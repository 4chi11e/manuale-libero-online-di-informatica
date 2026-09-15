---
title: "Laboratorio: Dal Percettore alle Reti Neurali"
description: "Esercitazioni pratiche in Python: implementazione da zero del Percettore (AND vs XOR), addestramento di reti MLP con Scikit-Learn, impatto del Feature Scaling e tracciamento dei confini di decisione curvilinei."
---

Benvenuto nel laboratorio pratico dell'Unità 4 (**Reti Neurali - Dal Percettore al Deep Learning**).

In questo laboratorio:
1. Implementerai da zero in Python puro la regola di aggiornamento del **Percettore di Rosenblatt**, verificando il suo successo sulla porta **AND** e il suo fallimento strutturale sulla porta **XOR**;
2. Addestrerai una **Rete Neurale Multistrato (`MLPClassifier`)** di Scikit-Learn su un dataset non lineare (*Moons*), analizzando la curva di discesa dell'errore (Loss Curve);
3. Verificherai sperimentalmente l'impatto fondamentale del **Feature Scaling (`StandardScaler`)** sulla velocità di convergenza;
4. Traccerai graficamente il **confine di decisione curvilineo** generato dalla rete con Matplotlib.

---

## 1. Configurazione dell'Ambiente

Per eseguire il codice in locale sul tuo computer, assicurati di avere installato le librerie standard:
```bash
pip install numpy matplotlib scikit-learn
```

---

## 2. Esercitazioni Guidate

### Laboratorio A1: Implementazione del Percettore da Zero (Porta AND)
Costruiamo un neurone artificiale elementare in Python puro (senza librerie esterne) e addestriamolo ad apprendere la tabella di verità della porta logica **AND**:
*   $[0, 0] \to 0$
*   $[0, 1] \to 0$
*   $[1, 0] \to 0$
*   $[1, 1] \to 1$

```python
# Definizione del dataset per la porta AND
dataset_and = [
    ([0, 0], 0),
    ([0, 1], 0),
    ([1, 0], 0),
    ([1, 1], 1)
]

# 1. Inizializziamo i parametri a zero
w1, w2 = 0.0, 0.0
b = 0.0
lr = 0.1  # Learning Rate (tasso di apprendimento)

# 2. Funzione di attivazione a gradino (Heaviside)
def step_function(z):
    return 1 if z >= 0 else 0

# 3. Ciclo di addestramento su più epoche
epochs = 15
print("=== ADDESTRAMENTO PERCETTORE: PORTA AND ===")
for epoch in range(epochs):
    errori_epoca = 0
    for x, y_target in dataset_and:
        # A) Somma pesata
        z = w1 * x[0] + w2 * x[1] + b
        # B) Predizione del neurone
        y_pred = step_function(z)
        # C) Calcolo dell'errore
        errore = y_target - y_pred
        errori_epoca += abs(errore)
        # D) Regola di aggiornamento di Rosenblatt
        w1 += lr * errore * x[0]
        w2 += lr * errore * x[1]
        b += lr * errore

    print(f"Epoca {epoch + 1:02d} | Pesi: w1={w1:.2f}, w2={w2:.2f}, b={b:.2f} | Errori: {errori_epoca}")
    if errori_epoca == 0:
        print(f"--> Convergenza raggiunta con successo in {epoch + 1} epoche!\n")
        break
```

---

### Laboratorio A2: La Prova Sperimentale del Limite di Rosenblatt (Porta XOR)
Cosa accade se somministriamo al singolo neurone la tabella della porta **XOR (OR esclusivo)**?

```python
# Definizione del dataset per la porta XOR
dataset_xor = [
    ([0, 0], 0),
    ([0, 1], 1),
    ([1, 0], 1),
    ([1, 1], 0)
]

w1, w2 = 0.0, 0.0
b = 0.0
lr = 0.1

print("=== ADDESTRAMENTO PERCETTORE: PORTA XOR ===")
for epoch in range(20):
    errori_epoca = 0
    for x, y_target in dataset_xor:
        z = w1 * x[0] + w2 * x[1] + b
        y_pred = step_function(z)
        errore = y_target - y_pred
        errori_epoca += abs(errore)
        w1 += lr * errore * x[0]
        w2 += lr * errore * x[1]
        b += lr * errore

    print(f"Epoca {epoch + 1:02d} | Pesi: w1={w1:.2f}, w2={w2:.2f}, b={b:.2f} | Errori: {errori_epoca}")
```

> **Cosa osservi nell'output?**  
> Il ciclo continuerà a oscillare senza mai raggiungere `Errori: 0`. Qualunque sia il numero di epoche, il singolo neurone non convergerà mai: hai appena verificato sperimentalmente il limite teorico di Minsky & Papert del 1969!

