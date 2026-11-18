---
title: Creare tabelle e modificare i dati
description: CREATE TABLE, tipi di dato e vincoli, chiavi primarie ed esterne, INSERT, UPDATE e DELETE
---

Finora abbiamo solo **letto** i dati. In questa pagina vediamo i comandi per **creare la struttura** del database (DDL) e per **inserire, modificare e cancellare** i dati (DML). Sono comandi più semplici della `SELECT`, ma vanno usati con attenzione: a differenza di una query, **modificano davvero** il database, e non c'è un "annulla".

## Creare un database

```sql
CREATE DATABASE cinema;
USE cinema;
```

Il primo comando crea un database vuoto, il secondo dice al DBMS che i comandi successivi riguardano quel database. In phpMyAdmin il secondo passo corrisponde a selezionare il database nella colonna di sinistra.

## Creare una tabella: CREATE TABLE

Una tabella si crea indicando, per ogni campo, il **nome**, il **tipo di dato** ed eventuali **vincoli**. Ecco come si crea la tabella SALA del database di esempio:

```sql
CREATE TABLE sala (
    codsala INT AUTO_INCREMENT,
    posti   INT NOT NULL,
    nome    VARCHAR(50) NOT NULL,
    citta   VARCHAR(50) NOT NULL,
    PRIMARY KEY (codsala)
);
```

### I tipi di dato principali

| Tipo | Contiene | Esempio |
|---|---|---|
| `INT` | numeri interi | `300` |
| `DECIMAL(n, d)` | numeri con la virgola esatti, con `n` cifre di cui `d` decimali (adatto ai soldi) | `DECIMAL(8, 2)` → `123456.78` |
| `FLOAT`, `DOUBLE` | numeri con la virgola approssimati | `3.14159` |
| `VARCHAR(n)` | testi lunghi al massimo `n` caratteri | `VARCHAR(50)` |
| `CHAR(n)` | testi di lunghezza fissa `n` (codici, sigle) | `CHAR(2)` → `'MI'` |
| `TEXT` | testi lunghi | descrizioni, note |
| `DATE` | date | `'2021-04-15'` |
| `TIME` | orari | `'14:30:00'` |
| `DATETIME` | data e ora insieme | `'2021-04-15 14:30:00'` |
| `BOOLEAN` | vero o falso (in MySQL è un numero: 1 o 0) | `TRUE` |

La scelta del tipo corrisponde al **dominio** degli attributi che abbiamo definito in [progettazione](../../database/progettazione-logica/). Scegliere il tipo giusto è importante: un `DATE` permette di confrontare e ordinare le date e di usare le funzioni come `YEAR()`, mentre una data salvata come testo no.

### I vincoli

I vincoli sono regole che il DBMS fa rispettare automaticamente, rifiutando gli inserimenti e le modifiche che le violano. Sono lo strumento con cui il database garantisce l'**integrità** dei dati.

| Vincolo | Significato |
|---|---|
| `PRIMARY KEY (campi)` | i campi formano la chiave primaria: valori unici e mai `NULL` |
| `NOT NULL` | il campo deve sempre avere un valore |
| `UNIQUE` | non possono esistere due righe con lo stesso valore nel campo |
| `DEFAULT valore` | il valore usato se nell'inserimento il campo non viene indicato |
| `CHECK (condizione)` | ogni riga deve rispettare la condizione, ad esempio `CHECK (posti > 0)` |
| `AUTO_INCREMENT` | (MySQL) il DBMS assegna da solo un numero progressivo a ogni nuova riga |
| `FOREIGN KEY ... REFERENCES ...` | il campo è una chiave esterna (vedi sotto) |

### Chiavi esterne: FOREIGN KEY

Le chiavi esterne, che nello schema logico indichiamo con l'asterisco, si dichiarano con `FOREIGN KEY`, indicando a quale tabella e a quale campo fanno riferimento. Ecco la tabella PROIEZIONE:

```sql
CREATE TABLE proiezione (
    codproiezione  INT AUTO_INCREMENT,
    codfilm        INT NOT NULL,
    codsala        INT NOT NULL,
    incasso        INT NOT NULL DEFAULT 0,
    dataproiezione DATE NOT NULL,
    PRIMARY KEY (codproiezione),
    FOREIGN KEY (codfilm) REFERENCES film (codfilm),
    FOREIGN KEY (codsala) REFERENCES sala (codsala)
);
```

E la tabella RECITA, che ha una **chiave primaria composta** da due campi, ciascuno dei quali è anche chiave esterna:

```sql
CREATE TABLE recita (
    codattore INT,
    codfilm   INT,
    PRIMARY KEY (codattore, codfilm),
    FOREIGN KEY (codattore) REFERENCES attore (codattore),
    FOREIGN KEY (codfilm)   REFERENCES film (codfilm)
);
```

