---
title: "Esercizi Teorici: Il Percettore e Reti Neurali"
description: "Esercizi di calcolo manuale e domande teoriche su Percettore di Rosenblatt, separabilità lineare, funzioni di attivazione, architetture MLP, epoche/batch e Backpropagation."
---

Questi esercizi ti consentono di verificare la comprensione approfondita dei concetti teorici della quarta unità (**Reti Neurali - Dal Percettore al Deep Learning**) prima di passare alla scrittura del codice in Python.

---

### Esercizio 1: Calcolo Manuale di un Neurone Artificiale
Un neurone artificiale ha due ingressi $x_1 = 1.0$ e $x_2 = 0.5$. I pesi associati sono rispettivamente $w_1 = 0.8$ e $w_2 = -1.2$. Il bias è $b = -0.1$.
*   **A)** Calcola la combinazione lineare (somma pesata) $z$.
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

---

### Esercizio 2: Calcolo di un Passo di Apprendimento del Percettore (Regola di Rosenblatt)
Considera un Percettore di Rosenblatt a due ingressi con funzione di attivazione a gradino (Heaviside step function: output 1 se $z \ge 0$, altrimenti 0).
Lo stato attuale dei parametri è:
$$
w_1 = 0.3, \quad w_2 = -0.4, \quad b = 0.1, \quad \text{Learning Rate } \eta = 0.1
$$
Il modello riceve il campione $x = [2.0, 1.0]$ la cui etichetta reale è $y = 1$.

*   **A)** Calcola la somma pesata $z$ e la predizione attuale $\hat{y}$.
*   **B)** Calcola l'errore commesso $(y - \hat{y})$.
*   **C)** Applica la regola di aggiornamento di Rosenblatt per calcolare i nuovi valori dei pesi $w_1', w_2'$ e del bias $b'$.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-unita4-es-rosenblatt">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-unita4-es-rosenblatt">
        <p><strong>Soluzione:</strong>
        <ul>
            <li><strong>A) Somma pesata e predizione:</strong>
                $$
                z = w_1 x_1 + w_2 x_2 + b = (0.3 \cdot 2.0) + (-0.4 \cdot 1.0) + 0.1 = 0.6 - 0.4 + 0.1 = 0.3
                $$
                Poiché $z = 0.3 \ge 0$, la funzione a gradino restituisce $\hat{y} = 1$.
            </li>
            <li><strong>B) Calcolo dell'errore:</strong>
                $$
                \text{Errore} = y - \hat{y} = 1 - 1 = 0
            $$
            </li>
            <li><strong>C) Aggiornamento dei parametri:</strong>
                Poiché l'errore è pari a 0 (la predizione era corretta), nessun peso viene modificato:
                $$
                w_1' = 0.3, \quad w_2' = -0.4, \quad b' = 0.1
                $$
            </li>
        </ul>
        <em>Nota didattica:</em> Se il target fosse stato $y = 0$, l'errore sarebbe stato $-1$, e i pesi sarebbero stati corretti: $w_1' = 0.3 + 0.1 \cdot (-1) \cdot 2.0 = 0.1$.
        </p>
    </div>
</div>

---

