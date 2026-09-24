---
title: Reti di calcolatori
sidebar:
  order: 1
---

Una **rete di calcolatori** è un sistema formato da due o più dispositivi di elaborazione autonomi (*host* o nodi terminali), interconnessi tra loro mediante appositi canali di comunicazione (*link* fisici o wireless), in grado di scambiarsi dati e condividere risorse materiali (hardware come stampanti o dischi di rete) e immateriali (dati, file, servizi applicativi, accesso al web e calcolo distribuito).

Affinché la comunicazione tra calcolatori con architetture, sistemi operativi e linguaggi diversi possa avvenire con successo, i nodi devono adottare insiemi condivisi di regole formali, standard e formati, noti come **protocolli di comunicazione**.

---

## 1. Componenti fondamentali di una rete

In qualsiasi rete informatica si possono distinguere alcuni elementi cardine:

- **Host (o nodi terminali / End System):** dispositivi che generano o utilizzano i dati. Comprendono computer desktop, portatili, server, smartphone, tablet e la crescente galassia dei dispositivi IoT (Internet of Things, come sensori, videocamere di sorveglianza ed elettrodomestici smart).
- **Nodi intermedi di commutazione e instradamento:** apparati dedicati che governano il flusso dei dati all'interno dell'infrastruttura di rete. I più noti sono:
  - **Switch:** operano all'interno della medesima rete locale (LAN), instradando i dati verso la porta a cui è collegato il dispositivo destinatario specifico.
  - **Router:** operano all'interconnessione tra reti diverse e geograficamente distanti, decidendo il percorso ottimale (*routing*) che i dati devono seguire per raggiungere la destinazione finale.
- **Canali trasmissivi (link):** il mezzo fisico o guidato (cavi in rame, fibre ottiche) o non guidato (onde radio nello spazio) attraverso cui viaggia il segnale.
- **Interfaccia di rete (NIC - Network Interface Card):** scheda o componente integrato (Ethernet o Wi-Fi) presente in ogni host e apparato di rete, che converte i bit digitali del calcolatore in segnali fisici (elettrici, ottici o elettromagnetici) idonei alla trasmissione sul canale.
- **Protocolli:** le convenzioni condivise che definiscono la sintassi, la semantica e la sincronizzazione della comunicazione.

---

## 2. Vantaggi e sfide delle reti

L'avvento e la diffusione capillare delle reti telematiche hanno rivoluzionato l'organizzazione del lavoro e della società.

### Perché colleghiamo i computer?
1. **Condivisione di risorse e cooperazione:** periferiche costose, archivi centralizzati, banche dati e applicazioni possono essere usate contemporaneamente da utenti remoti, riducendo le duplicazioni e i costi complessivi.
2. **Affidabilità e tolleranza ai guasti (*fault tolerance*):** un'architettura distribuita riduce al minimo il rischio di interruzione del servizio (*single point of failure*). Se un server o un collegamento si guasta, il carico può essere reindirizzato su altri nodi o su percorsi alternativi.
3. **Scalabilità:** una rete ben progettata permette di aggiungere nuovi host, nuovi servizi o ampliare la copertura geografica in modo modulare, senza dover ricostruire da zero l'infrastruttura esistente.
4. **Accessibilità e mobilità:** dati e servizi cloud sono fruibili ovunque e da qualsiasi dispositivo provvisto di connessione.

