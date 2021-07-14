---
layout: default
title: Livello 4 - Trasporto
nav_order: 4
parent: ISO/OSI
grand_parent: Reti
has_children: False
---

# Livello 4: Trasporto (Transport Layer)
{: .no_toc}

## Indice
{: .no_toc .text-delta }

- TOC
{:toc}

_Obiettivo: permettere un trasferimento di dati trasparente e affidabile (implementando anche un controllo degli errori e delle perdite) tra due host. È il primo livello realmente end-to-end, cioè da host sorgente a host destinatario._

Il livello di trasporto è il livello che separa i livelli inferiori, che si occupano della gestione della rete, dai livelli superiori i quali non si devono preoccupare della natura della rete usata per stabilire la comunicazione. Nessun dispositivo di rete opera a questo livello (solo in parte i router) ma solo gli host che non si occupano di ciò che avviene nei canali di comunicazione e nei nodi lungo il percorso fatto dai pacchetti. In questo senso il livello di trasporto si occupa quindi di offrire alle applicazioni un canale di comunicazione *trasparente* (non importa cosa avviene ai livelli inferiori) e *affidabile* (ci si occupa dell'effettiva integrità dei dati).

Di seguito vengono riportati i servizi che vengono, in genere, offerti dal livello di trasporto; è bene ricordare che nessuno di tali servizi è obbligatorio. Di conseguenza, per ciascuna applicazione è possibile scegliere il protocollo più adatto allo scopo.

- *Servizio orientato alla connessione*. In genere il livello rete non stabilisce una connessione persistente verso l'host di destinazione. Il livello di trasporto si incarica, quindi, di realizzare una connessione persistente che viene poi chiusa quando non è più necessaria.
- *Corretto ordine di consegna*. Poiché i pacchetti possono seguire percorsi diversi all'interno della rete, non c'è alcuna garanzia che i dati vengano recapitati nello stesso ordine in cui sono stati inviati. Il livello di trasporto verifica che i pacchetti vengano riordinati nella giusta sequenza in ricezione prima di passarli al livello superiore.
- *Trasferimento affidabile*. Il protocollo si occupa di garantire che tutti i dati inviati vengano ricevuti; nel caso il servizio di rete utilizzato perda pacchetti, il protocollo di trasporto si occupa di ritrasmetterli al mittente sotto forma di file corrotti.
- *Controllo di flusso*. Se gli host coinvolti nella comunicazione hanno prestazioni molto differenti può capitare che un pc più veloce "inondi" di dati uno più lento portando alla perdita di pacchetti. Mediante il controllo di flusso, un host in "difficoltà" può chiedere di abbassare il tasso di trasmissione in modo da poter gestire le informazioni in ingresso.
- *Controllo di Congestione*: il protocollo riconosce uno stato di congestione della rete e adatta di conseguenza la velocità di trasmissione.
- *Orientamento al Byte*. Invece che gestire i dati in base ai pacchetti, viene fornita la possibilità di vedere la comunicazione come uno stream di byte, in modo da semplificarne l'utilizzo.
- *Multiplazione*. Il protocollo permette di stabilire diverse connessioni contemporanee tra gli stessi due host, tipicamente utilizzando l'astrazione delle porte. Nell'uso comune diversi servizi utilizzano porte logiche di comunicazione diverse.

[Link](https://it.wikipedia.org/wiki/Livello_di_trasporto "Livello di trasporto") alla pagina wikipedia dedicata al livello di trasporto.

## Le porte
Le porte sono lo strumento utilizzato per realizzare la multiplazione delle connessioni a livello di trasporto, ovvero per permettere ad un calcolatore di effettuare più connessioni contemporanee verso altri calcolatori, facendo in modo che i dati contenuti nei pacchetti in arrivo vengano indirizzati al processo che li sta aspettando. Il termine porta è mutuato direttamente da quello di porta fisica di connessione tra cavi di un calcolatore o di un qualunque altro dispositivo elettronico, ma di fatto nell'ambito della trasmissione dei dati durante una connessione non c'è altra porta fisica oltre a quella di aggancio del connettore del cavo. Nell'ambito delle reti di telecomunicazioni il termine porta indica quindi solamente una *porta virtuale* o *logica* e può essere vista banalmente come un'etichetta (label) sotto forma di numero che identifica e discrimina il traffico dati di una connessione da quello di un'altra.

Il numero di porta è indicato in TCP e UDP da una sequenza di 16 bit per cui è possibile identificare 2<sup>16</sup> = 65536 connessioni logiche differenti da o verso un determinato host. 

I numeri di porta sono raggruppati in tre diverse categorie:
- le *porte note* (well known ports) appartengono all'intervallo 0-1023 e sono fissate a specifici servizi;
- le *porte registrate* appartengono all'intervallo 1024-49151 e sono associate sotto richiesta di aziende private a servizi da loro offerti;
- le *porte libere* appartengono all'intervallo 49152-65535 e non sono associate a nessun servizio in particolare, sono quindi liberamente utilizzabili.

A questo [link](https://en.wikipedia.org/wiki/List_of_TCP_and_UDP_port_numbers) è possibile trovare l'elenco di tutte le associazioni tra porte e servizi registrate.

## Le socket
Definito il significato di porta è possibile quindi comprendere come una connessione tra due host a livello di trasporto sia definita da una coppia di valori: un indirizzo IP che identifica l'host, e un numero di porta che indica la connessione logica a quel determinato host. Quando un'applicazione vuole instaurare una connessione con un'applicazione di un altro host collegato in rete, crea una socket che è la struttura dati che identifica una specifica connessione. 

## Protocolli di livello 4: TCP e UDP
Nello stack protocollare Internet, i protocolli di trasporto più utilizzati sono:

- **TCP** (Transmission Control Protocol) è il più complicato fra i due e fornisce un servizio end-to-end orientato alla connessione e al byte, con verifica del corretto ordine di consegna, controllo di errore e di flusso. In pratica implementa tutte le funzionalità che il livello di trasporto può offrire. 
- **UDP** (User Datagram Protocol): è un protocollo più snello e fornisce un servizio a datagrammi, senza connessione, con un meccanismo di riduzione (non correzione) degli errori e con porte multiple. Non gestisce il riordinamento dei pacchetti né la ritrasmissione di quelli persi.

Entrambi i protocolli si basano su IP ma a causa delle evidenti differenze sono utilizzati in contesti completamente differenti. TCP è il protocollo più affidabile ma tutti i servizi che offre comportano un alto *overhead* della comunicazione.

Il termine overhead indica quella parte di banda di trasmissione che viene utilizzata per spedire, anziché informazione utile, dati aggiuntivi necessari per il particolare protocollo di comunicazione utilizzato. Questo traffico aggiuntivo è composto da:
- tutte le intestazioni che ogni livello della pila aggiunge;
- tutti le comunicazioni necessarie a instaurare e coordinare la comunicazione;
- tutti i dati necessari a fornire controllo e correzione degli errori.

In certi contesti avere alti livelli di overhead può essere inaccettabile. In questi contesti è quindi necessario utilizzare un protocollo come UDP che eliminando la maggior parte dei servizi offerti da TCP riduce al minimo l'overhead sacrificando l'affidabilità della comunicazione. In generale possiamo quindi dire che TCP è preferibile in quei contesti in cui è fondamentale l'integrità dei dati trasmessi (ad es. trasferimento file, posta elettronica, trasferimento pagine web...), UDP è invece preferibile in quei contesti in cui sono presenti stringenti vincoli di banda o tempo di trasmissione (servizi real time, comunicazione P2P, servizio DNS).

Di seguito è proposto un elenco dei principali servizi Internet e dei protocolli che essi adottano:

<table style="text-align:center;">
    <tbody>
        <tr>
            <td width="200px"><b>Applicazione</b>
            </td>
            <td width="200px"><b>Protocollo strato applicazione</b>
            </td>
            <td width="200px"><b>Protocollo strato trasporto</b>
            </td>
        </tr>
        <tr>
            <td>Posta elettronica
            </td>
            <td><a href="/wiki/Simple_Mail_Transfer_Protocol" title="Simple Mail Transfer Protocol">SMTP</a>
            </td>
            <td>TCP
            </td>
        </tr>
        <tr>
            <td>Accesso a terminale remoto
            </td>
            <td><a href="/wiki/Telnet" title="Telnet">telnet</a>
            </td>
            <td>TCP
            </td>
        </tr>
        <tr>
            <td>Trasferimento file
            </td>
            <td><a href="/wiki/File_Transfer_Protocol" title="File Transfer Protocol">FTP</a>
            </td>
            <td>TCP
            </td>
        </tr>
        <tr>
            <td>Web
            </td>
            <td><a href="/wiki/Hypertext_Transfer_Protocol" title="Hypertext Transfer Protocol">HTTP</a>
            </td>
            <td>TCP
            </td>
        </tr>
        <tr>
            <td>Streaming Audio/Video
            </td>
            <td><a href="/wiki/Real_Time_Streaming_Protocol" title="Real Time Streaming Protocol">RTSP</a>/<a
                    href="/wiki/Real_Time_Protocol" class="mw-redirect" title="Real Time Protocol">RTP</a>
            </td>
            <td>TCP (comandi) + UDP (flusso)
            </td>
        </tr>
        <tr>
            <td>Server di file remoto
            </td>
            <td><a href="/wiki/Network_File_System" title="Network File System">NFS</a>
            </td>
            <td>tipicamente UDP
            </td>
        </tr>
        <tr>
            <td>Telefonia su internet (<a href="/wiki/Voice_over_IP" title="Voice over IP">VoIP</a>)
            </td>
            <td><a href="/wiki/Session_Initiation_Protocol" title="Session Initiation Protocol">SIP</a>, <a
                    href="/wiki/H.323" title="H.323">H.323</a>, <a href="/wiki/Voice_over_IP#Protocolli_VoIP"
                    title="Voice over IP">altri</a>
            </td>
            <td>tipicamente UDP
            </td>
        </tr>
        <tr>
            <td>Gestione della rete
            </td>
            <td><a href="/wiki/Simple_Network_Management_Protocol" title="Simple Network Management Protocol">SNMP</a>
            </td>
            <td>tipicamente UDP
            </td>
        </tr>
        <tr>
            <td>Protocollo di routing
            </td>
            <td><a href="/wiki/Routing_Information_Protocol" title="Routing Information Protocol">RIP</a>
            </td>
            <td>tipicamente UDP
            </td>
        </tr>
        <tr>
            <td>Risoluzione dei nomi
            </td>
            <td><a href="/wiki/Domain_Name_System" title="Domain Name System">DNS</a>
            </td>
            <td>tipicamente UDP
            </td>
        </tr>
    </tbody>
</table>

### TCP - Transmission Control Protocol

TCP è il protocollo di livello 4 su cui si appoggia gran parte delle applicazioni della rete internet e di solito è usato in combinazione col protocollo IP tanto che insieme danno il nome al modello TCP-IP su cui si basa internet. 

In linea con i dettami del livello di trasporto stabiliti dal modello ISO/OSI e con l'intento di superare il problema della mancanza di affidabilità e controllo della comunicazione sorto con l'interconnessione su vasta scala di reti locali in un'unica grande rete geografica, TCP è stato progettato e realizzato per utilizzare i servizi offerti dai protocolli di rete di livello inferiore (IP e protocolli di livello fisico e livello datalink) che definiscono efficacemente il modo di trasferimento sul canale di comunicazione, ma che non offrono alcuna garanzia di affidabilità sulla consegna in termini di ritardo, perdita ed errore dei pacchetti informativi trasmessi, sul controllo di flusso tra terminali e sul controllo della congestione di rete, supplendo quindi ai problemi di cui sopra e costruendo così un affidabile canale di comunicazione tra due processi applicativi di rete. Il canale di comunicazione così costruito è composto da un flusso bidirezionale di byte a seguito dell'instaurazione di una connessione agli estremi tra i due terminali in comunicazione. Inoltre alcune funzionalità di TCP sono vitali per il buon funzionamento complessivo di una rete IP. Sotto questo punto di vista TCP può essere considerato come un protocollo di rete che si occupa di costruire connessioni e garantire affidabilità su una rete IP sottostante che è sostanzialmente di tipo best-effort.

#### Caratteristiche

- TCP è un protocollo **orientato alla connessione**, ovvero prima di poter trasmettere dati deve stabilire la comunicazione, negoziando una connessione tra mittente e destinatario, che rimane attiva anche in assenza di scambio di dati e viene esplicitamente chiusa quando non più necessaria. Esso quindi possiede le funzionalità per creare, mantenere e chiudere una connessione.
- TCP è un protocollo **affidabile**: garantisce la consegna dei segmenti a destinazione attraverso il meccanismo degli acknowledgements.
- Il servizio offerto da TCP è il trasporto di un flusso di byte bidirezionale tra due applicazioni in esecuzione su host differenti. Il protocollo permette alle due applicazioni di trasmettere contemporaneamente nelle due direzioni, quindi il servizio può essere considerato **"Full-duplex"** anche se non tutti i protocolli applicativi basati su TCP utilizzano questa possibilità.
- Il flusso di byte prodotto dall'applicazione (o applicativo, o protocollo applicativo) sull'host mittente, viene preso in carico da TCP per la trasmissione, viene quindi frazionato in blocchi, detti **segmenti**, e consegnato al TCP sull'host destinatario che lo passerà all'applicativo indicato dal numero di porta del destinatario nell'header del segmento (es.: applicativo HTTP, porta 80).
- TCP garantisce che i dati trasmessi, se giungono a destinazione, lo facciano in ordine e una volta sola ("at most once"). Più formalmente, il protocollo fornisce ai livelli superiori un servizio equivalente ad una connessione fisica diretta che trasporta un flusso di byte. Questo è realizzato attraverso vari meccanismi di acknowledgment e di ritrasmissione su timeout.
- TCP offre funzionalità di **controllo di errore** sui pacchetti pervenuti grazie al campo checksum contenuto nell'header dei segmenti.
- TCP possiede funzionalità di controllo di flusso tra terminali in comunicazione e controllo della congestione sulla connessione, attraverso il meccanismo della finestra scorrevole. Questo permette di ottimizzare l'utilizzo dei buffer di ricezione/invio sui due end devices (controllo di flusso) e di diminuire il numero di segmenti inviati in caso di congestione della rete.
- TCP fornisce un servizio di **multiplazione delle connessioni** su un host, attraverso il meccanismo dei numeri di porta del mittente.

#### Confronto con UDP

Le principali differenze tra TCP e UDP (User Datagram Protocol), l'altro principale protocollo di trasporto della suite di protocolli Internet, sono:

- TCP è un protocollo orientato alla connessione. Pertanto, per stabilire, mantenere e chiudere una connessione, è necessario inviare segmenti di servizio i quali aumentano l'overhead di comunicazione. Al contrario, UDP è senza connessione ed invia solo i datagrammi richiesti dal livello applicativo; (nota: i pacchetti prendono nomi diversi a seconda delle circostanze a cui si riferiscono: segmenti (TCP) o datagrammi (UDP));
- UDP non offre nessuna garanzia sull'affidabilità della comunicazione, ovvero sull'effettivo arrivo dei segmenti, né sul loro ordine in sequenza in arrivo; al contrario il TCP, tramite i meccanismi di acknowledgement e di ritrasmissione su timeout, riesce a garantire la consegna dei dati, anche se al costo di un maggiore overhead (raffrontabile visivamente confrontando la dimensione delle intestazioni dei due protocolli); TCP riesce altresì a riordinare i segmenti in arrivo presso il destinatario attraverso un campo del suo header: il sequence number;
l'oggetto della comunicazione di TCP è un flusso di byte, mentre quello di UDP sono singoli datagrammi.
- L'utilizzo del protocollo TCP rispetto a UDP è, in generale, preferito quando è necessario avere garanzie sulla consegna dei dati o sull'ordine di arrivo dei vari segmenti (come per esempio nel caso di trasferimenti di file). Al contrario UDP viene principalmente usato quando l'interazione tra i due host è [idempotente](https://it.wikipedia.org/wiki/Idempotenza) o nel caso si abbiano forti vincoli sulla velocità e l'economia di risorse della rete (es. streaming in tempo reale, videogiochi multiplayer).

#### Segmento TCP

La PDU (Protocol Data Unit, in poche parole il pacchetto) di TCP è detta segmento. Ciascun segmento viene normalmente imbustato in un pacchetto IP, ed è costituito dall'intestazione (header) TCP e da un carico utile (in inglese payload), ovvero i dati provenienti dal livello applicativo (es.: HTTP). I dati contenuti nell'intestazione costituiscono un canale di comunicazione tra TCP mittente e TCP destinatario, che viene utilizzato per realizzare le funzionalità dello strato di trasporto e non è accessibile agli strati dei livelli superiori.

Un segmento TCP è così strutturato:

<table class="sistema-bordi-multi-riga-colonna" id="tab-struttura-pdu" style="margin: 0 auto; text-align:center">
    <tbody>
        <tr>
            <th style="border-bottom:none; border-right:none;"><i>Offset</i>
            </th>
            <th>Ottetto
            </th>
            <th colspan="8">0
            </th>
            <th colspan="8">1
            </th>
            <th colspan="8">2
            </th>
            <th colspan="8">3
            </th>
        </tr>
        <tr>
            <th style="border-top: none">Ottetto
            </th>
            <th><kbd><a href="/wiki/Bit" title="Bit">Bit</a></kbd></th>
            <th><kbd>&#160;0</kbd></th>
            <th><kbd>&#160;1</kbd></th>
            <th><kbd>&#160;2</kbd></th>
            <th><kbd>&#160;3</kbd></th>
            <th><kbd>&#160;4</kbd></th>
            <th><kbd>&#160;5</kbd></th>
            <th><kbd>&#160;6</kbd></th>
            <th><kbd>&#160;7</kbd></th>
            <th><kbd>&#160;8</kbd></th>
            <th><kbd>&#160;9</kbd></th>
            <th><kbd>10</kbd></th>
            <th><kbd>11</kbd></th>
            <th><kbd>12</kbd></th>
            <th><kbd>13</kbd></th>
            <th><kbd>14</kbd></th>
            <th><kbd>15</kbd></th>
            <th><kbd>16</kbd></th>
            <th><kbd>17</kbd></th>
            <th><kbd>18</kbd></th>
            <th><kbd>19</kbd></th>
            <th><kbd>20</kbd></th>
            <th><kbd>21</kbd></th>
            <th><kbd>22</kbd></th>
            <th><kbd>23</kbd></th>
            <th><kbd>24</kbd></th>
            <th><kbd>25</kbd></th>
            <th><kbd>26</kbd></th>
            <th><kbd>27</kbd></th>
            <th><kbd>28</kbd></th>
            <th><kbd>29</kbd></th>
            <th><kbd>30</kbd></th>
            <th><kbd>31</kbd>
            </th>
        </tr>
        <tr>
            <th>0
            </th>
            <th><kbd> 0</kbd>
            </th>
            <td colspan="16">Source port</td>
            <td colspan="16">Destination port
            </td>
        </tr>
        <tr>
            <th>4
            </th>
            <th><kbd>32</kbd>
            </th>
            <td colspan="32">Sequence number
            </td>
        </tr>
        <tr>
            <th>8
            </th>
            <th><kbd>32</kbd>
            </th>
            <td colspan="32">Acknowledgment number (se <kbd>ACK</kbd> è impostato)
            </td>
        </tr>
        <tr>
            <th>12
            </th>
            <th><kbd>96</kbd>
            </th>
            <td colspan="4">Data offset</td>
            <td colspan="4">Reserved<br /><kbd><b>0 0 0 0</b></kbd></td>
            <td><kbd>C<br />W<br />R</kbd></td>
            <td><kbd>E<br />C<br />E</kbd></td>
            <td><kbd>U<br />R<br />G</kbd></td>
            <td><kbd>A<br />C<br />K</kbd></td>
            <td><kbd>P<br />S<br />H</kbd></td>
            <td><kbd>R<br />S<br />T</kbd></td>
            <td><kbd>S<br />Y<br />N</kbd></td>
            <td><kbd>F<br />I<br />N</kbd></td>
            <td colspan="16">Window Size
            </td>
        </tr>
        <tr>
            <th>16
            </th>
            <th><kbd>128</kbd>
            </th>
            <td colspan="16">Checksum</td>
            <td colspan="16">Urgent pointer (se <kbd>URG</kbd> è impostato)
            </td>
        </tr>
        <tr>
            <th>20
            </th>
            <th><kbd>160</kbd>
            </th>
            <td colspan="32" style="background:#ffd0d0;">Options (facoltativo)
            </td>
        </tr>
        <tr>
            <th>20/60
                <p>...
                </p>
            </th>
            <th><kbd>160/480<br />...</kbd>
            </th>
            <td colspan="32">Data
            </td>
        </tr>
    </tbody>
</table>

- **Source port** [16 bit] - Identifica il numero di porta sull'host mittente associato alla connessione TCP.
- **Destination** port [16 bit] - Identifica il numero di porta sull'host destinatario associato alla connessione TCP.
- **Sequence number** [32 bit] - Numero di sequenza, indica lo scostamento (espresso in byte) dell'inizio del segmento TCP all'interno del flusso completo, a partire dall'Initial Sequence Number (ISN), deciso all'apertura della connessione.
- **Acknowledgment number** [32 bit] - Numero di riscontro, ha significato solo se il flag ACK è impostato a 1, e conferma la ricezione di una parte del flusso di dati nella direzione opposta, indicando il valore del prossimo Sequence number che l'host mittente del segmento TCP si aspetta di ricevere.
- **Data offset** [4 bit] - Indica la lunghezza (in dword da 32 bit) dell'header del segmento TCP; tale lunghezza può variare da 5 dword (20 byte) a 15 dword (60 byte) a seconda della presenza e della lunghezza del campo facoltativo Options.
- **Reserved** [4 bit] - Bit non utilizzati e predisposti per sviluppi futuri del protocollo; dovrebbero essere impostati a zero.
- **Flags** [8 bit] - Bit utilizzati per il controllo del protocollo:
  - **CWR** (Congestion Window Reduced) - se impostato a 1 indica che l'host sorgente ha ricevuto un segmento TCP con il flag ECE impostato a 1 (aggiunto all'header in RFC 3168).
  - **ECE** [ECN (Explicit Congestion Notification) -Echo] - se impostato a 1 indica che l'host supporta ECN durante il 3-way handshake (aggiunto all'header in RFC 3168).
  - **URG** - se impostato a 1 indica che nel flusso sono presenti dati urgenti alla posizione (offset) indicata dal campo Urgent pointer. Urgent Pointer punta alla fine dei dati urgenti;
  - **ACK** - se impostato a 1 indica che il campo Acknowledgment number è valido;
  - **PSH** - se impostato a 1 indica che i dati in arrivo non devono essere bufferizzati ma passati subito ai livelli superiori dell'applicazione;
  - **RST** - se impostato a 1 indica che la connessione non è valida; viene utilizzato in caso di grave errore; a volte utilizzato insieme al flag ACK per la chiusura di una connessione.
  - **SYN** - se impostato a 1 indica che l'host mittente del segmento vuole aprire una connessione TCP con l'host destinatario e specifica nel campo Sequence number il valore dell'Initial Sequence Number (ISN); ha lo scopo di sincronizzare i numeri di sequenza dei due host. L'host che ha inviato il SYN deve attendere dall'host remoto un pacchetto SYN/ACK.
  - **FIN** - se impostato a 1 indica che l'host mittente del segmento vuole chiudere la connessione TCP aperta con l'host destinatario. Il mittente attende la conferma dal ricevente (con un FIN-ACK). A questo punto la connessione è ritenuta chiusa per metà: l'host che ha inviato FIN non potrà più inviare dati, mentre l'altro host ha il canale di comunicazione ancora disponibile. Quando anche l'altro host invierà il pacchetto con FIN impostato, la connessione, dopo il relativo FIN-ACK, sarà considerata completamente chiusa.
- **Window size** [16 bit] - Indica la dimensione della finestra di ricezione dell'host mittente, cioè il numero di byte che il mittente è in grado di accettare a partire da quello specificato dall'acknowledgment number.
- **Checksum** [16 bit] - Campo di controllo utilizzato per la verifica della validità del segmento. È ottenuto facendo il complemento a 1 della somma complemento a uno a 16 bit dell'intero header TCP (con il campo checksum messo a zero), dell'intero payload, con l'aggiunta di uno pseudo header composto da: indirizzo IP sorgente(32bit),indirizzo IP destinazione(32bit), un byte di zeri, un byte che indica il protocollo e due byte che indicano la lunghezza del pacchetto TCP (header + dati).
- **Urgent pointer** [16 bit] - Puntatore a dato urgente, ha significato solo se il flag URG è impostato a 1 ed indica lo scostamento in byte a partire dal Sequence number del byte di dati urgenti all'interno del flusso.
- **Options** - Opzioni (facoltative) per usi del protocollo avanzati.
- **Data** - rappresenta il carico utile o payload da trasmettere cioè la PDU proveniente dal livello superiore.

#### Funzionamento

Prima ancora del trasferimento dei dati su canale di comunicazione e delle operazioni di controllo di trasmissione sul flusso dei dati in ricezione, in trasmissione TCP si occupa di instaurare la connessione agli estremi tra i processi applicativi dei terminali in comunicazione attraverso la definizione del socket ovvero coppia indirizzo IP, porta sia del mittente che del destinatario. Si ricorda invece che la commutazione interna nei nodi della rete di trasporto dati segue invece tipicamente la commutazione di pacchetto ovvero senza circuito o connessione fissa dedicata tipica invece della commutazione di circuito. Il fine della connessione TCP è in ogni caso il riservamento di risorse tra processi applicativi che si scambiano informazioni o servizi tra loro (es. server e client). Al termine della connessione, TCP attua la fase dell'abbattimento della connessione. Le due procedure sono distinte.

Le procedure di creazione e abbattimento della connessione e le tecniche di gestione del traffico dati sono lunghe e complesse e non saranno trattate. Se vuoi approfondire l'argomento puoi farlo [qui](https://it.wikipedia.org/wiki/Transmission_Control_Protocol)

### UDP - User Datagram Protocol

UDP, come TCP è un protocollo di livello 4 solitamente utilizzato insieme al protocollo IP ma, a differenza del TCP, l'UDP è un protocollo di tipo connectionless, inoltre non gestisce il riordinamento dei pacchetti né la ritrasmissione di quelli persi, ed è perciò generalmente considerato di minore affidabilità. In compenso è molto rapido (non c'è latenza per riordino e ritrasmissione) ed efficiente per le applicazioni "leggere" o time-sensitive. In genere è utilizzato per le applicazioni per le quali un pacchetto in ritardo ha validità nulla, per esempio la trasmissione audio-video in tempo reale (streaming o VoIP sono gli usi più comuni), oppure la trasmissione di altre informazioni sullo stato di un sistema, per esempio i giochi multiplayer online.

