---
title: "Esercizi sulla Rappresentazione dell'Informazione"
description: "Raccolta di problemi ed esercitazioni pratiche con soluzioni a comparsa su codice ASCII, Unicode, codifiche personali e calcolo del numero di bit necessari."
---

In questa pagina puoi metterti alla prova con esercizi su codifiche e rappresentazione dell'informazione in binario.

Tutte le soluzioni sono **nascoste per impostazione predefinita**: prova prima a risolverli su carta o a mente, poi clicca su ciascun riquadro per confrontare il tuo risultato con lo svolgimento completo.

---

## Tipologia 1: Codice ASCII

### Codifica ASCII: da testo a binario

Codifica le seguenti parole usando il codice ASCII (esprimi ogni carattere come 1 byte in binario):
- **A)** `HI`
- **B)** `Ok`
- **C)** `BYTE`

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-ascii-enc">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-ascii-enc">
        <p><strong>A) "HI"</strong></p>
        <ul>
            <li>H = 72 = <strong>01001000</strong></li>
            <li>I = 73 = <strong>01001001</strong></li>
        </ul>
        <p>Sequenza: <code>01001000 01001001</code></p>
        <p><strong>B) "Ok"</strong></p>
        <ul>
            <li>O = 79 = <strong>01001111</strong></li>
            <li>k = 107 = <strong>01101011</strong></li>
        </ul>
        <p>Sequenza: <code>01001111 01101011</code></p>
        <p><strong>C) "BYTE"</strong></p>
        <ul>
            <li>B = 66 = <strong>01000010</strong></li>
            <li>Y = 89 = <strong>01011001</strong></li>
            <li>T = 84 = <strong>01010100</strong></li>
            <li>E = 69 = <strong>01000101</strong></li>
        </ul>
        <p>Sequenza: <code>01000010 01011001 01010100 01000101</code></p>
    </div>
</div>

---

### Decodifica ASCII: da binario a testo

Decodifica le seguenti sequenze di byte usando il codice ASCII:
- **A)** `01001010 01000001`
- **B)** `01001101 01000001 01010000`
- **C)** `01001001 01001110 01000110 01001111`

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-ascii-dec">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-ascii-dec">
        <p><strong>A) <code>01001010 01000001</code></strong></p>
        <ul>
            <li>$01001010 = 64+8+2 = 74$ → <strong>J</strong></li>
            <li>$01000001 = 64+1 = 65$ → <strong>A</strong></li>
        </ul>
        <p>Testo: <strong>"JA"</strong></p>
        <p><strong>B) <code>01001101 01000001 01010000</code></strong></p>
        <ul>
            <li>$01001101 = 64+8+4+1 = 77$ → <strong>M</strong></li>
            <li>$01000001 = 64+1 = 65$ → <strong>A</strong></li>
            <li>$01010000 = 64+16 = 80$ → <strong>P</strong></li>
        </ul>
        <p>Testo: <strong>"MAP"</strong></p>
        <p><strong>C) <code>01001001 01001110 01000110 01001111</code></strong></p>
        <ul>
            <li>$01001001 = 64+8+1 = 73$ → <strong>I</strong></li>
            <li>$01001110 = 64+8+4+2 = 78$ → <strong>N</strong></li>
            <li>$01000110 = 64+4+2 = 70$ → <strong>F</strong></li>
            <li>$01001111 = 64+8+4+2+1 = 79$ → <strong>O</strong></li>
        </ul>
        <p>Testo: <strong>"INFO"</strong></p>
    </div>
</div>

---

### Quanta memoria occupa un testo?

Calcola quanti **byte** e quanti **bit** occupa ciascun testo usando la codifica ASCII (1 carattere = 1 byte):
- **A)** La parola `informatica` (11 caratteri)
- **B)** La frase `Ciao mondo!` (11 caratteri, spazio incluso)
- **C)** Un file di testo con 80 righe da 60 caratteri ciascuna

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-ascii-size">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-ascii-size">
        <p><strong>A) "informatica" (11 caratteri):</strong></p>
        <ul>
            <li>$11 \text{ caratteri} \times 1 \text{ byte} = 11 \text{ byte} = 88 \text{ bit}$</li>
        </ul>
        <p><strong>B) "Ciao mondo!" (11 caratteri incluso lo spazio e il punto esclamativo):</strong></p>
        <ul>
            <li>$11 \text{ caratteri} \times 1 \text{ byte} = 11 \text{ byte} = 88 \text{ bit}$</li>
        </ul>
        <p><strong>C) File con 80 righe × 60 caratteri:</strong></p>
        <ul>
            <li>$80 \times 60 = 4800 \text{ caratteri}$</li>
            <li>$4800 \times 1 \text{ byte} = \mathbf{4800 \text{ byte}} \approx 4.7 \text{ KB}$</li>
            <li>In bit: $4800 \times 8 = 38.400 \text{ bit}$</li>
        </ul>
    </div>
</div>

---

## Tipologia 2: Calcolo del numero di bit necessari

### Quanti bit servono?

Per ciascuno dei seguenti insiemi, calcola il numero **minimo** di bit necessari a rappresentare tutti gli elementi:
- **A)** I 12 mesi dell'anno
- **B)** I 26 caratteri dell'alfabeto italiano (solo maiuscole)
- **C)** I 7 giorni della settimana
- **D)** I 365 giorni dell'anno
- **E)** I 52 caratteri delle carte di un mazzo

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-nbit">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-nbit">
        <p>Per trovare il numero minimo di bit $k$, cerco la minima potenza di 2 maggiore o uguale a $N$: $2^k \geq N$.</p>
        <ul>
            <li><strong>A) 12 mesi:</strong><br />
                $2^3 = 8 &lt; 12 \leq 16 = 2^4$ → servono <strong>4 bit</strong> (si possono rappresentare 16 valori, se ne usano 12).
            </li>
            <li><strong>B) 26 lettere maiuscole:</strong><br />
                $2^4 = 16 &lt; 26 \leq 32 = 2^5$ → servono <strong>5 bit</strong> (si possono rappresentare 32 valori, se ne usano 26).
            </li>
            <li><strong>C) 7 giorni:</strong><br />
                $2^2 = 4 &lt; 7 \leq 8 = 2^3$ → servono <strong>3 bit</strong> (si possono rappresentare 8 valori, se ne usano 7).
            </li>
            <li><strong>D) 365 giorni:</strong><br />
                $2^8 = 256 &lt; 365 \leq 512 = 2^9$ → servono <strong>9 bit</strong> (si possono rappresentare 512 valori, se ne usano 365).
            </li>
            <li><strong>E) 52 carte:</strong><br />
                $2^5 = 32 &lt; 52 \leq 64 = 2^6$ → servono <strong>6 bit</strong> (si possono rappresentare 64 valori, se ne usano 52).
            </li>
        </ul>
    </div>
</div>

---

### Quante cose si possono rappresentare?

Con il numero di bit indicato, quanti oggetti distinti posso codificare al massimo?
- **A)** 3 bit
- **B)** 6 bit
- **C)** 10 bit
- **D)** 1 bit
- **E)** 16 bit

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-2k">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-2k">
        <p>Con $k$ bit si possono rappresentare $2^k$ valori distinti (da 0 a $2^k - 1$).</p>
        <ul>
            <li><strong>A) 3 bit:</strong> $2^3 = \mathbf{8}$ valori</li>
            <li><strong>B) 6 bit:</strong> $2^6 = \mathbf{64}$ valori</li>
            <li><strong>C) 10 bit:</strong> $2^{10} = \mathbf{1024}$ valori (la famosa "kilo" informatica)</li>
            <li><strong>D) 1 bit:</strong> $2^1 = \mathbf{2}$ valori (solo 0 e 1: perfetto per Vero/Falso)</li>
            <li><strong>E) 16 bit:</strong> $2^{16} = \mathbf{65.536}$ valori</li>
        </ul>
    </div>
</div>

---

## Tipologia 3: Codifica del mazzo di carte

Usa la codifica strutturata vista nella spiegazione (2 bit seme + 4 bit valore):

| Seme | Codice | Valore | Codice |
| :---: | :---: | :---: | :---: |
| ♠ | 00 | Asso | 0001 |
| ♥ | 01 | 2–9 | 0010–1001 |
| ♦ | 10 | 10 | 1010 |
| ♣ | 11 | Fante | 1011 |
| — | — | Donna | 1100 |
| — | — | Re | 1101 |

### Codifica di carte

