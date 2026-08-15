---
title: "Esercizi Teorici: Regressione, Classificazione e Valutazione"
description: "Esercizi di verifica teorica e di calcolo manuale (carta e penna) sui modelli lineari, logistici, discesa del gradiente e metriche di performance."
---

Questi esercizi ti consentono di verificare la comprensione dei concetti matematici e logici fondamentali relativi alla seconda unità (Regressione, Classificazione e Valutazione) prima di passare alla scrittura del codice.

---

### Esercizio 1: Modelli Lineari e Regressione
Un modello di regressione lineare ha trovato la seguente retta di regressione: $y = 0.5 \cdot x + 3.8$, dove $x$ rappresenta le ore di studio e $y$ rappresenta il voto finale previsto. 
*   **A)** Qual è il voto previsto per uno studente che studia $5$ ore?
*   **B)** Se uno studente non studia affatto ($x=0$), quale voto prevede il modello? Come si chiama questo parametro nell'equazione del modello?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-teoria-linear">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-teoria-linear">
        <p><strong>Soluzione:</strong>
        <ul>
            <li><strong>A)</strong> Sostituiamo $x=5$ nell'equazione: $y = 0.5 \cdot 5 + 3.8 = 2.5 + 3.8 = 6.3$. Il voto previsto è <strong>6.3</strong>.</li>
            <li><strong>B)</strong> Se $x=0$, $y = 0.5 \cdot 0 + 3.8 = 3.8$. Il voto previsto è <strong>3.8</strong>. Questo parametro rappresenta l'intercetta (in inglese <strong>bias</strong>).</li>
        </ul>
        </p>
    </div>
</div>

---

### Esercizio 2: Modelli di Classificazione e Sigmoide
Per quale motivo per i problemi di classificazione binaria si preferisce la Regressione Logistica rispetto alla Regressione Lineare? Descrivi la funzione matematica utilizzata a questo scopo.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-teoria-logistic">Visualizza la risposta corretta</p>
    <div class="soluzione" id="sol-teoria-logistic">
        <p><strong>Risposta:</strong> La regressione lineare può produrre in output qualsiasi valore numerico reale (anche negativo o superiore a $1$), il che rende impossibile interpretare l'output come una probabilità di appartenenza a una classe binaria ($0$ o $1$). La regressione logistica risolve questo problema introducendo la funzione <strong>Sigmoide</strong> (o logistica):
        $$
        \sigma(z) = \frac{1}{1 + e^{-z}}
        $$
        Questa funzione "schiaccia" qualsiasi valore di input $z$ in un intervallo compreso strettamente tra $0$ e $1$, permettendo di interpretare il risultato come la probabilità che il dato appartenga alla classe target.</p>
    </div>
</div>

---

### Esercizio 3: Ottimizzazione e Discesa del Gradiente
Spiega l'analogia tra la "ricerca della valle nella nebbia" e il funzionamento dell'algoritmo di *Discesa del Gradiente*. Nel formalismo matematico dell'algoritmo, che cosa rappresenta la pendenza del terreno e cosa rappresenta la dimensione del passo?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-teoria-gradiente">Visualizza la risposta corretta</p>
    <div class="soluzione" id="sol-teoria-gradiente">
        <p><strong>Risposta:</strong>
        <ul>
            <li>La <strong>funzione di costo</strong> rappresenta la montagna, dove l'altezza corrisponde all'entità dell'errore (vogliamo raggiungere il punto più basso, ovvero l'errore minimo).</li>
            <li>La <strong>pendenza del terreno</strong> sotto i piedi corrisponde al <strong>Gradiente</strong> ($\nabla L$), che indica la direzione in cui l'errore sale più rapidamente. Per scendere, ci muoviamo nella direzione opposta.</li>
            <li>La <strong>dimensione del passo</strong> corrisponde al <strong>Tasso di Apprendimento / Learning Rate</strong> ($\eta$). Se facciamo passi troppo piccoli (learning rate basso) impiegheremo molto tempo a scendere; se facciamo passi troppo grandi (learning rate alto) rischiamo di scavalcare la valle e risalire sull'altro versante.</li>
        </ul>
        </p>
    </div>