---

### Laboratorio B: Classificazione Non Lineare con Rete Multistrato (`MLPClassifier`)
Addestriamo una rete multistrato sul dataset non lineare a due lune intrecciate (**Moons**) e monitoriamo la curva di discesa della funzione di costo (Loss Curve):

```python
import matplotlib.pyplot as plt
from sklearn.datasets import make_moons
from sklearn.model_selection import train_test_split
from sklearn.neural_network import MLPClassifier

# 1. Creazione del dataset non lineare (800 campioni)
X, y = make_moons(n_samples=800, noise=0.20, random_state=42)

# 2. Suddivisione in Training set (80%) e Test set (20%)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# 3. Creazione dell'MLP (due strati nascosti da 16 e 8 neuroni con ReLU)
mlp = MLPClassifier(hidden_layer_sizes=(16, 8),
                    activation='relu',
                    learning_rate_init=0.01,
                    max_iter=500,
                    random_state=42)

# 4. Addestramento con Backpropagation
mlp.fit(X_train, y_train)

# 5. Valutazione dell'accuratezza
acc_train = mlp.score(X_train, y_train)
acc_test = mlp.score(X_test, y_test)
print(f"Accuratezza Train: {acc_train * 100:.1f}%")
print(f"Accuratezza Test:  {acc_test * 100:.1f}%")

# 6. Visualizzazione della Loss Curve
plt.figure(figsize=(8, 4.8))
plt.plot(mlp.loss_curve_, color='#2980b9', linewidth=2.2, label='Funzione di Costo (Loss)')
plt.title("Discesa della Loss durante l'addestramento (Backpropagation)", fontsize=12, fontweight='bold')
plt.xlabel("Iterazioni (Epoche)")
plt.ylabel("Valore della Cross-Entropy Loss")
plt.grid(True, linestyle='--', alpha=0.5)
plt.legend()
plt.tight_layout()
plt.show()
```

---

### Laboratorio C: L'Impatto Cruciale del Feature Scaling (`StandardScaler`)
Per comprendere perché la scalatura è indispensabile nelle reti neurali, generiamo un dataset in cui una feature ha valori compresi tra $18$ e $70$ (es. età) e l'altra tra $15\,000$ e $100\,000$ (es. reddito annuo). Confrontiamo l'addestramento **senza scaling** e **con scaling**:

```python
import numpy as np
from sklearn.preprocessing import StandardScaler
from sklearn.neural_network import MLPClassifier

# Generiamo dati con scale numeriche fortemente sbilanciate
np.random.seed(42)
n = 500
eta = np.random.uniform(18, 70, (n, 1))           # Scala: 10^1
reddito = np.random.uniform(15000, 100000, (n, 1)) # Scala: 10^5
X_grezzo = np.hstack([eta, reddito])
y = (reddito > 45000 + 300 * eta).astype(int).ravel()

# --- Caso 1: Addestramento SENZA Feature Scaling ---
mlp_no_scale = MLPClassifier(hidden_layer_sizes=(16, 8), max_iter=300, random_state=42)
mlp_no_scale.fit(X_grezzo, y)
print(f"[SENZA Scaling] Epoche impiegate: {mlp_no_scale.n_iter_} | Accuratezza: {mlp_no_scale.score(X_grezzo, y)*100:.1f}%")

# --- Caso 2: Addestramento CON StandardScaler ---
scaler = StandardScaler()
X_scalato = scaler.fit_transform(X_grezzo)

mlp_scaled = MLPClassifier(hidden_layer_sizes=(16, 8), max_iter=300, random_state=42)
mlp_scaled.fit(X_scalato, y)
print(f"[CON Scaling]   Epoche impiegate: {mlp_scaled.n_iter_} | Accuratezza: {mlp_scaled.score(X_scalato, y)*100:.1f}%")
```

---

## 3. Coding Challenges

### Challenge 1: Confronto delle Funzioni di Attivazione
*   **Task:** Modifica l'inizializzazione del modello `MLPClassifier` nel **Laboratorio B** impostando a turno le tre funzioni di attivazione viste nella teoria:
    1.  `activation='relu'` (standard de facto per gli strati nascosti)
    2.  `activation='logistic'` (la Sigmoide)
    3.  `activation='tanh'` (la Tangente Iperbolica)
