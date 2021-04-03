---
layout: default
title: Crittografia Moderna
nav_order: 2
parent: Crittografia
grand_parent: Reti
---

# Crittografia Moderna
{: .no_toc}

* TOC
{:toc}

La crittografia moderna si differenzia notevolmente dalla crittografia di cui si è parlato fin ora; l’avvento dei computer infatti ha rivoluzionato profondamente sia i sistemi crittografici sia il modo di vedere e utilizzare la crittografia.

Molti sistemi crittografici analizzati in precedenza e considerati ragionevolmente sicuri fino al XIX sec, possono oggi essere forzati in tempi brevissimi grazie alla velocità di elaborazione del computer. Inoltre possono essere ora utilizzati sistemi crittografici molto complessi e che, un tempo, avrebbero richiesto tempi di cifratura “a mano” troppo lunghi.

Nell’era dei computer la crittografia + “uscita dai campi di battaglia” e viene utilizzata da ogni persona, più o meno consapevolmente, nella vita di tutti i giorni: per prelevare soldi con un bancomat, nell’effettuare acquisti su internet o, semplicemente, chiamando con un telefono cellulare. La crittografia è quindi diventata uno strumento di massa, atto a proteggere i segreti di stato tanto quanto i dati che noi vogliamo, o almeno vorremmo, rimanessero privati.

