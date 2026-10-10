---
title: Stringhe
description: Le stringhe in Python, sequenze immutabili di caratteri, indicizzazione, slicing, metodi di ricerca e manipolazione, formattazione e conversioni.
---

Una **stringa** è una sequenza ordinata di caratteri utilizzata per rappresentare testo. In Python le stringhe sono uno dei tipi di dato più versatili e potenti, con a disposizione decine di metodi pronti all'uso per la ricerca, la trasformazione e la pulizia del testo.

Si possono definire racchiudendo il testo tra apici singoli `'...'` oppure apici doppi `"..."`:

```python
messaggio = "Ciao a tutti!"
linguaggio = 'Python'
vuota = ""    # stringa vuota (lunghezza 0)
```

I due tipi di apici sono del tutto equivalenti. La convenzione è usare gli apici doppi quando la stringa contiene un apostrofo interno, e viceversa:

```python
frase1 = "L'albero è alto"       # apici doppi per contenere l'apostrofo
frase2 = 'Ha detto: "Buongiorno"'  # apici singoli per contenere le virgolette
```

Per testi che si sviluppano su più righe si usano invece i **tripli apici** (`"""..."""` oppure `'''...'''`):

```python
poesia = """Nel mezzo del cammin di nostra vita
mi ritrovai per una selva oscura,
ché la diritta via era smarrita."""
```

All'interno di una stringa si possono inoltre inserire caratteri speciali preceduti dal carattere di escape `\`:
* `\n`: va a capo (newline);
* `\t`: inserisce una tabulazione orizzontale;
* `\\`: inserisce una barra rovesciata;
* `\'` o `\"`: inserisce l'apice corrispondente senza chiudere la stringa.

:::tip Per chi conosce il C
In C una stringa non è un tipo di dato primitivo, ma un array di `char` terminato dal carattere speciale `\0` (`char s[20] = "ciao";`). Bisognava calcolare in anticipo la dimensione della memoria e fare molta attenzione a non superare i confini dell'array (buffer overflow).

In Python il tipo `str` è un oggetto a tutti gli effetti: la memoria è gestita in modo completamente automatico, non esiste alcun terminatore `\0` esposto e la stringa può crescere o ridursi dinamicamente senza alcun rischio di sforare il buffer.
:::

---

## 1. Le stringhe come sequenze: indici e slicing

Nel capitolo precedente abbiamo studiato a fondo le [liste](../liste/). Dal punto di vista della struttura, una stringa in Python è a sua volta una **sequenza ordinata**: la differenza è che invece di contenere elementi di qualunque tipo, contiene singoli caratteri di testo.

Per questo motivo, **tutto ciò che abbiamo imparato su indici, scorrimento e slicing nelle liste vale identico per le stringhe**:

*   **Indici da `0` a `len(s) - 1`**: il primo carattere è `s[0]`, l'ultimo si trova a `s[len(s) - 1]`.
*   **Indici negativi**: contano dalla fine verso l'inizio; `s[-1]` è l'ultimo carattere, `s[-2]` il penultimo.
*   **Lunghezza**: la funzione `len(s)` restituisce il numero totale di caratteri.
*   **Scorrimento**: un ciclo `for c in s:` esamina i singoli caratteri in sequenza, mentre `for i, c in enumerate(s):` fornisce contemporaneamente l'indice e il carattere.
*   **Slicing `s[inizio:fine:passo]`**: estrae una porzione di testo includendo l'indice di `inizio` ed escludendo l'indice di `fine`. Omettendo gli estremi si intende l'inizio o la fine della stringa (`s[:4]`, `s[4:]`).
*   **Inversione**: il passo negativo `s[::-1]` restituisce la stringa rovesciata (utilissimo per verificare se una parola è palindroma).

Un esempio compatto:

```python
testo = "Informatica"

print(testo[0])       # 'I' (primo carattere)
print(testo[-1])      # 'a' (ultimo carattere con indice negativo)
print(len(testo))     # 11

# Slicing
print(testo[:4])      # 'Info' (dall'indice 0 al 3)
print(testo[4:])      # 'rmatica' (dall'indice 4 alla fine)
print(testo[2:6])     # 'form' (dall'indice 2 al 5)
print(testo[::2])     # 'Ifrtia' (un carattere ogni due)
print(testo[::-1])    # 'acitamrofnI' (stringa invertita)
```

