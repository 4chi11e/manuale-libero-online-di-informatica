---
layout: default
title: Reti
nav_order: 5
has_children: true
---

# Rete di computer
{: .no_toc }

Una <b>rete di computer</b>, è un insieme di dispositivi (*host* e *nodi di commutazione*), collegati l'uno con l'altro da appositi canali di comunicazione (*link*), che per mezzo di opportuni protocolli di comunicazione hanno la possibilità di condividere risorse che possono essere materiali, cioè dispositivi fisici come una stampante, o immateriali come dati, informazioni o servizi di ogni genere.

Le reti possono essere realizzate con un gran numero di tecnologie e modelli differenti. Di seguito verranno descritte le principali tecniche usate, soprattutto quelle legate alla rete internet.


## Indice
{: .no_toc .text-delta }

- TOC
{:toc}

## Caratteristiche generali

La rete fornisce un servizio di trasferimento dati, attraverso comuni funzionalità di <a href="https://it.wikipedia.org/wiki/Trasmissione_(telecomunicazioni)" title="Trasmissione (telecomunicazioni)">trasmissione</a> e <a href="https://it.wikipedia.org/wiki/Ricezione" title="Ricezione">ricezione</a>, ad una popolazione di utenti distribuiti su un'area più o meno grande. Esempi di rete informatica sono le reti <a href="https://it.wikipedia.org/wiki/Local_Area_Network" title="Local Area Network">LAN</a>, <a href="https://it.wikipedia.org/wiki/Wireless_LAN" class="mw-redirect" title="Wireless LAN">WLAN</a>, <a href="https://it.wikipedia.org/wiki/Wide_Area_Network" title="Wide Area Network">WAN</a> e <a href="https://it.wikipedia.org/wiki/Global_Area_Network" class="mw-redirect" title="Global Area Network">GAN</a> la cui interconnessione globale dà vita alla Rete <a href="https://it.wikipedia.org/wiki/Internet" title="Internet">Internet</a>.

Le reti di computer generano <a href="https://it.wikipedia.org/wiki/Traffico_(telecomunicazioni)" title="Traffico (telecomunicazioni)">traffico</a> di tipo fortemente impulsivo ovvero <a href="https://it.wikipedia.org/wiki/Pacchetto_(reti)" title="Pacchetto (reti)">pacchettizzato</a> e asincrono, a differenza della <a href="https://it.wikipedia.org/wiki/Rete_telefonica" title="Rete telefonica">rete telefonica</a> sincrona, e per questo hanno dato origine e usano&nbsp;la tecnologia della <a href="https://it.wikipedia.org/wiki/Commutazione_di_pacchetto" title="Commutazione di pacchetto">commutazione di pacchetto</a>, piuttosto che la <a href="https://it.wikipedia.org/wiki/Commutazione_di_circuito" class="mw-redirect" title="Commutazione di circuito">Commutazione di circuito</a> come per le linee telefoniche tradizionali. Nate come reti dati private tra servizi della difesa e le università, a partire dagli anni 2000 le reti internet si sono diffuse verso le reti integrate nei servizi di <a href="https://it.wikipedia.org/wiki/Rete_telefonica" title="Rete telefonica">rete telefonica</a>, con l'avvento dell'<a href="https://it.wikipedia.org/wiki/ISDN" class="mw-redirect" title="ISDN">ISDN</a>, con la tecnologia <a href="https://it.wikipedia.org/wiki/ADSL" title="ADSL">ADSL</a> e attualmente tramite la <a href="https://it.wikipedia.org/wiki/Fibra_ottica" title="Fibra ottica">Fibra ottica</a> e la telefonia mobile con <a href="https://it.wikipedia.org/wiki/4G_LTE" class="mw-redirect" title="4G LTE">4G LTE</a>.

### Terminologia generale
Parlando di reti si fa spesso riferimento ad alcune componenti di esse. Di seguito sono riportati i principali componenti di una rete:
- **Host** - dispositivo terminale di rete (computer, smarphone, server...)
- **Nodo** di commutazione cioè quei dispositivi interni alla rete che ne gestiscono il traffico (router, switch...)
- **Canale** (link) o collegamento tra nodi o tra host e nodi (cavi di rete di varia natura)
- Interfaccia o scheda di rete sugli host e sui nodi che permette loro di comunicare

Parlando invece dei messaggi che vengono spediti nella rete si fa riferimento a:
- **Pacchetto** (packet)- nelle reti digitali i dati vengono raggruppati in pacchetti con formati definiti dai vari protocolli di comunicazione. Il termine pacchetto è un termine generico che può sempre andare bene ma a voler essere precisi, a seconda del livello della pila protocollare ISO-OSI in cui si opera, si preferisce usare termini differenti: al livello 2 si preferisce il termine **frame**, a livello 3 **pacchetto** (packet) e a livello 4 **segmento** (in TCP) o **datagramma** (UDP). 
- **Intestazione** o **header** - Ogni pacchetto è diviso il due parti, la parte iniziale detta intestazione o header è la parte in cui sono inserite le informazioni riguardanti il pacchetto come indirizzi di destinazione e provenienza. 
- **Payload** o più semplicemente **dati** è la parte del pacchetto che contiene i dati.

### Problemi e vantaggi di una rete internet

La costruzione delle prime reti risale al 1969 quando viene creato il primo nodo di IMP (Interface Message Processor) dell'<a href="https://it.wikipedia.org/wiki/ARPANET" title="ARPANET">ARPANET</a> a UCLA . La tecnologia delle reti e la sua successiva diffusione in giro per il mondo ha permesso rivoluzionari sviluppi nell'organizzazione delle risorse di calcolo e nella distribuzione di dati e risorse in giro per il mondo grazie alle dorsali oceaniche in fibra ottica.

