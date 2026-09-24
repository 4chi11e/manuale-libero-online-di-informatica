---
title: Livello 2 - Collegamento Dati
---

Il **Livello di Collegamento Dati** (*Data Link Layer*) è il secondo strato del modello ISO/OSI.

Mentre il Livello Fisico si limita a trasmettere un flusso grezzo e continuo di bit sul canale, il compito del Livello 2 è trasformare quel canale in un mezzo di comunicazione affidabile ed efficiente tra due nodi **direttamente adiacenti**, ossia appartenenti alla stessa rete locale o collegati dalla medesima tratta fisica.

La **PDU** (Protocol Data Unit) di questo livello è il **Frame** (o *Trama*): una sequenza di byte strutturata, provvista di un'intestazione (*header*) e di una coda (*trailer*) che racchiudono il pacchetto proveniente dal Livello di Rete.

---

## 1. La suddivisione IEEE 802: LLC e MAC

Nelle reti locali (LAN cablate e wireless), lo standard internazionale **IEEE 802** suddivide il Livello 2 in due sotto-livelli funzionali: **LLC** (in alto) e **MAC** (in basso).

*Perché questa divisione?*  
In alto c'è il software di rete (**protocollo IP**, Livello 3), che è unico e vuole lavorare sempre nello stesso modo. In basso, invece, ci sono mezzi fisici molto diversi tra loro: un cavo in rame Ethernet gestisce i segnali in modo completamente differente rispetto alle onde radio del Wi-Fi.

Il Livello 2 viene quindi separato in due ruoli specializzati:

1. **LLC (Logical Link Control - IEEE 802.2 - Sotto-livello superiore):**
   - Agisce come un **"adattatore universale"** tra l'hardware di rete sottostante e il Livello 3 (IP) soprastante.
   - Nasconde le differenze fisiche: grazie a LLC, al protocollo IP non importa se i dati viaggeranno su un cavo in rame, su fibra ottica o via Wi-Fi; per IP la rete sottostante appare e si comporta sempre allo stesso modo.
   - Quando riceve i dati dal basso, legge a quale protocollo del livello superiore devono essere consegnati (ad esempio se a IPv4, a IPv6 o ad ARP).

2. **MAC (Medium Access Control - Sotto-livello inferiore):**
   - È la parte a diretto contatto con la tecnologia fisica (Ethernet, Wi-Fi, Bluetooth): ogni mezzo ha il proprio specifico MAC.
   - Regola **l'accesso al canale** (decide quando una scheda può trasmettere per evitare interferenze o collisioni), costruisce fisicamente il frame aggiungendo header e trailer, e gestisce l'indirizzamento hardware tramite gli **indirizzi MAC**.

---

## 2. L'Indirizzo MAC (Indirizzo Fisico)

Per recapitare un frame al calcolatore corretto all'interno di una rete locale, ogni interfaccia di rete (NIC) deve essere univocamente identificabile. Questa identificazione avviene tramite l'**indirizzo MAC** (*Media Access Control address*), noto anche come **indirizzo fisico** o **hardware**.

L'indirizzo MAC è un codice a **48 bit (6 byte)** impresso originariamente dal costruttore nella memoria non volatile (ROM/EEPROM) della scheda di rete (motivo per cui in inglese viene detto *Burned-In Address* o BIA).

:::note[Il MAC è davvero immutabile? (MAC Spoofing e Privacy)]
Sebbene l'indirizzo originario sia impresso fisicamente nel chip di fabbrica, all'avvio il sistema operativo ne carica una copia in memoria e permette di **sovrascriverlo via software** (*MAC Spoofing*).  
Questa funzionalità è usata attivamente dagli smartphone (iOS, Android) e da Windows per proteggere la **privacy** (*MAC Address Randomization*): collegandosi a reti Wi-Fi pubbliche o commerciali, il dispositivo genera indirizzi MAC casuali e fittizi per impedire che gli spostamenti dell'utente vengano tracciati.
:::

### Formato e struttura

