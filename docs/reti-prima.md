---
layout: default
title: Reti per la classe prima
nav_order: 3
has_children: False
---

# Le reti di computer
{: .no_toc}

Lo studio approfondito del funzionaemnto delle reti di calcolatori è argomento di quinta e verrà trattato nell'[apposita sezione](reti/reti/). Per poter affrontare lo studio della programmazione e più in generale per poter utilizzare opportunamente il computer nell'era delle reti e di internet, è necessario avere almeno alcune conoscenze di base sul funzionamento delle reti di computer.

## Indice
{: .no_toc .text-delta }

- TOC
{:toc}

## Che cos'è una rete

Una rete di computer, è un insieme di dispositivi (host e nodi di commutazione), collegati l’uno con l’altro da appositi canali di comunicazione (link), che per mezzo di opportuni protocolli di comunicazione hanno la possibilità di condividere risorse che possono essere materiali, cioè dispositivi fisici come una stampante, o immateriali come dati, informazioni o servizi di ogni genere.

Le reti possono essere realizzate con un gran numero di tecnologie e modelli differenti. Di seguito verranno descritte alcune tecnologie e alcuni protocolli fondamentali.

## Protocollo

Per poter parlare di tecnologie di rete è necessario definire che cos'è un protocollo.

In informatica un protocollo è l'insieme delle regole che devono essere rispettate per poter effettuare una comunicazione. Parlando di protocolli di rete normalmente si intendono tutte le specifiche dell'hardware coinvolte (se è un protocollo che lavora anche a livello hardware), e tutte le regole che riguardano forme e tempi della comunicazione. Il protocollo può prevedere l'utilizzo di un linguaggio specifico per la comunicazione ma rappresenta qualcosa di molto più ampio e i due concetti non vanno confusi.

## Le reti locali o LAN

In base all'estensione le reti vengono catalogate in maniera differente poichè in base all'estensione vengono usate tecnologie differenti. Potremmo in generale distinguere le reti tra reti locali o LAN (local area network) e reti geografiche o WAN (wide area network). Mentre le reti geografiche sono quelle gestite dai gestori delle linee telefoniche o ISP (internet service provider) cioè le compagnie che ci forniscono la connessione alla rete internet, le reti LAN sono quelle reti che hanno un'estensione di un edificio o pochi edifici adiacenti, come la rete della scuola o la rete di casa nostra.

Le reti LAN, come tutte le altre reti possono presentarsi sotto forma di reti cablate o reti wireless (letteralemente senza cavo) e i due principali protocolli che vengono usati sono WiFi e Ethernet.

### Reti cablate

Le reti possono usare cavi fisici per comunicare che si possono dividere in due grandi categorie: i cavi di rame che trasmettono i bit che compongono i dati da comunicare sotto forma di tensioni elettriche e cavi in fibra ottica che trasmenttono segnali luminosi (fotoni).

#### Cavi di rame

I protocolli che prevedono cavi di rame sono tantissimi ma il più usato, quello che vediamo in quasi tutte le reti LAN sono i cavi definiti dal protocollo Ethernet (IEEE 802.3) e detti quindi comunemente cavi Ethernet. Questi cavi sono formati da un fascio di 8 cavi di rame intrecciati tra loro. Il protocollo Ethernet prevede in realtà due tipi di cavi che differiscono tra loro per l'intestazione e sono:

- cavi diretti che hanno la stessa disposizione degli otto cavi interni alle due estremità e sono utilizzati per collegare i computer ai dispositivi di rete (hub, switch, router), sono quelli più comuni;
- cavi incrociati che hanno una disposizione "*incrociata*" di alcuni dei cavi interni alle due estremità e sono utilizzati per collegare i computer direttamente tra loro, sono usati molto raramente poichè di solito i computer non si collegano direttamente fra loro.

I cavi di rame sono relativamente economici (rispetto alla fibra ottica in realtà il rame costa) e molto usati ma presentano un limite: sono soggetti alle interferenze con altri cavi, soprattutto i cavi che portano la corrente elettrica. Per questo motivo i cavi in rame sono spesso schermati con delle reti metalliche ma nonostante questo, anche nelle migliori condizioni, non riescono a trasmettere un buon segnale oltre i 100 metri.

#### Cavi in fibra ottica

