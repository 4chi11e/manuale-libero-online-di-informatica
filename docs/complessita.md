---
layout: default
title: Complessità computazionale
nav_order: 3
has_children: false
---

# Teoria della Complessità Computazionale
{: .no_toc }

## Indice
{: .no_toc .text-delta }

- TOC
{:toc}

## I problemi e la loro complessità

La **teoria della complessità computazionale** si pone come obiettivo quello di analizzare la complessità dei problemi in modo da poterli catalogare e confrontare in base alla loro difficoltà. In questo capitolo verranno trattate le modalità con cui è possibile valutare la complessità dei problemi. Per poterlo fare è necessario iniziare a definire alcuni concetti fondamentali.

### Problema e Algoritmo risolutivo

In informatica, così come in matematica, un problema è una relazione tra un insieme di *istanze* e un insieme di *soluzioni*. La descrizione del problema può essere data in molte forme, con un linguaggio naturale o con un linguaggio matematico, e pone sempre un quesito per cui date una serie di premesse si chiede di trovare una o più soluzioni che soddisfino determinate condizioni. La descrizione del problema spesso prevede che in input venga fornita una serie di valori o variabili che aquistano un valore diverso per ogni istanza del problema

Il concetto di **istanza**, che dovrebbe essere familiare ad un informatico, si può definire in questo contesto come una *specifica formulazione del problema per cui sono stati assegnati determinati valori alle variabili in input*.

<div class="esempio"  markdown="1">

Esempio

Problema 1: determinare se un numero è primo.<br>
Ogni numero che può essere fornito in input al problema rappresenta un istanza del problema, cioè:

I<sub>1</sub> = 3, I<sub>2</sub> = 6, I<sub>3</sub> = 7, ..., I<sub>n</sub> = 127 ...
{: .ta-c}

Problema 2: Ordinamento di un vettore di n elementi.<br>
Ogni istanza è rappresentata da un diverso vettore vettore da ordinare, vettore che può variare per cardinalità e valori che contiene:

I<sub>1</sub> = [5, 7, 2, 1], I<sub>2</sub> = [1], I<sub>3</sub> = [1, 2, 3, 4], ..., I<sub>n</sub> = [4, 77, 128, ... 923] ...
{: .ta-c}

</div>

Il problema numero 2 presenta una caratteristica molto importante per la descrizione di molti problemi: il valore *n* che indica la dimensione del vettore di input. In generale questo valore definisce la *cardinalità dei dati in ingresso* o **cardinalità dell'input**. è evidente che il tempo di esecuzione di un algoritmo può variare anche molto da istanza a istanza e in particolare può cambiare moltissimo al variare del valore di *n*.

Per poter fornire una soluzione ad ogni istanza del problema è necessario eseguire un algoritmo risolutivo del problema. Se indichiamo con *A* l'algoritmo, con *π* il problema e con *I* l'istanza, possiamo dire che: 

*A* risolve *π* se applicato ad ogni sua istanza *I* ne produce la soluzione corretta
{: .importante}

## Analisi della complessità degli algoritmi

Dalle definizioni date finora risulta evidente la correlazione tra problema e algoritmo risolutivo. Per poter analizzare la complessità dei problemi è quindi necessario passare dall'analisi della complessità degli algoritmi risolutivi del problema. Per poterlo fare è necessario adottare dei criteri con cui valutare la complessità.

### Parametri di complessità
I criteri che si possono adottare per valutare la complessità possono essere moltissimi ed è necessario stabilire quali siano quelli più rilevanti e utili nel nostro contesto di lavoro. Alcuni criteri utili in determinati contesti possono essere:

- la semplicità di comprensione o modificabilità del codice sorgente
- l'accessibilità o usabilità dell'interfaccia utente
- la bellezza grafica dell'interfaccia
- ...

Questi criteri seppur importanti in certi contesti non sono adatti per valutare la complessità di un algoritmo poichè sono tutti criteri **soggettivi** e non sono quindi universalmente quantificabili. Questi criteri poi in realtà non ci dicono nulla sull'efficienza dell'algoritmo e quindi sulla complessità del problema risolto.

È quindi necessario identificare **criteri di efficienza oggettivi** degli algoritmi. Questi criteri sono:

- la complessità temporale che consiste nel tempo impiegato per eseguire l'algoritmo
- la complessità spaziale che indica quanta memoria richiede l'algoritmo per la sua esecuzione
- la complessità di I/O che indica il tempo necessario alle operazioni di imput e output effettuate dall'algoritmo
- la complessità di trasmissione che indica il tempo necessario alla trasmissione o ricezione di dati da componenti remote o altri calcolatori

I due criteri più rilevanti sono i primi due e sono quelli su cui si basa la catalogazione dei problemi, in particolar modo il primo.

#### La complessità di tempo
Abbiamo definito la complessità di tempo come la quantità di tempo necessaria all'esecuzione dell'algoritmo, questa definizione però è decisamente semplicistica e in realtà inadatta a valutare oggettivamente un algoritmo e quindi un problema. Il motivo di quest'affermazione è che il tempo necessario all'esecuzione di un algoritmo è strettamente dipendente dalle caratteristiche della macchina che esegue l'algoritmo, caratteristiche completamente indipendenti dall'algoritmo stesso il quale può essere eseguito da chiunque. Quello che ci interessa sapere sono le caratteristiche dell'algoritmo indipendentemente da chi lo esegue.

