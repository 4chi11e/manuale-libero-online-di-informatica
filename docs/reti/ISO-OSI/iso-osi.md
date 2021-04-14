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
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/ISO-OSI-parallelo_posta.svg">
    </div>
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
  <p>Percorso dei dati e incapsulamento durante una comunicazione.</p>
</div>
<!-- modal -->
<div id="img-ISO-OSI-incapsulamento" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-ISO-OSI-incapsulamento">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/incapsulamento.png">
    </div>
    <p>Percorso dei dati e incapsulamento durante una comunicazione.</p>
    <p>Sul lato sinistro è indicato il percorso dei dati dal livello 7 al livello 1 durante il quale ai dati vengono aggiunti ad ogni livello le intestazioni del livello (ad es. AH, application header, al livello 7, poi PH, presentation header, al livello 6..., al livello datalink si aggiunge anche un tail). Sul lato destro è mostrato il percorso inverso durante il quale vengono "spacchettati" i dati ad ogni livello</p>
  </div>
</div>

Formalmente l'**Iincapsulamento** (o _imbustamento_), nelle [reti di calcolatori](https://it.wikipedia.org/wiki/Reti_di_calcolatori "Reti di calcolatori"), è un termine che indica l'operazione, spesso ripetuta più volte, di inserimento di un [payload](https://it.wikipedia.org/wiki/Carico_utile_(informatica) "Carico utile (informatica)") di un certo livello N dello [strato architetturale](https://it.wikipedia.org/wiki/Architettura_di_rete "Architettura di rete") tra dati di controllo (intestazioni o [header](/wiki/Header "Header")) di livello N-1\. Il risultato è un [pacchetto](https://it.wikipedia.org/wiki/Pacchetto_(reti) "Pacchetto (reti)") di livello N-1, che diventa quindi il carico utile per il [protocollo di rete](https://it.wikipedia.org/wiki/Protocollo_di_rete "Protocollo di rete") di livello N-2, e così via.

Come esempio pratico si può pensare ad un sistema per la spedizione della posta. La busta incapsula la lettera da spedire e su di essa è scritto l'indirizzo di destinazione. A sua volta il postino terrà le buste in un contenitore che a sua volta sarà contenuto in un mezzo di trasporto.

Come mostrato nella figura a fianco, i dati che viaggiano dal livello n di un host al livello n di un altro host, scendono verso il livello fisico del primo host e ad ogni livello vengono incapsulati con l'aggiunta dell'header del livello raggiunto. A livello fisico avviene la comunicazione bit a bit del pacchetto ricevuto dal livello di collegamento, al dispositivo fisico del secondo host. Da lì i dati vengono spediti ai livelli superiori e ad ogni livello viene eliminata l'intestazione (o header) più esterno e tenuto il payload del livello raggiunto.

## ISO/OSI e TCP/IP

<!-- ISO/OSI è il modello teorico su cui sono state sviluppate le reti moderne. Nello sviluppo della rete internet si è però sviluppato uno standard di fatto che viene normalmente chiamata, per sineddoche, suite di protocolli TCP/IP o più brevemente modello TCP/IP. Nella [prossima sezione]({{site.baseurl}}/docs/reti/ISO-OSI/tcp-ip/) saranno analizzati nel dettaglio questa suite di protocolli e le loro funzionalità. -->

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/ISO-OSI-TCP-IP-layers.png" class="modal__opener" aprire="#img-ISO-OSI-TCP-IP-layers">
  <p>Il modello TCP-IP (dx) in confronto al modello ISO/OSI (sx)</p>
</div>
<!-- modal -->
<div id="img-ISO-OSI-TCP-IP-layers" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-ISO-OSI-TCP-IP-layers">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/ISO-OSI-TCP-IP-layers.png">
    </div>
    <p>Il modello TCP-IP (dx) in confronto al modello ISO/OSI (sx)</p>
  </div>
</div>

TCP/IP è il nome comunemente usato per riferirsi ad un modello costituito da un insieme di protocolli organizzati in livelli utilizzato nella rete internet. Il suo nome deriva dai due protocolli più uitilizzati, il Transmission Control Protocol (TCP) e l'Internet Protocol (IP). Questo modello, a differenza del modello ISO/OSI, che è un modello teorico, costituisce l'evoluzione delle prime reti locali, disomogenee tra loro, che col tempo hanno avuto la necessità di unirsi gradualmente fino a formare internet. In tale processo, ISO/OSI ha costituito solo un modello teorico per TCP/IP, che conserva alcune sostanziali differenze. Le differenze principali e più evidenti sono costituite dalla riduzione del numero dei livelli adottati da 7 a 4 unificando i tre livelli superiori e i due inferiori. L'unificazione dei livelli superiori è dovuta al fatto che questo modello riguarda la gestione delle funzionalità di rete e non gli aspetti applicativi. L'unione dei due livelli inferiori ci mostra invece la concretezza di questo modello che rispecchia la necessità di unificare le funzionalità dei livelli fisico e collegamento in un unico protocollo, come nei casi dei protocolli ethernet e wifi. 

Di seguito è riportata una lista che associa ad ogni livello della pila TCP/IP molti protocolli che operano a tale livello. Per ogni elemento è fornito un link esterno alla pagina wikipedia dedicata ad esso.

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/ISO-OSI-TCP-IP-protocolli.jpg" class="modal__opener" aprire="#img-ISO-OSI-TCP-IP-protocolli">
  <p>Il modello TCP-IP (dx) in confronto al modello ISO/OSI (sx)</p>
</div>
<!-- modal -->
<div id="img-ISO-OSI-TCP-IP-protocolli" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-ISO-OSI-TCP-IP-protocolli">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/ISO-OSI-TCP-IP-protocolli.jpg">
    </div>
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
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/hub.jpg">
    </div>
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
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/switch-rack.jpg" class="modal__opener" aprire="#img-switch-rack">
  <p>Porzione di armadio rack contenente diversi switch a 24 porte</p>
</div>
<!-- modal -->
<div id="img-switch-rack" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-switch-rack">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/switch-rack.jpg">
    </div>
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



### Livello 7: applicazione (Application Layer) - ANCORA DA FINIRE

_Obiettivo: permettere alle applicazioni di comunicare con applicazioni in esecuzione su un altro host._

Il livello 7 prende il nome di "applicazione" poichè fornisce alle applicazioni i protocolli necessari alla comunicazione con applicazioni che sono eseguite su altri host. Non bisogna quindi confondere applicazioni e protocolli utilizzati. 

Esistono moltissimi protocolli utilizzati dalle applicazioni per svolgere svariati compiti come: trasferimento file, terminale virtuale, posta elettronica, risoluzione di nomi di dominio...

Prima di trattare nello specifico le funzionalità offerte dai vari protocolli è necessario conoscere alcuni aspetti generali della comunicazione a livello applicazione.

#### URI e URL
lo Uniform Resource Identifier (in acronimo URI) è una sequenza di caratteri che identifica universalmente ed univocamente una risorsa. Un URI può essere classificato come qualcosa che definisce posizioni (URL) o nomi (URN) o entrambi.

Un __URN__ (Uniform Resource Name) è un URI che identifica una risorsa mediante un "nome" in un particolare dominio di nomi ("namespace"). Un URN può quindi essere usato per identificare una risorsa, senza lasciarne intendere l'ubicazione o come ottenerne una rappresentazione. Per esempio l'URN urn:isbn:0-395-36341-1 è un URI che mappa universalmente e univocamente un libro mediante il suo identificativo, o nome, (0-395-36341-1) nel namespace dei codici ISBN, ma non suggerisce dove e come possiamo ottenere una copia di tale libro. Si noti che, da RFC8141, un URN è un URI assegnata sotto lo schema URI "urn".

Un __URL__ (Uniform Resource Locator) è un URI che identifica una risorsa tramite la sua "collocazione" ("location"). Di fatto, non identifica la risorsa per nome, ma con il modo con cui la si può reperire. Per esempio, l'URL http://www.example.com/ è un URI che identifica una risorsa (l'home page di un sito web) e lascia intendere che una rappresentazione di tale risorsa (il codice HTML della versione corrente di tale home page) è ottenibile via HTTP da un host di rete chiamato www.example.com.

