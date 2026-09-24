---
title: Livello 1 - Fisico
---

Il **Livello Fisico** (*Physical Layer*) è il primo e più basso strato della pila protocollare ISO/OSI.

Mentre tutti i livelli superiori elaborano pacchetti e informazioni logiche strutturate, l'obiettivo del Livello Fisico è puramente operativo: **ricevere la sequenza di bit dal Livello 2 (Collegamento) e trasmetterla attraverso il canale di comunicazione sotto forma di segnali fisici continui** (impulsi di tensione elettrica sul rame, impulsi di luce nella fibra ottica o onde elettromagnetiche nello spazio libero), assicurando che il nodo ricevente sia in grado di riconvertire tali segnali nella medesima sequenza binaria.

La **PDU** (Protocol Data Unit) di questo livello è il **singolo Bit**: per il Livello Fisico i dati sono una sequenza non strutturata di 0 e 1, del tutto priva di significato o di suddivisione logica (non esistono indirizzi, né numeri di porta, né nomi di file).

---

## 1. Le quattro specifiche degli standard fisici

Per consentire a schede di rete, cavi e apparati di costruttori diversi di interconnettersi fisicamente senza incompatibilità, gli standard di livello fisico (come IEEE 802.3 per Ethernet o IEEE 802.11 per il Wi-Fi) regolano dettagliatamente quattro ambiti:

