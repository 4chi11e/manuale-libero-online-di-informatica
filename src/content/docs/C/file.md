---
title: File di testo
description: Lettura e scrittura di file di testo in C, fopen e fclose, modalità di apertura, fgets, fscanf, fprintf, parsing delle righe e caricamento di array di struct
---

I programmi visti finora memorizzano i dati solo nelle variabili, cioè nella memoria RAM: quando il programma termina, tutti i dati vanno persi. Quasi tutti i programmi reali però hanno bisogno di conservare i dati in modo permanente nella **memoria di massa** (disco fisso, SSD, chiavetta USB), sotto forma di **file**: una rubrica deve ricordare i contatti, un gioco i salvataggi e i record, un registro elettronico i voti.

Esistono due grandi categorie di file:

*   i **file di testo**, che contengono caratteri leggibili organizzati in righe, e si possono aprire e modificare con un qualsiasi editor (come il Blocco note o VS Code). Sono file di testo i file `.txt`, `.csv`, ma anche i file `.c` che scriviamo;
*   i **file binari**, che contengono i dati nello stesso formato in cui sono memorizzati in RAM, e non sono leggibili da un essere umano (immagini, eseguibili, documenti di Word...).

In questa pagina ci occupiamo dei file di testo.

## 1. Aprire e chiudere un file

Per lavorare su un file serve una variabile di tipo **puntatore a `FILE`** (un tipo definito in `stdio.h`), che si "aggancia" al file con la funzione `fopen`. Partiamo da un esempio:

```c
#include <stdio.h>

int main() {
    FILE *fp = fopen("dati.txt", "r");
    if (fp == NULL) {
        perror("Errore nell'apertura del file");
        return 1;
    }

    // ... qui si legge il file ...

    fclose(fp);
    return 0;
}
```

La funzione `fopen` riceve due stringhe: il **nome del file** e la **modalità di apertura**, e restituisce il puntatore al file aperto. Se non riesce ad aprire il file restituisce **`NULL`**.

### Il nome e il percorso del file
*   Se il file si trova nella stessa cartella in cui viene eseguito il programma, basta il nome completo di estensione: `"dati.txt"`.
*   Se il file si trova in un'altra cartella bisogna indicare un **percorso**, che può essere:
    *   **relativo**, cioè a partire dalla cartella corrente: `"input/dati.txt"` per entrare nella sottocartella `input`, `"../dati.txt"` per uscire dalla cartella corrente (con `..` si risale di un livello, con `"../../"` di due);
    *   **assoluto**, cioè a partire dalla radice del disco: `"C:\\Users\\Mario\\Desktop\\dati.txt"` su Windows, `"/home/mario/Desktop/dati.txt"` su Linux e macOS.

Notate le **doppie barre** nel percorso Windows: dentro una stringa la barra rovesciata è il carattere di escape (come in `\n`), e per scriverne una vera bisogna raddoppiarla. In alternativa si può usare la barra normale anche su Windows (`"C:/Users/Mario/Desktop/dati.txt"`), che funziona ugualmente ed evita il problema.

:::tip[Il programma non trova il file?]
I percorsi relativi partono dalla **cartella di lavoro** (*working directory*) del programma, cioè la cartella in cui si trova il terminale quando il programma viene avviato, che non è necessariamente quella che contiene il file `.c` o l'eseguibile. Se `fopen` restituisce `NULL` anche se il file esiste, quasi sempre il problema è questo. In VS Code la cosa più semplice è aprire con *File → Apri cartella* proprio la cartella che contiene sia il programma sia il file di testo.
:::

### Le modalità di apertura

| Modalità | Significato | Se il file esiste | Se il file non esiste |
|---|---|---|---|
| `"r"` | lettura (*read*) | si legge dall'inizio | `fopen` restituisce `NULL` |
| `"w"` | scrittura (*write*) | **viene cancellato** e ricreato vuoto | viene creato vuoto |
| `"a"` | aggiunta (*append*) | si scrive in fondo, dopo il contenuto esistente | viene creato vuoto |