### Le sfide aperte
- **Sicurezza e riservatezza dei dati:** rendere i calcolatori raggiungibili via rete li espone a minacce informatiche (intercettazione dei dati o *sniffing*, attacchi malware, intrusioni non autorizzate, tentativi di furto d'identità o *spoofing*). Per questo motivo le reti richiedono robusti meccanismi di crittografia, autenticazione e firewall.
- **Complessità architetturale e di gestione:** garantire prestazioni elevate, bassa latenza e continuità operativa su scala globale richiede una costante attività di monitoraggio, configurazione e manutenzione degli apparati.

---

## 3. Classificazione delle reti

Le reti possono essere classificate secondo differenti criteri: l'estensione geografica, il mezzo trasmissivo adottato e la modalità di diffusione dei messaggi.

### 3.1 Per estensione geografica

- **PAN (Personal Area Network):** rete personale con raggio d'azione di pochi metri, destinata a collegare dispositivi vicini a un singolo utente (es. smartphone collegato via Bluetooth a cuffie, smartwatch o al computer).
- **LAN (Local Area Network):** rete locale che copre un'area circoscritta (un'abitazione, un'aula scolastica, un edificio aziendale), con estensione da poche decine di metri fino a circa 1 km. È caratterizzata da velocità di trasmissione elevate e bassi tassi di errore.
- **CAN (Campus Area Network):** interconnessione di più LAN all'interno di un insieme di edifici adiacenti appartenenti alla stessa organizzazione (es. un campus universitario o un complesso ospedaliero).
- **MAN (Metropolitan Area Network):** rete che si estende sull'intera area di una città (es. una rete in fibra ottica municipale che collega sedi comunali, scuole e presidi di pubblica sicurezza).
- **WAN (Wide Area Network):** rete geografica che copre vaste aree regionali, nazionali o intercontinentali. Interconnette diverse LAN e MAN attraverso linee di telecomunicazione pubbliche o private gestite da operatori di telecomunicazioni.
- **Internet:** la rete globale risultante dall'interconnessione aperta e cooperativa di tutte le reti del pianeta.

:::tip[Intranet ed Extranet]
Si definisce **Intranet** una rete privata, basata sulle stesse tecnologie e protocolli di Internet (come HTTP, TCP/IP), il cui accesso è rigorosamente riservato agli utenti interni di un'organizzazione (ad esempio i dipendenti di un'azienda). Si parla invece di **Extranet** quando l'accesso a porzioni della rete interna è esteso in modo controllato a partner esterni selezionati (fornitori, clienti, collaboratori).
:::

---

### 3.2 Per mezzo trasmissivo

I canali trasmissivi si dividono in due grandi famiglie: **guidati** (cablati) e **non guidati** (wireless).

#### Mezzi trasmissivi cablati

1. **Cavi in rame a doppino ritorto (Twisted Pair):**
   - Costituiti da 4 coppie (8 fili) di rame isolati, terminati con il classico connettore a 8 poli **RJ-45**.
   - **Il problema dell'interferenza elettromagnetica (EMI) e della diafonia:**
     - Nei cavi in rame i dati viaggiano sotto forma di segnali elettrici (variazioni di tensione e corrente).
     - Secondo le leggi dell'elettromagnetismo (leggi di Ampère e di Faraday-Neumann), ogni corrente elettrica variabile genera attorno al conduttore un campo magnetico oscillante; viceversa, qualsiasi campo magnetico variabile esterno induce una corrente spuria (detta **rumore** o disturbo) nei conduttori adiacenti.
     - Questo fenomeno si manifesta in due forme critiche:
       - **Interferenza Elettromagnetica esterna (EMI / RFI):** disturbi generati da apparecchiature esterne come motori elettrici, lampade fluorescenti, elettrodomestici o dai cavi della rete elettrica a 230 V. Per questa ragione le norme impiantistiche vietano di far passare i cavi di rete nelle stesse canaline dei cavi elettrici della corrente.
       - **Diafonia (*Crosstalk*):** l'interferenza reciproca generata tra i singoli fili di rame che corrono vicini e paralleli all'interno dello stesso cavo di rete.
   - **Come si combatte l'interferenza?**
     - **L'intreccio dei fili (Twisted Pair):** è la soluzione più brillante ed economica. I due fili di ciascuna coppia sono avvolti a spirale l'uno attorno all'altro e trasmettono un segnale *differenziale* (uguale in modulo ma di segno opposto). Poiché i fili sono costantemente intrecciati, un disturbo elettromagnetico esterno colpisce entrambi i fili con la stessa intensità; all'arrivo, il ricevitore calcola la differenza tra i due segnali, eliminando quasi del tutto il rumore di fondo comune. Inoltre, le quattro coppie hanno un passo di avvolgimento differente (numero di spire al metro diverso) per evitare la diafonia tra coppia e coppia.
     - **La schermatura metallica (UTP vs STP/FTP):** i cavi non schermati (**UTP** - *Unshielded Twisted Pair*) si affidano solo all'intreccio e sono perfetti per uffici e abitazioni. Nelle fabbriche o in ambienti con forti campi elettromagnetici si usano invece cavi dotati di una lamina di alluminio o di una calza a treccia metallica (**FTP/STP** - *Shielded Twisted Pair*), che fa da gabbia di Faraday isolando i conduttori dai disturbi esterni.
   - **Attenuazione e limite di distanza:** a causa della resistenza ohmica del rame e della dispersione del segnale a frequenze elevate, l'ampiezza dell'onda elettrica diminuisce progressivamente con la lunghezza del cavo (attenuazione). Per lo standard Ethernet su rame (Cat 5e, Cat 6, Cat 6a), la lunghezza massima garantita per una singola tratta senza apparati intermedi di rigenerazione è di **100 metri**.
   - *Nota pratica:* in passato si distinguevano cavi "diretti" (per collegare host a switch) e cavi "incrociati" o *cross* (per collegare direttamente due host o due switch tra loro). Oggi questa distinzione è del tutto superata: quasi tutti i dispositivi integrano la funzione **Auto-MDIX**, che rileva e adatta automaticamente la polarità delle connessioni.

