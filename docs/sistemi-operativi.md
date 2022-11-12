---
layout: default
title: Sistemi Operativi
nav_order: 3
has_children: False
---

# Sistemi Operativi
{: .no_toc}

Un **sistema operativo** (abbreviato in SO, OS in inglese), in informatica, è un software di base, composto normalmente da più sottosistemi o componenti software: kernel, scheduler, file system, gestore della memoria, gestore delle periferiche, interfaccia utente, che gestisce le risorse hardware e software della macchina, fornendo servizi di base ai software applicativi. Tra i sistemi operativi per computer desktop si citano Microsoft Windows, MacOS, le distribuzioni Linux, sistemi Unix-like, BSD e Chrome OS, mentre per i dispositivi mobili, quali smartphone e tablet, vi sono iOS, Android, Windows Phone, Sailfish OS, Symbian OS e KaiOS.

## Indice
{: .no_toc .text-delta }

- TOC
{:toc}

## Descrizione

Un sistema operativo è un insieme di software che fornisce all'utente una serie di comandi e servizi per usufruire al meglio della potenza di calcolo di un qualsivoglia elaboratore elettronico, spaziando dal più piccolo dei palmari al più potente tra i mainframe. I sistemi operativi nascondono tutti i dettagli tecnici legati allo specifico hardware e architettura rappresentando le informazioni ad un alto livello, meglio comprensibile dall'uomo.

Esso garantisce l'operatività di base di un calcolatore, coordinando e gestendo le risorse hardware di processamento (processore) e memorizzazione (memoria primaria), le periferiche, le risorse/attività software (processi) e facendo da interfaccia con l'utente, senza il quale quindi non sarebbe possibile l'utilizzo del computer stesso e dei programmi/software specifici, come applicazioni o librerie software.

È dunque un componente essenziale del sistema di elaborazione che funge da interfaccia tra l'utente e la macchina ed inoltre è una base alla quale si appoggiano gli altri software, che dunque dovranno essere progettati e realizzati in modo da essere riconosciuti e supportati da quel particolare sistema operativo.

In generale un sistema operativo può essere:

- monoutente, se un solo utente per volta può accedere alle risorse dell'elaboratore;
- multiutente, se più utenti possono accedere alle risorse dell'elaboratore che a sua volta può essere:
    - seriale, sequenzialmente uno per volta;
    - parallelo, ciascuno parallelamente agli altri;
- monotasking o monoprogrammato, se in grado di eseguire un solo compito o task (processo) alla volta:
- multitasking o multithreading o multiprogrammato, se in grado di svolgere più compiti o sottocompiti parallelamente attraverso una certa politica di scheduling (es. timesharing).
- portabile o meno su differenti architetture hardware di processori.

### Funzioni principali

Secondo una definizione più rigorosa, il sistema operativo è un insieme di funzioni e strutture dati responsabile:

- del controllo e della gestione delle risorse di sistema (CPU e Memoria primaria);
- dell'esecuzione dei programmi (processi) che su di esso vengono eseguiti, assegnando ad essi le necessarie risorse per l'avanzamento dei processi;
- gestire l'archiviazione e l'accesso ai file. I programmi possono gestire l'archiviazione dei dati su memoria di massa (ottenendo strutture complesse, come una base di dati), servendosi delle procedure messe a disposizione del sistema operativo. La componente del SO che si occupa di tutto ciò viene chiamata file system;
- della gestione delle componenti hardware che costituiscono il computer (processi di Input/Output da e verso le periferiche collegate al sistema).

Infine, se è prevista interazione con l'utente, viene solitamente utilizzata allo scopo un'interfaccia software (grafica: GUI o testuale: CLI) per accedere alle risorse hardware (dischi, memoria, I/O in generale) del sistema. D'altra parte, un sistema operativo può essere utilizzato anche su una macchina che non preveda interazione diretta con un essere umano (per un esempio, vedi smart card o determinati sistemi embedded) spesso dunque più leggero e semplificato. Solitamente un sistema operativo installato su computer fornisce anche degli applicativi di base per svolgere elaborazioni di diverso tipo.

