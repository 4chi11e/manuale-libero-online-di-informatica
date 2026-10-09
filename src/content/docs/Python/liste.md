---
title: Liste
description: Le liste in Python, indici, metodi, slicing, list comprehension, riferimenti e copie e gli algoritmi fondamentali
---

Supponiamo di dover memorizzare i voti di una classe di 25 studenti. Creare 25 variabili `voto1`, `voto2`, ..., `voto25` sarebbe assurdo, e non potremmo nemmeno scorrerle con un ciclo. Ci serve una variabile capace di contenere **tanti valori**: in Python questa struttura si chiama **lista**.

## 1. Cos'è una lista

Una **lista** è una sequenza **ordinata** di valori, detti **elementi**. Si crea scrivendo gli elementi tra parentesi quadre, separati da virgole:

```python
voti = [7, 8, 5, 9, 6]
nomi = ["Anna", "Luca", "Marta"]
vuota = []                          # lista vuota
mista = [3, "ciao", 2.5, True]      # elementi di tipo diverso

print(voti)          # [7, 8, 5, 9, 6]
print(len(voti))     # 5: il numero di elementi
```

Chi viene dal C riconoscerà nelle liste qualcosa di simile agli **array**, ma con importanti differenze:

*   una lista **non ha una dimensione fissa**: può crescere e restringersi durante l'esecuzione;
*   una lista può contenere elementi di **tipo diverso** (anche se, nella pratica, quasi sempre conterrà elementi dello stesso tipo);
*   Python controlla sempre che non si acceda a posizioni inesistenti, segnalando un errore invece di leggere memoria a caso.

## 2. Accesso agli elementi: gli indici

Ogni elemento occupa una posizione, chiamata **indice**. Gli indici **partono da 0**: il primo elemento ha indice 0, il secondo 1, e l'ultimo ha indice `len(lista) - 1`.

```text
lista:    [ 7 | 8 | 5 | 9 | 6 ]
indice:     0   1   2   3   4
negativo:  -5  -4  -3  -2  -1
```

Per accedere a un elemento si scrive il nome della lista seguito dall'indice tra parentesi quadre:

```python
voti = [7, 8, 5, 9, 6]
print(voti[0])     # 7: il primo
print(voti[2])     # 5
print(voti[4])     # 6: l'ultimo
print(voti[-1])    # 6: l'ultimo, con indice negativo
print(voti[-2])    # 9: il penultimo
```

Gli **indici negativi** contano dalla fine: `-1` è l'ultimo elemento, `-2` il penultimo e così via. Sono comodissimi per accedere al fondo della lista senza calcolarne la lunghezza.

:::caution[IndexError]
Accedere a un indice che non esiste causa l'errore `IndexError: list index out of range`. L'errore più frequente è usare `voti[len(voti)]` pensando di prendere l'ultimo elemento: l'ultimo indice valido è `len(voti) - 1`.
:::

## 3. Modificare gli elementi

Le liste sono **mutabili**: i loro elementi possono essere modificati dopo la creazione, assegnando un nuovo valore a una posizione.

```python
voti = [7, 8, 5, 9, 6]
voti[2] = 6
voti[-1] += 1
print(voti)    # [7, 8, 6, 9, 7]
```

## 4. Scorrere una lista

Esistono due modi principali per scorrere una lista con un ciclo `for`.

### Scorrere gli elementi
Se ci interessano solo i **valori**, si scorre direttamente la lista: a ogni iterazione la variabile di ciclo contiene l'elemento successivo.

```python
voti = [7, 8, 5, 9, 6]
for voto in voti:
    print(voto, end=" ")
```

### Scorrere gli indici
Se ci serve sapere anche la **posizione** di ogni elemento, oppure dobbiamo **modificare** gli elementi, si scorrono gli indici con `range(len(lista))`:

```python
voti = [7, 8, 5, 9, 6]
for i in range(len(voti)):
    print(f"Voto n.{i + 1}: {voti[i]}")

# aumento tutti i voti di 1
for i in range(len(voti)):
    voti[i] += 1
```

:::caution
Modificare la variabile di ciclo **non** modifica la lista:
```python
for voto in voti:
    voto += 1      # cambia solo la variabile voto, la lista resta uguale!
```
Per modificare gli elementi bisogna passare dall'indice: `voti[i] += 1`.
:::

Esiste anche la funzione `enumerate`, che fornisce a ogni iterazione sia l'indice sia l'elemento:

```python
for i, voto in enumerate(voti):
    print(i, voto)
```

## 5. Aggiungere e rimuovere elementi

