---
layout: default
title: Livello 3 - Rete
nav_order: 3
parent: ISO/OSI
grand_parent: Reti
has_children: False
---

# Livello 3: Rete (Network Layer)
{: .no_toc}

_Obiettivo: rendere i livelli superiori indipendenti dai meccanismi e dalle tecnologie di trasmissione usate per la connessione e prendersi carico della consegna a destinazione dei pacchetti._

È responsabile di:

* [routing](https://it.wikipedia.org/wiki/Instradamento#Routing "Instradamento"): scelta ottimale del percorso di rete da utilizzare per garantire la consegna delle informazioni dal mittente al destinatario, scelta svolta dal [router](https://it.wikipedia.org/wiki/Router "Router") attraverso dei particolari [algoritmi di Routing](https://it.wikipedia.org/wiki/Protocolli_di_routing "Protocolli di routing") e [tabelle di routing](https://it.wikipedia.org/wiki/Routing_table "Routing table").
* conversione dei dati nel passaggio fra una rete ed un'altra con diverse caratteristiche, come il protocollo di rete utilizzato (_internet-working_). Deve, quindi:
  * tradurre gli indirizzi di rete;
  * valutare la necessità di frammentare i pacchetti dati se la nuova rete prevede una diversa dimensione dei pacchetti;
  * valutare la necessità di gestire diversi protocolli attraverso l'impiego di [gateway](https://it.wikipedia.org/wiki/Gateway_(informatica) "Gateway (informatica)").

La sua unità dati fondamentale è il _pacchetto_.

Il protocollo di rete più usato è il protocollo IP (Internet Protocol) usato in tutte le reti TCP/IP. Nella sezione dedicata al protocollo IP verranno analizzate nel dettaglio le operazioni effettuate nel livello di rete.

[Link](https://it.wikipedia.org/wiki/Livello_di_rete "Livello di rete") alla pagina wikipedia.

## Router

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/router.jfif" class="modal__opener" aprire="#img-router">
  <p>Router domestico dotato sia di porte fisiche che di antenne per il Wi-Fi</p>
</div>
<!-- modal -->
<div id="img-router" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-router">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/router.jfif">
    </div>
    <p>Router domestico dotato sia di porte fisiche che di antenne per il Wi-Fi</p>
  </div>
</div>

Un router è un dispositivo di rete di livello 3 usato per collegare sottoreti diverse e che si occupa di instradare i pacchetti fra le diverse sottoreti. Il router spesso opera anche come "gestore" di una determinata sottorete fornendo una serie di servizi agli host collegati a quella sottorete.

Mentre gli switch si occupano di collegare dispositivi all'interno di una stessa rete identificandoli per mezzo di indirizzi MAC, i router si occupano di collegare diverse reti utilizzando indirizzi di livello di rete che permettendo loro di effettuare il routing dei pacchetti tra reti differenti. Ogni protocollo di rete effettua queste operazioni in maniera differente. Nel capitolo riguardante il [protocollo IP](#) verrà trattato nel dettaglio questo argomento.

Spesso le reti sono organizzate gerarchicamente tra loro e i router sono quindi solitamente costruiti per rispettare tale ordine. Spesso quindi i router presentano una porta per la connessione alla rete "esterna" e una o più porte fisiche per i collegamenti verso la rete "interna". A volte possiedono anche antenne per fornire connessione Wi-Fi alla rete interna.


## Protocollo IP 

Internet Protocol (IP), in telecomunicazioni e informatica, è un protocollo di rete, che si occupa di indirizzamento/instradamento, appartenente alla suite di protocolli Internet TCP/IP su cui è basato il funzionamento della rete Internet.

È un protocollo di interconnessione di reti (Inter-Networking Protocol), classificato al livello di rete (3) del modello ISO/OSI, nato per interconnettere reti eterogenee per tecnologia, prestazioni, gestione, pertanto implementato sopra altri protocolli di livello collegamento, come Ethernet o ATM. È un protocollo a pacchetti senza connessione e di tipo best effort, che non garantisce cioè alcuna forma di affidabilità della comunicazione in termini di controllo di errore, controllo di flusso e controllo di congestione, che può essere invece realizzata dai protocolli di trasporto di livello superiore (livello 4), come TCP.

Correntemente sono usate due versioni del protocollo IP, l'originaria versione 4 e la più recente versione 6, nata dall'esigenza di gestire meglio il crescente numero di dispositivi (host) connessi ad Internet.

### Compiti e funzioni

Il principale compito di IP è l'Indirizzamento e l'instradamento (commutazione) tra sottoreti eterogenee, che a livello locale utilizzano invece un indirizzamento proprio, tipicamente basato sull'indirizzo fisico o indirizzo MAC e protocolli di livello datalink (2) del modello ISO-OSI (es. Ethernet, Token ring, Token bus). Per far ciò è necessario assegnare un nuovo piano di indirizzamento a cui tutte le sottoreti devono sottostare per poter comunicare e interoperare tra loro: tale piano è rappresentato proprio dal Protocollo IP. Questo comporta infatti:

- l'assegnazione a ciascun terminale che ne fa richiesta (cioè si connette alla rete Internet) di un nuovo diverso indirizzo, univocamente associato all'indirizzo MAC locale, detto Indirizzo IP (assegnato manualmente o automaticamente per mezzo del protocollo DHCP);
- la definizione delle modalità o procedure tese a individuare il percorso di rete per interconnettere due qualunque sottoreti durante una comunicazione tra host sorgente di una certa sottorete e host destinatario di un'altra sottorete, cui l'indirizzo IP appartiene. La conoscenza di questo percorso di rete comporta a sua volta l'assegnazione e la conoscenza dell'indirizzo IP a ciascun commutatore (router) che collega la rete dell'host emittente con quella dell'host destinatario, cioè quindi la conoscenza della sequenza di tutti i router di tutte le sottoreti da attraversare.

In sostanza dunque IP rappresenta la "colla" che unisce tra loro tutte le varie sottoreti eterogenee, a livello di indirizzamento\instradamento, permettendone il dialogo o scambio di informazioni tra loro cioè l'interlavoro (internetworking) o interoperabilità in fatto di trasmissione. Rimane invece compito delle singole sottoreti occuparsi di instradare al loro interno i pacchetti tramite i protocolli locali di livello 2. I pacchetti possono attraversare interamente una sottorete per dirigersi verso la successiva secondo le indicazioni del protocollo IP oppure, se si è già raggiunta la sottorete del destinatario, possono essere instradati verso l'Indirizzo MAC locale dell'host destinatario, risolvendo l'indirizzo IP dell'host in indirizzo MAC tramite protocollo ARP (Protocollo che permette di associare indirizzi MAC ad indirizzi IP). Sotto questo punto di vista (che coincide con la nascita e lo sviluppo storico di Internet) si parla comunemente di integrazione nell'architettura logico-protocollare delle sottoreti del protocollo IP.

In generale dunque l'instradamento in Internet può essere diretto (o locale) (direct forwarding) se deve essere attraversata una sola sottorete fisica cioè l'host destinatario fa parte della stessa sottorete dell'host sorgente oppure indiretto (indirect forwarding) se devono essere attraversate più di una sottorete ovvero se l'host destinatario non appartiene alla stessa sottorete dell'host sorgente. Per quanto detto precedentemente quest'ultimo tipo di indirizzamento altro non è che una successione di instradamenti diretti.

Anche se l'indirizzamento indiretto altro non è che una successione di instradamenti diretti tramite i protocolli locali di trasporto di livello 2, in generale operare un indirizzamento di livello 3 tramite i soli indirizzi MAC, pur essendo questi univoci per ciascun terminale host, non sarebbe stato possibile perché essi non danno vita ad un piano di indirizzamento gerarchico cioè gli indirizzi MAC, il cui assegnamento è pseudo-casuale, non sono raggruppabili in sottoreti con lo stesso prefisso identificativo come invece lo sono gli indirizzi Host_IP. In altri termini esisterebbero notevoli problemi di scalabilità nell'implementare tabelle di instradamento indicizzate non per identificativi di sottoreti (Net_ID), ma per ciascun indirizzo MAC esistente. Per capire meglio questo concetto è necessario comprendere struttura ed utilizzo degli indirizzi IP.

### Indirizzo IP

Un indirizzo IP è un numero (sequenza di bit che varia di lunghezza in base alla versione del protocollo) che identifica univocamente un'interfaccia di un host connessa alla rete fisica. L'indirizzo IP è assegnato propriamente all'interfaccia (ad esempio una scheda di rete) e non all'host, perché è questa ad essere connessa alla rete. Un router, ad esempio, ha diverse interfacce e per ognuna occorre un indirizzo IP. Sarebbe quindi impreciso dire che un indirizzo IP identifica univocamente un host.

Gli indirizzi IP sono indicati negli header dei pacchetti IP e sono essenziali per permettere l'instradamento dei pacchetti. Analogamente a quanto succede per un indirizzo stradale od un numero di telefono ci permettono di identificare univocamente sorgente e destinazione di una comunicazione.

L'indirizzo IP si compone di due parti: indicatore di rete (Net_ID) e indicatore di host (Host_ID); la parte Net_ID è assegnata all'ICANN che a sua volta delega organizzazioni regionali (Europa, Asia, ecc) che a loro volta delegano altre organizzazioni (per l'Italia GARR).

- La prima parte quindi identifica la rete, chiamata network o routing prefix (Net_ID) ed è utilizzato per l'instradamento a livello di sottoreti.
- La seconda parte invece identifica, all'interno della rete, l'host (o l'interfaccia in IPv6) e le eventuali sottoreti (Host_ID) ed è utilizzato per l'instradamento a livello locale dell'host una volta raggiunta la sottorete locale di destinazione, cui segue la traduzione o risoluzione in indirizzo MAC per l'effettiva consegna del pacchetto dati al destinatario con i protocolli della rete locale.

Con l'introduzione del CIDR è possibile creare sottoreti, a differenza del sistema a classi, che prevedeva il rispetto delle reti imposte con conseguente spreco di indirizzi IP.

Con lo scopo di ridurre la necessità di indirizzi IP, sono stati assegnati tre blocchi di indirizzi IP per le reti private, classe A, classe B e classe C. Se un'organizzazione decide di utilizzare uno di questi IP, non ha bisogno di coordinarsi con ICANN o con qualsiasi altro registro Internet.

### IPv4

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/Ipv4_address-it.svg" class="modal__opener" aprire="#img-ipv4">
  <p>Un esempio di indirizzo IPv4</p>
</div>
<!-- modal -->
<div id="img-ipv4" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-ipv4">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/Ipv4_address-it.svg">
    </div>
    <p>Un esempio di indirizzo IPv4</p>
  </div>
</div>


L'indirizzo IPv4 è costituito da 32 bit (4 byte) suddiviso in 4 gruppi da 8 bit (1 byte), separati ciascuno da un punto (notazione dotted, es. 11001001.00100100.10101111.00001111). Ciascuno di questi 4 byte è poi convertito in formato decimale di più facile identificazione, che semplifica la lettura e la memorizzazione da parte di noi umani, (quindi ogni numero varia tra 0 e 255 essendo 2<sup>8</sup>=256, ovvero le combinazioni disponibili ci dicono quanti numeri possiamo utilizzare in ogni gruppo identificato dal punto). Un esempio di indirizzo IPv4 è 172.16.254.1 che corrisponde a una notazione binaria.

Nello standard IPv4 (Internet Protocol versione 4), essendo costituito da 32 bit, le combinazioni utilizzabili sono 2<sup>32</sup> pari a circa 4 miliardi. All'inizio, 1981, sembravano tanti, tuttavia oggi sono pochi poiché se ognuno di noi ha diversi dispositivi connessi ad internet, questi avranno degli indirizzi IP univoci. Basti pensare che molte persone posseggono uno smartphone, un computer e una smart TV, quindi 3 indirizzi IP. Sono quindi state identificate due soluzioni: la separazione tra *indirizzi privati* e *indirizzi pubblici*, e il passaggio al protocollo IPv6 che utilizza indirizzi più lunghi (128 bit). Queste soluzioni saranno descritte nel dettaglio più avanti.



#### Indirizzi pubblici e privati

La separazione tra indirizzi privati e indirizzi pubblici è un sistema che ha permesso a IPv4 di rimanere in uso ancora oggi nonostante le iterfacce di rete che richiedono un indirizzo IP siano molte di più di 4 miliardi.

Questo sistema è basato sul riutilizzo di indirizzi IP all'interno di differenti reti private, in questo modo gli indirizzi IP sono univoci solo all'interno di una rete privata e lo spazio di indirizzamento è separato per ogni rete privata. L'indirizzo IP del dispositivo da cui stai leggendo questa pagina potrebbe quindi essere utilizzato da tante altre persone nel mondo che sono collegate a reti private diverse dalla tua.

Per poter far comunicare tra loro host appartenenti a differenti reti private in cui è quindi possibile che più di un host abbia un determinato indirizzo IP è necessario che almeno un host di ogni sottorete, solitamente un router, possieda un indirizzo IP pubblico che deve essere unico al mondo. è la presenza di questi router che permette la comunicazione tra host appartenenti a reti private diverse attuando un servizio chiamato NAT.

#### NAT

Il **network address translation** o **NAT**, ovvero traduzione degli indirizzi di rete, conosciuto anche come network masquerading, è una tecnica che consiste nel modificare gli indirizzi IP contenuti negli header dei pacchetti in transito su un sistema, solitamente un router (o un firewall ma per motivi diversi da quelli qui esposti, principalmente per la sicurezza), all'interno di una comunicazione tra due o più host.

Nel caso di comunicazione tra due host appartenenti a reti private diverse il NAT serve a fare in modo che entrambi gli host che stanno comunicando possano scrivere come IP di destinazione un indirizzo IP pubblico, quindi uivoco, che possa essere instradato correttamente tra le diverse sottoreti. Ogni host penserà di parlare con il router dell'altra sottorete, che è l'unico host di tale sottorete ad essere visibile al mondo (poichè ha un indirizzo pubbico). I router quindi devono continuamente effettuare la *traduzione degli indirizzi di rete* quando inoltrano i pacchetti all'interno della propria sottorete verso il destinatario.

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/nat.png" class="modal__opener" aprire="#img-nat">
  <p>Un esempio di comunicazione mascherata. In questo caso è l'indirizzo di A che è mascherato</p>
</div>
<!-- modal -->
<div id="img-nat" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-nat">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/nat.png">
    </div>
    <p>Un esempio di comunicazione mascherata. In questo caso è l'indirizzo di A che è mascherato</p>
  </div>
</div>

Un esempio pratico di comunicazione che richiede l'utilizzo del NAT è costituito dal computer che stai usando per leggere questa pagina che si trova in una rete privata che deve comunicare col server su cui risiede la pagina che deve essere scaricata. Nell'immagine a fianco di esempio il computer è indicato dall'host A, il router della tua rete da R e il server da B. Considera che tra R e B ci saranno tanti altri nodi appartenenti alla rete internet, così come tra A ed R è possibile che ci siano altri nodi interni alla rete locale. 

A conosce l'indirizzo di B che è pubblico e scrive nell'intestazione dei pacchetti il proprio indirizzo come mittente e l'indirizzo di B come destinatario. Quando i pacchetti arrivano a R, R modifica l'indirizzo mittente col proprio indirizzo, un indirizzo pubblico, perchè altrimenti B non sarebbe in grado di rispondere poichè l'indirizzo di A è privato e nessuno nella rete internet saprebbe a chi mandare i pacchetti oppure li manderebbero alla persona sbagliata che ha un indirizzo IP pubblico identico all'indirizzo IP privato di A. B quindi risponde indicando come destinatario R e non A. R quindi quando riceve i pacchetti da B sostituisce l'indirizzo di destinazione, che B ha indicato come R, scrivendo A e inoltrando i pacchetti verso A. Eventuali nodi interni alla rete sono quindi in grado di far arrivare i pacchetti ad A.

Si pone però un problema: un router, in questo caso R, riceve continuamente pacchetti da e verso molteplici host, come fa quindi a sapere quali pacchetti sono quelli che B sta effettivamente mandando ad A e non a qualcun'altro all'interno della stessa sottorete (o anche solamente al router stesso)? 

Per implementare il NAT, un router ha bisogno di effettuare il tracciamento delle connessioni, ovvero di tenere traccia di tutte le connessioni che lo attraversano. Per "connessione" in questo contesto si intende un flusso bidirezionale di pacchetti tra due host, identificati da particolari caratteristiche a livelli superiori a quello di rete (IP):

- nel caso di TCP è una connessione TCP in senso proprio, caratterizzata da una coppia di porte.
- nel caso di UDP, per quanto UDP sia un protocollo di trasporto senza connessione, viene considerata connessione uno scambio di pacchetti UDP tra due host che usino la stessa coppia di numeri di porta.
- altri protocolli vengono gestiti in modo analogo, usando caratteristiche del pacchetto a livelli superiori ad IP per identificare i pacchetti che appartengono ad una stessa connessione.

TCP e UDP sono sono protocolli di livello 4 e sono descritti nella pagina dedicata a tale livello.

Come precedentemente accennato il NAT è effettuato anche per motivi di sicurezza poichè effettuare la conversione degli indirizzi IP rende molto difficile per un host esterno alla rete comunicare con un host interno alla rete, di fatto proteggendo l'host interno da moltissimi attacchi dall'esterno. Per questo motivo anche i firewall spesso implementano il NAT (insieme ad una serie di altri sistemi).

### Gestione e assegnamento degli indirizzi a livello internazionale

Gli indirizzi IP pubblici e i range di indirizzi sono rilasciati e regolamentati dall'ICANN tramite una serie di organizzazioni delegate. 

La parte Net_ID degli indirizzi è assegnata dall'ICANN mentre l'assegnazione della parte Host_ID è delegata al richiedente che eventualmente può suddividerla ulteriormente per la creazione di altre sottoreti logiche (subnetting) evitando duplicazioni e sprechi di indirizzi.

Gli indirizzi IP possono essere assegnati in maniera permanente (per esempio un server che si trova sempre allo stesso indirizzo) oppure in maniera temporanea, da un intervallo di indirizzi disponibili. In particolare l'assegnazione dell'Host_Id può essere di due tipi: dinamica oppure statica. L'assegnazione dinamica è utile nel caso di dispositivi che si connettono e disconnettono frequentemente e non devono svolgere ruolo di server. Nel caso un dispositivo debba essere facilmente raggiunto da altri host, come nel caso dei server, è consigliabile un assegnamento statico in modo che l'indirizzo di tale host sia noto e sempre lo stesso (si potrebbe parzialmente risolvere il problema con un abile utilizzo dei DNS che però risulterebbe comunque facilitato e alleggerito da un assegnamento statico).

Nel tempo gli indirizzi IPv4 disponibili sono diminuiti progressivamente diventando una risosa scarsa, molto richiesta e quindi costosa. La difficile implementazione a livello globale dell'IPv6 ha portato all'introduzione di nuovi concetti, che hanno rivoluzionato la teoria e la pratica delle reti. Vanno citati l'abbandono del concetto di classi di indirizzi IP e il conseguente utilizzo sempre maggiore di indirizzi classless (privi del concetto di classe), la maschera di sottorete, la riorganizzazione gerarchica degli indirizzi mediante utilizzo massivo di NAT.

L'utilizzo di queste tecniche ha prolungato di molti anni la vita di IPv4, ma non ha risolto davvero il problema, infatti nell'autunno del 2020 sono stati venduti gli ultimi blocchi di indirizzi IP disponibili rendendo inevitabile il passaggio all'IPv6. 

### IPv6

### Impostazioni di rete fondamentali

#### Conoscere l'indirizzo in uso
Per conoscere il proprio indirizzo IP, maschera di sottorete e gateway in qualsiasi sistema operativo Unix-like (come nei sistemi Linux o in macOS) è sufficiente aprire una shell e digitare il comando ifconfig (o ipconfig, a seconda della distribuzione in uso).

Nei sistemi operativi Microsoft Windows, invece, con il comando ipconfig, dal prompt dei comandi, si possono avere le informazioni desiderate. Tale comando non è sempre già installato. Nel caso non lo fosse già, per installarlo si deve eseguire un doppio click sul file suptools.msi nella cartella \Support\Tools nel CD di installazione[7].

Mediante il ping e il traceroute (comandi del DOS, oppure programmi scritti in altri linguaggi) viene inviato un pacchetto "di prova" per misurare rispettivamente il tempo di risposta e il percorso geografico della connessione attiva.

Chi naviga utilizzando un router, usando tali comandi visualizzerà le informazioni relative alla propria rete privata. Le informazioni riguardo all'IP pubblico (assegnato al router) sono disponibili nel pannello di configurazione del router stesso oppure è possibile visualizzarlo tramite un sito apposito[8].


## Link e riferimenti esterni

- [ISO/OSI su Wikipedia](https://it.wikipedia.org/wiki/Modello_OSI)
- [Livello di rete su Wikipedia](https://it.wikipedia.org/wiki/Livello_di_rete)
- [Internet Protocol su Wikipedia](https://it.wikipedia.org/wiki/Internet_Protocol)
- [Indirizzo IP su Wikipedia](https://it.wikipedia.org/wiki/Indirizzo_IP)
- [NAT su Wikipedia](https://it.wikipedia.org/wiki/Network_address_translation)

