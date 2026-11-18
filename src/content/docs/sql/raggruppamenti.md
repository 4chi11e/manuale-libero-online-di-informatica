---
title: Funzioni di aggregazione e raggruppamenti
description: COUNT, SUM, AVG, MIN e MAX, raggruppare le righe con GROUP BY, filtrare i gruppi con HAVING
---

Le query viste finora restituiscono righe "prese" dalle tabelle. Molte domande però chiedono un **calcolo su un insieme di righe**: *quante* sale ci sono a Pisa? *Qual è* l'incasso medio? *Quanti* attori ha ogni film? Per rispondere servono le **funzioni di aggregazione** e la clausola **`GROUP BY`**.

## Le funzioni di aggregazione

Una funzione di aggregazione prende **tutte le righe** selezionate dalla query e le riassume in **un solo valore**.

| Funzione | Restituisce |
|---|---|
| `COUNT(*)` | il numero di righe |
| `COUNT(campo)` | il numero di righe in cui il campo **non è NULL** |
| `COUNT(DISTINCT campo)` | il numero di valori **diversi** (non NULL) del campo |
| `SUM(campo)` | la somma dei valori |
| `AVG(campo)` | la media dei valori |
| `MIN(campo)` | il valore più piccolo |
| `MAX(campo)` | il valore più grande |

```sql
-- Quante sale ci sono a Pisa?
SELECT COUNT(*) AS numero_sale
FROM sala
WHERE citta = 'Pisa';
```

| numero_sale |
|---|
| 4 |

L'ordine con cui lavora il DBMS è importante: **prima** la `WHERE` sceglie le righe (le quattro sale di Pisa), **poi** la funzione le conta.

Si possono calcolare più funzioni nella stessa query:

```sql
SELECT SUM(posti) AS totale, AVG(posti) AS media, MIN(posti) AS minimo, MAX(posti) AS massimo
FROM sala;
```

| totale | media | minimo | massimo |
|---|---|---|---|
| 1350 | 192.8571 | 50 | 300 |

### COUNT e i valori NULL

Le varie forme di `COUNT` danno risultati diversi quando ci sono valori `NULL` o ripetuti:

```sql
SELECT COUNT(*), COUNT(genere), COUNT(DISTINCT genere)
FROM film;
```

| COUNT(\*) | COUNT(genere) | COUNT(DISTINCT genere) |
|---|---|---|
| 18 | 13 | 5 |

* `COUNT(*)` conta tutti i 18 film;
* `COUNT(genere)` conta solo i 13 film di cui è indicato il genere;
* `COUNT(DISTINCT genere)` conta quanti generi diversi ci sono: commedia, fantascienza, storico, drammatico, azione.

Anche `SUM`, `AVG`, `MIN` e `MAX` **ignorano i valori NULL**: la media delle durate dei film è calcolata solo sui film di cui la durata è nota.

:::caution[Funzioni di aggregazione e campi normali insieme]
Una query come questa non ha senso:

```sql
-- SBAGLIATA
SELECT nome, MAX(posti)
FROM sala;
```