Una chiave esterna garantisce l'**integrità referenziale**: non si può inserire una proiezione di un film che non esiste, né cancellare una sala che ha delle proiezioni. Per questo motivo le tabelle vanno create nell'ordine giusto: prima FILM e SALA, poi PROIEZIONE, che fa riferimento a entrambe.

:::note[Cosa succede quando si cancella una riga collegata]
Dopo il `REFERENCES` si può indicare cosa fare quando la riga a cui si fa riferimento viene cancellata o modificata:

* `ON DELETE RESTRICT` (il comportamento predefinito): la cancellazione viene rifiutata;
* `ON DELETE CASCADE`: vengono cancellate automaticamente anche tutte le righe collegate (cancellando un film si cancellano tutte le sue proiezioni);
* `ON DELETE SET NULL`: nelle righe collegate la chiave esterna diventa `NULL`.

Lo stesso vale per `ON UPDATE`. Ad esempio `FOREIGN KEY (codfilm) REFERENCES film (codfilm) ON UPDATE CASCADE` fa sì che, se cambia il codice di un film, cambi automaticamente anche in tutte le sue proiezioni.
:::

## Modificare ed eliminare una tabella: ALTER e DROP

```sql
-- Aggiungere un campo
ALTER TABLE sala ADD indirizzo VARCHAR(100);

-- Modificare il tipo di un campo
ALTER TABLE sala MODIFY nome VARCHAR(80) NOT NULL;

-- Eliminare un campo
ALTER TABLE sala DROP indirizzo;

-- Eliminare un'intera tabella, con la struttura e tutti i dati
DROP TABLE sala;
```

Come abbiamo detto parlando di [schema e istanza](../../database/database/#schema-istanza-e-modelli-di-dati), lo schema di un database andrebbe modificato il meno possibile, soprattutto quando contiene già dei dati.

## Inserire dati: INSERT

```sql
INSERT INTO sala (posti, nome, citta)
VALUES (150, 'sala firenze 1', 'Firenze');
```

Si indicano la tabella, l'elenco dei campi da riempire e, dopo `VALUES`, i valori **nello stesso ordine** dei campi. Il campo `codsala` non è indicato perché è `AUTO_INCREMENT`: il DBMS gli assegna da solo il primo numero libero.

Con un solo comando si possono inserire più righe:

```sql
INSERT INTO sala (posti, nome, citta)
VALUES (150, 'sala firenze 1', 'Firenze'),
       (90,  'sala firenze 2', 'Firenze'),
       (400, 'sala torino 1',  'Torino');
```

Se si inseriscono valori per **tutti** i campi, nell'ordine in cui sono definiti nella tabella, l'elenco dei campi si può omettere (`INSERT INTO sala VALUES (8, 150, 'sala firenze 1', 'Firenze')`), ma è sconsigliato: se un giorno la tabella cambia struttura, il comando smette di funzionare o, peggio, mette i valori nei campi sbagliati.

## Modificare dati: UPDATE

```sql
-- La sala pisa 3 è stata ampliata a 80 posti
UPDATE sala
SET posti = 80
WHERE codsala = 5;
```

Dopo `SET` si indicano i campi da modificare e il nuovo valore (più campi si separano con virgole); la `WHERE` indica **quali righe** modificare, esattamente come nella `SELECT`. Il nuovo valore può essere un'espressione che usa il valore vecchio:

```sql
-- Tutte le sale di Pisa guadagnano 10 posti
UPDATE sala
SET posti = posti + 10
WHERE citta = 'Pisa';
```

## Cancellare dati: DELETE

```sql
-- Cancellare le proiezioni senza incasso
DELETE FROM proiezione
WHERE incasso = 0;
```

`DELETE` cancella **intere righe**: non si indicano i campi. Anche qui è la `WHERE` a scegliere quali.

:::danger[UPDATE e DELETE senza WHERE]
Se si dimentica la `WHERE`, il comando viene applicato a **tutte le righe** della tabella: `UPDATE sala SET posti = 80` porta a 80 posti tutte le sale, `DELETE FROM proiezione` svuota completamente la tabella delle proiezioni. Il DBMS non chiede conferma.

Un'abitudine prudente è scrivere **prima** la `SELECT` con la stessa `WHERE` (`SELECT * FROM proiezione WHERE incasso = 0`), controllare che le righe trovate siano proprio quelle da modificare o cancellare, e solo dopo trasformarla in `UPDATE` o `DELETE`.
:::

## Esercizi

L'[eserciziario](../esercizi/) è dedicato alle interrogazioni con `SELECT`. Per esercitarsi sui comandi di questa pagina si può provare a ricreare da zero, con `CREATE TABLE`, la struttura del database dei film, e a inserirvi qualche riga con `INSERT`, verificando che i vincoli rifiutino i dati non validi (una proiezione di un film inesistente, una sala senza nome...).
