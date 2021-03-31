---
layout: default
title: Crittografia Moderna
nav_order: 2
parent: Crittografia
grand_parent: Reti
---

<!-- JQuery -->
<script src="https://code.jquery.com/jquery-3.5.1.min.js" integrity="sha256-9/aliU8dGd2tb6OSsuzixeV4y/faTqgFtohetphbbj0=" crossorigin="anonymous"></script>
<!-- Miei script -->
<script src="{{site.baseurl}}/assets/js/bordi-tabelle.js"></script>
<script src="{{site.baseurl}}/assets/js/crittografia-antica.js"></script>

<!-- MathJax -->
<script src="https://polyfill.io/v3/polyfill.min.js?features=es6"></script>
<script id="MathJax-script" async src="https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-mml-chtml.js"></script>

# Crittografia Moderna
{: .no_toc}

* TOC
{:toc}

La crittografia moderna si differenzia notevolmente dalla crittografia di cui si è parlato fin ora; l’avvento dei computer infatti ha rivoluzionato profondamente sia i sistemi crittografici sia il modo di vedere e utilizzare la crittografia.

Molti sistemi crittografici analizzati in precedenza e considerati ragionevolmente sicuri fino al XIX sec, possono oggi essere forzati in tempi brevissimi grazie alla velocità di elaborazione del computer. Inoltre possono essere ora utilizzati sistemi crittografici molto complessi e che, un tempo, avrebbero richiesto tempi di cifratura “a mano” troppo lunghi.

Nell’era dei computer la crittografia + “uscita dai campi di battaglia” e viene utilizzata da ogni persona, più o meno consapevolmente, nella vita di tutti i giorni: per prelevare soldi con un bancomat, nell’effettuare acquisti su internet o, semplicemente, chiamando con un telefono cellulare. La crittografia è quindi diventata uno strumento di massa, atto a proteggere i segreti di stato tanto quanto i dati che noi vogliamo, o almeno vorremmo, rimanessero privati.

