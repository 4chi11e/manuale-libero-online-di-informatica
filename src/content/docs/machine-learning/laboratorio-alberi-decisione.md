---
title: "Laboratorio: Alberi di Decisione"
description: "Laboratorio pratico in Python con Scikit-Learn per addestrare alberi di decisione, regolarizzarli con max_depth e combinare una Random Forest."
---

Benvenuto nel laboratorio pratico dell'Unità 3. Qui imparerai a implementare alberi decisionali e Random Forest in Python usando Scikit-Learn, regolarizzare i modelli per prevenire l'overfitting e tracciarne la struttura grafica.

---

## 1. Configurazione e Download
Ti consigliamo di svolgere questo laboratorio in locale sul tuo computer scaricando ed eseguendo il Notebook Jupyter dedicato:

*   [Scarica il Notebook: unita3_alberi_decisione.ipynb](/manuale-libero-online-di-informatica/assets/codice/python/unita3_alberi_decisione.ipynb)

---

## 2. Esecuzione del Laboratorio Passo dopo Passo

Di seguito vediamo come costruire il codice passo dopo passo, analizzando le scelte di parametri e funzioni per ciascuna sezione.

### Passo 1: Importazione delle Librerie e Generazione dei Dati

Iniziamo importando i moduli necessari e generando un dataset fittizio di classificazione.

```python
import matplotlib.pyplot as plt
from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier, plot_tree
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score

# 1. Generiamo un dataset sintetico (500 campioni, 2 feature per facilitare la visualizzazione)
X, y = make_classification(n_samples=500, n_features=2, n_redundant=0, 
                           n_clusters_per_class=1, random_state=42) # random_state=42 blocca la casualità per riproducibilità
# print(X)  # Decommenta per visualizzare i dati del dataset X generato
```

*   **`make_classification`**: È una funzione di Scikit-Learn che genera dataset sintetici (casuali ma dotati di una struttura logica interna). È ideale per esercitarsi e testare modelli di classificazione senza dover caricare file esterni.
*   **`n_samples=500` e `n_features=2`**: Generiamo un dataset composto da 500 campioni e sole 2 caratteristiche (colonne). Manteniamo il numero di feature a 2 in modo da poter visualizzare e comprendere facilmente lo schema grafico finale dell'albero.
*   **`random_state=42`**: Imposta un "seme" per il generatore di numeri casuali. Questo garantisce che, ogni volta che esegui il codice, l'albero si divida esattamente nello stesso modo, rendendo i tuoi esperimenti ripetibili e confrontabili.

---

### Passo 2: Suddivisione in Training Set e Test Set

Dividiamo i dati destinando l'80% all'addestramento e il 20% alla verifica finale (test set).

```python
# 2. Dividiamo in Train (80%) e Test set (20% per valutare l'accuratezza neutrale)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
```

*   **`train_test_split`**: Separa i dati in **Training Set (80%)** per addestrare i due modelli e **Test Set (20%)** per valutarne l'accuratezza in modo neutrale su dati mai visti prima.
*   **`test_size=0.2`**: Consiste nello standard di riservare il 20% dei campioni (100 in totale) come Test Set e l'80% (400 campioni) come Training Set.

---

### Passo 3: Addestramento e Valutazione di un Singolo Albero di Decisione

Creiamo un albero decisionale limitando la profondità a `max_depth=3` per evitare che cresca all'infinito memorizzando i dati a memoria (overfitting).

```python
# 3. Addestriamo un Albero di Decisione (limite di profondità max_depth=3 per prevenire overfitting)
albero = DecisionTreeClassifier(max_depth=3, random_state=42)
albero.fit(X_train, y_train)

# Previsioni e valutazione dell'Albero sul Test Set
y_pred_alb = albero.predict(X_test)
print(f"Accuratezza del singolo Albero: {accuracy_score(y_test, y_pred_alb) * 100:.1f}%")
```

*   **`DecisionTreeClassifier`**: La classe ufficiale che implementa l'algoritmo del singolo albero di decisione per la classificazione.
*   **`max_depth=3`**: Questo parametro limita la crescita dell'albero a una profondità massima di 3 livelli. È lo strumento principale di **regolarizzazione**: impedendo all'albero di dividersi ulteriormente, si previene l'overfitting.
    *   *Consiglio Pratico / Esperimento:* Prova a modificare questo valore impostando `max_depth=1` (albero troppo semplice, underfitting) o rimuovendolo del tutto impostando `max_depth=None` (albero libero di crescere, overfitting). Riesegui il codice e osserva come cambia l'accuratezza sul Test Set: noterai che in entrambi i casi le prestazioni sul Test Set calano rispetto a una profondità intermedia ottimale!
*   **`fit(X_train, y_train)`**: Calcola ricorsivamente le soglie ottimali su ciascuna caratteristica massimizzando il Guadagno di Gini ad ogni livello.
*   **`accuracy_score`**: Calcola la percentuale di risposte corrette del modello sul Test Set.

---

### Passo 4: Addestramento e Valutazione della Random Forest

Creiamo una Random Forest composta da 100 alberi decisionali differenti che cooperano tra loro tramite voto di maggioranza.

```python
# 4. Addestriamo una Random Forest (100 alberi decisionali indipendenti cooperanti per abbattere la varianza)
foresta = RandomForestClassifier(n_estimators=100, max_depth=3, random_state=42)
foresta.fit(X_train, y_train)

# Previsioni e valutazione della Foresta
y_pred_for = foresta.predict(X_test)
print(f"Accuratezza della Random Forest: {accuracy_score(y_test, y_pred_for) * 100:.1f}%")
```