Infatti, visto che le applicazioni in tempo reale richiedono spesso un bit-rate minimo di trasmissione, non vogliono ritardare eccessivamente la trasmissione dei pacchetti e possono tollerare qualche perdita di dati, il modello di servizio TCP può non essere particolarmente adatto alle loro caratteristiche. Nel caso della telefonia via Internet (VoIP), un pacchetto riordinato è inutile perché risale a un tempo passato, mentre un pacchetto non ricevuto causa lo stallo del sistema fino al suo arrivo, per cui si sentirebbe un lungo silenzio seguito da tutti i pacchetti non arrivati in tempo.

L'UDP fornisce soltanto i servizi basilari del livello di trasporto, ovvero:

- multiplazione delle connessioni, ottenuta attraverso il meccanismo di assegnazione delle porte;
- verifica degli errori (integrità dei dati) mediante una checksum, inserita in un campo dell'intestazione (header) del pacchetto, mentre TCP garantisce anche il trasferimento affidabile dei dati, il controllo di flusso e il controllo della congestione.
- 
L'UDP è un protocollo stateless, ovvero non tiene nota dello stato della connessione dunque ha, rispetto al TCP, meno informazioni da memorizzare: un server dedicato ad una particolare applicazione che scelga UDP come protocollo di trasporto può supportare quindi molti più client attivi.