### Esercizio 3: Teoria dei Limiti e Logica del Percettore
Il Percettore semplice di Rosenblatt è in grado di classificare correttamente solo problemi che sono **linearmente separabili**. 
*   **A)** Spiega cosa significa "linearmente separabile" in uno spazio a due dimensioni.
*   **B)** Quale porta logica elementare (tra AND, OR, XOR) **non** è linearmente separabile e di conseguenza non può essere appresa da un singolo Percettore? Spiega il perché.
*   **C)** Quale conseguenza storica ebbe la dimostrazione di questo limite da parte di Minsky e Papert nel 1969?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-unita4-es2">Visualizza la risposta corretta</p>
    <div class="soluzione" id="sol-unita4-es2">
        <p><strong>Risposta:</strong>
        <ul>
            <li><strong>A)</strong> In due dimensioni, un problema è linearmente separabile se è possibile tracciare una linea retta sul piano cartesiano che separi completamente tutti i punti appartenenti alla classe 0 da quelli della classe 1.</li>
            <li><strong>B)</strong> La porta logica <strong>XOR (OR esclusivo)</strong> non è linearmente separabile. Sul piano cartesiano:
                <ul>
                    <li>Classe 0: $(0,0)$ e $(1,1)$</li>
                    <li>Classe 1: $(0,1)$ e $(1,0)$</li>
                </ul>
                I punti delle due classi sono disposti a croce/diagonali alternate; qualsiasi retta tracciata sul piano lascerà sempre almeno un punto nel semipiano errato. Per separare lo XOR servono almeno due rette distinte (ovvero una rete multistrato MLP).</li>
            <li><strong>C)</strong> Poiché all'epoca non si conosceva un algoritmo matematico per addestrare reti composte da più strati (la Backpropagation fu resa celebre solo nel 1986), la dimostrazione provocò il blocco dei finanziamenti alla ricerca, aprendo il primo <strong>Inverno dell'AI (AI Winter)</strong>.</li>
        </ul>
        </p>
    </div>
</div>

---

### Esercizio 4: Calcolo Aritmetico su Epoche, Batch e Iterazioni
Un dataset di visione artificiale contiene **$60\,000$ immagini** di addestramento. Si decide di addestrare una rete neurale impostando un **batch size di $128$** per un totale di **$25$ epoche**.

*   **A)** Quante iterazioni (aggiornamenti dei pesi) vengono eseguite durante **1 singola epoca**? *(Arrotonda per eccesso all'intero più vicino se l'ultimo batch è incompleto)*
*   **B)** Quanti aggiornamenti complessivi dei pesi verranno eseguiti al termine dell'intero addestramento ($25$ epoche)?
*   **C)** Se decidiamo di raddoppiare la dimensione del batch portandola a **$256$**, il numero di iterazioni per epoca aumenterà o diminuirà? Perché?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-unita4-es-batch">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-unita4-es-batch">
        <p><strong>Soluzione:</strong>
        <ul>
            <li><strong>A) Iterazioni per epoca:</strong>
                $$
                \frac{60\,000 \text{ campioni}}{128 \text{ campioni per batch}} = 468.75 \implies \mathbf{469 \text{ iterazioni per epoca}}
                $$
                (468 batch completi da 128 immagini più 1 ultimo batch residuo da 96 immagini).
            </li>
            <li><strong>B) Iterazioni complessive in 25 epoche:</strong>
                $$
                469 \text{ iterazioni/epoca} \times 25 \text{ epoche} = \mathbf{11\,725 \text{ iterazioni totali}}
                $$
            </li>
            <li><strong>C) Con batch size = 256:</strong>
                $$
                \frac{60\,000}{256} = 234.375 \implies \mathbf{235 \text{ iterazioni per epoca}}
                $$
                Il numero di iterazioni **si dimezza**. Un batch più grande elabora più dati contemporaneamente (sfruttando meglio il parallelismo delle GPU), producendo stime del gradiente più stabili ma riducendo il numero di volte in cui i pesi vengono aggiornati durante un'epoca.
            </li>
        </ul>
        </p>
    </div>
</div>

---

### Esercizio 5: Calcolo Matriciale di un MLP a Due Strati (Forward Pass)
Considera una piccola rete MLP con:
*   **Vettore di Input ($1 \times 2$):** $x = [2, -1]$
*   **Strato Nascosto (2 neuroni con attivazione ReLU):**
    $$
    W^{(1)} = \begin{bmatrix} 0.5 & -0.2 \\ 1.0 & 0.4 \end{bmatrix}, \quad b^{(1)} = [0.1, -0.3]
    $$
