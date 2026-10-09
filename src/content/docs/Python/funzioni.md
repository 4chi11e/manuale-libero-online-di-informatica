---
title: Funzioni
description: Definire e usare funzioni in Python, parametri, valori di ritorno, visibilità delle variabili e ricorsione
---

Man mano che i programmi crescono, scrivere tutto in un unico blocco di codice diventa scomodo: lo stesso pezzo di codice viene copiato in più punti, e diventa difficile capire cosa fa ogni parte. Le **funzioni** risolvono questo problema.

Una **funzione** è un blocco di codice a cui diamo un **nome**, che svolge un compito preciso e che possiamo **richiamare** (cioè eseguire) tutte le volte che vogliamo. Ne abbiamo già usate molte: `print`, `input`, `int`, `len`, `math.sqrt`... Ora impariamo a scriverne di nostre.

Usare le funzioni porta tre grandi vantaggi:

*   **Riuso**: il codice si scrive una volta sola e si usa ovunque serva. Se c'è un errore, si corregge in un solo punto.
*   **Leggibilità**: `if e_primo(n):` è molto più chiaro di dieci righe di cicli e condizioni.
*   **Scomposizione dei problemi**: un problema complesso si spezza in tanti sotto-problemi più semplici, ciascuno risolto da una funzione (approccio *top-down*).

## 1. Definire e chiamare una funzione

Una funzione si **definisce** con la parola chiave `def`, seguita dal nome, dalle parentesi tonde con gli eventuali parametri e dai due punti. Il corpo della funzione è indentato, proprio come i blocchi di `if` e cicli.

```python
def saluta():
    print("Ciao!")
    print("Benvenuto nel programma")

saluta()   # chiamata della funzione
saluta()   # posso chiamarla quante volte voglio
```

Attenzione a due aspetti:

*   la **definizione** (`def ...`) non esegue nulla: dice solo a Python "esiste una funzione con questo nome che fa queste cose". Il codice della funzione viene eseguito solo quando la funzione viene **chiamata**;
*   una funzione deve essere definita **prima** di essere chiamata, altrimenti si ottiene un `NameError`. Per questo le definizioni si mettono di solito all'inizio del file.

## 2. Parametri e argomenti

Quasi sempre una funzione ha bisogno di ricevere dei dati su cui lavorare. Questi dati si indicano tra le parentesi:

```python
def stampa_rettangolo(righe, colonne):
    for i in range(righe):
        print("* " * colonne)

stampa_rettangolo(2, 5)
stampa_rettangolo(3, 3)
```

*   I nomi scritti nella definizione (`righe`, `colonne`) si chiamano **parametri**: sono variabili che esistono solo dentro la funzione.
*   I valori passati nella chiamata (`2` e `5`) si chiamano **argomenti**. Al momento della chiamata il primo argomento viene assegnato al primo parametro, il secondo al secondo, e così via.

Gli argomenti possono essere valori, variabili o espressioni qualsiasi: `stampa_rettangolo(n, n * 2)`.

### Argomenti per nome e valori di default
Si può indicare esplicitamente a quale parametro assegnare un argomento scrivendone il nome. In questo modo l'ordine non conta più:

```python
stampa_rettangolo(colonne=5, righe=2)
```

Ai parametri si può anche assegnare un **valore di default**, che viene usato quando l'argomento non viene passato. I parametri con valore di default devono stare in fondo:

```python
def stampa_rettangolo(righe, colonne, simbolo="*"):
    for i in range(righe):
        print(f"{simbolo} " * colonne)

stampa_rettangolo(2, 5)        # usa "*"
stampa_rettangolo(2, 5, "#")   # usa "#"
```

È lo stesso meccanismo che abbiamo usato con `print(..., end=" ")`.

## 3. Il valore di ritorno: `return`

Una funzione può **restituire** un risultato a chi l'ha chiamata con l'istruzione `return`. Il valore restituito "prende il posto" della chiamata e può essere stampato, salvato in una variabile o usato in un'espressione.

```python
def somma(a, b):
    return a + b

risultato = somma(3, 5)
print(risultato)              # 8
print(somma(10, 2) * 2)       # 24
if somma(1, 1) == 2:
    print("La matematica funziona")
```

Quando viene eseguito un `return` la funzione **termina immediatamente**, anche se ci sono altre istruzioni dopo. Questo permette di scrivere funzioni con più `return`:

