---
layout: default
title: Architettura dei computer
nav_order: 2
has_children: False
---

# Architettura dei computer
{: .no_toc}


## Indice
{: .no_toc .text-delta }

- TOC
{:toc}

## Il computer
Il termine computer è un termine un po' generico e con esso ci si può riferire a molti dispositivi anche molto diversi tra loro come notebook, smartphone, server... La parola computer deriva dal verbo inglese "to compute" che significa "elaborare". Tutti i dispositivi elettronici in grado di eseguire calcoli o comunque in generale eseguire delle operazioni potremmo chiamarli quindi computer.

### Hardware e software

Per capire meglio come sia fatto un computer è bene partire innanzitutto dal definire due concetti fondamentali, quelli di hardware e software.
Col termine **hardware** ci si riferisce alle componenti fisiche (hard in inglese significa duro) di un computer, come ad esempio un processore, un hard disk, una tastiera o una stampante.
Col termine **software** ci si riferisce alle componenti immateriali che possiamo trovare in un computer come i programmi o i dati. Il software per poter esistere deve poter essere memorizzato in un componente hardware provvisto di memoria.

Solitamente i compomenti hardware di un computer, ad eccezione di alcuni componenti molto semplici, sono gestiti da appositi software che prendono il nome di driver o di firmware. I **driver** sono i software dedicati alla gestione delle periferiche di un computer e servono al sistema operativo di un computer per poter interagire correttamente con la specifica periferica. Il **firmware** è invece un software che gestisce in autonomia un determinato dispositivo hardware che può essere un dispositivo completamente autonomo o una parte di un computer. Un esempio importante è il firmware della scheda madre chiamato anche BIOS o più recentemente UEFI (vedi sezione "Esecuzione del sistema operativo").

## La struttura di un computer

### Architettura di Von Neumann

Negli anni '40 del novecento diversi scienziati hanno ideato dei dispositivi elettronici che sono stati presi a modello per i successivi computer. Esistono due modelli molto importanti nella storia dei computer:

- **la macchina di Turing**
- **l'architettura di Von Neumann**

Turing è considerato uno dei più grandi matematici moderni e uno dei più importanti teorici dell'informatica. Turing è forse lo scenziato che maggiormante ha contribuito allo sviluppo della teoria della computazione e elemento fondamentale di tale teoria è il modello di computer da lui ideato detto comunemente "macchina di Turing". 

Nonostante l'importanza che ricopre questo modello di computer, i computer moderni si basano su un'architettura differente ideata dal matematico e informatico ungherese John von Neumann (leggi *fon noiman*). La maggior parte dei primissimi computer costruiti verso la fine degli anni '40 è basata sull'architettura di Von Neumann.

Lo schema si basa sui seguenti componenti fondamentali:

- Unità centrale di elaborazione (CPU) o processore, che si occupa di svolgere tutte le operazioni;
- Memoria centrale, intesa come memoria di lavoro o memoria principale (RAM, Random Access Memory);
- Bus, un canale che collega tutti i componenti fra loro;
- Memoria di massa che serve a memorizzare permanentemente grandi quantità di dati;
- Periferiche di input/output, tramite le quali i dati vengono inseriti nel calcolatore per essere elaborati e infine restituiti all'utente;

Di seguito sono trattati in dettaglio i vari componenti

### CPU

