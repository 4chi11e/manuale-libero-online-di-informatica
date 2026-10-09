---
title: Dizionari
description: I dizionari in Python, coppie chiave-valore, accesso, modifica, scorrimento, conteggio delle frequenze e strutture annidate
---

Con le [liste](../liste/) accediamo agli elementi tramite la loro **posizione**: `voti[3]`. In molte situazioni però sarebbe molto più naturale accedere a un dato tramite un **nome**: il numero di telefono di "Marco", il prezzo del "caffè", i punti dell'"Inter"... Per questo esistono i **dizionari**.

## 1. Cos'è un dizionario

Un **dizionario** è una raccolta di coppie **chiave → valore**. Proprio come in un dizionario vero si cerca una parola (la chiave) per trovarne la definizione (il valore), in un dizionario Python si usa la chiave per ottenere il valore associato.

Si crea con le parentesi graffe, scrivendo le coppie nella forma `chiave: valore` separate da virgole:

```python
prezzi = {"caffè": 1.20, "cappuccino": 1.50, "cornetto": 1.30}
eta = {"Anna": 16, "Luca": 17, "Marta": 16}
vuoto = {}

print(prezzi)
print(len(prezzi))    # 3: il numero di coppie
```

Le regole fondamentali:

*   le **chiavi sono uniche**: non possono esistere due coppie con la stessa chiave (i valori invece possono ripetersi, come i 16 anni di Anna e Marta);
*   le chiavi devono essere di un tipo **immutabile**: tipicamente stringhe o numeri, ma anche tuple. Le liste **non** possono essere chiavi;
*   i **valori** possono essere di qualsiasi tipo: numeri, stringhe, liste, persino altri dizionari;
*   le coppie mantengono l'ordine in cui sono state inserite, ma **non** si accede a esse per posizione: `prezzi[0]` non è il primo elemento, ma il valore associato alla chiave `0` (che qui non esiste).

## 2. Accedere ai valori

Si accede a un valore scrivendo la chiave tra parentesi quadre:

```python
print(prezzi["caffè"])     # 1.2
print(eta["Luca"])         # 17
```

Se la chiave non esiste si ottiene un errore `KeyError`:

```python
print(prezzi["tè"])        # KeyError: 'tè'
```

Per evitarlo si può prima controllare che la chiave sia presente con l'operatore `in`, oppure usare il metodo `get`, che restituisce `None` (o un valore di default a scelta) invece di generare un errore:

```python
if "tè" in prezzi:
    print(prezzi["tè"])
else:
    print("Il tè non è nel listino")

print(prezzi.get("tè"))        # None
print(prezzi.get("tè", 0))     # 0: valore di default
```

:::note
L'operatore `in` sui dizionari controlla le **chiavi**, non i valori: `"caffè" in prezzi` è `True`, mentre `1.20 in prezzi` è `False`.
:::

## 3. Aggiungere, modificare ed eliminare

Per **aggiungere** una coppia basta assegnare un valore a una chiave nuova; se la chiave esiste già, il suo valore viene **sostituito**. La sintassi è la stessa in entrambi i casi.

```python
prezzi["tè"] = 1.40          # la chiave non c'era: viene aggiunta
prezzi["caffè"] = 1.30       # la chiave c'era: il valore viene aggiornato
prezzi["cornetto"] += 0.10   # aumento il prezzo del cornetto
```

Per **eliminare** una coppia:

```python
del prezzi["tè"]               # elimina la coppia (KeyError se non esiste)
p = prezzi.pop("cappuccino")   # elimina la coppia e ne restituisce il valore
```

## 4. Scorrere un dizionario

Un ciclo `for` su un dizionario scorre le sue **chiavi**:

```python
for prodotto in prezzi:
    print(f"{prodotto}: {prezzi[prodotto]:.2f} €")
```

Esistono tre metodi che permettono di scegliere cosa scorrere:

| Metodo | Restituisce | Esempio |
|---|---|---|
| `d.keys()` | le chiavi | `for k in d.keys():` (equivale a `for k in d:`) |
| `d.values()` | i valori | `for v in d.values():` |
| `d.items()` | le coppie (chiave, valore) | `for k, v in d.items():` |

