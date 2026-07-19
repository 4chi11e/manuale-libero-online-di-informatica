---
title: "Unità 4: Come Apprende una Rete - Retropropagazione e MLP"
description: "Studio del ciclo di apprendimento di una rete neurale, discesa del gradiente, retropropagazione (Backpropagation) e utilizzo di MLPClassifier in scikit-learn."
---

Abbiamo visto la struttura di una rete neurale e come i singoli neuroni elaborano le informazioni per produrre una previsione. Ma come fa una rete a trovare i pesi ($w$) e i bias ($b$) ottimali in modo autonomo? In questa unità studieremo l'algoritmo fondamentale dietro l'addestramento delle reti neurali: la **Retropropagazione** (Backpropagation) combinata con la **Discesa del Gradiente**.

---

## 4.1 Il Ciclo di Apprendimento e la Funzione di Costo

L'addestramento di una rete neurale è un processo iterativo diviso in tre fasi principali che si ripetono per molte epoche (epoch):

1.  **Propagazione in Avanti (Forward Propagation):** I dati di input viaggiano attraverso la rete dallo strato di input a quello di output, producendo una predizione $\hat{y}$.
2.  **Calcolo del Costo (Loss/Cost Function):** Si confronta la predizione $\hat{y}$ con il valore reale $y$ per calcolare l'errore commesso. La funzione di costo quantifica "quanto è pessima" la rete.
3.  **Propagazione all'Indietro (Backpropagation) e Aggiornamento:** L'errore viene propagato all'indietro per calcolare come modificare i pesi e i bias per ridurre l'errore al ciclo successivo.

---

## 4.2 La Discesa del Gradiente (Gradient Descent)

Immagina di trovarti sulla cima di una montagna nebbiosa e di voler raggiungere la valle (il punto di minimo della funzione di costo) senza poter vedere il panorama. L'unica cosa che puoi percepire sotto i tuoi piedi è la pendenza del terreno. Un'ottima strategia consiste nel fare piccoli passi nella direzione in cui il terreno scende più rapidamente.

Nelle reti neurali facciamo esattamente lo stesso:

*   Il **Gradiente** ($\nabla L$) è un vettore matematico che indica la direzione di massima salita della funzione di costo rispetto ai parametri.
*   Per minimizzare il costo, aggiorniamo ogni peso $w$ muovendoci nella direzione **opposta** al gradiente:

$$w \leftarrow w - \eta \cdot \frac{\partial L}{\partial w}$$

Dove:
*   $\frac{\partial L}{\partial w}$ è la derivata parziale della funzione di costo rispetto al peso $w$. Indica la pendenza della curva di errore.
*   $\eta$ (la lettera greca *eta*) è il **Tasso di Apprendimento** (Learning Rate). Regola la lunghezza del "passo" che facciamo ad ogni aggiornamento.

### L'Importanza del Learning Rate ($\eta$)

Scegliere il corretto valore del learning rate è cruciale:
*   **Troppo piccolo:** I passi sono minuscoli. La rete impiegherà moltissimo tempo ad addestrarsi, rischiando di rimanere bloccata in minimi locali.
*   **Troppo grande:** I passi sono eccessivi. La rete rischia di saltare oltre il minimo globale, oscillando continuamente o addirittura divergendo (l'errore cresce anziché diminuire).

---

## 4.3 La Retropropagazione (Backpropagation)

Per aggiornare i pesi di un neurone situato negli strati interni (nascosti), dobbiamo capire come il cambiamento di quel singolo peso influenzi l'errore finale all'uscita della rete. 

La **Retropropagazione** (Backpropagation) risolve questo problema applicando in modo sistematico la **Regola della Catena (Chain Rule)** delle derivate. 

L'algoritmo calcola i gradienti partendo dall'errore sull'output e li propaga a ritroso strato dopo strato:

$$\frac{\partial L}{\partial w_{nascosto}} = \frac{\partial L}{\partial \text{Output}} \cdot \frac{\partial \text{Output}}{\partial \text{Nascosto}} \cdot \frac{\partial \text{Nascosto}}{\partial w_{nascosto}}$$

Grazie a questo metodo, la rete calcola in modo estremamente efficiente la derivata dell'errore rispetto a ciascun singolo peso e bias presente nel modello.

---

## 💻 Laboratorio Python (VS Code offline)

In questo laboratorio useremo la classe `MLPClassifier` (Multi-Layer Perceptron) di Scikit-Learn per classificare un dataset bidimensionale non lineare generato sinteticamente chiamato **"Moons"** (due mezzelune intrecciate).

Crea un notebook Jupyter chiamato `unita4.ipynb` ed esegui il seguente codice.

### Classificazione di Dati Non Lineari

```python
import matplotlib.pyplot as plt
from sklearn.datasets import make_moons
from sklearn.model_selection import train_test_split
from sklearn.neural_network import MLPClassifier

# 1. Generiamo un dataset non-lineare a forma di due mezze lune intrecciate
X, y = make_moons(n_samples=600, noise=0.2, random_state=42)

# 2. Dividiamo in Train e Test set (80/20)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# 3. Creiamo l'MLPClassifier
# hidden_layer_sizes=(8, 8): definisce due strati nascosti da 8 neuroni ciascuno
# learning_rate_init=0.01: imposta il tasso di apprendimento iniziale (eta)
# max_iter=400: numero massimo di epoche di addestramento
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
print(f"Accuratezza sul Test Set: {tasso_test * 100:.1f}%")
```

### Visualizzazione della Curva di Perdita (Loss Curve)
Possiamo tracciare come l'errore del modello scende epoca dopo epoca. Questo ci mostra visivamente la discesa del gradiente in azione.

```python
# Grafico della Loss Curve
plt.figure(figsize=(8, 5))
plt.plot(mlp.loss_curve_, color='#a38cf4', linewidth=2)
plt.title("Andamento della Funzione di Costo (Loss) durante l'addestramento")
plt.xlabel("Epoca (Iterazione)")
plt.ylabel("Valore della Loss")
plt.grid(True, linestyle='--', alpha=0.6)
plt.show()
```

---

## 📝 Materiale per la Verifica scritta (Unità 4)

### Domande Teoriche

#### Domanda 1
Spiega l'analogia tra la "ricerca della valle nella nebbia" e il funzionamento dell'algoritmo di *Discesa del Gradiente*. Nel formalismo matematico dell'algoritmo, che cosa rappresenta la pendenza del terreno e cosa rappresenta la dimensione del passo?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-unita4-teoria1">Visualizza la risposta corretta</p>
    <div class="soluzione" id="sol-unita4-teoria1">
        <p><strong>Risposta:</strong>
        <ul>
            <li>La <strong>funzione di costo</strong> rappresenta la montagna, dove l'altezza corrisponde all'entità dell'errore (vogliamo raggiungere il punto più basso, ovvero l'errore minimo).</li>
            <li>La <strong>pendenza del terreno</strong> sotto i piedi corrisponde al <strong>Gradiente</strong> ($\nabla L$), che indica la direzione in cui l'errore sale più rapidamente. Per scendere, ci muoviamo nella direzione opposta.</li>
            <li>La <strong>dimensione del passo</strong> corrisponde al <strong>Learning Rate</strong> ($\eta$). Se facciamo passi troppo piccoli (learning rate basso) impiegheremo molto tempo a scendere; se facciamo passi troppo grandi (learning rate alto) rischiamo di scavalcare la valle e risalire sull'altro versante.</li>
        </ul>
        </p>
    </div>
