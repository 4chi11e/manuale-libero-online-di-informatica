---
title: "Esercizi sulle Conversioni Numeriche"
description: "Raccolta di problemi ed esercitazioni pratiche con soluzioni a comparsa su interi positivi, numeri frazionari, complemento a 2 e overflow."
---

In questa pagina puoi metterti alla prova con una serie di problemi ed esercizi di diversa complessità. 

Tutte le soluzioni sono **nascoste per impostazione predefinita**: prova prima a risolverli su carta o a mente, poi clicca su ciascun riquadro per confrontare il tuo risultato con lo svolgimento completo.

:::tip[Strumento Interattivo per le Conversioni]
Vuoi generare nuovi esercizi casuali o verificare immediatamente un passaggio?  
Utilizza lo **[Strumento Interattivo per le Conversioni Numeriche](https://4chi11e.github.io/conversioni-numeriche/)**, che mostra in tempo reale tabelle, divisioni successive e grafici dettagliati per qualsiasi base numerica.
:::

---

## Tipologia 1: Interi Positivi e Sistemi di Numerazione

### Da Binario a Decimale (Calcolo dei Pesi)
Converti i seguenti numeri binari nel corrispondente valore decimale:
- **A)** $(10110)_2$
- **B)** $(1101101)_2$
- **C)** $(11111111)_2$ (un byte completo a tutti bit 1)

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-interi-bin2dec">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-interi-bin2dec">
        <p><strong>Somma delle potenze accese:</strong></p>
        <ul>
            <li><strong>A) $(10110)_2$:</strong><br />
                $16 + 4 + 2 = \mathbf{22}_{10}$.
            </li>
            <li><strong>B) $(1101101)_2$:</strong><br />
                $64 + 32 + 8 + 4 + 1 = \mathbf{109}_{10}$.
            </li>
            <li><strong>C) $(11111111)_2$:</strong><br />
                $128 + 64 + 32 + 16 + 8 + 4 + 2 + 1 = 2^8 - 1 = \mathbf{255}_{10}$.
            </li>
        </ul>
    </div>
</div>

---

### Da Decimale a Binario: Confronto tra Metodi
Converti i seguenti numeri decimali in binario scegliendo la strategia più rapida ed efficiente:
- **A)** $156_{10}$ *(numero medio-piccolo: provalo con il metodo intuitivo)*
- **B)** $1350_{10}$ *(numero grande: valuta le divisioni per 2 o il passaggio per l'esadecimale)*

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-interi-dec2bin">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-interi-dec2bin">
        <ul>
            <li><strong>A) $156_{10}$ (Risoluzione rapida con il Metodo Intuitivo delle Potenze):</strong><br />
                Massima potenza contenuta: $128$.
                <ul>
                    <li>$156 - 128 = 28 \implies$ colonna $128 \to \mathbf{1}$</li>
                    <li>$28 < 64 \implies$ colonna $64 \to \mathbf{0}$</li>
                    <li>$28 < 32 \implies$ colonna $32 \to \mathbf{0}$</li>
                    <li>$28 - 16 = 12 \implies$ colonna $16 \to \mathbf{1}$</li>
                    <li>$12 - 8 = 4 \implies$ colonna $8 \to \mathbf{1}$</li>
                    <li>$4 - 4 = 0 \implies$ colonna $4 \to \mathbf{1}$</li>
                    <li>$0 < 2 \implies$ colonna $2 \to \mathbf{0}$</li>
                    <li>$0 < 1 \implies$ colonna $1 \to \mathbf{0}$</li>
                </ul>
                Risultato immediato: $156_{10} = \mathbf{10011100}_2$.
            </li>
            <li><strong>B) $1350_{10}$ (Numero grande: Divisioni per 2 o Scorciatoia Esadecimale):</strong><br />
                <em>Strategia 1 (Divisioni successive per 2):</em><br />
                $1350 : 2 = 675 \text{ (r 0)}$; $675 : 2 = 337 \text{ (r 1)}$; $337 : 2 = 168 \text{ (r 1)}$; $168 : 2 = 84 \text{ (r 0)}$;<br />
                $84 : 2 = 42 \text{ (r 0)}$; $42 : 2 = 21 \text{ (r 0)}$; $21 : 2 = 10 \text{ (r 1)}$; $10 : 2 = 5 \text{ (r 0)}$;<br />
                $5 : 2 = 2 \text{ (r 1)}$; $2 : 2 = 1 \text{ (r 0)}$; $1 : 2 = 0 \text{ (r 1)}$.<br />
                <br />
                <em>Strategia 2 (Scorciatoia: 3 sole divisioni per 16 e quartetti):</em><br />
                $1350 : 16 = 84 \text{ (r 6)}$; $84 : 16 = 5 \text{ (r 4)}$; $5 : 16 = 0 \text{ (r 5)} \implies (546)_{16}$.<br />
                Espandendo a 4 bit: $5 \to 0101, \; 4 \to 0100, \; 6 \to 0110$.<br />
                <br />
                Risultato finale: $1350_{10} = \mathbf{10101000110}_2$.
            </li>
        </ul>
    </div>