*   **`RandomForestClassifier`**: La classe ufficiale per creare e gestire le Random Forest (apprendimento d'ensemble).
*   **`n_estimators=100`**: Definisce il numero di alberi decisionali da addestrare in parallelo all'interno della foresta. Inserire più alberi aumenta la robustezza del modello riducendone la varianza, ma richiede più memoria e tempo di calcolo. Un valore di 100 è lo standard predefinito ottimale.
*   **`max_depth=3`**: Anche in questo caso stiamo ponendo un limite alla profondità di ciascuno dei 100 singoli alberi componenti la foresta.

---

### Passo 5: Visualizzazione Grafica dell'Albero di Decisione

Uno dei grandi vantaggi degli alberi di decisione è la loro **interpretabilità**. Possiamo disegnare l'albero per vedere esattamente quali domande ha scelto di fare l'algoritmo.

```python
# 5. Disegniamo la struttura dell'Albero di Decisione (interpretabilità grafica)
plt.figure(figsize=(12, 8))
plot_tree(albero, 
          feature_names=["Caratteristica A", "Caratteristica B"], 
          class_names=["Classe 0", "Classe 1"], 
          filled=True,  # Colora i nodi (arancione classe 0, blu classe 1; più scuro = più puro)
          rounded=True) # Nodi con spigoli arrotondati per leggibilità
plt.title("Struttura dell'Albero di Decisione Addestrato (max_depth=3)")
plt.show()
```

*   **`plot_tree(...)`**: Genera il diagramma dell'albero.
*   **`filled=True`**: Colora i nodi per identificare visivamente la classe predominante al loro interno (es. arancione per la Classe 0 e blu per la Classe 1). L'intensità del colore indica la purezza del nodo: più il colore è scuro ed acceso, più l'impurezza di Gini del nodo è vicina a 0.
*   **`rounded=True`**: Disegna i nodi con angoli arrotondati per migliorarne la leggibilità grafica.

<details>
<summary><b>Visualizza il codice completo (pronto da copiare ed eseguire)</b></summary>

```python
import matplotlib.pyplot as plt
from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier, plot_tree
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score

X, y = make_classification(n_samples=500, n_features=2, n_redundant=0, 
                           n_clusters_per_class=1, random_state=42)

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

albero = DecisionTreeClassifier(max_depth=3, random_state=42)
albero.fit(X_train, y_train)
y_pred_alb = albero.predict(X_test)
print(f"Accuratezza del singolo Albero: {accuracy_score(y_test, y_pred_alb) * 100:.1f}%")

foresta = RandomForestClassifier(n_estimators=100, max_depth=3, random_state=42)
foresta.fit(X_train, y_train)
y_pred_for = foresta.predict(X_test)
print(f"Accuratezza della Random Forest: {accuracy_score(y_test, y_pred_for) * 100:.1f}%")

plt.figure(figsize=(12, 8))
plot_tree(albero, 
          feature_names=["Caratteristica A", "Caratteristica B"], 
          class_names=["Classe 0", "Classe 1"], 
          filled=True, 
          rounded=True)
plt.title("Struttura dell'Albero di Decisione Addestrato (max_depth=3)")
plt.show()
```
</details>

---

## Parte 3: Coding Challenges

Mettiti alla prova modificando ed estendendo il codice Python scritto finora sul tuo notebook.

### Challenge 1: L'impatto della profondità dell'albero sull'Overfitting
*   **Task:** Utilizza il dataset sintetico e la suddivisione generati nel laboratorio pratico. Addestra un `DecisionTreeClassifier` impostando `max_depth=None` (ovvero lasciandolo crescere senza alcun vincolo). Calcola l'accuratezza del modello sia sui dati di addestramento (`X_train`) che sui dati di test (`X_test`).
*   **Domanda:** Quali valori di accuratezza ottieni sui due set? Come si spiega la differenza di performance rispetto all'albero regolarizzato con `max_depth=3`?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-lab-tree-overfit">Visualizza la risoluzione e il codice</p>
    <div class="soluzione" id="sol-lab-tree-overfit">
        <p><strong>Risoluzione e Codice:</strong></p>
        <pre><code class="language-python"># Inizializziamo un albero senza limiti di profondità
albero_overfit = DecisionTreeClassifier(max_depth=None, random_state=42)
albero_overfit.fit(X_train, y_train)

# Calcoliamo le previsioni su train e test
y_pred_train = albero_overfit.predict(X_train)
y_pred_test = albero_overfit.predict(X_test)

print(f"Accuratezza sul Training Set: {accuracy_score(y_train, y_pred_train) * 100:.1f}%")
print(f"Accuratezza sul Test Set:     {accuracy_score(y_test, y_pred_test) * 100:.1f}%")
        </code></pre>
        <p><strong>Risultati attesi a schermo:</strong></p>
        <pre><code class="language-text">Accuratezza sul Training Set: 100.0%
Accuratezza sul Test Set:     88.0%  (il valore esatto può oscillare in base al dataset generato)
        </code></pre>
        <p><strong>Spiegazione concettuale:</strong></p>
        <p>Con <code>max_depth=None</code>, l'albero raggiunge un'accuratezza del <strong>100.0% sul Training Set</strong>. Questo accade perché l'algoritmo ha continuato a creare nodi finché ogni singola foglia non conteneva campioni purissimi della stessa classe, adattandosi perfettamente (o meglio, "memorizzando") tutti i dati usati per l'apprendimento.</p>
        <p>Tuttavia, sul <strong>Test Set l'accuratezza scende</strong> (ad esempio all' $88\%$, contro il $92\%$ dell'albero regolarizzato con <code>max_depth=3</code>). Questo divario netto tra train e test dimostra che l'albero non vincolato soffre di <strong>Overfitting</strong>: ha imparato il rumore e le eccezioni specifiche del train set a scapito della sua capacità di generalizzazione su campioni mai visti prima.</p>
    </div>
</div>
