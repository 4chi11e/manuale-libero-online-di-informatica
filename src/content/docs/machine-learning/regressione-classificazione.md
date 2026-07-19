---
title: "Unità 2: Primi Modelli - Regressione e Classificazione"
description: "Studio della Regressione Lineare e Logistica con scikit-learn, metriche di valutazione come MSE e R² e comprensione della matrice di confusione."
---

Dopo aver visto come organizzare e suddividere i dati, in questa seconda unità vedremo come addestrare i nostri primi modelli predittivi usando la libreria **Scikit-Learn**. Affronteremo i due compiti principali dell'apprendimento supervisionato: la **regressione** e la **classificazione**.

---

## 2.1 Regressione Lineare (Prevedere valori continui)

Il modello più semplice e intuitivo per fare regressione è la **Regressione Lineare**. L'obiettivo è trovare una relazione lineare (una linea retta) che leghi la feature indipendente $x$ al target continuo $y$.

L'equazione matematica di una retta con una sola feature è:

$$y = w \cdot x + b$$

Dove:
*   $w$ (in matematica chiamato coefficiente angolare $m$) rappresenta il **peso** (weight) assegnato alla feature. Determina la pendenza della retta.
*   $b$ (in matematica chiamato intercetta $q$) rappresenta il **bias** (o termine noto). È il valore di $y$ quando $x = 0$.

### La Funzione di Costo: Mean Squared Error (MSE)
Come fa l'algoritmo a capire qual è la "retta migliore"? Cerca di minimizzare l'errore commesso. Per misurare questo errore, si calcola l'**Errore Quadratico Medio (Mean Squared Error - MSE)**:

$$MSE = \frac{1}{N} \sum_{i=1}^{N} (y_i - \hat{y}_i)^2$$

Dove:
*   $N$ è il numero totale di campioni nel dataset.
*   $y_i$ è il valore reale (il target effettivo del campione $i$).
*   $\hat{y}_i$ (letto *y-hat*) è il valore previsto dal modello per il campione $i$ ($\hat{y}_i = w \cdot x_i + b$).
*   La differenza $(y_i - \hat{y}_i)$ è il **residuo** (l'errore individuale). Elevandolo al quadrato, si evitano compensazioni tra errori positivi e negativi e si penalizzano maggiormente gli errori più grandi.

---

## 2.2 Classificazione con la Regressione Logistica

Sebbene contenga il termine "regressione" nel nome, la **Regressione Logistica** è un algoritmo utilizzato per problemi di **classificazione binaria** (prevedere se un dato appartiene alla classe $0$ o alla classe $1$).

Se usassimo la regressione lineare per la classificazione, potremmo ottenere valori di output esterni all'intervallo $[0, 1]$ (ad esempio $-0.5$ o $1.8$), che non hanno senso come probabilità.
La regressione logistica risolve questo problema applicando all'output lineare una funzione matematica chiamata **funzione Sigmoide** (o logistica):

$$\sigma(z) = \frac{1}{1 + e^{-z}}$$

Dove $z = w \cdot x + b$. La curva sigmoidea ha una forma a "S" che mappa qualsiasi valore reale in un intervallo compreso strettamente tra $0$ e $1$:

*   Se $z$ è molto grande e positivo, $e^{-z} \to 0$, quindi $\sigma(z) \to 1$.
*   Se $z$ è molto grande e negativo, $e^{-z} \to +\infty$, quindi $\sigma(z) \to 0$.
*   Se $z = 0$, $e^{0} = 1$, quindi $\sigma(z) = 0.5$.

### Soglia Decisionale
Il valore restituito dalla sigmoide rappresenta la **probabilità** che il campione appartenga alla classe $1$. Per prendere la decisione finale (classe $0$ o $1$), si definisce una soglia decisionale (di solito $0.5$):

$$\text{Classe prevista} = \begin{cases} 1 & \text{se } \sigma(z) \ge 0.5 \\ 0 & \text{se } \sigma(z) < 0.5 \end{cases}$$

---

## 💻 Laboratorio Python (VS Code offline)

Crea un notebook chiamato `unita2.ipynb` ed esegui i passaggi seguenti.

### Parte 1: Laboratorio di Regressione Lineare
Vogliamo prevedere il voto finale di uno studente basandoci sul numero di ore di studio settimanali.

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

*   **Nota**: Il coefficiente $R^2$ (R-quadrato) varia tra $0$ e $1$. Più è vicino a $1$, migliore è la capacità del modello di spiegare la variabilità dei dati (un valore di $1$ indica una previsione perfetta).

### Parte 2: Laboratorio di Regressione Logistica
Prevediamo se uno studente supererà o meno l'esame ($1$ o $0$) basandoci sulle ore di studio e sulla percentuale di presenze.

```python
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, confusion_matrix

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
y_prob = clf.predict_proba(X_test)  # Restituisce le probabilità di classe 0 e classe 1

print(f"Previsioni per gli studenti di test: {y_pred}")
print(f"Probabilità stimate (Classe 0 vs Classe 1):\n{y_prob}")
print(f"Accuratezza sul test set: {accuracy_score(y_test, y_pred) * 100:.1f}%")
```

### Valutazione: La Matrice di Confusione
Per comprendere in dettaglio gli errori commessi da un classificatore, si analizza la **Matrice di Confusione**, che incrocia le classi reali con quelle previste:

```python
cm = confusion_matrix(y_test, y_pred)
print("Matrice di Confusione:")
print(cm)
```

La matrice ha questa struttura:

| | Previsto $0$ | Previsto $1$ |
| :--- | :---: | :---: |
| **Reale $0$** | **Vero Negativo (TN)** | **Falso Positivo (FP)** |
| **Reale $1$** | **Falso Negativo (FN)** | **Vero Positivo (VP)** |

*   **Vero Negativo (TN):** Campioni reali $0$ previsti correttamente come $0$.
*   **Falso Positivo (FP):** Campioni reali $0$ previsti erroneamente come $1$ (Errore di tipo I).
*   **Falso Negativo (FN):** Campioni reali $1$ previsti erroneamente come $0$ (Errore di tipo II).
*   **Vero Positivo (VP):** Campioni reali $1$ previsti correttamente come $1$.

---

## 📝 Materiale per la Verifica scritta (Unità 2)

### Domande Teoriche e di Calcolo

#### Domanda 1
Un modello di regressione lineare ha trovato la seguente retta di regressione: $y = 0.5 \cdot x + 3.8$, dove $x$ rappresenta le ore di studio e $y$ rappresenta il voto finale previsto. 
*   **A)** Qual è il voto previsto per uno studente che studia $5$ ore?
*   **B)** Se uno studente non studia affatto ($x=0$), quale voto prevede il modello? Come si chiama questo parametro nell'equazione del modello?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-unita2-teoria1">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-unita2-teoria1">
        <p><strong>Soluzione:</strong>
        <ul>
            <li><strong>A)</strong> Sostituiamo $x=5$ nell'equazione: $y = 0.5 \cdot 5 + 3.8 = 2.5 + 3.8 = 6.3$. Il voto previsto è <strong>6.3</strong>.</li>
            <li><strong>B)</strong> Se $x=0$, $y = 0.5 \cdot 0 + 3.8 = 3.8$. Il voto previsto è <strong>3.8</strong>. Questo parametro rappresenta l'intercetta (in inglese <strong>bias</strong>).</li>
        </ul>
        </p>
    </div>