1. **Specifiche Meccaniche:** definiscono la forma fisica, le dimensioni geometriche e la disposizione dei piedini (*pin*) di spine, prese e connettori (ad esempio il connettore a 8 poli **RJ-45** per i cavi Ethernet in rame, i connettori a baionetta o a innesto **SC / LC** per la fibra ottica, o le guide d'onda e le antenne per le frequenze radio).
2. **Specifiche Elettriche e Ottiche:**
   - *Per i cavi in rame:* i valori di tensione elettrica associati agli stati logici (ad esempio $+2.5\text{ V}$ e $-2.5\text{ V}$), le correnti massime e la durata temporale di ciascun impulso di bit ($T_{bit} = 1 / R$, che a una velocità di $1\text{ Gbps}$ è pari a solo **$1\text{ nanosecondo}$**!).
   - *Per la fibra ottica:* le lunghezze d'onda impiegate da laser e LED (es. $850\text{ nm}$ per le fibre multimodali corte, $1310\text{ nm}$ o $1550\text{ nm}$ per le tratte monomodali oceaniche) e la potenza luminosa minima ricevibile espressa in dBm.
   - *Per il wireless:* le bande di frequenza radio allocate e la massima potenza irradiata consentita dalle leggi sulle telecomunicazioni.
3. **Specifiche Funzionali:** attribuiscono un significato preciso a ciascun pin o circuito del connettore. Ad esempio, nei cavi a doppino ritorto si specificano quali coppie sono assegnate alla trasmissione (*Tx+* e *Tx-*), quali alla ricezione (*Rx+* e *Rx-*), quali fungono da massa/schermo (*GND*) e quali possono trasportare energia per alimentare direttamente telefoni VoIP o videocamere (**PoE** - *Power over Ethernet*).
4. **Specifiche Procedurali:** stabiliscono la corretta sequenza temporale di segnali per attivare la linea, sincronizzare i circuiti di clock tra trasmettitore e ricevitore, negoziare la massima velocità supportata da entrambi gli estremi (*auto-negotiation*) e gestire la disattivazione del collegamento in caso di disconnessione.

---

## 2. Segnali, velocità e latenza

Dal punto di vista informatico, il livello fisico deve garantire il trasferimento rapido e corretto dei dati attraverso il canale. A questo scopo è utile distinguere due grandezze fondamentali:

1. **Velocità di trasmissione (Bit Rate):**
   - Misurata in bit al secondo (**bps**, **Mbps**, **Gbps**), indica la quantità di bit che la scheda di rete riesce a immettere nel canale ogni secondo.
2. **Latenza e ritardo di propagazione:**
   - Rappresenta il tempo impiegato dal segnale per percorrere la distanza fisica tra mittente e ricevitore. Sebbene i segnali viaggino a velocità prossime a quella della luce ($v \approx 200.000\text{ km/s}$ nel rame e nella fibra ottica), sulle grandi distanze geografiche o nei collegamenti satellitari questo ritardo fisico introduce un tempo di attesa inevitabile (da pochi millisecondi fino a centinaia di millisecondi).

:::note[Approfondimento: Come viaggiano i bit (Banda Base e Modulazione)]
Per chi vuole comprendere il legame tra informatica ed elettronica, i bit logici ($0$ e $1$) vengono convertiti in segnali fisici secondo due modalità:
- **Su cavo (Ethernet - Banda Base):** i bit vengono convertiti direttamente in impulsi di tensione elettrica o impulsi luminosi (usando tecniche di codifica che garantiscono la sincronizzazione del clock tra i dispositivi).
- **Via radio (Wi-Fi e reti mobili - Banda Traslata):** i bit digitali vengono "impressi" su un'onda ad alta frequenza (**onda portante**) modificandone ampiezza, frequenza o fase (**modulazione**).
:::

---

## 3. Apparati di Livello 1: Ripetitori e Hub

Operando a livello fisico, i dispositivi di questo strato non hanno memoria per immagazzinare frame, non sanno cosa sia un indirizzo MAC o un indirizzo IP, e non possono prendere decisioni di instradamento logico. Il loro compito è puramente rigenerativo o moltiplicativo del segnale.

### 4.1 Il Ripetitore (Repeater)

<!-- thumbnail -->
<div class="thumbnail float-right clear-both mb-2">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/Schema_ripetitore.jpg" class="modal__opener" aprire="#img-schema_ripetitore">
  <p>Schema di comunicazione tra host per mezzo di un ripetitore</p>
</div>
<!-- modal -->
<div id="img-schema_ripetitore" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-schema_ripetitore">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/Schema_ripetitore.jpg">
    </div>
    <p>Il ripetitore riceve il segnale attenuato e deformato dal primo segmento e lo rigenera amplificato e privo di rumore sul secondo</p>
  </div>
</div>

A causa della resistenza elettrica dei conduttori o delle dispersioni ottiche, qualsiasi segnale subisce un'inevitabile attenuazione e distorsione lungo il percorso. Nei cavi Ethernet su rame, la massima distanza affidabile è limitata a 100 metri.

Un **ripetitore** è un apparato a due porte:
- Riceve il segnale elettrico in ingresso, ormai debole e distorto dal rumore.
- Invece di limitarsi ad amplificarlo analogicamente (amplificando anche il rumore), **lo decodifica, lo rigenera in onde quadre perfette e lo ritrasmette a piena potenza** sulla seconda porta.
- Permette di collegare due segmenti di cavo, raddoppiando l'estensione geografica della rete locale.

---

### 4.2 L'Hub Ethernet (Ripetitore Multiporta)

<!-- thumbnail -->
<div class="thumbnail float-right clear-both mb-2">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/ethernet_hub.jpg" class="modal__opener" aprire="#img-ethernet_hub">
  <p>Hub Ethernet a 4 porte (apparato storico di Livello 1)</p>
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

Un **hub** (chiamato anche concentratore o ripetitore multiporta) è concettualmente un ripetitore dotato di molte porte (4, 8, 16 o 24):

- Quando un impulso elettrico entra da una qualsiasi porta, l'elettronica interna dell'hub si limita a replicarlo istantaneamente su **tutte le altre porte** (*flooding* elettrico cieco).
- Una rete con un hub centrale possiede una **topologia fisica a stella** (tutti i cavi convergono al centro), ma una **topologia logica a bus**: tutti gli host condividono lo stesso canale elettrico.

#### Perché gli hub sono scomparsi?
L'hub presenta tre difetti strutturali gravissimi:
1. **Unico dominio di collisione:** se due computer collegati all'hub trasmettono nello stesso istante, i loro segnali si scontrano all'interno dell'apparato, distruggendo i dati (**collisione**) e obbligando entrambi a ritrasmettere (tramite CSMA/CD).
2. **Banda condivisa dimezzata:** la velocità della rete (es. 100 Mbps) viene spartita tra tutti gli host collegati; inoltre l'hub costringe a lavorare in modalità **Half-Duplex** (non è possibile inviare e ricevere contemporaneamente).
3. **Mancanza di riservatezza:** ogni computer collegato all'hub riceve indistintamente i frame di tutti gli altri, rendendo banale l'intercettazione dei dati (*sniffing*).

Con il crollo dei costi dell'hardware nei primi anni 2000, gli hub sono stati **completamente soppiantati dagli switch di Livello 2**, che operano in modo intelligente inoltrando i frame solo sulla porta a cui è collegato il vero destinatario.

---

## 4. Il passaggio al livello superiore

Il Livello Fisico garantisce che una sequenza di bit possa viaggiare dal punto A al punto B attraverso un mezzo materiale. Tuttavia, lascia aperti problemi fondamentali:
- *Come fa il ricevitore a riconoscere dove inizia e dove finisce un messaggio all'interno del flusso continuo di bit?*
- *Come si verifica se qualche bit si è alterato per un'interferenza elettrica lungo il cavo?*
- *Come si identifica in modo univoco il destinatario all'interno della stessa rete locale?*

A rispondere a queste esigenze provvede il livello immediatamente superiore: il **[Livello 2 - Collegamento Dati](/manuale-libero-online-di-informatica/reti/iso-osi/livello2/)**.
