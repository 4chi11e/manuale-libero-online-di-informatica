---
title: Elementi di base
description: Il primo programma, variabili, tipi di dato, operatori, input e output in Python
---

In questa pagina vediamo i "mattoni" fondamentali di qualsiasi programma Python: come si scrive e si esegue un programma, come si memorizzano i dati nelle **variabili**, quali **tipi di dato** esistono, come si fanno i calcoli e come si comunica con l'utente tramite **input** e **output**.

:::note[Prima di iniziare]
Per scrivere ed eseguire programmi Python serve l'interprete Python installato sul computer e un editor (consigliato Visual Studio Code). Le istruzioni dettagliate per l'installazione si trovano nel capitolo *Ambiente di sviluppo* dell'eserciziario, linkato nella [pagina introduttiva](../programmazione-in-python/).
:::

## 1. Il primo programma

Un programma Python è un semplice file di testo con estensione `.py` che contiene una sequenza di **istruzioni**. L'interprete le legge ed esegue **una alla volta, dall'alto verso il basso**.

```python
print("Ciao mondo!")
```

```text
Ciao mondo!
```

La funzione `print` scrive sullo schermo (più precisamente nel *terminale*) quello che le passiamo tra le parentesi. Il testo va racchiuso tra virgolette, doppie `"..."` o singole `'...'` indifferentemente.

### Python è un linguaggio interpretato
A differenza del C, dove il codice sorgente viene prima **compilato** in un file eseguibile e solo dopo eseguito, in Python il codice viene letto ed eseguito direttamente dall'**interprete**, riga per riga. Questo ha due conseguenze pratiche:

*   non c'è una fase di compilazione separata: si scrive e si esegue subito;
*   molti errori vengono scoperti solo quando l'interprete arriva alla riga sbagliata. Le righe precedenti, nel frattempo, sono già state eseguite.

### I commenti
Tutto ciò che segue il simbolo `#` su una riga è un **commento**: l'interprete lo ignora. I commenti servono a chi legge il codice (compreso voi stessi tra qualche settimana!) per capire cosa fa il programma.

```python
# Questo programma saluta l'utente
print("Ciao!")  # anche qui posso scrivere un commento
```

## 2. Le variabili

Una **variabile** è un nome a cui associamo un valore, in modo da poterlo memorizzare e riutilizzare. Si crea con l'**operatore di assegnamento** `=`:

```python
eta = 16
nome = "Giulia"
altezza = 1.68

print(nome)
print(eta)
```