</div>

#### Domanda 2
Per quale motivo per i problemi di classificazione binaria si preferisce la Regressione Logistica rispetto alla Regressione Lineare? Descrivi la funzione matematica utilizzata a questo scopo.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-unita2-teoria2">Visualizza la risposta corretta</p>
    <div class="soluzione" id="sol-unita2-teoria2">
        <p><strong>Risposta:</strong> La regressione lineare può produrre in output qualsiasi valore numerico reale (anche negativo o superiore a $1$), il che rende impossibile interpretare l'output come una probabilità di appartenenza a una classe binaria ($0$ o $1$). La regressione logistica risolve questo problema introducendo la funzione <strong>Sigmoide</strong> (o logistica):
        $$\sigma(z) = \frac{1}{1 + e^{-z}}$$
        Questa funzione "schiaccia" qualsiasi valore di input $z$ in un intervallo compreso strettamente tra $0$ e $1$, permettendo di interpretare il risultato come la probabilità che il dato appartenga alla classe target.</p>
    </div>
</div>

---

### Esercizio Pratico sulla Matrice di Confusione
Un modello diagnostico è stato testato su $100$ pazienti per rilevare una patologia ($1$ = Malato, $0$ = Sano). I risultati del test sono riassunti nella seguente matrice di confusione:

```text
[[75  5]
 [ 8 12]]
```

*   **A)** Identifica il numero di Veri Negativi (TN), Falsi Positivi (FP), Falsi Negativi (FN) e Veri Positivi (VP).
*   **B)** Calcola l'**Accuratezza** del modello, definita come la frazione di previsioni corrette sul totale dei casi:
$$\text{Accuratezza} = \frac{VP + TN}{VP + TN + FP + FN}$$
*   **C)** Se fossi un medico, saresti più preoccupato dei $5$ falsi positivi o degli $8$ falsi negativi? Giustifica la risposta basandoti sul significato clinico.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-unita2-pratico1">Visualizza la risoluzione dell'esercizio</p>
    <div class="soluzione" id="sol-unita2-pratico1">
        <p><strong>Soluzione:</strong>
        <ul>
            <li><strong>A)</strong> Dalla matrice di confusione ricaviamo:
                <ul>
                    <li>Veri Negativi (TN) = 75</li>
                    <li>Falsi Positivi (FP) = 5</li>
                    <li>Falsi Negativi (FN) = 8</li>
                    <li>Veri Positivi (VP) = 12</li>
                </ul>
            </li>
            <li><strong>B)</strong> Calcoliamo l'accuratezza:
                $$\text{Accuratezza} = \frac{12 + 75}{12 + 75 + 5 + 8} = \frac{87}{100} = 0.87 \text{ (ovvero 87.0\%)}$$
            </li>
            <li><strong>C)</strong> In campo medico, i <strong>falsi negativi (8 pazienti)</strong> sono molto più preoccupanti. Un falso negativo rappresenta un paziente effettivamente malato che il modello classifica come sano, con il rischio che non riceva le cure necessarie. Un falso positivo comporta esami di controllo aggiuntivi, ma non mette direttamente a rischio la vita del paziente per mancata diagnosi.</li>
        </ul>
        </p>
    </div>
</div>
