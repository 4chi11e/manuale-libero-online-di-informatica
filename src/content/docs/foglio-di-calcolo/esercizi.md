---
title: Esercizi — Foglio di Calcolo
description: Esercizi pratici su formattazione, riferimenti, funzioni SE e PIÙ.SE, CERCA.X e grafici con OnlyOffice.
---

Questi esercizi accompagnano il capitolo **[Il Foglio di Calcolo](/manuale-libero-online-di-informatica/foglio-di-calcolo/foglio-di-calcolo/)**. Per ogni esercizio è disponibile una soluzione a comparsa: prova a risolverlo da solo prima di aprirla!

---

## Tipologia 1 — Celle, tipi di dato e formattazione

### Esercizio 1.1
Apri un nuovo foglio di calcolo in OnlyOffice. Crea la seguente tabella partendo dalla cella A1:

| Nome | Cognome | Voto | Data esame |
|------|---------|------|-----------|
| Alice | Rossi | 8.5 | 15/06/2025 |
| Brando | Verdi | 6 | 15/06/2025 |
| Chiara | Bianchi | 9.5 | 16/06/2025 |
| Davide | Neri | 5 | 16/06/2025 |

Poi:
1. Formatta la colonna *Voto* (C2:C5) come numero con **1 cifra decimale**.
2. Formatta la colonna *Data esame* (D2:D5) nel formato `gg/mm/aaaa`.
3. Metti in **grassetto** la riga delle intestazioni (riga 1).
4. Aggiungi un bordo a tutta la tabella (A1:D5).

<details>
<summary>💡 Soluzione</summary>

1. Seleziona C2:C5 → `Ctrl+1` → Categoria: *Numero* → Posizioni decimali: 1
2. Seleziona D2:D5 → `Ctrl+1` → Categoria: *Data* → scegli il formato `gg/mm/aaaa`
3. Seleziona A1:D1 → `Ctrl+G` (grassetto)
4. Seleziona A1:D5 → `Ctrl+1` → scheda *Bordi* → scegli *Tutti i bordi*

</details>

---

### Esercizio 1.2 — Tipi di dato
Per ciascun valore nella colonna A, indica nella colonna B il tipo di dato (Testo / Numero / Data / Booleano):

| A | B (tua risposta) |
|---|---|
| `"Ciao"` | |
| `42` | |
| `01/01/2000` | |
| `VERO` | |
| `3.14` | |
| `"123"` | |

:::note
Attenzione all'ultima riga: `"123"` è scritto tra virgolette, quindi è **testo**, non numero!
:::

<details>
<summary>💡 Soluzione</summary>

| A | B (risposta) |
|---|---|
| `"Ciao"` | Testo |
| `42` | Numero (intero) |
| `01/01/2000` | Data |
| `VERO` | Booleano |
| `3.14` | Numero (decimale) |
| `"123"` | Testo (le virgolette forzano il tipo testo) |

</details>

---

## Tipologia 2 — Formattazione condizionale

### Esercizio 2.1
Partendo dalla tabella dell'Esercizio 1.1, applica la formattazione condizionale alla colonna dei voti (C2:C5):
- **Sfondo rosso chiaro** per voti < 6
- **Sfondo verde chiaro** per voti ≥ 6
- **Grassetto + sfondo verde scuro** per voti ≥ 9

<details>
<summary>💡 Soluzione</summary>

1. Seleziona C2:C5
2. *Home* → *Formattazione condizionale* → *Nuova regola*
3. Prima regola: "Valore cella" + "minore di" + `6` → Formato: riempimento rosso chiaro
4. Seconda regola: "Valore cella" + "maggiore o uguale a" + `6` → Formato: riempimento verde chiaro
5. Terza regola: "Valore cella" + "maggiore o uguale a" + `9` → Formato: grassetto + riempimento verde scuro

**Importante:** nella finestra di gestione regole, metti la regola del 9 **in cima** (priorità più alta), altrimenti un 9.5 verrebbe colorato solo di verde chiaro.

</details>

---

### Esercizio 2.2
In un nuovo foglio, inserisci in A1:A10 i numeri da 1 a 10. Applica una **scala di colore** (da rosso per i valori bassi a verde per i valori alti) usando la formattazione condizionale.