Codifica le seguenti carte:
- **A)** Asso di ♠
- **B)** Re di ♥
- **C)** 5 di ♦
- **D)** Donna di ♣

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-carte-enc">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-carte-enc">
        <ul>
            <li><strong>A) Asso di ♠:</strong> seme ♠ = <code>00</code>, valore Asso = <code>0001</code> → <strong><code>000001</code></strong></li>
            <li><strong>B) Re di ♥:</strong> seme ♥ = <code>01</code>, valore Re = <code>1101</code> → <strong><code>011101</code></strong></li>
            <li><strong>C) 5 di ♦:</strong> seme ♦ = <code>10</code>, valore 5 = <code>0101</code> → <strong><code>100101</code></strong></li>
            <li><strong>D) Donna di ♣:</strong> seme ♣ = <code>11</code>, valore Donna = <code>1100</code> → <strong><code>111100</code></strong></li>
        </ul>
    </div>
</div>

---

### Decodifica di carte

Decodifica i seguenti codici binari (formato: 2 bit seme + 4 bit valore):
- **A)** `010111`
- **B)** `101011`
- **C)** `110011`
- **D)** `000010`

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-carte-dec">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-carte-dec">
        <ul>
            <li><strong>A) <code>01|0111</code>:</strong> seme <code>01</code> = ♥, valore <code>0111</code> = 7 → <strong>7 di ♥</strong></li>
            <li><strong>B) <code>10|1011</code>:</strong> seme <code>10</code> = ♦, valore <code>1011</code> = Fante → <strong>Fante di ♦</strong></li>
            <li><strong>C) <code>11|0011</code>:</strong> seme <code>11</code> = ♣, valore <code>0011</code> = 3 → <strong>3 di ♣</strong></li>
            <li><strong>D) <code>00|0010</code>:</strong> seme <code>00</code> = ♠, valore <code>0010</code> = 2 → <strong>2 di ♠</strong></li>
        </ul>
    </div>
</div>

---

## Tipologia 4: Inventare una propria codifica

### Codifica dei pianeti del sistema solare

Il sistema solare ha **8 pianeti** (Mercurio, Venere, Terra, Marte, Giove, Saturno, Urano, Nettuno).

- **A)** Quanti bit sono necessari per codificare tutti e 8 i pianeti?
- **B)** Proponi una codifica assegnando a ogni pianeta un codice binario (partendo da 0).
- **C)** Come codificheresti "Terra"? E "Nettuno"?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-pianeti">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-pianeti">
        <p><strong>A) Numero di bit necessari:</strong></p>
        <p>$2^2 = 4 &lt; 8 = 2^3$ → servono <strong>3 bit</strong> esatti (non si spreca nessun codice!).</p>
        <p><strong>B) Una possibile codifica:</strong></p>
        <ul>
            <li>Mercurio → <code>000</code></li>
            <li>Venere → <code>001</code></li>
            <li>Terra → <code>010</code></li>
            <li>Marte → <code>011</code></li>
            <li>Giove → <code>100</code></li>
            <li>Saturno → <code>101</code></li>
            <li>Urano → <code>110</code></li>
            <li>Nettuno → <code>111</code></li>
        </ul>
        <p><strong>C) Codici specifici:</strong></p>
        <ul>
            <li>Terra → <strong><code>010</code></strong></li>
            <li>Nettuno → <strong><code>111</code></strong></li>
        </ul>
    </div>
</div>

---

### Codifica dei semi delle carte italiane

Le carte italiane hanno **4 semi**: Coppe, Denari, Bastoni, Spade.
- **A)** Quanti bit servono per codificarli tutti?
- **B)** Proponi una codifica.
- **C)** Se aggiungessimo anche i 4 semi francesi (♠♥♦♣), in totale avremmo 8 semi diversi. Cambierebbe qualcosa nel numero di bit necessari?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-semi-italiani">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-semi-italiani">
        <p><strong>A) Bit necessari per 4 semi:</strong></p>
        <p>$2^1 = 2 &lt; 4 = 2^2$ → servono <strong>2 bit</strong> esatti.</p>
        <p><strong>B) Una possibile codifica:</strong></p>
        <ul>
            <li>Coppe → <code>00</code></li>
            <li>Denari → <code>01</code></li>
            <li>Bastoni → <code>10</code></li>
            <li>Spade → <code>11</code></li>
        </ul>
        <p><strong>C) Con 8 semi totali:</strong></p>
        <p>$8 = 2^3$ → servirebbero <strong>3 bit</strong>. Aggiungere 4 semi raddoppia le possibilità, quindi serve 1 bit in più.</p>
    </div>
</div>

---

## Tipologia 5: Unità di misura dell'informazione

:::tip[Riepilogo delle unità]
| Unità | Valore in byte | Valore in bit |
| :---: | ---: | ---: |
| 1 B | 1 | 8 |
| 1 kB | 1.000 | 8.000 |
| 1 MB | 1.000.000 | 8.000.000 |
| 1 GB | 1.000.000.000 | 8.000.000.000 |
| 1 KiB | 1.024 | 8.192 |
| 1 MiB | 1.048.576 | 8.388.608 |
| 1 GiB | 1.073.741.824 | 8.589.934.592 |
:::

### Conversioni dirette

Esegui le seguenti conversioni (esprimi il risultato con un numero ragionevole di cifre significative):
- **A)** 512 MB in kB, in byte, in bit
- **B)** 2 GiB in MiB, in byte
- **C)** 1,5 MB in kB e in kbit (kilobit)
- **D)** 4096 KiB in MiB
- **E)** 3,2 GB in MB

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-conv-dirette">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-conv-dirette">
        <ul>
            <li><strong>A) 512 MB:</strong><br />
                $512 \times 10^3 = 512.000 \, \text{kB}$<br />
                $512 \times 10^6 = 512.000.000 \, \text{B}$<br />
                $512 \times 10^6 \times 8 = 4.096.000.000 \, \text{bit} \approx 4{,}096 \, \text{Gbit}$
            </li>
            <li><strong>B) 2 GiB:</strong><br />
                $2 \times 2^{10} = 2048 \, \text{MiB}$<br />
                $2 \times 2^{30} = 2.147.483.648 \, \text{B} \approx 2{,}147 \times 10^9 \, \text{B}$
            </li>
            <li><strong>C) 1,5 MB:</strong><br />
                $1{,}5 \times 10^3 = 1500 \, \text{kB}$<br />
                $1{,}5 \times 10^6 \times 8 = 12.000.000 \, \text{bit} = 12.000 \, \text{kbit} = 12 \, \text{Mbit}$
            </li>
            <li><strong>D) 4096 KiB:</strong><br />
                $4096 \div 2^{10} = 4096 \div 1024 = \mathbf{4 \, \text{MiB}}$
            </li>
            <li><strong>E) 3,2 GB:</strong><br />
                $3{,}2 \times 10^3 = \mathbf{3200 \, \text{MB}}$
            </li>
        </ul>
    </div>
</div>

---

### Da MB a MiB (e viceversa)

Esegui le seguenti conversioni tra i due sistemi:
- **A)** 100 MB in MiB
- **B)** 256 MiB in MB
- **C)** 1,5 GB in GiB
- **D)** 1 TiB in TB

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-mb-mib">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-mb-mib">
        <ul>
            <li><strong>A) 100 MB in MiB:</strong><br />
                $\dfrac{100 \times 10^6}{2^{20}} = \dfrac{100.000.000}{1.048.576} \approx \mathbf{95{,}37 \, \text{MiB}}$
            </li>
            <li><strong>B) 256 MiB in MB:</strong><br />
                $\dfrac{256 \times 2^{20}}{10^6} = \dfrac{256 \times 1.048.576}{1.000.000} = \dfrac{268.435.456}{1.000.000} \approx \mathbf{268{,}4 \, \text{MB}}$
            </li>
            <li><strong>C) 1,5 GB in GiB:</strong><br />
                $\dfrac{1{,}5 \times 10^9}{2^{30}} = \dfrac{1.500.000.000}{1.073.741.824} \approx \mathbf{1{,}397 \, \text{GiB}}$
            </li>
            <li><strong>D) 1 TiB in TB:</strong><br />
                $\dfrac{1 \times 2^{40}}{10^{12}} = \dfrac{1.099.511.627.776}{1.000.000.000.000} \approx \mathbf{1{,}0995 \, \text{TB}}$
            </li>
        </ul>
    </div>
</div>

---

### Il paradosso del disco fisso

Un disco fisso viene venduto con la dicitura **"500 GB"**. Il sistema operativo mostra una dimensione diversa.
- **A)** Quanti byte contiene esattamente un disco da 500 GB (sistema decimale)?
- **B)** Quanti GiB corrisponde quella capacità?
- **C)** Di quanti GiB "manca" il disco rispetto ai 500 GiB che ti saresti aspettato?
- **D)** È una truffa? Spiega.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-disco">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-disco">
        <ul>
            <li><strong>A) Byte in 500 GB:</strong><br />
                $500 \times 10^9 = 500.000.000.000 \, \text{B}$
            </li>
            <li><strong>B) Conversione in GiB:</strong><br />
                $\dfrac{500.000.000.000}{2^{30}} = \dfrac{500.000.000.000}{1.073.741.824} \approx \mathbf{465{,}7 \, \text{GiB}}$
            </li>
            <li><strong>C) Differenza:</strong><br />
                $500 - 465{,}7 \approx \mathbf{34{,}3 \, \text{GiB}}$ in meno rispetto alle aspettative.
            </li>
            <li><strong>D) Truffa?</strong><br />
                No. Il produttore dichiara 500 GB decimali, che è esattamente quello che il disco contiene. Il sistema operativo converte quella quantità in GiB (binari) e mostra 465,7 GiB. Entrambi hanno ragione: usano unità di misura diverse.
            </li>
        </ul>
    </div>
