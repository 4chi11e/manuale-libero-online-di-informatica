---
title: "Laboratorio: Dal Percettore alle Reti Neurali"
description: "Esercitazioni pratiche in Python: implementazione da zero di un Percettore AND e addestramento di una Rete Neurale Multistrato con Scikit-Learn."
---

Benvenuto nel laboratorio pratico dell'Unità 4. Qui implementerai un Percettore logico da zero in Python per comprenderne la logica degli aggiornamenti matematici, e addestrerai un classificatore neurale multistrato (MLP) su un dataset non lineare.

---

## 1. Configurazione
Ti consigliamo di svolgere questo laboratorio in locale sul tuo computer, salvando il codice in uno script Python o in un notebook Jupyter locale.

---

## 2. Esecuzione del Laboratorio

### Laboratorio A: Implementazione di un Percettore da Zero (AND)
Costruiremo un neurone artificiale elementare in Python puro (senza librerie esterne) e gli insegneremo la funzione logica AND:
*   $[0, 0] \to 0$
*   $[0, 1] \to 0$
*   $[1, 0] \to 0$
*   $[1, 1] \to 1$

```python
# Definizione del dataset per la porta AND
dataset = [
    ([0, 0], 0),
    ([0, 1], 0),
    ([1, 0], 0),
    ([1, 1], 1)
]

# Inizializziamo pesi e bias a zero
w1, w2 = 0.0, 0.0
b = 0.0

# Tasso di apprendimento (learning rate)
lr = 0.1

# Funzione di attivazione a gradino
def step_function(z):
    return 1 if z >= 0 else 0

# Ciclo di addestramento (Epochs)
epochs = 10
for epoch in range(epochs):
    print(f"--- Epoca {epoch + 1} ---")
    errore_totale = 0
    
    for x, y in dataset:
        # 1. Somma pesata
        z = w1 * x[0] + w2 * x[1] + b
        
        # 2. Output del neurone (funzione a gradino)
        y_pred = step_function(z)
        
        # 3. Calcolo dell'errore (target - previsto)
        errore = y - y_pred
        errore_totale += abs(errore)
        
        # 4. Regola di aggiornamento di Rosenblatt
        w1 += lr * errore * x[0]
        w2 += lr * errore * x[1]
        b += lr * errore
        
    print(f"Pesi: w1={w1:.2f}, w2={w2:.2f}, b={b:.2f} | Errori commessi: {errore_totale}")
    
    # Interrompiamo se non ci sono più errori
    if errore_totale == 0:
        print("L'apprendimento della porta AND è terminato con successo!")
        break
```

---

### Laboratorio B: Classificazione con Rete Neurale Multistrato (Scikit-Learn)
Addestreremo un modello `MLPClassifier` (Multi-Layer Perceptron) sul dataset non-lineare **Moons** (mezzelune intrecciate) e tracceremo la discesa dell'errore.

```python
import matplotlib.pyplot as plt
from sklearn.datasets import make_moons
from sklearn.model_selection import train_test_split
from sklearn.neural_network import MLPClassifier

# 1. Generiamo il dataset non-lineare Moons (600 campioni)
X, y = make_moons(n_samples=600, noise=0.2, random_state=42)

# 2. Dividiamo in Train e Test set (80/20)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# 3. Creiamo l'MLPClassifier
# hidden_layer_sizes=(8, 8): definisce due strati nascosti da 8 neuroni ciascuno
mlp = MLPClassifier(hidden_layer_sizes=(8, 8), 
                    learning_rate_init=0.01, 
                    max_iter=400, 
                    random_state=42)

# 4. Addestriamo la rete neurale
mlp.fit(X_train, y_train)

# 5. Valutiamo le prestazioni
tasso_train = mlp.score(X_train, y_train)
tasso_test = mlp.score(X_test, y_test)

print(f"Accuratezza sul Train Set: {tasso_train * 100:.1f}%")
print(f"Accuratezza sul Test Set:  {tasso_test * 100:.1f}%")

# 6. Grafico della Loss Curve (Curva di errore decrescente)
plt.figure(figsize=(8, 5))
plt.plot(mlp.loss_curve_, color='#a38cf4', linewidth=2)
plt.title("Andamento della Loss (Costo) durante l'addestramento")
plt.xlabel("Epoca (Iterazione)")
plt.ylabel("Valore della Loss")
plt.grid(True, linestyle='--', alpha=0.6)
plt.show()
```

---

## 3. Coding Challenges

Mettiti alla prova modificando ed estendendo il codice scritto finora.

### Challenge 1: Confronto delle Funzioni di Attivazione
*   **Task:** Modifica l'inizializzazione del modello `MLPClassifier` nel **Laboratorio B** impostando una funzione di attivazione differente rispetto a quella predefinita (ReLU). Prova ad impostare la funzione sigmoide (`activation='logistic'`) e successivamente la tangente iperbolica (`activation='tanh'`).
*   **Domanda:** Esegui nuovamente il codice per ciascuna configurazione. Quante epoche sono necessarie affinché la rete converga? Qual è la differenza di accuratezza sul Test Set?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-lab-activation">Visualizza la risoluzione e la spiegazione</p>
    <div class="soluzione" id="sol-lab-activation">
        <p><strong>Spiegazione concettuale:</strong></p>
        <ul>
            <li>La funzione predefinita di Scikit-Learn è la <strong>ReLU</strong>. Essendo lineare per tutti i valori positivi e nulla per quelli negativi, calcola i gradienti all'indietro in modo estremamente rapido, consentendo alla rete di convergere in circa 100-150 epoche con un'elevata accuratezza.</li>
            <li>Impostando <code>activation='logistic'</code> (la Sigmoide), noterai che la rete impiega un numero significativamente superiore di epoche per convergere (spesso superando le 300 o 400 iterazioni) o registra un'accuratezza leggermente inferiore a parità di epoche. Questo accade a causa del fenomeno della **saturazione dei gradienti**: quando gli input sono molto alti o molto bassi, la pendenza della sigmoide si appiattisce vicino allo zero, rendendo la retropropagazione dell'errore (Backpropagation) estremamente lenta ed inefficace.</li>
            <li>La tangente iperbolica (<code>activation='tanh'</code>) si comporta meglio della sigmoide poiché è centrata sullo zero (il che accelera l'aggiornamento dei pesi), ma risulta comunque meno efficiente e reattiva rispetto alla ReLU sui dataset reali.</li>
        </ul>
    </div>
</div>