Sebbene molte delle funzionalità sopraddette non siano spesso immediatamente visibili/percepibili dall'utente, l'importanza del sistema operativo di un calcolatore è cruciale: oltre alla necessità di gestione delle funzionalità di base sopraddette, al di là delle prestazioni massime offerte dall'hardware dell'elaboratore stesso, il sistema operativo determina di fatto efficienza e buona parte delle prestazioni effettive di funzionamento dell'intero sistema ad esempio in termini di latenze di processamento, stabilità, interruzioni o crash di sistema.

## Struttura

Come già sommariamente descritto, un sistema operativo è formato da diversi componenti che sono organizzati secondo una struttura a strati a volte chiamata anche onion skin (buccia di cipolla in inglese). Questa suddivisione è tipica della maggior parte dei sistemi informatici poichè permette di dividere le funzioni dei diversi componenti del sistema in modo che ogni componente abbia la maggior indipendenza possibile nell'occuparsi della propria funzione in modo che una modifica ad uno dei componenti non comporti necessariamente la modifica dell'intero sistema. I vari strati che formano l'intero sistema conengono idealmente un solo componente (la realtà è spesso più complessa) e ogni componente utilizza le funzionalità offerte dal livello sottostante senza sapere come esso le implementi e offre a sua volta i propri servizi ai componenti del livello superiore (anche in questo caso un modello ideale prevede che si interagisca solo coi livelli immediatamente inferiori e superiori ma spesso nella realtà questo non è vero). 

Il livello più basso si occupa di gestire le componenti hardware in modo che i livelli superiori non abbiano la necessità di sapere come gestirle direttamente ma abbiano a disposizione delle funzioni standard. Su hardware diversi basta quindi modificare il codice del livello più basso per fornire le stesse funzionalità ai livelli superiori, tutto questo chiaramente entro certi limiti.

I livelli più vicini alla gestione dell'hardware vengono considerati *bassi* mentre i livelli più vicini all'interazione con l'utente vengono chiamati *alti*. Lo stesso sistema è usato per descrivere i linguaggi di programmazione che si dividono in linguaggi di basso livello e linguaggi di alto livello. Questa distinzione non vuole indicare la qualità delle funzionalità offerte ma soltanto il fatto che siano più o meno orientati alla gestione diretta dell'hardware o fornire funzionalità astratte adatte all'interazione con l'utente.

Un'ultima cosa da sottolineare è che questa divisione per livelli, oltre a fornire agli utenti componenti dedicate a semplificare l'utilizzo del computer, permette agli sviluppatori sofware di scrivere programmi senza doversi adattare alle specifiche hardware della moltitudine di dispositivi in commercio, ma semplicemente adattandosi alle funzionalità di alto livello (cioè lontane dal livello hardware) offerte dai sistemi operativi. Un programma scritto per Microsoft Windows può quindi essere eseguito su qualsiasi hardware gestito da tale sistema operativo. Sono gli sviluppatori del sistema operativo e i creatori dell'hardware che si devono preoccupare della compatibilità tra sistema operativo e hardware con la scrittura di appositi drivers ovvero software che dovranno essere aggiunti al sistema operativo per gestire specifici dispositivi.

Passiamo quindi ad analizzare le funzionalità dei vari componenti del sistema operativo.

### Kernel

Un kernel è un gruppo di funzioni fondamentali, strettamente interconnesse fra loro e con l'hardware. Un kernel non è altro che un software che ha il compito di fornire agli altri moduli che compongono il sistema operativo e ai programmi in esecuzione sul computer le funzioni fondamentali per un accesso controllato all'hardware, sollevandoli dai dettagli della sua gestione; esso fornisce dunque le funzionalità di base per tutte le altre componenti del sistema operativo, che assolvono le loro funzioni servendosi dei servizi che esso offre ed è dunque il motore o core di un sistema operativo.

A seconda del tipo di sistema operativo il kernel può inglobare altre parti o fornire solo funzioni base delegando più funzioni possibile a oggetti/gestori esterni. I sistemi operativi si dividono da questo punto di vista in due categorie:
- sistemi operativi a microkernel, cioè con un kernel minimale che si occupa solamente della gestione delle componenti hardware;
- sistemi operativi monolitici che integrano invece dentro di sé la gestione della memoria virtuale, la cpu, lo scheduler e i gestori di file system, nonché i driver necessari per il controllo di tutte le periferiche collegate.

