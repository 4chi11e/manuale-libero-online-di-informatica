---
layout: default
title: ISO/OSI
nav_order: 1
parent: Reti
has_children: True
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

Nelle pagine successive sono descritte le funzionalità offerte da ogni livello mantenendo la suddivisione in sette livelli del modello ISO/OSI. Per i livelli inferiori saranno anche descritti i principali dispositivi di rete che operano a tale livello. É importante sottolineare il fatto che un dispositivo di livello N opera su tutti i livelli fino al livello N poichè ogni protocollo per funzionare necessita delle funzionalità offerte dai livelli inferiori come visto nella sezione dedicata all'[incapsulamento](#incapsulamento).

## Dispositivi e livelli

Esistono molti tipi di dispositivi che operano a diversi livelli della pila ISO/OSI fornendo quindi ognuno diverse funzionalità. Di seguito sono riportati e brevemente descritti i dispositivi più comuni.

### Livello 1 - Fisico

<!-- thumbnail -->
<div class="thumbnail tright mb-2">
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/Schema_ripetitore.jpg" class="modal__opener" aprire="#img-schema_ripetitore">
  <p>Schema di comunicazione tra host per mezzo di un ripetitore</p>
</div>
<!-- modal -->
<div id="img-schema_ripetitore" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-schema_ripetitore">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/Schema_ripetitore.jpg">
    </div>
    <p>Schema di comunicazione tra host per mezzo di un ripetitore</p>
  </div>
</div>

<!-- thumbnail -->
<div class="thumbnail tright  mb-2">
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/ethernet_hub.jpg" class="modal__opener" aprire="#img-ethernet_hub">
  <p>Foto di un hub</p>
</div>
<!-- modal -->
<div id="img-ethernet_hub" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-ethernet_hub">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/ethernet_hub.jpg">
    </div>
    <p>Foto di un hub. Il basso numero di porte è dovuto all'incapacità di risolvere il problema delle collisioni</p>
  </div>
</div>

- Modem
- Repeater
- Hub

Sono dispositivi attivi, componenti di reti telematiche: il repeater connette fra loro due reti, mentre l'hub consente connessioni di più host.

L'appartenenza al livello 1 del modello ISO/OSI implica che il traffico si considera per bit, cioè per semplice sequenza di stati logici uno e zero, non raggruppati in nessun modo. Operando a livello 1, inoltre, repeater e hub non gestiscono l'arbitraggio dell'accesso al mezzo trasmissivo, e lasciano che gli host collegati lo facciano tramite l'algoritmo CSMA/CD. Quindi la connessione di un host a un hub non può che essere half-duplex. Operano nell'ambito del medesimo dominio di collisione, per cui il traffico di qualsiasi nodo, le collisioni ed i frame ritrasmessi vengono replicati su tutte le porte dell'hub, sottraendo quindi banda passante in egual misura ad ogni utenza della rete.

L'hub è un componente ormai obsoleto e viene sostituito dallo switch.

### Livello 2 - Collegamento

<!-- thumbnail -->
<div class="thumbnail tright  mb-2">
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/schema_bridge.jpg" class="modal__opener" aprire="#img-schema_bridge">
  <p>Schema di comunicazione tra host per mezzo di un bridge</p>
</div>
<!-- modal -->
<div id="img-schema_bridge" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-schema_bridge">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/schema_bridge.jpg">
    </div>
    <p>Schema di comunicazione tra host per mezzo di un bridge</p>
  </div>
</div>

- Bridge
- Switch

I due dispositivi suddetti sono molto simili e operano al livello 2 del modello OSI. Sono dispositivi "intelligenti" che operano mediante "auto-apprendimento" e sono, quindi, plug-and-play e non si limitano a replicare il segnale, ma agiscono sui frame ricevuti instradandoli verso la destinazione esatta. Mediante queste loro capacità essi tengono i domini di collisione separati, col vantaggio di occupare banda passante solo sulle porte effettivamente interessate dal traffico, lasciando libere le altre. Operano anche sulla gestione dei frame per cui se trovano la rete occupata utilizzano un buffer per immagazzinare i frame attendendo che la rete si liberi. Lo switch, rispetto al bridge, ha interfacce multiple per cui consente il collegamento diretto di più host e fornisce prestazioni migliori grazie ad algoritmi di gestione dei frame più sofisticati.

<!-- thumbnail -->
<div class="thumbnail tright  mb-2">
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/switch.jpg" class="modal__opener" aprire="#img-switch">
  <p>Foto di unp switch</p>
