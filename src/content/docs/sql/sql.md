---
title: Il linguaggio SQL
description: Introduzione al linguaggio SQL, il database di esempio e il percorso della sezione
---

Nella sezione [Database](../../database/database/) abbiamo visto come si progetta una base di dati: dallo schema E/R si arriva alle tabelle del modello relazionale. In questa sezione impariamo a **usare** un database già esistente, cioè a chiedergli le informazioni che ci servono. Per farlo si usa il linguaggio **SQL**.

## Cos'è SQL

**SQL** (*Structured Query Language*, pronunciato "esse-cu-elle" oppure "sequel") è il linguaggio standard per lavorare con i database relazionali. È nato negli anni '70 nei laboratori IBM ed è oggi supportato, con piccole differenze, da tutti i DBMS relazionali: MySQL, MariaDB, PostgreSQL, SQLite, Oracle, SQL Server.

SQL è molto diverso dai linguaggi di programmazione come C o Python, perché è un linguaggio **dichiarativo**:

* in C o Python scriviamo **come** ottenere un risultato (un ciclo che scorre i dati, un `if` che controlla ogni elemento, una variabile che accumula il conteggio...);
* in SQL scriviamo soltanto **cosa** vogliamo ottenere ("i nomi delle sale di Pisa"), e sarà il DBMS a decidere come recuperare i dati nel modo più efficiente.

Un comando SQL che chiede dei dati al database si chiama **query** (o *interrogazione*). Il risultato di una query è sempre una **tabella**: a volte di molte righe, a volte di una sola riga, a volte vuota.

## Le parti del linguaggio

Come anticipato nell'[introduzione ai database](../../database/database/), i comandi SQL si dividono in gruppi a seconda dello scopo:

| Gruppo | Serve a... | Comandi principali |
|---|---|---|
| **DQL** (*Data Query Language*) | interrogare i dati | `SELECT` |
| **DML** (*Data Manipulation Language*) | inserire, modificare, cancellare i dati | `INSERT`, `UPDATE`, `DELETE` |
| **DDL** (*Data Definition Language*) | creare e modificare la struttura (lo schema) | `CREATE`, `ALTER`, `DROP` |
| **DCL** (*Data Control Language*) | gestire utenti e permessi | `GRANT`, `REVOKE` |

La parte più importante, e quella su cui ci concentreremo di più, è la **`SELECT`**: è il comando che si usa di gran lunga più spesso ed è anche quello che richiede più ragionamento.

## Come provare le query

Per esercitarsi serve un DBMS installato. A scuola usiamo **MariaDB** (una versione di MySQL, del tutto compatibile) incluso nel pacchetto **XAMPP**:

1. si avvia XAMPP e si fa partire il servizio **MySQL**;
2. si apre il browser all'indirizzo `http://localhost/phpmyadmin`;
3. si importa il database di esempio (scheda **Importa**, scegliendo il file `.sql`);
4. si seleziona il database a sinistra e si apre la scheda **SQL**, dove si scrivono le query e si eseguono con **Esegui**.

In alternativa a phpMyAdmin si può usare un programma come HeidiSQL o DBeaver, che si collega allo stesso server.

## Regole di scrittura

Prima di iniziare, qualche regola generale che vale per tutte le query:

* **Maiuscole e minuscole:** le parole chiave (`SELECT`, `FROM`, `WHERE`...) possono essere scritte in qualunque modo, ma per convenzione si scrivono in **maiuscolo**, così si distinguono a colpo d'occhio dai nomi di tabelle e campi, che scriviamo in minuscolo.
* **Spazi e a capo:** non contano. Una query si può scrivere su una sola riga, ma è molto più leggibile andare a capo a ogni clausola.
* **Punto e virgola:** segna la fine di un comando. Se si esegue una sola query è facoltativo, se se ne eseguono più di una di seguito è obbligatorio.
* **Testi e date** vanno tra **apici singoli**: `'Pisa'`, `'2004-12-25'`. MySQL accetta anche i doppi apici, ma gli apici singoli sono lo standard e funzionano ovunque. I **numeri** si scrivono senza apici.
* **Commenti:** tutto ciò che segue `--` (due trattini e uno spazio) fino alla fine della riga è un commento.

