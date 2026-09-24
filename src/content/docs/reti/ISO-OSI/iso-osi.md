---
title: Il Modello ISO/OSI
---

Agli albori dell'informatica, negli anni '70, ogni grande costruttore di calcolatori (come IBM, DEC, Xerox) sviluppava la propria architettura di rete proprietaria e chiusa. Il risultato era un'intrinseca incompatibilità: due sistemi di marche diverse non potevano comunicare tra loro se non attraverso costosi e complessi apparati di adattamento.

Per superare questa frammentazione, nel 1984 l'**ISO** (*International Organization for Standardization*) definì lo standard **ISO 7498**, noto come modello **OSI** (*Open Systems Interconnection*): un'architettura di riferimento aperta, modulare e indipendente dai produttori hardware, concepita per consentire l'interoperabilità tra sistemi eterogenei in tutto il mondo.

---

## 1. Architettura modulare a strati

Il modello ISO/OSI affronta la straordinaria complessità della comunicazione di rete applicando il principio del *divide et impera*: scompone il processo di trasmissione in una pila (*stack*) gerarchica di **7 livelli logici** (detti *layer*).

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/OSI_Model_v1-ita.png" class="modal__opener" aprire="#img-modello-ISO-OSI">
  <p>I 7 livelli del modello di riferimento ISO/OSI</p>
</div>
<!-- modal -->
<div id="img-modello-ISO-OSI" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-modello-ISO-OSI">&times;</span>
    <div class="modal__content__img-container--double">
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/OSI_Model_v1-eng.png">
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/OSI_Model_v1-ita.png">
    </div>
    <p>Il modello di riferimento OSI in italiano e in inglese</p>
  </div>
</div>

Ciascun livello:
1. **Ha un compito specifico e ben delimitato** (ad esempio: determinare il percorso migliore, controllare gli errori di trasmissione o convertire i bit in segnali fisici).
2. **Fornisce un insieme ben definito di servizi al livello superiore**, mettendogli a disposizione funzionalità pronte all'uso.
3. **Si appoggia al livello inferiore considerandolo come una "scatola nera"**: al livello superiore non interessa *come* il livello sottostante svolga il proprio lavoro né con quale tecnologia. Ad esempio, a un browser web (livello Applicazione) non importa se i bit viaggiano su un cavo in rame, su onde radio Wi-Fi o su fibra ottica; gli basta richiedere al livello inferiore di recapitare i dati.

Questo approccio conferisce una fondamentale **indipendenza modulare (astrazione)**: è possibile modificare, aggiornare o sostituire completamente il protocollo o la tecnologia adottata a un determinato livello senza dover toccare in alcun modo i livelli sovrastanti o le applicazioni usate dagli utenti.

