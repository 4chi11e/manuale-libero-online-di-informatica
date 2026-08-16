---
title: Conversioni numeriche
description: Guida completa ai sistemi di numerazione, algoritmi di conversione tra basi (interi e frazionari) e rappresentazione dei numeri negativi in complemento a due.
---

I computer e tutti i moderni dispositivi digitali operano internamente manipolando stati fisici discreti: presenza o assenza di tensione elettrica, magnetizzazione positiva o negativa, passaggio o blocco di luce. Questa natura fisica binaria fa sì che l'unità fondamentale di informazione sia il **bit** (*binary digit*), che può assumere solo i due valori $0$ e $1$.

Comprendere come i numeri e i dati vengano codificati e trasformati tra le diverse basi è uno dei primi e più importanti passi nello studio dell'informatica.

```text
              ┌────────────────────────┐
              │    SISTEMA DECIMALE    │ <─── Utilizzato dagli esseri umani (Base 10)
              └───────────┬────────────┘
                          │
            ┌─────────────┴─────────────┐
            │                           │
            ▼                           ▼
┌────────────────────────┐   ┌────────────────────────┐
│    SISTEMA BINARIO     │   │  SISTEMA ESADECIMALE   │
│  Linguaggio macchina   │   │  Rappresentazione      │
│        (Base 2)        │   │  compatta (Base 16)    │
└────────────────────────┘   └────────────────────────┘
```

### Perché questo argomento è fondamentale?

Lo studio delle conversioni numeriche non è un mero esercizio algebrico, ma la chiave per comprendere gli argomenti cardine dei capitoli successivi del manuale:

- **Architettura dei Calcolatori:** I registri del processore (CPU), l'unità aritmetico-logica (ALU), i bus di comunicazione e l'indirizzamento della memoria RAM operano a livello di parole binarie (a 32 o 64 bit).
- **Sistemi Operativi:** Gli indirizzi di memoria fisica e virtuale, i puntatori e i permessi dei file (come la celebre notazione ottale `chmod 755` nei sistemi Linux/Unix) sono costantemente espressi in esadecimale o in ottale per comodità di lettura.
- **Reti di Calcolatori:** Gli indirizzi **IPv4** sono costituiti da 32 bit suddivisi in 4 byte decimali (e il calcolo delle maschere di sottorete, o *subnetting*, richiede continue conversioni tra binario e decimale); gli indirizzi fisici **MAC** e gli indirizzi **IPv6** sono invece interamente codificati in notazione esadecimale.

