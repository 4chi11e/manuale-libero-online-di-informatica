---
title: Strutture di controllo
description: Condizioni, selezione con if/elif/else, cicli while e for, break e continue e gli schemi algoritmici più comuni
---

Finora i nostri programmi eseguivano le istruzioni una dopo l'altra, sempre tutte e sempre nello stesso ordine. Per risolvere problemi reali però un programma deve saper **prendere decisioni** e **ripetere operazioni**. Gli strumenti che permettono di farlo si chiamano **strutture di controllo**.

Un importante risultato dell'informatica teorica (il *teorema di Böhm-Jacopini*) afferma che **qualsiasi algoritmo** può essere scritto usando soltanto tre strutture:

1.  **Sequenza**: istruzioni eseguite una dopo l'altra (quello che abbiamo fatto finora);
2.  **Selezione**: si sceglie quali istruzioni eseguire in base a una condizione (`if`);
3.  **Iterazione**: si ripete un gruppo di istruzioni finché serve (`while`, `for`).

## 1. Condizioni ed espressioni booleane

Una **condizione** è un'espressione che può essere solo vera (`True`) o falsa (`False`). Le condizioni più semplici si ottengono con gli **operatori di confronto**:

| Operatore | Significato | Esempio | Risultato |
|---|---|---|---|
| `==` | uguale a | `5 == 5` | `True` |
| `!=` | diverso da | `5 != 3` | `True` |
| `<` | minore di | `5 < 3` | `False` |
| `>` | maggiore di | `5 > 3` | `True` |
| `<=` | minore o uguale | `5 <= 5` | `True` |
| `>=` | maggiore o uguale | `3 >= 5` | `False` |

:::caution[= e == sono cose diverse]
`=` è l'**assegnamento** (mette un valore in una variabile), `==` è il **confronto** (chiede se due valori sono uguali). Scrivere `if x = 5:` è un errore di sintassi.
:::

### Operatori logici
Più condizioni si possono combinare con gli **operatori logici** `and`, `or` e `not`:

| Operatore | Il risultato è `True` se... | Esempio |
|---|---|---|
| `a and b` | **entrambe** le condizioni sono vere | `voto >= 6 and voto <= 10` |
| `a or b` | **almeno una** delle condizioni è vera | `x < 0 or x > 100` |
| `not a` | la condizione è falsa | `not (x == 0)` |

Python permette anche di scrivere i confronti "a catena" come in matematica: `6 <= voto <= 10` equivale a `voto >= 6 and voto <= 10`.

```python
voto = 7
print(voto >= 6)              # True
print(6 <= voto <= 10)        # True
print(voto < 1 or voto > 10)  # False: il voto è valido
```

## 2. L'indentazione: i blocchi di codice

Prima di vedere le strutture di controllo dobbiamo capire come Python raggruppa le istruzioni in **blocchi**. In C i blocchi sono delimitati dalle parentesi graffe `{ }`, in Python invece si usa l'**indentazione**, cioè il rientro delle righe verso destra:

*   la riga che "apre" un blocco (ad esempio un `if`) termina con i **due punti** `:`;
*   tutte le istruzioni che fanno parte del blocco sono **rientrate** dello stesso numero di spazi (lo standard è **4 spazi**, che VS Code inserisce automaticamente premendo Tab);
*   il blocco finisce quando si torna al livello di rientro precedente.

```python
if x > 0:
    print("x è positivo")       # dentro l'if
    print("lo stampo solo se x > 0")  # dentro l'if
print("questo lo stampo sempre")      # fuori dall'if
```

L'indentazione **non è solo estetica**: cambia il significato del programma. Un rientro sbagliato causa un `IndentationError`, o peggio, un programma che funziona in modo diverso da quello che volevamo.

## 3. La selezione: `if`, `else`, `elif`

### `if` semplice
Le istruzioni del blocco vengono eseguite **solo se** la condizione è vera; altrimenti vengono saltate.

```python
n = int(input("Scrivi un numero: "))
if n < 0:
    n = -n
print(f"Il valore assoluto è {n}")
```

### `if` - `else`
Con `else` indichiamo cosa fare quando la condizione è **falsa**. Viene eseguito sempre **uno solo** dei due blocchi.

```python
num = float(input("Scrivi il valore del numeratore: "))
den = float(input("Scrivi il valore del denominatore: "))
if den == 0:
    print("Non è possibile dividere per 0")
else:
    print(f"{num} / {den} = {num / den}")
```

### `if` - `elif` - `else`
Quando le alternative sono più di due si usa `elif` (contrazione di *else if*). Le condizioni vengono controllate **in ordine, dall'alto verso il basso**: viene eseguito il blocco della **prima** condizione vera e tutte le altre vengono ignorate. Il blocco `else` finale (facoltativo) viene eseguito se nessuna condizione è vera.

```python
voto = float(input("Inserisci la media: "))
if voto >= 6:
    print("Promosso")
elif voto >= 5:
    print("Rimandato")
else:
    print("Bocciato")
```