Nella comunità informatica è aperta da decenni una discussione su quale sia l'approccio migliore da seguire, possiamo dire brevemente che il modello a microkernel è più complesso da progettare, mantenere ed aggiornare, ma è anche più veloce, efficiente e stabile. Attualmente la maggior parte dei sistemi operativi più usati e diffusi segue il modello monolitico o quantomeno un modello ibrido poichè si è dimostrato più semplice da sviluppare (il kernel linux e tutti i sistemi UNIX sono monolitici mentre i sistemi windows più recenti seguono un modello ibrido).

### Scheduler

Lo scheduler è il componente fondamentale dei sistemi operativi multitasking, cioè quelli in grado di eseguire più processi contemporaneamente (va inteso simbolicamente. In realtà non c'è una gestione parallela dei processi ma avviene in sequenza, i tempi sono talmente brevi che all'utente sembra che i programmi vadano contemporaneamente). Lo scheduler si occupa di fare avanzare un processo interrompendone temporaneamente un altro, realizzando così un cambiamento di contesto (context switch). Generalmente i computer con un processore sono in grado di eseguire un programma per volta, quindi per poter far convivere più processi è necessario usare lo scheduler. Lo scheduler deve continuamente decidere quale processo deve essere eseguito e per quanto tempo e le scelte fatte determinano le prestazioni complessive dell'intero sistema. Esistono vari algoritmi di scheduling che permettono di scegliere nella maniera più efficiente possibile quale processo far proseguire.

I processi non hanno continuamente bisogno della CPU: a volte, anziché far eseguire istruzioni alla CPU, si mettono in attesa che arrivino dei dati da un file, o che l'utente prema un tasto della tastiera. Quindi si può, in linea di principio, usare questi tempi "morti" (di attesa) per far eseguire un altro programma. Quest'idea, sorta fin dai primi anni cinquanta, si concretizzò nei sistemi operativi multitasking, cioè dotati di uno scheduler che manda in esecuzione più processi (esecuzione di programmi), assegnando a turno la CPU ad ognuno e sospendendo l'esecuzione dei processi in attesa di un evento esterno (lettura/scrittura sulle memorie di massa, stampa, input utente ecc.) finché questo non si verifica. Dovendo ospitare in memoria centrale più processi nello stesso tempo, i sistemi multitask hanno bisogno di più memoria rispetto a quelli monotask: perciò questo tipo di sistemi operativi è quasi sempre dotato di un gestore di memoria virtuale. Inoltre, con più processi simultaneamente attivi, il controllo delle risorse hardware diventa una reale necessità e non è più possibile farne a meno. 

Lo scheduler scandisce dunque il tempo di esecuzione dei vari processi e assicura che ciascuno di essi venga eseguito per il tempo richiesto. Normalmente lo scheduler gestisce anche lo stato dei processi e può sospenderne l'esecuzione nel caso questi siano in attesa senza fare nulla, assegnando le risorse inutilizzate ad altri processi che le necessitano (esempio classico è la richiesta di dati da disco).

#### Programma e Processo

Si è parlato fino ad ora di programmi e processi, risulta quindi necessario spiegare esattamente di che cosa si sta parlando. Un programma è composto da un elenco di istruzioni scritte in uno specifico linguaggio che descrivono uno o più algoritmi e che possono essere memorizzate su dispositivi di memoria di ogni genere. Il programma è quindi un'entità statica che esiste a prescindere dal fatto che essa venga o meno eseguita. Un processo invece è un'entità dinamica che rappresenta un programma in esecuzione su un calcolatore e che quindi è caricata sulla memoria centrale di un computer. Il processo non contiene solamente la sequenza di istruzioni del programma da eseguire ma anche tutte le informazioni riguardanti lo stato di esecuzione del programma compresi i dati prodotti o caricati in memoria di cui necessita e tutte le informazioni che il sistema operativo utilizza per gestirne l'esecuzione.

Ci sarebbe da fare una distinzione tra processo e thread ma una trattazione completa sarebbe complessa, diremo solo che un processo può essere diviso in thread, cioè in sottoprocessi in modo da poter eseguire in parallelo diverse operazioni. Questo è utile quando un processo è in esecuizione su un sistema che permette l'esecuzione contemporanea di più processi (o thread) perchè sono a disposizione diversi processori (su uno stesso computer o su una rete di computer).