</div>

---

### Passaggio Diretto tra Binario ed Esadecimale (Quartetti)
Esegui le seguenti conversioni dirette senza passare per la base 10:
- **A)** $(101111010011)_2 \to \text{Base 16}$
- **B)** $(\text{3F8A})_{16} \to \text{Base 2}$
- **C)** $(1111000101)_2 \to \text{Base 16}$ *(attenzione al numero di bit non multiplo di 4)*

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-interi-bin-hex">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-interi-bin-hex">
        <ul>
            <li><strong>A) $(101111010011)_2$:</strong><br />
                Raggruppiamo a 4 bit da destra: $\underbrace{1011}_{\text{B}} \quad \underbrace{1101}_{\text{D}} \quad \underbrace{0011}_{3} \implies \mathbf{(\text{BD3})_{16}}$.
            </li>
            <li><strong>B) $(\text{3F8A})_{16}$:</strong><br />
                Espandiamo ogni cifra in 4 bit: $\text{3} \to 0011, \; \text{F} \to 1111, \; 8 \to 1000, \; \text{A} \to 1010 \implies \mathbf{(0011111110001010)_2}$.
            </li>
            <li><strong>C) $(1111000101)_2$:</strong><br />
                I bit sono 10. Aggiungiamo due zeri a sinistra: $\underbrace{0011}_{3} \quad \underbrace{1100}_{\text{C}} \quad \underbrace{0101}_{5} \implies \mathbf{(3\text{C}5)_{16}}$.
            </li>
        </ul>
    </div>
</div>

---

### Conversione tra Basi Generiche Arbitrarie
Converti il numero $(231)_4$ espresso in base 4 nella corrispondente rappresentazione in **base 6**.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-interi-arbitrarie">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-interi-arbitrarie">
        <ol>
            <li><strong>Passo 1 (Base 4 $\to$ Base 10):</strong><br />
                $$(231)_4 = 2 \cdot 4^2 + 3 \cdot 4^1 + 1 \cdot 4^0 = 2 \cdot 16 + 3 \cdot 4 + 1 = 32 + 12 + 1 = \mathbf{45}_{10}$$
            </li>
            <li><strong>Passo 2 (Base 10 $\to$ Base 6):</strong><br />
                Divisioni successive per 6:
                <ul>
                    <li>$45 : 6 = 7$ con resto <strong>3</strong> (LSB)</li>
                    <li>$7 : 6 = 1$ con resto <strong>1</strong></li>
                    <li>$1 : 6 = 0$ con resto <strong>1</strong> (MSB)</li>
                </ul>
            </li>
        </ol>
        <p>Risultato finale: $$(231)_4 = 45_{10} = \mathbf{(113)_6}$$</p>
    </div>
</div>

---

### Sfida: Confronto e Ordinamento tra Basi Diverse
Ordina i seguenti 5 valori dal più piccolo al più grande, motivando i passaggi:
$$A = (101110)_2, \quad B = (57)_8, \quad C = (2\text{E})_{16}, \quad D = 47_{10}, \quad E = (142)_5$$

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-interi-confronto">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-interi-confronto">
        <p><strong>Strategia:</strong> Portiamo tutti i valori al ponte comune in <strong>Base 10</strong>:</p>
        <ul>
            <li>$A = (101110)_2 = 32 + 8 + 4 + 2 = \mathbf{46}_{10}$</li>
            <li>$B = (57)_8 = 5 \cdot 8 + 7 \cdot 1 = 40 + 7 = \mathbf{47}_{10}$</li>
            <li>$C = (2\text{E})_{16} = 2 \cdot 16 + 14 = 32 + 14 = \mathbf{46}_{10}$</li>
            <li>$D = \mathbf{47}_{10}$</li>
            <li>$E = (142)_5 = 1 \cdot 25 + 4 \cdot 5 + 2 = 25 + 20 + 2 = \mathbf{47}_{10}$</li>
        </ul>
        <p><strong>Confronto e ordinamento:</strong></p>
        $$A = C \; (46) \quad < \quad B = D = E \; (47)$$
        <p>Tutti i valori corrispondono a soli due numeri decimali ($46$ e $47$).</p>
    </div>
</div>

---

