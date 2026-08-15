---
title: "Unità 1: Introduzione al Machine Learning e Preparazione dei Dati"
description: "Introduzione al paradigma del Machine Learning, classificazione delle tipologie di apprendimento, preparazione dei dati in Python e suddivisione in Train/Test set."
---

Benvenuti nel mondo dell'**Intelligenza Artificiale**. In questa prima unità capiremo come i computer possono "imparare" direttamente dall'esperienza (i dati) senza che un programmatore debba scrivere esplicitamente ogni singola istruzione logica.

---

## 1.1 Il Cambio di Paradigma: Programmazione Classica vs Machine Learning

Nella **programmazione tradizionale (classica)**, il programmatore scrive le regole (gli algoritmi) e le fornisce al computer insieme ai dati di partenza. Il computer esegue queste regole passo dopo passo e produce un risultato.

$$
\text{Dati} + \text{Regole} \longrightarrow \text{Risultati}
$$

> **Esempio**: Se vuoi calcolare l'area di un cerchio, scrivi la regola matematica $A = \pi \cdot r^2$. Fornisci il raggio (dato) e il computer calcola l'area (risultato).

Nel **Machine Learning (ML)**, il processo si inverte. Spesso non conosciamo la regola matematica o logica complessa che lega i dati ai risultati (ad esempio, come distinguere la foto di un cane da quella di un gatto). Forniamo quindi al computer i dati e i risultati attesi (esempi). Sarà l'algoritmo di ML a trovare la regola (ovvero il **"modello"**).

$$
\text{Dati} + \text{Risultati} \longrightarrow \text{Regole (Modello)}
$$

Una volta che il modello è stato addestrato, possiamo fornirgli nuovi dati di cui non conosciamo il risultato e usarlo per fare previsioni:

$$
\text{Nuovi Dati} + \text{Modello} \longrightarrow \text{Previsioni}
$$

---

## 1.2 La Struttura dei Dati: Dataset, Feature e Target

Per far apprendere un computer, i dati devono essere organizzati in forma tabellare, chiamata **Dataset**. Le colonne del dataset si dividono in due categorie principali:

*   **Feature (Caratteristiche / Variabili Indipendenti - $X$):** Sono le colonne che contengono le informazioni usate dal modello per fare la previsione. Nei modelli matematici, corrispondono alle nostre variabili indipendenti $x_1, x_2, \dots, x_n$.
*   **Target (Etichetta / Variabile Dipendente - $y$):** È la colonna che contiene l'output che vogliamo prevedere. Matematicamente, corrisponde alla variabile dipendente $y$.

### Esempio di Dataset Immobiliare

| Superficie in $m^2$ ($x_1$) | Numero di Camere ($x_2$) | Prezzo Venduto ($y$) |
| :---: | :---: | :---: |
| 85 | 3 | 210.000 € |
| 120 | 4 | 295.000 € |
| **FEATURE** | **FEATURE** | **TARGET** |

---

## 1.3 Apprendimento Supervisionato vs Non Supervisionato

Il Machine Learning si divide principalmente in due grandi famiglie, a seconda della presenza o meno del target nel dataset:

### Apprendimento Supervisionato (Supervised Learning)
Il dataset di partenza contiene sia le feature sia il target (conosciamo già la risposta corretta per i dati storici). Il modello impara a mappare gli input negli output. Si divide in:
*   **Classificazione:** Il target è una categoria discreta (es. "Sì/No", "Gatto/Cane", "Email di Spam / Email Sicura").
*   **Regressione:** Il target è un valore numerico continuo (es. il prezzo di una casa, la temperatura di domani).

### Apprendimento Non Supervisionato (Unsupervised Learning)
Il dataset contiene solo le feature, senza alcun target associato. L'algoritmo deve trovare autonomamente dei pattern o raggruppare i dati simili.
*   **Clustering:** Raggruppamento di dati in gruppi (cluster) basandosi sulla loro similarità (es. segmentazione dei clienti con abitudini d'acquisto affini).

---

## 1.4 Esercizi e Laboratorio Pratico

Per mettere in pratica le conoscenze teoriche acquisite in questa unità sulla preparazione dei dati e sulla suddivisione in train e test set, consulta la sezione pratica del manuale:

*   **Teoria e Calcolo (Carta e Penna)**:
    *   [Esercizi Teorici: Introduzione al Machine Learning](file:///f:/Progetti%20Github/Manuale_Libero_Online_di_Informatica/Repository-manuale/src/content/docs/machine-learning/esercizi-teorici-dati.md)
*   **Esercitazione in Python (Scikit-Learn)**:
    *   [Laboratorio: Preparazione Dati in Python](file:///f:/Progetti%20Github/Manuale_Libero_Online_di_Informatica/Repository-manuale/src/content/docs/machine-learning/laboratorio-dati.md)
    *   [Download Notebook Jupyter: unita1_introduzione_dati.ipynb](/manuale-libero-online-di-informatica/assets/codice/python/unita1_introduzione_dati.ipynb)