Nella seguente tabella sono indicati in secondi i tempi di esecuzione di due algoritmi A₁ e A₂ che risolvono lo stesso problema su due computer diversi e con differenti dimensioni dell'input.

<table class="ta-c">
    <tr>
        <th></th>
        <th colspan="2">Computer 1</th>
        <th colspan="2">Computer 2</th>
    </tr>
    <tr>
        <th><a>n</a> </th>
        <th>A₁</th>
        <th>A₂</th>
        <th>A₁</th>
        <th>A₂</th>
    </tr>
    <tr>
        <td>50</td>
        <td>0,005</td>
        <td>0,07</td>
        <td>0,05</td>
        <td>0,25</td>
    </tr>
    <tr>
        <td>100</td>
        <td>0,003</td>
        <td>0,13</td>
        <td>0,18</td>
        <td>0,55</td>
    </tr>
    <tr>
        <td>200</td>
        <td>0,13</td>
        <td>0,27</td>
        <td>0,73</td>
        <td>1,18</td>
    </tr>
    <tr>
        <td>300</td>
        <td>0,32</td>
        <td>0,42</td>
        <td>1,65</td>
        <td>1,85</td>
    </tr>
    <tr>
        <td>400</td>
        <td>0,55</td>
        <td>0,57</td>
        <td>2,93</td>
        <td>2,67</td>
    </tr>
    <tr>
        <td>500</td>
        <td>0,67</td>
        <td>0,72</td>
        <td>4,60</td>
        <td>3,28</td>
    </tr>
    <tr>
        <td>1000</td>
        <td>3,57</td>
        <td>1,60</td>
        <td>18,32</td>
        <td>7,03</td>
    </tr>

</table>

Pssiamo osservare che la misurazione in secondi del tempo di esecuzione non è in grado di descrivere la bontà dell'algoritmo perchè dipende sia dalla potenza di calcolo dei computer sia dalla dimensione dell'input.

Nella realtà ci sono anche altri fattori che determinano la velocità di esecuzione dell'algoritmo. Un programmatore sa infatti che i programmi vengono scritti quasi sempre in un linguaggio di programmazione che poi deve essere tradotto nel linguaggio della macchina che lo esegue. Diversi compilatori possono produrre un codice macchina differente più o meno efficiente, inoltre le singole operazioni in linguaggio macchina richiedono tempi di esecuzione differenti, tempi che possono variare anche al variare della CPU.

È necessario quindi trovare una modalità differente per rappresentare la complessità temporale che dipenda esclusivamente dalle caratteristiche dell'algoritmo.

Il primo passaggio da effettuare è introdurre una nuova notazione che permetta di indicare la complessità temporale indipendentemente dalla dimensione dell'input o meglio che mantenga la cardinalità dell'input come generico parametro. Indicheremo quindi il tempo di calcolo con la funzione *T(n)* che per ora indica un generico tempo di esecuzione in funzione della dimensione dell'input *n*.

Il secondo passaggio è quello di cambiare completamente l'unità di misura utilizzata per misurare il tempo di calcolo, poichè abbiamo visto che la misurazione in secondi è praticamente inutile. La nuova unità di misura dovrà tener conto solo del numero di operazioni effettuate, a prescindere dallo specifico tempo di esecuzione di tale operazione in un determinato calcolatore.

Dovremo assumere che:
- le seguenti istruzioni elementari abbiano lo stesso tempo di calcolo:
  - assegnamento, 
  - operazioni di I/O, 
  - operazioni aritmetiche, 
  - valutazione di espressioni booleane
- qualsiasi accesso alla memoria abbia un costo fisso
- non vi sia alcun grado di parallelismo
- le operazioni abbiano un costo sempre uguale a prescindere dal valore delle variabili coinvolte

In questo modo ogni operazione verrà trattata in egual modo e considerata un'**istruzione a costo unitario** o **passo base**. È evidente che questo rappresenta una semplificazione della realtà ma ci permette di svincolare ogni misurazione dalle caratteristiche tecnologiche dei calcolatori e dei compilatori usati.

La funzione T(n) può quindi essere definita nel seguente modo:

La funzione *T(n)* esprime il numero di passi base necessari affinchè l'algoritmo *A* possa produrre la soluzione di un'istanza di dimensione *n*.
{: .importante}

##### Esempi ed esercizi

ancora da inserire

### Complessità asintotica

Una volta che è stata definita correttamente la complessità di tempo in termini di numero passi base in funzione della dimensione dell'input è possibile porsi l'obiettivo di confrontare gli algoritmi tra di loro. 

Immaginiamo di aver trovato una serie di algoritmi con diversi tempi di calcolo e volerli confrontare tra loro. Supponendo che un passo base richieda 1 microsecondo (10<sup>-6</sup> s) per essere eseguito è possibile costruire la seguente tabella che rappresenta i tempi di esecuzione in secondi dei diversi algoritmi al crescere della dimensione dell'input

