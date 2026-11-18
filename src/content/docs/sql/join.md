---
title: Interrogare più tabelle - le JOIN
description: Collegare le tabelle tramite chiavi primarie ed esterne con JOIN, alias delle tabelle, la stessa tabella usata più volte, LEFT JOIN
---

Un database ben progettato e [normalizzato](../../database/normalizzazione/) divide le informazioni in molte tabelle, proprio per evitare le ripetizioni. Il rovescio della medaglia è che quasi ogni domanda interessante richiede dati che stanno in **tabelle diverse**. Per esempio, per sapere *quali attori hanno recitato in The Matrix*:

* il titolo del film sta nella tabella **FILM**;
* il nome degli attori sta nella tabella **ATTORE**;
* il collegamento tra i due ("chi ha recitato in cosa") sta nella tabella **RECITA**.

L'operazione che rimette insieme le tabelle si chiama **JOIN** (in italiano *congiunzione*).

## L'idea: seguire le chiavi esterne

Ricordiamo come sono fatte le tabelle coinvolte:

* **FILM** (<u>codfilm</u>, titolo, ...)
* **RECITA** (<u>codattore\*</u>, <u>codfilm\*</u>)
* **ATTORE** (<u>codattore</u>, nome, ...)

In RECITA non ci sono i titoli né i nomi, ma solo i **codici**: una riga come `(26783, 13)` significa "l'attore 26783 ha recitato nel film 13". Per trasformarla in "Keanu Reeves ha recitato in The Matrix" bisogna andare a cercare il film 13 nella tabella FILM e l'attore 26783 nella tabella ATTORE.

Una JOIN fa esattamente questo: **affianca a ogni riga di una tabella le righe dell'altra tabella che hanno lo stesso valore in un campo**, quasi sempre una chiave esterna da una parte e la chiave primaria corrispondente dall'altra.

## La sintassi di JOIN ... ON

```sql
SELECT campi
FROM tabella1 JOIN tabella2 ON tabella1.campo = tabella2.campo;
```

Dopo `ON` si scrive la **condizione di collegamento**, cioè quali campi devono essere uguali. Vediamo un primo esempio con due tabelle:

```sql
SELECT film.titolo, recita.codattore
FROM film JOIN recita ON film.codfilm = recita.codfilm
WHERE film.titolo = 'The Matrix';
```

| titolo | codattore |
|---|---|
| The Matrix | 26783 |
| The Matrix | 26784 |
| The Matrix | 26785 |
| The Matrix | 26789 |

Abbiamo trovato i **codici** dei quattro attori. Per avere i **nomi** basta collegare anche la tabella ATTORE, aggiungendo una seconda JOIN:

```sql
-- Gli attori che hanno recitato in The Matrix
SELECT film.titolo, attore.nome
FROM film JOIN recita ON film.codfilm = recita.codfilm
          JOIN attore ON recita.codattore = attore.codattore
WHERE film.titolo = 'The Matrix';
```

| titolo | nome |
|---|---|
| The Matrix | Keanu Reeves |
| The Matrix | Carrie-Anne Moss |
| The Matrix | Hugo Weaving |
| The Matrix | Joe Pantoliano |

Si possono collegare quante tabelle si vuole: per ogni tabella in più si aggiunge un'altra `JOIN ... ON ...`. In generale, **per collegare N tabelle servono N−1 condizioni di collegamento**.

:::note[Nome della tabella davanti al campo]
La notazione `tabella.campo` (ad esempio `film.codfilm`) indica il campo di una tabella precisa. È **obbligatoria** quando lo stesso nome di campo compare in più tabelle della query: scrivere solo `codfilm` sarebbe ambiguo, perché c'è sia in FILM sia in RECITA, e MySQL darebbe l'errore *"Column 'codfilm' in field list is ambiguous"*. Nel nostro database anche `nome` e `nazionalita` compaiono in più tabelle. Quando il nome non è ambiguo si può omettere, ma scriverlo sempre rende la query più chiara.
:::