### Batteria Mista di Conversioni tra Basi
Mettiti alla prova con questa serie di conversioni assortite. **Le tipologie e le basi sono mescolate:** analizza autonomamente ogni caso per scegliere la via più rapida (somma dei pesi, sottrazione di potenze, divisioni successive, quartetti/terzetti diretti o ponte in base 10).

Clicca sulla freccia a lato di ogni conversione per verificare la soluzione e la strategia consigliata:

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>1.</strong> $(110111)_2 \to \text{Base } 10$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>Strategia:</strong> Somma dei pesi delle potenze di 2 accese ($32 + 16 + 4 + 2 + 1$).</p>
    <p><strong>Risultato:</strong> $\mathbf{55}_{10}$</p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>2.</strong> $74_{10} \to \text{Base } 2$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>Strategia:</strong> Metodo intuitivo delle potenze ($74 - 64 = 10 \to 10 - 8 = 2 \to 2 - 2 = 0$).</p>
    <p><strong>Risultato:</strong> $\mathbf{1001010}_2$</p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>3.</strong> $(\text{3D})_{16} \to \text{Base } 2$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>Strategia:</strong> Espansione diretta a 4 bit per cifra ($\text{3} \to 0011, \; \text{D} \to 1101$).</p>
    <p><strong>Risultato:</strong> $\mathbf{111101}_2$</p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>4.</strong> $(101111)_2 \to \text{Base } 16$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>Strategia:</strong> Raggruppamento a quartetti da destra: $\underbrace{0010}_{2} \ \underbrace{1111}_{\text{F}}$.</p>
    <p><strong>Risultato:</strong> $\mathbf{(2\text{F})_{16}}$</p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>5.</strong> $(43)_5 \to \text{Base } 10$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>Strategia:</strong> Notazione polinomiale con potenze di 5 ($4 \cdot 5^1 + 3 \cdot 5^0 = 20 + 3$).</p>
    <p><strong>Risultato:</strong> $\mathbf{23}_{10}$</p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>6.</strong> $198_{10} \to \text{Base } 16$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>Strategia:</strong> Divisioni per 16: $198 : 16 = 12 \text{ (resto 6)} \to 12 \implies \text{C}$.</p>
    <p><strong>Risultato:</strong> $\mathbf{(\text{C}6)_{16}}$</p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>7.</strong> $(101011100)_2 \to \text{Base } 8 \text{ (Ottale)}$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>Strategia:</strong> Raggruppamento diretto a terzetti (3 bit): $\underbrace{101}_{5} \ \underbrace{011}_{3} \ \underbrace{100}_{4}$.</p>
    <p><strong>Risultato:</strong> $\mathbf{(534)_8}$</p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>8.</strong> $(\text{8A})_{16} \to \text{Base } 10$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>Strategia:</strong> Moltiplicazione per i pesi esadecimali ($8 \cdot 16 + 10 \cdot 1 = 128 + 10$).</p>
    <p><strong>Risultato:</strong> $\mathbf{138}_{10}$</p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>9.</strong> $(32)_4 \to \text{Base } 2$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>Strategia:</strong> Espansione diretta a coppie di 2 bit ($3 \to 11, \; 2 \to 10$, poiché $4 = 2^2$).</p>
    <p><strong>Risultato:</strong> $\mathbf{1110}_2$</p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>10.</strong> $115_{10} \to \text{Base } 2$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>Strategia:</strong> Sottrazione rapida di potenze ($115 - 64 = 51 \to 51 - 32 = 19 \to 19 - 16 = 3 \to 3 - 2 = 1 \to 1 - 1 = 0$).</p>
    <p><strong>Risultato:</strong> $\mathbf{1110011}_2$</p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>11.</strong> $(213)_4 \to \text{Base } 7$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>Strategia:</strong> Ponte in Base 10. $(213)_4 = 2\cdot 16 + 1\cdot 4 + 3 = 39_{10} \to 39 : 7 = 5 \text{ (resto 4)}$.</p>
    <p><strong>Risultato:</strong> $\mathbf{(54)_7}$</p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>12.</strong> $(72)_8 \to \text{Base } 2$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>Strategia:</strong> Espansione diretta a terzetti di 3 bit ($7 \to 111, \; 2 \to 010$).</p>
    <p><strong>Risultato:</strong> $\mathbf{111010}_2$</p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>13.</strong> $(\text{F5})_{16} \to \text{Base } 8$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>Strategia:</strong> Ponte binario: $\text{F5}_{16} \to 1111\ 0101_2 \to$ raggruppamento a 3 bit: $\underbrace{011}_{3} \ \underbrace{110}_{6} \ \underbrace{101}_{5}$.</p>
    <p><strong>Risultato:</strong> $\mathbf{(365)_8}$</p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>14.</strong> $45_{10} \to \text{Base } 3$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>Strategia:</strong> Divisioni successive per 3: $45:3=15\text{ (r 0)} \to 15:3=5\text{ (r 0)} \to 5:3=1\text{ (r 2)} \to 1:3=0\text{ (r 1)}$.</p>
    <p><strong>Risultato:</strong> $\mathbf{(1200)_3}$</p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>15.</strong> $(1001001)_2 \to \text{Base } 10$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>Strategia:</strong> Somma potenze di 2 accese ($64 + 8 + 1$).</p>
    <p><strong>Risultato:</strong> $\mathbf{73}_{10}$</p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>16.</strong> $(321)_6 \to \text{Base } 10$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>Strategia:</strong> Notazione polinomiale in base 6 ($3 \cdot 36 + 2 \cdot 6 + 1 = 108 + 12 + 1$).</p>
    <p><strong>Risultato:</strong> $\mathbf{121}_{10}$</p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>17.</strong> $250_{10} \to \text{Base } 16$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>Strategia:</strong> Divisioni per 16: $250 : 16 = 15 \text{ (resto 10} \implies \text{A)} \to 15 \implies \text{F}$.</p>
    <p><strong>Risultato:</strong> $\mathbf{(\text{FA})_{16}}$</p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>18.</strong> $(101101111)_2 \to \text{Base } 16$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>Strategia:</strong> Raggruppamento a quartetti da destra: $\underbrace{0001}_{1} \ \underbrace{0110}_{6} \ \underbrace{1111}_{\text{F}}$.</p>
    <p><strong>Risultato:</strong> $\mathbf{(16\text{F})_{16}}$</p>
  </div>