<details>
<summary>💡 Soluzione</summary>

1. Seleziona A1:A10
2. *Home* → *Formattazione condizionale* → *Scale di colore*
3. Scegli la scala predefinita rosso-giallo-verde (o personalizzala)

I numeri bassi appariranno tendenti al rosso, quelli alti al verde — utile per visualizzare classifiche o intensità.

</details>

---

## Tipologia 3 — Riferimenti a celle e intervalli

### Esercizio 3.1 — Riferimenti relativi
Crea questa tabella:

|   | A | B |
|---|---|---|
| **1** | Quantità | Prezzo unitario |
| **2** | 5 | 12 |
| **3** | 8 | 7.5 |
| **4** | 3 | 20 |

Nella colonna C (intestazione "Totale"), scrivi in C2 una formula che moltiplica Quantità × Prezzo unitario, poi **trascinala** fino a C4.

Domanda: dopo il trascinamento, cosa contengono C3 e C4?

<details>
<summary>💡 Soluzione</summary>

- C2: `=A2*B2` → 60
- Trascinando verso il basso, i riferimenti si aggiornano automaticamente:
  - C3: `=A3*B3` → 60
  - C4: `=A4*B4` → 60

Questo è il comportamento dei **riferimenti relativi**: si adattano alla nuova posizione della formula.

</details>

---

### Esercizio 3.2 — Riferimenti assoluti
Hai una tabella di prezzi e vuoi applicare uno **sconto fisso** che sta nella cella E1 (es. 20%, scrivi `0.20` in E1).

|   | A | B | C | D | E |
|---|---|---|---|---|---|
| **1** | Prodotto | Prezzo | Prezzo scontato | | 0.20 |
| **2** | Tastiera | 45 | ? | | |
| **3** | Mouse | 25 | ? | | |
| **4** | Monitor | 180 | ? | | |

Scrivi la formula in C2 usando un riferimento **assoluto** a E1, poi trascinala fino a C4.

<details>
<summary>💡 Soluzione</summary>

In C2: `=B2*(1-$E$1)`

- `B2` è relativo → si aggiorna a B3, B4 trascinando
- `$E$1` è assoluto → punta sempre a E1 (lo sconto fisso)

Risultati:
- C2: `=B2*(1-$E$1)` → 45 × 0.80 = 36
- C3: `=B3*(1-$E$1)` → 25 × 0.80 = 20
- C4: `=B4*(1-$E$1)` → 180 × 0.80 = 144

</details>

---

### Esercizio 3.3 — Intervalli
Scrivi le formule che calcolano:
1. La somma delle celle da A1 a A20
2. Il massimo dei valori in tutto il range B1:D10
3. Il numero di celle non vuote nella colonna C

<details>
<summary>💡 Soluzione</summary>

1. `=SOMMA(A1:A20)`
2. `=MAX(B1:D10)`
3. `=CONTA.VALORI(C:C)`

</details>

---

## Tipologia 4 — Operazioni e funzioni di base

### Esercizio 4.1
Hai questi dati in colonna A (A1:A8): `12, 7, 8.5, 6, 9, 5.5, 8, 7.5`

Calcola (usando le funzioni appropriate):
1. La **somma** totale
2. La **media**
3. Il voto **massimo**
4. Il voto **minimo**
5. Il voto medio **arrotondato a 1 decimale**

<details>
<summary>💡 Soluzione</summary>

Con i dati in A1:A8:
1. `=SOMMA(A1:A8)` → 63.5
2. `=MEDIA(A1:A8)` → 7.9375
3. `=MAX(A1:A8)` → 12 *(attenzione: 12 è fuori scala 1-10 ma vale come esercizio!)*
4. `=MIN(A1:A8)` → 5.5
5. `=ARROTONDA(MEDIA(A1:A8); 1)` → 7.9

</details>

---

### Esercizio 4.2
Un negozio vende 3 prodotti. Calcola il totale con IVA al 22%.

| Prodotto | Prezzo netto |
|---------|-------------|
| Libro | 15.00 |
| Penna | 2.50 |
| Quaderno | 4.80 |

Scrivi **una sola formula** in C5 che somma i prezzi netti e applica l'IVA.