</div>

---

### Bit e byte: conversioni miste

Negli esercizi sui file audio e video, le formule lavorano spesso in **bit** ma i risultati finali vanno in **MB o MiB**. Allenati con queste conversioni:
- **A)** $8.388.608$ bit in MiB
- **B)** $144.000.000$ bit in MB
- **C)** $1.440.000$ bit in kB
- **D)** $5.308.416.000$ bit in GB

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-bit-byte">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-bit-byte">
        <ul>
            <li><strong>A) $8.388.608$ bit in MiB:</strong><br />
                $8.388.608 \div 8 = 1.048.576 \, \text{B} = 2^{20} \, \text{B} = \mathbf{1 \, \text{MiB}}$
            </li>
            <li><strong>B) $144.000.000$ bit in MB:</strong><br />
                $144.000.000 \div 8 = 18.000.000 \, \text{B} = \mathbf{18 \, \text{MB}}$
            </li>
            <li><strong>C) $1.440.000$ bit in kB:</strong><br />
                $1.440.000 \div 8 = 180.000 \, \text{B} = \mathbf{180 \, \text{kB}}$
            </li>
            <li><strong>D) $5.308.416.000$ bit in GB:</strong><br />
                $5.308.416.000 \div 8 = 663.552.000 \, \text{B} = \mathbf{0{,}6636 \, \text{GB}} \approx 663{,}6 \, \text{MB}$
            </li>
        </ul>
    </div>
</div>

---

## Tipologia 6: Audio e Digitalizzazione

:::tip[Formule e regole utili]
$$\text{dimensione} = \text{sample rate} \times \text{bit depth} \times \text{canali} \times \text{durata}$$
$$\text{bitrate} = \text{sample rate} \times \text{bit depth} \times \text{canali}$$
$$\text{Teorema di Nyquist-Shannon:} \quad f_s \ge 2 \cdot f_{\text{max}}$$
Ricorda: **1 MB = 10⁶ B = 8×10⁶ bit** · **1 MiB = 2²⁰ B = 8×2²⁰ bit** · **1 B = 8 bit**
:::

### Frequenza di campionamento e Teorema di Nyquist

- **A)** La voce umana in una normale conversazione telefonica contiene frequenze significative fino a circa $3{,}4\text{ kHz}$ ($3400\text{ Hz}$). Qual è la frequenza di campionamento minima necessaria per digitalizzare la telefonata senza perdere informazioni? Perché nei sistemi telefonici digitali si usa tradizionalmente uno standard a $8000\text{ Hz}$?
- **B)** Un sensore sismico rileva vibrazioni del terreno fino a una frequenza massima di $50\text{ Hz}$. Qual è la frequenza di campionamento minima ($f_s$) richiesta per l'ADC?
- **C)** Se campioniamo un suono che ha una frequenza di $15\text{ kHz}$ usando una frequenza di campionamento di soli $20\text{ kHz}$, cosa succede? Come si chiama questo fenomeno?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-nyquist">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-nyquist">
        <ul>
            <li><strong>A) Voce telefonica ($f_{\text{max}} = 3400\text{ Hz}$):</strong><br />
                Per il Teorema di Nyquist-Shannon: $f_s \ge 2 \cdot f_{\text{max}} = 2 \times 3400\text{ Hz} = \mathbf{6800\text{ Hz}}$.<br />
                Lo standard telefonico a $8000\text{ Hz}$ ($8\text{ kHz}$) garantisce che $8000 > 6800\text{ Hz}$, lasciando un margine di sicurezza per i filtri analogici reali.
            </li>
            <li><strong>B) Sensore sismico ($f_{\text{max}} = 50\text{ Hz}$):</strong><br />
                $f_s \ge 2 \times 50\text{ Hz} = \mathbf{100\text{ Hz}}$ (almeno 100 campioni al secondo).
            </li>
            <li><strong>C) Campionamento a $20\text{ kHz}$ con suono a $15\text{ kHz}$ ($f_s < 2 \cdot f_{\text{max}}$):</strong><br />
                La frequenza minima richiesta sarebbe $2 \times 15 = 30\text{ kHz}$. Poiché $20\text{ kHz} < 30\text{ kHz}$, si verifica il fenomeno del <strong>sottocampionamento</strong> e della distorsione da <strong>Aliasing</strong>: l'onda a $15\text{ kHz}$ viene registrata erroneamente come una falsa frequenza a $20 - 15 = 5\text{ kHz}$, producendo un suono distorto.
            </li>
        </ul>
    </div>
</div>

---

### Riconoscere ADC e DAC nella vita quotidiana

Indica per ciascuna delle seguenti situazioni se entra in gioco un convertitore **ADC** (da analogico a digitale) o un **DAC** (da digitale ad analogico):
1. Invii una nota vocale su WhatsApp parlando al microfono dello smartphone.
2. Ascolti una canzone su Spotify con le cuffie wireless/cablate.
3. Scatti una fotografia con la fotocamera del telefono.
4. L'assistente vocale (es. Siri / Google Assistant) ti risponde a voce dall'altoparlante.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-adc-dac">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-adc-dac">
        <ol>
            <li><strong>Nota vocale al microfono:</strong> <strong>ADC</strong> (l'onda sonora della voce viene trasformata in dati binari).</li>
            <li><strong>Ascolto con le cuffie:</strong> <strong>DAC</strong> (i file digitali di Spotify vengono trasformati in segnale elettrico per far vibrare le cuffie).</li>
            <li><strong>Scatto di una foto:</strong> <strong>ADC</strong> (il sensore ottico converte la luce analogica incidente in pixel e numeri binari).</li>
            <li><strong>Risposta dall'altoparlante:</strong> <strong>DAC</strong> (il testo generato digitalmente viene convertito in suono udibile attraverso l'altoparlante).</li>
        </ol>
    </div>
</div>

---

### Dimensione di una canzone MP3

Vuoi scaricare una canzone che dura **2 minuti e 40 secondi**. Hai trovato diversi file MP3 ma non conosci la loro qualità: vedi solo nome e dimensione. Sai che la miglior qualità MP3 possibile prevede un **bitrate di 320 kbps** (la compressione è già inclusa nel bitrate).

Che dimensione deve avere il file con la codifica migliore?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-mp3-size">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-mp3-size">
        <p>Durata in secondi: $t = 2 \times 60 + 40 = 160 \, \text{s}$.</p>
        $$\text{dimensione} = 320 \, \frac{\text{kb}}{\text{s}} \times 160 \, \text{s} = 51.200 \, \text{kb} = \frac{51.200 \times 10^3 \, \text{b}}{8 \times 10^6 \, \text{b/MB}} = \mathbf{6{,}4 \, \text{MB}}$$
    </div>
</div>

---

### Musica FLAC ad alta qualità

Sei un audiofilo e vuoi ascoltare musica alla massima qualità. Le migliori registrazioni digitali prevedono un campionamento a **48 kHz** e **24 bit**. Il formato lossless FLAC riduce la dimensione dei file mediamente di **un terzo** (il file occupa i $\frac{2}{3}$ della dimensione originale). La musica deve essere **stereo** (2 canali).

Quanto occupa mediamente **un minuto** di musica in queste condizioni?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-flac">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-flac">
        $$\text{dim.} = \frac{48.000 \times 24 \times 2 \times \frac{2}{3} \times 60}{8 \times 10^6} \, \text{MB} = \frac{92.160.000}{8.000.000} = \mathbf{11{,}52 \, \text{MB}}$$
    </div>
</div>

---

### Trova la durata di una registrazione (1)

Devi registrare un file audio a **44,1 kHz** e **16 bit** in **stereo** (2 canali). Al termine, prima di qualsiasi compressione, il file occupa **27,5184 MB**. Quanto dura la registrazione?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-dur1">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-dur1">
        $$t = \frac{27{,}5184 \times 10^6 \times 8}{44.100 \times 16 \times 2} = \frac{220.147.200}{1.411.200} = \mathbf{156 \, \text{s}}$$
    </div>
</div>

---

### Trova la durata di una registrazione (2)