Lo schema completo di una URL è del tipo (non tutte le componenti sono obbligatorie):

`<scheme>://<domain>:<port>/<path>?<querystring>#<fragmentid>`

esempi di url sono:

- ftp://ftp.is.co.za/rfc/rfc1808.txt  -  schema per servizi FTP
- http://www.math.uio.no/faq/compression-faq/part1.html  -  schema per servizi HTTP
- file://C:/Folder1/SubFolder2/file%20text.txt  -  schema per un file nel file system locale
- mailto:mduerst@ifi.unizh.ch - schema per indirizzi di posta elettronica
- news:comp.infosystems.www.servers.unix - schema per newsgroup e articoli Usenet
- telnet://melvyl.ucop.edu/ - schema per servizi interattivi telnet
- irc://irc.freenode.net/wikipedia-it - schema per IRC
- spotify:artist:6wWVKhxIU2cEi0K81v7HvP - schema per brani su Spotify
- usb://Samsung/SCX-4x21%20Series?serial=8P36BADL316673B.&interface=1 - Esempio di stampante in ambiente Linux

I protocolli di livello applicazione usano normalmente gli URL, ma è stato detto in precedenza che per creare un canale di comunicazione tra due host si crea una socket che è formata da indirizzo IP e porta. In questo caso l'indirizzo IP non è indicato, si identifica invece l'host contenente la risorsa per mezzo di un _nome di dominio_, indicato nella struttura dell'url come _domain_. Per instaurare una comunicazione è necessario quindi l'utilizzo di un servizio che converta i nomi di dominio in indirizzi IP, questo servizio è il Domain Name System (DNS).

#### DNS
{: .titolo-3}

il sistema dei nomi di dominio (in inglese: Domain Name System, DNS), è un sistema utilizzato per assegnare nomi ai nodi della rete (host). Questi nomi sono utilizzabili, mediante una traduzione, di solito chiamata "risoluzione", al posto degli indirizzi IP originali. Il servizio è realizzato tramite un database distribuito, costituito dai server DNS. Il DNS ha una struttura gerarchica ad albero rovesciato ed è diviso in domini (com, org, it, ecc.). Ad ogni dominio o nodo corrisponde un nameserver, che conserva un database con le informazioni di alcuni domini di cui è responsabile e si rivolge ai nodi successivi quando deve trovare informazioni che appartengono ad altri domini.