:::tip[Strumento Interattivo di Supporto]
Per verificare i tuoi calcoli, visualizzare i passaggi passo-passo ed esercitarti con esempi generati al volo, puoi utilizzare lo strumento online:  
👉 **[Strumento Interattivo per le Conversioni Numeriche](https://4chi11e.github.io/conversioni-numeriche/)**
:::

---

## 1. Come contiamo noi: il Sistema Posizionale in Base 10

Fin da piccoli siamo abituati a contare in **base 10** (molto probabilmente perché abbiamo dieci dita sulle mani!). In base 10 abbiamo a disposizione dieci cifre diverse: da $0$ a $9$.

Ma cosa significa davvero un numero come **$743$**?

Fin dalle scuole elementari abbiamo imparato a scomporlo in colonne:
- **$3$ unità** (vale $3 \times 1 = 3$)
- **$4$ decine** (vale $4 \times 10 = 40$)
- **$7$ centinaia** (vale $7 \times 100 = 700$)

$$743 = 700 + 40 + 3 = (7 \times 100) + (4 \times 10) + (3 \times 1)$$

Questo modo di rappresentare i numeri si chiama **sistema posizionale**: il valore reale di una cifra non dipende solo dal suo disegno, ma dalla **posizione** in cui si trova all'interno del numero.  
Un $7$ all'inizio vale $700$, ma se lo spostiamo all'ultimo posto vale soltanto $7$!

Se osserviamo con attenzione, ogni colonna (partendo da destra e andando verso sinistra) vale **10 volte di più** rispetto a quella precedente:
- Colonna 0 (unità): $1 = 10^0$
- Colonna 1 (decine): $10 = 10^1$
- Colonna 2 (centinaia): $100 = 10^2$
- Colonna 3 (migliaia): $1000 = 10^3$

$$743 = 7 \cdot 10^2 + 4 \cdot 10^1 + 3 \cdot 10^0$$

---

## 2. E se cambiassimo base? Il Sistema Binario (Base 2)

I computer non hanno dieci dita: all'interno dei processori e delle memorie ci sono miliardi di microscopici interruttori elettronici (i transistor) che possono trovarsi solo in due stati fisici possibili: **spento ($0$)** o **acceso ($1$)**.

Per questo motivo il computer usa la **base 2 (sistema binario)**, in cui abbiamo a disposizione solo due cifre: **$0$** e **$1$**. Ogni singola cifra binaria si chiama **bit** (*binary digit*).

La regola posizionale è **la stessa identica del sistema decimale**, solo che ogni colonna (da destra verso sinistra), invece di moltiplicarsi per 10, **si moltiplica per 2 (raddoppia)**:

| Colonna | $7$ | $6$ | $5$ | $4$ | $3$ | $2$ | $1$ | $0$ |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Potenza di 2** | $2^7$ | $2^6$ | $2^5$ | $2^4$ | $2^3$ | $2^2$ | $2^1$ | $2^0$ |
| **Valore della colonna** | **$128$** | **$64$** | **$32$** | **$16$** | **$8$** | **$4$** | **$2$** | **$1$** |

---

## 3. Parte I: Numeri Interi (Senza Virgola)

Vediamo ora passo dopo passo come convertire i numeri interi positivi da una base all'altra.

### 3.1. Conversioni tra Binario (Base 2) e Decimale (Base 10)

#### Da Binario a Decimale: "Accendere o spegnere i pesi"
Per convertire un numero binario in decimale basta guardare le colonne:
1. Scrivi il valore di ogni colonna (partendo da destra: $1, 2, 4, 8, 16, 32, 64, 128 \dots$).
2. Prendi solo i valori delle colonne dove c'è il bit **$1$** ("acceso") e sommali tra loro. I bit **$0$** ("spento") si ignorano.

:::note[Esempio: Convertire 110101 in decimale]
Allineiamo ogni cifra binaria alla sua colonna:

| Valore colonna | 32 | 16 | 8 | 4 | 2 | 1 |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: |
| **Cifra binaria** | **1** | **1** | **0** | **1** | **0** | **1** |

Sommiamo solo i valori corrispondenti ai bit **1**:
$$(110101)_2 = 32 + 16 + 4 + 1 = 53_{10}$$
:::

#### Da Decimale a Binario (Metodo 1: Divisioni Successive)
Per convertire un numero intero da decimale a binario:
1. Si divide il numero decimale per $2$.
2. Si annota il **resto** (che sarà sempre $0$ o $1$).
3. Si divide il quoziente ottenuto nuovamente per $2$.
4. Si prosegue fino a quando il quoziente diventa $0$.
5. **Si leggono i resti in ordine inverso (dall'ultimo ottenuto al primo, cioè dal basso verso l'alto).**

:::note[Esempio: Convertire 45 in binario con le divisioni]
Eseguiamo le divisioni successive per 2:

| Divisione | Quoziente | Resto | Cifra binaria |
| :---: | :---: | :---: | :--- |
| $45 : 2$ | $22$ | **$1$** | $\leftarrow$ LSB (cifra meno significativa) |
| $22 : 2$ | $11$ | **$0$** | |
| $11 : 2$ | $5$ | **$1$** | |
| $5 : 2$ | $2$ | **$1$** | |
| $2 : 2$ | $1$ | **$0$** | |
| $1 : 2$ | $0$ | **$1$** | $\leftarrow$ MSB (cifra più significativa) |

Raccogliendo i resti dal basso verso l'alto otteniamo:
$$45_{10} = (101101)_2$$
:::

#### Da Decimale a Binario (Metodo 2: Metodo Intuitivo per Sottrazione di Potenze)
Per numeri non eccessivamente grandi (fino a qualche centinaio), esiste un metodo molto più rapido che si può svolgere **in gran parte a mente**.

Si basa su una semplice domanda: *«Qual è la potenza di 2 più grande contenuta nel mio numero?»*.

**Come procedere:**
1. Trova la **potenza di 2 più alta** che sia minore o uguale al numero di partenza.
2. Scrivi **$1$** come prima cifra e calcola quanto **rimane** sottraendo quella potenza.
3. Passa in rassegna in ordine decrescente **tutte le potenze successive fino a $2^0 = 1$**:
   - Se la potenza considerata **ci sta** nel valore rimasto: scrivi **$1$** e sottrai il suo valore dal totale rimanente.
   - Se la potenza **non ci sta** (è più grande di quanto rimasto): scrivi **$0$** e mantieni inalterato il valore rimanente.
4. **Le cifre si leggono direttamente in ordine naturale, dall'alto verso il basso (da sinistra a destra).**

:::note[Esempio: Convertire 100 in binario con la sottrazione di potenze]
La potenza di 2 più grande contenuta in 100 è $2^6 = 64$. Scorriamo tutte le potenze a scendere fino a $2^0$:

| Potenza di 2 | Valore Rimanente | Ci sta? | Operazione / Resto | Cifra Binaria |
| :---: | :---: | :---: | :---: | :---: |
| $2^6 = 64$ | $100$ | **Sì** ($100 \ge 64$) | $100 - 64 = 36$ | **1** |
| $2^5 = 32$ | $36$ | **Sì** ($36 \ge 32$) | $36 - 32 = 4$ | **1** |
| $2^4 = 16$ | $4$ | No ($4 < 16$) | $4$ | **0** |
| $2^3 = 8$ | $4$ | No ($4 < 8$) | $4$ | **0** |
| $2^2 = 4$ | $4$ | **Sì** ($4 \ge 4$) | $4 - 4 = 0$ | **1** |
| $2^1 = 2$ | $0$ | No ($0 < 2$) | $0$ | **0** |
| $2^0 = 1$ | $0$ | No ($0 < 1$) | $0$ | **0** |

Leggendo le cifre dall'alto verso il basso otteniamo direttamente:
$$100_{10} = (1100100)_2$$
:::

---

### 3.2. Conversioni tra Esadecimale (Base 16) e Decimale (Base 10)

Il sistema esadecimale (base 16) necessita di 16 simboli. Poiché le cifre arabe arrivano solo a 9, si utilizzano le prime 6 lettere dell'alfabeto latino:

| Simbolo | $0$ | $1$ | $2$ | $3$ | $4$ | $5$ | $6$ | $7$ | $8$ | $9$ | $\text{A}$ | $\text{B}$ | $\text{C}$ | $\text{D}$ | $\text{E}$ | $\text{F}$ |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Valore decimale** | $0$ | $1$ | $2$ | $3$ | $4$ | $5$ | $6$ | $7$ | $8$ | $9$ | $10$ | $11$ | $12$ | $13$ | $14$ | $15$ |

#### Da Esadecimale a Decimale (Metodo delle potenze di 16)
In base 16, ogni colonna vale 16 volte più di quella alla sua destra ($1, 16, 256, 4096 \dots$).  
Basta moltiplicare ciascuna cifra per il valore della sua colonna (ricordando di convertire le lettere nei loro valori da 10 a 15).

:::note[Esempio: Convertire 2A7 (esadecimale) in decimale]
Ricordando che $\text{A} = 10$:

$$\begin{aligned} (2\text{A}7)_{16} &= 2 \cdot 16^2 + 10 \cdot 16^1 + 7 \cdot 16^0 \\ &= (2 \times 256) + (10 \times 16) + (7 \times 1) \\ &= 512 + 160 + 7 = 679_{10} \end{aligned}$$
:::

#### Da Decimale a Esadecimale (Divisioni Successive per 16)
Si divide ripetutamente per 16, registrando i resti (convertendo i resti da 10 a 15 nelle corrispondenti lettere A-F) e leggendoli dal basso verso l'alto.

:::note[Esempio: Convertire 3019 in esadecimale]
Eseguiamo le divisioni successive per 16:

| Divisione | Quoziente | Resto | Lettera esadecimale | Posizione |
| :---: | :---: | :---: | :---: | :--- |
| $3019 : 16$ | $188$ | $11$ | **B** | $\leftarrow$ cifra meno significativa |
| $188 : 16$ | $11$ | $12$ | **C** | |
| $11 : 16$ | $0$ | $11$ | **B** | $\leftarrow$ cifra più significativa |

Raccogliendo i resti dal basso verso l'alto:
$$3019_{10} = (\text{BCB})_{16}$$
:::

:::tip[E se provassimo con il Metodo Intuitivo delle Potenze?]
Possiamo convertire lo stesso numero $3019_{10}$ cercando le potenze di 16 ($1, 16, 256, 4096 \dots$). Noteremo però che **a mente è molto più faticoso**!

Nel sistema binario una potenza può starci solo $0$ o $1$ volta. In esadecimale, invece, dobbiamo calcolare **quante volte** (da 0 a 15) la potenza è contenuta nel valore rimanente:

| Potenza di 16 | Valore Rimanente | Quante volte ci sta? | Operazione e Resto | Cifra Esadecimale |
| :---: | :---: | :---: | :---: | :---: |
| $16^2 = 256$ | $3019$ | **11 volte** | $3019 - (11 \times 256) = 3019 - 2816 = 203$ | **B** ($11$) |
| $16^1 = 16$ | $203$ | **12 volte** | $203 - (12 \times 16) = 203 - 192 = 11$ | **C** ($12$) |
| $16^0 = 1$ | $11$ | **11 volte** | $11 - (11 \times 1) = 0$ | **B** ($11$) |

Risultato: $3019_{10} = (\text{BCB})_{16}$.

**Conclusione:**
- Il **metodo intuitivo delle potenze** è **spesso più veloce** in **base 2** (specialmente per numeri piccoli o medi), dove basta verificare se una potenza è presente o assente.
- In **base 16**, il **metodo delle divisioni successive** (oppure la conversione diretta a blocchi di 4 bit) è molto più semplice e sicuro, poiché evita di dover calcolare moltiplicazioni pesanti a mente come $11 \times 256$.
:::

---

### 3.3. Conversioni tra Basi Generiche Qualsiasi (Metodo del Ponte in Base 10)

Quando dobbiamo convertire un numero tra due basi generiche qualsiasi (ad esempio da base 5 a base 7), il metodo universale è utilizzare la nostra cara **Base 10 come "ponte"**.

Poiché siamo abituati a eseguire tutte le operazioni aritmetiche (somme, moltiplicazioni e divisioni) in base 10, passare per il sistema decimale è il procedimento standard per collegare due basi arbitrarie:

```text
┌─────────────┐             Passo 1                     ┌──────────────┐
│   Base b1   │ ──────────────────────────────────────> │   Base 10    │
└─────────────┘       (somma pesi delle colonne)        └──────┬───────┘
                                                               │ Passo 2 (divisioni per b2)
                                                               ▼
                                                        ┌──────────────┐
                                                        │   Base b2    │
                                                        └──────────────┘
```

:::note[Esempio: Convertire 342 (base 5) in base 7]
**Passo 1: Da Base 5 a Base 10** (le colonne in base 5 valgono $1, 5, 25 \dots$):

$$(342)_5 = (3 \times 25) + (4 \times 5) + (2 \times 1)$$
$$= 75 + 20 + 2 = 97_{10}$$

**Passo 2: Da Base 10 a Base 7** (divisioni successive per 7)

| Divisione | Quoziente | Resto | Posizione |
| :---: | :---: | :---: | :--- |
| $97 : 7$ | $13$ | **$6$** | $\leftarrow$ cifra meno significativa |
| $13 : 7$ | $1$ | **$6$** | |
| $1 : 7$ | $0$ | **$1$** | $\leftarrow$ cifra più significativa |

Risultato:
$$(342)_5 = (166)_7$$
:::

---

### 3.4. Conversioni Dirette tra Basi Potenze di 2

Esiste un "trucco" fantastico quando una base è una potenza esatta di 2:
- **Base 16** ($16 = 2^4$): ogni cifra esadecimale equivale esattamente a **un gruppetto di 4 bit**!
- **Base 8** ($8 = 2^3$): ogni cifra ottale equivale esattamente a **un gruppetto di 3 bit**!

Non serve fare alcuna moltiplicazione o divisione: basta sostituire direttamente le cifre con i loro blocchi di bit.

#### Tabella di Corrispondenza Rapida
| Esadecimale | Binario (4 bit) | Decimale | Ottale | Binario (3 bit) |
| :---: | :---: | :---: | :---: | :---: |
| **0** | `0000` | 0 | **0** | `000` |
| **1** | `0001` | 1 | **1** | `001` |
| **2** | `0010` | 2 | **2** | `010` |
| **3** | `0011` | 3 | **3** | `011` |
| **4** | `0100` | 4 | **4** | `100` |
| **5** | `0101` | 5 | **5** | `101` |
| **6** | `0110` | 6 | **6** | `110` |
| **7** | `0111` | 7 | **7** | `111` |
| **8** | `1000` | 8 | - | - |
| **9** | `1001` | 9 | - | - |
| **A** | `1010` | 10 | - | - |
| **B** | `1011` | 11 | - | - |
| **C** | `1100` | 12 | - | - |
| **D** | `1101` | 13 | - | - |
| **E** | `1110` | 14 | - | - |
| **F** | `1111` | 15 | - | - |

#### Da Binario a Esadecimale (Diretto)
1. Raggruppa i bit in **gruppi di 4 partendo da destra**.
2. Se all'ultimo gruppo a sinistra mancano dei bit, aggiungi degli zeri davanti.
3. Sostituisci ogni gruppo con la cifra esadecimale corrispondente.

:::note[Esempio: Convertire 11010111100 in esadecimale]
1. Suddividiamo a quartetti partendo da destra:
   $$\underbrace{0110}_{\mathbf{6}} \quad \underbrace{1011}_{\mathbf{B}} \quad \underbrace{1100}_{\mathbf{C}}$$
   *(Abbiamo aggiunto uno zero a sinistra nel primo gruppo per completare i 4 bit).*
2. Risultato:
   $$(11010111100)_2 = (\text{6BC})_{16}$$
:::

#### Da Esadecimale a Binario (Diretto)
Sostituisci ogni cifra esadecimale con il suo blocco di **4 bit precisi** (scrivendo anche gli eventuali zeri all'inizio del quartetto!).

:::note[Esempio: Convertire 3E9 in binario]
Sostituiamo ogni cifra esadecimale con il suo blocco di 4 bit:

| Cifra Esadecimale | **3** | **E** ($14$) | **9** |
| :--- | :---: | :---: | :---: |
| **Blocco a 4 bit** | `0011` | `1110` | `1001` |

Unendo i blocchi otteniamo:
$$(3\text{E}9)_{16} = (001111101001)_2 = (1111101001)_2$$
:::

#### Ponte Rapido Esadecimale - Ottale (passando per il Binario)
Per convertire tra base 16 e base 8 non serve passare per la base 10: usiamo il binario come scorciatoia!

```text
┌──────────────┐                            ┌──────────────┐                            ┌──────────────┐
│ Esadecimale  │ ──(spacchetta a 4 bit)───> │   Binario    │ ────(raggruppa a 3 bit)──> │    Ottale    │
└──────────────┘                            └──────────────┘                            └──────────────┘
```

:::note[Esempio: Convertire 5D in ottale]
1. Spacchettiamo ogni cifra esadecimale in 4 bit:
   $$(5\text{D})_{16} \implies 0101 \quad 1101 \implies (01011101)_2$$
2. Riorganizziamo gli stessi bit in gruppi da 3 partendo da destra:
   $$\underbrace{001}_{\mathbf{1}} \quad \underbrace{011}_{\mathbf{3}} \quad \underbrace{101}_{\mathbf{5}}$$
3. Risultato:
   $$(5\text{D})_{16} = (135)_8$$
:::

---

## 4. Parte II: Numeri con la Virgola (Frazionari)

Cosa succede alle cifre poste **dopo la virgola**?

Nel sistema decimale siamo abituati a:
- 1ª cifra dopo la virgola: **decimi** ($\frac{1}{10} = 0.1$)
- 2ª cifra dopo la virgola: **centesimi** ($\frac{1}{100} = 0.01$)
- 3ª cifra dopo la virgola: **millesimi** ($\frac{1}{1000} = 0.001$)

Nel **sistema binario** accade la stessa identica cosa, ma dimezzando ogni volta il valore (dividendo per 2):

| Colonna dopo la virgola | $1^{\text{a}}$ ($2^{-1}$) | $2^{\text{a}}$ ($2^{-2}$) | $3^{\text{a}}$ ($2^{-3}$) | $4^{\text{a}}$ ($2^{-4}$) |
| :--- | :---: | :---: | :---: | :---: |
| **Frazione** | $\frac{1}{2}$ | $\frac{1}{4}$ | $\frac{1}{8}$ | $\frac{1}{16}$ |
| **Valore decimale** | **$0.5$** | **$0.25$** | **$0.125$** | **$0.0625$** |

### 4.1. Da Binario a Decimale con la Virgola
Basta sommare i valori delle colonne accese (bit $1$), sia per la parte intera che per la parte decimale.

:::note[Esempio: Convertire 101.101 in decimale]
- Parte intera: $1\cdot 4 + 0\cdot 2 + 1\cdot 1 = 5$
- Parte frazionaria: $1\cdot 0.5 + 0\cdot 0.25 + 1\cdot 0.125 = 0.5 + 0.125 = 0.625$

Sommando le due parti:
$$(101.101)_2 = 5 + 0.625 = 5.625_{10}$$
:::

### 4.2. Da Decimale a Binario con la Virgola (Moltiplicazioni Successive)
Per convertire la parte frazionaria di un numero decimale in binario:
1. Si separa la parte intera dalla parte frazionaria.
2. La **parte intera** si converte con le solite **divisioni per 2**.
3. La **parte frazionaria** (dopo lo $0.$) si converte mediante **moltiplicazioni successive per 2**:
   - Moltiplica la frazione per $2$.
   - La **parte intera del risultato** ($0$ o $1$) è la nuova cifra binaria dopo la virgola.
   - Prendi la nuova parte decimale rimanente e moltiplica ancora per 2.
   - Fermati quando la frazione diventa $0$ (numero finito) o quando individui un periodo.
4. **Le cifre binarie dopo la virgola si leggono dall'alto verso il basso.**

:::note[Esempio: Convertire 0.6875 in binario]
Eseguiamo le moltiplicazioni successive per 2:

| Moltiplicazione | Risultato | Parte intera | Posizione |
| :---: | :---: | :---: | :--- |
| $0.6875 \times 2$ | $1.375$ | **1** | $\leftarrow$ 1ª cifra dopo la virgola |
| $0.375 \times 2$ | $0.75$ | **0** | $\leftarrow$ 2ª cifra dopo la virgola |
| $0.75 \times 2$ | $1.5$ | **1** | $\leftarrow$ 3ª cifra dopo la virgola |
| $0.5 \times 2$ | $1.0$ | **1** | $\leftarrow$ 4ª cifra dopo la virgola (fine, frazione = 0) |

Raccogliendo le cifre dall'alto verso il basso:
$$0.6875_{10} = (0.1011)_2$$
:::

#### I Numeri Periodici nel Passaggio di Base: il caso di 0.1

Un numero che possiede una rappresentazione finita in decimale (come $0.1 = \frac{1}{10}$) può diventare **periodico infinito** quando viene convertito in binario!

##### Come si identifica il periodo?
> **Regola fondamentale:** Le moltiplicazioni si interrompono non appena **la parte decimale ottenuta ricompare identica a una già calcolata in un passaggio precedente**. Da quel momento in poi, infatti, l'algoritmo non farebbe altro che ripetere all'infinito la stessa sequenza di calcoli.

Proviamo ad applicare le moltiplicazioni successive per 2 al numero $0.1_{10}$:

| Passo | Moltiplicazione | Risultato | Cifra Binaria | Analisi del Periodo |
| :---: | :---: | :---: | :---: | :--- |
| **1** | $0.1 \times 2$ | $\mathbf{0}.2$ | **0** | **Antiperiodo** (1ª cifra dopo la virgola) |
| **2** | $\mathbf{0.2} \times 2$ | $\mathbf{0}.4$ | **0** | 🟡 **Inizio del periodo:** entra la frazione **$0.2$** |
| **3** | $0.4 \times 2$ | $\mathbf{0}.8$ | **0** | 2ª cifra del periodo |
| **4** | $0.8 \times 2$ | $\mathbf{1}.6$ | **1** | 3ª cifra del periodo |
| **5** | $0.6 \times 2$ | $\mathbf{1}.\mathbf{2}$ | **1** | 4ª cifra del periodo $\to$ avanza di nuovo la frazione **$\mathbf{0.2}$**! |
| **6** | $\mathbf{0.2} \times 2$ | $\mathbf{0}.4$ | **0** | 🛑 **STOP:** abbiamo ritrovato **$0.2$** (già calcolato al Passo 2). |

Poiché il ciclo si ripete a partire dal Passo 2, le quattro cifre binarie ottenute nei passi 2, 3, 4 e 5 formano il **periodo `0011`**:

$$0.1_{10} = (0.0\overline{0011})_2 = 0.00011001100110011\dots_2$$

:::caution[Perché i calcolatori sbagliano 0.1 + 0.2?]
Poiché i registri del computer hanno una dimensione limitata (es. 32 o 64 bit per i tipi `float` e `double`), la sequenza periodica infinita deve essere **troncata e arrotondata**.

Questo fenomeno fondamentale spiega perché in quasi tutti i linguaggi di programmazione (come C, Java, Python o JavaScript) calcolare `0.1 + 0.2` produce il celebre risultato `0.30000000000000004`!
:::

---

### 4.3. Conversioni Dirette con la Virgola (Binario ed Esadecimale)
Quando si convertono numeri con la virgola tra binario ed esadecimale (o ottale), la regola è:

- **Per la parte intera:** si raggruppa a blocchi di 4 da destra verso sinistra ($\leftarrow$).
- **Per la parte decimale:** si raggruppa a blocchi di 4 da sinistra verso destra ($\rightarrow$), aggiungendo zeri a destra se l'ultimo quartetto è incompleto.

:::note[Esempio: Convertire 1101.101 in esadecimale]
1. Parte intera: $(1101)_2 = \text{D}_{16}$.
2. Parte frazionaria: $(.101)_2 \to$ completiamo a 4 bit aggiungendo uno zero a destra: $(.1010)_2 = \text{A}_{16}$.
3. Risultato:
$$(1101.101)_2 = (\text{D.A})_{16}$$
:::

---

## 5. Parte III: Rappresentazione dei Numeri Interi Negativi

Nei circuiti di un computer non esiste il segno "$-$": le celle di memoria possono contenere soltanto $0$ e $1$. Inoltre, a livello hardware lavoriamo sempre con **registri a dimensione fissa** (solitamente a 8 bit, 16 bit, 32 bit o 64 bit).

Vediamo come si possono rappresentare i numeri positivi e negativi (*interi con segno*).

---

### 5.1. Metodo 1: Modulo e Segno (Sign and Magnitude)

È l'approccio più intuitivo:
- Il **bit più a sinistra** (chiamato **MSB**, *Most Significant Bit*) funge da **bit di segno**:
  - `0` indica numero **positivo** ($+$)
  - `1` indica numero **negativo** ($-$)
- I rimanenti $n-1$ bit codificano il **valore assoluto** (modulo) del numero in binario naturale.

:::note[Esempio con registri a 8 bit]
- $+43_{10} = \mathbf{0}0101011_2$ (bit di segno $0$, valore $43$)
- $-43_{10} = \mathbf{1}0101011_2$ (bit di segno $1$, valore $43$)
:::

#### Perché il Modulo e Segno NON viene usato nei calcolatori moderni?
1. **Problema del Doppio Zero:** esistono due rappresentazioni distinte per lo zero:  
   $+0 = 00000000_2$ e $-0 = 10000000_2$. Questo spreca una configurazione e complica la logica di confronto.
2. **Circuiti aritmetici complessi:** per sommare due numeri, la CPU non può semplicemente sommare i bit, ma deve verificare prima i segni, decidere se fare una somma o una sottrazione, e gestire quale dei due operandi abbia valore assoluto maggiore.

---

### 5.2. Metodo 2: Complemento a 1 (Cenno)

Nel complemento a 1:
- I numeri positivi iniziano per `0` e sono codificati normalmente.
- Un numero negativo si ottiene **invertendo tutti i bit** del corrispondente numero positivo ($0 \to 1$ e $1 \to 0$).

Esempio a 8 bit: $+5 = 00000101_2 \implies -5 = 11111010_2$.

Anche il complemento a 1 soffre del problema del **doppio zero** ($+0 = 00000000_2$ e $-0 = 11111111_2$) e richiede la gestione di un riporto circolare durante l'addizione.

---

### 5.3. Metodo 3: Complemento a 2 (Standard Universale)

Il **Complemento a 2** (*Two's Complement*) è la convenzione universale adottata da tutti i processori moderni per rappresentare gli interi con segno.

#### Come calcolare il Complemento a 2 di un numero negativo:
Data la rappresentazione a $n$ bit del numero positivo:
1. **Inverti tutti i bit** (calcola il complemento a 1: $0 \to 1$ e $1 \to 0$).
2. **Somma $1$** al risultato.

$$\text{Regola: } \quad C_2(x) = \overline{x} + 1$$

:::note[Esempio: Rappresentazione di -43 su 8 bit]
1. Scriviamo $+43_{10}$ su 8 bit:  
   $+43_{10} = 00101011_2$
2. Invertiamo tutti i bit:  
   $\overline{43} = 11010100_2$
3. Aggiungiamo 1:  

```text
    11010100 +
           1 =
   ──────────
    11010101   (in binario a 8 bit)
```

Quindi, su 8 bit: $-43_{10} = 11010101_2$.
:::

#### Scorciatoia Pratica: Il Metodo "Da Destra a Sinistra"
Per calcolare il complemento a 2 di un numero negativo senza dover eseguire l'inversione e la successiva addizione $+1$ in colonna, esiste una regola visiva immediata:

> **Regola:**
> 1. Prendi il numero positivo binario e **leggilo partendo da destra verso sinistra ($\leftarrow$)**.
> 2. **Ricopia identici tutti gli eventuali zeri e il primo bit `1` che incontri**.
> 3. Da quel punto in poi, procedendo sempre verso sinistra, **inverti tutti i bit rimanenti** ($0 \to 1$ e $1 \to 0$).

:::note[Esempio 1: Calcolare -40 su 8 bit]
Partiamo dal numero positivo $+40_{10} = 00101000_2$:

| Bit (da sinistra a destra) | $b_7$ | $b_6$ | $b_5$ | $b_4$ | $b_3$ | $b_2$ | $b_1$ | $b_0$ | Azione da destra ($\leftarrow$) |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :--- |
| **Numero positivo ($+40$)** | `0` | `0` | `1` | `0` | **`1`** | **`0`** | **`0`** | **`0`** | Leggi da destra |
| **Passo 1: Copia invariata** | - | - | - | - | **`1`** | **`0`** | **`0`** | **`0`** | Ricopia fino al 1° bit `1` |
| **Passo 2: Inverti a sinistra** | **`1`** | **`1`** | **`0`** | **`1`** | - | - | - | - | Inverti tutti i bit rimasti |
| **Risultato finale ($-40$)** | **`1`** | **`1`** | **`0`** | **`1`** | **`1`** | **`0`** | **`0`** | **`0`** | **$11011000_2$** |
:::

:::note[Esempio 2: Calcolare -43 su 8 bit]
Partiamo dal numero positivo $+43_{10} = 00101011_2$:
- Il primo bit a destra è già un `1`: ricopiamo solo quello (**`1`**).
- Invertiamo tutti i 7 bit posti a sinistra: `0010101` $\to$ **`1101010`**.
- Risultato: $-43_{10} = \mathbf{11010101}_2$.
:::

---

### 5.4. Proprietà Straordinarie del Complemento a 2

#### 1. Il Peso del Bit di Segno (Lettura Diretta del Valore)
Normalmente, per scoprire quale numero decimale negativo corrisponde a una sequenza binaria in complemento a 2 (ad esempio `11010101`), bisognerebbe eseguire un lungo procedimento inverso: ri-applicare il complemento a due (invertire i bit e sommare $1$ per trovare il modulo positivo), calcolare il valore decimale e infine rimettere il segno "$-$".

Esiste però una proprietà straordinaria che ci **risparmia completamente di dover riconvertire il numero**: la consueta formula della notazione posizionale rimane valida per calcolare il valore all'istante, con un'unica fondamentale regola:

> **Il bit più a sinistra ($b_{n-1}$, il bit di segno) ha un peso NEGATIVO pari a $-2^{n-1}$**, mentre tutti gli altri bit conservano i consueti pesi positivi.

$$V = -b_{n-1} \cdot 2^{n-1} + \sum_{k=0}^{n-2} b_k \cdot 2^k$$

:::note[Esempio di Calcolo Diretto: Leggere 11010101 a 8 bit]
I pesi delle colonne a 8 bit sono: $\mathbf{-128}, +64, +32, +16, +8, +4, +2, +1$.

Basta sommare direttamente i pesi delle colonne con bit `1`:

$$\begin{aligned} V &= \mathbf{-128} \cdot 1 + 64 \cdot 1 + 32 \cdot 0 + 16 \cdot 1 + 8 \cdot 0 + 4 \cdot 1 + 2 \cdot 0 + 1 \cdot 1 \\ &= -128 + 64 + 16 + 4 + 1 \\ &= -128 + 85 = \mathbf{-43}_{10} \end{aligned}$$

Otteniamo direttamente $-43_{10}$ in un solo passaggio, senza dover riconvertire o ri-complementare nulla!
:::

#### 2. Intervallo di Rappresentazione (Range) con $n$ bit
Con $n$ bit in complemento a 2:
- Lo **zero è univoco**: $00000000_2 = 0$.
- L'intervallo di valori rappresentabili va da **$-2^{n-1}$** a **$+2^{n-1} - 1$**.

| Dimensione ($n$ bit) | Tipo comune in C/C++ | Valore Minimo | Valore Massimo |
| :---: | :---: | :---: | :---: |
| **8 bit** (1 byte) | `int8_t` / `signed char` | $-2^7 = \mathbf{-128}$ | $+2^7 - 1 = \mathbf{+127}$ |
| **16 bit** (2 byte) | `int16_t` / `short` | $-2^{15} = \mathbf{-32.768}$ | $+2^{15} - 1 = \mathbf{+32.767}$ |
| **32 bit** (4 byte) | `int32_t` / `int` | $-2^{31} \approx \mathbf{-2.147.483.648}$ | $+2^{31} - 1 \approx \mathbf{+2.147.483.647}$ |
| **64 bit** (8 byte) | `int64_t` / `long long` | $-2^{63} \approx -9.22 \times 10^{18}$ | $+2^{63} - 1 \approx +9.22 \times 10^{18}$ |

*(Nota: c'è esattamente un numero negativo in più rispetto ai positivi, poiché lo 0 occupa una combinazione tra i numeri con bit di segno positivo).*

#### 3. La Sottrazione diventa una Semplice Addizione!
Questo è il motivo per cui l'intera industria informatica adotta il complemento a 2:  
Per eseguire $A - B$, la CPU esegue semplicemente la somma tra $A$ e il complemento a 2 di $B$:

$$A - B = A + (-B)$$

Non serve costruire un circuito hardware per la sottrazione: **il sommatore binario della CPU gestisce somme e sottrazioni con la stessa identica operazione!** L'eventuale riporto (*carry*) che fuoriesce dall'ultimo bit ($n$-esimo) viene semplicemente ignorato.

:::note[Esempio di Sottrazione: Calcolare 28 - 12 su 8 bit]
Convertiamo i termini:
- $+28_{10} = 00011100_2$
- $+12_{10} = 00001100_2 \implies -12_{10} = 11110100_2$ (complemento a 2)

Eseguiamo la normale addizione binaria:

```text
    00011100   (+28)  +
    11110100   (-12)  =
  ──────────
  (1)00010000   (+16)
```

Il nono bit di riporto $(1)$ generato a sinistra viene scartato perché lavoriamo a 8 bit.  
Il risultato a 8 bit è $00010000_2 = 16_{10}$, che è esattamente il risultato corretto ($28 - 12 = 16$)!
:::

#### Il Concetto di Overflow
L'**overflow** (o traboccamento) si verifica quando il risultato di un'operazione tra interi con segno eccede l'intervallo di valori rappresentabili nel registro (ad esempio tra $-128$ e $+127$ su 8 bit).

La regola per rilevare l'overflow è immediata:
- **Overflow Positivo:** Somma di due numeri **positivi** che produce un risultato con bit di segno `1` (**negativo**).
- **Overflow Negativo:** Somma di due numeri **negativi** che produce un risultato con bit di segno `0` (**positivo**).
- *(Nota: la somma di due numeri di segno opposto non può **mai** generare overflow, poiché il risultato si avvicina sempre allo zero).*

:::warning[Esempi Pratici di Overflow su 8 bit (Range: da -128 a +127)]
**1. Esempio di Overflow Positivo (+70 + +80 = +150):**  
Il valore teorico $+150$ supera il limite massimo rappresentabile ($+127$):

```text
    01000110   (+70)  +
    01010000   (+80)  =
  ──────────
    10010110   (Bit di segno 1: la CPU legge -106!)
```
*Sommando due numeri positivi la CPU ottiene un numero con bit di segno `1`, producendo l'assurdo risultato $-106_{10}$ anziché $+150$!*

---

**2. Esempio di Overflow Negativo (-70 + -80 = -150):**  
Il valore teorico $-150$ scende al di sotto del valore minimo rappresentabile ($-128$):

```text
    10111010   (-70)  +
    10110000   (-80)  =
  ──────────
  (1)01101010   (Bit di segno 0: la CPU legge +106!)
```
*Sommando due numeri negativi, scartando il nono bit di riporto, la CPU ottiene un numero a 8 bit che inizia con `0`, producendo $+106_{10}$ anziché $-150$!*
:::

:::tip[Perché la somma di due numeri di segno opposto non può MAI causare overflow?]
**Spiegazione intuitiva:**  
L'overflow si verifica soltanto quando il risultato cresce eccessivamente in valore assoluto, finendo per "sfondare" i limiti dell'intervallo (oltre $+127$ o sotto $-128$).

Quando sommiamo un numero positivo $A$ e un numero negativo $-B$, stiamo in realtà effettuando una **differenza**:
$$A + (-B) = A - B$$

Il risultato finale sarà **sempre più vicino allo zero** (e quindi più piccolo in valore assoluto) rispetto all'operando di partenza più grande. Poiché entrambi i numeri iniziali si trovano già all'interno dei limiti validi, il loro risultato rimarrà obbligatoriamente compreso nell'intervallo.

**Verifica sul caso più estremo a 8 bit:**
Prendiamo il massimo numero positivo ($+127$) e il minimo numero negativo ($-128$):
$$+127 + (-128) = \mathbf{-1}_{10}$$
Il risultato ($-1$) è pienamente valido e compreso nell'intervallo $[-128, +127]$. È dunque **matematicamente impossibile** generare overflow con segni opposti.
:::

---

## 6. Mappa di Riepilogo delle Conversioni

| Da $\to$ A | Metodo di Calcolo | Esempio Chiave |
| :--- | :--- | :--- |
| **Base $b \to$ Decimale** | **Forma Polinomiale:** somma delle cifre moltiplicate per le potenze positive e negative della base $b$. | $(1101)_2 = 1\cdot 8 + 1\cdot 4 + 0\cdot 2 + 1\cdot 1 = 13_{10}$ |
| **Decimale $\to$ Base $b$ (Interi)** | **Divisioni successive per $b$:** raccogliere i resti dal basso verso l'alto (dall'ultimo al primo). | $13 : 2 = 6 \text{ (r 1)}, \dots \implies 1101_2$ |
| **Decimale $\to$ Base $b$ (Frazionari)** | **Moltiplicazioni successive per $b$:** raccogliere le parti intere dall'alto verso il basso. | $0.625 \cdot 2 = 1.25 \dots \implies 0.101_2$ |
| **Base $b_1 \to$ Base $b_2$ (Generiche)** | **Ponte in Base 10:** prima $b_1 \to 10$ con il metodo polinomiale, poi $10 \to b_2$ con le divisioni successive. | $(32)_5 \to 17_{10} \to (21)_8$ |
| **Binario $\to$ Esadecimale** | **Raggruppamento a 4 bit (nibble):** da destra a sinistra per gli interi, da sinistra a destra per i decimali. | $10110111_2 \to (\text{B7})_{16}$ |
| **Esadecimale $\to$ Binario** | **Espansione diretta a 4 bit:** sostituire ogni cifra con il suo quartetto binario corrispondente. | $(\text{A3})_{16} \to 1010\ 0011_2$ |
| **Intero Negativo $\to$ Compl. a 2** | **Inversione bit + 1:** oppure copiare invariato fino al primo '1' da destra e poi invertire tutto a sinistra. | $-5_{10} \to \text{da } 00000101 \to 11111011_2$ |

---

## 7. Mettiti alla Prova: Esercizi ed Esercitazioni Pratiche

Per consolidare tutti i concetti appresi e verificare la tua preparazione:

👉 **[Vai alla raccolta completa degli Esercizi sulle Conversioni Numeriche](/manuale-libero-online-di-informatica/conversioni-numeriche/esercizi/)**

Troverai tantissimi esercizi guidati suddivisi in 3 tipologie (Interi Positivi, Numeri con la Virgola, Interi con Segno in Complemento a 2) con soluzioni espandibili a scomparsa e passaggi dettagliati.

Puoi inoltre generare infiniti nuovi esercizi e verificare tutti i passaggi matematici in tempo reale con lo **[Strumento Interattivo per le Conversioni Numeriche](https://4chi11e.github.io/conversioni-numeriche/)**.