*   **Strato di Output (1 neurone con attivazione Sigmoide):**
    $$
    W^{(2)} = \begin{bmatrix} 0.8 \\ -1.5 \end{bmatrix}, \quad b^{(2)} = [0.2]
    $$

*   **A)** Calcola la combinazione lineare $z^{(1)} = x \cdot W^{(1)} + b^{(1)}$.
*   **B)** Calcola le attivazioni nascoste $h = \text{ReLU}\big(z^{(1)}\big)$.
*   **C)** Calcola l'uscita $z^{(2)} = h \cdot W^{(2)} + b^{(2)}$ e la predizione finale $\hat{y} = \sigma\big(z^{(2)}\big)$. *(Usa $e^{-0.28} \approx 0.756$)*

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-unita4-es-mlp-matrix">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-unita4-es-mlp-matrix">
        <p><strong>Soluzione:</strong>
        <ul>
            <li><strong>A) Calcolo di $z^{(1)}$ (Strato Nascosto):</strong>
                $$
                z_1^{(1)} = (2 \cdot 0.5) + (-1 \cdot 1.0) + 0.1 = 1.0 - 1.0 + 0.1 = 0.1
                $$
                $$
                z_2^{(1)} = (2 \cdot -0.2) + (-1 \cdot 0.4) + (-0.3) = -0.4 - 0.4 - 0.3 = -1.1
                $$
                Quindi $z^{(1)} = [0.1, -1.1]$.
            </li>
            <li><strong>B) Attivazione con ReLU ($h = \max(0, z)$):</strong>
                $$
                h_1 = \max(0, 0.1) = 0.1
                $$
                $$
                h_2 = \max(0, -1.1) = 0.0
                $$
                Quindi il vettore delle attivazioni è $h = [0.1, 0.0]$. *(Il secondo neurone è rimasto spento)*.
            </li>
            <li><strong>C) Calcolo dell'Output Finale:</strong>
                $$
                z^{(2)} = (h_1 \cdot 0.8) + (h_2 \cdot -1.5) + 0.2 = (0.1 \cdot 0.8) + (0.0 \cdot -1.5) + 0.2 = 0.08 + 0 + 0.2 = 0.28
                $$
                Applicando la Sigmoide:
                $$
                \hat{y} = \sigma(0.28) = \frac{1}{1 + e^{-0.28}} \approx \frac{1}{1 + 0.756} = \frac{1}{1.756} \approx \mathbf{0.569}
                $$
            </li>
        </ul>
        </p>
    </div>
</div>

---

### Esercizio 6: La Funzione Softmax per Classificazione Multi-classe
Una rete neurale per il riconoscimento di 3 specie di fiori emette, prima dell'attivazione finale, i seguenti tre punteggi grezzi (logit):
$$
z_1 = 2.0, \quad z_2 = 1.0, \quad z_3 = 0.0
$$
*(Dati: $e^2 \approx 7.39$, $e^1 \approx 2.72$, $e^0 = 1.00$)*

*   **A)** Calcola la probabilità associata a ciascuna delle tre classi applicando la formula di Softmax:
    $$
    \text{Softmax}(z_i) = \frac{e^{z_i}}{\sum_{j=1}^{3} e^{z_j}}
    $$
*   **B)** Verifica che la somma delle tre probabilità sia pari al $100\%$ ($1.0$).
*   **C)** Quale specie verrà scelta come predizione finale dal modello?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-unita4-es-softmax">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-unita4-es-softmax">
        <p><strong>Soluzione:</strong>
        <ul>
            <li><strong>A) Calcolo della somma degli esponenziali:</strong>
                $$
                \text{Somma} = e^{2.0} + e^{1.0} + e^{0.0} \approx 7.39 + 2.72 + 1.00 = 11.11
                $$
                Probabilità per ciascuna classe:
                $$
                P(\text{Classe 1}) = \frac{7.39}{11.11} \approx \mathbf{0.665} \quad (66.5\%)
                $$
                $$
                P(\text{Classe 2}) = \frac{2.72}{11.11} \approx \mathbf{0.245} \quad (24.5\%)
                $$
                $$
                P(\text{Classe 3}) = \frac{1.00}{11.11} \approx \mathbf{0.090} \quad (9.0\%)
                $$
            </li>
            <li><strong>B) Verifica della somma:</strong>
                $$
                0.665 + 0.245 + 0.090 = \mathbf{1.000} \quad (100\%)
                $$
            </li>
            <li><strong>C) Predizione finale:</strong>
                Il modello assegna il campione alla **Classe 1**, avendo ottenuto la probabilità più alta ($66.5\%$).
            </li>
        </ul>
        </p>
    </div>