Convenzionalmente viene rappresentato con **6 coppie di cifre esadecimali** separate da due punti o trattini (ad esempio: `00:1A:2B:3C:4D:5E`).

I 48 bit sono suddivisi in due metà:
- **I primi 24 bit (3 byte) - OUI (Organizationally Unique Identifier):** identificano in modo esclusivo il **produttore hardware** della scheda di rete (ad esempio Intel, Cisco, Apple, Realtek). Questo prefisso viene assegnato ufficialmente dall'ente internazionale IEEE a ciascuna azienda.
- **Gli ultimi 24 bit (3 byte) - Identificatore di interfaccia:** costituiscono un numero seriale progressivo univoco assegnato dal costruttore a quella specifica scheda, garantendo che non esistano al mondo due schede di rete con lo stesso indirizzo MAC.

```
+--------------------------+--------------------------+
|  OUI (Costruttore)       |  Numero Seriale Univoco  |
|  24 bit (3 byte)         |  24 bit (3 byte)         |
+--------------------------+--------------------------+
|       00 : 1A : 2B       |       3C : 4D : 5E       |
+--------------------------+--------------------------+
```

### Tipologie di indirizzi MAC
- **Unicast:** identifica la singola interfaccia di rete di un calcolatore (comunicazione uno-a-uno).
- **Broadcast:** ha tutti i 48 bit posti a 1, ossia `FF:FF:FF:FF:FF:FF`. Un frame con questo indirizzo di destinazione viene preso in carico ed elaborato da tutte le schede di rete presenti nella LAN.
- **Multicast:** identifica un gruppo specifico di host; in ambito Ethernet su IPv4 inizia convenzionalmente con il prefisso riservato `01:00:5E:...`.

:::tip[Analogia: Codice Fiscale vs Indirizzo di Residenza]
La differenza tra indirizzo fisico (MAC) e indirizzo logico (IP) è analoga a quella tra codice fiscale e indirizzo di residenza:
- L'**indirizzo MAC** è come il **codice fiscale**: ti identifica a livello hardware fin dalla fabbrica.
- L'**indirizzo IP** (Livello 3) è come l'**indirizzo di residenza**: è geografico e gerarchico (Stato, Città, Via, Numero), e cambia ogni volta che sposti il computer da una rete a un'altra (es. dal Wi-Fi di casa alla rete della scuola).
:::

---

## 3. Anatomia di un Frame Ethernet (IEEE 802.3)

Il processo di **framing** consiste nel racchiudere il pacchetto dati proveniente dal Livello 3 tra specifici campi di intestazione (*header*) e di coda (*trailer*).

La struttura di un frame Ethernet standard comprende i seguenti campi:

| Preambolo + SFD | MAC Destinatario | MAC Mittente | EtherType | Payload (Dati L3) | FCS / CRC |
| :---: | :---: | :---: | :---: | :---: | :---: |
| 7 + 1 byte | 6 byte | 6 byte | 2 byte | 46 – 1500 byte | 4 byte |

1. **Preambolo e SFD (8 byte):** una sequenza di bit alternati `101010...` che consente al circuito ricevente di agganciare la frequenza di clock del trasmettitore; si conclude con il byte `10101011` (*Start of Frame Delimiter*) che segnala l'inizio dei dati veri e propri.
2. **MAC Destinatario (6 byte):** l'indirizzo fisico del dispositivo che deve ricevere il frame.
3. **MAC Mittente (6 byte):** l'indirizzo fisico della scheda che ha generato o ritrasmesso il frame.
4. **EtherType (2 byte):** indica quale protocollo di Livello 3 è trasportato nel payload (ad esempio `0x0800` per IPv4, `0x86DD` per IPv6, `0x0806` per una richiesta ARP).
5. **Payload / Dati (da 46 a 1500 byte):** il pacchetto informativo del livello superiore. La dimensione massima standard trasferibile in un singolo frame Ethernet è pari a **1500 byte**, valore noto come **MTU** (*Maximum Transmission Unit*). Se il pacchetto è inferiore a 46 byte, viene aggiunto un riempimento di bit a zero (*padding*) per raggiungere la lunghezza minima di 64 byte complessivi.
6. **FCS / CRC (4 byte - Frame Check Sequence):** sequenza di controllo a ridondanza ciclica per la rilevazione degli errori. Prima di inviare il frame, il mittente applica un algoritmo matematico (CRC-32) su tutti i bit e memorizza il risultato nell'FCS. All'arrivo, il ricevitore esegue lo stesso calcolo: se il risultato coincide il frame è valido, altrimenti **è corrotto e viene scartato immediatamente**.

