---
title: Il Foglio di Calcolo
description: Guida completa a OnlyOffice Spreadsheets — dalle basi della formattazione alle funzioni condizionali, riferimenti, CERCA.X e grafici.
---

Ogni giorno, in uffici, scuole, negozi e ospedali, qualcuno sta aprendo un **foglio di calcolo** per organizzare dati, fare calcoli, creare grafici o prendere decisioni. È uno degli strumenti informatici più usati al mondo — capirlo bene è una competenza concreta e immediatamente spendibile.

Inoltre, lo studio del foglio di calcolo costituisce un perfetto **ponte verso la programmazione vera e propria**: l'uso delle celle e dei loro indirizzi ci allena a pensare in termini di **variabili** (contenitori di memoria con un nome e un valore), mentre le formule e le condizioni ci introducono all'uso di **funzioni**, operatori logici e strutture decisionali.

In questo capitolo useremo **OnlyOffice**, un software gratuito e open-source che funziona esattamente come Microsoft Excel (e apre gli stessi file `.xlsx`), ma senza costi per scuole e studenti.

:::tip[Scarica OnlyOffice gratis]
👉 **[Download OnlyOffice Desktop Editors](https://www.onlyoffice.com/download-desktop.aspx)**  
Scegli la versione per il tuo sistema operativo (Windows, macOS o Linux). L'installazione è semplice e gratuita.  
In alternativa puoi usare **OnlyOffice Online** direttamente nel browser, senza installare nulla.
:::

## 1. Celle, tipi di dato e formattazione

### 1.1 Il foglio di lavoro

Un foglio di calcolo è una griglia di **celle**, ognuna identificata da una **colonna** (lettera: A, B, C…) e una **riga** (numero: 1, 2, 3…).

```text
        A          B          C          D
   ┌──────────┬──────────┬──────────┬──────────┐
 1 │  Nome    │  Età     │  Voto    │          │
   ├──────────┼──────────┼──────────┼──────────┤
 2 │  Alice   │  15      │  8.5     │          │
   ├──────────┼──────────┼──────────┼──────────┤
 3 │  Brando  │  14      │  7       │          │
   └──────────┴──────────┴──────────┴──────────┘
         ↑
      Cella A1 = "Nome"
      Cella B2 = 15
      Cella C3 = 7
```

Ogni cella può contenere **quattro tipi fondamentali di dato**:

| Tipo | Descrizione | Esempi | Come viene salvato |
|------|-------------|--------|--------------------|
| **Testo** (*stringa*) | Sequenza di caratteri | `"Alice"`, `"Milano"`, `"ciao"` | Codifica Unicode (come visto nel capitolo precedente!) |
| **Numero** | Intero o decimale | `42`, `8.5`, `-3`, `0.001` | Virgola mobile a 64 bit (standard IEEE 754) |
| **Data/Ora** | Giorno e ora | `19/08/2025`, `14:30` | Internamente un numero: i giorni dal 1/1/1900 |
| **Booleano** | Vero o Falso | `VERO`, `FALSO` | 1 bit: 1 = VERO, 0 = FALSO |

:::note[Collegamento con la Rappresentazione dell'Informazione]
Questi tipi di dato non sono una novità: sono esattamente le stesse codifiche che abbiamo studiato nel capitolo sulla Rappresentazione dell'Informazione. Testi = Unicode, numeri interi e decimali = binario/virgola mobile, booleani = 1 bit. Il foglio di calcolo ci mostra tutto questo "in azione"!
:::

### 1.2 Formattazione delle celle

Il contenuto di una cella e il suo **aspetto visivo** sono due cose separate. Un numero come `8.5` può essere visualizzato in modi diversissimi senza cambiare il suo valore reale:

| Formato | Come appare | Quando si usa |
|---------|-------------|---------------|
| Numero | `8.50` | Dati generici |
| Valuta | `€ 8,50` | Prezzi e importi |
| Percentuale | `850%` | Rapporti e proporzioni |
| Data | (dipende dal valore) | Date e scadenze |

**Per formattare una cella** in OnlyOffice: seleziona la cella o un intervallo → clic destro → *Formato celle* (oppure `Ctrl+1`).

Da questa finestra puoi modificare:
- **Categoria:** numero, valuta, percentuale, data, testo…
- **Tipo di carattere:** dimensione, grassetto, corsivo, colore
- **Bordi:** stile e colore dei bordi della cella
- **Riempimento:** colore di sfondo

:::tip[Selezionare più celle contemporaneamente]
- `Clic` + trascina → seleziona un rettangolo di celle
- `Ctrl + Clic` → seleziona celle non adiacenti
- `Ctrl + A` → seleziona tutto il foglio
- Clic sull'intestazione di colonna (es. `A`) → seleziona tutta la colonna
:::

---

## 2. Formattazione condizionale

La **formattazione condizionale** cambia automaticamente l'aspetto di una cella in base al suo valore. È utilissima per evidenziare i dati importanti a colpo d'occhio.

**Esempi pratici:**
- 🟢 Voti ≥ 6: sfondo verde
- 🔴 Voti < 6: sfondo rosso
- 🟡 Valori vicini alla soglia: sfondo giallo

### 2.1 Come si imposta in OnlyOffice

1. Seleziona l'intervallo di celle (es. `C2:C30` con i voti)
2. Menu *Home* → *Formattazione condizionale*
3. Scegli una regola:

| Tipo di regola | Descrizione |
|----------------|-------------|
| **Evidenzia celle** | Colore basato su: valore, testo, data, duplicati |
| **Regole prime/ultime** | Evidenzia i valori più alti o più bassi |
| **Barre dati** | Una barra orizzontale proporzionale al valore |
| **Scale di colore** | Gradiente di colore (es. rosso → verde) |
| **Set di icone** | Frecce, semafori, stelle in base al valore |

**Esempio — registro voti con tre fasce:**

| Regola | Condizione | Formato |
|--------|-----------|---------|
| Sufficiente | Valore ≥ 6 | Sfondo verde chiaro |
| Insufficiente | Valore < 6 | Sfondo rosso chiaro |
| Eccellente | Valore ≥ 9 | Grassetto + sfondo verde scuro |

:::note[Priorità delle regole]
Quando più regole si applicano alla stessa cella, viene usata quella **con priorità più alta** (la prima nell'elenco). Nell'esempio sopra, la regola "eccellente" deve stare **sopra** quella "sufficiente" nell'elenco, altrimenti un 9 verrebbe colorato solo di verde chiaro.
:::

---

## 3. Riferimenti a celle e intervalli

Il vero potere del foglio di calcolo è la possibilità di usare il **valore di una cella dentro un'altra cella**. Questo si fa tramite i **riferimenti**.

### 3.1 Riferimento relativo

Scrivere `=A1` in un'altra cella significa: "prendi il valore di A1".

**La caratteristica chiave:** quando copi o trascini una formula, i riferimenti relativi si **aggiornano automaticamente** seguendo lo spostamento.

```text
    A        B         C
┌───────┬──────────┬──────────┐
│  10   │ =A1*2    │          │  ← B1 contiene =A1*2 → mostra 20
├───────┼──────────┼──────────┤
│  20   │ =A2*2    │          │  ← Trascinando B1 in B2, diventa =A2*2 → 40
├───────┼──────────┼──────────┤
│  30   │ =A3*2    │          │  ← B3 diventa =A3*2 → 60
└───────┴──────────┴──────────┘
```

### 3.2 Riferimento assoluto

A volte non vuoi che il riferimento cambi trascinando. Per "bloccare" una cella si usa il simbolo `$`.

| Notazione | Significato | Cosa si blocca |
|-----------|-------------|----------------|
| `A1` | Relativo | Nulla — si aggiorna tutto |
| `$A$1` | Assoluto | Sia la colonna che la riga |
| `$A1` | Misto | Solo la colonna A |
| `A$1` | Misto | Solo la riga 1 |

**Esempio pratico — IVA in una cella fissa:**

```text
    A           B              C
┌────────┬──────────────┬────────────────────────────┐
│ Prezzo │ Prezzo + IVA │                            │
├────────┼──────────────┼────────────────────────────┤
│ 100    │ =A2*(1+$B$1) │   B1 contiene 0.22 (22%)   │
├────────┼──────────────┤                            │
│ 250    │ =A3*(1+$B$1) │   $B$1 non cambia mai!     │
├────────┼──────────────┤                            │
│  80    │ =A4*(1+$B$1) │                            │
└────────┴──────────────┴────────────────────────────┘
```

:::tip[Scorciatoia per il simbolo $]
Mentre scrivi una formula, clicca sulla cella di riferimento e poi premi **F4** per ciclare tra le modalità: relativo → assoluto → misto riga → misto colonna.
:::

### 3.3 Intervalli di celle

Un **intervallo** è un rettangolo di celle indicato con `PrimaC:UltimaC`:

| Notazione | Significato |
|-----------|-------------|
| `A1:A10` | Dalla cella A1 alla A10 (colonna) |
| `A1:E1` | Dalla cella A1 alla E1 (riga) |
| `A1:C5` | Rettangolo 3×5 (3 colonne, 5 righe) |
| `A:A` | Tutta la colonna A |
| `1:1` | Tutta la riga 1 |

Gli intervalli si usano prevalentemente nelle funzioni (es. `=SOMMA(A1:A10)`).

---

## 4. Operazioni semplici nelle celle

Una **formula** in una cella inizia sempre con il simbolo `=`. Senza l'uguale, il foglio interpreta il contenuto come testo.

### 4.1 Operatori aritmetici

| Operatore | Operazione | Esempio | Risultato |
|-----------|-----------|---------|-----------|
| `+` | Addizione | `=3+5` | 8 |
| `-` | Sottrazione | `=10-4` | 6 |
| `*` | Moltiplicazione | `=6*7` | 42 |
| `/` | Divisione | `=15/4` | 3.75 |
| `^` | Potenza | `=2^10` | 1024 |
| `()` | Parentesi | `=(3+2)*4` | 20 |

### 4.2 Operatori di confronto

Producono un risultato booleano (`VERO` o `FALSO`) e si usano nelle funzioni condizionali:

| Operatore | Significato | Esempio |
|-----------|-------------|---------|
| `=` | Uguale | `=A1=B1` |
| `<>` | Diverso | `=A1<>0` |
| `>` | Maggiore | `=C3>6` |
| `<` | Minore | `=C3<6` |
| `>=` | Maggiore o uguale | `=B2>=18` |
| `<=` | Minore o uguale | `=B2<=100` |

### 4.3 Priorità degli operatori

Come in matematica, le operazioni hanno una priorità: prima le parentesi, poi le potenze, poi moltiplicazione e divisione, infine addizione e sottrazione.

```text
  =2+3*4        → 14     (non 20! Il * ha priorità sul +)
  =(2+3)*4      → 20     (le parentesi forzano l'addizione prima)
  =2^3+1        → 9      (2³=8, poi 8+1=9)
```

---

## 5. Funzioni di base

Le **funzioni** sono formule predefinite che eseguono calcoli complessi con pochi caratteri. La sintassi è sempre:

```
=NOME_FUNZIONE(argomento1; argomento2; ...)
```

:::note[Punto e virgola o virgola?]
In OnlyOffice con lingua italiana, gli argomenti di una funzione si separano con il **punto e virgola** (`;`). Nelle versioni in inglese si usa la virgola (`,`).
:::

### 5.1 Funzioni matematiche e statistiche

| Funzione | Descrizione | Esempio |
|----------|-------------|---------|
| `SOMMA(intervallo)` | Somma tutti i valori | `=SOMMA(A1:A10)` |
| `MEDIA(intervallo)` | Media aritmetica | `=MEDIA(B2:B30)` |
| `MIN(intervallo)` | Valore minimo | `=MIN(C1:C100)` |
| `MAX(intervallo)` | Valore massimo | `=MAX(C1:C100)` |
| `CONTA.VALORI(intervallo)` | Conta le celle non vuote | `=CONTA.VALORI(A:A)` |
| `CONTA.NUMERI(intervallo)` | Conta solo le celle con numeri | `=CONTA.NUMERI(B:B)` |
| `ARROTONDA(numero; cifre)` | Arrotonda a N cifre decimali | `=ARROTONDA(3.14159; 2)` → 3.14 |
| `RADQ(numero)` | Radice quadrata | `=RADQ(144)` → 12 |
| `VALORE.ASSOLUTO(numero)` | Valore assoluto $|x|$ | `=VALORE.ASSOLUTO(-7)` → 7 |

**Esempio pratico — registro voti:**

```text
     A          B
  ┌────────┬──────────┐
1 │ Voti   │          │
  ├────────┼──────────┤
2 │  7     │          │
3 │  8.5   │          │
4 │  6     │          │   Nella cella B6: =MEDIA(A2:A5)  → 7.5
5 │  8.5   │          │   Nella cella B7: =MAX(A2:A5)    → 8.5
  ├────────┼──────────┤   Nella cella B8: =MIN(A2:A5)    → 6
6 │ Media  │  7.5     │
7 │ Max    │  8.5     │
8 │ Min    │  6       │
  └────────┴──────────┘
```

### 5.2 Funzioni di testo

| Funzione | Descrizione | Esempio |
|----------|-------------|---------|
| `LUNGHEZZA(testo)` | Numero di caratteri | `=LUNGHEZZA("ciao")` → 4 |
| `MAIUSC(testo)` | Converti in maiuscolo | `=MAIUSC("ciao")` → `CIAO` |
| `MINUSC(testo)` | Converti in minuscolo | `=MINUSC("CIAO")` → `ciao` |
| `CONCATENA(t1; t2; ...)` | Unisce testi | `=CONCATENA("Ciao "; "Mondo")` |
| `SINISTRA(testo; n)` | Primi N caratteri | `=SINISTRA("Informatica"; 4)` → `Info` |
| `DESTRA(testo; n)` | Ultimi N caratteri | `=DESTRA("Informatica"; 5)` → `atica` |

---

## 6. Funzioni condizionali: SE e PIÙ.SE

### 6.1 La funzione SE

`SE` è la funzione più potente e versatile del foglio di calcolo. Permette di scegliere un valore o un calcolo in base a una condizione.

```
=SE(condizione; valore_se_vero; valore_se_falso)
```

**Esempio — classificazione voti:**

```text
=SE(C2>=6; "Sufficiente"; "Insufficiente")
```

| C2 (voto) | Risultato della formula |
|-----------|------------------------|
| 8 | `"Sufficiente"` |
| 5.5 | `"Insufficiente"` |
| 6 | `"Sufficiente"` |

**SE può essere annidato** (un SE dentro un altro SE) per gestire più casi:

```text
=SE(C2>=9; "Ottimo"; SE(C2>=7; "Buono"; SE(C2>=6; "Sufficiente"; "Insufficiente")))
```

```text
Voto ≥ 9  →  "Ottimo"
Voto ≥ 7  →  "Buono"
Voto ≥ 6  →  "Sufficiente"
Voto < 6  →  "Insufficiente"
```

:::note[Limite dei SE annidati]
Annidare molti `SE` rende la formula difficile da leggere e correggere. Per più di 3 casi, è meglio usare `PIÙ.SE`.
:::

### 6.2 La funzione PIÙ.SE

`PIÙ.SE` valuta più condizioni in ordine, restituendo il valore della prima condizione vera:

```
=PIÙ.SE(condizione1; valore1; condizione2; valore2; ...; VERO; valore_default)
```

**Lo stesso esempio di prima con PIÙ.SE:**

```text
=PIÙ.SE(C2>=9; "Ottimo"; C2>=7; "Buono"; C2>=6; "Sufficiente"; VERO; "Insufficiente")
```

Molto più leggibile! L'ultimo argomento `VERO; "Insufficiente"` è il "default" — viene usato se nessuna condizione precedente è vera.

**Esempio pratico — calcolo della fascia d'età:**

```text
=PIÙ.SE(B2<13; "Bambino"; B2<18; "Adolescente"; B2<65; "Adulto"; VERO; "Anziano")
```

### 6.3 Funzioni condizionali aggregate

| Funzione | Descrizione | Esempio |
|----------|-------------|---------|
| `CONTA.SE(intervallo; criterio)` | Conta celle che soddisfano la condizione | `=CONTA.SE(C:C; ">=6")` |
| `SOMMA.SE(intervallo; criterio; somma_se)` | Somma solo i valori che soddisfano la condizione | `=SOMMA.SE(B:B; ">=18"; C:C)` |
| `MEDIA.SE(intervallo; criterio)` | Media delle celle che soddisfano la condizione | `=MEDIA.SE(C:C; ">6")` |

---

## 7. CERCA.X — cercare dati in altre tabelle

### 7.1 Il problema del CERCA.VERT

Immagina di avere due tabelle: una con i codici prodotto e i prezzi, un'altra con gli ordini. Vuoi trovare automaticamente il prezzo di ogni prodotto ordinato.

```text
Tabella Prodotti (Foglio1)       Tabella Ordini (Foglio2)
  A           B                    A            B         C
┌──────────┬────────┐            ┌──────────┬────────┬──────────┐
│ Codice   │ Prezzo │            │ Ordine   │ Codice │ Prezzo   │
├──────────┼────────┤            ├──────────┼────────┼──────────┤
│ P001     │ 12.50  │            │ 001      │ P003   │  ???     │
│ P002     │  8.00  │            │ 002      │ P001   │  ???     │
│ P003     │ 25.00  │            │ 003      │ P002   │  ???     │
└──────────┴────────┘            └──────────┴────────┴──────────┘
```

Il vecchio `CERCA.VERT` funzionava ma aveva **limiti importanti**:
- Cercava solo la colonna **più a sinistra** della tabella
- Richiedeva di contare manualmente il numero di colonna del risultato
- Non supportava ricerche da destra verso sinistra

### 7.2 CERCA.X — la soluzione moderna

`CERCA.X` (in inglese *XLOOKUP*) è la funzione moderna che risolve tutti questi problemi:

```
=CERCA.X(valore_cercato; dove_cercare; cosa_restituire; [se_non_trovato])
```

| Argomento | Descrizione |
|-----------|-------------|
| `valore_cercato` | Il valore da cercare (es. il codice prodotto) |
| `dove_cercare` | L'intervallo dove cercare (es. la colonna codici) |
| `cosa_restituire` | L'intervallo da cui prendere il risultato (es. la colonna prezzi) |
| `se_non_trovato` | *(opzionale)* Cosa mostrare se non trova nulla (es. `"Non trovato"`) |

**Applicazione all'esempio:**

```text
Nella cella C2 di Foglio2:
=CERCA.X(B2; Foglio1.A:A; Foglio1.B:B; "Non trovato")

  B2 = "P003"  →  cerca "P003" nella colonna A di Foglio1
                →  trovato in riga 3
                →  restituisce B3 di Foglio1 → 25.00 ✓
```

**Vantaggi rispetto a CERCA.VERT:**

| Caratteristica | CERCA.VERT | CERCA.X |
|----------------|-----------|---------|
| Direzione di ricerca | Solo da sinistra | Qualsiasi direzione |
| Numero colonna da specificare | Sì (fragile!) | No (si specifica direttamente) |
| Gestione "non trovato" | Complicata | Argomento opzionale semplice |
| Leggibilità | Bassa | Alta |
| Disponibilità | Storica | OnlyOffice 7.2+, Excel 2019+ |

**Esempio completo — anagrafica studenti:**

```text
Foglio "Studenti": colonna A = ID, colonna B = Nome, colonna C = Classe

In un altro foglio, trovare il nome dato l'ID:
=CERCA.X(A2; Studenti.A:A; Studenti.B:B; "ID non presente")

Trovare la classe:
=CERCA.X(A2; Studenti.A:A; Studenti.C:C; "ID non presente")
```

:::tip[CERCA.X con risultato non trovato]
Usare sempre il quarto argomento con un messaggio chiaro come `"Non trovato"` o `""` (stringa vuota). In caso contrario, la cella mostrerà l'errore `#N/D`, che è poco user-friendly.
:::

---

## 8. Grafici

I **grafici** trasformano una tabella di numeri in una rappresentazione visiva che permette di cogliere tendenze, confronti e distribuzioni in pochi secondi.

### 8.1 Tipi di grafico

| Tipo | Quando usarlo | Esempio |
|------|--------------|---------|
| **Istogramma / Colonne** | Confrontare categorie distinte | Voti per studente, vendite per mese |
| **Grafico a linee** | Mostrare un andamento nel tempo | Temperatura giornaliera, crescita utenti |
| **Grafico a torta** | Mostrare le proporzioni di un tutto | Distribuzione voti, spese per categoria |
| **Dispersione (XY)** | Relazione tra due variabili numeriche | Altezza vs peso, ore studio vs voto |
| **Barre orizzontali** | Come colonne, ma con etichette lunghe | Classifica con nomi interi |

### 8.2 Come creare un grafico in OnlyOffice

1. **Seleziona i dati** incluse le intestazioni (es. `A1:B6`)
2. Menu *Inserisci* → *Grafico*
3. Scegli il **tipo di grafico** nella finestra che appare
4. Clicca *OK* — il grafico appare nel foglio

### 8.3 Personalizzare il grafico

Dopo aver creato il grafico, fai doppio clic su di esso per entrare in modalità modifica:

| Elemento | Come personalizzarlo |
|----------|---------------------|
| **Titolo** | Clic sul testo del titolo e scrivi |
| **Colori** | Clic destro sulla serie → *Formato serie dati* |
| **Legenda** | Scheda *Layout del grafico* → *Legenda* |
| **Assi** | Clic destro sull'asse → *Formato asse* (min, max, scala) |
| **Etichette dati** | Clic destro sulla serie → *Aggiungi etichette dati* |

### 8.4 Scegliere il grafico giusto

```text
Stai confrontando valori di categorie diverse?
  → ISTOGRAMMA a colonne

I tuoi dati cambiano nel tempo?
  → GRAFICO A LINEE

Vuoi mostrare le proporzioni di un tutto?
  → TORTA (ma solo con poche categorie, max 5-6)

Hai due variabili numeriche e vuoi vedere la relazione?
  → DISPERSIONE (XY)
```

:::note[La trappola della torta]
Il grafico a torta sembra attraente ma è spesso il **peggior modo** di presentare dati. Con più di 5-6 fette, diventa impossibile da leggere. Considera sempre un istogramma come alternativa.
:::

---

## Riepilogo

| Argomento | Concetto chiave |
|-----------|----------------|
| Tipi di dato | Testo, numero, data, booleano — stessa codifica binaria vista nella Rappresentazione dell'Informazione |
| Formattazione condizionale | Cambia l'aspetto automaticamente in base al valore |
| Riferimenti relativi | Si aggiornano trascinando → `A1` |
| Riferimenti assoluti | Non cambiano mai → `$A$1` |
| Operatori | `+`, `-`, `*`, `/`, `^`, confronti (`>`, `<`, `=`, `<>`) |
| Funzioni base | `SOMMA`, `MEDIA`, `MIN`, `MAX`, `CONTA.VALORI`, `ARROTONDA` |
| `SE` / `PIÙ.SE` | Formule che scelgono il risultato in base a una condizione |
| `CERCA.X` | Cerca un valore in una colonna e restituisce il dato corrispondente in un'altra |
| Grafici | Colonne, linee, torta, dispersione — scegliere il tipo giusto è fondamentale |

---

➡️ Vai agli **[Esercizi](/manuale-libero-online-di-informatica/foglio-di-calcolo/esercizi/)** per mettere in pratica tutto ciò che hai imparato!
