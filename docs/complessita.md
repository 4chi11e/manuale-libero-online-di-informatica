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






## Altre cose da considerare e aggiungere

### Complessità intrinseca di un problema
Un problema di cui si conosce un algoritmo, con la relativa complessità computazionale potrebbe, in futuro,
essere risolto algoritmicamente in un altro modo, magari più efficiente (ad esempio con complessità di tempo
inferiore)
- Fino a che punto è possibile “migliorare” la soluzione di un problema?
- Fino a che punto possiamo sperare che qualcuno in futuro possa formulare un algoritmo migliore per
risolvere il nostro problema?
- Ci sono limiti al di sotto dei quali non è possibile scendere?

Per alcuni problemi la risposta è affermativa: si conosce il limite oltre il quale nessun algoritmo può scendere,
per ingegnoso che possa essere.

Si parla di **“lower bound” del problema, ovvero il numero minimo di operazioni che qualsiasi
soluzione al problema comporta** e che dipende dalla struttura stessa del problema mentre è indipendente da
un qualsiasi algoritmo, anche sofisticatissimo.
Il lower bound di un problema è una proprietà intrinseca dello stesso (spesso facciamo riferimento ad esso
chiamandolo complessità intrinseca del problema), ed è un’informazione importantissima per chi sviluppa
software.

La conoscenza del lower-bound di un problema ha un’importanza fondamentale: ci permette di non perdere
tempo nella ricerca di un algoritmo più veloce, che non può esistere. Abbiamo così la certezza che nessun
“genio” (neanche fra 10.000 anni) potrà mai trovare un algoritmo che sia più veloce del lower-bound del
problema.

La dimostrazione di lower-bound è difficile. Bisogna analizzare, ad esempio, la natura del problema,
indipendentemente da quella che può essere una possibile strategia di soluzione. Sono pochi i problemi di cui si
è dimostrata l’esistenza di lower-bound. Due esempi famosi sono il problema della ricerca di un elemento in una
tabella che è equivalente alla ricerca di una parola in un dizionario e il problema dell’ordinamento di una lista di oggetti (siano parole, numeri, ecc…). Nel primo caso il lower-bound è *log(n)*, cioè nessun algoritmo (basato su confronto di elementi) può impiegare, nel worst-case, meno di *log(n)* operazioni in presenza di una tabella con n elementi. Nel secondo caso è stato dimostrato che un qualsiasi algoritmo che ordina un insieme di n elementi non può effettuare (nel worst-case) meno di *n·log(n)* operazioni elementari.



## altro materiale

https://it.wikipedia.org/wiki/Problema_computazionale

https://it.wikipedia.org/wiki/Teoria_della_complessit%C3%A0_computazionale






## Riferimenti esterni
- [Complessità intrinseca di un problema](http://dsc.unisa.it/alberto/Alberto/09-10/IG/Dispense/Dispense%204.3%20-%20Complessit%C3%A0%20Intrinseca.pdf): dispensa del Prof. Alberto Postiglione per il corso "Concetti di Base su Algoritmi, Strutture Dati e Programmazione" dell'Università degli Studi di Salerno.