È importante scegliere bene la modalità: aprire in `"w"` un file che contiene dati importanti li **cancella** immediatamente, anche se poi non si scrive nulla. Esistono anche le modalità `"r+"`, `"w+"` e `"a+"`, che permettono di leggere e scrivere sullo stesso file, ma sono più complicate da usare correttamente e non le tratteremo.

### Controllare l'apertura
Aprire un file è un'operazione che può **fallire** per molti motivi: il file non esiste, il nome è sbagliato, non si hanno i permessi, il disco è pieno... Per questo, dopo ogni `fopen` bisogna **sempre** controllare che il puntatore restituito non sia `NULL`. Si può scrivere `if (fp == NULL)` oppure, in modo equivalente, `if (!fp)`, visto che `NULL` vale 0 cioè falso.

In caso di errore, nell'esempio:

*   si usa la funzione **`perror`** invece di `printf`: oltre a stampare il messaggio indicato, aggiunge una descrizione dello specifico errore che si è verificato. Ad esempio, se il file non esiste, viene stampato `Errore nell'apertura del file: No such file or directory`;
*   si termina il programma con **`return 1`**. Il valore restituito dal `main` viene comunicato al sistema operativo: per convenzione 0 significa che il programma è terminato correttamente, un valore diverso da 0 indica un errore. Si possono usare valori diversi (1, 2, 3...) per distinguere errori diversi, ad esempio l'apertura di file diversi.

### Chiudere il file
Quando si è finito di lavorare su un file, bisogna chiuderlo con `fclose`. Se non lo si fa, spesso sembra che non succeda nulla, perché alla fine del programma il sistema operativo chiude automaticamente tutti i file rimasti aperti. È comunque importante chiuderli sempre:

*   quando si scrive, i dati non vengono scritti subito sul disco ma accumulati in un'area di memoria temporanea (il *buffer*), e vengono scritti davvero solo quando il buffer è pieno o quando il file viene chiuso: se il programma va in crash prima della chiusura, i dati possono andare persi;
*   il numero di file che un programma può tenere aperti contemporaneamente è limitato;
*   per riaprire lo stesso file in un'altra modalità (ad esempio prima scriverlo e poi rileggerlo) bisogna prima chiuderlo.

## 2. Leggere un file

Le funzioni principali per leggere un file di testo sono `fgets` e `fscanf`, versioni per i file di funzioni che già conosciamo.

