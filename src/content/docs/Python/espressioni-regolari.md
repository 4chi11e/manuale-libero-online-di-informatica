---
title: Espressioni regolari
description: Le espressioni regolari (regex) in Python, il modulo re, metacaratteri, quantificatori, classi di caratteri, ricerca, validazione e manipolazione avanzata del testo.
---

Finora abbiamo cercato e sostituito porzioni di testo usando i metodi nativi delle [stringhe](../stringhe/), come `.find()` o `.replace()`. Questi metodi sono ottimi quando conosciamo il testo esatto da cercare, ma mostrano tutti i loro limiti quando dobbiamo cercare un **motivo** (un *pattern*) variabile.

Ad esempio, come faremmo a verificare se una stringa è:
* un numero di telefono valido?
* una data nel formato `GG/MM/AAAA`?
* un indirizzo email corretto?
* una targa automobilistica italiana (due lettere, tre cifre, due lettere)?

Con le sole istruzioni viste finora servirebbero decine di righe di codice, con cicli, controlli su indici e molteplici condizioni `if`. Per risolvere questi problemi in modo compatto ed elegante esistono le **espressioni regolari** (in inglese *regular expressions*, spesso abbreviate in **regex** o **regexp**).

Una regex è una sequenza di caratteri che definisce un **modello di ricerca**: qualsiasi testo che rispetta quella "forma" viene riconosciuto e catturato.

:::tip Per chi conosce il C
In C la convalida di stringhe con formati complessi richiede decine di righe di codice procedurale a basso livello: cicli con puntatori, controlli continui con `isdigit()` e `isalpha()`, gestione di flag booleani e contatori di posizione. In Python, il modulo standard `re` implementa un potente motore di pattern matching che permette di esprimere gli stessi controlli con una singola riga di codice dichiarativo.
:::

---

## 1. Il modulo `re` e le raw string (`r"..."`)

Per utilizzare le espressioni regolari in Python si importa il modulo della libreria standard **`re`** (non serve installare nulla):

```python
import re
```

### Le stringhe "raw" (`r"..."`)
In Python la barra rovesciata `\` viene normalmente usata per inserire caratteri speciali di escape, come `\n` (a capo) o `\t` (tabulazione).

Se anteponiamo una lettera **`r`** (che sta per *raw*, cioè **"grezzo"**), diciamo a Python di **disattivare le sequenze di escape** e di considerare ogni carattere alla lettera:

```python
# 1. Stringa normale: interpreta \n come "vai a capo"
print("riga 1\nriga 2")
# Output:
# riga 1
# riga 2

# 2. Stringa raw: la barra e la lettera 'n' rimangono intatte
print(r"riga 1\nriga 2")
# Output:
# riga 1\nriga 2
```

#### Perché è fondamentale con le regex?
Nelle espressioni regolari useremo continuamente simboli che iniziano con la barra rovesciata: ad esempio `\d` indica una cifra, `\s` uno spazio, `\b` un confine di parola.

* Senza la `r`, Python cercherebbe di interpretare quelle barre rovesciate prima ancora di passarle al motore delle regex (ad esempio `\b` in Python è il carattere ASCII *Backspace*, non il confine di parola!).
* Per evitare conflitti ed errori, la regola pratica universale è: **tutti i pattern regex vanno sempre scritti come raw string**, con la `r` davanti alle virgolette:

```python
pattern = r"\d+"   # cerca una o più cifre: pulito, leggibile e sicuro
```

---

## 2. Le funzioni principali del modulo `re`

Prima di studiare la sintassi dei pattern, vediamo le quattro funzioni che useremo più spesso.

### 2.1 Trovare tutte le corrispondenze: `re.findall()`
È la funzione più semplice e immediata: cerca **tutte** le occorrenze del pattern all'interno del testo e le restituisce in una **lista di stringhe**:

```python
import re

testo = "Oggi ho comprato 3 mele, 12 arance e 150 noci"
numeri = re.findall(r"\d+", testo)

print(numeri)
# ['3', '12', '150']
```

Se il pattern non viene mai trovato, `findall()` restituisce una lista vuota `[]`.

### 2.2 Cercare la prima occorrenza: `re.search()`
Scansiona il testo dall'inizio alla fine alla ricerca della **prima** corrispondenza:
* se la trova, restituisce un oggetto **`Match`**;
* se non la trova, restituisce **`None`**.

```python
testo = "Temperatura minima: 18 gradi"
risultato = re.search(r"\d+", testo)