### Gestore della memoria

Il gestore di memoria è la componente del sistema operativo che si occupa di gestire ed assegnare la memoria centrale ai processi che ne fanno richiesta per poter essere eseguiti. La gestione della memoria è necessaria anche per tenere traccia di quanta memoria è impegnata e di quanta invece è disponibile per soddisfare nuove richieste: in mancanza di un sistema di gestione, si avrebbe prima o poi il caso nefasto di processi che ne sovrascrivono altri, con gli ovvi inconvenienti. Esso è eseguito dal MMU (Memory Management Unit) che alloca la memoria primaria richiesta dai programmi e dal sistema operativo stesso (che è un programma). Quando i programmi terminano la loro esecuzione (sia perchè termina correttamente sia per un errore o un crash del programma) il gestore della memoria rende di nuovo disponibile la memoria utilizzata.

In un sistema monoprogrammato la gestione della memoria è molto semplice poichè il programma in esecuzione è da solo e ha a disposizione tutta la memoria. In un sistema multiprogrammato i processi che devono essere mantenuti in memoria possono essere molti e il gestore deve fare in modo che ogni processo abbia a disposizione tutta la memoria necessaria senza interferire con gli altri processi. Per raggiungere questi scopi la memoria viene gestita fornendo ai processi una ***memoria virtuale***. 

#### Memoria virtuale

Il concetto di virtualizzazione di una risorsa è molto comune in informatica e consiste nel fornire a chi richiede l'utilizzo di una risorsa, non il completo accesso e controllo della risorsa, ma un'interfaccia che consente di accedere indirettamente alla risorsa. In questo caso l'unico componente che vede ed utilizza la memoria per quella che è realmente è il gestore (l'MMU) che gestisce l'accesso di tutti i processi alla memoria. Ogni processo penserà di avere un accesso completo ed esclusivo alla memoria ma in realtà ne vedrà solo un pezzetto che lui vedrà come l'intera memoria del sistema. Il suo pezzetto di memoria sarà indirizzato come un unico grande blocco di memoria che parte dal byte 0 e termina al byte x. In realtà l'MMU sa che la memoria del processo parte da un certo byte dell'intera memoria centrale y e terminerà in un altra posizione (idealmente y+x). La memoria assegnata al processo potrebbe (e spesso succede) essere addirittura spezzettata in più parti ma il processo non se ne accorgerebbe, l'MMU si occupa di convertire al volo gli indirizzi di memoria del processo in indirizzi di memoria reali per accedere effettivamente alla memoria centrale.

La creazione di una memoria virtuale consente al gestore della memoria di offrire un'ulteriore funzionalità. Può succedere che i processi in esecuzione su un computer richiedano un quantitativo di memoria superiore a quella disponibile nella memoria centrale, in questo caso il gestore della memoria può decidere di spostare temporaneamente sulla memoria di massa i dati dei processi che non sono attualmente in esecuzione. Quando lo scheduler riporterà in esecuzione il processo i cui dati sono temporaneamente in memoria di massa, il gestore della memoria riporterà in memoria centrale tutti i dati (per essere eseguito un processo deve risiedere in memoria centrale!). Questo sistema di spostamento temporaneo dei processi dalla memoria centrale alla memoria di massa e viceversa prende il nome di ***swap*** o ***swapping*** e la zona del dispositivo di memoria di massa (hhd o ssd) messo a disposizione per questo scopo è il file di swap (se risiede nel normale file system ) o partizione di swap (se viene usata una partizione a parte).

#### Frammentazione della memoria

Il continuo processo di assegnamento e liberazione della memoria comporta il fatto che la memoria venga progressivamente frammentata. Nel tempo si formano una moltitudine di zone occupate separate da zone più o meno grandi di memoria libera. Il gestore della memoria avrà sempre più difficoltà a trovare zone contigue di memoria sufficientemente grandi per l'esecuzione dei processi e sarà costretto a spezzettare le zone di memoria da assegnare ad un processo. La frammentazione della memoria rappresenta un grosso problema soprattutto se si sta parlando di memoria non ad accesso casuale come gli hard disk, ma lo è anche nel caso della memoria ram se si iniziano a formare frammenti troppo piccoli. Esistono diverse strategie per far fronte al problema e la più semplice è quello di suddividere la memoria in blocchi di dimensione fissa inseparabili che devono essere assegnati e liberati per intero, questi blocchi vengono chiamati pagine (o pages in inglese). Il gestore della memoria tiene traccia delle pagine assegnate ai vari processi nel **file di paging** che consiste essenzialmente in una grande tabella in cui si associano i processi con le pagine.

