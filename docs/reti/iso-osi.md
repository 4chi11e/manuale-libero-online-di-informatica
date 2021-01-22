---
layout: default
title: ISO/OSI
nav_order: 1
parent: Reti
has_children: true
---

# Modello ISO/OSI

<div class="thumbnail float-right">
   <img src="{{"/assets/images/ISO-OSI_-_OSI_Model_v1.svg" | absolute_url }}" onclick="document.getElementById('img01').style.display='block'" class="hoverlink">
   <p class="fs-2">Il modello di riferimento OSI</p>
   <!--modal-->
   <div id="img01" class="w3-modal">
    <div class="w3-modal-content">
      <div class="w3-container">
        <span onclick="document.getElementById('img01').style.display='none'" class="w3-button w3-display-topright">&times;</span>
        <img src="{{"/assets/images/ISO-OSI_-_OSI_Model_v1.svg" | absolute_url }}" data-toggle="modal" data-target="#OSI_Model">
        <p>Il modello di riferimento OSI</p>
      </div>
    </div>
  </div>
</div>

Il **modello OSI** (acronimo di
[Open Systems Interconnection](https://it.wikipedia.org/wiki/Open_Systems_Interconnection "Open Systems Interconnection"),
conosciuto anche come **modello ISO/OSI**), in
[telecomunicazioni](https://it.wikipedia.org/wiki/Telecomunicazioni "Telecomunicazioni")
e
[informatica](https://it.wikipedia.org/wiki/Informatica "Informatica"),
è uno
[standard](https://it.wikipedia.org/wiki/Standard_(informatica) "Standard (informatica)")
stabilito nel [1984](https://it.wikipedia.org/wiki/1984 "1984")
dall'[International Organization for Standardization](https://it.wikipedia.org/wiki/International_Organization_for_Standardization "International Organization for Standardization")
(ISO), il principale ente di standardizzazione internazionale, il quale
sentì la necessità di avviare il progetto per la definizione di un
modello di riferimento a
[formato aperto](https://it.wikipedia.org/wiki/Formato_aperto "Formato aperto")
per l'interconnessione di sistemi di
[computer](https://it.wikipedia.org/wiki/Computer "Computer") (_Basic
Reference Model_ o standard
[ISO 7498](https://it.wikipedia.org/wiki/ISO_7498 "ISO 7498")). Tale
modello stabilisce per
l'[architettura](https://it.wikipedia.org/wiki/Architettura_di_rete "Architettura di rete")
logica di rete, una struttura a strati composta da una pila di
[protocolli di comunicazione di rete](https://it.wikipedia.org/wiki/Protocollo_di_rete "Protocollo di rete")
suddivisa in 7 livelli, seguendo un modello logico-gerarchico.

A livello implementativo lo standard _[de facto](https://it.wikipedia.org/wiki/De_facto "De facto")_ affermatosi per architetture di rete a livelli è invece il [TCP/IP](https://it.wikipedia.org/wiki/TCP/IP "TCP/IP"), che riprende in parte il modello OSI.

## Indice

{: .no_toc .text-delta }

1. TOC
{:toc}

## Caratteristiche

<div class="thumbnail float-right">
   <img src="{{"/assets/images/ISO-OSI_-_Rm-osi_parallel_it.svg" | absolute_url }}" onclick="document.getElementById('img02').style.display='block'" class="hoverlink">
   <p class="fs-2">Parallelo fra imprese (livelli superiori) e sistema postale (livelli inferiori) e il modello ISO/OSI.</p>
   <!--modal-->
   <div id="img02" class="w3-modal">
    <div class="w3-modal-content">
      <div class="w3-container">
        <span onclick="document.getElementById('img02').style.display='none'" class="w3-button w3-display-topright">&times;</span>
        <img src="{{"/assets/images/ISO-OSI_-_Rm-osi_parallel_it.svg" | absolute_url }}" data-toggle="modal" data-target="#OSI_Model">
        <p>Parallelo fra imprese (livelli superiori) e sistema postale (livelli inferiori) e il modello ISO/OSI.</p>
      </div>
    </div>
  </div>
</div>

Il modello ISO/OSI, concepito per [reti di telecomunicazioni](https://it.wikipedia.org/wiki/Rete_di_telecomunicazione "Rete di telecomunicazione") a [commutazione di pacchetto](https://it.wikipedia.org/wiki/Commutazione_di_pacchetto "Commutazione di pacchetto"), è costituito da una pila (o stack) di protocolli attraverso i quali viene ridotta la complessità implementativa di un sistema di comunicazione per il networking. In particolare ISO/OSI è costituito da strati (o livelli), i cosiddetti _**layer**_, che definiscono e racchiudono in sé a livello logico uno o più aspetti fra loro correlati della comunicazione fra due [nodi](https://it.wikipedia.org/wiki/Nodo_(informatica) "Nodo (informatica)") di una rete. I layer sono in totale 7 e vanno dal livello fisico (quello del mezzo fisico, ossia del [cavo](https://it.wikipedia.org/wiki/Cavo_elettrico "Cavo elettrico"), delle [onde radio](https://it.wikipedia.org/wiki/Onda_radio "Onda radio") o qualsiasi altro sistema trasmissivo tra cui la [fibra ottica](https://it.wikipedia.org/wiki/Fibra_ottica "Fibra ottica")) fino al livello delle applicazioni, attraverso cui si realizza la comunicazione di _alto livello_.

Ogni layer individua un protocollo di comunicazione del livello medesimo. ISO/OSI realizza una **comunicazione per livelli**, cioè dati due nodi A e B, il livello n del nodo A può scambiare [informazioni](https://it.wikipedia.org/wiki/Informazione "Informazione") col livello n del nodo B, ma non con gli altri. Ogni livello in trasmissione realizza la comunicazione col livello corrispondente sui nodi di transito o destinatari usando il [SAP](https://it.wikipedia.org/wiki/Service_Access_Point "Service Access Point") (_service access point_) del livello immediatamente sottostante. Sicché ISO/OSI [incapsula](https://it.wikipedia.org/wiki/Imbustamento "Imbustamento") i messaggi di livello n in messaggi del livello n-1\. Così se A deve inviare, ad esempio, una [e-mail](https://it.wikipedia.org/wiki/E-mail "E-mail") a B, l'applicazione (liv. 7) di A propagherà il messaggio usando il layer sottostante (liv. 6) che a sua volta userà i servizi del layer inferiore, fino ad arrivare alla comunicazione ovvero alla [trasmissione](https://it.wikipedia.org/wiki/Trasmissione_(telecomunicazioni) "Trasmissione (telecomunicazioni)") sul [canale](https://it.wikipedia.org/wiki/Canale_(telecomunicazioni) "Canale (telecomunicazioni)") o [mezzo fisico trasmissivo](https://it.wikipedia.org/wiki/Mezzo_trasmissivo "Mezzo trasmissivo").

Questa comunicazione multilivello conferisce modularità al sistema permettendo una maggiore semplicità di [progettazione](https://it.wikipedia.org/wiki/Progettazione "Progettazione") e gestione della rete e la possibilità di migliorare, sviluppare e dunque eventualmente sostituire i protocolli dei vari strati cioè [implementare](https://it.wikipedia.org/wiki/Implementazione "Implementazione") e reimplementare con dei protocolli ciascuna delle rispettive funzionalità logiche lasciando inalterate le funzioni altrui.

### Elenco e funzioni dei livelli

#### [Livello 1: fisico (Physical Layer)](https://it.wikipedia.org/wiki/Livello_fisico "Livello fisico")

_Obiettivo: trasmettere un flusso di dati non strutturati attraverso un collegamento fisico, occupandosi della forma e dei livelli di tensione del segnale. Ha a che fare con le procedure meccaniche ed elettroniche necessarie a stabilire, mantenere e disattivare un collegamento fisico._

Semplicemente: si occupa di controllare la rete, gli [hardware](https://it.wikipedia.org/wiki/Hardware "Hardware") che la compongono e i dispositivi che permettono la connessione.

In questo livello si decidono:

* Il numero di bit in un collegamento (PROB)
* Le [tensioni](https://it.wikipedia.org/wiki/Tensione_elettrica "Tensione elettrica") scelte per rappresentare i valori logici dei [bit](https://it.wikipedia.org/wiki/Bit "Bit") trasmessi;
* La durata in microsecondi del [segnale](https://it.wikipedia.org/wiki/Segnale_(fisica) "Segnale (fisica)") che identifica un bit;
* La [modulazione](https://it.wikipedia.org/wiki/Modulazione "Modulazione") e la [codifica](https://it.wikipedia.org/wiki/Codifica "Codifica") utilizzata;
* L'eventuale trasmissione simultanea in due direzioni ([Half-Duplex o Full-Duplex](https://it.wikipedia.org/wiki/Duplex "Duplex"));
* La forma e la meccanica dei [connettori](https://it.wikipedia.org/wiki/Interfaccia_video#Tipi_di_connettori "Interfaccia video") usati per collegare l'hardware al [mezzo trasmissivo](https://it.wikipedia.org/wiki/Mezzo_trasmissivo "Mezzo trasmissivo").

#### [Livello 2: collegamento dati (Datalink Layer)](https://it.wikipedia.org/wiki/Livello_di_collegamento_dati "Livello di collegamento dati")

_Obiettivo: permettere il trasferimento_ affidabile _di dati attraverso il livello fisico. Invia frame di dati con la necessaria sincronizzazione ed effettua un [controllo degli errori](https://it.wikipedia.org/wiki/Rilevazione_e_correzione_d%27errore "Rilevazione e correzione d'errore") e delle perdite di segnale. Tutto ciò consente di far apparire, al livello superiore, il mezzo fisico come una [linea di trasmissione](https://it.wikipedia.org/wiki/Linea_di_trasmissione "Linea di trasmissione") esente da errori di trasmissione._

Questo livello si occupa in primis di formare i dati da inviare attraverso il livello fisico, [incapsulando](https://it.wikipedia.org/wiki/Imbustamento "Imbustamento") il pacchetto proveniente dallo strato superiore in un nuovo [pacchetto](https://it.wikipedia.org/wiki/Pacchetto_(reti) "Pacchetto (reti)") provvisto di un nuovo _[header](https://it.wikipedia.org/wiki/Header "Header")_ (intestazione) e _tail_ (coda), usati anche per sequenze di controllo. Questa frammentazione dei dati in specifici pacchetti è detta _framing_ e i singoli pacchetti sono i _[frame](https://it.wikipedia.org/wiki/Data_frame "Data frame")_.

Come [controllo di errore](https://it.wikipedia.org/wiki/Controllo_di_errore "Controllo di errore"), per ogni pacchetto ricevuto, il destinatario invia al mittente un pacchetto **ACK** (_acknowledgement_, conferma) contenente lo stato della trasmissione: il mittente deve ripetere l'invio dei pacchetti mal trasmessi e di quelli che non hanno ricevuto riscontro/risposta. Per ottimizzare l'invio degli [ACK](https://it.wikipedia.org/wiki/ACK_(informatica) "ACK (informatica)"), si usa una tecnica detta **Piggybacking**, che consiste nell'accodare ai messaggi in uscita gli ACK relativi ad una [connessione](https://it.wikipedia.org/wiki/Connessione_(informatica) "Connessione (informatica)") in entrata, per ottimizzare l'uso del livello fisico. I pacchetti ACK possono anche essere raggruppati e mandati in blocchi.

Questo livello si occupa anche di controllare il flusso di dati ([controllo di flusso](https://it.wikipedia.org/wiki/Controllo_di_flusso "Controllo di flusso")): in caso di sbilanciamento della [velocità di trasmissione](https://it.wikipedia.org/wiki/Velocit%C3%A0_di_trasmissione "Velocità di trasmissione") tra mittente e destinatario, si occupa di rallentare l'operazione della macchina più veloce, accordandola all'altra e minimizzando così le perdite dovute a sovraccarico sul destinatario.

La sua unità dati fondamentale è il _frame_.

#### [Livello 3: rete (Network Layer)](https://it.wikipedia.org/wiki/Livello_di_rete "Livello di rete")

_Obiettivo: rendere i livelli superiori indipendenti dai meccanismi e dalle tecnologie di trasmissione usate per la connessione e prendersi carico della consegna a destinazione dei pacchetti._

È responsabile di:

* [routing](https://it.wikipedia.org/wiki/Instradamento#Routing "Instradamento"): scelta ottimale del percorso di rete da utilizzare per garantire la consegna delle informazioni dal mittente al destinatario, scelta svolta dal [router](https://it.wikipedia.org/wiki/Router "Router") attraverso dei particolari [algoritmi di Routing](https://it.wikipedia.org/wiki/Protocolli_di_routing "Protocolli di routing") e [tabelle di routing](https://it.wikipedia.org/wiki/Routing_table "Routing table").
* conversione dei dati nel passaggio fra una rete ed un'altra con diverse caratteristiche, come il protocollo di rete utilizzato (_internet-working_). Deve, quindi:
  * tradurre gli indirizzi di rete;
  * valutare la necessità di frammentare i pacchetti dati se la nuova rete ha una diversa [Maximum Transmission Unit](https://it.wikipedia.org/wiki/Maximum_Transmission_Unit "Maximum Transmission Unit") (MTU);
  * valutare la necessità di gestire diversi protocolli attraverso l'impiego di [gateway](https://it.wikipedia.org/wiki/Gateway_(informatica) "Gateway (informatica)").

La sua unità dati fondamentale è il _pacchetto_.

#### [Livello 4: trasporto (Transport Layer)](https://it.wikipedia.org/wiki/Livello_di_trasporto "Livello di trasporto")

_Obiettivo: permettere un trasferimento di dati trasparente e affidabile (implementando anche un controllo degli errori e delle perdite) tra due [host](https://it.wikipedia.org/wiki/Host "Host"). È il primo livello realmente end-to-end, cioè da host sorgente a destinatario._

Si occupa di:

* stabilire, mantenere e terminare una [connessione](https://it.wikipedia.org/wiki/Connessione_(informatica) "Connessione (informatica)"), garantendo il corretto e ottimale funzionamento della sottorete di comunicazione.
* [controllo della congestione](https://it.wikipedia.org/wiki/Controllo_della_congestione "Controllo della congestione"): evitare che troppi pacchetti dati arrivino allo stesso [router](https://it.wikipedia.org/wiki/Router "Router") contemporaneamente con effetto di perdita di pacchetti stessi.

A differenza dei livelli precedenti, che si occupano di connessioni tra nodi contigui di una rete, il Trasporto (a livello logico) si occupa solo del punto di partenza e di quello finale.

Si occupa anche di effettuare la frammentazione dei dati provenienti dal livello superiore in pacchetti, detti "_segmenti_" e trasmetterli in modo efficiente ed affidabile usando il livello rete ed isolando da questo i livelli superiori. Inoltre, si preoccupa di ottimizzare l'uso delle risorse di rete e di prevenire la congestione.

La sua unità dati fondamentale è il _messaggio di ktm_.

#### [Livello 5: sessione (Session Layer)](https://it.wikipedia.org/wiki/Livello_di_sessione "Livello di sessione")

_Obiettivo: controllare la comunicazione tra applicazioni. Instaurare, mantenere ed abbattere connessioni (sessioni) tra applicazioni cooperanti. Si occupa anche della sincronia di invio/ricezione messaggi._

Esso consente di aggiungere, ai servizi forniti dal livello di trasporto, servizi più avanzati, quali la gestione del dialogo (mono o bidirezionale), la gestione del [token](https://it.wikipedia.org/wiki/Token_(testo) "Token (testo)") (per effettuare mutua esclusione) o la sincronizzazione (inserendo dei checkpoint in modo da ridurre la quantità di dati da ritrasmettere in caso di gravi malfunzionamenti).

Si occupa anche di inserire dei punti di controllo nel flusso dati: in caso di errori nell'invio dei pacchetti, la comunicazione riprende dall'ultimo punto di controllo andato a buon fine.

#### [Livello 6: presentazione (Presentation Layer)](https://it.wikipedia.org/wiki/Livello_di_presentazione "Livello di presentazione")

_Obiettivo: trasformare i dati forniti dalle applicazioni in un formato standardizzato e offrire servizi di comunicazione comuni, come la [crittografia](https://it.wikipedia.org/wiki/Crittografia "Crittografia"), la [compressione](https://it.wikipedia.org/wiki/Compressione_dati "Compressione dati") del testo e la riformattazione._

Esso consente di gestire la sintassi dell'[informazione](https://it.wikipedia.org/wiki/Informazione "Informazione") da trasferire. E sono previste tre diverse sintassi:

* astratta (definizione formale dei dati che gli applicativi si scambiano),
* concreta locale (come i dati sono rappresentati localmente)
* di trasferimento (come i dati sono codificati durante il trasferimento).

#### [Livello 7: applicazione (Application Layer)](https://it.wikipedia.org/wiki/Livello_applicazioni "Livello applicazioni")

_Obiettivo: interfacciare utente e macchina._

Fornisce un insieme di protocolli che operano a stretto contatto con le [applicazioni](https://it.wikipedia.org/wiki/Applicazione_(informatica) "Applicazione (informatica)"). Potrebbe essere errato identificare un'applicazione utente come parte del livello applicazione.

I protocolli delle applicazioni tipiche di questo livello realizzano operazioni come ad esempio:

* Trasferimento [file](https://it.wikipedia.org/wiki/File "File")
* [Terminale virtuale](https://it.wikipedia.org/wiki/Terminale_virtuale "Terminale virtuale")
* [Posta elettronica](https://it.wikipedia.org/wiki/Posta_elettronica "Posta elettronica")

### Incapsulamento

<div class="thumbnail float-right">
   <img src="{{"/assets/images/incapsulamento.png" | absolute_url }}" onclick="document.getElementById('img03').style.display='block'" class="hoverlink">
   <p class="fs-2">Percorso dei dati e incapsulamento durante una comunicazione</p>
   <!--modal-->
   <div id="img03" class="w3-modal">
    <div class="w3-modal-content">
      <div class="w3-container">
        <span onclick="document.getElementById('img03').style.display='none'" class="w3-button w3-display-topright">&times;</span>
        <img src="{{"/assets/images/incapsulamento.png" | absolute_url }}" data-toggle="modal" data-target="#OSI_Model">
        <p>Percorso dei dati e incapsulamento durante una comunicazione</p>
      </div>
    </div>
  </div>
</div>

Formalmente l'**Iincapsulamento** (o _imbustamento_), nelle [reti di calcolatori](https://it.wikipedia.org/wiki/Reti_di_calcolatori "Reti di calcolatori"), è un termine che indica l'operazione, spesso ripetuta più volte, di inserimento di un [payload](https://it.wikipedia.org/wiki/Carico_utile_(informatica) "Carico utile (informatica)") di un certo livello N dello [strato architetturale](https://it.wikipedia.org/wiki/Architettura_di_rete "Architettura di rete") tra dati di controllo (intestazioni o [header](/wiki/Header "Header")) di livello N-1\. Il risultato è un [pacchetto](https://it.wikipedia.org/wiki/Pacchetto_(reti) "Pacchetto (reti)") di livello N-1, che diventa quindi il carico utile per il [protocollo di rete](https://it.wikipedia.org/wiki/Protocollo_di_rete "Protocollo di rete") di livello N-2, e così via.

Come esempio pratico si può pensare ad un sistema per la spedizione della posta. La busta incapsula la lettera da spedire e su di essa è scritto l'indirizzo di destinazione. A sua volta il postino terrà le buste in un contenitore che a sua volta sarà contenuto in un mezzo di trasporto.

Come mostrato nella figura a fianco, i dati che viaggiano dal livello n di un host al livello n di un altro host, scendono verso il livello fisico del primo host e ad ogni livello vengono incapsulati con l'aggiunta dell'header del livello raggiunto. A livello fisico avviene la comunicazione bit a bit del pacchetto ricevuto dal livello di collegamento, al dispositivo fisico del secondo host. Da lì i dati vengono spediti ai livelli superiori e ad ogni livello viene eliminata l'intestazione (o header) più esterno e tenuto il payload del livello raggiunto.

### Overhead

In generale in informatica la parola **overhead** (in inglese letteralmente in alto, che sta di sopra) serve per definire le risorse accessorie, richieste in sovrappiù rispetto a quelle strettamente necessarie per ottenere un determinato scopo in seguito all'introduzione di un metodo o di un processo più evoluto o più generale. Questo termine, è usato con accezioni differenti in diversi ambiti dell'informatica. Puoi approfondire [qui](https://it.wikipedia.org/wiki/Overhead) l'argomento.  

Nello specifico, parlando di reti, il termine **overhead** indica quella parte di banda di trasmissione che viene utilizzata per spedire, anziché informazione utile, dati aggiuntivi necessari per il particolare protocollo di rete utilizzato. La presenza di molteplici livelli di astrazione si traduce in un sommarsi dell'overhead imposto da ciascun livello con l'aggiunta degli **header**. A seconda della dimensione del pacchetto originale e della dimensione degli header dei vari protocolli, l'overhead potrebbe non essere affatto trascurabile.

Nelle comunicazioni tra computer l'**overhead** non è composto solo dalle intestazioni dei pacchetti, ma è costituito anche e soprattutto da tutto quel **traffico prodotto dai protocolli per coordinare la comunicazione**. Questo aspetto è così importante da determinare la scelta di un protocollo piuttosto di un altro nel caso l'overhead generato da un protocollo sia ritenuto eccessivo.

## Confronto con il TCP/IP

<div class="thumbnail float-right">
   <img src="{{"/assets/images/ISO-OSI_-_Abbinamento_ISO-OSI_e_TCP-IP.jpg" | absolute_url }}" onclick="document.getElementById('img04').style.display='block'" class="hoverlink">
   <p class="fs-2">Confronto tra ISO/OSI e TCP/IP</p>
   <!--modal-->
   <div id="img04" class="w3-modal">
    <div class="w3-modal-content">
      <div class="w3-container">
        <span onclick="document.getElementById('img04').style.display='none'" class="w3-button w3-display-topright">&times;</span>
        <img src="{{"/assets/images/ISO-OSI_-_Abbinamento_ISO-OSI_e_TCP-IP.jpg" | absolute_url }}" data-toggle="modal" data-target="#OSI_Model">
        <p>Confronto tra ISO/OSI e TCP/IP</p>
      </div>
    </div>
  </div>
</div>

_Lo stesso argomento in dettaglio: **[Suite di protocolli Internet](https://it.wikipedia.org/wiki/Suite_di_protocolli_Internet "Suite di protocolli Internet")**_.

TCP/IP è il nome comunemente usato per riferirsi ad un modello costituito da un insieme di protocolli organizzati in livelli utilizzato nella rete internet. Il suo nome deriva dai due protocolli più uitilizzati, il Transmission Control Protocol (TCP) e l'Internet Protocol (IP). Questo modello, a differenza del modello ISO/OSI, che è un modello teorico, costituisce l'evoluzione delle prime reti locali, disomogenee tra loro, che col tempo hanno avuto la necessità di unirsi gradualmente fino a formare internet. In tale processo, ISO/OSI ha costituito solo un modello teorico per TCP/IP, che conserva alcune sostanziali differenze. Le differenze principali e più evidenti sono costituite dalla riduzione del numero dei livelli adottati da 7 a 4 unificando i tre livelli superiori e i due inferiori. L'unificazione dei livelli superiori è dovuta al fatto che questo modello riguarda la gestione delle funzionalità di rete e non gli aspetti applicativi. L'unione dei due livelli inferiori ci mostra invece la concretezza di questo modello che rispecchia la necessità di unificare le funzionalità dei livelli fisico e collegamento in un unico protocollo, come nei casi dei protocolli ethernet e wifi. I livelli diventano quindi:

* **[Livello di applicazione](https://it.wikipedia.org/wiki/Livello_di_applicazione "Livello di applicazione")** con i protocolli:<br>
  [BGP](/wiki/Border_Gateway_Protocol "Border Gateway Protocol"), [DHCP](/wiki/Dynamic_Host_Configuration_Protocol "Dynamic Host Configuration Protocol"), [DNS](/wiki/Domain_Name_System "Domain Name System"), [FTP](/wiki/File_Transfer_Protocol "File Transfer Protocol"), [HTTP](/wiki/Hypertext_Transfer_Protocol "Hypertext Transfer Protocol"), [HTTPS](/wiki/HTTPS "HTTPS"), [IMAP](/wiki/Internet_Message_Access_Protocol "Internet Message Access Protocol"), [LDAP](/wiki/Lightweight_Directory_Access_Protocol "Lightweight Directory Access Protocol"), [MGCP](/wiki/Media_Gateway_Control_Protocol "Media Gateway Control Protocol"), [MQTT](/wiki/MQTT "MQTT"), [NNTP](/wiki/Network_News_Transfer_Protocol "Network News Transfer Protocol"), [NTP](/wiki/Network_Time_Protocol "Network Time Protocol"), [POP](/wiki/Post_Office_Protocol "Post Office Protocol"), [ONC/RPC](/wiki/Open_Network_Computing_Remote_Procedure_Call "Open Network Computing Remote Procedure Call"), [RTP](/wiki/Real-time_Transport_Protocol "Real-time Transport Protocol"), [RTSP](/wiki/Real_Time_Streaming_Protocol "Real Time Streaming Protocol"), [RIP](/wiki/Routing_Information_Protocol "Routing Information Protocol"), [SIP](/wiki/Session_Initiation_Protocol "Session Initiation Protocol"), [SMTP](/wiki/Simple_Mail_Transfer_Protocol "Simple Mail Transfer Protocol"), [SNMP](/wiki/Simple_Network_Management_Protocol "Simple Network Management Protocol"), [SSH](/wiki/Secure_Shell "Secure Shell"), [Telnet](/wiki/Telnet "Telnet"), [TLS/SSL](/wiki/Transport_Layer_Security "Transport Layer Security"), [XMPP](/wiki/XMPP "XMPP"), [_altri..._](/wiki/Category:Application_layer_protocols "Category:Application layer protocols")
* **[Livello di trasporto](https://it.wikipedia.org/wiki/Livello_di_trasporto "Livello di trasporto")** con i protocolli:<br>
  [TCP](/wiki/Transmission_Control_Protocol "Transmission Control Protocol"), [UDP](/wiki/User_Datagram_Protocol "User Datagram Protocol"), [DCCP](/wiki/Datagram_Congestion_Control_Protocol "Datagram Congestion Control Protocol"), [SCTP](/wiki/Stream_Control_Transmission_Protocol "Stream Control Transmission Protocol"), [RSVP](/wiki/Resource_Reservation_Protocol "Resource Reservation Protocol"), [_altri..._](/wiki/Category:Transport_layer_protocols "Category:Transport layer protocols")
* **[Livello di rete](https://it.wikipedia.org/wiki/Livello_di_rete "Livello di rete")** con i protocolli:<br>
  [IP](/wiki/Internet_Protocol "Internet Protocol") ([IPv4](/wiki/IPv4 "IPv4"), [IPv6](/wiki/IPv6 "IPv6")), [ICMP](/wiki/Internet_Control_Message_Protocol "Internet Control Message Protocol"), [ICMPv6](/wiki/Internet_Control_Message_Protocol_for_IPv6 "Internet Control Message Protocol for IPv6"), [ECN](/wiki/Explicit_Congestion_Notification "Explicit Congestion Notification"), [IGMP](/wiki/Internet_Group_Management_Protocol "Internet Group Management Protocol"), [IPsec](/wiki/IPsec "IPsec"), [_altri..._](/wiki/Category:Internet_layer_protocols "Category:Internet layer protocols")
* **[Livello di accesso alla rete](https://it.wikipedia.org/wiki/Livello_di_accesso_alla_rete "Livello di accesso alla rete")** con i protocolli:<br>
  [ARP](/wiki/Address_Resolution_Protocol "Address Resolution Protocol"), [NDP](/wiki/Neighbor_Discovery_Protocol "Neighbor Discovery Protocol"), [OSPF](/wiki/Open_Shortest_Path_First "Open Shortest Path First"), [Tunnels](/wiki/Tunneling_protocol "Tunneling protocol") ([L2TP](/wiki/Layer_2_Tunneling_Protocol "Layer 2 Tunneling Protocol")), [PPP](/wiki/Point-to-Point_Protocol "Point-to-Point Protocol"), [MAC](/wiki/Medium_access_control "Medium access control") ([Ethernet](/wiki/Ethernet "Ethernet"), [Wi-Fi](/wiki/Wi-Fi "Wi-Fi"), [DSL](/wiki/Digital_subscriber_line "Digital subscriber line"), [ISDN](/wiki/Integrated_Services_Digital_Network "Integrated Services Digital Network"), [FDDI](/wiki/Fiber_Distributed_Data_Interface "Fiber Distributed Data Interface"), [_altri..._](/wiki/Category:Link_protocols "Category:Link protocols")

<!-- versione a lista
* [Livello di applicazione](https://it.wikipedia.org/wiki/Livello_di_applicazione "Livello di applicazione") con i protocolli:
  * [BGP](/wiki/Border_Gateway_Protocol "Border Gateway Protocol")
  * [DHCP](/wiki/Dynamic_Host_Configuration_Protocol "Dynamic Host Configuration Protocol")
  * [DNS](/wiki/Domain_Name_System "Domain Name System")
  * [FTP](/wiki/File_Transfer_Protocol "File Transfer Protocol")
  * [HTTP](/wiki/Hypertext_Transfer_Protocol "Hypertext Transfer Protocol")
  * [HTTPS](/wiki/HTTPS "HTTPS")
  * [IMAP](/wiki/Internet_Message_Access_Protocol "Internet Message Access Protocol")
  * [LDAP](/wiki/Lightweight_Directory_Access_Protocol "Lightweight Directory Access Protocol")
  * [MGCP](/wiki/Media_Gateway_Control_Protocol "Media Gateway Control Protocol")
  * [MQTT](/wiki/MQTT "MQTT")
  * [NNTP](/wiki/Network_News_Transfer_Protocol "Network News Transfer Protocol")
  * [NTP](/wiki/Network_Time_Protocol "Network Time Protocol")
  * [POP](/wiki/Post_Office_Protocol "Post Office Protocol")
  * [ONC/RPC](/wiki/Open_Network_Computing_Remote_Procedure_Call "Open Network Computing Remote Procedure Call")
  * [RTP](/wiki/Real-time_Transport_Protocol "Real-time Transport Protocol")
  * [RTSP](/wiki/Real_Time_Streaming_Protocol "Real Time Streaming Protocol")
  * [RIP](/wiki/Routing_Information_Protocol "Routing Information Protocol")
  * [SIP](/wiki/Session_Initiation_Protocol "Session Initiation Protocol")
  * [SMTP](/wiki/Simple_Mail_Transfer_Protocol "Simple Mail Transfer Protocol")
  * [SNMP](/wiki/Simple_Network_Management_Protocol "Simple Network Management Protocol")
  * [SSH](/wiki/Secure_Shell "Secure Shell")
  * [Telnet](/wiki/Telnet "Telnet")
  * [TLS/SSL](/wiki/Transport_Layer_Security "Transport Layer Security")
  * [XMPP](/wiki/XMPP "XMPP")
  * [_altri..._](/wiki/Category:Application_layer_protocols "Category:Application layer protocols")
* [Livello di trasporto](https://it.wikipedia.org/wiki/Livello_di_trasporto "Livello di trasporto")
  * [TCP](/wiki/Transmission_Control_Protocol "Transmission Control Protocol")
  * [UDP](/wiki/User_Datagram_Protocol "User Datagram Protocol")
  * [DCCP](/wiki/Datagram_Congestion_Control_Protocol "Datagram Congestion Control Protocol")
  * [SCTP](/wiki/Stream_Control_Transmission_Protocol "Stream Control Transmission Protocol")
  * [RSVP](/wiki/Resource_Reservation_Protocol "Resource Reservation Protocol")
  * [_altri..._](/wiki/Category:Transport_layer_protocols "Category:Transport layer protocols")
* [Livello di rete](https://it.wikipedia.org/wiki/Livello_di_rete "Livello di rete")
  * [IP](/wiki/Internet_Protocol "Internet Protocol")
    * [IPv4](/wiki/IPv4 "IPv4")
    * [IPv6](/wiki/IPv6 "IPv6")
  * [ICMP](/wiki/Internet_Control_Message_Protocol "Internet Control Message Protocol")
  * [ICMPv6](/wiki/Internet_Control_Message_Protocol_for_IPv6 "Internet Control Message Protocol for IPv6")
  * [ECN](/wiki/Explicit_Congestion_Notification "Explicit Congestion Notification")
  * [IGMP](/wiki/Internet_Group_Management_Protocol "Internet Group Management Protocol")
  * [IPsec](/wiki/IPsec "IPsec")
  * [_altri..._](/wiki/Category:Internet_layer_protocols "Category:Internet layer protocols")
* [Livello di accesso alla rete](https://it.wikipedia.org/wiki/Livello_di_accesso_alla_rete "Livello di accesso alla rete")
  * [ARP](/wiki/Address_Resolution_Protocol "Address Resolution Protocol")
  * [NDP](/wiki/Neighbor_Discovery_Protocol "Neighbor Discovery Protocol")
  * [OSPF](/wiki/Open_Shortest_Path_First "Open Shortest Path First")
  * [Tunnels](/wiki/Tunneling_protocol "Tunneling protocol")
    * [L2TP](/wiki/Layer_2_Tunneling_Protocol "Layer 2 Tunneling Protocol")
  * [PPP](/wiki/Point-to-Point_Protocol "Point-to-Point Protocol")
  * [MAC](/wiki/Medium_access_control "Medium access control")
    * [Ethernet](/wiki/Ethernet "Ethernet")
    * [Wi-Fi](/wiki/Wi-Fi "Wi-Fi")
    * [DSL](/wiki/Digital_subscriber_line "Digital subscriber line")
    * [ISDN](/wiki/Integrated_Services_Digital_Network "Integrated Services Digital Network")
    * [FDDI](/wiki/Fiber_Distributed_Data_Interface "Fiber Distributed Data Interface")
  * [_altri..._](/wiki/Category:Link_protocols "Category:Link protocols")
-->

## Link e riferimenti esterni

* [ISO/OSI su Wikipedia](https://it.wikipedia.org/wiki/Modello_OSI)