if risultato:
    print("Trovato:", risultato.group())      # '18' (il testo catturato)
    print("Inizio:", risultato.start())        # 20 (indice iniziale nel testo)
    print("Fine:  ", risultato.end())          # 22 (indice finale)
else:
    print("Nessun numero trovato")
```

### 2.3 Validare un testo intero: `re.fullmatch()`
Verifica se l'**intera stringa** corrisponde esattamente al pattern dal primo all'ultimo carattere (utilissimo per verificare se l'input dell'utente è corretto):

```python
codice = "AB123"

# Verifica se il codice è composto esattamente da 2 lettere maiuscole e 3 cifre
if re.fullmatch(r"[A-Z]{2}\d{3}", codice):
    print("Codice valido!")
else:
    print("Formato non valido")
```

### 2.4 Sostituzione avanzata: `re.sub()`
È l'equivalente avanzato di `.replace()`. Sostituisce tutte le corrispondenze del pattern con una stringa a nostra scelta:

```python
testo = "Il prezzo è 10 euro, con sconto 5 euro"
# Sostituiamo ogni numero con il simbolo '#'
censurato = re.sub(r"\d+", "#", testo)

print(censurato)
# 'Il prezzo è # euro, con sconto # euro'
```

### 2.5 Divisione su delimitatori multipli: `re.split()`
Mentre `.split()` delle stringhe divide solo su un separatore fisso, `re.split()` permette di dividere un testo usando un pattern come separatore:

```python
testo = "mela,pera;arancia banana  limone"
# Divide su qualsiasi sequenza di virgole, punti e virgole o spazi
frutti = re.split(r"[,;\s]+", testo)

print(frutti)
# ['mela', 'pera', 'arancia', 'banana', 'limone']
```

---

## 3. La sintassi delle regex: Metacaratteri e Classi

Una regex è composta da caratteri normali (che cercano se stessi) e da **metacaratteri**, cioè caratteri speciali con un significato ben preciso.

### 3.1 I metacaratteri di base

| Metacarattere | Significato | Esempio | Corrisponde a |
|:---:|---|---|---|
| `.` | **Qualsiasi carattere** singolo (tranne a capo) | `r"c.ne"` | `"cane"`, `"cene"`, `"c1ne"`, `"c-ne"` |
| `^` | **Inizio della stringa** (ancoraggio) | `r"^Ciao"` | Corrisponde solo se la stringa inizia con `"Ciao"` |
| `$` | **Fine della stringa** (ancoraggio) | `r"fine$"` | Corrisponde solo se la stringa finisce con `"fine"` |
| `\|` | **OR logico** (alternativa) | `r"gatto\|cane"` | Cerca `"gatto"` oppure `"cane"` |
| `\` | **Escape**: toglie il significato speciale | `r"\."` | Cerca un vero punto fermo `.` nel testo |

```python
# Cercare parole che finiscono con 'are'
print(re.findall(r"\w+are$", "andare a ballare"))  # ['ballare']
```

---

### 3.2 Insiemi di caratteri: le parentesi quadre `[...]`

Le parentesi quadre definiscono un **insieme di caratteri ammessi**: la regex cercherà **un solo carattere** tra quelli indicati.

* `[aeiou]`: una vocale minuscola qualsiasi.
* `[a-z]`: qualsiasi lettera minuscola dalla `a` alla `z` (intervallo).
* `[A-Z]`: qualsiasi lettera maiuscola.
* `[0-9]`: qualsiasi cifra numerica da 0 a 9.
* `[a-zA-Z0-9]`: qualsiasi carattere alfanumerico.
* `[^0-9]`: il simbolo `^` all'inizio delle quadre indica la **negazione** (qualsiasi carattere che *non* sia una cifra).

```python
testo = "Ho visto 1 gatto, 2 cani e 9 uccellini"
vocali = re.findall(r"[aeiou]", testo)
print("Numero di vocali:", len(vocali))
```

---

### 3.3 Classi predefinite (scorciatoie)

Per evitare di scrivere continuamente `[0-9]` o `[a-zA-Z0-9_]`, le regex mettono a disposizione comode scorciatoie:

| Simbolo | Significato | Equivalente a |
|:---:|---|---|
| `\d` | Cifra decimale (*digit*) | `[0-9]` |
| `\D` | **Non** cifra | `[^0-9]` |
| `\w` | Carattere di parola (*word*) | `[a-zA-Z0-9_]` (lettere, cifre, underscore) |
| `\W` | **Non** carattere di parola | `[^a-zA-Z0-9_]` (spazi, punteggiatura, simboli) |
| `\s` | Spazio bianco (*space*) | Spazio `' '`, tabulazione `\t`, a capo `\n` |
| `\S` | **Non** spazio bianco | Qualsiasi carattere visibile |

```python
frase = "Codice: TX-492"