### Leggere riga per riga con `fgets`
Il modo più comune e sicuro di leggere un file di testo è leggerlo **una riga alla volta** con `fgets`, già vista nella pagina sulle [stringhe](../stringhe/#leggere-una-frase-intera) per leggere dalla tastiera. Al posto di `stdin` si indica il puntatore al file:

```c
#include <stdio.h>

int main() {
    FILE *fp = fopen("note.txt", "r");
    if (fp == NULL) {
        perror("Errore nell'apertura del file");
        return 1;
    }

    char riga[256];
    int numero = 1;
    while (fgets(riga, sizeof(riga), fp) != NULL) {
        printf("%3d: %s", numero, riga);    // riga contiene già il '\n' finale
        numero++;
    }

    fclose(fp);
    return 0;
}
```

La riga più importante è la condizione del `while`, che non è un semplice confronto ma una **chiamata a funzione**. `fgets` legge una riga dal file e la memorizza in `riga`, e restituisce:

*   un puntatore valido (diverso da `NULL`) se la lettura è andata a buon fine;
*   `NULL` se non c'è più nulla da leggere (si è arrivati alla **fine del file**) oppure se si è verificato un errore.

La condizione quindi significa: "continua a eseguire il ciclo **finché `fgets` riesce a leggere una riga**". Ad ogni iterazione `fgets` legge la riga successiva, perché il file "ricorda" il punto a cui si è arrivati. Quando si raggiunge la fine del file, `fgets` restituisce `NULL`, la condizione diventa falsa e il ciclo termina da solo. È uno schema tipicissimo del C: la funzione fa due cose insieme, **legge e dice se ci è riuscita**, e il `while` usa direttamente quel risultato. Spesso si trova scritto in forma più compatta, `while (fgets(riga, sizeof(riga), fp))`.

La stringa `riga` deve essere abbastanza grande da contenere la riga più lunga del file: se una riga è più lunga, `fgets` ne legge solo una parte, e il resto verrà letto alla chiamata successiva come se fosse un'altra riga. Ricordate inoltre che `fgets` include nella stringa il carattere `'\n'` finale: per eliminarlo si usa la stessa istruzione vista per la tastiera, `riga[strcspn(riga, "\n")] = '\0';`.

### Leggere dati formattati con `fscanf`
Se il file ha una struttura semplice e regolare, con campi separati da spazi che `scanf` saprebbe leggere, si può usare direttamente `fscanf`, che funziona come `scanf` ma legge dal file indicato come primo parametro.

File `studenti.txt`:
```text
Mario 16 7.5
Anna 15 8.25
Luca 16 6.75
```

```c
#include <stdio.h>

int main() {
    FILE *fp = fopen("studenti.txt", "r");
    if (fp == NULL) {
        perror("Errore nell'apertura del file");
        return 1;
    }

    char nome[50];
    int eta;
    double media;

    while (fscanf(fp, "%49s %d %lf", nome, &eta, &media) == 3) {
        printf("Nome: %-10s | Eta': %d | Media: %.2f\n", nome, eta, media);
    }

    fclose(fp);
    return 0;
}
```

Anche qui la lettura è nella condizione del `while`: `fscanf` restituisce il **numero di valori letti correttamente**, quindi il ciclo continua finché vengono letti tutti e tre i campi, e termina quando il file finisce o quando si incontra una riga che non rispetta il formato.

Quando si leggono semplicemente sequenze di elementi tutti dello stesso tipo, ad esempio tutte le parole di un testo, si trova spesso il confronto con la costante **`EOF`** (*End Of File*), il valore che le funzioni di lettura restituiscono quando hanno raggiunto la fine del file:

```c
char parola[100];
while (fscanf(fp, "%99s", parola) != EOF) {
    printf("%s\n", parola);
}
```

### `fgets` o `fscanf`?
*   `fscanf` è comoda quando si è **sicuri che il file sia scritto correttamente** e abbia un formato semplice, con i campi separati da spazi.
*   `fgets` è più **sicura e versatile**: funziona con qualsiasi file e permette di gestire righe vuote, campi che contengono spazi (come "Mario Rossi") e righe scritte male. Obbliga però a fare in un secondo momento il **parsing** della riga letta, cioè a estrarne i dati, ad esempio con `sscanf`.

In generale, il metodo più robusto è il secondo: **leggere ogni riga con `fgets` e poi analizzarla con `sscanf`** (o con le tecniche di [tokenizzazione](../stringhe/#7-tokenizzazione-dividere-una-stringa-in-parti) viste nella pagina sulle stringhe).

### Leggere un carattere alla volta con `fgetc`
Per alcune elaborazioni (contare i caratteri, le righe, le vocali di un file...) può essere comodo leggere il file **un carattere alla volta** con `fgetc`, che restituisce il carattere letto oppure `EOF` alla fine del file:

```c
int c;              // int e non char, per poter contenere anche EOF
int righe = 0;
while ((c = fgetc(fp)) != EOF) {
    if (c == '\n') {
        righe++;
    }
}
```

Notate le parentesi nella condizione: prima si assegna a `c` il carattere letto, poi si confronta `c` con `EOF`. La variabile `c` è di tipo `int` perché `EOF` è un valore speciale (di solito -1) che deve essere distinguibile da tutti i caratteri.

:::danger[Il problema di `feof`]
Esiste una funzione, `feof(fp)`, che dice se si è raggiunta la fine del file, e verrebbe naturale usarla così:

```c
while (!feof(fp)) {                 // SBAGLIATO
    fgets(riga, sizeof(riga), fp);
    printf("%s", riga);
}
```

A prima vista sembra logico: "finché non sono alla fine del file, leggo una riga e la stampo". Il problema è che `feof` diventa vera solo **dopo** che un tentativo di lettura è **fallito** perché si era alla fine del file, non quando si legge l'ultima riga. L'ultimo giro del ciclo avviene quindi quando non c'è più nulla da leggere: `fgets` fallisce e restituisce `NULL`, ma la `printf` viene eseguita comunque, ristampando l'ultima riga. In altre parole, `feof` non dice "sono alla fine del file", ma "**l'ultima lettura è fallita** perché ero alla fine del file".

Per correggere il ciclo bisognerebbe controllare comunque il valore restituito da `fgets`, ma a quel punto è evidente che la forma più semplice e corretta è quella vista prima: `while (fgets(riga, sizeof(riga), fp))`. Online, e anche in alcune vecchie soluzioni dell'eserciziario, si trovano molti programmi che cadono in questo errore.
:::

## 3. Leggere e analizzare le righe

Vediamo due esempi tipici di lettura con `fgets` seguita dall'analisi della riga.

### Righe con un formato fisso: `fgets` + `sscanf`
File `persone.txt`, che contiene anche righe vuote o scritte male:
```text
Francesco 39

Andrea
30
Paolo 45
Emanuele 48
```

```c
#include <stdio.h>

int main() {
    FILE *fp = fopen("persone.txt", "r");
    if (fp == NULL) {
        perror("Errore nell'apertura del file");
        return 1;
    }

    char riga[100];
    char nome[50];
    int eta;

    while (fgets(riga, sizeof(riga), fp) != NULL) {
        if (sscanf(riga, "%49s %d", nome, &eta) == 2) {
            printf("Nome: %s, Eta': %d\n", nome, eta);
        }
        // altrimenti la riga non è valida: la si ignora (o si stampa un avviso)
    }

    fclose(fp);
    return 0;
}
```

```text
Nome: Francesco, Eta': 39
Nome: Paolo, Eta': 45
Nome: Emanuele, Eta': 48
```

`sscanf` restituisce il numero di campi letti correttamente: il confronto con 2 garantisce che siano stati estratti sia il nome sia l'età. Le righe vuote, la riga "Andrea" (a cui manca l'età) e la riga "30" (che non è un nome valido seguito da un numero) vengono semplicemente scartate. Con `fscanf` questo file avrebbe creato problemi: dopo "Andrea", `fscanf` avrebbe letto "30" come età di Andrea, perché per `%d` l'a capo è uno spazio come gli altri.

### Righe con un numero variabile di elementi
File `nomi.txt`, in cui sia il numero di righe sia il numero di nomi per riga possono variare:
```text
Francesco Paolo, Emanuele;Andrea Luca

Daniele Anna Lia
```

In questo caso si usa la tokenizzazione con `strcspn` vista nella pagina sulle [stringhe](../stringhe/#quando-il-numero-di-parti-è-variabile-strcspn), salvando ogni nome in un array di stringhe:

```c
#include <stdio.h>
#include <string.h>

#define MAX_NOMI 100
#define LUN 30

int main() {
    FILE *fp = fopen("nomi.txt", "r");
    if (fp == NULL) {
        perror("Errore nell'apertura del file");
        return 1;
    }

    char riga[256];
    char nomi[MAX_NOMI][LUN];
    char sep[] = " ,;\n";
    int n = 0;

    while (fgets(riga, sizeof(riga), fp) != NULL) {
        int i = 0;
        while (riga[i] != '\0' && n < MAX_NOMI) {
            int len = strcspn(riga + i, sep);
            if (len > 0 && len < LUN) {
                strncpy(nomi[n], riga + i, len);
                nomi[n][len] = '\0';        // strncpy non aggiunge il terminatore
                n++;
            }
            i += len;
            if (riga[i] != '\0') {
                i++;                        // salta il separatore
            }
        }
    }
    fclose(fp);

    printf("Letti %d nomi:\n", n);
    for (int k = 0; k < n; k++) {
        printf("%s\n", nomi[k]);
    }
    return 0;
}
```

Tra i separatori c'è anche `'\n'`, così l'a capo alla fine di ogni riga non finisce dentro l'ultimo nome. La condizione `n < MAX_NOMI` impedisce di uscire dall'array se il file contiene troppi nomi, e `len < LUN` scarta i nomi troppo lunghi per essere memorizzati.

## 4. Scrivere su un file

Scrivere su un file è molto simile a scrivere sullo schermo. Le funzioni principali sono:

*   **`fprintf(fp, formato, ...)`**: scrittura formattata, funziona esattamente come `printf` ma scrive sul file indicato come primo parametro;
*   **`fputs(stringa, fp)`**: scrive una stringa così com'è. Attenzione all'ordine dei parametri, con il file **in fondo**, e al fatto che non aggiunge automaticamente l'a capo;
*   **`fputc(carattere, fp)`**: scrive un singolo carattere.

Il file deve essere aperto in modalità `"w"` o `"a"`.

```c
#include <stdio.h>

int main() {
    FILE *fp = fopen("tabelline.txt", "w");
    if (fp == NULL) {
        perror("Errore nell'apertura del file");
        return 1;
    }

    fputs("Tavola pitagorica\n\n", fp);
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            fprintf(fp, "%4d", i * j);
        }
        fputc('\n', fp);
    }

    fclose(fp);
    printf("File scritto correttamente\n");
    return 0;
}
```

Eseguendo il programma non compare nulla sullo schermo (a parte il messaggio finale), ma nella cartella di lavoro viene creato il file `tabelline.txt` con la tavola pitagorica ben incolonnata. Eseguendolo una seconda volta il file viene sovrascritto; aprendolo in modalità `"a"`, invece, ogni esecuzione aggiungerebbe una nuova tavola in fondo al file.

`fprintf` fa già tutto quello che fa `fputs` e molto di più, quindi molti programmatori si abituano a usare solo quella. `fputs` resta comoda per scrivere stringhe già pronte, senza variabili da inserire.

:::note[Anche lo schermo e la tastiera sono file]
In C la tastiera e lo schermo sono gestiti come file speciali, sempre aperti, a cui corrispondono tre puntatori predefiniti: `stdin` (*standard input*, la tastiera), `stdout` (*standard output*, lo schermo) e `stderr` (*standard error*, lo schermo, ma riservato ai messaggi di errore). Per questo `fgets(s, N, stdin)` legge dalla tastiera, e `printf(...)` è esattamente equivalente a `fprintf(stdout, ...)`. Una funzione che riceve un `FILE *` come parametro può quindi scrivere indifferentemente su un file o sullo schermo!
:::

## 5. Un esempio completo: salvare e caricare un array di struct

Nei programmi gestionali i dati vengono tipicamente tenuti in memoria in un [array di struct](../struct/#5-array-di-struct): all'avvio del programma vengono **caricati** da un file, e al termine (o dopo ogni modifica) vengono **salvati** sul file. Un formato molto usato è il **CSV** (*Comma Separated Values*): una riga per ogni elemento, con i campi separati da un carattere speciale come la virgola o il punto e virgola. I file CSV si possono aprire anche con un [foglio di calcolo](../../foglio-di-calcolo/foglio-di-calcolo/).

```c
#include <stdio.h>
#include <string.h>

#define MAX_CONTATTI 100
#define LUN 50

typedef struct {
    char nome[LUN];
    char telefono[LUN];
    int eta;
} Contatto;

// carica i contatti dal file; restituisce quanti ne ha letti, o -1 in caso di errore
int carica(const char *nomeFile, Contatto rubrica[], int max) {
    FILE *fp = fopen(nomeFile, "r");
    if (fp == NULL) {
        return -1;
    }

    char riga[256];
    int n = 0;
    while (n < max && fgets(riga, sizeof(riga), fp) != NULL) {
        Contatto c;
        if (sscanf(riga, "%49[^;];%49[^;];%d", c.nome, c.telefono, &c.eta) == 3) {
            rubrica[n] = c;
            n++;
        }
    }

    fclose(fp);
    return n;
}

// salva i contatti sul file; restituisce 1 se è andato tutto bene, 0 altrimenti
int salva(const char *nomeFile, Contatto rubrica[], int n) {
    FILE *fp = fopen(nomeFile, "w");
    if (fp == NULL) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%s;%s;%d\n", rubrica[i].nome, rubrica[i].telefono, rubrica[i].eta);
    }

    fclose(fp);
    return 1;
}

int main() {
    Contatto rubrica[MAX_CONTATTI];

    int n = carica("rubrica.csv", rubrica, MAX_CONTATTI);
    if (n == -1) {
        printf("File non trovato: si parte con una rubrica vuota\n");
        n = 0;
    }

    // aggiunta di un nuovo contatto
    if (n < MAX_CONTATTI) {
        strcpy(rubrica[n].nome, "Mario Rossi");
        strcpy(rubrica[n].telefono, "333 1234567");
        rubrica[n].eta = 42;
        n++;
    }

    for (int i = 0; i < n; i++) {
        printf("%-20s %-15s %3d\n", rubrica[i].nome, rubrica[i].telefono, rubrica[i].eta);
    }

    if (!salva("rubrica.csv", rubrica, n)) {
        perror("Errore nel salvataggio");
        return 1;
    }
    return 0;
}
```

Il file `rubrica.csv` avrà un contenuto di questo tipo:

```text
Anna Bianchi;340 9998887;35
Mario Rossi;333 1234567;42
```

Osservazioni:

*   le operazioni sui file sono racchiuse in due funzioni, `carica` e `salva`, che ricevono il nome del file come parametro: il `main` resta semplice e le funzioni si possono riutilizzare;
*   il punto e virgola come separatore permette di avere campi che contengono **spazi** (come "Mario Rossi"): lo scanset `%49[^;]` legge tutto fino al punto e virgola, spazi compresi. Con `%s` sarebbe stato impossibile;
*   in `carica` la condizione `n < max` viene controllata **prima** di leggere la riga, così non si esce mai dall'array, anche se il file contiene più righe del previsto;
*   ogni riga viene letta in una struct di appoggio `c`, che viene copiata nell'array solo se la riga è valida: le righe vuote o malformate vengono ignorate;
*   le funzioni restituiscono un valore che indica se l'operazione è riuscita, e il `main` lo controlla: un programma ben scritto non dà mai per scontato che le operazioni sui file vadano a buon fine.

## 6. Errori comuni

| Errore | Conseguenza |
|---|---|
| Non controllare se `fopen` ha restituito `NULL` | Crash del programma alla prima lettura o scrittura |
| File non trovato perché la cartella di lavoro è diversa da quella attesa | `fopen` restituisce `NULL` |
| `"C:\Users\..."` con barre singole | Le `\` vengono interpretate come sequenze di escape: si scrive `\\` o `/` |
| Apertura in `"w"` di un file da cui si volevano leggere o aggiungere dati | Il contenuto del file viene cancellato |
| `while (!feof(fp))` | L'ultima riga viene elaborata due volte |
| `fclose` dimenticata | Dati non scritti sul disco in caso di crash, impossibilità di riaprire il file |
| `fgets` senza gestire il `'\n'` finale | Stringhe con un a capo indesiderato, confronti che falliscono |
| Parametri di `fputs` invertiti, o file dimenticato in `fprintf` | Errore o warning di compilazione |
| Stringa di lettura troppo piccola | Le righe lunghe vengono spezzate in più letture |
| Caricamento in un array senza controllare la dimensione massima | Uscita dai limiti dell'array se il file è troppo lungo |
| `char c = fgetc(fp)` invece di `int c` | Il confronto con `EOF` può non funzionare correttamente |

## Esercizi

Gli esercizi relativi a questi argomenti si trovano nel capitolo **"Files in C: esercizi"** dell'eserciziario (sezioni *Esercizi senza struct* ed *Esercizi con l'uso di struct*), linkato nella [pagina introduttiva](../programmazione-in-c/).