</details>

---

## Tipologia 2: Numeri Frazionari (con la Virgola) e Periodici

### Da Binario con la Virgola a Decimale
Converti i seguenti numeri binari con la virgola nel formato decimale:
- **A)** $(11.101)_2$
- **B)** $(0.011)_2$
- **C)** $(1010.0001)_2$

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-fraz-bin2dec">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-fraz-bin2dec">
        <ul>
            <li><strong>A) $(11.101)_2$:</strong><br />
                Parte intera: $2 + 1 = 3$. Parte frazionaria: $0.5 + 0.125 = 0.625$. $\implies \mathbf{3.625}_{10}$.
            </li>
            <li><strong>B) $(0.011)_2$:</strong><br />
                Parte frazionaria: $0.25 + 0.125 = \mathbf{0.375}_{10}$.
            </li>
            <li><strong>C) $(1010.0001)_2$:</strong><br />
                Parte intera: $8 + 2 = 10$. Parte frazionaria: $2^{-4} = \frac{1}{16} = 0.0625$. $\implies \mathbf{10.0625}_{10}$.
            </li>
        </ul>
    </div>
</div>

---

### Da Decimale con la Virgola a Binario (Moltiplicazioni)
Converti il numero decimale $18.3125_{10}$ in binario, calcolando separatamente la parte intera e la parte frazionaria.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-fraz-dec2bin">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-fraz-dec2bin">
        <ol>
            <li><strong>Parte intera ($18_{10}$):</strong> $18 = 16 + 2 \implies \mathbf{10010}_2$.</li>
            <li><strong>Parte frazionaria ($0.3125_{10}$):</strong>
                <ul>
                    <li>$0.3125 \times 2 = \mathbf{0}.625 \implies$ cifra <strong>0</strong></li>
                    <li>$0.625 \times 2 = \mathbf{1}.25 \implies$ cifra <strong>1</strong></li>
                    <li>$0.25 \times 2 = \mathbf{0}.5 \implies$ cifra <strong>0</strong></li>
                    <li>$0.5 \times 2 = \mathbf{1}.0 \implies$ cifra <strong>1</strong> (frazione residua = 0, fine)</li>
                </ul>
                Parte decimale: $\mathbf{.0101}_2$.
            </li>
        </ol>
        <p>Risultato finale: $$18.3125_{10} = \mathbf{(10010.0101)_2}$$</p>
    </div>
</div>

---