Il metodo `items()` è il più comodo quando servono sia la chiave sia il valore:

```python
for prodotto, prezzo in prezzi.items():
    print(f"{prodotto:<12}{prezzo:6.2f} €")
```

Con `values()` si possono usare direttamente le funzioni viste per le liste:

```python
media_eta = sum(eta.values()) / len(eta)
piu_vecchio = max(eta.values())
```

:::caution
Non si possono aggiungere o eliminare chiavi da un dizionario mentre lo si scorre con un `for`: Python genera un errore `RuntimeError`. Modificare i **valori** delle chiavi esistenti invece è permesso.
:::

## 5. Lo schema del conteggio

Il dizionario è lo strumento perfetto per **contare quante volte compare** ogni elemento di una sequenza. Lo schema è sempre lo stesso: per ogni elemento, se è già una chiave del dizionario se ne incrementa il contatore, altrimenti lo si aggiunge con contatore 1.

```python
def frequenze(sequenza):
    d = {}
    for elemento in sequenza:
        if elemento in d:
            d[elemento] += 1
        else:
            d[elemento] = 1
    return d

print(frequenze("abracadabra"))
# {'a': 5, 'b': 2, 'r': 2, 'c': 1, 'd': 1}

print(frequenze([3, 1, 3, 3, 2, 1]))
# {3: 3, 1: 2, 2: 1}
```

Usando `get` con valore di default 0, il corpo del ciclo si riduce a una sola riga:

```python
for elemento in sequenza:
    d[elemento] = d.get(elemento, 0) + 1
```

Una volta costruito il dizionario delle frequenze, trovare l'elemento più frequente è una semplice ricerca del massimo:

```python
d = frequenze([3, 1, 3, 3, 2, 1])
piu_frequente = None
freq_max = 0
for elemento, freq in d.items():
    if freq > freq_max:
        piu_frequente = elemento
        freq_max = freq
print(f"{piu_frequente} compare {freq_max} volte")   # 3 compare 3 volte
```

Provate a risolvere lo stesso problema usando solo le liste: vi renderete conto di quanto il dizionario semplifichi le cose!

## 6. Strutture annidate

Siccome i valori possono essere di qualsiasi tipo, liste e dizionari si possono combinare per rappresentare dati anche complessi.

### Dizionario di liste
Ad esempio, i voti di ogni studente:

```python
voti = {
    "Anna": [7, 8, 6.5],
    "Luca": [5, 6, 7],
}
voti["Anna"].append(9)         # aggiungo un voto ad Anna
voti["Marta"] = []             # nuova studentessa, ancora senza voti

for nome, lista_voti in voti.items():
    if len(lista_voti) > 0:
        print(f"{nome}: media {sum(lista_voti) / len(lista_voti):.2f}")
    else:
        print(f"{nome}: nessun voto")
```

### Lista di dizionari
Ogni dizionario rappresenta un "oggetto" con le sue caratteristiche (come una riga di una tabella di un database), e la lista li raccoglie tutti. È l'alternativa più leggibile alle [matrici miste](../matrici/#6-matrici-miste): si scrive `studente["media"]` invece di `studente[2]`.

```python
studenti = [
    {"nome": "Anna",  "cognome": "Rossi",   "media": 7.5},
    {"nome": "Luca",  "cognome": "Bianchi", "media": 6.0},
    {"nome": "Marta", "cognome": "Verdi",   "media": 8.5},
]

for s in studenti:
    if s["media"] >= 7:
        print(s["nome"], s["cognome"])
```

### Dizionario di dizionari
Ogni oggetto è identificato da una chiave (ad esempio il nome di una squadra) e descritto da un dizionario:

```python
classifica = {
    "Inter":       {"punti": 10, "gol_fatti": 8, "gol_subiti": 3},
    "Real Madrid": {"punti": 12, "gol_fatti": 13, "gol_subiti": 4},
}
classifica["Inter"]["punti"] += 3
print(classifica["Inter"]["punti"])     # 13
```

## 7. Ordinare un dizionario

I dizionari non hanno un metodo `sort()`: l'ordinamento è un'operazione che riguarda le sequenze, cioè le liste. Il metodo generale, che funziona **in ogni caso**, è quindi:

