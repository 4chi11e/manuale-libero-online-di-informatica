---
title: "Esercizi e Laboratorio di Machine Learning"
description: "Esercitazioni di Machine Learning classico: domande teoriche e di calcolo (carta e penna), laboratori in Python con Scikit-Learn e sfide di programmazione (Coding Challenges)."
---

Benvenuto nella sezione pratica di Machine Learning classico! Questa pagina raccoglie sia gli esercizi di verifica teorica e di calcolo manuale (da svolgere con carta e penna), sia le esercitazioni pratiche di programmazione in Python con le relative sfide.

---

## Parte 1: Esercizi Teorici (Carta e Penna)

Questi esercizi ti consentono di verificare la comprensione dei concetti matematici e logici fondamentali prima di passare alla scrittura del codice.

### 1.1 Modelli Lineari e Regressione
Un modello di regressione lineare ha trovato la seguente retta di regressione: $y = 0.5 \cdot x + 3.8$, dove $x$ rappresenta le ore di studio e $y$ rappresenta il voto finale previsto. 
*   **A)** Qual è il voto previsto per uno studente che studia $5$ ore?
*   **B)** Se uno studente non studia affatto ($x=0$), quale voto prevede il modello? Come si chiama questo parametro nell'equazione del modello?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-teoria-linear">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-teoria-linear">
        <p><strong>Soluzione:</strong>
        <ul>
            <li><strong>A)</strong> Sostituiamo $x=5$ nell'equazione: $y = 0.5 \cdot 5 + 3.8 = 2.5 + 3.8 = 6.3$. Il voto previsto è <strong>6.3</strong>.</li>
            <li><strong>B)</strong> Se $x=0$, $y = 0.5 \cdot 0 + 3.8 = 3.8$. Il voto previsto è <strong>3.8</strong>. Questo parametro rappresenta l'intercetta (in inglese <strong>bias</strong>).</li>
        </ul>
        </p>
    </div>
</div>

---

### 1.2 Modelli di Classificazione e Sigmoide
Per quale motivo per i problemi di classificazione binaria si preferisce la Regressione Logistica rispetto alla Regressione Lineare? Descrivi la funzione matematica utilizzata a questo scopo.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-teoria-logistic">Visualizza la risposta corretta</p>
    <div class="soluzione" id="sol-teoria-logistic">
        <p><strong>Risposta:</strong> La regressione lineare può produrre in output qualsiasi valore numerico reale (anche negativo o superiore a $1$), il che rende impossibile interpretare l'output come una probabilità di appartenenza a una classe binaria ($0$ o $1$). La regressione logistica risolve questo problema introducendo la funzione <strong>Sigmoide</strong> (o logistica):
        $$
        \sigma(z) = \frac{1}{1 + e^{-z}}
        $$
        Questa funzione "schiaccia" qualsiasi valore di input $z$ in un intervallo compreso strettamente tra $0$ e $1$, permettendo di interpretare il risultato come la probabilità che il dato appartenga alla classe target.</p>
    </div>
</div>

---

### 1.3 Ottimizzazione e Discesa del Gradiente
Spiega l'analogia tra la "ricerca della valle nella nebbia" e il funzionamento dell'algoritmo di *Discesa del Gradiente*. Nel formalismo matematico dell'algoritmo, che cosa rappresenta la pendenza del terreno e cosa rappresenta la dimensione del passo?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-teoria-gradiente">Visualizza la risposta corretta</p>
    <div class="soluzione" id="sol-teoria-gradiente">
        <p><strong>Risposta:</strong>
        <ul>
            <li>La <strong>funzione di costo</strong> rappresenta la montagna, dove l'altezza corrisponde all'entità dell'errore (vogliamo raggiungere il punto più basso, ovvero l'errore minimo).</li>
            <li>La <strong>pendenza del terreno</strong> sotto i piedi corrisponde al <strong>Gradiente</strong> ($\nabla L$), che indica la direzione in cui l'errore sale più rapidamente. Per scendere, ci muoviamo nella direzione opposta.</li>
            <li>La <strong>dimensione del passo</strong> corrisponde al <strong>Tasso di Apprendimento / Learning Rate</strong> ($\eta$). Se facciamo passi troppo piccoli (learning rate basso) impiegheremo molto tempo a scendere; se facciamo passi troppo grandi (learning rate alto) rischiamo di scavalcare la valle e risalire sull'altro versante.</li>
        </ul>
        </p>
    </div>