`MAX(posti)` è un solo valore calcolato su tutte le righe, mentre `nome` ha un valore diverso in ogni riga: quale nome dovrebbe comparire accanto al massimo? A seconda delle impostazioni, MySQL dà errore oppure mostra un nome qualsiasi, che **non** è necessariamente quello della sala più grande. Per trovare "la sala con più posti" serve una [sottoquery](../sottoquery/#confronto-con-un-singolo-valore).
:::

## Raggruppare le righe: GROUP BY

Finora la funzione di aggregazione riassumeva **tutte** le righe in un'unica riga. Ma spesso la domanda è *"per ogni..."*: *per ogni città, quante sale ci sono?* In questo caso le righe vanno prima divise in **gruppi**, e la funzione va calcolata **separatamente per ogni gruppo**. È quello che fa la clausola **`GROUP BY`**:

```sql
-- Per ogni città, il numero di sale e il numero totale di posti
SELECT citta, COUNT(*) AS numero_sale, SUM(posti) AS posti_totali
FROM sala
GROUP BY citta;
```

| citta | numero_sale | posti_totali |
|---|---|---|
| Milano | 2 | 500 |
| Pisa | 4 | 600 |
| Roma | 1 | 250 |

Il DBMS mette insieme tutte le righe con lo stesso valore di `citta` (le due di Milano, le quattro di Pisa, quella di Roma) e restituisce **una riga per ogni gruppo**, con i valori calcolati sulle righe di quel gruppo.

La regola da ricordare è: **nella `SELECT`, oltre alle funzioni di aggregazione, si possono mettere solo i campi su cui si raggruppa** (o campi che hanno un unico valore in tutto il gruppo, come vedremo tra poco). Nell'esempio possiamo mostrare `citta`, perché ogni gruppo ha una sola città, ma non `nome`, perché ogni gruppo contiene sale con nomi diversi.

:::tip[Riconoscere quando serve GROUP BY]
Nelle richieste, le espressioni **"per ogni..."**, **"per ciascun..."**, **"di ogni..."** seguite da un conteggio, una somma o una media indicano quasi sempre un `GROUP BY` su quello che viene dopo "ogni": *"per ogni città il numero di sale"* → `GROUP BY citta`; *"per ogni film il numero di attori"* → `GROUP BY` sul film.
:::

### Raggruppare dopo una JOIN

Il `GROUP BY` si usa moltissimo insieme alle JOIN. *"Per ogni film, il titolo e il numero di attori che vi hanno recitato"*:

```sql
SELECT film.titolo, COUNT(*) AS numero_attori
FROM film JOIN recita ON film.codfilm = recita.codfilm
GROUP BY film.codfilm;
```

| titolo | numero_attori |
|---|---|
| Forrest Gump | 1 |
| Star Wars: Episode IV – A New Hope | 2 |
| Star Wars: Episode VII – The Force Awakens | 1 |
| Matrimonio all'italiana | 2 |
| La ciociara | 1 |
| J'accuse | 2 |
| Leon | 3 |
| The Matrix | 4 |
| The Matrix Reloaded | 5 |
| Star Wars: Episode V – The Empire Strikes Back | 2 |
| John Wick | 1 |

La JOIN produce una riga per ogni coppia film-attore; il `GROUP BY` raccoglie le righe dello stesso film e `COUNT(*)` le conta.

Notiamo che abbiamo raggruppato per **`film.codfilm`**, la chiave primaria, e non per `titolo`. È la scelta corretta: due film diversi potrebbero avere lo stesso titolo (pensiamo ai remake) e raggruppando per titolo verrebbero contati insieme. Raggruppando per la chiave primaria, invece, ogni gruppo corrisponde esattamente a un film, e quindi MySQL ci permette di mostrare nella `SELECT` qualunque altro campo della tabella FILM (titolo, regista, anno...), perché all'interno del gruppo ha un unico valore.

:::note[GROUP BY e altri DBMS]
Raggruppare per la chiave primaria e mostrare altri campi della stessa tabella è permesso da MySQL e da PostgreSQL. Altri DBMS sono più severi e richiedono di elencare nel `GROUP BY` tutti i campi non aggregati della `SELECT`: `GROUP BY film.codfilm, film.titolo`. Il risultato è identico, e questa forma funziona ovunque.
:::

### LEFT JOIN e conteggi che valgono zero

Nella tabella precedente mancano i film senza attori: la JOIN li ha esclusi, quindi non formano nessun gruppo. Se la richiesta è davvero *"per ogni film"*, compresi quelli che hanno zero attori, serve una [LEFT JOIN](../join/#left-join-tenere-anche-le-righe-senza-corrispondenza):

```sql
SELECT film.titolo, COUNT(recita.codattore) AS numero_attori
FROM film LEFT JOIN recita ON film.codfilm = recita.codfilm
GROUP BY film.codfilm;
```

| titolo | numero_attori |
|---|---|
| La strada | 0 |
| Amarcord | 0 |
| Forrest Gump | 1 |
| MELANCHOLIA | 0 |
| ... | ... |
| The Matrix Reloaded | 5 |
| ... | ... |

Attenzione a cosa si conta: qui è indispensabile **`COUNT(recita.codattore)`** e non `COUNT(*)`. Per "La strada" la LEFT JOIN produce **una** riga, con `recita.codattore` uguale a `NULL`: `COUNT(*)` conterebbe quella riga e darebbe 1, mentre `COUNT(recita.codattore)` ignora il `NULL` e dà correttamente 0.

## Filtrare i gruppi: HAVING

Supponiamo di volere solo *"le città che hanno più di una sala"*. La condizione riguarda il **numero di sale**, che si conosce solo **dopo** aver formato i gruppi. Non si può quindi scrivere nella `WHERE`, che lavora sulle singole righe prima del raggruppamento. Per le condizioni sui gruppi esiste la clausola **`HAVING`**, che si scrive dopo il `GROUP BY`:

```sql
SELECT citta, COUNT(*) AS numero_sale
FROM sala
GROUP BY citta
HAVING COUNT(*) > 1;
```

| citta | numero_sale |
|---|---|
| Milano | 2 |
| Pisa | 4 |

Allo stesso modo, *"i film in cui hanno recitato almeno 3 attori"*:

```sql
SELECT film.titolo, COUNT(*) AS numero_attori
FROM film JOIN recita ON film.codfilm = recita.codfilm
GROUP BY film.codfilm
HAVING COUNT(*) >= 3;
```

| titolo | numero_attori |
|---|---|
| Leon | 3 |
| The Matrix | 4 |
| The Matrix Reloaded | 5 |

:::tip[Alias nella HAVING]
In MySQL nella `HAVING` si può usare l'alias definito nella `SELECT`: `HAVING numero_attori >= 3`. È comodo e più leggibile, ma non tutti i DBMS lo permettono; ripetere l'espressione (`HAVING COUNT(*) >= 3`) funziona sempre.
:::

### WHERE o HAVING?

La differenza tra le due clausole è il **momento** in cui agiscono:

* **`WHERE`** filtra le **righe**, **prima** del raggruppamento. Contiene condizioni sui singoli campi: `citta = 'Pisa'`, `genere = 'fantascienza'`, `dataproiezione >= '2021-01-01'`.
* **`HAVING`** filtra i **gruppi**, **dopo** il raggruppamento. Contiene condizioni sulle funzioni di aggregazione: `COUNT(*) > 1`, `SUM(incasso) > 1000`.

Spesso nella stessa query servono entrambe. *"Per ogni sala che dal 2021 in poi ha incassato in totale più di 1000 €, il nome della sala e l'incasso totale (sempre dal 2021)"*:

```sql
SELECT sala.nome, SUM(proiezione.incasso) AS incasso_totale
FROM sala JOIN proiezione ON sala.codsala = proiezione.codsala
WHERE proiezione.dataproiezione >= '2021-01-01'
GROUP BY sala.codsala
HAVING SUM(proiezione.incasso) > 1000;
```

| nome | incasso_totale |
|---|---|
| sala milano 1 | 2900 |

Il DBMS: prende le proiezioni dal 2021 in poi (`WHERE`), le raggruppa per sala (`GROUP BY`), somma gli incassi di ogni sala e tiene solo le sale con somma maggiore di 1000 (`HAVING`). La "sala pisa 1", che dal 2021 ha incassato in tutto 1000 €, viene scartata.

## L'ordine di esecuzione di una query

Ora che conosciamo tutte le clausole, è utile sapere che il DBMS **non** le esegue nell'ordine in cui le scriviamo. L'ordine logico di esecuzione è:

| Ordine | Clausola | Cosa fa |
|---|---|---|
| 1 | `FROM` e `JOIN` | prende le tabelle e le collega |
| 2 | `WHERE` | tiene solo le righe che soddisfano la condizione |
| 3 | `GROUP BY` | divide le righe rimaste in gruppi |
| 4 | `HAVING` | tiene solo i gruppi che soddisfano la condizione |
| 5 | `SELECT` | calcola le colonne del risultato (e applica `DISTINCT`) |
| 6 | `ORDER BY` | ordina il risultato |
| 7 | `LIMIT` | tiene solo le prime righe |

Questo spiega molte regole viste finora: nella `WHERE` non si possono usare le funzioni di aggregazione, perché i gruppi non esistono ancora; nella `WHERE` non si possono usare gli alias della `SELECT`, perché la `SELECT` viene calcolata dopo; nell'`ORDER BY`, invece, gli alias si possono usare.

```sql
-- I registi con più film nel database, in ordine decrescente
SELECT regista, COUNT(*) AS numero_film
FROM film
WHERE regista IS NOT NULL
GROUP BY regista
ORDER BY numero_film DESC;
```

## Esercizi

Nella parte **"Database Film"** dell'[eserciziario](../esercizi/) i conteggi iniziano con *"Numero di attori che hanno recitato in The Matrix"*; il `GROUP BY` con *"Per ogni attore la somma delle durate dei film in cui ha recitato"* e *"Numero di attori per ogni film"*; la `HAVING` con *"Numero di attori per ogni film in cui hanno recitato almeno 3 attori"*. Nel database dei voli aerei si trovano molti esercizi del tipo *"Per ogni città / nazione / compagnia..."*.
