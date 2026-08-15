---
title: "Esercizi Teorici: Il Percettore e Reti Neurali"
description: "Esercizi di calcolo e domande teoriche sulla retropropagazione dell'errore, funzioni di attivazione e limiti di separabilità lineare del Percettore."
---

Questi esercizi ti consentono di verificare la comprensione dei concetti teorici fondamentali della quarta unità (Reti Neurali - Dal Percettore al Deep Learning) prima di passare alla scrittura del codice.

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

### Esercizio 2: Teoria dei Limiti e Logica del Percettore
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

---

### Esercizio 3: La Regola della Catena (Chain Rule) e la Backpropagation
Spiega in quale fase dell'apprendimento di una rete neurale si applica la *Regola della Catena (Chain Rule)* delle derivate e perché essa è di fondamentale importanza per l'addestramento degli strati nascosti.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-unita4-teoria2">Visualizza la risposta corretta</p>
    <div class="soluzione" id="sol-unita4-teoria2">
        <p><strong>Risposta:</strong> La Regola della Catena si applica durante la fase di <strong>Retropropagazione (Backpropagation)</strong>. È fondamentale perché i neuroni negli strati nascosti (intermedi) non hanno un errore direttamente misurabile rispetto al target finale (non sappiamo quale debba essere l'attivazione esatta di un neurone interno). La regola della catena permette di calcolare la derivata parziale dell'errore finale rispetto a un peso interno, "scomponendola" nel prodotto delle derivate degli strati successivi. In questo modo l'errore misurato all'uscita viene retropropagato fino al primo strato di pesi della rete, rendendone possibile l'aggiornamento.</p>
    </div>
</div>