2. **Cavi in fibra ottica:**
   - La fibra ottica è un filamento continuo di vetro di silice purissimo (o plastica speciale) di diametro paragonabile a quello di un capello, formato da un nucleo centrale trasparente (*core*) circondato da un rivestimento (*cladding*) con indice di rifrazione inferiore.
   - Il segnale viaggia sotto forma di impulsi di luce generati da laser o LED, propagandosi per **riflessione totale interna** lungo il nucleo secondo le leggi dell'ottica (legge di Snell).
   - **Vantaggi principali:**
     - Totale immunità da interferenze elettromagnetiche o radiofrequenze.
     - Bassissima attenuazione del segnale, che permette tratte di decine o centinaia di chilometri senza bisogno di amplificatori.
     - Larghezza di banda elevatissima (nell'ordine dei Terabit al secondo), che la rende il mezzo d'elezione per le dorsali oceaniche, le interconnessioni metropolitane e le connessioni domestiche ad alta velocità (FTTH - *Fiber to the Home*).

#### Mezzi trasmissivi wireless (senza fili)

Nelle reti senza fili il mezzo di propagazione è lo spazio libero e l'informazione viene trasmessa mediante **onde elettromagnetiche** (onde radio e microonde) irradiate e captate da antenne.

Tutte le onde elettromagnetiche si propagano nell'aria alla velocità della luce ($c \approx 3 \times 10^8\text{ m/s}$). Ciò che varia tra le diverse tecnologie è la **frequenza** ($f$) e di conseguenza la **lunghezza d'onda** ($\lambda = c / f$):
- **Basse frequenze / lunghezze d'onda maggiori (es. centinaia di MHz):** hanno un'ottima capacità di diffrazione e penetrazione degli ostacoli (muri, rilievi montuosi) e coprono grandi distanze, ma offrono una ridotta larghezza di banda disponibile per trasmettere dati ad alta velocità.
- **Alte frequenze / lunghezze d'onda millimetriche (es. GHz, tipici del Wi-Fi a 2.4/5/6 GHz e delle reti cellulari 5G):** consentono canali molto ampi e tassi di trasferimento dati elevatissimi, ma risentono fortemente dell'attenuazione dovuta a muri, pioggia e ostacoli fisici, richiedendo una visibilità ottica quasi diretta (*line-of-sight*) e una presenza più densa di celle/punti di accesso sul territorio.

---

### 3.3 Per modalità di diffusione dei dati

In base alla relazione tra mittente e destinatari del traffico:

- **Unicast (uno-a-uno):** come una telefonata privata; il messaggio viaggia esclusivamente tra il nodo mittente e un singolo destinatario identificato dal suo indirizzo specifico (es. la navigazione web standard tra il tuo browser e un server).
- **Broadcast (uno-a-tutti):** come parlare con un megafono in una stanza chiusa. Il messaggio inviato dall'host viene trasmesso indistintamente a **tutti** i dispositivi della rete locale, costringendo ciascun calcolatore a riceverlo ed esaminarlo (motivo per cui i router bloccano il broadcast per non saturare Internet). Viene usato principalmente per annunci di servizio e configurazione automatica (es. richieste DHCP o risoluzioni ARP).
- **Multicast (uno-a-molti selezionati):** come una frequenza o un canale a cui ci si "sintonizza". Il mittente genera una sola copia dei dati; sono poi gli apparati di rete (switch e router) a duplicare e recapitare il flusso **esclusivamente verso i dispositivi che si sono esplicitamente iscritti a quel gruppo**. Tutti gli altri computer della rete rimangono completamente indisturbati e non ricevono alcun traffico superfluo (usato ad esempio per videoconferenze, streaming IPTV e lezioni in diretta).

---

## 4. Topologie di rete: Fisiche e Logiche

La **topologia di rete** è la rappresentazione geometrica e strutturale (grafo) dei collegamenti tra gli elementi costituenti la rete.

È essenziale distinguere due piani:
- **Topologia fisica:** descrive come i dispositivi, i cavi e le antenne sono fisicamente disposti e collegati nello spazio.
- **Topologia logica:** descrive come i dati fluiscono effettivamente all'interno della rete dal punto di vista dei nodi comunicanti.

Una rete può avere una topologia fisica diversa da quella logica: ad esempio, una rete cablata con un vecchio hub centrale è fisicamente a stella (tutti i cavi convergono nell'apparato), ma logicamente a bus (il segnale ricevuto da una porta viene replicato elettricamente su tutte le altre porte indistintamente).

---

### 4.1 Topologia a stella

<!-- thumbnail -->
<div class="thumbnail tright mb-2">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/NetworkTopology-Stella.png" class="modal__opener" aprire="#img-NetworkTopology-Stella">
  <p>Rappresentazione di una rete a stella</p>
</div>
<!-- modal -->
<div id="img-NetworkTopology-Stella" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-NetworkTopology-Stella">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/NetworkTopology-Stella.png">
    </div>
    <p>Rappresentazione di una rete a stella</p>
  </div>
</div>

Tutti i nodi periferici sono collegati a un nodo centrale che governa le comunicazioni. Nelle reti moderne questo nodo centrale è uno **switch**.

- **Vantaggi:**
  - *Isolamento dei guasti:* se un cavo o un host periferico si interrompe, il resto della rete continua a funzionare regolarmente.
  - *Facilità di gestione e scalabilità:* aggiungere o rimuovere un dispositivo richiede soltanto di inserire o disinserire un cavo nello switch, senza alterare il traffico degli altri nodi.
  - *Zero collisioni (con switch full-duplex):* lo switch esamina l'indirizzo di destinazione di ciascun frame e lo inoltra solo sulla porta del destinatario, creando canali dedicati temporanei.
- **Svantaggi:**
  - *Punto unico di fallimento (*single point of failure*):* se il nodo centrale (switch) si guasta o perde alimentazione, l'intera rete cessa di funzionare.
- **Impiego odierno:** è la topologia standard indiscussa per tutte le reti locali cablate (LAN di uffici, scuole, abitazioni).

---

### 4.2 Topologia a stella estesa o ad albero

<!-- thumbnail -->
<div class="thumbnail tright mb-2">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/NetworkTopology-Tree.png" class="modal__opener" aprire="#img-NetworkTopology-Tree">
  <p>Rappresentazione di una rete ad albero</p>
</div>
<!-- modal -->
<div id="img-NetworkTopology-Tree" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-NetworkTopology-Tree">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/NetworkTopology-Tree.png">
    </div>
    <p>Rappresentazione di una rete ad albero</p>
  </div>
</div>

Rappresenta un'evoluzione gerarchica della topologia a stella. I nodi centrali delle singole stelle (switch di piano o di reparto) sono a loro volta collegati a uno switch principale di livello superiore (*core switch* o nodo radice).

- **Vantaggi:** organizza la rete in sottoreti logiche ben strutturate (es. livello di accesso, di distribuzione e di core), facilitando il cablaggio strutturato e la manutenzione di edifici articolati o grandi aziende.
- **Svantaggi:** il guasto di un nodo intermedio di smistamento isola l'intero sotto-albero a esso collegato (anche se i nodi appartenenti a quello stesso ramo possono continuare a dialogare tra loro).

---

### 4.3 Topologia a maglia (Mesh)

<!-- thumbnail -->
<div class="thumbnail tright mb-2">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/NetworkTopology-Full_Mesh.svg" class="modal__opener" aprire="#img-NetworkTopology-Full_Mesh">
  <p>Rappresentazione di una rete a maglia completa</p>
</div>
<!-- modal -->
<div id="img-NetworkTopology-Full_Mesh" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-NetworkTopology-Full_Mesh">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/NetworkTopology-Full_Mesh.svg">
    </div>
    <p>Rappresentazione di una rete a maglia completa</p>
  </div>
</div>

<!-- thumbnail -->
<div class="thumbnail tright mb-2">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/NetworkTopology-Mesh.png" class="modal__opener" aprire="#img-NetworkTopology-Mesh">
  <p>Rappresentazione di una rete parzialmente magliata</p>
</div>
<!-- modal -->
<div id="img-NetworkTopology-Mesh" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-NetworkTopology-Mesh">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/NetworkTopology-Mesh.png">
    </div>
    <p>Rappresentazione di una rete parzialmente magliata</p>
  </div>
</div>

- **Maglia completa (*Full Mesh*):** ogni nodo è collegato con una linea punto-a-punto diretta a ciascun altro nodo della rete.
  - Per una rete di $N$ nodi occorrono $C = \frac{N \cdot (N - 1)}{2}$ collegamenti.
  - Offre la massima robustezza e zero problemi di congestione, ma ha una scalabilità pessima: collegare 20 calcolatori richiederebbe già 190 canali fisici! Risulta economicamente e fisicamente impraticabile su larga scala.
- **Maglia parziale (*Partial Mesh*):** i nodi più importanti dispongono di collegamenti multipli e ridondanti verso altri nodi strategici, senza che tutti siano collegati con tutti.
  - Se un canale o un nodo intermedio collassa, gli algoritmi di instradamento (*routing*) ricalcolano automaticamente percorsi alternativi.
  - **Impiego odierno:** è l'architettura fondante delle reti geografiche (WAN) e della dorsale di Internet.

---

### 4.4 Topologie storiche (Bus e Anello)

Queste topologie hanno avuto un ruolo fondamentale nelle prime generazioni di reti, ma oggi sono state superate nelle reti locali cablate:

<!-- thumbnail -->
<div class="thumbnail tright mb-2">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/NetworkTopology-Bus.png" class="modal__opener" aprire="#img-NetworkTopology-Bus">
  <p>Rappresentazione di una rete a bus</p>
</div>
<!-- modal -->
<div id="img-NetworkTopology-Bus" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-NetworkTopology-Bus">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/NetworkTopology-Bus.png">
    </div>
    <p>Rappresentazione di una rete a bus</p>
  </div>
</div>

- **Topologia a bus:**
  - Tutti gli host sono collegati a un unico cavo dorsale condiviso (*bus* coassiale), terminato alle estremità con resistenze di chiusura (50 $\Omega$) per evitare la riflessione del segnale.
  - Il canale è condiviso: quando un host trasmette, tutti gli altri ascoltano. Se due host trasmettono nello stesso istante si verifica una **collisione**, che richiede meccanismi di risoluzione e ritrasmissione.
  - *Punto critico:* un'interruzione fisica in un qualsiasi punto del cavo dorsale elimina la terminazione resistiva, provocando rimbalzi del segnale e il blocco immediato di tutta la rete.

<!-- thumbnail -->
<div class="thumbnail tright mb-2">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/NetworkTopology-Ring.png" class="modal__opener" aprire="#img-NetworkTopology-Ring">
  <p>Rappresentazione di una rete ad anello</p>
</div>
<!-- modal -->
<div id="img-NetworkTopology-Ring" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-NetworkTopology-Ring">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/NetworkTopology-Ring.png">
    </div>
    <p>Rappresentazione di una rete ad anello</p>
  </div>
</div>

- **Topologia ad anello:**
  - I nodi sono collegati in serie a formare un percorso circolare chiuso unidirezionale. Ogni nodo agisce da ripetitore: riceve il segnale dal nodo precedente e lo rigenera verso il successivo.
  - Storicamente diffusa nelle reti *Token Ring* (IBM) o *FDDI*, regolava l'accesso al canale tramite un gettone logico (*token*).
  - *Punto critico:* il guasto di un singolo nodo o link interrompeva l'anello (a meno di complesse architetture a doppio anello controrotante).

:::note[Ma Ethernet e Wi-Fi non erano "a bus"?]
Spesso si sente dire che le reti Ethernet o Wi-Fi sono tecnologie a bus: come si concilia questo con le definizioni appena viste?
- **Ethernet:** è nata negli anni '70/'80 effettivamente come un **bus fisico e logico** su cavo coassiale. Negli anni '90, con i primi cavi a coppie ritorte e gli *hub*, è diventata **fisicamente a stella** ma è rimasta **logicamente a bus** (l'hub ripeteva il segnale su tutte le porte generando collisioni). Dagli anni 2000, con l'avvento degli **switch** e dei collegamenti *full-duplex*, Ethernet è diventata a **stella sia fisica che logica**: ogni dispositivo ha un canale dedicato verso lo switch, senza più collisioni né bus condivisi.
- **Wi-Fi:** l'architettura è **fisicamente a stella** (tutti i dispositivi comunicano con un Access Point centrale), ma poiché condividono la stessa frequenza radio nell'etere, il canale si comporta **logicamente come un mezzo condiviso a contesa**, ereditando la necessità di regole per evitare le collisioni proprio come accadeva nei vecchi bus cablati.
:::

---

## 5. Modalità di trasmissione e tecniche di commutazione

### 5.1 Modalità d'uso del canale: Simplex, Half-Duplex, Full-Duplex

- **Simplex:** la trasmissione avviene in un'unica direzione prefissata; il trasmettitore invia i dati e il ricevitore può solo riceverli, senza possibilità di replica (es. radio e televisione tradizionali, sensori di telemetria unidirezionali).
- **Half-Duplex:** la trasmissione può avvenire in entrambe le direzioni, ma **non contemporaneamente** (a turno). Il canale è condiviso e chi trasmette deve attendere che l'altro abbia terminato (es. walkie-talkie, Wi-Fi sullo stesso canale radio, vecchie reti Ethernet con hub).
- **Full-Duplex:** la trasmissione può avvenire in entrambe le direzioni **contemporaneamente**, grazie a canali di invio e ricezione fisicamente o logicamente separati (es. normale telefonata, connessioni Ethernet moderne su doppino intrecciato o fibra con switch).

---

### 5.2 Il processo di commutazione (Switching)

<!-- thumbnail -->
<div class="thumbnail tright mb-2">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/commutazione.png" class="modal__opener" aprire="#img-commutazione">
  <p>Principio di funzionamento di un nodo di commutazione: i dati in ingresso da un canale vengono instradati sul canale di uscita appropriato</p>
</div>
<!-- modal -->
<div id="img-commutazione" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-commutazione">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/commutazione.png">
    </div>
    <p>Principio di funzionamento di un nodo di commutazione: i dati in ingresso da un canale vengono instradati sul canale di uscita appropriato</p>
  </div>
</div>

Nelle reti che collegano sorgente e destinatario attraverso più nodi intermedi, la **commutazione** è il processo con cui un nodo riceve i dati da una linea di ingresso e determina su quale linea di uscita inoltrarli per farli progredire verso la meta.

I due paradigmi architetturali storici sono la **commutazione di circuito** e la **commutazione di pacchetto**.

---

#### Commutazione di circuito

<!-- thumbnail -->
<div class="thumbnail tright mb-2">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/commutazione_di_circuito.png" class="modal__opener" aprire="#img-commutazione_di_circuito">
  <p>Schema di una rete a commutazione di circuito</p>
</div>
<!-- modal -->
<div id="img-commutazione_di_circuito" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-commutazione_di_circuito">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/commutazione_di_circuito.png">
    </div>
    <p>Schema di una rete a commutazione di circuito</p>
  </div>
</div>

È il modello originario della **rete telefonica tradizionale** (PSTN):
1. **Fase di instaurazione:** prima di trasmettere qualsiasi informazione, la rete crea un percorso fisico o una porzione di banda dedicata e riservata da mittente a destinatario (chiamata telefonica).
2. **Fase di trasferimento dati:** i dati fluiscono lungo il circuito dedicato con ritardo costante e banda garantita.
3. **Fase di rilascio:** al termine della conversazione il circuito viene smantellato e le risorse rese disponibili per altre comunicazioni.

- **Il grande difetto nelle reti dati:** il traffico informatico non è continuo, ma fortemente irregolare e "a raffiche" (*bursty*, con lunghi silenzi alternati a scambi rapidi di bit). Mantenere un circuito dedicato impegnato durante le pause di trasmissione costituisce un enorme spreco di risorse ed è economicamente insostenibile su Internet.

---

#### Commutazione di pacchetto (il fondamento di Internet)

<!-- thumbnail -->
<div class="thumbnail tright mb-2">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/commutazione_di_pacchetto_datagram.png" class="modal__opener" aprire="#img-commutazione_di_pacchetto_datagram">
  <p>Schema di una rete a commutazione di pacchetto: i pacchetti numerati possono seguire percorsi diversi e giungere a destinazione</p>
</div>
<!-- modal -->
<div id="img-commutazione_di_pacchetto_datagram" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-commutazione_di_pacchetto_datagram">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/commutazione_di_pacchetto_datagram.png">
    </div>
    <p>Schema di una rete a commutazione di pacchetto: i pacchetti numerati possono seguire percorsi diversi e giungere a destinazione</p>
  </div>
</div>

Nelle reti digitali moderne il messaggio da trasmettere viene suddiviso alla sorgente in blocchi di dimensione contenuta chiamati **pacchetti**.

Ogni pacchetto è composto essenzialmente da:
- **Intestazione (Header):** contiene i dati di controllo necessari per la gestione e l'instradamento, in primis l'indirizzo del mittente (*source IP*), l'indirizzo del destinatario (*destination IP*), codici di controllo errore (*checksum*) e numeri di sequenza.
- **Dati utili (Payload):** l'effettivo frammento di messaggio dell'utente.

I pacchetti viaggiano attraverso la rete in modo indipendente, condividendo dinamicamente le linee di trasmissione con i pacchetti di altre comunicazioni (**multiplazione statistica**). Ciascun nodo intermedio (router) riceve un pacchetto, lo memorizza momentaneamente nel proprio buffer, ne legge l'indirizzo di destinazione e lo reinstrada verso il nodo successivo più idoneo (**store-and-forward**).

- **Perché Internet usa i pacchetti?**
  1. *Efficienza del canale:* le linee trasmissive vengono occupate solo quando ci sono pacchetti da spedire; se una sorgente tace, il canale è immediatamente utilizzabile da altri.
  2. *Robustezza ai guasti:* se un router o una tratta si interrompe a metà comunicazione, i pacchetti successivi vengono instradati automaticamente su un percorso alternativo.
  3. *Gestione efficiente degli errori:* se un pacchetto arriva danneggiato, l'host mittente dovrà ritrasmettere solo quel singolo pacchetto e non l'intero file.

I due approcci principali alla commutazione di pacchetto sono:
- **A datagramma (Connectionless):** è il modello del protocollo **IP** alla base di Internet. Ogni pacchetto è un'entità autonoma. I pacchetti possono seguire percorsi differenti a seconda dello stato di congestione dei router e possono arrivare a destinazione con ritardi variabili o persino fuori sequenza. Spetterà ai protocolli di livello superiore sull'host ricevente (come TCP) riordinare i pacchetti e richiedere l'eventuale reinvio di quelli smarriti.
- **A circuiti virtuali (Connection-oriented):** prima di inviare i dati si negozia un cammino logico fisso attraverso i nodi intermedi. Tutti i pacchetti della sessione seguiranno la medesima sequenza di nodi, garantendo l'ordine di arrivo e parametri di qualità di servizio (QoS) più controllati. Storicamente impiegato in reti come X.25, Frame Relay, ATM e parzialmente rivisitato nelle tecnologie di commutazione per etichette (MPLS).

---

### 5.3 Modalità con connessione e senza connessione (a livello di trasporto/servizio)

Quando due applicazioni comunicano attraverso la rete, il servizio di trasporto offerto dai protocolli può essere:

- **Connection-oriented (a connessione):**
  - Prima di scambiare dati reali, mittente e destinatario eseguono una procedura preliminare di accordo (*handshake*) per sincronizzarsi e allocare le risorse logiche.
  - La sessione offre garanzie: consegna affidabile dei dati, controllo di flusso per non sovraccaricare il ricevente e corretto riordino dei frammenti.
  - Al termine dello scambio la sessione viene esplicitamente chiusa.
  - *Esempio principe:* il protocollo **TCP**, impiegato per la navigazione web sicura (HTTPS), l'invio di email e il download di file.
- **Connectionless (senza connessione):**
  - Il mittente invia immediatamente i dati senza alcun preavviso o handshake preliminare.
  - Non vi sono conferme di ricezione (*acknowledgement*) né garanzie di riordino automatico; il protocollo adotta una politica detta *best-effort* (fa il massimo per consegnare il pacchetto, ma non lo garantisce).
  - Offre in cambio grandissima velocità e minimo sovraccarico (*overhead*).
  - *Esempio principe:* il protocollo **UDP**, largamente utilizzato per videochiamate in tempo reale, streaming live, giochi online multiplayer e richieste DNS, dove una lieve perdita di pacchetti è preferibile ai ritardi introdotti dalle ritrasmissioni.

---

## 6. L'architettura globale di Internet

Internet non ha un centro di comando unico né appartiene a una singola organizzazione: è una **"rete di reti"** cooperativa e interconnessa, formata da decine di migliaia di reti autonome denominate **Autonomous Systems (AS)** (gestite da università, grandi aziende tech, centri di ricerca e operatori di telecomunicazioni).

La spina dorsale di Internet è strutturata gerarchicamente attraverso diversi livelli di fornitori di servizi di connettività, detti **ISP** (*Internet Service Provider*):

1. **ISP di Livello 1 (Tier 1 - Dorsale globale):**
   - Una dozzina di grandi colossi internazionali delle telecomunicazioni (es. NTT, AT&T, Lumen, Telia, Telecom Italia Sparkle/Seabone) che possiedono le grandi dorsali in fibra ottica terrestri e i cavi sottomarini transoceanici.
   - Sono interconnessi tra loro in una struttura a maglia con accordi di **peering paritario** (non pagano pedaggio l'uno all'altro per scambiarsi traffico). Costituiscono il nucleo (*core*) di Internet e sono in grado di raggiungere qualsiasi destinazione globale.
2. **ISP di Livello 2 (Tier 2 - Operatori nazionali e regionali):**
   - Operatori con copertura nazionale o continentale. Acquistano servizi di transito a pagamento dagli ISP Tier 1 per accedere al resto del mondo e stipulano accordi di scambio reciproco con altri Tier 2.
3. **ISP di Livello 3 (Tier 3 - Reti di accesso locale):**
   - I provider a cui si collegano gli utenti finali (utenze residenziali, scuole, piccole e medie imprese). Utilizzano reti di accesso in fibra (FTTH/FTTC), rame (ADSL/VDSL) o ponti radio/cellulari (FWA, 4G, 5G) e acquistano il traffico di transito dagli ISP di livello superiore.

:::note[I punti di interscambio: gli IXP]
Per evitare che il traffico tra due utenti della stessa nazione o città debba percorrere lunghe e costose tratte internazionali verso i Tier 1, gli operatori si incontrano in speciali nodi fisici neutrali chiamati **IXP (Internet Exchange Point)** (in Italia il più noto è il *MIX* di Milano, o il *Namex* di Roma). Qui gli ISP e i grandi distributori di contenuti (Google, Netflix, Meta, Amazon) collegano i loro router per scambiarsi traffico locale a bassissima latenza e a costi ridotti.
:::

---

## 7. Verso i modelli a strati

Come emerge da questa panoramica iniziale, il funzionamento di una rete richiede di risolvere contemporaneamente una quantità straordinaria di problemi eterogenei:
- Gestire segnali elettrici, impulsi di luce e onde radio sul mezzo fisico.
- Riconoscere i dispositivi all'interno della stessa rete locale e regolarne l'accesso al canale.
- Instradare i pacchetti lungo percorsi ottimali attraverso router distribuiti in tutto il mondo.
- Garantire l'integrità, l'affidabilità e la sicurezza della comunicazione.
- Interfacciare i flussi di dati con le applicazioni usate dagli utenti finali (browser, client di posta, app mobili).

Gestire tutte queste funzioni in un unico blocco monolitico sarebbe impossibile. Per questo motivo l'ingegneria delle reti adotta un'architettura modulare fondata sul concetto di **pila protocollare a livelli**.

Nel capitolo successivo verrà introdotto il modello teorico di riferimento: il **[Modello ISO/OSI](/manuale-libero-online-di-informatica/reti/iso-osi/iso-osi/)**, che scompone il problema della comunicazione di rete in 7 livelli logici gerarchici.