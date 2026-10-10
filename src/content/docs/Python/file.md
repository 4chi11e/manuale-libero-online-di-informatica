---
title: File di testo
description: Lettura e scrittura di file di testo in Python, gestione con with open, codifica utf-8, modalità di accesso, parsing riga per riga e flussi di elaborazione dati.
---

Finora tutti i dati gestiti dai nostri programmi (numeri inseriti dall'utente, liste, dizionari) risiedevano esclusivamente nella **memoria RAM**. La RAM è una memoria volatile: non appena il programma termina la sua esecuzione, tutti i dati svaniscono.

Per conservare le informazioni in modo permanente e renderle riutilizzabili nel tempo abbiamo bisogno della **persistenza dei dati** sulla memoria di massa (disco fisso o SSD), sotto forma di **file**.

In questa sezione ci concentreremo sui **file di testo** (come i file `.txt` o i file tabellari `.csv`), cioè sequenze di caratteri leggibili da esseri umani e apribili con qualsiasi editor di testo.

:::tip Per chi conosce il C
In C la gestione dei file richiedeva di usare puntatori opachi (`FILE *f = fopen("dati.txt", "r")`), controllare manualmente se il puntatore era `NULL`, leggere con `fgets()` o `fscanf()` gestendo buffer statici, e soprattutto ricordarsi tassativamente di chiamare `fclose(f)`. Dimenticare `fclose()` o incorrere in un errore a metà esecuzione causava perdita di dati o blocchi del file nel sistema operativo.

In Python usiamo il costrutto `with open(...) as f:`, che gestisce l'apertura e garantisce la **chiusura automatica** del file al termine del blocco, anche in caso di errori imprevisti.
:::

---

## 1. Apertura sicura: il blocco `with open()`

Per lavorare con un file in Python si usa la funzione nativa **`open()`** combinata con l'istruzione **`with`**:

```python
with open("dati.txt", "r", encoding="utf-8") as f:
    # Qui dentro il file 'f' è aperto e possiamo lavorarci
    contenuto = f.read()

# Fuori dal blocco indentato il file è AUTOMATICAMENTE chiuso!
```

Analizziamo i tre argomenti fondamentali di `open()`:

1. **Il percorso del file** (`"dati.txt"`): se specifichiamo solo il nome, Python cerca il file nella cartella di lavoro corrente (la cartella da cui è stato avviato lo script).
2. **La modalità di accesso** (`"r"`): indica se vogliamo leggere, scrivere o aggiungere dati.
3. **La codifica dei caratteri** (`encoding="utf-8"`): specifica come i caratteri (in particolare lettere accentate ed emoji) sono codificati in byte.

:::warning Perché specificare sempre `encoding="utf-8"`?
Sui sistemi operativi Windows la codifica predefinita può essere impostata su vecchi standard (come `cp1252`). Senza `encoding="utf-8"`, aprire un file contenente lettere accentate (`è`, `à`, `ù`) può provocare errori improvvisi di tipo `UnicodeDecodeError`. Specificare esplicitamente UTF-8 garantisce che il programma funzioni in modo identico e affidabile su qualsiasi computer.
:::

---

## 2. Le modalità di apertura (`mode`)

Il secondo parametro di `open()` stabilisce l'operazione consentita sul file:

| Modalità | Significato | Comportamento se il file esiste | Comportamento se il file NON esiste |
|:---:|---|---|---|
| `'r'` | **Lettura** (*read*, default) | Posiziona il cursore all'inizio per leggere | Solleva un errore `FileNotFoundError` |
| `'w'` | **Scrittura** (*write*) | **Cancella tutto** il contenuto esistente e riscrive da zero | Crea un nuovo file vuoto |
| `'a'` | **Aggiunta in coda** (*append*) | Mantiene il contenuto esistente e scrive alla fine | Crea un nuovo file vuoto |
| `'x'` | **Creazione esclusiva** | Solleva un errore `FileExistsError` | Crea un nuovo file vuoto |

:::caution Attenzione con la modalità `'w'`
Aprire un file con `"w"` sovrascrive immediatamente il file azzerandone il contenuto, anche prima di scrivere qualsiasi dato! Se volete aggiungere nuove righe a un file esistente senza cancellare quelle vecchie, dovete usare la modalità append (`"a"`).
:::

---

## 3. I quattro modi per leggere un file di testo

Python offre diversi metodi per leggere il contenuto di un file aperto in modalità `"r"`. A seconda della dimensione del file e di ciò che dobbiamo fare, c'è un metodo ideale.

### Metodo 1: Riga per riga con il ciclo `for` (il più consigliato)
È il modo più efficiente, naturale ed elegante di leggere un file in Python:

```python
with open("studenti.txt", "r", encoding="utf-8") as f:
    for riga in f:
        print(riga, end="")
```

* **Perché `end=""`?** Ogni riga restituita dal file termina già con il carattere di fine riga `\n`. Poiché la funzione `print()` aggiunge di default un secondo `\n`, senza `end=""` vedremmo una riga vuota tra una stampa e l'altra.
* **Perché è il più efficiente?** Python non carica tutto il file nella memoria RAM in un colpo solo, ma legge una riga alla volta. Questo significa che il programma può elaborare senza problemi anche file enormi di diversi gigabyte senza saturare la memoria.

### Metodo 2: Leggere tutto in un'unica stringa (`f.read()`)
Legge l'intero contenuto del file dal punto corrente fino alla fine e lo restituisce come una singola stringa:

```python
with open("testo.txt", "r", encoding="utf-8") as f:
    tutto_il_testo = f.read()

print(f"Il file contiene {len(tutto_il_testo)} caratteri")
```

È utilissimo per file di dimensioni medio-piccole quando vogliamo:
* contare i caratteri totali o le occorrenze di una parola;
* usare le [espressioni regolari](../espressioni-regolari/) sull'intero documento;
* dividere tutto in singole parole con `tutto_il_testo.split()`.

### Metodo 3: Tutte le righe in una lista (`f.readlines()`)
Legge tutte le righe del file e le inserisce in una lista di stringhe:

```python
with open("testo.txt", "r", encoding="utf-8") as f:
    righe = f.readlines()

print(f"Numero totale di righe: {len(righe)}")
print("Prima riga:", righe[0])
print("Ultima riga:", righe[-1])
```

È comodo quando abbiamo bisogno di accedere alle righe tramite indice posizionale (ad esempio per confrontare la riga corrente con la riga precedente).

### Metodo 4: Una singola riga alla volta (`f.readline()`)
Legge e restituisce la riga successiva del file. Se il file è terminato, restituisce una stringa vuota `""`.

```python
with open("testo.txt", "r", encoding="utf-8") as f:
    riga1 = f.readline()
    riga2 = f.readline()
```

#### Il caso d'uso classico: scartare l'intestazione
Molti file di dati (come i file CSV o tabellari) hanno la prima riga dedicata ai nomi delle colonne (header). Usare `readline()` prima di avviare il ciclo `for` è la tecnica più pulita per separare i titoli dai dati:

```python
with open("classifica.csv", "r", encoding="utf-8") as f:
    intestazione = f.readline()  # legge e "consuma" la prima riga
    
    # Il ciclo for partirà automaticamente dalla SECONDA riga!
    for riga in f:
        print("Dato:", riga.strip())
```

---

## 4. Scrivere su file: modalità `'w'` e `'a'`

Per scrivere su un file aperto in modalità `"w"` o `"a"` si usano principalmente due approcci.

### Scrivere con `f.write()`
Il metodo `f.write()` riceve come parametro una stringa e la scrive sul file:

```python
nomi = ["Mario", "Lucia", "Elena", "Paolo"]

with open("elenco_nomi.txt", "w", encoding="utf-8") as f:
    for nome in nomi:
        f.write(nome + "\n")
```

:::warning `write()` non aggiunge l'a capo automaticamente!
A differenza di `print()`, il metodo `f.write()` **non aggiunge alcun carattere di a capo**. Se scriviamo `f.write("A")` e poi `f.write("B")`, sul file otterremo `"AB"`. Bisogna sempre inserire esplicitamente `"\n"` alla fine del testo, ad esempio usando le f-string: `f.write(f"{nome}\n")`.
:::

### Scrivere con `print(..., file=f)` (alternativa comoda)
Pochi sanno che la normale funzione `print()` accetta un parametro opzionale **`file`**:

```python
with open("elenco_nomi.txt", "w", encoding="utf-8") as f:
    for nome in nomi:
        print(nome, file=f)  # scrive sul file e aggiunge l'a capo automaticamente!
```

Questa sintassi è spesso più comoda ed espressiva rispetto a concatenare manualmente i `\n`.

### Scrivere una lista di righe con `f.writelines()`
Se abbiamo già una lista di stringhe che contengono il `\n` finale, possiamo scriverle tutte insieme:

```python
righe = ["Prima riga\n", "Seconda riga\n", "Terza riga\n"]

with open("output.txt", "w", encoding="utf-8") as f:
    f.writelines(righe)
```

In alternativa, per unire una lista di stringhe senza newline e scriverle con un'unica operazione:

```python
parole = ["mela", "pera", "banana"]
with open("frutta.txt", "w", encoding="utf-8") as f:
    f.write("\n".join(parole) + "\n")
```

### Aggiungere dati in coda (modalità append `'a'`)
Se dobbiamo registrare eventi continui (come un log o nuovi utenti) senza toccare ciò che è già presente sul disco:

```python
with open("registro_accessi.log", "a", encoding="utf-8") as f:
    f.write("Nuovo accesso registrato alle 11:30\n")
```

---

## 5. Il flusso tipico: Parsing e manipolazione di file di dati

La quasi totalità degli esercizi reali con i file segue uno schema ricorrente in 4 passi:

```mermaid
graph LR
    A["1. Leggi riga per riga"] --> B["2. Pulisci con strip()"]
    B --> C["3. Spezza con split() e converti"]
    C --> D["4. Salva in Liste o Dizionari"]
    D --> E["5. Elabora e salva in nuovo file"]
```

Vediamo come funziona nella pratica con un caso concreto.

### Esempio guidato: Il registro delle ore lavorate
Immaginiamo di avere un file `ore_lavoro.txt` con la seguente struttura:
```text
Dipendente - Reparto - Ore
Mario Rossi - Vendite - 38
Lucia Verdi - Sviluppo - 42
Paolo Neri - Vendite - 40
Elena Bianchi - Sviluppo - 45
```

Vogliamo calcolare le ore totali per ogni dipendente, identificare chi ha fatto straordinari (più di 40 ore) e salvare un file di report `straordinari.txt`.

```python
dipendenti = []

# PASSO 1: Lettura e Parsing del file
with open("ore_lavoro.txt", "r", encoding="utf-8") as f:
    f.readline()  # 1. Scartiamo l'intestazione
    
    for riga in f:
        riga = riga.strip()   # 2. Rimuoviamo \n e spazi esterni
        if not riga:          # Ignoriamo eventuali righe vuote
            continue
            
        # 3. Spezziamo la riga sul separatore '-'
        parti = riga.split("-")
        nome = parti[0].strip()
        reparto = parti[1].strip()
        ore = int(parti[2].strip())  # 4. Conversione obbligatoria a int!
        
        # 5. Memorizziamo in un dizionario
        dipendenti.append({
            "nome": nome,
            "reparto": reparto,
            "ore": ore
        })

# PASSO 2: Elaborazione dei dati
# Ordiniamo i dipendenti per ore lavorate decrescenti
dipendenti.sort(key=lambda x: -x["ore"])

# PASSO 3: Scrittura del file di output
with open("straordinari.txt", "w", encoding="utf-8") as fout:
    fout.write("DIPENDENTI CON STRAORDINARI (> 40 ore)\n")
    fout.write("-" * 40 + "\n")
    
    for dip in dipendenti:
        if dip["ore"] > 40:
            fout.write(f"{dip['nome']:<20} ({dip['reparto']}): {dip['ore']} ore\n")

print("Elaborazione completata con successo!")
```

---

## 6. Buone pratiche e trabocchetti frequenti

### 6.1 Pulire sempre le righe con `.strip()`
Una riga letta da file include sempre il carattere speciale di fine riga `\n`. Se proviamo a convertire una riga numerica o a confrontare una stringa, il `\n` nascosto può causare comportamenti inattesi:

```python
with open("numeri.txt", "r", encoding="utf-8") as f:
    for riga in f:
        # Pulisce sia gli spazi bianchi sia il \n prima di convertire
        valore = int(riga.strip())
```

### 6.2 Gestire le righe vuote
Nei file di testo reali capita spesso che in fondo o tra i paragrafi siano presenti righe vuote. Quando una riga è vuota, `riga` contiene solo `"\n"`, e `riga.strip()` restituisce la stringa vuota `""`.

Per evitare errori di indice su `split()` (`IndexError`), inserite sempre un controllo di guardia:

```python
for riga in f:
    riga = riga.strip()
    if not riga:     # Se la riga è vuota, passa subito alla successiva
        continue
    # procedi con lo split in totale sicurezza
```

### 6.3 Gestire l'errore `FileNotFoundError`
Se il file richiesto non esiste o il nome è stato digitato male, il programma si interrompe bruscamente sollevando `FileNotFoundError`. Possiamo gestirlo con un blocco `try...except`:

```python
nome_file = input("Nome del file da aprire: ").strip()

try:
    with open(nome_file, "r", encoding="utf-8") as f:
        testo = f.read()
        print(f"File letto con successo ({len(testo)} caratteri)")
except FileNotFoundError:
    print(f"Errore: il file '{nome_file}' non esiste nella cartella corrente!")
```

### 6.4 Generare nomi di file di output dinamici
Negli esercizi capita spesso di dover leggere un file `dati.txt` e produrre un file modificato con nome `dati-modificato.txt` o `dati-out.txt`.

Ci sono due modi eleganti per farlo:

```python
nome_originale = "elenco.txt"

# Modo 1: con slicing per togliere l'estensione '.txt' (ultimi 4 caratteri)
nome_out1 = nome_originale[:-4] + "-out.txt"

# Modo 2: con il metodo splitext del modulo os.path
import os
base, est = os.path.splitext(nome_originale)
nome_out2 = f"{base}-modificato{est}"

print(nome_out1)  # 'elenco-out.txt'
print(nome_out2)  # 'elenco-modificato.txt'
```

---

## Esempi notevoli dall'eserciziario

### Esempio 1: Conteggio di righe e parole di un file
Calcolare quante righe piene contiene un file e contare il numero di parole presenti in ciascuna riga:

```python
def analizza_file(nomefile):
    righe_totali = 0
    parole_per_riga = []
    
    with open(nomefile, "r", encoding="utf-8") as f:
        for riga in f:
            riga = riga.strip()
            if riga:  # Considera solo le righe non vuote
                righe_totali += 1
                parole = riga.split()
                parole_per_riga.append(len(parole))
                
    return righe_totali, parole_per_riga

n_righe, parole = analizza_file("brano.txt")
print(f"Righe totali non vuote: {n_righe}")
print("Parole per ciascuna riga:", parole)
```

### Esempio 2: Filtraggio e ordinamento di dati tabellari
Dato un file di esploratori nel formato `Nome Cognome AnnoNascita AnnoMorte`, ordinarli in base alla durata della loro vita (dalla più longeva alla meno longeva) e riscrivere il risultato su un secondo file:

```python
esploratori = []

with open("esploratori.txt", "r", encoding="utf-8") as fin:
    for riga in fin:
        riga = riga.strip()
        if not riga:
            continue
        parti = riga.split()
        nome = parti[0]
        cognome = parti[1]
        nascita = int(parti[2])
        morte = int(parti[3])
        durata_vita = morte - nascita
        
        esploratori.append([nome, cognome, nascita, morte, durata_vita])

# Ordiniamo per durata vita decrescente (indice 4)
esploratori.sort(key=lambda x: -x[4])

# Riscriviamo sul file di output
with open("esploratori_ordinati.txt", "w", encoding="utf-8") as fout:
    fout.write(f"{'Nome':12} {'Cognome':15} {'Nascita':8} {'Morte':8} {'Età':5}\n")
    fout.write("=" * 52 + "\n")
    for esp in esploratori:
        fout.write(f"{esp[0]:12} {esp[1]:15} {esp[2]:<8} {esp[3]:<8} {esp[4]:<5}\n")

print("File generato con successo!")
```

---

## Esercizi

Gli esercizi relativi a questo argomento si trovano nel capitolo **"Files"** dell'eserciziario, linkato nella [pagina introduttiva](../programmazione-in-python/).