</div>
<!-- modal -->
<div id="img-switch" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-switch">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/switch.jpg">
    </div>
    <p>Foto di uno switch. L'alto numero di porte (24) è permesso dalla risoluzione del problema delle collisioni</p>
  </div>
</div>

Operando a livello 2 del modello ISO/OSI, lo switch è in grado di identificare l'Indirizzo MAC del mittente e del destinatario del frame; lo switch dispone di una memoria volatile (MAC table), che viene riempita con le associazioni fra le porte ed i MAC osservati su di esse, in modo da poter tracciare istantaneamente le connessioni fra porte in funzione dei frame stessi. L'isolamento fra i domini di collisione permette di non impiegare il CSMA/CD, adottando la modalità full-duplex sulle porte e raddoppiando la banda passante aggregata delle stesse; ciò inoltre evita la propagazione di collisioni e di frame non inerenti alla specifica porta.

L'operatività a livello di frame, inoltre, permette di intervenire sulla distribuzione degli stessi; gli switch di tipo managed (gestiti) possono essere configurati in modo da supportare (ad esempio) VLAN port-based, aggregazione (802.3ad/LACP), controllo d'accesso basato sugli indirizzi MAC o su autenticazione (802.1x), STP (802.1D), RSTP (802.1w), QoS MAC-based (802.1p). Caratteristica importante di uno switch è la sua banda passante aggregata, indicata come la capacità effettiva del suo hardware di gestire un determinato traffico e si esprime in bps (bit per secondo); altra caratteristica importante è il forward rate, cioè la capacità di instradare frames al netto del tempo di processo, e si esprime in pps (pacchetti per secondo).

è molto comune imbattersi in dispositivi che vengono chiamati switch ma che in realtà offrono funzionalità di livello più elevato e che sono quindi di fatto dei router.

### Livello 3 - Rete

<!-- thumbnail -->
<div class="thumbnail tright mb-2">
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/schema_router.jpg" class="modal__opener" aprire="#img-schema_router">
  <p>Schema di comunicazione tra host per mezzo di un router</p>
</div>
<!-- modal -->
<div id="img-schema_router" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-schema_router">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/schema_router.jpg">
    </div>
    <p>Schema di comunicazione tra host per mezzo di un router</p>
  </div>
</div>

<!-- thumbnail -->
<div class="thumbnail tright mb-2">
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/gateway_firewall.svg" class="modal__opener" aprire="#img-gateway_firewall">
  <p>Schema di un firewall</p>
</div>
<!-- modal -->
<div id="img-gateway_firewall" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-gateway_firewall">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/gateway_firewall.svg">
    </div>
    <p>Schema di un firewall</p>
  </div>
</div>

<!-- thumbnail -->
<div class="thumbnail tright mb-2">
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/proxy_concept_it.svg" class="modal__opener" aprire="#img-proxy_concept_it">
  <p>Schema di funzionamento di un proxy</p>
</div>
<!-- modal -->
<div id="img-proxy_concept_it" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-proxy_concept_it">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/proxy_concept_it.svg">
    </div>
    <p>Schema di funzionamento di un proxy</p>
  </div>
</div>

- Router
- Firewall (lavora anche a livello di trasporto e di applicazione)

Il router opera al livello 3 ed oltre della gerarchia di protocolli ISO/OSI, gestendo le informazioni a livello di packet, con capacità di identificare mittente e destinatario logici (es. indirizzo IP). La capacità di operare a livello di protocollo, permette di definire configurazioni selettive come routing (instradamento), lista di controllo degli accessi basate su IP, VLAN basate su protocollo e gestione della qualità del servizio (prioritizzazione dei pacchetti).

Il router, per la realtà complessa nella quale può trovarsi ad operare, può impiegare protocolli di gestione del traffico di tipo evoluto, come algoritmi di routing (es. RIP, IGRP, EIGRP, OSPF, IS-IS), algoritmi di ricerca del percorso migliore e di risoluzione di errori di percorso.

### Livello 4 - Trasporto

- Firewall (lavora anche a livello di rete e di applicazione)

### Livello applicativo

- Gateway
- Firewall (lavora anche a livello di rete e di trasporto)
- Proxy

## Link e riferimenti esterni
{: .clear-both}

- [ISO/OSI su Wikipedia](https://it.wikipedia.org/wiki/Modello_OSI)
- [Incapsulamento su Wikipedia](https://it.wikipedia.org/wiki/Imbustamento)
- [TCP/IP su Wikipedia](https://it.wikipedia.org/wiki/Suite_di_protocolli_Internet)
- [Dispositivi di rete su Wikipedia](https://it.wikipedia.org/wiki/Dispositivo_di_rete)
