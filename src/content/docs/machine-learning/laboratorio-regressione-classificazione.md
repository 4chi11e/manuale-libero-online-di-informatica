---
title: "Laboratorio: Regressione e Classificazione"
description: "Laboratori pratici in Python con Scikit-Learn per addestrare modelli di regressione lineare, regressione logistica e misurarne l'accuratezza, la precisione e il recall."
---

Benvenuto nel laboratorio pratico dedicato alla Regressione e alla Classificazione. In questa sezione implementerai modelli lineari e logistici in Python, analizzerai le metriche di accuratezza tramite le matrici di confusione e ti cimenterai con sfide di programmazione avanzate.

---

## 1. Configurazione e Download
Ti consigliamo di svolgere questi laboratori offline nel tuo notebook Jupyter `laboratorio_ml.ipynb` locale.

### Download dei File del Laboratorio:
*   [Scarica il Dataset Studenti (CSV): studenti_voti.csv](/manuale-libero-online-di-informatica/assets/documenti/studenti_voti.csv)

---

## 2. Esecuzione dei Laboratori

### Esercizio 2.1: Regressione Lineare con Dati Hardcoded
Iniziamo addestrando un modello elementare su pochi campioni definiti direttamente nel codice.

```python
import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score

# Feature X: Ore studio (deve essere bidimensionale per Scikit-Learn)
X = np.array([[2], [4], [6], [8], [10], [12]])

# Target y: Voto ottenuto
y = np.array([4.5, 5.5, 6.0, 7.0, 8.5, 9.0])

# Inizializziamo e addestriamo il modello
reg = LinearRegression()
reg.fit(X, y)

# Prevediamo i valori sul nostro dataset
y_pred = reg.predict(X)

print(f"Modello addestrato: y = {reg.coef_[0]:.2f} * x + {reg.intercept_:.2f}")
print(f"MSE (Errore Quadratico Medio): {mean_squared_error(y, y_pred):.3f}")
print(f"R² (Coefficiente di Determinazione): {r2_score(y, y_pred):.3f}")
```

---

### Esercizio 2.2: Regressione Lineare da file CSV
Carichiamo un dataset di 100 studenti salvato in un file CSV esterno, addestriamo la regressione lineare e tracciamo il grafico dei risultati.

```python
import pandas as pd
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score
import matplotlib.pyplot as plt

# A. Carichiamo i dati dal file CSV
df = pd.read_csv("studenti_voti.csv")

# B. Prepariamo le variabili per Scikit-Learn
X = df[["ore_studio"]] # Doppie parentesi quadre per estrarre la feature come DataFrame bidimensionale
y = df["voto_esame"]

# C. Inizializziamo e addestriamo il modello
reg_pandas = LinearRegression()
reg_pandas.fit(X, y)

# D. Calcoliamo le previsioni del modello
y_pred = reg_pandas.predict(X)

# E. Valutiamo le metriche prestazionali
print("\n--- Risultati del Modello su 100 studenti ---")
print(f"Retta di regressione: y = {reg_pandas.coef_[0]:.3f} * x + {reg_pandas.intercept_:.3f}")
print(f"MSE: {mean_squared_error(y, y_pred):.3f}")
print(f"R²: {r2_score(y, y_pred):.3f}")

# F. Disegniamo il grafico finale
plt.figure(figsize=(8, 5))
plt.scatter(X, y, color="blue", alpha=0.6, label="Dati Reali (Studenti)")
plt.plot(X, y_pred, color="red", linewidth=2.4, label="Retta di Regressione")
plt.xlabel("Ore di Studio Settimanali")
plt.ylabel("Voto dell'Esame (1-10)")
plt.title("Regressione Lineare: Ore di Studio vs Voto Conseguito")
plt.grid(True, linestyle="--", alpha=0.5)
plt.legend()
plt.show()
```

---

### Esercizio 2.3: Regressione Logistica con Dati Hardcoded
Addestriamo un classificatore binario elementare su dati inseriti a mano nel codice.