Ogni nome di dominio termina con un "." (punto). Ad esempio l'indirizzo wikipedia.org termina con il punto. La stringa che segue il punto finale è chiamata "dominio radice" (DNS root zone). I server responsabili del dominio radice sono i cosiddetti root nameservers. Essi possiedono l'elenco dei server autoritativi di tutti i domini di primo livello (TLD) riconosciuti e lo forniscono in risposta a ciascuna richiesta. I root nameserver sono 13 in tutto il mondo, di cui 10 negli Stati Uniti, due in Europa (Inghilterra e Svezia) e uno in Giappone.

##### Storia
{: .no_toc}

Il DNS fu ideato il 23 giugno 1983 da Paul Mockapetris, Jon Postel e Craig Partridge; le specifiche originali sono descritte nello standard RFC 882. Nel 1987 vennero pubblicati commenti allo standard RFC del DNS, con i nomi RFC 1034 e RFC 1035 rendendo obsolete le specifiche precedenti.

##### Descrizione
{: .no_toc}

Il nome DNS denota anche il protocollo di livello 7 che regola il funzionamento del servizio, i programmi che lo implementano, i server su cui questi vengono elaborati, l'insieme di questi server che cooperano per fornire il servizio più intelligente.

I nomi DNS, o "nomi di dominio" o "indirizzi mnemonici", sono una delle caratteristiche più visibili di Internet. L'operazione di conversione da nome a indirizzo IP è detta "risoluzione DNS"; la conversione da indirizzo IP a nome è detta "risoluzione inversa".

In pratica, il DNS è un registro universale cioè un database distribuito, con una struttura gerarchica, che archivia i nomi mnemonici di dominio e la loro associazione ai relativi indirizzi IP specifici.

###### Motivazioni ed utilizzi
{: .no_toc}

- La possibilità di attribuire un nome testuale facile da memorizzare a un server (ad esempio un sito world wide web) migliora di molto l'uso del servizio, in quanto gli esseri umani trovano più facile ricordare nomi testuali (mentre gli host e i router sono raggiungibili utilizzando gli indirizzi IP numerici). Per questo, il DNS è fondamentale per l'ampia diffusione di internet anche tra utenti non tecnici, ed è una delle sue caratteristiche più visibili.
- È possibile attribuire più nomi allo stesso indirizzo IP (o viceversa) per rappresentare diversi servizi o funzioni forniti da uno stesso host (o più host che erogano lo stesso servizio). Questa "flessibilità" risulta utile in molti casi:
> - Nel caso in cui si debba sostituire il server che ospita un servizio, o si debba modificare il suo indirizzo IP, è sufficiente modificare il record DNS, senza dover intervenire sui client.
> - Utilizzando nomi diversi per riferirsi ai diversi servizi erogati da uno stesso host (registrati quindi con lo stesso indirizzo IP), è possibile spostare una parte dei servizi su un altro host (con diverso indirizzo IP, già predisposto a fornire i servizi in oggetto). Modificando quindi sul server DNS i record dei nomi associati ai servizi da spostare e registrando il nuovo IP al posto di quello vecchio, si otterrà lo spostamento automatico delle nuove richieste di tutti i client su questo nuovo host, senza interruzione dei servizi.
> - Un utilizzo molto popolare di questa possibilità è il cosiddetto virtual hosting, basato sui nomi, una tecnica per cui un web server dotato di una singola interfaccia di rete e di singolo indirizzo IP può ospitare più siti web, usando l'indirizzo alfanumerico trasmesso nell'header HTTP per identificare il sito per cui viene fatta la richiesta.
> - Facendo corrispondere a un nome più indirizzi IP, il carico dei client che richiedono quel nome viene distribuito sui diversi server associati agli IP registrati, ottenendo un aumento delle prestazioni complessive del servizio e una tolleranza ai guasti (ma è necessario assicurarsi che i diversi server siano sempre allineati, ovvero offrano esattamente lo stesso servizio ai client).
- La risoluzione inversa è utile per identificare l'identità di un host, o per leggere il risultato di un traceroute.
- Il DNS viene usato da numerose tecnologie in modo poco visibile agli utenti, per organizzare le informazioni necessarie al funzionamento del servizio.

###### Nomi di dominio
{: .no_toc}

Un nome di dominio è costituito da una serie di stringhe separate da punti, ad esempio it.wikipedia.org. e sono organizzati a livelli. A differenza degli indirizzi IP, dove la parte più importante del numero è la prima cifra partendo da sinistra, in un nome DNS la parte più importante è la prima partendo da destra.

La parte più a destra è detta dominio di primo livello (o TLD, Top Level Domain), e ce ne sono centinaia che possono essere scelti, per esempio .org o .it.

Un dominio di secondo livello, a differenza del dominio di primo livello che è formato da parole "fisse" e limitate, è formato da una parola scelta a piacimento. Questa parola deve il più possibile essere legata a quello che ci identifica e a quello che vogliamo comunicare. Il dominio di secondo livello è quindi formato da due parti, per esempio wikipedia.org, e così via.

Il dominio di terzo livello è il figlio del dominio di secondo livello, infatti, prendendo come esempio wikipedia.org, un dominio di terzo livello sarà: stuff.wikipedia.org. Ogni ulteriore elemento specifica quindi un'ulteriore suddivisione. Quando un dominio di secondo livello viene registrato all'assegnatario, questo è autorizzato a usare i nomi di dominio relativi ai successivi livelli, come some.other.stuff.wikipedia.org (dominio di quinto livello) e così via.

