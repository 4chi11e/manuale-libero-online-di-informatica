---
title: Sottoquery
description: Query annidate - confronto con un valore, IN e NOT IN, sottoquery nel FROM, e gli schemi per risolvere le richieste più comuni
---

Una **sottoquery** (o *query annidata*) è una `SELECT` scritta **dentro** un'altra query, tra parentesi. Il DBMS esegue prima la sottoquery e poi usa il suo risultato nella query principale (detta anche *query esterna*).

Le sottoquery permettono di rispondere a domande che con le sole JOIN sono difficili o impossibili, in particolare quelle che contengono le parole **"nessuno"**, **"mai"**, **"non"**, **"solo"**, **"sia... sia..."**, oppure un confronto con una media o un massimo.

## Confronto con un singolo valore

Se la sottoquery restituisce **un solo valore** (una riga e una colonna), si può usare in una condizione come se fosse un numero o un testo qualsiasi. Il caso tipico è il confronto con un valore calcolato da una funzione di aggregazione.

*"Le sale con più posti della media"*:

```sql
SELECT nome, citta, posti
FROM sala
WHERE posti > (SELECT AVG(posti) FROM sala);
```

| nome | citta | posti |
|---|---|---|
| sala milano 1 | Milano | 300 |
| sala pisa 1 | Pisa | 200 |
| sala roma 1 | Roma | 250 |
| sala milano 2 | Milano | 200 |
| sala pisa 4 | Pisa | 250 |

La sottoquery calcola la media (circa 192,9); la query esterna tiene le sale con più posti. Non si poteva scrivere `WHERE posti > AVG(posti)`, perché nella `WHERE` le funzioni di aggregazione non si possono usare.

Allo stesso modo si risolvono le richieste "il più..." in modo sempre corretto, anche in caso di pari merito. *"Il film più lungo"*:

```sql
SELECT titolo, durata
FROM film
WHERE durata = (SELECT MAX(durata) FROM film);
```

| titolo | durata |
|---|---|
| The Matrix Reloaded | 138 |

Se due film avessero la stessa durata massima, compariranno entrambi (cosa che con `ORDER BY ... LIMIT 1` non succederebbe).

## IN: appartenere a un elenco

Se la sottoquery restituisce **una colonna con più righe**, il suo risultato è un elenco di valori, e si usa con l'operatore **`IN`** che abbiamo già visto nelle [interrogazioni di base](../select/#in-un-valore-tra-tanti). La differenza è che ora l'elenco non lo scriviamo a mano, ma lo calcola il database.

*"I titoli dei film in cui ha recitato Keanu Reeves"*:

```sql
SELECT titolo
FROM film
WHERE codfilm IN (
    SELECT recita.codfilm
    FROM recita JOIN attore ON recita.codattore = attore.codattore
    WHERE attore.nome = 'Keanu Reeves'
);
```

| titolo |
|---|
| The Matrix |
| The Matrix Reloaded |
| John Wick |

Per leggere una query con sottoquery conviene partire **dall'interno**:

1. la sottoquery restituisce i codici dei film di Keanu Reeves: 13, 14, 18;
2. la query esterna diventa `SELECT titolo FROM film WHERE codfilm IN (13, 14, 18)`.

Questa stessa richiesta si poteva risolvere anche con una semplice JOIN. Le sottoquery diventano davvero necessarie con la forma negata.

:::caution[Confrontare le cose giuste]
Il campo prima di `IN` e la colonna restituita dalla sottoquery devono contenere **lo stesso tipo di informazione**: codici di film con codici di film, codici di attori con codici di attori. Scrivere `WHERE codfilm IN (SELECT codattore ...)` non dà errore (sono entrambi numeri), ma il risultato non ha alcun senso. Conviene confrontare sempre **chiavi primarie ed esterne** e non nomi o titoli, che potrebbero non essere unici.
:::

## NOT IN: le richieste "nessuno", "mai", "non"

*"I titoli dei film che non sono mai stati proiettati a Pisa"*.

Il primo tentativo che viene in mente è sbagliato:

```sql
-- SBAGLIATA
SELECT DISTINCT film.titolo
FROM film JOIN proiezione ON film.codfilm = proiezione.codfilm
          JOIN sala ON proiezione.codsala = sala.codsala
WHERE sala.citta <> 'Pisa';
```

Questa query trova i film che sono stati proiettati **almeno una volta in una città diversa da Pisa**, che è tutta un'altra cosa: un film proiettato sia a Pisa sia a Milano comparirebbe lo stesso, grazie alla proiezione di Milano. E un film mai proiettato da nessuna parte non comparirebbe, perché la JOIN lo esclude. Il problema, ancora una volta, è che **la `WHERE` guarda una riga alla volta**: non può sapere se, in un'altra riga, lo stesso film è stato proiettato a Pisa.

