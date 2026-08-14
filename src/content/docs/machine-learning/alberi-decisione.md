---
title: "Unità 3: Alberi di Decisione e Random Forest"
description: "Il funzionamento degli alberi di decisione, il calcolo dell'impurezza di Gini, la regolarizzazione per prevenire l'overfitting, e il funzionamento dei metodi ensemble con le Random Forest."
---

Nelle unità precedenti abbiamo visto modelli (lineari e logistici) che provano a tracciare una linea retta o una curva continua nello spazio per separare le classi o prevedere valori. Esiste però un altro paradigma del Machine Learning classico estremamente potente, intuitivo e molto vicino al modo di ragionare umano: i **modelli basati su regole di decisione**.

Il modello capostipite di questa famiglia è l'**Albero di Decisione (Decision Tree)**. In questa unità vedremo come funziona la sua struttura, come si calcola matematicamente dove effettuare una suddivisione dei dati, come evitare che memorizzi troppo i dettagli (overfitting) e come unire più alberi insieme per formare una **Random Forest**.

---

## 3.1 La Struttura dell'Albero di Decisione

Un albero di decisione è un modello predittivo strutturato come un diagramma di flusso gerarchico (un grafo ad albero orientato dall'alto verso il basso). Ogni nodo rappresenta una domanda su una determinata caratteristica (feature), i rami rappresentano le risposte possibili (sotto-condizioni) e i nodi terminali contengono la previsione finale.

```text
                  [ Nodo Radice ] (Tutti gli studenti)
                         │
             Domanda: Ore Studio >= 5?
                   ┌─────┴─────┐
                  Sì           No
                  ▼            ▼
           [ Nodo Figlio ]   [ Foglia 1 ] (Previsione: Bocciato)
                 │
       Domanda: Presenze >= 80%?
            ┌────┴────┐
           Sì         No
           ▼          ▼
     [ Foglia 2 ]   [ Foglia 3 ] (Previsione: Bocciato)
(Previsione: Promosso)
```

In un albero si distinguono tre tipi di nodi:
*   **Nodo Radice (Root Node):** È il nodo iniziale, posizionato in cima, che contiene l'intero dataset. Da qui parte la prima ramificazione.
*   **Nodi Decisionali o Intermedi (Decision Nodes):** Rappresentano una condizione logica (es. *«Le ore di studio sono $\ge 5$?»* o *«La percentuale di presenze è $\ge 80\%$?»*). Dividono i dati in due o più rami figli.
*   **Nodi Foglia o Terminali (Leaf Nodes):** Si trovano alla fine delle ramificazioni e non si dividono ulteriormente. Contengono la **previsione finale** (ad esempio l'esito *«Promosso»* o *«Bocciato»* nella classificazione, o un valore continuo preciso nella regressione).

> **Come funziona la regressione negli alberi? (Chiarimento sul valore puntuale previsto):**
> Nei problemi di regressione (dove vogliamo prevedere un valore continuo, come il voto d'esame da 1 a 10), l'albero non restituisce un intervallo di valori, ma un **singolo valore numerico preciso (puntuale)**.
> Questo valore è calcolato come la **media aritmetica** dei target di tutti i campioni del Training Set che sono finiti in quella specifica foglia durante l'addestramento.
> *Esempio:* Se uno studente finisce in una foglia che, durante l'addestramento, conteneva 5 studenti che hanno ottenuto come voti reali $6, 7, 7, 8, 9$, il modello calcolerà la media di questi voti ($\frac{6+7+7+8+9}{5} = 7.4$) e assegnerà la previsione fissa di **$7.4$** a chiunque finisca in quella foglia. Non vi## 3.2 Come si Costruisce un Albero: L'Impurezza di Gini

Per costruire l'albero, l'algoritmo deve decidere come suddividere i dati. L'obiettivo è dividere gli studenti in gruppi che siano il più possibile "omogenei" (o puri), ovvero composti da studenti che appartengono tutti alla stessa classe (es. tutti Promossi o tutti Bocciati).

Per misurare matematicamente il grado di "disordine" o di "mescolanza" all'interno di un gruppo, utilizziamo una metrica chiamata **Impurezza di Gini (Gini Impurity)**.

### L'analogia intuitiva: Il barattolo di biglie

Immagina di avere un barattolo contenente delle biglie di due colori, rosso (Promossi) e blu (Bocciati):
*   **Purezza assoluta (Gini = 0):** Il barattolo contiene **solo biglie rosse**. Se peschi due biglie a caso, saranno sicuramente dello stesso colore. Non c'è alcun disordine.
*   **Massimo disordine (Gini = 0.5):** Il barattolo contiene **metà biglie rosse e metà blu**. Se peschi due biglie a caso, c'è il 50% di probabilità di pescare colori diversi. C'è massima mescolanza.

### La Formula (senza paura!)

La formula generale per calcolare l'impurezza di Gini $I_G$ è:

$$
I_G = 1 - \sum_{i=1}^{C} p_i^2
$$

Se lavoriamo su un problema di **classificazione binaria** (con solo due classi, come Promosso/Bocciato), possiamo eliminare il simbolo di sommatoria ($\sum$) e scrivere la formula in modo molto più semplice:

$$
I_G = 1 - (p_{\text{promosso}}^2 + p_{\text{bocciato}}^2)
$$

Dove:
*   $p_{\text{promosso}}$ è la frazione di studenti promossi nel gruppo ($\frac{\text{numero promossi}}{\text{totale studenti}}$).
*   $p_{\text{bocciato}}$ è la frazione di studenti bocciati nel gruppo ($\frac{\text{numero bocciati}}{\text{totale studenti}}$).

> **Il significato matematico:** La somma dei quadrati delle proporzioni ($p_{\text{promosso}}^2 + p_{\text{bocciato}}^2$) indica la probabilità che, scegliendo a caso due elementi dal gruppo, questi appartengano allo stesso colore. Sottraendo questo valore da $1$, calcoliamo la probabilità che appartengano a classi diverse (ossia la probabilità di commettere un errore di classificazione se assegnassimo le etichette in modo casuale). Più è alta questa probabilità di errore, più il gruppo è "impuro".

### Esempio Pratico: Dividere una classe di studenti

Vediamo come l'albero applica questo calcolo per decidere dove fare una ramificazione.
Immaginiamo di avere un gruppo iniziale di **10 studenti**:
*   **6 Promossi** ($p_{\text{promosso}} = \frac{6}{10} = 0.6$)
*   **4 Bocciati** ($p_{\text{bocciato}} = \frac{4}{10} = 0.4$)

#### Fase 1: Calcolare l'impurezza di partenza (Nodo Radice)
Applichiamo la nostra formula semplificata al gruppo iniziale:

$$
\begin{aligned}
I_{G,\text{inizio}} &= 1 - (p_{\text{promosso}}^2 + p_{\text{bocciato}}^2) \\
&= 1 - (0.6^2 + 0.4^2) \\
&= 1 - (0.36 + 0.16) \\
&= 1 - 0.52 = \mathbf{0.48}
\end{aligned}
$$

Il gruppo di partenza ha un disordine molto alto ($0.48$), quasi vicino al massimo teorico di $0.5$.

#### Fase 2: Valutare una suddivisione (Split)
L'albero propone di dividere gli studenti in base alla regola: *«Le ore di studio sono $\ge 5$?»*. Questo split separa i 10 studenti in due nuovi gruppi:
*   **Ramo Sinistro (Sì - Ore $\ge 5$):** 5 studenti totali $\implies$ 5 Promossi, 0 Bocciati.
*   **Ramo Destro (No - Ore $< 5$):** 5 studenti totali $\implies$ 1 Promosso, 4 Bocciati.

#### Fase 3: Calcolare l'impurezza dei due nuovi gruppi
Calcoliamo l'impurezza di Gini per ciascuno dei due rami figli:

*   **Gruppo Sinistro ($I_{G,\text{sin}}$):** 
    Le proporzioni sono $p_{\text{promosso}} = \frac{5}{5} = 1.0$ e $p_{\text{bocciato}} = \frac{0}{5} = 0.0$.
    $$I_{G,\text{sin}} = 1 - (1.0^2 + 0.0^2) = 1 - 1 = \mathbf{0} \quad \text{(Gruppo Puro!)}$$
    *Significato:* Il gruppo è perfettamente omogeneo, contiene solo promossi.

*   **Gruppo Destro ($I_{G,\text{des}}$):** 
    Le proporzioni sono $p_{\text{promosso}} = \frac{1}{5} = 0.2$ e $p_{\text{bocciato}} = \frac{4}{5} = 0.8$.
    $$I_{G,\text{des}} = 1 - (0.2^2 + 0.8^2) = 1 - (0.04 + 0.64) = 1 - 0.68 = \mathbf{0.32}$$
    *Significato:* C'è ancora un po' di disordine, ma molto inferiore rispetto al punto di partenza.

#### Fase 4: Calcolare l'impurezza media dopo la divisione
Per valutare la bontà complessiva di questa suddivisione, calcoliamo la media delle due impurezze. Questa media deve essere **ponderata** (dando più importanza al gruppo che contiene più elementi). Nel nostro caso i due gruppi contengono entrambi 5 studenti su 10 totali (una frazione del $50\%$ o $0.5$ ciascuno):

$$
\begin{aligned}
I_{G,\text{split}} &= (\text{Frazione Sinistra} \cdot I_{G,\text{sin}}) + (\text{Frazione Destra} \cdot I_{G,\text{des}}) \\
&= \left(\frac{5}{10} \cdot 0\right) + \left(\frac{5}{10} \cdot 0.32\right) = 0 + 0.16 = \mathbf{0.16}
\end{aligned}
$$

#### Fase 5: Calcolare il Guadagno di Gini (Gini Gain)
Infine, misuriamo quanto disordine abbiamo "eliminato" grazie a questa divisione, sottraendo l'impurezza finale da quella iniziale:

$$
\text{Guadagno} = I_{G,\text{inizio}} - I_{G,\text{split}} = 0.48 - 0.16 = \mathbf{0.32}
$$

Un guadagno di **$0.32$** è un ottimo risultato! Significa che lo split ha ridotto significativamente l'incertezza. 

L'albero di decisione calcolerà questo guadagno per ogni possibile suddivisione (es. provando soglie come 2 ore, 3 ore, ecc.) e sceglierà lo split che offre il **guadagno maggiore**. Successivamente, applicherà lo stesso procedimento in modo ricorsivo sui nodi figli finché non si arresta.

> **Nota Teorica (Entropia come alternativa):**
> Al posto di Gini, alcuni algoritmi misurano il disordine tramite l'**Entropia**, un concetto mutuato dalla teoria dell'informazione:
> $$H = - \sum p_i \log_2(p_i)$$
> Dal punto di vista pratico, Gini ed Entropia si comportano in modo quasi identico, ma l'impurezza di Gini è preferita come impostazione predefinita in molte librerie (tra cui Scikit-Learn) perché non richiede il calcolo di logaritmi ed è quindi più veloce da eseguire al computer.


---

## 3.3 Il Rischio di Overfitting e la Regolarizzazione

Gli alberi di decisione sono modelli non parametrici estremamente flessibili. Se non poniamo alcun limite alla loro crescita, continueranno a dividersi fino a quando ogni singola foglia conterrà esattamente un solo campione del dataset.

Un albero del genere otterrà un'accuratezza del **100% sul Training Set**, ma sarà andato incontro a un **Overfitting estremo**: avrà memorizzato ogni minima eccezione e rumore del set di addestramento, fallendo completamente nel generalizzare su dati nuovi (Validation/Test set).

```text
Albero senza limiti (Overfitting)          Albero Regolarizzato (Generalizza)
       [Ore Studio >= 5?]                        [Ore Studio >= 5?]
         ┌──────┴──────┐                           ┌──────┴──────┐
        Sì             No                         Sì             No
        ▼              ▼                          ▼              ▼
 [Voto >= 6?]     [Voto >= 4?]                [Promosso]     [Bocciato]
   ┌────┴────┐      ┌────┴────┐                  (99% sicuro)   (80% sicuro)
  Sì         No    Sì         No
  ▼          ▼     ▼          ▼
[Prom.]    [Bocc.] [Prom.]   [Bocc.]
(1 studente)       (1 studente)
```

Per prevenire l'overfitting, dobbiamo applicare delle tecniche di **Regolarizzazione** limitando la crescita dell'albero tramite la regolazione di parametri (chiamati iperparametri):

1.  **Massima Profondità (`max_depth`):** Indica il numero massimo di livelli dell'albero (la distanza massima tra la radice e la foglia più lontana). Bloccare la profondità a un valore piccolo (es. 3 o 4) impedisce all'albero di creare regole troppo specifiche.
2.  **Campioni Minimi per la Divisione (`min_samples_split`):** Il numero minimo di campioni che un nodo deve contenere per essere autorizzato a dividersi ancora.
3.  **Campioni Minimi per Foglia (`min_samples_leaf`):** Il numero minimo di campioni che una foglia terminale deve contenere. Impedisce la creazione di foglie basate su un solo studente.
4.  **Potatura (Pruning):** Consiste nel lasciar crescere l'albero senza limiti e poi "tagliare" (potare) i rami che non portano a un incremento significativo delle prestazioni sul Validation Set.

---

## 3.4 L'unione fa la forza: Le Random Forest

Un singolo albero di decisione tende ad avere un'alta varianza (è molto instabile: una piccola modifica ai dati di addestramento può cambiare radicalmente la struttura dell'albero). 

Per risolvere questo limite, Leo Breiman nel 2001 ha introdotto le **Random Forest (Foreste Casuali)**, basate sul concetto di **Ensemble Learning** (l'apprendimento d'insieme): combinare le previsioni di molti modelli "deboli" per ottenerne uno estremamente robusto.

```text
                  [ Input: Caratteristiche dello Studente ]
                         │
        ┌────────────────┼────────────────┐
        ▼                ▼                ▼
  [ Albero 1 ]     [ Albero 2 ]     [ Albero 100 ]
        │                │                │
     Prevede:         Prevede:         Prevede:
    Promosso         Bocciato         Promosso
        │                │                │
        └────────────────┼────────────────┘
                         ▼
                   [ Votazione ] (Maggioranza)
                         ▼
               Previsione: PROMOSSO
```

### Come funziona una Random Forest?
Una Random Forest addestra in parallelo centinaia di alberi di decisione diversi tra loro, basandosi su due principi di casualità:

1.  **Bootstrap Aggregating (Bagging):** Ciascun albero viene addestrato su un sotto-dataset creato prendendo campioni a caso **con reinserimento** (o rimpiazzo). Questo significa che lo stesso campione può essere duplicato nello stesso albero, e che alberi diversi lavorano su insiemi di dati parzialmente **sovrapposti** ma con combinazioni uniche. A livello matematico, quando i dataset sono grandi, in ogni estrazione bootstrap circa il $63.2\%$ dei dati originali viene selezionato (alcuni una sola volta, molti duplicati o triplicati), mentre il restante $36.8\%$ rimane escluso (dati definiti *Out-Of-Bag*).
2.  **Casualità delle Feature (Feature Randomness):** Quando un albero deve scegliere la migliore caratteristica per effettuare uno split, non analizza tutte le feature a disposizione, ma solo un sottoinsieme casuale (es. solo 2 feature estratte a caso su 10). Questo rende gli alberi molto diversi e scorrelati tra loro.

### La Decisione Finale
Quando inseriamo un nuovo dato (es. un nuovo studente):
*   In problemi di **classificazione**, ciascun albero esprime un voto. La foresta assegna la classe che ha ottenuto la **maggioranza dei voti**.
*   In problemi di **regressione**, ciascun albero calcola un valore continuo. La foresta restituisce la **media aritmetica** delle stime di tutti gli alberi.

Grazie a questa cooperazione, la Random Forest abbatte drasticamente la varianza e l'overfitting del singolo albero, diventando uno degli algoritmi di Machine Learning classici più performanti e versatili in assoluto.

## 3.5 Il Compromesso tra Bias e Varianza (Bias-Variance Tradeoff)

Arrivati a questo punto, è naturale chiedersi: *perché alcuni modelli tendono all'underfitting e altri all'overfitting?* La risposta risiede in un concetto teorico fondamentale del Machine Learning: il **compromesso tra Bias e Varianza**.

Qualsiasi errore di previsione di un modello può essere scomposto in due componenti principali (più una componente di rumore casuale inevitabile nei dati):

### 1. Il Bias (Distorsione o Pregiudizio)
Rappresenta l'errore sistematico introdotto quando un modello fa **assunzioni troppo semplici o rigide** per cercare di approssimare la realtà. La parola inglese *bias* significa letteralmente "pregiudizio" o "inclinazione preconcetta": il modello assume a priori che la regola dei dati sia semplice, costringendosi a fare errori sistematici se la realtà è invece complessa.
*   **Alto Bias (Modello troppo semplice):** Il modello ha forti assunzioni rigide (es. assume che la relazione sia una retta o si basi su un'unica domanda) e quindi manca della flessibilità necessaria per catturare la complessità reale dei dati.
*   **Esempio con gli alberi:** Un albero di decisione limitato ad una profondità massima pari a 1 (`max_depth=1`). Questo modello farà un solo e unico split (es. *«Ore Studio >= 5?»*), presumendo che il successo scolastico dipenda solo da una singola regola binaria. Questo "pregiudizio" rigido lo costringe a commettere sistematicamente errori grossolani.
*   **Effetto:** Causa **Underfitting**. Il modello ha prestazioni mediocri sia sul Training Set sia sul Test Set.

### 2. La Varianza (Instabilità)
Rappresenta la sensibilità del modello alle piccole fluttuazioni del dataset di addestramento.
*   **Alta Varianza:** Il modello è estremamente flessibile e instabile. Se cambiamo anche solo pochi dati nel Training Set, il modello si adatta a queste variazioni cambiando completamente la sua struttura e le sue previsioni.
*   **Esempio con gli alberi:** Un albero di decisione lasciato crescere senza alcun limite di profondità. Creerà ramificazioni microscopiche per isolare ogni singolo studente (es. *«Se ha studiato 4.3 ore, ha il 90% di presenze e porta gli occhiali... allora è promosso»*). Se modifichiamo i dati di addestramento anche di una sola persona, l'albero si dividerà in punti completamente diversi, generando previsioni del tutto instabili.
*   **Effetto:** Causa **Overfitting**. Il modello ha prestazioni eccezionali sul Training Set (accuratezza vicina al 100%) ma fallisce sul Test Set, poiché ha memorizzato il rumore casuale e le eccezioni invece delle regole generali.

---

### L'analogia del bersaglio

Per capire intuitivamente questo concetto, immagina di lanciare delle freccette verso un bersaglio. In questo gioco:
*   Il **centro del bersaglio ($*$)** rappresenta la **verità** (la previsione corretta al 100%).
*   Ogni **freccetta ($o$)** rappresenta la **previsione** fatta da un modello addestrato su un diverso campione di dati.
*   La **distanza dal centro** rappresenta il **Bias** (l'errore sistematico dovuto alle semplificazioni del modello).
*   La **dispersione (quanto sono sparpagliate le freccette)** rappresenta la **Varianza** (l'instabilità del modello al variare dei dati).

```text
       ALTA VARIANZA               BASSA VARIANZA
    ┌─────────────────┐         ┌─────────────────┐
    │  o    o    o    │         │                 │
A   │    o  *  o      │         │      o o o      │
L   │  o    o    o    │         │      o * o      │
T   │                 │         │      o o o      │
O   │ (Disperso/Fuori)│         │ (Compatto/Fuori)│
    └─────────────────┘         └─────────────────┘
    ┌─────────────────┐         ┌─────────────────┐
B   │      o   o      │         │                 │
A   │    o   *   o    │         │        *        │
S   │      o   o      │         │      (o o)      │
S   │                 │         │                 │
O   │ (Disperso/Centro)│        │ (Compatto/Centro)│
    └─────────────────┘         └─────────────────┘
      * = Centro reale    o = Freccetta/Previsione
```

#### Come interpretare i quattro quadranti:

1.  **Basso Bias, Bassa Varianza (In basso a destra - Il modello ideale):** 
    Le freccette sono tutte strettamente raggruppate intorno al centro del bersaglio. Il modello è stabile (bassa varianza) e colpisce sempre nel segno (basso bias).
2.  **Alto Bias, Bassa Varianza (In alto a destra - Underfitting):** 
    Le freccette sono molto vicine tra loro (bassa varianza, il modello è coerente e prevedibile), ma sono concentrate lontano dal centro (alto bias). Il modello commette costantemente lo stesso errore sistematico perché le sue assunzioni di partenza sono troppo semplici e rigide. *Esempio: la Regressione Lineare.*
3.  **Basso Bias, Alta Varianza (In basso a sinistra - Overfitting):** 
    Le freccette circondano in media il centro (basso bias, il modello avrebbe la flessibilità per colpire il bersaglio), ma sono disperse caoticamente in ogni direzione (alta varianza). Le previsioni cambiano selvaggiamente ad ogni lancio a seconda del dataset specifico. *Esempio: un singolo albero di decisione non limitato.*
4.  **Alto Bias, Alta Varianza (In alto a sinistra - Il caso peggiore):** 
    Le freccette sono sia lontane dal centro (alto bias) sia sparpagliate ovunque (alta varianza). Il modello è contemporaneamente inadeguato nelle sue regole e instabile nelle sue previsioni.

---

### Confronto tra i Modelli Classici Studiati

La tabella seguente riassume le caratteristiche dei modelli visti in queste prime unità, aiutandoti a capire come si posizionano nel compromesso bias-varianza:

| Modello | Bias | Varianza | Rischio Principale | Come si Regolarizza (Previene Overfitting) |
| :--- | :---: | :---: | :---: | :--- |
| **Regressione Lineare/Logistica** | Alto | Bassa | Underfitting | Selezione attenta delle caratteristiche, regolarizzazione dei coefficienti. |
| **Albero di Decisione (singolo)** | Basso | Alta | Overfitting | Limitare profondità (`max_depth`), campioni minimi (`min_samples_split`, `min_samples_leaf`). |
| **Random Forest** | Basso | Bassa | Nessuno (ottimo equilibrio) | Regolare il numero di alberi (`n_estimators`) e la profondità dei singoli alberi. |

> **Nota Importante (Niente è assoluto):**
> I valori di Bias e Varianza indicati nella tabella descrivono la **tendenza predefinita** di questi modelli quando vengono usati nella loro forma standard. Non sono proprietà fisse ed immutabili in assoluto:
> *   Un **albero di decisione** ha un'alta varianza di default, ma se lo limitiamo forzatamente impostando `max_depth=1`, riduciamo drasticamente la sua varianza aumentando il suo bias (spostandolo verso l'underfitting).
> *   Un **modello lineare** ha un alto bias di default, ma se aggiungiamo moltissime caratteristiche polinomiali complesse (es. $x^2, x^3, \dots, x^{10}$), aumentiamo la sua varianza e riduciamo il suo bias (spostandolo verso l'overfitting).
> In sintesi: gli iperparametri e la **regolarizzazione** servono proprio a controllare questo bilanciamento, permettendoci di spostare il modello lungo la curva del compromesso per trovare il punto di errore minimo sul Test Set.

### Il Bagging si applica ad altri modelli?

Il **Bagging** (estrarre campioni a caso con rimpiazzo e fare la media delle previsioni) è un concetto matematico universale che può essere applicato a *qualsiasi* modello di Machine Learning, non solo alle Random Forest.

Ad esempio, è possibile utilizzare questa tecnica per problemi di regressione: le Random Forest nascono sia per la classificazione che per la regressione (in quest'ultimo caso Scikit-Learn fornisce la classe `RandomForestRegressor`), dove ogni albero calcola una previsione numerica puntuale e il risultato finale della foresta è la media aritmetica di tutte le risposte.

Tuttavia, applicare il Bagging a modelli già molto stabili, come la **Regressione Lineare**, è di scarsa utilità. Se si addestrano 100 regressioni lineari su campioni diversi, si otterranno 100 rette quasi identiche e la loro media sarà indistinguibile da un singolo modello lineare classico, ma sarà costata 100 volte più calcoli. Il Bagging fa miracoli solo sui modelli instabili ad alta varianza, come gli alberi di decisione, perché ne cura il difetto di fabbrica principale.



---

## 3.6 Laboratorio Pratico in Python (Scikit-Learn)

Per svolgere questo laboratorio sul tuo computer, scarica ed esegui localmente il Notebook Jupyter dedicato:
*   [Scarica il Notebook: unita3_alberi_decisione.ipynb](/manuale-libero-online-di-informatica/assets/codice/python/unita3_alberi_decisione.ipynb)

Di seguito trovi il codice Python completo del laboratorio, seguito da una spiegazione dettagliata di ciascuna parte.

```python
import matplotlib.pyplot as plt
from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier, plot_tree
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score

# 1. Generiamo un dataset sintetico (500 campioni, 2 feature)
X, y = make_classification(n_samples=500, n_features=2, n_redundant=0, 
                           n_clusters_per_class=1, random_state=42)

# 2. Dividiamo in Train e Test set (80/20)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# 3. Addestriamo un Albero di Decisione (con profondità massima limitata per regolarizzare)
albero = DecisionTreeClassifier(max_depth=3, random_state=42)
albero.fit(X_train, y_train)

# Previsioni e valutazione dell'Albero
y_pred_alb = albero.predict(X_test)
print(f"Accuratezza del singolo Albero: {accuracy_score(y_test, y_pred_alb) * 100:.1f}%")

# 4. Addestriamo una Random Forest (composta da 100 alberi decisionali cooperanti)
foresta = RandomForestClassifier(n_estimators=100, max_depth=3, random_state=42)
foresta.fit(X_train, y_train)

# Previsioni e valutazione della Foresta
y_pred_for = foresta.predict(X_test)
print(f"Accuratezza della Random Forest: {accuracy_score(y_test, y_pred_for) * 100:.1f}%")

# 5. Disegniamo la struttura dell'Albero di Decisione
plt.figure(figsize=(12, 8))
plot_tree(albero, 
          feature_names=["Caratteristica A", "Caratteristica B"], 
          class_names=["Classe 0", "Classe 1"], 
          filled=True, 
          rounded=True)
plt.title("Struttura dell'Albero di Decisione Addestrato (max_depth=3)")
plt.show()
```

### Spiegazione Dettagliata del Codice

#### A. Importazione dei Moduli (`sklearn`)
*   `make_classification`: È una funzione di utilità di Scikit-Learn che genera dataset sintetici (casuali ma dotati di una struttura logica interna). È ideale per esercitarsi e testare modelli di classificazione senza dover caricare file esterni.
*   `DecisionTreeClassifier`: La classe ufficiale che implementa l'algoritmo del singolo albero di decisione per la classificazione.
*   `RandomForestClassifier`: La classe ufficiale per creare e gestire le Random Forest.
*   `plot_tree`: Una funzione che permette di disegnare visivamente il grafico dell'albero decisionale addestrato, mostrando le domande e i nodi.

#### B. Generazione e Suddivisione dei Dati (Punti 1 e 2)
*   `n_samples=500` e `n_features=2`: Generiamo un dataset composto da 500 campioni e sole 2 caratteristiche (colonne). Manteniamo il numero di feature a 2 in modo da poter visualizzare e comprendere facilmente lo schema grafico dell'albero.
*   `train_test_split(..., test_size=0.2)`: Separa i dati in **Training Set (80%)** per addestrare i due modelli e **Test Set (20%)** per valutarne l'accuratezza in modo neutrale su dati mai visti prima.

#### C. Creazione e Regolarizzazione del Singolo Albero (Punto 3)
*   `max_depth=3`: Questo parametro limita la crescita dell'albero a una profondità massima di 3 livelli (il nodo radice più altri 3 sotto-livelli). È lo strumento principale di **regolarizzazione**: impedendo all'albero di dividersi ulteriormente, si previene l'overfitting.
*   `random_state=42`: Imposta un "seme" per il generatore di numeri casuali di Scikit-Learn. Questo garantisce che, ogni volta che esegui il codice, l'albero si divida esattamente nello stesso modo, rendendo i tuoi esperimenti ripetibili e confrontabili.

#### D. Creazione della Random Forest (Punto 4)
*   `n_estimators=100`: Definisce il numero di alberi decisionali da addestrare in parallelo all'interno della foresta. Inserire più alberi aumenta la robustezza del modello riducendone la varianza, ma richiede più memoria e tempo di calcolo. Un valore di 100 è lo standard predefinito ottimale.
*   `max_depth=3`: Anche in questo caso stiamo ponendo un limite alla profondità di ciascuno dei 100 singoli alberi componenti la foresta.

#### E. Rappresentazione Grafica dell'Albero (Punto 5)
*   `plot_tree(...)`: Genera il diagramma dell'albero.
    *   `feature_names`: Associa i nomi alle caratteristiche all'interno dei nodi decisionali.
    *   `class_names`: Associa i nomi delle classi ai nodi foglia.
    *   `filled=True`: Colora i nodi per identificare visivamente la classe predominante al loro interno (es. arancione per la Classe 0 e blu per la Classe 1). L'intensità del colore indica la purezza del nodo: più il colore è scuro ed acceso, più l'impurezza di Gini del nodo è vicina a 0.
    *   `rounded=True`: Disegna i nodi con angoli arrotondati per migliorarne la leggibilità grafica.

---

## 3.7 Esercizi ed Esercitazioni (Carta e Penna)

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

### Esercizio 2: Prevenire l'Overfitting negli Alberi
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