| Operazione | Effetto | Esempio (partendo da `l = [1, 2, 3]`) |
|---|---|---|
| `l.append(x)` | aggiunge `x` in fondo | `l.append(4)` → `[1, 2, 3, 4]` |
| `l.insert(i, x)` | inserisce `x` in posizione `i` | `l.insert(0, 9)` → `[9, 1, 2, 3]` |
| `l.pop()` | rimuove e **restituisce** l'ultimo elemento | `l.pop()` → restituisce `3`, `l` diventa `[1, 2]` |
| `l.pop(i)` | rimuove e restituisce l'elemento in posizione `i` | `l.pop(0)` → restituisce `1`, `l` diventa `[2, 3]` |
| `l.remove(x)` | rimuove la **prima** occorrenza del valore `x` | `l.remove(2)` → `[1, 3]` |
| `del l[i]` | elimina l'elemento in posizione `i` | `del l[1]` → `[1, 3]` |
| `l.clear()` | svuota la lista | `l.clear()` → `[]` |

Attenzione alla differenza tra `pop(i)`/`del`, che lavorano con la **posizione**, e `remove(x)`, che lavora con il **valore**. Se il valore da rimuovere non è presente, `remove` genera un errore `ValueError`.

`append` è di gran lunga il metodo più usato: il modo tipico per costruire una lista è partire da una lista vuota e aggiungere un elemento alla volta.

```python
voti = []
n = int(input("Quanti voti vuoi inserire? "))
for i in range(n):
    voto = float(input(f"Scrivi il {i + 1}° voto: "))
    while voto < 1 or voto > 10:
        voto = float(input("Voto non valido, reinseriscilo: "))
    voti.append(voto)
print(voti)
```

## 6. Operatori e funzioni utili

```python
a = [1, 2, 3]
b = [4, 5]

print(a + b)          # [1, 2, 3, 4, 5]   concatenazione
print(a * 2)          # [1, 2, 3, 1, 2, 3] ripetizione
print(2 in a)         # True: 2 è presente nella lista
print(7 not in a)     # True
print([0] * 5)        # [0, 0, 0, 0, 0]  utile per creare liste "vuote" di una certa lunghezza
```

Funzioni e metodi che lavorano su liste di numeri (e non solo):

| Funzione / metodo | Descrizione | Esempio con `l = [4, 1, 3, 1]` |
|---|---|---|
| `len(l)` | numero di elementi | `4` |
| `sum(l)` | somma degli elementi | `9` |
| `min(l)` / `max(l)` | elemento minimo / massimo | `1` / `4` |
| `l.count(x)` | quante volte compare `x` | `l.count(1)` → `2` |
| `l.index(x)` | indice della prima occorrenza di `x` | `l.index(3)` → `2` |
| `sorted(l)` | restituisce una **nuova** lista ordinata | `[1, 1, 3, 4]` (`l` non cambia) |
| `l.sort()` | ordina la lista **stessa** | `l` diventa `[1, 1, 3, 4]` |
| `l.sort(reverse=True)` | ordina in ordine decrescente | `l` diventa `[4, 3, 1, 1]` |
| `l.reverse()` | inverte l'ordine della lista stessa | `l` diventa `[1, 3, 1, 4]` |

:::caution[sort() non restituisce nulla]
I metodi che modificano la lista, come `sort()`, `reverse()` e `append()`, restituiscono `None`. Scrivere `l = l.sort()` è un errore classico: si ottiene `l = None` e la lista è persa! Si scrive semplicemente `l.sort()`, oppure `l2 = sorted(l)` se si vuole una nuova lista ordinata lasciando intatta l'originale.
:::

:::tip
Con le funzioni già pronte la media si calcola in una riga: `media = sum(voti) / len(voti)`. Negli esercizi però vi verrà spesso chiesto di **non** usare `sum`, `max`, `sort`... per imparare a scrivere da soli gli algoritmi corrispondenti (li trovate in fondo alla pagina).
:::

## 7. Slicing: estrarre porzioni di lista

Con lo **slicing** (letteralmente "affettare") si estrae una porzione di lista, indicando tra parentesi quadre l'indice di **inizio** (incluso) e quello di **fine** (escluso), separati dai due punti. Funziona esattamente come `range`.

```python
l = [10, 20, 30, 40, 50, 60]
print(l[1:4])     # [20, 30, 40]   dall'indice 1 al 4 escluso
print(l[:3])      # [10, 20, 30]   dall'inizio al 3 escluso
print(l[3:])      # [40, 50, 60]   dal 3 fino alla fine
print(l[-2:])     # [50, 60]       gli ultimi due
print(l[::2])     # [10, 30, 50]   un elemento ogni due
print(l[::-1])    # [60, 50, 40, 30, 20, 10]  lista invertita
print(l[:])       # una copia dell'intera lista
```