1.  **trasformare** il dizionario in una lista;
2.  **ordinare** la lista, indicando se serve in base a cosa ordinare con una funzione *lambda*.

### Passo 1: dal dizionario alla lista
Il metodo `items()` fornisce le coppie (chiave, valore), che `list()` raccoglie in una lista di tuple:

```python
punti = {"Inter": 10, "Real Madrid": 12, "Milan": 10, "Sheriff": 6}
classifica = list(punti.items())
print(classifica)
# [('Inter', 10), ('Real Madrid', 12), ('Milan', 10), ('Sheriff', 6)]
```

Da qui in poi lavoriamo con una normale lista, e possiamo usare tutto quello che sappiamo sulle [liste](../liste/).

### Passo 2: ordinare la lista
Se chiamiamo `sort()` senza parametri, le tuple vengono confrontate a partire dal primo elemento, cioè la chiave: otteniamo l'ordine alfabetico delle squadre.

```python
classifica.sort()
# [('Inter', 10), ('Milan', 10), ('Real Madrid', 12), ('Sheriff', 6)]
```

Se invece vogliamo ordinare in base ai punti, dobbiamo dire a `sort()` **quale valore guardare** quando confronta due elementi.

Ricordiamo prima com'è fatto ogni elemento della lista: è una coppia formata dalla chiave e dal valore del dizionario, cioè dal nome della squadra e dai suoi punti.

```python
elemento = classifica[0]   # ('Inter', 10)
print(elemento[0])         # Inter  → in posizione 0 c'è il nome della squadra
print(elemento[1])         # 10     → in posizione 1 ci sono i punti
```

Quindi, preso un elemento qualsiasi della lista, i punti si trovano in posizione **1**.

Per dire a `sort()` di usare i punti si usa il parametro `key`, a cui passiamo una funzione scritta da noi: questa funzione riceve **un elemento** della lista e **restituisce il valore** da usare per il confronto. Nel nostro caso, riceve una coppia e restituisce i suoi punti:

```python
def prendi_punti(x):
    return x[1]

classifica.sort(key = prendi_punti)
```

`x` è il nome del parametro, e rappresenta **un generico elemento della lista**, cioè una coppia (squadra, punti). Visto che vogliamo ordinare per punti, la funzione restituisce `x[1]`. Se volessimo ordinare per nome restituirebbe `x[0]`.

`sort()` chiama `prendi_punti` su ogni elemento della lista e ottiene:

```text
('Inter', 10)        →  10
('Milan', 10)        →  10
('Real Madrid', 12)  →  12
('Sheriff', 6)       →   6
```

poi ordina gli elementi in base a questi numeri:

```python
# [('Sheriff', 6), ('Inter', 10), ('Milan', 10), ('Real Madrid', 12)]
```

Notate che si scrive `key = prendi_punti` **senza parentesi**: non stiamo chiamando la funzione, la stiamo consegnando a `sort()`, che la chiamerà da sé per ogni elemento.

### Le funzioni lambda
Definire con `def` una funzione di una sola riga, solo per usarla in un `sort()`, è scomodo. Python permette di scriverla direttamente dentro la chiamata, con la parola chiave `lambda`:

```python
classifica.sort(key = lambda x: x[1])
```

`lambda x: x[1]` si legge "una funzione che riceve `x` e restituisce `x[1]`": è **identica** a `prendi_punti`, solo che non ha un nome e non serve scrivere `return` (il valore dopo i due punti viene restituito automaticamente).

```text
def prendi_punti(x):
    return x[1]          ⟶     lambda x: x[1]
```

### Ordine decrescente e più criteri
Per una classifica serve l'ordine **decrescente**. Il modo più semplice è far restituire alla lambda il valore **cambiato di segno**: ordinando in modo crescente i valori `-12, -10, -10, -6` si ottengono i punti dal più alto al più basso.

```python
classifica.sort(key = lambda x: -x[1])
```

Se la lambda restituisce una **tupla**, l'ordinamento avviene per più criteri: si confronta il primo valore e, solo in caso di parità, il secondo. Ad esempio per punti decrescenti e, a parità di punti, nome in ordine alfabetico:

```python
classifica.sort(key = lambda x: (-x[1], x[0]))

for squadra, p in classifica:
    print(f"{squadra:<12}{p:3d}")
```

```text
Real Madrid  12
Inter        10
Milan        10
Sheriff       6
```

:::tip
Esiste anche il parametro `reverse = True`, che inverte l'intero ordinamento. Il segno meno però è più flessibile, perché permette di avere un criterio decrescente e uno crescente nella stessa tupla, come nell'esempio sopra. Il segno meno funziona solo con i numeri: non si può scrivere `-x[0]` se `x[0]` è una stringa.
:::

### Perché questo metodo funziona sempre
Una volta ottenuta la lista, la lambda può restituire **qualsiasi cosa** calcolata a partire dall'elemento. Ad esempio, con un dizionario di dizionari si può ordinare per punti e, a parità, per differenza reti:

```python
squadre = {
    "Inter":       {"punti": 10, "gol_fatti": 8,  "gol_subiti": 3},
    "Real Madrid": {"punti": 12, "gol_fatti": 13, "gol_subiti": 4},
    "Milan":       {"punti": 10, "gol_fatti": 6,  "gol_subiti": 4},
}

classifica = list(squadre.items())
# ogni elemento è una coppia (nome, dizionario_dei_dati)
classifica.sort(key = lambda x: (-x[1]["punti"], -(x[1]["gol_fatti"] - x[1]["gol_subiti"])))
```

Lo stesso vale se la lista viene costruita in modo diverso, ad esempio con una list comprehension che aggiunge dati calcolati, come il totale dei voti di ogni studente:

```python
voti = {"Anna": [7, 8, 9], "Luca": [6, 5, 7], "Marta": [9, 9, 8]}
tabella = [[nome, v, sum(v)] for nome, v in voti.items()]
tabella.sort(key = lambda x: -x[2])
# [['Marta', [9, 9, 8], 26], ['Anna', [7, 8, 9], 24], ['Luca', [6, 5, 7], 18]]
```

Se alla fine serve di nuovo un dizionario, una lista di coppie ordinata si può ritrasformare con `dict(classifica)`: i dizionari mantengono l'ordine di inserimento.

### Scorciatoie
Una volta capito il metodo generale, si possono usare alcune forme più compatte:

*   `sorted()` accetta direttamente qualsiasi sequenza e restituisce una nuova lista ordinata, quindi fa i passi 1 e 2 in un colpo solo:
    ```python
    classifica = sorted(punti.items(), key = lambda x: -x[1])
    ```
*   se servono solo le **chiavi** in ordine alfabetico basta `sorted(punti)`, perché scorrere un dizionario significa scorrerne le chiavi:
    ```python
    for squadra in sorted(punti):
        print(squadra, punti[squadra])
    ```
*   per avere le **chiavi** ordinate in base ai **valori** si può passare come `key` il metodo `get` del dizionario stesso, che data una chiave restituisce il suo valore:
    ```python
    sorted(punti, key = punti.get, reverse = True)   # ['Real Madrid', 'Inter', 'Milan', 'Sheriff']
    ```

## 8. Liste o dizionari?

| | Lista | Dizionario |
|---|---|---|
| Accesso agli elementi | tramite **posizione** (indice intero) | tramite **chiave** (qualsiasi tipo immutabile) |
| Ordine | fondamentale: gli elementi hanno una posizione | conta poco: si cerca per chiave |
| Duplicati | ammessi | chiavi uniche (valori duplicabili) |
| Cercare un elemento | bisogna scorrere la lista (lento con tante voci) | immediato tramite la chiave (veloce anche con milioni di voci) |
| Esempi tipici | sequenza di voti, numeri letti in input, coda di attesa | rubrica, listino prezzi, conteggi, classifica |

Come regola pratica: se vi trovate a cercare continuamente un elemento scorrendo una lista, o a usare due liste "parallele" (una con i nomi e una con i valori corrispondenti), probabilmente vi serve un dizionario.

## Esercizi

Gli esercizi relativi a questi argomenti si trovano nel capitolo **"Dizionari"** dell'eserciziario, linkato nella [pagina introduttiva](../programmazione-in-python/).