### Riconoscimento del Periodo in Binario
Converti la frazione decimale $0.6_{10}$ in binario. Individua l'eventuale antiperiodo, la sequenza periodica e spiega il punto esatto di arresto del calcolo.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-fraz-periodico">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-fraz-periodico">
        <p>Eseguiamo le moltiplicazioni per 2:</p>
        <ul>
            <li><strong>Passo 1:</strong> $\mathbf{0.6} \times 2 = \mathbf{1}.2 \implies$ cifra <strong>1</strong> (entra la frazione $0.2$)</li>
            <li><strong>Passo 2:</strong> $0.2 \times 2 = \mathbf{0}.4 \implies$ cifra <strong>0</strong></li>
            <li><strong>Passo 3:</strong> $0.4 \times 2 = \mathbf{0}.8 \implies$ cifra <strong>0</strong></li>
            <li><strong>Passo 4:</strong> $0.8 \times 2 = \mathbf{1}.\mathbf{6} \implies$ cifra <strong>1</strong> (avanza di nuovo la frazione <strong>$0.6$</strong>!)</li>
            <li><strong>Passo 5:</strong> $\mathbf{0.6} \times 2 = \mathbf{1}.2 \implies$ 🛑 <strong>STOP:</strong> abbiamo ritrovato $0.6$ già calcolato al Passo 1.</li>
        </ul>
        <p>Non c'è antiperiodo e il periodo è composto dalle 4 cifre <code>1001</code>:</p>
        $$0.6_{10} = (0.\overline{1001})_2 = 0.100110011001\dots_2$$
    </div>
</div>

---

### Conversione Frazionaria Diretta tra Binario ed Esadecimale
Converti i seguenti numeri:
- **A)** $(11010.11)_2 \to \text{Esadecimale}$
- **B)** $(\text{A.4E})_{16} \to \text{Binario}$

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-fraz-bin-hex">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-fraz-bin-hex">
        <ul>
            <li><strong>A) $(11010.11)_2$:</strong>
                <ul>
                    <li>Parte intera: raggruppiamo a sinistra $\underbrace{0001}_{1} \quad \underbrace{1010}_{\text{A}} \implies 1\text{A}_{16}$.</li>
                    <li>Parte frazionaria: raggruppiamo a destra aggiungendo due zeri $\underbrace{.1100}_{\text{C}} \implies .\text{C}_{16}$.</li>
                    <li>Risultato: $(11010.11)_2 = \mathbf{(1\text{A.C})_{16}}$.</li>
                </ul>
            </li>
            <li><strong>B) $(\text{A.4E})_{16}$:</strong>
                <ul>
                    <li>$\text{A} \to 1010$, $4 \to 0100$, $\text{E} \to 1110$.</li>
                    <li>Risultato: $(\text{A.4E})_{16} = \mathbf{(1010.01001110)_2}$.</li>
                </ul>
            </li>
        </ul>
    </div>
</div>

---

### Sfida: Diagnosi di un Errore nei Calcoli Floating-Point
Un programma bancario deve accreditare una commissione fissa pari a $0.20$ € su ogni transazione. Dopo 5 transazioni, il software confronta se il saldo commissioni è esattamente uguale a $1.00$ € tramite l'istruzione:
`if (totale == 1.0) ...`  
Tuttavia, il test fallisce inaspettatamente.

1. Spiega dal punto di vista della codifica binaria perché il numero $0.20_{10}$ non può essere rappresentato in modo esatto in memoria.
2. Mostra le prime 8 cifre binarie dopo la virgola del numero $0.20_{10}$.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-fraz-float-bug">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-fraz-float-bug">
        <ol>
            <li><strong>Causa dell'errore:</strong><br />
                Una frazione decimale può essere finita in binario solo se il suo denominatore ridotto ai minimi termini è una potenza di 2 ($2, 4, 8, 16 \dots$).  
                Poiché $0.20 = \frac{1}{5}$ e il denominatore contiene il fattore 5, in binario il numero diventa **periodico illimitato**. La CPU, disponendo di un numero finito di bit (es. 32 bit per i `float`), è costretta a troncare la sequenza, introducendo un micro-errore di arrotondamento ad ogni operazione.
            </li>
            <li><strong>Calcolo della sequenza binaria di $0.20_{10}$:</strong>
                <ul>
                    <li>$0.2 \times 2 = \mathbf{0}.4 \implies 0$</li>
                    <li>$0.4 \times 2 = \mathbf{0}.8 \implies 0$</li>
                    <li>$0.8 \times 2 = \mathbf{1}.6 \implies 1$</li>
                    <li>$0.6 \times 2 = \mathbf{1}.2 \implies 1$</li>
                    <li>$0.2 \times 2 = \mathbf{0}.4 \implies 0$ (ritorna 0.2, inizio ripetizione del periodo $0011$)</li>
                </ul>
                Le prime 8 cifre binarie dopo la virgola sono: $$0.20_{10} \approx \mathbf{0.00110011}_2$$
            </li>
        </ol>
    </div>
</div>

---

## Tipologia 3: Interi con Segno, Complemento a 2 e Overflow