Notate che nel secondo controllo non serve scrivere `voto >= 5 and voto < 6`: se il programma arriva lì, sappiamo già che la prima condizione era falsa, quindi `voto` è sicuramente minore di 6.

### `if` annidati
Dentro un blocco si può mettere qualsiasi istruzione, compreso un altro `if`. Si parla allora di `if` **annidati**:

```python
a = float(input("Lato a: "))
b = float(input("Lato b: "))
c = float(input("Lato c: "))

if a < b + c and b < a + c and c < a + b:
    if a == b == c:
        print("Triangolo equilatero")
    elif a == b or b == c or a == c:
        print("Triangolo isoscele")
    else:
        print("Triangolo scaleno")
else:
    print("Con questi lati non si può costruire un triangolo")
```

:::tip
Prima di annidare tanti `if`, chiedetevi se le condizioni si possono combinare con `and`/`or` o riorganizzare con `elif`: il codice risulta quasi sempre più leggibile.
:::

## 4. Il ciclo `while`

Il ciclo `while` ripete un blocco di istruzioni **finché la condizione è vera**. Prima di ogni ripetizione (detta *iterazione*) la condizione viene ricontrollata: appena diventa falsa, il ciclo termina e il programma prosegue con le istruzioni successive.

```python
contatore = 1
while contatore <= 5:
    print(contatore)
    contatore += 1
print("Fine!")
```

```text
1
2
3
4
5
Fine!
```

Se la condizione è falsa fin dall'inizio, il blocco non viene eseguito **nemmeno una volta**.

:::danger[Il ciclo infinito]
Se all'interno del ciclo nessuna istruzione modifica le variabili della condizione, la condizione resterà vera per sempre e il programma non terminerà mai. Ad esempio, dimenticando `contatore += 1` nell'esempio sopra si stamperebbe `1` all'infinito. Se succede, si può interrompere il programma dal terminale con **Ctrl + C**.
:::

Il `while` è il ciclo giusto quando **non sappiamo in anticipo quante volte** bisognerà ripetere. Due casi tipici:

### Controllo dell'input
Chiedere un valore finché l'utente non ne inserisce uno valido:

```python
n = int(input("Scrivi un numero positivo: "))
while n <= 0:
    n = int(input("Il numero deve essere positivo, riprova: "))
```

### Sequenza terminata da un valore speciale
Leggere numeri finché l'utente non inserisce 0 (il cosiddetto *valore sentinella*):

```python
somma = 0
quanti = 0
n = int(input("Inserisci un numero (0 per terminare): "))
while n != 0:
    somma += n
    quanti += 1
    n = int(input("Inserisci un numero (0 per terminare): "))
print(f"Hai inserito {quanti} numeri, la loro somma è {somma}")
```

Notate lo schema: si legge il primo valore **prima** del ciclo, e il successivo **alla fine** di ogni iterazione, così che il controllo avvenga sempre sul valore appena letto.

## 5. Il ciclo `for` e la funzione `range`

Il ciclo `for` serve a ripetere un blocco **per ogni elemento** di una sequenza. La sequenza più usata è quella prodotta dalla funzione `range`, che genera una serie di numeri interi:

```python
for i in range(5):
    print(i)
```

```text
0
1
2
3
4
```

A ogni iterazione la variabile `i` (chiamata **variabile di ciclo**) assume il valore successivo della sequenza. `range` può ricevere uno, due o tre parametri:

| Chiamata | Numeri generati | Note |
|---|---|---|
| `range(5)` | 0, 1, 2, 3, 4 | da 0 fino a 5 **escluso** |
| `range(2, 6)` | 2, 3, 4, 5 | da 2 (incluso) a 6 (**escluso**) |
| `range(0, 10, 2)` | 0, 2, 4, 6, 8 | il terzo parametro è il passo |
| `range(10, 0, -1)` | 10, 9, 8, ..., 1 | con passo negativo si conta all'indietro |
| `range(10, 0, -3)` | 10, 7, 4, 1 | |

:::caution[Il secondo estremo è sempre escluso]
`range(1, 10)` arriva fino a **9**. Per contare da 1 a `n` compreso bisogna scrivere `range(1, n + 1)`. Allo stesso modo, per contare all'indietro da `n` fino a 0 compreso si scrive `range(n, -1, -1)`.
:::

Esempio: moltiplicazione di due numeri usando solo le somme.

```python
n1 = int(input("Scrivi il primo numero: "))
n2 = int(input("Scrivi il secondo numero: "))
risultato = 0
for i in range(n2):
    risultato += n1
print(f"{n1} * {n2} = {risultato}")
```

Quando la variabile di ciclo non serve all'interno del blocco, per convenzione la si chiama `_`:

```python
for _ in range(3):
    print("Ciao!")
```

Il `for` non funziona solo con `range`: si può usare per scorrere i caratteri di una stringa, e soprattutto gli elementi di una [lista](../liste/) o le chiavi di un [dizionario](../dizionari/), come vedremo.

```python
for lettera in "ciao":
    print(lettera)
```

### `for` o `while`?
Qualsiasi ciclo `for` si può riscrivere con un `while` (ma non sempre il contrario in modo comodo). Come regola pratica:

*   usate il **`for`** quando sapete **quante volte** ripetere (o quali elementi scorrere) prima di iniziare il ciclo;
*   usate il **`while`** quando il numero di ripetizioni dipende da qualcosa che si scopre **durante** il ciclo (un input dell'utente, un risultato che deve raggiungere una certa soglia...).

## 6. `break` e `continue`

Due istruzioni permettono di modificare il normale funzionamento di un ciclo:

*   **`break`** interrompe immediatamente il ciclo e il programma prosegue dopo di esso;
*   **`continue`** salta il resto dell'iterazione corrente e passa direttamente alla successiva.

```python
for i in range(1, 11):
    if i % 3 == 0:
        continue      # salto i multipli di 3
    if i == 8:
        break         # arrivato a 8 mi fermo
    print(i, end=" ")
```

```text
1 2 4 5 7
```

Un uso frequente di `break` è il ciclo `while True`, che sarebbe infinito ma viene interrotto dall'interno quando si verifica una certa condizione:

```python
from random import randint

segreto = randint(1, 100)
tentativi = 0
while True:
    n = int(input("Indovina il numero (1-100): "))
    tentativi += 1
    if n < segreto:
        print("Troppo basso!")
    elif n > segreto:
        print("Troppo alto!")
    else:
        break
print(f"Bravo! Hai indovinato in {tentativi} tentativi")
```

:::tip
`break` e `continue` sono comodi, ma non abusatene: un ciclo con tanti punti di uscita diventa difficile da seguire. Spesso basta scrivere bene la condizione del `while`.
:::

## 7. Cicli annidati

Come per gli `if`, all'interno di un ciclo si può inserire un altro ciclo. Il ciclo interno viene eseguito **completamente a ogni iterazione** del ciclo esterno.

```python
n = 4
for i in range(n):          # righe
    for j in range(n):      # colonne
        print("*", end=" ")
    print()                 # a capo alla fine di ogni riga
```

```text
* * * *
* * * *
* * * *
* * * *
```

Facendo dipendere il ciclo interno dalla variabile del ciclo esterno si ottengono figure diverse, ad esempio un triangolo:

```python
n = 4
for i in range(1, n + 1):
    for j in range(i):
        print("*", end=" ")
    print()
```

```text
*
* *
* * *
* * * *
```

I cicli annidati sono indispensabili per lavorare con le [matrici](../matrici/).

## 8. Schemi ricorrenti

Moltissimi esercizi si risolvono combinando pochi "schemi" di base. Imparare a riconoscerli è la chiave per diventare veloci a programmare.

### Contatore
Una variabile che parte da 0 e viene incrementata di 1 ogni volta che si verifica qualcosa.

```python
pari = 0
for i in range(10):
    n = int(input("Numero: "))
    if n % 2 == 0:
        pari += 1
print(f"Hai inserito {pari} numeri pari")
```

### Accumulatore (somma e prodotto)
Una variabile in cui si "accumulano" i valori. Per la somma si parte da **0**, per il prodotto da **1** (l'elemento neutro dell'operazione).

```python
n = int(input("Calcola il fattoriale di: "))
fattoriale = 1
for i in range(2, n + 1):
    fattoriale *= i
print(f"{n}! = {fattoriale}")
```

### Massimo e minimo
Si tiene in una variabile il "miglior candidato" trovato finora e lo si aggiorna ogni volta che se ne trova uno migliore. Il valore iniziale è il **primo elemento** della sequenza.

```python
quanti = int(input("Quanti numeri vuoi inserire? "))
n = int(input("Numero: "))
massimo = n
for _ in range(quanti - 1):
    n = int(input("Numero: "))
    if n > massimo:
        massimo = n
print(f"Il massimo è {massimo}")
```

:::caution
Non inizializzate il massimo a 0: se l'utente inserisce solo numeri negativi, il risultato sarebbe sbagliato!
:::

### Flag (variabile booleana)
Una variabile `True`/`False` che "ricorda" se si è verificato un certo evento. Esempio: verificare se un numero è primo.

```python
n = int(input("Scrivi un numero: "))
primo = n >= 2              # 0 e 1 non sono primi
for d in range(2, n):
    if n % d == 0:          # ho trovato un divisore
        primo = False
        break               # inutile continuare a cercare
if primo:
    print(f"{n} è primo")
else:
    print(f"{n} non è primo")
```

### Scomporre un numero nelle sue cifre
Con `% 10` si ottiene l'ultima cifra, con `// 10` la si elimina. Ripetendo finché il numero non diventa 0 si analizzano tutte le cifre:

```python
n = int(input("Scrivi un numero intero positivo: "))
somma_cifre = 0
while n > 0:
    cifra = n % 10
    somma_cifre += cifra
    n //= 10
print(f"La somma delle cifre è {somma_cifre}")
```

## Esercizi

Gli esercizi relativi a questi argomenti si trovano nel capitolo **"Algoritmi e strutture di controllo"** dell'eserciziario, linkato nella [pagina introduttiva](../programmazione-in-python/).