Un file audio **PCM stereo** a **44,1 kHz** e **16 bit** occupa **10,1 MB**. Quanto dura la registrazione?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-dur2">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-dur2">
        $$t = \frac{10{,}1 \times 10^6 \times 8}{44.100 \times 16 \times 2} = \frac{80.800.000}{1.411.200} \approx \mathbf{57{,}25 \, \text{s}}$$
    </div>
</div>

---

### Trova il sample rate

Hai un file audio **mono** che occupa **25,92 MB**. La registrazione dura **3 minuti** e la risoluzione di campionamento è **24 bit**. Qual è il sample rate?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-samplerate">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-samplerate">
        <p>Dimensione in bit: $25{,}92 \times 10^6 \times 8 = 207.360.000 \, \text{b}$. &nbsp; Durata: $180 \, \text{s}$.</p>
        $$\text{sample rate} = \frac{207.360.000}{24 \times 180} = 48.000 \, \text{Hz} = \mathbf{48 \, \text{kHz}}$$
    </div>
</div>

---

### Trova il bitrate di un MP3

Hai scaricato un brano MP3 da **4,5 MB** che dura **3 min 45 s**.
- **A)** Calcola il bitrate medio del file.
- **B)** Se la dimensione fosse stata **4,5 MiB**, il bitrate sarebbe un numero intero? Cosa puoi concludere?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-bitrate">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-bitrate">
        <p>Durata: $t = 3 \times 60 + 45 = 225 \, \text{s}$.</p>
        <p><strong>A) Con 4,5 MB:</strong></p>
        $$\text{bitrate} = \frac{4{,}5 \times 8 \times 10^6}{225} = \frac{36.000.000}{225} = 160.000 \, \frac{\text{b}}{\text{s}} = \mathbf{160 \, \text{kbps}}$$
        <p><strong>B) Con 4,5 MiB:</strong></p>
        $$4{,}5 \times 8 \times 1024 \times 1024 = 37.748.736 \, \text{b} \implies \text{bitrate} = \frac{37.748.736}{225} = 167.772{,}16 \, \frac{\text{b}}{\text{s}}$$
        <p>Il bitrate <strong>non è intero</strong>. I bitrate MP3 sono sempre interi (128, 160, 192, 320 kbps…), quindi un file da esattamente 4,5 MiB a questa durata non è possibile in pratica.</p>
    </div>
</div>

---

### Trova la profondità di campionamento (da revisionare)

Un registratore professionale registra in **stereo** a **96 kHz**. Una registrazione di **30 secondi**, non compressa, occupa **17,28 MB**. Quanti bit per campione usa il registratore?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-nuovo-bitdepth">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-nuovo-bitdepth">
        <p><strong>1. Ragionamento sulle grandezze</strong></p>
        <p>La dimensione del file si ottiene moltiplicando frequenza, profondità, canali e tempo. Conosco tutto tranne la profondità: quindi la trovo dividendo la dimensione (in bit) per il numero totale di campioni registrati, cioè frequenza $\times$ tempo $\times$ canali.</p>
        <p><strong>2. Ragionamento con le unità di misura</strong></p>
        <p>Voglio dei $\text{b/c}$. Ho la dimensione in $\text{MB}$, la frequenza in $\text{c/s}$, il tempo in $\text{s}$ e i canali. Porto la dimensione in bit:</p>
        $$17{,}28 \, \cancel{\text{MB}} \times \frac{10^6 \, \cancel{\text{B}}}{1 \, \cancel{\text{MB}}} \times \frac{8 \, \text{b}}{1 \, \cancel{\text{B}}} = 138.240.000 \, \text{b}$$
        <p>Moltiplicando $\text{c/s} \times \text{s}$ ottengo i campioni:</p>
        $$96.000 \, \frac{\text{c}}{\cancel{\text{s}}} \times 30 \, \cancel{\text{s}} \times 2 = 5.760.000 \, \text{c}$$
        <p>Dividendo i bit per i campioni ottengo i $\text{b/c}$:</p>
        $$\frac{138.240.000 \, \text{b}}{5.760.000 \, \text{c}} = \mathbf{24 \, b/c}$$
    </div>
</div>

---

### Trova il numero di canali (da revisionare)

Un film ha una traccia audio **surround** non compressa registrata a **48 kHz** e **16 bit**. Un minuto di questa traccia occupa circa **32,96 MiB**. Quanti canali audio ha la traccia?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-nuovo-canali">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-nuovo-canali">
        <p><strong>1. Ragionamento sulle grandezze</strong></p>
        <p>Calcolo quanto occuperebbe un minuto di audio con <strong>un solo canale</strong> (frequenza $\times$ profondità $\times$ tempo). La dimensione reale sarà un multiplo di questo valore: dividendo la dimensione reale per quella di un canale trovo il numero di canali.</p>
        <p><strong>2. Ragionamento con le unità di misura</strong></p>
        <p>Il numero di canali è un <strong>numero puro</strong>: devo quindi dividere due grandezze con la stessa unità ($\text{b}$ diviso $\text{b}$). Porto la dimensione in bit (attenzione: MiB!):</p>
        $$32{,}96 \, \cancel{\text{MiB}} \times \frac{2^{20} \, \cancel{\text{B}}}{1 \, \cancel{\text{MiB}}} \times \frac{8 \, \text{b}}{1 \, \cancel{\text{B}}} \approx 276.488.520 \, \text{b}$$
        <p>Bit occupati da un singolo canale in un minuto:</p>
        $$48.000 \, \frac{\cancel{\text{c}}}{\cancel{\text{s}}} \times 16 \, \frac{\text{b}}{\cancel{\text{c}}} \times 60 \, \cancel{\text{s}} = 46.080.000 \, \text{b}$$
        $$\text{canali} = \frac{276.488.520 \, \cancel{\text{b}}}{46.080.000 \, \cancel{\text{b}}} \approx \mathbf{6}$$
        <p>Si tratta di un audio <strong>5.1</strong> (5 diffusori più un subwoofer). Il risultato non è esattamente intero perché la dimensione nel testo è arrotondata.</p>
    </div>
</div>

---

### La telefonata digitale (da revisionare)

La telefonia digitale tradizionale campiona la voce a **8 kHz** con **8 bit** per campione, in **mono**.
- **A)** Qual è il bitrate di una telefonata, in kbps?
- **B)** Quanto occuperebbe la registrazione non compressa di una telefonata di **un'ora**, in MB e in MiB?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-nuovo-telefono">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-nuovo-telefono">
        <p><strong>1. Ragionamento sulle grandezze</strong></p>
        <p>A) Il bitrate è il numero di bit al secondo: si ottiene moltiplicando i campioni al secondo per i bit di ogni campione (e per i canali, qui 1). B) La dimensione è il bitrate moltiplicato per la durata.</p>
        <p><strong>2. Ragionamento con le unità di misura</strong></p>
        <p><strong>A)</strong> Voglio dei $\text{b/s}$: moltiplico $\text{c/s}$ per $\text{b/c}$.</p>
        $$8.000 \, \frac{\cancel{\text{c}}}{\text{s}} \times 8 \, \frac{\text{b}}{\cancel{\text{c}}} \times 1 = 64.000 \, \frac{\text{b}}{\text{s}} = \mathbf{64 \, kbps}$$
        <p><strong>B)</strong> Voglio dei $\text{b}$ (poi MB e MiB): moltiplico $\text{b/s}$ per $\text{s}$. Un'ora sono $3600 \, \text{s}$.</p>
        $$64.000 \, \frac{\text{b}}{\cancel{\text{s}}} \times 3600 \, \cancel{\text{s}} = 230.400.000 \, \text{b}$$
        $$230.400.000 \, \cancel{\text{b}} \times \frac{1 \, \cancel{\text{B}}}{8 \, \cancel{\text{b}}} \times \frac{1 \, \text{MB}}{10^6 \, \cancel{\text{B}}} = \mathbf{28{,}8 \, MB}$$
        $$28.800.000 \, \cancel{\text{B}} \times \frac{1 \, \text{MiB}}{2^{20} \, \cancel{\text{B}}} \approx \mathbf{27{,}47 \, MiB}$$
    </div>
</div>

---

### Quanto dura il podcast? (da revisionare)