Una CPU (Central Processing Unit) o processore è il componente del computer che ha il compito di eseguire le istruzioni dei programmi presenti nella memoria centrale del computer (in casi particolari anche da altre memorie come la rom in fase di boot, come spiegato nella sezione dedicata all'avvio del sistema operativo). La cpu è un dispositivo estremamente complesso formato da molte componenti, di seguito sono indicate le più importanti:

<!-- thumbnail -->
<div class="thumbnail tright mb-2">
  <img src="{{site.baseurl}}/assets/images/architettura/schema-cpu.png" class="modal__opener" aprire="#schema-cpu">
  <p>Schema della struttura interna di una CPU</p>
</div>
<!-- modal -->
<div id="schema-cpu" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#schema-cpu">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/architettura/schema-cpu.png">
    </div>
    <p>Schema della struttura interna di una CPU</p>
  </div>
</div>

- unità aritmetica logica (Arithmetic Logic Unit o ALU): si occupa di eseguire le operazioni logiche ed aritmetiche;
- unità di controllo (Control Unit o CU): è in grado di comprendere le operazioni da fare e coordina tutte le componenti della CPU affinchè vengano eseguite;
- registri: nella CPU sono presenti molti registri che consistono in una sequenza di bit; il numero di bit dipende dal processore e tutti gli altri componenti del pc, soprattutto il bus, si dovrà adeguare a questo numero. Ci possono essere processori a 8, 16, 32 o 64 bit cioè che usano registri con questo numero di bit. I registri possono essere al massimo qualche decina, alcuni generici che servono alla CPU per memorizzare e leggere molto velocemente i dati necessari allo svolgimento delle istruzioni, alcuni dedicati a specifiche funzioni, i più importanti sono:
  - program counter (PC) dove viene scritto l'indirizzo della memoria centrale della prossima istruzione da eseguire;
  - instruction register (IR) dove viene scritta l'istruzione corrente da svolgere in modo che l'unità di controllo possa leggerla e, sulla base dei bit contenuti in essa, mandare gli opportuni segnali a tutte le componenti della cpu, principalmente la alu;
- bus interno che serve a trasmettere i dati tra le diverse componenti; è formato da un fascio di cavi il cui numero è uguale alla dimensione dei registri in modo da trasmettere il valore di ogni bit di un registro;
- clock, dall'inglese orologio, che emette un segnale ad intervalli regolari e serve per coordinare temporalmente il lavoro di tutte le componenti della CPU in modo che ogni componente sappia l'esatto momento in cui deve effettuare ogni operazione. La frequenza a cui viene emesso il segnale viene comunemente detto frequenza di clock o più brevemente solo clock e ci dà un'indicazione generale della velocità a cui lavora il processore, i processori moderni hanno frequenze dell'ordine dei GHz (spesso tra 1 e 5 GHz).

#### Ciclo fondamentale o ciclo di fetch-execute
La CPU è in grado di eseguire un gran numero di operazioni anche molto diverse tra loro. Il genere di operazioni che vengono svolte sono: le operazioni aritmetiche, le operazioni logiche, lettura o scrittura di dati da o verso specifici registri o posizioni in memoria centrale... Le diverse operazioni possono essere più o meno complesse e richiederanno più o meno tempo per essere eseguite, una somma ad esempio richiede meno tempo di una divisione. Siccome ogni operazione singola delle componenti del processore avviene quando il clock manda un segnale a tutti, il tempo di esecuzione delle istruzioni da parte del processore viene misurato in numero di segnali del clock; una istruzione potrà quindi richiedere uno o più clock (diciamo per semplicità da 2 o 3 a una decina). Per avere un'idea di quanto tempo richieda l'esecuzione di una istruzione basta sapere il numero di clock e la frequenza del clock, se la frequenza è di 3GHz e un istruzione richiede 3 clock, l'operazione richiede 1 miliardesimo di secondo per essere eseguita ((1 / 3 miliardi) * 3). 

Il numero di operazioni e il modo in cui vengono eseguite cambia da processore a processore e costituisce il linguaggio dello specifico processore detto anche linguaggio macchina. 

Per quanto le operazioni possano essere diverse l'una dall'altra in realtà il processore continua a ripetere sempre la stessa sequenza di operazioni detto ciclo di fetch-execute o ciclo di prelievo ed esecuzione. Questo ciclo è composto da 3 fasi fondamentali:

1. il processore preleva (fetch) un istruzione dalla memoria nella posizione indicata dall'instruction pointer e la scrive nell'instruction register;
2. l'unità di controllo decodifica (decode) o interpreta l'istruzione da eseguire e manda gli opportuni segnali agli altri componenti del processore, ad esempio dice alla alu che operazione deve fare, da quali registri leggere i dati e su quale altro registro scrivere il risultato;
3. viene incrementato l'instruction pointer per puntare alla prossima istruzione da eseguire (in realtà l'istruzione eseguita dalla alu potrebbe essere quella di modificare il valore dell'IP per "saltare" ad un altra istruzione e questo permette di poter fare delle scelte in un programma, per questo motivo e per risparmiare tempo questa operazione viene in realtà fatta alla fine del punto 1)

Il processore non fa altro che ripetere questa sequenza all'infinito.

### Memoria Centrale

La memoria centrale è la memoria in cui devono essere memorizzate tutte le istruzioni che si vuole far eseguire alla CPU. Siccome il ciclo fondamentale di funzionamento della CPU richiede di accedere continuamente alla memoria, è necessario che l'accesso (sia scrittura che lettura) alla memoria sia il più possibile veloce. Succede anche spesso che il processore non acceda sempre in sequenza alle istruzioni scritte in memoria ma che decida di spostarsi frequentemente da un punto all'altro, come nel caso di scelte (if else), cicli (while e for), chiamate a funzioni o passaggio all'esecuzione di altri processi, la memoria centrale deve permettere di accedere il più velocemente possibile a qualsiasi posizione della memoria. Per questi motivi la memoria centrale deve avere particolari caratteristiche:
- essere più veloce possibile
- permettere quello che viene chiamato accesso casuale (random access) che in questo caso non si intende letteralmente "a caso" ma "in un qualsiasi punto"
La memoria centrale viene quindi chiamata anche RAM (Random Access Memory). Per poter avere queste caratteristiche la RAM è molto costosa e quindi se ne utilizza solo la quantità necessaria all'esecuzione dei programmi e non si usa per l'archiviazione dei dati e dei programmi. Un altro motivo molto importante per cui la RAM non può essere usata come archivio è che per poter essere molto veloce si utilizza una particolare tecnologia che ha il difetto di rendere la RAM **volatile** cioè in grado di mantenere memorizzati i dati solo quando è accesa e quindi percorsa da tensione elettrica.

Le principali caratteristiche delle memorie ram sono:
- la capienza misurata in byte poichè la memoria è formata da una lunghissima sequenza di byte e ogni byte è numerato per potervi accedere; attualmente le memorie di un PC contengono normalmente 8 o 16 GB;
- la frequenza del clock della memoria; anche la memoria ha un suo clock che scandisce il tempo per sincronizzare le operazioni da fare e la frequenza di clock ci indica indirettamente il tempo di accesso alla memoria; anche per le RAM attualmente le frequenze sono dell'ordine dei GHz anche se normalmente sono più basse di quelle del processore, ma un'operazione del processore richiede più cicli di clock rispetto alla semplice lettura da parte della memoria; il processore non viene quindi rallentato.

### BUS di sistema

Il BUS di sistema o più brevemente BUS è il canale di comunicazione che permette a tutti i componenti del computer di trasmettere dati tra loro. Di fatto un BUS è un fascio di "cavi" di rame che permettono di trasmettere in parallelo un certo numero di bit che dipende dal numero di "cavi". Il numero di bit trasmissibili in parallelo dal bus deve equivalere alla dimensione dei registri del processore (i processori di oggi lavorano solitamente con 64bit; i bus delle schede video per esigenze particolari, in particolare il parallelismo, possono arrivare a centinaia di bit). Il bus di sistema è composto in realtà da diversi bus:
- il bus dati su cui viaggiano i dati
- il bus degli indirizzi usato per indicare l'indirizzo della memoria a cui si vuole accedere (lettura o scrittura che sia)
- il bus di controllo che serve per inviare segnali di varia natura che servono a dirigere l'operato di tutti i componenti del computer (CPU che dice alle periferiche che cosa fare o periferiche che segnalano alla CPU un determinato avvenimento)

Il BUS è utilizzato continuamente dalla CPU per accedere alla memoria nel ciclo di fetch-execute ma è usato anche con minor frequenza per comunicare con le periferiche.

### Memoria di Massa

Le dimensioni limitate e la volatilità della RAM rendono necessaria l'adozione di periferiche di archiviazione di massa (o memoria di massa). Sebbene la memoria di massa possa essere considerata una periferica, la sua importanza comporta una gestione particolare e dedicata, essa è infatti indispensabile per:
-  caricare in memoria centrale tutti i programmi da eseguire (compreso il sistema operativo) e i dati da utilizzare
-  salvare tutto ciò che non si vuole perdere allo spegnimento del computer o tutto ciò che è troppo grande per stare interamente nella memoria centrale anche a computer acceso.

Esistono tantissimi tipi di memoria di massa che possono variare in base alle tecnologie adottate, la capienza e il costo. Le memorie possono essere ad accesso casuale come gli SSD o ad accesso sequenziale come gli HDD (hard disk), i nastri magnetici, i CD e i DVD. 

Le memorie ad accesso casuale presentano l'indiscutibile vantaggio di poter accedere velocemente ai dati ma sono più costose di quelle ad accesso sequenziale (in realtà andrebbe fatta la distinzione tra velocità di lettura/scrittura sequenziale e tempo di accesso casuale alla memoria e il confronto tra memorie sarebbe più complesso). Fino a 10-15 anni fa inoltre le memorie ad accesso casuale erano quasi solamente volatili e/o esageratamente costose. Solo nell'ultimo decennio hanno iniziato a diffondersi dispositivi di memorizzazione ad accesso casuale, non volatili, veloci e dal costo accettabile: gli SSD (solid state drive) che stanno lentamente soppiantando gli altri dispositivi di memorizzazione di massa.

### Periferiche

Le periferiche sono le componenti che permettono al computer di interagire col mondo esterno: l'utente o altri dispositivi e ne esistono un'infinità di tipi diversi. Alcune periferiche sono componenti elettronici che troviamo direttamente integrate nella scheda madre del computer come la scheda di rete o la scheda audio, altre possono essere esterne al computer come mouse, tastiera, schermo, stampante...
Le periferiche sono chiamate così perchè non fanno parte delle componenti del computer che interagiscono più frequentemente e velocemente, esse si trovano infatti anche fisicamente più lontane dalla CPU e interagiscono con essa in tempi che per un umano possono sembrare veloci ma per la CPU sono tempi lunghissimi. Un hard disk che è una periferica piuttosto veloce e che interagisce spesso con la CPU rispetto ad altre periferiche ha tempi di accesso ai dati dell'ordine dei millisecondi (10<sup>-3</sup>), mentre abbiamo visto che la CPU interagisce con la RAM in tempi dell'ordine dei nanosecondi(10<sup>-9</sup>), una differenza di 6 ordini di grandezza! Per questo motivo la CPU non sta mai ferma ad aspettare in attesa della risposta di una periferica ma continua a lavorare (con la RAM) mentre aspetta un segnale di risposta da una periferica (segnale che arriva per mezzo del bus di controllo con quella che viene chiamata una "interruzione")

### Altri componenti

L'architettura di Von Neumann prevedeva almeno in lineaa generale le presenza di tutti i compomenti finora esposti. Nella pratica sono però necessari una serie di altri componenti hardware che offrano una serie di funzionalità aggiuntive fondamentali: la CPU ha bisogno di essere alimentata e raffreddata, le periferiche devono essere collegate alla CPU, i vari componenti che sono delicati e devono essere protetti...

#### Il case

Il *case* (termine mutuato dall'inglese *computer case*) è essenzialmente la "scatola" che contiene e protegge tutti gli altri componenti hardware. Deve prevedere appositi alloggiamenti per fissare tutti i vari pezzi del computer e offrire aperture per poter collegare cavetteria di vario tipo alle varie periferiche. Esistono *case* di ogni tipo e dimensione in base alle esigenze, sia funzionali che estetiche. Online puoi trovare ogni tipo di esempio.  

#### La scheda madre
La scheda madre è il componente più importante non citato nella architettura di Von Neuman perchè è quel componente a cui vengono collegati con appositi collegamenti tutti gli altri componenti, compresi CPU e RAM. È talmente importante che quando si assembla un computer è il secondo componente che viene scelto dopo la CPU siccome deve essere pienamente compatibile con essa e supportarne le funzionalità. Una delle componenti della scheda madre è infatti il socket, cioè l'alloggiamento della CPU e ogni famiglia di CPU richiede un alloggiamento specifico con una serie di connettori o pin per collegare la CPU al BUS di sistema che è stampato sulla scheda madre (Intel e AMD, i principali produttori di CPU per computer desktop o notebook, sviluppano ogni pochi anni un nuovo tipo di socket). 

Alla scheda madre sono anche collegati i vari "banchi" di memoria RAM (si possono solitamente collegare 2 o 4 memorie RAM che vanno a formare insieme la memoria centrale).

Sulla scheda madre sono presenti un gran numero di connettori per collegare vari tipi di periferica. Sono inoltre presenti diverse periferiche ritenute utili e sufficientemente piccole da poter essere integrate direttamente nella scheda madre, come ad esempio il chip di rete o quello per l'elaborazione audio. In alcuni casi sono presenti anche chip per l'elaborazione video (chiaramente meno complessi e potenti rispetto ad una scheda video dedicata). Chip o schede dedicate sono essenzialmente dei minicomputer dedicati a svolgere un determinato compito che comunicano con la CPU. La trattazione di questi componenti, in particolare la scheda video sarebbe interessante ma troppo lunga e complessa.

#### Alimentatore
Ogni computer deve essere alimentato con corrente continua per funzionare, per questo motivo ogni computer è provvisto di un alimentatore che oltre a convertire la corrente alternata della linea elettrica in una corrente continua stabile senza sbalzi di tensione, fornisce tutti i diversi cavi e connettori per alimentare ogni componente del computer. Alcuni componenti, principalmente le periferiche, sono collegati direttamente all'alimentatore, mentre altri come la CPU e la RAM sono alimentati dalla scheda madre la quale è collegata all'alimentatore.

#### Sistemi di raffreddamento
Ogni dispositivo elettronico per funzionare è percorso da corrente elettrica e per questo motivo si scalda. Alcuni componenti che richiedono una scarsissima potenza per funzionare si scaldano molto poco e non ci si deve preoccupare più di tanto che si possano surriscaldare (sempre che siano stati ben progettati) per altri componenti è necessario invece ricorrere ad appositi sistemi di raffreddamento. Lo stesso case del computer deve prevedere un sistema di ricambio e circolazione dell'aria per permettere il raffreddamento dei vari componenti e questo avviene per mezzo di ventole opportunamente disposte in aperture del case. Alcuni componenti devono prevedere la presenza di radiatori che conducano bene il calore e lo possano scambiare con l'aria circolante. Su alcuni componenti come il processore e la scheda video, i componenti che si scaldano di può sono solitamente montate delle ventole sopra i rispettivi radiatori. Esistono per i casi più estremi sistemi di raffreddamento che invece che far circolare aria fanno circolare un liquido ad alta densità termica (sistemi di raffreddamento a liquido).

è importante ricordarsi che le aperture che permettono la circolazione dell'aria non devono mai essere ostruite quando il computer (o notebook o smartphone...) è acceso per non rischiare che il dispositivo si surriscaldi. I computer hanno dei sistemi di sicurezza che spengono il dispositivo quando la temperatura interna dei componenti sale troppo (sono presenti dei termometri) ma non sempre riescono a prevenire danni. Un cattivo raffreddamento può avvenire per i seguenti motivi:
- l'utente copre le aperture da cui deve entrare o uscire l'aria ad esempio appoggiando il dispositivo su un tessuto o mettendolo in uno zaino;
- il dispositivo si riempie di sporco, tipicamente polvere che si accumula sui radiatori o sulle prese d'aria, che imedisce il raffreddamento;
- i sistema di raffreddamento si danneggia o è montato male.