Si possono indicare almeno quattro punti di forza di una rete dati distribuita rispetto alla concentrazione di tutto su un singolo dispositivo e in un singolo luogo:

1.  _fault tolerance_ (resistenza ai guasti): grazie alla ridondanza dei dati il guasto di una macchina non blocca tutta la rete, ed è possibile sostituire il computer guasto facilmente e in lasso di tempo breve (la componentistica costa poco e un'azienda può permettersi di tenere i pezzi di ricambio in magazzino);
2.  _economicità_: come accennato sopra, hardware e software per computer costano meno di quelli per un singolo mainframe;
3.  _gradualità della crescita e flessibilità ([scalabilità](https://it.wikipedia.org/wiki/Scalabilit%C3%A0 "Scalabilità"))_: l'aggiunta di nuovi nodi e terminali a una rete già esistente e la sua espansione sono semplici e poco costose;
4.  _facilità di accesso ai dati_: ovunque ci si trovi nel mondo i dati salvati sui sistemi connessi a internet sono sempre accessibili e disponibili con tempi di attesa in media molto brevi.

Tuttavia una rete mostra alcuni punti deboli:

1.  _scarsa sicurezza_: un malintenzionato può avere accesso più facilmente ad una rete di computer: quando un virus infetta un sistema della rete questo si propaga rapidamente agli altri, l'opera di individuazione e rimozione della minaccia può risultare lunga e difficile;
2.  _alti costi di costruzione e di manutenzione_: creare una infrastruttura di rete è molto complicato e costoso in quanto richiede molto lavoro, depositare i cavi, costruire centraline e centrali di commutazione;
3.  furto dei dati: se i dati non sono criptati possono essere rubati da chi li intercetta sulla connessione (sniffing);
4.  impersonificazione: senza fattori di autenticazione un qualsiasi utente della rete si può spacciare per qualcun altro.

## Tipologie di rete e tecniche di trasferimento dell'informazione

Esiste una grande varietà di tecnologie di rete e di modelli organizzativi, che possono essere classificati secondo diversi aspetti.

### Classificazione in base all'estensione geografica

Un modo molto semplice di catalogare le reti è in base alla loro estensione spaziale. Le categorie sono le seguenti:

- si parla di *rete locale* o **LAN** (Local Area Network) se la rete si estende all'interno di un edificio o di un comprensorio, con una estensione media nell'ordine del centinaio di metri (da pochi metri a un chilometro).
- si parla di *rete universitaria* o **CAN** (Campus Area Network), intendendo la rete interna ad un campus universitario, o comunque ad un insieme di edifici adiacenti, separati tipicamente da terreno di proprietà dello stesso ente, che possono essere collegati con cavi propri senza far ricorso ai servizi di operatori di telecomunicazioni. Tale condizione facilita la realizzazione di una rete di interconnessione ad alte prestazioni e a costi contenuti.
- si parla di *rete metropolitana* o **MAN** (Metropolitan Area Network) se la rete si estende all'interno di una città.
- si parla di *rete geografica* o **WAN** (Wide Area Network) se la rete ricopre un'area geografica molto estesa e che intercorre nelle reti precedenti.
- si parla di *rete globale* o **GAN** (Global Area Network) se la rete collega calcolatori dislocati in tutto il mondo, anche via satellite.

La rete **internet** è invece un'unica grande rete risultante dall'unione di utte le reti del mondo che sono collegate fra loro. Le reti private che non sono collegate alla rete internet vengono solitamente dette **intranet** (questo termine viene usato anche con accezioni diverse)

### Classificazione in base alla tecnologia trasmissiva

A seconda della modalità di trasmissione dei dati, le reti si possono dividere in due tipologie:

- **Reti broadcast**: nelle reti broadcast gli host sono direttamente collegati ad un canale di comunicazione condiviso da tutti. Quando un host trasmette un messaggio sul canale di comunicazione, il messaggio sarà ricevuto da tutti gli host che leggendo l'indirizzo di destinazione nell'intestazione dei pacchetti capiranno se il messaggio è effettivamente rivolto a loro.  
Nel caso un host voglia spedire un messaggio a più di un altro host contemporaneamente lo può fare, in questo caso si parla di comunicazione **multicast**. Nel caso invece si mandi un messaggio a tutti i dispositivi della rete si parla di comunicazione **broadcast**.
- **Reti punto a punto**: nelle reti punto a punto gli host sono connessi tra loro a coppie, mediante diversi canali di trasmissione. Per arrivare alla corretta destinazione un messaggio viene inviato dal mittente all'host al quale è direttamente connesso (oppure a uno degli host nel caso di connessione multipla), che ritrasmette il messaggio alla ricerca del destinatario.  
Quindi il percorso che il messaggio deve compiere non è noto a priori dato che le connessioni sono multiple e generano un grafo, sicuramente esisteranno più percorsi alternativi per raggiungere la destinazione. La scelta dei percorsi viene fatta da appositi *algoritmi di instradamento* (**routing**) che rivestono un ruolo determinante per il funzionamento della rete.

Con il termine **routing** si intende il reinstradamento automatico dei pacchetti in base alla rilevazione e all'analisi della situazione corrente della rete: un algoritmo di routing decide quale connessione usare per instradare il pacchetto dalla macchina sorgente alla macchina destinazione nel modo ritenuto migliore possibile.

Non è una regola ma nella pratica, per le reti locali si privilegia la struttura broadcast mentre per le reti con canali di comunicazione più lunghi è preferibile il punto a punto. Ci sono importanti eccezioni, ad esempio le reti senza fili, cioè basate su comunicazioni via radio come il Wi-Fi sono necessariamente di tipo broadcast; un altro esempio è costituito dalle reti locali ATM che sono punto a punto.


### Classificazione in base al tipo di canale trasmissivo
Da questo punto di vista le reti si dividono principalmente in due categorie, che possono a loro volta poi essere ulteriormente suddivise:
- **Reti cablate**: in questo caso i canali di comunicazione sono costituiti da cavi fisici che possono essere di vario tipo in base ai materiali usati e alla loro composizione interna:
> - cavi di **rame**: il rame è il conduttore più usato per costruire cavi che trasmettano segnali elettrici. Se ne possono trovare di tantissimi tipi ma quelli con cui abbiamo più frequentemente a che fare sono i cavi **Ethernet** che sono cavi composti da un fascio di 8 fili di rame isolati e "intestati" alle due estremità del cavo in un connettore **RJ-45**. In realtà esistono due tipi di cavi, i cavi **diretti** (i più comuni) che servono a collegare gli host con i dispositivi di rete come router o switch, e i cavi **incrociati** che servono a collegare direttamente tra loro due host (si fa raramente). La differenza tra i due cavi sta nell'ordine con cui sono disposti i fili di rame nel connettore RJ-45. Per maggiori dettagli puoi guardare [qui](https://it.wikipedia.org/wiki/Ethernet#Cablaggi).  
I cavi di rame hanno una caratteristica, per trasmettere un'informazione hanno bisogno di essere percorsi da una corrente elettrica. Secondo le leggi della fisica una corrente elettrica crea un campo magnetico intorno al conduttore e viceversa un campo magnetico genera una corrente elettrica in un conduttore. Per questo motivo i cavi di rame sono sensibili ai disturbi creati da altri cavi sia di rete che di alimentazione. Per questo motivo spesso i cavi vengono schermati con delle "armature" di metallo che circondano il cavo.  
In ogni caso i cavi ethernet, anche nelle migliori condizioni, non riescono a trasmettere un segnale di sufficiente qualità oltre i 100 metri.
> - cavi in **fibra ottica** sono basati su un principio completamente diverso per trasmettere i segnali, essi infatti possono essere descritti schematicamente come dei tubi vuoti il cui interno è rivestito da un materiale che riflette la luce. In questo modo sono in grado di essere percorsi da segnali luminosi per distanze molto più lunghe rispetto ad un cavo di rame. In generale un cavo in fibra ottica permette inoltre una maggior velocità di trasmissione rispetto ai cavi di rame. è per questo motivo che le grandi dorsali di rete sono fatte in fibra ottica. Un semplice cavo in fibra ottica può essere usato per trasmettere segnali fino a 1000 metri.
- **Reti wireless** o senza fili: sono reti in cui le comunicazioni non avvengono attraverso un cavo ma via radio. Esistono diversi tipi di reti wireless: Wi-Fi, Bluetooth, reti per telefoni cellulari di vario genere, normalmente suddivise in diverse generazioni (3G, 4G, 5G ...), reti satellitari...  
In tutte queste reti i dispositivi per comunicare tra loro usano antenne che trasmettono segnali via radio. Quello che cambia tra le varie reti sono i protocolli di comunicazione e le frequenze utilizzate. Quando si parla di reti wireless il canale di comunicazione è una specifica frequenza (o intervallo di frequenze) radio.  
Le frequenze non sono tutte uguali, e possono presentare vantaggi e svantaggi. In generale più la frequenza è alta più è alta la velocità di trasmissione dei dati. Frequenze molto alte però hanno il problema di essere facilmente bloccate da ostacoli fisici ed è necessaria una *linea di visuale* tra le antenne comunicanti. Le frequenze di questo tipo più usate sono dell'ordine dei Ghz e sono parzialmente usate dal Wi-Fi (che usa anche frequenze più basse, più lente ma con gittata maggiore) e saranno ampiamente usate dal 5G che avrà bisogno di diffusione capillare nel territorio e assenza di ostacoli (motivo per cui abbattono gli alberi che contenendo acqua ostacolano pesantemente il segnale).  
Le frequenze usate da televisione e radio sono più lente ma sono anche quelle che si trasmettono meglio, motivo per cui si sta cercando di diminuire le frequenze usate da queste tecnologie (vedi cambiamento delle frequenze per i canali televisivi con necessità di risintonizzare il televisore ogni pochi anni magari dovendo anche cambiare decoder) per lasciarle alle nuove generazioni di reti di telecomunicazioni.

### Classificazione in base alla topologia di rete

In telecomunicazioni la topologia di rete è il modello geometrico (grafo) finalizzato a rappresentare le relazioni di connettività, fisica o logica, tra gli elementi costituenti la rete stessa (detti anche nodi). Il concetto di topologia si applica a qualsiasi tipo di rete di telecomunicazioni: telefonica, rete di computer, Internet.

Esistono diversi tipi di topologie alcune elementari, altre più complesse che possono essere viste come composizione delle topologie più semplici. 

Ogni topologia presenta vantaggi e svantaggi e possiamo confrontare le diverse topologie in base ai seguenti criteri:

- costo dell'infrastruttura
- complessità di gestione
- tolleranza ai guasti o fault tolerance
- scalabilità

Alcune reti utilizzano collegamenti **punto a punto**, cioè la connessione diretta tra coppie di nodi, con canali riservati, senza stazioni intermedie. Altre prevedono i collegamenti **multipunto**, in altre parole utilizzano un canale comune su cui possono accedere più nodi.

Le topologie più importanti sono:

<!-- thumbnail -->
<div class="thumbnail tright mb-2">
  <img src="{{site.baseurl}}/assets/images/reti/NetworkTopology-Ring.png" class="modal__opener" aprire="#img-NetworkTopology-Ring">
  <p>Rappresentazione di una rete ad anello</p>
</div>
<!-- modal -->
<div id="img-NetworkTopology-Ring" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-NetworkTopology-Ring">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/NetworkTopology-Ring.png">
    </div>
    <p>Rappresentazione di una rete ad anello</p>
  </div>
</div>

- **Topologia ad anello**: nella topologia ad anello ogni nodo è collegato con altri nodi in modo da formare una struttura circolare. Ogni informazione da trasferire deve percorrere l'anello fino al destinatario: per esempio, se consideriamo il messaggio di risposta per la conferma ogni scambio di informazioni coinvolge tutti i nodi della rete, che devono cooperare alla comunicazione anche se non sono direttamente interessati al messaggio. Il guasto di un nodo quindi causa la "caduta" dell'intera rete anche se è facile escludere, anche automaticamente, un nodo dalla rete e ripristinare le comunicazioni.  
Una rete di questo tipo non è neppure particolarmente scalabile poichè per ogni comunicazione devono essere coinvolti tutti gli altri nodi dell'anello.  
Le reti ad anello sono abbastanza economiche e facile da gestire e hanno avuto anche una certa diffusione in passato ma, per i problemi precedentemente descritti, è stata soppiantata nella maggior parte dei casi da topologie più economiche o più efficienti.

<!-- thumbnail -->
<div class="thumbnail tright mb-2">
  <img src="{{site.baseurl}}/assets/images/reti/NetworkTopology-Stella.png" class="modal__opener" aprire="#img-NetworkTopology-Stella">
  <p>Rappresentazione di una rete a stella</p>
</div>
<!-- modal -->
<div id="img-NetworkTopology-Stella" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-NetworkTopology-Stella">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/NetworkTopology-Stella.png">
    </div>
    <p>Rappresentazione di una rete a stella</p>
  </div>
</div>

- **Topologia a stella**: in questa topologia è presente un nodo centrale a cui sono collegati tutti gli altri nodi della rete. Il numero dei canali è uguale al numero di nodi meno uno (quello centrale): c = n - 1.  
La complessità, il costo e la scalabilità di questa rete dipendono completamente dal nodo centrale che deve gestire tutte le comunicazioni e offrire una sufficiente capacità di banda e di robustezza. In questa rete ogni nodo esterno comunica direttamente solo col nodo centrale senza doversi preoccupare di sapere quando può o non può trasmettere (**risolve** il problema delle **collisioni**), come invece avviene in altri tipi di rete (ad es. topologia a bus).  
Il fatto che tutto il traffico passi da un unico nodo comporta che un guasto ad un nodo periferico non causi nessun problema al resto della rete, d'altra parte un guasto al nodo centrale provoca la totale interruzione delle comunicazioni.  
La scalabilità di una rete a stella è piuttosto buona poichè non dipende dalla complessità di gestione del traffico ma solo dal fatto che il nodo centrale sia in grado di gestire la quantità di traffico prodotto dai nodi periferici in ogni momento. Aggiungere un nuovo nodo inoltre è molto semplice e non richiede l'interruzione delle comunicazioni per il resto della rete.  
La topologia a stella è una topologia largamente utilizzata nelle LAN odierne, spesso strutturate con uno switch al centro a cui possono essere collegati anche decine di computer.

<!-- thumbnail -->
<div class="thumbnail tright mb-2">
  <img src="{{site.baseurl}}/assets/images/reti/NetworkTopology-Bus.png" class="modal__opener" aprire="#img-NetworkTopology-Bus">
  <p>Rappresentazione di una rete a bus</p>
</div>
<!-- modal -->
<div id="img-NetworkTopology-Bus" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-NetworkTopology-Bus">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/NetworkTopology-Bus.png">
    </div>
    <p>Rappresentazione di una rete a bus</p>
  </div>
</div>

- **Topologia a bus**
I nodi sono connessi a un unico canale comune, condiviso da tutti. I messaggi, vengono inviati sul canale e tutti i nodi li ricevono, ma solo il nodo che riconosce di essere il destinatario acquisisce messaggio, gli altri lo scartano.  
Le reti a bus sono particolarmente economiche perchè minimizza il numero di canali utilizzati inoltre non richiede nessun dispositivo aggiuntivo (come ad esempio nella rete a stella). Questa topologia è anche molto efficiente dal punto di vista della scalabilità (l'aggiunta di un nodo non comporta aggiunta di collegamenti né interruzione dei collegamenti esistenti) e della robustezza (la rottura del bus porta ad avere comunque un partizionamento della rete in due topologie a bus). L'unico difetto è costituito dal fatto che la presenza di un unico collegamento condiviso tra tutti i nodi richiede di utilizzare meccanismi di controllo dell'accesso che evitino le collisioni o le interferenze tra i nodi. Anche avere troppi nodi collegati ad un unico bus può essere un problema poichè avverrebbero troppe collisioni.  
Per tutti questi motivi le reti con topologia ad hub sono piuttosto diffuse soprattutto in reti di piccole dimensioni (la rete Ethernet nelle sue versioni iniziali, era fisicamente strutturata a bus) anche se l'utilizzo degli switch ha portato ad utilizzare sempre di più la topologia a stella nelle reti cablate.

<!-- thumbnail -->
<div class="thumbnail tright mb-2">
  <img src="{{site.baseurl}}/assets/images/reti/NetworkTopology-Full_Mesh.svg" class="modal__opener" aprire="#img-NetworkTopology-Full_Mesh">
  <p>Rappresentazione di una rete a maglia completa</p>
</div>
<!-- modal -->
<div id="img-NetworkTopology-Full_Mesh" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-NetworkTopology-Full_Mesh">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/NetworkTopology-Full_Mesh.svg">
    </div>
    <p>Rappresentazione di una rete a maglia completa</p>
  </div>
</div>

<!-- thumbnail -->
<div class="thumbnail tright mb-2">
  <img src="{{site.baseurl}}/assets/images/reti/NetworkTopology-Mesh.png" class="modal__opener" aprire="#img-NetworkTopology-Mesh">
  <p>Rappresentazione di una rete parzialmente magliata</p>
</div>
<!-- modal -->
<div id="img-NetworkTopology-Mesh" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-NetworkTopology-Mesh">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/NetworkTopology-Mesh.png">
    </div>
    <p>Rappresentazione di una rete parzialmente magliata</p>
  </div>
</div>

- **Topologia a maglia**: una topologia **completamente magliata** è caratterizzata dal fatto che ogni nodo è collegato con tutti gli altri: ciò significa che esistono tutte le possibili connessioni tra i vari nodi della rete. Una topologia di questo tipo offre sicuramente molti vantaggi: non ci sono problemi di commutazione, la tolleranza ai guasti è ottima visto che è possibile mettere o togliere nodi senza provocare nessun problema al resto della rete.  
Il grande problema di questa topologia è l'enorme numero di collegamenti richesto: *C* = *N* · (*N* - 1) / 2; è quindi impensabile adottare una topologia di questo tipo per una rete che non sia davvero piccola, proprio per il fatto che il numero di collegamente tra i vari nodi diverrebbe troppo elevato, basti pensare che una rete con 25 computer (come un comune laboratorio scolastico di informatica) richiederebbe 300 collegamenti!  
Quando non sono presenti tutti i collegamenti tra ogni coppia di nodi si parla di topologia **parzialmente magliata**. Un modello di questo tipo è utilizzato soprattutto agli alti livelli della rete internet dove è necessario collegare tra loro reti differenti (di differenti ISP o gestori di rete) considerate di pari livello tra loro. 

<!-- thumbnail -->
<div class="thumbnail tright mb-2">
  <img src="{{site.baseurl}}/assets/images/reti/NetworkTopology-Tree.png" class="modal__opener" aprire="#img-NetworkTopology-Tree">
  <p>Rappresentazione di una rete ad albero</p>
</div>
<!-- modal -->
<div id="img-NetworkTopology-Tree" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-NetworkTopology-Tree">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/NetworkTopology-Tree.png">
    </div>
    <p>Rappresentazione di una rete ad albero</p>
  </div>
</div>

- **Topologia ad albero**: questa topologia è una caso particolare di rete parzialmente magliata in cui si forma una struttura di rete essenzialmente gerarchica in cui ogni nodo (a parte il nodo *radice*) è collegato ad un nodo *padre* che lo collega al resto della rete; viceversa un nodo può avere dei nodi *figlo* (a parte i nodi *foglia*) a cui fa da nodo *padre*.  
Le topologie ad albero presentano un elevato grado di affidabilità: l'unico punto debole è costituito dai nodi padre, che, in caso di guasto, rendono impossibile l'accesso alla sottorete che si diparte da essi e che rimane quindi isolata. Va osservato che anche in questo caso la sottorete che rimane isolata, a meno che non sia costituita solo da nodi terminali, rimane comunque funzionante e operativa, essendo sempre possibile la comunicazione tra nodi della sottorete facenti capo a nodi padre comuni non guasti. Nella topologia a stella, invece, il guasto dell'hub comporta la perdita totale della funzionalità di rete, risultando di fatto isolati tutti i nodi componenti.  
Altro vantaggio importante delle topologie ad albero è l'elevata scalabilità: infatti è possibile aggiungere o togliere nodi e connessioni senza modificare la rete né la sua funzionalità, fino al numero massimo di diramazioni consentite dal nodo padre. Inoltre, è molto facile l'accorpamento di più reti in un'unica rete, collegando direttamente tra loro i relativi nodi radice, senza che questo abbia ripercussioni sulle reti preesistenti.  
Questa struttura di rete risulta anche particolarmente semplice da gestire dal punto di vista del routing dei pacchetti.  
Per tutti questi motivi la topologia ad albero è molto utilizzata. Di seguito vedremo ad esempio come la rete internet utilizzi largamente questa topologia.


### Modalità di comunicazione

Le modalità di comunicazione tra host si dividono in due categorie:

- **modalità a connessione** o **connection-oriented**:
    prima dell'inizio della trasmissione si deve stabilire una connessione tra mittente e destinatario che verrà chiusa al termine della comunicazione, si identificani quindi tre fasi:
    - apertura della connessione: il mittente contatta il destinatario e si assicura che esso sia pronto a ricevere le informazioni (si crea la connessione);
    - trasferimento dei dati
    - chiusura della sessione di comunicazione durante la quale rilasciate le risorse usate per la comunicazione.

    Un esempio di comunicazione connection-oriented è la telefonata nella quale prima di comunicare col destinatario si attende che esso risponda alla chiamata e dichiari di essere in ascolto. In questo caso si parla di **comunicazione sincrona** poichè le due parti possono interagire nello stesso momento.
- **modalità senza connessione** o **connectionless**
    in questo tipo di comunicazione i dati vengono trasmessi dal mittente senza avvisare il destinatario, i dati vengono salvati in una memoria dalla quale poi il destinatario sarà in grado di accedere ai dati. Il mittente non sa se e quando il destinatario visualizzerà i dati ricevuti. In questo caso si parla di **comunicazione asincrona**.


### Modalità di utilizzo del canale

La trasmissione dei dati, a seconda della modalità di utilizzo del canale di comunicazione può essere classificata in:

- **simplex**: la trasmissione può avvenire solo in un senso; è il caso tipico delle trasmissioni televisive o radiofoniche dove i ricevitori sono le televisioni e le radio, dispositivi che non sono in grado di inviare alcun messaggio al trasmettitore;
- **half-duplex**: la trasmissione può avvenire nei due sensi ma solo in una direzione per volta poichè il canale trasmissivo è unico e può essere usato solo da un trasmettitore per volta; un esempio e quello del walkie talkie;
- **full-duplex**: la trasmissione può avvenire nei due sensi contemporaneamente poichè sono presenti due canali di trasmissione da poter usare nelle due divese direzioni; un esempio è la comunicazione telefonica.


### Tecniche di multiplazione del canale di comunicazione

Per **multiplazione** si intende la suddivisione nell'uso del canale di comunicazione tra i dispositivi ad esso collegati e che trasmettono segnali su di esso. Le modalità di multiplazione sono due:

- **multiplazione statica**: la suddivisione del canale è fissa e determinata a priori, normalmente avviene manualmente; un esempio è quello delle trasmissioni televisive in cui ad ogni emittente è assegnata una frequenza fissa che non varia nel tempo;
- **multiplazione dinamica**: la suddivisione del canale avviene in tempo reale in modo appunto dinamico o variabile in modo che il canale venga assegnato temporaneamente ad un host o ad una coppia di host; la suddivisione può avvenire in due modi:
  - **preassegnazione**: il canale viene assegnato all'inizio dell'attività, su richiesta, e viene riservato per tutta la durata dell'attività e infine rilasciato, come ad esempio in una telefonata;
  - **assegnazione a domanda**: anche in questo caso le risorse trasmissive viengono assegnate su richiesta ma non vengono rilasciate su iniziativa degli host che le usano, le risorse infatti vengono assegnate solo per determinati intervalli di tempo; in questo modo tutti gli host hanno le stesse opportunità di accedere al canale (sempre che non vengano date delle priorità), inoltre questa modalità permette di ottimizzare l'uso del canale nel caso in cui un'applicazione alterni l'uso del canale con momenti di pausa.

### Modalità di accesso al canale

Sono state sviluppate diverse tecniche per regolare l'utilizzo del canale di comunicazione in modo da evitare sovrapposizioni e ottimizzare i tempi di accesso e comunicazione in reti di tipo broadcast dove cioè più host utilizzano lo stesso canale di comunicazione. Le modalità si dividono in:

- **accesso centralizzato**: esiste un dispositivo detto multiplexer (MUX) che decide, in modo statico o dinamico, chi può comunicare sul canale trasmissivo secondo un'opportuna politica di scheduling.
- **accesso multiplo o distribuito**: sono gli host che decidono quando possono comunicare sul canale, per farlo è necessario che utilizzino opportune tecniche per evitare sovrapposizioni e garantire a tutti gli host un accesso equo al canale; queste tecniche sono:
  - protocolli **deterministici senza contesa** tra cui:
    - protocolli di accesso multiplo a divisione di tempo (TDMA) in cui si preassegnano degli intervalli di tempo in cui ogni host può comunicare sul canale;
    - protocolli di accesso multiplo a divisione di frequenza (FDMA) (o lunghezza d'onda (WDM)) in cui si riservano ad ogni host determinate frequenze o intervalli di frequenze utilizzabili per comunicare sul canale;
    - techiche di passaggio del testimone in cui ogni host può comunicare sul canale per un determinato intervallo di tempo prima di cedere il testimone ad un altro host;

    I primi due metodi sono essenzialmente tecniche di multipazione con preassegnazione mentre l'ultimo equivale ad una multiplazione a domanda poichè ogni host può passare subito il testimone senza trasmettere nulla.

  - protocolli ad **accesso casuale o contesa** in cui la possibilità di accedere al canale in un determinato momento non viene stabilita preventivamente ma il canale viene conteso dagli host ad esso collegati; i principali protocolli sono:
    - **Aloha**, puro o slotted (non lo trattiamo, puoi approfondire [qui](https://it.wikipedia.org/wiki/ALOHAnet) l'argomento)
    - CSMA/CD ovvero *Carrier Sense Multiple Access / Collision Detection*: protocollo molto utilizzato nelle reti a bus e implementato in Ethernet, esso prevede che per comunicare un host esegua le seguenti operazioni:
        1.  verificare se il canale è libero, se non lo è aspetto (carrier sense)
        2.  quando il canale è libero aspettare un periodo di tempo casuale e ricontrollare se il canale è ancora libero, se non lo è torno al punto 1 altrimenti iniziare a trasmettere
        3.  se dopo aver iniziato a trasmettere ci si accorge di una collisione, cioè anche un altro host sta trasmettendo (collision detection), torno al punto 1 e il tempo di attesa del punto 2 viene aumentato (per diminuire la probabilità di una nuova collisione)
        4.  continuare la comunicazione solo per un periodo massimo di tempo, poi liberare il canale

        Questo sistema permette a tutti gli host di poter trasmettere sul canale con le stesse probabilità degli altri host e mediamente per la stessa quantità di tempo. (puoi approfondire [qui](https://it.wikipedia.org/wiki/CSMA/CD) l'argomento)

  - CDMA (Code Division Multiple Access): sistema molto complesso che permette di non dover suddividire il canale tra gli host che possono tutti comunicare contemporaneamente senza confondere tra loro le comunicazioni; è molto utilizzato nelle reti mobili dal 2G in poi. Se ti interessa puoi approfondire [qui](https://people.unica.it/michelenitti/files/2012/04/ST-CM6-CDMA.pdf) l'argomento.


### Tecniche di commutazione

<!-- thumbnail -->
<div class="thumbnail tright mb-2">
  <img src="{{site.baseurl}}/assets/images/reti/commutazione.png" class="modal__opener" aprire="#img-commutazione">
  <p>Schema di un nodo con diversi canali di ingresso e uscita. Il nodo deve effettuare la commutazione (switching) inoltrando il flusso di dati proveniente da un canale di ingresso ad un canale di uscita</p>
</div>
<!-- modal -->
<div id="img-commutazione" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-commutazione">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/commutazione.png">
    </div>
    <p>Schema di un nodo con diversi canali di ingresso e uscita. Il nodo deve effettuare la commutazione (switching) inoltrando il flusso di dati proveniente da un canale di ingresso ad un canale di uscita</p>
  </div>
</div>

In una rete normalmente è necessario gestire comunicazioni che avvengono tra host che non sono direttamente collegati fra loro, in questo caso le informazioni devono transitare da nodi intermedi tra sorgente e destinatario. Ogni nodo ha dei canali da cui possono arrivare informazioni e deve stabilire in quale (o quali) altro canale inoltrare la comunicazione, questo processo di scelta e inoltro si chiama **commutazione** o **switching**.

Quando sarà trattato il livello 3 (rete) della pila ISO-OSI sarà evidente come la commutazione riguardi proprio il livello di rete e in particolare sia effettuata dai router.

Esistono diverse modalità di commutazione e ognuna caratterizza fortemente la rete che la utilizza tanto da rendere queste reti molto diverse l'una dall'altra. Le modalità di commutazione identificano tre principali tipologie di rete:

- le reti commutazione di circuito (circuit switching)
- le reti a commutazione di messaggio (message switching) (poco rilevanti non le tratteremo)
- le reti a commutazione di pacchetto (packet switching)



#### Commutazione di circuito

<!-- thumbnail -->
<div class="thumbnail tright mb-2">
  <img src="{{site.baseurl}}/assets/images/reti/commutazione_di_circuito.png" class="modal__opener" aprire="#img-commutazione_di_circuito">
  <p>Schema di una rete a commutazione di circuito</p>
</div>
<!-- modal -->
<div id="img-commutazione_di_circuito" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-commutazione_di_circuito">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/commutazione_di_circuito.png">
    </div>
    <p>Schema di una rete a commutazione di circuito</p>
  </div>
</div>

Le reti a commutazione di circuito sono caratteristiche delle **reti analogiche** che sono le reti più vecchie. Nelle reti analogiche c'è la necessità di creare un canale fisico dedicato o circuito all'intera comunicazione poichè esso deve essere attraversato da un segnale analogico continuo. I nodi interni della rete devono quindi formare un canale all'inizio della comunicazione e lo devono mantenere fino alla fine della comunicazione. Per capire il funzionamento di questa rete basta pensare a come funzionavano le vecchie reti telefoniche: quando veniva fatta una telefonata, il centralino doveva creare un canale fisico dal dispositivo chiamante fino al dispositivo ricevente, originariamente queste operazioni venivano fatte addirittura a mano e successivamente da dispositivi elettromeccanici. Solo alla fine della chiamata i nodi interni potevano interrompere il circuito e formarne di nuovi per altre comunicazioni.

Questo tipo di rete presenta comunicazioni chiaramente [connection-oriented](#modalità-di-comunicazione)


#### Commutazione di pacchetto

<!-- thumbnail -->
<div class="thumbnail tright mb-2">
  <img src="{{site.baseurl}}/assets/images/reti/commutazione_di_pacchetto_datagram.png" class="modal__opener" aprire="#img-commutazione_di_pacchetto_datagram">
  <p>Schema di una rete a commutazione di pacchetto di tipo datagram. I pacchetti numerati in ordine di trasmissione possono percorrere percorsi diversi.</p>
</div>
<!-- modal -->
<div id="img-commutazione_di_pacchetto_datagram" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-commutazione_di_pacchetto_datagram">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/commutazione_di_pacchetto_datagram.png">
    </div>
        <p>Schema di una rete a commutazione di pacchetto di tipo datagram. I pacchetti numerati in ordine di trasmissione possono percorrere percorsi diversi.</p>
  </div>
</div>

Se nelle comunicazioni analogiche c'è la necessità di creare un canale dedicato, con le **comunicazioni digitali** non c'è più questa necessità. Nelle comunicazioni digitali la comunicazione consiste in un flusso di bit che vengono raggruppati in pacchetti. Non è assolutamente necessario che i pacchetti percorrano i canali di comunicazione tutti insieme ma possono percorrere percorsi diversi nella rete anche mischiandosi a pacchetti riguardanti altre comunicazioni, l'importante è che il destinatario li riceva e sia in grado di ricostruire il flusso di bit originale. Tutto questo comporta importanti vantaggi rispetto ad una rete a commutazione di circuito:
  
- non è necessario dedicare un canale esclusivamente ad una comunicazione, su di esso possono transitarne quante se ne vogliono, purchè il canale abbia sifficiente capacità trasmissiva;
- i flussi di pacchetti possono eseguire percorsi differenti distribuendo il traffico da nodi e canali più trafficati ad altri più liberi

Risulta chiaro quindi come le reti a commutazione di pacchetto siano molto più efficienti delle reti a commutazione di circuito nel gestire le risorse di rete.

Le reti a commutazione di circuito, non riservando risorse dedicate per la comunicazione presentano uno svantaggio piuttosto rilevante: non offrono garanzie sulla banda disponibile, aspetto molto rilevante in comunicazioni real-time. Questo limite è parzialmente superato consentendo di aggiungere livelli di priorità ai pacchetti in transito.

Le reti a commutazione di pacchetto si suddividono in due categorie:

<!-- thumbnail -->
<div class="thumbnail tright mb-2">
  <img src="{{site.baseurl}}/assets/images/reti/commutazione_di_pacchetto_datagram.png" class="modal__opener" aprire="#img-commutazione_di_pacchetto_datagram">
    <p>Schema di una rete a commutazione di pacchetto di tipo datagram. I pacchetti numerati in ordine di trasmissione possono percorrere percorsi diversi.</p>
</div>
<!-- modal -->
<div id="img-commutazione_di_pacchetto_datagram" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-commutazione_di_pacchetto_datagram">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/commutazione_di_pacchetto_datagram.png">
    </div>
    <p>Schema di una rete a commutazione di pacchetto di tipo datagram. I pacchetti numerati in ordine di trasmissione possono percorrere percorsi diversi.</p>
  </div>
</div>

<!-- thumbnail -->
<div class="thumbnail tright mb-2">
  <img src="{{site.baseurl}}/assets/images/reti/commutazione_di_pacchetto_canale_virtuale.png" class="modal__opener" aprire="#img-commutazione_di_pacchetto_canale_virtuale">
    <p>Schema di una rete a commutazione di pacchetto a canali virtuali. I pacchetti numerati in ordine di trasmissione percorrono solo il circuito virtuale.</p>
</div>
<!-- modal -->
<div id="img-commutazione_di_pacchetto_canale_virtuale" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-commutazione_di_pacchetto_canale_virtuale">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/commutazione_di_pacchetto_canale_virtuale.png">
    </div>
    <p>Schema di una rete a commutazione di pacchetto a canali virtuali. I pacchetti numerati in ordine di trasmissione percorrono solo il circuito virtuale.</p>
  </div>
</div>

- di tipo **datagram**: i pacchetti possono percorrere percorsi diversi;
- a **canali virtuali**: i pacchetti appartenenti ad una sessione di comunicazione seguono tutti lo stesso percorso andando a formare un circuito virtuale (e non fisico come nel circuit switching) tra host comunicanti. Questa soluzione permette di risolvere il problema delle comunicazioni real-time con un opportuna configurazione dei nodi intermedi che possono dedicare una determinata quantità di banda al circuito virtuale. In questo caso come nella commutazione di circuito, è necessario inataurare la connessione tra i due estremi del circuito virtuale.


## Architettura della rete internet
La rete internet è un'unica grande rete risultante dall’unione di utte le reti del mondo che sono collegate fra loro. Non è possibile qui catalogarla in base ai criteri precedentemente descritti poichè alcune reti ad esso collegate sono di tipo broadcast, altre punto a punto; delle parti sono cablate, altre no. Dal punto di vista telle topologie però è possibile fare alcune importanti osservazioni. La rete internet non è strutturata secondo un unico modello topologico ma si può notare che a parte nei livelli più alti della rete, la topologia dominante è quella ad albero, la rete internet infatti è fortemente gerarchizzata. 

La rete internet è divisa e gestita da vari [ISP](https://it.wikipedia.org/wiki/Internet_service_provider) ("Internet service provider" o compagnie telefoniche) di vario livello in quanto tale divisione è economicamente vantaggiosa:

1.  **[ISP di primo livello](https://it.wikipedia.org/wiki/Rete_di_primo_livello)** (o globali) che controllano il nucleo della rete, sono internazionali e sono direttamente connessi ad altri ISP di primo livello, a loro poi si collegano gli ISP di livello inferiore; Gli ISP di primo livello formano, quindi, la dorsale principale di Internet (ne fanno parte UUNet, AT&T, Sprint Nextel, ecc.). A questo livello le reti dei vari ISP sono collegate fra loro secondo una topologia a maglia poichè si trovano tutti allo stesso livello.
2.  **[ISP](https://en.wikipedia.org/wiki/Tier_2_network)** di levello nazionale: fanno da tramite tra gli ISP di primo livello e quelli di accesso; Appartengono a questa categoria ISP come Telecom Italia. A questo livello la struttura gerarchica si fa più evidente anche se sono possili collegamenti tra ISP di pari livello.
3.  **ISP locali**, che servono un area ristretta, a loro si connettono gli utenti minori. Qui la topologia è essenzialmente solo ad albero.

Esistono aziende che operano solo a livello di grandi dorsali e o comunicazioni su grandi distanze (ad es. Seabone, Sprint), aziende che operano solo a livello locale e aziende che invece operano a tutti i livelli della rete (ad es. Telecom Italia).

Riprendendo l'analisi della rete dal punto di vista delle topologie, semplificando possiamo quindi dire che le topologie principali sono:

- Livelli alti: parzialmente magliata, poichè gli ISP di primo livello sono collegati tra loro alla pari.
- Livello intermedio (la maggior parte della rete internet): ad albero, fortemente gerarchizzato
- Reti locali: a bus è la più frequente ma possiamo trovare qualsiasi topologia, queste reti sono le foglie rispetto alla struttura ad albero degli ISP


## Altro

### Simulatori di rete

Esistono disponibili in rete diversi [simulatori](https://it.wikipedia.org/wiki/Simulatore "Simulatore") di rete ovvero programmi che consentono di definire lo schema di rete con i vari dispositivi di rete interallacciati tra loro da collegamenti di rete, [configurabili](https://it.wikipedia.org/wiki/Configurazione_(informatica) "Configurazione (informatica)") e testabili (es. simulatori [CISCO](https://it.wikipedia.org/wiki/Cisco_Systems "Cisco Systems"), [Juniper](https://it.wikipedia.org/wiki/Juniper_Networks "Juniper Networks"), [distribuzioni Linux](https://it.wikipedia.org/wiki/Distribuzione_Linux "Distribuzione Linux") apposite (es. Netkit), ecc.).

Un software utilizzabile per simulare la creazione di una rete e la sua gestione a livello 2 e 3 è CISCO Packet Tracer.