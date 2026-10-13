---
title: Elementi di base
description: Il primo programma, la compilazione, variabili, tipi di dato, operatori, printf e scanf in linguaggio C
---

In questa pagina vediamo i "mattoni" fondamentali di qualsiasi programma C: come si scrive un programma e come lo si trasforma in qualcosa che il computer può eseguire, come si memorizzano i dati nelle **variabili**, quali **tipi di dato** esistono, come si fanno i calcoli e come si comunica con l'utente tramite **input** e **output**.

:::note[Prima di iniziare]
Per scrivere ed eseguire programmi C servono due programmi: un **compilatore** (useremo MinGW, che contiene il compilatore `gcc`) e un **editor** o IDE (consigliato Visual Studio Code). Le istruzioni dettagliate per l'installazione si trovano nel capitolo *Ambiente di sviluppo* dell'eserciziario, linkato nella [pagina introduttiva](../programmazione-in-c/).
:::

## 1. Il primo programma

Il primo programma che si scrive in qualsiasi linguaggio è quello che stampa sullo schermo una frase di saluto. Nonostante sia brevissimo, contiene già molti elementi fondamentali della sintassi del C.

```c
#include <stdio.h>

int main() {
    printf("Ciao mondo!\n");
    return 0;
}
```

```text
Ciao mondo!
```

Analizziamolo riga per riga:

*   `#include <stdio.h>` dice al compilatore di includere la **libreria** `stdio` (*standard input output*), una raccolta di funzioni già pronte per leggere e scrivere dati. Senza questa riga non potremmo usare `printf`. Le righe che iniziano con `#` si chiamano **direttive** e vengono elaborate prima di tutto il resto, durante la compilazione.
*   `int main()` è la **funzione principale**. Ogni programma C deve averne una, ed è da lì che inizia l'esecuzione. La parola `int` prima del nome indica che `main` restituisce un numero intero al sistema operativo; le parentesi tonde indicano che si tratta di una funzione (come in matematica, `f(x)`). Vedremo bene le funzioni nella [pagina dedicata](../funzioni/).
*   Le **parentesi graffe** `{ }` racchiudono un **blocco** di codice: tutto ciò che sta tra le graffe appartiene a `main`.
*   `printf("Ciao mondo!\n");` stampa sullo schermo (più precisamente nel *terminale*) il testo racchiuso tra virgolette. `printf` sta per *print formatted*: vedremo più avanti perché "formatted". La sequenza `\n` significa "vai a capo".
*   Ogni istruzione termina con il **punto e virgola** `;`. Andare a capo dopo ogni istruzione è solo una questione di ordine: per il compilatore conta il `;`.
*   `return 0;` termina il programma comunicando al sistema operativo che tutto è andato bene (per convenzione `0` significa "nessun errore"). In `main` questa riga si può anche omettere, ma è bene abituarsi a scriverla.

:::tip[Il codice deve essere ordinato]
Ogni volta che si apre una graffa e si va a capo, il codice contenuto va **indentato**, cioè spostato a destra di 4 spazi (premete il tasto Tab, non 4 volte lo spazio). Al compilatore l'indentazione non interessa, ma a chi legge sì: un codice non indentato è quasi impossibile da capire e da correggere. In VS Code potete formattare automaticamente il file con `Shift + Alt + F`.
:::

### Dal codice sorgente al programma: la compilazione
Il processore di un computer sa eseguire solo il proprio **linguaggio macchina**, una sequenza di istruzioni binarie molto elementari. Il testo che scriviamo in C (il **codice sorgente**, un file con estensione `.c`) deve quindi essere tradotto in linguaggio macchina da un programma chiamato **compilatore**. Il risultato è un file **eseguibile** (su Windows con estensione `.exe`) che può essere avviato anche su computer dove il compilatore non è installato.

La traduzione avviene in tre fasi principali:

1.  **Preprocessore**: elabora le direttive che iniziano con `#`, ad esempio sostituisce `#include <stdio.h>` con il contenuto del file `stdio.h` ed elimina i commenti.
2.  **Compilazione**: traduce il codice C in linguaggio macchina. È qui che vengono segnalati gli errori di sintassi.
3.  **Linking**: unisce il nostro codice con il codice delle funzioni di libreria che abbiamo usato (come `printf`), producendo l'eseguibile finale.

Normalmente l'estensione di VS Code fa tutto questo premendo il pulsante "play", ma è utile sapere che dietro le quinte viene eseguito un comando di questo tipo:

```text
gcc ciao.c -o ciao.exe
```

che compila `ciao.c` e produce l'eseguibile `ciao.exe` (l'opzione `-o` indica il nome del file di output). Aggiungendo l'opzione `-Wall` il compilatore segnala anche i **warning**, cioè avvisi su parti di codice lecite ma sospette: è un ottimo aiuto per scovare errori.

:::note[Errori di compilazione ed errori di esecuzione]
Se il codice contiene un errore di sintassi (un `;` mancante, una parentesi non chiusa, una variabile non dichiarata...) il compilatore si rifiuta di creare l'eseguibile e segnala la riga dell'errore: il programma **non parte nemmeno**. Altri errori invece si manifestano solo durante l'esecuzione (ad esempio una divisione per zero) oppure non si manifestano affatto, ma il programma produce risultati sbagliati: questi sono errori di **logica** e sono i più difficili da trovare.
:::

### I commenti
I commenti sono parti di testo ignorate dal compilatore, utili a chi legge il codice (compresi voi stessi tra qualche settimana!). In C ne esistono di due tipi:

```c
// commento su una sola riga: tutto ciò che segue // viene ignorato

/* commento
   su più righe */

int eta = 16;   // anche qui posso scrivere un commento
```

:::tip[Commentare velocemente in VS Code]
In VS Code si possono commentare (o togliere il commento a) una o più righe con la combinazione di tasti **`Ctrl + ù`** (sulle tastiere inglesi è `Ctrl + /`): basta posizionare il cursore sulla riga, oppure selezionare più righe, e premere la combinazione. Viene aggiunto `//` all'inizio di ogni riga; premendola di nuovo il commento viene tolto. È comodissimo per "disattivare" temporaneamente una parte di codice mentre si cerca un errore, senza doverla cancellare.
:::

## 2. Le variabili

Per eseguire un qualsiasi calcolo un programma deve poter memorizzare dei dati, come numeri o caratteri. Per farlo si usano le **variabili**: si può immaginare una variabile come una "scatola" in memoria, con un nome, che contiene un valore.

In C, a differenza di linguaggi come Python, ogni variabile deve essere **dichiarata** prima di essere usata, indicandone il **tipo** e il **nome**:

```c
#include <stdio.h>

int main() {
    int a, b;          // dichiarazione di due variabili intere
    float media;       // dichiarazione di una variabile con la virgola

    a = 7;             // assegnamento
    b = 8;
    media = (a + b) / 2.0;

    printf("La media tra %d e %d vale %f\n", a, b, media);
    return 0;
}
```

```text
La media tra 7 e 8 vale 7.500000
```

Dichiarare il tipo serve al compilatore per due motivi:

*   sapere **quanta memoria riservare** alla variabile (un carattere occupa meno spazio di un numero con la virgola);
*   sapere **come sono codificati** i bit contenuti in quella memoria. La stessa sequenza di bit può rappresentare un intero, un numero con la virgola o un carattere a seconda del tipo (vedi la pagina sulla [Rappresentazione dell'Informazione](../../rappresentazione-informazione/rappresentazione-informazione/)).

Quando si dichiara una variabile si dice anche che si crea un'**istanza** di un certo tipo: `int` è un tipo, mentre `a` e `b` sono istanze di `int`. Capiterà spesso di sentire il verbo **istanziare** una variabile.

:::caution[L'uguale non è quello della matematica]
In programmazione `=` è l'**operatore di assegnamento** e significa "**calcola il valore a destra e mettilo nella variabile a sinistra**". Per questo è perfettamente legale (e comunissimo) scrivere:

```c
x = 5;
x = x + 1;   // calcola x + 1 (cioè 6) e mettilo in x
```

Per **confrontare** due valori si usa invece il doppio uguale `==`, che vedremo nelle [strutture di controllo](../strutture-di-controllo/).
:::

### Inizializzazione
Si può assegnare un valore a una variabile già nel momento in cui la si dichiara. Questa operazione si chiama **inizializzazione**:

```c
int contatore = 0;
float prezzo = 9.99, sconto = 0.2;
char lettera = 'a';
```

:::danger[Le variabili non inizializzate contengono "robaccia"]
Quando si dichiara una variabile senza assegnarle un valore, il C **non** la azzera: la variabile contiene i bit che si trovavano per caso in quella zona di memoria, cioè un valore imprevedibile.

```c
int somma;            // contiene un valore casuale!
somma = somma + 5;    // risultato imprevedibile
```

È uno degli errori più frequenti: quando una variabile deve partire da un valore preciso (un contatore, una somma...) ricordatevi sempre di inizializzarla.
:::

### Dove dichiarare le variabili
Nelle prime versioni del linguaggio (lo standard C89) le variabili dovevano essere dichiarate tutte all'inizio di un blocco, prima di qualsiasi altra istruzione. Per questo nel codice più vecchio, e in molti esempi dell'eserciziario, le dichiarazioni sono tutte raccolte in cima al `main`. Dallo standard C99 in poi è possibile dichiarare una variabile in qualsiasi punto, purché **prima** di usarla: è anzi buona abitudine dichiararla il più vicino possibile al punto in cui serve.

### Regole per i nomi delle variabili
*   Possono contenere lettere, cifre e il carattere `_` (underscore), ma **non possono iniziare con una cifra** e non possono contenere spazi o lettere accentate.
*   Il C distingue maiuscole e minuscole: `voto`, `Voto` e `VOTO` sono tre variabili diverse.
*   Non si possono usare le **parole riservate** del linguaggio (`int`, `if`, `for`, `while`, `return`, ...).
*   Per i nomi composti da più parole si usa di solito lo stile *camelCase* (`mediaVoti`) oppure lo stile *snake_case* (`media_voti`). L'importante è scegliere uno stile e usarlo in modo coerente.

Scegliete sempre nomi **significativi**: `base` e `altezza` sono molto più chiari di `a` e `b`.

## 3. I tipi di dato fondamentali

| Tipo | Contenuto | Dimensione tipica | Esempi |
|---|---|---|---|
| `char` | un carattere (in realtà un piccolo intero) | 1 byte | `'a'`, `'Z'`, `'7'`, `'\n'` |
| `int` | numero intero | 4 byte | `5`, `-12`, `0` |
| `float` | numero con la virgola, precisione singola | 4 byte | `3.14f`, `-0.5f` |
| `double` | numero con la virgola, precisione doppia | 8 byte | `3.14`, `2.0`, `1e-3` |

Alcune osservazioni importanti:

*   I numeri con la virgola si scrivono con il **punto**: `3.14`, non `3,14`.
*   Il `double` usa il doppio dei bit del `float` (da cui il nome) ed è quindi più preciso: ha circa 15-16 cifre significative contro le circa 7 del `float`. Nei calcoli conviene preferire `double`. Una costante come `3.14` è considerata un `double`; per indicare un `float` si aggiunge una `f`: `3.14f`.
*   Gli `int` hanno un **limite**: con 4 byte (32 bit) si rappresentano i numeri da -2 147 483 648 a 2 147 483 647. Se un calcolo supera questo limite si verifica un **overflow** e il risultato è sbagliato (tipicamente "ricomincia" dai negativi). Ad esempio il fattoriale di 13 non sta già più in un `int`.
*   Il `char` contiene un singolo carattere, scritto tra **apici singoli** (`'a'`). Le **virgolette doppie** (`"a"`) indicano invece una stringa, che è un'altra cosa (vedi la pagina sulle [stringhe](../stringhe/)).

### Modificatori: `unsigned`, `long`, `short`
Il tipo `int` si può "modificare" per ottenere interi più grandi, più piccoli o senza segno:

| Tipo | Dimensione tipica | Intervallo |
|---|---|---|
| `short` | 2 byte | da -32 768 a 32 767 |
| `int` | 4 byte | circa ± 2 miliardi |
| `unsigned int` | 4 byte | da 0 a circa 4 miliardi |
| `long long` | 8 byte | circa ± 9 · 10¹⁸ |

Le dimensioni esatte dipendono dal sistema: per conoscerle si usa l'operatore `sizeof`, che restituisce il numero di byte occupati da un tipo o da una variabile:

```c
printf("Un int occupa %d byte\n", (int)sizeof(int));
printf("Un double occupa %d byte\n", (int)sizeof(double));
```

(Il `(int)` davanti a `sizeof` è una conversione di tipo, spiegata più sotto: `sizeof` restituisce un tipo speciale chiamato `size_t` che si stamperebbe con `%zu`.)

### I caratteri sono numeri
Un `char` è in realtà un numero intero di un byte: il **codice ASCII** del carattere (vedi la pagina su [codifiche e caratteri](../../rappresentazione-informazione/codifiche/)). Lo stesso valore può essere stampato come carattere o come numero:

```c
char c = 'A';
printf("%c %d\n", c, c);        // A 65
printf("%c\n", c + 1);          // B
printf("%d\n", '7' - '0');      // 7: trasforma il carattere '7' nel numero 7
```

Questo permette dei trucchi molto utili: le lettere dell'alfabeto hanno codici consecutivi (`'a'` = 97, `'b'` = 98, ...), così come le cifre (`'0'` = 48, `'1'` = 49, ...). Per sapere se `c` è una lettera minuscola basta controllare che sia compreso tra `'a'` e `'z'`.

### Il tipo booleano
Nelle prime versioni del C non esisteva un tipo per i valori logici vero/falso: si usano gli interi, con la convenzione che **0 significa falso** e **qualsiasi altro valore significa vero**. Dallo standard C99 è disponibile la libreria `stdbool.h`, che definisce il tipo `bool` e i valori `true` e `false`, supportata da tutti i compilatori moderni. Ne parleremo nelle [strutture di controllo](../strutture-di-controllo/#il-vero-e-il-falso-in-c).

### Le costanti
Spesso nel programma compaiono valori fissi che non devono cambiare, come il numero di elementi di un elenco o il valore di π. Invece di scriverli "a mano" in più punti, conviene dare loro un nome. Il modo più usato in C è la direttiva `#define`:

```c
#include <stdio.h>

#define PI 3.14159
#define N 10

int main() {
    double raggio = 2;
    printf("Circonferenza: %f\n", 2 * PI * raggio);
    printf("Elementi: %d\n", N);
    return 0;
}
```

`#define` è una direttiva per il preprocessore: prima della compilazione ogni occorrenza di `PI` nel codice viene **sostituita** con `3.14159`. Notate che non c'è né `=` né `;`. Per convenzione i nomi delle costanti si scrivono in MAIUSCOLO.

In alternativa si può usare la parola chiave `const` davanti a una normale dichiarazione: `const double PI = 3.14159;`. Il compilatore segnalerà un errore se si prova a modificarne il valore.

## 4. Gli operatori aritmetici

| Operatore | Operazione | Esempio | Risultato |
|---|---|---|---|
| `+` | somma | `7 + 2` | `9` |
| `-` | sottrazione | `7 - 2` | `5` |
| `*` | moltiplicazione | `7 * 2` | `14` |
| `/` | divisione | `7 / 2` <br/> `7.0 / 2` | `3` <br/> `3.5` |
| `%` | resto della divisione intera (modulo) | `7 % 2` | `1` |

L'ordine delle operazioni è quello della matematica: prima `*`, `/` e `%`, poi `+` e `-`. In caso di dubbio usate le **parentesi tonde**. In C **non esiste** un operatore per l'elevamento a potenza: si usa la funzione `pow` (vedi più sotto) oppure, per potenze piccole, la moltiplicazione (`x * x`).

:::caution[La divisione tra interi]
Se **entrambi** gli operandi sono interi, anche il risultato della divisione è intero: la parte decimale viene semplicemente **troncata**. `7 / 2` vale `3`, e `1 / 2` vale `0`!

```c
int a = 7, b = 2;
float r;

r = a / b;          // r vale 3.0: la divisione è fatta tra interi, PRIMA di assegnare
r = (float)a / b;   // r vale 3.5
r = a / 2.0;        // r vale 3.5: 2.0 è un double
```

Per ottenere un risultato con la virgola, **almeno uno** dei due operandi deve essere un numero con la virgola. Notate che non basta che la variabile a sinistra sia `float`: l'assegnamento avviene dopo che la divisione è già stata calcolata.
:::

L'operatore `%` (resto) si usa con i soli interi ed è utilissimo:

*   `n % 2 == 0` controlla se un numero è **pari**;
*   `a % b == 0` controlla se `a` è **multiplo** di `b` (cioè se `b` è un divisore di `a`);
*   `n % 10` restituisce l'**ultima cifra** di un numero, mentre `n / 10` la "toglie".

### Conversioni di tipo (cast)
Quando in un'espressione compaiono tipi diversi, il C converte automaticamente il tipo "più piccolo" in quello "più grande" (ad esempio `int` in `double`). Quando si assegna un valore con la virgola a una variabile intera, invece, la parte decimale viene troncata:

```c
int x = 3.9;    // x vale 3
```

Per forzare una conversione si usa l'operatore di **cast**, scrivendo il tipo desiderato tra parentesi davanti al valore: `(float)a`, `(int)3.9`, `(double)somma / n`.

### Incremento, decremento e assegnamento composto
Capita continuamente di dover aggiornare una variabile usando il suo stesso valore. Esistono delle abbreviazioni:

```c
i++;            // equivale a i = i + 1
i--;            // equivale a i = i - 1
totale += 30;   // equivale a totale = totale + 30
totale -= 5;    // totale = totale - 5
prodotto *= 2;  // prodotto = prodotto * 2
media /= n;     // media = media / n
resto %= 10;    // resto = resto % 10
```

Gli operatori `++` e `--` si possono scrivere anche prima della variabile (`++i`). Se usati da soli in un'istruzione non c'è differenza; se invece compaiono dentro un'espressione più complessa il comportamento cambia (`x = i++` assegna a `x` il vecchio valore di `i`, `x = ++i` il nuovo). Per evitare confusione, conviene usarli **solo come istruzioni a sé stanti**.

### Funzioni matematiche
Le funzioni matematiche si trovano nella libreria `math.h` e lavorano con i `double`:

| Funzione | Descrizione | Esempio | Risultato |
|---|---|---|---|
| `sqrt(x)` | radice quadrata | `sqrt(16)` | `4.0` |
| `pow(x, y)` | potenza x<sup>y</sup> | `pow(2, 10)` | `1024.0` |
| `fabs(x)` | valore assoluto | `fabs(-2.5)` | `2.5` |
| `floor(x)` | approssimazione per difetto | `floor(3.7)` | `3.0` |
| `ceil(x)` | approssimazione per eccesso | `ceil(3.2)` | `4.0` |
| `round(x)` | arrotondamento all'intero più vicino | `round(3.5)` | `4.0` |

```c
#include <stdio.h>
#include <math.h>

int main() {
    double c1 = 3, c2 = 4;
    double ipotenusa = sqrt(pow(c1, 2) + pow(c2, 2));
    printf("Ipotenusa: %g\n", ipotenusa);   // Ipotenusa: 5
    return 0;
}
```

Il valore assoluto di un **intero** si calcola invece con `abs`, che si trova nella libreria `stdlib.h`.

:::note
Su Linux e macOS, quando si usano le funzioni di `math.h`, può essere necessario aggiungere l'opzione `-lm` al comando di compilazione (`gcc prog.c -o prog -lm`) per collegare la libreria matematica. Su Windows con MinGW non serve.
:::

## 5. Output: la funzione `printf`

`printf` riceve come primo parametro una **stringa di formato**, cioè il testo da stampare, al cui interno si possono inserire dei **segnaposto** (detti *specificatori di formato*) che iniziano con `%`. Al posto di ogni segnaposto viene stampato il valore dei parametri successivi, nell'ordine:

```c
int a = 12, b = 5;
printf("%d + %d = %d\n", a, b, a + b);
printf("%d / %d = %d con resto %d\n", a, b, a / b, a % b);
```

```text
12 + 5 = 17
12 / 5 = 2 con resto 2
```

Lo specificatore deve corrispondere al **tipo** del valore da stampare: `printf` non ha modo di sapere di che tipo sia la variabile, si fida di quello che le diciamo. Se si stampa un `int` con `%f` (o viceversa) il risultato è un numero senza senso.

| Specificatore | Tipo | Esempio | Output |
|---|---|---|---|
| `%d` | `int` | `printf("%d", 42)` | `42` |
| `%f` | `float` e `double` (6 decimali) | `printf("%f", 3.5)` | `3.500000` |
| `%g` | `float` e `double`, senza zeri inutili | `printf("%g", 3.5)` | `3.5` |
| `%e` | notazione esponenziale | `printf("%e", 1500.0)` | `1.500000e+03` |
| `%c` | `char` (come carattere) | `printf("%c", 'a')` | `a` |
| `%s` | stringa | `printf("%s", "ciao")` | `ciao` |
| `%x` | `int` in esadecimale | `printf("%x", 255)` | `ff` |
| `%%` | il carattere `%` | `printf("100%%")` | `100%` |

Per i `double` si può usare anche `%lf`, che in `printf` è equivalente a `%f`. Attenzione però: in `scanf` le due cose **non** sono equivalenti, come vedremo tra poco.

### Formattare l'output
Tra `%` e la lettera si possono aggiungere delle indicazioni su **come** stampare il valore:

| Formato | Significato | Esempio | Output |
|---|---|---|---|
| `%.2f` | 2 cifre decimali | `printf("%.2f", 3.14159)` | `3.14` |
| `%5d` | intero su almeno 5 caratteri, allineato a destra | `printf("%5d", 42)` | `   42` |
| `%-5d` | come sopra, ma allineato a sinistra | `printf("%-5d\|", 42)` | `42   \|` |
| `%05d` | riempie con zeri invece che con spazi | `printf("%05d", 42)` | `00042` |
| `%8.2f` | almeno 8 caratteri in tutto, di cui 2 decimali | `printf("%8.2f", 3.14159)` | `    3.14` |

Il numero dopo `%` indica l'ingombro **minimo**: se il valore è più lungo viene stampato per intero. I formati con la larghezza (`%3d`, `%5d`...) sono fondamentali per stampare tabelle e [matrici](../matrici/) ben incolonnate.

### Le sequenze di escape
Alcuni caratteri non si possono scrivere direttamente dentro una stringa, perché hanno un significato speciale. Si scrivono allora preceduti dalla barra rovesciata `\`:

| Sequenza | Significato |
|---|---|
| `\n` | a capo (*new line*) |
| `\t` | tabulazione |
| `\"` | virgolette doppie (senza `\` chiuderebbero la stringa) |
| `\'` | apice singolo |
| `\\` | barra rovesciata |
| `\0` | carattere nullo, il terminatore delle [stringhe](../stringhe/) |

```c
printf("Ha detto: \"Ciao!\"\n");    // Ha detto: "Ciao!"
printf("Nome\tCognome\n");          // Nome    Cognome
```

## 6. Input: la funzione `scanf`

La funzione `scanf` (*scan formatted*) legge dati dalla tastiera e li memorizza nelle variabili. Funziona in modo analogo a `printf`, con gli stessi specificatori di formato:

```c
#include <stdio.h>

int main() {
    double base, altezza;

    printf("Scrivi il valore della base: ");
    scanf("%lf", &base);
    printf("Scrivi il valore dell'altezza: ");
    scanf("%lf", &altezza);

    printf("L'area del triangolo vale %g\n", base * altezza / 2);
    return 0;
}
```

```text
Scrivi il valore della base: 4
Scrivi il valore dell'altezza: 3
L'area del triangolo vale 6
```

C'è però una differenza fondamentale: le variabili da riempire vanno scritte precedute dal simbolo **`&`**. L'operatore `&` restituisce l'**indirizzo** in memoria della variabile: a `scanf` non serve sapere quanto vale la variabile (vale "robaccia", visto che deve ancora essere riempita), ma **dove si trova**, per poterci scrivere dentro. Questo meccanismo verrà spiegato a fondo nella pagina sui [puntatori](../puntatori/).

:::caution[Errori classici con `scanf`]
*   **Dimenticare la `&`**: `scanf("%d", n);` compila (al massimo con un warning) ma fa scrivere `scanf` in un punto casuale della memoria, con conseguenze imprevedibili, spesso il crash del programma.
*   **Sbagliare lo specificatore per i `double`**: in `scanf` si usa `%f` per i `float` e `%lf` per i `double`. Leggere un `double` con `%f` produce valori senza senso.
*   **Scrivere testo nella stringa di formato**: `scanf("Inserisci un numero %d", &n);` non stampa nulla, ma si aspetta che l'utente scriva esattamente "Inserisci un numero" prima del numero! I messaggi vanno stampati con `printf`, la stringa di `scanf` deve contenere solo gli specificatori.
:::

### Leggere più valori insieme
Con una sola `scanf` si possono leggere più valori. L'utente può separarli con spazi o andando a capo:

```c
int giorno, mese, anno;
printf("Inserisci una data (gg mm aaaa): ");
scanf("%d %d %d", &giorno, &mese, &anno);
```

Se nella stringa di formato si inserisce un carattere diverso dallo spazio, l'utente deve scriverlo esattamente: con `scanf("%d/%d/%d", &giorno, &mese, &anno);` la data va scritta come `25/12/2025`.

### Il valore restituito da `scanf`
`scanf` restituisce il **numero di valori letti correttamente**. Se l'utente scrive `ciao` quando ci si aspetta un numero, la lettura fallisce, la variabile non viene modificata e `scanf` restituisce 0. Si può sfruttare questo valore per controllare l'input:

```c
int n;
printf("Inserisci un numero: ");
if (scanf("%d", &n) != 1) {
    printf("Non hai inserito un numero!\n");
    return 1;
}
```

(Il costrutto `if` è spiegato nella prossima pagina.)

### Leggere un carattere: lo spazio prima di `%c`
Quando l'utente preme Invio, anche il carattere "a capo" viene inviato al programma e rimane in attesa di essere letto (si dice che resta nel **buffer** di input). Gli specificatori `%d`, `%f`, `%s` saltano automaticamente spazi e a capo, `%c` invece no: legge qualunque carattere, compreso l'a capo rimasto dalla lettura precedente.

```c
int n;
char risposta;

scanf("%d", &n);
scanf("%c", &risposta);    // SBAGLIATO: legge l'a capo rimasto dopo il numero
scanf(" %c", &risposta);   // CORRETTO: lo spazio prima di %c salta spazi e a capo
```

Lo **spazio prima di `%c`** dice a `scanf` di scartare tutti gli spazi, le tabulazioni e gli a capo prima di leggere il carattere.

La lettura di parole e frasi intere verrà spiegata nella pagina sulle [stringhe](../stringhe/#4-input-e-output-di-stringhe).

## 7. Numeri casuali

Per giochi, simulazioni e per riempire velocemente elenchi di dati di prova, è utile saper generare numeri casuali. In realtà un computer genera numeri **pseudocasuali**: sequenze di numeri calcolate da un algoritmo deterministico, ma che "sembrano" casuali (la loro distribuzione statistica è analoga a quella di una sequenza veramente casuale).

```c
#include <stdio.h>
#include <stdlib.h>   // rand, srand
#include <time.h>     // time

int main() {
    srand(time(NULL));          // da fare UNA sola volta, all'inizio del programma

    int dado = rand() % 6 + 1;  // numero casuale tra 1 e 6
    printf("Hai tirato: %d\n", dado);
    return 0;
}
```

*   `rand()` restituisce un intero pseudocasuale compreso tra 0 e una costante molto grande chiamata `RAND_MAX`.
*   L'algoritmo parte da un valore iniziale detto **seme** (*seed*): a parità di seme, la sequenza generata è sempre la stessa. Per ottenere sequenze diverse a ogni esecuzione si cambia il seme con `srand`, passandogli l'ora attuale ottenuta con `time(NULL)`, che è sempre diversa. `srand` va chiamata **una sola volta**, all'inizio del `main`, non prima di ogni `rand()`.

### Numeri casuali in un intervallo
Per ottenere un numero casuale compreso tra `min` e `max` (estremi inclusi) si usa la formula:

```c
int x = rand() % (max - min + 1) + min;
```

Per capirla, ricostruiamola con un esempio in cui vogliamo un numero tra 3 e 5:

1.  `rand() % k` dà per forza un numero tra 0 e k-1, perché il resto della divisione per k non può superare k-1;
2.  i numeri da estrarre sono 3, 4, 5, cioè 3 numeri: la differenza tra gli estremi più uno, `5 - 3 + 1` (facendo solo la differenza si "perde" un estremo);
3.  per ottenere 3, 4, 5 si estrae un numero tra 0, 1, 2 e poi gli si aggiunge 3, cioè `min`.

Mettendo insieme i tre passaggi si ottiene `rand() % (5 - 3 + 1) + 3`, cioè `rand() % (max - min + 1) + min`.

## 8. Errori comuni

| Errore | Conseguenza |
|---|---|
| `;` dimenticato alla fine di un'istruzione | Errore di compilazione, spesso segnalato sulla riga **successiva** |
| Variabile usata senza essere dichiarata, o nome scritto male (maiuscole!) | Errore di compilazione: `'x' undeclared` |
| Variabile non inizializzata | Il programma compila, ma usa valori casuali |
| Divisione tra interi quando serviva un risultato con la virgola | Risultato troncato: `1 / 2` vale `0` |
| Specificatore di formato sbagliato (`%d` per un `double`, `%f` in `scanf` per un `double`) | Valori stampati o letti senza senso |
| `&` dimenticata in `scanf` | Crash o comportamento imprevedibile |
| `"a"` al posto di `'a'` per un carattere | Errore o warning: `"a"` è una stringa, non un `char` |
| Overflow di un `int` | Risultati sbagliati (anche negativi) senza alcun messaggio di errore |

:::tip[Leggere i messaggi del compilatore]
Quando la compilazione fallisce, il compilatore stampa l'elenco degli errori indicando file, riga e colonna (ad esempio `ciao.c:5:5: error: ...`). Partite sempre dal **primo** errore della lista: spesso gli errori successivi sono solo una conseguenza del primo, e spariscono una volta corretto quello. Non ignorate i **warning**: quasi sempre segnalano un vero problema.
:::

## Esercizi

Gli esercizi relativi a questi argomenti si trovano nel capitolo **"Introduzione e strutture di controllo"** dell'eserciziario (sezione *Variabili operazioni e stampe*), linkato nella [pagina introduttiva](../programmazione-in-c/).