:::caution[L'uguale non è quello della matematica]
In programmazione `=` **non** significa "è uguale a", ma "**prendi il valore a destra e mettilo nella variabile a sinistra**". Per questo è perfettamente legale (e comunissimo) scrivere:

```python
x = 5
x = x + 1   # calcola x + 1 (cioè 6) e mettilo in x
print(x)    # 6
```

In matematica `x = x + 1` sarebbe un'equazione impossibile, in Python è un'istruzione che incrementa `x`.
:::

### Regole per i nomi delle variabili
*   Possono contenere lettere, cifre e il carattere `_` (underscore), ma **non possono iniziare con una cifra**.
*   Non possono contenere spazi: si usa `_` per separare le parole, ad esempio `media_voti` (questo stile si chiama *snake_case* ed è quello consigliato in Python).
*   Python distingue maiuscole e minuscole: `voto`, `Voto` e `VOTO` sono tre variabili diverse.
*   Non si possono usare le **parole riservate** del linguaggio (`if`, `for`, `while`, `def`, `return`, `True`, ...).

Scegliete sempre nomi **significativi**: `base` e `altezza` sono molto più chiari di `a` e `b`.

### Tipizzazione dinamica
In C bisogna dichiarare il tipo di ogni variabile (`int x;`), in Python no: il tipo viene deciso automaticamente in base al valore assegnato, e una variabile può persino cambiare tipo durante il programma. Per sapere il tipo di un valore si usa la funzione `type`:

```python
x = 10
print(type(x))   # <class 'int'>
x = "dieci"
print(type(x))   # <class 'str'>
```

## 3. I tipi di dato fondamentali

| Tipo | Nome | Esempi | Descrizione |
|---|---|---|---|
| `int` | intero | `5`, `-12`, `0`, `1000000` | Numeri interi, senza limite di grandezza |
| `float` | virgola mobile | `3.14`, `-0.5`, `2.0` | Numeri con la virgola (si usa il **punto**!) |
| `str` | stringa | `"ciao"`, `'A'`, `""` | Sequenze di caratteri (testo) |
| `bool` | booleano | `True`, `False` | Valori logici vero/falso |

*   Gli `int` in Python **non hanno un limite massimo**: si possono calcolare tranquillamente numeri enormi come `2**1000`, cosa impossibile con gli `int` del C.
*   I `float` invece hanno una precisione limitata, perché sono memorizzati in binario con un numero finito di bit (vedi la pagina sulla [Rappresentazione dell'Informazione](../../rappresentazione-informazione/rappresentazione-informazione/)). Ad esempio `0.1 + 0.2` dà `0.30000000000000004`.
*   I `bool` sono il risultato dei confronti (`5 > 3` vale `True`) e li useremo moltissimo nelle [strutture di controllo](../strutture-di-controllo/).

## 4. Gli operatori aritmetici

| Operatore | Operazione | Esempio | Risultato |
|---|---|---|---|
| `+` | somma | `7 + 2` | `9` |
| `-` | sottrazione | `7 - 2` | `5` |
| `*` | moltiplicazione | `7 * 2` | `14` |
| `/` | divisione | `7 / 2` | `3.5` |
| `//` | divisione intera | `7 // 2` | `3` |
| `%` | resto (modulo) | `7 % 2` | `1` |
| `**` | elevamento a potenza | `7 ** 2` | `49` |

Alcune osservazioni importanti:

*   La divisione `/` restituisce **sempre** un `float`, anche se il risultato è "tondo": `6 / 3` vale `2.0`. Se serve un intero si usa `//`.
*   `//` e `%` sono utilissimi: `n % 2 == 0` controlla se un numero è pari, `n % 10` restituisce l'ultima cifra di un numero e `n // 10` la "toglie".
*   L'ordine delle operazioni è quello della matematica: prima `**`, poi `*`, `/`, `//`, `%`, infine `+` e `-`. In caso di dubbio, usate le **parentesi tonde**.
*   La radice quadrata si può calcolare come potenza: `x ** 0.5` (oppure `x ** (1/2)`).

### Assegnamento composto
Capita continuamente di dover aggiornare una variabile usando il suo stesso valore. Esistono delle abbreviazioni:

```python
contatore = 0
contatore += 1     # equivale a contatore = contatore + 1
totale = 100
totale -= 30       # totale = totale - 30
prodotto = 2
prodotto *= 5      # prodotto = prodotto * 5
media = 50
media /= 4         # media = media / 4
```

:::note
In Python **non esistono** gli operatori `++` e `--` del C: si scrive `i += 1`.
:::

## 5. Output: la funzione `print`

`print` può ricevere più valori separati da virgole: li stampa uno dopo l'altro separati da uno spazio, e alla fine va a capo.

```python
base = 4
altezza = 3
print("L'area è", base * altezza / 2)
```

```text
L'area è 6.0
```

Si può modificare il comportamento con due parametri opzionali:

*   `sep` decide cosa mettere **tra** i valori (di default uno spazio);
*   `end` decide cosa mettere **alla fine** (di default `"\n"`, cioè l'a capo).

```python
print(1, 2, 3, sep="-")    # 1-2-3
print("Ciao", end=" ")
print("a tutti")           # Ciao a tutti  (sulla stessa riga)
```

Il trucco `end=" "` è molto usato nei cicli per stampare più valori sulla stessa riga.

### Le f-string
Il modo più comodo e leggibile per costruire un testo che contiene dei valori è la **f-string**: si mette una `f` prima delle virgolette e si scrivono le espressioni tra parentesi graffe `{}`.

```python
a = 7
b = 2
print(f"{a} + {b} = {a + b}")
print(f"{a} / {b} = {a / b}")
```

```text
7 + 2 = 9
7 / 2 = 3.5
```

Dopo l'espressione si possono aggiungere i due punti `:` seguiti da un **formato**:

| Formato | Significato | Esempio | Risultato |
|---|---|---|---|
| `:.2f` | float con 2 cifre decimali | `f"{3.14159:.2f}"` | `3.14` |
| `:5d` | intero su 5 caratteri (allineato a destra) | `f"{42:5d}"` | `   42` |
| `:<5` | allineato a sinistra su 5 caratteri | `f"{'ab':<5}"` | `ab   ` |
| `:^7` | centrato su 7 caratteri | `f"{'ab':^7}"` | `  ab   ` |

I formati con la larghezza (`:3d`, `:5d`...) sono fondamentali per stampare tabelle e [matrici](../matrici/) ben incolonnate.

## 6. Input: la funzione `input`

La funzione `input` mostra un messaggio, aspetta che l'utente scriva qualcosa e prema Invio, e restituisce **sempre una stringa**.

```python
nome = input("Come ti chiami? ")
print(f"Ciao {nome}!")
```

Se vogliamo un numero dobbiamo **convertire** la stringa con `int()` o `float()`:

```python
base = float(input("Scrivi il valore della base: "))
altezza = float(input("Scrivi il valore dell'altezza: "))
area = base * altezza / 2
print(f"L'area del triangolo è {area}")
```

:::caution[Errore classicissimo: dimenticare la conversione]
```python
a = input("Primo numero: ")    # l'utente scrive 3
b = input("Secondo numero: ")  # l'utente scrive 4
print(a + b)                   # stampa 34, non 7!
```
Senza conversione `a` e `b` sono le stringhe `"3"` e `"4"`, e il `+` tra stringhe le **concatena** (le attacca una dopo l'altra) invece di sommarle.
:::

Se l'utente scrive qualcosa che non è un numero (ad esempio `ciao`), `int()` genera un errore `ValueError` e il programma si interrompe. Per ora non ce ne preoccupiamo.

### Conversioni di tipo
| Funzione | Converte in | Esempio | Risultato |
|---|---|---|---|
| `int(x)` | intero (tronca i decimali) | `int("12")`, `int(3.9)` | `12`, `3` |
| `float(x)` | float | `float("2.5")`, `float(4)` | `2.5`, `4.0` |
| `str(x)` | stringa | `str(42)` | `"42"` |

### Leggere più valori sulla stessa riga
A volte è comodo far inserire più numeri in una sola riga separati da spazi. Si usa il metodo `split()`, che divide la stringa in pezzi:

```python
riga = input("Inserisci due numeri separati da uno spazio: ")  # es. "3 4"
pezzi = riga.split()          # ["3", "4"]
a = int(pezzi[0])
b = int(pezzi[1])
print(a + b)                  # 7
```

Le parentesi quadre `[0]` e `[1]` servono a prendere il primo e il secondo pezzo: le vedremo bene nella pagina sulle [liste](../liste/).

## 7. Un primo sguardo alle stringhe

Le stringhe verranno approfondite in seguito, ma alcune operazioni sono utili fin da subito:

```python
saluto = "Ciao"
nome = "Marco"
print(saluto + " " + nome)  # concatenazione: Ciao Marco
print("ah" * 3)             # ripetizione: ahahah
print(len(nome))            # lunghezza: 5
print(nome.upper())         # MARCO
print(nome.lower())         # marco
```

:::caution[Non si possono sommare stringhe e numeri]
```python
eta = 16
print("Hai " + eta + " anni")   # TypeError!
```
Bisogna convertire il numero con `str(eta)`, oppure (molto meglio) usare una f-string: `print(f"Hai {eta} anni")`.
:::

## 8. Funzioni matematiche e moduli

Alcune funzioni sono sempre disponibili (si dicono *built-in*):

| Funzione | Descrizione | Esempio | Risultato |
|---|---|---|---|
| `abs(x)` | valore assoluto | `abs(-7)` | `7` |
| `round(x)` | arrotonda all'intero più vicino | `round(3.7)` | `4` |
| `round(x, n)` | arrotonda a `n` decimali | `round(3.14159, 2)` | `3.14` |
| `max(a, b, ...)` | il più grande | `max(3, 8, 5)` | `8` |
| `min(a, b, ...)` | il più piccolo | `min(3, 8, 5)` | `3` |

Molte altre funzioni sono raccolte in **moduli** che vanno **importati** con l'istruzione `import`. Il più usato per i calcoli è `math`:

```python
import math

print(math.sqrt(16))    # radice quadrata: 4.0
print(math.pi)          # 3.141592653589793
print(math.floor(3.7))  # approssimazione per difetto: 3
print(math.ceil(3.2))   # approssimazione per eccesso: 4
```

In alternativa si possono importare solo le funzioni che servono, così da non dover scrivere `math.` davanti:

```python
from math import sqrt, pi

circonferenza = 2 * pi * 5
print(sqrt(25))
```

### Numeri casuali
Il modulo `random` permette di generare numeri casuali, utilissimo per giochi, simulazioni e per riempire velocemente liste e matrici di prova:

```python
from random import randint, random

dado = randint(1, 6)   # intero casuale tra 1 e 6, ESTREMI COMPRESI
x = random()           # float casuale tra 0 (compreso) e 1 (escluso)
print(dado, x)
```

## 9. Errori comuni

| Messaggio di errore | Causa tipica |
|---|---|
| `SyntaxError` | Errore di scrittura: parentesi o virgolette non chiuse, due punti mancanti... |
| `NameError: name 'x' is not defined` | Variabile usata prima di essere creata, oppure nome scritto male (attenzione alle maiuscole!) |
| `TypeError: can only concatenate str (not "int") to str` | Somma tra stringa e numero |
| `ValueError: invalid literal for int()` | `int()` applicato a un testo che non rappresenta un numero intero |
| `ZeroDivisionError` | Divisione (o `//` o `%`) per zero |
| `IndentationError` | Righe rientrate (spostate a destra) senza motivo: in Python l'indentazione ha un significato preciso, come vedremo nella prossima pagina |

:::tip[Leggere i messaggi di errore]
Quando il programma si blocca, Python stampa un messaggio (chiamato *traceback*). Leggetelo **dal basso**: l'ultima riga dice il tipo di errore, poco sopra c'è il numero di riga in cui si è verificato. Nove volte su dieci basta questo per capire il problema.
:::

## Esercizi

Gli esercizi relativi a questi argomenti si trovano nel capitolo **"Variabili e operazioni elementari"** dell'eserciziario, linkato nella [pagina introduttiva](../programmazione-in-python/).