## Come si costruisce una query con le JOIN

Davanti a una richiesta che coinvolge più tabelle conviene ragionare sempre con lo stesso metodo:

1. **Quali dati servono nel risultato e nelle condizioni?** Individuare in quali tabelle si trovano.
2. **Come si arriva da una tabella all'altra?** Guardando lo schema, cercare il "percorso" di chiavi esterne che le collega. Spesso bisogna passare anche per tabelle di cui non ci interessa nessun campo, come RECITA nell'esempio precedente: servono solo da "ponte".
3. **Scrivere il FROM** con le JOIN lungo quel percorso, una condizione `ON` per ogni collegamento.
4. **Aggiungere la WHERE** con le condizioni della richiesta e scegliere i campi della `SELECT`.

Proviamo con la richiesta: *"Per ogni proiezione del 15 aprile 2021, il nome e la città della sala, il titolo del film e l'incasso"*.

1. Servono: nome e città (**SALA**), titolo (**FILM**), incasso e data (**PROIEZIONE**).
2. PROIEZIONE contiene sia `codfilm` sia `codsala`, quindi fa da ponte tra FILM e SALA.
3. e 4.:

```sql
SELECT sala.nome, sala.citta, film.titolo, proiezione.incasso
FROM proiezione JOIN film ON proiezione.codfilm = film.codfilm
                JOIN sala ON proiezione.codsala = sala.codsala
WHERE proiezione.dataproiezione = '2021-04-15';
```

| nome | citta | titolo | incasso |
|---|---|---|---|
| sala milano 1 | Milano | Jurassic Park | 1200 |
| sala pisa 1 | Pisa | Jurassic Park | 1000 |
| sala milano 1 | Milano | The Post | 1500 |

L'ordine in cui si scrivono le tabelle nel `FROM` non cambia il risultato: l'importante è che ogni tabella aggiunta sia collegata, con la sua condizione `ON`, a una tabella già presente.

## Gli alias delle tabelle

Con molte tabelle i nomi completi rendono le query lunghe. Come per le colonne, anche alle tabelle si può dare un **alias**, scrivendolo dopo il nome della tabella nel `FROM` (con o senza `AS`). Da quel momento, nel resto della query, si usa l'alias al posto del nome:

```sql
SELECT s.nome, s.citta, f.titolo, p.incasso
FROM proiezione AS p JOIN film AS f ON p.codfilm = f.codfilm
                     JOIN sala AS s ON p.codsala = s.codsala
WHERE p.dataproiezione = '2021-04-15';
```

Questa query è identica alla precedente. Vedremo tra poco che in certi casi gli alias non sono solo una comodità ma diventano indispensabili.

## JOIN e DISTINCT

Una JOIN produce una riga per **ogni combinazione** collegata. Questo genera spesso dei duplicati. Chiediamo *"i titoli dei film proiettati a Pisa"*:

```sql
SELECT DISTINCT f.titolo
FROM film f JOIN proiezione p ON f.codfilm = p.codfilm
            JOIN sala s ON p.codsala = s.codsala
WHERE s.citta = 'Pisa';
```

| titolo |
|---|
| Godzilla |
| Star Wars: Episode IV – A New Hope |
| Leon |
| Matrimonio all'italiana |
| Forrest Gump |
| Jurassic Park |

Senza `DISTINCT`, un film proiettato più volte a Pisa comparirebbe una volta per ogni proiezione. Conviene chiedersi sempre: **il risultato può contenere righe ripetute?** Se la richiesta è un semplice elenco ("i titoli", "i nomi"), la risposta è quasi sempre `DISTINCT`.

## Le condizioni che "non funzionano": una riga alla volta

Proviamo a cercare *"i film in cui hanno recitato sia Marcello Mastroianni sia Sophia Loren"*. Il primo tentativo che viene in mente è:

```sql
-- SBAGLIATA: non restituisce mai nulla
SELECT f.titolo
FROM film f JOIN recita r ON f.codfilm = r.codfilm
            JOIN attore a ON r.codattore = a.codattore
WHERE a.nome = 'Marcello Mastroianni' AND a.nome = 'Sophia Loren';
```

Il risultato è vuoto. Il motivo è fondamentale per capire SQL: **la WHERE controlla una riga alla volta**. Dopo le JOIN ogni riga contiene **un solo** attore, quindi il nome non può essere contemporaneamente "Marcello Mastroianni" e "Sophia Loren".

Una soluzione è collegare **due volte** le tabelle RECITA e ATTORE, in modo che ogni riga contenga **due attori** dello stesso film. Per distinguere le due copie della stessa tabella gli alias diventano obbligatori:

```sql
SELECT f.titolo
FROM film f JOIN recita r1 ON f.codfilm = r1.codfilm
            JOIN attore a1 ON r1.codattore = a1.codattore
            JOIN recita r2 ON f.codfilm = r2.codfilm
            JOIN attore a2 ON r2.codattore = a2.codattore
WHERE a1.nome = 'Marcello Mastroianni' AND a2.nome = 'Sophia Loren';
```

| titolo |
|---|
| Matrimonio all'italiana |

Ora ogni riga è formata da un film, un suo attore (`a1`) e un altro suo attore (`a2`): la condizione chiede che il primo sia Mastroianni e il secondo Loren. Nella pagina sulle [sottoquery](../sottoquery/) vedremo un altro modo, spesso più semplice, di risolvere le richieste del tipo "sia... sia...".

### La stessa tabella usata due volte

La tecnica di collegare due volte la stessa tabella serve ogni volta che una richiesta mette in relazione **due elementi dello stesso tipo**. Per esempio: *"gli attori che hanno recitato almeno una volta insieme a Keanu Reeves"*. Partiamo da Keanu Reeves (`a1`), troviamo i suoi film (`r1`), poi tutti gli attori di quei film (`r2`, `a2`):

```sql
SELECT DISTINCT a2.nome
FROM attore a1 JOIN recita r1 ON a1.codattore = r1.codattore
               JOIN recita r2 ON r1.codfilm = r2.codfilm
               JOIN attore a2 ON r2.codattore = a2.codattore
WHERE a1.nome = 'Keanu Reeves' AND a2.nome <> 'Keanu Reeves';
```

| nome |
|---|
| Carrie-Anne Moss |
| Hugo Weaving |
| Joe Pantoliano |
| Lambert Wilson |
| Monica Bellucci |

La condizione `a2.nome <> 'Keanu Reeves'` serve a togliere Keanu Reeves stesso, che altrimenti risulterebbe "aver recitato con sé stesso". Notiamo che in questa query la tabella FILM non serve: il collegamento tra i film passa direttamente per il campo `codfilm` delle due copie di RECITA.

Lo stesso schema si ritrova in molti database: un dipendente e il suo responsabile (entrambi nella tabella DIPENDENTE), un passeggero e il suo accompagnatore (entrambi nella tabella CLIENTE), un volo e l'aeroporto di partenza e di arrivo (entrambi nella tabella AEROPORTO).

## Condizioni che coinvolgono campi di tabelle diverse

Dopo una JOIN, nella stessa riga ci sono campi di tabelle diverse, e la `WHERE` può confrontarli tra loro. Per esempio, *"gli attori che hanno recitato in un film quando erano minorenni"*:

```sql
SELECT f.titolo, a.nome, f.annoproduzione - a.annonascita AS eta
FROM film f JOIN recita r ON f.codfilm = r.codfilm
            JOIN attore a ON r.codattore = a.codattore
WHERE f.annoproduzione - a.annonascita < 18;
```

| titolo | nome | eta |
|---|---|---|
| Leon | Natalie Portman | 13 |