</div>

---

### Esercizio 4: Generalizzazione e Overfitting
Descrivi cos'è l'Overfitting (sovraddestramento) e indica una possibile soluzione basata sul monitoraggio degli errori durante le epoche di addestramento.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-teoria-overfitting">Visualizza la risposta corretta</p>
    <div class="soluzione" id="sol-teoria-overfitting">
        <p><strong>Risposta:</strong> L'Overfitting si verifica quando un modello impara "troppo bene" le anomalie e i rumori specifici del dataset di addestramento (Train set), perdendo la capacità di generalizzare su dati nuovi (Test set). Visivamente, l'accuratezza del Train sale vicina al 100% mentre quella del Test crolla.
        Una possibile soluzione è l'<strong>Arresto Anticipato (Early Stopping)</strong>: si monitora l'errore del test set durante le epoche di addestramento e si interrompe il ciclo non appena l'errore del test smette di scendere e inizia a risalire, conservando i pesi ottimali calcolati in quel punto.</p>
    </div>
</div>

---

### Esercizio 5: Calcolo Pratico della Matrice di Confusione e Metriche
Un modello predittivo per rilevare se una mail è spam ($1$ = Spam, $0$ = Normale) viene testato su $100$ email. La matrice di confusione risultante è la seguente:

```text
[[70  5]
  [10 15]]
```