#### Struttura di un datagramma UDP

Un datagramma (o pacchetto) UDP è così strutturato:

<table class="sistema-bordi-multi-riga-colonna tab-struttura-pdu">
    <tbody>
        <tr align="center">
            <th width="4%">+
            </th>
            <th colspan="16" width="48%">Bit 0-15
            </th>
            <th colspan="16" width="48%">16-31
            </th>
        </tr>
        <tr align="center">
            <th>0
            </th>
            <td colspan="16" bgcolor="#FFDDDD">Source Port (optional)
            </td>
            <td colspan="16">Destination Port
            </td>
        </tr>
        <tr align="center">
            <th>32
            </th>
            <td colspan="16">Length
            </td>
            <td colspan="16" bgcolor="#FFDDDD">Checksum (optional)
            </td>
        </tr>
        <tr align="center">
            <th>64+
            </th>
            <td colspan="32">&#160;<br />Data<br />&#160;
            </td>
        </tr>
    </tbody>
</table>

- Header:
  - Source port [16 bit] - identifica il numero di porta sull'host del mittente del datagramma;
  - Destination port [16 bit] - identifica il numero di porta sull'host del destinatario del datagramma;
  - Length [16 bit] - contiene la lunghezza totale in bytes del datagramma UDP (header+dati);
  - Checksum [16 bit] - contiene il codice di controllo del datagramma (header + dati + pseudo-header, quest'ultimo comprendente gli indirizzi IP di sorgente e destinazione). L'algoritmo di calcolo è definito nell'RFC del protocollo;
- Payload:
  - Data - contiene i dati del messaggio





## Modelli di condivisione delle risorse

I modelli client server e peer to peer sono modelli di condivisione delle risorse. Sebbene esistano tra i due modelli alcune differenze anche sull'aspetto della comunicazione il punto centrale è la localizzazione delle risorse e il modo in cui vengono condivise.

### Modello Client-Server
Nel modello client server le risorse da condividere risiedono tutte su un host definito server (in inglese servitore) che le mette a disposizione di tutti gli altri che quindi vengono definiti client (clienti). Essere client o server quindi non è una caratteristica intrinseca di un determinato host, ma solo il suo ruolo in una relazione di condivisione di risorse. Un computer può essere client per quanto riguarda un servizio e server per un altro. Esistono però alcuni computer che vengono tenuti in esecuzione con l'unico scopo di offrire un servizio e per questo vengono chiamati *server dedicati*.

Il modello client server è un modello di gestione delle risorse *centralizzato* poichè appunto accentra le risorse in un unico punto. Questa caratteristica ha il vantaggio di rendere la ricerca delle risorse molto semplice e abbastanza efficiente, ma ha anche lo svantaggio che se il server smette di condividere la risorsa per un qualsiasi motivo, la risorsa diventa totalmente irreperibile.

### Modello Peer to Peer
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


## Link e riferimenti esterni

- [ISO/OSI su Wikipedia](https://it.wikipedia.org/wiki/Modello_OSI)
- [Livello di trasporto su Wikipedia](https://it.wikipedia.org/wiki/Livello_di_trasporto)
- [Porte su Wikipedia](https://it.wikipedia.org/wiki/Porta_(reti))
- [Socket su Wikipedia](https://it.wikipedia.org/wiki/Socket_(reti))
- Elenco delle porte su Wikipedia [in italiano](https://it.wikipedia.org/wiki/Porte_TCP_e_UDP_standard) e [in inglese](https://en.wikipedia.org/wiki/List_of_TCP_and_UDP_port_numbers) (più approfondito)
- [TCP su Wikipedia](https://it.wikipedia.org/wiki/Transmission_Control_Protocol)
- [UDP su Wikipedia](https://it.wikipedia.org/wiki/User_Datagram_Protocol)
- [Peer to Peer su Wikipedia](https://it.wikipedia.org/wiki/Peer-to-peer)