<details>
<summary>💡 Soluzione</summary>

`=SOMMA(B2:B4)*1.22`

Oppure in forma più esplicita:
`=(B2+B3+B4)*(1+0.22)`

Risultato: 22.30 × 1.22 = 27.21

</details>

---

## Tipologia 5 — Funzioni condizionali: SE e PIÙ.SE

### Esercizio 5.1
Aggiungi una colonna "Esito" alla tabella dell'Esercizio 1.1. Usa `SE` per scrivere:
- `"Promosso"` se il voto è ≥ 6
- `"Bocciato"` se il voto è < 6

<details>
<summary>💡 Soluzione</summary>

In E2 (o nella prima cella vuota a destra):
`=SE(C2>=6; "Promosso"; "Bocciato")`

Trascina fino all'ultima riga della tabella.

</details>

---

### Esercizio 5.2
Usa `PIÙ.SE` per creare una colonna "Valutazione" con queste fasce:

| Voto | Valutazione |
|------|------------|
| < 5 | Gravemente insufficiente |
| 5 – 5.9 | Insufficiente |
| 6 – 6.9 | Sufficiente |
| 7 – 7.9 | Discreto |
| 8 – 8.9 | Buono |
| 9 – 10 | Ottimo |

<details>
<summary>💡 Soluzione</summary>

```
=PIÙ.SE(
  C2>=9;    "Ottimo";
  C2>=8;    "Buono";
  C2>=7;    "Discreto";
  C2>=6;    "Sufficiente";
  C2>=5;    "Insufficiente";
  VERO;     "Gravemente insufficiente"
)
```

*(puoi scriverla su una riga sola: `=PIÙ.SE(C2>=9;"Ottimo";C2>=8;"Buono";C2>=7;"Discreto";C2>=6;"Sufficiente";C2>=5;"Insufficiente";VERO;"Gravemente insufficiente")`)*

</details>

---

### Esercizio 5.3 — CONTA.SE
Hai una lista di voti in A1:A20. Scrivi le formule per contare:
1. Quanti voti sono sufficienti (≥ 6)
2. Quanti voti sono ottimi (≥ 9)
3. Quanti voti sono esattamente 7

<details>
<summary>💡 Soluzione</summary>

1. `=CONTA.SE(A1:A20; ">=6")`
2. `=CONTA.SE(A1:A20; ">=9")`
3. `=CONTA.SE(A1:A20; 7)`

**Nota:** le condizioni con operatori (`>=6`) vanno tra virgolette; il valore esatto (`7`) non ha bisogno di virgolette.

</details>

---

## Tipologia 6 — CERCA.X

### Esercizio 6.1
Crea due tabelle in due fogli diversi:

**Foglio1 — Catalogo prodotti:**

| A | B |
|---|---|
| Codice | Prezzo |
| P001 | 12.50 |
| P002 | 8.00 |
| P003 | 25.00 |
| P004 | 5.50 |

**Foglio2 — Ordini:**

| A | B | C |
|---|---|---|
| N° Ordine | Codice | Prezzo |
| 001 | P003 | ? |
| 002 | P001 | ? |
| 003 | P005 | ? |
| 004 | P002 | ? |

Nella colonna C di Foglio2, usa `CERCA.X` per trovare automaticamente il prezzo di ogni prodotto. Per P005 (che non esiste), mostra `"Prodotto non trovato"`.

<details>
<summary>💡 Soluzione</summary>

In C2 di Foglio2:
```
=CERCA.X(B2; Foglio1.A:A; Foglio1.B:B; "Prodotto non trovato")
```

Risultati:
- C2 (P003): 25.00 ✓
- C3 (P001): 12.50 ✓
- C4 (P005): "Prodotto non trovato" ✓
- C5 (P002): 8.00 ✓

</details>

---

### Esercizio 6.2
Hai una lista di studenti con ID, nome e classe. In un secondo foglio hai solo l'ID e vuoi trovare nome e classe.

**Foglio "Studenti":**

| A (ID) | B (Nome) | C (Classe) |
|--------|---------|-----------|
| S01 | Alice | 1A |
| S02 | Brando | 2B |
| S03 | Chiara | 1A |
| S04 | Davide | 3C |

