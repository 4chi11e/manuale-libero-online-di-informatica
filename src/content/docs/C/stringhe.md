---
title: Stringhe
description: Stringhe in C come array di caratteri, il terminatore, input e output, le funzioni di string.h e ctype.h, sscanf, sprintf, tokenizzazione e array di stringhe
---

Una **stringa** è una sequenza di caratteri: una parola, una frase, un nome, il contenuto di una riga di un file. Nei linguaggi di alto livello esiste un tipo apposito per rappresentarle (`string` in C++, `str` in Python). Il C, essendo un linguaggio relativamente di basso livello, **non ha un tipo stringa**: le stringhe sono semplicemente **[array](../array/) di `char`**, e come array vanno trattate. Questo rende le stringhe in C un po' più scomode da usare che in altri linguaggi, ma permette di capire bene come funzionano davvero.

## 1. Il carattere terminatore

Ogni stringa in C termina con un carattere speciale, il **carattere nullo** `'\0'`, che segna la fine del testo. Tutte le funzioni che lavorano con le stringhe (`printf`, `strlen`, `strcpy`...) scorrono i caratteri uno dopo l'altro finché non incontrano `'\0'`: è grazie a lui che sanno dove la stringa finisce.

```text
char s[10] = "Ciao";

indice:   0     1     2     3     4     5     6     7     8     9
        +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    s:  | 'C' | 'i' | 'a' | 'o' | \0  | \0  | \0  | \0  | \0  | \0  |
        +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
```

Ne derivano alcune conseguenze importanti:

*   un array di 10 `char` può contenere stringhe di **al massimo 9 caratteri**: un posto va sempre lasciato al terminatore;
*   la **lunghezza** di una stringa (il numero di caratteri "veri", 4 nell'esempio) è in generale diversa dalla **dimensione** dell'array (10);
*   il carattere `'\0'` ha codice ASCII 0, per questo in alcuni programmi si trova scritto semplicemente `0`. Non va confuso con il carattere `'0'` (la cifra zero), che ha codice ASCII 48.

:::danger[Senza terminatore è il caos]
Se una stringa non termina con `'\0'`, le funzioni che la usano continuano a leggere la memoria che segue l'array finché, per caso, non trovano un byte che vale 0. Il risultato sono caratteri strani stampati dopo il testo, o il crash del programma. Ogni volta che costruite una stringa carattere per carattere, **ricordatevi di aggiungere il terminatore alla fine**.
:::

## 2. Dichiarazione e inizializzazione

Le stringhe si dichiarano come array di `char`. Come per gli array numerici, conviene usare una costante per la dimensione:

```c
#define N 30

int main() {
    char nome[N];           // può contenere stringhe fino a 29 caratteri
    // ...
    return 0;
}
```

Nella dichiarazione si può assegnare subito un valore. Le due righe seguenti sono equivalenti: in entrambi i casi viene creato un array di 5 `char` (4 lettere più il terminatore):

```c
char s1[] = "Ciao";
char s2[] = {'C', 'i', 'a', 'o', '\0'};
```

Il testo tra virgolette doppie (`"Ciao"`) si chiama **stringa letterale**: il terminatore viene aggiunto automaticamente dal compilatore. Se si indica una dimensione più grande del necessario, come in `char s[N] = "Ciao";`, i caratteri rimanenti vengono riempiti con `'\0'`.

:::caution[Dopo la dichiarazione `=` e `==` non funzionano]
Esattamente come per gli array numerici, l'assegnamento con `=` è possibile solo nella dichiarazione. Dopo, le stringhe **non si possono copiare con `=`** e **non si possono confrontare con `==`**, `<` o `>`:

```c
char s[N];
s = "Ciao";             // ERRORE di compilazione

char a[N] = "Roma", b[N] = "Roma";
if (a == b) {           // compila, ma è SEMPRE falso!
    // ...
}
```

Il confronto `a == b` non confronta i caratteri ma gli **indirizzi** in memoria dei due array, che sono sempre diversi (ne parleremo nella pagina sui [puntatori](../puntatori/)). Per copiare e confrontare le stringhe bisogna lavorare carattere per carattere, oppure usare le funzioni della libreria `string.h` descritte più avanti.
:::

## 3. Scorrere una stringa carattere per carattere

Essendo un array, si può accedere a ogni carattere di una stringa con il suo indice: `s[0]` è il primo carattere. Per scorrere una stringa, però, di solito non si usa la dimensione dell'array, ma ci si ferma quando si incontra il terminatore:

```c
char s[] = "Programmazione in C";
int vocali = 0;

for (int i = 0; s[i] != '\0'; i++) {
    char c = s[i];
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        vocali++;
    }
}
printf("La frase contiene %d vocali\n", vocali);
```

Ecco come si copia una stringa in un'altra senza usare librerie. Notate l'aggiunta del terminatore alla fine, che il ciclo non copia perché si ferma prima:

```c
char s1[N] = "ciao", s2[N];
int i;
for (i = 0; s1[i] != '\0'; i++) {
    s2[i] = s1[i];
}
s2[i] = '\0';           // terminatore
```

### Lavorare con i caratteri: la libreria `ctype.h`
Poiché i caratteri sono numeri (il loro [codice ASCII](../elementi-di-base/#i-caratteri-sono-numeri)) e le lettere hanno codici consecutivi, molte operazioni si possono fare con semplici confronti e calcoli:

```c
if (c >= 'a' && c <= 'z') {     // c è una lettera minuscola
    c = c - 'a' + 'A';          // la trasforma nella maiuscola corrispondente
}
```

Il calcolo `c - 'a'` dà la posizione della lettera nell'alfabeto (0 per `'a'`, 1 per `'b'`...); aggiungendo `'A'` si ottiene la lettera maiuscola nella stessa posizione. Per comodità, la libreria `ctype.h` fornisce funzioni già pronte per questi controlli e conversioni:

| Funzione | Restituisce |
|---|---|
| `isalpha(c)` | vero se `c` è una lettera |
| `isdigit(c)` | vero se `c` è una cifra (`'0'`...`'9'`) |
| `isalnum(c)` | vero se `c` è una lettera o una cifra |
| `isspace(c)` | vero se `c` è uno spazio, una tabulazione o un a capo |
| `isupper(c)` / `islower(c)` | vero se `c` è una lettera maiuscola / minuscola |
| `toupper(c)` / `tolower(c)` | la versione maiuscola / minuscola di `c` (se `c` non è una lettera lo restituisce invariato) |

```c
#include <stdio.h>
#include <ctype.h>

int main() {
    char s[] = "CiAo a TuTtI";

    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = toupper(s[i]);       // modifica la stringa
    }
    printf("%s\n", s);              // CIAO A TUTTI

    return 0;
}
```

Notate che `toupper` **non modifica** il carattere che riceve, ma **restituisce** il carattere convertito: per modificare la stringa bisogna riassegnarlo, come in `s[i] = toupper(s[i]);`.

## 4. Input e output di stringhe

### Stampare
Per stampare una stringa si usa `printf` con lo specificatore `%s`. Come per i numeri, si può controllare la formattazione:

| Formato | Significato |
|---|---|
| `%s` | stampa la stringa così com'è |
| `%10s` | occupa almeno 10 caratteri, allineando la stringa a destra (spazi prima) |
| `%-10s` | occupa almeno 10 caratteri, allineando la stringa a sinistra (spazi dopo) |
| `%.5s` | stampa al massimo i primi 5 caratteri |
| `%10.5s` | al massimo 5 caratteri, su uno spazio di almeno 10 |
| `%.*s` | come `%.5s`, ma il numero di caratteri è passato come parametro |

Questi formati sono particolarmente utili per costruire tabelle allineate:

```c
printf("|%-10s|%-10s|\n", "Nome", "Cognome");
printf("|%-10s|%-10s|\n", "Mario", "Rossi");
printf("|%-10s|%-10s|\n", "Giovanni", "Bianchi");

char s[] = "programmazione";
int n = 4;
printf("%.*s\n", n, s);         // prog
```

```text
|Nome      |Cognome   |
|Mario     |Rossi     |
|Giovanni  |Bianchi   |
prog
```

### Leggere una parola con `scanf`
Per leggere una stringa con `scanf` si usa `%s`. A differenza delle variabili numeriche, il nome della stringa va scritto **senza `&`**: il nome di un array rappresenta già l'indirizzo del suo primo elemento (il motivo sarà chiaro nella pagina sui [puntatori](../puntatori/)).

```c
char nome[30];
printf("Come ti chiami? ");
scanf("%29s", nome);            // niente & con le stringhe
printf("Ciao %s!\n", nome);
```

Due osservazioni importanti:

*   `%s` legge **una sola parola**: si ferma al primo spazio o a capo. Se l'utente scrive "Mario Rossi", in `nome` finisce solo "Mario" (e "Rossi" resta in attesa di essere letto dalla prossima `scanf`).
*   Il numero in `%29s` indica il **massimo** numero di caratteri da leggere: senza questo limite, se l'utente scrivesse una parola più lunga dell'array, `scanf` continuerebbe a scrivere oltre la fine, sovrascrivendo altre zone di memoria (si chiama *buffer overflow* ed è una delle vulnerabilità più sfruttate dagli attacchi informatici). Si scrive 29 e non 30 per lasciare spazio al terminatore.

### Leggere una frase intera
Per leggere una riga intera, spazi compresi, ci sono due metodi.

**Metodo 1: `scanf` con uno *scanset*.** Al posto di `%s` si indica tra parentesi quadre l'insieme dei caratteri ammessi. Scrivendo `[^\n]`, con il simbolo `^` all'inizio, si indica invece l'insieme dei caratteri **non** ammessi, cioè quelli che fanno terminare la lettura: in questo caso l'a capo.

```c
scanf(" %29[^\n]", frase);      // legge fino a 29 caratteri o fino all'a capo (escluso)
```

Lo **spazio** prima di `%` serve a scartare eventuali spazi e a capo iniziali, ad esempio quello rimasto in sospeso dopo una lettura precedente (è lo stesso trucco visto per [`%c`](../elementi-di-base/#leggere-un-carattere-lo-spazio-prima-di-c)).

**Metodo 2: `fgets`.** È una funzione più generale, che legge una riga da qualsiasi sorgente di input: la useremo anche per leggere i [file di testo](../file/). Riceve, in ordine, la stringa in cui scrivere, la sua dimensione (per non uscire dall'array) e la sorgente, che per la tastiera è `stdin` (*standard input*).

```c
fgets(frase, sizeof(frase), stdin);
frase[strcspn(frase, "\n")] = '\0';     // elimina l'a capo finale
```

`fgets` ha un vantaggio su `scanf`: la dimensione massima si indica come parametro, mentre in `scanf` il limite va scritto a mano dentro la stringa di formato (non si può scrivere `%N[^\n]` usando una costante). C'è però un dettaglio da gestire: `fgets` inserisce nella stringa **anche il carattere `'\n'`** finale, se c'è spazio. La seconda riga lo elimina: la funzione `strcspn(frase, "\n")` restituisce la posizione del primo `'\n'` (o la lunghezza della stringa, se non c'è), e in quella posizione si scrive il terminatore. Il funzionamento di `strcspn` è spiegato più avanti.

:::caution[Mescolare `scanf` e `fgets`]
Dopo aver letto un numero con `scanf("%d", &n)`, l'a capo premuto dall'utente resta nel buffer di input. Se subito dopo si chiama `fgets`, questa legge quell'a capo come se fosse una riga vuota e termina immediatamente, senza dare all'utente la possibilità di scrivere. Le soluzioni sono due: usare per la frase `scanf(" %29[^\n]", ...)`, il cui spazio iniziale scarta l'a capo, oppure svuotare il buffer prima di `fgets`:

```c
scanf("%d", &n);
while (getchar() != '\n');      // scarta tutti i caratteri fino all'a capo compreso
fgets(frase, sizeof(frase), stdin);
```
:::

:::danger[Non usate `gets`]
Online, e in programmi vecchi, potreste trovare la funzione `gets(s)` per leggere una riga. È **pericolosa** perché non permette di indicare la dimensione dell'array: se l'utente scrive troppi caratteri, `gets` scrive oltre la fine della stringa. Per questo è stata **eliminata** dallo standard C11. Usate sempre `fgets`.
:::

## 5. Le funzioni della libreria `string.h`

Per fortuna non è necessario scrivere a mano ogni volta i cicli per copiare, confrontare o misurare le stringhe: la libreria `string.h` contiene funzioni già pronte.

| Funzione | Cosa fa | Equivalente "intuitivo" |
|---|---|---|
| `strlen(s)` | restituisce il numero di caratteri di `s` (terminatore escluso) | lunghezza di `s` |
| `strcpy(dest, src)` | copia `src` in `dest` | `dest = src` |
| `strcat(dest, src)` | aggiunge `src` in fondo a `dest` | `dest = dest + src` |
| `strcmp(s1, s2)` | confronta due stringhe in ordine alfabetico | `s1 == s2`, `s1 < s2`, ... |
| `strchr(s, c)` | cerca il carattere `c` in `s` | |
| `strstr(s, sub)` | cerca la stringa `sub` dentro `s` | |
| `strcspn(s, car)` | restituisce quanti caratteri ci sono all'inizio di `s` prima di uno dei caratteri di `car` | |

```c
#include <stdio.h>
#include <string.h>

#define N 30

int main() {
    char s1[N] = "mi chiamo Francesco";
    char s2[N] = "io invece Paolo";

    // copia
    strcpy(s1, "Ciao");
    printf("s1: %s\n", s1);                     // Ciao
    strcpy(s1, s2);
    printf("s1: %s\n", s1);                     // io invece Paolo

    // concatenazione
    char saluto[N] = "Ciao";
    strcat(saluto, " ");
    strcat(saluto, "belli!");
    printf("%s\n", saluto);                     // Ciao belli!

    // lunghezza
    printf("Lunghezza: %d\n", (int)strlen(saluto));    // 11

    // confronto
    printf("%d\n", strcmp("Milano", "Roma") < 0);      // 1: Milano viene prima
    if (strcmp(s1, s2) == 0) {
        printf("s1 e s2 sono uguali\n");
    }

    return 0;
}
```

### Il confronto con `strcmp`
`strcmp(s1, s2)` confronta le due stringhe carattere per carattere e restituisce:

*   un numero **negativo** se `s1` viene **prima** di `s2` in ordine alfabetico;
*   **0** se le due stringhe sono **uguali**;
*   un numero **positivo** se `s1` viene **dopo** `s2`.

Lo standard non garantisce che i valori siano esattamente -1 e 1, quindi il risultato va sempre confrontato con 0: `strcmp(a, b) < 0` per "a viene prima di b", `strcmp(a, b) == 0` per "sono uguali". L'errore più comune è scrivere `if (strcmp(a, b))` pensando che significhi "se sono uguali": succede esattamente il contrario, perché quando sono uguali `strcmp` restituisce 0, cioè falso!

:::note[L'ordine "alfabetico" è in realtà l'ordine ASCII]
`strcmp` confronta i codici ASCII dei caratteri. Nella tabella ASCII tutte le lettere maiuscole vengono prima delle minuscole, quindi per `strcmp` `"Zebra"` viene prima di `"ape"`. Per un confronto che non tenga conto di maiuscole e minuscole bisogna convertire prima le stringhe (ad esempio tutte in minuscolo).
:::

### Attenzione allo spazio
`strcpy` e `strcat` non controllano che nella stringa di destinazione ci sia abbastanza spazio: è responsabilità del programmatore garantire che `dest` sia abbastanza grande da contenere il risultato, terminatore compreso. In caso contrario si ha un *buffer overflow*, con le conseguenze già descritte.

Esiste la variante `strncpy(dest, src, n)` che copia al massimo `n` caratteri, ma attenzione: se `src` è più lunga di `n` caratteri, il terminatore **non viene aggiunto** e bisogna metterlo a mano.

```c
strncpy(dest, src, N - 1);
dest[N - 1] = '\0';
```

:::note[`strlen` restituisce un `size_t`]
`strlen` (come `sizeof` e `strcspn`) restituisce un valore di tipo `size_t`, un intero senza segno che si stamperebbe con `%zu`. Per semplicità si può convertire in `int` con un cast, come nell'esempio: `(int)strlen(s)`. Inoltre, `strlen` scorre ogni volta tutta la stringa per contarne i caratteri: in un ciclo come `for (i = 0; i < strlen(s); i++)` la lunghezza viene ricalcolata a ogni iterazione. Meglio salvarla prima in una variabile, oppure usare la condizione `s[i] != '\0'`.
:::

## 6. Scrivere e leggere dentro una stringa: `sprintf` e `sscanf`

Spesso è utile costruire una stringa "scrivendoci dentro" come si scriverebbe sullo schermo, oppure estrarre dei valori da una stringa come se la si leggesse da tastiera. A questo servono le funzioni `sprintf` e `sscanf`, che funzionano esattamente come `printf` e `scanf` ma ricevono come primo parametro la stringa su cui lavorare:

```c
#include <stdio.h>

int main() {
    // sprintf: scrive in una stringa invece che sullo schermo
    char risultato[50];
    int a = 5, b = 3;
    int n = sprintf(risultato, "%d + %d = %d", a, b, a + b);
    printf("\"%s\" e' lunga %d caratteri\n", risultato, n);

    // sscanf: legge da una stringa invece che dalla tastiera
    char frase[] = "Rudolph is 12 years old";
    char nome[20];
    int eta;
    sscanf(frase, "%19s %*s %d", nome, &eta);   // %*s legge la parola "is" e la scarta
    printf("%s -> %d\n", nome, eta);

    return 0;
}
```

```text
"5 + 3 = 8" e' lunga 9 caratteri
Rudolph -> 12
```

*   `sprintf` restituisce il numero di caratteri scritti. Esiste anche la versione `snprintf(s, dimensione, formato, ...)`, più sicura perché non scrive mai oltre la dimensione indicata.
*   `sscanf`, come `scanf`, restituisce il numero di valori letti correttamente: è utilissimo per controllare che la stringa avesse il formato atteso.
*   Un asterisco dopo il `%` (`%*s`, `%*d`) indica di leggere un valore ma **scartarlo**, senza memorizzarlo in nessuna variabile.

Per convertire una stringa in numero esistono anche le funzioni `atoi` (*ascii to integer*) e `atof` (*ascii to float*) della libreria `stdlib.h`: `atoi("42")` restituisce il numero 42.

## 7. Tokenizzazione: dividere una stringa in parti

Un'operazione molto frequente, soprattutto quando si leggono dati da [file](../file/), è dividere una stringa in parti separate da uno o più caratteri **separatori**. Ad esempio dividere `"Mario;Rossi;17"` nei tre campi nome, cognome ed età. Ogni parte si chiama **token** e l'operazione si chiama **tokenizzazione** (*tokenizing*) o *parsing*.

### Quando il formato è noto: `sscanf` con gli scanset
Se si conosce in anticipo il numero di parti, basta una `sscanf`. Gli scanset come `%[^;]` ("leggi tutto fino al punto e virgola escluso") permettono di gestire separatori diversi dallo spazio:

```c
char riga[] = "Mario Rossi;via Roma 12;17";
char nome[50], indirizzo[50];
int eta;

if (sscanf(riga, "%49[^;];%49[^;];%d", nome, indirizzo, &eta) == 3) {
    printf("Nome: %s | Indirizzo: %s | Eta': %d\n", nome, indirizzo, eta);
}
```

Nella stringa di formato, dopo ogni `%49[^;]` c'è un `;`: serve a "consumare" il separatore prima di leggere il campo successivo. Il controllo `== 3` verifica che tutti e tre i campi siano stati letti.

### Quando il numero di parti è variabile: `strcspn`
Quando il numero di token non è noto (ad esempio un elenco di nomi di lunghezza variabile), non si può scrivere una `sscanf` con un numero fisso di campi. Bisogna scorrere la stringa con un ciclo, individuando un token alla volta. Lo strumento più comodo è la funzione `strcspn` (da *STRing Complement SPaN*): `strcspn(s, sep)` conta quanti caratteri ci sono all'inizio di `s` **prima** di incontrare uno qualsiasi dei caratteri contenuti in `sep`. In pratica, restituisce la lunghezza del prossimo token.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char s[] = "uno, due;tre quattro";
    char sep[] = " ,;";             // tre separatori possibili
    int i = 0;

    while (s[i] != '\0') {
        int len = strcspn(s + i, sep);      // lunghezza del token che inizia in posizione i
        if (len > 0) {
            printf("Token: %.*s\n", len, s + i);
        }
        i += len;                   // salta il token
        if (s[i] != '\0') {
            i++;                    // salta il separatore
        }
    }

    return 0;
}
```

```text
Token: uno
Token: due
Token: tre
Token: quattro
```

Vediamo i dettagli:

*   `s + i` indica "la stringa `s` a partire dalla posizione `i`": in questo modo `strcspn` comincia a contare dal punto in cui siamo arrivati, invece che dall'inizio. È un esempio di *aritmetica dei puntatori*, che approfondiremo nella [pagina dedicata](../puntatori/#4-puntatori-e-array).
*   Per stampare solo il token, e non tutto il resto della stringa, si usa `%.*s` passando come numero di caratteri la lunghezza `len`.
*   Il controllo `len > 0` evita di considerare token vuoti, che si incontrano quando ci sono due separatori consecutivi (come `", "` dopo "uno") o un separatore all'inizio della stringa.
*   L'ultimo `if` salta il separatore, ma solo se non si è già arrivati alla fine della stringa.

Se il token va conservato e non solo stampato, lo si copia in un'altra stringa con `strncpy`, aggiungendo il terminatore; se è un numero, lo si converte direttamente con `atoi(s + i)` (che si ferma da sola al primo carattere non numerico).

```c
char token[50];
strncpy(token, s + i, len);
token[len] = '\0';
```

:::note[E la funzione `strtok`?]
Nella libreria `string.h` esiste anche la funzione `strtok`, pensata proprio per la tokenizzazione e che si trova in moltissimi esempi online. È però sconsigliata: **modifica** la stringa originale (sostituisce i separatori con `'\0'`) e ricorda internamente il punto a cui è arrivata, quindi non si possono fare due tokenizzazioni contemporaneamente (ad esempio dividere una riga in campi e poi ogni campo in sotto-parti). Il metodo con `strcspn` non ha nessuno di questi problemi. Esempi d'uso di `strtok` si trovano comunque nell'eserciziario.
:::

## 8. Array di stringhe

Per memorizzare un elenco di stringhe (i nomi degli studenti di una classe, le parole di un testo...) si usa un **array di stringhe**, cioè una [matrice](../matrici/) di `char` in cui ogni **riga** è una stringa:

```c
#define N 5     // numero di stringhe
#define M 30    // lunghezza massima di ogni stringa (terminatore compreso)

char nomi[N][M] = {"Marco", "Anna", "Luca", "Giulia", "Paolo"};
```

*   `nomi[i]` è l'`i`-esima stringa, e si usa come una qualsiasi stringa: `printf("%s", nomi[i])`, `strcpy(nomi[i], "Sara")`, `scanf("%29s", nomi[i])`;
*   `nomi[i][j]` è il `j`-esimo carattere dell'`i`-esima stringa.

Ad esempio, per rendere maiuscola l'iniziale di ogni nome si modifica il primo carattere di ogni riga:

```c
for (int i = 0; i < N; i++) {
    nomi[i][0] = toupper(nomi[i][0]);
}
```

### Ordinare alfabeticamente
Per ordinare un array di stringhe si possono usare gli stessi algoritmi visti per gli [array numerici](../array/#6-ordinare-un-array), con due differenze: il confronto si fa con `strcmp` e lo scambio con `strcpy`, usando una stringa di appoggio.

```c
#include <stdio.h>
#include <string.h>

#define N 5
#define M 30

int main() {
    char nomi[N][M] = {"Marco", "Anna", "Luca", "Giulia", "Paolo"};
    char tmp[M];

    // bubble sort
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (strcmp(nomi[j], nomi[j + 1]) > 0) {     // nomi[j] viene dopo nomi[j+1]
                strcpy(tmp, nomi[j]);
                strcpy(nomi[j], nomi[j + 1]);
                strcpy(nomi[j + 1], tmp);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%s\n", nomi[i]);
    }

    return 0;
}
```

```text
Anna
Giulia
Luca
Marco
Paolo
```

## 9. Errori comuni

| Errore | Conseguenza |
|---|---|
| Dimenticare il terminatore `'\0'` quando si costruisce una stringa | Caratteri strani stampati dopo il testo, o crash |
| Array dimensionato senza spazio per il terminatore (`char s[4] = "Ciao";`) | La stringa non è terminata |
| `s = "testo";` oppure `s1 = s2;` | Errore di compilazione: si usa `strcpy` |
| `if (s1 == s2)` | Confronta gli indirizzi, non il contenuto: si usa `strcmp(s1, s2) == 0` |
| `if (strcmp(s1, s2))` per verificare l'uguaglianza | Condizione vera quando le stringhe sono **diverse** |
| `scanf("%s", &s)` | La `&` è di troppo (spesso funziona lo stesso, ma è scorretta e il compilatore dà un warning) |
| `scanf("%s", s)` senza limite di caratteri | Possibile buffer overflow |
| `%s` per leggere una frase | Viene letta solo la prima parola |
| `fgets` senza eliminare il `'\n'` finale | Confronti che falliscono, stampe con a capo inattesi |
| `fgets` subito dopo `scanf("%d", ...)` | `fgets` legge l'a capo rimasto e restituisce una riga vuota |
| `"a"` al posto di `'a'` (o viceversa) | `"a"` è una stringa di 2 caratteri, `'a'` un singolo `char` |

## Esercizi

Gli esercizi relativi a questi argomenti si trovano nel capitolo **"Array, stringhe e matrici"** dell'eserciziario (sezioni *Stringhe* e *Array di stringhe o matrici di caratteri*), linkato nella [pagina introduttiva](../programmazione-in-c/).