*   **A)** Identifica i valori di TN, FP, FN e TP.
*   **B)** Calcola l'Accuratezza, la Precisione e la Sensibilità (Recall) del modello.
*   **C)** Se volessi evitare a tutti i costi che una mail importante (non-spam) finisca nella cartella spam del destinatario, a quale metrica dovresti dare priorità per minimizzare questo rischio specifico?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-teoria-metriche-calc">Visualizza la risoluzione dell'esercizio</p>
    <div class="soluzione" id="sol-teoria-metriche-calc">
        <p><strong>Soluzione:</strong>
        <ul>
            <li><strong>A) Dalla matrice ricaviamo:</strong>
                <ul>
                    <li>Vero Negativo (TN) = 70</li>
                    <li>Falso Positivo (FP) = 5</li>
                    <li>Falso Negativo (FN) = 10</li>
                    <li>Vero Positivo (TP) = 15</li>
                </ul>
            </li>
            <li><strong>B) Calcolo delle metriche:</strong>
                <ul>
                    <li>$\text{Accuratezza} = \frac{TP + TN}{\text{Totale}} = \frac{15 + 70}{100} = 0.85 \implies \mathbf{85.0\%}$</li>
                    <li>$\text{Precisione} = \frac{TP}{TP + FP} = \frac{15}{15 + 5} = \frac{15}{20} = 0.75 \implies \mathbf{75.0\%}$</li>
                    <li>$\text{Sensibilità (Recall)} = \frac{TP}{TP + FN} = \frac{15}{15 + 10} = \frac{15}{25} = 0.60 \implies \mathbf{60.0\%}$</li>
                </ul>
            </li>
            <li><strong>C) Priorità clinica/operativa:</strong>
                Per evitare che mail normali vengano classificate erroneamente come spam, dobbiamo ridurre al minimo i Falsi Positivi (FP). Guardando le formule, la metrica che dobbiamo massimizzare è la <strong>Precisione</strong> (infatti a denominatore c'è FP: più FP è basso, più la precisione si avvicina al 100%). Un'alta precisione garantisce che quasi tutto ciò che viene classificato come spam lo sia veramente, proteggendo le mail importanti dall'essere perse.</li>
        </ul>
        </p>
    </div>
</div>

---

### Esercizio 6: Diagnosi di Overfitting e Underfitting (Casi Studio)
Associa a ciascuno dei seguenti scenari di addestramento lo stato corretto del modello, scegliendo tra: *Generalizzazione Corretta*, *Overfitting*, *Underfitting Strutturale* o *Underfitting da Mancato Addestramento*. Motivando brevemente la risposta:

*   **Caso A:** Un modello lineare per stimare i prezzi delle case mostra un errore (Loss) molto elevato sia sul Train Set ($0.55$) sia sul Validation Set ($0.56$). Cambiando il Learning Rate o addestrando per più tempo l'errore non scende.
*   **Caso B:** Una rete neurale addestrata per $5$ iterazioni mostra un errore del $0.48$ sul Train Set e del $0.49$ sul Validation Set. Aumentando le iterazioni a $500$, l'errore sul Train scende a $0.08$ e sul Validation a $0.09$.
*   **Caso C:** Un modello mostra un errore sul Train Set vicinissimo allo zero ($0.01$), ma sul Validation Set e sul Test Set l'errore schizza a $0.85$.
*   **Caso D:** Un modello mostra un errore sul Train Set pari a $0.10$ e sul Validation Set pari a $0.11$, mantenendosi stabile anche sul Test Set ($0.11$).

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-teoria-diagnosi">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-teoria-diagnosi">
        <p><strong>Soluzione:</strong>
        <ul>
            <li><strong>Caso A: Underfitting Strutturale.</strong> L'errore è elevato su entrambi i set e non cambia modificando i parametri di addestramento ($\eta$ o iterazioni). Significa che il modello è troppo semplice per rappresentare la complessità dei dati.</li>
            <li><strong>Caso B: Underfitting da Mancato Addestramento.</strong> L'errore iniziale era alto, ma è sceso notevolmente aumentando il numero di iterazioni. Il modello era semplicemente sotto-addestrato nelle prime fasi.</li>
            <li><strong>Caso C: Overfitting.</strong> Il modello ha memorizzato i dati di addestramento (errore quasi nullo sul Train), ma fallisce completamente nel generalizzare su dati nuovi (errore altissimo su Validation/Test).</li>
            <li><strong>Caso D: Generalizzazione Corretta.</strong> Il modello mostra errori bassi e simili sia sui dati di addestramento sia su dati non visti (Validation/Test), dimostrando di aver imparato le regole generali.</li>
        </ul>
        </p>
    </div>
</div>

---

### Esercizio 7: Proporzioni e Suddivisione dei Dataset
*   **A)** Perché l'utilizzo del Test Set a ogni iterazione per effettuare l'Early Stopping rappresenta un errore metodologico? Come si chiama questo errore?
*   **B)** Un team di Data Science sta lavorando su un dataset medico con $800$ pazienti totali. Un altro team sta addestrando una rete neurale per la guida autonoma su un dataset di $5.000.000$ di immagini. Quali proporzioni di suddivisione (Train/Validation/Test) consiglieresti a ciascuno dei due team? Motiva la scelta.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-teoria-proporzioni">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-teoria-proporzioni">
        <p><strong>Soluzione:</strong>
        <ul>
            <li><strong>A)</strong> Usare il Test Set per l'Early Stopping crea **Data Leakage** (contaminazione). Anche se il modello non aggiorna i pesi usando il Test Set, noi umani stiamo selezionando l'iterazione ottimale basandoci sulle prestazioni di test. In questo modo le prestazioni finali sul Test Set risulteranno ottimistiche e non rappresenteranno più una misura imparziale su dati futuri.</li>
            <li><strong>B) Consigli per la suddivisione:</strong>
                <ul>
                    <li><strong>Team Medico (800 pazienti):</strong> Consigliata una suddivisione **70% Train / 15% Validation / 15% Test** (o **80/10/10**). Con soli 800 pazienti, dedicare il 15% significa avere 120 pazienti sia nel Validation che nel Test. Se usassimo percentuali più piccole (es. 1%), avremmo solo 8 pazienti nei set di controllo, rendendo le misure di errore instabili e soggette al caso.</li>
                    <li><strong>Team Guida Autonoma (5.000.000 immagini):</strong> Consigliata una suddivisione **98% Train / 1% Validation / 1% Test** (o persino **99% / 0.5% / 0.5%**). Con 5 milioni di immagini, l'1% equivale a 50.000 immagini: una quantità enorme, ampiamente sufficiente per testare il modello. Destinare il 15% al test (750.000 immagini) sarebbe uno spreco inutile di dati che potrebbero invece essere usati per migliorare l'addestramento.</li>
                </ul>
            </li>
        </ul>
        </p>
    </div>
</div>
