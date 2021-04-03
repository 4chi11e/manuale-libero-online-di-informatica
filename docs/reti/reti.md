---
layout: default
title: Reti
nav_order: 2
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
- **Pacchetto** (packet)- nelle reti digitali i dati vengono raggruppati in pacchetti con formati definiti dai vari protocolli di comunicazione
- **Intestazione** (header) - Ogni pacchetto è diviso il due parti, la parte iniziale detta intestazione o header è la parte in cui sono inserite le informazioni riguardanti il pacchetto come indirizzi di destinazione e provenienza. 
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

## Tipologie di rete

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
I cavi di rame hanno una caratteristica, per trasmettere un'informazione hanno bisogno di essere percorsi da una corrente elettrica. Secondo le leggi della fisica una corrente elettrica crea un campo elettrico intorno al conduttore e viceversa un campo elettrico genera una corrente elettrica in un conduttore. Per questo motivo i cavi di rame sono sensibili ai disturbi creati da altri cavi sia di rete che di alimentazione. Per questo motivo spesso i cavi vengono schermati con delle "armature" di metallo che circondano il cavo.  
In ogni caso i cavi ethernet, anche nelle migliori condizioni, non riescono a trasmettere un segnale di sufficiente qualità oltre i 100 metri.
> - cavi in **fibra ottica** sono basati su un principio completamente diverso per trasmettere i segnali, essi infatti possono essere descritti schematicamente come dei tubi vuoti il cui interno è rivestito da un materiale che riflette la luce. In questo modo sono in grado di essere percorsi da segnali luminosi per distanze molto più lunghe rispetto ad un cavo di rame. In generale un cavo in fibra ottica permette inoltre una maggior velocità di trasmissione rispetto ai cavi di rame. è per questo motivo che le grandi dorsali di rete sono fatte in fibra ottica.
- **Reti wireless** o senza fili: sono reti in cui le comunicazioni non avvengono attraverso un cavo ma via radio. Esistono diversi tipi di reti wireless: Wi-Fi, Bluetooth, reti per telefoni cellulari di vario genere, normalmente suddivise in diverse generazioni (3G, 4G, 5G ...), reti satellitari...  
In tutte queste reti i dispositivi per comunicare tra loro usano antenne che trasmettono segnali via radio. Quello che cambia tra le varie reti sono i protocolli di comunicazione e le frequenze utilizzate. Quando si parla di reti wireless il canale di comunicazione è una specifica frequenza (o intervallo di frequenze) radio.  
Le frequenze non sono tutte uguali, e possono presentare vantaggi e svantaggi. In generale più la frequenza è alta più è alta la velocità di trasmissione dei dati. Frequenze molto alte però hanno il problema di essere facilmente bloccate da ostacoli fisici ed è necessaria una *linea di visuale* tra le antenne comunicanti. Le frequenze di questo tipo più usate sono dell'ordine dei Ghz e sono parzialmente usate dal Wi-Fi (che usa anche frequenze più basse, più lente ma con gittata maggiore) e saranno ampiamente usate dal 5G che avrà bisogno di diffusione capillare nel territorio e assenza di ostacoli (motivo per cui abbattono gli alberi che contenendo acqua ostacolano pesantemente il segnale).  
Le frequenze usate da televisione radio sono più lente ma sono anche quelle che si trasmettono meglio, motivo per cui si sta cercando di diminuire le frequenze usate da queste tecnologie (vedi cambiamento delle frequenze per i canali televisivi con necessità di risintonizzare il televisore ogni pochi anni magari dovendo anche cambiare decoder) per lasciarle alle nuove generazioni di reti di telecomunicazioni.

### Classificazione in base alla topologia di rete