La soluzione corretta ragiona "per differenza": prima si trovano i film che **sono** stati proiettati a Pisa, poi si prendono **tutti gli altri**.

```sql
SELECT titolo
FROM film
WHERE codfilm NOT IN (
    SELECT proiezione.codfilm
    FROM proiezione JOIN sala ON proiezione.codsala = sala.codsala
    WHERE sala.citta = 'Pisa'
);
```

| titolo |
|---|
| La strada |
| Amarcord |
| MELANCHOLIA |
| KONG URAGANO SULLA METROPOLI |
| Star Wars: Episode VII – The Force Awakens |
| La ciociara |
| J'accuse |
| The Matrix |
| The Matrix Reloaded |
| Star Wars: Episode V – The Empire Strikes Back |
| The Post |
| John Wick |

Lo stesso schema vale per *"i film in cui non compare nessun attore francese"*: la query sbagliata con `WHERE attore.nazionalita <> 'francese'` restituirebbe anche "Leon", che ha un attore francese (Jean Reno) ma anche attori di altre nazionalità. Quella corretta è:

```sql
SELECT titolo
FROM film
WHERE codfilm NOT IN (
    SELECT recita.codfilm
    FROM recita JOIN attore ON recita.codattore = attore.codattore
    WHERE attore.nazionalita = 'francese'
);
```

In questo risultato non compaiono "J'accuse", "Leon" e "The Matrix Reloaded", gli unici film con almeno un attore francese. Compaiono invece anche i film senza attori registrati, che effettivamente non hanno nessun attore francese.

:::caution[NOT IN e i valori NULL]
Se la sottoquery di un `NOT IN` restituisce anche un solo valore `NULL`, la query esterna non restituisce **nessuna riga**: per SQL non si può sapere se un valore è diverso da un valore sconosciuto. Con le chiavi primarie ed esterne di solito il problema non si pone, perché non sono mai `NULL`; se invece nella sottoquery si seleziona un campo che può essere vuoto, conviene aggiungere `WHERE campo IS NOT NULL`.
:::

## Le richieste "sia... sia..."

Nella pagina sulle JOIN abbiamo risolto *"i film con sia Mastroianni sia Loren"* collegando due volte le stesse tabelle. Con una sottoquery il ragionamento è spesso più naturale: **tra** le righe che soddisfano la prima condizione, si tengono quelle che compaiono **anche** nell'elenco di quelle che soddisfano la seconda.

*"Gli attori che hanno recitato sia in The Matrix sia in The Matrix Reloaded"*:

```sql
SELECT attore.nome
FROM attore JOIN recita ON attore.codattore = recita.codattore
            JOIN film ON film.codfilm = recita.codfilm
WHERE film.titolo = 'The Matrix'
  AND attore.codattore IN (
      SELECT recita.codattore
      FROM recita JOIN film ON film.codfilm = recita.codfilm
      WHERE film.titolo = 'The Matrix Reloaded'
  );
```

| nome |
|---|
| Keanu Reeves |
| Carrie-Anne Moss |
| Hugo Weaving |

Cambiando `IN` in `NOT IN` (e scambiando i due film) si ottiene *"gli attori di The Matrix Reloaded che non hanno recitato in The Matrix"*: Lambert Wilson e Monica Bellucci.

## Le richieste "solo"

*"Gli attori che hanno recitato solo in film di fantascienza"*. Anche qui la soluzione con una sola JOIN e `WHERE genere = 'fantascienza'` è sbagliata: troverebbe gli attori che hanno recitato **almeno** in un film di fantascienza, anche se hanno fatto pure film di altri generi.

"Solo in film di fantascienza" significa: **hanno recitato in film di fantascienza** e **non hanno mai recitato in film di altro genere**. Le due parti della frase diventano le due parti della query:

```sql
SELECT DISTINCT attore.nome
FROM attore JOIN recita ON attore.codattore = recita.codattore
            JOIN film ON film.codfilm = recita.codfilm
WHERE film.genere = 'fantascienza'
  AND attore.codattore NOT IN (
      SELECT recita.codattore
      FROM recita JOIN film ON film.codfilm = recita.codfilm
      WHERE film.genere <> 'fantascienza' OR film.genere IS NULL
  );
```

| nome |
|---|
| Carrie-Anne Moss |
| Hugo Weaving |
| Joe Pantoliano |
| Lambert Wilson |
| Monica Bellucci |

Keanu Reeves non compare, perché ha recitato anche in "John Wick", che è un film d'azione. La condizione `OR film.genere IS NULL` nella sottoquery serve a considerare "di altro genere" anche i film di cui il genere non è noto, come i film di Star Wars: senza di essa, chi ha recitato in un film di fantascienza e in un film senza genere risulterebbe aver fatto "solo fantascienza".

