---
title: "Unità 2: Primi Modelli - Regressione e Classificazione"
description: "Studio della Regressione Lineare e Logistica con scikit-learn, metriche di valutazione come MSE e R² e comprensione della matrice di confusione."
---

Dopo aver visto come organizzare e suddividere i dati, in questa seconda unità vedremo come addestrare i nostri primi modelli predittivi usando la libreria **Scikit-Learn**. Affronteremo i due compiti principali dell'apprendimento supervisionato: la **regressione** e la **classificazione**.

---

## 2.1 Regressione Lineare (Prevedere valori continui)

Il modello più semplice e intuitivo per fare regressione è la **Regressione Lineare**. L'obiettivo è trovare una relazione lineare (una linea retta) che leghi la feature indipendente $x$ al target continuo $y$.

L'equazione matematica di una retta con una sola feature è:

$$
y = w \cdot x + b
$$

Dove:
*   $w$ (in matematica chiamato coefficiente angolare $m$) rappresenta il **peso** (weight) assegnato alla feature. Determina la pendenza della retta.
*   $b$ (in matematica chiamato intercetta $q$) rappresenta il **bias** (o termine noto). È il valore di $y$ quando $x = 0$.

### La Funzione di Costo: Mean Squared Error (MSE)
Come fa l'algoritmo a capire qual è la "retta migliore"? Cerca di minimizzare l'errore commesso. Per misurare questo errore, si calcola l'**Errore Quadratico Medio (Mean Squared Error - MSE)**:

$$
MSE = \frac{1}{N} \sum_{i=1}^{N} (y_i - \hat{y}_i)^2
$$