|                   | n = 10                | n=100                     | n=1000                | n=10<sup>6</sup>              |
| log(n)            | 10<sup>-6</sup>       | 2·10<sup>-6</sup>         | 3·10<sup>-6</sup>     | 6·10<sup>-6</sup>             |
| √n                | 3·10<sup>-6</sup>     | 10<sup>-5</sup>           | 3·10<sup>-5</sup>     | 10<sup>-3</sup>               |
| n+5               | 15·10<sup>-6</sup>    | 10<sup>-4</sup>           | 10<sup>-3</sup>       | 1 s                           |
| 2·n               | 2·10<sup>-5</sup>     | 2·10<sup>-4</sup>         | 2·10<sup>-3</sup>     | 2 s                           |
| n·log(n)          | 10<sup>-5</sup>       | 2·10<sup>-4</sup>         | 3·10<sup>-3</sup>     | 6 s                           |
| n<sup>2</sup>     | 10<sup>-4</sup>       | 10<sup>-2</sup>           | 1 s                   | 10<sup>6</sup> (~12 gg)       |
| n<sup>2</sup>+n   | 1,1·10<sup>-4</sup>   | 1,01·10<sup>-2</sup>      | 1 s                   | 10<sup>6</sup> (~12 gg)       |
| n<sup>3</sup>     | 10<sup>-3</sup>       | 1 s                       | 10<sup>3</sup> (~1 g) | 10<sup>12</sup> (~30 secoli)  |
| 2<sup>n</sup>     | 10<sup>-3</sup>       | 10<sup>14</sup> secoli    | 10<sup>285</sup> secoli | ----                        |
{: #tabella-tempi-di-calcolo}

Guardando i risultati si possono subito fare due importanti considerazioni:

- per valori di n piccoli tutti gli algoritmi hanno tempi di calcolo accettabili
- per valori di n grandi gli algoritmi differiscono enormemente

Capiamo subito quindi che per vautare la velocità o meglio la complessità di un algoritmo è necessario studiare il suo comportamento per valori di n grandi cioè, detto in termini matematici, studiare l'andamento asintotico di *T(n)*.

Concentrandoci quindi sugli andamenti asintotici possiamo osservare che gli algoritmi si possono dividere in gruppi che hanno un andamento simile:

- il primo, che ha un andamento logaritmico, mantiene sempre valori di *T(n)* estremamente bassi rimanendo sempre allo stesso ordine di grandezza
- il secondo, che è un polinomio con grado inferiore a 1, cresce molto lentamente mantenendosi su frazioni di secondo anche con n grandi
- terzo e quarto, che hanno andamento lineare, crescono lentamente mantenendo sempre buoni tempi di calcolo; la presenza di un coefficiente (2) non modifica significativamente la situazione
- il quinto, che combina un andamento lineare con uno logaritmico, non si discosta dai tempi lineari
- gli altri algoritmi con andamento polinomiale con grado superiore a 1, presentano tempi di calcolo accettabili finchè la dimensione dell'input non è troppo grande, poi i tempi diventano inaccettabili
- l'ultimo, che ha un andamento esponenziale, all'aumentare di n raggiunge molto in fretta tempi di calcolo inaccettabili

Queste osservazioni ci permettono di raggruppare in categorie di tempi di calcolo e quindi categorie di complessità temporale i vari algoritmi sulla base dell'andamento asintotico dei tempi di calcolo. Le categorie sono:

- costante (tempo che non dipende da n ma è fisso)
- logaritmico
- polinomiale con grado inferiore a 1
- lineare (polinomiale con grado uguale a 1)
- pseudolineare (n·log(n))
- polinomiale (con grado maggiore di 1)
- esponenziale
- fattoriale
- n<sup>n</sup>

Nella lista sono state aggiunte per completezza alcune classi non presenti nell'esempio precedente.

#### Notazioni di complessità asintotica

Per chi conosce la matematica il concetto di andamento asintotico dovrebbe essere chiaro ma è compunque importante trattare questo concetto in maggior dettaglio poichè nella teoria della complessità computazionale sono utilizzate diverse notazioni per esprimere la complessità degli algoritmi (e quindi dei problemi). Notare che quando si parla di complessità solitamente se non si specifica nient'altro si dà per scontato che si sta parlando di complessità temporale ma le notazioni di seguito descritte sono valide anche per le complessità spaziale, di IO e di trasmissione.

##### O-grande

La funzione O-grande (leggi o grande) è utilizzata per indicare un limite asintotico superiore della nostra funzione T(n) infatti è definita in questo modo:

$$ f(x) \in O(g(n)) \text{ per } n \to \infty $$

se e solo se

$$ \exists x_0 \in \Bbb{R}, \; c > 0 \quad : \quad f(n) ≤ c · g(x) \ ∀ x > x_0 $$

Prendiamo ad esempio due funzioni:

- $f(n) = 6n^4-2n^3+5$
- $g(n) = n^4$

possiamo dire che $ f(n) \in O(g(n)) $ per $ x \to \infty $, infatti le due funzioni hanno lo stesso grado e $ f(n) $ ha solamente un coefficiente (6) che la rende superiore a $g(n)$ ma la definizione ci consente di scegliere un opportuno coefficiente $c$ per cui moltiplicare $g(n)$ che permette a $g(n)$ di essere superiore a $f(n)$  da un certo valore di n in poi.

In pratica stiamo dicendo che la funzione $f(n)$ ha un andamento asintotico limitato superiormente dalla funzione $g(n)$, senza considerare i coefficienti che come abbiamo visto analizzando [questa](#tabella-tempi-di-calcolo) tabella non sono rilevanti nel considerare gli andamenti asintotici. In altre parole $f(n)$ cresce al massimo come $g(n)$.

È necessario fare una precisazione sulla notazione O-grande: è vero che $f(n) \in O(g(n))$ ma è anche vero che $f(n) \in O(n^5)$ e che $f(n) \in O(2^n)$ poichè entrambe queste relazioni soddisfano la definizione di O-grande e sia $n^5$ che $2^n$ rappresentano un limite oltre il quale $f(n)$ non potrà mai andare asintoticamente. Nonostante sia possibile quindi individuare infinite funzioni superiori a $f(n)$ ha senso individuare solo la funzione più piccola e semplice che indichi il limite superiore di crescita asintotica di $f(n)$.

|$T(n)$         |O-grande   |andamento      |
|-              |-          |-              |
|$34$           |$O(1)$     |costante       |
|$7+3log(n)$    |$O(log(n))$|logaritmico    |
|$7n+12$        |$O(n)$     |lineare        |
|$2n+5 log(n)$  |$O(n)$     |lineare        |
|$2n · 5log(n)$ |$O(n)$     |pseudolineare  |
|$3n^2+5n$      |$O(n^2)$   |quadratico     |
|$2n+5 n·m$     |$O(n^2)$   |quadratico     |
|$2n+5 n·m$     |$O(n^2)$   |quadratico     |
|$3^n+5n^3$     |$O(2^n)$   |esponenziale   |
|$3^n+5n^3 + n!$|$O(n!)$    |fattoriale     |

Conoscendo la matematica si può arrivare a conclusioni piuttosto semplici ma importanti che nel loro insieme possono essere chiamate ***algebra degli O-grandi***:

- $f(n) \in O(h(n))$ e $g(n) \in O(h(n)) \Rightarrow f(n) + g(n) \in O(h(n))$
- $f(n) \in O(h(n))$ e $g(n) \in O(i(n)) \Rightarrow f(n) · g(n) \in O(h(n) · i(n))$
- $an^k \in O(n^k)$
- $n^k \in O(n^k+i)$ per ogni $i$ positivo
- $f(n) \in O(g(n))$ e $g(n) \in O(h(n)) \Rightarrow f(n) \in O(h(n))$ (proprietà transitiva)

Nel calcolare la complessità di blocchi di codice si possono invece fare le seguenti osservazioni:

- **Teorema della somma**: la complessità di un blocco costituito da più blocchi in sequenza è quella del blocco di complessità maggiore,
- **Teorema del prodotto**: la complessità di un blocco costituito da più blocchi annidati è data dal prodotto delle complessità dei blocchi componenti.

Con questi strumenti è possibile calcolare la complessità di qualsiasi algoritmo.

Nonostante la notazione O-grande sia quella più comunemente usata non è nè l'unica nè la più precisa, ne esistono infatti altre due molto importanti.

##### Ω-grande

La funzione Ω-grande (leggi omega grande) è una funzione piuttosto simile alla funzione O-grande ma è utilizzata per indicare un limite asintotico inferiore della nostra funzione T(n) infatti è definita in questo modo:

$$ f(x) \in Ω(g(n)) \text{ per } n \to \infty $$

se e solo se

$$ \exists x_0 \in \Bbb{R}, \; c > 0 \quad : \quad f(n) ≥ c·g(x) \ ∀ x > x_0 $$

Prendiamo anche in questo caso le due funzioni:

- $f(n) = 6n^4-2n^3+5$
- $g(n) = n^4$

possiamo dire che $ f(n) \in Ω(g(n)) $ per $ x \to \infty $, infatti le due funzioni hanno lo stesso grado e $ f(n) $ e secondo la definizione possiamo scegliere un opportuno coefficiente $c$ per cui moltiplicare $g(n)$ che permette a $g(n)$ di essere inferiore a $f(n)$ da un certo valore di n in poi.

In pratica stiamo dicendo che la funzione $f(n)$ ha un andamento asintotico limitato inferiormente dalla funzione $g(n)$, senza considerare i coefficienti che sono irrilevanti. In altre parole $f(n)$ cresce almeno come $g(n)$.

Anche in questo caso è necessario fare una precisazione: è vero che $f(n) \in O(g(n))$ ma è anche vero che $f(n) \in O(n^3)$ e che $f(n) \in O(log(n))$ poichè entrambe queste relazioni soddisfano la definizione di Ω-grande e sia $n^3$ che $log(n)$ sono sicuramente inferiori a $f(n)$ per $ x \to \infty $. Nonostante sia possibile quindi individuare infinite funzioni inferiori a $f(n)$ ha senso individuare solo la funzione più grande e semplice che indichi il limite minimo di crescita asintotica di $f(n)$.

##### Θ-grande

La notazione Θ-grande (leggi teta grande) è una funzione che permette di unire in un'unica notazione le caratteristiche delle due funzioni precedenti, essa indica infatti in modo preciso l'andamento asintotico della funzione T(n). Θ-grande è definita come:

$$ f(x) \in Θ(g(n)) \text{ per } n \to \infty $$

se e solo se

$$ \exists x_0 \in \Bbb{R}, \; c_1 > 0, c_2 > 0  \quad : \quad c_1·g(x) ≤ f(n) ≤ c_2·g(x)  \ ∀ x > x_0 $$

Prendiamo anche in questo caso le due funzioni:

- $f(n) = 6n^4-2n^3+5$
- $g(n) = n^4$

possiamo dire che $ f(n) \in Θ(g(n)) $ per $ x \to \infty $, infatti le due funzioni hanno lo stesso grado e $ f(n) $ e secondo la definizione possiamo scegliere due opportuni coefficienti $c_1$ e $c_2$ per cui moltiplicare $g(n)$ e ottenere due valori uno inferiore e uno superiore a $f(n)$ da un certo valore di n in poi.

In pratica stiamo dicendo che la funzione $f(n)$ ha un andamento asintotico uguale a quello della funzione $g(n)$, senza considerare i coefficienti che sono irrilevanti. In altre parole $f(n)$ cresce asintoticamente come $g(n)$, nè più nè meno.

### Confronto tra algoritmi

Una volta calcolate le complessità degli algoritmi espresse con le notazioni O-grande o Θ-grande è immediato effettuare un confronto tra due algoritmi, basta conoscere l'ordine degli infiniti studiati in matematica.

Per il calcolo della complessità c'è però un problema che non è ancora stato preso in considerazione. Per capire di che problema si tratta consideriamo un esempio reale: un algoritmo di ordinamento di un vettore. A prescindere dal tipo di algoritmo è evidente che il tempo di calcolo non dipenderà solo dalla dimensione del vettore (la dimensione n dell'input) ma anche dalla situazione iniziale del vettore. L'ordinamento di un vettore già ordinato richiederà un tempo molto breve, mentre l'ordinamento di un vettore completamente disordinato richiederà molto più tempo. Ci rendiamo facilmente conto che possiamo distinguere tre diverse situazioni che corrispondono a tre complessità potenzialmente molto diverse tra loro:

- caso migliore: è il caso o insieme di casi col minor tempo di calcolo (a parità di n), in questo caso un vettore già ordinato
- caso peggiore: è il caso o insieme di casi col maggior tempo di calcolo (a parità di n)
- caso medio: ipotetico vettore il cui tempo di calcolo è il tempo medio di calcolo di tutte le istanze del problema

Quando si considera la complessità computazionale si fa riferimento al caso peggiore e se non viene specificato nulla si dà per scontato che ci si sta riferendo a quello. Solitamente invece il caso migliore è considerato poco rilevante nel valutare la complessità dell'algoritmo, infatti mentre il caso migliore è solo un caso particolare e fortunato con un tempo di calcolo particolarmente basso il caso peggiore è quello che ci indica effettivamente la capacità dell'algoritmo di trovare la soluzione corretta in qualsiasi situazione.

Per caso medio, a differenza degli altri due, non ci si riferisce ad un caso o ad un insieme di casi reali ma si indende un ipotetico caso il cui tempo di calcolo è il tempo medio di calcolo su tutte le possibili istanze del problema. Non è detto che sia possibile calcolare a priori il tempo medio di calcolo, spesso infatti è necessario calcolare effettivamente il tempo medio per l'esecuzione dell'algoritmo su tante istanze casuali diverse. Il valore ottenuto è un valore molto utile da conoscere perchè indica mediamente in quanto tempo è possibile trovare la soluzione del problema. 

Non è detto che in applicazioni reali venga scelto di utilizzare l'algoritmo che abbia la complessità minore che è vautata nel caso peggiore. Un esempio noto è il quick sort, il più usato algoritmo di ordinamento di vettori che ha complessità $Θ(n^2)$ nel caso peggiore e $Θ(n·log(n))$ nel caso medio. Quick sort infatti è preferibile ad altri algoritmi come merge sort che hanno complessità $Θ(n·log(n))$ anche nel caso peggiore e questo a causa di una serie di altri fattori come la complessità spaziale o altri dettagli legati a dettagli implementativi.

Può essere molto interessante approfondire lo studio delle complessità degli algoritmi di ordinamento a partire da [qui](https://it.wikipedia.org/wiki/Algoritmo_di_ordinamento).


## La complessità dei problemi

Finora si è parlato della complessità degli algoritmi dando per scontato un concetto cioè che la complessità di un problema è dato dalla complessità del miglior algoritmo disponibile che lo risolve. Algoritmo e problema però sono due cose diverse e non è detto che al momento sia stato scoperto il milgior algoritmo possibile per un determinato problema. Ci si chiede quindi se sia possibila valutare la complessità intrinseca di un problema a prescindere dagli algoritmi al momento noti.

### Complessità intrinseca di un problema

Un problema di cui si conosce un algoritmo, con la relativa complessità computazionale potrebbe, in futuro, essere risolto algoritmicamente in un altro modo, magari più efficiente (ad esempio con complessità di tempo inferiore)

- Fino a che punto è possibile “migliorare” la soluzione di un problema?
- Fino a che punto possiamo sperare che qualcuno in futuro possa formulare un algoritmo migliore per risolvere il nostro problema?
- Ci sono limiti al di sotto dei quali non è possibile scendere?

Per alcuni problemi la risposta è affermativa: si conosce il limite oltre il quale nessun algoritmo può scendere, per ingegnoso che possa essere.

Si parla di **“lower bound” del problema, ovvero il numero minimo di operazioni che qualsiasi soluzione al problema comporta** e che dipende dalla struttura stessa del problema mentre è indipendente da un qualsiasi algoritmo, anche sofisticatissimo. Il lower bound di un problema è una proprietà intrinseca dello stesso (spesso facciamo riferimento ad esso chiamandolo complessità intrinseca del problema), ed è un’informazione importantissima per chi sviluppa software.

La conoscenza del lower-bound di un problema ha un’importanza fondamentale: ci permette di non perdere tempo nella ricerca di un algoritmo più veloce, che non può esistere. Abbiamo così la certezza che nessun “genio” (neanche fra 10.000 anni) potrà mai trovare un algoritmo che sia più veloce del lower-bound del problema.

La dimostrazione di lower-bound è difficile. Bisogna analizzare, ad esempio, la natura del problema, indipendentemente da quella che può essere una possibile strategia di soluzione. Sono pochi i problemi di cui si è dimostrata l’esistenza di lower-bound. Due esempi famosi sono il problema della ricerca di un elemento in una tabella che è equivalente alla ricerca di una parola in un dizionario e il problema dell’ordinamento di una lista di oggetti (siano parole, numeri, ecc…). Nel primo caso il lower-bound è $log(n)$, cioè nessun algoritmo (basato su confronto di elementi) può impiegare, nel worst-case, meno di $log(n)$ operazioni in presenza di una tabella con n elementi. Nel secondo caso è stato dimostrato che un qualsiasi algoritmo che ordina un insieme di n elementi non può effettuare (nel worst-case) meno di $n·log(n)$ operazioni elementari.

### Tipologia di problemi

I problemi possono essere di varia natura e in base al tipo quesito che pongono è possibile classificarli in quattro gruppi:
- problemi di **decisione**: un problema è di decisione se chiede di dare una risposta del tipo vero o falso, ad esempio dato un numero n determinare se esso è primo;
- problemi di **ricerca**: sono quei problemi che chiedono di trovare una soluzione corretta in un insieme di soluzioni possibili, ad esempio trovare un fattore primo di un numero può essere espresso come problema di ricerca che consiste nel trovare in un insieme di coppie (n, p) una coppia per cui p è un fattore primo di n;
- problemi di **conteggio** o **enumerazione**: sono quei problemi che chiedono di trovare il numero di soluzioni ad un dato problema di ricerca, ad esempio dato un numero n contare il numero di fattori primi di n;
- problema di **ottimizzazione**: sono quei problemi in cui si chiede di trovare la miglior soluzione possibile nell'insieme di tutte le soluzioni possibili di un problema di ricerca, ad esempio dato un grafo G trovare un insieme indipendente di G di dimensione massima.
- problema di **funzione**: sono quei problemi in cui ci si aspetta una singolo output per ogni input, ma l'output è più complesso di quello di un problema di decisione, cioè, non è solo sì o no;esempi notevoli includono il problema del commesso viaggiatore, che richiede la strada presa dal commesso viaggiatore, e il problema della fattorizzazione degli interi, che richiede la lista dei fattori.

Nonostante questi problemi siano apparentemente di natura molto diversa è in realtà possibile trasformare ogni problema in un problema di decisione riformulandolo opportunamente senza modificare il grado di complessità del problema. Le modalità in cui è possibile effettuare tale operazione sono complesse e richiederebbero uno studio più approfondito della teoria della computazione, basti sapere che è possibile farlo. Questo concetto è importante perchè ci permette di dire che nonostante i problemi si possano presentare sotto forme molto diverse, il modo in cui questo viene presentato non influisce sulla sua complessità poichè esso può essere riformulato in altri termini senza influire sulla sua complessità intrinseca. Sarà quindi ora possibile iniziare a catalogare i problemi in base alla loro complessità

### Problemi computabili e non computabili

Preso un problema, di qualsiasi tipo esso sia, è possibile fare una prima catalogazione tra problemi risolvibili e problemi non risolvibli o comunque non sempre risolvibili. Preso l'insieme di tutti i possibili problemi immaginabili, il primo sottoinsieme è infatti l'insieme dei problemi **computabili** o **decidibili**. Tutti gli altri problemi saranno quindi chiamati **non computabili** o **indecidibili**

Un problema P si dice computabile quando esiste un algoritmo A che lo risolve, cioè applicando ad A una qualunque istanza I di P ne fornisce l'esatta soluzione in un numero finito di passi.
{: .importante}

È importante sottolineare che l'algoritmo deve trovare la soluzione per ogni istanza del problema e che lo deve fare in un numero finito di passi, cioè in un tempo finito, impiegare un tempo infinito significherebbe infatti non trovare mai la soluzione.

La domanda che ci si pone è: i due sottoinsiemi appena identificati sono entrambi non vuoti? Sicuramente esistono problemi che sappiamo risolvere e problemi che non siamo in grado di risolvere, ma siamo proprio sicuri che i problemi che attualmente non siamo in grado di risolvere non possano avere una soluzione a noi sconosciuta? A questa domanda si è cercato di dare risposta per molto tempo e alla fine dell'800 con la teoria degli infiniti si era già riusciti a dare una risposta affermativa ma non era ancora stato formulato un problema per cui fosse anche stata dimostrata l'indecidibilità. Nel 1936 Alan Touring riuscì a dimostrare l'indecidibilità di un problema, il problema della terminazione (halting problem).

#### Problema della terminazione

Il problema della terminazione (dall'inglese Halting problem, tradotto anche con problema dell'arresto o problema della fermata) chiede se sia sempre possibile, descritto un algoritmo e un determinato ingresso finito, stabilire se l'algoritmo in questione termina o continua la sua esecuzione all'infinito. È stato dimostrato che non può esistere un algoritmo generale in grado di risolvere il problema per tutti i possibili ingressi. La versione più nota del problema è quella proposta nel 1936 dal matematico Alan Turing, insieme alla dimostrazione della sua indecidibilità.

##### Dimostrazione

Si supponga per assurdo che esista un algoritmo che prende in ingresso un qualsiasi altro algoritmo a avente un ingresso finito d ed è in grado di stabilire se a termina in tempo finito (restituendo il valore true) o se non termina (restituendo in questo caso il valore false).


```java
// halts() restituisce true se il suo input termina, false altrimenti
boolean C(a, d):
    return halts(a(d));
```

Essendo per la macchina sia a sia d sequenze indistinte di simboli, è possibile passare come secondo parametro di C lo stesso algoritmo a, ovvero eseguire C(a,a).

Sia ora loop un programma che non termina mai (ad esempio while true do done): è possibile costruire un altro algoritmo chiamato K che, prendendo in ingresso a, esegue loop non restituendo alcun valore se C(a,a) restituisce true, mentre restituisce true se C(a,a) restituisce false. Ovvero:

```java
// loop() è una funzione che non termina
boolean K(a):
  if C(a,a) loop();
    return true;
```

Quindi K termina restituendo il valore true solo se l'algoritmo a con ingresso a non termina, altrimenti K continua a eseguire loop ciclando all'infinito senza restituire alcun valore.

Passando all'algoritmo K lo stesso K, ovvero K(K), questo algoritmo termina, restituendo il valore true, solo se l'algoritmo K con input K non termina. Ovvero K(K) termina se e solo se K(K) non termina, il che è una contraddizione che prova essere assurda l'ipotesi iniziale sull'esistenza di un algoritmo C che, dato un qualsiasi algoritmo a e un suo input d, è in grado di stabilire se a(d) termina o non termina.

### Problemi trattabili e intrattabili

Nell'analizzare la complessità degli algoritmi sono state identificate diverse classi di complessità e si è visto che ci sono classi di complessità per cui all'aumentare della dimensione dell'input il tempo di esecuzione rimane molto contenuto, per altri il tempo aumenta considerevolmente ma rimane ancora gestibile, ci sono altri casi, come ad esempio per la complessità esponenziale, in cui i tempi di calcolo diventano velocemente proibitivi. è evidente quindi che i problemi, possano essere catalogati tra problemi trattabili, quelli il cui tempo di calcolo non cresce in modo eccessivo, e quelli in cui i tempi di calcolo diventano proibitivi.

Di seguito sono riportati i tempi di esecuzione di algoritmi con diverse complessità di calcolo al variare della dimensione dell'input dando come tempo di esecuzione di un passo base 1 microsecondo (10<sup>-6</sup> s)

|                   | n = 10                | n=100                     | n=1000                | n=10<sup>6</sup>              |
| log(n)            | 10<sup>-6</sup>       | 2·10<sup>-6</sup>         | 3·10<sup>-6</sup>     | 6·10<sup>-6</sup>             |
| √n                | 3·10<sup>-6</sup>     | 10<sup>-5</sup>           | 3·10<sup>-5</sup>     | 10<sup>-3</sup>               |
| n                 | 10<sup>-5</sup>       | 10<sup>-4</sup>           | 10<sup>-3</sup>       | 1 s                           |
| n·log(n)          | 10<sup>-5</sup>       | 2·10<sup>-4</sup>         | 3·10<sup>-3</sup>     | 6 s                           |
| n<sup>2</sup>     | 10<sup>-4</sup>       | 10<sup>-2</sup>           | 1 s                   | 10<sup>6</sup> (~12 gg)       |
| n<sup>3</sup>     | 10<sup>-3</sup>       | 1 s                       | 10<sup>3</sup> (~1 g) | 10<sup>12</sup> (~30 secoli)  |
| 2<sup>n</sup>     | 10<sup>-3</sup>       | 10<sup>14</sup> secoli    | 10<sup>285</sup> secoli | ----                        |
{: #tabella-tempi-di-calcolo-2}

Guardando i risultati si può intuire che è possibile suddividere ulteriormente i problemi in problemi risolvibili velocimente e problemi trattabili ma trattabili solo quando n non cresce eccessivamente. Per un programmatore questa distinzione è importante poichè nella realtà passare da un tempo di calcolo quadratico ad uno pseudolineare rappresenta un salto di qualità decisamente notevole. Effettivamente i tempi polinomiali con esponente maggiore di 1 non sono particolarmente efficienti e ci si chiede se non sia opportuno ritenere anche i problemi con tale complessità intrattabili. Intanto è già evidente la differenza con i problemi esponenziali, inoltre è interessante osservare come cambiano i tempi di calcolo al variare della capacità computazionale dei calcolatori.

Nella seguente tabella sono riportati i miglioramenti ottenibili, in termini di dimensioni delle istanze risolvibili, per diverse funzioni di complessità, al migliorare della tecnologia dei calcolatori. con $x_i$ è indicata la dimensione di un'istanza risolvibile attualmente in un minuto per la i-esima funzione di complessità.

| T(n)  | Computer odierno  | Computer 100 volte più veloce | computer 10.000 volte più veloce  |
|-------|-------------------|-------------------------------|-----------------------------------|
| $n$   |$x_1$              |$100·x_1$                      |$10.000·x_1$                       |
| $n^2$ |$x_2$              |$10·x_3$                       |$100·x_3$                          |
| $n^3$ |$x_3$              |$4,6·x_3$                      |$21,5·x_3$                         |
| $n^5$ |$x_4$              |$2,5·x_4$                      |$6,3·x_4$                          |
| $2^n$ |$x_5$              |$x_5+6,6$                      |$x_5+13,2$                         |
| $3^n$ |$x_6$              |$x_6+4,2$                      |$x_6+8,4$                          |
{: .ta-c}

Osservando i risultati riportati in tabella e considerando che, come indicato dalla [legge di Moore](https://it.wikipedia.org/wiki/Legge_di_Moore), la potenza di calcolo dei calcolatori aumenta esponenzialmente raddoppiando ogni anno, è lecito aspettarsi che un problema di complessità polinomiale oggi ritenuto intrattabile perchè presenta una dimensione dell'input troppo grande, diventerà trattabile in futuro con l'aumento delle capacità computazionali dei computer. Non si può dire la stessa cosa per i problemi esponenziali. Guardando il modo in cui sono stati ottenuti i risultati si può capire meglio quale sia l'entità dei miglioramenti ottenibili.

Considerando che:

$$ \text{tempo di esecuzione} = \text{tempo esecuzione passo base} · \text{numero passi base} $$

$$ 60s = tepb · T(n) $$

$$ T(n) = \frac{60s}{tepb} $$

Se indichiamo con $n$ la dimensione dell'input per cui l'esecuzione dell'algoritmo richiede 1 minuto con un computer di riferimento, e con $n_x$ la dimensione dell'input per cui l'esecuzione dell'algoritmo richiede 1 minuto con un computer x volte più potente otteniamo che:  

- algoritmo polinomiale di esponente k: 

$$n^k = \frac{60s}{tepb} $$

$$n_x^k = \frac{60s}{tepb/x} $$

$$n_x = \sqrt[k]{x}$$

- algoritmo esponenziale di base k:

$$k^n = \frac{60s}{tepb} $$

$$k^{n_x} = \frac{60s}{tepb/x} $$

$$n_x=n+log_k(x)$$

Bisogna poi ricordare che l'umento della potenza di calcolo x avviene in modo esponenziale. Per i problemi con complessità polinomiale significa quindi un miglioramento più che lineare nella dimensione dell'input infatti l'esponenziale domina la radice. Si può dire quindi che problemi di complessità polinomiale sono di per sè trattabili e il limite della dimensione dell'input che siamo in grado di gestire è puramente tecnologico.

Non si può fare la stessa osservazione per quanto riguarda i problemi esponenziali, per cui l'umento delle prestazioni esponenziale viene annullato dal logaritmo che è proprio la funzione inversa dell'esponenziale.

Possiamo quindi concludere che:

la distinzione tra problemi trattabili e intrattabili corrisponde alla distinzione tra problemi con complessità polinomiale e problemi con complessità esponenziale.
{: .importante}

A scanso di errori (che gli studenti fanno molto spesso) è importante ricordare che i problemi intrattabili rientrano comunque nella categoria dei problemi computabili infatti i tempi di calcolo sono per noi inaccettabili ma finiti.


## Altre cose da considerare e aggiungere

### Classi di complessità P e NP

- [P (complessità)](https://it.wikipedia.org/wiki/P_(complessit%C3%A0))
- [NP (complessità)](https://it.wikipedia.org/wiki/NP_(complessit%C3%A0))

#### Classe NPC o NP-Completa

- [NP-completo su Wikipedia](https://it.wikipedia.org/wiki/NP-completo)

#### P vs NP

- [Classi di complessità P e NP su Wikipedia](https://it.wikipedia.org/wiki/Classi_di_complessit%C3%A0_P_e_NP)

## Risolvere problemi intrattabili


## Riferimenti esterni
- [Teoria della complessità computazionale su Wikipedia](https://it.wikipedia.org/wiki/Teoria_della_complessit%C3%A0_computazionale)
- [Notazione O-grande su Wikipedia](https://it.wikipedia.org/wiki/O-grande)
- [Algoritmi di ordinamento su Wikipedia](https://it.wikipedia.org/wiki/Algoritmo_di_ordinamento)
- [Complessità intrinseca di un problema](http://dsc.unisa.it/alberto/Alberto/09-10/IG/Dispense/Dispense%204.3%20-%20Complessit%C3%A0%20Intrinseca.pdf): dispensa del Prof. Alberto Postiglione per il corso "Concetti di Base su Algoritmi, Strutture Dati e Programmazione" dell'Università degli Studi di Salerno.
- [Problema computazionale su Wikipedia](https://it.wikipedia.org/wiki/Problema_computazionale)
- [Problema della terminazione su Wikipedia](https://it.wikipedia.org/wiki/Problema_della_terminazione)
- [Legge di Moore su Wikipedia](https://it.wikipedia.org/wiki/Legge_di_Moore)