</div>

---

### 1.4 Generalizzazione e Overfitting
Descrivi cos'è l'Overfitting (sovraddestramento) e indica una possibile soluzione basata sul monitoraggio degli errori durante le epoche di addestramento.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-teoria-overfitting">Visualizza la risposta corretta</p>
    <div class="soluzione" id="sol-teoria-overfitting">
        <p><strong>Risposta:</strong> L'Overfitting si verifica quando un modello impara "troppo bene" le anomalie e i rumori specifici del dataset di addestramento (Train set), perdendo la capacità di generalizzare su dati nuovi (Test set). Visivamente, l'accuratezza del Train sale vicina al 100% mentre quella del Test crolla.
        Una possibile soluzione è l'<strong>Arresto Anticipato (Early Stopping)</strong>: si monitora l'errore del test set durante le epoche di addestramento e si interrompe il ciclo non appena l'errore del test smette di scendere e inizia a risalire, conservando i pesi ottimali calcolati in quel punto.</p>
    </div>
</div>

---

### 1.5 Calcolo Pratico della Matrice di Confusione e Metriche
Un modello predittivo per rilevare se una mail è spam ($1$ = Spam, $0$ = Normale) viene testato su $100$ email. La matrice di confusione risultante è la seguente:

```text
[[70  5]
 [10 15]]
```