### Codifica di Numeri Negativi su 8 bit
Rappresenta ciascuno dei seguenti numeri interi in complemento a 2 su **8 bit**:
- **A)** $-58_{10}$
- **B)** $-72_{10}$
- **C)** $-1_{10}$

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-segno-c2">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-segno-c2">
        <ul>
            <li><strong>A) $-58_{10}$ (Metodo classico: Inversione $+ 1$):</strong><br />
                $+58_{10} = 00111010_2 \implies$ Invertiamo: $11000101 \implies +1 = \mathbf{11000110}_2$.
            </li>
            <li><strong>B) $-72_{10}$ (Scorciatoia da destra a sinistra):</strong><br />
                $+72_{10} = 01001000_2$.  
                Ricopiamo invariati gli zeri fino al primo 1 (`...1000`) e invertiamo la parte restante a sinistra (`0100` $\to$ `1011`):  
                Risultato: $\mathbf{10111000}_2$.
            </li>
            <li><strong>C) $-1_{10}$ (Il massimo negativo):</strong><br />
                $+1_{10} = 00000001_2 \implies$ Invertiamo: $11111110 \implies +1 = \mathbf{11111111}_2$.  
                *(In complemento a 2 tutti i bit a 1 rappresentano sempre il valore $-1$).*
            </li>
        </ul>
    </div>
</div>

---

### Lettura Diretta del Valore con il Peso Negativo
Senza applicare l'inversione e il $+1$, calcola direttamente a mente o con un solo passaggio di somma il valore decimale rappresentato dalle seguenti sequenze a 8 bit in complemento a 2:
- **A)** $B_1 = 11100101_2$
- **B)** $B_2 = 10000001_2$
- **C)** $B_3 = 01101100_2$

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-segno-lettura-diretta">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-segno-lettura-diretta">
        <p><strong>Regola:</strong> Il bit più a sinistra ha peso $\mathbf{-128}$, gli altri bit conservano i pesi positivi ($+64, +32, +16, +8, +4, +2, +1$).</p>
        <ul>
            <li><strong>A) $11100101_2$:</strong><br />
                $V = -128 + 64 + 32 + 4 + 1 = -128 + 101 = \mathbf{-27}_{10}$.
            </li>
            <li><strong>B) $10000001_2$:</strong><br />
                $V = -128 + 1 = \mathbf{-127}_{10}$.
            </li>
            <li><strong>C) $01101100_2$:</strong><br />
                Il bit di segno è $0$, quindi il numero è positivo:<br />
                $V = 64 + 32 + 8 + 4 = \mathbf{+108}_{10}$.
            </li>
        </ul>
    </div>
</div>

---

### Sottrazione Binaria ed Eliminazione del Riporto
Esegui su **8 bit** la sottrazione $35 - 19$ trasformandola nell'addizione binaria $35 + (-19)$.  
Mostra la somma in colonna e commenta il comportamento del riporto sul nono bit.

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-segno-sottrazione">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-segno-sottrazione">
        <ol>
            <li>$+35_{10} = 32 + 2 + 1 = \mathbf{00100011}_2$.</li>
            <li>$+19_{10} = 00010011_2 \implies -19_{10} = \mathbf{11101101}_2$ (complemento a 2).</li>
            <li>Eseguiamo la somma in colonna a 8 bit:</li>
        </ol>
        <pre><code>    00100011   (+35)  +
    11101101   (-19)  =
  ──────────
  (1)00010000   (+16)</code></pre>
        <p>Il nono bit di riporto <code>(1)</code> generato a sinistra viene <strong>scartato</strong> perché il registro è a 8 bit. Il valore risultante a 8 bit è $00010000_2 = \mathbf{+16}_{10}$, perfettamente conforme all'operazione algebrica $35 - 19 = 16$.</p>
    </div>
</div>

---

### Diagnosi e Rilevamento dell'Overflow
Determina per ciascuna delle seguenti operazioni tra numeri a **8 bit** con segno (intervallo $[-128, +127]$) se si verifica una condizione di **overflow**, specificandone la tipologia:
- **A)** $(+85) + (+60)$
- **B)** $(-90) + (-50)$
- **C)** $(+100) + (-40)$
- **D)** $(-64) + (-64)$

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-segno-overflow">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-segno-overflow">
        <ul>
            <li><strong>A) $(+85) + (+60) = +145$:</strong><br />
                Poiché $+145 > +127$, sfora il limite superiore. In binario la somma dà un bit di segno <code>1</code> (la CPU legge $-111$).<br />
                <strong>Esito: OVERFLOW POSITIVO.</strong>
            </li>
            <li><strong>B) $(-90) + (-50) = -140$:</strong><br />
                Poiché $-140 < -128$, scende sotto il limite inferiore. In binario la somma dà un bit di segno <code>0</code> (la CPU legge $+116$).<br />
                <strong>Esito: OVERFLOW NEGATIVO.</strong>
            </li>
            <li><strong>C) $(+100) + (-40) = +60$:</strong><br />
                I segni sono discordi: l'operazione equivale a una differenza. Il risultato $+60$ è compreso in $[-128, +127]$.<br />
                <strong>Esito: NESSUN OVERFLOW</strong> (la somma di numeri di segno opposto non può mai causare overflow).
            </li>
            <li><strong>D) $(-64) + (-64) = -128$:</strong><br />
                Il valore $-128$ coincide esattamente con il valore minimo rappresentabile a 8 bit ($10000000_2$).<br />
                <strong>Esito: NESSUN OVERFLOW</strong> (il risultato è esattamente al limite estremo, ma ancora rappresentabile).
            </li>
        </ul>
    </div>
