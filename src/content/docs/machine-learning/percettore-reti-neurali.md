---
title: "Unità 3: Introduzione alle Reti Neurali - Il Percettore"
description: "L'ispirazione biologica delle reti neurali, la matematica del Percettore di Rosenblatt, l'importanza della non-linearità e le funzioni di attivazione come ReLU e Sigmoide."
---

Nelle unità precedenti abbiamo visto modelli lineari in grado di risolvere relazioni semplici. Tuttavia, i problemi reali (come il riconoscimento d'immagini o del linguaggio) presentano relazioni altamente non lineari. In questa unità introdurremo il mattone fondamentale del **Deep Learning**: il **neurone artificiale** (o **Percettore**), e vedremo come collegare più neuroni per formare una **Rete Neurale**.

---

## 3.1 L'Ispirazione Biologica e il Neurone Artificiale

Le reti neurali artificiali traggono ispirazione dalla struttura del cervello umano. 

*   Nel **cervello umano**, i **dendriti** ricevono segnali elettrici da altri neuroni; il **corpo cellulare** elabora tali impulsi e, se la stimolazione supera una certa soglia, il segnale viene propagato lungo l'**assone** fino alle **sinapsi**, che lo trasmettono ai neuroni successivi.
*   Nel **neurone artificiale**, i dendriti sono rappresentati dagli **input** ($x_i$), il corpo cellulare esegue una **somma pesata** dei segnali d'ingresso pesati ($w_i \cdot x_i$) più un valore di **bias** ($b$), e l'assone/sinapsi è modellato da una **funzione di attivazione** che decide il valore dell'output finale ($a$).

### La Matematica del Percettore (Rosenblatt, 1958)
Il modello matematico del singolo neurone artificiale riceve un vettore di input $x = [x_1, x_2, \dots, x_n]^T$ e produce un output $a$ attraverso due passaggi principali:

1.  **Combinazione Lineare (Somma Pesata $z$):**
    $$z = w_1 \cdot x_1 + w_2 \cdot x_2 + \dots + w_n \cdot x_n + b = \sum_{j=1}^{n} w_j \cdot x_j + b$$
    Dove $w_j$ sono i **pesi** (weights) associati a ciascun input, e $b$ è il **bias**.

2.  **Applicazione della Funzione di Attivazione $f(z)$:**
    $$a = f(z)$$
    L'output $a$ (attivazione del neurone) viene inviato come input ai neuroni successivi.

Nel Percettore originale di Rosenblatt, la funzione di attivazione era una **funzione a gradino di Heaviside**:

$$f(z) = \begin{cases} 1 & \text{se } z \ge 0 \\ 0 & \text{se } z < 0 \end{cases}$$

---

## 3.2 Funzioni di Attivazione e l'Importanza della Non-Linearità

### Perché abbiamo bisogno della non-linearità?
Se non utilizzassimo funzioni di attivazione non lineari, l'intera rete neurale (anche con milioni di strati) si comporterebbe esattamente come un singolo modello lineare. 

In matematica, la composizione di funzioni lineari è ancora una funzione lineare. Ad esempio, se abbiamo due funzioni lineari:
$$f(x) = \alpha \cdot x + \beta \quad \text{e} \quad g(x) = \gamma \cdot x + \delta$$
Componendole si ottiene:
$$f(g(x)) = \alpha(\gamma \cdot x + \delta) + \beta = (\alpha \cdot \gamma) \cdot x + (\alpha \cdot \delta + \beta)$$
La funzione risultante ha sempre la struttura lineare $A \cdot x + B$. Di conseguenza, una rete neurale lineare non potrebbe mai apprendere relazioni complesse (come curve, cerchi, o pattern complessi).

### Funzioni di Attivazione Moderne
Oggi si utilizzano diverse funzioni di attivazione non lineari:

*   **Sigmoide:** $\sigma(z) = \frac{1}{1 + e^{-z}}$. Mappa l'output tra $0$ e $1$. Utile nell'ultimo strato per la classificazione binaria.
*   **ReLU (Rectified Linear Unit):** $f(z) = \max(0, z)$.
    Se l'input $z$ è positivo, restituisce $z$; se è negativo, restituisce $0$. È la funzione più utilizzata negli strati intermedi (nascosti) perché è estremamente veloce da calcolare e facilita l'addestramento.
*   **Tangente Iperbolica (tanh):** $f(z) = \tanh(z) = \frac{e^z - e^{-z}}{e^z + e^{-z}}$. Mappa l'output tra $-1$ e $1$.

---

## 3.3 La Rete Neurale Multistrato (MLP)

Collegando più neuroni in parallelo e in cascata si ottiene una **Rete Neurale Multistrato** (Multi-Layer Perceptron - MLP). I neuroni sono organizzati in tre tipi di strati (layers):

1.  **Strato di Input (Input Layer):** Riceve i dati del dataset (non esegue calcoli).
2.  **Strati Nascosti (Hidden Layers):** Strati intermedi che estraggono caratteristiche via via più astratte dai dati.
3.  **Strato di Output (Output Layer):** Produce la risposta finale della rete (es. una classe o un valore continuo).

---

## 💻 Laboratorio Python (VS Code offline)

Creiamo un notebook Jupyter chiamato `unita3.ipynb`. In questo laboratorio implementeremo **da zero in Python puro** (senza librerie esterne tranne per definire i dati) un Percettore per insegnargli a comportarsi come una **porta logica AND**.

Tabella di verità della porta AND:

| Input $x_1$ | Input $x_2$ | Target $y$ (AND) |
| :---: | :---: | :---: |
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

### Codice del Percettore da Zero

```python
# Definizione del dataset per la porta AND
dataset = [
    ([0, 0], 0),
    ([0, 1], 0),
    ([1, 0], 0),
    ([1, 1], 1)
]

# Inizializziamo pesi e bias a valori piccoli (es. zero)
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
        # 1. Calcolo della combinazione lineare
        z = w1 * x[0] + w2 * x[1] + b
        
        # 2. Calcolo della predizione (output del neurone)
        y_pred = step_function(z)
        
        # 3. Calcolo dell'errore
        errore = y - y_pred
        errore_totale += abs(errore)
        
        # 4. Regola di aggiornamento dei pesi e del bias
        w1 += lr * errore * x[0]
        w2 += lr * errore * x[1]
        b += lr * errore
        
    print(f"Pesi aggiornati: w1={w1:.2f}, w2={w2:.2f}, b={b:.2f} | Errori commessi: {errore_totale}")
    
    # Se non ci sono più errori, possiamo interrompere l'addestramento
    if errore_totale == 0:
        print("L'apprendimento è terminato con successo!")
        break
```

**Output atteso all'ultima epoca:**
```text
Pesi aggiornati: w1=0.20, w2=0.10, b=-0.20 | Errori commessi: 0
L'apprendimento è terminato con successo!
```

---

## 📝 Materiale per la Verifica scritta (Unità 3)

### Esercizi Teorici e Pratici

#### Esercizio 1 (Calcolo Manuale)
Un neurone artificiale ha due ingressi $x_1 = 1.0$ e $x_2 = 0.5$. I pesi associati sono rispettivamente $w_1 = 0.8$ e $w_2 = -1.2$. Il bias è $b = -0.1$.
*   **A)** Calcola la combinazione lineare $z$.
*   **B)** Se la funzione di attivazione è la **ReLU**, quale sarà l'output $a$ del neurone?
*   **C)** E se la funzione di attivazione fosse la **Sigmoide**, quale sarebbe l'output $a$ (approssimato a tre cifre decimali)? *(Usa l'approssimazione $e^{-0.1} \approx 0.905$)*

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-unita3-es1">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-unita3-es1">
        <p><strong>Soluzione:</strong>
        <ul>
            <li><strong>A) Calcolo di $z$:</strong>
                $$z = w_1 \cdot x_1 + w_2 \cdot x_2 + b = 0.8 \cdot 1.0 + (-1.2) \cdot 0.5 + (-0.1)$$
                $$z = 0.8 - 0.6 - 0.1 = 0.1$$
            </li>
            <li><strong>B) Con funzione di attivazione ReLU:</strong>
                $$a = \max(0, z) = \max(0, 0.1) = 0.1$$
            </li>
            <li><strong>C) Con funzione di attivazione Sigmoide:</strong>
                $$a = \sigma(z) = \frac{1}{1 + e^{-0.1}} \approx \frac{1}{1 + 0.905} = \frac{1}{1.905} \approx 0.525$$
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
    <p class="soluzione-toggler" totoggle="#sol-unita3-es2">Visualizza la risposta corretta</p>
    <div class="soluzione" id="sol-unita3-es2">
        <p><strong>Risposta:</strong>
        <ul>
            <li><strong>A)</strong> In due dimensioni, un problema è linearmente separabile se è possibile tracciare una linea retta sul piano cartesiano che separi completamente i punti appartenenti alla classe 0 da quelli della classe 1.</li>
            <li><strong>B)</strong> La porta logica <strong>XOR (OR esclusivo)</strong> non è linearmente separabile. Rappresentando i suoi quattro ingressi su un grafico bidimensionale:
                <ul>
                    <li>Classe 0: $(0,0)$ e $(1,1)$</li>
                    <li>Classe 1: $(0,1)$ e $(1,0)$</li>
                </ul>
                Graficamente, i punti di classe 0 e 1 sono alternati in diagonale; è geometricamente impossibile tracciare un'unica retta che separi i punti neri dai punti bianchi. Per risolvere lo XOR è necessaria una rete con almeno uno strato nascosto (MLP).</li>
        </ul>
        </p>
    </div>
</div>
