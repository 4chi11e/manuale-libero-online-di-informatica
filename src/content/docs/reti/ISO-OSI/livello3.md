---
title: Livello 3 - Rete
---

_Obiettivo: rendere i livelli superiori indipendenti dai meccanismi e dalle tecnologie di trasmissione fisiche, prendendosi carico dell'indirizzamento logico, dell'instradamento (routing) e della consegna dei pacchetti tra reti eterogenee._

---

## 1. Il Ruolo del Livello di Rete

Nel [Livello 2 (Collegamento)](/manuale-libero-online-di-informatica/reti/iso-osi/livello2/) abbiamo visto come i nodi comunicano all'interno di una singola rete locale (LAN) per mezzo di frame e indirizzi fisici MAC. Tuttavia, non appena due calcolatori appartengono a reti distinte e geograficamente separate, il solo Livello 2 non è più sufficiente.

### Perché il Livello 2 non basta su scala geografica?

1. **Assenza di gerarchia negli indirizzi MAC**: l'indirizzo MAC è un identificatore "piatto" (*flat*): indica il costruttore e un numero seriale, ma non contiene alcuna informazione sulla posizione geografica o logica del dispositivo nel mondo. Nessun apparato al mondo potrebbe memorizzare tabelle di commutazione con tutti i miliardi di indirizzi MAC esistenti sul pianeta.
2. **Limitazione del Broadcast**: le reti locali fanno largo uso di frame broadcast (es. richieste ARP). Se l'intera Internet fosse un'unica gigantesca rete di Livello 2, le continue comunicazioni broadcast saturerebbero istantaneamente ogni canale trasmissivo (*broadcast storm*).
3. **Eterogeneità delle reti fisiche**: Internet collega tra loro segmenti di rete diversissimi: reti cablate Ethernet, ponti radio Wi-Fi, dorsali in fibra ottica e connessioni mobili 4G/5G. Ciascuna di queste adotta frame con formati, lunghezze e velocità differenti.

Il compito del **Livello di Rete** è proprio realizzare l'**interconnessione di reti eterogenee** (*internetworking*). Per fare ciò, definisce un piano di **indirizzamento logico e gerarchico** indipendente dal supporto fisico e introduce il processo di **instradamento (routing)**, ovvero la capacità di guidare i dati da una sorgente a una destinazione attraverso router intermedi.

L'unità fondamentale di dati (PDU) di questo livello è il **pacchetto** (o *datagramma*).

### Il Protocollo IP e il modello *Best-Effort*

Il protocollo indiscusso su cui poggia l'intera rete Internet è l'**IP** (*Internet Protocol*). Le sue caratteristiche strutturali fondamentali sono due:

- **Senza connessione (*connectionless*)**: prima di inviare dati non viene stabilito alcun circuito né alcuna connessione preventiva tra sorgente e destinatario. Ogni pacchetto viaggia in modo indipendente dagli altri e contiene tutte le informazioni di indirizzamento necessarie per raggiungere la destinazione.
- **Non affidabile (*best-effort*)**: il protocollo IP compie il "massimo sforzo" per recapitare ciascun pacchetto a destinazione, ma **non garantisce** che il pacchetto non venga smarrito, ritardato, duplicato o consegnato fuori ordine a causa di congestioni sui router.

:::note[Separazione dei compiti: IP vs TCP]
L'assenza di garanzie a Livello 3 è una precisa scelta architetturale (*end-to-end principle*): delegando la correzione degli errori e il riordinamento ai livelli superiori (in particolare al protocollo **TCP** a Livello 4), i router intermedi rimangono estremamente veloci, leggeri ed efficienti.
:::

---

## 2. L'Indirizzo IPv4

<!-- thumbnail -->
<div class="thumbnail float-right clear-both mb-2">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/Ipv4_address-it.svg" class="modal__opener" aprire="#img-ipv4" alt="Struttura di un indirizzo IPv4">
  <p>Struttura gerarchica di un indirizzo IPv4: suddivisione tra prefisso di rete (Net ID) e identificatore del nodo (Host ID).</p>
</div>
<!-- modal -->
<div id="img-ipv4" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-ipv4">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/Ipv4_address-it.svg" alt="Struttura di un indirizzo IPv4">
    </div>
    <p>Struttura gerarchica di un indirizzo IPv4: suddivisione tra prefisso di rete (Net ID) e identificatore del nodo (Host ID).</p>
  </div>
</div>

Un indirizzo IPv4 è un codice numerico lungo **32 bit** (4 byte).

Per comodità di lettura, i 32 bit vengono suddivisi in 4 gruppi da 8 bit (ottetti), ciascuno convertito in numero decimale (da 0 a 255, essendo $2^8 = 256$), separati da un punto. Questa convenzione è detta **notazione decimale puntata** (*dotted-decimal notation*):

```text
Formato binario:  11000000 . 10101000 . 00000001 . 00001010
Decimale puntato:    192   .    168   .     1    .     10
```

Con 32 bit a disposizione, lo spazio complessivo di indirizzi teoricamente esprimibili è pari a:

$$2^{32} = 4.294.967.296 \quad (\approx 4{,}3 \text{ miliardi di indirizzi})$$

:::important[L'indirizzo IP appartiene all'interfaccia, non all'host!]
È uso comune dire che "il computer ha un certo IP". In termini rigorosi, l'indirizzo IP è associato all'**interfaccia di rete** (la scheda Ethernet o Wi-Fi) e non all'apparato in sé. Un computer portatile connesso contemporaneamente via cavo e via Wi-Fi possiede **due indirizzi IP distinti**; un router dotato di 4 porte di rete possiede almeno **quattro indirizzi IP**.
:::

### Struttura Bipartita: Net ID e Host ID

A differenza dell'indirizzo MAC, l'indirizzo IP è **gerarchico** ed è idealmente diviso in due porzioni:

1. **Net ID (Network Identifier o Prefisso di Rete)**: identifica la specifica rete logica a cui il nodo appartiene. Tutti i dispositivi connessi alla medesima rete fisica/logica devono condividere lo stesso Net ID per poter comunicare direttamente.
2. **Host ID (Host Identifier)**: identifica in modo univoco una specifica interfaccia all'interno di quella determinata rete.

Questa struttura richiama l'indirizzo telefonico tradizionale (prefisso distrettuale + numero dell'abbonato) o l'indirizzo postale (CAP/città + via e numero civico). I router su Internet non hanno bisogno di sapere dove si trovi ciascun singolo computer del pianeta: leggono solo il **Net ID** per indirizzare il pacchetto verso la rete di appartenenza; una volta che il pacchetto ha raggiunto la rete di destinazione, sarà l'infrastruttura locale a recapitarlo al corrispettivo **Host ID**.

---

## 3. Maschera di Sottorete (Subnet Mask), CIDR e Subnetting

Come fa un computer o un router a sapere esattamente dove finisce il Net ID e dove comincia l'Host ID all'interno dei 32 bit? Questa informazione viene fornita dalla **Subnet Mask** (Maschera di Sottorete).

### Cos'è la Subnet Mask

