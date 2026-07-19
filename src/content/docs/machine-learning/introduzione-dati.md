---
title: "Unità 1: Introduzione al Machine Learning e Preparazione dei Dati"
description: "Introduzione al paradigma del Machine Learning, classificazione delle tipologie di apprendimento, preparazione dei dati in Python e suddivisione in Train/Test set."
---

Benvenuti nel mondo dell'**Intelligenza Artificiale**. In questa prima unità capiremo come i computer possono "imparare" direttamente dall'esperienza (i dati) senza che un programmatore debba scrivere esplicitamente ogni singola istruzione logica.

---

## 1.1 Il Cambio di Paradigma: Programmazione Classica vs Machine Learning

Nella **programmazione tradizionale (classica)**, il programmatore scrive le regole (gli algoritmi) e le fornisce al computer insieme ai dati di partenza. Il computer esegue queste regole passo dopo passo e produce un risultato.

$$\text{Dati} + \text{Regole} \longrightarrow \text{Risultati}$$

> **Esempio**: Se vuoi calcolare l'area di un cerchio, scrivi la regola matematica $A = \pi \cdot r^2$. Fornisci il raggio (dato) e il computer calcola l'area (risultato).

Nel **Machine Learning (ML)**, il processo si inverte. Spesso non conosciamo la regola matematica o logica complessa che lega i dati ai risultati (ad esempio, come distinguere la foto di un cane da quella di un gatto). Forniamo quindi al computer i dati e i risultati attesi (esempi). Sarà l'algoritmo di ML a trovare la regola (ovvero il **"modello"**).

$$\text{Dati} + \text{Risultati} \longrightarrow \text{Regole (Modello)}$$

Una volta che il modello è stato addestrato, possiamo fornirgli nuovi dati di cui non conosciamo il risultato e usarlo per fare previsioni:

$$\text{Nuovi Dati} + \text{Modello} \longrightarrow \text{Previsioni}$$

---

## 1.2 La Struttura dei Dati: Dataset, Feature e Target

Per far apprendere un computer, i dati devono essere organizzati in forma tabellare, chiamata **Dataset**. Le colonne del dataset si dividono in due categorie principali:

*   **Feature (Caratteristiche / Variabili Indipendenti - $X$):** Sono le colonne che contengono le informazioni usate dal modello per fare la previsione. Nei modelli matematici, corrispondono alle nostre variabili indipendenti $x_1, x_2, \dots, x_n$.
*   **Target (Etichetta / Variabile Dipendente - $y$):** È la colonna che contiene l'output che vogliamo prevedere. Matematicamente, corrisponde alla variabile dipendente $y$.

### Esempio di Dataset Immobiliare

| Superficie in $m^2$ ($x_1$) | Numero di Camere ($x_2$) | Prezzo Venduto ($y$) |
| :---: | :---: | :---: |
| 85 | 3 | 210.000 € |
| 120 | 4 | 295.000 € |
| **FEATURE** | **FEATURE** | **TARGET** |

---

## 1.3 Apprendimento Supervisionato vs Non Supervisionato

Il Machine Learning si divide principalmente in due grandi famiglie, a seconda della presenza o meno del target nel dataset:

### 1. Apprendimento Supervisionato (Supervised Learning)
Il dataset di partenza contiene sia le feature sia il target (conosciamo già la risposta corretta per i dati storici). Il modello impara a mappare gli input negli output. Si divide in:
*   **Classificazione:** Il target è una categoria discreta (es. "Sì/No", "Gatto/Cane", "Email di Spam / Email Sicura").
*   **Regressione:** Il target è un valore numerico continuo (es. il prezzo di una casa, la temperatura di domani).

### 2. Apprendimento Non Supervisionato (Unsupervised Learning)
Il dataset contiene solo le feature, senza alcun target associato. L'algoritmo deve trovare autonomamente dei pattern o raggruppare i dati simili.
*   **Clustering:** Raggruppamento di dati in gruppi (cluster) basandosi sulla loro similarità (es. segmentazione dei clienti con abitudini d'acquisto affini).

---

## 💻 Laboratorio Python (VS Code offline)

Per svolgere questa esercitazione offline sul tuo computer, utilizzeremo **Visual Studio Code (VS Code)** e i **Jupyter Notebook** (documenti con estensione `.ipynb` che consentono di alternare testo scritto e celle di codice Python eseguibili singolarmente).

### Configurazione dell'Ambiente di Lavoro

#### 1. Installare l'estensione per i Notebook in VS Code
1. Apri VS Code.
2. Clicca sull'icona delle **Estensioni** nella barra laterale sinistra (oppure premi `Ctrl + Shift + X`).
3. Cerca **"Jupyter"** nella barra di ricerca.
4. Troverai diversi risultati. Installa l'estensione ufficiale fornita da **Microsoft** (denominata semplicemente **Jupyter**, con l'icona di un pianeta arancione). Le altre estensioni collegate (come *Jupyter Keymap* o *Jupyter Cell Tags*) verranno installate automaticamente o non sono necessarie.

