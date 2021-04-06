---
layout: default
title: ISO/OSI
nav_order: 1
parent: Reti
has_children: true
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

A livello implementativo lo standard _[de facto](https://it.wikipedia.org/wiki/De_facto "De facto")_ affermatosi per architetture di rete a livelli è invece il [TCP/IP](https://it.wikipedia.org/wiki/TCP/IP "TCP/IP"), che riprende in parte il modello OSI.

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


## Elenco e funzioni dei livelli
Di seguito sono descritte le funzionalità offerte da ogni livello. Per i livelli inferiori saranno anche descritti i principali dispositivi di rete che operano a tale livello. É importante sottolineare il fatto che un dispositivo di livello N opera su tutti i livelli fino al livello N poichè ogni protocollo per funzionare necessita delle funzionalità offerte dai livelli inferiori (per maggiori dettagli vedi il capitolo sull'[incapsulamento](#incapsulamento)).  

### Livello 1: fisico (Physical Layer)

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

#### Hub
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

### Livello 2: Collegamento dati (Datalink layer)

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

#### Switch

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


### Livello 3: rete (Network Layer)
_Obiettivo: rendere i livelli superiori indipendenti dai meccanismi e dalle tecnologie di trasmissione usate per la connessione e prendersi carico della consegna a destinazione dei pacchetti._

È responsabile di:

* [routing](https://it.wikipedia.org/wiki/Instradamento#Routing "Instradamento"): scelta ottimale del percorso di rete da utilizzare per garantire la consegna delle informazioni dal mittente al destinatario, scelta svolta dal [router](https://it.wikipedia.org/wiki/Router "Router") attraverso dei particolari [algoritmi di Routing](https://it.wikipedia.org/wiki/Protocolli_di_routing "Protocolli di routing") e [tabelle di routing](https://it.wikipedia.org/wiki/Routing_table "Routing table").
* conversione dei dati nel passaggio fra una rete ed un'altra con diverse caratteristiche, come il protocollo di rete utilizzato (_internet-working_). Deve, quindi:
  * tradurre gli indirizzi di rete;
  * valutare la necessità di frammentare i pacchetti dati se la nuova rete prevede una diversa dimensione dei pacchetti;
  * valutare la necessità di gestire diversi protocolli attraverso l'impiego di [gateway](https://it.wikipedia.org/wiki/Gateway_(informatica) "Gateway (informatica)").

La sua unità dati fondamentale è il _pacchetto_.

Il protocollo di rete più usato è il protocollo IP (Internet Protocol) usato in tutte le reti TCP/IP.

[Link](https://it.wikipedia.org/wiki/Livello_di_rete "Livello di rete") alla pagina wikipedia.

#### Router

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








# --ARRIVATO FIN QUI A SISTEMARE--



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