```python
def calcola(a, b, simbolo):
    if simbolo == '+':
        return a + b
    elif simbolo == '-':
        return a - b
    elif simbolo == '*':
        return a * b
    elif simbolo == '/':
        return a / b
    print(f"Operatore \"{simbolo}\" non valido")
    return None
```

### `return` o `print`?
È una delle confusioni più frequenti all'inizio. Confrontate queste due funzioni:

```python
def stampa_maggiore(a, b):
    if a > b:
        print(a)
    else:
        print(b)

def maggiore(a, b):
    if a > b:
        return a
    return b
```

*   `stampa_maggiore` **mostra** il risultato sullo schermo, ma il valore poi si perde: il resto del programma non può usarlo.
*   `maggiore` **restituisce** il risultato, e chi la chiama decide cosa farne: stamparlo, salvarlo, usarlo in un altro calcolo (`maggiore(maggiore(a, b), c)` trova il massimo tra tre numeri!).

Una funzione senza `return` restituisce comunque un valore speciale, `None`, che significa "niente":

```python
x = stampa_maggiore(2, 5)   # stampa 5
print(x)                    # None
```

:::tip[Regola pratica]
A meno che il compito della funzione non sia proprio stampare qualcosa, è quasi sempre meglio che **restituisca** il risultato invece di stamparlo. Allo stesso modo, è meglio che una funzione riceva i dati come **parametri** invece di chiederli con `input` al suo interno: sarà molto più facile da riutilizzare.
:::

### Restituire più valori
In Python una funzione può restituire più valori contemporaneamente, separandoli con la virgola. Chi chiama la funzione può raccoglierli in altrettante variabili:

```python
import math

def perimetro_area(c1, c2):
    ipotenusa = math.sqrt(c1**2 + c2**2)
    perimetro = c1 + c2 + ipotenusa
    area = c1 * c2 / 2
    return perimetro, area

p, a = perimetro_area(3, 4)
print(f"Perimetro = {p}, Area = {a}")   # Perimetro = 12.0, Area = 6.0
```

