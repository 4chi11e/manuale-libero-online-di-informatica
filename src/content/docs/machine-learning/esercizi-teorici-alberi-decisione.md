---
title: "Esercizi Teorici: Alberi di Decisione e Random Forest"
description: "Esercizi teorici e di calcolo (carta e penna) sull'impurezza di Gini, la struttura degli alberi di decisione, e le strategie di regolarizzazione contro l'overfitting."
---

Questi esercizi ti consentono di verificare la comprensione dei concetti teorici fondamentali della terza unità (Alberi di Decisione e Random Forest) prima di passare alla scrittura del codice.

---

### Esercizio 1: Calcolo manuale dell'Impurezza di Gini
Dato un nodo contenente **15 campioni totali**, di cui **12** appartengono alla classe $1$ (Spam) e **3** appartengono alla classe $0$ (Normale):
*   **A)** Calcola l'impurezza di Gini del nodo.
*   **B)** Se il nodo contenesse 15 campioni tutti appartenenti alla classe 1, quale sarebbe il valore dell'impurezza di Gini? Come viene definito un nodo con questo valore?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-tree-gini">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-tree-gini">
        <p><strong>Risoluzione:</strong>
        <ul>
            <li><strong>A) Calcolo dell'impurezza:</strong>
                Le proporzioni delle classi sono:
                $p_1 = \frac{12}{15} = 0.8$ e $p_0 = \frac{3}{15} = 0.2$.
                Applichiamo la formula di Gini:
                $$I_G = 1 - (p_1^2 + p_0^2) = 1 - (0.8^2 + 0.2^2) = 1 - (0.64 + 0.04) = 1 - 0.68 = \mathbf{0.32}$$
                L'impurezza del nodo è pari a <strong>0.32</strong>.
            </li>
            <li><strong>B) Caso estremo:</strong>
                Se tutti i campioni appartengono alla classe 1, $p_1 = 1.0$ e $p_0 = 0.0$.
                $$I_G = 1 - (1.0^2 + 0.0^2) = 1 - 1 = \mathbf{0}$$
                L'impurezza è pari a <strong>0</strong>. Un nodo con impurezza zero viene definito <strong>Nodo Puro</strong>.
            </li>
        </ul>
        </p>
    </div>
</div>

---

### Esercizio 2: Regolarizzazione degli Alberi e Overfitting
Un albero di decisione viene addestrato su un dataset senza impostare alcun limite alla sua crescita.
*   **A)** Quali prestazioni (accuratezza ed errore) ti aspetti di osservare sul Training Set rispetto al Test Set? Come si chiama questo scenario?
*   **B)** Indica due iperparametri che potresti configurare in Scikit-Learn per costringere l'albero a rimanere più semplice, spiegando brevemente l'effetto di ciascuno.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-tree-overfitting-ex">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-tree-overfitting-ex">
        <p><strong>Soluzione:</strong>
        <ul>
            <li><strong>A)</strong> Ci si aspetta un'accuratezza del 100% (errore nullo) sul Training Set, poiché l'albero si è ramificato fino a isolare ogni singolo punto di addestramento. Al contrario, sul Test Set l'errore sarà molto elevato (accuratezza molto bassa). Questo scenario prende il nome di <strong>Overfitting</strong>.</li>
            <li><strong>B) Iperparametri di regolarizzazione (sceglierne due):</strong>
                <ul>
                    <li><code>max_depth</code>: limita l'altezza massima dell'albero, evitando che vengano create troppe ramificazioni in cascata estremamente specifiche.</li>
                    <li><code>min_samples_split</code>: definisce il numero minimo di campioni che un nodo deve contenere per potersi dividere ulteriormente. Se un nodo contiene meno campioni del valore impostato, viene forzato a diventare una foglia.</li>
                    <li><code>min_samples_leaf</code>: impone una quota minima di campioni all'interno di una foglia, evitando la creazione di foglie basate su pochissimi campioni anomali.</li>
                </ul>
            </li>
        </ul>
        </p>
    </div>
</div>