:::note[In Ethernet non c'è ACK!]
Un errore diffuso è pensare che a Livello 2 il ricevitore risponda sempre confermando ogni frame ricevuto con un pacchetto di *ACK* (acknowledgement). Nelle reti Ethernet cablate **non esiste alcun riscontro positivo**: la trasmissione è veloce e *connectionless*. Se un frame si corrompe lungo il cavo, viene scartato in silenzio; spetterà ai protocolli affidabili di Livello 4 (come TCP) accorgersi dell'eventuale mancanza e richiedere la ritrasmissione.  
L'unica eccezione rilevante è il **Wi-Fi (802.11)**: poiché il mezzo radio è molto instabile e soggetto a forti interferenze, nel Wi-Fi ogni frame richiede una ricevuta ACK immediata già al Livello 2.
:::

---

## 4. Apparati di Livello 2: Bridge e Switch

I dispositivi di Livello 2 sono in grado di interpretare i singoli bit in arrivo dal Livello Fisico, ricostruire il frame ed esaminare gli indirizzi MAC per prendere decisioni intelligenti di inoltro.

### 4.1 Il Bridge (Ponte)

<!-- thumbnail -->
<div class="thumbnail float-right clear-both mb-2">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/schema_bridge.jpg" class="modal__opener" aprire="#img-schema_bridge">
  <p>Schema di comunicazione tra host per mezzo di un bridge</p>
</div>
<!-- modal -->
<div id="img-schema_bridge" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-schema_bridge">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/schema_bridge.jpg">
    </div>
    <p>Il bridge collega due segmenti di rete separando i domini di collisione</p>
  </div>
</div>

Introdotto negli anni '80, il **bridge** è un dispositivo a due porte impiegato per connettere due segmenti separati di una stessa LAN.

A differenza dei ripetitori di Livello 1, il bridge legge il MAC destinatario: se la comunicazione avviene tra due computer che risiedono sullo stesso segmento, il bridge blocca il frame evitando che vada a intasare il secondo segmento. È stato il primo dispositivo capace di **isolare i domini di collisione**.

---

### 4.2 Lo Switch (Bridge multiporta ad alte prestazioni)

<!-- thumbnail -->
<div class="thumbnail float-right clear-both mb-2">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/switch-rack.jpg" class="modal__opener" aprire="#img-switch-rack">
  <p>Armadio rack con switch di rete a 24 porte</p>
</div>
<!-- modal -->
<div id="img-switch-rack" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-switch-rack">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/switch-rack.jpg">
    </div>
    <p>Switch montati in un rack aziendale per collegare centinaia di postazioni</p>
  </div>
</div>

Lo **switch** rappresenta l'evoluzione moderna del bridge: è un apparato provvisto di numerose porte (tipicamente 8, 24 o 48) che opera a velocità di linea tramite circuiti integrati dedicati ad altissime prestazioni (ASIC).

#### Come funziona uno Switch? (L'algoritmo di apprendimento e inoltro)
Uno switch non necessita di configurazione manuale iniziale: è un apparato *plug-and-play* che apprende autonomamente la topologia della rete costruendo una tabella interna detta **MAC Address Table** (o tabella CAM).

Quando un frame giunge su una porta dello switch, l'apparato compie due operazioni sequenziali:

1. **Auto-apprendimento (*Learning*):**
   - Lo switch esamina il **MAC Sorgente** del frame e la porta su cui è arrivato.
   - Registra l'associazione nella propria tabella: ad esempio *"Il calcolatore con MAC AA:AA:AA:AA:AA:AA è collegato alla Porta 3"*, associando un timer di scadenza (*aging timer*).
2. **Decisione di inoltro (*Forwarding, Filtering, Flooding*):**
   - Lo switch esamina il **MAC Destinatario** e consulta la propria tabella:
     - **Forwarding (Inoltro mirato):** se il MAC destinatario è presente in tabella su una porta diversa da quella di ingresso, il frame viene trasmesso **solo ed esclusivamente su quella specifica porta**.
     - **Filtering (Filtraggio):** se il MAC destinatario è associato alla **stessa porta** da cui è entrato il frame, lo switch scarta il frame senza replicarlo altrove. Questo accade quando a una singola porta sono collegati più dispositivi (ad esempio tramite un **secondo switch in cascata**, un **Access Point Wi-Fi** a cui sono agganciati decine di smartphone, o un server con più macchine virtuali): lo switch capisce che il destinatario si trova già su quel medesimo ramo e non occorre occupare le altre porte.
     - **Flooding (Diffusione cieca):** se il MAC destinatario non è ancora presente in tabella (*Unknown Unicast*), oppure se si tratta di un indirizzo di **Broadcast** (`FF:FF:FF:FF:FF:FF`), lo switch inoltra il frame su **tutte le altre porte** tranne quella di provenienza, in attesa che il destinatario risponda rivelando la propria posizione.

---

### 4.3 Domini di Collisione e Domini di Broadcast

La presenza dello switch trasforma radicalmente l'architettura della rete locale:

- **Isolamento dei domini di collisione (Microsegmentazione):**  
  Ogni singola porta dello switch costituisce un dominio di collisione indipendente. Poiché le connessioni operano in **Full-Duplex** (canali di trasmissione e ricezione separati), host e switch possono trasmettere contemporaneamente alla massima velocità senza che si verifichi alcuna collisione.
- **Unicità del dominio di broadcast:**  
  Lo switch **non isola il traffico di broadcast**. Se un host invia un pacchetto broadcast, lo switch lo inonda su tutte le porte. Di conseguenza, tutti i dispositivi collegati a uno switch (o a una cascata di switch interconnessi) appartengono allo **stesso dominio di broadcast**.

:::note[Le VLAN (Virtual Local Area Network)]
Negli switch gestibili (*managed switch*) è possibile superare il limite dell'unico dominio di broadcast configurando le **VLAN (standard IEEE 802.1Q)**. Una VLAN permette di partizionare logicamente un singolo switch fisico in più reti locali virtuali indipendenti (ad esempio, isolando la rete dei laboratori da quella della segreteria o dei docenti), impedendo al traffico broadcast di passare da una VLAN all'altra senza il controllo di un router.
:::

---

## 5. Il passaggio al livello superiore: perché serve il Livello 3?

Se gli switch e gli indirizzi MAC permettono a centinaia di computer di dialogare in una LAN alla velocità della luce e senza collisioni, *perché non usiamo gli indirizzi MAC e gli switch per gestire l'intera rete Internet?*

La ragione risiede nella natura degli indirizzi MAC:
- Gli indirizzi MAC sono **indirizzi "piatti" (non gerarchici)**. L'indirizzo MAC non contiene alcuna informazione sulla posizione geografica del computer o sulla rete a cui è connesso: avere l'indirizzo MAC di un server situato a Tokyo non fornisce alcun indizio su come instradare i dati attraverso l'Oceano per raggiungerlo.
- Se Internet fosse basata solo su switch, le tabelle di memoria degli apparati dovrebbero contenere miliardi di indirizzi MAC individuali e qualsiasi richiesta broadcast si propagherebbe istantaneamente su tutti i calcolatori del pianeta, provocando il collasso immediato dell'infrastruttura mondiale (*broadcast storm*).

Per collegare tra loro reti eterogenee su scala planetaria è indispensabile un sistema di **indirizzamento logico, gerarchico e instradabile**: è questo il compito del **[Livello 3 - Rete](/manuale-libero-online-di-informatica/reti/iso-osi/livello3/)** e del protocollo **IP**.