```python
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score

# Dataset di addestramento
# Feature: [Ore_Studio, Presenze_Percentuale]
X_train = [[12, 90], [5, 60], [15, 95], [8, 70], [20, 100], [4, 50]]
y_train = [1, 0, 1, 0, 1, 0]

# Dati del test set (nuovi studenti)
X_test = [[10, 80], [6, 65]]
y_test = [1, 0]

# Inizializziamo e addestriamo il classificatore logistico
clf = LogisticRegression()
clf.fit(X_train, y_train)

# Eseguiamo le previsioni sul test set
y_pred = clf.predict(X_test)
y_prob = clf.predict_proba(X_test)  # Restituisce le probabilità [Classe 0, Classe 1]

print(f"Previsioni per gli studenti di test: {y_pred}")
print(f"Probabilità stimate (Bocciato vs Promosso):\n{y_prob}")
print(f"Accuratezza sul test set: {accuracy_score(y_test, y_pred) * 100:.1f}%")
```

---

### Esercizio 2.4: Classificazione Logistica e Matrice di Confusione
Generiamo un dataset sintetico più grande, eseguiamo la suddivisione in Train/Test set (80/20) e calcoliamo tutte le metriche viste a lezione tramite la matrice di confusione.

```python
from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, confusion_matrix, precision_score, recall_score

# 1. Generiamo un dataset sintetico di classificazione binaria (600 campioni)
X, y = make_classification(n_samples=600, n_features=2, n_redundant=0, 
                           n_clusters_per_class=1, random_state=42)

# 2. Dividiamo il dataset in Training Set (80%) e Test Set (20%)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

print(f"Dimensioni del Train Set: {X_train.shape[0]} campioni")
print(f"Dimensioni del Test Set:  {X_test.shape[0]} campioni\n")

# 3. Inizializziamo e addestriamo il modello di Regressione Logistica
clf = LogisticRegression()
clf.fit(X_train, y_train)

# 4. Prevediamo i risultati per i dati del Test Set (nascosti in addestramento)
y_pred = clf.predict(X_test)

# 5. Calcoliamo e stampiamo le metriche di valutazione sul Test Set
accuracy = accuracy_score(y_test, y_pred)
precision = precision_score(y_test, y_pred)
recall = recall_score(y_test, y_pred)

print("--- Valutazione del Modello sul Test Set ---")
print(f"Accuratezza (Accuracy): {accuracy * 100:.1f}%")
print(f"Precisione (Precision): {precision * 100:.1f}%")
print(f"Sensibilità (Recall):    {recall * 100:.1f}%")

# 6. Generiamo e visualizziamo la Matrice di Confusione
cm = confusion_matrix(y_test, y_pred)
print("\nMatrice di Confusione:")
print(cm)
```

---

## 3. Coding Challenges
Mettiti alla prova modificando ed estendendo il codice Python scritto finora sul tuo notebook.

### Challenge 1: L'effetto del Bias (Regressione Lineare)
*   **Task:** Modifica l'inizializzazione del modello di regressione lineare nella **Esercizio 2.1** impostando il parametro `fit_intercept=False`:
    ```python
    reg = LinearRegression(fit_intercept=False)
    ```
*   **Domanda:** Esegui nuovamente il codice. Qual è la nuova equazione della retta? Qual è il nuovo valore dell'MSE? Confrontalo con quello precedente dell'Esercizio 2.1 ($MSE \approx 0.048$): l'errore è aumentato o diminuito? Perché?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-lab-bias">Visualizza la risoluzione e il codice</p>
    <div class="soluzione" id="sol-lab-bias">
        <p><strong>Risoluzione e Codice:</strong></p>
        <pre><code class="language-python"># Modifica dell'inizializzazione del modello
reg_no_bias = LinearRegression(fit_intercept=False)
reg_no_bias.fit(X, y)

# Nuove previsioni
y_pred_no_bias = reg_no_bias.predict(X)

print(f"Modello senza bias: y = {reg_no_bias.coef_[0]:.2f} * x")
print(f"Nuovo MSE: {mean_squared_error(y, y_pred_no_bias):.3f}")
        </code></pre>
        <p><strong>Risultati attesi a schermo:</strong></p>
        <pre><code class="language-text">Modello senza bias: y = 0.87 * x
Nuovo MSE: 2.403
        </code></pre>
        <p><strong>Spiegazione concettuale:</strong></p>
        <p>Il nuovo MSE è di <strong>2.403</strong>, un valore notevolmente più alto rispetto allo <strong>0.048</strong> ottenuto con il bias abilitato (circa 50 volte superiore!).</p>
        <p>Forzando la retta a passare per l'origine $(0,0)$ tramite `fit_intercept=False`, abbiamo eliminato il bias $b$. Questo significa che se uno studente studia 0 ore, il modello è obbligato a prevedere un voto pari a 0. I dati reali però ci dicono che anche con pochissime ore il voto di partenza è più alto (l'intercetta originale era $3.50$). Rimuovendo questo grado di libertà, la retta si inclina forzatamente per compensare, ma perde gran parte della sua precisione ed adattabilità, portando ad errori di previsione molto più elevati.</p>
    </div>