Un episodio di un podcast in formato MP3 a **128 kbps** occupa **5 MiB**. Quanto dura l'episodio, in minuti e secondi?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-nuovo-podcast">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-nuovo-podcast">
        <p><strong>1. Ragionamento sulle grandezze</strong></p>
        <p>Il bitrate dice quanti bit vengono usati per ogni secondo. Se divido i bit totali del file per i bit usati in un secondo, ottengo quanti secondi dura il file.</p>
        <p><strong>2. Ragionamento con le unità di misura</strong></p>
        <p>Voglio dei $\text{s}$. Ho dei $\text{b}$ (la dimensione) e dei $\text{b/s}$ (il bitrate): $\text{b} \div \text{b/s} = \text{s}$. Porto la dimensione in bit:</p>
        $$5 \, \cancel{\text{MiB}} \times \frac{2^{20} \, \cancel{\text{B}}}{1 \, \cancel{\text{MiB}}} \times \frac{8 \, \text{b}}{1 \, \cancel{\text{B}}} = 41.943.040 \, \text{b}$$
        $$\frac{41.943.040 \, \cancel{\text{b}}}{128.000 \, \dfrac{\cancel{\text{b}}}{\text{s}}} = 327{,}68 \, \text{s} \approx \mathbf{5 \, min \; 28 \, s}$$
        <p>(Infatti $327{,}68 - 5 \times 60 = 27{,}68 \, \text{s}$.)</p>
    </div>
</div>

---

### Quante canzoni nella chiavetta? (da revisionare)

Hai una chiavetta USB da **16 GiB** e vuoi riempirla di canzoni in formato MP3 a **192 kbps**. Le canzoni durano in media **4 minuti**. Quante canzoni puoi caricare?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-nuovo-chiavetta">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-nuovo-chiavetta">
        <p><strong>1. Ragionamento sulle grandezze</strong></p>
        <p>Prima calcolo quanto occupa una canzone (bitrate $\times$ durata). Poi divido la capacità della chiavetta per lo spazio occupato da una canzone.</p>
        <p><strong>2. Ragionamento con le unità di misura</strong></p>
        <p>Spazio per una canzone: $\text{b/s} \times \text{s} = \text{b}$, cioè bit per ogni canzone. Durata: $4 \times 60 = 240 \, \text{s}$.</p>
        $$192.000 \, \frac{\text{b}}{\cancel{\text{s}}} \times 240 \, \cancel{\text{s}} = 46.080.000 \, \text{b} \quad \to \quad 46.080.000 \, \cancel{\text{b}} \times \frac{1 \, \text{B}}{8 \, \cancel{\text{b}}} = 5.760.000 \, \frac{\text{B}}{\text{canzone}}$$
        <p>Capacità della chiavetta (attenzione: GiB!):</p>
        $$16 \, \cancel{\text{GiB}} \times \frac{2^{30} \, \text{B}}{1 \, \cancel{\text{GiB}}} = 17.179.869.184 \, \text{B}$$
        <p>Voglio delle canzoni: $\text{B} \div \text{B/canzone} = \text{canzoni}$.</p>
        $$\frac{17.179.869.184 \, \cancel{\text{B}}}{5.760.000 \, \dfrac{\cancel{\text{B}}}{\text{canzone}}} \approx 2982{,}6 \, \text{canzoni} \quad \to \quad \mathbf{2982 \, canzoni}$$
        <p>Si arrotonda per difetto: l'ultima canzone non ci starebbe per intero.</p>
    </div>
</div>

---

### Qual è il suono più acuto registrato? (da revisionare)

Un file audio **mono** non compresso a **16 bit** dura **1 minuto** e occupa **2,88 MB**.
- **A)** Qual è la frequenza di campionamento?
- **B)** Qual è la frequenza sonora più alta che è stato possibile registrare senza aliasing? La registrazione è adatta alla musica?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-nuovo-fmax">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-nuovo-fmax">
        <p><strong>1. Ragionamento sulle grandezze</strong></p>
        <p>A) Se divido la dimensione in bit per i bit di ogni campione, ottengo il numero di campioni registrati; dividendo per la durata, ottengo i campioni al secondo. B) Per il Teorema di Nyquist-Shannon la frequenza di campionamento deve essere almeno il doppio della frequenza massima: quindi la frequenza massima è la metà della frequenza di campionamento.</p>
        <p><strong>2. Ragionamento con le unità di misura</strong></p>
        <p><strong>A)</strong> Voglio dei $\text{c/s}$. Porto la dimensione in bit: $2{,}88 \times 10^6 \times 8 = 23.040.000 \, \text{b}$. Poi $\text{b} \div \text{b/c} = \text{c}$, e $\text{c} \div \text{s} = \text{c/s}$:</p>
        $$\frac{23.040.000 \, \cancel{\text{b}}}{16 \, \dfrac{\cancel{\text{b}}}{\text{c}} \times 60 \, \text{s}} = 24.000 \, \frac{\text{c}}{\text{s}} = \mathbf{24 \, kHz}$$
        <p><strong>B)</strong> $f_{\text{max}} = \dfrac{f_s}{2} = \dfrac{24.000 \, \text{Hz}}{2} = \mathbf{12 \, kHz}$.</p>
        <p>La registrazione va bene per la voce, ma non per la musica ad alta qualità: l'orecchio umano sente fino a circa $20 \, \text{kHz}$, quindi i suoni più acuti (tra $12$ e $20 \, \text{kHz}$) sono andati persi.</p>
    </div>
</div>

---

## Tipologia 7: Immagini

:::tip[Formule utili]
$$\text{dimensione (bit)} = \text{larghezza} \times \text{altezza} \times \text{bpp}$$
Dividi per $8$ → byte · per $8 \times 10^3$ → kB · per $8 \times 10^6$ → MB · per $8 \times 2^{20}$ → MiB
:::

### Quanti colori?

Un'immagine **1920×1080 pixel** non compressa occupa **777,6 kB**. Quanti colori può avere al massimo?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-colori-fhd">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-colori-fhd">
        $$\text{bpp} = \frac{777{,}6 \times 10^3 \times 8}{1920 \times 1080} = \frac{6.220.800}{2.073.600} = 3 \, \text{bpp}$$
        $$\text{colori massimi} = 2^3 = \mathbf{8}$$
    </div>
</div>

---

### Immagine in bianco e nero quadrata

Un'immagine in **bianco e nero puro** (1 bit per pixel) occupa **80 kB**. L'immagine è **quadrata**: quanti pixel misura il lato?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-bnq">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-bnq">
        $$\text{pixel totali} = \frac{80 \times 10^3 \times 8}{1} = 640.000 \, \text{px} \implies \text{lato} = \sqrt{640.000} = \mathbf{800 \, \text{px}}$$
    </div>
</div>

---

### Immagine quadrata a 24 bpp (in MiB)

Un'immagine **quadrata** con colour depth di **24 bit** occupa **12 MiB**. Quanti pixel misura il lato? Indica anche la dimensione in MB.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-24bpp-mib">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-24bpp-mib">
        $$\text{pixel totali} = \frac{12 \times 2^{20} \times 8}{24} = 4.194.304 \, \text{px} \implies \text{lato} = \sqrt{4.194.304} = \mathbf{2048 \, \text{px}}$$
        $$\text{in MB} = \frac{12 \times 2^{20} \times 8}{8 \times 10^6} = \mathbf{12{,}582912 \, \text{MB}}$$
    </div>
</div>

---

### File RAW della fotocamera

Un file immagine RAW **4000×3000 pixel** occupa **36 MB**. Qual è il colour depth del sensore? Quanti colori può rappresentare?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-raw">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-raw">
        $$\text{bpp} = \frac{36 \times 10^6 \times 8}{4000 \times 3000} = \frac{288.000.000}{12.000.000} = \mathbf{24 \, \text{bpp}}$$
        $$\text{colori} = 2^{24} = \mathbf{16.777.216} \approx 16{,}7 \, \text{milioni} \quad \text{(RGB True Color)}$$
    </div>
</div>

---

### Immagine in scala di grigi (in MiB)

Un'immagine occupa **2,25 MiB**, è **quadrata** e usa **8 bit per pixel**. Quanti pixel misura il lato?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-grigio-mib">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-grigio-mib">
        $$\text{pixel totali} = \frac{2{,}25 \times 2^{20} \times 8}{8} = 2{,}25 \times 1.048.576 = 2.359.296 \, \text{px}$$
        $$\text{lato} = \sqrt{2.359.296} = \mathbf{1536 \, \text{px}}$$
    </div>
</div>

---

### Trova la larghezza di uno screenshot (da revisionare)

Uno schermo "ultrawide" è alto **1080 px**. Uno screenshot non compresso dello schermo, a **24 bpp**, occupa **8100 KiB**. Quanto è largo lo schermo, in pixel?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-nuovo-ultrawide">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-nuovo-ultrawide">
        <p><strong>1. Ragionamento sulle grandezze</strong></p>
        <p>Se divido i bit totali dell'immagine per i bit di ogni pixel, ottengo il numero di pixel. Il numero di pixel è larghezza $\times$ altezza: conoscendo l'altezza, la larghezza si trova dividendo il numero di pixel per l'altezza.</p>
        <p><strong>2. Ragionamento con le unità di misura</strong></p>
        <p>Porto la dimensione in bit (attenzione: KiB!):</p>
        $$8100 \, \cancel{\text{KiB}} \times \frac{1024 \, \cancel{\text{B}}}{1 \, \cancel{\text{KiB}}} \times \frac{8 \, \text{b}}{1 \, \cancel{\text{B}}} = 66.355.200 \, \text{b}$$
        <p>Voglio dei $\text{px}$: $\text{b} \div \text{b/px} = \text{px}$.</p>
        $$\frac{66.355.200 \, \cancel{\text{b}}}{24 \, \dfrac{\cancel{\text{b}}}{\text{px}}} = 2.764.800 \, \text{px}$$
        $$\text{larghezza} = \frac{2.764.800}{1080} = \mathbf{2560 \, px}$$
        <p>Lo schermo ha risoluzione $2560 \times 1080$.</p>
    </div>
