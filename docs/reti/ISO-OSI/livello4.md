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

## Protocolli TCP e UDP
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