Un nome di dominio, come per esempio it.wikipedia.org, può essere parte di un URL, come http://it.wikipedia.org/wiki/Treno, o di un indirizzo e-mail, come per esempio apache@it.wikipedia.org. È anche possibile connettersi a un sito con il protocollo telnet oppure usare una connessione FTP usando il suo nome a dominio.

###### Sistema DNS in Internet
{: .no_toc}

Qualsiasi rete IP può usare il DNS per implementare un suo sistema di nomi privato. Tuttavia, il termine "nome di dominio" è più comunemente utilizzato quando esso si riferisce al sistema pubblico dei DNS su Internet. Il sistema del DNS è organizzato in modo gerarchico secondo quello che viene chiamato un _albero rovesciato_. 

In cima alla gerarchia si trovano 13 server universali detti _root server_ i quali devono conoscere almeno le collocazioni di tutti nameserver di primo livello. I root server hanno nomi di dominio che vanno da a.root-servers.net a m.rootservers.net e i loro IP sono noti ([qui](https://it.wikipedia.org/wiki/Root_nameserver#Elenco_dei_root_nameserver) puoi trovare la lista oltre ad altri approfondimenti).

I server di primo livello si occupano di gestire i nomi di dominio che competono loro, esisteranno quindi uno o più server di primo livello che gestiscono il dominio .com altri che gestiscono il dominio .it...

Esistono poi altri server ad un livello inferiore che gestiscono i vari domini registrati. In alcuni casi ad un dominio di secondo livello corrisponde un server DNS che gestisce quel dominio compreso tutti i nomi di livello successivo ad esso associati. In molti casi invece i nomi di dominio sono registrati presso server che gestiscono un gran numero di nomi di dominio come ad esempio Aruba, AWS...

Ogni volta che un host vuole risolvere un nome di dominio di cui non conosca già l'IP corrispondente, interroga un server DNS o nameserver a sua scelta, il quale, se conosce la risposta, la manda all'host. Quando un nameserver riceve una interrogazione a cui non sa dare risposta, ha due possibilità, se la domanda riguarda un sottodominio del dominio da lui gestito, passa la domanda al nameserver di competenza (ad es. se viene chiesto al nameserver responsabile del dominio .org di risolvere wikipedia.org, la domanda viene passata al nameserver di livello inferiore che gestisce il dominio wikipedia), se invece l'interrogazione riguarda un altro dominio, il nameserver passa la domanda ad un superiore (ad es. se viene chiesto al nameserver responsabile del dominio .it di risolvere wikipedia.org la domanda _dovrebbe_ essere passata al rootserver).

La struttura gerarchica ad albero del sistema DNS permette in un numero limitato di passaggi di raggiungere il server competente per lo specifico nome richiesto. 

Teoricamente per arrivare ad ogni spazio di dominio si dovrebbe passare spesso dai rootserver che però sono pochi per riuscire a servire continuamente tutti gli host del mondo. Nella pratica però la maggior parte delle informazioni fornite dai root nameserver non cambia molto spesso e viene memorizzata in varie cache (memoria temporanea) da una gerarchia di server DNS cui si rivolgono i singoli computer prima di interrogare i nameserver principali; anzi, quando viene fatta una richiesta di informazioni la risposta contiene anche l'informazione su per quanto tempo essa può essere ritenuta valida, proprio per rendere le richieste di risoluzione DNS ai root nameserver relativamente rare.

Esistono alcuni nameserver che non gestiscono uno spazio di dominio particolare ma per motivi vari (analisi del traffico dati per scopi privati?) offrono gratuitamente il servizio DNS aggiungendo in alcuni casi anche altri servizi come ad esempio il blocco di siti pericolosi. [Qui](https://www.worldcomputing.it/computer/internet/44-elenco-migliori-veloci-affidabili-server-dns-pubblici-gratuiti.html) puoi trovare un articolo che descrive 12 diversi DNS pubblici.


#### HTTP
{: .titolo-3}

HTTP (HyperText Transfer Protocol - protocollo di trasferimento di un ipertesto) è un protocollo a livello applicativo usato come principale sistema per la trasmissione d'informazioni sul web in una architettura client-server. Le specifiche del protocollo sono gestite dal World Wide Web Consortium (W3C). Un server HTTP generalmente resta in ascolto delle richieste dei client sulla porta 80 usando il protocollo TCP a livello di trasporto.

##### Storia
{: .no_toc}

La prima versione dell'HTTP, la 0.9, risale alla fine degli anni 1980 e costituiva, insieme con il linguaggio HTML e gli URL, il nucleo base del World Wide Web (WWW) sviluppata da Tim Berners-Lee al CERN di Ginevra per la condivisione delle informazioni tra la comunità dei fisici delle alte energie. Prima di HTTP il protocollo di riferimento per tali scopi era il più semplice e leggero FTP. La prima versione effettivamente disponibile del protocollo, la HTTP/1.0, venne implementata dallo stesso Berners-Lee nel 1991 e riconosciuta come standard nel 1996.

Negli anni il WWW conobbe un successo crescente e divennero evidenti alcuni limiti della versione 1.0 del protocollo, in particolare:

- l'impossibilità di ospitare più siti web sullo stesso server ([virtual hosting](https://it.wikipedia.org/wiki/Virtual_hosting), argomento interessante ma complesso, non lo tratteremo);
- il mancato riuso delle connessioni disponibili;
- l'insufficienza dei meccanismi di sicurezza.

Per far fronte ai primi due problemi il protocollo venne aggiornato alla versione 1.1 nel 1999 (e poi alla 2.0 nel 2014). Per risolvere i problemi di sicurezza è stato sviluppato invece HTTPS che sfrutta protocolli crittografici a livello di presentazione.

##### Funzionamento
{: .no_toc}

L'HTTP è un protocollo che lavora con un'architettura di tipo client/server: il client esegue una richiesta e il server restituisce la risposta mandata da un altro host. Nell'uso comune il client corrisponde al browser ed il server la macchina su cui risiede il sito web. Vi sono quindi due tipi di messaggi HTTP: messaggi richiesta e messaggi risposta.

<!-- thumbnail -->
<div class="thumbnail--50 float-right">
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/http-request-response.png" class="modal__opener" aprire="#img-http-request-response">
  <p>Schema di funzionamento di una richiesta di risorsa (una pagina web) da parte di un browser (client) e conseguente risposta di un server HTTP</p>
</div>
<!-- modal -->
<div id="img-http-request-response" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-http-request-response">&times;</span>
    <div class="modal__content__img-container"> 
      <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/http-request-response.png">
    </div>
    <p>Schema di funzionamento di una richiesta di risorsa (una pagina web) da parte di un browser (client) e conseguente risposta di un server HTTP</p>
  </div>
</div>

HTTP differisce da altri protocolli di livello 7 come FTP, per il fatto che le connessioni vengono generalmente chiuse una volta che una particolare richiesta (o una serie di richieste correlate) è stata soddisfatta. Questo comportamento rende il protocollo HTTP ideale per il World Wide Web, in cui le pagine molto spesso contengono dei collegamenti (link) a pagine ospitate da altri server diminuendo così il numero di connessioni attive limitandole a quelle effettivamente necessarie con aumento quindi di efficienza (minor carico e occupazione) sia sul client che sul server. Talvolta però pone problemi agli sviluppatori di contenuti web, perché la natura senza stato (_stateless_) della sessione di navigazione costringe ad utilizzare dei metodi alternativi - tipicamente basati sui [cookie](#cookies) - per conservare lo stato dell'utente.

###### Messaggio di richiesta
{: .no_toc}

Il messaggio di richiesta è composto di quattro parti:

    GET /wiki/Pagina_principale HTTP/1.1  
    Host: it.wikipedia.org  
    User-Agent: Mozilla/5.0 (compatible; Konqueror/3.2; Linux) (KHTML, like Gecko)  
    Accept: text/html, image/jpeg, image/png, text/*, image/*, */*  
    Accept-Charset: iso-8859-1, utf-8;q=0.5, *;q=0.5  
    Accept-Language: it  
    Connection: Keep-Alive

- riga di richiesta (request line): che a sua volta è composta da:  
> - metodo (i primi tre dei seguenti metodi sono i più importanti e usati)
>> - GET: usato per richiedere una risorsa, è possibile aggiungere parametri all'url
>> - POST: usato per inviare al server una serie di coppie di valori *name=value* usate come input per la risorsa richiesta indicata dall'URL
>> - HEAD: simile a get ma richiede come risposta solo l'header e non il body, allo scopo di avere solo informazioni sulla risorsa, di solito per testare accessibilità alla risorsa o scoprire se sono disponibili modifiche dall'ultima richiesta
>> - PUT:
>> - DELETE: 
>> - PATCH
>> - TRACE
>> - OPTIONS
>> - CONNECT
> - URL
> - Versione del protocollo
- sezione header (informazioni aggiuntive), i più comuni sono:
> - Host: nome del server a cui si riferisce l'URL; è obbligatorio nelle richieste conformi HTTP/1.1 perché permette l'uso dei virtual host basati sui nomi.
> - User-Agent: identificazione del tipo di client: tipo browser, produttore, versione...
> - Cookie: utilizzati dalle applicazioni web per archiviare e recuperare informazioni a lungo termine sul lato client; spesso usati per memorizzare un token di autenticazione o per tracciare le attività dell'utente.
- riga vuota (CRLF: i 2 caratteri carriage return e line feed), essenzialmente un separatore tra intestazione e body;
- body (corpo del messaggio), usato quando ci sono effettivamente dati da trasferire (non è il caso del GET, lo è invece del POST).

###### Messaggio di risposta
{: .no_toc}

    HTTP/1.1 200 OK
    Date: Fri, 22 Feb 2019 10:50:37 GMT
    Content-Type: text/html; charset=UTF-8
    Content-Length: 22208
    Connection: keep-alive
    Server: mw1215.eqiad.wmnet
    Content-language: it
    Content-Encoding: gzip
    Last-Modified: Fri, 22 Feb 2019 08:46:20 GMT
    Age: 20548
    Cache-Control: private, s-maxage=0, max-age=0, must-revalidate
    Vary: Accept-Encoding,Cookie,Authorization
    [...]
    
    <!DOCTYPE html>
    <html class="client-nojs" lang="it" dir="ltr">
    <head>
    <meta charset="UTF-8"/>
    <title>Wikipedia, l'enciclopedia libera</title>
    [...]
    </body>
    </html>

Il messaggio di risposta è di tipo testuale ed è composto da quattro parti:

- riga di stato (status-line):<br>ha una grande importanza soprattutto per gli sviluppatori poichè qui è indicato un codice a tre cifre che indica il tipo di risposta che può appartenere alle seguenti categorie:
> - 1xx: Informational (messaggi informativi)
> - 2xx: Successful (la richiesta è stata soddisfatta), ad es.:  
>> - 200 OK. Il server ha fornito correttamente il contenuto nella sezione body.
> - 3xx: Redirection (non c'è risposta immediata, ma la richiesta è sensata e viene detto come ottenere la risposta) ad es.:  
>> - 301 Moved Permanently. La risorsa che abbiamo richiesto non è raggiungibile perché è stata spostata in modo permanente.  
>> - 302 Found. La risorsa è raggiungibile con un altro URI indicato nel header Location. Di norma i browser eseguono la richiesta all'URI indicato in modo automatico senza interazione dell'utente.
> - 4xx: Client error (la richiesta non può essere soddisfatta perché sbagliata)  
>> - 400 Bad Request. La risorsa richiesta non è comprensibile al server.  
>> - 404 Not Found. La risorsa richiesta non è stata trovata e non se ne conosce l'ubicazione. Di solito avviene quando l'URI è stato indicato in modo incorretto, oppure è stato rimosso il contenuto dal server.  
> - 5xx: Server error (la richiesta non può essere soddisfatta per un problema interno del server)  
>> - 500 Internal Server Error. Il server non è in grado di rispondere alla richiesta per un suo problema interno.  
>> - 502 Bad Gateway. Il server web che agisce come reverse proxy non ha ottenuto una risposta valida dal server di upstream.  
>> - 505 HTTP Version Not Supported. La versione di http non è supportata.
- sezione header, i più comuni sono:
> - Server. Indica il tipo e la versione del server. Può essere visto come l'equivalente dell'header di richiesta User-Agent
> - Content-Type. Indica il tipo di contenuto restituito come:
>> - text/html Documento HTML
>> - text/plain Documento di testo non formattato
>> - text/xml Documento XML
>> - image/jpeg Immagine di formato JPEG
- riga vuota (CRLF: i 2 caratteri carriage return e line feed);
- body (contenuto della risposta).

In questa sezione sono stati riportati solo due esempi di messaggi HTTP, una richiesta di tipo GET e una risposta possibile a tale domanda. Sulla [pagina di Wikipedia](https://it.wikipedia.org/wiki/Hypertext_Transfer_Protocol) da cui sono state tratte queste informazioni è possibile trovare molti altri [esempi](https://it.wikipedia.org/wiki/Hypertext_Transfer_Protocol#Esempi_di_messaggi_HTTP) ed approfondimenti. 

###### Tipo di connessione
{: .no_toc}

Il client può chiedere al server, nel messaggio di richiesta, di utilizzare due tipi di comunicazione:

- __non persistente__: per ogni richiesta e relativa risposta, viene stabilita una connessione TCP dedicata;
- __persistente__: ogni richiesta e relativa risposta è trasferita utilizzando la stessa connessione TCP; è il comportamento predefinito di HTTP 1.1. 

Da un lato, le connessioni non persistenti introducono una latenza aggiuntiva rispetto a quelle persistenti perchè aprire e chiudere una connessione TCP introduce dell'overhead.
D'altro canto, le connessioni persistenti precludono il parallelismo nelle comunicazioni, giacché il client che abbia diverse richieste da inviare allo stesso server è costretto ad evaderle sequenzialmente, una dopo l'altra. Per queste ragioni, i browser solitamente sfruttano le complementarità prestazionali delle due politiche di comunicazione per massimizzare la loro efficienza: solitamente aprono con ogni server diverse connessioni TCP in parallelo, su cui comunicano con strategia persistente.

##### Streaming HTTP
{: .no_toc}

La fruizione nelle pagine WEB di materiale multimediale, quale audio o video viene gestito in modo del tutto analogo al download dei file, tramite un caricamento progressivo o distribuzione progressiva, in cui il file viene scaricato in modo progressivo dall'inizio alla fine (tramite i protocolli Real Time Streaming Protocol e Real-time Transport Protocol) e nel caso il bit-rate sia eccessivo per la rete che lo trasporta può verificarsi un continuo ricaricamento del buffer

##### Cookies
{: .titolo-4}

Il protocollo HTTP è un protocollo _stateless_ cioè non tiene traccia dello stato della connessione. Se la comunicazione si limitasse all'uso delle funzionalità offerte da HTTP quindi ad ogni richiesta di un client il server risponderebbe come se fosse la prima volta che il client comunica con lui. Per tenere traccia dello stato della comunicazione sono quindi stati introdotti i cookies che funzionano come dei gettoni identificativi che i server rilasciano ai client e in cui memorizzano informazioni a lungo termine.

I server inviano i cookie nella risposta HTTP al client e ci si aspetta che i web browser salvino e inviino i cookie al server, ogni qual volta si facciano richieste aggiuntive al web server. Tale riconoscimento permette di realizzare meccanismi di autenticazione usati ad esempio per i login; di memorizzare dati utili alla sessione di navigazione, come le preferenze sull'aspetto grafico o linguistico del sito; di tracciare la navigazione dell'utente, ad esempio per fini statistici o pubblicitari; di associare dati memorizzati dal server, ad esempio il contenuto del carrello di un negozio elettronico.

Date le implicazioni per la riservatezza dei naviganti del web, l'uso dei cookie è categorizzato e disciplinato negli ordinamenti giuridici di numerosi paesi, tra cui quelli europei, inclusa l'Italia. Tra le varie regole dettate dalla legge, quella più evidente per l'utente è che i server devono ricevere un esplicito permesso da parte dell'utente per poter utilizzare i cookies. 

In termini pratici e non specialistici, un cookie è simile ad un piccolo file, memorizzato nel computer da siti web durante la navigazione, utile a salvare le preferenze e a migliorare le prestazioni dei siti web. In questo modo si ottimizza l'esperienza di navigazione da parte dell'utente.

Nel dettaglio, un cookie è una stringa di testo di piccole dimensioni inviata da un web server ad un web client (di solito un browser) e poi rimandata indietro dal client al server (senza subire modifiche) ogni volta che il client accede alla stessa porzione dello stesso dominio web. I cookie sono stati originariamente introdotti per fornire un modo agli utenti di memorizzare gli oggetti che volevano acquistare, mentre navigavano nel sito web (il cosiddetto "carrello della spesa").

Oggi, tuttavia, il contenuto del carrello di un utente viene immagazzinato in un database sul server, piuttosto che in un cookie sul client. Per tenere traccia a quale utente è assegnato il carrello della spesa, il server Web invia un cookie al client che contiene un identificatore di sessione univoco (tipicamente, una lunga serie di lettere e numeri). Poiché i cookie vengono inviati al server ad ogni richiesta del client, l'identificatore di sessione sarà inviato al server ogni volta che l'utente visita una pagina sul sito web, ciò permette al server di sapere quale carrello deve fornire all'utente.

Poiché i cookie di sessione contengono solo un identificatore di sessione univoco, questo rende la quantità di informazioni personali che un sito web può memorizzare virtualmente illimitata. Il sito non si limita alle restrizioni in materia di quanto possa essere lunga la stringa di testo che compone un cookie. I cookie di sessione possono anche contribuire a migliorare i tempi di caricamento delle pagine, dal momento che la quantità di informazioni in un cookie di sessione è piccolo e richiede poca banda.

I cookie vengono spesso erroneamente ritenuti veri e propri programmi e ciò genera errate convinzioni. In realtà essi sono semplici blocchi di dati, incapaci, da soli, di compiere qualsiasi azione sul computer. In particolare non possono essere né spyware, né virus. Ciononostante i cookie provenienti da alcuni siti sono catalogati come spyware da molti prodotti anti-spyware perché rendono possibile l'individuazione dell'utente. I moderni browser permettono agli utenti di decidere se accettare o no i cookie, ma l'eventuale rifiuto rende alcuni oggetti inutilizzabili. Ad esempio, gli shopping cart implementati con i cookie non funzionano in caso di rifiuto.

La grande varietà esistente di cookie nel mondo del web rende difficile una loro classificazione. È possibile comunque stilarne una tassonomia generale separandoli in diverse categorie. 

L'attributo principale tramite cui possiamo dividere i cookie è il loro ciclo di vita, il quale ci permette di distinguerli in:

- __Cookie di sessione__: questi cookie non vengono memorizzati in modo persistente sul dispositivo dell'utente e vengono cancellati alla chiusura del browser. A differenza di altri cookie, i cookie di sessione non hanno una data di scadenza, ed in base a questo il browser riesce ad identificarli come tali.
- __Cookie persistenti__: invece di svanire alla chiusura del browser, come vale per i cookie di sessione, i cookie persistenti scadono ad una data specifica o dopo un determinato periodo di tempo. Ciò significa che, per l'intera durata di vita del cookie (che può essere lunga o breve a seconda della data di scadenza decisa dai suoi creatori), le sue informazioni verranno trasmesse al server ogni volta che l'utente visita il sito web, o ogni volta che l'utente visualizza una risorsa appartenente a tale sito da un altro sito (ad esempio un annuncio pubblicitario). Per questo motivo, i cookie persistenti possono essere utilizzati dagli inserzionisti per registrare le informazioni sulle abitudini di navigazione web di un utente per un periodo prolungato di tempo. Tuttavia, essi sono utilizzati anche per motivi "legittimi " (come ad esempio mantenere gli utenti registrati nel loro account sui siti web, al fine di evitare, ad ogni visita, l'inserimento delle credenziali per l'accesso ai siti web).

È possibile poi classificare i cookie in base alla provenienza in:

- __Cookie di prima parte__: normalmente, l'attributo di dominio di un cookie corrisponderà al dominio che viene visualizzato nella barra degli indirizzi del browser web; sono i cookie inviati al browser direttamente dal sito che si sta visitando. Questo è chiamato un cookie di prima parte. Possono essere sia persistenti sia di sessione; sono gestiti direttamente dal proprietario e/o responsabile del sito e vengono utilizzati, ad esempio, per garantirne il funzionamento tecnico o tenere traccia di preferenze espresse in merito all'uso del sito stesso.
- __Cookie di terza parte__: i cookie di terze parti, appartengono a domini diversi da quello mostrato nella barra degli indirizzi. Questi tipi di cookie appaiono in genere quando le pagine web sono dotate di contenuti, come ad esempio banner pubblicitari, da siti web esterni. Questo implica la possibilità di monitoraggio della cronologia di navigazione dell'utente, ed è spesso usato dagli inserzionisti, nel tentativo di servire annunci rilevanti e personalizzati per ciascun utente. Per esempio, supponiamo che un utente visiti www.example.org. Questo sito web contiene un annuncio da ad.foxytracking.com, che, una volta scaricato, imposta un cookie che appartiene al dominio della pubblicità (ad.foxytracking.com). Quindi, l'utente visita un altro sito web, www.foo.com, che contiene anche un annuncio da ad.foxytracking.com/, e che stabilisce anche un cookie appartenente a quel dominio (ad.foxytracking.com). Alla fine, entrambi questi cookie saranno inviati al venditore quando si caricano le loro pubblicità o visitando il loro sito web. L'inserzionista può quindi utilizzare questi cookie per costruire una cronologia di navigazione degli utenti in tutti i siti che hanno gli annunci di questo inserzionista. La maggior parte dei moderni browser web contengono delle impostazioni di privacy che sono in grado di bloccare i cookie di terze parti.

Esistono molti altri tipi di cookie, se vuoi approfondire l'argomento puoi farlo [qui](https://it.wikipedia.org/wiki/Cookie)


##### HTTPS
{: .titolo-4}

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/HTTPS_icon.png" class="modal__opener" aprire="#img-HTTPS_icon">
  <p>Icona del lucchetto di HTTPS seguita dall'inizio di un URL che usa HTTPS</p></div>
<!-- modal -->
<div id="img-HTTPS_icon" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-HTTPS_icon">&times;</span>
    <div class="modal__content__img-container"> 
      <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/HTTPS_icon.png">
    </div>
    <p>Icona del lucchetto di HTTPS seguita dall'inizio di un URL che usa HTTPS</p>
  </div>
</div>

L'HyperText Transfer Protocol over Secure Socket Layer (HTTPS), (anche noto come HTTP over TLS, HTTP over SSL e HTTP Secure) è un protocollo per la comunicazione sicura attraverso una rete di computer utilizzato su reti TCP/IP quali internet. Consiste nella comunicazione tramite il protocollo HTTP (Hypertext Transfer Protocol) all'interno di una connessione criptata, dal Transport Layer Security (TLS) o dal suo predecessore, Secure Sockets Layer (SSL) (protocolli di livello 6). Come HTTP utilizza TCP ma generalmente sulla porta 443. I servizi aggiuntivi offerti dall'uso dei protocolli di cifratura sono:

- cifratura del traffico;
- verifica di integrità del traffico (la correzione degli errori è già offerta da TCP ma TLS protegge da malevoli modifiche fatte da terzi);
- autenticazione del server;
- autenticazione dell'utente (in realtà spesso non avviene).

HTTP non è criptato, quindi è vulnerabile alle intercettazioni e ad attacchi man-in-the-middle: gli attaccanti possono ottenere l'accesso ad account di siti web con informazioni sensibili, o modificare le pagine web per iniettare al loro interno dei malware o della pubblicità malevola. HTTPS è progettato per resistere a tali attacchi ed è considerato sicuro contro di essi (con eccezione delle versioni più obsolete e deprecate del protocollo SSL).

Le URL del protocollo HTTPS iniziano con https:// e utilizzano la porta 443 di default, mentre le URL HTTP cominciano con http:// e utilizzano la porta 80. Normalmente nei browser viene anche usata l'icona di un lucchetto per indicare che la connessione in corso è cifrata è che il server si è correttamente autenticato (si è sicuri dell'identità del server).

Per comprendere meglio le funzionalità offerte da HTTPS è necessario studiare il funzionamento di TLS nella [sezione](#transport-layer-security-tls) ad esso dedicata. è anche possibile approfondire l'argomento sulla [pagina Wikipedia](https://it.wikipedia.org/wiki/HTTPS) dedicata a HTTPS

#### FTP 
{: .titolo-3}

#### Protocolli per la posta elettronica
{: .titolo-3}


## Link e riferimenti esterni

- [ISO/OSI su Wikipedia](https://it.wikipedia.org/wiki/Modello_OSI)
- [Incapsulamento su Wikipedia](https://it.wikipedia.org/wiki/Imbustamento)
- [TCP/IP su Wikipedia](https://it.wikipedia.org/wiki/Suite_di_protocolli_Internet)
- [Livello di trasporto su Wikipedia](https://it.wikipedia.org/wiki/Transmission_Control_Protocol)
- [Porte su Wikipedia](https://it.wikipedia.org/wiki/Porta_(reti))
- [Socket su Wikipedia](https://it.wikipedia.org/wiki/Socket_(reti))
- Elenco delle porte su Wikipedia [in italiano](https://it.wikipedia.org/wiki/Porte_TCP_e_UDP_standard) e [in inglese](https://en.wikipedia.org/wiki/List_of_TCP_and_UDP_port_numbers) (più approfondito)
- [TCP su Wikipedia](https://it.wikipedia.org/wiki/Transmission_Control_Protocol#Confronto_con_UDP)
- [UDP su Wikipedia](https://it.wikipedia.org/wiki/User_Datagram_Protocol)
- [Peer to Peer su Wikipedia](https://it.wikipedia.org/wiki/Peer-to-peer)
- [TLS su Wikipedia](https://en.wikipedia.org/wiki/Transport_Layer_Security)
- [URI su Wikipedia](https://it.wikipedia.org/wiki/Uniform_Resource_Locator)
- [DNS su Wikipedia](https://it.wikipedia.org/wiki/Domain_Name_System)
- [Articolo sui DNS pubblici](https://www.worldcomputing.it/computer/internet/44-elenco-migliori-veloci-affidabili-server-dns-pubblici-gratuiti.html)
- [HTTP su Wikipedia](https://it.wikipedia.org/wiki/Hypertext_Transfer_Protocol)
- [Cookies su Wikipedia](https://it.wikipedia.org/wiki/Cookie)
- [HTTPS su Wikipedia](https://it.wikipedia.org/wiki/HTTPS)