I cavi in fibra ottica sono basati su un meccanismo diverso da quelli di rame, non trasmettono infatti tensioni elettriche ma sono strutturati come dei piccoli tubi la cui superficie interna è riflettente e permette di trasmettere segnali luminosi al loro interno. Questo meccanismo è molto più efficiente rispetto alla trasimissione di un segnale elettrico e permette di raggiungere velocità di trasmissione molto più alte rispetto ai cavi di rame. I cavi in fibra ottica inoltre non risentono di interferenze elettriche e trasmettono i segnali ad una distanza maggiore raggiungendo circa i 1000 metri. Per questi motivi tutte le grandi dorsali della rete internet sono fatte oggi con cavi in fibra ottica. I cavi in fibra ottica sono però costosi (soprattutto i dispositivi che li usano) e fragili e per questo sono poco usati nelle reti locali.

### Reti wireless

Le reti wireless sono reti che utilizzano segnali radio per trasmettere dati tra dispositivi muniti di apposite antenne. Il principale protocollo per le reti locali wireless è il WiFi (IEEE 802.11) che definisce tra le varie cose le frequenze e le forme d'onda utilizzate per trasmettere i segnali. Un'aspetto importante da sapere sulle frequenze utilizzate, che possono variare tra le centinaia di MHz e i GHz, è che a frequenze più alte corrispondono velocità maggiori di trasmissione ma anche una peggior capacità del segnale di oltrepassare ostacoli come i muri di casa o le piante (che contengono acqua), mentre a frequenze minori corrispondono velocità minori ma una maggior capacità di trasmissione in presenza di ostacoli. Per questi motivi in certi contesti è preferibile usare frequenze minori pur di avere una miglior ricezione del segnale. Questo è anche il motivo per cui protocolli ad alta velocità di trasmissione che utilizzano alte frequenze necessitano di una visuale diretta tra le antenne ricetrasmittenti come nel caso del 5G ed è il motivo per cui vengono abbattuti tanti alberi nelle strade delle città in cui si sta implementando la rete 5G.

Mentre per le reti cablate l'accesso alla rete è evidente e di facile controllo poichè richiede un accesso fisico alla rete, nelle reti wireless sono molto semplici gli accessi indesiderati alla rete se non si implementano apposite misure di sicurezza basate sulla crittografia. Il protocollo WiFi prevede infatti la cifratura dei dati ed è normalmente richiesta la conoscenza di una chiave di cifratura per accedere alla rete. Possono essere previsiti anche altri sistemi ancora più sicuri come il filtro degli indirizzi fisici delle schede di rete o il possesso di un certificato di identità digitale.

### Dispositivi di rete

Le reti cablate prevedono la presenza di alcuni dispositivi di rete per collegare alla stessa rete molti dispositivi, questi dispositivi sono:

- hub: dispositivi molto semplici, economici ma a basse prestazioni, con poche porte (attacchi per i cavi di rete), sono ormai poco usati e considerati obsoleti;
- switch: dispositivi più complessi in grado di gestire molte porte e collegare molti computer all'interno di una rete
- router: dispositivi in grado di gestire una rete e collegarla ad un altra rete; funge da *gateway* verso la rete internet per i dispositivi appartenenti ad una rete locale;
- access point: dispositivi che collegano la parte di rete wireless col resto della rete che è cablata; spesso nelle reti locali come quelle domestiche questa funzionalità è incorporata nel router che funge anche da access point.

## Misurazione del traffico

Nelle reti il traffico viene misurato indicando il numero di bit che percorre un certo canale o dispositivo nell'unità di tempo, questa quantità viene chiamata *bandwidth* (letteralmente ampiezza di banda). L'unità di misura normalmente utilizzata è il bit per secondo indicata normalmente con ***bps*** (bit per second) preferito a b/s. Il fatto che normalmente la dimensione dei dati venga indicata in byte può generare una certa confusione. Un esempio classico è l'indicazione della velocità di una comune rete in fibra ottica domestica che può essere 100 Mbps (poi la velocità reale di solito è inferiore ma è un altro discorso). Quando scarichiamo un documento però normalmente la velocità di download ci viene indicata in MB/s. Per uniformare le due misure dobbiamo ricordare che la velocità della nostra connessione indicata a 100MBps corrisponde a 100/8 = 12 MB/s.

## Indirizzamento dei dispositivi in rete

### Indirizzi IP

Per permettere la comunicazione tra dispositivi collegati in rete è necessario fornire ad ogni dispositivo un codice identificativo univoco, così come avviene ad esempio per poter spedire la posta ordinaria in cui si indicano via, numero civico, comune, nazione, che sono unici nel mondo. Esistono molti modi per identificare i dispositivi in rete ma il metodo usato nella rete internet e nella maggior parte delle reti locali (che si collegano poi alla rete internet) è quello usato dal protocollo IP (Internet Protocol) che usa codici di 32 bit (4 byte) normalmente indicati come 4 numeri separati da un punto. Questi numeri rappresentano ognuno un byte e sono quindi numeri che vanno da 0 a 255. Un paio di indirizzi IP sono ad esempio 192.168.1.10 oppure 142.250.180.164 che è l'indirizzo di un server di Google.

