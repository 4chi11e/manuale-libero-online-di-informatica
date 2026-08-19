---
title: Rappresentazione dell'Informazione
description: Come si codificano testi, simboli e dati in binario. Dal codice ASCII a Unicode, fino a inventare codifiche personali come quella di un mazzo di carte.
---

Nelle pagine sulle conversioni numeriche abbiamo imparato a rappresentare **i numeri** in binario. Ma un computer non deve memorizzare solo numeri: deve gestire testi, immagini, suoni, video, e molto altro ancora.

Come fa a farlo? La risposta è sorprendentemente semplice: **tutto viene trasformato in numeri**, e quei numeri vengono poi scritti in binario.

```text
   Testo, immagini, suoni, video...
              │
              ▼
   ┌──────────────────────┐
   │   CODIFICA (regola)  │  ←── "La lettera A vale il numero 65"
   └──────────────────────┘
              │
              ▼
       Numeri interi
              │
              ▼
   ┌──────────────────────┐
   │  Conversione binaria │
   └──────────────────────┘
              │
              ▼
     01000001 01000010 ...   ←── quello che c'è davvero nella memoria
```

La **codifica** è semplicemente un accordo: una tabella che associa ogni simbolo (lettera, numero, colore, suono…) a un numero intero. Dato quel numero, il computer lo converte in binario e lo memorizza. Quando serve rileggerlo, fa il percorso inverso.

In questo capitolo vediamo come funzionano alcune codifiche reali e come si potrebbe **inventarne una da zero**.

---

## 1. Il Codice ASCII: il primo alfabeto del computer

### Cos'è ASCII?

