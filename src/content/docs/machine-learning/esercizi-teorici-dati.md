---
title: "Esercizi Teorici: Introduzione al Machine Learning"
description: "Esercitazioni teoriche sul paradigma del Machine Learning, struttura dei dataset (feature e target) e classificazione dei tipi di apprendimento."
---

Questi esercizi ti consentono di verificare la comprensione dei concetti teorici fondamentali della prima unità prima di passare alla scrittura del codice.

---

### Esercizio 1: Programmazione Tradizionale vs Machine Learning
*   **A)** Spiega qual è la differenza fondamentale nel flusso di lavoro tra la programmazione tradizionale (classica) e il Machine Learning. Aiutati scrivendo gli schemi delle due relazioni.
*   **B)** Se dovessi scrivere un programma per calcolare le tasse degli utenti in base a scaglioni IRPEF fissati dalla legge, utilizzeresti la programmazione classica o il Machine Learning? Motiva brevemente la scelta.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-teoria-paradigma">Visualizza la risposta corretta</p>
    <div class="soluzione" id="sol-teoria-paradigma">
        <p><strong>Risposta:</strong>
        <ul>
            <li><strong>A) Differenza di flusso:</strong>
                <ul>
                    <li>Nella <strong>programmazione classica</strong>, forniamo al computer i <em>Dati</em> e le <em>Regole</em> (istruzioni scritte da noi) per ottenere dei <em>Risultati</em>:
                        $$\text{Dati} + \text{Regole} \longrightarrow \text{Risultati}$$
                    </li>
                    <li>Nel <strong>Machine Learning</strong> invertiamo il flusso: forniamo al computer i <em>Dati</em> storici e i <em>Risultati</em> noti (esempi) in modo che l'algoritmo possa estrarre le <em>Regole</em> (il modello predittivo):
                        $$\text{Dati} + \text{Risultati} \longrightarrow \text{Regole (Modello)}$$
                    </li>
                </ul>
            </li>
            <li><strong>B) Scelta del paradigma:</strong>
                Per il calcolo delle tasse si utilizza la <strong>programmazione classica</strong>. Le regole sono certe, deterministiche e fissate in modo univoco dalla legge (scaglioni ben precisi). Non c'è bisogno di indovinare una regola nascosta dai dati: basta scrivere le istruzioni logiche (es. `if/else`) per ottenere il risultato esatto al 100%.
            </li>
        </ul>
        </p>
    </div>
</div>

---

### Esercizio 2: Struttura dei Dati (Feature e Target)
Immagina di voler addestrare un modello per stimare i consumi energetici mensili (in kWh) di varie abitazioni. Per ogni casa raccogli le seguenti informazioni: superficie in $m^2$, numero di elettrodomestici, classe energetica dell'edificio, numero di abitanti e consumo reale misurato.
*   **A)** Quali colonne rappresentano le **Feature** ($X$) e quale colonna rappresenta il **Target** ($y$)?
*   **B)** Qual è la differenza concettuale tra una feature e un target?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-teoria-feature-target">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-teoria-feature-target">
        <p><strong>Soluzione:</strong>
        <ul>
            <li><strong>A) Suddivisione:</strong>
                <ul>
                    <li><strong>Feature ($X$):</strong> Superficie ($m^2$), numero di elettrodomestici, classe energetica, numero di abitanti. Sono le informazioni in ingresso che descrivono l'abitazione.</li>
                    <li><strong>Target ($y$):</strong> Consumo mensile (kWh). È la variabile di cui vogliamo fare la previsione.</li>
                </ul>
            </li>
            <li><strong>B) Differenza concettuale:</strong>
                Le <strong>Feature</strong> sono le variabili indipendenti usate come punto di partenza per descrivere i campioni del dataset. Il <strong>Target</strong> è la variabile dipendente (il traguardo/l'etichetta) che il modello tenta di prevedere a partire dalle feature.
            </li>
        </ul>
        </p>
    </div>
</div>

---

### Esercizio 3: Tipologie di Apprendimento
Associa ciascuno dei seguenti scenari alla tipologia corretta di Machine Learning, specificando se si tratta di **Apprendimento Supervisionato (Classificazione o Regressione)** o **Apprendimento Non Supervisionato (Clustering)**:
*   **Caso A:** Raggruppare i visitatori di un sito e-commerce in 5 gruppi omogenei in base alla frequenza e al tipo di acquisti effettuati, per creare campagne pubblicitarie mirate.
*   **Caso B:** Prevedere il prezzo di vendita di un'automobile usata a partire dall'anno di immatricolazione, dai chilometri percorsi e dai cavalli del motore.
*   **Caso C:** Identificare se la foto di una radiografia polmonare indica la presenza di una polmonite (Sì/No).

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-teoria-tipi-ml">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-teoria-tipi-ml">
        <p><strong>Soluzione:</strong>
        <ul>
            <li><strong>Caso A: Apprendimento Non Supervisionato (Clustering).</strong> Non abbiamo un'etichetta di destinazione definita a priori (non sappiamo a quali gruppi debbano appartenere i clienti); l'algoritmo deve analizzare le similarità per formare i gruppi autonomamente.</li>
            <li><strong>Caso B: Apprendimento Supervisionato (Regressione).</strong> Il target è il prezzo dell'auto, che è un valore numerico continuo.</li>
            <li><strong>Caso C: Apprendimento Supervisionato (Classificazione).</strong> Il target è una categoria discreta e binaria (Presenza di polmonite: Sì o No).</li>
        </ul>
        </p>
    </div>
</div>
