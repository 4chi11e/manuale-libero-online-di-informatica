---
title: "Unità 4: Reti Neurali - Dal Percettore al Deep Learning"
description: "L'ispirazione biologica delle reti neurali, la matematica del Percettore, il problema dello XOR, le funzioni di attivazione, le reti multistrato (MLP) e l'algoritmo di retropropagazione dell'errore (Backpropagation)."
---

Nelle unità precedenti abbiamo esplorato due grandi famiglie del Machine Learning classico:
1. **Modelli Lineari e Logistici (Unità 2):** cercano di trovare relazioni o separare le classi tramite formule matematiche lineari;
2. **Alberi di Decisione e Random Forest (Unità 3):** scompongono i problemi attraverso una sequenza gerarchica di domande del tipo `SE... ALLORA...`, ideali per dati tabulari.

Tuttavia, quando ci troviamo ad affrontare compiti percettivi complessi su dati non strutturati (come il riconoscimento di **immagini** composte da milioni di pixel, la comprensione del **linguaggio naturale** o l'analisi di segnali **audio**), le regole rigide a cascata e le semplici formule lineari non riescono a cogliere la ricchezza delle informazioni.

Per superare queste sfide nasce il paradigma del **Deep Learning (Apprendimento Profondo)**, basato sulle **Reti Neurali Artificiali**: modelli capaci di estrarre e combinare autonomamente caratteristiche via via più astratte dai dati grezzi.

In questa unità partiremo dal componente fondamentale — il singolo **neurone artificiale** (o **Percettore**) —, analizzeremo i suoi limiti geometrici storici (il problema dello *XOR*) e vedremo come collegare più neuroni in una **Rete Neurale Multistrato (MLP)** per risolvere problemi complessi mediante l'algoritmo di **Retropropagazione dell'errore (Backpropagation)**.

---

## 4.1 L'Ispirazione Biologica e il Neurone Artificiale

Le reti neurali artificiali traggono ispirazione dalla struttura microscopica del cervello umano, composto da miliardi di neuroni interconnessi attraverso centinaia di trilioni di sinapsi.

### L'Analogia Biologica e la Struttura Computazionale

```text
  ┌──────────────────────────────────────────────────────┐
  │ 1. DENDRITI (Ingressi Numerici e Pesi Sinaptici)     │
  │    • Riceve le feature del campione:  x1, x2, ..., xn│
  │    • Ciascun canale ha un'importanza: w1, w2, ..., wn│
  └──────────────────────────┬───────────────────────────┘
                             │
                             ▼
  ┌──────────────────────────────────────────────────────┐
  │ 2. CORPO CELLULARE (Combinazione Lineare e Bias)     │
  │    • Esegue la somma pesata di tutti i segnali       │
  │    • Aggiunge il Bias (b) come soglia di base        │
  │                                                      │
  │    Formula:  z = (w1*x1 + w2*x2 + ... + wn*xn) + b   │
  └──────────────────────────┬───────────────────────────┘
                             │
                             ▼
  ┌──────────────────────────────────────────────────────┐
  │ 3. ASSONE / SINAPSI (Funzione di Attivazione)        │
  │    • Decide se e quanto il neurone deve "sparare"    │
  │    • Introduce la non-linearità indispensabile       │
  │                                                      │
  │    Formula:  a = f(z)                                │
  └──────────────────────────┬───────────────────────────┘
                             │
                             ▼
                    Output Finale (a)
```

*   **Nel neurone biologico:** I *dendriti* ricevono segnali elettrochimici da altri neuroni; il *corpo cellulare (soma)* accumula tali cariche elettriche; se l'accumulo supera una determinata soglia di potenziale, il neurone "spara" un impulso lungo l' *assone*, trasmettendolo tramite le *sinapsi* ai neuroni successivi.
*   **Nel neurone artificiale:** I dendriti sono modellati come **ingressi numerici** ($x_1, x_2, \dots, x_n$); ciascuna connessione ha un'importanza quantificata da un **peso sinaptico** ($w_1, w_2, \dots, w_n$); il corpo cellulare calcola la **somma pesata** dei segnali più una costante di **bias** ($b$); infine, una **funzione di attivazione** determina l'output numerico finale ($a$).

---

### La Matematica del Percettore (Rosenblatt, 1958)

Il modello matematico del singolo neurone artificiale riceve un vettore di input $x = [x_1, x_2, \dots, x_n]$ e produce una risposta $a$ attraverso due passaggi sequenziali:

```text
  x1 ──( w1 )──┐
               │
  x2 ──( w2 )──┼──> [ Somma pesata: z ] ──> [ Attivazione: a = f(z) ] ──> Output a
               │           ▲
  xn ──( wn )──┘           │
                     ( + Bias b )
```

#### 1. Combinazione Lineare (Somma Pesata $z$)
Tutti gli ingressi vengono moltiplicati per i rispettivi pesi e sommati al termine di bias:

$$
z = w_1 x_1 + w_2 x_2 + \dots + w_n x_n + b = \sum_{j=1}^{n} w_j x_j + b
$$

*   **Pesi ($w_j$):** Regolano l'importanza e l'effetto di ogni singola feature sulla decisione del neurone:
    *   *Peso positivo ($w_j > 0$):* Un aumento dell'input incentiva l'attivazione del neurone (effetto eccitatorio);
    *   *Peso negativo ($w_j < 0$):* Un aumento dell'input ostacola l'attivazione (effetto inibitorio);
    *   *Peso nullo o vicino a zero ($w_j \approx 0$):* La feature viene ignorata (o ha un impatto irrilevante), poiché il prodotto $w_j \cdot x_j$ tende a zero e non incide sulla somma.
*   **Bias ($b$):** Rappresenta una soglia intrinseca che consente di traslare la funzione decisionale indipendentemente dal valore degli input (se tutti gli ingressi $x_j$ fossero pari a zero, il neurone avrebbe comunque un valore base $z = b$).

#### 2. Applicazione della Funzione di Attivazione ($a = f(z)$)
Il valore continuo $z$ viene passato a una funzione di attivazione $f(z)$ per stabilire l'output finale:

$$
a = f(z)
$$

Nel **Percettore originale di Frank Rosenblatt (1958)**, la funzione di attivazione era una **funzione a gradino (Heaviside Step Function)**:

$$
f(z) = \begin{cases} 1 & \text{se } z \ge 0 \\ 0 & \text{se } z < 0 \end{cases}
$$

### Come Imparava il Percettore di Rosenblatt?

L'algoritmo di apprendimento del percettore originale aggiorna i pesi ogni volta che il modello commette un errore di classificazione. Se l'etichetta reale è $y \in \{0, 1\}$ e la predizione è $\hat{y} = f(z)$, la regola di aggiornamento è:

$$
w_j \leftarrow w_j + \eta \cdot (y - \hat{y}) \cdot x_j
$$
$$
b \leftarrow b + \eta \cdot (y - \hat{y})
$$

Dove $\eta$ (eta) è il **tasso di apprendimento (Learning Rate)**, un parametro compreso solitamente tra $0.001$ e $0.1$ che controlla l'entità di ciascuna correzione.
*   Se la previsione è corretta ($\hat{y} = y$), l'errore $(y - \hat{y}) = 0$, quindi nessun peso viene modificato.
*   Se il modello ha previsto $0$ ma il target era $1$, i pesi associati agli ingressi attivi vengono incrementati.
*   Se il modello ha previsto $1$ ma il target era $0$, i pesi vengono decrementati.

---

## 4.2 Il Limite del Singolo Neurone e il Problema dello XOR

Per comprendere il limite del percettore, dobbiamo chiarire un concetto fondamentale del Machine Learning: il **Confine di Decisione** (*Decision Boundary*).

> **Cos'è il Confine di Decisione?**  
> Quando un modello di classificazione deve decidere se un nuovo dato appartiene alla classe `0` o alla classe `1` (es. *Spam* vs *Non Spam*, oppure *Promosso* vs *Bocciato*), esso traccia una linea di demarcazione nello spazio dei dati. Tutti i punti che cadono da un lato della linea vengono classificati come `1`, mentre quelli dall'altro lato come `0`.

Nel singolo percettore, il confine di decisione corrisponde al punto in cui la somma pesata vale esattamente zero ($w_1 x_1 + w_2 x_2 + b = 0$). Sul piano cartesiano a due dimensioni, questa equazione rappresenta **sempre una linea retta rigida** (o un iperpiano piatto in più dimensioni).

Di conseguenza, un singolo neurone può risolvere esclusivamente problemi **linearmente separabili** (dove le due classi possono essere separate da una retta).

---

### Le Porte Logiche AND e OR (Separabili) vs XOR (Non Separabile)

Il singolo percettore è perfettamente in grado di apprendere funzioni logiche elementari come l'**AND** o l'**OR**, mentre fallisce sistematicamente con la porta **XOR (OR Esclusivo)**:

| $x_1$ | $x_2$ | Target AND | Target OR | Target XOR |
| :---: | :---: | :---: | :---: | :---: |
| 0 | 0 | 0 | 0 | **0** |
| 0 | 1 | 0 | 1 | **1** |
| 1 | 0 | 0 | 1 | **1** |
| 1 | 1 | 1 | 1 | **0** |

<div style="margin: 1.5rem 0; text-align: center;">
  <img src="/manuale-libero-online-di-informatica/assets/images/machine-learning/separabilita_porte_logiche.png" 
       alt="Confronto della separabilità lineare sul piano cartesiano per le porte logiche AND, OR e XOR" 
       class="modal__opener" 
       aprire="#img-separabilita-porte" 
       style="width: 100%; max-width: 100%; height: auto; border-radius: 8px; box-shadow: 0 4px 14px rgba(0,0,0,0.12); border: 1px solid var(--sl-color-gray-5); cursor: zoom-in; display: block;" />
  <p style="font-size: 0.88rem; color: var(--sl-color-gray-3); margin-top: 0.4rem;"><em>(Clicca sull'immagine per ingrandirla a schermo intero)</em></p>
</div>

<!-- modal popup -->
<div id="img-separabilita-porte" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-separabilita-porte">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/machine-learning/separabilita_porte_logiche.png" alt="Confronto della separabilità lineare sul piano cartesiano per le porte logiche AND, OR e XOR">
    </div>
    <p>Confronto della separabilità lineare sul piano cartesiano per le porte logiche AND, OR e XOR</p>
  </div>
</div>

*   **Porta AND (a sinistra):** I tre punti di classe 0 e l'unico punto di classe 1 $(1,1)$ sono separati nettamente dalla retta $x_1 + x_2 - 1.5 = 0$.
*   **Porta OR (al centro):** L'unico punto di classe 0 $(0,0)$ è isolato dai tre punti di classe 1 dalla retta $x_1 + x_2 - 0.5 = 0$.
*   **Porta XOR (a destra):** I punti di classe 1 (in verde) e di classe 0 (in rosso) si trovano posizionati su diagonali incrociate ad "X". **È geometricamente impossibile tracciare un'unica retta che separi le due classi**: qualunque retta sul piano lascerà sempre almeno un punto nel semipiano errato. Per separare lo XOR servirebbero **due rette distinte** (ovvero più neuroni combinati tra loro). 

:::warning[La Crisi Storica dell'AI (Minsky & Papert, 1969)]
Nel 1969, Marvin Minsky e Seymour Papert pubblicarono il celebre libro *Perceptrons*, dimostrando matematicamente l'incapacità di un singolo neurone di risolvere lo XOR. Poiché all'epoca non si conosceva un algoritmo efficiente per addestrare reti composte da più strati di neuroni, la ricerca subì una brusca frenata per oltre un decennio, aprendo la stagione del primo **"Inverno dell'Intelligenza Artificiale" (AI Winter)**.
:::

---

## 4.3 Le Funzioni di Attivazione e la Non-Linearità

Per superare il limite dello XOR e affrontare problemi complessi, la soluzione è combinare più neuroni in strati successivi. Tuttavia, per rendere efficace questa combinazione, **i neuroni devono utilizzare funzioni di attivazione non lineari**.

### Perché la non-linearità è indispensabile?

Se usassimo solo combinazioni lineari ($f(z) = z$), una rete neurale anche con decine di strati intermedi si ridurrebbe matematicamente a un **unico modello lineare equivalente**.

Infatti, la composizione di due funzioni lineari $f(x) = a \cdot x + b$ e $g(x) = c \cdot x + d$ produce:
$$
f(g(x)) = a(c \cdot x + d) + b = (a \cdot c) \cdot x + (a \cdot d + b)
$$
La funzione risultante ha sempre la struttura lineare $A \cdot x + B$. Senza non-linearità, aggiungere strati non aumenta la capacità del modello di apprendere forme e geometrie complesse.

---

### Le Principali Funzioni di Attivazione

#### 1. Sigmoide (Logistica)

<!-- thumbnail sigmoide -->
<div class="thumbnail float-right">
  <img src="/manuale-libero-online-di-informatica/assets/images/machine-learning/attivazione_sigmoide.png" alt="Grafico Funzione Sigmoide" class="modal__opener" aprire="#img-attivazione-sigmoide" style="cursor: zoom-in;" />
  <p>Funzione Sigmoide: $\sigma(z) = \frac{1}{1 + e^{-z}}$</p>
</div>

<!-- modal popup sigmoide -->
<div id="img-attivazione-sigmoide" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-attivazione-sigmoide">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/machine-learning/attivazione_sigmoide.png" alt="Grafico Funzione Sigmoide">
    </div>
    <p>Andamento della funzione di attivazione Sigmoide con asintoti a 0 e 1</p>
  </div>
</div>

$$
\sigma(z) = \frac{1}{1 + e^{-z}}
$$

*   **Intervallo:** $(0, 1)$.
*   **Uso:** Converte qualsiasi valore reale in una probabilità compresa tra 0 e 1. È la scelta ideale nello **strato di output** per problemi di classificazione binaria.
*   **Limite negli strati nascosti:** Per valori di $|z|$ molto grandi (positivi o negativi), la curva si appiattisce quasi completamente e la sua derivata tende a zero. Ciò provoca il fenomeno della *saturazione dei gradienti* (*Vanishing Gradient*), che rallenta o blocca l'aggiornamento dei pesi durante la retropropagazione.

<div class="clear-both"></div>

#### 2. ReLU (Rectified Linear Unit)

<!-- thumbnail relu -->
<div class="thumbnail float-right">
  <img src="/manuale-libero-online-di-informatica/assets/images/machine-learning/attivazione_relu.png" alt="Grafico Funzione ReLU" class="modal__opener" aprire="#img-attivazione-relu" style="cursor: zoom-in;" />
  <p>Funzione ReLU: $f(z) = \max(0, z)$</p>
</div>

<!-- modal popup relu -->
<div id="img-attivazione-relu" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-attivazione-relu">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/machine-learning/attivazione_relu.png" alt="Grafico Funzione ReLU">
    </div>
    <p>Andamento della funzione di attivazione ReLU (Rectified Linear Unit)</p>
  </div>
</div>

$$
\text{ReLU}(z) = \max(0, z)
$$

*   **Intervallo:** $[0, +\infty)$.
*   **Uso:** È lo **standard de facto** per gli strati nascosti (*hidden layers*) nelle reti neurali moderne.
*   **Vantaggi:** È computazionalmente efficientissima (un semplice confronto con lo zero) e per tutti i valori positivi $z > 0$ la sua derivata è costante e pari a $1$. Questo evita la saturazione dei gradienti e consente un addestramento molto più rapido e stabile.

<div class="clear-both"></div>

#### 3. Tangente Iperbolica ($\tanh$)

<!-- thumbnail tanh -->
<div class="thumbnail float-right">
  <img src="/manuale-libero-online-di-informatica/assets/images/machine-learning/attivazione_tanh.png" alt="Grafico Funzione Tangente Iperbolica" class="modal__opener" aprire="#img-attivazione-tanh" style="cursor: zoom-in;" />
  <p>Funzione tanh: $\tanh(z) = \frac{e^z - e^{-z}}{e^z + e^{-z}}$</p>
</div>

<!-- modal popup tanh -->
<div id="img-attivazione-tanh" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-attivazione-tanh">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/machine-learning/attivazione_tanh.png" alt="Grafico Funzione Tangente Iperbolica">
    </div>
    <p>Andamento della funzione di attivazione Tangente Iperbolica centrata sullo zero</p>
  </div>
</div>

$$
\tanh(z) = \frac{e^z - e^{-z}}{e^z + e^{-z}}
$$

*   **Intervallo:** $(-1, 1)$.
*   **Uso:** Ha una forma simile a quella della sigmoide ma è **centrata sullo zero** (*zero-centered*). Questo fa sì che le attivazioni abbiano media vicina a zero, velocizzando la convergenza rispetto alla sigmoide negli strati nascosti.

<div class="clear-both"></div>

#### 4. Softmax (per Classificazione Multi-classe)
Nello strato di output per problemi con più di due classi (es. riconoscere le cifre da 0 a 9):
$$
\text{Softmax}(z_i) = \frac{e^{z_i}}{\sum_{j=1}^{K} e^{z_j}}
$$
Trasforma i valori in uscita in probabilità la cui somma totale è esattamente $1.0$ ($100\%$).

<div class="clear-both"></div>

---

## 4.4 La Rete Neurale Multistrato (MLP)

Collegando i neuroni in strati organizzati si ottiene una **Rete Neurale Multistrato** (Multi-Layer Perceptron - MLP).

<div style="margin: 1.5rem 0; text-align: center;">
  <img src="/manuale-libero-online-di-informatica/assets/images/machine-learning/architettura_mlp.png" 
       alt="Architettura di una Rete Neurale Multistrato MLP: Strato di Input, Strato Nascosto e Strato di Output" 
       class="modal__opener" 
       aprire="#img-architettura-mlp" 
       style="width: 100%; max-width: 100%; height: auto; border-radius: 8px; box-shadow: 0 4px 14px rgba(0,0,0,0.12); border: 1px solid var(--sl-color-gray-5); cursor: zoom-in; display: block;" />
  <p style="font-size: 0.88rem; color: var(--sl-color-gray-3); margin-top: 0.4rem;"><em>(Clicca sull'immagine per ingrandirla a schermo intero)</em></p>
</div>

<!-- modal popup -->
<div id="img-architettura-mlp" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-architettura-mlp">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/machine-learning/architettura_mlp.png" alt="Architettura di una Rete Neurale Multistrato MLP: Strato di Input, Strato Nascosto e Strato di Output">
    </div>
    <p>Architettura di una Rete Neurale Multistrato (Multi-Layer Perceptron - MLP) con connessioni dense (Fully Connected) e propagazione in avanti</p>
  </div>
</div>

Una rete MLP è composta da tre livelli:
1.  **Strato di Input (Input Layer):** Riceve le feature di ciascun campione (es. ore di studio, età, pixel). Non effettua calcoli ma passa semplicemente i numeri in avanti.
2.  **Strati Nascosti (Hidden Layers):** Strati intermedi in cui ogni neurone combina i segnali ricevuti e applica un'attivazione non lineare. Questi strati trasformano lo spazio dei dati, "piegandolo" in modo che le classi diventino separabili.
3.  **Strato di Output (Output Layer):** Emette la risposta finale (un numero continuo per la regressione o una probabilità per la classificazione).

---

### Dallo Schema alla Matematica: Come Funziona il Calcolo

Osservando lo schema sopra (con 3 feature di input, uno strato nascosto a 4 neuroni e uno strato di output a 2 risposte), vediamo esattamente come i numeri fluiscono attraverso le formule matematiche:

#### 1. Il Calcolo del Singolo Neurone Nascosto ($h_1$)
Ciascun neurone dello strato nascosto si comporta come il singolo Percettore visto nella sezione 4.1. Ad esempio, il neurone $h_1$:
1. Riceve in ingresso tutte le 3 feature di input moltiplicate per i rispettivi pesi sinaptici:
   $$
   z_1^{(1)} = w_{11}^{(1)} x_1 + w_{21}^{(1)} x_2 + w_{31}^{(1)} x_3 + b_1^{(1)}
   $$
   *(l'apice $^{(1)}$ indica che siamo nel 1° strato, mentre il pedice $_{11}$ indica il peso dal canale di input 1 al neurone 1)*;
2. Applica la funzione di attivazione non lineare (es. ReLU):
   $$
   h_1 = f\big(z_1^{(1)}\big)
   $$

Lo stesso calcolo avviene in parallelo per tutti gli altri neuroni $h_2, h_3, h_4$.

#### 2. La Forma Compatta Matriciale (Input $\rightarrow$ Nascosto)
Invece di scrivere 4 formule separate, raggruppiamo gli ingressi in un vettore riga $x = [x_1, x_2, x_3]$, tutti i pesi nella matrice $W^{(1)}$ (di dimensione $3 \times 4$) e i bias nel vettore $b^{(1)}$:

$$
\underbrace{
\begin{bmatrix} z_1^{(1)} & z_2^{(1)} & z_3^{(1)} & z_4^{(1)} \end{bmatrix}
}_{z^{(1)} \; (1 \times 4)}
=
\underbrace{
\begin{bmatrix} x_1 & x_2 & x_3 \end{bmatrix}
}_{x \; (1 \times 3)}
\cdot
\underbrace{
\begin{bmatrix}
w_{11}^{(1)} & w_{12}^{(1)} & w_{13}^{(1)} & w_{14}^{(1)} \\
w_{21}^{(1)} & w_{22}^{(1)} & w_{23}^{(1)} & w_{24}^{(1)} \\
w_{31}^{(1)} & w_{32}^{(1)} & w_{33}^{(1)} & w_{34}^{(1)}
\end{bmatrix}
}_{W^{(1)} \; (3 \times 4)}
+
\underbrace{
\begin{bmatrix} b_1^{(1)} & b_2^{(1)} & b_3^{(1)} & b_4^{(1)} \end{bmatrix}
}_{b^{(1)} \; (1 \times 4)}
$$

E le risposte dello strato nascosto diventano il vettore di attivazioni $h$:
$$
h = f\big(z^{(1)}\big) = \begin{bmatrix} f(z_1^{(1)}) & f(z_2^{(1)}) & f(z_3^{(1)}) & f(z_4^{(1)}) \end{bmatrix}
$$

#### 3. Dal Livello Nascosto all'Output (Nascosto $\rightarrow$ Output)
Ora le attivazioni calcolate $h = [h_1, h_2, h_3, h_4]$ diventano **i nuovi ingressi** per lo strato di output, che possiede la sua matrice di pesi $W^{(2)}$ (di dimensione $4 \times 2$) e bias $b^{(2)}$ (di dimensione $1 \times 2$):

$$
z^{(2)} = h \cdot W^{(2)} + b^{(2)}
$$

Infine, applicando la funzione di attivazione finale $g$ (es. Sigmoide o Softmax), otteniamo le predizioni finali:
$$
\hat{y} = g\big(z^{(2)}\big) = \begin{bmatrix} \hat{y}_1 & \hat{y}_2 \end{bmatrix}
$$

#### 4. La Rete come Composizione Unitaria di Funzioni
Unendo i due passaggi, l'intera rete neurale si esprime con un'unica, elegante formula matematica:
$$
\hat{y} = g\Big( f\big( x \cdot W^{(1)} + b^{(1)} \big) \cdot W^{(2)} + b^{(2)} \Big)
$$

*   I dati grezzi $x$ entrano dal primo strato;
*   La funzione interna $f(\dots)$ trasforma lo spazio non lineare delle feature;
*   La funzione esterna $g(\dots)$ produce la stima o la classificazione finale $\hat{y}$.

:::note[Il Teorema di Approssimazione Universale (Cybenko, 1989)]
Una rete neurale con almeno uno strato nascosto sufficientemente ampio e funzioni di attivazione non lineari può **approssimare qualsiasi funzione continua** con precisione arbitraria.
:::

---

### Perché il Feature Scaling è Fondamentale nelle Reti Neurali?

A differenza degli Alberi di Decisione (che analizzano ogni caratteristica singolarmente con soglie indipendenti e non risentono delle scale numeriche), le Reti Neurali **sommano tra loro tutte le feature all'interno della stessa combinazione lineare**:

$$
z = w_1 x_1 + w_2 x_2 + b
$$

Se $x_1$ è lo stipendio (es. $35\,000$) e $x_2$ sono gli anni di esperienza (es. $4$), la feature con i valori più grandi schiaccerà l'altra, rendendo l'addestramento instabile.

> **Regola pratica:** Prima di addestrare una rete neurale, è fondamentale riscalare le feature (ad esempio con `StandardScaler` o `MinMaxScaler` in Scikit-Learn), portando tutte le variabili su una scala numerica comparabile.

---

## 4.5 Come Apprende una Rete Neurale: Epoche, Batch e Backpropagation

L'addestramento di una rete neurale consiste nell'aggiustare progressivamente i valori di tutti i pesi $W$ e bias $b$ affinché le predizioni del modello siano il più vicine possibile alla realtà. 

Per capire come avviene questo processo, dobbiamo chiarire come i dati vengono somministrati alla rete e come il computer riesce a calcolare l'errore ed aggiornare i parametri.

---

### Epoche, Batch e Iterazioni

Nel Deep Learning i dataset contengono spesso decine di migliaia (o milioni) di esempi. Per gestire questa mole di informazioni, si utilizzano tre concetti chiave:

*   **Epoca (Epoch):** È un passaggio completo in cui la rete neurale ha elaborato **l'intero dataset di addestramento** esattamente una volta. Poiché un singolo passaggio non è sufficiente per ottimizzare milioni di parametri, l'addestramento richiede decine o centinaia di epoche.
*   **Batch (o Mini-batch):** È il "blocco" o sottoinsieme di campioni inviato alla rete in un singolo passaggio (ad esempio 32, 64, 100 o 128 immagini alla volta).
*   **Iterazione (o Step):** È il **singolo aggiornamento dei pesi** che la rete esegue dopo aver elaborato un batch.

:::note[Esempio Chiarissimo di Calcolo: Epoca vs Iterazioni]
Immaginiamo di avere un dataset di **$1\,000$ immagini** e di addestrare la rete a blocchi di **$100$ immagini per volta** (*batch size = 100*):

1. **Quante iterazioni servono per fare 1 epoca?**  
   Dividiamo il totale degli esempi per la dimensione del batch:
   $$
   \frac{1\,000 \text{ immagini totali}}{100 \text{ immagini per blocco}} = \mathbf{10 \text{ blocchi}} \implies \mathbf{10 \text{ iterazioni}}
   $$
2. **Cosa succede concretamente durante l'epoca?**
   * La rete prende il **1° blocco** da 100 $\implies$ calcola l'errore ed esegue la **1ª iterazione** (1° aggiornamento pesi);
   * Prende il **2° blocco** da 100 $\implies$ esegue la **2ª iterazione**;
   * ... e così via fino al 10° blocco.
3. **Completamento dell'Epoca:**  
   Dopo **10 iterazioni**, la rete ha "visto" tutte le 1.000 immagini del dataset ($10 \times 100 = 1\,000$). Si è quindi conclusa **1 Epoca**.  
   Se impostiamo l'addestramento su **50 epoche**, la rete eseguirà in totale $50 \times 10 = \mathbf{500 \text{ iterazioni}}$ complessive.
:::

---

### Come fa la rete a lavorare su 100 immagini in un colpo solo?

Potrebbe sembrare che la rete debba elaborare le 100 immagini una dopo l'altra con un lento ciclo `for`. In realtà, il processo sfrutta due principi fondamentali:

#### 1. Il motivo statistico: L'Errore Medio
Invece di correggere i pesi basandosi sull'errore di una singola immagine (che potrebbe essere un'anomalia o contenere rumore), la rete:
1. Calcola la predizione $\hat{y}_i$ e il rispettivo errore $\mathcal{L}_i$ per ciascuna delle 100 immagini del blocco;
2. Calcola la **media aritmetica dell'errore** su tutto il batch:
   $$
   \mathcal{L}_{\text{batch}} = \frac{1}{100} \sum_{i=1}^{100} \mathcal{L}_i
   $$
3. **Esegue un unico aggiornamento dei pesi**, muovendosi nella direzione media indicata dal gruppo. In questo modo le oscillazioni casuali si annullano e l'apprendimento procede in modo molto più fluido e stabile.

#### 2. Il motivo computazionale: Algebra Matriciale e GPU
Come fa il processore a calcolare 100 immagini contemporaneamente?
* Invece di passare un singolo vettore di feature alla volta ($x = [x_1, x_2, \dots, x_n]$), il computer impila le 100 immagini una sotto l'altra formando una **Matrice dei Dati $X$** con 100 righe e $n$ colonne.
* Le schede video moderne (**GPU**), nate per la grafica 3D, contengono migliaia di piccoli core specializzati nell'eseguire moltiplicazioni tra matrici in parallelo.
* Con una **singola operazione matriciale**:
  $$
  Z = X \cdot W^T + b
  $$
  la GPU calcola le attivazioni di tutte le 100 immagini **nello stesso identico ciclo di clock**, in poche frazioni di millisecondo!

$$
\underbrace{
\begin{bmatrix}
x_{1}^{(1)} & x_{2}^{(1)} & \dots & x_{n}^{(1)} \\
x_{1}^{(2)} & x_{2}^{(2)} & \dots & x_{n}^{(2)} \\
\vdots & \vdots & \ddots & \vdots \\
x_{1}^{(100)} & x_{2}^{(100)} & \dots & x_{n}^{(100)}
\end{bmatrix}
}_{\text{Matrice } X \; (100 \times n)}
\cdot
\underbrace{
\begin{bmatrix}
w_1 \\
w_2 \\
\vdots \\
w_n
\end{bmatrix}
}_{\text{Pesi } W}
+ b
=
\underbrace{
\begin{bmatrix}
z^{(1)} \\
z^{(2)} \\
\vdots \\
z^{(100)}
\end{bmatrix}
}_{\text{Output } Z \; (100 \times 1)}
$$

---

### Le 4 Fasi del Ciclo di Addestramento

Ad ogni iterazione (su ciascun batch di dati), la rete ripete un ciclo composto da quattro fasi consecutive:

```text
  ┌────────────────────────────────────────────────────────┐
  │ 1. FORWARD PROPAGATION (Propagazione in Avanti)        │
  │    • Il batch di dati attraversa la rete (Input ──> Out│
  │    • Calcolo di z e attivazione a per ciascun layer    │
  │                                                        │
  │    Formule:  Z = X*W + b   ──>   A = f(Z) ──> Y_pred   │
  └───────────────────────────┬────────────────────────────┘
                              │
                              ▼
  ┌────────────────────────────────────────────────────────┐
  │ 2. CALCOLO DELLA LOSS (Misura dell'Errore Medio)       │
  │    • Confronta le predizioni Y_pred con i target reali │
  │                                                        │
  │    Regressione (MSE):      L = 1/B * Σ (y - y_pred)^2  │
  │    Classificazione (Loss): L = - 1/B * Σ [y*log(y_pred)│
  └───────────────────────────┬────────────────────────────┘
                              │
                              ▼
  ┌────────────────────────────────────────────────────────┐
  │ 3. BACKPROPAGATION (Retropropagazione dell'Errore)     │
  │    • L'errore viaggia all'indietro strato per strato   │
  │    • Calcolo dei gradienti tramite la Regola Catena    │
  │                                                        │
  │    Gradiente:  dL/dW = (dL/dy_pred) * (dy_pred/dz) *...│
  └───────────────────────────┬────────────────────────────┘
                              │
                              ▼
  ┌────────────────────────────────────────────────────────┐
  │ 4. DISCESA DEL GRADIENTE (Aggiornamento Parametri)     │
  │    • I pesi vengono corretti per ridurre la Loss       │
  │    • Passo di correzione regolato dal Learning Rate η  │
  │                                                        │
  │    Formula:  W_nuovo = W_vecchio - η * (dL/dW)         │
  └────────────────────────────────────────────────────────┘
```

1.  **Forward Propagation (Propagazione in Avanti):**
    *   *Cosa fa:* Il batch di dati attraversa la rete dall'input all'output. In ogni strato si calcola la combinazione lineare $Z = XW + b$ e si applica l'attivazione non lineare $A = f(Z)$, fino a ottenere le predizioni finali $\hat{Y}$.
    *   *Intuizione:* È la rete che "fa la sua previsione" sulla base dei pesi che possiede in quel momento.

2.  **Calcolo della Loss (Misura dell'Errore):**
    *   *Cosa fa:* Confronta le previsioni della rete ($\hat{Y}$) con i valori reali corretti ($Y$) per quantificare l'errore medio commesso sul batch:
        *   *Per la Regressione (Mean Squared Error - MSE):*
            $$
            \mathcal{L} = \frac{1}{B} \sum_{i=1}^{B} (y_i - \hat{y}_i)^2
            $$
        *   *Per la Classificazione (Binary Cross-Entropy):*
            $$
            \mathcal{L} = - \frac{1}{B} \sum_{i=1}^{B} \Big[ y_i \log(\hat{y}_i) + (1-y_i) \log(1-\hat{y}_i) \Big]
            $$
    *   *Intuizione:* È il "voto del compito": un unico numero che misura quanto la rete è lontana dal risultato corretto.

3.  **Backpropagation (Retropropagazione dell'Errore):**
    *   *Cosa fa:* È l'algoritmo (Rumelhart et al., 1986) che calcola il **gradiente** per ciascun parametro, ossia la derivata dell'errore rispetto al singolo peso $w$ (o all'intera matrice $W$). Per risalire dall'output fino ai primi strati nascosti, applica a ritroso la **Regola della Catena (Chain Rule)**:
        $$
        \frac{\partial \mathcal{L}}{\partial w_{\text{nascosto}}} = \underbrace{\frac{\partial \mathcal{L}}{\partial \hat{y}}}_{\text{Errore finale}} \cdot \underbrace{\frac{\partial \hat{y}}{\partial z_{\text{out}}} \cdot \frac{\partial z_{\text{out}}}{\partial a_{\text{nas}}} \dots}_{\text{Catena degli strati intermedi}} \cdot \underbrace{\frac{\partial z_{\text{nas}}}{\partial w_{\text{nascosto}}}}_{\text{Impatto del singolo peso}}
        $$
    *   *Intuizione (La "distribuzione delle responsabilità"):* Immagina una catena di montaggio in cui il prodotto finale esce difettoso. Il controllo qualità risale la fabbrica all'indietro per capire **chi e quanto ha contribuito all'errore**. La derivata risponde semplicemente a una domanda pratica: *"Se aumento questo specifico peso $w$ di un briciolo ($+0.01$), l'errore finale salirà o scenderà, e con quale velocità?"*.

4.  **Aggiornamento dei Parametri (Discesa del Gradiente):**
    *   *Cosa fa:* Conoscendo la direzione dell'errore, corregge i parametri muovendoli in senso opposto alla pendenza:
        *   **Per il singolo peso $w$ e il singolo bias $b$:**
            $$
            w_{\text{nuovo}} \leftarrow w_{\text{vecchio}} - \eta \cdot \frac{\partial \mathcal{L}}{\partial w}, \qquad b_{\text{nuovo}} \leftarrow b_{\text{vecchio}} - \eta \cdot \frac{\partial \mathcal{L}}{\partial b}
            $$
        *   **In forma matriciale compatta (tutti i milioni di pesi $W$ aggiornati contemporaneamente dalla GPU):**
            $$
            W_{\text{nuovo}} \leftarrow W_{\text{vecchio}} - \eta \cdot \frac{\partial \mathcal{L}}{\partial W}
            $$
        dove $\eta$ è il **Learning Rate** (tasso di apprendimento).
    *   *Intuizione (La discesa nella nebbia):* Immagina di essere in montagna avvolto da una fitta nebbia e di voler raggiungere la valle (il minimo dell'errore). Non vedi la mappa completa, ma con i piedi senti la pendenza del terreno sotto di te e fai un passo verso il basso:
        *   Se il passo $\eta$ è **troppo grande**, rischi di scavalcare la valle e finire sul versante opposto;
        *   Se il passo $\eta$ è **troppo piccolo**, impiegherai un tempo infinito a scendere;
        *   Gli ottimizzatori moderni (come **Adam**) funzionano come "scarponi intelligenti" che allungano o accorciano il passo automaticamente a seconda della ripidità del terreno.

---

## 4.6 Sintesi del Modulo: Come i Modelli Tracciano i Confini

Ora che conosciamo i tre grandi paradigmi del Machine Learning (Modelli Lineari, Alberi e Reti Neurali), possiamo confrontarli osservando **il modo in cui ciascuno divide lo spazio delle decisioni**:

<div style="margin: 1.5rem 0; text-align: center;">
  <img src="/manuale-libero-online-di-informatica/assets/images/machine-learning/confronto_confini_decisione.png" 
       alt="Confronto geometrico dei confini di decisione: Modelli Lineari vs Alberi di Decisione vs Reti Neurali MLP" 
       class="modal__opener" 
       aprire="#img-confronto-confini" 
       style="width: 100%; max-width: 100%; height: auto; border-radius: 8px; box-shadow: 0 4px 14px rgba(0,0,0,0.12); border: 1px solid var(--sl-color-gray-5); cursor: zoom-in; display: block;" />
  <p style="font-size: 0.88rem; color: var(--sl-color-gray-3); margin-top: 0.4rem;"><em>(Clicca sull'immagine per ingrandirla a schermo intero)</em></p>
</div>

<!-- modal popup -->
<div id="img-confronto-confini" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-confronto-confini">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/machine-learning/confronto_confini_decisione.png" alt="Confronto geometrico dei confini di decisione: Modelli Lineari vs Alberi di Decisione vs Reti Neurali MLP">
    </div>
    <p>Confronto geometrico della forma del confine di decisione: Modelli Lineari (retta/iperpiano), Alberi di Decisione (tagli ortogonali a scatola) e Reti Neurali MLP (superfici curvilinee flessibili)</p>
  </div>
</div>

### Tabella Comparativa dei Paradigmi

| Aspetto | Modelli Lineari / Logistici | Alberi di Decisione / Random Forest | Reti Neurali (Deep Learning) |
| :--- | :--- | :--- | :--- |
| **Confine di Decisione** | **Retta o Iperpiano piatto** (separa con un piano geometrico continuo) | **A gradini / scatole** (combinazione di tagli ortogonali agli assi) | **Superfici curvilinee arbitrarie** (forme complesse e flessibili) |
| **Campi di Utilizzo Ideali** | Relazioni semplici, dataset piccoli o lineari | Dati tabulari (fogli Excel, database con feature eterogenee) | Dati non strutturati (immagini, segnali audio, testo, video) |
| **Interpretabilità** | **Alta**: i pesi indicano direttamente l'importanza di ciascuna feature | **Alta**: le regole decisionali possono essere lette e stampate come diagrammi di flusso | **Bassa** ("scatola nera"): le decisioni derivano da milioni di parametri distribuiti |
| **Scalatura dei Dati (Scaling)** | Spesso raccomandata per regolarizzazione o discesa del gradiente | **Non necessaria**: insensibili all'ordine di grandezza delle colonne | **Indispensabile**: pesi e gradienti dipendono dalla scala numerica dei dati |

---

## 4.7 Esercizi e Laboratorio Pratico

Per consolidare la comprensione teorica e sperimentare l'addestramento pratico di un Percettore e di una Rete Neurale Multistrato in Python:

*   **Verifica Teorica e Calcolo a Mano**:
    *   [Esercizi Teorici: Il Percettore e Reti Neurali](file:///f:/Progetti%20Github/Manuale_Libero_Online_di_Informatica/Repository-manuale/src/content/docs/machine-learning/esercizi-teorici-percettore-reti-neurali.md)
*   **Esercitazione Pratica in Python**:
    *   [Laboratorio: Dal Percettore alle Reti Neurali](file:///f:/Progetti%20Github/Manuale_Libero_Online_di_Informatica/Repository-manuale/src/content/docs/machine-learning/laboratorio-percettore-reti-neurali.md)