## Architettura della rete internet
La rete internet è invece un’unica grande rete risultante dall’unione di utte le reti del mondo che sono collegate fra loro. Non è possibile qui catalogarla in base ai criteri precedentemente descritti poichè alcune reti ad esso collegate sono di tipo broadcast, altre punto a punto; delle parti sono cablate, altre no. Ogni rete a seconda dell'estensione, o di particolari esigenze adotta una topologia piuttosto che un'altra.
Dal punto di vista della gestione si può però notare una precisa struttura gerarchica. La rete internet è divisa e gestita da vari [ISP](https://it.wikipedia.org/wiki/Internet_service_provider) ("Internet service provider" o compagnie telefoniche) di vario livello in quanto tale divisione è economicamente più vantaggiosa:

1.  [ISP di primo livello](https://it.wikipedia.org/wiki/Rete_di_primo_livello) (o globali) che controllano il nucleo della rete, sono internazionali e sono direttamente connessi ad altri ISP di primo livello, a loro poi si collegano gli ISP di livello inferiore; Gli ISP di primo livello formano, quindi, la dorsale principale di Internet (ne fanno parte UUNet, AT&T, Sprint Nextel, ecc.);
2.  [ISP](https://en.wikipedia.org/wiki/Tier_2_network) di levello nazionale: fanno da tramite tra gli ISP di primo livello e quelli di accesso; Appartengono a questa categoria ISP come Telecom Italia.
3.  ISP locali, che servono un area ristretta, a loro si connettono gli utenti minori.

Esistono aziende che operano solo a livello di grandi dorsali e o comunicazioni su grandi distanze (ad es. Seabone, Sprint), aziende che operano solo a livello locale e aziende che invece operano a tutti i livelli della rete (ad es. Telecom Italia).





















































# --- DA QUI SCHIFEZZE ---

### Componenti hardware di una rete

_Lo stesso argomento in dettaglio: **[Dispositivo di rete](https://it.wikipedia.org/wiki/Dispositivo_di_rete "Dispositivo di rete")**_

hardware detti anche [dispositivi di rete](https://it.wikipedia.org/wiki/Dispositivo_di_rete "Dispositivo di rete"):<sup id="cite_ref-:0_1-0" class="reference">[[1]](https://it.wikipedia.org/wiki/Rete_di_computer#cite_note-:0-1)</sup>

*   [router](https://it.wikipedia.org/wiki/Router "Router")
*   [modem](https://it.wikipedia.org/wiki/Modem "Modem")
*   [Switch](https://it.wikipedia.org/wiki/Switch "Switch")
*   [Access point](https://it.wikipedia.org/wiki/Access_point "Access point")
*   [client](https://it.wikipedia.org/wiki/Client "Client")
*   [server](https://it.wikipedia.org/wiki/Server "Server")
*   [DNS](https://it.wikipedia.org/wiki/DNS "DNS")
*   [proxy](https://it.wikipedia.org/wiki/Proxy "Proxy")
*   [nat](https://it.wikipedia.org/wiki/Network_address_translation "Network address translation")

I componenti [software](https://it.wikipedia.org/wiki/Software "Software") di una rete sono detti [protocolli di rete](https://it.wikipedia.org/wiki/Protocollo_di_rete "Protocollo di rete"). Potete trovarne una lista [qui](https://it.wikipedia.org/wiki/Protocollo_di_rete#Elenco_di_protocolli_di_rete_secondo_ISO/OSI "Protocollo di rete").

Solitamente, nel gergo dei progettisti di rete, con la dizione _apparati di rete_ s'intendono i dispositivi dell'infrastruttura a supporto di server e cablaggio, considerati essenziali. In reti che supportano [domini](https://it.wikipedia.org/wiki/Dominio_(informatica) "Dominio (informatica)") complessi, le tipologie di apparati utilizzati sono ancora più numerose.

### Tecnologie trasmissive

*   [Doppino telefonico](https://it.wikipedia.org/wiki/Doppino_telefonico "Doppino telefonico")
*   [Cavo coassiale](https://it.wikipedia.org/wiki/Cavo_coassiale "Cavo coassiale")
*   [Fibra ottica](https://it.wikipedia.org/wiki/Fibra_ottica_multimodale "Fibra ottica multimodale")
*   [Antenne radiotelevisive](https://it.wikipedia.org/wiki/Antenne_radiotelevisive_centralizzate "Antenne radiotelevisive centralizzate")
*   [Reti satellitari](https://it.wikipedia.org/wiki/Telecomunicazioni_satellitari "Telecomunicazioni satellitari")

## Tipi di reti

Esiste una grande varietà di tecnologie di rete e di modelli organizzativi, che possono essere classificati secondo diversi aspetti:

### Classificazione sulla base dell'estensione geografica

A seconda dell'estensione geografica, si distinguono diversi tipi di reti:

*   si parla di _rete locale_ o [LAN](https://it.wikipedia.org/wiki/Local_Area_Network "Local Area Network") (_Local Area Network_) se la rete si estende all'interno di un edificio o di un comprensorio, con una estensione nell'ordine del centinaio di metri<sup id="cite_ref-2" class="reference">[[2]](https://it.wikipedia.org/wiki/Rete_di_computer#cite_note-2)</sup>.
*   si parla di _rete universitaria_ o [CAN](https://it.wikipedia.org/wiki/Campus_Area_Network "Campus Area Network") (_Campus Area Network_), intendendo la rete interna ad un campus universitario, o comunque ad un insieme di edifici adiacenti, separati tipicamente da terreno di proprietà dello stesso ente, che possono essere collegati con cavi propri senza far ricorso ai servizi di operatori di telecomunicazioni. Tale condizione facilita la realizzazione di una rete di interconnessione ad alte prestazioni e a costi contenuti.
*   si parla di _rete metropolitana_ o [MAN](https://it.wikipedia.org/wiki/Metropolitan_Area_Network "Metropolitan Area Network") (_Metropolitan Area Network_) se la rete si estende all'interno di una città.
*   si parla di _rete geografica_ o [WAN](https://it.wikipedia.org/wiki/Wide_Area_Network "Wide Area Network") (_Wide Area Network_) se la rete ricopre un'area geografica molto estesa e che intercorre nelle reti precedenti.
*   si parla di _rete globale_ o [GAN](https://it.wikipedia.org/wiki/Global_Area_Network "Global Area Network") (_Global Area Network_) se la rete collega calcolatori dislocati in tutto il mondo, anche via satellite.

### Classificazione in base al canale trasmissivo

#### Reti locali

_Lo stesso argomento in dettaglio: **[Local Area Network](https://it.wikipedia.org/wiki/Local_Area_Network "Local Area Network")**_

Le [reti locali](https://it.wikipedia.org/wiki/Local_Area_Network "Local Area Network") (_Local Area Network_ o LAN) vengono realizzate tipicamente utilizzando un sistema di [cablaggio](https://it.wikipedia.org/wiki/Cablaggio "Cablaggio") strutturato con cavi [UTP](https://it.wikipedia.org/wiki/Unshielded_Twisted_Pair "Unshielded Twisted Pair") in categoria 5 o superiore, che servono uno o più edifici utilizzati tipicamente da una stessa entità organizzativa, che realizza e gestisce la propria rete, eventualmente con la cooperazione di aziende specializzate. In molti casi il cablaggio è complementato o sostituito da una copertura wireless.

Le LAN vengono realizzate soprattutto con la tecnologia [ethernet](https://it.wikipedia.org/wiki/Ethernet "Ethernet") che supportano velocità di 1 Gbit/s o anche 10 Gbit/s, su cavi in rame dalle caratteristiche adeguate (CAT5 o superiore), o su fibra ottica.

#### Reti pubbliche

Le reti pubbliche sono gestite da operatori del settore e offrono servizi di telecomunicazione a privati e aziende in una logica di mercato.

Per poter offrire servizi al pubblico, è necessario disporre di una infrastruttura di distribuzione che raggiunga l'intera popolazione.

Per ragioni storiche, parecchie reti pubbliche sono basate sul [doppino telefonico](https://it.wikipedia.org/wiki/Doppino_telefonico "Doppino telefonico") (dette anche [POTS](https://it.wikipedia.org/wiki/POTS "POTS"), _Plain Old Telephone System_). Questa tecnologia era stata studiata per supportare il servizio di telefonia analogica, ma data la sua pervasività e gli alti investimenti che servivano per sostituirla è stata adattata al trasporto di dati mediante diverse tecnologie, ad oggi è stata quasi interamente sostituita dalla fibra ottica:

*   i [modem](https://it.wikipedia.org/wiki/Modem "Modem") per codificare segnali digitali sopra le comuni linee telefoniche analogiche. Il vantaggio di questa tecnologia è che non richiede modifiche alla rete distributiva esistente in quanto utilizza la linea telefonica già esistente e trasmette i dati ad una frequenza superiore alla banda telefonica che arriva a 4KHz. Sono necessari due modem ai due capi di una connessione telefonica attiva per stabilire una connessione. La velocità è limitata a circa 56 Kbit/s, con l'adozione di modem client e server che supportano la versione [V92](https://it.wikipedia.org/w/index.php?title=V92&action=edit&redlink=1 "V92 (la pagina non esiste)") dei protocolli di comunicazione per modem. Questo protocollo incorpora funzioni di compressione del flusso di bit trasmesso, quindi la velocità effettiva dipende dal fattore di compressione dei dati trasmessi.
*   le reti [ISDN](https://it.wikipedia.org/wiki/ISDN "ISDN") (_Integrated Services Digital Network_) trasmettendo dati e voce su due canali telefonici in tecnologia digitale. Mediante appositi adattatori, è possibile inviare direttamente dati digitali. La tecnologia ISDN, quando è usata per la trasmissione di dati, arriva ad una velocità massima di 128 Kbit/s, senza compressione, sfruttando in pratica due connessioni dial-up in parallelo, possibili solo con determinati provider. La velocità su un singolo canale è invece limitata a 64 Kbit/s. Ci sarebbe un terzo canale utilizzato per il segnale ma non per la comunicazione con una capacità di 16 Kbit/s (Esso non viene mai utilizzato per i dati).

Utilizzando modem analogici o ISDN, è possibile stabilire una connessione dati diretta tra due qualsiasi utenze della rete telefonica o ISDN rispettivamente.

*   la tecnologia [ADSL](https://it.wikipedia.org/wiki/ADSL "ADSL") (_Asymmetric Digital Subscriber Line_) utilizza una porzione della banda trasmissiva disponibile sul doppino telefonico dalla sede dell'utente alla centrale telefonica più vicina per inviare dati digitali. È necessaria l'installazione di nuovi apparati di commutazione nelle centrali telefoniche, chiamati [DSLAM](https://it.wikipedia.org/wiki/DSLAM "DSLAM"), e l'utilizzo di filtri negli impianti telefonici domestici per separare le frequenze utilizzate per la trasmissione dati da quelle per la comunicazione vocale. La loro diffusione sul territorio è limitata dai costi, che la rendono conveniente solo nelle aree maggiormente sviluppate. Durante la connessione tramite ADSL è possibile continuare a utilizzare il telefono, in quanto le frequenze della voce e dei dati non si sovrappongono. Questa tecnologia è inoltre chiamata _Asymmetric_ in quanto le velocità di download e di upload non sono uguali: in Italia sono tipicamente pari a 4 Mbit/s in download e 512 Kbit/s in upload, ma per certi abbonamenti la velocità di download può arrivare a 12 Mbit/s o anche 20 Mbit/s, usando tecnologie di punta come [ADSL2+](https://it.wikipedia.org/wiki/ADSL2%2B "ADSL2+") e reti di distribuzione in fibra ottica di ottima qualità. Il doppino di rame presenta l'inconveniente di attenuare i segnali, e non permette il funzionamento di questa tecnologia per distanze superiori ai 5 km circa. In alcuni casi è anche possibile un'ulteriore riduzione della distanza massima dovuta a interferenze esterne che aumentano la probabilità d'errore. Un'altra limitazione importante è data dall'interferenza "interna", che si verifica quando molte utenze telefoniche sullo stesso cavo di distribuzione utilizzano il servizio ADSL. Questo fa sì che non si possa attivare il servizio ADSL su più di circa il 50% delle linee di un cavo di distribuzione.
*   la fibra ottica è attualmente utilizzata in più varianti [FTTx](https://it.wikipedia.org/wiki/FTTx "FTTx"): può arrivare fino al cabinet o anche in casa, ha velocità di trasmissione dati che arrivano fino a 1 Gbit/s per gli utenti domestici.<sup id="cite_ref-3" class="reference">[[3]](https://it.wikipedia.org/wiki/Rete_di_computer#cite_note-3)</sup>

#### Reti di trasporto

Capacità ancora superiori sono necessarie per trasportare il traffico aggregato tra le centrali di un operatore di telecomunicazioni attraverso quella che è comunemente chiamata [rete di trasporto](https://it.wikipedia.org/wiki/Rete_di_trasporto "Rete di trasporto").

Con tecnologie più costose, tipicamente utilizzate dai provider, si raggiungono velocità di 40 Gbit/s per il singolo link su fibra ottica.

Su una singola fibra è poi possibile inviare molteplici segnali attraverso una tecnica di multiplazione chiamata (Dense) [Wavelength Division Multiplexing](https://it.wikipedia.org/wiki/Wavelength_Division_Multiplexing "Wavelength Division Multiplexing") ((D) WDM), o Multiplazione di Lunghezza d'Onda, che invia segnali ottici differenti a diverse lunghezze d'onda (in gergo, _colori_). Il numero di segnali indipendenti trasportabile va dai 4 o 16 dei relativamente economici impianti (Coarse) WDM alle centinaia degli impianti DWDM più avanzati.

Negli [Stati Uniti d'America](https://it.wikipedia.org/wiki/Stati_Uniti_d%27America "Stati Uniti d'America") il progetto [Internet2](https://it.wikipedia.org/wiki/Internet2 "Internet2"), cui collaborano la [NASA](https://it.wikipedia.org/wiki/NASA "NASA"), la difesa e le università americane, connette già molti campus alla velocità di 2 Gigabit/s (disponibili anche per studenti), con miglioramenti di [TCP/IP](https://it.wikipedia.org/wiki/TCP/IP "TCP/IP") per poter sfruttare alte velocità di trasmissione.

## Topologia della rete

### Classificazione in base alla gerarchia dei nodi

In base alla gerarchia dei suoi nodi è possibile distinguere le seguenti tipologie di reti:

*   _reti [client-server](https://it.wikipedia.org/wiki/Client-server "Client-server")_: i nodi sono o dei client (chi chiede dati o risorse) o dei server (sistemi che rispondono alle richieste inoltrate dai client);
*   _reti [peer-to-peer](https://it.wikipedia.org/wiki/Peer-to-peer "Peer-to-peer")_: tutti i nodi sono sia client che server, tutti trasmettono e ricevono dati contemporaneamente;
*   reti ibride.

### Sezioni di una rete

In ogni rete di grandi dimensioni (WAN), è individuabile una **sezione di accesso**, che dà vita alla [rete di accesso](https://it.wikipedia.org/wiki/Rete_di_accesso "Rete di accesso"), e una **sezione di trasporto**, che dà vita alla [rete di trasporto](https://it.wikipedia.org/wiki/Rete_di_trasporto "Rete di trasporto").

La **sezione di accesso** ha lo scopo di consentire l'accesso alla rete da parte dell'utente, e quindi di solito rappresenta una sede di risorse _indivise_ (Si pensi ai collegamenti ADSL commerciali: La porzione di cavo che ci collega alla centrale è un [doppino telefonico](https://it.wikipedia.org/wiki/Doppino_telefonico "Doppino telefonico"), utilizzato esclusivamente dall'abbonato). La sezione di accesso altresì comprende tutti quegli strumenti idonei a consentire l'accesso alla rete. Quindi possiamo distinguere vari tipi di accesso: "Residenziale" (Classica linea a 56 Kbit/s, linea ISDN/ADSL), "Business" (Rete Locale dell'azienda e Gateway o Proxy che consente l'accesso all'esterno), "Mobile" (si pensi ad esempio al GSM, che consente un accesso basato su una rete a radiofrequenza con copertura "cellulare"), o "Wireless".

La **sezione di trasporto** è quella che ha il compito di trasferire l'informazione tra vari nodi di accesso, utilizzando se è necessario anche nodi di transito. È sede quindi di risorse _condivise_ sia di [trasporto](https://it.wikipedia.org/wiki/Modo_di_trasferimento "Modo di trasferimento") dati sia di elaborazione. Dal punto di vista strutturale, una rete di trasporto è costruita quasi esclusivamente attraverso fibre ottiche (es. [Backbone](https://it.wikipedia.org/wiki/Dorsale_(informatica) "Dorsale (informatica)")).

## Architettura protocollare

Una rete di calcolatori è strutturata a livello logico-funzionale in una tipica [architettura di rete](https://it.wikipedia.org/wiki/Architettura_di_rete "Architettura di rete") cioè con uno [stack protocollare](https://it.wikipedia.org/wiki/Protocollo_di_rete "Protocollo di rete") per l'espletamento dell'insieme delle funzionalità di rete. I vari protocolli servono a gestire specifiche funzionalità della rete nei suoi vari livelli in modo che tutto funzioni correttamente. Ciò serve a permettere una corretta comunicazione tra dispositivi anche molto diversi tra loro.

### Livelli di rete

La rete è divisa in 5 livelli (dal più alto al più basso):<sup id="cite_ref-4" class="reference">[[4]](https://it.wikipedia.org/wiki/Rete_di_computer#cite_note-4)</sup>

*   livello 5: applicativo, i protocolli di livello applicazione sono distribuiti su più sistemi periferici e permette alle applicazioni presenti su questi sistemi di comunicare tra loro scambiandosi messaggi;
*   livello 4: trasporto, implementa i protocolli che si occupano del trasferimento del messaggio e della loro frammentazione in pacchetti. I principali protocolli sono il TCP e l'UDP;
*   livello 3: rete, implementa il protocollo IP che si occupa dell'[instradamento](https://it.wikipedia.org/wiki/Instradamento "Instradamento") e dell'[inoltro](https://it.wikipedia.org/w/index.php?title=Inoltro&action=edit&redlink=1 "Inoltro (la pagina non esiste)") dei datagrammi (o pacchetti) da un host a un altro tramite degli appositi algoritmi di routing;
*   livello 2: linea (o collegamento), i servizi forniti da questo livello dipendono dallo specifico protocollo utilizzato e dalla tecnologia trasmissiva della rete;
*   livello 1: fisico, si occupa dell'invio e della lettura dei singoli bit delle trame.

### Protocolli di trasmissione

#### TCP (Trasmission Control Protocol)

_Lo stesso argomento in dettaglio: **[Transmission Control Protocol](https://it.wikipedia.org/wiki/Transmission_Control_Protocol "Transmission Control Protocol")**_.

Il servizio [TCP](https://it.wikipedia.org/wiki/Transmission_Control_Protocol "Transmission Control Protocol") (di livello 4, trasporto) è di tipo connection-oriented (tra mittente e destinatario viene instaurata una connessione prima di procedere alla trasmissione dei dati). Fornisce un controllo sulla congestione della rete regolando la quantità dei dati trasmessi istante per istante per impedire di sovraccaricare la rete. Con controllo di flusso il trasmettitore invia tanti dati quanti il ricevitore è in grado di ricevere. Controllo d'errore, in caso di errori o perdita dei dati questi ultimi vengono ritrasmessi.<sup id="cite_ref-5" class="reference">[[5]](https://it.wikipedia.org/wiki/Rete_di_computer#cite_note-5)</sup>

#### UDP (User Datagram Protocol)

_Lo stesso argomento in dettaglio: **[User Datagram Protocol](https://it.wikipedia.org/wiki/User_Datagram_Protocol "User Datagram Protocol")**_.

<div class="thumb tright">

<div class="thumbinner" style="width:222px;">[![](./Rete di computer - Wikipedia_files/220px-Header_of_UDP.jpg)](https://it.wikipedia.org/wiki/File:Header_of_UDP.jpg)

<div class="thumbcaption">

<div class="magnify">[](https://it.wikipedia.org/wiki/File:Header_of_UDP.jpg "Ingrandisci")</div>

Header UDP</div>

</div>

</div>

Il servizio [UDP](https://it.wikipedia.org/wiki/User_Datagram_Protocol "User Datagram Protocol") (di livello 4, trasporto) è di tipo connectionless (invio i dati senza aver instaurato una connessione con il destinatario). Questo servizio non è affidabile in quanto non fornisce garanzie riguardo alla corretta ed effettiva consegna dei messaggi (chiamati datagram), non esegue alcun tipo di controllo di flusso e congestione.<sup id="cite_ref-6" class="reference">[[6]](https://it.wikipedia.org/wiki/Rete_di_computer#cite_note-6)</sup>

#### IP (Internet Protocol)

_Lo stesso argomento in dettaglio: **[Internet Protocol](https://it.wikipedia.org/wiki/Internet_Protocol "Internet Protocol")**_.

L'IP (di livello 3, rete) si occupa della multiplazione dei pacchetti, ovvero scrittura e lettura degli indirizzi IP del mittente e del destinatario. Il suo sistema di trasmissione è best-effort, ovvero fa il possibile perché i pacchetti giungano a destinazione ma non offre alcun tipo di garanzia e controllo d'errore, controlla solo che gli indirizzi non siano danneggiati. Viene anche implementato il TTL (Time To Leave) ovvero il tempo di vita del pacchetto espresso in numero massimo di router che il pacchetto può attraversare prima di essere scartato.<sup id="cite_ref-7" class="reference">[[7]](https://it.wikipedia.org/wiki/Rete_di_computer#cite_note-7)</sup>

### Router

_Lo stesso argomento in dettaglio: **[Router](https://it.wikipedia.org/wiki/Router "Router")**_.

I [router](https://it.wikipedia.org/wiki/Router "Router") sono apparati fondamentali della rete che permettono la connessione di più host tra di loro e tra reti diverse. Un router possiede più interfacce di rete, anche diverse tra loro, ed è implementato fino al livello 3 ovvero il livello di trasporto. Questo apparato di rete (o nodo) tramite il routing permette a due nodi, non collegati direttamente, di comunicare tra di loro mediante la collaborazione di altri nodi. Si avvale di una tabella di routing e relativi algoritmi per determinare il percorso ideale per l'inoltro dei pacchetti. Per eseguire l'inoltro dei pacchetti il router dispone di più [buffer](https://it.wikipedia.org/wiki/Buffer "Buffer") (di ingresso e di uscita) dove vengono salvati in modo temporaneo i dati. Dalla porta in ingresso viene letta la destinazione del pacchetto, il processore del router tramite la tabella di routing decide la porta di uscita, il pacchetto viene trasferito dal buffer di ingresso a quello di uscita per essere trasmesso.

### Architettura client-server

_Lo stesso argomento in dettaglio: **[Sistema client/server](https://it.wikipedia.org/wiki/Sistema_client/server "Sistema client/server")**_.

Spesso le reti informatiche sono organizzate sotto un'architettura [client-server](https://it.wikipedia.org/wiki/Client-server "Client-server") dove il [client](https://it.wikipedia.org/wiki/Client "Client") istanzia una richiesta di servizio al [server](https://it.wikipedia.org/wiki/Server "Server") per usufruire di risorse condivise tra tutti gli utenti della rete. I client sono solo in grado di inviare richieste ai server e questi ultimi solo di comunicare tra di loro e di rispondere ai client.<sup id="cite_ref-8" class="reference">[[8]](https://it.wikipedia.org/wiki/Rete_di_computer#cite_note-8)</sup>

### Architettura peer-to-peer

_Lo stesso argomento in dettaglio: **[Peer-to-peer](https://it.wikipedia.org/wiki/Peer-to-peer "Peer-to-peer")**_.

<div class="thumb tright">

<div class="thumbinner" style="width:312px;">[![](./Rete di computer - Wikipedia_files/P2ptv.PNG)](https://it.wikipedia.org/wiki/File:P2ptv.PNG)

<div class="thumbcaption">

<div class="magnify">[](https://it.wikipedia.org/wiki/File:P2ptv.PNG "Ingrandisci")</div>

Generica rete [peer-to-peer](https://it.wikipedia.org/wiki/Peer-to-peer "Peer-to-peer"): notare che i client ritrasmettono i flussi di dati ad altri client comportandosi quindi da peer.</div>

</div>

</div>

In questa architettura tutti i dispositivi connessi alla rete hanno le stesse capacità, tutti possono inviare e ricevere dati comunicando con gli altri peer. Vi è un server che tiene una lista aggiornata di tutti i computer connessi in modo tale che chi si connette è in grado di iniziare subito a comunicare con i peer adiacenti. Una particolare politica adottata da questo sistema è scaricare per primi i dati più rari per poi procedere a scaricare i dati più facilmente reperibili.<sup id="cite_ref-9" class="reference">[[9]](https://it.wikipedia.org/wiki/Rete_di_computer#cite_note-9)</sup>

## Simulatori di rete

Esistono disponibili in rete diversi [simulatori](https://it.wikipedia.org/wiki/Simulatore "Simulatore") di rete ovvero programmi che consentono di definire lo schema di rete con i vari dispositivi di rete interallacciati tra loro da collegamenti di rete, [configurabili](https://it.wikipedia.org/wiki/Configurazione_(informatica) "Configurazione (informatica)") e testabili (es. simulatori [CISCO](https://it.wikipedia.org/wiki/Cisco_Systems "Cisco Systems"), [Juniper](https://it.wikipedia.org/wiki/Juniper_Networks "Juniper Networks"), [distribuzioni Linux](https://it.wikipedia.org/wiki/Distribuzione_Linux "Distribuzione Linux") apposite (es. Netkit), ecc.).