*   **A)** Identifica i valori di TN, FP, FN e TP.
*   **B)** Calcola l'Accuratezza, la Precisione e la Sensibilità (Recall) del modello.
*   **C)** Se volessi evitare a tutti i costi che una mail importante (non-spam) finisca nella cartella spam del destinatario, a quale metrica dovresti dare priorità per minimizzare questo rischio specifico?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-teoria-metriche-calc">Visualizza la risoluzione dell'esercizio</p>
    <div class="soluzione" id="sol-teoria-metriche-calc">
        <p><strong>Soluzione:</strong>
        <ul>
            <li><strong>A) Dalla matrice ricaviamo:</strong>
                <ul>
                    <li>Vero Negativo (TN) = 70</li>
                    <li>Falso Positivo (FP) = 5</li>
                    <li>Falso Negativo (FN) = 10</li>
                    <li>Vero Positivo (TP) = 15</li>
                </ul>
            </li>
            <li><strong>B) Calcolo delle metriche:</strong>
                <ul>
                    <li>$\text{Accuratezza} = \frac{TP + TN}{\text{Totale}} = \frac{15 + 70}{100} = 0.85 \implies \mathbf{85.0\%}$</li>
                    <li>$\text{Precisione} = \frac{TP}{TP + FP} = \frac{15}{15 + 5} = \frac{15}{20} = 0.75 \implies \mathbf{75.0\%}$</li>
                    <li>$\text{Sensibilità (Recall)} = \frac{TP}{TP + FN} = \frac{15}{15 + 10} = \frac{15}{25} = 0.60 \implies \mathbf{60.0\%}$</li>
                </ul>
            </li>
            <li><strong>C) Priorità clinica/operativa:</strong>
                Per evitare che mail normali vengano classificate erroneamente come spam, dobbiamo ridurre al minimo i Falsi Positivi (FP). Guardando le formule, la metrica che dobbiamo massimizzare è la <strong>Precisione</strong> (infatti a denominatore c'è FP: più FP è basso, più la precisione si avvicina al 100%). Un'alta precisione garantisce che quasi tutto ciò che viene classificato come spam lo sia veramente, proteggendo le mail importanti dall'essere perse.</li>
        </ul>
        </p>
    </div>
</div>

---

### 1.6 Diagnosi di Overfitting e Underfitting (Casi Studio)
Associa a ciascuno dei seguenti scenari di addestramento lo stato corretto del modello, scegliendo tra: *Generalizzazione Corretta*, *Overfitting*, *Underfitting Strutturale* o *Underfitting da Mancato Addestramento*. Motivando brevemente la risposta:

*   **Caso A:** Un modello lineare per stimare i prezzi delle case mostra un errore (Loss) molto elevato sia sul Train Set ($0.55$) sia sul Validation Set ($0.56$). Cambiando il Learning Rate o addestrando per più tempo l'errore non scende.
*   **Caso B:** Una rete neurale addestrata per $5$ iterazioni mostra un errore del $0.48$ sul Train Set e del $0.49$ sul Validation Set. Aumentando le iterazioni a $500$, l'errore sul Train scende a $0.08$ e sul Validation a $0.09$.
*   **Caso C:** Un modello mostra un errore sul Train Set vicinissimo allo zero ($0.01$), ma sul Validation Set e sul Test Set l'errore schizza a $0.85$.
*   **Caso D:** Un modello mostra un errore sul Train Set pari a $0.10$ e sul Validation Set pari a $0.11$, mantenendosi stabile anche sul Test Set ($0.11$).

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-teoria-diagnosi">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-teoria-diagnosi">
        <p><strong>Soluzione:</strong>
        <ul>
            <li><strong>Caso A: Underfitting Strutturale.</strong> L'errore è elevato su entrambi i set e non cambia modificando i parametri di addestramento ($\eta$ o iterazioni). Significa che il modello è troppo semplice per rappresentare la complessità dei dati.</li>
            <li><strong>Caso B: Underfitting da Mancato Addestramento.</strong> L'errore iniziale era alto, ma è sceso notevolmente aumentando il numero di iterazioni. Il modello era semplicemente sotto-addestrato nelle prime fasi.</li>
            <li><strong>Caso C: Overfitting.</strong> Il modello ha memorizzato i dati di addestramento (errore quasi nullo sul Train), ma fallisce completamente nel generalizzare su dati nuovi (errore altissimo su Validation/Test).</li>
            <li><strong>Caso D: Generalizzazione Corretta.</strong> Il modello mostra errori bassi e simili sia sui dati di addestramento sia su dati non visti (Validation/Test), dimostrando di aver imparato le regole generali.</li>
        </ul>
        </p>
    </div>
</div>

---

### 1.7 Proporzioni e Suddivisione dei Dataset
*   **A)** Perché l'utilizzo del Test Set a ogni iterazione per effettuare l'Early Stopping rappresenta un errore metodologico? Come si chiama questo errore?
*   **B)** Un team di Data Science sta lavorando su un dataset medico con $800$ pazienti totali. Un altro team sta addestrando una rete neurale per la guida autonoma su un dataset di $5.000.000$ di immagini. Quali proporzioni di suddivisione (Train/Validation/Test) consiglieresti a ciascuno dei due team? Motiva la scelta.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-teoria-proporzioni">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-teoria-proporzioni">
        <p><strong>Soluzione:</strong>
        <ul>
            <li><strong>A)</strong> Usare il Test Set per l'Early Stopping crea **Data Leakage** (contaminazione). Anche se il modello non aggiorna i pesi usando il Test Set, noi umani stiamo selezionando l'iterazione ottimale basandoci sulle prestazioni di test. In questo modo le prestazioni finali sul Test Set risulteranno ottimistiche e non rappresenteranno più una misura imparziale su dati futuri.</li>
            <li><strong>B) Consigli per la suddivisione:</strong>
                <ul>
                    <li><strong>Team Medico (800 pazienti):</strong> Consigliata una suddivisione **70% Train / 15% Validation / 15% Test** (o **80/10/10**). Con soli 800 pazienti, dedicare il 15% significa avere 120 pazienti sia nel Validation che nel Test. Se usassimo percentuali più piccole (es. 1%), avremmo solo 8 pazienti nei set di controllo, rendendo le misure di errore instabili e soggette al caso.</li>
                    <li><strong>Team Guida Autonoma (5.000.000 immagini):</strong> Consigliata una suddivisione **98% Train / 1% Validation / 1% Test** (o persino **99% / 0.5% / 0.5%**). Con 5 milioni di immagini, l'1% equivale a 50.000 immagini: una quantità enorme, ampiamente sufficiente per testare il modello. Destinare il 15% al test (750.000 immagini) sarebbe uno spreco inutile di dati che potrebbero invece essere usati per migliorare l'addestramento.</li>
                </ul>
            </li>
        </ul>
        </p>
    </div>