```sql
-- I nomi delle sale di Pisa
SELECT nome
FROM sala
WHERE citta = 'Pisa';
```

:::caution[Testi uguali per noi, diversi per il computer]
Un confronto come `citta = 'Pisa'` trova solo le righe in cui il valore è scritto **esattamente** così. Con le impostazioni usuali MySQL non distingue tra maiuscole e minuscole (`'pisa'` trova anche `'Pisa'`), ma basta uno spazio in più o un errore di battitura (`'Pisa '`, `'Pissa'`) per non trovare nulla. Se una query restituisce una tabella vuota e non ce lo aspettiamo, la prima cosa da controllare è come sono scritti i dati nel database.
:::

## Il database di esempio

Tutti gli esempi di questa sezione usano lo stesso database, lo stesso dell'eserciziario: un piccolo **catalogo di film** con gli attori che vi hanno recitato e le proiezioni nelle sale cinematografiche. Lo schema logico è il seguente (chiave primaria sottolineata, chiavi esterne con l'asterisco):

* **ATTORE** (<u>codattore</u>, nome, annonascita, nazionalita)
* **FILM** (<u>codfilm</u>, titolo, annoproduzione, nazionalita, regista, genere, durata)
* **RECITA** (<u>codattore\*</u>, <u>codfilm\*</u>)
* **SALA** (<u>codsala</u>, posti, nome, citta)
* **PROIEZIONE** (<u>codproiezione</u>, codfilm\*, codsala\*, incasso, dataproiezione)

Proviamo a leggere lo schema come abbiamo imparato nella [progettazione logica](../../database/progettazione-logica/):

* tra **FILM** e **ATTORE** c'è un'associazione **N:N** (un film ha molti attori, un attore recita in molti film), che è stata tradotta con la tabella di collegamento **RECITA**: ogni riga di RECITA dice "l'attore X ha recitato nel film Y";
* **PROIEZIONE** collega un film a una sala in una certa data: ogni proiezione riguarda un solo film e una sola sala, mentre un film può essere proiettato molte volte e in una sala si proiettano molti film.

Per farsi un'idea dei dati, questa è la tabella **SALA** completa:

| codsala | posti | nome | citta |
|---|---|---|---|
| 1 | 300 | sala milano 1 | Milano |
| 2 | 200 | sala pisa 1 | Pisa |
| 3 | 100 | sala pisa 2 | Pisa |
| 4 | 250 | sala roma 1 | Roma |
| 5 | 50 | sala pisa 3 | Pisa |
| 6 | 200 | sala milano 2 | Milano |
| 7 | 250 | sala pisa 4 | Pisa |

Le altre tabelle contengono 18 film, 18 attori, 24 righe in RECITA e 15 proiezioni. Nelle pagine seguenti, sotto ogni query, è riportato il risultato ottenuto su questi dati.

:::tip[Studiare con il database aperto]
Il modo migliore per imparare SQL è provare ogni esempio sul database vero, modificarlo e vedere cosa cambia nel risultato. Leggere le query senza eseguirle è come studiare il nuoto sui libri.
:::

## Il percorso di questa sezione

1. [Interrogazioni di base](../select/): `SELECT`, `FROM`, `WHERE`, operatori di confronto e logici, `IN`, `BETWEEN`, `LIKE`, `NULL`, `DISTINCT`, ordinamento, campi calcolati e date.
2. [Interrogare più tabelle: le JOIN](../join/): collegare le tabelle tramite le chiavi esterne, alias, la stessa tabella usata due volte, `LEFT JOIN`.
3. [Funzioni di aggregazione e raggruppamenti](../raggruppamenti/): `COUNT`, `SUM`, `AVG`, `MIN`, `MAX`, `GROUP BY` e `HAVING`.
4. [Sottoquery](../sottoquery/): query dentro altre query, `IN` e `NOT IN`, sottoquery nel `FROM`, e gli schemi per risolvere le richieste più comuni ("nessuno", "sia... sia...", "solo").
5. [Creare tabelle e modificare i dati](../modifica-dati/): `CREATE TABLE`, vincoli, `INSERT`, `UPDATE`, `DELETE`.
6. [Eserciziario](../esercizi/): la raccolta di esercizi su due database, un catalogo di film e un sistema di voli aerei.