</div>

---

### Challenge 2: Soglia Decisionale Personalizzata (Regressione Logistica)
*   **Task:** Utilizza il modello addestrato nel **Esercizio 2.3**. Scrivi uno script Python che estrae le probabilità della classe 1 per il test set dal vettore `y_prob` (prodotto da `clf.predict_proba(X_test)`) e applica manualmente la soglia decisionale di $0.8$ per determinare la classe prevista (1 se probabilità $\ge 0.8$, altrimenti 0).
*   **Domanda:** Quali sono le nuove previsioni del modello per i due studenti del test set con questa soglia più rigida?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-lab-soglia">Visualizza la risoluzione e il codice</p>
    <div class="soluzione" id="sol-lab-soglia">
        <p><strong>Risoluzione e Codice:</strong></p>
        <pre><code class="language-python"># y_prob contiene [prob_classe_0, prob_classe_1] per ciascun elemento.
# Estraiamo solo le probabilità della classe 1 (colonna indice 1)
prob_classe_1 = y_prob[:, 1]

# Impostiamo la nuova soglia decisionale
soglia_personalizzata = 0.8

# Applichiamo la soglia: True (diventa 1) se >= 0.8, False (diventa 0) altrimenti
y_pred_personalizzato = (prob_classe_1 >= soglia_personalizzata).astype(int)

print(f"Probabilità classe 1 (Promosso): {prob_classe_1}")
print(f"Previsioni con soglia standard 0.5: {y_pred}")
print(f"Previsioni con soglia rigida 0.8:  {y_pred_personalizzato}")
        </code></pre>
        <p><strong>Risultati attesi a schermo:</strong></p>
        <pre><code class="language-text">Probabilità classe 1 (Promosso): [0.5128965  0.00228039]
Previsioni con soglia standard 0.5: [1 0]
Previsioni con soglia rigida 0.8:  [0 0]
        </code></pre>
        <p><strong>Spiegazione concettuale:</strong></p>
        <p>Con la soglia standard a $0.5$, il primo studente (che ha il $51.3\%$ di probabilità di promozione) veniva classificato come <strong>1 (Promosso)</strong>. Alzando la soglia all' $80\%$ ($0.8$), il modello diventa più "severo": poiché $51.3\% < 80\%$, anche questo studente viene ora classificato come **0 (Bocciato)**. 
        Modificando la soglia possiamo rendere un modello più conservativo o più ottimista a seconda delle esigenze (ad esempio, essere molto conservativi prima di approvare una transazione bancaria sospetta o una diagnosi clinica).</p>
    </div>
</div>

---

### Challenge 3: Calcolo delle metriche Precision e Recall da codice
*   **Task:** Utilizza la matrice di confusione `cm` calcolata sul test set del **Esercizio 2.4**. Scompatta i quattro valori usando il metodo `.ravel()` di NumPy:
    ```python
    TN, FP, FN, TP = cm.ravel()
    ```
    Scrivi il codice Python per calcolare la **Precision** e il **Recall** del modello sul test set e stampali a schermo.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-lab-metriche">Visualizza la risoluzione e il codice</p>
    <div class="soluzione" id="sol-lab-metriche">
        <p><strong>Risoluzione e Codice:</strong></p>
        <pre><code class="language-python"># Scompattiamo la matrice di confusione dell'Esercizio 2.4
TN, FP, FN, TP = cm.ravel()

# Calcoliamo Precision e Recall (aggiungiamo un controllo per evitare divisioni per zero)
precision = TP / (TP + FP) if (TP + FP) > 0 else 0
recall = TP / (TP + FN) if (TP + FN) > 0 else 0

print(f"Veri Negativi (TN): {TN}, Falsi Positivi (FP): {FP}")
print(f"Falsi Negativi (FN): {FN}, Veri Positivi (TP): {TP}")
print(f"Precision: {precision:.2f} (ovvero {precision * 100:.1f}%)")
print(f"Recall:    {recall:.2f} (ovvero {recall * 100:.1f}%)")
        </code></pre>
        <p><strong>Risultati attesi a schermo:</strong></p>
        <pre><code class="language-text">Veri Negativi (TN): 58, Falsi Positivi (FP): 3