## LEFT JOIN: tenere anche le righe senza corrispondenza

La JOIN vista finora (chiamata più precisamente **INNER JOIN**; scrivere `JOIN` o `INNER JOIN` è la stessa cosa) tiene solo le righe che **trovano una corrispondenza** nell'altra tabella. Un film senza attori nel database, come "La strada", non compare in nessuna riga di `film JOIN recita`.

A volte invece vogliamo tenere **tutte** le righe della prima tabella, anche quelle senza corrispondenza. Si usa allora la **LEFT JOIN** (o *LEFT OUTER JOIN*): tiene tutte le righe della tabella a **sinistra** e, quando non c'è corrispondenza a destra, riempie i campi della tabella di destra con `NULL`.

```sql
SELECT film.titolo, recita.codattore
FROM film LEFT JOIN recita ON film.codfilm = recita.codfilm
WHERE film.codfilm IN (1, 2, 3, 13);
```

| titolo | codattore |
|---|---|
| La strada | NULL |
| Amarcord | NULL |
| Forrest Gump | 26773 |
| The Matrix | 26783 |
| The Matrix | 26784 |
| The Matrix | 26785 |
| The Matrix | 26789 |

Questo permette, per esempio, di trovare **le righe che non hanno corrispondenze**: basta tenere solo quelle in cui il campo dell'altra tabella è rimasto `NULL`.

```sql
-- I film per cui non è registrato nessun attore
SELECT film.titolo
FROM film LEFT JOIN recita ON film.codfilm = recita.codfilm
WHERE recita.codattore IS NULL;
```

| titolo |
|---|
| La strada |
| Amarcord |
| MELANCHOLIA |
| Godzilla |
| KONG URAGANO SULLA METROPOLI |
| Jurassic Park |
| The Post |

Esiste anche la **RIGHT JOIN**, che fa la stessa cosa tenendo tutte le righe della tabella di **destra**. Non serve quasi mai: basta scambiare l'ordine delle tabelle e usare una LEFT JOIN.

La LEFT JOIN sarà importante soprattutto con i [conteggi](../raggruppamenti/#left-join-e-conteggi-che-valgono-zero), quando vorremo contare qualcosa "per ogni film", compresi quelli che hanno zero attori o zero proiezioni.

## Un altro modo di scrivere le JOIN

Su molti libri e in molto codice si trova una sintassi più vecchia, in cui le tabelle si elencano nel `FROM` separate da virgole e le condizioni di collegamento si scrivono nella `WHERE`:

```sql
SELECT film.titolo, attore.nome
FROM film, recita, attore
WHERE film.codfilm = recita.codfilm
  AND recita.codattore = attore.codattore
  AND film.titolo = 'The Matrix';
```

Il risultato è lo stesso. Elencare le tabelle con le virgole produce il **prodotto cartesiano**, cioè tutte le combinazioni possibili di righe: `FROM film, recita` da solo produce 18 × 24 = 432 righe, quasi tutte senza senso (ogni film abbinato a ogni riga di RECITA). Sono le condizioni nella `WHERE` a tenere solo le combinazioni corrette.

La sintassi con `JOIN ... ON` è preferibile perché tiene separate le condizioni di **collegamento** (nell'`ON`) da quelle della **richiesta** (nella `WHERE`): così è molto più difficile dimenticare un collegamento, errore che con le virgole produce silenziosamente migliaia di righe sbagliate.

## Esercizi

Nella parte **"Database Film"** dell'[eserciziario](../esercizi/) le JOIN servono a partire dall'esercizio *"Nome dell'attore e titoli dei film in cui ha recitato"*; l'uso della stessa tabella due volte compare in *"Il titolo dei film in cui recitano Marcello Mastroianni e Sophia Loren"* e negli esercizi su Keanu Reeves. Il database dei voli aerei richiede JOIN più lunghe, con le tabelle AEROPORTO e CLIENTE usate più volte nella stessa query.
