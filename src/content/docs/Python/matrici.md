---
title: Matrici
description: Le matrici in Python come liste di liste, creazione, scorrimento per righe e per colonne, diagonali e celle adiacenti
---

Molti dati si organizzano naturalmente in una **tabella** con righe e colonne: il registro dei voti (studenti × materie), una scacchiera, il campo di gioco di battaglia navale o del tris, le tabelline, i pixel di un'immagine... La struttura che rappresenta una tabella si chiama **matrice**.

## 1. Le matrici come liste di liste

In Python non esiste un tipo "matrice" predefinito: una matrice si rappresenta come una **lista di liste**, dove ogni lista interna è una **riga**.

```python
mat = [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12]
]
```

Questa matrice ha **3 righe e 4 colonne** (si dice che è una matrice 3 × 4). Graficamente:

```text
           colonna 0  colonna 1  colonna 2  colonna 3
riga 0         1          2          3          4
riga 1         5          6          7          8
riga 2         9         10         11         12
```

### Accesso agli elementi
Per accedere a un elemento servono **due indici**: prima quello della **riga**, poi quello della **colonna**.

```python
print(mat[1][2])    # 7: riga 1, colonna 2
mat[0][0] = 100     # modifica dell'elemento in alto a sinistra
print(mat[1])       # [5, 6, 7, 8]: l'intera riga 1
print(mat[-1][-1])  # 12: l'ultimo elemento dell'ultima riga
```

Il funzionamento di `mat[1][2]` è semplice se lo si legge in due passi: `mat[1]` è la lista `[5, 6, 7, 8]`, e `[2]` prende l'elemento di indice 2 di quella lista.

### Dimensioni
```python
righe = len(mat)        # numero di righe: 3
colonne = len(mat[0])   # numero di colonne (lunghezza della prima riga): 4
```

Di solito le variabili che indicano riga e colonna si chiamano `i` e `j`, mentre il numero di righe e di colonne si indica con `n` e `m`.

## 2. Creare una matrice

### Con due cicli e `append`
Il metodo più leggibile: si crea ogni riga come lista vuota, la si riempie, e la si aggiunge alla matrice.

```python
n = 3   # righe
m = 4   # colonne
mat = []
for i in range(n):
    riga = []
    for j in range(m):
        riga.append(0)
    mat.append(riga)
```

### Con una list comprehension
Le due list comprehension annidate fanno la stessa cosa in una riga. Quella **esterna** genera le righe, quella **interna** gli elementi di ogni riga.

```python
from random import randint

zeri = [[0 for j in range(m)] for i in range(n)]
casuale = [[randint(1, 99) for _ in range(m)] for _ in range(n)]
tabelline = [[(i + 1) * (j + 1) for j in range(10)] for i in range(10)]
```

:::danger[La trappola della moltiplicazione di liste]
Sembrerebbe un modo furbo di creare una matrice di zeri, ma **non funziona**:
```python
mat = [[0] * 3] * 3
mat[0][0] = 5
print(mat)    # [[5, 0, 0], [5, 0, 0], [5, 0, 0]]  ?!
```
L'operatore `*` sulla lista esterna non crea 3 righe diverse, ma ripete 3 volte il **riferimento alla stessa riga** (ricordate la sezione [Riferimenti e copie](../liste/#10-riferimenti-e-copie) delle liste). Modificando una riga si modificano "tutte", perché in realtà è una sola.

In realtà `[0] * m` per creare la singola riga funzionerebbe, perché gli elementi ripetuti sono numeri (immutabili). Ma ricordarsi quando `*` è sicuro e quando no è scomodo e facile da sbagliare: **nel dubbio usate sempre la list comprehension**, che crea ogni volta un oggetto nuovo e funziona in ogni caso:

```python
mat = [[0 for _ in range(m)] for _ in range(n)]
```
:::