</div>

---

### Sfida: Il Bug del Contatore di Punti (Scenario Reale)
In un videogioco arcade rétro, il punteggio della partita è memorizzato in una variabile a 8 bit con segno (`int8_t`).  
Un giocatore ha accumulato **$120$ punti** e raccoglie un bonus da **$+20$ punti**.

1. Quale valore numerico compare improvvisamente sullo schermo del giocatore dopo aver raccolto il bonus?
2. Mostra la somma binaria eseguita dal processore e spiega quale flag di stato della CPU viene attivato.
3. Come avrebbe dovuto dichiarare la variabile lo sviluppatore per evitare questo bug mantenendo l'occupazione di 1 solo byte?

<div class="soluzione-container">
    <p class="soluzione-toggler" totoggle="#sol-segno-arcade-bug">Visualizza la risoluzione</p>
    <div class="soluzione" id="sol-segno-arcade-bug">
        <ol>
            <li><strong>Valore visualizzato a schermo:</strong><br />
                Il giocatore vedrà comparire il punteggio **$-116$**!
            </li>
            <li><strong>Analisi binaria della CPU:</strong><br />
                $+120_{10} = 01111000_2$<br />
                $+20_{10} = 00010100_2$<br />
                Somma in colonna:
                <pre><code>    01111000   (+120)  +
    00010100   (+20)   =
  ──────────
    10001100   (Bit di segno 1: la CPU legge -128 + 8 + 4 = -116)</code></pre>
                La somma di due valori positivi ha invaso il bit di segno $b_7$, attivando il **flag di Overflow (OF)** della CPU.
            </li>
            <li><strong>Soluzione corretta:</strong><br />
                Dichiarare la variabile come intero senza segno (`uint8_t` / `unsigned char`), il cui intervallo su 8 bit va da $0$ a $+255$, consentendo di gestire agevolmente $140$ punti in un solo byte.
            </li>
        </ol>
    </div>
</div>

---

