---
title: "Unità 4: Reti Neurali - Dal Percettore al Deep Learning"
description: "L'ispirazione biologica delle reti neurali, la matematica del Percettore, la retropropagazione dell'errore (Backpropagation) e l'addestramento di reti neurali MLP con Scikit-Learn."
---

Nelle unità precedenti abbiamo visto modelli lineari e logistici in grado di risolvere relazioni semplici. Tuttavia, i problemi del mondo reale (come il riconoscimento d'immagini, del linguaggio o la classificazione di dati altamente curvilinei) presentano relazioni non lineari complesse che una semplice retta o sigmoide non possono separare.

In questa unità introdurremo il mattone fondamentale del **Deep Learning**: il **neurone artificiale** (o **Percettore**), vedremo come collegare più neuroni per formare una **Rete Neurale Multistrato** e studieremo l'algoritmo di **Retropropagazione (Backpropagation)** che ne permette l'apprendimento.

---

## 3.1 L'Ispirazione Biologica e il Neurone Artificiale

Le reti neurali artificiali traggono ispirazione dalla struttura del cervello umano. 

*   Nel **cervello umano**, i **dendriti** ricevono segnali elettrici da altri neuroni; il **corpo cellulare** elabora tali impulsi e, se la stimolazione supera una certa soglia, il segnale viene propagato lungo l'**assone** fino alle **sinapsi**, che lo trasmettono ai neuroni successivi.
*   Nel **neurone artificiale**, i dendriti sono rappresentati dagli **input** ($x_i$), il corpo cellulare esegue una **somma pesata** dei segnali d'ingresso pesati ($w_i \cdot x_i$) più un valore di **bias** ($b$), e l'assone/sinapsi è modellato da una **funzione di attivazione** che decide il valore dell'output finale ($a$).

### La Matematica del Percettore (Rosenblatt, 1958)
Il modello matematico del singolo neurone artificiale riceve un vettore di input $x = [x_1, x_2, \dots, x_n]^T$ e produce un output $a$ attraverso due passaggi principali:

1.  **Combinazione Lineare (Somma Pesata $z$):**
    $$
    z = w_1 \cdot x_1 + w_2 \cdot x_2 + \dots + w_n \cdot x_n + b = \sum_{j=1}^{n} w_j \cdot x_j + b
    $$
    Dove $w_j$ sono i **pesi** (weights) associati a ciascun input, e $b$ è il **bias**.

2.  **Applicazione della Funzione di Attivazione $f(z)$:**
    $$
    a = f(z)
    $$
    L'output $a$ (attivazione del neurone) viene inviato come input ai neuroni successivi.

Nel Percettore originale di Rosenblatt, la funzione di attivazione era una **funzione a gradino di Heaviside**:

$$
f(z) = \begin{cases} 1 & \text{se } z \ge 0 \\ 0 & \text{se } z < 0 \end{cases}
$$

---

## 3.2 Funzioni di Attivazione e l'Importanza della Non-Linearità

### Perché abbiamo bisogno della non-linearità?
Se non utilizzassimo funzioni di attivazione non lineari, l'intera rete neurale (anche con milioni di strati) si comporterebbe esattamente come un singolo modello lineare. 

In matematica, la composizione di funzioni lineari è ancora una funzione lineare. Ad esempio, se abbiamo due funzioni lineari:
$$
f(x) = \alpha \cdot x + \beta \quad \text{e} \quad g(x) = \gamma \cdot x + \delta
$$
Componendole si ottiene:
$$
f(g(x)) = \alpha(\gamma \cdot x + \delta) + \beta = (\alpha \cdot \gamma) \cdot x + (\alpha \cdot \delta + \beta)
$$
La funzione risultante ha sempre la struttura lineare $A \cdot x + B$. Di conseguenza, una rete neurale lineare non potrebbe mai apprendere relazioni complesse (come curve, cerchi, o pattern complessi).

### Funzioni di Attivazione Moderne
Oggi si utilizzano diverse funzioni di attivazione non lineari:

*   **Sigmoide:** $\sigma(z) = \frac{1}{1 + e^{-z}}$. Mappa l'output tra $0$ e $1$. Utile nell'ultimo strato per la classificazione binaria.
*   **ReLU (Rectified Linear Unit):** $f(z) = \max(0, z)$. Se l'input $z$ è positivo, restituisce $z$; se è negativo, restituisce $0$. È la funzione più utilizzata negli strati intermedi (nascosti) perché è velocissima da calcolare e facilita l'addestramento velocizzando la convergenza.
*   **Tangente Iperbolica (tanh):** $f(z) = \tanh(z) = \frac{e^z - e^{-z}}{e^z + e^{-z}}$. Mappa l'output tra $-1$ e $1$.

---

## 3.3 Il limite del singolo neurone (Il problema dello XOR)

Il Percettore semplice a singolo neurone è in grado di classificare correttamente solo problemi che sono **linearmente separabili** (ovvero dove le classi possono essere separate sul piano da una linea retta).

Questo limite storico, descritto da Minsky e Papert nel 1969, portò al primo "inverno dell'Intelligenza Artificiale". Sebbene un singolo neurone possa apprendere le porte logiche **AND** e **OR**, esso fallisce sistematicamente con la porta logica **XOR (OR esclusivo)**.

Tabella di verità dello XOR:

| Input $x_1$ | Input $x_2$ | Target $y$ (XOR) |
| :---: | :---: | :---: |
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

Rappresentando graficamente i punti dello XOR su un piano cartesiano, si nota come le classi $0$ e $1$ si trovino alternate in diagonale. È geometricamente impossibile tracciare un'unica retta che separi i punti di classe 0 dai punti di classe 1.

---

## 3.4 La Rete Neurale Multistrato (MLP)

Per risolvere problemi non linearmente separabili (come lo XOR), dobbiamo collegare più neuroni in parallelo e in cascata, formando una **Rete Neurale Multistrato** (Multi-Layer Perceptron - MLP). 

I neuroni sono organizzati in tre tipi di strati (layers):

1.  **Strato di Input (Input Layer):** Riceve le caratteristiche del dataset (non esegue calcoli).
2.  **Strati Nascosti (Hidden Layers):** Strati intermedi (nascosti all'esterno) che estraggono caratteristiche via via più astratte e complesse dai dati.
3.  **Strato di Output (Output Layer):** Produce la risposta finale della rete (es. una probabilità o un valore continuo).

---

## 3.5 Come Apprende una Rete: Forward Propagation e Backpropagation

L'addestramento di una rete neurale multistrato avviene ripetendo per molte epoche un ciclo composto da tre fasi principali:

### 1. Propagazione in Avanti (Forward Propagation)
I dati di input viaggiano attraverso la rete dallo strato di input, passando per gli strati nascosti (dove vengono calcolate somme pesate e funzioni di attivazione), fino allo strato di output, producendo la predizione finale $\hat{y}$.

### 2. Calcolo del Costo (Loss Function)
Si confronta la predizione $\hat{y}$ con il valore reale $y$ per calcolare l'errore commesso tramite una funzione di costo (come la Log Loss per la classificazione).

### 3. Retropropagazione (Backpropagation)
È l'algoritmo chiave del Deep Learning. Per capire come modificare i pesi dei neuroni situati negli strati nascosti (che non sono direttamente collegati all'output), l'errore viene propagato all'indietro strato dopo strato.

Per fare questo, la retropropagazione applica in modo sistematico la **Regola della Catena (Chain Rule)** delle derivate.

Ad esempio, se vogliamo capire come un peso $w_{nascosto}$ in uno strato nascosto influenzi l'errore finale $L$, calcoliamo la derivata parziale moltiplicando le pendenze degli strati successivi:

$$
\frac{\partial L}{\partial w_{nascosto}} = \frac{\partial L}{\partial \text{Output}} \cdot \frac{\partial \text{Output}}{\partial \text{Nascosto}} \cdot \frac{\partial \text{Nascosto}}{\partial w_{nascosto}}
$$

Una volta calcolato questo gradiente per ogni singolo peso e bias della rete, i parametri vengono aggiornati usando la discesa del gradiente.

---

## 3.6 Laboratorio Python (VS Code offline)

In questa parte pratica svolgeremo due laboratori: nel primo scriveremo da zero un Percettore elementare per comprenderne l'algoritmo di apprendimento; nel secondo useremo Scikit-Learn per addestrare una rete neurale multistrato complessa su un dataset non lineare.

### Laboratorio A: Implementazione di un Percettore da Zero (Porta AND)
Implementiamo **in Python puro** (senza librerie) un singolo Percettore per insegnargli la porta logica AND.

Tabella di verità della porta AND:
*   $[0,0] \to 0$
*   $[0,1] \to 0$
*   $[1,0] \to 0$
*   $[1,1] \to 1$

Crea un file chiamato `percettore_and.py` o inserisci in `unita3.ipynb`:

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
        
        # 2. Output del neurone
        y_pred = step_function(z)
        
        # 3. Calcolo dell'errore
        errore = y - y_pred
        errore_totale += abs(errore)
        
        # 4. Regola di aggiornamento
        w1 += lr * errore * x[0]
        w2 += lr * errore * x[1]
        b += lr * errore
        
    print(f"Pesi: w1={w1:.2f}, w2={w2:.2f}, b={b:.2f} | Errori commessi: {errore_totale}")
    
    # Interrompiamo se non ci sono più errori
    if errore_totale == 0:
        print("L'apprendimento della porta AND è terminato con successo!")
        break
```

**Output atteso all'ultima epoca:**
```text
Pesi: w1=0.20, w2=0.10, b=-0.20 | Errori commessi: 0
L'apprendimento della porta AND è terminato con successo!
```

---

### Laboratorio B: Classificazione Non Lineare con MLPClassifier (Scikit-Learn)
Addestriamo una rete neurale multistrato (`MLPClassifier`) di Scikit-Learn per classificare un dataset bidimensionale non lineare chiamato **"Moons"** (due mezzelune intrecciate) e visualizziamo la discesa della curva di errore (loss curve).

Aggiungi questa cella nel tuo notebook ed eseguila:

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
# learning_rate_init=0.01: tasso di apprendimento iniziale
# max_iter=400: numero massimo di epoche
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

## 3.7 Esercizi

### Domande Teoriche e Calcoli Manuali

#### Esercizio 1 (Calcolo Manuale)
Un neurone artificiale ha due ingressi $x_1 = 1.0$ e $x_2 = 0.5$. I pesi associati sono rispettivamente $w_1 = 0.8$ e $w_2 = -1.2$. Il bias è $b = -0.1$.
*   **A)** Calcola la combinazione lineare $z$.
*   **B)** Se la funzione di attivazione è la **ReLU**, quale sarà l'output $a$ del neurone?
*   **C)** E se la funzione di attivazione fosse la **Sigmoide**, quale sarebbe l'output $a$ (approssimato a tre cifre decimali)? *(Usa l'approssimazione $e^{-0.1} \approx 0.905$)*

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-unita4-es1">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-unita4-es1">
        <p><strong>Soluzione:</strong>
        <ul>
            <li><strong>A) Calcolo di $z$:</strong>
                $$
                z = w_1 \cdot x_1 + w_2 \cdot x_2 + b = 0.8 \cdot 1.0 + (-1.2) \cdot 0.5 + (-0.1)
                $$
                $$
                z = 0.8 - 0.6 - 0.1 = 0.1
                $$
            </li>
            <li><strong>B) Con funzione di attivazione ReLU:</strong>
                $$
                a = \max(0, z) = \max(0, 0.1) = 0.1
                $$
            </li>
            <li><strong>C) Con funzione di attivazione Sigmoide:</strong>
                $$
                a = \sigma(z) = \frac{1}{1 + e^{-0.1}} \approx \frac{1}{1 + 0.905} = \frac{1}{1.905} \approx 0.525
                $$
            </li>
        </ul>
        </p>
    </div>
</div>

#### Esercizio 2 (Teoria dei Limiti e Logica)
Il Percettore semplice di Rosenblatt è in grado di classificare correttamente solo problemi che sono **linearmente separabili**. 
*   **A)** Spiega cosa significa "linearmente separabile" in uno spazio a due dimensioni.
*   **B)** Quale porta logica elementare (tra AND, OR, XOR) **non** è linearmente separabile e di conseguenza non può essere appresa da un singolo Percettore? Spiega il perché.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-unita4-es2">Visualizza la risposta corretta</p>
    <div class="soluzione" id="sol-unita4-es2">
        <p><strong>Risposta:</strong>
        <ul>
            <li><strong>A)</strong> In due dimensioni, un problema è linearmente separabile se è possibile tracciare una linea retta sul piano cartesiano che separi completamente i punti appartenenti alla classe 0 da quelli della classe 1.</li>
            <li><strong>B)</strong> La porta logica <strong>XOR (OR esclusivo)</strong> non è linearmente separabile. Rappresentando i suoi quattro ingressi su un grafico bidimensionale:
                <ul>
                    <li>Classe 0: $(0,0)$ e $(1,1)$</li>
                    <li>Classe 1: $(0,1)$ e $(1,0)$</li>
                </ul>
                Graficamente, i punti di classe 0 e 1 sono alternati in diagonale; è geometricamente impossibile tracciare un'unica retta che separi i punti di classe 0 da quelli di classe 1. Per risolvere lo XOR è necessaria una rete con almeno uno strato nascosto (MLP).</li>
        </ul>
        </p>
    </div>
</div>

#### Domanda 3
Spiega in quale fase dell'apprendimento di una rete neurale si applica la *Regola della Catena (Chain Rule)* delle derivate e perché essa è di fondamentale importanza per l'addestramento degli strati nascosti.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-unita4-teoria2">Visualizza la risposta corretta</p>
    <div class="soluzione" id="sol-unita4-teoria2">
        <p><strong>Risposta:</strong> La Regola della Catena si applica durante la fase di <strong>Retropropagazione (Backpropagation)</strong>. È fondamentale perché i neuroni negli strati nascosti (intermedi) non hanno un errore direttamente misurabile rispetto al target finale (non sappiamo quale debba essere l'attivazione esatta di un neurone interno). La regola della catena permette di calcolare la derivata parziale dell'errore finale rispetto a un peso interno, "scomponendola" nel prodotto delle derivate degli strati successivi. In questo modo l'errore misurato all'uscita viene retropropagato fino al primo strato di pesi della rete, rendendone possibile l'aggiornamento.</p>
    </div>
</div>