### Lettura da input
```python
n = int(input("Numero di righe: "))
m = int(input("Numero di colonne: "))
mat = []
for i in range(n):
    riga = []
    for j in range(m):
        riga.append(int(input(f"Elemento [{i}][{j}]: ")))
    mat.append(riga)
```

### Copiare una matrice
Come per le liste, l'assegnamento `copia = mat` non copia nulla: crea solo un secondo nome per la stessa matrice (vedi [Riferimenti e copie](../liste/#10-riferimenti-e-copie)). Ma con le matrici **nemmeno `copy()` basta**:

```python
mat = [[1, 2], [3, 4]]
copia = mat.copy()
copia[0][0] = 99
print(mat)     # [[99, 2], [3, 4]]  ?! l'originale è cambiata
```

`mat.copy()` crea una nuova lista **esterna**, ma i suoi elementi sono i riferimenti alle **stesse righe** dell'originale:

```text
mat   ──► [ • , • ]
            │   │
            ▼   ▼
          [1,2] [3,4]     ← righe condivise
            ▲   ▲
            │   │
copia ──► [ • , • ]
```

Bisogna copiare anche **ogni riga**. Si può fare con una list comprehension, oppure con la funzione `deepcopy` del modulo `copy`, che copia la struttura a qualsiasi livello di annidamento (*copia profonda*):

```python
copia = [riga.copy() for riga in mat]

# oppure
from copy import deepcopy
copia = deepcopy(mat)
```

È lo stesso problema della trappola `[[0] * m] * n` vista sopra: in entrambi i casi più "righe" sono in realtà la stessa lista.

## 3. Scorrere una matrice

Per visitare tutti gli elementi servono **due cicli annidati**: il ciclo esterno scorre le righe, quello interno le colonne.

### Con gli indici
```python
for i in range(len(mat)):
    for j in range(len(mat[i])):
        print(mat[i][j], end=" ")
    print()     # a capo alla fine di ogni riga
```

### Con gli elementi
Se non servono gli indici, si possono scorrere direttamente le righe e poi gli elementi di ogni riga:

```python
for riga in mat:
    for elemento in riga:
        print(elemento, end=" ")
    print()
```