Dove:
*   $N$ è il numero totale di campioni nel dataset.
*   $y_i$ è il valore reale (il target effettivo del campione $i$).
*   $\hat{y}_i$ (letto *y-hat*) è il valore previsto dal modello per il campione $i$ ($\hat{y}_i = w \cdot x_i + b$).
*   La differenza $(y_i - \hat{y}_i)$ è il **residuo** (l'errore individuale). Elevandolo al quadrato, si evitano compensazioni tra errori positivi e negativi e si penalizzano maggiormente gli errori più grandi.

### Come Trovare la Retta Migliore: Calcolo Diretto vs Addestramento Iterativo

Per trovare i valori ideali di $w$ e $b$ che rendono l'MSE il più piccolo possibile, esistono due strade principali:

1.  **Metodo Analitico (Calcolo Diretto):**
    Esiste una formula matematica diretta (chiamata metodo dei *Minimi Quadrati Ordinari* o *Equazione Normale*) che consente di calcolare all'istante i valori esatti di $w$ e $b$ in un solo passaggio. È molto efficiente per dataset piccoli, ma diventa impraticabile se abbiamo milioni di caratteristiche (feature) perché richiede calcoli matriciali estremamente pesanti per i computer.

2.  **Metodo Iterativo (Discesa del Gradiente):**
    Invece di calcolare la soluzione in un colpo solo, l'algoritmo effettua una serie di tentativi ripetuti (**iterazioni**):
    *   **Inizializzazione:** Si parte assegnando a $w$ e $b$ dei valori casuali (la retta iniziale sarà probabilmente pessima).
    *   **Predizione ed Errore:** Si calcola l'MSE con i parametri attuali.
    *   **Aggiornamento (Passo di Addestramento):** Si calcola la direzione in cui l'errore aumenta o diminuisce (il **Gradiente**) e si modificano leggermente $w$ e $b$ nella direzione che riduce l'errore.
    *   **Ripetizione:** Si ripete questo ciclo per centinaia o migliaia di volte (ogni ripetizione è un'**iterazione** o **epoca**) finché l'errore non scende al minimo e si stabilizza (fase di *convergenza*).

> [!NOTE]
> **Perché è importante capire il concetto di Iterazione?**
> Mentre per la regressione lineare il calcolo diretto è tecnicamente possibile, per quasi tutti gli altri modelli di Machine Learning più complessi (come la regressione logistica e le reti neurali) non esiste una formula diretta per calcolare i parametri ottimali. L'unico modo per addestrarli è utilizzare un processo **iterativo** basato su tentativi e aggiustamenti successivi.
>
> *(Nota: Nei capitoli successivi vedremo in dettaglio la matematica e il codice di questi cicli di addestramento: in particolare, nell'Unità 3 studieremo come si aggiornano i pesi nel Percettore, mentre nell'Unità 4 vedremo come la Discesa del Gradiente minimizza l'errore epoca dopo epoca).*

### 📊 Un Esempio Pratico di Calcolo (Passo dopo Passo)

Per fissare bene le idee, facciamo un esempio numerico completo basato su un caso reale. 
Vogliamo prevedere il voto finale di uno studente basandoci sulle sue ore di studio settimanali. Immaginiamo di avere un piccolissimo dataset di 3 studenti:
*   **Studente 1:** Studia $x_1 = 2$ ore $\implies$ Voto reale $y_1 = 4.5$
*   **Studente 2:** Studia $x_2 = 6$ ore $\implies$ Voto reale $y_2 = 6.0$
*   **Studente 3:** Studia $x_3 = 10$ ore $\implies$ Voto reale $y_3 = 8.5$

Supponiamo che il nostro modello lineare sia già stato addestrato e abbia trovato la seguente retta ottimale:

$$
\hat{y} = 0.5 \cdot x + 3.5
$$

Dove il peso (coefficiente angolare) è $w = 0.5$ e il bias (intercetta) è $b = 3.5$.

#### 1. Effettuare una Previsione per un Nuovo Studente
Se arriva un nuovo studente che ha studiato per **5 ore** ($x = 5$), quale voto prevede il modello?
Applichiamo l'equazione della retta:

$$
\hat{y} = 0.5 \cdot 5 + 3.5 = 2.5 + 3.5 = \mathbf{6.0}
$$

Il modello prevede che lo studente otterrà un voto pari a **6.0**.

#### 2. Calcolo dell'Errore Quadratico Medio (MSE) sul Dataset
Per capire quanto è accurata la nostra retta su tutto il dataset, calcoliamo l'MSE. Calcoliamo la previsione $\hat{y}$ e l'errore per ciascun studente:

1.  **Studente 1 ($x_1=2, y_1=4.5$):**
    *   Previsione: $\hat{y}_1 = 0.5 \cdot 2 + 3.5 = 4.5$
    *   Errore (Residuo): $y_1 - \hat{y}_1 = 4.5 - 4.5 = 0$
    *   Errore Quadrato: $(0)^2 = 0$
2.  **Studente 2 ($x_2=6, y_2=6.0$):**
    *   Previsione: $\hat{y}_2 = 0.5 \cdot 6 + 3.5 = 6.5$
    *   Errore (Residuo): $y_2 - \hat{y}_2 = 6.0 - 6.5 = -0.5$
    *   Errore Quadrato: $(-0.5)^2 = 0.25$
3.  **Studente 3 ($x_3=10, y_3=8.5$):**
    *   Previsione: $\hat{y}_3 = 0.5 \cdot 10 + 3.5 = 8.5$
    *   Errore (Residuo): $y_3 - \hat{y}_3 = 8.5 - 8.5 = 0$
    *   Errore Quadrato: $(0)^2 = 0$

Infine, facciamo la media degli errori quadratici ($N = 3$):

$$
MSE = \frac{0 + 0.25 + 0}{3} = \frac{0.25}{3} \approx \mathbf{0.083}
$$

Questo valore rappresenta l'errore totale (o costo) della nostra retta. Ma **$0.083$ è un buon risultato?** Come facciamo a capirlo?

*   **Il problema dell'unità di misura:** Poiché i voti reali sono espressi in "punti" (es. 6.0 o 8.5), l'MSE si trova espresso in **"punti al quadrato"** ($0.083 \text{ punti}^2$). Questo rende difficile valutarlo a colpo d'occhio.
*   **La soluzione (RMSE):** Per riportare l'errore all'unità di misura originale (i voti), possiamo calcolare la radice quadrata dell'MSE (ottenendo la metrica chiamata **RMSE - Root Mean Squared Error**):
    $$RMSE = \sqrt{MSE} = \sqrt{0.083} \approx \mathbf{0.29 \text{ punti}}$$
*   **La valutazione:** Un errore medio di soli $\pm 0.29$ punti su una scala di voti scolastici da 1 a 10 significa che il modello è **estremamente preciso**! Le sue previsioni mancano il voto reale di pochissimo (meno di un terzo di voto).

> [!IMPORTANT]
> **La Lezione più Importante per un Data Scientist:**
> Un numero di per sé non significa nulla. Un errore di $\pm 0.29$ metri ($29$ centimetri) è del tutto trascurabile se stiamo stimando la distanza geografica tra due città, ma sarebbe **catastrofico** in campo medico se un modello dovesse individuare la posizione di un tumore all'interno del corpo umano per orientare un fascio di radioterapia. In quel contesto, un errore di 29 centimetri colpirebbe un organo o tessuto sano completamente diverso, con conseguenze fatali!
> Sta sempre all'essere umano (al programmatore, al ricercatore) **interpretare i dati** conoscendo a fondo sia il funzionamento matematico degli strumenti, sia il contesto reale dell'applicazione. Non bisogna mai accettare ciecamente i risultati di un algoritmo senza aver compreso gli strumenti e il dominio in cui si sta operando.

*(Nota didattica: in questo esempio abbiamo usato pesi $w$ e bias $b$ già calcolati per fare le nostre previsioni. Il processo matematico che permette all'algoritmo di partire da valori casuali ed effettuare le correzioni iterativamente per trovarli da solo verrà approfondito nell'Unità 4 - Addestramento e Valutazione).*

---

## 2.2 Classificazione con la Regressione Logistica

Sebbene contenga il termine "regressione" nel nome, la **Regressione Logistica** è un algoritmo utilizzato per problemi di **classificazione binaria** (prevedere se un dato appartiene alla classe $0$ o alla classe $1$).

Se usassimo la regressione lineare direttamente per la classificazione, potremmo ottenere valori di previsione esterni all'intervallo $[0, 1]$ (ad esempio $-0.5$ o $1.8$), che non hanno senso se interpretati come probabilità.

Per risolvere questo problema, la regressione logistica utilizza una formula lineare interna (chiamata $z$):

$$
z = w \cdot x + b
$$

E ne "schiaccia" l'output tra $0$ e $1$ passandolo attraverso la **funzione Sigmoide** (o logistica):

$$
\sigma(z) = \frac{1}{1 + e^{-z}}
$$

> [!IMPORTANT]
> **Chiarimento Concettuale:**
> **Non si esegue prima una regressione lineare classica per poi passarne il risultato alla sigmoide.** 
> Il modello di regressione logistica viene addestrato da zero come un'unica entità. Durante l'addestramento, l'algoritmo ottimizza i pesi $w$ e il bias $b$ per massimizzare la correttezza della classificazione tramite una funzione di costo chiamata **Log Loss** (o entropia incrociata), e non tramite la minimizzazione dell'errore lineare (MSE). La combinazione lineare $z = w \cdot x + b$ e la sigmoide lavorano insieme fin dall'inizio.

### ❓ FAQ Didattiche: Capire la Matematica del Modello

*   **Perché calcoliamo $z$ con una retta ($w \cdot x + b$) anziché usare un singolo numero costante $z$?**
    Se usassimo un singolo numero costante $z$, la sigmoide restituirebbe sempre la stessa identica probabilità per chiunque (es. tutti gli studenti avrebbero sempre il $60\%$ di probabilità di promozione). 
    Noi vogliamo invece che la probabilità vari al variare delle caratteristiche dello studente (ore di studio $x$). La combinazione lineare $z = w \cdot x + b$ serve proprio a **collegare i dati reali ($x$) all'ingresso della sigmoide**. Al variare delle ore di studio $x$, varia il valore di $z$ e, di conseguenza, la probabilità finale $\sigma(z)$. I parametri $w$ (peso) e $b$ (bias) definiscono quanto ciascuna caratteristica influisce sul risultato.

*   **Che cos'è la Log Loss (Entropia Incrociata)?**
    È la funzione che misura l'errore del modello per correggerlo durante l'addestramento. A differenza dell'errore quadratico (MSE), che misura solo la distanza numerica, la **Log Loss penalizza duramente le risposte in cui il modello è sicuro di sé ma sbaglia**:
    - Se uno studente passa l'esame (classe reale $= 1$) e il modello stima una probabilità del $99\%$ ($\sigma(z) = 0.99$), l'errore (Log Loss) è quasi zero.
    - Se lo studente passa (classe reale $= 1$) ma il modello stima solo l' $1\%$ ($\sigma(z) = 0.01$), la Log Loss applica una **penalizzazione logaritmica gigantesca** (tende a infinito). Questo errore altissimo costringe l'algoritmo ad aggiustare pesantemente i valori di $w$ e $b$ per migliorare alla prossima iterazione.
    - *(Niente panico se la Log Loss ti sembra complessa: approfondiremo la matematica delle funzioni di costo e le loro formule matematiche nell'Unità 4 - Addestramento e Valutazione).*

---

La curva sigmoidea ha una forma a "S" che mappa qualsiasi valore reale di $z$ in un valore compreso strettamente tra $0$ e $1$:

*   Se $z$ è molto grande e positivo, $e^{-z} \to 0$, quindi $\sigma(z) \to 1$.
*   Se $z$ è molto grande e negativo, $e^{-z} \to +\infty$, quindi $\sigma(z) \to 0$.
*   Se $z = 0$, $e^{0} = 1$, quindi $\sigma(z) = 0.5$.

<p class="ta-c">
  <img src="/manuale-libero-online-di-informatica/assets/images/machine-learning/sigmoide_generica.png" alt="Grafico Funzione Sigmoide Generica" style="max-width: 75%; height: auto; border-radius: 8px; box-shadow: 0 4px 12px rgba(0,0,0,0.15); margin: 1.5rem auto; display: block; border: 1px solid var(--sl-color-gray-5);" />
</p>

### Soglia Decisionale
Il valore restituito dalla sigmoide rappresenta la **probabilità** che il campione appartenga alla classe $1$. Per prendere la decisione finale (classe $0$ o $1$), si definisce una soglia decisionale (di solito $0.5$):

$$
\text{Classe prevista} = \begin{cases} 1 & \text{se } \sigma(z) \ge 0.5 \\ 0 & \text{se } \sigma(z) < 0.5 \end{cases}
$$

<p class="ta-c">
  <img src="/manuale-libero-online-di-informatica/assets/images/machine-learning/sigmoide_specifica.png" alt="Grafico Funzione Sigmoide Esempio Specifico" style="max-width: 75%; height: auto; border-radius: 8px; box-shadow: 0 4px 12px rgba(0,0,0,0.15); margin: 1.5rem auto; display: block; border: 1px solid var(--sl-color-gray-5);" />
</p>

### 📊 Un Esempio Pratico di Calcolo (Passo dopo Passo)

Per rendere tutto semplice e concreto, applichiamo le formule su un esempio reale. 
Vogliamo prevedere se uno studente **supererà l'esame (classe $1$)** o **sarà bocciato (classe $0$)** in base alle sue ore di studio settimanali ($x$).

Supponiamo che il nostro modello di regressione logistica sia già stato addestrato e abbia trovato questi parametri:
*   Peso (moltiplicatore delle ore): $w = 0.5$
*   Bias (valore di partenza): $b = -5$

La nostra equazione lineare interna $z$ è quindi:

$$
z = 0.5 \cdot x - 5
$$

Vediamo cosa succede a tre studenti che studiano un numero differente di ore:

#### 1. Studente A ($x = 6$ ore di studio)
1.  **Calcolo di $z$:**
    $$z = 0.5 \cdot 6 - 5 = 3 - 5 = -2$$
2.  **Calcolo della probabilità (Sigmoide):**
    $$\sigma(-2) = \frac{1}{1 + e^{-(-2)}} = \frac{1}{1 + e^{2}} \approx \frac{1}{1 + 7.389} = \frac{1}{8.389} \approx \mathbf{0.119} \implies \mathbf{11.9\%}$$
3.  **Classificazione (Soglia $0.5$):**
    Poiché la probabilità del $11.9\%$ è inferiore alla soglia dello $0.5$ ($11.9\% < 50\%$), il modello prevede che lo studente **non supererà l'esame (Classe prevista = 0)**.

#### 2. Studente B ($x = 10$ ore di studio)
1.  **Calcolo di $z$:**
    $$z = 0.5 \cdot 10 - 5 = 5 - 5 = 0$$
2.  **Calcolo della probabilità (Sigmoide):**
    $$\sigma(0) = \frac{1}{1 + e^{-0}} = \frac{1}{1 + 1} = \frac{1}{2} = \mathbf{0.500} \implies \mathbf{50\%}$$
3.  **Classificazione (Soglia $0.5$):**
    La probabilità è esattamente il $50\%$. Questo rappresenta il **punto di svolta (decision boundary)**: con meno di 10 ore il modello prevede bocciatura, con 10 o più ore prevede promozione.

#### 3. Studente C ($x = 14$ ore di studio)
1.  **Calcolo di $z$:**
    $$z = 0.5 \cdot 14 - 5 = 7 - 5 = 2$$
2.  **Calcolo della probabilità (Sigmoide):**
    $$\sigma(2) = \frac{1}{1 + e^{-2}} \approx \frac{1}{1 + 0.135} = \frac{1}{1.135} \approx \mathbf{0.881} \implies \mathbf{88.1\%}$$
3.  **Classificazione (Soglia $0.5$):**
    Poiché la probabilità del $88.1\%$ è maggiore della soglia dello $0.5$ ($88.1\% \ge 50\%$), il modello prevede che lo studente **supererà l'esame (Classe prevista = 1)**.

---

## 💻 Laboratorio Python (VS Code offline)

Crea un notebook chiamato `unita2.ipynb` ed esegui i passaggi seguenti.

### Parte 1: Laboratorio di Regressione Lineare
Vogliamo prevedere il voto finale di uno studente basandoci sul numero di ore di studio settimanali.

```python
import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score

# Feature X: Ore studio (deve essere bidimensionale per Scikit-Learn)
X = np.array([[2], [4], [6], [8], [10], [12]])

# Target y: Voto ottenuto
y = np.array([4.5, 5.5, 6.0, 7.0, 8.5, 9.0])

# Inizializziamo e addestriamo il modello
reg = LinearRegression()
reg.fit(X, y)

# Prevediamo i valori sul nostro dataset
y_pred = reg.predict(X)

print(f"Modello addestrato: y = {reg.coef_[0]:.2f} * x + {reg.intercept_:.2f}")
print(f"MSE (Errore Quadratico Medio): {mean_squared_error(y, y_pred):.3f}")
print(f"R² (Coefficiente di Determinazione): {r2_score(y, y_pred):.3f}")
```

*   **Nota**: Il coefficiente $R^2$ (R-quadrato) varia tra $0$ e $1$. Più è vicino a $1$, migliore è la capacità del modello di spiegare la variabilità dei dati (un valore di $1$ indica una previsione perfetta).

### Parte 2: Laboratorio di Regressione Logistica
Prevediamo se uno studente supererà o meno l'esame ($1$ o $0$) basandoci sulle ore di studio e sulla percentuale di presenze.

```python
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, confusion_matrix

# Dataset di addestramento
# Feature: [Ore_Studio, Presenze_Percentuale]
X_train = [[12, 90], [5, 60], [15, 95], [8, 70], [20, 100], [4, 50]]
y_train = [1, 0, 1, 0, 1, 0]

# Dati del test set (nuovi studenti)
X_test = [[10, 80], [6, 65]]
y_test = [1, 0]

# Inizializziamo e addestriamo il classificatore logistico
clf = LogisticRegression()
clf.fit(X_train, y_train)

# Eseguiamo le previsioni sul test set
y_pred = clf.predict(X_test)
y_prob = clf.predict_proba(X_test)  # Restituisce le probabilità di classe 0 e classe 1

print(f"Previsioni per gli studenti di test: {y_pred}")
print(f"Probabilità stimate (Classe 0 vs Classe 1):\n{y_prob}")
print(f"Accuratezza sul test set: {accuracy_score(y_test, y_pred) * 100:.1f}%")
```

### Valutazione: La Matrice di Confusione
Per comprendere in dettaglio gli errori commessi da un classificatore, si analizza la **Matrice di Confusione**, che incrocia le classi reali con quelle previste:

```python
cm = confusion_matrix(y_test, y_pred)
print("Matrice di Confusione:")
print(cm)
```

La matrice ha questa struttura:

| | Previsto $0$ | Previsto $1$ |
| :--- | :---: | :---: |
| **Reale $0$** | **Vero Negativo (TN)** | **Falso Positivo (FP)** |
| **Reale $1$** | **Falso Negativo (FN)** | **Vero Positivo (VP)** |

*   **Vero Negativo (TN):** Campioni reali $0$ previsti correttamente come $0$.
*   **Falso Positivo (FP):** Campioni reali $0$ previsti erroneamente come $1$ (Errore di tipo I).
*   **Falso Negativo (FN):** Campioni reali $1$ previsti erroneamente come $0$ (Errore di tipo II).
*   **Vero Positivo (VP):** Campioni reali $1$ previsti correttamente come $1$.

---

## 📝 Esercizi

### Domande Teoriche e di Calcolo

#### Domanda 1
Un modello di regressione lineare ha trovato la seguente retta di regressione: $y = 0.5 \cdot x + 3.8$, dove $x$ rappresenta le ore di studio e $y$ rappresenta il voto finale previsto. 
*   **A)** Qual è il voto previsto per uno studente che studia $5$ ore?
*   **B)** Se uno studente non studia affatto ($x=0$), quale voto prevede il modello? Come si chiama questo parametro nell'equazione del modello?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-unita2-teoria1">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-unita2-teoria1">
        <p><strong>Soluzione:</strong>
        <ul>
            <li><strong>A)</strong> Sostituiamo $x=5$ nell'equazione: $y = 0.5 \cdot 5 + 3.8 = 2.5 + 3.8 = 6.3$. Il voto previsto è <strong>6.3</strong>.</li>
            <li><strong>B)</strong> Se $x=0$, $y = 0.5 \cdot 0 + 3.8 = 3.8$. Il voto previsto è <strong>3.8</strong>. Questo parametro rappresenta l'intercetta (in inglese <strong>bias</strong>).</li>
        </ul>
        </p>
    </div>