#### 2. Installare le librerie dal terminale
Apri il terminale integrato in VS Code (`Ctrl + Shift + '` oppure *Terminale > Nuovo Terminale*) ed esegui il seguente comando per installare le librerie di analisi dati e machine learning:

```bash
pip install pandas scikit-learn
```

#### 3. Creare il file del Notebook
Puoi creare un nuovo Notebook in due modi:
*   **Metodo Rapido:** Crea un nuovo file vuoto, salvalo con il nome `unita1.ipynb` (la parte fondamentale è l'estensione `.ipynb`). VS Code lo riconoscerà automaticamente come Notebook.
*   **Metodo da Command Palette:** Premi `Ctrl + Shift + P` (o `F1`), digita `Create: New Jupyter Notebook` e premi `Invio`. Salva poi il file come `unita1.ipynb`.

#### 4. Selezionare il Kernel (l'ambiente Python)
Quando apri il file per la prima volta:
1. In alto a destra del Notebook, clicca sul pulsante **"Select Kernel"** (Seleziona Kernel).
2. Seleziona **"Python Environments..."** e scegli la versione di Python installata sul tuo computer (ad esempio quella legata al tuo ambiente globale o a `conda`).

---

### Esecuzione del Laboratorio

Nei Jupyter Notebook, il codice è diviso in **Celle**. Puoi inserire il codice di ogni passaggio in una cella separata. Per eseguire il codice di una cella, clicca sull'icona **Play** a sinistra della cella, oppure premi la combinazione di tasti **`Shift + Invio`**.

### Passaggio 1: Caricamento e Ispezione dei Dati
Creiamo un piccolo dataset fittizio con dati scolastici di alcuni studenti.

```python
import pandas as pd

# Creiamo un piccolo dataset fittizio di studenti
data = {
    'Ore_Studio': [12, 5, 15, 8, 20, 4, 18, 10],
    'Presenze_Percentuale': [90, 60, 95, 70, 100, 50, 90, 80],
    'Superato': [1, 0, 1, 0, 1, 0, 1, 1]  # Target (1=Sì, 0=No)
}

df = pd.DataFrame(data)
print(df)
```

**Output atteso:**
```text
   Ore_Studio  Presenze_Percentuale  Superato
0          12                    90         1
1           5                    60         0
2          15                    95         1
3           8                    70         0
4          20                   100         1
5           4                    50         0
6          18                    90         1
7          10                    80         1
```

### Passaggio 2: Isolare Feature ($X$) e Target ($y$)
Prima di passare i dati all'algoritmo, separiamo le caratteristiche ($X$) dalla risposta corretta ($y$).

```python
# X contiene tutte le colonne tranne 'Superato'
X = df[['Ore_Studio', 'Presenze_Percentuale']]

# y contiene solo la colonna 'Superato'
y = df['Superato']

print("Matrice delle Feature (X):")
print(X)
print("\nTarget (y):", list(y))
```

### Passaggio 3: Il concetto di Train e Test Split
Non possiamo testare le prestazioni di un modello sugli stessi dati su cui si è addestrato: rischierebbe semplicemente di ricordare le risposte a memoria (fenomeno noto come **Overfitting** o *sovraccapacità di adattamento*). 

Per evitare questo errore, dividiamo il dataset in due parti distinte:
*   **Train Set (tipicamente l'80%):** i dati con cui il modello impara.
*   **Test Set (tipicamente il 20%):** i dati tenuti nascosti per valutare le reali prestazioni del modello su dati nuovi.

```python
from sklearn.model_selection import train_test_split

# Dividiamo i dati: l'80% va in training e il 20% in test
# random_state=42 assicura che lo split sia riproducibile ad ogni esecuzione
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

print(f"Dataset originale: {len(X)} righe")
print(f"Train set: {len(X_train)} righe")
print(f"Test set: {len(X_test)} righe")
```

---

## 📝 Materiale per la Verifica scritta (Unità 1)

### Domande Teoriche

#### Domanda 1
Spiega per quale motivo, prima di addestrare qualsiasi modello di Machine Learning, è di fondamentale importanza dividere il dataset iniziale in un *Train Set* e in un *Test Set*. Cosa si rischia di non individuare se testiamo il modello sugli stessi dati di addestramento?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-teoria-1">Visualizza la risposta corretta</p>
    <div class="soluzione" id="sol-teoria-1">
        <p><strong>Risposta:</strong> Dividere il dataset è essenziale per valutare la capacità del modello di <em>generalizzare</em>, ossia di fare previsioni accurate su dati nuovi che non ha mai visto durante l'addestramento. Se testiamo il modello sugli stessi dati di train, rischiamo di non accorgerci del fenomeno dell'<strong>Overfitting</strong>. In questo caso il modello memorizza le risposte del dataset di addestramento ma fallirà sistematicamente quando si troverà di fronte a nuovi dati.</p>
    </div>
</div>

#### Domanda 2
Descrivi brevemente la differenza tra un problema di *Classificazione* e uno di *Regressione* all'interno dell'apprendimento supervisionato, fornendo un esempio pratico per ciascuno.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-teoria-2">Visualizza la risposta corretta</p>
    <div class="soluzione" id="sol-teoria-2">
        <p><strong>Risposta:</strong>
        <ul>
            <li>Nella <strong>Classificazione</strong>, il target è una variabile qualitativa o discreta (le uscite sono categorie/classi). <em>Esempio pratico</em>: decidere se un'email è "Spam" o "Non Spam".</li>
            <li>Nella <strong>Regressione</strong>, il target è una variabile quantitativa o numerica continua. <em>Esempio pratico</em>: prevedere il prezzo di vendita di una casa basandosi sulla sua metratura.</li>
        </ul>
        </p>
    </div>
</div>

---

### Esercizio Pratico di Analisi Dati
Un'azienda di e-commerce raccoglie i dati dei propri utenti per prevedere se un utente completerà un acquisto (valori possibili: "Sì" o "No"). I dati raccolti sono: *Età dell'utente*, *Tempo speso sul sito (in minuti)*, *Numero di prodotti visualizzati* e *Acquisto Completato*.

*   **A)** Identifica quali variabili rappresentano le Feature ($X$) e quale rappresenta il Target ($y$).
*   **B)** Si trata di un problema di apprendimento supervisionato o non supervisionato? Giustifica la risposta.
*   **C)** Se il target fosse invece "Prezzo totale del carrello in euro", il problema sarebbe di Classificazione o di Regressione?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-pratico-1">Visualizza la risoluzione dell'esercizio</p>
    <div class="soluzione" id="sol-pratico-1">
        <p><strong>Soluzione:</strong>
        <ul>
            <li><strong>A)</strong> Feature ($X$): <em>Età dell'utente</em>, <em>Tempo speso sul sito</em>, <em>Numero di prodotti visualizzati</em>. Target ($y$): <em>Acquisto Completato</em>.</li>
            <li><strong>B)</strong> Si tratta di apprendimento <strong>supervisionato</strong>, poiché il dataset contiene sia le feature che l'etichetta target da prevedere ("Acquisto Completato").</li>
            <li><strong>C)</strong> Il problema diventerebbe di <strong>Regressione</strong>, poiché il target ("Prezzo totale del carrello") è un valore numerico continuo in euro.</li>
        </ul>
        </p>
    </div>
</div>

---

### Esercizio sul Codice Python
Dato il seguente frammento di codice in cui sono presenti due spazi vuoti segnati con `___(1)___` e `___(2)___`, completalo in modo che il codice separi correttamente le feature dal target e divida il dataset destinando il 30% dei dati al test set.

```python
import pandas as pd
from sklearn.model_selection import train_test_split

df = pd.read_csv("dati_studenti.csv")

# 1. Separiamo feature e target
X = df[['ore_studio', 'media_voti']]
y = df['___(1)___']

# 2. Dividiamo in train e test
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=___(2)___, random_state=42)
```

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-codice-1">Visualizza il codice completo</p>
    <div class="soluzione" id="sol-codice-1">
        <p><strong>Soluzione:</strong>
        <ul>
            <li><code>___(1)___</code> deve essere sostituito con la colonna target, ad esempio <code>'superato'</code> (o il nome esatto della colonna target nel file csv).</li>
            <li><code>___(2)___</code> deve essere sostituito con <code>0.3</code> (che rappresenta il 30% destinato al test set).</li>
        </ul>
        Codice completo modificato:
        <pre><code># 1. Separiamo feature e target
y = df['superato']

# 2. Dividiamo in train e test
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)</code></pre>
        </p>
    </div>
</div>
