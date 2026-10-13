---
title: Codifiche Multimediali
description: Come si codificano immagini, audio e video in binario, e come calcolare le dimensioni di file multimediali non compressi.
---

Abbiamo visto che qualsiasi dato può essere trasformato in una sequenza di bit. Ma mentre testi e numeri sono informazioni naturalmente discrete (composte da singoli simboli separati), il mondo fisico in cui viviamo è fatto di fenomeni **continui**: suoni, luci, colori, temperature, movimenti.

Per permettere a un calcolatore di elaborare questi dati del mondo reale, dobbiamo comprendere la distinzione fondamentale tra **grandezze analogiche** e **digitali** e imparare come avviene il processo di **digitalizzazione**.

---

## 1. Dal mondo reale al computer: Analogico, Digitale e Digitalizzazione

### Grandezze Analogiche vs Grandezze Digitali

| Caratteristica | Grandezza Analogica (*Analog*) | Grandezza Digitale (*Digital*) |
| :--- | :--- | :--- |
| **Natura dei valori** | **Continua** (*Continuous*): può assumere **infiniti valori intermedi** all'interno di un intervallo. | **Discreta** (*Discrete*): può assumere solo un **insieme finito di valori numerici** ben definiti (cifre/bit). |
| **Natura temporale** | Varia in modo continuo e fluido nel tempo. | Misurata a istanti di tempo separati e specifici. |
| **Esempi fisici** | La temperatura dell'aria, l'onda di pressione dell'aria creata da una voce, la lancetta dei secondi di un orologio analogico, un disco in vinile. | Un termometro digitale (es. $21{,}4^\circ\text{C}$), un orologio digitale (`14:35`), un file audio MP3, un testo al computer. |

### Perché il digitale ha solo un numero finito di valori?

La differenza fondamentale sta nel modo in cui l'informazione viene memorizzata:

1. **Nel mondo reale (analogico):** tra due valori qualsiasi (ad esempio tra $20^\circ\text{C}$ e $21^\circ\text{C}$) esistono **infiniti valori intermedi** ($20{,}1^\circ$, $20{,}15^\circ$, $20{,}1578923\dots^\circ$). La natura non "arrotonda".
2. **Nel computer (digitale):** la memoria è composta da un numero finito di **bit**. Se per memorizzare un dato assegniamo $N$ bit (ad esempio $8$ o $16$ bit), possiamo generare soltanto **$2^N$ combinazioni binarie distinte**. Non possiamo memorizzare infinite cifre decimali perché richiederebbero una quantità infinita di bit e di memoria!