### Batteria Mista di Operazioni in Complemento a 2
Esegui ciascuna delle seguenti operazioni tra numeri interi con segno su **8 bit** (intervallo $[-128, +127]$):
- Se l'operazione è una sottrazione $A - B$, trasformala nell'addizione $A + (-B)$ calcolando il complemento a 2 del secondo termine.
- Esegui la somma binaria in colonna a 8 bit e scarta l'eventuale 9° bit di riporto finale.
- **Verifica infine il risultato** riconvertendo la sequenza binaria ottenuta in decimale (usando il peso $-128$ sul bit di segno) per confermare la correttezza del calcolo e diagnosticare eventuali condizioni di **Overflow**.

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>1.</strong> $(+42) + (+25)$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>1. Codifica a 8 bit:</strong> $+42_{10} = 00101010_2$, $+25_{10} = 00011001_2$</p>
    <p><strong>2. Somma in colonna:</strong> $00101010 + 00011001 = \mathbf{00111101}_2$</p>
    <p><strong>3. Verifica decimale:</strong> $32 + 16 + 8 + 4 + 1 = \mathbf{+67}_{10}$ (Conforme a $42 + 25 = 67$, nessun overflow).</p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>2.</strong> $(+58) - (+23)$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>1. Trasformazione:</strong> $+58 + (-23)$. $+58 = 00111010_2$; $+23 = 00010111_2 \implies -23 = 11101001_2$</p>
    <p><strong>2. Somma in colonna:</strong> $00111010 + 11101001 = (1)\mathbf{00100011}_2$ (9° bit scartato)</p>
    <p><strong>3. Verifica decimale:</strong> $32 + 2 + 1 = \mathbf{+35}_{10}$ (Conforme a $58 - 23 = 35$, nessun overflow).</p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>3.</strong> $(+19) - (+45)$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>1. Trasformazione:</strong> $+19 + (-45)$. $+19 = 00010011_2$; $+45 = 00101101_2 \implies -45 = 11010011_2$</p>
    <p><strong>2. Somma in colonna:</strong> $00010011 + 11010011 = \mathbf{11100110}_2$</p>
    <p><strong>3. Verifica decimale:</strong> $-128 + 64 + 32 + 4 + 2 = \mathbf{-26}_{10}$ (Conforme a $19 - 45 = -26$, nessun overflow).</p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>4.</strong> $(-30) + (-40)$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>1. Codifica a 8 bit:</strong> $-30 = 11100010_2$, $-40 = 11011000_2$</p>
    <p><strong>2. Somma in colonna:</strong> $11100010 + 11011000 = (1)\mathbf{10111010}_2$ (9° bit scartato)</p>
    <p><strong>3. Verifica decimale:</strong> $-128 + 32 + 16 + 8 + 2 = \mathbf{-70}_{10}$ (Conforme a $-30 + (-40) = -70$, nessun overflow).</p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>5.</strong> $(-15) - (+28)$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>1. Trasformazione:</strong> $-15 + (-28)$. $-15 = 11110001_2$, $-28 = 11100100_2$</p>
    <p><strong>2. Somma in colonna:</strong> $11110001 + 11100100 = (1)\mathbf{11010101}_2$ (9° bit scartato)</p>
    <p><strong>3. Verifica decimale:</strong> $-128 + 64 + 16 + 4 + 1 = \mathbf{-43}_{10}$ (Conforme a $-15 - 28 = -43$, nessun overflow).</p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>6.</strong> $(+75) + (+65)$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>1. Codifica a 8 bit:</strong> $+75_{10} = 01001011_2$, $+65_{10} = 01000001_2$</p>
    <p><strong>2. Somma in colonna:</strong> $01001011 + 01000001 = \mathbf{10001100}_2$</p>
    <p><strong>3. Diagnosi:</strong> Il risultato teorico $+140$ supera $+127$. Il bit di segno diventa $1$, la CPU legge $-128 + 8 + 4 = \mathbf{-116}_{10}$. $\implies$ ⚠️ <strong>OVERFLOW POSITIVO!</strong></p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>7.</strong> $(-80) + (-60)$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>1. Codifica a 8 bit:</strong> $-80_{10} = 10110000_2$, $-60_{10} = 11000100_2$</p>
    <p><strong>2. Somma in colonna:</strong> $10110000 + 11000100 = (1)\mathbf{01110100}_2$</p>
    <p><strong>3. Diagnosi:</strong> Il risultato teorico $-140$ è inferiore a $-128$. Il bit di segno diventa $0$, la CPU legge $64 + 32 + 16 + 4 = \mathbf{+116}_{10}$. $\implies$ ⚠️ <strong>OVERFLOW NEGATIVO!</strong></p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>8.</strong> $(+90) - (-18)$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>1. Trasformazione:</strong> $+90 - (-18) = +90 + (+18)$. $+90 = 01011010_2$, $+18 = 00010010_2$</p>
    <p><strong>2. Somma in colonna:</strong> $01011010 + 00010010 = \mathbf{01101100}_2$</p>
    <p><strong>3. Verifica decimale:</strong> $64 + 32 + 8 + 4 = \mathbf{+108}_{10}$ (Conforme a $90 - (-18) = 108$, nessun overflow).</p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>9.</strong> $(-100) - (-45)$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>1. Trasformazione:</strong> $-100 - (-45) = -100 + (+45)$. $-100 = 10011100_2$, $+45 = 00101101_2$</p>
    <p><strong>2. Somma in colonna:</strong> $10011100 + 00101101 = \mathbf{11001001}_2$</p>
    <p><strong>3. Verifica decimale:</strong> $-128 + 64 + 8 + 1 = \mathbf{-55}_{10}$ (Conforme a $-100 - (-45) = -55$, nessun overflow).</p>
  </div>
</details>

<details class="conversione-item">
  <summary>
    <span class="conv-testo"><strong>10.</strong> $(+64) - (+64)$</span>
    <span class="conv-btn">Soluzione <span class="conv-arrow">▾</span></span>
  </summary>
  <div class="conv-soluzione">
    <p><strong>1. Trasformazione:</strong> $+64 + (-64)$. $+64 = 01000000_2$, $-64 = 11000000_2$</p>
    <p><strong>2. Somma in colonna:</strong> $01000000 + 11000000 = (1)\mathbf{00000000}_2$ (9° bit scartato)</p>
    <p><strong>3. Verifica decimale:</strong> $\mathbf{0}_{10}$ (Conforme a $64 - 64 = 0$, nessun overflow).</p>
  </div>
</details>
