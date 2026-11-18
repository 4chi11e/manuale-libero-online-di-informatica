---
title: Interrogazioni di base
description: Il comando SELECT su una sola tabella - proiezione, selezione, operatori, NULL, DISTINCT, ordinamento, campi calcolati e date
---

In questa pagina impariamo a interrogare **una sola tabella**. Sembra poco, ma tutte le query più complesse che vedremo nelle pagine successive sono costruite a partire da questi mattoni.

## La struttura di una SELECT

La forma più semplice di una query è:

```sql
SELECT campi
FROM tabella
WHERE condizione;
```

che si legge quasi come una frase in inglese: "seleziona questi *campi* dalla *tabella* dove vale la *condizione*".

* **`SELECT`** indica **quali colonne** vogliamo nel risultato;
* **`FROM`** indica **da quale tabella** prendere i dati;
* **`WHERE`** (facoltativa) indica **quali righe** tenere.

## Scegliere le colonne: SELECT e FROM

Per vedere un'intera tabella si usa l'asterisco `*`, che significa "tutte le colonne":

```sql
SELECT *
FROM sala;
```

Il risultato è la tabella SALA completa, già vista nella [pagina introduttiva](../sql/#il-database-di-esempio).

Di solito però non ci servono tutte le colonne. Basta elencare quelle che vogliamo, separate da virgole, nell'ordine in cui vogliamo vederle:

```sql
SELECT nome, citta
FROM sala;
```

| nome | citta |
|---|---|
| sala milano 1 | Milano |
| sala pisa 1 | Pisa |
| sala pisa 2 | Pisa |
| sala roma 1 | Roma |
| sala pisa 3 | Pisa |
| sala milano 2 | Milano |
| sala pisa 4 | Pisa |

Questa operazione, che "taglia" la tabella in verticale tenendo solo alcune colonne, nella teoria dei database si chiama **proiezione**.

:::tip[Meglio evitare l'asterisco]
`SELECT *` è comodo per dare un'occhiata ai dati, ma nelle query vere conviene sempre scrivere le colonne che servono: il risultato è più leggibile e, nelle query su più tabelle, si evitano colonne inutili o ripetute. Anche negli esercizi, se la richiesta è "il nome delle sale", la risposta corretta contiene **solo** il nome.
:::

## Scegliere le righe: WHERE

La clausola `WHERE` contiene una **condizione** che viene controllata riga per riga: nel risultato restano solo le righe per cui la condizione è vera. Questa operazione, che "taglia" la tabella in orizzontale, si chiama **selezione**.

```sql
-- Nome e posti delle sale di Pisa
SELECT nome, posti
FROM sala
WHERE citta = 'Pisa';
```

| nome | posti |
|---|---|
| sala pisa 1 | 200 |
| sala pisa 2 | 100 |
| sala pisa 3 | 50 |
| sala pisa 4 | 250 |

Notiamo che la colonna usata nella condizione (`citta`) non deve per forza comparire nel risultato.

### Operatori di confronto

| Operatore | Significato | Esempio |
|---|---|---|
| `=` | uguale | `citta = 'Pisa'` |
| `<>` (oppure `!=`) | diverso | `genere <> 'commedia'` |
| `>` `>=` | maggiore, maggiore o uguale | `posti >= 200` |
| `<` `<=` | minore, minore o uguale | `annoproduzione < 1980` |

Attenzione: in SQL l'uguaglianza si scrive con un **solo** `=`, non con `==` come in C e Python.

### Operatori logici: AND, OR, NOT

Più condizioni si combinano con gli operatori logici, che funzionano esattamente come in programmazione:

* `AND`: la riga resta se sono vere **entrambe** le condizioni;
* `OR`: la riga resta se è vera **almeno una** delle condizioni;
* `NOT`: inverte la condizione.

```sql
-- Le sale di Pisa con almeno 200 posti
SELECT nome, posti
FROM sala
WHERE citta = 'Pisa' AND posti >= 200;
```

| nome | posti |
|---|---|
| sala pisa 1 | 200 |
| sala pisa 4 | 250 |

```sql
-- Le sale che sono a Milano oppure hanno meno di 100 posti
SELECT nome, citta
FROM sala
WHERE citta = 'Milano' OR posti < 100;
```

| nome | citta |
|---|---|
| sala milano 1 | Milano |
| sala pisa 3 | Pisa |
| sala milano 2 | Milano |

:::caution[Le parentesi con AND e OR]
`AND` ha la precedenza su `OR`, proprio come la moltiplicazione sull'addizione. Se vogliamo "i film di fantascienza francesi o giapponesi" **non** possiamo scrivere:

```sql
WHERE genere = 'fantascienza' AND nazionalita = 'francese' OR nazionalita = 'giapponese'
```

perché verrebbe letto come "(fantascienza **e** francesi) **oppure** giapponesi", e comparirebbero anche i film giapponesi di qualunque genere. La versione corretta usa le parentesi:

```sql
WHERE genere = 'fantascienza' AND (nazionalita = 'francese' OR nazionalita = 'giapponese')
```

Nel dubbio, le parentesi si mettono sempre: non costano nulla e rendono chiara l'intenzione.
:::

Un altro errore tipico riguarda il linguaggio naturale: "i film francesi **e** giapponesi" in italiano significa "sia i francesi sia i giapponesi", ma in SQL si scrive con `OR`, perché nessun film ha contemporaneamente le due nazionalità. La condizione `nazionalita = 'francese' AND nazionalita = 'giapponese'` è **sempre falsa**: ogni singola riga ha un solo valore nel campo `nazionalita`.

### IN: un valore tra tanti

Quando dobbiamo confrontare un campo con molti valori possibili, invece di una lunga serie di `OR` possiamo usare `IN` con l'elenco dei valori tra parentesi:

```sql
-- I film francesi o giapponesi
SELECT titolo, nazionalita
FROM film
WHERE nazionalita IN ('francese', 'giapponese');
```

| titolo | nazionalita |
|---|---|
| MELANCHOLIA | francese |
| Godzilla | giapponese |
| KONG URAGANO SULLA METROPOLI | giapponese |
| J'accuse | francese |
| Leon | francese |

Esiste anche la forma negata `NOT IN (...)`, che tiene le righe il cui valore **non** compare nell'elenco. Vedremo che `IN` diventa uno strumento potentissimo quando l'elenco, invece di scriverlo a mano, lo produce un'altra query ([sottoquery](../sottoquery/)).

### BETWEEN: un intervallo

`BETWEEN a AND b` è vera quando il valore è compreso tra `a` e `b`, **estremi inclusi**. È equivalente a `campo >= a AND campo <= b`.

```sql
-- I film prodotti negli anni '90
SELECT titolo, annoproduzione
FROM film
WHERE annoproduzione BETWEEN 1990 AND 1999;
```

| titolo | annoproduzione |
|---|---|
| Forrest Gump | 1994 |
| Leon | 1994 |
| The Matrix | 1999 |
| Jurassic Park | 1993 |

`BETWEEN` funziona anche con le date e con i testi (in ordine alfabetico).

### LIKE: cercare dentro un testo

L'operatore `=` confronta il testo intero. Per cercare un testo che **contiene**, **inizia** o **finisce** con qualcosa si usa `LIKE` insieme a due caratteri speciali (detti *caratteri jolly*):

* `%` sta per **qualunque sequenza di caratteri**, anche vuota;
* `_` sta per **esattamente un carattere** qualsiasi.

| Condizione | Vera per i testi che... |
|---|---|
| `nome LIKE 'Jean%'` | iniziano con "Jean" |
| `titolo LIKE '%Matrix'` | finiscono con "Matrix" |
| `titolo LIKE '%Star Wars%'` | contengono "Star Wars" in qualunque punto |
| `codice LIKE 'A___'` | sono lunghi 4 caratteri e iniziano con "A" |

```sql
-- Tutti i film della saga di Star Wars
SELECT titolo
FROM film
WHERE titolo LIKE '%Star Wars%';
```

| titolo |
|---|
| Star Wars: Episode IV – A New Hope |
| Star Wars: Episode VII – The Force Awakens |
| Star Wars: Episode V – The Empire Strikes Back |

Senza caratteri jolly, `LIKE 'Leon'` si comporta come `= 'Leon'`: per cercare un pezzo di testo il `%` è indispensabile.

## Il valore NULL

Nel database di esempio alcuni film non hanno il genere o la durata: il campo è **vuoto**. In SQL un campo vuoto contiene il valore speciale **`NULL`**, che significa "valore sconosciuto o mancante". `NULL` non è lo zero e non è il testo vuoto `''`: è proprio l'assenza di un valore.

`NULL` ha una regola tutta sua: **qualunque confronto con NULL non è mai vero**. Per questo la condizione `genere = NULL` non trova nulla, nemmeno le righe con il genere vuoto. Per controllare se un campo è vuoto esistono due operatori appositi: **`IS NULL`** e **`IS NOT NULL`**.

```sql
-- I film di cui non conosciamo il genere
SELECT titolo, regista
FROM film
WHERE genere IS NULL;
```

| titolo | regista |
|---|---|
| La strada | F. Fellini |
| Amarcord | F. Fellini |
| Star Wars: Episode IV – A New Hope | George Lucas |
| Star Wars: Episode VII – The Force Awakens | J. J. Abrams |
| Star Wars: Episode V – The Empire Strikes Back | Irvin Kershner |

:::caution[NULL e le condizioni "diverso da"]
Anche la condizione `genere <> 'commedia'` **esclude** i film con il genere `NULL`: per SQL non si sa se un film senza genere sia una commedia o no, quindi la condizione non è vera e la riga viene scartata. Se vogliamo davvero "tutti i film che non sono commedie, compresi quelli senza genere" dobbiamo scrivere `genere <> 'commedia' OR genere IS NULL`.
:::

## Eliminare i duplicati: DISTINCT

Chiediamo l'elenco delle città in cui ci sono sale:

```sql
SELECT citta
FROM sala;
```

Il risultato contiene sette righe, una per sala: Milano, Pisa, Pisa, Roma, Pisa, Milano, Pisa. SQL non elimina da solo le righe ripetute. Per farlo si aggiunge la parola chiave **`DISTINCT`** subito dopo `SELECT`:

```sql
SELECT DISTINCT citta
FROM sala;
```

| citta |
|---|
| Milano |
| Pisa |
| Roma |

`DISTINCT` si applica all'intera riga del risultato: con `SELECT DISTINCT citta, posti` due righe vengono considerate uguali solo se hanno la stessa città **e** lo stesso numero di posti. Diventerà molto utile con le [JOIN](../join/), che producono spesso righe ripetute.

## Ordinare il risultato: ORDER BY

Le righe del risultato non hanno un ordine garantito: di solito escono nell'ordine in cui sono memorizzate, ma non bisogna contarci. Per ordinarle si aggiunge in fondo la clausola **`ORDER BY`**, seguita dal campo su cui ordinare e, facoltativamente, dalla direzione:

* `ASC` (*ascending*): crescente, dalla A alla Z, dal più piccolo al più grande. È il valore predefinito, quindi si può omettere;
* `DESC` (*descending*): decrescente.

Si può ordinare su più campi: il secondo campo viene usato per ordinare le righe che hanno lo stesso valore nel primo, e così via.

```sql
-- Le sale ordinate per città e, nella stessa città, dalla più grande alla più piccola
SELECT nome, citta, posti
FROM sala
ORDER BY citta, posti DESC;
```

| nome | citta | posti |
|---|---|---|
| sala milano 1 | Milano | 300 |
| sala milano 2 | Milano | 200 |
| sala pisa 4 | Pisa | 250 |
| sala pisa 1 | Pisa | 200 |
| sala pisa 2 | Pisa | 100 |
| sala pisa 3 | Pisa | 50 |
| sala roma 1 | Roma | 250 |

### LIMIT: solo le prime righe

In MySQL la clausola **`LIMIT n`**, scritta per ultima, tiene solo le prime `n` righe del risultato. Insieme a `ORDER BY` permette di ottenere classifiche:

```sql
-- I tre film più recenti
SELECT titolo, annoproduzione
FROM film
ORDER BY annoproduzione DESC
LIMIT 3;
```

| titolo | annoproduzione |
|---|---|
| J'accuse | 2019 |
| The Post | 2017 |
| Star Wars: Episode VII – The Force Awakens | 2015 |

:::note
`LIMIT` non fa parte dello standard SQL e in altri DBMS si scrive in modo diverso (ad esempio `FETCH FIRST 3 ROWS ONLY` o `SELECT TOP 3`). Va usato con attenzione: se due film fossero entrambi del 2015, `LIMIT 3` ne terrebbe uno solo, scelto a caso. Per trovare "il film più recente" in modo sempre corretto vedremo una soluzione con le [sottoquery](../sottoquery/#confronto-con-un-singolo-valore).
:::

## Campi calcolati e alias: AS

Nella `SELECT` non siamo obbligati a scrivere solo nomi di campi: possiamo scrivere **espressioni**, che vengono calcolate per ogni riga. Con la parola chiave **`AS`** si dà un nome (un **alias**) alla colonna calcolata, che altrimenti avrebbe come intestazione l'espressione stessa.

```sql
-- Per ogni attore italiano, l'anno in cui ha compiuto 18 anni
SELECT nome, annonascita, annonascita + 18 AS anno_maggiore_eta
FROM attore
WHERE nazionalita = 'italiana';
```

| nome | annonascita | anno_maggiore_eta |
|---|---|---|
| Sophia Loren | 1934 | 1952 |
| Marcello Mastroianni | 1924 | 1942 |
| Monica Bellucci | 1964 | 1982 |

Si possono usare i normali operatori aritmetici `+`, `-`, `*`, `/` e anche le espressioni nella `WHERE` (ad esempio `WHERE posti * 2 > 400`). L'alias si può usare anche solo per rinominare una colonna: `SELECT nome AS nome_sala FROM sala`.

## Lavorare con le date

Le date in SQL si scrivono **tra apici** nel formato **`'AAAA-MM-GG'`** (anno, mese, giorno), ad esempio `'2004-12-25'` per il giorno di Natale 2004. Le date si possono confrontare con i normali operatori: una data "minore" è una data precedente.

```sql
-- Le proiezioni del 15 aprile 2021
SELECT codproiezione, codfilm, incasso
FROM proiezione
WHERE dataproiezione = '2021-04-15';

-- Le proiezioni del mese di dicembre 2004
SELECT codproiezione, codfilm, incasso
FROM proiezione
WHERE dataproiezione BETWEEN '2004-12-01' AND '2004-12-31';
```

:::caution[Le date senza apici]
Scrivere `WHERE dataproiezione = 2021-04-15` senza apici **non** dà errore, ma il risultato è sbagliato: per MySQL quella è una sottrazione tra numeri (2021 meno 4 meno 15, cioè 2002) e nessuna data sarà uguale a 2002.
:::

MySQL mette a disposizione molte funzioni sulle date. Le più utili negli esercizi sono:

| Funzione | Risultato |
|---|---|
| `CURDATE()` | la data di oggi |
| `CURDATE() - INTERVAL 1 DAY` | la data di ieri (allo stesso modo `INTERVAL 1 MONTH`, `INTERVAL 1 YEAR`...) |
| `YEAR(data)`, `MONTH(data)`, `DAY(data)` | l'anno, il mese, il giorno di una data |
| `DATEDIFF(data1, data2)` | il numero di giorni tra le due date |
| `TIMESTAMPDIFF(YEAR, data_nascita, CURDATE())` | gli anni compiuti, cioè l'età di una persona |

```sql
-- Le proiezioni di oggi
SELECT codproiezione, codfilm
FROM proiezione
WHERE dataproiezione = CURDATE();

-- Le proiezioni dell'anno 2021
SELECT codproiezione, codfilm
FROM proiezione
WHERE YEAR(dataproiezione) = 2021;
```

## Riepilogo: l'ordine delle clausole

Le clausole di una `SELECT` vanno scritte sempre in quest'ordine (quelle tra parentesi quadre sono facoltative):

```sql
SELECT [DISTINCT] campi o espressioni
FROM tabella
[WHERE condizione sulle righe]
[ORDER BY campi [ASC|DESC]]
[LIMIT n];
```

Nelle prossime pagine aggiungeremo le JOIN (dentro il `FROM`) e le clausole `GROUP BY` e `HAVING` (tra `WHERE` e `ORDER BY`).

## Esercizi

I primi esercizi della parte **"Database Film"** dell'[eserciziario](../esercizi/) usano una sola tabella (ad esempio *"Il nome di tutte le sale di Pisa"*, *"Il titolo dei film di F. Fellini prodotti dopo il 1960"*, *"Il titolo e la durata dei film di fantascienza, giapponesi o francesi, prodotti dopo il 1960"*).