</div>

---

### Un'immagine con pochi colori (da revisionare)

Un'immagine di **800×600 pixel** contiene **200 colori** diversi. Usando il minor numero possibile di bit per pixel (con lo stesso numero di bit per tutti i pixel), quanto occupa l'immagine non compressa, in KiB?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-nuovo-200colori">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-nuovo-200colori">
        <p><strong>1. Ragionamento sulle grandezze</strong></p>
        <p>Prima trovo quanti bit servono per distinguere 200 colori: cerco la più piccola potenza di 2 che è almeno 200. Con 7 bit ho $2^7 = 128$ colori (non bastano), con 8 bit ho $2^8 = 256$ colori (bastano). Quindi servono <strong>8 bit per pixel</strong>. Poi la dimensione è il numero di pixel per i bit di ogni pixel.</p>
        <p><strong>2. Ragionamento con le unità di misura</strong></p>
        <p>Voglio dei $\text{KiB}$. Ho dei $\text{px}$ e dei $\text{b/px}$: moltiplicando ottengo bit, poi converto.</p>
        $$800 \times 600 \, \cancel{\text{px}} \times 8 \, \frac{\cancel{\text{b}}}{\cancel{\text{px}}} \times \frac{1 \, \cancel{\text{B}}}{8 \, \cancel{\text{b}}} \times \frac{1 \, \text{KiB}}{1024 \, \cancel{\text{B}}} = \frac{480.000}{1024} \, \text{KiB} = \mathbf{468{,}75 \, KiB}$$
    </div>
</div>

---

### Quante foto nella scheda di memoria? (da revisionare)

Una fotocamera scatta foto RAW da **6000×4000 pixel** a **24 bpp** (non compresse). Quante foto si possono salvare in una scheda di memoria da **64 GiB**?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-nuovo-sd">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-nuovo-sd">
        <p><strong>1. Ragionamento sulle grandezze</strong></p>
        <p>Prima calcolo quanto occupa una foto (pixel $\times$ bit per pixel). Poi divido la capacità della scheda per lo spazio occupato da una foto.</p>
        <p><strong>2. Ragionamento con le unità di misura</strong></p>
        <p>Spazio per una foto: $\text{px} \times \text{b/px} = \text{b}$, poi in byte.</p>
        $$6000 \times 4000 \, \cancel{\text{px}} \times 24 \, \frac{\cancel{\text{b}}}{\cancel{\text{px}}} \times \frac{1 \, \text{B}}{8 \, \cancel{\text{b}}} = 72.000.000 \, \frac{\text{B}}{\text{foto}}$$
        <p>Capacità della scheda (attenzione: GiB!):</p>
        $$64 \, \cancel{\text{GiB}} \times \frac{2^{30} \, \text{B}}{1 \, \cancel{\text{GiB}}} = 68.719.476.736 \, \text{B}$$
        <p>Voglio delle foto: $\text{B} \div \text{B/foto} = \text{foto}$.</p>
        $$\frac{68.719.476.736 \, \cancel{\text{B}}}{72.000.000 \, \dfrac{\cancel{\text{B}}}{\text{foto}}} \approx 954{,}4 \, \text{foto} \quad \to \quad \mathbf{954 \, foto}$$
    </div>
</div>

---

### Quanti megapixel ha la fotocamera? (da revisionare)

Una foto in formato JPEG occupa **3,6 MB**. Sai che la compressione JPEG ha ridotto la dimensione di **10 volte** rispetto all'immagine originale a **24 bpp**. Quanti megapixel ha la fotocamera?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-nuovo-megapixel">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-nuovo-megapixel">
        <p><strong>1. Ragionamento sulle grandezze</strong></p>
        <p>La compressione ha diviso la dimensione per 10: per risalire all'immagine originale devo quindi <strong>moltiplicare</strong> per 10. Poi, dividendo i bit dell'immagine originale per i bit di ogni pixel, trovo il numero di pixel.</p>
        <p><strong>2. Ragionamento con le unità di misura</strong></p>
        <p>Il fattore di compressione è un numero puro, quindi non cambia l'unità: $3{,}6 \, \text{MB} \times 10 = 36 \, \text{MB}$ (immagine originale). Porto in bit:</p>
        $$36 \, \cancel{\text{MB}} \times \frac{10^6 \, \cancel{\text{B}}}{1 \, \cancel{\text{MB}}} \times \frac{8 \, \text{b}}{1 \, \cancel{\text{B}}} = 288.000.000 \, \text{b}$$
        <p>Voglio dei $\text{px}$: $\text{b} \div \text{b/px} = \text{px}$.</p>
        $$\frac{288.000.000 \, \cancel{\text{b}}}{24 \, \dfrac{\cancel{\text{b}}}{\text{px}}} = 12.000.000 \, \text{px} = \mathbf{12 \, Mpx}$$
    </div>
</div>

---

### Trova la risoluzione di un'immagine 16:9 (da revisionare)

Un'immagine non compressa a **24 bpp** occupa **6,2208 MB** e ha proporzioni **16:9** (cioè larghezza e altezza stanno nel rapporto 16 a 9). Qual è la sua risoluzione?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-nuovo-169">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-nuovo-169">
        <p><strong>1. Ragionamento sulle grandezze</strong></p>
        <p>Dividendo i bit dell'immagine per i bit di ogni pixel trovo il numero di pixel. Poi uso le proporzioni: larghezza $= 16 \times k$ e altezza $= 9 \times k$ per un certo numero $k$, quindi il numero di pixel è $16k \times 9k = 144 \, k^2$.</p>
        <p><strong>2. Ragionamento con le unità di misura</strong></p>
        <p>Porto la dimensione in bit: $6{,}2208 \times 10^6 \times 8 = 49.766.400 \, \text{b}$. Voglio dei $\text{px}$: $\text{b} \div \text{b/px} = \text{px}$.</p>
        $$\frac{49.766.400 \, \cancel{\text{b}}}{24 \, \dfrac{\cancel{\text{b}}}{\text{px}}} = 2.073.600 \, \text{px}$$
        <p>Le proporzioni sono uno dei casi in cui le unità non bastano e serve un passaggio algebrico:</p>
        $$144 \, k^2 = 2.073.600 \implies k^2 = 14.400 \implies k = 120$$
        $$\text{larghezza} = 16 \times 120 = 1920 \, \text{px} \qquad \text{altezza} = 9 \times 120 = 1080 \, \text{px}$$
        <p>La risoluzione è $\mathbf{1920 \times 1080}$ (Full HD).</p>
    </div>
</div>

---

### Quanto comprime il PNG? (da revisionare)

Uno screenshot di **1024×768 pixel** a **24 bpp** viene salvato in formato PNG (compressione *lossless*) e occupa **768 KiB**. Qual è il fattore di compressione ottenuto?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-nuovo-png">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-nuovo-png">
        <p><strong>1. Ragionamento sulle grandezze</strong></p>
        <p>Calcolo quanto occuperebbe l'immagine non compressa (pixel $\times$ bit per pixel). Il fattore di compressione indica quante volte il file compresso è più piccolo dell'originale: si trova dividendo la dimensione originale per quella compressa.</p>
        <p><strong>2. Ragionamento con le unità di misura</strong></p>
        <p>Dimensione originale, portata in KiB per poterla confrontare con quella del PNG:</p>
        $$1024 \times 768 \, \cancel{\text{px}} \times 24 \, \frac{\cancel{\text{b}}}{\cancel{\text{px}}} \times \frac{1 \, \cancel{\text{B}}}{8 \, \cancel{\text{b}}} \times \frac{1 \, \text{KiB}}{1024 \, \cancel{\text{B}}} = 2304 \, \text{KiB}$$
        <p>Il fattore è un numero puro: divido due grandezze con la stessa unità.</p>
        $$\frac{2304 \, \cancel{\text{KiB}}}{768 \, \cancel{\text{KiB}}} = \mathbf{3} \quad \text{(compressione 1:3)}$$
        <p>È un valore tipico della compressione <em>lossless</em>, che riduce i file di circa 1,5–3 volte.</p>
    </div>
</div>

---

## Tipologia 8: Video