La forma completa è `lista[inizio:fine:passo]`; ognuno dei tre valori può essere omesso. Lo slicing restituisce sempre una **nuova lista**, senza modificare l'originale.

Le stesse regole di indici e slicing valgono anche per le **stringhe**: `"ciao"[0]` è `"c"` e `"ciao"[::-1]` è `"oaic"`.

## 8. Creare liste da input e liste casuali

### Leggere tutti i valori su una riga
Invece di chiedere un valore alla volta, si può far scrivere all'utente tutti i numeri su una riga separati da spazi, e poi dividerla con `split()`:

```python
riga = input("Inserisci i voti separati da spazi: ")  # es. "7 8 5.5 9"
pezzi = riga.split()               # ["7", "8", "5.5", "9"]: ancora stringhe!
voti = []
for pezzo in pezzi:
    voti.append(float(pezzo))      # [7.0, 8.0, 5.5, 9.0]
```

### Liste di numeri casuali
Per provare i programmi è comodissimo generare liste di numeri casuali:

```python
from random import randint

numeri = []
for _ in range(10):
    numeri.append(randint(1, 100))
print(numeri)
```

Le stesse operazioni si possono scrivere in modo molto più compatto con le *list comprehension*.

## 9. List comprehension

Una **list comprehension** è una sintassi compatta per creare una lista a partire da un ciclo. La forma base è:

```text
[espressione for variabile in sequenza]
```

e significa: "crea una lista che contiene il valore di *espressione* per ogni *variabile* della *sequenza*".

```python
quadrati = [x ** 2 for x in range(1, 6)]           # [1, 4, 9, 16, 25]
numeri = [randint(1, 100) for _ in range(10)]      # 10 numeri casuali
voti = [float(v) for v in input("Voti: ").split()] # lettura da input in una riga
```

Si può aggiungere una **condizione** in fondo per includere solo alcuni elementi:

```python
voti = [7, 4.5, 8, 5, 6, 9]
sufficienti = [v for v in voti if v >= 6]     # [7, 8, 6, 9]
```

Ogni list comprehension equivale a un normale ciclo con `append`. Ad esempio l'ultima riga equivale a:

```python
sufficienti = []
for v in voti:
    if v >= 6:
        sufficienti.append(v)
```

:::tip
Le list comprehension sono eleganti e molto usate, ma se diventano troppo lunghe o complicate è meglio tornare al ciclo esplicito, che è più leggibile.
:::

## 10. Riferimenti e copie

Questo è uno degli aspetti più importanti (e più fonte di errori) delle liste. Osservate:

```python
l1 = [1, 2, 3]
l2 = l1
l2[0] = 0
print(l1)        # [0, 2, 3]  ?!
```

Perché è cambiata anche `l1`? In Python una variabile non "contiene" la lista, ma è un **riferimento** (un nome che punta) a un oggetto in memoria. L'istruzione `l2 = l1` **non copia la lista**: crea un secondo nome per **la stessa lista**. Qualsiasi modifica fatta tramite `l2` è visibile anche tramite `l1`, perché sono la stessa cosa.

```text
l1 ──┐
     ├──► [0, 2, 3]
l2 ──┘
```

Se si vuole una copia indipendente bisogna crearla esplicitamente:

```python
l1 = [1, 2, 3]
l2 = l1.copy()    # oppure l2 = l1[:]  oppure l2 = list(l1)
l2[0] = 0
print(l1)         # [1, 2, 3]
print(l2)         # [0, 2, 3]
```