*   **Analisi:** Traccia le curve della Loss per ciascuna funzione di attivazione sullo stesso grafico e confronta il numero di epoche impiegate per raggiungere la convergenza.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-lab-activation">Visualizza la risoluzione e la spiegazione</p>
    <div class="soluzione" id="sol-lab-activation">
        <p><strong>Spiegazione concettuale:</strong></p>
        <ul>
            <li><strong>ReLU (Rectified Linear Unit):</strong> La pendenza costante pari a 1 per valori positivi impedisce la scomparsa del gradiente, permettendo alla rete di convergere molto rapidamente in un numero ridotto di epoche.</li>
            <li><strong>Sigmoide (Logistic):</strong> A causa della <em>saturazione dei gradienti</em> (quando $z$ è grande in valore assoluto la derivata tende a 0), la retropropagazione trasmette correzioni piccolissime, richiedendo molte più iterazioni o bloccandosi prima del minimo ottimale.</li>
            <li><strong>Tangente Iperbolica (tanh):</strong> Essendo centrata sullo zero (intervallo $[-1, 1]$), le attivazioni hanno media nulla, migliorando sensibilmente la convergenza rispetto alla sigmoide, ma risultando comunque mediamente più lenta della ReLU su strati profondi.</li>
        </ul>
    </div>
</div>

---

### Challenge 2: Visualizzare il Confine di Decisione Curvilineo in 2D
*   **Task:** Scrivi una funzione Python che sfrutti `np.meshgrid` e `plt.contourf` per tracciare il confine di decisione appreso dalla rete MLP sul dataset *Moons*.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-lab-boundary">Visualizza il codice della soluzione</p>
    <div class="soluzione" id="sol-lab-boundary">
        <p><strong>Codice Python per disegnare il Confine:</strong></p>
```python
import numpy as np
import matplotlib.pyplot as plt

# Creiamo una griglia fitta di punti
x_min, x_max = X[:, 0].min() - 0.5, X[:, 0].max() + 0.5
y_min, y_max = X[:, 1].min() - 0.5, X[:, 1].max() + 0.5
xx, yy = np.meshgrid(np.linspace(x_min, x_max, 300), np.linspace(y_min, y_max, 300))

# Calcoliamo le predizioni della rete su ogni punto della griglia
Z = mlp.predict(np.c_[xx.ravel(), yy.ravel()]).reshape(xx.shape)

# Disegniamo aree e confine
plt.figure(figsize=(9, 5.5))
plt.contourf(xx, yy, Z, levels=[-0.5, 0.5, 1.5], colors=['#fdedec', '#ebf5fb'], alpha=0.7)
plt.contour(xx, yy, Z, levels=[0.5], colors='#2c3e50', linewidths=2.5)

# Disegniamo i campioni reali
plt.scatter(X[y == 0, 0], X[y == 0, 1], c='#e74c3c', edgecolors='k', label='Classe 0 (●)', s=50)
plt.scatter(X[y == 1, 0], X[y == 1, 1], c='#2980b9', edgecolors='k', label='Classe 1 (▲)', marker='^', s=50)

plt.title("Confine di Decisione Curvilineo appreso dalla Rete MLP", fontsize=12, fontweight='bold')
plt.xlabel("Feature x₁")
plt.ylabel("Feature x₂")
plt.legend()
plt.grid(True, linestyle='--', alpha=0.4)
plt.tight_layout()
plt.show()
```
    </div>
</div>

---

### Challenge 3: Esplorazione della Capacità della Rete (Neuroni Nascosti)
*   **Task:** Cosa succede se riduciamo l'architettura dell'MLP a un solo neurone nascosto (`hidden_layer_sizes=(1,)`)? E cosa succede con una rete più profonda (`hidden_layer_sizes=(32, 32)`)?
*   **Domanda:** Perché una rete con un solo neurone nascosto non riesce a separare le due lune (underfitting), mentre la rete a due strati si adatta perfettamente alla forma curvilinea?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-lab-capacity">Visualizza la risoluzione e l'analisi</p>
    <div class="soluzione" id="sol-lab-capacity">
        <p><strong>Spiegazione:</strong>
        <ul>
            <li>Con <code>hidden_layer_sizes=(1,)</code>, la rete possiede un solo neurone intermedio: non è in grado di piegare lo spazio bidimensionale per creare un confine curvo chiuso e collassa essenzialmente su un confine quasi lineare (<strong>Underfitting</strong>, con accuratezza inferiore all'80%).</li>
            <li>Con <code>hidden_layer_sizes=(32, 32)</code>, la combinazione di 32 neuroni nel primo strato e 32 nel secondo offre sufficienti gradi di libertà non lineari per modellare e avvolgere la traiettoria complessa delle due lune, raggiungendo un'accuratezza sul Test Set vicina al 100%.</li>
        </ul>
        </p>
    </div>
</div>