### Gestore delle periferiche

La gestione delle periferiche è assegnata a specifici componenti che sulla base dei driver forniti dai produttori sono in grado di fornire agli altri componenti del sistema operativo e ai software un'interfaccia semplificata per accedere a tali periferiche. La gestione delle periferiche avviene sulla base dello stesso sistema visto per la gestione della memoria, la virtualizzazione. Questo sistema permette a chiunque voglia utilizzare una periferica di usarla pensando di averne un accesso esclusivo, in realtà si avrà accesso solo ad un interfaccia virtuale e l'accesso reale alla risorsa sarà gestita dal gestore. Questo permette di gestire l'accesso concorrente di più processi alla stessa risorsa. Un esempio semplice è quello dell'accesso alla stampante: più processi possono mandare contemporaneamente in stampa un file ed essi saranno stampati uno per volta.

### File System

Tutti i computer necessitano di una memoria di massa e il sistema operativo deve fornire ad utenti e processi un accesso ordinato ad essa. Il file system è un software che in sintesi è composto da un insieme di funzioni che permetta di organizzare e gestire (accesso o lettura, scrittura o memorizzazione, ordinamento) i dati sulla superficie dei mezzi di memorizzazione secondo una struttura ben precisa.

Le memorie di massa, come la memoria centrale è suddivisa in blocchi di dimensione fissa non separabili chiamati normalmente *settori* (di solito di 512 byte, sempre per gestire la frammentazione del disco) in cui vengono effettivamente memorizzati i dati. Il file system nasconde la gestione fisica della memoria di massa e offre una organizzazione logica dei file che è quella a cui siamo abituati. Esistono una moltitudine di file system diversi e l'organizzazione fisica dei dati può variare anche molto (più che altro nella gestione di basso livello cioè nella gestione dell'hardware) ma la rappresentazione di alto livello è quasi sempre più o meno la stessa. I dati vengono odinati in files che a loro volta sono organizzati in cartelle. Nella versione classica e più semplice, quella usata da linux, le cartelle sono ordinate in un unico albero, con una cartella *radice* (*root*) che contiente tutte le altre; ogni cartella può a sua volta contenere altre cartelle (ramificazione dell'albero) e infine contenere files (le foglie). Cartelle e file sono identificati da un nome e i file sono caratterizzati anche da un'estensione (ad esempio .exe o .txt) che ne descrive il tipo (utile per sapere con quale programma vanno aperti o eseguiti).

Il file system non si limita ad ordinare i dati e permetterne visualizzazione e modifica ma permette anche di stabilire i criteri di accesso. Il sistema operativo (se multiutente) permette di identificare l'utente che sta accedendo al sistema e quindi associa ad ogni file e cartella i permessi di accesso degli utenti. Un utente può avere o meno il permesso di vedere, leggere o modificare un file.

### Interfaccia utente

L'interfaccia utente è quel componente che permette all'utente di interagire col sistema operativo ed è quindi il componente di più alto livello. Come accennato in precedenza esistono dispositivi per cui non è prevista un'interazione con l'utente e quindi questo componente potrebbe non essere presente.

Le interfacce utente si dividono in due categorie principali:

#### CLI o Command Line Interface

Linterfaccia a riga di comando è la prima e più vecchia interfaccia introdotta sui computer poichè è la più semplice da implementare e richiede una quantità di risorse estremamente limitata per essere eseguita. Con questa interfaccia l'utente scrive direttamente con la tastiera i comandi che desidera eseguire e il risultato è scritto sotto forma di testo sullo schermo. Questa interfaccia pur essendo la più semplice e veloce da implementare è anche la più complicata da usare poichè prevede che l'utente conosca tutti i comandi di cui ha bisogno. Nonostante la difficoltà di utilizzo in realtà per un utente esperto si tratta di un interfaccia molto efficace. Per questi motivi al giorno d'oggi la CLI è usata solo da utenti esperti e professionisti soprattutto su sistemi server.

#### GUI o Graphical User Interface

L'interfaccia grafica è un tipo di interfaccia che è stata introdotta per i personal computer dagli anni '80. Questo tipo di interfaccia è molto più immediata ed intuitiva e a differenza di una CLI, non richiede una particolare conoscenza del sistema con cui interagire ed è qundi quella utilizzata da tutti gli utenti comuni. Esistono una grandissima varietà di GUI che spesso inseguono i gusti degli utenti.

Va ricordato che tutte le interfacce utente sono componenti a sè del sistema operativo e che esse vengono eseguite come tutti gli altri programmi e richiedono una certa quantità di risorse che per le GUI possono anche essere consistenti tanto che GUI moderne possono non essere eseguibili su sistemi datati, questo è anche il motivo per cui non sono state introdotte le GUI prima degli anni 80.

## Esecuzione del Sistema Operativo

Il sistema operativo è il software che gestisce tutto l'hardware e permette l'esecuzione di tutti i programmi. Quando accendiamo il computer però sappiamo che la memoria centrale è vuota poichè è una memoria volatile, il sistema operativo non è quindi in esecuzione. All'accensione del computer devono quindi avvenire dei processi particolari che permettano di avviare l'esecuzione del sistema operativo per poter poi continuare con il normale utilizzo del computer. Questa fase di aviamento del computer prende il nome di ***boot*** o ***bootstrap***.

Il bootstrap indica l'insieme dei processi che vengono eseguiti da un computer durante la fase di avvio, in particolare dall'accensione fino al completo caricamento in memoria primaria del kernel del sistema operativo a partire dalla memoria secondaria.
{:importante}

Nei primi computer l'inserimento del sistema operativo nella memoria centrale avveniva manualmente, ma successivamente sono stati sviluppati dei sistemi automatici per il caricamento del sistema operativo dalla memoria di massa alla memoria centrale. Per effettuare tali operazioni sono state inserite sulla scheda madre del computer una o più memorie non volatili che contengono il codice necessario a fare tale operazione. Queste memorie si trovano sulla scheda madre del computer e contengono un software chiamato BIOS (Basic Input-Output System) o più recentemente UEFI (Unified Extensible Firmware Interface). 

Il BIOS è il firmware del computer e, pur essendo composto da istruzioni software, è una parte integrante dell'hardware. Prima del 1990, il BIOS veniva memorizzato su una o più ROM, non riprogrammabili. Con l'aumentare della complessità, di pari passo con la necessità di aggiornamenti, si è diffusa la memorizzazione del firmware BIOS su memorie flash (come quelle delle chiavette usb), per permettere un rapido aggiornamento anche dall'utente inesperto.

Di seguito verranno elencate le operazioni effettuate durante il bootstrap:

1. Accensione (fase di RESET): nei primi momenti successivi all'ingresso della corrente nei circuiti elettronici il processore aspetta che le tensioni si stabilizzino, dopodichè viene segnata come prossima istruzione da eseguire l'istruzione presente in un particolare indirizzo di memoria che indica una zona della memoria non volatile in cui risiede il BIOS;
2. POST (*Power On Self Test*): il BIOS esegue una serie di test su tutte le componenti hardware collegate alla scheda madre, durante questa fase sullo schermo possono essere visibili (spesso si può scegliere) o un'immagine fissa (di solito il logo del produttore della scheda madre) oppure l'esito dei test man mano che vengono eseguiti; 
3. Avvio del boot loader: il BIOS carica in un punto particolare della memoria centrale un software, il boot loader, che si trova in una posizione fissa (il master boot record o MBR) della memoria di massa, questo software serve a scegliere (viene proprio chiesto all'utente) quale sistema operativo caricare in memoria centrale, se ce ne sono più di uno, e caricarlo correttamente.
4. caricamento e avvio del sistema operativo.

Solitamente, una volta che il sistema operativo è stato caricato, viene chiesta e verificata l'identità dell'utente per mezzo di una password (o recentemente in alcuni casi con altri metodi come la lettura dell'imporonta digitale)


