:::note Caratteri singoli in Python
In linguaggi come il C o Java esiste un tipo dedicato per il singolo carattere (`char`). In Python no: un singolo carattere è semplicemente una stringa di lunghezza 1 (`type(testo[0])` è sempre `str`, con `len(testo[0]) == 1`).
:::

:::tip Per chi conosce il C
In C estrarre una sottostringa o invertire una stringa richiedeva di allocare un nuovo buffer, impostare un ciclo `for` con due indici e ricordarsi di aggiungere esplicitamente lo `\0` finale. In Python `s[::-1]` o `s[2:6]` creano una nuova stringa in una sola operazione.
:::

---

## 2. La differenza fondamentale: l'immutabilità

Le stringhe in Python sono **immutabili**: una volta creata, una stringa **non può mai essere modificata** nella memoria.

Se proviamo a cambiare un singolo carattere tramite indice, Python solleva un errore:

```python
saluto = "ciao"
saluto[0] = "C"   # TypeError: 'str' object does not support item assignment
```

### Perché sono immutabili?
1. **Sicurezza**: se una funzione riceve una stringa come parametro, abbiamo la certezza assoluta che il suo contenuto non verrà alterato all'insaputa del chiamante.
2. **Efficienza**: Python può ottimizzare l'uso della memoria riutilizzando le stesse stringhe in punti diversi del programma (meccanismo di *interning*).
3. **Uso come chiavi**: solo gli oggetti immutabili possono essere usati come chiavi nei [dizionari](../dizionari/) o come elementi nei set.

### Come si "modifica" una stringa?
Poiché l'oggetto originale non si può modificare, l'approccio standard consiste nel **costruire una nuova stringa** e, se serve, riassegnarla alla stessa variabile.

**1. Tramite slicing e concatenazione:**
```python
s = "ciao"
s = "C" + s[1:]    # prende 'C' e unisce 'iao'
print(s)           # 'Ciao'
```

**2. Tramite conversione in lista di caratteri:**
Se dobbiamo apportare molte modifiche a singoli caratteri, la tecnica più comoda ed efficiente consiste nel convertire la stringa in una lista (le cui celle sono mutabili) e poi ricongiungerla con `join()`:

```python
testo = "mela"

# 1. Convertiamo in lista di caratteri
caratteri = list(testo)    # ['m', 'e', 'l', 'a']

# 2. Modifichiamo la lista liberamente
caratteri[0] = 'p'
caratteri[2] = 'r'

# 3. Ricostruiamo la stringa
risultato = "".join(caratteri)
print(risultato)           # 'pera'
```

:::tip Per chi conosce il C
Questo è uno dei più grandi "trabocchetti" per chi viene dal C! In C le stringhe inizializzate come array (`char s[] = "ciao";`) sono mutabili e si scrive comunemente `s[0] = 'C'`. In Python dovete sempre pensare in termini di creazione di un nuovo valore.
:::

---

## 3. Costruire stringhe: concatenazione e f-string

Poiché le stringhe sono immutabili, ogni volta che vogliamo comporre un nuovo testo dobbiamo costruirlo combinando valori esistenti. In Python abbiamo due strumenti principali:

### 3.1 Concatenazione (`+`) e ripetizione (`*`)
L'operatore `+` unisce due o più stringhe in sequenza, mentre `*` ripete una stringa per un numero intero di volte:

```python
nome = "Mario"
cognome = "Rossi"

completo = nome + " " + cognome
print(completo)          # 'Mario Rossi'

separatore = "-" * 30
print(separatore)        # '------------------------------'
```