cifre = re.findall(r"\d", frase)
print(cifre)  # ['4', '9', '2']
```

---

## 4. I Quantificatori: quante ripetizioni?

I quantificatori stabiliscono quante volte il carattere o la classe precedente deve ripetersi:

| Quantificatore | Significato | Esempio | Descrizione |
|:---:|---|---|---|
| `*` | **0 o più** volte | `r"ab*"` | `"a"`, `"ab"`, `"abb"`, `"abbb"`... |
| `+` | **1 o più** volte (almeno una) | `r"ab+"` | `"ab"`, `"abb"`, ma **non** `"a"` |
| `?` | **0 o 1** volta (opzionale) | `r"colou?r"` | `"color"` oppure `"colour"` |
| `{n}` | Esattamente **$n$** volte | `r"\d{3}"` | Esattamente tre cifre consecutive |
| `{n,m}` | Da **$n$** a **$m$** volte | `r"\d{2,4}"` | Da due a quattro cifre |
| `{n,}` | Almeno **$n$** volte | `r"\d{2,}"` | Due o più cifre |

### Esempi pratici di quantificatori

**1. Estrarre numeri interi (una o più cifre consecutive):**
```python
testo = "Partita finita 102 a 98 punti"
print(re.findall(r"\d+", testo))   # ['102', '98']
```
*(Nota la differenza: `r"\d"` avrebbe estratto le singole cifre `['1', '0', '2', '9', '8']`, mentre `r"\d+"` aggrega le cifre adiacenti nello stesso numero).*

**2. Formato di una data `GG/MM/AAAA`:**
```python
pattern_data = r"\d{2}/\d{2}/\d{4}"

testo = "La riunione è il 15/04/2026 oppure il 20/05/2026."
print(re.findall(pattern_data, testo))
# ['15/04/2026', '20/05/2026']
```

**3. Prefisso o parola opzionale (`?`):**
```python
# Cerca sia 'http://' sia 'https://'
pattern = r"https?://"
```

---

## 5. Gruppi di cattura: le parentesi tonde `(...)`

Le parentesi tonde `(...)` hanno un duplice scopo:
1. **Raggruppare** una sottoespressione a cui applicare un quantificatore: ad esempio `r"(ciao )+"` cerca la parola *"ciao "* ripetuta una o più volte.
2. **Catturare** porzioni specifiche del match per estrarle singolarmente.

Quando usiamo `re.search()`, possiamo estrarre i singoli gruppi con il metodo `.group(indice)` (dove `0` indica l'intero match, `1` il primo gruppo, `2` il secondo, ecc.):

```python
testo = "Appuntamento: 24/11/2026"
risultato = re.search(r"(\d{2})/(\d{2})/(\d{4})", testo)

if risultato:
    print("Data completa:", risultato.group(0))  # '24/11/2026'
    print("Giorno:       ", risultato.group(1))  # '24'
    print("Mese:         ", risultato.group(2))  # '11'
    print("Anno:         ", risultato.group(3))  # '2026'
```

:::warning Come si comporta `findall()` con i gruppi
Se un pattern contiene delle parentesi tonde, `re.findall()` restituisce una **lista di tuple**, ciascuna contenente solo i gruppi catturati:

```python
testo = "Anna: 25 anni, Luca: 18 anni"
print(re.findall(r"(\w+):\s*(\d+)", testo))
# [('Anna', '25'), ('Luca', '18')]
```
:::

---

## 6. Esempi notevoli dall'eserciziario

### Esempio 1: Ricerca di occorrenze ("quante volte compare 'tre'")
Dato un elenco di numeri scritti a parole, contare quante volte compare la sillaba `"tre"`.

Confrontiamo i tre approcci:
```python
import re

lista = ["trentatre", "milletrecento", "millequattrocentonovantadue", "trecentotredici"]

# Approccio 1: Cicli manuali con indici carattere per carattere (stile C)
print("=== Approccio stile C ===")
for parola in lista:
    conteggio = 0
    for i in range(len(parola) - 2):
        if parola[i:i+3] == "tre":
            conteggio += 1
    print(f"{parola:30} -> {conteggio}")