</div>

#### Domanda 2
Spiega in quale fase dell'apprendimento di una rete neurale si applica la *Regola della Catena (Chain Rule)* delle derivate e perché essa è di fondamentale importanza per l'addestramento degli strati nascosti.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-unita4-teoria2">Visualizza la risposta corretta</p>
    <div class="soluzione" id="sol-unita4-teoria2">
        <p><strong>Risposta:</strong> La Regola della Catena si applica durante la fase di <strong>Retropropagazione (Backpropagation)</strong>. È fondamentale perché i neuroni negli strati nascosti (intermedi) non hanno un errore direttamente misurabile rispetto al target finale (non sappiamo direttamente quale debba essere l'attivazione esatta di un neurone nascosto). La regola della catena permette di calcolare la derivata parziale dell'errore finale rispetto a un peso interno, "scomponendola" nel prodotto delle derivate degli strati successivi. In questo modo l'errore misurato all'uscita viene retropropagato fino al primo strato di pesi.</p>
    </div>
</div>

---

### Esercizio di Analisi di Grafici (Overfitting)
Immagina di addestrare una rete neurale complessa per 1000 epoche e di registrare l'accuratezza sul Train Set e sul Test Set. Ad un certo punto osservi il seguente andamento:
*   Fino all'epoca 200, sia l'accuratezza di Train sia quella di Test crescono costantemente (da 50% a 92%).
*   Dall'epoca 200 in poi, l'accuratezza di Train continua a salire fino a raggiungere il 99%, mentre l'accuratezza di Test inizia a scendere progressivamente fino a raggiungere l'82%.

*   **A)** Identifica quale fenomeno si sta verificando a partire dall'epoca 200. Spiegane il motivo.
*   **B)** A quale epoca sarebbe stato ideale interrompere l'addestramento? Come si chiama questa tecnica di regolarizzazione?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-unita4-pratico1">Visualizza la risoluzione dell'esercizio</p>
    <div class="soluzione" id="sol-unita4-pratico1">
        <p><strong>Soluzione:</strong>
        <ul>
            <li><strong>A)</strong> Si sta verificando il fenomeno dell'<strong>Overfitting</strong> (sovraddestramento). A partire dall'epoca 200, la rete smette di apprendere pattern generali utili per la predizione e inizia a "memorizzare" i dettagli specifici e il rumore presenti esclusivamente nel dataset di Train. Questo fa sì che le sue prestazioni sui dati di addestramento migliorino, ma la sua capacità di generalizzazione su dati nuovi (Test set) peggiori.</li>
            <li><strong>B)</strong> Sarebbe stato ideale fermarsi intorno all'<strong>epoca 200</strong>, nel punto in cui l'accuratezza del test set raggiunge il suo valore massimo prima di iniziare a decrescere. Questa tecnica di arresto basata sul monitoraggio dell'errore di convalida/test si chiama <strong>Early Stopping</strong> (Arresto Anticipato).</li>
        </ul>
        </p>
    </div>
</div>