Si può iniziare a parlare di crittografia moderna a partire dagli anni 1970 quando oltre ad esser stata trovata una soluzione al problema dello scambio della chiave ([Diffie-Hellman](#)) furono inventati i primi sistemi crittografici moderni simmetrci ([DES](#)) e asimmetrici ([RSA](#)) adatti ai calcolatori elettronici che proprio in quel periodo iniziavano a diffondersi.

Sebbene non consistano in veri e propri sistemi di crittografia, le [funzioni crittografiche di hash](#) hanno un ruolo piuttosto importante nell'ambito della crittografia moderna, essendo utilizzate in diversi ambiti, tra cui, insieme ad RSA, nell'implementazione di sistemi per la [firma digitale](#).

## Sistemi di crittografia simmetrici

Con [crittografia simmetrica](https://it.wikipedia.org/wiki/Crittografia_simmetrica#:~:text=Con%20crittografia%20simmetrica%2C%20o%20crittografia,performante%20e%20semplice%20da%20implementare.), o crittografia a chiave privata o precondivisa, si intende una tecnica di cifratura in cui la chiave di crittazione è la stessa chiave di decrittazione, rendendo l'algoritmo molto performante e semplice da implementare. Tuttavia presuppone che le due parti siano già in possesso delle chiavi, richiesta che non rende possibile uno scambio di chiavi con questo genere di algoritmi. Lo scambio avviene attraverso algoritmi a chiave asimmetrica o pubblica, generalmente più complessi sia da implementare che da eseguire ma che permettono questo scambio in modo sicuro. Dopodiché la comunicazione verrà crittata usando solo algoritmi a chiave simmetrica per garantire una comunicazione sicura ma veloce.

### Funzionamento

In questo genere di algoritmi si suppone che entrambe le parti conoscano già la chiave con cui crittare e decrittare il messaggio. Il mittente ha un messaggio **P** (PlainText o testo in chiaro). Il mittente critta il messaggio **P** con la chiave **k** usando un algoritmo di crittografia simmetrica chiamato **S**. Il messaggio risultante sarà **C** (CypherText o messaggio cifrato). In formule diventa:

S(P, k) = C
{: .esempio .ta-c .fs-5}

A questo punto al destinatario arriva un messaggio cifrato che riesce a decrittare poiché è in possesso della chiave privata. Ora il ricevente applica l'algoritmo di decrittazione **D** con la stessa chiave che ha usato il mittente per crittare il testo. Diventa:

D(C, k) = P
{: .esempio .ta-c .fs-5}

Se un attaccante ha intercettato il messaggio lungo il mezzo di comunicazione, avrà il messaggio crittato ma non la chiave che è stata scambiata in modo sicuro dai due interlocutori. Se l'attaccante vorrà leggere il messaggio crittato potrà solo usare metodi di decrittazione che richiedono elevate capacità di calcolo.

Il problema dello scambio della chiave deve essere risolto usando sistemi differenti come l'utilizzo della crittografia asimmetrica.

### Componenti comuni alle varie implementazioni

Tra i vari algoritmi di crittazione possiamo trovare alcune operazioni comuni, poiché aggiungono generalmente maggior sicurezza nel testo cifrato e sono operazioni rapide per la macchina.

Spesso una stessa operazione viene ciclata più volte, riferendosi a questi passaggi come **cicli** o **round**. Ad esempio in AES la stessa routine viene ripetuta 10 volte. In DES il testo in chiaro subisce 16 volte la crittazione insieme alla chiave prima di terminare. Una volta disegnato l'algoritmo viene molto facile ripeterlo, rendendo più complesso un lavoro di decrittazione forzata tramite brute force. Se l'algoritmo di decrittazione è ben disegnato e non si riescono ad avere informazioni sulla chiave, questo è l'unico metodo attraverso cui è possibile la decrittazione del messaggio cifrato.

Tra i vari algoritmi simmetrici possiamo riconoscere alcuni parametri standard come la **lunghezza della chiave** e la **dimensione del blocco**.

La lunghezza della chiave è misurata in bit e ha valori che oscillano tra 32 bit e 512 bit. Generalmente la lunghezza della chiave è un valore fisso nonostante esistano alcuni algoritmi come AES che impiegano lunghezze variabili.

Ogni algoritmo generalmente cerca di crittare una stringa di bit attraverso una chiave in un'altra stringa di bit della medesima lunghezza. La lunghezza di questa stringa è pari alla dimensione del blocco. Algoritmi ormai datati ma che hanno costituito uno standard per molti anni come il DES, avevano questo valore pari a 64bit in media. Oggi si preferisce adottare dimensioni di almeno 128 bit, numero che cresce nel tempo con l'aumentare della potenza dei computer. Per un alto livello di sicurezza oggi si consigliano 256 bit.

Un problema che affligge la dimensione del blocco è il paradosso del compleanno che rilascia informazioni sulla chiave ogni volta che avviene una collisione (quando due blocchi vengono cifrati allo stesso modo). Possiamo ritenere sicura solo la radice quadrata di tutte le combinazioni possibili. Per esempio con una dimensione di 64 bit, che genererebbe {\displaystyle 2^{64}}{\displaystyle 2^{64}} possibili combinazioni, potremo impiegarne solo {\displaystyle 2^{32}}{\displaystyle 2^{32}} prima di cominciare a rivelare informazioni sulla chiave.


## Crittografia asimmetrica

Fino agli anni 1970 gli unici sistemi crittografici esistenti erano simmetrici cioè prevedevano l'utilizzo di un'unica chiave utilizzata sia per cifrare che per decifrare. Per quanto i crittosistemi fossero sicuri ed efficienti rimaneva da risolvere un problema fondamentale, quello della condivisione della chiave. A questo scopo vennero proposte una serie di tecniche che si possono definire di cirittocrafia asimmetrica.

Prima di poter affrontare l'argomento è necessario studiare le basi matematiche che stanno alla base di tutta la crittografia asimmetrica cioè i numeri primi e l'aritmetica dei moduli.

### Numeri primi

Un intero positivo N si dice **primo** se 

*N è diverso da 1 ed è divisibile esattamente solo per 1 e per se stesso*.
{: .importante}

Ancora oggi il metodo più veloce per trovare tutti i numeri primi inferiori ad un limite L prefissato è il **crivello di Eratostene**. Tale algoritmo può essere schematizzato con i seguenti punti: 
- si costruisce un elenco E degli interi compresi tra 2 e L; 
- si cancellano tutti i multipli di 2 tranne 2; 
- si prende il primo numero non cancellato, che è 3, e si cancellano tutti i suoi multipli (escluso lui stesso); 
- si continua così fino alla parte intera della radice quadrata di L. I numeri superstiti sono i numeri primi compresi tra 2 e L. 

Chi lo desidera può vedere il crivello in azione [qui](http://britton.disted.camosun.bc.ca/sieve/jberatosapplet.htm).

Il **Teorema Fondamentale dell’Aritmetica** stabilisce che: 

ogni numero intero diverso da 0,-1,+1 si decompone nel prodotto di numeri primi e la decomposizione è unica a meno dell'ordine e del segno dei fattori.
{: .importante}

Dal Secondo Teorema di Euclide sui numeri primi sappiamo che **i numeri primi formano una successione infinita**.

È da notare che la dimostrazione di Euclide della esistenza di infiniti numeri primi è *costruttiva*, fornisce cioè un metodo che consente, almeno in linea di principio, di trovare un numero primo che sia *al di fuori di qualsiasi insieme finito Q di numeri primi assegnato!*

La tecnica è la seguente: 
- Sia Q = {q<sub>1</sub> , q<sub>2</sub> , q<sub>3</sub> ,..., q<sub>m</sub>}; 
- si calcola n = q<sub>1</sub> · q<sub>2</sub> · q<sub>3</sub> · ... · q<sub>m</sub> + 1 ; 
- evidentemente n è coprimo con tutti i q<sub>j</sub> contenuti in Q (cioè non ha fattori in comune con essi): quindi, *tutti i suoi fattori primi sono primi che non stanno in Q*. 

Esempio
Supponiamo di conoscere soltanto i numeri primi 2 e 3.  
Allora Q = {2, 3}, n = 2 · 3 + 1 = 7 , che è primo.  
Si aggiunge 7 a Q e si ottiene Q = {2, 3, 7}.  
Al passo seguente si ha n = 2 · 3 · 7 + 1 = 43 , che è primo anch’esso.  
Lo aggiungo al bottino: Q = {2, 3, 7, 43}.  
Si prosegue in questo modo: n = 2 · 3 · 7 · 43 + 1 = 1806 che può essere scomposto in fattori primi come 1806 = 13 · 139 , aggiungendo quindi due nuovi numeri all’insieme Q che diventa Q = {2, 3, 7, 43, 13, 139}.
{: .code-example}

Denotiamo la successione dei primi in ordine ascendente con p<sub>1</sub> , p<sub>2</sub> ,..., p<sub>n</sub>.  
Avremo allora: p<sub>1</sub> = 2, p<sub>2</sub> = 3, p<sub>3</sub> = 5, ...  
E inoltre: p<sub>10</sub> = 29, p<sub>100</sub> = 541, p<sub>1000</sub> = 7979, p<sub>10000</sub> = 104709

Una funzione di importanza fondamentale è la [funzione enumerativa dei numeri primi](https://it.wikipedia.org/wiki/Funzione_enumerativa_dei_primi) indicata con π(x):

$$\pi(x)$$ = numero dei primi minori o uguali a x
{: .importante .ta-c}

Si ha quindi: π(10) = 4 perché ci sono 4 primi (2,3,5,7) minori di 10. \
Alcuni valori di π(x) sono: \
*π*(100) = 25 \
*π*(1000) = 168 \
*π*(10000) = 1229 \
*π*(100000) = 9592 \
*π*(1000000) = 78498 \
*π*(10000000) = 664579 

Sulla [pagina](https://en.wikipedia.org/wiki/Prime-counting_function) in inglese di wikipedia dedicata alla funzione π sono riportati valori calcolati e stimati della funzione. Il più grande che possiamo trovare, pubblicato da David Baugh and Kim Walisch nel 2015 è:  

π(10<sup>27</sup>) = 16,352,460,426,841,680,446,427,399

Calcolare il valore esatto della funzione π(n) per valori così grandi di n richiede una quantità di calcoli inimmaginabile. Fortunatamente è possibile calcolare un valore approssimato di π(n) per mezzo del **Teorema dei numeri primi** il quale afferma che: 

$$\pi(x) \approx \frac{x}{log(x)}$$
{: .ta-c} 

Tra le altre, una conseguenza del teorema dei numeri primi è che la probabilità che un numero x preso a caso sia primo è circa:

$$\frac{1}{log(x)}$$
{: .ta-c}

**Esempio** 
La probabilità che un intero casuale di 1000 cifre sia primo è circa 1 / log(10<sup>1000</sup>). Tenendo presente che nel Teorema dei numeri primi il logaritmo è in base *e*: log(10<sup>1000</sup>) = 1000 · log(10) = 2302,59. Quindi, in media, troveremo un numero primo ogni 2302 interi presi a caso.
{: .code-example}

E' possibile, dato un intero *x* casuale, provare velocemente che *x* è primo? \
Naturalmente esiste un metodo ovvio (di forza bruta): dividerlo per gli interi che lo precedono. Oppure, cosa assai più intelligente, mettere in moto un crivello di Eratostene. Entrambi però richiederebbero tempi proibitivi di calcolo anche con numeri di modesta lunghezza, persino utilizzando supercomputers. 

Accenniamo qui soltanto al fatto che esistono metodi per dimostrare che un interno è *probabilmente primo*, con una probabilità di errore che si può rendere piccola a piacere (tra questi ricordiamo il Test di Fermat). Esistono poi anche metodi molto più efficaci, per i quali la probabilità di errore è ancora più bassa. Il punto di forza di tutti questi metodi è che il tempo che impiegano ad eseguire il test su x è **polinomiale**, cioè è esprimibile mediante un polinomio nel *numero delle cifre di x*. Nel 2002 tre ricercatori indiani (Agrawal, Saxena e Cayal) hanno trovato un algoritmo che è *al tempo stesso polinomiale e deterministico* per dimostrare la primalità di un numero. 

Questo è un grande risultato, che ha risolto una congettura rimasta aperta per decenni. Il loro algoritmo però non è ancora utilizzato in pratica, perché è molto più lento dei test probabilistici, i quali, del resto, sono *quasi certi* per i primi di centinaia di cifre che servono attualmente in crittografia.

### Aritmetica modulo n
Nel seguito **N** e **Z** denoteranno rispettivamente l'insieme dei numeri naturali {0,1,2,...} e l'insieme degli interi relativi {...,-2,-1,0,+1,+2,...}.
Dati a, b in **Z** ed n > 1 in N, diciamo che ***a*** *è congruo a* ***b modulo n*** se a e b divisi per n danno lo stesso resto; in questo caso scriviamo una relazione di equivalenza. *a ≡ b* mod(*n*). La relazione di congruenza è una relazione di equivalenza.

Esempio 
L'aritmetica dei moduli prende in considerazione un gruppo limitato di numeri disposti
ad anello, un po’ come le ore sul quadrante dell'orologio.\
Consideriamo ad esempio un quadrante contenente solo 7 numeri, da 0 a 6, corrispondente al modulo 7. \
Per calcolare 2 + 3 si partirà da 2 e ci si sposterà di 3 numeri, ottenendo 5. Per calcolare 2 + 6 si partirà da 2 e ci si sposterà di 6 numeri. In questo modo, attraversando l'intero anello, si otterrà come risultato 1.  
In pratica:  
2 + 3 = 5 mod(7)  
2 + 6 = 1 mod(7)
{: .code-example}

<div class="thumbnail--centrato mt-4 mb-4">
  <img src="{{site.baseurl}}/assets/images/Crittografia-congruenza-modulo.jpg">
</div>

Ovviamente *a ≡ b* mod(*n*) se e solo se *a = n · b + k* con *k* in ***Z***. 

Per indicare tutti i numeri che differiscono tra di loro per un multiplo di n si usa il nome **classe di resto modulo n** (insieme di numeri che hanno in comune il resto della divisione per n). 

Tali classi sono indicate usando tale resto con una sopralineatura: 
- <span class="overline">0</span> <ins>classe di resto modulo 0</ins>: insieme dei numeri interi che divisi per *n* danno 0; 
- <span class="overline">1</span> <ins>classe di resto modulo 1</ins>: insieme dei numeri interi che divisi per *n* danno 1; 
- … 
- <span class="overline">n-1</span> <ins>classe di resto modulo n-1</ins>: insieme dei numeri interi che divisi per *n* danno *n*-1; 

Si indica con **Z**<sub>*n*</sub> l’**insieme delle classi di resto modulo** ***n***: **Z**<sub>*n*</sub> = {<span class="overline">0</span>, <span class="overline">1</span>, ..., <span class="overline">n-1</span>}. 

Sono valide le seguenti proprietà: \
<span class="overline">a</span> + <span class="overline">b</span> = <span class="overline">a + b</span>  
<span class="overline">a</span> · <span class="overline">b</span> = <span class="overline">a · b</span> 

<div class="esempio" markdown=1>
  **Esempio**  
  Operazioni in Z<sub>5</sub>
  {: .mb-0 .mt-0}

  ![addizioni e moltiplicazioni in Z5]({{site.baseurl}}/assets/images/operazioni-in-Z5.jpg)
  {: .ta-c .mb-0 .mt-0}
</div>

### Il cifrario di Cesare “generalizzato” con l’aritmetica modulo n

Precedentemente abbiamo parlato del [cifrario di Cesare](#cifratura-di-cesare-ii-secolo-dc) e di come fosse possibile generare messaggi cifrati per mezzo di questo metodo. Vedremo ora come sia possibile generalizzare tale sistema di cifratura utilizzando le classi di resto, e ottenendo così una cifratura che non trasla soltanto le lettere dell’alfabeto, ma le “rimescola”. 

Consideriamo l’insieme delle classi di resto modulo 26, e associamo ad ogni lettera dell’alfabeto una classe di resto modulo 26. Fissiamo due numeri, detti **parametri di cifratura**, e otteniamo la lettera che sostituirà la lettera indicata dalla classe <span class="overline">x</span> con quella individuata dalla classe <span class="overline">y</span> per mezzo della formula: 

<span class="overline">y</span> = <span class="overline">a · x + b</span>

<div class="code-example" markdown="1">

  Esempio

  |CHIARO|a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|
  | |1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|16|17|18|19|20|21|22|23|24|25|26|
  |<span class="overline">y</span>=<span class="overline">5·*x*+1</span> |6|11|16|21|0|5|10|15|20|25|4|9|14|19|24|3|8|13|18|23|2|7|12|17|22|1|
  |CIFRATO|F|K|P|U|Z|E|J|O|T|Y|D|I|N|S|X|C|H|M|R|W|B|G|L|Q|V|A|
  {: .fs-4}

Testo chiaro: veni, vidi, vici  
Testo cifrato: gzst, gtut, gtpt
</div>

Risulta evidente che non tutte le scelte dei numeri *a* e *b* possono portare a una corretta cifratura e decifratura del messaggio: in particolare, è necessario che ogni lettera dell’alfabeto chiaro sia cifrata con una lettera differente, per evitare ambiguità nell’operazione di decrittazione. 

Si può dimostrare che, per avere una “buona” chiave di cifratura, occorre scegliere *a* in modo tale che *<span class="overline">a</span>* abbia inverso in ***Z***<sub>26</sub>.

#### Identità di Bézout 

Se *d* = MCD(*a, b*) allora esistono degli interi *x* e *y* tali che *d* = *a · x + b · y* 

### Funzione e Teorema di Eulero

La funzione di Eulero *$$\phi$$(n)* **indica il numero di elementi invertibile in *Z<sub>n</sub>***, e può essere anche interpretato come **il numero di interi minori di *n* e relativamente primi con esso.** Poiché contare le classi invertibili in ***Z***<sub>*n*</sub> è come contare i numeri tra 1 e *n*-1 che sono coprimi con *n*, si può affermare che: 

  se *n = p* è primo, si ha *$$\phi$$(p) = *p* - 1
  {: .ml-4}

Si ha inoltre: 

  se *n = p<sup>r</sup>* con *p* primo, si ha *$$\phi$$(n) = $$\phi$$(p<sup>r</sup>) = p<sup>r-1</sup> · (p - 1)*  
  se *n = p<sub>1</sub><sup>r1</sup> · ... · p<sub>k</sub><sup>rk</sup>* con *p<sub>1</sub>,..., p<sub>k</sub>* primi diversi tra loro, si ha 
  {: .ml-4}

  *$$\phi$$(n) = p<sub>1</sub><sup>r1-1</sup> (p<sub>1</sub>-1) ... p<sub>k</sub><sup>rk-1</sup> (p<sub>k</sub>-1)*
  {: .ta-c}

La funzione di Eulero è alla base dell’importantissimo **Teorema di Eulero**:

<div class="importante" markdown="1">
  Siano *a* e *n* due numeri interi positivi primi tra loro. Allora:    
  
  ***a<sup>$$\phi$$(n)</sup>* ≡ 1 mod(*n*)**
  {: .ta-c .fs-5}

</div>

### Un’applicazione della funzione di Eulero

Vedremo ora un’interessante applicazione del Teorema di Eulero, che permette di calcolare, dato un numero in forma di potenza, le cifre decimali del numero stesso scritto in forma posizionale.

Partiamo da un caso semplice per chiarire meglio il concetto: supponiamo di voler conoscere la cifra x che indica in numero di unità del numero 13<sup>5</sup>. In questo caso, una semplice calcolatrice portatile consente di ottenere il risultato 371293 e scoprire così che la cifra cercata è 3.

Vediamo come si sarebbe potuto ottenere lo stesso risultato con la funzione e il teorema di Eulero: cercare la cifra che indica il numero di unità di 13<sup>5</sup> equivale a calcolare il resto della divisione per 10, ossia il numero compreso tra 0 e 9 tale che *x* = 13<sup>5</sup> in *Z*<sub>10</sub>.

- 13 ≡ 3 mod(10), in quanto il resto della divisione per 10 è uguale e pari a 3;

- x = 13<sup>5</sup> = 3<sup>5</sup>

- per il Teorema di Eulero avremo: *a* = 3; *n* = 10; $$\phi$$(10) = $$\phi$$(2 · 5) = (2 - 1) · (5 - 1) = 4 

- 3<sup>*$$\phi$$*(10)</sup> = 3<sup>4</sup> = 1  mod(10)  (infatti: 3<sup>4</sup> = 81 = 1 mod(10)) 

- x = 3<sup>5</sup> = 3<sup>4</sup> · 3 = 1<sup>4</sup> · 3 = 3 

La cifra finale (il numero di unità) di 13<sup>5</sup> è quindi 3, come risultava dal calcolo diretto.

<div class="esempio" markdown=1>
  **Esempio**
  Si vogliono calcolare le ultime due cifre decimali (decine e unità) del numero 203<sup>327</sup>.  
  Le ultime due cifre decimali corrispondono al resto della divisione per 100.  
  Si procede quindi nel seguente modo:
  {: .mt-0 .mb-1}

<span class="overline"></span>

  - 203 ≡ 3 mod(100)
  - <span class="overline">*x*</span> = <span class="overline">203<sup>327</sup></span> = <span class="overline">3</span><sup>327</sup>
  - *a* = 3; *n* = 100; *$$\phi$$*(100) = *$$\phi$$*(2<sup>2</sup> · 5<sup>2</sup>) = 2<sup>2-1</sup> · (2 - 1) · 5<sup>2-1</sup> · (5 - 1) = 40  
  quindi: 3<sup>40</sup> ≡ 1 mod(100)
  - <span class="overline">3</span><sup>327</sup> = <span class="overline">3</span><sup>8·40+7</sup> = (<span class="overline">3</span><sup>40</sup>)<sup>8</sup> · <span class="overline">3</span><sup>7</sup> = <span class="overline">1</span> · <span class="overline">3</span><sup>7</sup> = <span class="overline">2187</span> = <span class="overline">87</span>
</div>

## La crittografia a chiave pubblica o asimmetrica

Tutti i metodi crittografici visti nei capitoli precedenti sono accomunati da una caratteristica: per tutti i metodi è necessario che mittente e destinatario, prima di scambiarsi un messaggio in codice, si siano accordati su quale “chiave” utilizzare per cifrare e decifrare i messaggi. Non è infatti sufficiente concordare il metodo da usare per nascondere il messaggio, ma è altresì necessario stabilire la chiave da utilizzare per applicare tale metodo. 

Le chiavi da usare nei sistemi di cui abbiamo parlato nei precedenti capitoli possono essere così riassunte: 

|**Metodo**|**Chiave/i**|
|Scitala lacedemonica|Diametro del cilindro|
|Atbash – Albam - Atba|Alfabeto cifrante|
|Cifratura di Cesare|Numero che da di quanto viene traslato l’alfabeto chiaro|
|Disco di Leon Battista Alberti|Lettera di partenza|
|Tavola di Vigenère|Parola chiave|
|Playfair cipher|Parola chiave|
|ADFGVX|Parola chiave “quadrato” e parola chiave “colonna”|
|Enigma|Settaggio della macchina|

E’ quindi possibile che la chiave sia costituita da un numero o da una o più parole; in ogni caso, due parti che vogliano scambiarsi messaggi in modo “sicuro” devo prima scambiarsi l’informazione costituita dalla chiave. E’ evidente che tale chiave deve rimanere segreta se si vuole che rimanga tale anche il messaggio: nasce quindi il problema di come scambiarsi in modo sicuro la chiave, in altre parole il cosiddetto **problema della distribuzione delle chiavi**. Possiamo ricordare a questo proposito ciò che ha scritto Simon Singh:

> “per poter condividere un segreto (tramite un messaggio crittato), due persone dovrebbero già condividere un segreto (la chiave)”. 

Nei prossimi capitoli vedremo come tale problema fu affrontato e risolto dopo la seconda guerra mondiale portando alla crittografia moderna a chiave pubblica.

### Una scatola e due lucchetti: lo scambio di chiavi secondo Diffie, Hellman e Merkle

Il modo migliore per capire come si sia potuti arrivare a concepire e a realizzare un sistema crittografico che non necessita di uno scambio preventivo di chiavi da parte di mittente e destinatario è partire da un esempio. Supponiamo che, per scambiarsi documenti riservati, mittente e destinatario utilizzino una scatola alla quale sia possibile applicare due lucchetti; è dunque possibile procedere nel seguente modo: 

<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/doppio_lucchetto.jpg" onclick="document.getElementById('doppio_lucchetto').style.display='block'" class="hoverlink">
</div>
<!--modal-->
<div id="doppio_lucchetto" class="modal">
  <div class="modal--content">
    <!-- <div class="w3-container"> -->
      <span onclick="document.getElementById('doppio_lucchetto').style.display='none'" class="modal--close w3-display-topright">&times;</span>
      <img src="{{site.baseurl}}/assets/images/doppio_lucchetto.jpg" data-toggle="modal" data-target="#doppio_lucchetto">
      <p>Il principio della Crittografia.</p>
    <!-- </div> -->
  </div>
</div>

- il mittente racchiude il messaggio nella scatola e la chiude con il lucchetto del quale solo lui possiede la chiave e spedisce la scatola al destinatario;

- il destinatario riceve la scatola ma non può aprirla dato che non ha la chiave del lucchetto; applica a questo punto un altro lucchetto, del quale solo lui possiede la chiave e rimanda la scatola al mittente; 

- il mittente alla ricezione della scatola toglie il lucchetto che aveva precedentemente applicato e la rispedisce al destinatario; 

- la scatola che arriva al destinatario è ormai chiusa solo con il lucchetto da lui stesso applicato: egli, quindi, potrà aprirla senza problemi e leggere il messaggio in essa racchiuso, senza che nessun terzo incomodo possa averne sbirciato il contenuto. 

Questa idea però non è immediatamente traducibile in un modello matematico, in quanto: svolgere il primo passaggio (mettere il primo lucchetto alla scatola) significa partire da certi dati iniziali (scatola senza lucchetti), applicare ad essi una determinata funzione matematica (primo lucchetto) e raggiungere un certo risultato (scatola con un lucchetto); svolgere il secondo passaggio (mettere il secondo lucchetto alla scatola) significa partire dai risultati del primo passaggio (scatola con un lucchetto), applicare ad essi una diversa funzione matematica (secondo lucchetto) e raggiungere un altro risultato (scatola con due lucchetti); il terzo passaggio consiste nell’inversione della funzione utilizzata nel primo passaggio (cioè nel togliere il primo lucchetto messo); il quarto, ovviamente, si realizza invertendo la funzione applicata nel secondo passaggio. Ma in questo modo non si riottengono, in generale, i dati iniziali (scatola senza lucchetto) poiché *l'inversione della composizione di due funzioni deve avvenire in ordine contrario rispetto all'ordine di applicazione*, cioè va invertita per prima quella applicata per ultima. 

Tutto ciò risulta evidente dall’esempio che segue.

<div class="esempio" markdown=1>
  **Esempio**

  Chiave di Alice

  |a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z
  |H|F|S|U|G|T|A|K|V|D|E|O|Y|J|B|P|N|X|W|C|Q|R|I|M|Z|L
  {: .tbl-mini}
  
  Chiave di Bob

  |a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z
  |C|P|M|G|A|T|N|O|J|E|F|W|I|Q|B|U|R|Y|H|X|S|D|Z|K|L|V 
  {: .tbl-mini}

  <div class="tbl-nowrapper" markdown=1>
  |MESSAGGIO:|ci vediamo
  |Cifrato da Alice:|SV RGUVHYB
  |Ricifrato da Bob:|HD YNSDOLP
  |Decifrato da Alice:|AJ MQCJLZP
  |Decifrato da Bob:|EI CNAIYWB
  {: .invisible .distanzia-colonne-3}
  </div>
</div>

Questo problema fu affrontato e risolto negli anni ’70 del secolo scorso dai ricercatori Whitfield Diffie, Martin Hellman e Ralph Merkle.

Le funzioni di cui si servirono per risolvere il problema della distribuzione delle chiavi derivano dall'[aritmetica dei moduli](#aritmetica-modulo-n) dove è spesso possibile incontrare funzioni unidirezionali, tali cioè da essere “difficili” da invertire.

Dalla tabella che segue si può osservare ad esempio come la potenza cresca regolarmente, mentre nel caso dell’aritmetica dei moduli la variazione della funzione non sia regolare.

|*x*|1|2|3|4|5|6|7|8|9|10|
|3<sup>*x*</sup>|3|9|27|81|243|729|2187|6561|19683|59049|
|3<sup>*x*</sup> mod(5)|3|4|2|1|3|4|2|1|3|4|
{: .ta-r}

Inoltre, dalla tabella si evince come in aritmetica normale sia immediato, dato un valore di x, ricavare il corrispondente valore della funzione, e viceversa, dato il valore della funzione ricavare x. In aritmetica dei moduli il comportamento “imprevedibile” della funzione rende questa inversione estremamente difficile.

La funzione unidirezionale che fu scelta dai tre ricercatori era del tipo: 

***Y<sup>x</sup>* mod(*p*)** con *p* numero primo e *Y < p* . 
{: .ta-c}

Per capire come questo metodo consenta a mittente e destinatario di **stabilire una chiave segreta senza incontrarsi** faremo ricorso a tre persone immaginarie che chiameremo Alice (mittente), Bob (destinatario) e Eva (una terza persona che vuole spiare le conversazioni tra Alice e Bob). 

Il metodo prevede che Alice e Bob concordino una chiave costituita dai numeri Y e p: l’aspetto affascinante del metodo è che Alice e Bob possono stabilire tali numeri “alla luce del sole”, senza cioè preoccuparsi di tenerli segreti (per esempio ad Eva).

Supponiamo che Alice e Bob abbiano deciso di utilizzare: *Y* = 13, *p* = 23 e vediamo con uno schema come possono procedere per stabilire **senza incontrarsi** una chiave che rimarrà nota solo a loro due.

<table markdown=1 class=".fs-6">
    <thead>
        <tr>
            <th></th>
            <th>ALICE</th>
            <th>BOB</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td style="white-space: nowrap"><em>Passo 1</em></td>
            <td>
              Sceglie un numero, supponiamo: 8<br/>
              e lo tiene <strong>segreto</strong><br/>
              Chiameremo questo numero <em>A</em></td>
            <td>
              Sceglie un numero, supponiamo: 5<br/>
              e lo tiene <strong>segreto</strong><br/>
              Chiameremo questo numero <em>B</em></td>
        </tr>
        <tr>
          <td><em>Passo 2</em></td>
          <td>
            Calcola:<br/>
            <em>Y<sup>A</sup></em> mod(<em>p</em>)<br/>
            13<sup>8</sup> mod(23) = 815730721 mod(23) = 2<br/>
            Chiameremo questo numero <em>α</em></td>
          <td>
            Calcola:<br/>
            <em>Y<sup>B</sup></em> mod(<em>p</em>)<br/>
            13<sup>5</sup> mod(23) = 371293  mod(23) = 4<br/>
            Chiameremo questo numero <em>β</em></td>
        </tr>
        <tr>
          <td rowspan=2><em>Passo 3</em></td>
          <td>Alice comunica a Bob il valore di <em>α</em></td>
          <td>Bob comunica ad Alice il valore di <em>β</em></td>
        </tr>
        <tr>
          <td colspan=2>Lo scambio di queste informazioni può avvenire tranquillamente in chiaro, in quanto un’eventuale intercettazione da parte di Eva non potrebbe comunque consentirle di risalire alla decifratura dei messaggi. Questo perché <strong><em>α</em> e <em>β</em> NON sono la chiave, e quindi è irrilevante che Eva ne venga a conoscenza.</strong></td>
        </tr>
        <tr>
          <td><em>Passo 4</em></td>
          <td>
            Calcola:<br/>
            <em>β<sup>A</sup></em>  mod(p)<br/>
            4<sup>8</sup>  mod(23) = 65536  mod(23) = 9</td>
          <td>
            Calcola:<br/>
            <em>α<sup>B</sup></em>  mod(p)<br/>
            2<sup>5</sup>  mod(23) = 32  mod(23) = 9</td>
        </tr>
        <tr>
          <td><em>Chiave</em></td>
          <td colspan=2>
            Alice e Bob hanno ottenuto lo stesso numero che rappresenterà la chiave dei loro messaggi.</td>
        </tr>
    </tbody>
</table>

In base a questo schema abbiamo dunque dimostrato che Alice e Bob possono concordare una chiave senza bisogno di incontrarsi e senza il timore che la chiave stessa sia intercettata da terzi: abbiamo quindi risolto il problema della distribuzione delle chiavi!

Per convincercene ulteriormente, vediamo perché ad Eva sia impossibile risalire al valore della chiave. Poiché tutte le comunicazioni dello schema precedente tra Alice e Bob sono in chiaro, Eva potrebbe aver intercettato le seguenti informazioni: 

- le comunicazioni relative alla scelta di *Y* e *p*, e quindi sapere che la funzione è del tipo: 13<sup>*x*</sup> mod(23); 
- le comunicazioni del passo 3, e quindi i valori di *α* e *β*. 

**Per trovare la chiave, Eva dovrebbe quindi procedere come Alice ed effettuare l’operazione *β^A* mod(*p*)**, oppure come Bob ed effettuare l’operazione ***α^B* mod(*p*)**. Ma Eva non conosce i valori di A o di B! D’altronde, tentare di ricavarli invertendo la funzione non sarebbe un compito semplice, in quanto si tratta di una funzione unidirezionale. 

La dimostrazione pubblica della loro scoperta fu data da Diffie, Hellman e Merkle nel giugno del 1976 alla National Computer Conference. 

L’introduzione di un metodo che consente a mittente e destinatario di scambiarsi la chiave in modo “sicuro” ha costituito una vera e proprio rivoluzione nel campo della crittografia; l’univo aspetto negativo del sistema Diffie - Hellman - Merkle risiede nell’introdurre una non contemporaneità tra le azioni di destinatario e mittente. Infatti, per applicare il suo “lucchetto” Bob deve attendere di ricevere il messaggio di Alice (supponiamo tramite mail), e la stessa Alice, per rimuovere il suo “lucchetto” deve attendere la risposta di Bob, e così via. Questo aspetto, che per persone che vivono in luoghi con fusi orari differenti può comportare un “ritardo” anche notevole nello scambio delle mail, rappresenta chiaramente un elemento che va contro la natura stessa della posta elettronica, che rappresenta uno dei modi più veloci di scambio delle informazioni. 

Nel prossimo paragrafo vedremo come questo aspetto sia stato risolto dall’introduzione della crittografia a chiave pubblica. 

### RSA 
Il passo avanti rispetto al metodo di scambio delle chiavi secondo Diffie-Hellman-Merkle avvenne grazie allo sforzo congiunto di tre ricercatori: Ronald Rivest, Adi Shamir e Leonard Adleman, dalle cui iniziali deriva il metodo noto come RSA. 

Il pregio di questo sistema rispetto al metodo Diffie-Hellman-Merkle è che non richiede uno scambio di informazioni tra Alice e Bob per la costruzione della chiave: questo sistema fa infatti uso di due chiavi, una detta “chiave pubblica ” e una chiamata “chiave privata” e utilizza un metodo di cifratura asimmetrico. 

In un sistema a chiave asimmetrica la chiave usata per cifrare e quella usata per decifrare non coincidono: è possibile quindi che Alice renda pubblica la chiave da usare per cifrare un messaggio (la sua chiave pubblica) e conservi segreta la chiave da usare per decifrare il messaggio (la sua chiave privata), per essere in grado solo lei di decifrare i messaggi a lei diretti. 

Il cuore della cifratura asimmetrica sviluppata da Rivest, Shamir e Adlemann è una funzione unidirezionale basata sul concetto di modulo. 

Il funzionamento del metodo RSA si può schematizzare con i seguenti punti: 

- si scelgono due numeri primi, *p* e *q* ; 
- si calcola il loro prodotto *N* = *p* · *q* , chiamato *modulo* (dato che tutta l'aritmetica seguente è in *modulo n*
- si sceglie poi un numero *e* (chiamato *esponente pubblico*), più piccolo di *N* e primo rispetto a $$ {\phi(N) = (p-1)\cdot(q-1)} $$, dove $${\phi}$$ è la funzione di Eulero; 
- si calcola il numero d (chiamato *esponente privato*) tale che *e* · *d* ≡ 1 mod((*p*-1)·(*q*-1))

La chiave pubblica è rappresentata dalla coppia di numeri (*N, e*), mentre la chiave privata è rappresentata da (*N, d*). 

Un messaggio *m* viene cifrato attraverso l'operazione *m<sup>e</sup>* mod(*N*), mentre il messaggio *c* così ottenuto viene decifrato con *c<sup>d</sup>* = *m<sup>e·d</sup>* = *m*<sup>1</sup> mod(*N*). Il procedimento funziona solo se la chiave *e* utilizzata per cifrare e la chiave *d* utilizzata per decifrare sono legate tra loro dalla relazione *e* · *d* = 1 mod((*p*-1)·(*q*-1)), e quindi quando un messaggio viene cifrato con una delle due chiavi (la chiave pubblica) può essere decifrato solo utilizzando l'altra (la chiave privata). 

Vediamo in pratica come sia possibile realizzare una cifratura RSA. 

Per cifrare un messaggio, questo deve essere prima di tutto trasformato in un numero o in una serie di numeri, diciamo *m<sub>1</sub>, m<sub>2</sub>,..., m<sub>k</sub>*. Questa operazione può essere effettuata utilizzando, ad esempio, il codice ASCII, e trasformando il numero binario ottenuto nel corrispondente in base dieci. Per semplicità, nel prossimo esempio considereremo che il messaggio segreto che si vuole trasmettere consista di un solo numero *m*, senza preoccuparci del metodo utilizzato per generarlo. 

Faremo inoltre nuovamente riferimento ai nostri personaggi immaginari, Alice e Bob. 

#### Operazioni effettuate da Alice (Generazione delle Chiavi):

<ol>
  <li>
    sceglie due numeri primi p e q:
    <p class="ta-c">
        <em>p</em> = 47, <em>q</em> = 71
    </p>
  </li>
  <li>
    calcola <em>N</em> = <em>p</em> · <em>q</em>:
    <p class="ta-c">
        <em>p</em> = 47, <em>q</em> = 71
    </p>
  </li>
  <li>
    calcola <em>\(\phi\)(N)</em> = <em>(p-1) · (q-1)</em>:
    <p class="ta-c">
        \(\phi\)(3337) = (47-1) · (71-1) = 3220
    </p>
  </li>
  <li>
    sceglie <em>e</em> tale che: <em>e</em> < <em>N</em> e <em>MCD(e, \(\phi\)(N))</em> = 1: 
    <p class="ta-c">
        <em>e</em> = 79
    </p>
  </li>
  <li>
    calcola <em>d</em> tale che: <em>e</em> · <em>d</em> = 1 mod((<em>p</em>-1) · (<em>q</em>-1))
    <p class="ta-c">
        <em>d</em> = 79<sup>-1</sup> mod(3220) = 1019
    </p>
  </li>
  <li>
    la chiave pubblica è: 
    <p class="ta-c">
        (<em>e</em>, <em>N</em>) = (79, 3337)
    </p>
  </li>
  <li>
    la chiave privata è: 
    <p class="ta-c">
        (<em>d</em>, <em>N</em>) = (1019, 3337)
    </p>
  </li>
</ol>

Adesso Alice è libera di pubblicare la sua chiave pubblica su Internet, o su un qualsiasi altro elenco disponibile a chiunque voglia scriverle messaggi cifrati. 

Supponiamo allora che Bob le voglia mandare un messaggio costituito da vediamo quale operazioni deve eseguire. 

#### Operazioni effettuate da Bob (Cifratura): 
<ol>
  <li>
    calcola <em>c</em> = <em>m<sup>e</sup></em>  mod(<em>N</em>):
    <p class="ta-c">
        <em>p</em> = 47, <em>q</em> = 71
    </p>
  </li>
  <li>
    <em>c</em> rappresenta il messaggio cifrato che può essere letto (decifrato) solo da chi è in possesso della chiave privata e quindi solo da Alice. Bob può quindi spedire in tutta tranquillità c senza preoccuparsi del fatto che Eva possa intercettarlo, poiché anche in quell’eventualità non sarebbe in grado di volgerlo in chiaro. 
  </li>
</ol>

#### Operazioni effettuate da Alice (Decifratura):

1. ricevuto il messaggio Alice ricava *m* mediante la formula *m* = *c<sup>d</sup>* mod(*N*):

  *m* = 1570<sup>1019</sup> mod(3337) = 688
  {: .ta-c}

L’unico modo per Eva di decifrare il messaggio è di avere *d* e quindi di riuscire a ottenere *p* e *q* dalla fattorizzazione di *N*: come detto precedentemente, il processo di fattorizzazione di un numero nei suoi fattori primi è un processo molto lungo, specialmente se si ha a che fare con numeri molto grandi.

La segretezza nella comunicazioni tra Alice e Bob è quindi assicurata!

**Esempio**  
Si scelgono due numeri primi *p* = 7, *q* = 17
si calcola *n = p · q* = 7 · 17 = 119  
si calcola *$$\phi$$(n)* = (*p* - 1) · (*q* - 1) = 6 · 16 = 96  
si sceglie *e < $$\phi$$(n)*, relativamente primo con *$$\phi$$(n), e* = 5  
si determina *d* tale che *d* · *e* mod(96) = 1 e *d* < 96, *d* = 77 (infatti 77 · 5 = 385 = 96 · 4 + 1)
{: .esempio}

#### Curiosità e considerazioni 
Samuel Wagstaff, docente di informatica all’Università dell’Indiana, è riuscito a fattorizzare un numero di 167 cifre in centomila ore di tempo computer. Il numero della prova era: 

  16379019558053662392174130154670449583923965684832704024983781709239694686351321204156509649226080541971824707555797144568969073877772973038883717449030628887379284041
  {: .ml-4 .mr-4 .fs-3}

Questa notizia dovrebbe far riflettere: considerando che ad oggi si scoprono ancora nuovi algoritmi matematici per decrittare sempre più velocemente e che la potenza dei calcolatori aumenta vertiginosamente di mese in mese (e non parliamo dei computers dei laboratori segreti!), sarà una buona scelta affidare dati importantissimi ad un metodo che si basa esclusivamente sulla lentezza dei calcolatori attuali? 

Bisogna anche notare che una chiave da 1024 bit in un sistema a chiave pubblica, vale circa quanto una a 64 bit di un sistema a chiave simmetrica a causa del fatto che nel sistema a chiave pubblica esiste sempre un legame tra chiave privata e segreta che permette di ridurre le combinazioni necessarie per trovare il codice di accesso. 

Stabilita tale corrispondenza di sicurezza tra le lunghezze delle chiavi dei due sistemi, è interessante notare quando detto alla conferenza Crypto '93 (notare che sono già passati diversi anni), da M. Wiener del Bell Northern Research, il quale ha descritto come con un milione di dollari sia realizzabile un chip speciale da 50 milioni di test al secondo che, in parallelo ad altri 57.000, può condurre un attacco con successo mediamente in 3,5 ore. Con un costo di 10 milioni di dollari il tempo si abbassa a 21 minuti, e con 100 milioni a disposizione, il codice è infranto in pochi secondi! 

Fatto sta che il commercio elettronico ha già iniziato a farne uso e alcuni anni fa, il 5 Agosto 1997, il Consiglio dei Ministri Italiano ha approvato il regolamento di attuazione dell’art.15 della legge 57/97, nota anche come legge Bassanini-1, con il quale si stabilisce che l’originale di un documento può essere anche quello depositato su di un file. Tale documento su file ha valore probante sia sul contenuto sia sulla provenienza se corredato da firma elettronica legalmente riconosciuta. 

#### Numeri primi e RSA 

Da quanto esposto nei precedenti paragrafi risulta chiaro che la conoscenza di numeri primi molto “grandi” permette di effettuare cifrature RSA sempre più potenti. La ricerca di tali numeri costituisce quindi, da un po’ di anni a questa parte, un vero e proprio business, e molte aziende hanno come solo scopo quello di trovarne di sempre più grandi. Nella tabella seguente sono riportati alcuni dei numeri scoperti negli ultimi anni. 

![numeri primi trovati]({{site.baseurl}}/assets/images/numeri-primi-trovati.jpg)

I numeri della forma 2<sup>*n*</sup> - 1 sono detti numeri di Mersenne e sono indicati con *M<sub>n</sub>*. In generale questi numeri non sono primi, nemmeno se *n* è primo (per esempio *M*<sub>11</sub> = 2047 = 89 · 23); non si sa nemmeno se di numeri di Mersenne primi ce ne siano un numero finito o se siano infiniti.
{: .thumbnail--testo .float-right .mt-0}

Da molti anni accade che il più grande numero primo noto sia un primo di Mersenne. Chi volesse capovolgere la situazione, e trovare un numero primo "generico" più grande dovrà ancora una volta alzare il tiro (e di parecchio). Il 42-esimo primo di Mersenne ha "appena" 7.816.230 cifre, e sembra piccolo posto accanto al nuovo arrivato.

Il più recente primo di Mersenne (il 43-esimo) è stato scoperto il 15 Dicembre 2005 da Curtis Cooper e Steven Boone: 

  **2<sup>30402457</sup> - 1**
  {: .ta-c}

Esso rappresenta **il più grande numero primo noto**, con ben 9.152.052 cifre! Siamo a un passo dalla soglia dei 10 milioni di cifre, per la quale la Electronic Frontier Foundation offre 100.000 dollari. 

Il premio precedente - di 50.000 dollari - è stato assegnato nel 2000 a Nayan Hajratwala il quale, partecipando alla GIMPS (Great Internet Mersenne Prime Search), trovò nel 1999 il 38-esimo primo di Mersenne (2.098.960 cifre). 

#### Attacchi
Nel 1977, subito dopo il lancio del sistema di crittografia RSA, Martin Gardner pubblicò su Scientific American un piccolo messaggio cifrato, basato su una chiave costituita da un numero N di 129 cifre, prodotto di due numeri primi molto grandi. Il messaggio e la chiave erano stati forniti da ricercatori del MIT, che offrivano un premio in denaro a chi avesse decrittato il messaggio. A quei tempi si stimò che ci sarebbero voluti all'incirca **ventimila anni** per scomporre in fattori primi quel numero, con i più veloci calcolatori disponibili. Dopo di allora però ci furono importanti novità, più che sul lato della velocità dei computer, sui **metodi per fattorizzare grandi numeri**. Inoltre la massiccia diffusione di Internet costituì una variabile imprevista: sotto la guida di alcuni ricercatori, un esercito di 600 volontari di 20 paesi si mise all'opera e dopo non molti mesi di lavoro, nell'Aprile del 1994, la fattorizzazione fu scoperta: si trattava di due numeri, uno di 64 e uno di 65 cifre. Erano passati solo (!) 17 anni dalla pubblicazione della chiave pubblica. Solo per curiosità riportiamo qui i valori dei numeri coinvolti (i volonterosi possono provare ad eseguire il prodotto richiesto, per controllare che non ci siano errori): 

*p* = 3490529510847650949147849619903898133417764638493387843990820577  
*q* = 32769132993266709549961988190834461413177642967992942539798288533  
*N* = 
{: .mb-0}

114381625757888867669235779976146612010218296721242362562561842935706935245733897830597123563958705058989075147599290026879543541 
{: .ml-4 .mt-0}

Attualmente chiavi di 1024 bit sono considerate sufficientemente sicure.  
Tempo medio di attacco: 

| lunghezza chiave | tempo richiesto | tempo richiesto 
| (bit) | a 1 decr/ms | a 106 decr/ms 
|56 | 255 ms = 1142 anni | 10 ore 
|128 | 2127 ms ~ 1024 anni | ~ 1018 anni 
|168 | 2167 ms ~ 1036 anni | ~ 1030 anni 

#### La fattorizzazione 
Discutiamo solo il problema inverso della fattorizzazione. A prima vista, sapendo che si usano numeri primi vicini a 2<sup>128</sup>, si potrebbe pensare di costruirsi una tabella dei numeri che sono prodotto di due tali primi. Ma quanti sono?  
In base al risultato ottenuto da Hadamard sappiamo che: 

$$ {\lim\limits_{x \to 1} \frac{\pi(n)}{\frac{n}{log(n)}} = 1} $$

dove *p(n)* rappresenta il numero di primi minori o uguali a *n*.

Dunque possiamo rozzamente valutare $$ {\pi(2^{128})} $$ come: 

$$ {\frac{2^{128}}{log(2^{128})} \approx 3 \cdot 10^{36}} $$

e $$ {\pi(2^{127})} $$ come: 

  $$ {\frac{2^{127}}{log(2^{127})} \approx 2 \cdot 10^{36}} $$ 
  
e quindi $$ {\pi(2^{128}-\pi(2^{127})) \approx 10^{36}} $$. Stiamo cauti nella stima e diciamo che ne abbiamo almeno 10<sup>30</sup> (in realtà potremmo anche dire con sicurezza 10<sup>35</sup> ). I prodotti di due numeri di questa forma sono allora dell’ordine di 10<sup>60</sup>. Immagazzinarli in forma binaria richiede allora $$ {2^{256} \cdot 10^{60} \approx 2^{256} \cdot 2^{199} = 2^{455}} $$ bit, quindi $$ {2^{452} \approx 10^{136} } $$ byte. Un terabyte è circa 10<sup>12</sup> byte, quindi servirebbe qualcosa come 10<sup>124</sup> terabyte. Troppi anche solo da immaginare: il diametro della Galassia in metri è 10<sup>21</sup>. Più sensato è pensare di fattorizzare N, ma l’unico modo conosciuto è di dividerlo successivamente per 2, 3, e così via. E’ probabile che, nel momento in cui si è ottenuta la fattorizzazione richiesta, la chiave pubblica sia cambiata da parecchi mesi, si faccia un conto approssimativo del tempo richiesto. 

Un numero è detto semiprimo (anche detto biprimo o 2-quasi primo, o pq numero) è un numero naturale che è il prodotto di numeri primi (non necessariamente distinti). I primi numeri semiprimi sono: <span class="fs-2">4, 6, 9, 10, 14, 15, 21, 22, 25, 26, 33, 34, 35, 38, 39, 46, 49, 51, 55, 57, 58, 62, 65, 69, 74, 77, 82, 85, 86, 87, 91, 93, 94, 95, 106.<span>
<!-- 111, 115, 118, 119, 121, 122, 123, 129, 133, 134, 141, 142, 143, 145, 146, 155, 158, 159, 161, 166, 169, 177, 178, 183, 185, 187. -->
{: .thumbnail--testo .float-right .mt--1}

In matematica, RSA-2048 è il più grande dei numeri RSA (semiprimi grandi che fanno parte del RSA Factoring Challenge), e ad esso è associato il premio più grande per la sua fattorizzazione: 200000 dollari.  
RSA-2048 è un numero con 617 cifre decimali (2048 bits)! 


RSA-2048 = 
{: .mb-0 .clear-both}
  25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784406918290641249515082189298559149176184502808489120072844992687392807287776735971418347270261896375014971824691165077613379859095700097330459748808428401797429100642458691817195118746121515172654632282216869987549182422433637259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133844143603833904414952634432190114657544454178424020924616515723350778707749817125772467962926386356373289912154831438167899885040445364023527381951378636564391212010397122822120720357
  <!-- 251959084756578934940271832400483985714292821262040320277771378360436 620207075955562640185258807844069182906412495150821892985591491761845 028084891200728449926873928072877767359714183472702618963750149718246 911650776133798590957000973304597488084284017974291006424586918171951 187461215151726546322822168699875491824224336372590851418654620435767 984233871847744479207399342365848238242811981638150106748104516603773 060562016196762561338441436038339044149526344321901146575444541784240 209246165157233507787077498171257724679629263863563732899121548314381 67899885040445364023527381951378636564391212010397122822120720357 -->
  {: .ml-4 .mr-4 .fs-4 .mt-0}

  

Il più grande numero RSA mai fattorizzato è composto da 200 cifre decimali (663 bits); probabilmente non si raggiungerà la fattorizzazione di RSA-2048 prima di alcuni decenni. RSAlabs ritiene infatti che i computer e le memorie necessarie per fattorizzare un numero RSA siano: 

| numero | computers | memoria 
| RSA-760 | 215000 | 4 Gb 
| RSA-1024 | 342000000 | 170 Gb
| RSA-1620 | 1.6·10<sup>15</sup> | 120 Tb 

  