:::tip[L'analogia visiva: La Rampa vs La Scala a Gradini]
Per visualizzare la differenza pensa a una salita:

- **Analogico = Una rampa liscia:** puoi fermarti a **qualsiasi altezza**, in modo continuo e senza interruzioni. Ci sono infiniti punti possibili su cui poggiare il piede.
- **Digitale = Una scala con gradini:** puoi trovarti solo sul **gradino 1, gradino 2, gradino 3...** Non puoi appoggiare il piede "a mezz'aria" tra due gradini. Se ti trovi a un'altezza intermedia, devi per forza posizionarti sul gradino più vicino (*arrotondamento/quantizzazione*).

```text
       MONDO ANALOGICO (Rampa)                   MONDO DIGITALE (Scala)
       
                /                                          ┌─── Livello 3 (11)
               /                                       ┌───┘
              /                                    ┌───┘        Livello 2 (10)
             /                                 ┌───┘
            /                              ┌───┘                Livello 1 (01)
           /                           ┌───┘
          /                        ┌───┘                        Livello 0 (00)
         /                     ────┘
    Infiniti punti possibili                  Solo 4 livelli ben distinti (2 bit)
```

Se aumentiamo il numero di bit (es. passando da 8 bit a 16 o 24 bit), i gradini diventano **tantissimi e microscopici** (con 24 bit abbiamo oltre 16 milioni di gradini!), così vicini da sembrare a occhio nudo una rampa continua. Ma dal punto di vista matematico e fisico rimarranno sempre gradini **singoli, separati e in numero finito**.
:::

:::note[Da dove viene la parola "Digitale"?]
La parola italiana **digitale** deriva dall'inglese *digit* (che significa "cifra", a sua volta dal latino *digitus*, "dito", con cui si contava). Un sistema digitale è semplicemente un sistema che elabora e memorizza l'informazione sotto forma di **cifre numeriche** (e nei computer, cifre binarie: $0$ e $1$).
:::

---

### Il processo di digitalizzazione: 3 passi fondamentali

La **digitalizzazione** (*digitization* o *analog-to-digital conversion*) è il procedimento con cui una grandezza fisica continua viene trasformata in una sequenza di numeri binari. Si articola in tre fasi sequenziali:

```text
 Segnale Fisico Continuo
 (es. suono nel microfono)
           │
           ▼
 ┌───────────────────────────────────┐
 │ 1. CAMPIONAMENTO (Sampling)       │  ←── Si misura il segnale a intervalli regolari
 └─────────────────┬─────────────────┘
                   │
                   ▼
 ┌───────────────────────────────────┐
 │ 2. QUANTIZZAZIONE (Quantization)  │  ←── Si arrotonda ogni misura al livello più vicino
 └─────────────────┬─────────────────┘
                   │
                   ▼
 ┌───────────────────────────────────┐
 │ 3. CODIFICA (Encoding)            │  ←── Si trasforma ogni livello in numeri binari (bit)
 └─────────────────┬─────────────────┘
                   │
                   ▼
  01101001 11000101 00101110 ...
```

#### 1. Campionamento (*Sampling*)
Consiste nel misurare il valore del segnale analogico a **intervalli regolari di tempo**.
- Il segnale passa dall'essere continuo nel tempo a essere una serie di **campioni discreti** (*samples*).
- **Frequenza di campionamento (*Sample Rate* o *Sampling Frequency*, $f_s$):** indica quanti campioni vengono prelevati ogni secondo e si misura in **Hertz (Hz)** ($1\text{ Hz} = 1\text{ campione al secondo}$).

#### 2. Quantizzazione (*Quantization*)
Il valore di ampiezza misurato in ciascun campione (che in natura è un numero reale con infinite cifre decimali) deve essere **approssimato** a uno dei livelli discreti prestabiliti consentiti dal sistema.
- **Profondità di bit (*Bit Depth* o *Sample Resolution*):** il numero di bit dedicati a memorizzare ciascun campione. Se usiamo $N$ bit, abbiamo a disposizione $2^N$ livelli di ampiezza diversi.
- **Errore di quantizzazione (*Quantization Error / Noise*):** la piccola differenza tra il valore reale dell'onda e il livello discreto a cui è stato approssimato. Più bit usiamo per campione, più livelli abbiamo a disposizione e minore sarà questa distorsione.

#### 3. Codifica (*Encoding*)
A ogni livello quantizzato viene assegnato il corrispondente codice numerico espresso in **notazione binaria** (sequenza di $0$ e $1$), pronto per essere salvato in memoria o trasmesso su una rete.

---

### Dispositivi di conversione: ADC e DAC

Per far dialogare la CPU con il mondo fisico circostante, i calcolatori utilizzano circuiti elettronici dedicati:

```text
 ── INGRESSO: Dal mondo fisico al computer ──────────────────────────────────────────

  MONDO REALE (Analogico)                      COMPUTER (Digitale)
 ┌───────────────────────────┐                ┌───────────────────────────────────┐
 │ Onde sonore, luce, calore │                │                                   │
 └─────────────┬─────────────┘                │                                   │
               │                              │                                   │
    [Sensore / Trasduttore]                   │                                   │
    (es. microfono, camera)                   │                                   │
               │                              │                                   │
               ▼                              │                                   │
     Segnale Elettrico                        │                                   │
     (continuo nel tempo)                     │                                   │
               │                              │                                   │
               ▼                              │                                   │
 ┌───────────────────────────┐  Numeri binari │      MEMORIA / DISCO / CPU        │
 │   ADC (Analog-to-Digital) │ ─────────────► │                                   │
 └───────────────────────────┘  (Bit: 0 e 1)  │  I dati vengono memorizzati,      │
                                              │  salvati in file (MP3, WAV, JPG)  │
                                              │  o elaborati dal processore       │
 ── USCITA: Dal computer al mondo fisico ─────│                                   │
                                              │                                   │
 ┌───────────────────────────┐  Numeri binari │                                   │
 │   DAC (Digital-to-Analog) │ ◄───────────── │                                   │
 └─────────────┬─────────────┘  (Bit: 0 e 1)  └───────────────────────────────────┘
               │
               ▼
     Segnale Elettrico
     (ricostruito continuo)
               │
               ▼
    [Attuatore / Dispositivo]
    (es. altoparlante, cuffie)
               │
               ▼
 ┌───────────────────────────┐
 │   Onda Sonora Udibile     │
 └───────────────────────────┘
  MONDO REALE (Analogico)
```

- **Convertitore Analogico-Digitale (ADC — *Analog-to-Digital Converter*):**  
  Riceve in ingresso una grandezza fisica (trasformata in tensione elettrica da un **sensore / trasduttore** come un microfono, un sensore fotografico CMOS o un termometro) e produce in uscita la sequenza corrispondente di numeri binari.
- **Convertitore Digitale-Analogico (DAC — *Digital-to-Analog Converter*):**  
  Esegue l'operazione inversa: riceve dal computer una sequenza di numeri binari e li riconverte in un segnale elettrico continuo variabile nel tempo. Questo segnale pilota un **attuatore** (come un altoparlante, una cuffia o un display) per ricreare la sensazione fisica originale per i nostri sensi.

:::tip[Esempio quotidiano: la Scheda Audio]
La **scheda audio** (*sound card*) del tuo computer o del tuo smartphone contiene entrambi i dispositivi:
- Quando parli al microfono per registrare un messaggio vocale, l'**ADC** digitalizza la tua voce.
- Quando ascolti musica con le cuffie, il **DAC** trasforma i file MP3 o streaming nei segnali elettrici che fanno vibrare le membrane delle cuffie.
:::

---

### Regole per non perdere informazione: Nyquist-Shannon e Aliasing

Una domanda cruciale sorge spontanea: *quanti campioni al secondo dobbiamo prelevare per essere sicuri di non perdere informazioni e poter ricostruire fedelmente il segnale originale?*

#### Il Teorema del Campionamento di Nyquist-Shannon

Formulato dai matematici e ingegneri Harry Nyquist e Claude Shannon, il teorema stabilisce una regola fondamentale:

> Per poter ricostruire **perfettamente** e senza alcuna ambiguità un segnale analogico continuo a partire dai suoi campioni, la **frequenza di campionamento** ($f_s$) deve essere **almeno il doppio della frequenza massima ($f_{\text{max}}$)** contenuta nel segnale originario:
> 
> $$f_s \ge 2 \cdot f_{\text{max}}$$

La frequenza minima teorica richiesta, pari a $2 \cdot f_{\text{max}}$, è denominata **Frequenza di Nyquist** (*Nyquist Rate*).

:::note[Perché i CD Audio usano proprio 44.100 Hz (44,1 kHz)?]
L'orecchio umano di un ragazzo sano può udire frequenze sonore comprese tra circa $20\text{ Hz}$ (suoni molto gravi/bassi) e circa $20.000\text{ Hz} = 20\text{ kHz}$ (suoni molto acuti/alti).

Applicando la regola di Nyquist-Shannon:
$$f_s \ge 2 \times 20.000\text{ Hz} = 40.000\text{ Hz}$$

In fase di progettazione del formato CD Audio (all'inizio degli anni '80) si è scelto il valore standard di **$44.100\text{ Hz}$** ($44{,}1\text{ kHz}$): una frequenza leggermente superiore a $40\text{ kHz}$ che consente di campionare l'intero spettro udibile lasciando un margine di sicurezza per i filtri elettronici reali.
:::

#### Cosa succede se campioniamo troppo lentamente? L'Aliasing

Se campioniamo a una frequenza insufficiente ($f_s < 2 \cdot f_{\text{max}}$), si verifica il fenomeno del **sottocampionamento** (*under-sampling*), che genera una grave distorsione chiamata **Aliasing** (o distorsione da aliasing).

- Nell'**audio**, l'aliasing fa sì che frequenze acute al di sopra del limite vengano "mascherate" (in inglese *alias*) trasformandosi in frequenze basse e false non presenti nel suono originale, producendo un timbro sgradevole, metallico o stonato.
- Nei **video e nelle immagini**, un tipico esempio di aliasing è l'**effetto carrozza** (*wagon-wheel effect*): quando in un filmato a 24 o 30 fotogrammi al secondo le ruote di un'auto sembrano girare lentamente all'indietro o restare immobili, perché la velocità di rotazione della ruota supera la frequenza di campionamento visivo della telecamera.

---

### Glossario dei Termini Tecnici (Italiano ↔ Inglese)

| Termine Italiano | Termine Inglese | Significato sintetico |
| :--- | :--- | :--- |
| **Grandezza analogica** | *Analog quantity / signal* | Grandezza continua nel tempo e nei valori. |
| **Grandezza digitale** | *Digital quantity / signal* | Grandezza discreta rappresentata tramite numeri/bit. |
| **Digitalizzazione** | *Digitization / A/D conversion* | Processo di conversione da analogico a digitale. |
| **Trasduttore / Sensore** | *Transducer / Sensor* | Dispositivo che trasforma un fenomeno fisico in segnale elettrico. |
| **Campionamento** | *Sampling* | Misurazione del segnale a intervalli discreti di tempo. |
| **Frequenza di campionamento** | *Sample rate / Sampling frequency* | Numero di campioni prelevati al secondo (Hz). |
| **Quantizzazione** | *Quantization* | Arrotondamento dell'ampiezza al livello discreto più vicino. |
| **Profondità di bit / Risoluzione** | *Bit depth / Sample resolution* | Numero di bit usati per rappresentare ciascun campione. |
| **Convertitore A/D (ADC)** | *Analog-to-Digital Converter (ADC)* | Circuito che trasforma segnali elettrici analogici in numeri binari. |
| **Convertitore D/A (DAC)** | *Digital-to-Analog Converter (DAC)* | Circuito che trasforma numeri binari in segnali elettrici analogici. |
| **Aliasing** | *Aliasing* | Distorsione generata dal campionamento al di sotto del limite di Nyquist. |
| **Frequenza di Nyquist** | *Nyquist rate* | La soglia minima di campionamento ($2 \cdot f_{\text{max}}$). |

---

## 2. Le unità di misura dell'informazione

Prima di affrontare i calcoli sulle dimensioni dei file, dobbiamo padroneggiare bene le **unità di misura** dell'informazione digitale, perché negli esercizi troverai sia MB che MiB, sia GB che GiB — e non sono la stessa cosa!

### L'unità base: il Byte

L'unità fondamentale è il **bit** (0 o 1). Nella pratica, la memoria e i file si misurano in **byte** (B), dove:

$$1 \, \text{B} = 8 \, \text{bit}$$

Tutto il resto sono multipli del byte.

### Il problema: due sistemi di multipli

Il byte ha due famiglie di multipli che convivono (e spesso causano confusione):

#### Sistema decimale (SI) — prefissi delle scienze fisiche

Usano le **potenze di 10**, esattamente come nel sistema metrico (km, kg…). Sono usati soprattutto dai **produttori di hardware** (dischi fissi, chiavette USB) e nelle misure di velocità delle reti.

| Prefisso | Simbolo | Valore | Esempio |
| :---: | :---: | :---: | :--- |
| kilo | **kB** | $10^3$ B = 1.000 B | un file di testo semplice |
| Mega | **MB** | $10^6$ B = 1.000.000 B | una foto JPEG compressa |
| Giga | **GB** | $10^9$ B = 1.000.000.000 B | un film compresso |
| Tera | **TB** | $10^{12}$ B | un disco fisso moderno |

#### Sistema binario (IEC) — prefissi informatici

Usano le **potenze di 2**, che si adattano meglio all'architettura binaria dei computer. Sono usati dai **sistemi operativi** (Windows, macOS, Linux) quando mostrano le dimensioni di file e cartelle.

| Prefisso | Simbolo | Valore | Equivalente approssimativo |
| :---: | :---: | :---: | :---: |
| kibi | **KiB** | $2^{10}$ B = 1.024 B | ≈ 1 kB (+2,4%) |
| Mebi | **MiB** | $2^{20}$ B = 1.048.576 B | ≈ 1,049 MB (+4,9%) |
| Gibi | **GiB** | $2^{30}$ B = 1.073.741.824 B | ≈ 1,074 GB (+7,4%) |
| Tebi | **TiB** | $2^{40}$ B = 1.099.511.627.776 B | ≈ 1,1 TB (+10%) |

:::note[Nota storica]
Prima dello standard IEC (1998), il prefisso "kilo" veniva usato per indicare 1024 anziché 1000. Ancora oggi molte persone scrivono "KB" o "MB" intendendo in realtà KiB e MiB. Negli esercizi di questo capitolo il simbolo usato (MB oppure MiB) è sempre **esplicito e significativo**.
:::

### Confronto fianco a fianco

Per avere un'idea immediata delle differenze:

| Unità | Valore esatto | Differenza rispetto all'unità SI |
| :---: | ---: | :---: |
| 1 kB | 1.000 B | — |
| 1 KiB | 1.024 B | +2,4% |
| 1 MB | 1.000.000 B | — |
| 1 MiB | 1.048.576 B | +4,9% |
| 1 GB | 1.000.000.000 B | — |
| 1 GiB | 1.073.741.824 B | +7,4% |
| 1 TB | 1.000.000.000.000 B | — |
| 1 TiB | 1.099.511.627.776 B | +10,0% |

### Il paradosso del disco fisso

:::note[Esempio pratico — "Mi hanno fregato 70 GB?"]
Compri un disco fisso da **1 TB**. Il produttore usa TB decimali:

$$1 \, \text{TB} = 10^{12} \, \text{B} = 1.000.000.000.000 \, \text{B}$$

Quando colleghi il disco al computer, il sistema operativo (che usa GiB) mostra:

$$\frac{10^{12} \, \text{B}}{2^{30} \, \text{B/GiB}} = \frac{1.000.000.000.000}{1.073.741.824} \approx 931 \, \text{GiB}$$

Il disco mostra **931 GiB** invece di 1000. Non manca spazio: è solo una differenza di unità di misura! Il produttore non mente, il sistema operativo non mente — usano semplicemente scale diverse.
:::

### Come convertire

Dati in forma di formule:

$$\text{da MB a MiB:} \quad x \, \text{MB} = \frac{x \times 10^6}{2^{20}} \, \text{MiB} = \frac{x}{1{,}048576} \, \text{MiB}$$

$$\text{da MiB a MB:} \quad x \, \text{MiB} = \frac{x \times 2^{20}}{10^6} \, \text{MB} = x \times 1{,}048576 \, \text{MB}$$

:::tip[Regola pratica]
Tra MB e MiB la differenza è circa il **5%**: 1 MiB è circa il 5% più grande di 1 MB.  
Tra GB e GiB la differenza è circa il **7%**: 1 GiB è circa il 7% più grande di 1 GB.

Nei calcoli di stima puoi usare questa regola: se il testo dice **MiB**, il valore in byte è leggermente **più grande** dello stesso numero in MB.
:::

---

## 3. Immagini digitali


### Pixel e risoluzione

Un'immagine digitale è una griglia di **pixel** (*picture element*). Ogni pixel è il più piccolo punto colorato di un'immagine. La **risoluzione** di un'immagine si esprime come:

$$\text{larghezza} \times \text{altezza} \quad \text{(in pixel)}$$

Per esempio, un'immagine "Full HD" ha risoluzione $1920 \times 1080$ pixel, ovvero circa 2 milioni di pixel.

### Profondità di colore (bit per pixel)

Per memorizzare un pixel, dobbiamo codificare il suo colore. Quanti colori diversi vogliamo distinguere?

| Profondità | Bit per pixel | Colori possibili | Uso tipico |
| :---: | :---: | :---: | :--- |
| 1 bpp | 1 bit | $2^1 = 2$ | Immagini in bianco e nero puro |
| 8 bpp | 8 bit | $2^8 = 256$ | Scala di grigi o tavolozza limitata |
| 24 bpp | 24 bit | $2^{24} \approx 16{,}7$ milioni | **True Color** (RGB 8 bit/canale): standard web e fotografico |
| 30 bpp | 30 bit | $2^{30} \approx 1{,}07$ miliardi | **Deep Color / HDR** (RGB 10 bit/canale): video 4K moderni, cinema |
| 32 bpp | 32 bit | come 24 + canale alpha | Grafica con trasparenza (formato PNG / RGBA) |

- **RGB Standard (True Color — 24 bit / 8 bit per canale):**  
  Il colore di ogni pixel è composto da tre canali: **R**osso (8 bit, 0–255), **V**erde (8 bit, 0–255) e **B**lu (8 bit, 0–255).  
  Ogni pixel occupa $8 + 8 + 8 = 24\text{ bit} = \mathbf{3\text{ byte}}$ per un totale di $256 \times 256 \times 256 \approx 16{,}7\text{ milioni di colori}$.

- **RGB HDR / Deep Color (30 bit / 10 bit per canale):**  
  Nei moderni contenuti **HDR** (*High Dynamic Range*) e nei televisori/smartphone di ultima generazione, ogni canale colore usa **10 bit** ($2^{10} = 1024$ livelli per canale: 0–1023).  
  Ogni pixel occupa $10 + 10 + 10 = \mathbf{30\text{ bit}}$ (ovvero $3{,}75\text{ byte}$), permettendo di rappresentare oltre **1 miliardo di sfumature di colore** ($1024 \times 1024 \times 1024 = 2^{30} = 1.073.741.824$), eliminando le striature nei gradienti di luce e cielo.

### Calcolo della dimensione di un'immagine

La dimensione di un'immagine **non compressa** si calcola così:

$$\text{dimensione} = \text{larghezza} \times \text{altezza} \times \text{bit per pixel}$$

:::note[Esempio: immagine Full HD a 24 bpp]
$$1920 \times 1080 \times 24 \text{ bit} = 49.766.400 \text{ bit} = 6.220.800 \text{ byte} \approx 6{,}22 \text{ MB} \; (\approx 5{,}93 \text{ MiB})$$

Un singolo fotogramma di un film in alta definizione pesa quasi 6 MB se non viene compresso!
:::

---

## 4. Audio digitale

### Campionamento

Il suono è un'onda continua nel tempo. Per digitalizzarlo, si "fotografa" il livello dell'onda a intervalli regolari: questa operazione si chiama **campionamento**.

- **Frequenza di campionamento (sample rate):** quante misurazioni al secondo, in Hz (Hertz)
- **Profondità di campionamento (bit depth):** quanti bit si usano per ogni misura

| Qualità | Frequenza | Bit depth | Canali |
| :--- | :---: | :---: | :---: |
| Telefono digitale | 8.000 Hz | 8 bit | 1 (mono) |
| CD Audio (standard) | 44.100 Hz | 16 bit | 2 (stereo) |
| Audio professionale | 48.000 Hz | 24 bit | 2 (stereo) |

### Calcolo della dimensione di un file audio

$$\text{dimensione} = \text{frequenza} \times \text{bit depth} \times \text{canali} \times \text{durata (secondi)}$$

:::note[Esempio: 1 minuto di CD Audio]
$$44.100 \times 16 \times 2 \times 60 = 84.672.000 \text{ bit} = 10.584.000 \text{ byte} \approx 10{,}58 \text{ MB} \; (\approx 10{,}09 \text{ MiB})$$

Un CD può contenere circa 650 MB di dati, corrispondenti a circa **un'ora** di musica in qualità CD non compressa.
:::

---

## 5. Video digitale

Un video è semplicemente una **sequenza di immagini** (frame) mostrate in rapida successione, accompagnata da una traccia audio.

- **Frame rate (fps):** numero di immagini al secondo (tipicamente 24, 25, 30 o 60 fps)
- Ogni frame è un'immagine completa con la sua risoluzione e profondità colore

### Calcolo della dimensione di un file video

$$\text{dimensione video} = \text{dimensione di un frame} \times \text{frame rate} \times \text{durata (secondi)}$$

$$\text{dimensione totale} = \text{dimensione video} + \text{dimensione audio}$$

:::note[Esempio: 10 secondi di video Full HD a 24 fps e 24 bpp]
Dimensione video:
$$1920 \times 1080 \times 24 \text{ bit} \times 24 \text{ fps} \times 10 \text{ s} = 1.194.393.600 \text{ bit} = 149.299.200 \text{ byte} \approx 149 \text{ MB}$$

Solo 10 secondi di video non compresso pesano quasi 150 MB! Ecco perché la **compressione** (H.264, H.265, AV1…) è indispensabile: riduce le dimensioni di 100–1000 volte.
:::

---

## 6. La Compressione Multimediale e i Formati più Diffusi

Come abbiamo visto nei calcoli precedenti, i file multimediali non compressi (*raw*) hanno dimensioni gigantesche:
- Una sola fotografia da $12\text{ Megapixel}$ a 24 bit occuperebbe circa **$36\text{ MB}$**.
- Una sola canzone di 4 minuti in qualità CD non compressa occupa circa **$42\text{ MB}$**.
- Un film di due ore in 4K a 60 fps e 10 bit occuperebbe oltre **$10\text{ Terabyte}$**!

Sarebbe impensabile inviare immagini su WhatsApp, ascoltare musica in streaming su Spotify o guardare un film su Netflix senza la **compressione dei dati** (*data compression*).

---

### Compressione Lossless vs Lossy

Tutti gli algoritmi di compressione appartengono a due grandi famiglie:

| Caratteristica | Compressione **Lossless** (*Senza Perdita*) | Compressione **Lossy** (*Con Perdita*) |
| :--- | :--- | :--- |
| **Come funziona?** | Elimina le ridondanze matematiche e statistiche. I dati decompressi sono **esattamente identici al 100%** a quelli originali (come un archivio `.zip`). | Elimina le informazioni che l'occhio o l'orecchio umano **non riescono a percepire facilmente** (modelli psicoacustici e psicovisivi). |
| **Fattore di riduzione** | **Modesto:** riduce la dimensione di circa **$1{,}5 \times - 3 \times$** (risparmio tipico del 30%–60%). | **Elevatissimo:** riduce la dimensione di **$10 \times, 50 \times$ fino a oltre $100 \times$**. |
| **Recupero originale** | Perfetto al bit singolo: reversibile. | Irreversibile: i dettagli scartati sono persi per sempre. |
| **Ambiti di utilizzo** | Documenti di testo, codice sorgente, grafica con bordi netti, archiviazione master audio, diagnostica medica. | Streaming online (YouTube, Spotify, Netflix), videogiochi, social media, fotografie da smartphone. |

:::tip[Il compromesso fondamentale: Dimensione vs Qualità (*Trade-off*)]
Nella compressione **lossy**, il livello di compressione **non è fisso**: si può comprimere virtualmente *quanto si vuole*!
- Possiamo impostare un file JPEG con qualità al $90\%$ (file più grande, quasi indistinguibile dall'originale) oppure al $10\%$ (file minuscolo, ma pieno di evidenti artefatti e "quadrettoni").
- Possiamo comprimere una traccia MP3 a $320\text{ kbps}$ (qualità elevatissima) oppure a $64\text{ kbps}$ (file leggerissimo, ma con suono inscatolato e metallico).

Il lavoro di chi gestisce file multimediali e piattaforme di streaming è proprio trovare il **miglior compromesso possibile** tra **peso del file** e **qualità percepita** in base all'esigenza:
- **Alta qualità / peso maggiore:** per guardare un film su una smart TV 4K da 65 pollici o per masterizzare musica.
- **Massima compressione / peso minimo:** per inviare un vocale o una foto rapidamente su WhatsApp con connessione dati lenta o instabile.
:::

---

### Codec vs Formato Contenitore (*Container*)

Spesso si fa confusione tra **codec** ed **estensione del file**:

- **Codec** (*Coder-Decoder*): è l'**algoritmo matematico** che comprime e decomprime il flusso audio o video (ad esempio: *H.264*, *HEVC/H.265*, *AV1*, *AAC*, *MP3*).
- **Contenitore (*Container*)**: è la "scatola" (il file con la sua estensione, ad esempio `.mp4`, `.mkv`, `.avi`) che racchiude al suo interno contemporaneamente la traccia video, una o più tracce audio (es. italiano e inglese), i sottotitoli e i capitoli sincronizzati.

:::tip[Metafora]
Il **contenitore** è come una valigia (`.mp4`), mentre i **codec** sono il modo in cui sono stati piegati e compressi i vestiti al suo interno (la traccia video H.264 e la traccia audio AAC).
:::

---

### I Formati più Comuni Oggi

#### 1. Immagini
- **JPEG / JPG** (*Lossy*): il formato fotografico più diffuso al mondo da oltre 30 anni. Ottimo per fotografie con sfumature e paesaggi, pessimo per loghi e testi (dove crea aloni sfocati).
- **PNG** (*Lossless*): supporta la trasparenza (canale *alpha*) e mantiene i bordi nitidi. Ideale per loghi, icone, grafici e screenshot.
- **WebP / AVIF** (*Lossy o Lossless*): formati moderni sviluppati per il web. A parità di qualità visiva pesano dal 30% al 50% in meno rispetto a JPEG e PNG.
- **SVG** (*Grafica Vettoriale*): non è fatto di pixel, ma di formule matematiche (linee, curve, poligoni). Può essere ingrandito all'infinito senza mai sgranare.

#### 2. Audio
- **WAV / AIFF** (*Non compresso - PCM*): registra ogni singolo campione senza alcuna compressione. Usato negli studi di registrazione professionali per l'editing.
- **FLAC** (*Lossless*): il formato standard per audiofili. Riduce la dimensione del 40-50% senza perdere neanche un bit di qualità musicale.
- **MP3** (*Lossy*): lo storico formato che ha rivoluzionato la musica digitale negli anni 2000. Ancora universale, ma tecnologicamente superato.
- **AAC / Ogg Vorbis / Opus** (*Lossy moderni*): garantiscono una qualità superiore a MP3 a parità di bitrate. Sono usati da YouTube, Apple Music, Spotify e per le chiamate VoIP (WhatsApp, Discord).

#### 3. Video
- **H.264 / AVC** (*Codec Lossy*): il codec video più compatibile al mondo, riproducibile su qualsiasi computer, TV, smartphone e browser da oltre 15 anni.
- **H.265 / HEVC** (*Codec Lossy*): successore di H.264. A parità di qualità dimezza lo spazio necessario (efficienza doppia), ed è lo standard per i video in **4K ed HDR**.
- **AV1** (*Codec Lossy Open & Royalty-Free*): il codec moderno del consorzio *AOMedia* (Google, Netflix, Amazon, Apple, Microsoft). Offre una compressione ancora migliore di HEVC ed è gratuito da implementare (usato sempre più da YouTube e Netflix).
- **MP4 / MKV / WebM** (*Contenitori*):
  - `.mp4`: standard universale supportato ovunque.
  - `.mkv` (*Matroska*): contenitore aperto estremamente potente, capace di contenere decine di tracce audio e sottotitoli in formati diversi.
  - `.webm`: contenitore ottimizzato per lo streaming web HTML5.

---

## 7. Il Metodo Pratico: risolvere gli esercizi con le unità di misura

Abbiamo visto tante formule diverse: una per le immagini, una per l'audio, una per il video, più le conversioni tra bit, byte, MB e MiB. Imparare a memoria tutte le formule (e tutte le loro versioni "inverse") è faticoso e porta facilmente a errori.

Naturalmente, ragionando bene sul significato delle grandezze si riesce sempre a capire cosa moltiplicare e cosa dividere: se ogni pixel occupa 24 bit e i pixel sono 2 milioni, è chiaro che il totale si ottiene con una moltiplicazione. Ma quando le grandezze in gioco diventano tante (frequenza, profondità, canali, tempo, conversioni tra byte e MB…) o quando l'esercizio chiede di trovare un dato "al contrario", il ragionamento si complica e diventa facile confondersi.

Per questo conviene usare un **metodo più semplice e meccanico**: basta sapere **quali grandezze sono in gioco** e **in quale unità di misura si esprimono**. Le unità di misura, se scritte sempre accanto ai numeri, ci dicono da sole cosa moltiplicare e cosa dividere, senza dover ricordare nessuna formula.

:::tip[Un metodo che vale anche in fisica e in scienze]
Questa tecnica si chiama **analisi dimensionale** e non è un trucco solo informatico: è esattamente lo stesso metodo che si usa in **fisica**, in **chimica** e in tutte le **scienze**. Ad esempio, se un'auto viaggia a $90 \, \text{km/h}$ per $2 \, \text{h}$, moltiplicando le unità si ottiene $\frac{\text{km}}{\cancel{\text{h}}} \times \cancel{\text{h}} = \text{km}$: la distanza percorsa. Imparare a usarla qui ti servirà anche in tutte le altre materie scientifiche!
:::

### Le abbreviazioni che useremo

Per scrivere le unità di misura in modo compatto useremo questi simboli:

| Simbolo | Significato |
| :---: | :--- |
| $\text{b}$ | bit |
| $\text{B}$ | byte ($1 \, \text{B} = 8 \, \text{b}$) |
| $\text{px}$ | pixel |
| $\text{c}$ | campione (audio) |
| $\text{frame}$ | fotogramma (video) |
| $\text{s}$ | secondo |
| $\text{Hz}$ | "al secondo": per la frequenza di campionamento $1 \, \text{Hz} = 1 \, \text{c/s}$ (un campione al secondo) |

### Riepilogo delle grandezze in gioco

Il trucco fondamentale è scrivere ogni grandezza con un'unità di misura "parlante", del tipo **"quanti X per ogni Y"**: ad esempio la profondità di colore non è semplicemente "24 bit", ma **24 bit per ogni pixel**, cioè $24 \, \text{b/px}$; la profondità di campionamento non è "16 bit", ma **16 bit per ogni campione**, cioè $16 \, \text{b/c}$.

#### Immagini

| Grandezza | Come può comparire nel testo | Unità di misura |
| :--- | :--- | :---: |
| **Formato** (risoluzione) | "$1920 \times 1080$", "Full HD", "4K", "immagine quadrata di lato…" | larghezza $\times$ altezza (in $\text{px}$) |
| **Numero totale di pixel** | "12 megapixel" ($1 \, \text{Mpx} = 10^6 \, \text{px}$) | $\text{px}$ |
| **Numero di colori** | "256 colori", "16,7 milioni di colori" | numero puro |
| **Profondità di colore** | "24 bpp", "colour depth", "bit per pixel" | $\text{b/px}$ |
| **Dimensione** | "occupa 6 MB", "pesa…" | $\text{b}$ (oppure B, kB, MB, MiB…) |

Le relazioni tra queste grandezze sono:

$$\text{numero di pixel} \; [\text{px}] = \text{larghezza} \times \text{altezza}$$

$$\text{numero di colori} = 2^{\,\text{profondità di colore}}$$

$$\text{dimensione} \; [\text{b}] = \text{numero di pixel} \; [\text{px}] \times \text{profondità di colore} \; [\text{b/px}]$$

:::note[Formati con un nome e profondità "per canale"]
- Alcuni formati vengono indicati con un nome: **HD** $= 1280 \times 720$, **Full HD** $= 1920 \times 1080$, **4K UHD** $= 3840 \times 2160$.
- A volte la profondità di colore è data **per canale** (es. "8 bit per canale RGB"). I canali RGB sono 3, quindi: $8 \, \text{b/canale} \times 3 \, \text{canali/px} = 24 \, \text{b/px}$.
:::

#### Audio

| Grandezza | Come può comparire nel testo | Unità di misura |
| :--- | :--- | :---: |
| **Frequenza di campionamento** | "44,1 kHz", "sample rate", $f_s$ | $\text{Hz} = \text{c/s}$ |
| **Profondità di campionamento** | "16 bit", "bit depth", "risoluzione" | $\text{b/c}$ |
| **Numero di canali** | "mono" $= 1$, "stereo" $= 2$ | numero puro |
| **Tempo** (durata) | "3 min 45 s", "un minuto di musica" | $\text{s}$ |
| **Bitrate** | "320 kbps", "velocità di trasmissione" | $\text{b/s}$ |
| **Dimensione** | "occupa 10 MB", "pesa…" | $\text{b}$ (oppure B, kB, MB, MiB…) |

Le relazioni tra queste grandezze sono:

$$\text{bitrate} \; [\text{b/s}] = \text{frequenza} \; [\text{c/s}] \times \text{profondità} \; [\text{b/c}] \times \text{numero di canali}$$

$$\text{dimensione} \; [\text{b}] = \text{bitrate} \; [\text{b/s}] \times \text{tempo} \; [\text{s}]$$

#### Video

Un video è una **sequenza di immagini** (frame), eventualmente accompagnata da una traccia audio. Ritroviamo quindi **tutte le grandezze delle immagini**, riferite al singolo frame, a cui se ne aggiungono di nuove:

| Grandezza | Come può comparire nel testo | Unità di misura |
| :--- | :--- | :---: |
| **Formato** di un frame | "$1280 \times 720$", "Full HD", "4K" | larghezza $\times$ altezza (in $\text{px}$) |
| **Pixel per frame** | numero totale di pixel di un fotogramma | $\text{px/frame}$ |
| **Numero di colori** | "256 colori" | numero puro |
| **Profondità di colore** | "24 bpp", "10 bit per canale" | $\text{b/px}$ |
| **Dimensione di un frame** | peso di un singolo fotogramma | $\text{b/frame}$ |
| **Frame rate** *(nuova)* | "30 fps", "fotogrammi al secondo" | $\text{frame/s}$ |
| **Tempo** *(nuova)* | "dura 10 s" | $\text{s}$ |
| **Bitrate** *(nuova)* | "597 Mbps", "flusso dati" | $\text{b/s}$ |
| **Dimensione** | "occupa 2 GiB" | $\text{b}$ (oppure B, kB, MB, MiB…) |
| **Traccia audio** (se presente) | ha tutte le grandezze dell'audio | $\text{b}$, da sommare al video |

Le relazioni tra queste grandezze sono:

$$\text{dimensione di un frame} \; [\text{b/frame}] = \text{pixel per frame} \; [\text{px/frame}] \times \text{profondità di colore} \; [\text{b/px}]$$

$$\text{bitrate} \; [\text{b/s}] = \text{dimensione di un frame} \; [\text{b/frame}] \times \text{frame rate} \; [\text{frame/s}]$$

$$\text{dimensione} \; [\text{b}] = \text{bitrate} \; [\text{b/s}] \times \text{tempo} \; [\text{s}] \qquad (+ \text{ eventuale audio})$$

#### Valida per tutti: il fattore di compressione

| Grandezza | Come può comparire nel testo | Unità di misura |
| :--- | :--- | :---: |
| **Fattore di compressione** | "riduce di 25 volte", "1:25" | numero puro |

Si **divide** la dimensione (o il bitrate) del file non compresso per il fattore di compressione.

### La catena delle unità di misura

Mettendo in fila le relazioni si vede che i tre tipi di file seguono **lo stesso schema**: a ogni passaggio si moltiplica per una grandezza "X per ogni Y" e l'unità Y si semplifica. Ecco i passaggi per arrivare alla dimensione del file, scritti solo con le unità di misura:

| Tipo di file | Passaggio | Calcolo con le unità di misura |
| :--- | :--- | :---: |
| **Immagine** | pixel $\times$ profondità di colore $=$ dimensione | $\cancel{\text{px}} \times \dfrac{\text{b}}{\cancel{\text{px}}} = \text{b}$ |
| **Audio** | ① frequenza $\times$ profondità $\times$ canali $=$ bitrate | $\dfrac{\cancel{\text{c}}}{\text{s}} \times \dfrac{\text{b}}{\cancel{\text{c}}} \times \text{canali} = \dfrac{\text{b}}{\text{s}}$ |
| | ② bitrate $\times$ tempo $=$ dimensione | $\dfrac{\text{b}}{\cancel{\text{s}}} \times \cancel{\text{s}} = \text{b}$ |
| **Video** | ① pixel per frame $\times$ profondità di colore $=$ dimensione di un frame | $\dfrac{\cancel{\text{px}}}{\text{frame}} \times \dfrac{\text{b}}{\cancel{\text{px}}} = \dfrac{\text{b}}{\text{frame}}$ |
| | ② dimensione di un frame $\times$ frame rate $=$ bitrate | $\dfrac{\text{b}}{\cancel{\text{frame}}} \times \dfrac{\cancel{\text{frame}}}{\text{s}} = \dfrac{\text{b}}{\text{s}}$ |
| | ③ bitrate $\times$ tempo $=$ dimensione | $\dfrac{\text{b}}{\cancel{\text{s}}} \times \cancel{\text{s}} = \text{b}$ |

- Negli esercizi **diretti** (trovare la dimensione) si eseguono i passaggi dall'alto in basso **moltiplicando**.
- Negli esercizi **inversi** (trovare tempo, frequenza, profondità, frame rate…) si parte dalla dimensione e si risale **dividendo**.

In entrambi i casi il **bitrate** ($\text{b/s}$) fa da "ponte" tra audio e video: qualunque sia il tipo di file, $\text{b/s} \times \text{s} = \text{b}$.

### Le conversioni sono frazioni che valgono 1

Anche i cambi di unità si fanno moltiplicando. Ogni equivalenza può essere scritta come una **frazione che vale 1**, che possiamo girare come ci serve:

| Equivalenza | Frazioni utilizzabili |
| :--- | :---: |
| $1 \, \text{B} = 8 \, \text{b}$ | $\dfrac{8 \, \text{b}}{1 \, \text{B}}$ oppure $\dfrac{1 \, \text{B}}{8 \, \text{b}}$ |
| $1 \, \text{MB} = 10^6 \, \text{B}$ | $\dfrac{10^6 \, \text{B}}{1 \, \text{MB}}$ oppure $\dfrac{1 \, \text{MB}}{10^6 \, \text{B}}$ |
| $1 \, \text{MiB} = 2^{20} \, \text{B}$ | $\dfrac{2^{20} \, \text{B}}{1 \, \text{MiB}}$ oppure $\dfrac{1 \, \text{MiB}}{2^{20} \, \text{B}}$ |
| $1 \, \text{kb} = 1000 \, \text{b}$ (kbps $\to$ b/s) | $\dfrac{1000 \, \text{b}}{1 \, \text{kb}}$ |
| $1 \, \text{kHz} = 1000 \, \text{Hz} = 1000 \, \text{c/s}$ | $\dfrac{1000 \, \text{c/s}}{1 \, \text{kHz}}$ |
| $1 \, \text{min} = 60 \, \text{s}$ | $\dfrac{60 \, \text{s}}{1 \, \text{min}}$ |

Si sceglie sempre la versione della frazione che fa **semplificare l'unità che vogliamo eliminare** (quella che sta sopra si semplifica con una uguale sotto, e viceversa).

### Il metodo in 4 passi

1. **Cosa devo trovare? In che unità?** Scrivi l'unità del risultato (es. "b/px", "s", "MB").
2. **Elenca i dati con la loro unità "parlante"** (es. $16 \, \text{b/c}$, non solo "16").
3. **Combina i dati** moltiplicando e dividendo in modo che le unità si semplifichino e **rimanga esattamente l'unità cercata**. Se l'unità finale non torna, l'impostazione è sbagliata!
4. **Fai i calcoli** e controlla che il risultato sia sensato (una foto da 3000 GB o una canzone da 0,002 secondi indicano un errore).

:::tip[La tabella delle "mosse"]
Quasi tutti gli esercizi si riducono a una catena di queste operazioni:

| Ho... | e ho... | Voglio... | Operazione |
| :---: | :---: | :---: | :---: |
| $\text{b/px}$ | $\text{px}$ | $\text{b}$ | moltiplico |
| $\text{b}$ | $\text{px}$ | $\text{b/px}$ | divido: $\text{b} \div \text{px}$ |
| $\text{b}$ | $\text{b/px}$ | $\text{px}$ | divido: $\text{b} \div \text{b/px}$ |
| $\text{c/s}$ | $\text{b/c}$ | $\text{b/s}$ | moltiplico |
| $\text{b/s}$ | $\text{b/c}$ | $\text{c/s}$ | divido: $\text{b/s} \div \text{b/c}$ |
| $\text{px/frame}$ | $\text{b/px}$ | $\text{b/frame}$ | moltiplico |
| $\text{b/frame}$ | $\text{frame/s}$ | $\text{b/s}$ | moltiplico |
| $\text{b/s}$ | $\text{b/frame}$ | $\text{frame/s}$ | divido: $\text{b/s} \div \text{b/frame}$ |
| $\text{b/s}$ | $\text{s}$ | $\text{b}$ | moltiplico |
| $\text{b}$ | $\text{s}$ | $\text{b/s}$ | divido: $\text{b} \div \text{s}$ |
| $\text{b}$ | $\text{b/s}$ | $\text{s}$ | divido: $\text{b} \div \text{b/s}$ |

**Regola generale:** se l'unità che ti serve è un **prodotto** delle unità che hai, moltiplica; se è un **rapporto**, dividi.
:::

### Esempi svolti con le unità di misura

#### Esempio 1 — Immagine: dimensione in MB (calcolo diretto)

*Quanto occupa un'immagine $1920 \times 1080$ px a 24 bpp, in MB?*

Voglio dei **MB**. Ho dei $\text{px}$ e dei $\text{b/px}$: moltiplicando ottengo bit, poi converto con le frazioni che valgono 1.

$$1920 \times 1080 \, \cancel{\text{px}} \times 24 \, \frac{\cancel{\text{b}}}{\cancel{\text{px}}} \times \frac{1 \, \cancel{\text{B}}}{8 \, \cancel{\text{b}}} \times \frac{1 \, \text{MB}}{10^6 \, \cancel{\text{B}}} = \frac{1920 \times 1080 \times 24}{8 \times 10^6} \, \text{MB} \approx \mathbf{6{,}22 \, MB}$$

#### Esempio 2 — Immagine: trovare la profondità di colore (calcolo inverso)

*Un file RAW $4000 \times 3000$ px occupa 36 MB. Qual è la profondità di colore?*

Voglio dei **b/px**: è un **rapporto** tra bit e pixel, quindi devo dividere i bit del file per il numero di pixel. Prima porto i MB in bit:

$$36 \, \cancel{\text{MB}} \times \frac{10^6 \, \cancel{\text{B}}}{1 \, \cancel{\text{MB}}} \times \frac{8 \, \text{b}}{1 \, \cancel{\text{B}}} = 288.000.000 \, \text{b}$$

$$\frac{288.000.000 \, \text{b}}{4000 \times 3000 \, \text{px}} = \frac{288.000.000}{12.000.000} \, \frac{\text{b}}{\text{px}} = \mathbf{24 \, b/px}$$

Da qui, se serve, il numero di colori: $2^{24} \approx 16{,}7$ milioni.

#### Esempio 3 — Audio: trovare la durata (calcolo inverso)

*Un file audio stereo a 44,1 kHz e 16 bit occupa 27,5184 MB. Quanto dura?*

Voglio dei **secondi**. Calcolo prima il bitrate ($\text{b/s}$):

$$44.100 \, \frac{\cancel{\text{c}}}{\text{s}} \times 16 \, \frac{\text{b}}{\cancel{\text{c}}} \times 2 = 1.411.200 \, \frac{\text{b}}{\text{s}}$$

Ho dei **b** (la dimensione) e dei **b/s** (il bitrate): dividendo, i bit si semplificano e rimangono i secondi.

$$\frac{27{,}5184 \times 10^6 \times 8 \, \cancel{\text{b}}}{1.411.200 \, \dfrac{\cancel{\text{b}}}{\text{s}}} = \frac{220.147.200}{1.411.200} \, \text{s} = \mathbf{156 \, s}$$

:::note[Perché dividere per "b/s" dà dei secondi?]
Dividere per una frazione equivale a moltiplicare per la sua inversa:
$$\text{b} \div \frac{\text{b}}{\text{s}} = \cancel{\text{b}} \times \frac{\text{s}}{\cancel{\text{b}}} = \text{s}$$
:::

#### Esempio 4 — Audio compresso: dimensione di un MP3

*Un MP3 a 320 kbps dura 2 min 40 s. Quanto occupa in MB?*

Voglio dei **MB**. Ho un bitrate ($\text{kb/s}$) e una durata: bitrate $\times$ durata dà i bit. Prima trasformo la durata in secondi: $2 \times 60 + 40 = 160 \, \text{s}$.

$$320 \, \frac{\cancel{\text{kb}}}{\cancel{\text{s}}} \times 160 \, \cancel{\text{s}} \times \frac{1000 \, \cancel{\text{b}}}{1 \, \cancel{\text{kb}}} \times \frac{1 \, \cancel{\text{B}}}{8 \, \cancel{\text{b}}} \times \frac{1 \, \text{MB}}{10^6 \, \cancel{\text{B}}} = \mathbf{6{,}4 \, MB}$$

#### Esempio 5 — Video: trovare il frame rate (calcolo inverso)

*Un video non compresso $1280 \times 720$ px, 24 bpp, dura 10 s e occupa 829,44 MB. Qual è il frame rate?*

Voglio dei **frame/s**. Calcolo quanto pesa un fotogramma:

$$1280 \times 720 \, \frac{\cancel{\text{px}}}{\text{frame}} \times 24 \, \frac{\text{b}}{\cancel{\text{px}}} = 22.118.400 \, \frac{\text{b}}{\text{frame}}$$

Porto la dimensione del file in bit e la divido per la durata, ottenendo il bitrate:

$$\frac{829{,}44 \times 10^6 \times 8 \, \text{b}}{10 \, \text{s}} = 663.552.000 \, \frac{\text{b}}{\text{s}}$$

Ho dei **b/s** e dei **b/frame**: dividendo, i bit si semplificano e rimangono i frame al secondo.

$$\frac{663.552.000 \, \dfrac{\cancel{\text{b}}}{\text{s}}}{22.118.400 \, \dfrac{\cancel{\text{b}}}{\text{frame}}} = \mathbf{30 \, frame/s}$$

#### Esempio 6 — Compressione: trovare il fattore

*Il video dell'esempio 5 viene compresso e occupa 16,5888 MB. Di quante volte è stato ridotto?*

Il fattore di compressione è un **numero puro**: si ottiene dividendo due grandezze con la **stessa unità**, che quindi si semplificano completamente.

$$\frac{829{,}44 \, \cancel{\text{MB}}}{16{,}5888 \, \cancel{\text{MB}}} = \mathbf{50} \quad \text{(compressione 1:50)}$$

### Due casi in cui le unità non bastano

Le unità di misura guidano quasi tutti i calcoli, ma ci sono due passaggi da ricordare a parte:

- **Dal numero di colori alla profondità di colore:** colori e b/px sono legati da una potenza di 2, non da un prodotto. Con $N \, \text{b/px}$ si hanno $2^N$ colori; viceversa, per rappresentare un certo numero di colori si cerca la **più piccola potenza di 2** che li contiene (es. 1000 colori $\to$ $2^{10} = 1024 \ge 1000$ $\to$ servono **10 b/px**).
- **Dal formato al numero di pixel (e viceversa):** il numero di pixel si ottiene moltiplicando larghezza per altezza; se l'immagine è **quadrata** e conosco il numero totale di pixel, il lato si trova con la **radice quadrata**: $\text{lato} = \sqrt{\text{numero di pixel}}$.

### Le trappole più comuni

:::caution[Controlla sempre queste cose prima di consegnare]
- **Minuti e secondi:** il tempo va sempre portato in **secondi** prima di moltiplicarlo per un bitrate in b/s.
- **bit e byte:** la "b" minuscola indica i bit, la "B" maiuscola i byte. I bitrate (kbps, Mbps) sono in **bit**, le dimensioni dei file di solito in **byte**: serve il fattore $8$.
- **MB o MiB?** $1 \, \text{MB} = 10^6 \, \text{B}$, $1 \, \text{MiB} = 2^{20} \, \text{B}$. Leggi bene il simbolo nel testo.
- **kHz e kbps:** il prefisso "k" vale $1000$ (non $1024$) sia per le frequenze sia per i bitrate.
- **Bit per canale o bit per pixel?** "10 bit per canale RGB" significa $10 \times 3 = 30 \, \text{b/px}$.
- **Mono o stereo?** Lo stereo raddoppia tutto ($\times 2$).
- **Compressione:** un fattore "1:25" o "riduce di 25 volte" **divide** la dimensione; "riduce di un terzo" significa invece che rimangono i $\frac{2}{3}$.
:::

---

## 8. Mettiti alla Prova: Esercizi ed Esercitazioni Pratiche

Per consolidare tutti i concetti e verificare la tua preparazione:

👉 **[Vai alla raccolta completa degli Esercizi sulla Rappresentazione dell'Informazione](/manuale-libero-online-di-informatica/rappresentazione-informazione/esercizi/)**

Nella pagina degli esercizi troverai problemi su:
- **Unità di misura**: conversioni dirette e differenze tra standard SI (MB) e IEC (MiB)
- **File audio**: calcolo di dimensioni, durata, sample rate, bitrate e formati compressi (MP3, FLAC)
- **Immagini**: calcolo di colour depth (True Color, HDR), dimensioni e numero di colori
- **Video**: bitrate (4K HDR), colour depth e fattori di riduzione dei codec (1:25)