Lo stesso schema serve per le richieste con **"sempre"**: *"i film le cui proiezioni hanno sempre incassato più di 500 €"* sono i film proiettati almeno una volta che **non** hanno **nessuna** proiezione con incasso minore o uguale a 500 €.

## Sottoquery nel FROM

Il risultato di una query è una tabella, quindi una sottoquery si può usare anche **nel `FROM`**, come se fosse una tabella vera. In questo caso è obbligatorio darle un alias.

Serve soprattutto quando bisogna **aggregare due volte**, cioè calcolare una funzione su valori che sono già il risultato di un `GROUP BY`. *"Il numero medio di film diretti da ogni regista"*: prima bisogna contare i film di ogni regista, poi fare la media di quei conteggi.

```sql
SELECT AVG(numero_film) AS media_film_per_regista
FROM (
    SELECT regista, COUNT(*) AS numero_film
    FROM film
    WHERE regista IS NOT NULL
    GROUP BY regista
) AS conteggi;
```

| media_film_per_regista |
|---|
| 1.3077 |

La sottoquery produce una tabella temporanea `conteggi` con una riga per regista (13 registi, 4 dei quali con 2 film e gli altri con 1); la query esterna calcola la media della colonna `numero_film`. Non si poteva scrivere `AVG(COUNT(*))`: le funzioni di aggregazione non si possono annidare.

Con la stessa tecnica si possono anche confrontare i gruppi con un valore calcolato su altri gruppi, ad esempio *"il film con il maggior numero di attori"*:

```sql
SELECT film.titolo, COUNT(*) AS numero_attori
FROM film JOIN recita ON film.codfilm = recita.codfilm
GROUP BY film.codfilm
HAVING COUNT(*) = (
    SELECT MAX(n)
    FROM (SELECT COUNT(*) AS n FROM recita GROUP BY codfilm) AS conteggi
);
```

| titolo | numero_attori |
|---|---|
| The Matrix Reloaded | 5 |

## Riepilogo: dalla richiesta alla query

Davanti a un esercizio, le parole della richiesta suggeriscono quasi sempre lo schema da usare. Questa tabella riassume gli schemi visti in questa sezione:

| Nella richiesta... | Schema | Esempio |
|---|---|---|
| dati su più tabelle | `JOIN` seguendo le chiavi esterne | nomi degli attori di The Matrix |
| "almeno uno", "almeno una volta" | `JOIN` + `WHERE` (+ `DISTINCT`) | attori che hanno recitato in un film di fantascienza |
| "quanti", "il totale", "la media" | funzione di aggregazione | numero di sale di Pisa |
| "per ogni..." | `GROUP BY` sulla chiave dell'elemento | numero di attori per ogni film |
| "per ogni..., anche quelli con zero" | `LEFT JOIN` + `GROUP BY` + `COUNT(campo)` | numero di attori per ogni film, anche senza attori |
| "almeno N", "più di N" (riferito a un conteggio) | `GROUP BY` + `HAVING` | film con almeno 3 attori |
| "più della media", "il più..." | sottoquery con `AVG` o `MAX` | il film più lungo |
| "nessuno", "mai", "non" | `NOT IN` (sottoquery con ciò che **non** si vuole) | film mai proiettati a Pisa |
| "sia... sia..." | `IN` (oppure la stessa tabella due volte) | attori di Matrix e di Matrix Reloaded |
| "solo", "sempre" | `JOIN` + `NOT IN` (sottoquery con il caso contrario) | attori solo di fantascienza |
| media di conteggi, massimo di somme... | sottoquery nel `FROM` | numero medio di film per regista |
| due elementi dello stesso tipo ("insieme a", "accompagnatore") | stessa tabella due volte con alias | attori che hanno recitato con Keanu Reeves |

:::tip[Controllare il risultato]
Una query che non dà errori non è per forza una query giusta. Dopo averla scritta, conviene controllare il risultato su qualche caso noto: se chiediamo "i film senza attori francesi" e compare "Leon", in cui recita Jean Reno, la query è sbagliata. Con un database piccolo come quello degli esempi questo controllo si può fare a mano, guardando direttamente le tabelle.
:::

## Esercizi

Le sottoquery sono necessarie in buona parte della parte **"Database Film"** dell'[eserciziario](../esercizi/), a partire da *"Il titolo dei film in cui recita S. Loren ma non M. Mastroianni"*, *"Titoli dei film in cui non compare nessun attore francese"*, *"Nomi degli attori che hanno recitato solo in film di fantascienza"* e *"Il numero medio di film diretto da ogni regista"* (sottoquery nel `FROM`). Il database dei voli aerei ne fa largo uso, ad esempio in *"Nome e cognome dei piloti che non hanno mai pilotato insieme a Francesco Tormene"*.