:::tip[Formule utili]
$$\text{bitrate video} = \text{larghezza} \times \text{altezza} \times \text{bpp} \times \text{fps}$$
$$\text{dimensione video} = \text{bitrate} \times \text{durata (s)}$$
:::

### Bitrate di un video 4K HDR

Calcola il **bitrate** (in Mb/s) di un video **4K** ($3840 \times 2160$ px), **60 fps**, **10 bit per canale** RGB (HDR). Il codec riduce la dimensione di **25 volte**. Ignora l'audio.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-4k-hdr">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-4k-hdr">
        <p>$10 \, \text{bit/canale} \times 3 \, \text{canali} = 30 \, \text{bpp}$.</p>
        $$\text{bitrate raw} = 3840 \times 2160 \times 30 \times 60 = 14.929.920.000 \, \frac{\text{b}}{\text{s}} \approx 14{,}93 \, \text{Gb/s}$$
        $$\text{bitrate compresso} = \frac{14.929.920.000}{25} \approx \mathbf{597 \, \text{Mb/s}}$$
    </div>
</div>

---

### Trova il colour depth di un video

Hai un video senza audio che occupa **$D$ MB**, risoluzione **$1280 \times 720$**, frame rate **24 fps**, durata **$t$ secondi**. Calcola bpp e numero di colori.

:::note[Esercizio parametrico]
I valori di $D$ e $t$ vengono assegnati dall'insegnante. La procedura è sempre la stessa.
:::

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-video-bpp">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-video-bpp">
        $$\text{bpp} = \frac{D \times 10^6 \times 8}{1280 \times 720 \times 24 \times t}$$
        <p><strong>Esempio</strong> — $D = 663{,}552 \, \text{MB}$, $t = 30 \, \text{s}$:</p>
        $$\text{bpp} = \frac{663{,}552 \times 10^6 \times 8}{1280 \times 720 \times 24 \times 30} = \frac{5.308.416.000}{663.552.000} = 8 \, \text{bpp} \implies 2^8 = 256 \, \text{colori}$$
    </div>
</div>

---

### Colour depth da dimensione e risoluzione

Un video non compresso dura **5 secondi**, risoluzione **1920×1080 px**, **60 fps**, occupa **2,1729 GiB**. Calcola bpp e numero di colori.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-video-gib">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-video-gib">
        $$\text{dimensione in bit} = 2{,}1729 \times 2^{30} \times 8 \approx 18.665.076.000 \, \text{b}$$
        $$\text{pixel totali} = 1920 \times 1080 \times 60 \times 5 = 622.080.000$$
        $$\text{bpp} = \frac{18.665.076.000}{622.080.000} \approx \mathbf{30 \, \text{bpp}} \implies \text{colori} = 2^{30} \approx \mathbf{10^9}$$
        <p>(10 bit per canale RGB — formato HDR.)</p>
    </div>
</div>

---

### Quanto dura il video? (da revisionare)

Un video **Full HD** ($1920 \times 1080$) a **24 bpp** e **25 fps**, non compresso e senza audio, occupa **4,6656 GB**. Quanto dura?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-nuovo-durata-video">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-nuovo-durata-video">
        <p><strong>1. Ragionamento sulle grandezze</strong></p>
        <p>Calcolo il bitrate, cioè quanti bit servono per ogni secondo di video: pixel di un frame $\times$ bit per pixel $\times$ frame al secondo. Poi divido i bit totali del file per il bitrate e ottengo i secondi.</p>
        <p><strong>2. Ragionamento con le unità di misura</strong></p>
        <p>Bitrate: $\text{px/frame} \times \text{b/px} \times \text{frame/s} = \text{b/s}$.</p>
        $$1920 \times 1080 \, \frac{\cancel{\text{px}}}{\cancel{\text{frame}}} \times 24 \, \frac{\text{b}}{\cancel{\text{px}}} \times 25 \, \frac{\cancel{\text{frame}}}{\text{s}} = 1.244.160.000 \, \frac{\text{b}}{\text{s}}$$
        <p>Dimensione in bit: $4{,}6656 \times 10^9 \times 8 = 37.324.800.000 \, \text{b}$. Voglio dei $\text{s}$: $\text{b} \div \text{b/s} = \text{s}$.</p>
        $$\frac{37.324.800.000 \, \cancel{\text{b}}}{1.244.160.000 \, \dfrac{\cancel{\text{b}}}{\text{s}}} = \mathbf{30 \, s}$$
    </div>
</div>

---

### Il rallentatore (da revisionare)

Uno smartphone registra **2 secondi** di video al rallentatore in risoluzione **1280×720** a **24 bpp**. Il video non compresso occupa **1,327104 GB**.
- **A)** A quanti fps ha registrato lo smartphone?
- **B)** Se il video viene riprodotto a **30 fps**, quanto dura la riproduzione?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-nuovo-slowmo">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-nuovo-slowmo">
        <p><strong>1. Ragionamento sulle grandezze</strong></p>
        <p>A) Calcolo quanto pesa un frame (pixel $\times$ bit per pixel). Dividendo la dimensione totale per il peso di un frame trovo il numero di frame registrati; dividendo per la durata trovo i frame al secondo. B) Riproducendo gli stessi frame a una velocità più bassa, il video dura di più: la durata si trova dividendo il numero di frame per il nuovo frame rate.</p>
        <p><strong>2. Ragionamento con le unità di misura</strong></p>
        <p><strong>A)</strong> Peso di un frame: $\text{px/frame} \times \text{b/px} = \text{b/frame}$.</p>
        $$1280 \times 720 \, \frac{\cancel{\text{px}}}{\text{frame}} \times 24 \, \frac{\text{b}}{\cancel{\text{px}}} = 22.118.400 \, \frac{\text{b}}{\text{frame}}$$
        <p>Dimensione in bit: $1{,}327104 \times 10^9 \times 8 = 10.616.832.000 \, \text{b}$. Numero di frame: $\text{b} \div \text{b/frame} = \text{frame}$.</p>
        $$\frac{10.616.832.000 \, \cancel{\text{b}}}{22.118.400 \, \dfrac{\cancel{\text{b}}}{\text{frame}}} = 480 \, \text{frame} \qquad \frac{480 \, \text{frame}}{2 \, \text{s}} = \mathbf{240 \, frame/s}$$
        <p><strong>B)</strong> Voglio dei $\text{s}$: $\text{frame} \div \text{frame/s} = \text{s}$.</p>
        $$\frac{480 \, \cancel{\text{frame}}}{30 \, \dfrac{\cancel{\text{frame}}}{\text{s}}} = \mathbf{16 \, s}$$
        <p>I 2 secondi reali vengono mostrati in 16 secondi: il video è rallentato di 8 volte.</p>
    </div>
</div>

---

### Un film in streaming (da revisionare)

Una piattaforma di streaming trasmette i film in 4K con un bitrate (già compresso) di **15 Mbps**. Quanto spazio occupa un film di **2 ore**, in GB e in GiB?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-nuovo-streaming">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-nuovo-streaming">
        <p><strong>1. Ragionamento sulle grandezze</strong></p>
        <p>Il bitrate indica quanti bit arrivano ogni secondo: moltiplicandolo per la durata in secondi ottengo i bit totali del film. Non serve conoscere risoluzione, colori o fps, perché sono già "contenuti" nel bitrate.</p>
        <p><strong>2. Ragionamento con le unità di misura</strong></p>
        <p>Voglio dei $\text{GB}$: $\text{b/s} \times \text{s} = \text{b}$, poi converto. Durata: $2 \times 3600 = 7200 \, \text{s}$; bitrate: $15 \, \text{Mb/s} = 15.000.000 \, \text{b/s}$.</p>
        $$15.000.000 \, \frac{\text{b}}{\cancel{\text{s}}} \times 7200 \, \cancel{\text{s}} = 108.000.000.000 \, \text{b}$$
        $$108 \times 10^9 \, \cancel{\text{b}} \times \frac{1 \, \cancel{\text{B}}}{8 \, \cancel{\text{b}}} \times \frac{1 \, \text{GB}}{10^9 \, \cancel{\text{B}}} = \mathbf{13{,}5 \, GB}$$
        $$13.500.000.000 \, \cancel{\text{B}} \times \frac{1 \, \text{GiB}}{2^{30} \, \cancel{\text{B}}} \approx \mathbf{12{,}57 \, GiB}$$
    </div>
</div>

---

### Quanto comprime lo streaming? (da revisionare)