</div>

#### Domanda 2
Per quale motivo per i problemi di classificazione binaria si preferisce la Regressione Logistica rispetto alla Regressione Lineare? Descrivi la funzione matematica utilizzata a questo scopo.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-unita2-teoria2">Visualizza la risposta corretta</p>
    <div class="soluzione" id="sol-unita2-teoria2">
        <p><strong>Risposta:</strong> La regressione lineare può produrre in output qualsiasi valore numerico reale (anche negativo o superiore a $1$), il che rende impossibile interpretare l'output come una probabilità di appartenenza a una classe binaria ($0$ o $1$). La regressione logistica risolve questo problema introducendo la funzione <strong>Sigmoide</strong> (o logistica):
        $$
        \sigma(z) = \frac{1}{1 + e^{-z}}
        $$
        Questa funzione "schiaccia" qualsiasi valore di input $z$ in un intervallo compreso strettamente tra $0$ e $1$, permettendo di interpretare il risultato come la probabilità che il dato appartenga alla classe target.</p>
    </div>
</div>

---

### Esercizio Pratico sulla Matrice di Confusione
Un modello diagnostico è stato testato su $100$ pazienti per rilevare una patologia ($1$ = Malato, $0$ = Sano). I risultati del test sono riassunti nella seguente matrice di confusione:

```text
[[75  5]
 [ 8 12]]
```

*   **A)** Identifica il numero di Veri Negativi (TN), Falsi Positivi (FP), Falsi Negativi (FN) e Veri Positivi (VP).
*   **B)** Calcola l'**Accuratezza** del modello, definita come la frazione di previsioni corrette sul totale dei casi:
$$
\text{Accuratezza} = \frac{VP + TN}{VP + TN + FP + FN}
$$
*   **C)** Se fossi un medico, saresti più preoccupato dei $5$ falsi positivi o degli $8$ falsi negativi? Giustifica la risposta basandoti sul significato clinico.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-unita2-pratico1">Visualizza la risoluzione dell'esercizio</p>
    <div class="soluzione" id="sol-unita2-pratico1">
        <p><strong>Soluzione:</strong>
        <ul>
            <li><strong>A)</strong> Dalla matrice di confusione ricaviamo:
                <ul>
                    <li>Veri Negativi (TN) = 75</li>
                    <li>Falsi Positivi (FP) = 5</li>
                    <li>Falsi Negativi (FN) = 8</li>
                    <li>Veri Positivi (VP) = 12</li>
                </ul>
            </li>
            <li><strong>B)</strong> Calcoliamo l'accuratezza:
                $$
                \text{Accuratezza} = \frac{12 + 75}{12 + 75 + 5 + 8} = \frac{87}{100} = 0.87 \text{ (ovvero 87.0\%)}
                $$
            </li>
            <li><strong>C)</strong> In campo medico, i <strong>falsi negativi (8 pazienti)</strong> sono molto più preoccupanti. Un falso negativo rappresenta un paziente effettivamente malato che il modello classifica come sano, con il rischio che non riceva le cure necessarie. Un falso positivo comporta esami di controllo aggiuntivi, ma non mette direttamente a rischio la vita del paziente per mancata diagnosi.</li>
        </ul>
        </p>
    </div>
</div>
