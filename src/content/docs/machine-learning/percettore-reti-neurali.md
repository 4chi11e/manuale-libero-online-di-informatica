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

## 3.6 Esercizi e Laboratorio Pratico

Per mettere in pratica le conoscenze acquisite in questa unità sul Percettore e sulle reti neurali multistrato, consulta la sezione pratica del manuale:

*   **Teoria e Calcolo (Carta e Penna)**:
    *   [Esercizi Teorici: Il Percettore e Reti Neurali](file:///f:/Progetti%20Github/Manuale_Libero_Online_di_Informatica/Repository-manuale/src/content/docs/machine-learning/esercizi-teorici-percettore-reti-neurali.md)
*   **Esercitazione in Python (Scikit-Learn)**:
    *   [Laboratorio: Dal Percettore alle Reti Neurali](file:///f:/Progetti%20Github/Manuale_Libero_Online_di_Informatica/Repository-manuale/src/content/docs/machine-learning/laboratorio-percettore-reti-neurali.md)