### 3.2 Le f-string (stringhe formattate)
Unire variabili ed espressioni con il `+` diventa rapidamente scomodo e farraginoso, soprattutto quando compaiono numeri da convertire esplicitamente con `str()`. Per questo motivo, come abbiamo già visto fin dai primi programmi negli [elementi di base](../elementi-di-base/#le-f-string), il modo standard e di gran lunga più comodo per inserire valori in un testo sono le **f-string**.

Basta anteporre la lettera `f` prima delle virgolette e racchiudere le variabili o le espressioni direttamente tra parentesi graffe `{}`.

:::note Non solo per la stampa: sono vere e proprie stringhe!
Un fraintendimento comune è pensare che le f-string siano una funzionalità esclusiva di `print()`. In realtà, una f-string **produce a tutti gli effetti un nuovo valore di tipo `str`**: possiamo quindi assegnarlo a una variabile, memorizzarlo in una lista o restituirlo da una funzione esattamente come qualsiasi altro testo.
:::

```python
nome = "Luca"
media = 7.625

# 1. Assegnamento a una variabile
scheda = f"Studente: {nome} - Media: {media:.2f}"
print(scheda)
print(type(scheda))    # <class 'str'>

# 2. Creazione di stringhe complesse (es. nomi di file o codici)
giorno, mese, anno = 10, 5, 2026
nome_file = f"backup_{anno}_{mese:02d}_{giorno:02d}.txt"
print(nome_file)       # 'backup_2026_05_10.txt'

# 3. Uso diretto dentro print() (il più immediato quando serve solo mostrare il testo a video)
a, b = 15, 4
print(f"La somma di {a} e {b} è {a + b}")
print(f"In maiuscolo: {nome.upper()}")
```

#### Controllo delle cifre decimali
Aggiungendo `:` seguito dalla specifica di formato possiamo decidere con precisione quante cifre decimali mostrare:

```python
pi_greco = 3.1415926535

print(f"{pi_greco:.2f}")     # '3.14'   (2 cifre decimali con arrotondamento)
print(f"{pi_greco:.4f}")     # '3.1416' (4 cifre decimali)
```

#### Allineamento e larghezza fissa (impaginazione a tabella)
Negli esercizi capita spesso di dover stampare report o tabelle in cui i dati devono risultare perfettamente allineati in colonne:

* `{valore:>N}`: allineato a **destra** su una colonna larga $N$ caratteri;
* `{valore:<N}`: allineato a **sinistra** su una colonna larga $N$ caratteri;
* `{valore:^N}`: **centrato** su una colonna larga $N$ caratteri.

```python
prodotti = [
    ("Quaderno", 12, 1.80),
    ("Penna blu", 150, 0.50),
    ("Zaino scuola", 5, 45.00)
]

print(f"{'Prodotto':<15} {'Qta':>5} {'Prezzo':>8}")
print("-" * 30)
for nome, qta, prezzo in prodotti:
    print(f"{nome:<15} {qta:>5} {prezzo:>7.2f}€")
```

Output:
```text
Prodotto          Qta   Prezzo
------------------------------
Quaderno           12    1.80€
Penna blu         150    0.50€
Zaino scuola        5   45.00€
```

:::tip Per chi conosce il C
Le f-string prendono il posto di `printf()` e `sprintf()` del C. La sintassi è enormemente più sicura e leggibile: invece di dover mantenere la corrispondenza mentale tra specificatori di formato sparsi nel testo (`%s`, `%d`, `%10.2f`) e la lista di variabili in coda, l'espressione da stampare si trova esattamente nel punto del testo in cui deve apparire.
:::

---

## 4. Confronti, ricerca base e codici ASCII

### 4.1 Appartenenza (`in` e `not in`)
Permette di verificare con facilità se una sottostringa è presente all'interno di un'altra:

```python
frase = "Il gatto dorme sul divano"

print("gatto" in frase)      # True
print("cane" in frase)       # False
print("div" in frase)        # True (cerca anche parti di parola)
print("cane" not in frase)   # True
```

### 4.2 Confronti lessicografici (`==`, `!=`, `<`, `>`, `<=`, `>=`)
L'operatore `==` confronta il **contenuto** effettivo delle due stringhe, non i loro indirizzi di memoria:

```python
s1 = "ciao"
s2 = "ci" + "ao"
print(s1 == s2)    # True
```

Gli operatori `<`, `>`, `<=`, `>=` effettuano un confronto in **ordine alfabetico** (più precisamente *lessicografico*, basato sul codice numerico Unicode di ciascun carattere):

```python
print("ananas" < "banana")   # True (la 'a' viene prima della 'b')
print("casa" < "casale")     # True (la parola più corta viene prima a parità di prefisso)
```

:::warning Attenzione a maiuscole e minuscole
Nel set di caratteri ASCII/Unicode standard, tutte le lettere **maiuscole** hanno un codice numerico inferiore rispetto alle **minuscole**. Per questo motivo:

```python
print("Zanna" < "albero")    # True! ('Z' ha codice 90, 'a' ha codice 97)
```

Per fare confronti alfabetici realistici indipendenti dalla cassa grafica è bene convertire entrambe le stringhe in minuscolo con `.lower()`:

```python
parola1 = "Zanna"
parola2 = "albero"
print(parola1.lower() < parola2.lower())   # False ('albero' viene prima di 'zanna')
```
:::

### 4.3 Codici ASCII e funzioni `ord()` e `chr()`
Ogni carattere corrisponde a un numero intero secondo la tabella standard ASCII ed estesa Unicode.

* **`ord(carattere)`**: riceve una stringa di un solo carattere e restituisce il suo codice numerico intero.
* **`chr(codice)`**: riceve un numero intero e restituisce il carattere corrispondente.

```python
print(ord("A"))    # 65
print(ord("B"))    # 66
print(ord("a"))    # 97
print(ord(" "))    # 32 (il carattere spazio)

print(chr(65))     # 'A'
print(chr(98))     # 'b'
```

Questo meccanismo è fondamentale per cifrari e problemi di crittografia classica, come il **Cifrario di Cesare** (in cui ogni lettera viene traslata di $k$ posizioni nell'alfabeto):

```python
# Spostare una lettera avanti di una posizione
lettera = "c"
successiva = chr(ord(lettera) + 1)
print(successiva)  # 'd'
```

:::tip Per chi conosce il C
In C il tipo `char` è fondamentalmente un numero intero a 8 bit, quindi era lecito scrivere direttamente espressioni aritmetiche come `'a' + 1` (che produceva `'b'`). In Python l'operazione `'a' + 1` solleva un `TypeError: can only concatenate str (not "int") to str`. È obbligatorio passare esplicitamente per `ord()` e `chr()`.
:::

---

## 5. I metodi delle stringhe

Python fornisce un ricchissimo corredo di metodi specializzati. Ricordiamo che **nessun metodo modifica la stringa originale**: restituiscono sempre una **nuova stringa** o un valore di risposta.

### 5.1 Modifica di cassa (maiuscole e minuscole)

| Metodo | Descrizione | Esempio su `"corso python"` |
|---|---|---|
| `.lower()` | Converte tutto in minuscolo | `"CORSO".lower()` $\rightarrow$ `'corso'` |
| `.upper()` | Converte tutto in maiuscolo | `"corso".upper()` $\rightarrow$ `'CORSO'` |
| `.capitalize()` | Prima lettera maiuscola, il resto minuscolo | `"corso python".capitalize()` $\rightarrow$ `'Corso python'` |
| `.title()` | Iniziale di ogni parola maiuscola | `"corso python".title()` $\rightarrow$ `'Corso Python'` |
| `.swapcase()` | Inverte maiuscole e minuscole | `"PyThOn".swapcase()` $\rightarrow$ `'pYtHoN'` |

Esempio:
```python
testo = "   pRoGrAmMaZiOnE in PyThOn   "

print(testo.lower())       # '   programmazione in python   '
print(testo.upper())       # '   PROGRAMMAZIONE IN PYTHON   '
print(testo.title())       # '   Programmazione In Python   '
```

---

### 5.2 Pulizia e rimozione di spazi (`strip`)

Spesso i dati inseriti dall'utente tramite `input()` o letti da un file contengono spazi indesiderati all'inizio o alla fine, o caratteri di a capo `\n`.

| Metodo | Descrizione |
|---|---|
| `.strip()` | Rimuove spazi, tabulazioni e caratteri a capo da **entrambi i lati** |
| `.lstrip()` | Rimuove gli spazi solo a **sinistra** (all'inizio) |
| `.rstrip()` | Rimuove gli spazi solo a **destra** (alla fine) |

```python
grezzo = "   Milano   \n"
pulito = grezzo.strip()

print(f"'{pulito}'")       # 'Milano'
```

Se si passa una stringa come argomento, `.strip()` rimuove tutti i caratteri specificati invece degli spazi:

```python
s = "...Ciao Mondo!!!"
print(s.strip(".!"))       # 'Ciao Mondo'
```

---

### 5.3 Ricerca e conteggio

| Metodo | Descrizione |
|---|---|
| `.find(sub)` | Restituisce l'indice della **prima occorrenza** di `sub`, oppure **`-1`** se non trovata |
| `.rfind(sub)` | Restituisce l'indice dell'**ultima occorrenza** di `sub`, oppure `-1` |
| `.index(sub)` | Come `find`, ma solleva un errore `ValueError` se `sub` non è presente |
| `.count(sub)` | Conta quante volte la sottostringa `sub` compare (senza sovrapposizioni) |
| `.startswith(prefisso)` | Restituisce `True` se la stringa inizia con `prefisso` |
| `.endswith(suffisso)` | Restituisce `True` se la stringa finisce con `suffisso` |

```python
frase = "il cane abbaia al cane vicino"

print(frase.find("cane"))         # 3 (inizia all'indice 3)
print(frase.rfind("cane"))        # 19 (la seconda occorrenza inizia all'indice 19)
print(frase.find("gatto"))        # -1 (non presente)

print(frase.count("cane"))        # 2
print(frase.count("a"))           # 6

file = "documento.pdf"
print(file.endswith(".pdf"))      # True
print(file.startswith("doc"))     # True
```

:::tip Differenza tra `in`, `.find()` e `.index()`
* Se volete solo sapere **se** una parola è presente, usate l'operatore **`in`**: `"cane" in frase` (è il più rapido e leggibile).
* Se vi serve la **posizione** numerica e la parola potrebbe mancare, usate **`.find()`** (controllando se il risultato è $\ge 0$).
* Usate **`.index()`** solo se siete certi che la sottostringa sia presente, altrimenti il programma si interromperà con errore.
:::

---

### 5.4 Sostituzione (`replace`)

Il metodo `.replace(vecchio, nuovo)` sostituisce tutte le occorrenze di una sottostringa con un'altra:

```python
frase = "Oggi piove, domani piove ancora"
nuova = frase.replace("piove", "c'è il sole")

print(nuova)  # 'Oggi c'è il sole, domani c'è il sole ancora'
```

Un terzo parametro facoltativo indica il numero massimo di sostituzioni da effettuare:

```python
# Sostituisce solo la prima occorrenza
singola = frase.replace("piove", "splende il sole", 1)
print(singola)  # 'Oggi splende il sole, domani piove ancora'
```

Per eliminare del tutto un carattere o una parola, basta sostituirla con la stringa vuota `""`:

```python
codice = "123-456-789"
solo_cifre = codice.replace("-", "")
print(solo_cifre)   # '123456789'
```

---

### 5.5 Verifica del tipo di caratteri (metodi `is...`)

Tutti questi metodi restituiscono un booleano (`True` o `False`):

| Metodo | Restituisce `True` se... |
|---|---|
| `.isdigit()` | Tutti i caratteri sono cifre numeriche (`'0'`-`'9'`) e la stringa non è vuota |
| `.isalpha()` | Tutti i caratteri sono lettere dell'alfabeto (senza spazi o numeri) |
| `.isalnum()` | Tutti i caratteri sono alfanumerici (lettere o cifre) |
| `.isspace()` | Tutti i caratteri sono spazi bianchi, tabulazioni o newline |
| `.islower()` | Tutti i caratteri alfabetici sono minuscoli |
| `.isupper()` | Tutti i caratteri alfabetici sono maiuscoli |

```python
print("12345".isdigit())      # True
print("123a".isdigit())       # False
print("Mario".isalpha())      # True
print("Mario Rossi".isalpha()) # False (lo spazio non è una lettera!)
print("   \t\n".isspace())    # True
```

Sono utilissimi per validare l'input inserito da un utente prima di convertirlo con `int()` o elaborarlo:

```python
risposta = input("Inserisci la tua età: ").strip()
if risposta.isdigit():
    eta = int(risposta)
    print(f"Tra 5 anni avrai {eta + 5} anni")
else:
    print("Errore: devi inserire un numero valido!")
```

---

### 5.6 Divisione e unione: `split()` e `join()`

Questi due metodi rappresentano il ponte principale tra stringhe e [liste](../liste/).

#### Il metodo `.split()`
Spezza una stringa in una **lista di sottostringhe**. 

Se chiamato **senza argomenti**, spezza su qualsiasi sequenza di spazi bianchi consecutivi, tabulazioni o caratteri a capo (ignorando gli spazi iniziali e finali):

```python
frase = "   Python è   un linguaggio   fantastico   "
parole = frase.split()

print(parole)
# ['Python', 'è', 'un', 'linguaggio', 'fantastico']
```

Se invece si specifica un **delimitatore**, la divisione avverrà esattamente su quel carattere:

```python
dati = "Rossi,Mario,1990,Roma"
campi = dati.split(",")

print(campi)
# ['Rossi', 'Mario', '1990', 'Roma']
```

```python
data = "25/12/2026"
giorno, mese, anno = data.split("/")
print(f"Giorno: {giorno}, Mese: {mese}, Anno: {anno}")
```

#### Il metodo `join()`
Fa l'operazione opposta di `split`: prende una lista di stringhe e le **unisce** in un'unica stringa, inserendo un separatore tra un elemento e l'altro.

La sintassi può sembrare curiosa a prima vista: si chiama il metodo **sul separatore**, passando la lista come parametro:

$$\text{separatore}.\text{join}(\text{lista})$$

```python
parole = ["casa", "albero", "fiume", "montagna"]

# Unione con virgola e spazio
risultato1 = ", ".join(parole)
print(risultato1)     # 'casa, albero, fiume, montagna'

# Unione con trattino
risultato2 = " - ".join(parole)
print(risultato2)     # 'casa - albero - fiume - montagna'

# Unione senza alcun separatore
risultato3 = "".join(parole)
print(risultato3)     # 'casaalberofiumemontagna'
```

:::warning Attenzione con `join()`
Tutti gli elementi della lista passata a `join()` devono essere **stringhe**. Se la lista contiene numeri, bisogna prima convertirli:

```python
numeri = [10, 20, 30, 40]
# Errore: ', '.join(numeri) -> TypeError!

# Corretto con list comprehension o map:
stringa_num = ", ".join(str(n) for n in numeri)
print(stringa_num)    # '10, 20, 30, 40'
```
:::



---

## 6. Esempi pratici notevoli

### Esempio 1: Cifrario di Cesare
Cifrare un messaggio traslando ogni lettera alfabetica in avanti di $k$ posizioni (gestendo il riavvolgimento dell'alfabeto da 'z' ad 'a'):

```python
def cifra_cesare(testo, chiave=3):
    risultato = []
    for c in testo:
        if 'a' <= c <= 'z':
            # Calcoliamo la posizione da 0 a 25, sommiamo la chiave e applichiamo il modulo 26
            nuovo_codice = ord('a') + (ord(c) - ord('a') + chiave) % 26
            risultato.append(chr(nuovo_codice))
        elif 'A' <= c <= 'Z':
            nuovo_codice = ord('A') + (ord(c) - ord('A') + chiave) % 26
            risultato.append(chr(nuovo_codice))
        else:
            # Spazi e punteggiatura rimangono inalterati
            risultato.append(c)
    return "".join(risultato)

frase = "Attaccare all'alba!"
cifrata = cifra_cesare(frase, 3)
print("Originale:", frase)
print("Cifrata:  ", cifrata)   # Dwwdffduh doo'doed!
```

### Esempio 2: Maiuscole alternate
Data una stringa, convertire i caratteri in posizione pari in maiuscolo e quelli in posizione dispari in minuscolo:

```python
def maiuscole_alternate(stringa):
    caratteri = []
    for i, c in enumerate(stringa):
        if i % 2 == 0:
            caratteri.append(c.upper())
        else:
            caratteri.append(c.lower())
    return "".join(caratteri)

testo = "Ciao a tutti, come state?"
print(maiuscole_alternate(testo))
# CiAo a tUtTi, CoMe sTaTe?
```

---

## Esercizi

Gli esercizi relativi a questo argomento si trovano nel capitolo **"Stringhe"** dell'eserciziario, linkato nella [pagina introduttiva](../programmazione-in-python/).