La Subnet Mask è un numero a 32 bit composto da una sequenza contigua di **bit a 1** nella parte iniziale (che mascherano i bit del Net ID) seguiti da una sequenza di soli **bit a 0** nella parte finale (in corrispondenza dei bit dell'Host ID).

```text
Indirizzo IP:  192.168.1.10      -> 11000000.10101000.00000001.00001010
Subnet Mask:   255.255.255.0     -> 11111111.11111111.11111111.00000000
                                   |------ Rete (24 bit) -----|- Host -|
```

### L'Operazione di AND Logico Bit a Bit

Ogni volta che un host deve spedire un pacchetto, deve determinare se la destinazione si trova nella **stessa rete locale** (consegna diretta) oppure in una **rete remota** (consegna indiretta al Gateway).

Per compiere questa scelta, la scheda di rete esegue un'operazione di **AND logico bit a bit** (ricordando che $1 \land 1 = 1$, mentre $1 \land 0 = 0$ e $0 \land 0 = 0$):

1. Calcola l'indirizzo della propria rete: $\text{IP Sorgente} \text{ AND } \text{Subnet Mask}$.
2. Calcola l'indirizzo della rete di destinazione: $\text{IP Destinazione} \text{ AND } \text{Subnet Mask}$.
3. Se i due risultati sono identici, il nodo di destinazione è locale; se differiscono, il nodo è remoto e il pacchetto deve essere inoltrato al router.

#### Esempio pratico di calcolo

Supponiamo che il nostro host abbia IP `192.168.32.97` con maschera `255.255.255.224` e debba inviare un pacchetto all'IP `192.168.32.130`.

```text
Calcolo rete mittente:
  192.168. 32. 97 = 11000000.10101000.00100000.01100001  AND
  255.255.255.224 = 11111111.11111111.11111111.11100000  =
  -------------------------------------------------------------
  192.168. 32. 96 = 11000000.10101000.00100000.01100000  (Rete Locale)

Calcolo rete destinatario:
  192.168. 32.130 = 11000000.10101000.00100000.10000010  AND
  255.255.255.224 = 11111111.11111111.11111111.11100000  =
  -------------------------------------------------------------
  192.168. 32.128 = 11000000.10101000.00100000.10000000  (Rete Remota)
```

I due risultati (`192.168.32.96` e `192.168.32.128`) differiscono: il mittente capisce immediatamente che il destinatario appartiene a un'altra sottorete e invia il pacchetto al proprio **Default Gateway**.

:::note[Host vs Router: una diversa logica decisionale]
Inviare il pacchetto al Default Gateway è la strategia tipica di un **host terminale** (un PC, uno smartphone o una stampante). Un host, infatti, non conosce la complessa topologia dell'intera rete: applica una regola binaria molto semplice:
- Se la destinazione è nella *stessa* sottorete $\to$ la contatta direttamente (consegna diretta a Livello 2 tramite switch e ARP).
- Se la destinazione è in una sottorete *diversa* $\to$ delega il compito all'unico punto di uscita della propria LAN che conosce, appunto il **Default Gateway** (il router locale).

Per un **router**, invece, la faccenda è del tutto diversa: collegando contemporaneamente molteplici reti, il router non invia tutto ciecamente a un gateway; analizza invece la propria **Routing Table** per decidere su quale specifica interfaccia o verso quale router successivo (*Next Hop*) inoltrare il pacchetto (come vedremo nel dettaglio nella [Sezione 7](#7-il-router-e-linstradamento-routing)).
:::

### I Due Indirizzi Riservati: Rete e Broadcast

In **qualsiasi** sottorete IP esistono due indirizzi speciali che non possono mai essere assegnati a singoli computer, stampanti o interfacce:

1. **Indirizzo di Rete (Network Address)**: è il primo indirizzo della sottorete, ottenuto impostando **tutti i bit della porzione Host ID a 0**. Rappresenta la rete nel suo insieme e viene utilizzato nelle tabelle dei router (nell'esempio sopra: `192.168.32.96`).
2. **Indirizzo di Broadcast**: è l'ultimo indirizzo della sottorete, ottenuto impostando **tutti i bit della porzione Host ID a 1**. Inviare un pacchetto a questo indirizzo significa recapitargli simultaneamente a **tutti gli host** di quella specifica sottorete.
   Nel caso della rete precedente `192.168.32.96/27`:
   $$\text{Bit host a 1} \to 11000000.10101000.00100000.011\mathbf{11111}_2 = \mathbf{192.168.32.127}$$

#### Formula per il calcolo degli host utilizzabili

Se una sottorete riserva $h$ bit per la parte host, il numero totale di configurazioni binarie è $2^h$. Escludendo l'indirizzo di rete e l'indirizzo di broadcast, la formula universale per gli host effettivamente utilizzabili è:

$$\text{Host utilizzabili} = 2^h - 2$$

Per una maschera con 5 bit di host (come `/27`), gli host configurabili sono $2^5 - 2 = 32 - 2 = 30$.

---

### Dalle Classi Storiche al CIDR

All'inizio dello sviluppo di Internet (RFC 791, 1981), l'assegnazione degli indirizzi avveniva tramite un sistema rigido suddiviso in **classi** (*classful addressing*), in cui il confine tra rete e host poteva cadere unicamente al termine del 1°, 2° o 3° byte:

| Classe | Bit Iniziali | Range 1° Byte | Maschera (CIDR) | Host per Rete | Ambito d'uso tipico |
| :---: | :---: | :---: | :---: | :---: | :--- |
| **A** | `0...` | 1 – 126 | `255.0.0.0` (`/8`) | 16.777.214 | Grandissime organizzazioni / governi |
| **B** | `10...` | 128 – 191 | `255.255.0.0` (`/16`) | 65.534 | Università e grandi aziende |
| **C** | `110...` | 192 – 223 | `255.255.255.0` (`/24`) | 254 | Piccole aziende e reti locali |
| **D** | `1110...` | 224 – 239 | *(nessuna)* | — | Gruppi **Multicast** |
| **E** | `1111...` | 240 – 255 | *(nessuna)* | — | Riservata per scopi sperimentali |

:::caution[Il fallimento dell'architettura a Classi]
Il modello a classi soffriva di una rigidità distruttiva: se un'azienda necessitava di connettere 350 computer, una Classe C (254 host) era insufficiente; le veniva quindi assegnata una Classe B (65.534 host), lasciando inutilizzati oltre 65.000 indirizzi! Nel giro di un decennio lo spazio IPv4 rischiò il collasso completo.
:::

#### Il CIDR (*Classless Inter-Domain Routing*)

Nel 1993 il sistema delle classi venne ufficialmente abolito con l'introduzione del **CIDR** (RFC 1519). 

Con il CIDR, la maschera di sottorete non è più vincolata a confini di 8 bit, ma può avere **qualsiasi lunghezza arbitraria** da 1 a 32 bit. La maschera viene espressa sinteticamente indicando uno slash seguito dal numero di bit a 1 (notazione con prefisso, es. `/24`, `/27`, `/30`).

---

### Il Subnetting Pratico

Il **Subnetting** è la tecnica con cui una singola rete IP viene suddivisa logicamente in due o più sottoreti indipendenti e più piccole.

<!-- thumbnail -->
<div class="thumbnail float-right clear-both mb-2">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/subnetting.png" class="modal__opener" aprire="#img-subnetting" alt="Diagramma di subnetting">
  <p>Esempio di suddivisione di una rete in sottoreti isolate mediante maschera di rete.</p>
</div>
<!-- modal -->
<div id="img-subnetting" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-subnetting">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/subnetting.png" alt="Diagramma di subnetting">
    </div>
    <p>Esempio di suddivisione di una rete in sottoreti isolate mediante maschera di rete.</p>
  </div>
</div>

#### Perché si fa Subnetting?
- **Isolamento del traffico**: riduce le dimensioni dei domini di broadcast.
- **Sicurezza**: consente di separare dipartimenti sensibili (es. Amministrazione vs Rete Ospiti) applicando regole di firewalling sui router.
- **Efficienza nell'allocazione**: adatta la dimensione della rete all'effettivo numero di dispositivi previsti.

#### Come si calcola una suddivisione (Prestito di Bit)

Cosa significa esattamente "prendere in prestito dei bit"?  
Per distinguere e "numerare" più sottoreti diverse, dobbiamo estendere la parte di rete rubando cifre binarie alla parte host. In informatica, per contare $N$ oggetti distinti servono $k$ bit, dove:
- Con **$k$ bit** a disposizione possiamo generare esattamente **$2^k$ combinazioni binarie uniche** (che fungono da "targhe" o identificatori delle singole sottoreti).
- I bit rimanenti per gli host diminuiscono: **$h' = h - k$**.
- Di conseguenza, il numero di host utilizzabili per ogni sottorete scende a **$2^{h'} - 2$**.

---

#### Esempio Guidato: Dividere una `/24` in 4 sottoreti

Partiamo dalla rete `192.168.1.0/24` (maschera `255.255.255.0`, 8 bit di host) e supponiamo di voler ottenere **4 sottoreti**:

##### 1. Calcolo dei bit di prestito e della nuova maschera
1. Per ottenere 4 sottoreti ci chiediamo: *quanti bit binari servono per contare fino a 4?*  
   Servono **$k = 2$ bit**, poiché $2^2 = 4$ (le 4 combinazioni binarie saranno `00`, `01`, `10`, `11`).
2. La maschera di sottorete si allunga di 2 bit, passando da `/24` a **/26** ($24 + 2 = 26$ bit a 1):
   - In binario: `11111111.11111111.11111111.11000000`
   - In decimale puntato: **`255.255.255.192`**
3. I bit rimasti per identificare gli host in ciascuna sottorete sono $8 - 2 = 6$.  
   Ciascuna sottorete conterrà $2^6 - 2 = 64 - 2 = \mathbf{62}$ host utilizzabili.

##### 2. Come i 2 bit contano le 4 sottoreti (La visione binaria)
Osserviamo da vicino l'ultimo byte degli indirizzi. I suoi 8 bit sono ora divisi in due zone:
$$\underbrace{\mathbf{b_7 \quad b_6}}_{\text{2 bit di Sottorete}} \quad \underbrace{\mathbf{b_5 \quad b_4 \quad b_3 \quad b_2 \quad b_1 \quad b_0}}_{\text{6 bit di Host}}$$

I pesi posizionali dei primi due bit nell'ottetto sono **128** (per $b_7$) e **64** (per $b_6$).  
I 2 bit presi in prestito assumono le 4 combinazioni possibili (`00`, `01`, `10`, `11`), determinando l'indirizzo di ciascuna sottorete quando i restanti 6 bit di host sono tutti a 0:

| Sottorete | 2 bit di Rete | 6 bit di Host | Ultimo Byte Binario | Calcolo Decimale | Indirizzo di Rete Risultante |
| :---: | :---: | :---: | :---: | :---: | :--- |
| **1ª Rete** | `0 0` | `000000` | `00000000` | $0 + 0 = \mathbf{0}$ | **`192.168.1.0/26`** |
| **2ª Rete** | `0 1` | `000000` | `01000000` | $0 + 64 = \mathbf{64}$ | **`192.168.1.64/26`** |
| **3ª Rete** | `1 0` | `000000` | `10000000` | $128 + 0 = \mathbf{128}$ | **`192.168.1.128/26`** |
| **4ª Rete** | `1 1` | `000000` | `11000000` | $128 + 64 = \mathbf{192}$ | **`192.168.1.192/26`** |

##### 3. Come variano i bit all'interno di ciascuna sottorete
All'interno di ogni singola sottorete, i primi 2 bit rimangono **fissi**, mentre i 6 bit di host variano da tutti 0 fino a tutti 1 (da 0 a $2^6-1 = 63$ in decimale):
- **Tutti 0** (`000000`): è l'indirizzo della **sottorete**.
- **Da `000001` a `111110`** (da 1 a 62): sono i **62 host validi**.
- **Tutti 1** (`111111`, pari a $+63$): è l'indirizzo di **broadcast** della sottorete.

Ecco il quadro completo dei 4 intervalli:

| Sottorete | Indirizzo di Rete (Host tutti 0) | Primo Host Valido | Ultimo Host Valido | Broadcast (Host tutti 1) | Host Utili |
| :---: | :--- | :--- | :--- | :--- | :---: |
| **1ª** | `192.168.1.0` (`00 000000`) | `192.168.1.1` | `192.168.1.62` | `192.168.1.63` (`00 111111`) | 62 |
| **2ª** | `192.168.1.64` (`01 000000`) | `192.168.1.65` | `192.168.1.126` | `192.168.1.127` (`01 111111`) | 62 |
| **3ª** | `192.168.1.128` (`10 000000`) | `192.168.1.129` | `192.168.1.190` | `192.168.1.191` (`10 111111`) | 62 |
| **4ª** | `192.168.1.192` (`11 000000`) | `192.168.1.193` | `192.168.1.254` | `192.168.1.255` (`11 111111`) | 62 |

##### 4. La regola rapida del "passo" di incremento
Come si vede chiaramente dalla tabella, gli indirizzi di rete saltano sempre di **64** ($0, 64, 128, 192$). Questo valore **64** è la dimensione del blocco ($2^6 = 64$) ed è chiamato il **passo** di incremento:
- **Metodo binario (immediato)**: corrisponde al **peso dell'ultimo bit a 1 della subnet mask**. Nella maschera `11000000`, l'ultimo bit a 1 ha peso posizionale **64**.
- **Metodo decimale**: si sottrae il valore dell'ottetto della maschera a 256 ($256 - 192 = 64$).

---

### Tabella di Riferimento Rapido per Maschere Comuni

La tabella seguente riassume i prefissi di subnetting più utilizzati nelle reti locali aziendali e domestiche (formattata per una lettura compatta anche su foglio stampato A4):

| Notazione CIDR | Subnet Mask Decimale | Bit Host ($h$) | Indirizzi Totali ($2^h$) | Host Assegnabili ($2^h - 2$) | Ambito d'uso tipico |
| :---: | :--- | :---: | :---: | :---: | :--- |
| **/24** | `255.255.255.0` | 8 | 256 | 254 | Standard LAN domestica o piccolo ufficio |
| **/25** | `255.255.255.128` | 7 | 128 | 126 | Divisione LAN in 2 segmenti |
| **/26** | `255.255.255.192` | 6 | 64 | 62 | Divisione LAN in 4 dipartimenti |
| **/27** | `255.255.255.224` | 5 | 32 | 30 | Aule o reparti da circa 25 postazioni |
| **/28** | `255.255.255.240` | 4 | 16 | 14 | Piccoli gruppi di server / laboratori |
| **/29** | `255.255.255.248` | 3 | 8 | 6 | Reti di gestione o apparati di rete |
| **/30** | `255.255.255.252` | 2 | 4 | 2 | Collegamenti punto-punto tra router |
| **/32** | `255.255.255.255` | 0 | 1 | 1 (Host route) | Rotta specifica verso un singolo host |

:::tip[Vuoi esercitarti sul calcolo delle sottoreti?]
Per consolidare questi concetti con problemi guidati e spiegazioni passo-passo, consulta la pagina interna: [Esercizi di Subnetting con soluzioni](/manuale-libero-online-di-informatica/reti/iso-osi/esercizi-subnetting/).
:::

---

## 4. Indirizzi Privati e NAT (*Network Address Translation*)

Con la vertiginosa espansione di computer, smartphone e dispositivi IoT, i circa 4 miliardi di indirizzi IPv4 si sono rivelati del tutto insufficienti per assegnare a ogni apparato del mondo un IP univoco.

Per evitare il blocco prematuro di Internet negli anni '90 in attesa del futuro IPv6, è stata introdotta una distinzione fondamentale tra **indirizzi pubblici** e **indirizzi privati** (RFC 1918). *(La cronistoria dell'esaurimento ufficiale di IPv4 e i meccanismi attuali come il mercato degli IP e il Carrier-Grade NAT sono approfonditi nella [Sezione 8](#8-ipv6-il-presente-e-il-futuro))*.

### Indirizzi Pubblici vs Indirizzi Privati (RFC 1918)

- **Indirizzi Pubblici**: sono rilasciati dall'ICANN/IANA e dai registri regionali (RIR come RIPE NCC in Europa). Devono essere **rigorosamente unici in tutto il mondo** e sono gli unici indirizzi che i router della dorsale Internet accettano di instradare.
- **Indirizzi Privati**: sono intervalli di indirizzi riservati dallo standard **RFC 1918** per l'uso esclusivo all'interno di reti locali aziendali, scolastiche o domestiche. I router di Internet sono configurati per **scartare immediatamente** qualsiasi pacchetto contenente un IP privato come sorgente o destinazione.

Poiché gli indirizzi privati non transitano mai sulla rete Internet pubblica, **possono essere riutilizzati all'infinito** da milioni di reti private diverse in tutto il mondo senza alcuna possibilità di conflitto (l'IP `192.168.1.10`, ad esempio, può essere usato contemporaneamente a casa tua e in quella di milioni di altre persone nel mondo).  
Chiaramente, **all'interno della stessa rete privata ogni indirizzo deve essere rigorosamente unico**: se due dispositivi nella medesima LAN venissero configurati con lo stesso indirizzo IP, si genererebbe un *conflitto di indirizzi IP*, rendendo instabile o impossibile la comunicazione per entrambi.

| Blocco RFC 1918 | Prefisso CIDR | Intervallo di Indirizzi IP | Numero di IP | Destinazione d'uso tipica |
| :--- | :---: | :--- | :---: | :--- |
| **Classe A Privata** | `10.0.0.0/8` | `10.0.0.0` – `10.255.255.255` | 16.777.216 | Grandi reti aziendali, università, data center |
| **Classe B Privata** | `172.16.0.0/12` | `172.16.0.0` – `172.31.255.255` | 1.048.576 | Medie aziende e campus scolastici |
| **Classe C Privata** | `192.168.0.0/16` | `192.168.0.0` – `192.168.255.255` | 65.536 | Reti casalinghe e piccoli uffici (SOHO) |

#### Applicazione pratica: Suddividere i blocchi privati
Sebbene lo standard RFC 1918 definisca questi blocchi come spazi continui enormi (ad esempio oltre 16 milioni di indirizzi nella classe `10.0.0.0/8` o 65.000 nella `192.168.0.0/16`), **nessuna organizzazione li utilizza mai come un'unica gigantesca rete piatta**.

**La scelta classica per eccellenza nelle LAN è la maschera `/24` (`255.255.255.0`)**:  
È la configurazione di gran lunga più diffusa e usata al mondo perché coincide comodamente con i confini dei byte. Partendo ad esempio dal blocco `192.168.0.0/16`, basta incrementare il terzo numero per creare decine di sottoreti indipendenti da 254 dispositivi ciascuna (`192.168.0.x` per i laboratori, `192.168.1.x` per la segreteria, `192.168.2.x` per il Wi-Fi).

Tuttavia, grazie alla flessibilità del CIDR, gli amministratori non sono vincolati a `/24` e possono ritagliare sottoreti più piccole o più grandi in base alle reali necessità:

| Scenario | Maschera CIDR | Blocco Padre | Esempio Sottoreti Ricavate | Host Utili / Rete | Perché si sceglie? |
| :--- | :---: | :--- | :--- | :---: | :--- |
| **La Scelta Classica** *(standard LAN)* | **/24** | `192.168.0.0/16` | `192.168.0.0/24`<br>`192.168.1.0/24`<br>`192.168.2.0/24` | **254** | **È lo standard de facto**: immediata da leggere (varia solo il 3° byte), perfetta per la stragrande maggioranza di scuole e uffici. |
| **Reti Piccole** *(ottimizzazione bit)* | **/26** | `192.168.1.0/24` | `192.168.1.0/26`<br>`192.168.1.64/26`<br>`192.168.1.128/26` | **62** | **Evita sprechi**: ideale quando i reparti o le aule contano solo poche decine di postazioni. |
| **Grandi Reti** *(campus/ospedali)* | **/20** | `172.16.0.0/12` | `172.16.0.0/20`<br>`172.16.16.0/20`<br>`172.16.32.0/20` | **4.094** | **Grandi dimensioni**: permette a campus universitari e ospedali di accogliere migliaia di host per plesso. |

In tutti i casi, i motivi per cui si segmenta la rete rimangono gli stessi:
- **Sicurezza**: il router o firewall intermedio impedisce accessi non autorizzati tra le diverse sottoreti (es. gli studenti connessi al Wi-Fi non possono accedere ai server della segreteria).
- **Isolamento del traffico**: i pacchetti di broadcast restano confinati nella propria sottorete, senza intasare la banda dell'intero edificio.
- **Semplicità di gestione**: leggendo l'indirizzo IP si riconosce al volo a quale reparto o plesso appartiene il dispositivo.

### Altri Indirizzi Speciali Notevoli

- **Loopback (`127.0.0.0/8`)**: tipicamente `127.0.0.1` (`localhost`). È l'indirizzo con cui un computer fa riferimento a se stesso; i pacchetti inviati a questo IP non escono mai sulla scheda fisica di rete, ma vengono rigirati internamente nello stack software (utilissimo per testare server web o database in locale).
- **Link-Local / APIPA (`169.254.0.0/16`)**: intervallo riservato per l'auto-assegnazione da parte del sistema operativo in caso di mancata risposta del server DHCP (il funzionamento dettagliato, il significato del "triangolino giallo" e la diagnosi sono spiegati nella [Sezione 6.2 - DHCP](#2-dhcp-dynamic-host-configuration-protocol)).
- **Rotta di Default (`0.0.0.0/0`)**: usata nelle tabelle di instradamento per indicare la destinazione per "tutto il resto del mondo".

---

### Come Funziona il NAT / PAT

<!-- thumbnail -->
<div class="thumbnail float-right clear-both mb-2">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/nat.png" class="modal__opener" aprire="#img-nat" alt="Funzionamento del Network Address Translation (NAT)">
  <p>Mascheramento degli indirizzi privati con l'unico indirizzo IP pubblico del router tramite NAT/PAT.</p>
</div>
<!-- modal -->
<div id="img-nat" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-nat">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/nat.png" alt="Funzionamento del Network Address Translation (NAT)">
    </div>
    <p>Mascheramento degli indirizzi privati con l'unico indirizzo IP pubblico del router tramite NAT/PAT.</p>
  </div>
</div>

Se i computer di una casa o di una scuola usano indirizzi privati non instradabili su Internet, come possono navigare sul web? La risposta è il **NAT** (*Network Address Translation*), quasi sempre implementato nella forma di **PAT** (*Port Address Translation* o *NAPT*).

Il router domestico/aziendale possiede due facce:
- Un'interfaccia **interna (LAN)** con indirizzo privato (es. `192.168.1.1`).
- Un'interfaccia **esterna (WAN)** a cui il provider (ISP) ha assegnato un **unico indirizzo IP pubblico** (es. `82.55.10.12`).

Quando un dispositivo interno richiede una pagina web:
1. **Invio della richiesta**: il computer `192.168.1.15` apre una connessione verso un server web pubblico (`142.250.180.206`, Google) sulla porta 443 (la porta standard del protocollo web sicuro **HTTPS**), partendo dalla propria porta sorgente (es. `49152`).
2. **Traduzione sul Router**: il pacchetto giunge al router. Il router sostituisce l'IP privato del mittente con il proprio **IP pubblico** (`82.55.10.12`) e alloca una porta sorgente univoca temporanea (es. `50001`).
3. **Registrazione nella NAT Table**: il router salva l'associazione nella propria tabella di stato:
   $$\text{IP Privato } 192.168.1.15 : 49152 \longleftrightarrow \text{IP Pubblico } 82.55.10.12 : 50001$$
4. **Risposta dal Server**: il server remoto risponde al mittente che vede, ossia l'IP pubblico `82.55.10.12` sulla porta `50001`.
5. **Inoltro al client interno**: il router riceve la risposta, consulta la NAT Table, riconosce la porta `50001`, risostituisce l'IP di destinazione con `192.168.1.15:49152` e recapita il pacchetto al computer nella LAN.

:::tip[Effetto collaterale positivo: Sicurezza perimetrale]
Grazie al NAT, tutti i dispositivi della rete privata sono invisibili a chi si trova su Internet. Un malintenzionato esterno non può iniziare una connessione non richiesta verso un IP privato all'interno della nostra LAN, perché il router non saprebbe a quale computer interno instradarla e scarterebbe il pacchetto.
:::

---

## 5. Anatomia del Datagramma IPv4

Un pacchetto (o datagramma) IPv4 è formato da una sezione di controllo, detta **Header** (intestazione), seguita dai dati applicativi veri e propri (**Payload**).

L'header IPv4 ha una dimensione minima di **20 byte** (quando non vi sono opzioni facoltative) fino a un massimo di **60 byte**.

```text
 0                   1                   2                   3
 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|Version|  IHL  |Type of Service|          Total Length         |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|         Identification        |Flags|     Fragment Offset     |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|  Time to Live |    Protocol   |        Header Checksum        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                       Source IP Address                       |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                    Destination IP Address                     |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                    Options (opzionale)                        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
```

### I Campi Principali dell'Header

- **Version (4 bit)**: per IPv4 vale sempre `4` (`0100` in binario).
- **IHL (Internet Header Length, 4 bit)**: esprime la lunghezza dell'header in multipli di 32 bit (4 byte). Il valore minimo è 5 ($5 \times 4 = 20$ byte).
- **Total Length (16 bit)**: dimensione totale in byte dell'intero pacchetto (Header + Payload). Il valore massimo teorico è $2^{16} - 1 = 65.535$ byte.
- **Time To Live - TTL (8 bit)**: contatore di "salti" (*hop count*).
  - Ogni volta che un pacchetto attraversa un router, il router ne **decrementa il valore di 1**.
  - Se il TTL arriva a 0 prima di giungere a destinazione, il pacchetto viene scartato e il router invia indietro al mittente un messaggio ICMP di errore (*Time Exceeded*).
  - *Scopo vitale*: impedisce che pacchetti instradati erroneamente girino all'infinito tra loop di router, saturando la rete. È inoltre il meccanismo su cui si basa il comando `traceroute`.
- **Protocol (8 bit)**: indica quale protocollo di Livello 4 (o superiore) è contenuto all'interno del payload. I codici standard più importanti gestiti da IANA sono:
  - **`1`**: **ICMP** (*Internet Control Message Protocol*)
  - **`6`**: **TCP** (*Transmission Control Protocol*)
  - **`17`**: **UDP** (*User Datagram Protocol*)
- **Header Checksum (16 bit)**: codice di ridondanza per verificare l'integrità della sola intestazione. A ogni passaggio da un router il checksum deve essere ricalcolato, perché il campo TTL è diminuito di 1.
- **Source Address (32 bit)**: indirizzo IP del mittente.
- **Destination Address (32 bit)**: indirizzo IP del destinatario.

### La Frammentazione: MTU e i campi dedicati

Ogni tecnologia di Livello 2 stabilisce una dimensione massima per il payload che i propri frame possono trasportare, chiamata **MTU** (*Maximum Transmission Unit*). Nelle reti Ethernet convenzionali, l'MTU è di **1500 byte**.

Se un router deve inoltrare un pacchetto di 1500 byte verso una linea con MTU inferiore (ad esempio 576 byte), il protocollo IP suddivide il datagramma in pezzi più piccoli: questo processo prende il nome di **frammentazione**.

I tre campi dedicati alla frammentazione sono:
1. **Identification (16 bit)**: un codice numerico univoco attribuito dal mittente. Tutti i frammenti derivanti dallo stesso pacchetto originale condividono lo stesso ID, permettendo al destinatario finale di ricomporli insieme.
2. **Flags (3 bit)**:
   - **DF (Don't Fragment)**: se impostato a 1, ordina ai router intermedi di **non frammentare mai** il pacchetto. Se il pacchetto eccede l'MTU della linea successiva, il router lo scarta e avvisa il mittente con ICMP (meccanismo base del *Path MTU Discovery*).
   - **MF (More Fragments)**: se impostato a 1, avvisa il ricevente che questo non è l'ultimo frammento; l'ultimo frammento ha $MF = 0$.
3. **Fragment Offset (13 bit)**: indica la posizione del frammento all'interno del pacchetto originale, espressa in blocchi di 8 byte.

---

## 6. Protocolli Ausiliari di Livello 3

Il funzionamento operativo del Livello 3 si basa su protocolli di supporto indispensabili per la risoluzione degli indirizzi, la diagnostica e la configurazione automatica.

### 1. ARP (*Address Resolution Protocol*)

Mentre il protocollo IP ragiona con indirizzi logici a 32 bit, a livello locale la scheda di rete (scheda Ethernet o Wi-Fi) trasmette dati unicamente verso un indirizzo fisico **MAC a 48 bit**.

Il protocollo **ARP** (RFC 826) è l'anello di congiunzione tra Livello 3 e Livello 2: data la conoscenza dell'indirizzo IP di un nodo locale, ARP serve a scoprire il suo corrispettivo indirizzo MAC.

```text
  [ Host A ]                             [ Switch L2 ]                            [ Host B ]
 192.168.1.10                                                                    192.168.1.50
      │                                        │                                       │
      │── 1. ARP Request (Broadcast L2) ──────>│                                       │
      │      "Chi ha 192.168.1.50? Dillo ad A" │── 1. Inoltro Broadcast a tutti ──────>│
      │                                        │                                       │
      │<── 2. ARP Reply (Unicast) ─────────────────────────────────────────────────────│
      │      "192.168.1.50 ha MAC 00:1A:2B:3C:4D:5E"                                   │
      ▼                                                                                ▼
```

1. **ARP Request**: Host A invia un frame broadcast (`FF:FF:FF:FF:FF:FF`) chiedendo a tutta la LAN: *"Chi ha l'IP 192.168.1.50? Comunichi il proprio MAC a 192.168.1.10"*.
2. **ARP Reply**: tutti i nodi scartano la richiesta tranne l'host proprietario di quell'IP, che risponde direttamente in unicast a Host A con il proprio indirizzo MAC.
3. **Tabella ARP (ARP Cache)**: per non ripetere questa procedura prima di ogni singolo pacchetto, i calcolatori memorizzano le coppie (IP, MAC) scoperte in una tabella temporanea nella RAM (*ARP Cache*), con un tempo di scadenza tipico di qualche minuto.

---

### 2. DHCP (*Dynamic Host Configuration Protocol*)

<!-- thumbnail -->
<div class="thumbnail float-right clear-both mb-2">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/DHCP_session.svg" class="modal__opener" aprire="#img-dhcp" alt="Sessione tipica DHCP">
  <p>Le 4 fasi del ciclo DORA tra client e server DHCP.</p>
</div>
<!-- modal -->
<div id="img-dhcp" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-dhcp">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/DHCP_session.svg" alt="Sessione tipica DHCP">
    </div>
    <p>Le 4 fasi del ciclo DORA tra client e server DHCP.</p>
  </div>
</div>

Impostare a mano l'indirizzo IP, la subnet mask, il gateway e il server DNS su centinaia di computer, telefoni o tablet di una rete sarebbe insostenibile e produrrebbe frequenti errori di duplicazione.

Il protocollo **DHCP** permette a qualunque dispositivo che si collega a una rete di ricevere automaticamente i **4 parametri di configurazione vitali**:

1. **Indirizzo IP** assegnato al client.
2. **Subnet Mask** della rete.
3. **Default Gateway** (l'IP del router per uscire verso Internet).
4. **Server DNS** (l'IP del server che converte i nomi di dominio come `google.com` in indirizzi IP).

#### Il Ciclo DORA

L'assegnazione automatica avviene tramite uno scambio in 4 fasi noto con l'acronimo **DORA**:

1. **Discover**: il nuovo dispositivo non ha ancora un IP; invia quindi un pacchetto broadcast (`DHCPDISCOVER`) su tutta la LAN cercando un server DHCP.
2. **Offer**: uno o più server DHCP rispondono proponendo una configurazione di rete disponibile (`DHCPOFFER`).
3. **Request**: il client seleziona una delle offerte ricevute e invia in broadcast una formale richiesta di accettazione (`DHCPREQUEST`).
4. **Acknowledge**: il server conferma l'assegnazione definitiva (`DHCPACK`).

L'indirizzo viene concesso con un tempo limitato, detto **Lease Time** (tempo di noleggio). A metà scadenza, il client richiede un rinnovo; se il dispositivo si scollega senza rinnovare, l'IP torna libero nella riserva (*pool*) del server per essere riassegnato ad altri.

#### Cosa succede se il DHCP non risponde? (APIPA e il "Triangolino Giallo")

Cosa accade se un computer collegato alla rete invia il pacchetto `DHCPDISCOVER` ma **nessun server DHCP risponde** (ad esempio perché il router è spento, il cavo è collegato a uno switch isolato o il server DHCP ha esaurito gli IP)?

Per non lasciare la scheda di rete completamente disattivata e muta, il sistema operativo (Windows, macOS o Linux) attiva un meccanismo di emergenza chiamato **APIPA** (*Automatic Private IP Addressing*, standardizzato in RFC 3927 come *IPv4 Link-Local*):
1. **Auto-assegnazione**: il computer sceglie autonomamente un indirizzo casuale all'interno del blocco riservato **`169.254.0.0/16`** (da `169.254.1.0` a `169.254.254.255`, con maschera `255.255.0.0`).
2. **Controllo anti-conflitto con ARP**: prima di impostarlo definitivamente, il computer invia una richiesta ARP in broadcast chiedendo a tutta la rete locale se quell'indirizzo sia già occupato (*"C'è qualcuno con questo IP?"*). Se nessuno risponde entro breve tempo, lo fa proprio; se invece un altro dispositivo risponde, ne estrae immediatamente un altro a caso per evitare conflitti di indirizzo.
3. **Cosa permette di fare**: tutti i dispositivi che hanno un IP `169.254.x.x` possono comunicare tra loro all'interno dello stesso segmento locale (ad esempio per scambiare file tra due PC collegati con cavo diretto o inviare una stampa a una stampante di rete).
4. **Perché non c'è Internet**: il computer **non ha ricevuto né il Default Gateway né il server DNS**, e i router per norma scartano sempre questi pacchetti. È esattamente la situazione in cui i sistemi operativi mostrano l'avviso **"Connessione limitata"** o **"Nessun accesso a Internet"** (il classico triangolino giallo di Windows).

> **Regola diagnostica per tecnici e sistemisti:**  
> Se eseguendo `ipconfig` da terminale si legge un indirizzo IPv4 che inizia per **`169.254...`**, la diagnosi è immediata e certa: *la scheda di rete fisica funziona regolarmente, ma il computer non riesce a dialogare con il server DHCP*.

---

### 3. ICMP (*Internet Control Message Protocol*)

**ICMP** (RFC 792) è il protocollo di servizio di Livello 3 utilizzato da router e computer per segnalare condizioni di errore, anomalie o informazioni diagnostiche sullo stato della rete.

I due strumenti di diagnostica più famosi e utilizzati al mondo su qualsiasi sistema operativo poggiano direttamente su ICMP:

- **ping**: invia un pacchetto ICMP di tipo **Echo Request** verso l'host di destinazione. Se il nodo è attivo e raggiungibile, risponde con un messaggio di **Echo Reply**. Misura il tempo di andata e ritorno (*Round Trip Time* - RTT) e l'eventuale percentuale di pacchetti persi.
- **traceroute (o `tracert` su Windows)**: identifica la catena di tutti i router intermedi attraversati per raggiungere una destinazione remota. Funziona inviando pacchetti con TTL progressivo:
  - Primo pacchetto con $TTL = 1$: scade sul primo router, che risponde con un messaggio ICMP *Time Exceeded* (rivelando il proprio indirizzo IP).
  - Secondo pacchetto con $TTL = 2$: supera il primo router e scade sul secondo router.
  - Il processo prosegue fino al raggiungimento del server di destinazione.

Questi meccanismi di segnalazione e diagnostica, uniti ai comandi per esaminare ARP e DHCP, costituiscono la "cassetta degli attrezzi" fondamentale utilizzabile da qualsiasi riga di comando:

---

### Laboratorio Pratico: Comandi di Rete da Terminale

La tabella seguente mette a confronto i comandi fondamentali di amministrazione di rete utilizzabili dal prompt dei comandi di Windows e dalla shell di Linux/macOS:

| Operazione | Microsoft Windows | Linux / macOS | Cosa mostra / Cosa fa |
| :--- | :--- | :--- | :--- |
| **Configurazione IP** | `ipconfig /all` | `ip a` *(o `ifconfig`)* | Mostra IP, Subnet Mask, Gateway, DNS e MAC address |
| **Rinnovo DHCP** | `ipconfig /release`<br>`ipconfig /renew` | `sudo dhclient -r`<br>`sudo dhclient` | Rilascia l'IP corrente e forza una nuova richiesta DHCP da zero |
| **Tabella ARP locale** | `arp -a` | `ip neigh` *(o `arp -n`)* | Visualizza le coppie (IP, MAC) memorizzate nella cache |
| **Test Connettività (ICMP)** | `ping www.google.it` | `ping www.google.it` | Invia ICMP Echo Request misurando latenza e pacchetti persi |
| **Tracciamento Rotta (ICMP)** | `tracert www.google.it` | `traceroute www.google.it` | Mostra tutti i router intermedi sfruttando il TTL e ICMP |
| **Svuotamento cache DNS** | `ipconfig /flushdns` | `resolvectl flush-caches` | Cancella i record di risoluzione nomi salvati in locale |

---

## 7. Il Router e l'Instradamento (Routing)

<!-- thumbnail -->
<div class="thumbnail float-right clear-both mb-2">
  <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/router.jfif" class="modal__opener" aprire="#img-router" alt="Router moderno">
  <p>Router Wi-Fi SOHO con porte di rete fisiche LAN/WAN e antenne per la connettività wireless.</p>
</div>
<!-- modal -->
<div id="img-router" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-router">&times;</span>
    <div class="modal__content__img-container">   
      <img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/router.jfif" alt="Router moderno">
    </div>
    <p>Router Wi-Fi SOHO con porte di rete fisiche LAN/WAN e antenne per la connettività wireless.</p>
  </div>
</div>

Il **Router** è il dispositivo cardine del Livello 3.

A differenza di uno switch (che opera a Livello 2 e si limita a inoltrare i frame all'interno dello stesso dominio di broadcast), il router ha il compito specifico di **interconnettere reti diverse** e **isolare i domini di broadcast**: i pacchetti broadcast di una LAN non attraversano mai un router.

### Come Inoltra i Pacchetti un Router?

Mentre un normale computer (host) si limita a inviare "alla cieca" tutto il traffico non locale al proprio Default Gateway, un router è un crocevia di reti diverse: riceve pacchetti da molteplici interfacce e deve decidere in modo mirato dove instradarli.

All'interno di ogni router risiede una **Routing Table** (Tabella di instradamento). Quando il router riceve un pacchetto su una delle sue interfacce:

1. Estrae l'**IP di destinazione** contenuto nell'header del pacchetto.
2. Consulta la tabella di instradamento per determinare quale interfaccia di uscita (o quale successivo router, detto *Next Hop*) utilizzare.
3. Se sono presenti più rotte corrispondenti, applica la regola del **Longest Prefix Match** (Corrispondenza del prefisso più lungo): viene sempre scelta la rotta con la subnet mask più specifica (più lunga).
4. Decrementa di 1 il campo **TTL** del pacchetto, ricalcola l'**Header Checksum** e reincapsula il pacchetto in un nuovo frame di Livello 2 con il nuovo MAC di destinazione del salto successivo.

```text
Esempio di Tabella di Routing semplificata:
Destinazione Rete       Subnet Mask       Next Hop (Gateway)    Interfaccia
192.168.1.0             255.255.255.0     Direttamente connessa  eth0 (LAN)
10.0.0.0                255.0.0.0         192.168.1.254          eth0
0.0.0.0                 0.0.0.0           82.55.10.1 (ISP)       eth1 (WAN)
```

### Il Default Gateway

La voce `0.0.0.0` con maschera `0.0.0.0` (indicata come `0.0.0.0/0`) rappresenta la **Default Route** (rotta predefinita).

Se l'IP di destinazione non corrisponde a nessuna delle sottoreti esplicitamente elencate nella tabella, il router inoltra il pacchetto al **Default Gateway** (in genere il router del provider Internet), che a sua volta ripeterà il processo verso le dorsali globali.

### Instradamento Diretto vs Indiretto

- **Instradamento Diretto**: la sorgente e la destinazione appartengono alla **stessa sottorete**. Il pacchetto viene incapsulato in un frame Ethernet con l'indirizzo MAC reale del destinatario (scoperto tramite ARP) e consegnato direttamente attraverso lo switch locale.
- **Instradamento Indiretto**: la destinazione appartiene a una **sottorete diversa**. Il pacchetto IP mantiene come destinazione logica finale l'IP del computer remoto, ma a livello fisico viene incapsulato in un frame Ethernet indirizzato al **MAC address del Gateway locale**. Il Gateway aprirà il frame, leggerà l'IP e si occuperà di instradarlo.

### Cenni sui Protocolli di Routing

Le tabelle di instradamento possono essere popolate in due modi:
- **Routing Statico**: le rotte vengono inserite manualmente dall'amministratore di rete. È una soluzione semplice, sicura e priva di sovraccarico di banda, ma non si adatta automaticamente a eventuali guasti o disconnessioni di linee.
- **Routing Dinamico**: i router comunicano tra loro scambiandosi informazioni sullo stato dei collegamenti mediante speciali **protocolli di routing**. Se una linea si interrompe, i router ricalcolano autonomamente percorsi alternativi:
  - *Protocolli interni a un'organizzazione (IGP)*: **RIP** (Distance-Vector basato sul conteggio dei salti), **OSPF** (Link-State basato sul costo e sulla velocità delle linee).
  - *Protocolli tra grandi provider globali (EGP)*: **BGP** (*Border Gateway Protocol*), il vero "collante" che decide come i pacchetti attraversano i diversi continenti e operatori planetari.

---

## 8. IPv6: Il Presente e il Futuro

### La Fine di IPv4: Cronistoria e la Situazione Attuale

Sebbene l'architettura IPv4 continui a funzionare egregiamente grazie a NAT e subnetting, la disponibilità di nuovi indirizzi IPv4 si è ufficialmente esaurita a livello globale:
- **3 febbraio 2011**: la **IANA** (*Internet Assigned Numbers Authority*) assegna ufficialmente gli ultimi cinque blocchi `/8` rimasti (circa 16,7 milioni di indirizzi ciascuno) ai cinque registri regionali continentali (RIR).
- **Esaurimento continentale**: nei mesi e anni successivi, anche i singoli registri hanno esaurito le scorte ordinarie (APNIC in Asia nel 2011, ARIN in Nord America nel 2015, e **RIPE NCC** in Europa il **25 novembre 2019**).

**Come si fa oggi senza nuovi indirizzi IPv4 disponibili?**
1. **Il mercato secondario degli indirizzi IP**: non essendo più possibile richiedere nuovi blocchi gratuiti, è nato un florido mercato commerciale. Grandi aziende che possiedono vecchi blocchi non utilizzati li cedono all'asta a provider e colossi del cloud (Amazon AWS, Microsoft Azure, Google Cloud) a prezzi che oscillano tra i **35 e i 50 dollari per singolo indirizzo IP** (motivo per cui oggi i provider cloud fanno pagare una tariffa oraria per ogni IP pubblico associato a una macchina virtuale).
2. **Carrier-Grade NAT (CGNAT)**: molti operatori di telecomunicazioni (sulle reti mobili 4G/5G e su molte linee FTTH) applicano un "doppio NAT". Al router dell'utente finale non viene più assegnato un vero IP pubblico, bensì un indirizzo privato speciale (blocco `100.64.0.0/10`, RFC 6598); il provider fa poi confluire il traffico di centinaia di clienti diversi attraverso un unico IP pubblico in centrale. *(Questo è il motivo per cui spesso non è possibile aprire porte per il gaming o per telecamere di videosorveglianza casalinghe senza richiedere espressamente al provider un IP pubblico dedicato)*.
3. **La transizione definitiva a IPv6**: l'unica risposta strutturale e a lungo termine che ripristina la disponibilità illimitata di indirizzi.

### Caratteristiche Fondamentali di IPv6

1. **Spazio a 128 bit**: gli indirizzi passano da 32 bit a **128 bit** (16 byte). Lo spazio totale ammonta a:
   $$2^{128} \approx 3{,}4 \times 10^{38} \text{ indirizzi}$$
   Un numero così inconcepibilmente sterminato da consentire di assegnare miliardi di indirizzi IP pubblici a ogni singolo millimetro quadrato della superficie terrestre, eliminando alla radice la necessità del NAT.
2. **Formato e Notazione Esadecimale**:
   Gli indirizzi IPv6 vengono scritti come **8 gruppi di 4 cifre esadecimali** (ciascun gruppo rappresenta 16 bit), separati da due punti (`:`):
   `2001:0db8:85a3:0000:0000:8a2e:0370:7344`
3. **Regole di Abbreviazione**:
   - Gli **zeri iniziali** di ciascun gruppo possono essere omessi: `0db8` $\to$ `db8`; `0000` $\to$ `0`.
   - Una sequenza contigua di gruppi composti da soli zeri può essere contratta con il simbolo **`::`** (**applicabile una sola volta all'interno dell'indirizzo** per evitare ambiguità):
     $$\text{Da: } \text{2001:0db8:0000:0000:0000:0000:1428:57ab}$$
     $$\text{A: } \mathbf{2001:db8::1428:57ab}$$

### Differenze Chiave Rispetto a IPv4

- **Abolizione del Broadcast**: in IPv6 non esiste più l'indirizzo di broadcast. Tutto il traffico uno-a-molti avviene tramite **Multicast**, riducendo drasticamente il disturbo verso nodi non interessati.
- **Header Semplificato a Dimensione Fissa (40 byte)**: nonostante gli indirizzi siano 4 volte più lunghi, l'header base di IPv6 contiene solo 8 campi (contro i 13 di IPv4). Non c'è più il checksum nell'header (la verifica è delegata a Livello 2 e 4), velocizzando notevolmente l'elaborazione dei pacchetti da parte dei chip hardware dei router.
- **Autoconfigurazione Stateless (SLAAC)**: un computer connesso a una rete IPv6 può generare da solo il proprio indirizzo valido e univoco senza dover necessariamente attendere un server DHCP, dialogando direttamente con il router locale via messaggi *Neighbor Discovery* (ICMPv6).
- **Indirizzi Speciali di base**:
  - `::1` : indirizzo di **Loopback** (corrispondente al `127.0.0.1` di IPv4).
  - `::` : indirizzo **non specificato** (corrispondente a `0.0.0.0`).
  - `fe80::/10` : indirizzi **Link-Local**, obbligatori e utilizzati per comunicare solo all'interno del proprio segmento locale.
  - `::ffff:0:0/96` : indirizzi **IPv4-mapped** (es. `::ffff:192.168.1.1`). L'intero spazio di indirizzamento IPv4 è formalmente integrato all'interno di IPv6: i primi 80 bit sono a zero, 16 bit a uno (`ffff`) e gli ultimi 32 bit contengono l'IPv4. Vengono usati dai sistemi operativi per permettere a programmi scritti per IPv6 di dialogare trasparentemente con host IPv4.

### Come Funziona una Rete Mista? (Transizione e Coesistenza IPv4 / IPv6)

Dato che IPv4 e IPv6 **non sono reciprocamente retrocompatibili** (un router o un computer configurato solo per IPv4 scarta e non riconosce un pacchetto IPv6), la transizione globale da un protocollo all'altro non è potuta avvenire da un giorno all'altro con un semplice "interruttore".

Per far funzionare e comunicare reti e apparati eterogenei durante questo lungo periodo di transizione, l'IETF ha sviluppato **tre strategie fondamentali**:

```
                       COME CONVIVONO IPv4 E IPv6?
                                   │
      ┌────────────────────────────┼────────────────────────────┐
      ▼                            ▼                            ▼
1. DUAL STACK                2. TUNNELING                 3. TRADUZIONE
(Entrambi i protocolli)     (Incapsulamento)             (NAT64 + DNS64)
I nodi parlano sia IPv4      Pacchetti IPv6 viaggiano    Host solo-IPv6 dialogano
che IPv6 simultaneamente     "imbustati" dentro IPv4      con server solo-IPv4
```

---

#### 1. Dual Stack (La Soluzione Principale)
È il pilastro della convivenza su scala globale: tutti i moderni sistemi operativi (Windows, Linux, macOS, iOS, Android), i server web e i router gestiscono **entrambi gli stack di protocollo in parallelo** sulla stessa interfaccia di rete.
- Il computer riceve contemporaneamente sia un indirizzo IPv4 che un indirizzo IPv6.
- Quando un'applicazione (es. il browser) cerca un sito (come `google.com`), interroga il DNS:
  - Riceve il **record `A`** (*Address*): indirizzo IPv4 a 32 bit (es. `142.250.180.206`).
  - Riceve il **record `AAAA`** (*"Quad-A"*, poiché $4 \times 32\text{ bit} = 128\text{ bit}$): indirizzo IPv6 (es. `2a00:1450:4002:408::200e`).
- Se la rete locale e l'operatore supportano IPv6, il browser si connette tramite IPv6. Se rileva problemi o se la destinazione possiede solo IPv4, ripiega all'istante (*fallback*) su IPv4 in modo del tutto impercettibile per l'utente.

---

#### 2. Tunneling (Incrocio di Reti Differenti)
Cosa accade se due isole di rete IPv6 devono comunicare tra loro, ma la dorsale Internet che le separa (o il provider intermedio) parla ancora soltanto IPv4?
- **Concetto di incapsulamento**: il router di confine prende l'intero pacchetto IPv6 e lo inserisce come payload all'interno di un normale pacchetto IPv4 (tecniche come *6in4*, *6to4* o *GRE*).
- Il pacchetto IPv4 viaggia sulla rete intermedia come se fosse un normale dato; giunto al router di destinazione, quest'ultimo "scarta" l'intestazione IPv4 esterna ed estrae il pacchetto IPv6 originale, reinoltrandolo intatto nella rete locale IPv6.
- Funziona esattamente come spedire una lettera chiusa all'interno di un'altra busta più grande per superare un corriere che accetta solo formati standard.

---

#### 3. Traduzione: NAT64 e DNS64 (IPv6-Only verso il Vecchio Mondo IPv4)
Nelle reti cellulari 4G/5G moderne e nei grandi data center, gli operatori scelgono sempre più spesso di configurare le reti interne in modalità **esclusivamente IPv6** (*IPv6-only*), eliminando del tutto la complessità e il costo degli indirizzi IPv4 privati o CGNAT.

Ma cosa succede se uno smartphone collegato a una rete solo-IPv6 vuole visitare un vecchio server web che possiede **soltanto un indirizzo IPv4**? In questo caso il Dual Stack non può funzionare (il client non ha IPv4 e il server non ha IPv6). La comunicazione è resa possibile da una coppia di tecnologie:

1. **DNS64**: il client interroga il DNS chiedendo il record IPv6 (`AAAA`) del sito. Poiché il server web possiede solo un record IPv4 `A` (es. `198.51.100.25`), uno speciale server DNS64 crea al volo un indirizzo IPv6 fittizio (sintetico), prefissando l'IP a 32 bit con un prefisso convenzionale a 96 bit (es. `64:ff9b::198.51.100.25`).
2. **NAT64**: il client invia il pacchetto IPv6 a questo indirizzo sintetico. Un gateway NAT64 posto al confine della rete dell'operatore intercetta il traffico, traduce l'header IPv6 in un header IPv4 reale, inoltra la richiesta al vecchio server web su Internet e, ricevuta la risposta, la riconverte in IPv6 verso lo smartphone.

In questo modo, la transizione verso un'Internet interamente IPv6 può proseguire senza mai rompere l'accesso ai contenuti storici ancora ancorati a IPv4.

:::note[Approfondimento: Perché NAT64 usa 64:ff9b:: e non ::ffff:0:0/96?]
Un dubbio frequente tra studenti e sviluppatori è: *se l'intero spazio IPv4 è già mappato dentro IPv6 come `::ffff:0:0/96` (es. `::ffff:192.168.1.1`), perché per il NAT64 l'IETF ha introdotto un prefisso separato come `64:ff9b::/96`?*

La differenza sta tra cosa vive nella memoria del software e cosa viaggia sui cavi della rete:
- **`::ffff:0:0/96` vive solo nella memoria del computer (software)**: serve alle librerie del sistema operativo per permettere a un programma IPv6 di dialogare internamente con connessioni IPv4. Per norma (RFC 4291), non deve mai viaggiare su un cavo: i router lo scartano all'istante perché non corrisponde ad alcuna rotta fisica.
- **`64:ff9b::/96` viaggia sui cavi ed è instradabile**: un indirizzo si dice **instradabile** quando ha un prefisso di rete che i router sanno riconoscere nella propria Tabella di Routing per inoltrarlo da un nodo all'altro. Con il prefisso standard `64:ff9b::/96` (RFC 6052), tutti i router dell'operatore sanno esattamente cosa fare: *"Questo pacchetto ha il prefisso NAT64, quindi inoltralo all'apparato di traduzione IPv4"*.
:::

---

## Conclusioni e Collegamento con il Livello Superiore

In questo capitolo abbiamo analizzato come il Livello 3 si occupi di far viaggiare i singoli pacchetti tra reti geografiche eterogenee, sfruttando l'indirizzamento logico IP, le maschere di sottorete e i router.

Tuttavia, il protocollo IP offre solo un servizio **best-effort**: non garantisce che i pacchetti non si perdano, non controlla che arrivino nell'ordine corretto e non distingue a quale specifica applicazione software (browser, client email o gioco online) i dati siano destinati.

Questo compito è affidato al livello successivo: il **[Livello 4 - Trasporto](/manuale-libero-online-di-informatica/reti/iso-osi/livello4/)**, dove protocolli come **TCP** e **UDP** introdurranno i concetti di numeri di porta, controllo di flusso, riscontri e affidabilità end-to-end.