Un video **Full HD** ($1920 \times 1080$) a **30 fps** e **24 bpp** viene trasmesso in streaming con un bitrate di **8 Mbps**. Di quante volte è stato compresso rispetto al video originale?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-nuovo-fattore-video">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-nuovo-fattore-video">
        <p><strong>1. Ragionamento sulle grandezze</strong></p>
        <p>Calcolo il bitrate del video non compresso (pixel $\times$ bit per pixel $\times$ fps) e lo confronto con quello dello streaming: il fattore di compressione è il rapporto tra i due.</p>
        <p><strong>2. Ragionamento con le unità di misura</strong></p>
        <p>Bitrate originale: $\text{px/frame} \times \text{b/px} \times \text{frame/s} = \text{b/s}$.</p>
        $$1920 \times 1080 \, \frac{\cancel{\text{px}}}{\cancel{\text{frame}}} \times 24 \, \frac{\text{b}}{\cancel{\text{px}}} \times 30 \, \frac{\cancel{\text{frame}}}{\text{s}} = 1.492.992.000 \, \frac{\text{b}}{\text{s}}$$
        <p>Il fattore è un numero puro: divido due bitrate (entrambi in $\text{b/s}$).</p>
        $$\frac{1.492.992.000 \, \cancel{\text{b/s}}}{8.000.000 \, \cancel{\text{b/s}}} \approx \mathbf{187}$$
        <p>Lo streaming trasmette circa 187 volte meno dati del video originale!</p>
    </div>
</div>

---

### Video con audio (da revisionare)

Un video di **1 minuto** in risoluzione **1280×720**, **24 bpp** e **25 fps**, non compresso, è accompagnato da una traccia audio non compressa in qualità CD (**44,1 kHz**, **16 bit**, **stereo**).
- **A)** Quanto occupa in totale il file, in GiB?
- **B)** Quale percentuale dello spazio è occupata dall'audio?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-nuovo-video-audio">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-nuovo-video-audio">
        <p><strong>1. Ragionamento sulle grandezze</strong></p>
        <p>Video e audio si calcolano separatamente e poi si sommano. Per il video: pixel $\times$ bit per pixel $\times$ fps $\times$ durata. Per l'audio: frequenza $\times$ profondità $\times$ canali $\times$ durata. La percentuale è il rapporto tra audio e totale, moltiplicato per 100.</p>
        <p><strong>2. Ragionamento con le unità di misura</strong></p>
        <p><strong>A)</strong> Video: $\text{px/frame} \times \text{b/px} \times \text{frame/s} \times \text{s} = \text{b}$.</p>
        $$1280 \times 720 \, \frac{\cancel{\text{px}}}{\cancel{\text{frame}}} \times 24 \, \frac{\text{b}}{\cancel{\text{px}}} \times 25 \, \frac{\cancel{\text{frame}}}{\cancel{\text{s}}} \times 60 \, \cancel{\text{s}} = 33.177.600.000 \, \text{b}$$
        <p>Audio: $\text{c/s} \times \text{b/c} \times \text{canali} \times \text{s} = \text{b}$.</p>
        $$44.100 \, \frac{\cancel{\text{c}}}{\cancel{\text{s}}} \times 16 \, \frac{\text{b}}{\cancel{\text{c}}} \times 2 \times 60 \, \cancel{\text{s}} = 84.672.000 \, \text{b}$$
        <p>Totale: $33.177.600.000 + 84.672.000 = 33.262.272.000 \, \text{b}$.</p>
        $$33.262.272.000 \, \cancel{\text{b}} \times \frac{1 \, \cancel{\text{B}}}{8 \, \cancel{\text{b}}} \times \frac{1 \, \text{GiB}}{2^{30} \, \cancel{\text{B}}} \approx \mathbf{3{,}87 \, GiB}$$
        <p><strong>B)</strong> La percentuale è un numero puro: divido due grandezze in bit.</p>
        $$\frac{84.672.000 \, \cancel{\text{b}}}{33.262.272.000 \, \cancel{\text{b}}} \times 100 \approx \mathbf{0{,}25\%}$$
        <p>L'audio occupa una parte trascurabile del file: quasi tutto lo spazio è occupato dalle immagini.</p>
    </div>
</div>

---

### Quanto tempo per scaricare il film? (da revisionare)

Vuoi scaricare il film dell'esercizio "Un film in streaming", che occupa **13,5 GB**. La tua connessione internet ha una velocità di **100 Mbps**. Quanto tempo serve per il download?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-nuovo-download">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-nuovo-download">
        <p><strong>1. Ragionamento sulle grandezze</strong></p>
        <p>La velocità della connessione è anch'essa un bitrate: indica quanti bit si scaricano ogni secondo. Dividendo i bit totali del film per i bit scaricati in un secondo, ottengo i secondi necessari.</p>
        <p><strong>2. Ragionamento con le unità di misura</strong></p>
        <p>Voglio dei $\text{s}$: $\text{b} \div \text{b/s} = \text{s}$. Porto il film in bit:</p>
        $$13{,}5 \, \cancel{\text{GB}} \times \frac{10^9 \, \cancel{\text{B}}}{1 \, \cancel{\text{GB}}} \times \frac{8 \, \text{b}}{1 \, \cancel{\text{B}}} = 108.000.000.000 \, \text{b}$$
        $$\frac{108.000.000.000 \, \cancel{\text{b}}}{100.000.000 \, \dfrac{\cancel{\text{b}}}{\text{s}}} = 1080 \, \text{s} = \mathbf{18 \, min}$$
        <p>Attenzione: la velocità delle connessioni è in <strong>bit</strong> al secondo (Mbps), non in byte!</p>
    </div>
</div>

---

## Tipologia 9: Inventare codifiche per i giochi

Questi esercizi sono aperti: non esiste un'unica risposta corretta. Valuta la tua soluzione in termini di **completezza**, **non ambiguità** e **leggibilità**.

### Codifica del Tris

Il **Tris** si gioca su una griglia **3×3**. I giocatori si alternano (X e O).
- **A)** Quante mosse diverse esistono? Quanti bit bastano?
- **B)** Progetta una codifica **strutturata** dividendo i bit in campi (es. riga + colonna).
- **C)** Rappresenta: X in alto a sinistra → O al centro → X in basso a destra.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-tris">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-tris">
        <p><strong>A)</strong> La griglia ha 9 celle → 9 mosse possibili. $2^3 = 8 &lt; 9 \leq 16 = 2^4$ → <strong>4 bit</strong>.</p>
        <p><strong>B) Codifica riga+colonna (2 bit + 2 bit):</strong></p>
        <ul>
            <li>Righe: 1→<code>00</code>, 2→<code>01</code>, 3→<code>10</code> &nbsp; Colonne: 1→<code>00</code>, 2→<code>01</code>, 3→<code>10</code></li>
            <li>Formato: <code>[riga][colonna]</code>. I giocatori si alternano → non serve codificare chi gioca.</li>
        </ul>
        <pre>
         Col.1(00) Col.2(01) Col.3(10)
Riga1(00)   0000     0001     0010
Riga2(01)   0100     0101     0110
Riga3(10)   1000     1001     1010</pre>
        <p><strong>C)</strong> X(alto-sin.) → <strong><code>0000</code></strong> · O(centro) → <strong><code>0101</code></strong> · X(basso-des.) → <strong><code>1010</code></strong></p>
        <p>Sequenza: <code>0000 0101 1010</code></p>
    </div>
</div>

---

### Codifica di Forza 4

**Forza 4** si gioca su griglia **6×7**. Il disco cade sempre alla posizione più bassa libera nella colonna scelta.
- **A)** Quante mosse diverse in un turno? Quanti bit bastano?
- **B)** Proponi la codifica più compatta.
- **C)** Perché Forza 4 è **più semplice** da codificare del Tris, pur avendo una griglia più grande?
- **D)** Rappresenta: Rosso col. 4 → Giallo col. 4 → Rosso col. 3.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-forza4">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-forza4">
        <p><strong>A)</strong> Si sceglie solo la colonna: 7 scelte. $2^2 = 4 &lt; 7 \leq 8 = 2^3$ → <strong>3 bit</strong>.</p>
        <p><strong>B) Codifica colonne 1–7:</strong><br />
        Col.1→<code>001</code> · Col.2→<code>010</code> · Col.3→<code>011</code> · Col.4→<code>100</code> · Col.5→<code>101</code> · Col.6→<code>110</code> · Col.7→<code>111</code></p>
        <p><strong>C)</strong> Nel Tris il giocatore sceglie liberamente <em>due</em> coordinate (riga+colonna) → 4 bit. In Forza 4 la riga è determinata dalla gravità: basta <em>una</em> coordinata → 3 bit. La struttura del gioco riduce l'informazione da codificare.</p>
        <p><strong>D)</strong> Rosso col.4 → <strong><code>100</code></strong> · Giallo col.4 → <strong><code>100</code></strong> · Rosso col.3 → <strong><code>011</code></strong></p>
        <p>Sequenza: <code>100 100 011</code>. Lo stesso codice per le prime due mosse non è ambiguo: l'ordine indica chi ha giocato.</p>
    </div>
</div>