:::note[L'indipendenza è sempre assoluta?]
Sebbene nella teoria dei modelli a strati i livelli siano concepiti come moduli indipendenti, nella pratica ingegneristica reale delle reti esistono alcune eccezioni significative:
- **Protocolli cerniera:** alcuni protocolli nascono specificamente per raccordare due livelli contigui ben precisi, come **ARP** (*Address Resolution Protocol*), che traduce gli indirizzi logici IP (Livello 3) nei corrispondenti indirizzi fisici MAC (Livello 2) all'interno delle reti Ethernet.
- **Interdipendenze prestazionali e di controllo:** per garantire la massima efficienza e sicurezza, alcuni protocolli di livello superiore "sbirciano" nei campi del livello inferiore. L'esempio più noto è il protocollo di trasporto **TCP** (Livello 4), che include gli indirizzi IP sorgente e destinatario (campi propri del Livello 3) all'interno del calcolo del proprio codice di controllo errore (*checksum*).
:::

---

## 2. Comunicazione logica e incapsulamento

Il modello realizza una **comunicazione virtuale orizzontale**: il livello $N$ sul computer trasmittente dialoga idealmente con il corrispondente livello $N$ sul computer ricevente (*peer-to-peer layer*), rispettando le regole del protocollo di quel livello.

Fisicamente, tuttavia, i dati non possono "saltare" direttamente da un'applicazione all'altra: devono scendere verticalmente lungo la pila del mittente, attraversare il mezzo fisico sotto forma di segnali, e risalire la pila del ricevitore.

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/incapsulamento.png" class="modal__opener" aprire="#img-ISO-OSI-incapsulamento">
  <p>Processo di incapsulamento (discesa) e decapsulamento (risalita) dei dati</p>
</div>
<!-- modal -->
<div id="img-ISO-OSI-incapsulamento" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-ISO-OSI-incapsulamento">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/incapsulamento.png">
    </div>
    <p>Processo di incapsulamento e decapsulamento attraverso i livelli</p>
  </div>
</div>

### Il meccanismo dell'incapsulamento

Questo passaggio avviene tramite l'**incapsulamento** (o *imbustamento*):

1. **In trasmissione (discesa lungo lo stack):**
   - L'applicazione genera un messaggio o flusso dati.
   - Ogni livello riceve i dati dal livello superiore (che rappresentano il suo carico utile o **Payload**) e vi antepone la propria **Intestazione** (**Header**), contenente le informazioni di controllo necessarie per quel livello (es. numeri di porta, indirizzi IP, codici di stato).
   - Il Livello 2 (Collegamento) aggiunge solitamente anche una **Coda** (**Trailer**), contenente codici di controllo ridondanza (come il *CRC / Frame Check Sequence*) per verificare l'assenza di errori di trasmissione.
   - Giunti al Livello 1 (Fisico), l'intero blocco viene convertito in una sequenza continua di bit elettrici, ottici o elettromagnetici sul canale.
2. **In ricezione (risalita lungo lo stack):**
   - Il ricevitore riceve i bit a livello fisico, ricostruisce il blocco e lo passa verso l'alto (**decapsulamento** o *sbustamento*).
   - Ciascun livello legge e interpreta l'header a lui destinato, esegue le opportune verifiche, scarta l'header ed estrae il payload, passandolo intatto al livello superiore fino a giungere all'applicazione.

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/ISO-OSI-parallelo_posta.svg" class="modal__opener" aprire="#img-ISO-OSI-parallelo_posta">
  <p>Analogia tra il sistema postale e il modello ISO/OSI</p>
</div>
<!-- modal -->
<div id="img-ISO-OSI-parallelo_posta" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-ISO-OSI-parallelo_posta">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/ISO-OSI-parallelo_posta.svg">
    </div>
    <p>Parallelo tra la spedizione postale tradizionale e la comunicazione a livelli ISO/OSI</p>
  </div>
</div>

:::tip[L'analogia del servizio postale]
Pensa a quando scrivi una lettera:
- Tu componi il testo della lettera (**Dati / Livello Applicativo**).
- La inserisci in una busta con l'indirizzo del destinatario (**Header di Livello Rete**).
- Il postino raggruppa le buste in un sacco postale contrassegnato per il centro di smistamento locale (**Header di Livello Collegamento**).
- Il sacco viene caricato su un furgone o su un aereo che percorre la strada fisica (**Livello Fisico**).
- All'arrivo il sacco viene aperto, la busta estratta e consegnata all'ufficio, e il destinatario apre la busta per leggere il messaggio originario.
:::

---

### Unità di dati nei diversi livelli (PDU)

Nelle reti ogni blocco dati formattato a un determinato livello prende il nome formale di **PDU** (*Protocol Data Unit*). Sebbene colloquialmente si usi spesso la parola generica "pacchetto", la terminologia tecnica rigorosa è la seguente:

- **Livelli 7, 6, 5 (Applicazione, Presentazione, Sessione):** **Dati** (*Message / Data*)
- **Livello 4 (Trasporto):** **Segmento** (per il protocollo TCP) o **Datagramma** (per il protocollo UDP)
- **Livello 3 (Rete):** **Pacchetto** (in ambito IP spesso detto *Datagramma IP*)
- **Livello 2 (Collegamento dati):** **Frame** (o *Trama*)
- **Livello 1 (Fisico):** **Bit** (flusso continuo di 0 e 1)

---

## 3. Panoramica dei 7 Livelli ISO/OSI

I sette livelli vengono concettualmente ripartiti in due grandi categorie:
- **Media Layers (Livelli inferiori 1, 2, 3):** gestiscono il transito dei dati attraverso l'infrastruttura di rete e sono implementati anche dagli apparati intermedi (switch, router).
- **Host Layers (Livelli superiori 4, 5, 6, 7):** operano da capo a capo (*end-to-end*) esclusivamente tra i nodi terminali (i computer mittente e destinatario), garantendo l'integrità della comunicazione e l'interfaccia con i programmi utente.

| # | Livello | PDU | Funzione principale | Esempi di tecnologie e protocolli |
|---|---|---|---|---|
| **7** | **Applicazione** | Dati | Offre servizi di rete direttamente ai processi e alle applicazioni dell'utente. | HTTP, HTTPS, DNS, SMTP, FTP, SSH, DHCP |
| **6** | **Presentazione** | Dati | Gestisce la sintassi e la semantica dei dati: codifica caratteri, compressione e cifratura. | TLS/SSL, ASCII, UTF-8, JPEG, MPEG, JSON |
| **5** | **Sessione** | Dati | Instaura, mantiene, sincronizza e termina le sessioni di dialogo tra applicazioni. | NetBIOS, RPC, checkpoint e gestione token |
| **4** | **Trasporto** | Segmento / Datagramma | Consegna affidabile *end-to-end*, controllo del flusso, correzione errori, multiplexing su porte. | TCP, UDP |
| **3** | **Rete** | Pacchetto | Indirizzamento logico globale (IP) e instradamento (*routing*) attraverso reti eterogenee. | IPv4, IPv6, ICMP, router |
| **2** | **Collegamento** | Frame | Trasferimento affidabile su collegamento diretto tra nodi adiacenti, indirizzi fisici (MAC), framing. | Ethernet, Wi-Fi (802.11), switch |
| **1** | **Fisico** | Bit | Trasmissione di segnali non strutturati (tensioni, impulsi luminosi, onde radio) sul canale fisico. | Cavi in rame (UTP), fibra ottica, onde radio, connettori RJ-45 |

---

## 4. ISO/OSI e TCP/IP: Teoria vs Realtà

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/ISO-OSI-TCP-IP-layers.png" class="modal__opener" aprire="#img-ISO-OSI-TCP-IP-layers">
  <p>Confronto tra i livelli ISO/OSI e la pila TCP/IP</p>
</div>
<!-- modal -->
<div id="img-ISO-OSI-TCP-IP-layers" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-ISO-OSI-TCP-IP-layers">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/ISO-OSI-TCP-IP-layers.png">
    </div>
    <p>Confronto tra la struttura a 7 livelli OSI e la struttura a 4 livelli TCP/IP</p>
  </div>
</div>

Una delle domande più frequenti è: *se il modello ISO/OSI è così dettagliato e ben strutturato, perché Internet utilizza il modello TCP/IP?*

- **Il Modello ISO/OSI è un modello concettuale di riferimento (*de jure*):** fu progettato a tavolino da commissioni di esperti con l'obiettivo di definire in modo rigoroso e astratto ogni singolo aspetto della comunicazione. La sua suddivisione a 7 strati è ideale per lo studio e la progettazione, ma nella realtà pratica si è visto che mantenere livelli separati per ogni singola funzione (come Sessione e Presentazione) introduceva inutili sovraccarichi di elaborazione.
- **La Suite TCP/IP è uno standard di fatto (*de facto*):** nacque sul campo con lo sviluppo di ARPANET seguendo un principio pragmatico (*"Rough consensus and running code"*). Per semplicità ed efficienza implementativa, molti protocolli reali preferiscono incorporare direttamente al loro interno funzionalità afferenti a più livelli teorici: ad esempio, i moderni protocolli applicativi (come HTTPS, SSH o le API web) gestiscono autonomamente la sessione, la formattazione dei dati e la cifratura (TLS), senza bisogno di attraversare livelli intermedi dedicati.

Internet ha adottato universalmente la pila **TCP/IP**. Tuttavia, il modello ISO/OSI rimane il vocabolario e il punto di riferimento concettuale imprescindibile: ancora oggi, nel mondo professionale, si parla comunemente di "apparato di Livello 2" o "filtro di Livello 4".

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/ISO-OSI-TCP-IP-protocolli.jpg" class="modal__opener" aprire="#img-ISO-OSI-TCP-IP-protocolli">
  <p>Protocolli principali nei vari livelli dello stack</p>
</div>
<!-- modal -->
<div id="img-ISO-OSI-TCP-IP-protocolli" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-ISO-OSI-TCP-IP-protocolli">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/ISO-OSI-TCP-IP-protocolli.jpg">
    </div>
    <p>Principali protocolli associati ai livelli TCP/IP e ISO/OSI</p>
  </div>
</div>

### La corrispondenza tra i due modelli

Il modello TCP/IP originale (RFC 1122) riduce la pila a **4 livelli**:

1. **Livello di Applicazione:** raggruppa le funzioni dei livelli 5 (Sessione), 6 (Presentazione) e 7 (Applicazione) di OSI. I programmatori di applicazioni web o di rete gestiscono direttamente codifiche, crittografia e sessioni.
2. **Livello di Trasporto:** corrisponde esattamente al Livello 4 OSI. È dominato da due protocolli complementari: **TCP** (affidabile e orientato alla connessione) e **UDP** (veloce, senza connessione e best-effort).
3. **Livello Internet (o Rete):** corrisponde al Livello 3 OSI. Definisce l'indirizzamento e l'instradamento globale attraverso il protocollo **IP** (IPv4 e IPv6), coadiuvato da protocolli di controllo come **ICMP**.
4. **Livello di Accesso alla Rete (Link / Network Interface):** raggruppa le funzioni dei livelli 1 (Fisico) e 2 (Collegamento) di OSI. L'architettura TCP/IP non vincola alcun protocollo specifico a questo livello, permettendo a IP di operare indifferentemente sopra cavi Ethernet, ponti Wi-Fi, fibre ottiche o connessioni mobili 4G/5G.

*(Didatticamente, molti testi moderni adottano il cosiddetto **modello a 5 livelli**, mantenendo separati il livello di Collegamento Dati e il livello Fisico sotto il livello Rete per maggiore chiarezza didattica).*

---

## 5. Corrispondenza tra apparati di rete e livelli

Una regola fondamentale delle architetture a livelli afferma che:
> **Un apparato che opera al livello $N$ deve necessariamente implementare ed elaborare tutti i livelli inferiori da $1$ fino ad $N$.**

In base a quale livello della pila riescono a "leggere" e interpretare per prendere decisioni di inoltro, gli apparati di rete si classificano come segue:

### 1. Dispositivi di Livello 1 (Fisico): Hub e Ripetitori

<!-- thumbnail -->
<div class="thumbnail float-right clear-both mb-2">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/ethernet_hub.jpg" class="modal__opener" aprire="#img-ethernet_hub">
  <p>Hub Ethernet a 4 porte (Livello 1)</p>
</div>
<!-- modal -->
<div id="img-ethernet_hub" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-ethernet_hub">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/ethernet_hub.jpg">
    </div>
    <p>Hub Ethernet: dispositivo privo di logica che ripete i segnali elettrici su tutte le porte</p>
  </div>
</div>

- Operano esclusivamente sui singoli **bit grezzi**.
- Non sanno cosa sia un indirizzo né che formato abbiano i dati: si limitano a rigenerare e amplificare il segnale elettrico in ingresso e a ritrasmetterlo su tutte le altre porte (*flooding* o diffusione cieca).
- Creano un unico **dominio di collisione**: sono apparati obsoleti, sostituiti stabilmente dagli switch.

### 2. Dispositivi di Livello 2 (Collegamento): Switch e Bridge

<!-- thumbnail -->
<div class="thumbnail float-right clear-both mb-2">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/switch.jpg" class="modal__opener" aprire="#img-switch">
  <p>Switch di rete a 24 porte (Livello 2)</p>
</div>
<!-- modal -->
<div id="img-switch" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-switch">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/switch.jpg">
    </div>
    <p>Switch di rete: isola i domini di collisione leggendo gli indirizzi MAC di Livello 2</p>
  </div>
</div>

- Operano sui **frame** e sono in grado di interpretare gli **indirizzi fisici (MAC)**.
- Grazie a una tabella di apprendimento dinamico (*MAC table*), lo switch inoltra il frame esclusivamente sulla porta verso cui risiede l'host destinatario.
- Separano i domini di collisione su ogni singola porta, permettendo comunicazioni simultanee in Full-Duplex ad alta velocità.

### 3. Dispositivi di Livello 3 (Rete): Router

<!-- thumbnail -->
<div class="thumbnail float-right clear-both mb-2">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/schema_router.jpg" class="modal__opener" aprire="#img-schema_router">
  <p>Schema di funzionamento di un router (Livello 3)</p>
</div>
<!-- modal -->
<div id="img-schema_router" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-schema_router">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/schema_router.jpg">
    </div>
    <p>Il router esamina l'indirizzo IP di destinazione (Livello 3) per instradare il pacchetto verso la rete corretta</p>
  </div>
</div>

- Operano sui **pacchetti** e leggono gli **indirizzi logici globali (indirizzi IP)**.
- Collegano tra loro reti locali differenti (inter-networking) e consultano tabelle di instradamento (*routing tables*) per decidere il cammino ottimale dei pacchetti verso la destinazione.
- Delimitano e isolano anche i **domini di broadcast** (un messaggio inviato in broadcast non attraversa mai un router).

### 4. Dispositivi di Livello Superiore (L4 – L7): Firewall, Proxy e Gateway

- **Firewall di trasporto / ispezione di stato (Livello 4):** esaminano le intestazioni TCP/UDP e i numeri di porta (es. porta 80/443 per web, porta 22 per SSH), bloccando o autorizzando il traffico in base a regole di sicurezza.
- **Proxy e Firewall applicativi / WAF (Livello 7):** analizzano il contenuto vero e proprio delle richieste applicative (es. ispezione di URL HTTP, filtraggio di contenuti, scansione antivirus, autenticazione utenti).
- **Gateway applicativi:** apparati che traducono interi protocolli tra sistemi completamente incompatibili.

---

## 6. Come proseguire lo studio

Nelle sezioni successive esamineremo in dettaglio le caratteristiche, i protocolli e il funzionamento dei singoli livelli:

- **[Livello 1 - Fisico](/manuale-libero-online-di-informatica/reti/iso-osi/livello1/):** mezzi trasmissivi, codifiche di linea, modulazione e connettori.
- **[Livello 2 - Collegamento](/manuale-libero-online-di-informatica/reti/iso-osi/livello2/):** framing, indirizzamento MAC, controllo di flusso ed errore, funzionamento dello switch.
- **[Livello 3 - Rete](/manuale-libero-online-di-informatica/reti/iso-osi/livello3/):** architettura IP, classi di indirizzi, subnetting pratico e instradamento dei router.
- **[Livello 4 - Trasporto](/manuale-libero-online-di-informatica/reti/iso-osi/livello4/):** porte logiche, confronto dettagliato TCP vs UDP, affidabilità e controllo di congestione.
- **[Livelli 5 e 6 - Sessione e Presentazione](/manuale-libero-online-di-informatica/reti/iso-osi/livello5/):** sincronizzazione, codifica e sicurezza (TLS/SSL).
- **[Livello 7 - Applicazione](/manuale-libero-online-di-informatica/reti/iso-osi/livello7/):** i protocolli del web, della posta elettronica e dei servizi di rete (HTTP/HTTPS, DNS, DHCP).