Falsi Negativi (FN): 2, Veri Positivi (TP): 57
Precision: 0.95 (ovvero 95.0%)
Recall:    0.97 (ovvero 96.6%)
        </code></pre>
        <p><strong>Spiegazione concettuale:</strong></p>
        <p>Nel test set dell'Esercizio 2.4 (120 studenti totali), il modello commette 3 Falsi Positivi (studenti bocciati previsti erroneamente come promossi) e 2 Falsi Negativi (studenti promossi previsti erroneamente come bocciati). Ne consegue una Precision del $95.0\%$ (l'affidabilità delle previsioni positive) e un Recall del $96.6\%$ (la percentuale di promossi reali che siamo riusciti a identificare).</p>
    </div>
</div>

---

### Challenge 4: Simulazione di Early Stopping in Python
*   **Task:** Durante l'addestramento di una rete neurale su 10 iterazioni, registriamo l'errore sul Train Set e sul Validation Set a ogni passaggio. Supponi di avere i seguenti due array con gli errori misurati:
    ```python
    train_errors = [0.95, 0.70, 0.50, 0.35, 0.22, 0.15, 0.10, 0.07, 0.05, 0.03]
    val_errors =   [0.98, 0.75, 0.55, 0.40, 0.30, 0.28, 0.32, 0.38, 0.45, 0.52]
    ```
    Scrivi uno script Python che simula l'algoritmo di **Early Stopping**: scorrendo gli elementi dei due array, deve identificare l'indice dell'iterazione in cui l'errore sul Validation Set smette di scendere e inizia a risalire, e stampare a schermo l'iterazione ottimale salvata (1-indexed) e il relativo valore minimo di Validation Loss.
*   **Domanda:** In quale iterazione si verifica il blocco e qual è la configurazione ottimale salvata?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-lab-early-stopping-code">Visualizza la risoluzione e il codice</p>
    <div class="soluzione" id="sol-lab-early-stopping-code">
        <p><strong>Risoluzione e Codice:</strong></p>
        <pre><code class="language-python"># Definiamo gli array degli errori
train_errors = [0.95, 0.70, 0.50, 0.35, 0.22, 0.15, 0.10, 0.07, 0.05, 0.03]
val_errors   = [0.98, 0.75, 0.55, 0.40, 0.30, 0.28, 0.32, 0.38, 0.45, 0.52]

# Variabili di supporto
miglior_val_loss = float('inf')
miglior_iterazione = -1

# Scorriamo i dati
for idx, val_loss in enumerate(val_errors):
    # Se la loss attuale è migliore, aggiorniamo il record
    if val_loss < miglior_val_loss:
        miglior_val_loss = val_loss
        miglior_iterazione = idx + 1 # Convertiamo in 1-indexed
    else:
        # Se la loss inizia a risalire, l'Early Stopping interviene
        print(f"Overfitting rilevato all'iterazione {idx + 1} (Val Loss: {val_loss:.2f})")
        print("L'addestramento viene interrotto!")
        break

print(f"\nRisultato finale:")
print(f"Iterazione ottimale salvata: {miglior_iterazione}")
print(f"Minima Validation Loss: {miglior_val_loss:.2f}")
        </code></pre>
        <p><strong>Risultati attesi a schermo:</strong></p>
        <pre><code class="language-text">Overfitting rilevato all'iterazione 7 (Val Loss: 0.32)
L'addestramento viene interrotto!

Risultato finale:
Iterazione ottimale salvata: 6
Minima Validation Loss: 0.28
        </code></pre>
        <p><strong>Spiegazione concettuale:</strong></p>
        <p>Fino all'iterazione 6, l'errore del Validation Set scende progressivamente fino a un minimo di <strong>0.28</strong>. All'iterazione 7, l'errore sul Validation sale a <strong>0.32</strong> (mentre la train loss continua a scendere da 0.15 a 0.10). Questo è il segnale classico dell'inizio dell'overfitting. Lo script rileva questa salita, arresta l'addestramento e seleziona come modello migliore quello congelato al termine dell'iterazione 6.</p>
    </div>
</div>