### Stampa ben formattata
Con numeri di lunghezza diversa le colonne non risultano allineate. Si risolve con un formato a larghezza fissa nelle f-string (vedi gli [elementi di base](../elementi-di-base/#le-f-string)):

```python
for riga in mat:
    for num in riga:
        print(f"{num:3d}", end=" ")
    print()
```

```text
  1   2   3   4
  5   6   7   8
  9  10  11  12
```

### Scorrere per colonne
A volte serve visitare la matrice **colonna per colonna** (ad esempio per calcolare la media di ogni materia nel registro). Basta scambiare i due cicli: quello esterno scorre le colonne `j`, quello interno le righe `i`.

```python
n = len(mat)
m = len(mat[0])
for j in range(m):
    somma_colonna = 0
    for i in range(n):
        somma_colonna += mat[i][j]
    print(f"Somma della colonna {j}: {somma_colonna}")
```

## 4. Operazioni tipiche

### Una singola riga o una singola colonna
Una riga è già una lista, quindi su di essa si possono usare tutte le funzioni delle liste. Per una colonna invece bisogna prendere l'elemento `j` da ogni riga.

```python
r = 1
print(f"Riga {r}: {mat[r]}, somma {sum(mat[r])}")

c = 2
colonna = [riga[c] for riga in mat]
print(f"Colonna {c}: {colonna}, somma {sum(colonna)}")
```

### Somma di tutti gli elementi
```python
totale = 0
for riga in mat:
    for num in riga:
        totale += num
# oppure: totale = sum(sum(riga) for riga in mat)
```

### Massimo e sua posizione
```python
i_max, j_max = 0, 0
for i in range(len(mat)):
    for j in range(len(mat[i])):
        if mat[i][j] > mat[i_max][j_max]:
            i_max, j_max = i, j
print(f"Massimo {mat[i_max][j_max]} in riga {i_max}, colonna {j_max}")
```

### Le diagonali (matrici quadrate)
In una matrice **quadrata** (`n` righe e `n` colonne) si definiscono due diagonali:

*   la **diagonale principale**, dall'angolo in alto a sinistra a quello in basso a destra: sono gli elementi in cui **`i == j`**;
*   la **diagonale secondaria**, dall'angolo in alto a destra a quello in basso a sinistra: sono gli elementi in cui **`i + j == n - 1`**, cioè `j = n - 1 - i`.

```text
 principale            secondaria
[X . . .]              [. . . X]
[. X . .]              [. . X .]
[. . X .]              [. X . .]
[. . . X]              [X . . .]
```

Per visitarle basta un **solo ciclo**:

```python
n = len(mat)
principale = [mat[i][i] for i in range(n)]
secondaria = [mat[i][n - 1 - i] for i in range(n)]
```

### La trasposta
La **trasposta** di una matrice si ottiene scambiando le righe con le colonne: l'elemento `[i][j]` diventa l'elemento `[j][i]`. Una matrice `n × m` ha una trasposta `m × n`.

```python
n = len(mat)
m = len(mat[0])
trasposta = [[mat[i][j] for i in range(n)] for j in range(m)]
```

## 5. Celle adiacenti e controllo dei bordi

In moltissimi giochi su griglia (campo minato, gioco della vita, forza 4, ...) bisogna esaminare le celle **vicine** a una cella data. Le 8 celle che circondano la cella `(i, j)` si ottengono sommando a `i` e `j` uno spostamento di -1, 0 o +1:

```text
(i-1, j-1)  (i-1, j)  (i-1, j+1)
(i,   j-1)  (i,   j)  (i,   j+1)
(i+1, j-1)  (i+1, j)  (i+1, j+1)
```

Il problema sono le celle sul **bordo** della matrice, i cui vicini possono cadere fuori. Se l'indice sfora a destra o in basso si ottiene un `IndexError`; se diventa `-1`, invece, **Python non dà errore** ma prende l'ultima riga o colonna (indici negativi!), producendo risultati sbagliati senza alcun avviso. Per questo bisogna sempre controllare che gli indici siano validi:

```python
def conta_vicini(mat, i, j, valore):
    """Conta quante delle celle adiacenti a (i, j) contengono il valore indicato."""
    n = len(mat)
    m = len(mat[0])
    conta = 0
    for di in range(-1, 2):
        for dj in range(-1, 2):
            if di == 0 and dj == 0:
                continue                  # salto la cella stessa
            ni = i + di
            nj = j + dj
            if 0 <= ni < n and 0 <= nj < m and mat[ni][nj] == valore:
                conta += 1
    return conta
```

## 6. Matrici "miste"

Le righe di una matrice possono contenere dati di tipo diverso. È un modo semplice per rappresentare una tabella di dati in cui ogni riga descrive un oggetto e ogni colonna una sua caratteristica, come in un foglio di calcolo:

```python
studenti = [
    ["Anna",  "Rossi",   7.5],
    ["Luca",  "Bianchi", 6.0],
    ["Marta", "Verdi",   8.5],
]

for nome, cognome, media in studenti:
    print(f"{nome:<8}{cognome:<10}{media:5.1f}")
```

Notate come nel `for` ogni riga venga spacchettata direttamente nelle tre variabili `nome`, `cognome` e `media`.

Con questo tipo di dati però bisogna ricordarsi a memoria che la colonna 2 è la media, la 0 il nome e così via. Quando i dati diventano più complessi, conviene usare i [dizionari](../dizionari/), che permettono di accedere ai valori con un nome invece che con un numero.

## Esercizi

Gli esercizi relativi a questi argomenti si trovano nel capitolo **"Strutture dati fondamentali"** dell'eserciziario (sezioni *Matrici di soli numeri* e *Matrici miste*), linkato nella [pagina introduttiva](../programmazione-in-python/).