# Approccio 2: Con le espressioni regolari (una riga!)
print("\n=== Con le Regex ===")
for parola in lista:
    occorrenze = len(re.findall(r"tre", parola))
    print(f"{parola:30} -> {occorrenze}")
```

La regex `r"tre"` con `findall()` riduce l'algoritmo di conteggio a una chiamata immediata.

---

### Esempio 2: Il Rimario con regex
Data una parola inserita dall'utente, trovare nell'elenco tutte le parole che fanno rima, intese come parole che terminano con le stesse ultime 3 lettere.

L'ancoraggio di fine stringa `$` rende l'operazione elementare:

```python
import re

elenco_parole = [
    "canzone", "stazione", "portone", "bastone", "mattone",
    "colline", "pallone", "bambino", "finzione"
]

parola_utente = "attenzione"

# Prendiamo le ultime 3 lettere della parola ('one')
desinenza = parola_utente[-3:]

# Creiamo il pattern dinamico: qualsiasi parola che finisce con quella desinenza ($)
pattern = rf"\w*{desinenza}$"

print(f"Rime per '{parola_utente}' (terminano in '{desinenza}'):")
for p in elenco_parole:
    if re.search(pattern, p):
        print("-", p)
```

Output:
```text
Rime per 'attenzione' (terminano in 'one'):
- canzone
- stazione
- portone
- bastone
- mattone
- pallone
- finzione
```

---

### Esempio 3: Convalida di una targa italiana
Una targa italiana segue il formato: **due lettere maiuscole**, **tre cifre**, **due lettere maiuscole** (es. `AB123CD`).

```python
import re

def valida_targa(targa):
    targa = targa.strip().upper()
    # [A-Z]{2} -> esattamente due lettere maiuscole
    # \d{3}    -> esattamente tre cifre
    # [A-Z]{2} -> esattamente due lettere maiuscole
    return bool(re.fullmatch(r"[A-Z]{2}\d{3}[A-Z]{2}", targa))

test = ["AB123CD", "ab123cd", "A123BCD", "AB12CD", "MI999XY"]
for t in test:
    print(f"'{t}': {'VALIDA' if valida_targa(t) else 'NON VALIDA'}")
```

Output:
```text
'AB123CD': VALIDA
'ab123cd': VALIDA
'A123BCD': NON VALIDA
'AB12CD': NON VALIDA
'MI999XY': VALIDA
```

---

### Esempio 4: Convalida di un indirizzo MAC
Un indirizzo MAC è formato da 6 coppie di cifre esadecimali (`0-9`, `a-f`, `A-F`) separate da due punti `:`:

$$\text{02:FF:A5:F2:55:12}$$

```python
import re

def valida_mac(indirizzo):
    pattern = r"^[0-9a-fA-F]{2}(:[0-9a-fA-F]{2}){5}$"
    return bool(re.fullmatch(pattern, indirizzo.strip()))

print(valida_mac("02:FF:A5:F2:55:12"))  # True
print(valida_mac("02:FG:A5:F2:55:12"))  # False ('G' non è esadecimale)
print(valida_mac("02:FF:A5:F2:55"))     # False (manca una coppia)
```

---

## Tabella di riepilogo rapido

| Simbolo | Significato | Esempio |
|:---:|---|---|
| `.` | Qualsiasi carattere | `r"c.ne"` |
| `^` / `$` | Inizio / Fine del testo | `r"^Inizio"`, `r"Fine$"` |
| `\d` / `\D` | Cifra / Non cifra | `r"\d+"` |
| `\w` / `\W` | Alfanumerico / Non alfanumerico | `r"\w+"` |
| `\s` / `\S` | Spazio / Non spazio | `r"\s+"` |
| `[abc]` | Un carattere tra `a`, `b`, `c` | `r"[aeiou]"` |
| `[^abc]` | Qualsiasi carattere tranne `a`, `b`, `c` | `r"[^0-9]"` |
| `*` / `+` / `?` | 0+ volte / 1+ volte / 0 o 1 volta | `r"\d*"` , `r"\d+"`, `r"https?"` |
| `{n}` / `{n,m}` | Esattamente $n$ volte / Da $n$ a $m$ volte | `r"\d{4}"`, `r"\d{2,4}"` |
| `(...)` | Gruppo di cattura | `r"(\d{2})/(\d{2})"` |
| `\|` | Oppure (OR) | `r"gatto\|cane"` |

---

## Esercizi

Gli esercizi relativi a questo argomento si trovano nel capitolo **"Espressioni regolari"** dell'eserciziario, linkato nella [pagina introduttiva](../programmazione-in-python/).