Nei primi anni della storia dei computer (anni '60), americani e europei si sono messi d'accordo su una tabella standard: il **codice ASCII** (*American Standard Code for Information Interchange*).

L'idea è semplicissima: assegnare a ogni carattere utile (lettere, cifre, punteggiatura, spazio…) un numero intero da 0 a 127. Bastano **7 bit** per rappresentare tutti e 128 i codici ($2^7 = 128$). Nella pratica si usa sempre **1 byte (8 bit)**, usando il bit più significativo come $0$.

Ecco una parte della tabella ASCII con i caratteri più usati:

| Decimale | Binario | Carattere | Decimale | Binario | Carattere |
| :---: | :---: | :---: | :---: | :---: | :---: |
| 32 | 00100000 | *(spazio)* | 64 | 01000000 | @ |
| 48 | 00110000 | 0 | 65 | 01000001 | A |
| 49 | 00110001 | 1 | 66 | 01000010 | B |
| 50 | 00110010 | 2 | 67 | 01000011 | C |
| 51 | 00110011 | 3 | 68 | 01000100 | D |
| 52 | 00110100 | 4 | 69 | 01000101 | E |
| 53 | 00110101 | 5 | 70 | 01000110 | F |
| 54 | 00110110 | 6 | 71 | 01000111 | G |
| 55 | 00110111 | 7 | 72 | 01001000 | H |
| 56 | 00111000 | 8 | 73 | 01001001 | I |
| 57 | 00111001 | 9 | 74 | 01001010 | J |
| 97 | 01100001 | a | 75 | 01001011 | K |
| 98 | 01100010 | b | 76 | 01001100 | L |
| 99 | 01100011 | c | 77 | 01001101 | M |
| 100 | 01100100 | d | 78 | 01001110 | N |
| 101 | 01100101 | e | 79 | 01001111 | O |
| 102 | 01100110 | f | 80 | 01010000 | P |
| 103 | 01100111 | g | 81 | 01010001 | Q |
| 104 | 01101000 | h | 82 | 01010010 | R |
| 105 | 01101001 | i | 83 | 01010011 | S |
| 106 | 01101010 | j | 84 | 01010100 | T |
| 107 | 01101011 | k | 85 | 01010101 | U |
| 108 | 01101100 | l | 86 | 01010110 | V |
| 109 | 01101101 | m | 87 | 01010111 | W |
| 110 | 01101110 | n | 88 | 01011000 | X |
| 111 | 01101111 | o | 89 | 01011001 | Y |
| 112 | 01110000 | p | 90 | 01011010 | Z |
| 113 | 01110001 | q | 33 | 00100001 | ! |
| 114 | 01110010 | r | 44 | 00101100 | , |
| 115 | 01110011 | s | 46 | 00101110 | . |
| 116 | 01110100 | t | 63 | 00111111 | ? |

:::note[Osservazione: maiuscole e minuscole]
Nota che le lettere maiuscole (A–Z, codici 65–90) e le minuscole (a–z, codici 97–122) si differenziano esattamente di **32** in decimale, ovvero di **1 bit** in posizione 5 (contando da 0 da destra). Questo non è casuale: è stato progettato appositamente per rendere più semplice la conversione tra maiuscolo e minuscolo nell'hardware.

$$\underbrace{01000001}_{\text{A} = 65} \quad \overset{+32}{\longrightarrow} \quad \underbrace{01100001}_{\text{a} = 97}$$
:::

### Come si codifica una parola?

Ogni lettera diventa il suo codice ASCII, che viene poi scritto come 1 byte in binario. Una stringa di testo è quindi una **sequenza di byte**, uno per ogni carattere.

:::note[Esempio: Codificare "CIAO" in ASCII]
Cerchiamo il codice ASCII di ogni lettera:

| Carattere | Codice decimale | Codice binario (1 byte) |
| :---: | :---: | :---: |
| C | 67 | 01000011 |
| I | 73 | 01001001 |
| A | 65 | 01000001 |
| O | 79 | 01001111 |

La parola "CIAO" in memoria occupa **4 byte** = **32 bit**:

```text
01000011  01001001  01000001  01001111
    C         I         A         O
```
:::

:::note[Esempio: Decodificare una sequenza di byte]
Ricevi questa sequenza binaria e vuoi sapere che testo rappresenta:

```text
01001000  01001001
```

Converti ogni byte in decimale:
- $01001000 = 64 + 8 = 72$ → **H**
- $01001001 = 64 + 8 + 1 = 73$ → **I**

Il testo è **"HI"** (ciao in inglese)!
:::

### Quanta memoria occupa un testo?

Con ASCII ogni carattere occupa esattamente **1 byte**. Quindi:

$$\text{dimensione testo} = \text{numero di caratteri} \times 1 \text{ byte}$$

Un romanzo di 500 pagine con circa 2000 caratteri per pagina occupa:

$$500 \times 2000 \times 1 \text{ byte} = 1.000.000 \text{ byte} \approx 1 \text{ MB}$$

---

## 2. I limiti di 8 bit: Unicode e il mondo oltre l'inglese

Con 8 bit (1 byte) si hanno al massimo $2^8 = 256$ codici diversi. L'ASCII standard ne usa solo 128 (codici 0–127). I codici da 128 a 255 sono stati usati in modi diversi da paesi diversi — e qui sono iniziati i problemi.

Lettere italiane come **à, è, ì, ò, ù** non ci sono nella tabella ASCII standard! Stessa cosa per lettere tedesche (ä, ö, ü), francesi (ç, ê), greche (α, β, γ), cinesi, arabe, giapponesi… e le emoji! 😄

### La soluzione: Unicode

**Unicode** è uno standard internazionale nato negli anni '90 che assegna un numero univoco a **ogni simbolo usato da ogni lingua del mondo**, passato e presente. Ad oggi contiene oltre **140.000 caratteri**.

| Carattere | Nome Unicode | Codice |
| :---: | :--- | :---: |
| A | LATIN CAPITAL LETTER A | U+0041 |
| é | LATIN SMALL LETTER E WITH ACUTE | U+00E9 |
| α | GREEK SMALL LETTER ALPHA | U+03B1 |
| 中 | CJK UNIFIED IDEOGRAPH-4E2D | U+4E2D |
| 😄 | SMILING FACE WITH OPEN MOUTH AND SMILING EYES | U+1F604 |

Ovviamente con soli 8 bit non è possibile rappresentare 140.000 caratteri diversi ($2^8 = 256 \ll 140.000$). Servono più bit.

### UTF-8: la codifica di Unicode più usata su Internet

**UTF-8** è la codifica più diffusa di Unicode. Usa un numero **variabile** di byte per carattere:
- I caratteri ASCII originali (0–127) vengono codificati con **1 solo byte** (compatibilità totale)
- I caratteri europei comuni usano **2 byte**
- I caratteri asiatici e di altre scritture usano **3 byte**
- Emoji e caratteri rari usano **4 byte**

:::tip[Takeaway]
Per questa pagina, l'importante è capire **perché** Unicode esiste: 8 bit non bastano per rappresentare tutta la ricchezza dei linguaggi umani. Il dettaglio di come funziona UTF-8 internamente è un approfondimento per chi è curioso.
:::

---

## 3. Inventare una propria codifica: il mazzo di carte

Il concetto di codifica non è magico: chiunque può inventarne una. L'importante è che sia **non ambigua** (ogni sequenza di bit corrisponda a un solo simbolo) e **completa** (ogni simbolo abbia un codice).

Proviamo a inventare una codifica per un mazzo di carte da gioco standard (52 carte).

### Approccio 1: numerazione semplice

Il metodo più diretto: numeriamo le carte da **0 a 51** e rappresentiamo ogni numero in binario.

**Quanti bit ci servono?** Dobbiamo rappresentare 52 valori distinti (da 0 a 51). Cerchiamo la potenza di 2 più piccola che sia maggiore o uguale a 52:

$$2^5 = 32 < 52 \leq 64 = 2^6$$

Servono quindi **6 bit**, che ci permettono di rappresentare fino a $2^6 = 64$ valori (sprechiamo i codici 52–63, ma non è un problema).

Decidiamo l'ordine delle carte (un esempio):

| Numero | Carta | Binario (6 bit) |
| :---: | :---: | :---: |
| 0 | Asso di ♠ | 000000 |
| 1 | 2 di ♠ | 000001 |
| 2 | 3 di ♠ | 000010 |
| … | … | … |
| 12 | Re di ♠ | 001100 |
| 13 | Asso di ♥ | 001101 |
| … | … | … |
| 51 | Re di ♣ | 110011 |

Questo funziona, ma ha uno svantaggio: per sapere che carta è, devo consultare la tabella. Non posso capirlo "a occhio" dal codice binario.

### Approccio 2: codifica strutturata (seme + valore)

Un mazzo di carte ha una struttura naturale: **4 semi** × **13 valori**. Possiamo sfruttarla!

**Codificare il seme (4 semi → 2 bit):**

| Seme | Codice |
| :---: | :---: |
| ♠ (Picche) | 00 |
| ♥ (Cuori) | 01 |
| ♦ (Quadri) | 10 |
| ♣ (Fiori) | 11 |

Due bit bastano: $2^2 = 4 \geq 4$ ✓

**Codificare il valore (13 valori → 4 bit):**

| Valore | Codice | Valore | Codice |
| :---: | :---: | :---: | :---: |
| Asso | 0001 | 8 | 1000 |
| 2 | 0010 | 9 | 1001 |
| 3 | 0011 | 10 | 1010 |
| 4 | 0100 | Fante | 1011 |
| 5 | 0101 | Donna | 1100 |
| 6 | 0110 | Re | 1101 |
| 7 | 0111 | — | — |

Quattro bit ci danno $2^4 = 16$ valori possibili. Ne usiamo 13, sprechiamo i codici 0000 e 1110–1111.

**Codice finale di una carta = 2 bit seme + 4 bit valore = 6 bit totali**

:::note[Esempio: Codificare e decodificare con la codifica strutturata]
**Codificare il "7 di ♥":**
- Seme: ♥ → `01`
- Valore: 7 → `0111`
- Codice: `01` `0111` = **`010111`**

**Decodificare `110100`:**
- Primi 2 bit: `11` → ♣ (Fiori)
- Ultimi 4 bit: `0100` → 4
- Carta: **4 di ♣** ✓
:::

:::tip[Vantaggio della codifica strutturata]
Con questa codifica, leggendo solo i primi 2 bit so subito il seme, leggendo gli ultimi 4 bit so il valore. Non ho bisogno di una tabella completa da 52 righe!

Questo è esattamente il principio usato nei formati reali: i bit vengono suddivisi in **campi** con un significato specifico. Per esempio, negli indirizzi IP (che studierai più avanti nel capitolo sulle Reti) 32 bit vengono divisi in 4 gruppi da 8 bit, ognuno con il suo significato.
:::

---

## 4. Quanti bit servono? La formula generale

Abbiamo visto il ragionamento più volte: per rappresentare $N$ oggetti distinti (carte, lettere, colori, pianeti…) serve trovare il numero minimo di bit $k$ tale che $2^k \geq N$.

In matematica si scrive:

$$k = \lceil \log_2 N \rceil$$

dove $\lceil \cdot \rceil$ indica il **tetto** (arrotondamento all'intero superiore).

:::note[Cosa significa in pratica]
$\log_2 N$ è l'esponente a cui bisogna elevare 2 per ottenere $N$.  
Per esempio: $\log_2 8 = 3$ perché $2^3 = 8$, oppure $\log_2 52 \approx 5.7$ perché $2^{5.7} \approx 52$.

Siccome il numero di bit deve essere un numero intero, **arrotondiamo sempre per eccesso**: $\lceil 5.7 \rceil = 6$. 

Se arrotondassimo per difetto, 5 bit non sarebbero sufficienti per rappresentare 52 valori diversi, ne potremmo rappresentare solo 32; usandone 6 sì, sprecheremo solo qualche combinazione.
:::

In pratica, basta usare questa tabella mentale:

| Numero di bit | Valori rappresentabili | Esempi di utilizzo |
| :---: | :---: | :--- |
| 1 bit | $2^1 = 2$ | Vero/Falso, Acceso/Spento |
| 2 bit | $2^2 = 4$ | Semi di un mazzo di carte |
| 3 bit | $2^3 = 8$ | Giorni della settimana (ne usiamo 7) |
| 4 bit | $2^4 = 16$ | Valori di una carta (ne usiamo 13) |
| 5 bit | $2^5 = 32$ | Giorni di un mese (ne usiamo 28–31) |
| 6 bit | $2^6 = 64$ | Carte di un mazzo (ne usiamo 52) |
| 7 bit | $2^7 = 128$ | Caratteri ASCII standard |
| 8 bit | $2^8 = 256$ | Un byte — colori in scala di grigi |
| 10 bit | $2^{10} = 1024$ | La "kilo" informatica (1 KiB = 1024 B) |
| 16 bit | $2^{16} = 65.536$ | Caratteri Unicode di base |
| 24 bit | $2^{24} = 16.777.216$ | Colori RGB (True Color) |

:::tip[Il ragionamento funziona anche al contrario]
Con $k$ bit posso rappresentare $2^k$ oggetti distinti.

Con $k$ bit posso rappresentare fino a $2^k$ oggetti, con $k-1$ bit posso farne solo $2^{k-1}$, cioè la metà. **Ogni bit aggiunto raddoppia le possibilità.**
:::

### Esempi applicativi

:::note[Quanti bit per i mesi dell'anno?]
I mesi sono **12**. Cerco la minima potenza di 2 ≥ 12:

$$2^3 = 8 < 12 \leq 16 = 2^4$$

Servono **4 bit** (con cui posso rappresentare fino a 16 valori, sprecandone 4).
:::

:::note[Quanti bit per i giorni della settimana?]
I giorni sono **7**. Cerco la minima potenza di 2 ≥ 7:

$$2^2 = 4 < 7 \leq 8 = 2^3$$

Servono **3 bit** (con cui posso rappresentare fino a 8 valori, sprecandone 1).
:::

:::note[Quante cose posso rappresentare con 10 bit?]
Con 10 bit ho a disposizione $2^{10} = \mathbf{1024}$ codici diversi. Questa è la famosa **"kilo" informatica**: $1 \text{ KiB} = 1024 \text{ byte}$ proprio perché $2^{10} = 1024 \approx 1000$.
:::

---

## 5. Mettiti alla Prova: Esercizi ed Esercitazioni Pratiche

Per consolidare tutti i concetti appresi:

👉 **[Vai alla raccolta completa degli Esercizi sulla Rappresentazione dell'Informazione](/manuale-libero-online-di-informatica/rappresentazione-informazione/esercizi/)**

Troverai esercizi su:
- Codifica e decodifica ASCII (testo ↔ binario)
- Calcolo del numero di bit necessari
- Codifica e decodifica di sistemi inventati (carte da gioco e altro)
