---
title: "Laboratorio: Preparazione Dati in Python"
description: "Laboratorio pratico in Python con Pandas e Scikit-Learn per importare dati, isolare feature e target, e dividere in Train e Test set."
---

Benvenuto nel laboratorio pratico dell'Unità 1. Qui imparerai a preparare un dataset in Python, isolando le caratteristiche predittive (feature) dall'etichetta finale (target) e suddividendo i dati per l'addestramento e la valutazione del modello.

---

## 1. Configurazione dell'Ambiente e Esecuzione Offline

Ti consigliamo di svolgere questo laboratorio in locale sul tuo computer. Puoi scaricare direttamente il Notebook Jupyter fittizio per avviarlo in Visual Studio Code:

*   [Scarica il Notebook: unita1_introduzione_dati.ipynb](/manuale-libero-online-di-informatica/assets/codice/python/unita1_introduzione_dati.ipynb)

Assicurati di aver installato le librerie necessarie sul tuo terminale prima di procedere:
```bash
pip install pandas scikit-learn
```

---

## 2. Esecuzione del Codice Passo dopo Passo

##### Passo A: Caricamento e Ispezione dei Dati
Creiamo un piccolo dataset fittizio contenente dati scolastici relativi a ore di studio, frequenza e superamento o meno dell'esame.

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
*   **`pd.DataFrame(data)`**: Converte un dizionario Python in una tabella organizzata a righe e colonne (DataFrame), la struttura standard per manipolare dati.

##### Passo B: Isolare Feature ($X$) e Target ($y$)
Separiamo le caratteristiche in ingresso ($X$) dall'etichetta corretta ($y$) che il modello dovrà imparare a indovinare.

```python
# X contiene tutte le colonne tranne 'Superato'
X = df[['Ore_Studio', 'Presenze_Percentuale']]

# y contiene solo la colonna 'Superato'
y = df['Superato']

print("Matrice delle Feature (X):")
print(X)
print("\nTarget (y):", list(y))
```
*   **`df[['colonna1', 'colonna2']]`**: Estrae una matrice bidimensionale (due parentesi quadre) contenente solo le feature.
*   **`df['colonna']`**: Estrae un vettore monodimensionale (una parentesi quadra) contenente l'etichetta target.

##### Passo C: Suddivisione in Training Set e Test Set
Per valutare in modo neutrale il modello, dobbiamo testarlo su dati che non ha mai visto durante l'addestramento.

```python
from sklearn.model_selection import train_test_split

# Dividiamo i dati: l'80% va in training e il 20% in test
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

print(f"Dataset originale: {len(X)} righe")
print(f"Train set: {len(X_train)} righe")
print(f"Test set: {len(X_test)} righe")
```
*   **`train_test_split`**: Suddivide i record a caso. `test_size=0.2` indica che il 20% dei campioni va nel Test Set.
*   **`random_state=42`**: Blocca la casualità dell'estrazione per garantire la riproducibilità dei risultati ad ogni esecuzione.

<details>
<summary><b>Visualizza il codice completo (pronto da copiare ed eseguire)</b></summary>

```python
import pandas as pd
from sklearn.model_selection import train_test_split

# 1. Creazione dataset
data = {
    'Ore_Studio': [12, 5, 15, 8, 20, 4, 18, 10],
    'Presenze_Percentuale': [90, 60, 95, 70, 100, 50, 90, 80],
    'Superato': [1, 0, 1, 0, 1, 0, 1, 1]
}
df = pd.DataFrame(data)

# 2. Separazione Feature e Target
X = df[['Ore_Studio', 'Presenze_Percentuale']]
y = df['Superato']

# 3. Splitting Train/Test
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

print(f"Dimensioni del Train Set: {X_train.shape}")
print(f"Dimensioni del Test Set:  {X_test.shape}")
```
</details>

---

## 3. Coding Challenges

Mettiti alla prova estendendo o completando il codice scritto in questo laboratorio.

### Challenge 1: Completamento dello split da file CSV
*   **Task:** Completa il seguente frammento di codice in modo che carichi un ipotetico file CSV `"studenti.csv"`, isoli come feature le colonne `'ore_studio'` e `'media_voti'`, e infine divida il dataset destinando il 30% dei dati al test set.

```python
import pandas as pd
from sklearn.model_selection import train_test_split

# A. Carica il CSV
df = pd.read_csv("studenti.csv")

# B. Separa feature (X) e target (y)
X = df[['ore_studio', 'media_voti']]
y = df['___(1)___']

# C. Esegui la suddivisione
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=___(2)___, random_state=42)
```

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-unita1-ch1">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-unita1-ch1">
        <p><strong>Risoluzione:</strong>
        <ul>
            <li><code>___(1)___</code> deve essere sostituito con il nome della colonna target, ad esempio <code>'superato'</code>.</li>
            <li><code>___(2)___</code> deve essere sostituito con la frazione decimale <code>0.3</code> (che corrisponde al 30% di dati riservati al test set).</li>
        </ul>
        </p>
    </div>
</div>

---

### Challenge 2: Ispezione delle dimensioni delle matrici (Shape)
*   **Task:** Modifica il codice del laboratorio stampando a schermo la proprietà `.shape` di Pandas delle quattro variabili risultanti dallo split (`X_train`, `X_test`, `y_train`, `y_test`).
*   **Domanda:** Quali dimensioni ottieni? Spiega il significato dei due numeri restituiti dalla proprietà `.shape`.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-unita1-ch2">Visualizza la risoluzione e il codice</p>
    <div class="soluzione" id="sol-unita1-ch2">
        <p><strong>Codice:</strong></p>
        <pre><code class="language-python">print("Shape X_train:", X_train.shape)
print("Shape X_test: ", X_test.shape)
print("Shape y_train:", y_train.shape)
print("Shape y_test: ", y_test.shape)</code></pre>
        <p><strong>Risultati attesi:</strong></p>
        <pre><code class="language-text">Shape X_train: (6, 2)
Shape X_test:  (2, 2)
Shape y_train: (6,)
Shape y_test:  (2,)</code></pre>
        <p><strong>Spiegazione:</strong>
        La proprietà <code>.shape</code> restituisce una tupla che rappresenta la dimensionalità della variabile:
        <ul>
            <li>Per <code>X_train</code>, <code>(6, 2)</code> significa che ci sono <strong>6 righe</strong> (campioni) e <strong>2 colonne</strong> (le feature 'Ore_Studio' e 'Presenze_Percentuale').</li>
            <li>Per <code>y_train</code>, <code>(6,)</code> indica un vettore monodimensionale di <strong>6 elementi</strong> (le etichette target corrispondenti ai 6 campioni di train), senza colonne aggiuntive.</li>
        </ul>
        </p>
    </div>
</div>