</div>

---

### Esercizio 7: La Regola della Catena (Chain Rule) e la Backpropagation
Spiega in quale fase dell'apprendimento di una rete neurale si applica la *Regola della Catena (Chain Rule)* delle derivate e perché essa è di fondamentale importanza per l'addestramento degli strati nascosti.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-unita4-teoria2">Visualizza la risposta corretta</p>
    <div class="soluzione" id="sol-unita4-teoria2">
        <p><strong>Risposta:</strong> La Regola della Catena si applica durante la fase di <strong>Retropropagazione (Backpropagation)</strong>. È fondamentale perché i neuroni negli strati nascosti (intermedi) non hanno un errore direttamente misurabile rispetto al target finale (non sappiamo a priori quale valore esatto dovrebbe assumere un neurone interno). La regola della catena permette di calcolare la derivata parziale dell'errore finale rispetto a qualsiasi peso interno $w$, "scomponendola" nel prodotto delle derivate degli strati a valle:
        $$
        \frac{\partial \mathcal{L}}{\partial w_{\text{nascosto}}} = \frac{\partial \mathcal{L}}{\partial \hat{y}} \cdot \frac{\partial \hat{y}}{\partial z_{\text{out}}} \cdot \frac{\partial z_{\text{out}}}{\partial h} \cdot \frac{\partial h}{\partial z_{\text{nas}}} \cdot \frac{\partial z_{\text{nas}}}{\partial w_{\text{nascosto}}}
        $$
        In questo modo l'errore calcolato all'uscita viene retropropagato fino al primissimo strato di pesi, rendendone possibile la correzione mirata.</p>
    </div>
</div>

---

### Esercizio 8: Perché il Feature Scaling è Obbligatorio nelle Reti Neurali?
Confronta il funzionamento di un **Albero di Decisione** con quello di una **Rete Neurale** per spiegare perché la scalatura preliminare delle variabili (es. con `StandardScaler`) è facoltativa negli alberi ma assolutamente indispensabile nelle reti neurali.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-unita4-scaling">Visualizza la risposta corretta</p>
    <div class="soluzione" id="sol-unita4-scaling">
        <p><strong>Risposta:</strong>
        <ul>
            <li><strong>Negli Alberi di Decisione:</strong> Ogni nodo esegue un test su una sola feature alla volta (es. <code>if età &gt; 30</code> oppure <code>if stipendio &gt; 50.000</code>). Le feature non vengono mai sommate tra loro né moltiplicate per pesi numerici condivisi. Di conseguenza, l'ordine di grandezza non influenza minimamente la posizione ottimale del taglio.</li>
            <li><strong>Nelle Reti Neurali:</strong> Tutte le feature di input $x_1, x_2, \dots, x_n$ vengono sommate all'interno della stessa combinazione lineare $z = w_1 x_1 + w_2 x_2 + b$. Se una feature ha valori molto grandi (es. stipendio $50\,000$) e un'altra valori piccoli (es. età $0.35$), i gradienti associati alla prima variabile domineranno completamente l'aggiornamento dei pesi, deformando lo spazio dell'errore e provocando forti oscillazioni numeriche che rallentano o impediscono la convergenza della discesa del gradiente.</li>
        </ul>
        </p>
    </div>
</div>