In realtà la funzione restituisce un unico oggetto, una **tupla** `(12.0, 6.0)`, che viene poi "spacchettata" nelle due variabili. Le tuple sono descritte brevemente nella pagina sulle [liste](../liste/#11-le-tuple).

## 4. Visibilità delle variabili (scope)

Le variabili create all'interno di una funzione, compresi i parametri, sono **variabili locali**: esistono solo durante l'esecuzione della funzione e non sono visibili dall'esterno.

```python
def raddoppia(n):
    risultato = n * 2
    return risultato

print(raddoppia(5))   # 10
print(risultato)      # NameError: risultato non esiste qui fuori!
```

Le variabili create fuori da qualsiasi funzione si chiamano **globali**. Una funzione può leggerle, ma se prova ad assegnare loro un valore Python crea invece una nuova variabile locale con lo stesso nome:

```python
x = 10

def prova():
    x = 99         # questa è una NUOVA variabile locale
    print(x)       # 99

prova()
print(x)           # 10: la x globale non è cambiata
```

Esiste la parola chiave `global` per modificare una variabile globale da dentro una funzione, ma il suo uso è **fortemente sconsigliato**: rende il programma difficile da capire, perché il comportamento di una funzione dipende da qualcosa che sta fuori di essa. Il modo corretto è passare i dati come parametri e ricevere i risultati con `return`.

:::caution[Liste e dizionari passati come parametri]
Quando si passa a una funzione una [lista](../liste/) o un [dizionario](../dizionari/), la funzione riceve **lo stesso oggetto**, non una copia. Se la funzione lo modifica (ad esempio con `append`), la modifica è visibile anche all'esterno. Approfondiremo questo comportamento nella pagina sulle liste.
:::

## 5. Documentare le funzioni

È buona abitudine scrivere subito sotto la riga `def` una breve descrizione della funzione tra triple virgolette, chiamata **docstring**. VS Code la mostra quando si passa il mouse sopra il nome della funzione.

```python
def e_primo(n):
    """Restituisce True se n è un numero primo, False altrimenti."""
    if n < 2:
        return False
    for d in range(2, int(n ** 0.5) + 1):
        if n % d == 0:
            return False
    return True
```

Notate come in questa versione del controllo di primalità i `return` multipli rendano inutile la variabile flag che avevamo usato nelle [strutture di controllo](../strutture-di-controllo/#flag-variabile-booleana). Inoltre basta cercare i divisori fino alla radice quadrata di `n`: se `n` avesse un divisore più grande, avrebbe anche il suo "compagno" più piccolo della radice.

## 6. Struttura di un programma con funzioni

Un programma ben organizzato ha di solito questa forma: in alto gli `import`, poi le definizioni delle funzioni, infine il programma principale che le usa.

```python
from random import randint

def genera_numeri(quanti, minimo, massimo):
    """Restituisce una lista di numeri casuali."""
    return [randint(minimo, massimo) for _ in range(quanti)]

def media(numeri):
    """Restituisce la media dei numeri della lista."""
    return sum(numeri) / len(numeri)

# programma principale
numeri = genera_numeri(10, 1, 10)
print(numeri)
print(f"Media: {media(numeri):.2f}")
```

(La riga `[randint(...) for _ in range(quanti)]` è una *list comprehension*, che vedremo nella pagina sulle [liste](../liste/).)

## 7. La ricorsione

Una funzione può chiamare qualsiasi altra funzione, **anche sé stessa**. Una funzione che chiama sé stessa si dice **ricorsiva**.

L'idea della ricorsione è risolvere un problema riconducendolo allo **stesso problema, ma più piccolo**, finché non diventa così piccolo da avere una soluzione immediata. L'esempio classico è il fattoriale:

$$n! = n \cdot (n-1)! \qquad \text{e} \qquad 0! = 1$$

Cioè: per calcolare il fattoriale di 5 basta saper calcolare il fattoriale di 4 e moltiplicarlo per 5, e così via fino a 0, il cui fattoriale vale 1 per definizione.

```python
def fattoriale(n):
    if n == 0:                       # caso base
        return 1
    return n * fattoriale(n - 1)     # passo ricorsivo

print(fattoriale(5))   # 120
```

Ogni funzione ricorsiva deve avere due elementi:

1.  **Il caso base**: una situazione in cui la risposta è nota direttamente, senza ulteriori chiamate ricorsive.
2.  **Il passo ricorsivo**: la funzione chiama sé stessa su un problema **più piccolo**, che si avvicina al caso base.

Ecco cosa succede quando si calcola `fattoriale(3)`:

```text
fattoriale(3) = 3 * fattoriale(2)
                    fattoriale(2) = 2 * fattoriale(1)
                                        fattoriale(1) = 1 * fattoriale(0)
                                                            fattoriale(0) = 1
                                        fattoriale(1) = 1 * 1 = 1
                    fattoriale(2) = 2 * 1 = 2
fattoriale(3) = 3 * 2 = 6
```

Ogni chiamata resta "in sospeso" in attesa del risultato della chiamata successiva. Le chiamate in sospeso vengono memorizzate in un'area di memoria chiamata **stack** (pila).

:::danger[Ricorsione infinita]
Se manca il caso base, o se il passo ricorsivo non si avvicina mai al caso base (ad esempio `fattoriale(-1)` con la funzione sopra), la funzione continua a chiamare sé stessa senza fine. Python si accorge del problema dopo circa 1000 chiamate annidate e interrompe il programma con un `RecursionError`.
:::

### Ricorsione o iterazione?
Tutto ciò che si può fare con la ricorsione si può fare anche con i cicli, e viceversa. La versione iterativa di solito è più efficiente, ma ci sono problemi (come l'esplorazione di alberi e grafi, o alcuni algoritmi di ordinamento) in cui la soluzione ricorsiva è molto più naturale e semplice da scrivere.

Un altro esempio: stampare gli elementi di una lista in modo ricorsivo. Il caso base è la lista vuota (non c'è niente da stampare); il passo ricorsivo stampa il primo elemento e poi richiama la funzione sul resto della lista.

```python
def stampa_ricorsiva(lista):
    if len(lista) == 0:
        return
    print(lista[0], end=" ")
    stampa_ricorsiva(lista[1:])

stampa_ricorsiva([1, 2, 3, 4, 5])   # 1 2 3 4 5
```

## Esercizi

Gli esercizi relativi a questi argomenti si trovano nel capitolo **"Funzioni"** dell'eserciziario (sezioni *Funzioni semplici* e *Funzioni ricorsive*), linkato nella [pagina introduttiva](../programmazione-in-python/).