Purtroppo quando hanno inventato il protocollo IP negli anni 80 non si immaginava la grande diffusione che avrebbero avuto i computer e quindi sono stati introdotti indirizzi di soli 32 bit che ci permettono avere al massimo 2<sup>32</sup> = 4.294.967.296 (circa 4 miliardi) indirizzi che al giorno d'oggi sono troppo pochi (negli anni 80 sembravano tantissimi). La soluzione definitiva a questo problema è il passaggio ad una nuova versione del protocollo IP che prevede indirizzi a 128 bit che dovrebbe risolvere per sempre il problema (2<sup>128</sup> è un numero davvero gigantesco). Il vecchio protocollo è indicato con IPv4 (versione 4) mentre quello nuovo IPv6. Purtroppo cambiare tutta l'infrastruttura di internet è un processo lento e costoso e per questo nel tempo si sono utilizzati altri stratagemmi per poter riutilizzare gli indirizzi, il più importante è quello di usare indirizzi che siano univoci solo all'interno delle reti private (solitamente reti locali ma non sempre), questi indirizzi vengono detti indirizzi privati. è il router che collega la rete privata alla rete pubblica che si occupa di comunicare col resto del mondo con un indirizzo IP pubblico e quindi univoco nel mondo (in realtà possiamo avere anche reti private dentro reti private). La gestione di questo sistema è complicata e comporta delle limitazioni a quello che si può fare in una rete privata (anche se ci dà qualche vantaggio dal punto di vista della sicurezza) e per questo si auspica un passaggio completo al protocollo IPv6.

### URL e nomi di dominio

Abbiamo detto finora che per identificare un computer in rete abbiamo bisogno di un indirizzo IP eppure quando con un browser ci vogliamo collegare ad un sito internet, non scriviamo mai un indirizzo IP. Per identificare una risorsa in rete si utilizza un altro codice identificativo che si chiama URL (Uniform Resource Locator) che ci dice dove possiamo trovare la risorsa. La struttura dell'URL è:

`<scheme>://<domain>:<port>/<path>?<querystring>#<fragmentid>`

che nella sua forma più semplice e comune, togliendo i campi meno usati dai normali utenti, è:

`<scheme>://<domain>/<path>`

dove:

- "scheme" è il protocollo da usare per comunicare col dispositivo che possiede la risorsa
- "domain" è il nome di dominio ossia l'identificativo del dispositivo su cui si trova la risorsa;
- "path" è il percorso che indica la posizione della risorsa all'interno del dispositivo (come nelle cartelle del nostro PC).

Il sistema dei nomi di dominio o DNS (Domain Name System) è un sistema pensato per sostituire gli indirizzi IP nel riferirsi ad un dispositivo in rete. Per gli esseri è molto più semplice usare e memorizzare parole che codici numerici, inoltre il sistema DNS consente una serie di funzionalità avanzate molto utili nella gestione della rete. A livello di gestione della comunicazione di rete i dispositivi hanno bisogno di utilizzare gli indirizzi IP, per questo motivo, ogni volta che vogliamo accedere ad una risorsa indicando il nome di dominio, il browser (o qualunque altro software stia cercando di accedere alla risorsa) richiede la conversione di tale nome di dominio in indirizzo IP a un apposito server detto comunemente server DNS. 

Il funzionamento di DNS è complesso ma è possibile fare alcune semplici osservazioni. I nomi di dominio sono formati da due o più parole separate da un punto, ad esempio il nome di dominio "meet.google.com" che identifica un server di google che offre il servizio meet è composto da 3 parole che sono ordinate gerarchicamente. La prima parola indica la categoria del dominio ed è detto dominio di primo livello, in questo caso è com, cioè un'attività commerciale. Esistono molti domini di primo livello e alcuni come .com indicano il tipo di sito, altri come .it indicano la localizzazione geografica e linguistica. La seconda parola indica il dominio di secondo livello e indica l'organizzazione proprietaria del dispositivo e quindi del sito, in questo caso è google. Possono essere presenti altre parole che indicano una suddivisione interna del dominio, in questo caso è meet, un servizio interno a google. Si possono trovare ulteriori suddivisioni e non ci sono limiti.

Ad un nome di dominio corrisponde sempre un IP e nulla ci vieta di scriver nell'URL della risorsa a cui vogliamo accedere un indirizzo ip invece che un nome di dominio. Prova ad esempio a scrivere questo indirizzo IP: 142.250.180.164.