Per le liste di liste, come le matrici, `copy()` non basta: vedi [Copiare una matrice](../matrici/#copiare-una-matrice).

### Liste passate alle funzioni
Lo stesso meccanismo vale per i parametri delle [funzioni](../funzioni/): una funzione che riceve una lista lavora sulla **lista originale**, e le modifiche restano anche dopo la fine della funzione.

```python
def azzera_negativi(lista):
    for i in range(len(lista)):
        if lista[i] < 0:
            lista[i] = 0

numeri = [3, -2, 5, -7]
azzera_negativi(numeri)
print(numeri)    # [3, 0, 5, 0]
```

Questo comportamento è utile (non serve restituire la lista modificata), ma bisogna esserne consapevoli: se la funzione non deve modificare la lista originale, deve lavorare su una copia.

Bisogna però distinguere due operazioni molto diverse:

*   **modificare l'oggetto** a cui il nome punta (`lista[0] = 99`, `lista.append(4)`, `lista.sort()`...): il riferimento resta lo stesso, quindi la modifica è visibile da tutti i nomi che puntano a quella lista;
*   **assegnare** un nuovo valore al nome (`lista = ...`): l'oggetto originale non viene toccato, è il nome che smette di puntarlo e inizia a puntare a un altro oggetto.

```python
def modifica(lista):
    lista[0] = 99        # modifica la lista ricevuta

def riassegna(lista):
    lista = [99, 99]     # il nome locale ora punta a una NUOVA lista

numeri = [1, 2, 3]
riassegna(numeri)
print(numeri)            # [1, 2, 3]: l'originale non è cambiata
modifica(numeri)
print(numeri)            # [99, 2, 3]
```

Ecco cosa succede dentro `riassegna`:

```text
all'inizio della funzione:          dopo  lista = [99, 99]:

numeri ──┐                           numeri ──► [1, 2, 3]
         ├──► [1, 2, 3]
lista  ──┘                           lista  ──► [99, 99]
```

Il parametro `lista` è un nome locale: assegnargli un valore cambia solo dove punta lui, e alla fine della funzione sparisce insieme alla nuova lista. Per questo `lista = []` dentro una funzione **non svuota** la lista originale.

:::note
Con i numeri e le stringhe questo problema non si presenta, perché sono **immutabili**: non esiste un modo di modificarli "sul posto", ogni operazione crea un nuovo valore.
:::

## 11. Le tuple

Una **tupla** è una sequenza molto simile a una lista, ma **immutabile**: una volta creata non si possono modificare, aggiungere o togliere elementi. Si scrive con le parentesi tonde:

```python
punto = (3, 5)
print(punto[0])      # 3: indici e slicing funzionano come nelle liste
punto[0] = 4         # TypeError: le tuple non si possono modificare
```

Le tuple si usano per gruppi di valori che "vanno insieme" e non devono cambiare, come le coordinate di un punto o i valori restituiti da una funzione. Si possono **spacchettare** in più variabili:

```python
x, y = punto
print(x, y)          # 3 5
```

Lo spacchettamento permette anche di scambiare due variabili in una sola riga, cosa che torna utilissima negli algoritmi di ordinamento:

```python
a, b = b, a
```

## 12. Algoritmi fondamentali sulle liste

Gli algoritmi che seguono hanno un equivalente già pronto in Python, ma saperli scrivere da soli è fondamentale: sono la base di qualsiasi algoritmo più complesso.

### Somma e media
```python
somma = 0
for n in numeri:
    somma += n
media = somma / len(numeri)
```

### Massimo e posizione del massimo
```python
pos_max = 0
for i in range(1, len(numeri)):
    if numeri[i] > numeri[pos_max]:
        pos_max = i
print(f"Il massimo è {numeri[pos_max]} in posizione {pos_max}")
```

### Ricerca di un elemento (ricerca lineare)
Si scorre la lista finché non si trova l'elemento cercato. Se si arriva in fondo senza trovarlo, l'elemento non c'è.

```python
def cerca(lista, x):
    """Restituisce l'indice della prima occorrenza di x, oppure -1 se x non è presente."""
    for i in range(len(lista)):
        if lista[i] == x:
            return i
    return -1
```

### Conteggio
```python
def conta_maggiori(lista, soglia):
    """Conta quanti elementi della lista sono maggiori della soglia."""
    conta = 0
    for n in lista:
        if n > soglia:
            conta += 1
    return conta
```

### Inversione "sul posto"
Si scambia il primo elemento con l'ultimo, il secondo con il penultimo, e così via fino a metà lista.

```python
def inverti(lista):
    n = len(lista)
    for i in range(n // 2):
        lista[i], lista[n - 1 - i] = lista[n - 1 - i], lista[i]
```

### Filtrare: costruire una nuova lista
```python
pari = []
for n in numeri:
    if n % 2 == 0:
        pari.append(n)
# oppure: pari = [n for n in numeri if n % 2 == 0]
```

:::caution[Non rimuovere elementi mentre si scorre la lista con un for]
```python
numeri = [2, 4, 5, 6]
for n in numeri:
    if n % 2 == 0:
        numeri.remove(n)
print(numeri)    # [4, 5]: il 4 è sfuggito!
```
Quando si rimuove un elemento, tutti quelli successivi "scalano" di una posizione e il ciclo ne salta uno. Conviene costruire una **nuova lista** con gli elementi da tenere, oppure usare un `while` con l'indice che avanza solo quando non si rimuove nulla.
:::

## Esercizi

Gli esercizi relativi a questi argomenti si trovano nel capitolo **"Strutture dati fondamentali"** dell'eserciziario (sezioni *Liste di soli numeri* e *Liste miste*) e nel capitolo **"Algoritmi di ordinamento base"**, linkato nella [pagina introduttiva](../programmazione-in-python/).