**Foglio "Ricerca"** — dati in A2:

| A (ID ricercato) | B (Nome trovato) | C (Classe trovata) |
|---|---|---|
| S03 | ? | ? |

Scrivi le due formule per B2 e C2 nel foglio Ricerca.

<details>
<summary>💡 Soluzione</summary>

In B2: `=CERCA.X(A2; Studenti.A:A; Studenti.B:B; "Non trovato")`  
In C2: `=CERCA.X(A2; Studenti.A:A; Studenti.C:C; "Non trovato")`

Risultati per S03:
- B2: "Chiara"
- C2: "1A"

</details>

---

## Tipologia 7 — Grafici

### Esercizio 7.1 — Grafico a colonne
Crea questa tabella con le temperature medie mensili di una città:

| Mese | Temperatura (°C) |
|------|-----------------|
| Gen | 4 |
| Feb | 6 |
| Mar | 10 |
| Apr | 15 |
| Mag | 20 |
| Giu | 25 |

1. Seleziona entrambe le colonne e crea un **grafico a colonne**.
2. Aggiungi il titolo "Temperature medie mensili".
3. Cambia il colore delle barre in arancione.

<details>
<summary>💡 Soluzione</summary>

1. Seleziona A1:B7 → *Inserisci* → *Grafico* → tipo: *Colonne* → OK
2. Doppio clic sul grafico → clic sul titolo → scrivi "Temperature medie mensili"
3. Doppio clic sul grafico → clic su una barra → clic destro → *Formato serie dati* → cambia il colore di riempimento

</details>

---

### Esercizio 7.2 — Scegliere il grafico giusto
Per ogni scenario, indica il tipo di grafico più adatto e motiva brevemente:

1. Vuoi mostrare come è cambiato il numero di utenti di un'app nei 12 mesi del 2024.
2. Vuoi confrontare le vendite di 5 negozi diversi nel mese di dicembre.
3. Vuoi mostrare che il 60% delle spese scolastiche va in materiale, il 25% in gite, il 15% in altro.
4. Vuoi capire se c'è una relazione tra le ore di studio e il voto all'esame.

<details>
<summary>💡 Soluzione</summary>

1. **Grafico a linee** — è l'ideale per mostrare andamenti e tendenze nel tempo.
2. **Grafico a colonne** (istogramma) — confronta valori di categorie distinte e separate.
3. **Grafico a torta** — mostra proporzioni di un tutto (solo 3 fette, quindi leggibile).
4. **Grafico a dispersione (XY)** — mette in relazione due variabili numeriche e mostra se esiste una correlazione.

</details>

---

## Mini-progetto — Registro della classe

Crea un foglio di calcolo completo per gestire i voti di una classe. Il foglio deve:

1. Contenere una tabella con almeno 10 studenti e 5 voti ciascuno (inventali tu!)
2. Calcolare automaticamente la **media** di ogni studente (riga)
3. Aggiungere una colonna "Esito" con `SE` o `PIÙ.SE`
4. Applicare la **formattazione condizionale** alle medie (verde ≥ 6, rosso < 6)
5. Creare un **grafico a colonne** con le medie degli studenti
6. In un secondo foglio "Anagrafica", mettere nome e indirizzo email degli studenti; nel foglio principale usa `CERCA.X` per mostrare l'email data l'ID dello studente

<details>
<summary>💡 Soluzione (traccia)</summary>

**Foglio "Voti":**
- Colonna A: ID studente (S01, S02…)
- Colonne B-F: 5 voti
- Colonna G: `=MEDIA(B2:F2)` (trascinata per tutti)
- Colonna H: `=PIÙ.SE(G2>=9;"Ottimo"; G2>=7;"Buono"; G2>=6;"Sufficiente"; VERO;"Insufficiente")`
- Formattazione condizionale su G2:G11

**Grafico:** seleziona A1:A11 + G1:G11 (con Ctrl) → Inserisci → Grafico a colonne

**Foglio "Anagrafica":**
- Colonna A: ID (S01…), Colonna B: Nome, Colonna C: Email

**In Foglio "Voti", colonna I (Email):**
`=CERCA.X(A2; Anagrafica.A:A; Anagrafica.C:C; "Email non trovata")`

</details>
