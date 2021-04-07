---
layout: default
title: ISO/OSI
nav_order: 1
parent: Reti
has_children: false
---

# Modello ISO/OSI
{: .no_toc}

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/OSI_Model_v1-ita.png" class="modal__opener" aprire="#img-modello-ISO-OSI">
  <p>Il modello di riferimento OSI</p>
</div>
<!-- modal -->
<div id="img-modello-ISO-OSI" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-modello-ISO-OSI">&times;</span>
    <div class="modal__content__img-container--double">
      <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/OSI_Model_v1-eng.png">
      <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/OSI_Model_v1-ita.png">
    </div>
    <p>Il modello di riferimento OSI in italiano e in inglese</p>
  </div>
</div>

Il **modello OSI** (acronimo di
[Open Systems Interconnection](https://it.wikipedia.org/wiki/Open_Systems_Interconnection "Open Systems Interconnection"),
conosciuto anche come **modello ISO/OSI**), in
telecomunicazioni e informatica, è uno standard stabilito nel 1984 dall'[International Organization for Standardization](https://it.wikipedia.org/wiki/International_Organization_for_Standardization "International Organization for Standardization") (ISO), il principale ente di standardizzazione internazionale, il quale sentì la necessità di avviare il progetto per la definizione di un
modello di riferimento a formato aperto per l'interconnessione di sistemi di
computer (_Basic Reference Model_ o standard ISO 7498). Tale
modello stabilisce per l'architettura logica di rete, una struttura a strati composta da una pila di [protocolli di comunicazione di rete](https://it.wikipedia.org/wiki/Protocollo_di_rete "Protocollo di rete") suddivisa in 7 livelli, seguendo un modello logico-gerarchico.

A livello implementativo lo standard _[de facto](https://it.wikipedia.org/wiki/De_facto "De facto")_ affermatosi per architetture di rete a livelli è invece il [TCP/IP](https://it.wikipedia.org/wiki/TCP/IP "TCP/IP"), che riprende in parte il modello OSI. Nella [sezione dedicata al modello TCP/IP](#) verranno analizzati nel dettaglio i protocolli specifici utilizzati e le loro funzionalità.

## Indice
{: .no_toc .text-delta }

- TOC
{:toc}

## Caratteristiche

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/ISO-OSI-parallelo_posta.svg" class="modal__opener" aprire="#img-ISO-OSI-parallelo_posta">
  <p>Parallelo tra sistema di gestione della posta fisica e rete informatica basata sul modello ISO-OSI. Il parallelo mostra anche la divisione tra i livelli superiori e i livelli inferiori</p>
</div>
<!-- modal -->
<div id="img-ISO-OSI-parallelo_posta" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-ISO-OSI-parallelo_posta">&times;</span>
    <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/ISO-OSI-parallelo_posta.svg">
    <p>Parallelo tra sistema di gestione della posta fisica e rete informatica basata sul modello ISO-OSI. Il parallelo mostra anche la divisione tra i livelli superiori e i livelli inferiori</p>
  </div>
</div>

Il modello ISO/OSI, concepito per reti a [commutazione di pacchetto](#), è costituito da una pila (o stack) di protocolli attraverso i quali viene ridotta la complessità implementativa del sistema. In particolare ISO/OSI è costituito da  strati (o livelli), i cosiddetti _**layer**_, che definiscono e racchiudono in sé a livello logico uno o più aspetti fra loro correlati della comunicazione fra due nodi di una rete. I layer sono in totale 7 e vanno dal livello fisico, ossia quello del mezzo fisico, del cavo, delle onde radio o qualsiasi altro sistema trasmissivo tra cui la fibra ottica, fino al livello delle applicazioni, attraverso cui si realizza la comunicazione di _alto livello_. I livelli vengono anche divisi in due gruppi: i primi tre considerati _media layers_ perchè legati alla gestione dei dispositivi di rete_ e gli ultimi quattro chiamati _host layers_ perchè si occupano delle operazioni che avvengono solo sugli host.

Il modello ISO/OSI è solo un **modello astratto** che non prevede un protocollo specifico per ogni livello. Esistono invece modelli reali come ad esempio TCP/IP che specificano ad ogni livello il protocollo di comunicazione da usare. 

ISO/OSI realizza una **comunicazione per livelli**, cioè dati due nodi A e B, il livello n del nodo A può scambiare informazioni col livello n del nodo B, ma non con gli altri. Ogni livello in trasmissione realizza la comunicazione col livello corrispondente sui nodi di transito o destinatari usando i servizi offerti dal livello immediatamente sottostante. Sicché ISO/OSI **incapsula** i messaggi di livello n in messaggi del livello n-1,  così se A deve inviare, ad esempio, una e-mail a B, l'applicazione (liv. 7) di A propagherà il messaggio usando il layer sottostante (liv. 6) che a sua volta userà i servizi del layer inferiore, fino ad arrivare alla comunicazione ovvero alla trasmissione sul canale o mezzo fisico trasmissivo. Il messaggio, una volta raggiunto il computer di B a livello fisico, verrà propagato verso i livelli superiori fino a raggiungere il livello di applicazione. Possiamo quindi dire che ogni livello opera per offrire dei servizi ai livelli superiori e per farlo utilizza i servizi dei livelli inferiori, ad eccezione del livello 1 (fisico) che non ha livelli inferiori, e del livello 7 (applicazione) che offre servizi all'utente.

Questa comunicazione multilivello conferisce modularità al sistema permettendo una maggiore semplicità di progettazione e gestione della rete e la possibilità di migliorare, sviluppare o sostituire il protocollo utlizzato ad un determinato livello senza dover modificare i protocolli degli altri livelli.

Lo sviluppo di questo modello nasce negli anni '80 dalla necessità di creare un modello standard per la creazione di reti di calcolatori che proprio in quegli anni stavano vivendo la loro prima rapida diffusione. Fino a quel momento ogni sistema e quindi ogni rete era sviluppata in maniera autonoma da ogni organizzazione e ciò rendeva difficile interfacciare tra loro i diversi sistemi. ISO/OSI risolve questo problema offrendo uno standard da seguire, in particolare la divisione per livelli ha permesso di interfacciare tra loro sistemi anche molto diversi.

### Incapsulamento

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/incapsulamento.png" class="modal__opener" aprire="#img-ISO-OSI-incapsulamento">
  <p>Percorso dei dati e incapsulamento durante una comunicazione</p>
</div>
<!-- modal -->
<div id="img-ISO-OSI-incapsulamento" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-ISO-OSI-incapsulamento">&times;</span>
    <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/incapsulamento.png">
    <p>Percorso dei dati e incapsulamento durante una comunicazione</p>
  </div>
</div>

Formalmente l'**Iincapsulamento** (o _imbustamento_), nelle [reti di calcolatori](https://it.wikipedia.org/wiki/Reti_di_calcolatori "Reti di calcolatori"), è un termine che indica l'operazione, spesso ripetuta più volte, di inserimento di un [payload](https://it.wikipedia.org/wiki/Carico_utile_(informatica) "Carico utile (informatica)") di un certo livello N dello [strato architetturale](https://it.wikipedia.org/wiki/Architettura_di_rete "Architettura di rete") tra dati di controllo (intestazioni o [header](/wiki/Header "Header")) di livello N-1\. Il risultato è un [pacchetto](https://it.wikipedia.org/wiki/Pacchetto_(reti) "Pacchetto (reti)") di livello N-1, che diventa quindi il carico utile per il [protocollo di rete](https://it.wikipedia.org/wiki/Protocollo_di_rete "Protocollo di rete") di livello N-2, e così via.

Come esempio pratico si può pensare ad un sistema per la spedizione della posta. La busta incapsula la lettera da spedire e su di essa è scritto l'indirizzo di destinazione. A sua volta il postino terrà le buste in un contenitore che a sua volta sarà contenuto in un mezzo di trasporto.

Come mostrato nella figura a fianco, i dati che viaggiano dal livello n di un host al livello n di un altro host, scendono verso il livello fisico del primo host e ad ogni livello vengono incapsulati con l'aggiunta dell'header del livello raggiunto. A livello fisico avviene la comunicazione bit a bit del pacchetto ricevuto dal livello di collegamento, al dispositivo fisico del secondo host. Da lì i dati vengono spediti ai livelli superiori e ad ogni livello viene eliminata l'intestazione (o header) più esterno e tenuto il payload del livello raggiunto.

## ISO/OSI e TCP/IP

<!-- ISO/OSI è il modello teorico su cui sono state sviluppate le reti moderne. Nello sviluppo della rete internet si è però sviluppato uno standard di fatto che viene normalmente chiamata, per sineddoche, suite di protocolli TCP/IP o più brevemente modello TCP/IP. Nella [prossima sezione]({{site.baseurl}}/docs/reti/ISO-OSI/tcp-ip/) saranno analizzati nel dettaglio questa suite di protocolli e le loro funzionalità. -->

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/ISO-OSI-TCP-IP-layers.png" class="modal__opener" aprire="#ISO-OSI-TCP-IP-layers">
  <p>Il modello TCP-IP (dx) in confronto al modello ISO/OSI (sx)</p>
</div>
<!-- modal -->
<div id="ISO-OSI-TCP-IP-layers" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#ISO-OSI-TCP-IP-layers">&times;</span>
    <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/ISO-OSI-TCP-IP-layers.png">
    <p>Il modello TCP-IP (dx) in confronto al modello ISO/OSI (sx)</p>
  </div>
</div>

TCP/IP è il nome comunemente usato per riferirsi ad un modello costituito da un insieme di protocolli organizzati in livelli utilizzato nella rete internet. Il suo nome deriva dai due protocolli più uitilizzati, il Transmission Control Protocol (TCP) e l'Internet Protocol (IP). Questo modello, a differenza del modello ISO/OSI, che è un modello teorico, costituisce l'evoluzione delle prime reti locali, disomogenee tra loro, che col tempo hanno avuto la necessità di unirsi gradualmente fino a formare internet. In tale processo, ISO/OSI ha costituito solo un modello teorico per TCP/IP, che conserva alcune sostanziali differenze. Le differenze principali e più evidenti sono costituite dalla riduzione del numero dei livelli adottati da 7 a 4 unificando i tre livelli superiori e i due inferiori. L'unificazione dei livelli superiori è dovuta al fatto che questo modello riguarda la gestione delle funzionalità di rete e non gli aspetti applicativi. L'unione dei due livelli inferiori ci mostra invece la concretezza di questo modello che rispecchia la necessità di unificare le funzionalità dei livelli fisico e collegamento in un unico protocollo, come nei casi dei protocolli ethernet e wifi. 

Di seguito è riportata una lista che associa ad ogni livello della pila TCP/IP molti protocolli che operano a tale livello. Per ogni elemento è fornito un link esterno alla pagina wikipedia dedicata ad esso.

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/ISO-OSI-TCP-IP-protocolli.jpg" class="modal__opener" aprire="#ISO-OSI-TCP-IP-protocolli">
  <p>Il modello TCP-IP (dx) in confronto al modello ISO/OSI (sx)</p>
</div>
<!-- modal -->
<div id="ISO-OSI-TCP-IP-protocolli" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#ISO-OSI-TCP-IP-protocolli">&times;</span>
    <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/ISO-OSI-TCP-IP-protocolli.jpg">
    <p>Il modello TCP-IP (dx) in confronto al modello ISO/OSI (sx)</p>
  </div>
</div>

* **[Livello di applicazione](https://it.wikipedia.org/wiki/Livello_di_applicazione "Livello di applicazione")** con i protocolli:<br>
  [BGP](/wiki/Border_Gateway_Protocol "Border Gateway Protocol"), [DHCP](/wiki/Dynamic_Host_Configuration_Protocol "Dynamic Host Configuration Protocol"), [DNS](/wiki/Domain_Name_System "Domain Name System"), [FTP](/wiki/File_Transfer_Protocol "File Transfer Protocol"), [HTTP](/wiki/Hypertext_Transfer_Protocol "Hypertext Transfer Protocol"), [HTTPS](/wiki/HTTPS "HTTPS"), [IMAP](/wiki/Internet_Message_Access_Protocol "Internet Message Access Protocol"), [LDAP](/wiki/Lightweight_Directory_Access_Protocol "Lightweight Directory Access Protocol"), [MGCP](/wiki/Media_Gateway_Control_Protocol "Media Gateway Control Protocol"), [MQTT](/wiki/MQTT "MQTT"), [NNTP](/wiki/Network_News_Transfer_Protocol "Network News Transfer Protocol"), [NTP](/wiki/Network_Time_Protocol "Network Time Protocol"), [POP](/wiki/Post_Office_Protocol "Post Office Protocol"), [ONC/RPC](/wiki/Open_Network_Computing_Remote_Procedure_Call "Open Network Computing Remote Procedure Call"), [RTP](/wiki/Real-time_Transport_Protocol "Real-time Transport Protocol"), [RTSP](/wiki/Real_Time_Streaming_Protocol "Real Time Streaming Protocol"), [RIP](/wiki/Routing_Information_Protocol "Routing Information Protocol"), [SIP](/wiki/Session_Initiation_Protocol "Session Initiation Protocol"), [SMTP](/wiki/Simple_Mail_Transfer_Protocol "Simple Mail Transfer Protocol"), [SNMP](/wiki/Simple_Network_Management_Protocol "Simple Network Management Protocol"), [SSH](/wiki/Secure_Shell "Secure Shell"), [Telnet](/wiki/Telnet "Telnet"), [TLS/SSL](/wiki/Transport_Layer_Security "Transport Layer Security"), [XMPP](/wiki/XMPP "XMPP"), [_altri..._](/wiki/Category:Application_layer_protocols "Category:Application layer protocols")
* **[Livello di trasporto](https://it.wikipedia.org/wiki/Livello_di_trasporto "Livello di trasporto")** con i protocolli:<br>
  [TCP](/wiki/Transmission_Control_Protocol "Transmission Control Protocol"), [UDP](/wiki/User_Datagram_Protocol "User Datagram Protocol"), [DCCP](/wiki/Datagram_Congestion_Control_Protocol "Datagram Congestion Control Protocol"), [SCTP](/wiki/Stream_Control_Transmission_Protocol "Stream Control Transmission Protocol"), [RSVP](/wiki/Resource_Reservation_Protocol "Resource Reservation Protocol"), [_altri..._](/wiki/Category:Transport_layer_protocols "Category:Transport layer protocols")
* **[Livello di rete](https://it.wikipedia.org/wiki/Livello_di_rete "Livello di rete")** con i protocolli:<br>
  [IP](/wiki/Internet_Protocol "Internet Protocol") ([IPv4](/wiki/IPv4 "IPv4"), [IPv6](/wiki/IPv6 "IPv6")), [ICMP](/wiki/Internet_Control_Message_Protocol "Internet Control Message Protocol"), [ICMPv6](/wiki/Internet_Control_Message_Protocol_for_IPv6 "Internet Control Message Protocol for IPv6"), [ECN](/wiki/Explicit_Congestion_Notification "Explicit Congestion Notification"), [IGMP](/wiki/Internet_Group_Management_Protocol "Internet Group Management Protocol"), [IPsec](/wiki/IPsec "IPsec"), [_altri..._](/wiki/Category:Internet_layer_protocols "Category:Internet layer protocols")
* **[Livello di accesso alla rete](https://it.wikipedia.org/wiki/Livello_di_accesso_alla_rete "Livello di accesso alla rete")** con i protocolli:<br>
  [ARP](/wiki/Address_Resolution_Protocol "Address Resolution Protocol"), [NDP](/wiki/Neighbor_Discovery_Protocol "Neighbor Discovery Protocol"), [OSPF](/wiki/Open_Shortest_Path_First "Open Shortest Path First"), [Tunnels](/wiki/Tunneling_protocol "Tunneling protocol") ([L2TP](/wiki/Layer_2_Tunneling_Protocol "Layer 2 Tunneling Protocol")), [PPP](/wiki/Point-to-Point_Protocol "Point-to-Point Protocol"), [MAC](https://it.wikipedia.org/wiki/Media_Access_Control "Medium access control") ([Ethernet](/wiki/Ethernet "Ethernet"), [Wi-Fi](/wiki/Wi-Fi "Wi-Fi"), [DSL](/wiki/Digital_subscriber_line "Digital subscriber line"), [ISDN](/wiki/Integrated_Services_Digital_Network "Integrated Services Digital Network"), [FDDI](/wiki/Fiber_Distributed_Data_Interface "Fiber Distributed Data Interface"), [_altri..._](/wiki/Category:Link_protocols "Category:Link protocols")

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

[Link](https://it.wikipedia.org/wiki/Suite_di_protocolli_Internet "Suite di protocolli Internet") alla pagina wikipedia dedicata a TCP/IP.

Di seguito sono descritte le funzionalità offerte da ogni livello mantenendo la suddivisione in sette livelli del modello ISO/OSI. Per i livelli inferiori saranno anche descritti i principali dispositivi di rete che operano a tale livello. É importante sottolineare il fatto che un dispositivo di livello N opera su tutti i livelli fino al livello N poichè ogni protocollo per funzionare necessita delle funzionalità offerte dai livelli inferiori come visto nella sezione dedicata all'[incapsulamento](#incapsulamento).

## Livello 1: Fisico (Physical Layer)

_Obiettivo: trasmettere un flusso di dati non strutturati attraverso un collegamento fisico, occupandosi della forma e dei livelli di tensione del segnale. Ha a che fare con le procedure meccaniche ed elettroniche necessarie a stabilire, mantenere e disattivare un collegamento fisico._

Semplicemente: si occupa di controllare la rete, gli [hardware](https://it.wikipedia.org/wiki/Hardware "Hardware") che la compongono e i dispositivi che permettono la connessione.

In questo livello si decidono:

* Il numero di bit in un collegamento (PROB)
* Le tensioni scelte per rappresentare i valori logici dei bit trasmessi;
* La durata in microsecondi del segnale che identifica un bit;
* La [modulazione](https://it.wikipedia.org/wiki/Modulazione "Modulazione") e la [codifica](https://it.wikipedia.org/wiki/Codifica "Codifica") utilizzata;
* L'eventuale trasmissione simultanea in due direzioni Half-Duplex o Full-Duplex;
* La forma e la meccanica dei connettori usati per collegare l'hardware al mezzo trasmissivo.

I protocolli più famosi che operano a questo livello sono:
- Bluetooth
- DSL (Digital Subscriber Line)
- Ethernet (opera anche a livello 2)
- Wi-Fi (opera anche a livello 2)
- Wi-Max (opera anche a livello 2)

### Hub
<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/hub.jpg" class="modal__opener" aprire="#img-hub">
  <p>Un hub Ethernet da 4 porte.</p>
</div>
<!-- modal -->
<div id="img-hub" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-hub">&times;</span>
    <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/hub.jpg">
    <p>Un hub Ethernet da 4 porte.</p>
  </div>
</div>
L'hub è un disposivo di rete di livello fisico che funge da nodo di smistamento dati di una rete di comunicazione dati organizzata con una topologia logica a bus e di topologia fisica a stella. 

Questo dispositivo, operando a livello 1, non ha nessuna logica interna e si occupa solamente di ritrasmettere i segnali ricevuti da una porta su tutte le altre in broadcast. Per questo motivo una rete che utilizzi un hub, nonostante abbia una topologia fisica a stella con l'hub al cento, è di fatto una rete con topologia logica a bus ereditando i difetti di entrambe le topologie. Viste queste limitazioni un hub normalmente non ha un alto numero di porte.

Attualmente la tecnologia degli hub è considerata obsoleta, poiché largamente soppiantata dall'uso degli switch che, operando a livello 2, è in grado di decidere su quale porta ritrasmettere i segnali risolvendo il problema della collisioni.

[Link](https://it.wikipedia.org/wiki/Livello_fisico "Livello fisico") alla pagina wikipedia.

## Livello 2: Collegamento dati (Datalink layer)

_Obiettivo: permettere il trasferimento_ affidabile _di dati tra due nodi contigui nella rete attraverso il livello fisico. Invia frame di dati con la necessaria sincronizzazione ed effettua un [controllo degli errori](https://it.wikipedia.org/wiki/Rilevazione_e_correzione_d%27errore "Rilevazione e correzione d'errore") e delle perdite di segnale. Tutto ciò consente di far apparire, al livello superiore, il mezzo fisico come una linea di trasmissione esente da errori di trasmissione._

Questo livello si occupa in primis di formare i dati da inviare attraverso il livello fisico, [incapsulando](#incapsulamento) il pacchetto proveniente dallo strato superiore in un nuovo pacchetto provvisto di un nuovo _[header](https://it.wikipedia.org/wiki/Header "Header")_ (intestazione) e _tail_ (coda), usati anche per sequenze di controllo. Questa frammentazione dei dati in specifici pacchetti è detta _framing_ e i singoli pacchetti sono i _frame_. 

Le intestazioni contengono una serie di informazioni riguardanti il frame (detti _metadati_ ossia informazioni sui dati) che servono ai protocolli di livello 2 per gestire la trasmissione o effettuare il controllo degli errori. Due informazioni particolarmente importanti contenute negli header sono gli indirizzi di identificazione del mittente e del destinatario del frame detti _indirizzi MAC_. 

Come [controllo di errore](https://it.wikipedia.org/wiki/Controllo_di_errore "Controllo di errore"), per ogni pacchetto ricevuto, il destinatario invia al mittente un pacchetto **ACK** (_acknowledgement_, conferma) che ne conferma la corretta ricezione: il mittente deve ripetere l'invio dei pacchetti mal trasmessi e di quelli che non hanno ricevuto riscontro/risposta.

Questo livello si occupa anche di controllare il flusso di dati controllo di flusso: in caso di sbilanciamento della velocità di trasmissione tra mittente e destinatario, si occupa di rallentare l'operazione della macchina più veloce, accordandola all'altra e minimizzando così le perdite dovute a sovraccarico sul destinatario.

I protocolli più famosi che operano a questo livello sono:

- Ethernet (opera anche a livello 1)
- Wi-Fi (opera anche a livello 1)
- Point-to-Point Protocol (PPP)

[Link](https://it.wikipedia.org/wiki/Livello_di_collegamento_dati "Livello di collegamento dati") alla pagina wikipedia.

### Switch

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/switch-rack.jpg" class="modal__opener" aprire="#switch-rack">
  <p>Porzione di armadio rack contenente diversi switch a 24 porte</p>
</div>
<!-- modal -->
<div id="switch-rack" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#switch-rack">&times;</span>
    <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/switch-rack.jpg">
    <p>Porzione di armadio rack contenente diversi switch a 24 porte</p>
  </div>
</div>

Uno switch è un dispositivo di rete di livello 2, usato per collegare computer appartenenti ad una stessa rete solitamente all'interno di una stanza o di un piano di un edificio. A differenza degli hub precedentemente descritti, gli switch operano sul livello di collegamento dati (livello 2) e sono in grado di leggere nell'intestazione di ogni frame l'indirizzo MAC di destinazione e scegliere la porta corretta su cui ritrasmettere il frame. In questo modo viene creato un dominio di collisione separato per ciascuna porta dello switch cioè ogni dispositivo collegato a una porta dello switch può trasferire dati in qualsiasi momento senza che le trasmissioni interferiscano con quelle di un altro dispositivo risolvendo il cosiddetto _problema delle collisioni_. Gli switch possono quindi gestire diverse decine di collegamenti contemporaneamente (si trovano facilmente switch da 24 o 48 porte).

Essendo un dispositivo di livello 2, lo switch opera sia sul livello 1 che sul livello 2.

Spesso si trovano in commercio dispositivi che vengono definiti switch ma che in realtà offrono funzionalità di livello più alto tipiche dei router.


## Livello 3: Rete (Network Layer)
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

### Router

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/router.jfif" class="modal__opener" aprire="#router">
  <p>Router domestico dotato sia di porte fisiche che di antenne per il Wi-Fi</p>
</div>
<!-- modal -->
<div id="router" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#router">&times;</span>
    <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/router.jfif">
    <p>Router domestico dotato sia di porte fisiche che di antenne per il Wi-Fi</p>
  </div>
</div>

Un router è un dispositivo di rete di livello 3 usato per collegare sottoreti diverse e che si occupa di instradare i pacchetti fra le diverse sottoreti. Il router spesso opera anche come "gestore" di una determinata sottorete fornendo una serie di servizi agli host collegati a quella sottorete.

Mentre gli switch si occupano di collegare dispositivi all'interno di una stessa rete identificandoli per mezzo di indirizzi MAC, i router si occupano di collegare diverse reti utilizzando indirizzi di livello di rete che permettendo loro di effettuare il routing dei pacchetti tra reti differenti. Ogni protocollo di rete effettua queste operazioni in maniera differente. Nel capitolo riguardante il [protocollo IP](#) verrà trattato nel dettaglio questo argomento.

Spesso le reti sono organizzate gerarchicamente tra loro e i router sono quindi solitamente costruiti per rispettare tale ordine. Spesso quindi i router presentano una porta per la connessione alla rete "esterna" e una o più porte fisiche per i collegamenti verso la rete "interna". A volte possiedono anche antenne per fornire connessione Wi-Fi alla rete interna.

(Da fare tutta la parte sul protocollo IP)


## Livello 4: Trasporto (Transport Layer)

_Obiettivo: permettere un trasferimento di dati trasparente e affidabile (implementando anche un controllo degli errori e delle perdite) tra due host. È il primo livello realmente end-to-end, cioè da host sorgente a host destinatario._

Il livello di trasporto è il livello che separa i livelli inferiori, che si occupano della gestione della rete, dai livelli superiori i quali non si devono preoccupare della natura della rete usata per stabilire la comunicazione. Nessun dispositivo di rete opera a questo livello ma solo gli host che non si occupano di ciò che avviene nei canali di comunicazione e nei nodi lungo il percorso fatto dai pacchetti. In questo senso il livello di trasporto si occupa quindi di offrire alle applicazioni un canale di comunicazione *trasparente* (non importa cosa avviene ai livelli inferiori) e *affidabile* (ci si occupa dell'effettiva integrità dei dati).

Di seguito vengono riportati i servizi che vengono, in genere, offerti dal livello di trasporto; è bene ricordare che nessuno di tali servizi è obbligatorio. Di conseguenza, per ciascuna applicazione è possibile scegliere il protocollo più adatto allo scopo.

- *Servizio orientato alla connessione*. In genere il livello rete non stabilisce una connessione persistente verso l'host di destinazione. Il livello di trasporto si incarica, quindi, di realizzare una connessione persistente che viene poi chiusa quando non è più necessaria.
- *Corretto ordine di consegna*. Poiché i pacchetti possono seguire percorsi diversi all'interno della rete, non c'è alcuna garanzia che i dati vengano recapitati nello stesso ordine in cui sono stati inviati. Il livello di trasporto verifica che i pacchetti vengano riordinati nella giusta sequenza in ricezione prima di passarli al livello superiore.
- *Trasferimento affidabile*. Il protocollo si occupa di garantire che tutti i dati inviati vengano ricevuti; nel caso il servizio di rete utilizzato perda pacchetti, il protocollo di trasporto si occupa di ritrasmetterli al mittente sotto forma di file corrotti.
- *Controllo di flusso*. Se gli host coinvolti nella comunicazione hanno prestazioni molto differenti può capitare che un pc più veloce "inondi" di dati uno più lento portando alla perdita di pacchetti. Mediante il controllo di flusso, un host in "difficoltà" può chiedere di abbassare il tasso di trasmissione in modo da poter gestire le informazioni in ingresso.
- *Controllo di Congestione*: il protocollo riconosce uno stato di congestione della rete e adatta di conseguenza la velocità di trasmissione.
- *Orientamento al Byte*. Invece che gestire i dati in base ai pacchetti, viene fornita la possibilità di vedere la comunicazione come uno stream di byte, in modo da semplificarne l'utilizzo.
- *Multiplazione*. Il protocollo permette di stabilire diverse connessioni contemporanee tra gli stessi due host, tipicamente utilizzando l'astrazione delle porte. Nell'uso comune diversi servizi utilizzano porte logiche di comunicazione diverse.

[Link](https://it.wikipedia.org/wiki/Livello_di_trasporto "Livello di trasporto") alla pagina wikipedia dedicata al livello di trasporto.

### Le porte
Le porte sono lo strumento utilizzato per realizzare la multiplazione delle connessioni a livello di trasporto, ovvero per permettere ad un calcolatore di effettuare più connessioni contemporanee verso altri calcolatori, facendo in modo che i dati contenuti nei pacchetti in arrivo vengano indirizzati al processo che li sta aspettando. Il termine porta è mutuato direttamente da quello di porta fisica di connessione tra cavi di un calcolatore o di un qualunque altro dispositivo elettronico, ma di fatto nell'ambito della trasmissione dei dati durante una connessione non c'è altra porta fisica oltre a quella di aggancio del connettore del cavo. Nell'ambito delle reti di telecomunicazioni il termine porta indica quindi solamente una *porta virtuale* o *logica* e può essere vista banalmente come un'etichetta (label) sotto forma di numero che identifica e discrimina il traffico dati di una connessione da quello di un'altra.

Il numero di porta è indicato in TCP e UDP da una sequenza di 16 bit per cui è possibile identificare 2<sup>16</sup> = 65536 connessioni logiche differenti da o verso un determinato host. 

I numeri di porta sono raggruppati in tre diverse categorie:
- le *porte note* (well known ports) appartengono all'intervallo 0-1023 e sono fissate a specifici servizi;
- le *porte registrate* appartengono all'intervallo 1024-49151 e sono associate sotto richiesta di aziende private a servizi da loro offerti;
- le *porte libere* appartengono all'intervallo 49152-65535 e non sono associate a nessun servizio in particolare, sono quindi liberamente utilizzabili.

A questo [link](https://en.wikipedia.org/wiki/List_of_TCP_and_UDP_port_numbers) è possibile trovare l'elenco di tutte le associazioni tra porte e servizi registrate.

### Le socket
Definito il significato di porta è possibile quindi comprendere come una connessione tra due host a livello di trasporto sia definita da una coppia di valori: un indirizzo IP che identifica l'host, e un numero di porta che indica la connessione logica a quel determinato host. Quando un'applicazione vuole instaurare una connessione con un'applicazione di un altro host collegato in rete, crea una socket che è la struttura dati che identifica una specifica connessione. 

### Protocolli TCP e UDP
Nello stack protocollare Internet, i protocolli di trasporto più utilizzati sono:

- **TCP** (Transmission Control Protocol) è il più complicato fra i due e fornisce un servizio end-to-end orientato alla connessione e al byte, con verifica del corretto ordine di consegna, controllo di errore e di flusso. In pratica implementa tutte le funzionalità che il livello di trasporto può offrire. 
- **UDP** (User Datagram Protocol): è un protocollo più snello e fornisce un servizio a datagrammi, senza connessione, con un meccanismo di riduzione (non correzione) degli errori e con porte multiple. Non gestisce il riordinamento dei pacchetti né la ritrasmissione di quelli persi.

<!-- <div class="thumbnail--testo float-right mt-0 fs-4" markdown=1>
  Per **overhead** si intende tutto il traffico aggiuntivo rispetto ai soli dati che gli host vogliono scambiarsi. Questo traffico aggiuntivo è composto da:
  - tutte le intestazioni che ogni livello della pila aggiunge,
  - tutti le comunicazioni necessaria a instaurare la comunicazione
  - tutti i dati necessari a fornire controllo e correzione degli errori 
</div> -->

Entrambi i protocolli si basano su IP ma a causa delle evidenti differenze sono utilizzati in contesti completamente differenti. TCP è il protocollo più affidabile ma tutti i servizi che offre comportano un alto *overhead* della comunicazione.

Il termine overhead indica quella parte di banda di trasmissione che viene utilizzata per spedire, anziché informazione utile, dati aggiuntivi necessari per il particolare protocollo di comunicazione utilizzato. Questo traffico aggiuntivo è composto da:
- tutte le intestazioni che ogni livello della pila aggiunge;
- tutti le comunicazioni necessarie a instaurare e coordinare la comunicazione;
- tutti i dati necessari a fornire controllo e correzione degli errori.

In certi contesti avere alti livelli di overhead può essere inaccettabile. In questi contesti è quindi necessario utilizzare un protocollo come UDP che eliminando la maggior parte dei servizi offerti da TCP riduce al minimo l'overhead sacrificando l'affidabilità della comunicazione. In generale possiamo quindi dire che TCP è preferibile in quei contesti in cui è fondamentale l'integrità dei dati trasmessi (ad es. trasferimento file, posta elettronica, trasferimento pagine web...), UDP è invece preferibile in quei contesti in cui sono presenti stringenti vincoli di banda o tempo di trasmissione (servizi real time, comunicazione P2P, servizio DNS). Più avanti saranno approfonditi alcuni dei servizi qui citati e i motivi della scelta di protocollo fatta.


### Modelli di condivisione delle risorse

I modelli client server e peer to peer sono modelli di condivisione delle risorse. Sebbene esistano tra i due modelli alcune differenze anche sull'aspetto della comunicazione il punto centrale è la localizzazione delle risorse e il modo in cui vengono condivise.

#### Modello Client-Server
Nel modello client server le risorse da condividere risiedono tutte su un host definito server (in inglese servitore) che le mette a disposizione di tutti gli altri che quindi vengono definiti client (clienti). Essere client o server quindi non è una caratteristica intrinseca di un determinato host, ma solo il suo ruolo in una relazione di condivisione di risorse. Un computer può essere client per quanto riguarda un servizio e server per un altro. Esistono però alcuni computer che vengono tenuti in esecuzione con l'unico scopo di offrire un servizio e per questo vengono chiamati *server dedicati*.

Il modello client server è un modello di gestione delle risorse *centralizzato* poichè appunto accentra le risorse in un unico punto. Questa caratteristica ha il vantaggio di rendere la ricerca delle risorse molto semplice e abbastanza efficiente, ma ha anche lo svantaggio che se il server smette di condividere la risorsa per un qualsiasi motivo, la risorsa diventa totalmente irreperibile.

#### Modello Peer to Peer
Nel modello peer to peer, spesso abbreviato in P2P, le risorse non risiedono tutte su un unico server ma sono *distribuite* su host differenti. In questo modello quindi non esiste un solo computer che funge da server ma tanti host che condividono tra loro le loro risorse in una relazione tra pari (peer).

Nel modello client server la chiusura del server eliminava completamente la possibilità di reperire le risorse, in un modello distribuito invece la chiusura di un nodo della rete non influisce sul funzionamento di tutto il resto della rete, vengono perse solo le risorse presenti esclusivamente su quel nodo, eventualità comunque molto rara in una rete P2P. 

Nel modello client server le cose sono molto semplici, ai client basta conoscere l'indirizzo IP del server per reperire tutte le risorse disponibili. Nelle reti peer to peer invece le cose sono molto più complicate infatti:
- quando un peer vuole connettersi ad una rete P2P non conosce gli indirizzi dei peer che in quel momento sono collegati alla rete;
- non si sa in un determinato momento quali risorse siano condivise nella rete nè quali siano i peer che le stanno condividendo.

Per risolvere questi problemi sono state sviluppate tre architetture differenti:
1. Il P2P Puro non ha server centrale e tutti i Peer hanno lo stesso ruolo. Ogni nodo si occupa di individuare i Peer, le risorse e la condivisione di queste.
2. Il P2P con Discovery Server possiede un server centrale chiamato, appunto, Discovery, al quale l'utente (ovvero il Peer che in questo caso funge da client) comunica la propria esistenza al momento dell'avvio e riceve in risposta una lista con gli altri nomi della rete. Con essa l'utente può interrogare qualunque partecipante per conoscerne i contenuti. Quindi, quando l'utente necessita di un contenuto, prima contatta il server individualmente, poi inoltra la richiesta.
3. Il P2P con Discovery e Lookup Server: in questa architettura l'utente non solo si registra presso il Discovery Server, ma spedisce anche una lista dei propri contenuti ad intervalli regolari. Così, quando la richiesta successiva viene mandata, il server fornisce una lista dei partecipanti alla rete insieme ai relativi contenuti, tagliando richieste infruttuose e ottimizzando i tempi.

La presenza di server semplifica enormemente il coordinamento tra i peer, ma è anche un punto debole della rete poichè lo spegnimento del server compromette il funzionamento della rete. Esistono però delle reti P2P ibride in cui un certo numero di peer, detti super-nodi o super-peer che hanno anche funzione di indicizzazione.

Il funzionamento delle reti P2P ibride e soprattutto quello delle reti P2P pure è molto complesso e non è trattato in questa sede. Se desideri approfondire l'argomento puoi farlo [qui](https://it.wikipedia.org/wiki/Peer-to-peer).

è comunque importate fare un'osservazione cioè che nelle reti peer to peer, soprattutto in quelle pure, viene generata una grande quantità di traffico che serve esclusivamente a coordinare la rete e reperire le risorse. Tutto questo traffico, che potremmo far rientrare nella definizione di overhead, non è affatto trascurabile rispetto al traffico generato dal trasferimento di dati vero e proprio e può generare quello che viene definito *flooding* (allagamento in italiano) della rete. Per questo motivo il protocollo di livello 4 utilizzato nelle reti P2P per il coordinamento dei peer è il protocollo UDP che consente di minimizzare l'overhead. Per il trasferimento delle risorse che deve essere affidabile invece si utilizza TCP. 

Spesso viene associato al termine peer to peer il termine pirateria. É vero che in molti casi le reti P2P vengono usate per la condivisione di file protetti da diritto d'autore ma di per sé il peer to peer è una pratica assolutamente legittima. Il motivo per cui questo modello è quello preferito per la condivisione illegale di file è che la natura distribuita della rete ne impedisce il controllo o la censura. Mentre è molto semplice controllare ed eventualmetne spegnere un server causando la totale interruzione del servizio offerto, è praticamente impossibile chiudere una rete P2P soprattuto una pura o ibrida. 


### Livello 5: sessione (Session Layer)

_Obiettivo: controllare la comunicazione tra applicazioni. Instaurare, mantenere ed abbattere connessioni (sessioni) tra applicazioni cooperanti. Si occupa anche della sincronia di invio/ricezione messaggi. In pratica si occupa di gestire intere sessioni di comunicazione tra host._

Il livello di sessione è un livello normalmente poco studiato poichè è un livello che non offre di suo particolari servizi ma serve soprattutto a gestire i servizi offerti dal livello sottostante in modo da permettere alle applicazione di sfruttarli nella maniera desiderata. Il livello di sessione si occupa quindi di gestire le sessioni di comunicazione tra applicazioni su host diversi aprendo e chiudendo canali di comunicazione (servizio del livello 4) scegliendo opportunamente il protocollo da utilizzare (ad es. TCP o UDP) anche dinamicamente sulla base del controllo del traffico in corso.

I protocolli di livello di sessione sono tutti poco conosciuti anche perchè le funzionalità che il modello OSI colloca a questo livello sono solitamente incorporate nei protocolli di livello 7 seguendo essenzialmente il modello TCP/IP. Di seguito è comunque fornito un esempio di protocollo di livello di sessione.

L'RTP (Real-time Transfer Protocol) è un protocollo di livello di sessione utilizzato per servizi di comunicazione in tempo reale su internet. Internet offre un servizio *best-effort* e non sarebbe quindi adatto ad applicazioni real-time. Questo protocollo ottimizza i tempi di comunicazione monitorando costantemente il traffico dati e scegliendo di aprire connessioni TCP o UDP in base alle necessità. In questo modo si cerca di attenersi il più possibile ai vincoli richiesti da un'applicazione real time.

Per approfondire l'argomento è possibile consultare la [pagina wikipedia](https://it.wikipedia.org/wiki/Livello_di_sessione) dedicata al livello di sessione.




### Livello 6: presentazione (Presentation Layer)

_Obiettivo: trasformare i dati forniti dalle applicazioni in un formato standardizzato e offrire servizi di comunicazione come la [crittografia](# "Crittografia"), la [compressione](https://it.wikipedia.org/wiki/Compressione_dati "Compressione dati") e la riformattazione dei dati._

In breve questo livello si occupa di tutto ciò che riguarda la forma che devono assumere i dati prodotti dalle applicazioni prima che vengano inoltrati ai livelli inferiori per essere trasmessi nella rete.

La compressione dei dati ha un ruolo molto importante nelle comunicazioni in rete perchè permette di ridurre anche considerevolmente il traffico dati. Per poter affrontare l'argomento sarebbe necessario un approfondito studio della teoria dell'informazione che è un argomento lungo e complesso. In questa sede ci concentreremo sullo studio dei protocolli finalizzati all'ottenimento di una comunicazione sicura tramite l'uso della crittografia (argomento ampiamente trattato in [questa sezione]({{site.baseurl}}/docs/reti/crittografia/crittografia/) del manuale).

Esistono diversi protocolli che utilizzano la crittografia per instaurare comunicazioni sicure nei più svariati contesti, come ad esempio PGP o SSH. Di seguito ci concentreremo su un protocollo particolarmente importante, il TLS.

#### Transport Layer Security (TLS)

**Transport Layer Security (TLS)** e il suo predecessore **Secure Sockets Layer (SSL)** sono dei protocolli crittografici di presentazione che permettono una comunicazione sicura dalla sorgente al destinatario (end-to-end) su reti TCP/IP (come ad esempio Internet) fornendo autenticazione, integrità dei dati e confidenzialità operando al di sopra del livello di trasporto.

Diverse versioni del protocollo sono ampiamente utilizzate in applicazioni come i browser, l'e-mail, la messaggistica istantanea e il voice over IP. Un esempio di applicazione di SSL/TLS è nel protocollo HTTPS, che appunto significa HTTP over SSL.

##### Storia
Lo stack protocollare TCP/IP di Internet, diversamente dal modello ISO/OSI, non prevede di per sé funzionalità di sicurezza per motivi storici legati all'uso principale della rete ai suoi primordi (semplice scambio di dati tra ricercatori nella comunità scientifica), e solo successivamente con l'apertura della Rete a fini pubblici le problematiche di sicurezza sono diventate via via sempre più importanti da cui la necessità di inserire degli strati aggiuntivi che si occupino appunto di sicurezza.

<div id="versioni-tls-ssl" markdown=1>
  
  **Protocolli SSL e TLS**
  {: .mb-0 .pb-0 .ta-c}

  |Protocollo | Pubblicato | Status
  |-|-|-|
  |**SSL 1.0** | Non pubblicato | Non pubblicato
  |**SSL 2.0** | 1995 | Deprecato nel 2011 (RFC 6176)
  |**SSL 3.0** | 1996 | Deprecato nel 2015 (RFC 7568)
  |**TLS 1.0** | 1999 | Deprecazione pianificata per il 2020
  |**TLS 1.1** | 2006 | Deprecazione pianificata per il 2020
  |**TLS 1.2** | 2008 | |
  |**TLS 1.3** | 2018 | |

</div>

Le prime implementazioni di SSL erano limitate a cifratura a chiave simmetrica di soli 40 bit a causa delle restrizioni imposte dal governo statunitense sull'esportazione di tecnologie crittografiche, per motivi di sicurezza nazionale. In altri termini, la limitazione della dimensione delle chiavi a 40 bit è stata esplicitamente imposta per rendere la cifratura abbastanza debole da potere essere forzata (tramite l'uso di tecniche di ricerca brute force) dalle autorità giudiziarie che volessero decifrare il traffico cifrato, ma sufficientemente resistente agli attacchi da parte di entità con minori disponibilità di risorse tecnologico-finanziarie. Dopo diversi anni di controversie pubbliche, cause e l'ammissione da parte del governo statunitense di disponibilità sul mercato di prodotti per la cifratura migliori (sia all'interno che al di fuori degli Stati Uniti), alcuni aspetti delle restrizioni sono stati modificati. Le implementazioni moderne utilizzano chiavi per la cifratura simmetrica a 128 (o più) bit.

##### Funzionamento
I servizi offerti da TLS sono tre:
1. cifratura dei dati,
2. autenticazione dei partecipanti alla comunicazione,
3. controllo dell'integrità dei dati.

per poter offrire questi servizi il protocollo TLS divide la comunicazione tra host in tre fasi:

1. **Negoziazione fra le parti dell'algoritmo da utilizzare**.  
In questa fase i due host devono concordare quali algoritmi verranno utilizzati nelle fasi successive.
2. **Scambio delle chiavi e autenticazione**.  
Questa fase è quindi a sua volta divisa in due:  
> 1. utilizzo di un agoritmo di cifratura asimmetrico per effettuare uno scambio sicuro della chiave che verrà usata per il trasferimento dei dati che avverà con cifratura simmetrica che è più veloce e sicura.  
> 2. utilizzo di un algoritmo per l'autenticazione degli host. Molto spesso l'autenticazione TLS è unilaterale: è il solo server ad autenticarsi presso il client (il client, cioè, conosce l'identità del server, ma non viceversa cioè il client rimane anonimo e non autenticato sul server). Il browser valida il certificato del server controllando che la firma digitale dei certificati del server sia valida e riconosciuta da una certificate authority conosciuta utilizzando una cifratura a chiave pubblica. Nel caso di una connessione effettuata da un browser per mezzo del protocollo HTTPS, dopo questa autenticazione il browser indica una connessione sicura mostrando una specifica icona, di solito un lucchetto, di fianco all'URL. Questa fase è molto importante, basti pensare al caso in cui ci si voglia connettere al proprio servizio di home banking: è importante che il client sia sicuro di essersi connesso al giusto server e non ad un server fittizio creato per truffare i cilienti della banca.
3. **Cifratura simmetrica e autenticazione dei messaggi**.  
Questa fase consiste nella trasmissione dei dati veri e propri e ciò avviene per mezzo di un algoritmo di cifratura simmetrico che è molto più veloce e sicuro rispetto ad uno asimmetrico. In questa fase si utilizza anche una funzione crittografica di hash allo scopo di verificare che i dati ricevuti siano identici ai dati trasmessi evitando sia errori di trasmissione che eventuali manomissioni.

##### Algoritmi utilizzati
All'interno di una sessione tipicamente vengono utilizzati i seguenti protocolli:
- Per lo scambio di chiavi: [RSA]({{site.baseurl}}/docs/reti/crittografia/crittografia-moderna/#rsa), [Diffie-Hellman]({{site.baseurl}}/docs/reti/crittografia/crittografia-moderna/#lo-scambio-di-chiavi-secondo-diffie-hellman-e-merkle), ECDH, SRP, PSK (pre-shared key o chiave precondivisa)
- Per l'autenticazione: [RSA]({{site.baseurl}}/docs/reti/crittografia/crittografia-moderna/#rsa), DSA, ECDSA
- Per la cifratura simmetrica: [RC4]({{site.baseurl}}/docs/reti/crittografia/crittografia-moderna/#rc4), [DES]({{site.baseurl}}/docs/reti/crittografia/crittografia-moderna/#des-data-encryption-standard), [Triple DES]({{site.baseurl}}/docs/reti/crittografia/crittografia-moderna/#3des-triple-des), [AES]({{site.baseurl}}/docs/reti/crittografia/crittografia-moderna/#aes-advanced-encryption-standard) (Attualmente questo è il più utilizzato e consigliato), IDEA o Camellia.
- Per le funzioni crittografiche d'integrità si usano usualmente funzioni di hash: in TLS sono utilizzati [HMAC-MD5](https://it.wikipedia.org/wiki/HMAC) o [HMAC-SHA](https://it.wikipedia.org/wiki/HMAC) (sistema che utilizza gli algoritmi di hash visti [qui]({{site.baseurl}}/docs/reti/crittografia/crittografia-moderna/#algoritmi-di-hash-crittografico) aggiungendo funzionalità e sicurezza aggiuntive)

Puoi approfondire l'argomento alla [pagina](https://en.wikipedia.org/wiki/Transport_Layer_Security) di wikipedia dedicata a TLS.



### Livello 7: applicazione (Application Layer) - ANCORA DA SCRIVERE

_Obiettivo: interfacciare utente e macchina._

Fornisce un insieme di protocolli che operano a stretto contatto con le [applicazioni](https://it.wikipedia.org/wiki/Applicazione_(informatica) "Applicazione (informatica)"). Potrebbe essere errato identificare un'applicazione utente come parte del livello applicazione.

I protocolli delle applicazioni tipiche di questo livello realizzano operazioni come ad esempio:

* Trasferimento [file](https://it.wikipedia.org/wiki/File "File")
* [Terminale virtuale](https://it.wikipedia.org/wiki/Terminale_virtuale "Terminale virtuale")
* [Posta elettronica](https://it.wikipedia.org/wiki/Posta_elettronica "Posta elettronica")


## Link e riferimenti esterni

* [ISO/OSI su Wikipedia](https://it.wikipedia.org/wiki/Modello_OSI)