Si può iniziare a parlare di crittografia moderna a partire dagli anni 1970 quando oltre ad esser stata trovata una soluzione al problema dello scambio della chiave ([Diffie-Hellman](#)) furono inventati i primi sistemi crittografici moderni simmetrci ([DES](#)) e asimmetrici ([RSA](#)) adatti ai calcolatori elettronici che proprio in quel periodo iniziavano a diffondersi.

Sebbene non consistano in veri e propri sistemi di crittografia, le [funzioni crittografiche di hash](#) hanno un ruolo piuttosto importante nell'ambito della crittografia moderna, essendo utilizzate in diversi ambiti, tra cui, insieme ad RSA, nell'implementazione di sistemi per la [firma digitale](#).

## Crittografia simmetrica

Con [crittografia simmetrica](https://it.wikipedia.org/wiki/Crittografia_simmetrica#:~:text=Con%20crittografia%20simmetrica%2C%20o%20crittografia,performante%20e%20semplice%20da%20implementare.), o crittografia a chiave privata o precondivisa, si intende una tecnica di cifratura in cui la chiave di crittazione è la stessa chiave di decrittazione, rendendo l'algoritmo molto performante e semplice da implementare. Tuttavia presuppone che le due parti siano già in possesso delle chiavi, richiesta che non rende possibile uno scambio di chiavi con questo genere di algoritmi. Lo scambio avviene attraverso algoritmi a chiave asimmetrica o pubblica, generalmente più complessi sia da implementare che da eseguire ma che permettono questo scambio in modo sicuro. Dopodiché la comunicazione verrà crittata usando solo algoritmi a chiave simmetrica per garantire una comunicazione sicura ma veloce.

I crittosistemi moderni utilizzano diverse tecniche, anche molto complicate, per 
per rendere pratica e sicura la cifratura. Studiano la storia della crittografia si può notare come nel tempo siano stati teorizzati e formalizzati matematicamente molti metodi. Di seguito andremo ad analizzare solo alcune delle tecniche introdotte negli algoritmi di crittografia moderni, in modo da poterne comprendere a grandi linee il funzionamento.

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

Un problema che affligge la dimensione del blocco è il [paradosso del compleanno](https://it.wikipedia.org/wiki/Paradosso_del_compleanno) che rilascia informazioni sulla chiave ogni volta che avviene una collisione (quando due blocchi vengono cifrati allo stesso modo). Possiamo ritenere sicura solo la radice quadrata di tutte le combinazioni possibili. Per esempio con una dimensione di 64 bit, che genererebbe 2<sup>64</sup> possibili combinazioni, potremo impiegarne solo 2<sup>32</sup> prima di cominciare a rivelare informazioni sulla chiave.

### Metodi di crittazione a blocchi di cifre

Generalmente la dimensione del blocco scelta è della medesima lunghezza della chiave perché risulta semplice per l'implementazione di un algoritmo. Tuttavia è bene fare attenzione ad alcuni metodi che possono compromettere la sicurezza dell'algoritmo. Nei seguenti algoritmi individuiamo:

*k* è la chiave  
*P<sub>i</sub>* è l'i-esimo blocco del testo in chiaro  
*C<sub>i</sub>* è l'i-esimo blocco del testo cifrato  

#### Electronic Code Book (ECB)


<img src="{{site.baseurl}}/assets/images/crittografia/Ecb_encryption.png">
{: .ta-c}

*S(P<sub>i</sub>, k<sub>i</sub>) = C<sub>i</sub>*
{: .esempio .fs-5 .ta-c}

È l'implementazione più semplice, in cui l'unica cosa che nasconde il testo in chiaro è la chiave (o una parte di essa). Su questo metodo si basano sistemi come il [cifrario di Vigenere](#) e sappiamo che questo metodo risulta essere tanto semplice quanto insicuro. Infatti è sufficiente per l'attaccante raccogliere un numero sufficiente di campioni per poter eseguire un attacco di tipo statistico come il [metoto Kasiski](#). 

#### Cipher Block Chaining (CBC)

<img src="{{site.baseurl}}/assets/images/crittografia/Cbc_encryption.png">
{: .ta-c}

<div class="esempio fs-5 ta-c" markdown=1>

  *S((IV* ⊕ *P<sub>1</sub>, k<sub>1</sub>) = C<sub>1</sub>*
  {: .mt-0}

  *S((C<sub>i-1</sub>* ⊕ *P<sub>i</sub>, k<sub>i</sub>) = C<sub>i</sub>*
  {: .mb-0} 
    
</div>

Per superare i limiti di sicurezza di ECB, è necessario l'utilizzo di una tecnica in cui lo stesso blocco di testo in chiaro, se ripetuto, produce blocchi di testo cifrato differenti nonostante sia cifrato sempre con la stessa chiave. Questo è ciò che accade con la modalità CBC, in cui l'input dell'algoritmo di crittografia è il risultato dello [XOR](https://it.wikipedia.org/wiki/Disgiunzione_esclusiva) (indicato con il simbolo ⊕) tra il blocco di testo in chiaro corrente e il blocco di testo cifrato precedente; per ciascun blocco viene utilizzata la stessa chiave.

In fase di decifratura, ciascun blocco di testo cifrato passa attraverso l'algoritmo di decrittografia; il risultato subisce uno XOR con il blocco di testo cifrato precedente, per produrre il blocco di testo in chiaro.

Per produrre il primo blocco di testo cifrato, lo XOR viene effettuato tra un vettore di inizializzazione IV (dall'inglese initialization vector) e il primo blocco di testo in chiaro. In decifratura, l'IV subisce uno XOR con l'output dell'algoritmo di decrittografia in modo da ottenere nuovamente il primo blocco di testo in chiaro.

Il vettore di inizializzazione *IV* deve essere dunque noto non solo al mittente ma anche al destinatario, che tipicamente lo riceve assieme alla chiave.

Esistono altri sistemi basati sullo stesso principio quali Cipher Feedback (CFB), Output Feedback (OFB) o Counter (CTR) che presentano ognuno i propri vantaggi e svantaggi. Puoi approfondire [qui](https://it.wikipedia.org/wiki/Modalit%C3%A0_di_funzionamento_dei_cifrari_a_blocchi#Cipher_Block_Chaining_%28CBC%29) l'argomento.


### Esempi di algoritmi

Di seguito sono riportati i tre algorimi di cifratura simmetrica moderna più utilizzati dagli anni 1970 ad oggi.

#### DES (Data Encryption Standard)


è uno degli algoritmi a chiave simmetrica più famoso, pubblicato nel 1976 da IBM e scelto come standard per la Federal Information Processing Standard. È diventato in seguito lo standard fino a quando non fu decrittato nel 1997 in 3 giorni di calcolo. Nell'anno successivo fu sufficiente un giorno soltanto impiegando un cluster di computer e con l'avanzare i tempi si riducono ulteriormente. Il suo successore fu 3DES.

Impiega una chiave di 56 bit e opera su blocchi di 64 bit.

Puoi trovare altri dettagli [qui](https://it.wikipedia.org/wiki/Data_Encryption_Standard)

#### 3DES (Triple DES)

Quando DES non fu più sicuro, si cercò un metodo che mantenesse le meccaniche del DES ma che permettesse di avere una chiave più lunga. In questo algoritmo si esegue una tripla crittazione impiegando 3 chiavi DES standard, a 56 bit, ottenendo una chiave a 168 bit. È possibile anche invertire il secondo passaggio, ovvero eseguire una crittazione e una decrittazione. Tuttavia non modifica la sicurezza generale dell'algoritmo.

Anche questo algoritmo oggi non viene più impiegato poiché le tecnologie si stanno evolvendo e molti algoritmi di crittazione non risultano abbastanza forti da sopportare le elevate capacità di calcolo dei computer moderni, soprattutto con l'avvento delle GPGPU (general-purpose computing on graphics processing units ovvero le schede video dei nostri computer). 3DES ha lasciato il posto a AES, il nuovo standard ormai.

Puoi trovare altri dettagli [qui](https://it.wikipedia.org/wiki/Triple_DES)

#### AES (Advanced Encryption Standard)

Nel 1999 si presentarono vari algoritmi candidati a diventare lo standard di crittografia simmetrica. Questi candidati furono MARS proposto dalla IBM, RC6, Serpent, Twofish e Rijndael. Tutti questi algoritmi furono testati per efficienza e sicurezza su varie architetture, sia hardware che software. Tra questi ricevette un feedback positivo Rijndael ([ˈrɛindaːl]) che nel 2000 divenne il nuovo standard con il nome di AES. Fu dapprima impiegato dal governo degli USA e dopodiché il suo successo divenne globale.

AES lavora su blocchi a dimensione fissa di 128 bit. Inizialmente la lunghezza standard per la chiave era di 128 bit ma è stata prevista la possibilità di impiegate chiavi più lunghe da 192 e 256 bit, cosa che con l'aumentare della potenza di calcolo disponibile risulta ormai necessario per buoni livelli di sicurenzza.

Puoi trovare altri dettagli [qui](https://it.wikipedia.org/wiki/Advanced_Encryption_Standard)

### Cifrari a flusso

I cifrari a flusso sono cifrari simmetrici che non lavorano su un blocco di cifre con una chiave delle stesse dimensioni, come nei cifrari visti finora, ma combino la chiave (o una sequenza di numeri da essa derivata) con l'intero messaggio, di solito attraverso operazioni XOR.

I cifrari a flusso sono ispirati al [cifrario di Vernam](#), l'unico sistema crittografico per cui esiste la dimostrazione matematica della sua assoluta sicurezza. L'idea di questi cifrari infatti è quella di imitare l'utilizzo di una chiave lunga come l'intero messaggio, generando in fase di cifratura (e decifratura poichè simmetrico) una **sequenza di numeri pseudocausali** con cui cifrare il messaggio. La differenza col cifrario di Vernam è che in quel caso la chiave è davvero costituita da valori totalmente casuali e imprevedibili, caratteristica che rende il sistema sicuro; in questo caso invece la sequenza di caratteri generata è solo pseudocasuale.

Una sequenza di numeri pseudocasuale è prodotta da un **algoritmo deterministico** il cui stato di partenza dipende da un valore detto comunemente "seed" (seme in inglese) che costituisce in questo contesto la chiave di cifratura. Questa sequenza di numeri non è quindi davvero casuale ma dipende dalla chiave, e a **una stessa chiave corrisponde sempre una stessa sequenza di numeri pseudocasuali**, motivo per cui conoscendo la chiave è possibile generare la stessa sequenza sia in fase di cifratura che di decifratura. L'unica cosa in cui la sequenza assomiglia ad una realmente casuale è che produce le stesse proprietà statistiche (frequenza e distribuzione dei valori...).

Un'altra proprietà significativa di un generatore di numeri casuali è il suo **periodo**, ovvero il **numero di elementi dopo i quali la sequenza si ripete**. In generale più è lungo il periodo e migliore è la qualità del generatore. Nel nostro caso la sequenza prodotta equivarrà alla chiave realmente usata per cifrare i messaggi in chiaro e come sappiamo quando la chiave si ripete è possibile effettuare un attacco.

#### RC4

Un esempio di implementazione particolarmente famoso ed utilizzato in passato di questo sistema è l'algoritmo RC4 che consiste nella generazione di un flusso di bit pseudocasuale (keystream) combinato mediante un'operazione di XOR con il testo in chiaro per ottenere il testo cifrato. L'operazione di decifratura avviene nella stessa maniera, passando in input il testo cifrato ed ottenendo in output il testo in chiaro, questo perché il keystream è lo stesso a partire dalla stessa chiave e lo XOR è un'operazione simmetrica.

Non ci interessa approfondire i dettagli tecnici riguardo a questo algoritmo che puoi approfondire [qui](https://it.wikipedia.org/wiki/RC4), quello che ci interessa analizzare è come algoritmi quali RC4 paghino la propria semplicità e velocità in termini di sicurezza: questa infatti è molto debole e l'algoritmo è violabile con relativa facilità e velocità, tanto che il suo uso non è più consigliabile.

La debolezza di questi algoritmi risiede proprio nel legame che c'è tra la chiave e il keystream che non è una sequenza di numeri realmente casuali ma una sequenza di numeri prodotta da un algoritmo deterministico. Nel 2005 infatti è stato trovato un modo per violare una connessione wireless protetta con [WEP](https://it.wikipedia.org/wiki/Wired_Equivalent_Privacy), protocollo di cifratura per le reti Wi-Fi che usa RC4, in meno di un minuto.

### Lunghezza delle chiavi nella crittografia simmetrica

Il governo statunitense impose un serio limite all'esportazione e all'utilizzo di chiavi lunghe. Per molti anni il limite imposto dal governo fu di 40 bit, che per lo standard moderni è un limite ridicolo dato che un semplice computer è in grado in poche ore di verificare tutto lo spazio delle chiavi. Infatti mentre in Europa e nel resto del mondo si diffondevano algoritmi con chiavi lunghe gli Stati Uniti d'America per via di scelte politiche rimanevano costretti a utilizzare chiavi corte. Con la diffusione di internet e del commercio elettronico il Governo degli Stati Uniti fu costretto a cambiare la legge innalzando il limite a 128 bit.

Quando nel 1977 il Data Encryption Standard (DES) venne distribuito dal governo Statunitense la lunghezza della chiave di 56 bit era più che sufficiente, sebbene nel Lucifer, predecessore del DES la chiave fosse già di 112 bit. Ma l'NSA quando approvò il DES decise di ridurre la chiave. Visto che l'NSA è una delle agenzie meglio finanziate dal governo statunitense, si ritiene che già verso la fine degli anni settanta avessero risorse tecnologiche e finanziarie sufficienti per sviluppare una macchina specializzata che forzasse il DES verificando l'intero spazio delle chiavi. Comunque negli anni novanta si dimostrò che il DES era forzabile in un paio di giorni utilizzando macchine specializzate dal costo inferiore al milione di dollari e quindi con costi accessibili a tutte le multinazionali e ovviamente a tutti i Governi. Nel libro Cracking DES (O'Reilly and Associates) viene descritto come la EFF abbia finanziato e costruito una macchina in grado di forzare il DES. Da allora sono sorti anche dei progetti basati su computer distribuito che hanno consentito di forzare chiavi a 56 bit e che attualmente stanno forzando un messaggio a 64 bit codificato con l'algoritmo RC5.

L'algoritmo Skipjack dell'NSA utilizzato dal programma Fortezza utilizza chiavi a 80 bit.

Il DES è stato temporaneamente sostituito dal Triple DES che usa tre chiavi da 56 bit per ottenere una cifratura a 168 bit.

L'Advanced Encryption Standard pubblicato nel 2001 utilizza chiavi da almeno 128 bit e è un grado di utilizzare anche chiavi a 192 o 256 bit. La chiave a 128 bit viene considerata sufficiente per compiti normali mentre l'NSA specifica che per documenti Top secret la chiave deve essere di 192 o 256 bit.

Nel 2003 l'U.S. National Institute for Standards and Technology, NIST, ha proposto di abbandonare tutte le chiavi a 80 bit entro il 2015.

## Crittografia asimmetrica

Fino agli anni 1970 gli unici sistemi crittografici esistenti erano simmetrici cioè prevedevano l'utilizzo di un'unica chiave utilizzata sia per cifrare che per decifrare. Per quanto i crittosistemi fossero sicuri ed efficienti rimaneva da risolvere un problema fondamentale, quello della **condivisione della chiave**. A questo scopo vennero proposte una serie di tecniche che si possono definire di cirittocrafia asimmetrica.


### La matematica alla base della crittografia asimmetrica

Prima di poter affrontare l'argomento è necessario studiare le basi matematiche che stanno alla base di tutta la crittografia asimmetrica cioè i numeri primi e l'aritmetica dei moduli.

#### Numeri primi

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

#### Aritmetica modulo n

Nel seguito **N** e **Z** denoteranno rispettivamente l'insieme dei numeri naturali {0,1,2,...} e l'insieme degli interi relativi {...,-2,-1,0,+1,+2,...}.
Dati a, b in **Z** ed n > 1 in N, diciamo che ***a*** *è congruo a* ***b modulo n*** se a e b divisi per n danno lo stesso resto; in questo caso scriviamo una relazione di equivalenza. *a ≡ b* mod(*n*). La relazione di congruenza è una relazione di equivalenza.

Esempio 
L'aritmetica dei moduli prende in considerazione un gruppo limitato di numeri disposti
ad anello, un po’ come le ore sul quadrante dell'orologio.\
Consideriamo ad esempio un quadrante contenente solo 7 numeri, da 0 a 6, corrispondente al modulo 7. \
Per calcolare 2 + 3 si partirà da 2 e ci si sposterà di 3 numeri, ottenendo 5. Per calcolare 2 + 6 si partirà da 2 e ci si sposterà di 6 numeri. In questo modo, attraversando l'intero anello, si otterrà come risultato 1.  
In pratica:  
2 + 3 ≡ 5 mod(7)  
2 + 6 ≡ 1 mod(7)
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

#### Il cifrario di Cesare “generalizzato” con l’aritmetica modulo n

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

##### Identità di Bézout 

Se *d* = MCD(*a, b*) allora esistono degli interi *x* e *y* tali che *d* = *a · x + b · y* 

#### Funzione e Teorema di Eulero

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

#### Un’applicazione della funzione di Eulero

Vedremo ora un’interessante applicazione del Teorema di Eulero, che permette di calcolare, dato un numero in forma di potenza, le cifre decimali del numero stesso scritto in forma posizionale.

Partiamo da un caso semplice per chiarire meglio il concetto: supponiamo di voler conoscere la cifra x che indica in numero di unità del numero 13<sup>5</sup>. In questo caso, una semplice calcolatrice portatile consente di ottenere il risultato 371293 e scoprire così che la cifra cercata è 3.

Vediamo come si sarebbe potuto ottenere lo stesso risultato con la funzione e il teorema di Eulero: cercare la cifra che indica il numero di unità di 13<sup>5</sup> equivale a calcolare il resto della divisione per 10, ossia il numero compreso tra 0 e 9 tale che *x* = 13<sup>5</sup> in *Z*<sub>10</sub>.

- 13 ≡ 3 mod(10), in quanto il resto della divisione per 10 è uguale e pari a 3;

- x = 13<sup>5</sup> = 3<sup>5</sup>

- per il Teorema di Eulero avremo: *a* = 3; *n* = 10; $$\phi$$(10) = $$\phi$$(2 · 5) = (2 - 1) · (5 - 1) = 4 

- 3<sup>*$$\phi$$*(10)</sup> = 3<sup>4</sup> ≡ 1  mod(10)  (infatti: 3<sup>4</sup> = 81 ≡ 1 mod(10)) 

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

### Lo scambio di chiavi secondo Diffie, Hellman e Merkle

Il modo migliore per capire come si sia potuti arrivare a concepire e a realizzare un sistema crittografico che non necessiti di uno scambio preventivo di chiavi da parte di mittente e destinatario è partire da un esempio. Supponiamo che, per scambiarsi documenti riservati, mittente e destinatario utilizzino una scatola alla quale sia possibile applicare due lucchetti; è dunque possibile procedere nel seguente modo: 

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/doppio_lucchetto.jpg" class="modal__opener" aprire="#doppio-lucchetto">
</div>
<!-- modal -->
<div id="doppio-lucchetto" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#doppio-lucchetto">&times;</span>
    <img src="{{site.baseurl}}/assets/images/doppio_lucchetto.jpg">
    <p>Il metodo del doppio lucchetto.</p>
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
  |Decifrato da Bob:|EI CNAIYWB| che non è "ci vediamo"
  {: .invisible .distanzia-colonne-3}
  </div>
</div>

Questo problema fu affrontato e risolto negli anni ’70 del secolo scorso dai ricercatori Whitfield Diffie, Martin Hellman e Ralph Merkle.

Le funzioni di cui si servirono per risolvere il problema della distribuzione delle chiavi derivano dall'[aritmetica dei moduli](#aritmetica-modulo-n) dove è spesso possibile incontrare funzioni unidirezionali, funzioni agevoli da calcolare in una direzione ma che diventano computazionalmente
pesantissime nella direzione opposta (funzione inversa).

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
              Alice e Bob hanno ottenuto lo stesso numero <em>K</em> che rappresenterà la chiave dei loro messaggi.<br>
              <p class="ta-c mb-0">
                <em>K = K<sub>a</sub> = K<sub>b</sub> = Y<sup>A·B</sup> mod(p) = Y<sup>B·A</sup> mod(p) = 13<sup>8·5</sup> mod (23) = 9</em>
              </p>
          </td>
        </tr>
    </tbody>
</table>

In base a questo schema abbiamo dunque dimostrato che Alice e Bob possono concordare una chiave senza bisogno di incontrarsi e senza il timore che la chiave stessa sia intercettata da terzi: abbiamo quindi risolto il problema della distribuzione delle chiavi!

Per convincercene ulteriormente, vediamo perché ad Eva sia impossibile risalire al valore della chiave. Poiché tutte le comunicazioni dello schema precedente tra Alice e Bob sono in chiaro, Eva potrebbe aver intercettato le seguenti informazioni: 

- le comunicazioni relative alla scelta di *Y* e *p*, e quindi sapere che la funzione è del tipo: 13<sup>*x*</sup> mod(23); 
- le comunicazioni del passo 3, e quindi i valori di *α* e *β*. 

**Per trovare la chiave, Eva dovrebbe quindi procedere come Alice ed effettuare l’operazione *β^A* mod(*p*)**, oppure come Bob ed effettuare l’operazione ***α^B* mod(*p*)**. Ma Eva non conosce i valori di A o di B! D’altronde, tentare di ricavarli invertendo la funzione non sarebbe un compito semplice, in quanto si tratta di una funzione unidirezionale.

Se confrontiamo l'idea originale del doppio lucchetto con la soluzione trovata notiamo che mentre quell'idea cercava di proporre un vero e proprio sistema di cifratura per trasmettere messaggi cifrati, **questo sistema permette solamente di concordare un numero segreto**.

La dimostrazione pubblica della loro scoperta fu data da Diffie, Hellman e Merkle nel giugno del 1976 alla National Computer Conference. 

L’introduzione di un metodo che consente a mittente e destinatario di scambiarsi la chiave in modo “sicuro” ha costituito una vera e proprio rivoluzione nel campo della crittografia; l’unico aspetto negativo del sistema Diffie - Hellman - Merkle risiede nell’introdurre una non contemporaneità tra le azioni di destinatario e mittente. Infatti, per applicare il suo “lucchetto” Bob deve attendere di ricevere il messaggio di Alice (supponiamo tramite mail), e la stessa Alice, per rimuovere il suo “lucchetto” deve attendere la risposta di Bob, e così via. Questo aspetto, che per persone che vivono in luoghi con fusi orari differenti può comportare un “ritardo” anche notevole nello scambio delle mail, rappresenta chiaramente un elemento che va contro la natura stessa della posta elettronica, che rappresenta uno dei modi più veloci di scambio delle informazioni. Detto in termini più tecnici questo sistema è **adatto solo a comunicazioni di tipo sincrono e non a comunicazioni di tipo asincrono**.

Ricapitolando quindi possiamo dire che ***il sistema di Diffie-Hellman-Merkle risolve il problema della condivisione della chiave ma non offre un vero e proprio sistema di cifratura, inoltre è adatto solo a comunicazioni sincrone***. Nel prossimo paragrafo vedremo come queste limitazioni siano state superate dall’introduzione della crittografia a chiave pubblica.

### RSA 
Il passo avanti rispetto al metodo di scambio delle chiavi secondo Diffie-Hellman-Merkle avvenne grazie allo sforzo congiunto di tre ricercatori: Ronald Rivest, Adi Shamir e Leonard Adleman, dalle cui iniziali deriva il metodo noto come RSA. 

Il pregio di questo sistema rispetto al metodo Diffie-Hellman-Merkle è che non richiede uno scambio di informazioni tra Alice e Bob per la costruzione della chiave: questo sistema fa infatti uso di due chiavi, una detta “chiave pubblica ” e una chiamata “chiave privata” e utilizza un metodo di cifratura asimmetrico. 

In un sistema a chiave asimmetrica la chiave usata per cifrare e quella usata per decifrare non coincidono: è possibile quindi che Alice renda pubblica la chiave da usare per cifrare un messaggio (la sua chiave pubblica) e conservi segreta la chiave da usare per decifrare il messaggio (la sua chiave privata), per essere in grado solo lei di decifrare i messaggi a lei diretti. 

Il cuore della cifratura asimmetrica sviluppata da Rivest, Shamir e Adlemann è una funzione unidirezionale basata sul concetto di modulo.

#### Funzionamento

Il funzionamento del metodo RSA si può schematizzare con i seguenti punti: 

- si scelgono due numeri primi, *p* e *q* ; 
- si calcola il loro prodotto *N* = *p* · *q* , chiamato *modulo* (dato che tutta l'aritmetica seguente è in *modulo n*
- si sceglie poi un numero *e* (chiamato *esponente pubblico*), più piccolo di *N* e primo rispetto a $$ {\phi(N) = (p-1)\cdot(q-1)} $$, dove $${\phi}$$ è la funzione di Eulero; 
- si calcola il numero d (chiamato *esponente privato*) tale che *e* · *d* ≡ 1 mod((*p*-1)·(*q*-1))

La chiave pubblica è rappresentata dalla coppia di numeri (*N, e*), mentre la chiave privata è rappresentata da (*N, d*). 

Un messaggio *m* viene cifrato attraverso l'operazione *m<sup>e</sup>* mod(*N*), mentre il messaggio *c* così ottenuto viene decifrato con *c<sup>d</sup>* = *m<sup>e·d</sup>* = *m*<sup>1</sup> mod(*N*). Il procedimento funziona solo se la chiave *e* utilizzata per cifrare e la chiave *d* utilizzata per decifrare sono legate tra loro dalla relazione *e* · *d* ≡ 1 mod((*p*-1)·(*q*-1)), e quindi quando un messaggio viene cifrato con una delle due chiavi (la chiave pubblica) può essere decifrato solo utilizzando l'altra (la chiave privata). 

#### Dimostrazione matematica

La decifratura del messaggio è assicurata grazie ad alcuni teoremi matematici; infatti dal calcolo si ottiene:  

$$c^d \pmod{N} = (m^e)^d \pmod{N} = m^{e·d} \pmod{N}$$  

Ma sappiamo che  

$$e·d ≡ 1 \pmod{(p-1)·(q-1)}$$  

di conseguenza abbiamo che  

$$ e · d ≡ 1 \pmod{p-1}, \qquad e · d ≡ 1 \pmod{q-1}$$  

quindi, per il [piccolo teorema di Fermat](https://it.wikipedia.org/wiki/Piccolo_teorema_di_Fermat):  

$$m^{e · d} ≡ m \pmod{p}, \qquad m^{e · d} ≡ m \pmod{q}$$  

Siccome *p* e *q* sono numeri diversi e primi, possiamo applicare il [teorema cinese del resto](https://it.wikipedia.org/wiki/Teorema_cinese_del_resto), ottenendo che  

$$m^{e · d} ≡ m \pmod{p · q}$$  

e quindi che  

$$c^{d} ≡ m \pmod{N}$$


#### Esempio di utilizzo (singola cifratura)

Vediamo in pratica come sia possibile realizzare una cifratura RSA. 

Per cifrare un messaggio, questo deve essere prima di tutto trasformato in un numero o in una serie di numeri, diciamo *m<sub>1</sub>, m<sub>2</sub>,..., m<sub>k</sub>*. Questa operazione può essere effettuata utilizzando, ad esempio, il codice ASCII, e trasformando il numero binario ottenuto nel corrispondente in base dieci. Per semplicità, nel prossimo esempio considereremo che il messaggio segreto che si vuole trasmettere consista di un solo numero *m*, senza preoccuparci del metodo utilizzato per generarlo. 

Faremo inoltre nuovamente riferimento ai nostri personaggi immaginari, Alice e Bob. 

##### Operazioni effettuate da Alice (Generazione delle Chiavi):

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
    sceglie <em>e</em> tale che: <em>e</em> < <em>\(\phi\)(N)</em> e <em>MCD(e, \(\phi\)(N))</em> = 1 (cioè <em>e</em> coprimo con <em>\(\phi\)(N)</em>): 
    <p class="ta-c">
        <em>e</em> = 79
    </p>
  </li>
  <li>
    calcola <em>d</em> tale che: <em>e</em> · <em>d</em> ≡ 1 mod((<em>p</em>-1) · (<em>q</em>-1)):
    <p class="ta-c">
        <em>d</em> = 79<sup>-1</sup> mod(3220) = 1019
    </p>
    infatti:
    <p class="ta-c">
        79 · 1019 = 80501 ≡ 1 mod(3220)
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

##### Operazioni effettuate da Bob (Cifratura): 
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

##### Operazioni effettuate da Alice (Decifratura):

1. ricevuto il messaggio Alice ricava *m* mediante la formula *m* = *c<sup>d</sup>* mod(*N*):

  *m* = 1570<sup>1019</sup> mod(3337) = 688
  {: .ta-c}

**L’unico modo per Eva di decifrare il messaggio è di avere *d* e quindi di riuscire a ottenere *p* e *q* dalla fattorizzazione di *N***: come detto precedentemente, il processo di fattorizzazione di un numero nei suoi fattori primi è un processo molto lungo, specialmente se si ha a che fare con numeri molto grandi. La segretezza nella comunicazioni tra Alice e Bob è quindi assicurata!


#### Doppia cifratura

<!-- thumbnail -->
<div class="thumbnail float-right  thumbnail--50">
  <img src="{{site.baseurl}}/assets/images/crittografia/doppia-codifica.jpg" class="modal__opener" aprire="#img-doppia-codifica">
  <p>Schema della doppia cifratura in RSA</p>
</div>
<!-- modal -->
<div id="img-doppia-codifica" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-doppia-codifica">&times;</span>
    <img src="{{site.baseurl}}/assets/images/crittografia/doppia-codifica.jpg">
    <p>Dall'immagine si può vedere che Alice non si limita a cifrare il messaggio con la chiave pubblica di Bob ma esegue prima un'altra cifratura con la propria chiave privata; in questo modo Bob, aggiungendo una seconda decifratura con la chiave pubblica di Alice, sarà sicuro che solo Alice può aver cifrato e spedito il messaggio perchè è l'unica persona che conosce la chiave privata di Alice.</p>
  </div>
</div>

Con le operazioni fin qui descritte Alice e Bob sono riusciti ad assicurarsi solo il primo dei quattro [obiettivi della crittografia]({{site.baseurl}}/docs/reti/crittografia/crittografia/#obiettivi-della-crittografia): la riservatezza dei dati, ma non non gli altri tre. Per questo motivo RSA prevede una **doppia cifratura**.

Dall'immagine si può vedere che Alice non si limita a cifrare il messaggio con la chiave pubblica di Bob ma esegue prima un'altra cifratura con la propria chiave privata; in questo modo Bob, aggiungendo una seconda decifratura con la chiave pubblica di Alice, sarà sicuro che solo Alice può aver cifrato e spedito il messaggio perchè è l'unica persona che conosce la chiave privata di Alice. Il secondo e il quarto obiettivo: autenticazione dell'utente e non ripudio sono quindi stati raggiunti. 

Nelle comunicazioni digitali, l'autenticazione degli interlocutori è molto importante e nella maggior parte dei protocolli attualmente utilizzati per le comunicazioni sicure (come [TLS](#)) è prevista una fase di autenticazione in cui solitamente viene proprio usato RSA.

Per garantire anche il raggiungimento dell'ultimo obiettivo: l'integrità dei dati, è necessario utilizzare insieme ad RSA altri strumenti, come le [funzioni crittografiche di hash](#), ma questo è vero in generale per tutti i sistemi di comunicazione. 


#### Numeri primi e RSA 

Se da un lato la capacità di fattorizzare numeri ci permette di attaccare RSA, la conoscenza di numeri primi molto “grandi” ci permette di effettuare cifrature RSA sempre più potenti. La ricerca di tali numeri costituisce quindi un vero e proprio business, e molte aziende hanno come solo scopo quello di trovarne di sempre più grandi. 

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/crittografia/numeri-primi.png" class="modal__opener" aprire="#img-numeri-primi">
  <p>Un grafico aggiornato al 2016 del numero di cifre componenti il più grande numero primo conosciuto. La scala dell'asse delle ordinate è logaritmica. La linea rossa è la curva esponenziale che meglio si adatta al grafico e ha equazione: y = exp(0,187394 t − 360,527), dove t è in anni.</p>
</div>
<!-- modal -->
<div id="img-numeri-primi" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-numeri-primi">&times;</span>
    <img src="{{site.baseurl}}/assets/images/crittografia/numeri-primi.png">
    <p>Un grafico aggiornato al 2016 del numero di cifre componenti il più grande numero primo conosciuto. La scala dell'asse delle ordinate è logaritmica. La linea rossa è la curva esponenziale che meglio si adatta al grafico e ha equazione: y = exp(0,187394 t − 360,527), dove t è in anni.</p>
  </div>
</div>

[Il più grande numero primo conosciuto](https://it.wikipedia.org/wiki/Il_pi%C3%B9_grande_numero_primo_conosciuto) è, a ottobre 2020, 2<sup>82 589 933</sup> − 1, un numero che, se scritto in base 10, è composto da 24 862 048 cifre. Tale numero è stato scoperto il 7 dicembre 2018 da Patrick Laroche nell'ambito del progetto Great Internet Mersenne Prime Search (GIMPS).

I numeri della forma 2<sup>*n*</sup> - 1 sono detti numeri di Mersenne e sono indicati con *M<sub>n</sub>*. In generale questi numeri non sono primi, nemmeno se *n* è primo (per esempio *M*<sub>11</sub> = 2047 = 89 · 23); non si sa nemmeno se di numeri di Mersenne primi ce ne siano un numero finito o se siano infiniti. 

Dopo il 1992 tutti i numeri primi più grandi conosciuti sono stati numeri primi di Mersenne, l'ultimo numero primo non di Mersenne ad aver detenuto il suddetto record è stato 391 581 × 2216 193 − 1, scoperto nel 1989.


#### Attaccare RSA - La fattorizzazione 

Abbiamo visto che per attaccare RSA è necessario effettuare la fattorizzazione di N, ma come si fa a fattorizzare un numero così grande? La trattazione approfondita del problema la lasciamo ai matematici ma per capire l'entità del problema facciamo alcuni ragionamenti. 

A prima vista, sapendo che si usano numeri primi vicini a 2<sup>128</sup>, si potrebbe pensare di costruirsi una tabella dei numeri che sono prodotto di due tali primi. Ma quanti sono?  
In base al teorema dei numeri primi sappiamo che: 

$$ {\lim\limits_{x \to 1} \frac{\pi(n)}{\frac{n}{log(n)}} = 1} $$

dove *$$\pi(n)$$* rappresenta il numero di primi minori o uguali a *n*.

Dunque possiamo rozzamente valutare $$ {\pi(2^{128})} $$ come: 

$$ {\frac{2^{128}}{log(2^{128})} \approx 3 · 10^{36}} $$

e $$ {\pi(2^{127})} $$ come: 

  $$ {\frac{2^{127}}{log(2^{127})} \approx 2 · 10^{36}} $$ 
  
e quindi $$ {\pi(2^{128}-\pi(2^{127})) \approx 10^{36}} $$. Stiamo cauti nella stima e diciamo che ne abbiamo almeno 10<sup>30</sup> (in realtà potremmo anche dire con sicurezza 10<sup>35</sup> ). I prodotti di due numeri di questa forma sono allora dell’ordine di 10<sup>60</sup>. Immagazzinarli in forma binaria richiede allora $$ {2^{256} \cdot 10^{60} \approx 2^{256} \cdot 2^{199} = 2^{455}} $$ bit, quindi $$ {2^{452} \approx 10^{136} } $$ byte. Un terabyte è circa 10<sup>12</sup> byte, quindi servirebbe qualcosa come 10<sup>124</sup> terabyte. Troppi anche solo da immaginare: il diametro della Galassia in metri è 10<sup>21</sup>.

Più sensato è pensare di fattorizzare N, ma l’unico modo conosciuto è di dividerlo successivamente per 2, 3, e così via. E’ probabile che, nel momento in cui si è ottenuta la fattorizzazione richiesta, la chiave pubblica sia cambiata da parecchi mesi , si faccia un conto approssimativo del tempo richiesto. 

Un numero è detto semiprimo (anche detto biprimo o 2-quasi primo, o pq numero) è un numero naturale che è il prodotto di numeri primi (non necessariamente distinti). I primi numeri semiprimi sono: <span class="fs-2">4, 6, 9, 10, 14, 15, 21, 22, 25, 26, 33, 34, 35, 38, 39, 46, 49, 51, 55, 57, 58, 62, 65, 69, 74, 77, 82, 85, 86, 87, 91, 93, 94, 95, 106.<span>
<!-- 111, 115, 118, 119, 121, 122, 123, 129, 133, 134, 141, 142, 143, 145, 146, 155, 158, 159, 161, 166, 169, 177, 178, 183, 185, 187. -->
{: .thumbnail--testo .float-right .mt-0}

La RSA Laboratories fondata dai creatori dell'omonimo sistema di crittografia, ha proposto nel 1991 una sfida, la Factoring Challenge, in cui si offrivano premi in denaro a chi riuscisse a fattorizzare una serie di numeri semiprimi da usare come valori di *N* (semiprimi perchè prodotto dei due primi *p* e *q*). In questa pagina sono riportati i risultati raggiunti finora. Nonostante la gara sia stata dichiarata conclusa nel 2007 la ricerca delle soluzioni è ancora in corso e ad oggi (gennaio 2021) il numero più grande fattorizzato è RSA-250 un numero composto da 250 cifre decimali o 829 bits

  RSA-250 =
  {: .ml-4 .mr-4 .mt-0 .mb-0} 

  2140324650240744961264423072839333563008614715144755017797754920881418023447140136643345519095804679610992851872470914587687396261921557363047454770520805119056493106687691590019759405693457452230589325976697471681738069364894699871578494975937497937
  {: .ml-5 .mr-4 .mt-0 .fs-3} 

  RSA-250 =
  {: .ml-4 .mr-4 .mt-0 .mb-0} 

  64135289477071580278790190170577389084825014742943447208116859632024532344630238623598752668347708737661925585694639798853367
  {: .ml-5 .mr-4 .mt-0 .mb-0 .fs-3}

  ×
  {: .ml-4 .mr-4 .mt-0 .mb-0} 

  33372027594978156556226010605355114227940760344767554666784520987023841729210037080257448673296881877565718986258036932062711
  {: .ml-5 .mr-4 .mt-0 .fs-3}

In matematica, RSA-2048 è il più grande dei numeri RSA (semiprimi grandi che fanno parte del RSA Factoring Challenge). RSA-2048 è un numero con 617 cifre decimali (2048 bits) e probabilmente la sua fattorizzazione non varrà raggiunta ancora per alcuni decenni.

  RSA-2048 = 
  {: .ml-4 .mr-4 .mt-0 .mb-0} 

  25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784406918290641249515082189298559149176184502808489120072844992687392807287776735971418347270261896375014971824691165077613379859095700097330459748808428401797429100642458691817195118746121515172654632282216869987549182422433637259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133844143603833904414952634432190114657544454178424020924616515723350778707749817125772467962926386356373289912154831438167899885040445364023527381951378636564391212010397122822120720357
  {: .ml-5 .mr-4 .mt-0 .fs-3}

#### Lunghezza della chiave in RSA

Per quanto riguarda le dimensioni delle chiavi da utilizzare, nel 2003 la RSA ha dichiarato che una sua chiave a 1024 bit è equivalente a una chiave simmetrica a 80 bit, una sua chiave a 2048 bit è equivalente a una chiave simmetrica a 112 bit e la chiave a 3072 bit è equivalente a una chiave a 128 bit. RSA raccomanda di utilizzare chiavi ad almeno 1024 bit se si intende mantenere sicuri i documenti fino al 2010 e di utilizzare una chiave a 2048 bit se si vogliono documenti sicuri fino al 2030. La chiave a 3072 è indicata per i documenti che devono rimanere sicuri oltre il 2030. Un documento della [NIST](https://it.wikipedia.org/wiki/National_Institute_of_Standards_and_Technology) definisce una chiave asimmetrica a 15360 bit equivalente a una chiave simmetrica 256 bit.

Quando si sceglie la dimensione della chiave da utilizzare bisogna tenere a mente che per effettuare un qualsiasi attacco è necessario investire una certa quantità di risorse, che si possono tradurre anche in termini economici, e maggiori saranno le risorse investite maggiore sarà la velocità con cui si potrà effettuare l'attacco. Si sarà quindi disposti a fare un attacco solo nel caso le informazioni da scoprire abbiano un valore che valga la spesa richiesta. Ad esempio è interessante notare quanto detto alla conferenza Crypto ‘93 (ormai tantissimi anni fa ma il concetto è valido ancora oggi), da M. Wiener del Bell Northern Research, il quale ha descritto come con un milione di dollari sia realizzabile un chip speciale da 50 milioni di test al secondo che, in parallelo ad altri 57.000, può condurre un attacco con successo mediamente in 3,5 ore. Con un costo di 10 milioni di dollari il tempo si abbassa a 21 minuti, e con 100 milioni a disposizione, il codice è infranto in pochi secondi!


## Funzioni crittografiche di Hash

<!-- thumbnail -->
<div class="thumbnail float-right  thumbnail--50">
  <img src="{{site.baseurl}}/assets/images/crittografia/Hash_function.svg" class="modal__opener" aprire="#img-hash-function">
  <p markdown=1>Una funzione crittografica di hash al lavoro ([SHA1](https://it.wikipedia.org/wiki/SHA1)). Anche piccole modifiche ai dati di ingresso causano un notevole cambiamento dell'uscita: si tratta del cosiddetto effetto valanga.</p>
</div>
<!-- modal -->
<div id="img-hash-function" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-hash-function">&times;</span>
    <div class="modal__content__img-container"> 
      <img src="{{site.baseurl}}/assets/images/crittografia/Hash_function.svg">
    </div>
    <p markdown=1>Una funzione crittografica di hash al lavoro ([SHA1](https://it.wikipedia.org/wiki/SHA1)). Anche piccole modifiche ai dati di ingresso causano un notevole cambiamento dell'uscita: si tratta del cosiddetto effetto valanga.</p>
  </div>
</div>

Una funzione crittografica di hash, in informatica, è una classe speciale delle funzioni di hash che dispone di alcune proprietà che lo rendono adatto per l'uso nella crittografia.

Si tratta di un algoritmo matematico che mappa dei dati di lunghezza arbitraria (messaggio) in una stringa binaria di dimensione fissa chiamata valore di hash (spesso abbreviato impropriamente per comodità in hash), ma spesso viene indicata anche con altri termini come il termine inglese message digest (o semplicemente digest) oppure, se applicata a un file (o documento), come impronta digitale del file (o documento). Tale funzione di hash è progettata per essere unidirezionale (one-way), ovvero una funzione difficile da invertire: l'unico modo per ricreare i dati di input dall'output di una funzione di hash ideale è quello di tentare una ricerca di [forza-bruta](https://it.wikipedia.org/wiki/Metodo_forza_bruta) di possibili input per vedere se vi è corrispondenza (match). In alternativa, si potrebbe utilizzare una [tabella arcobaleno](https://it.wikipedia.org/wiki/Tabella_arcobaleno) di hash corrispondenti.

La funzione crittografica di hash ideale deve avere alcune proprietà fondamentali:

- deve identificare univocamente il messaggio, non è possibile che due messaggi differenti, pur essendo simili, abbiano lo stesso valore di hash;
- deve essere deterministico, in modo che lo stesso messaggio si traduca sempre nello stesso hash;
- deve essere semplice e veloce calcolare un valore hash da un qualunque tipo di dato;
- deve essere molto difficile o quasi impossibile generare un messaggio dal suo valore hash se non provando tutti i messaggi possibili.

Tali caratteristiche permettono alle funzioni crittografiche di hash di trovare ampio utilizzo in tutti quei contesti in cui sia necessario ottenere un'impronta digitale di un messaggio al fine di poterne poi verificare l'integrità.

### Proprietà

In generale una funzione di hash è progettata per prendere in input una stringa di qualsiasi lunghezza e produrre in output un valore di hash di lunghezza fissa. Per poter essere considerata funzione *crittografica* di hash questa funzione deve essere in grado di resistere a tutti gli attacchi basati sulla crittoanalisi: per fare questo deve rispettare le tre seguenti proprietà:

- **Resistenza alla preimmagine**:
> Dato un valore di hash h, deve essere difficile risalire ad un messaggio m con hash(m) = h. Questa proprietà deriva dal concetto di funzione unidirezionale. Funzioni che non dispongono di questa proprietà sono vulnerabili agli attacchi alla preimmagine.

- **Resistenza alla seconda preimmagine**:
> Dato un input m1, deve essere difficile trovare un secondo input m2 tale che hash(m1) = hash(m2). Funzioni che non dispongono di questa proprietà sono vulnerabili agli attacchi alla seconda preimmagine.

- **Resistenza alla collisione**:
> Dati due messaggi m1 ed m2, deve essere difficile che i due messaggi abbiano lo stesso hash, quindi con hash(m1) = hash(m2). Tale coppia è chiamata collisione di hash crittografica. Questa proprietà a volte è indicata come forte resistenza alla collisione. La resistenza alla collisione implica una resistenza alla seconda preimmagine, ma non implica la resistenza alla preimmagine: rispetto a quest'ultimo, richiede un valore di hash almeno due volte più lungo, altrimenti le collisioni possono essere trovate da un [attacco del compleanno](https://it.wikipedia.org/wiki/Attacco_del_compleanno).


Queste proprietà implicano che un eventuale attacco non permetta di rimpiazzare o modificare un messaggio senza conseguenze sul risultante valore di hash. Pertanto, se due stringhe hanno lo stesso digest, si può essere fiduciosi nel pensare che siano identiche. In particolare, la resistenza alla seconda preimmagine dovrebbe impedire ad un avversario maligno di elaborare un messaggio con lo stesso hash di un messaggio che l'avversario stesso non può controllare. La resistenza alla collisione, invece, impedisce all'attaccante di creare due messaggi distinti con lo stesso hash.

### Applicazioni

#### Verifica dell'integrità di un messaggio
Un'importante applicazione delle funzioni crittografiche di hash è nella verifica dell'integrità di un messaggio. Per mezzo di tali funzioni è possibile determinare, ad esempio, se sono state compiute modifiche ad un messaggio (o ad un file) confrontando il suo hash prima e dopo la trasmissione. Un particolare uso ne viene fatto nella maggior parte degli algoritmi di [firma digitale](#), i quali utilizzano le funzioni di hash al fine di produrre una firma tale da garantire l'autenticità di un messaggio, evitando che un possibile destinatario modifichi un documento firmato da qualcun altro. Per questo motivo il valore di hash viene anche detto impronta digitale del messaggio. La verifica quindi dell'autenticità del valore di hash del messaggio viene considerata come prova di autenticità del messaggio stesso.

#### Identificatore di file o dati
In quelle applicazioni in cui si necessita di gestire grandi quantitativi di file, un digest dei messaggi può anche essere utile nell'identificazione di essi in maniera affidabile. Diversi sistemi di gestione di codice sorgente, tra cui Git, Mercurial e Monotone, utilizzano il sha1sum (un algoritmo che calcola e verifica gli hash SHA-1) di vari tipi di contenuti (contenuti di file, alberi di directory, informazioni genealogiche, ecc.) per identificarli in modo univoco. Lo stesso obiettivo vuole essere raggiunto dalle reti di condivisione di file peer-to-peer dove, ad esempio, in un link ed2k, un hash di tipo MD4 è combinato con la dimensione del file, fornendo informazioni sufficienti per individuare le origini del file stesso, scaricarlo e verificarne il contenuto. I collegamenti magnetici (magnet links) ne costituisce un altro esempio. Avendo a disposizione funzioni hash di un certo tipo, una delle principali applicazioni delle funzioni crittografiche è quella di consentire la rapida ricerca di dati in una tabella hash. Tuttavia, rispetto alle funzioni di hash standard, le funzioni crittografiche di hash tendono ad essere più dispendiose in termini di calcolo. Per questo motivo, vengono utilizzate in contesti in cui è necessario che gli utenti siano protetti dalla possibilità di contraffazione (creazione di dati con lo stesso digest) da parte di partecipanti potenzialmente dannosi.

#### Verifica delle password
Nelle applicazioni che necessitano di un'adeguata autenticazione è troppo rischioso memorizzare le password di tutti gli utenti in chiaro, cioè su un file non cifrato, soprattutto nel caso in cui quest'ultimo venga compromesso. Un modo per evitare di andare incontro a una vera e propria violazione della sicurezza è quello di memorizzare solo il valore di hash di ogni password: una volta avvenuta l'autenticazione da parte dell'utente, viene calcolato l'hash della password da lui inserita e il risultato viene confrontato con l'hash memorizzato in precedenza. Spesso, la password viene concatenata con un valore casuale e non segreto, denominato salt, prima ancora che venga applicata la funzione hash. Utilizzati insieme, ma memorizzati separatamente, producono un output che sostituisce le sole password, consentendo dunque agli utenti di autenticarsi. Tenendo in considerazione il sale e il fatto che, generalmente, gli utenti ne possiedono diversi, non è possibile archiviare tabelle di valori di hash pre-computati per le password comuni. Però, come già accennato in precedenza, essendo da un lato le password dei messaggi brevi e le funzioni di hash progettate per essere calcolate rapidamente dall'altro, è possibile essere soggetti ad attacchi di forza bruta (basta considerare che la GPU può provare miliardi di possibili password al secondo). In compenso, esistono delle funzioni, denominate funzioni di stretching della chiave, come PBKDF2, Bcrypt o Scrypt che "potenziano" le password per renderle più sicure di fronte ad un attacco di forza bruta.

#### Proof-of-Work
Il sistema Proof-of-work è una misura economica per scoraggiare attacchi di tipo denial of service e altri abusi di servizio (come lo spam su una rete) che impone certi lavori da parte del richiedente del servizio, di solito intesi come tempo di elaborazione di un computer. Una caratteristica fondamentale di questi sistemi è la loro asimmetria: il lavoro deve essere moderatamente complesso (ma fattibile) sul lato richiedente, ma nello stesso tempo, per il fornitore di servizi (service provider) risulta semplice da controllare. Un sistema famoso, usato nella generazione di bitcoin e in Hashcash, usa inversioni di hash parziali per verificare che il lavoro sia stato fatto, in modo tale da sbloccare una ricompensa (detto reward di Bitcoin) nel caso di Bitcoin o come un token di buona volontà da inviare via e-mail ad Hashcash. In pratica, il mittente è tenuto a trovare un messaggio il cui valore hash inizia con un numero di bit zero: il lavoro medio che egli deve eseguire per trovare un messaggio valido è esponenziale nel numero di bit zero richiesti nel valore hash. D'altra parte, il destinatario può verificare la validità del messaggio eseguendo una singola funzione hash. Ad esempio, in Hashcash, se ad un mittente venisse richiesto di generare un header il cui valore hash SHA-1 a 160 bit ha come primi 20 bit degli zeri, dovrà in media provare 219 volte prima di trovare un header valido.

#### Generazione di numeri pseudocasuali e chiavi di derivazione
Le funzioni di hash possono essere impiegate anche per la generazione di stringhe pseudorandom o per la derivazione di chiavi e password da una singola chiave o password sicura.

### Attacchi alle funzioni crittografiche di hash

I possibili attacchi ad una funzione crittografica di hash si possono riassumere in due categorie:

- **Attacco alla preimmagine** cioè trovare il messaggio da cui è stato calcolato un certo valore di hash. 
> Di solito si vuole fare questo attacco quando si vuole scoprire una password di cui è stato salvato il valore di hash, argomento di cui si è parlato [qui](#verifica-delle-password)

- **Attacco alla seconda preimmagine** che consiste nel trovare una *collisione* ovvero trovare due messaggi che producano lo stesso valore di hash.
> Trovare delle collisioni permette ad un attaccante di sostituire un messaggio con un messaggio differente che produce lo stesso valore di hash


### Algoritmi di hash crittografico

Al giorno d'oggi esistono molte funzioni crittografiche di hash che vengono usate in molti contesti differenti. Nel tempo alcune di esse sono diventate obsolete perchè non più sicure all'aumentare della potenza di calcolo disponibile.

Di seguito sono riportate le funzioni crittografiche di hash più usate. Una lista più completa può essere consultata [qui](https://en.wikipedia.org/wiki/Comparison_of_cryptographic_hash_functions).

#### MD5
[MD5](https://en.wikipedia.org/wiki/MD5) was designed by Ronald Rivest in 1991 to replace an earlier hash function, MD4, and was specified in 1992 as RFC 1321. Collisions against MD5 can be calculated within seconds which makes the algorithm unsuitable for most use cases where a cryptographic hash is required. MD5 produces a digest of 128 bits (16 bytes).

#### SHA-1
[SHA-1]() was developed as part of the U.S. Government's Capstone project. The original specification – now commonly called SHA-0 – of the algorithm was published in 1993 under the title Secure Hash Standard, FIPS PUB 180, by U.S. government standards agency NIST (National Institute of Standards and Technology). It was withdrawn by the NSA shortly after publication and was superseded by the revised version, published in 1995 in FIPS  PUB 180-1 and commonly designated SHA-1. Collisions against the full SHA-1 algorithm can be produced using the shattered attack and the hash function should be considered broken. SHA-1 produces a hash digest of 160 bits (20 bytes).

Documents may refer to SHA-1 as just "SHA", even though this may conflict with the other Secure Hash Algorithms such as SHA-0, SHA-2, and SHA-3.

#### SHA-2
[SHA-2]() (Secure Hash Algorithm 2) is a set of cryptographic hash functions designed by the United States National Security Agency (NSA), first published in 2001. They are built using the Merkle–Damgård structure, from a one-way compression function itself built using the Davies–Meyer structure from a (classified) specialized block cipher.

SHA-2 basically consists of two hash algorithms: SHA-256 and SHA-512. SHA-224 is a variant of SHA-256 with different starting values and truncated output. SHA-384 and the lesser-known SHA-512/224 and SHA-512/256 are all variants of SHA-512. SHA-512 is more secure than SHA-256 and is commonly faster than SHA-256 on 64-bit machines such as AMD64.

The output size in bits is given by the extension to the "SHA" name, so SHA-224 has an output size of 224 bits (28 bytes); SHA-256, 32 bytes; SHA-384, 48 bytes; and SHA-512, 64 bytes.

| Algoritmo e variante | Dimensione dell'output (bit) | Dimensione dello stato interno (bit) |	Dimensione del blocco (bit) |	Max. dimensione del messaggio (bit) |	Dimensione della word (bit)	| Passaggi	| Operazioni	| Collisioni trovate
|-|-|-|-|-|-|-|-|-|
**SHA-0** |	160 |	160 |	512 |	2<sup>64</sup> − 1 |	32	| 80	| +,and,or,xor, rotl |	Sì
**SHA-1** |	160 |	160 |	512 |	2<sup>64</sup> − 1 |	32 |	80 |	+,and,or,xor, rotl |	Attacco [2<sup>63</sup>](https://it.wikipedia.org/wiki/Funzione_crittografica_di_hash#Algoritmi_di_hash_crittografico)
**SHA-2** (SHA-256/224) |	256/224 |	256 |	512 |	2<sup>64</sup> − 1 |	32 |	64 |	+,and,or,xor,shr, rotr |	Nessuna
**SHA-2** (SHA-512/384) |	512/384 |	512	| 1024 |	2<sup>128</sup> − 1 |	64 |	80 |	+,and,or,xor,shr, rotr |	Nessuna
{: .fs-3 .ta-c}

#### SHA-3
[SHA-3]() (Secure Hash Algorithm 3) was released by NIST on August 5, 2015. SHA-3 is a subset of the broader cryptographic primitive family Keccak. The Keccak algorithm is the work of Guido Bertoni, Joan Daemen, Michael Peeters, and Gilles Van Assche. Keccak is based on a sponge construction which can also be used to build other cryptographic primitives such as a stream cipher. SHA-3 provides the same output sizes as SHA-2: 224, 256, 384, and 512 bits.

Configurable output sizes can also be obtained using the SHAKE-128 and SHAKE-256 functions. Here the -128 and -256 extensions to the name imply the security strength of the function rather than the output size in bits.


## Firma digitale
  
La firma è  la sottoscrizione del proprio nome, o di uno pseudonimo, per chiudere un'opera d'arte o una scrittura, confermarla o renderne noto l'autore. Per questo motivo caratteristiche fondamentali della firma sono la sua unicità e il suo carattere personale. Il termine deriva dalla parola latina *firmus*, nel senso di definito, inamovibile.

La definizione appena data definisce il concetto classico di firma. Con l'avvento della digitalizzazione si è presentata la necessità di avere un corrispettivo digitale della normale firma autografa, qualcosa che permetta di dimostrare l'autenticità di un messaggio o di un documento digitale garantendo a chi legge tale documento che:

1. sia possibile verificare l'identità di chi ha firmato il documento (autenticazione),
2. il messaggio non sia stato modificato dopo l'apposizione della firma (integrità).
3. chi firma il documento non possa negare di averlo fatto (non ripudio)

Si può facilmente notare che queste tre condizioni corrispondono ai quattro [obiettivi della crittografia]({{site.baseurl}}/docs/reti/crittografia/crittografia/#obiettivi-della-crittografia) tolto quello riguardante la *riservatezza*, poichè in questo caso il documento non deve essere segreto, ma solo firmato.

Per raggiungere questi obiettivi si ricorre all'utilizzo di due strumenti precedentemente descritti: una funzione crittografica di hash e un algoritmo di crittografia asimmetrica, tipicamente RSA.

L'utilizzo di RSA permette di raggiungere gli obiettivi 1 e 3 poichè il firmatario può generare una coppia di chiavi pubblica privata e:
1. cifrare il documento con la propria chiave privata,
2. allegare al documento cifrato i propri dati personali, 
3. depositare la propria chiave pubblica, insieme ai propri dati personali presso un ente certificatore, che nella pratica in Italia possono essere ad esempio le Poste Italiane o la Camera di Commercio e che garantirà la corrispondenza tra i dati personali e la chiave pubblica;

in questo modo chiunque legga il documento può prelevare la chiave pubblica corrispondente ai dati personali allegati alla firma per decifrare il documento ed essere sicuro dell'identità del firmatario.

Con queste sole operazioni non è però garantita l'integrità del documento. Per raggiungere anche questo obiettivo è necessario usare anche una funzione crittografica di hash la cui principale applicazione è proprio quello di ottenere l'impronta diditale di un documento. La sequenza di operazioni da effettuare va quindi modificata come segue:

1. **calcolare il valore di hash** corrispondente al documento;
2. **cifrare il valore di hash** calcolato **con la propria chiave privata** e non l'intero documento, anche perchè l'obiettivo non è rendere segreto il documento ma solo firmarlo;
3. **depositare la propria chiave pubblica**, insieme ai propri dati personali **presso un ente certificatore**, che nella pratica in Italia possono essere ad esempio le Poste Italiane o la Camera di Commercio e che garantirà la corrispondenza tra i dati personali e la chiave pubblica (nessuna differenza rispetto a prima);
4. **allegare al documento il valore di hash cifrato e i propri dati personali**

in questo modo chiunque legga il documento può prelevare la chiave pubblica corrispondente ai dati personali allegati alla firma per decifrare il valore di hash e ricalcolare da se il valore di hash del documento e confrontare i due valori (quello decifrato dalla firma e quello ottenuto dal documento in chiaro ricevuto); se i due valori coincidono allora si può essere sicuri che documento e firma siano integri e autentici. I tre obiettivi sono stati raggiunti.



### Contraffare una firma digitale

Ceracare di contraffare una firma o un documento firmato, equivale ad effettuare un attacco a uno o entrambi i sistemi crittografici usati.

Se si vuole modificare il documento senza modificare la firma è necessario trovare una collisione della funzione crittografica di hash ovvero trovare un documento che produca lo stesso hash del documento originale.

Se si vuole firmare un documento con la firma di un'altra persona è necessario attaccare RSA e scoprire la chiave segreta di quella persona.

Entrambi questi scenari sono stati ampiamente trattati nelle sezioni riguardanti gli attacchi alle [funzioni crittografiche di hash]({{site.baseurl}}/docs/reti/crittografia/crittografia-moderna/#attacchi-alle-funzioni-crittografiche-di-hash) e a [RSA]({{site.baseurl}}/docs/reti/crittografia/crittografia-moderna/#attaccare-rsa---la-fattorizzazione).


### Come usare nella pratica la firma digitale

Nella pratica per poter utilizzare la firma digitale devo per prima cosa contattare un ente certificatore. In Italia gli enti certificatori, per poter rilasciare firme digitali, devono essere autorizzati da AgID, l'ente nazionale per la digitalizzazione della Pubblica Amministrazione. è possibile reperire [qui](https://www.agid.gov.it/it/piattaforme/firma-elettronica-qualificata/prestatori-di-servizi-fiduciari-attivi-in-italia) una lista completa dei *prestatori di servizi fiduciari* attivi in Italia compresa di link alla pagina di aquisto del servizio che ha un costo che si aggira sui 50€ all'anno. 

Una volta acquistato il servizio, l'ente certificatore si occupa di verificare l'identità di chi ha richiesto il servizio e rilascia uno o più dispositivi accompagnati da un software necessari all'applicazione delle firme ai documenti. I dispositivi possono essere una smart card (che contiene una sim) accompagnata da lettore oppure un'apposita chiavetta usb chiamata *token usb* provvista di sim.

Il software fornito per la firma dei documenti normalmente è in grado di firmare documenti pdf producendo un nuovo file in formato p7m che conterrà sia documento in chiaro che firma. Solitamente è possibile firmare documenti anche di formati differenti anche se il formato pdf è quello più supportato. Nel momento dell'apposizione della firma il software richiederà di poter comunicare con la sim, ricevuta tramite chiavetta o lettore di smart card, dove risiede la chiave privata necessaria per la firma. Per sicurezza l'accesso alla sim è protetto con un pin.

Di seguito è proposto il video informativo creato dalla camera di commercio di Milano, Monza Brianza, Lodi su che cos'è e come ottenere la firma digitale.

<div class="video-container">
<iframe src="https://www.youtube.com/embed/EMeIBuimVD4" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</div>