</div>

---

## Parte 2: Laboratori Python (VS Code offline)

Ti consigliamo di svolgere questi esercizi in locale nel tuo notebook Jupyter `laboratorio_ml.ipynb`.

### 2.1 Regressione Lineare: Dati Hardcoded
In questo esercizio, utilizzeremo un numero ridotto di dati inseriti direttamente nel codice.

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

### 2.2 Regressione Lineare: Caricamento da file CSV
In questo esercizio caricheremo un dataset di 100 studenti salvato in un file CSV esterno e disegneremo i dati e la retta di regressione.

#### 1. Scarica il Dataset
*   Scarica il file cliccando su: [studenti_voti.csv](/manuale-libero-online-di-informatica/assets/documenti/studenti_voti.csv) e salvalo nella cartella del notebook.

#### 2. Esegui il codice
```python
import pandas as pd
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score
import matplotlib.pyplot as plt

# A. Carichiamo i dati dal file CSV
df = pd.read_csv("studenti_voti.csv")

# B. Prepariamo le variabili per Scikit-Learn
# NOTA: Usiamo df[["ore_studio"]] con le DOPPIE parentesi per estrarre la colonna 
# sotto forma di DataFrame bidimensionale (matrice), richiesto per la feature X.
X = df[["ore_studio"]]
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

# Personalizziamo il grafico
plt.xlabel("Ore di Studio Settimanali")
plt.ylabel("Voto dell'Esame (1-10)")
plt.title("Regressione Lineare: Ore di Studio vs Voto Conseguito")
plt.grid(True, linestyle="--", alpha=0.5)
plt.legend()
plt.show()
```

---

### 2.3 Regressione Logistica: Dati Hardcoded
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

### 2.4 Regressione Logistica: Suddivisione Train/Test e Valutazione Completa
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

## Parte 3: Sfide di Programmazione (Coding Challenge)

Mettiti alla prova modificando ed estendendo il codice Python scritto finora sul tuo notebook.

### Challenge 3.1: L'effetto del Bias (Regressione Lineare)
*   **Task:** Modifica l'inizializzazione del modello di regressione lineare nella **Parte 2 (Esercizio 2.1)** impostando il parametro `fit_intercept=False`:
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

### Challenge 3.2: Soglia Decisionale Personalizzata (Regressione Logistica)
*   **Task:** Utilizza il modello addestrato nella **Parte 2 (Esercizio 2.3)**. Scrivi uno script Python che estrae le probabilità della classe 1 per il test set dal vettore `y_prob` (prodotto da `clf.predict_proba(X_test)`) e applica manualmente la soglia decisionale di $0.8$ per determinare la classe prevista (1 se probabilità $\ge 0.8$, altrimenti 0).
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

### Challenge 3.3: Calcolo delle metriche Precision e Recall da codice
*   **Task:** Utilizza la matrice di confusione `cm` calcolata sul test set della **Parte 2 (Esercizio 2.4)**. Scompatta i quattro valori usando il metodo `.ravel()` di NumPy:
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

### Challenge 3.4: Simulazione di Early Stopping in Python
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
