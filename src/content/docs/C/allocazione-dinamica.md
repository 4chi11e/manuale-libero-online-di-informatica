---
title: Allocazione dinamica della memoria
description: Stack e heap, malloc, calloc, realloc e free in C, array e matrici di dimensione decisa durante l'esecuzione, errori tipici nella gestione della memoria
---

Finora la dimensione di ogni array è stata decisa **mentre si scrive il programma**, con una costante: `int v[N];`. Per gestire quantità di dati non note in anticipo abbiamo usato il trucco della [dimensione logica](../array/#dimensione-fisica-e-dimensione-logica), dichiarando un array "abbastanza grande" e usandone solo una parte. Questa soluzione però ha dei limiti evidenti: se l'array è troppo piccolo i dati non ci stanno, se è troppo grande si spreca memoria, e in ogni caso un programma che legge un file non può sapere in anticipo quante righe conterrà.

L'**allocazione dinamica della memoria** permette di richiedere memoria **durante l'esecuzione del programma**, nella quantità che serve in quel momento. È utile quando:

*   non si sa in anticipo quanti dati serviranno;
*   la quantità di memoria dipende da un input dell'utente o dal contenuto di un file;
*   la quantità di dati cambia durante l'esecuzione (si aggiungono e si tolgono elementi);
*   si vogliono costruire [strutture dati dinamiche](../strutture-dati-dinamiche/), come liste, pile, code o alberi.

La memoria dinamica si gestisce tramite i [puntatori](../puntatori/) e alcune funzioni della libreria **`stdlib.h`**.

## 1. Stack e heap

La memoria usata da un programma in esecuzione è divisa in diverse zone. Le due che ci interessano sono lo **stack** e lo **heap**.

**Lo stack** (pila) contiene le variabili locali e i parametri delle funzioni. La memoria nello stack:

*   viene allocata **automaticamente** quando una funzione viene chiamata;
*   viene liberata **automaticamente** quando la funzione termina (per questo le variabili locali "muoiono" alla fine della funzione);
*   ha una **dimensione limitata**, di solito pochi megabyte. Per questo un array locale molto grande, come `int v[10000000];` (40 MB), fa andare in crash il programma appena viene chiamata la funzione che lo contiene.

**Lo heap** (mucchio) è l'area di memoria usata per l'allocazione dinamica. La memoria nello heap:

*   viene allocata **manualmente**, su richiesta del programmatore, con le funzioni `malloc`, `calloc` e `realloc`;
*   deve essere liberata **manualmente** con la funzione `free`: non viene liberata alla fine della funzione che l'ha richiesta, ma solo quando lo decide il programmatore (o, in ultima istanza, dal sistema operativo quando il programma termina);
*   è molto più grande dello stack: si possono allocare tranquillamente centinaia di megabyte, nei limiti della memoria del computer.

```text
+----------------------+
|        stack         |  variabili locali e parametri: gestito automaticamente,
|          |           |  cresce e si riduce con le chiamate di funzione
|          v           |
|                      |
|          ^           |
|          |           |
|         heap         |  memoria dinamica: gestita dal programmatore
+----------------------+
|   variabili globali  |
+----------------------+
|  codice del programma|
+----------------------+
```

## 2. Allocare memoria: `malloc`

La funzione `malloc` (*memory allocation*) riserva nello heap un blocco di memoria della dimensione indicata, **in byte**, e restituisce l'**indirizzo** del primo byte. Questo indirizzo va salvato in un puntatore, attraverso il quale si userà la memoria.

```c
int *v = malloc(10 * sizeof(int));     // spazio per 10 interi
```

Il numero di byte si calcola sempre con `sizeof`: `10 * sizeof(int)` significa "lo spazio necessario per 10 interi", qualunque sia la dimensione di un `int` sul computer in uso. Non scrivete mai `malloc(40)` dando per scontato che un `int` occupi 4 byte.

Grazie alla relazione tra [puntatori e array](../puntatori/#4-puntatori-e-array), il blocco allocato si usa **esattamente come un array**, con le parentesi quadre: `v[0]`, `v[i]`, `v[9]`.

:::caution[`malloc` può fallire]
Se non c'è abbastanza memoria disponibile, `malloc` restituisce **`NULL`**. Prima di usare la memoria allocata bisogna sempre controllare che l'allocazione sia riuscita:

```c
int *v = malloc(n * sizeof(int));
if (v == NULL) {
    printf("Errore di allocazione della memoria\n");
    return 1;
}
```
:::

Ecco un esempio completo, in cui la dimensione dell'array viene decisa dall'utente: è il vero vantaggio dell'allocazione dinamica.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &n);

    int *v = malloc(n * sizeof(int));
    if (v == NULL) {
        printf("Errore di allocazione della memoria\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &v[i]);
    }

    printf("Al contrario:");
    for (int i = n - 1; i >= 0; i--) {
        printf(" %d", v[i]);
    }
    printf("\n");

    free(v);        // libera la memoria quando non serve più
    return 0;
}
```

Come per le variabili normali, la memoria restituita da `malloc` **non viene inizializzata**: contiene valori casuali.

:::note[Il cast di `malloc`]
`malloc` restituisce un puntatore generico, di tipo `void *`, che in C viene convertito automaticamente nel tipo del puntatore a cui lo si assegna. In molti esempi si trova scritto `int *v = (int *)malloc(n * sizeof(int));`: il cast è inutile in C, ma è obbligatorio in C++, ed è per questo che compare spesso nel codice scritto da chi usa anche quel linguaggio.
:::

## 3. Liberare la memoria: `free`

La memoria allocata dinamicamente resta occupata finché non viene liberata esplicitamente con la funzione `free`, passandole il puntatore restituito da `malloc`:

```c
free(v);
v = NULL;
```

Dopo la `free` la memoria torna disponibile per altre allocazioni, e il puntatore **non deve più essere usato**: punta ancora allo stesso indirizzo, ma quella memoria non ci appartiene più. Per evitare di usarlo per sbaglio, conviene assegnargli subito `NULL`.

È vero che alla fine del programma il sistema operativo recupera tutta la memoria, ma un programma che alloca memoria senza mai liberarla continua a occupare sempre più RAM: si parla di **memory leak** (perdita di memoria). In un programma che gira a lungo (un server, un videogioco, un sistema operativo) o che alloca memoria all'interno di un ciclo, prima o poi la memoria si esaurisce. La regola è semplice: **per ogni `malloc` deve esserci una `free`**.

:::danger[Gli errori più pericolosi con la memoria dinamica]
*   **Usare la memoria dopo averla liberata** (*use after free*): `free(v); printf("%d", v[0]);`. Il risultato è imprevedibile: a volte sembra funzionare, a volte stampa valori casuali, a volte il programma va in crash.
*   **Liberare due volte la stessa memoria** (*double free*): `free(v); free(v);` corrompe le strutture interne dello heap, con crash anche molto più avanti nel programma. Assegnare `NULL` dopo la `free` protegge da questo errore, perché `free(NULL)` non fa nulla.
*   **Perdere l'unico puntatore** a un blocco allocato, ad esempio assegnandogli un altro indirizzo prima di aver fatto la `free`: quella memoria non potrà più essere liberata.
*   **Liberare memoria non allocata con `malloc`**, come un array normale o un indirizzo ottenuto con `&`: comportamento indefinito, quasi sempre un crash.
:::

## 4. Altre funzioni: `calloc` e `realloc`

### `calloc`: allocare e azzerare
La funzione `calloc` (*contiguous allocation*) funziona come `malloc`, ma riceve separatamente il numero di elementi e la dimensione di ciascuno, e **azzera** tutta la memoria allocata:

```c
int *conteggi = calloc(n, sizeof(int));     // n interi, tutti a 0
```

È comoda quando la memoria deve partire da zero, ad esempio per un array di contatori.

### `realloc`: cambiare la dimensione
La funzione `realloc` cambia la dimensione di un blocco di memoria già allocato, conservandone il contenuto. Riceve il puntatore al blocco e la **nuova dimensione** totale, e restituisce il puntatore al blocco ridimensionato:

```c
v = realloc(v, 20 * sizeof(int));   // da 10 a 20 interi (ma vedi l'avviso sotto)
```

Se dopo il blocco attuale c'è abbastanza spazio libero, `realloc` lo allunga "sul posto"; altrimenti alloca un nuovo blocco della dimensione richiesta, ci copia il contenuto di quello vecchio e libera il vecchio. Per questo il puntatore restituito può essere **diverso** da quello originale, e va sempre usato quello nuovo.

:::caution[Usate un puntatore temporaneo con `realloc`]
Anche `realloc` può fallire, e in questo caso restituisce `NULL` lasciando **intatto** il blocco originale. Ma se si scrive `v = realloc(v, ...)` e la `realloc` fallisce, `v` viene sovrascritto con `NULL` e l'indirizzo del blocco originale va perso per sempre: un memory leak, oltre alla perdita dei dati. Il modo corretto è usare un puntatore temporaneo:

```c
int *tmp = realloc(v, 20 * sizeof(int));
if (tmp == NULL) {
    printf("Errore di riallocazione\n");
    free(v);
    return 1;
}
v = tmp;
```
:::

`realloc` è lo strumento che permette di far **crescere** un array man mano che arrivano nuovi dati, ad esempio mentre si legge un file di cui non si conosce la lunghezza. Vedremo come sfruttarla al meglio nella pagina sulle [strutture dati dinamiche](../strutture-dati-dinamiche/#1-il-vector-array-dinamico).

## 5. Funzioni che restituiscono memoria allocata

Nella pagina sui puntatori abbiamo visto che una funzione [non può restituire l'indirizzo di un array locale](../puntatori/#5-array-come-parametri), perché le variabili locali vengono distrutte al termine della funzione. La memoria allocata con `malloc` invece si trova nello heap e **sopravvive** alla funzione che l'ha allocata: una funzione può quindi creare un array dinamico e restituirne l'indirizzo.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// crea un array di n numeri casuali tra min e max; restituisce NULL in caso di errore
int *creaArrayCasuale(int n, int min, int max) {
    int *v = malloc(n * sizeof(int));
    if (v == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        v[i] = rand() % (max - min + 1) + min;
    }
    return v;
}

int main() {
    srand(time(NULL));

    int n = 15;
    int *numeri = creaArrayCasuale(n, 1, 100);
    if (numeri == NULL) {
        printf("Errore di allocazione della memoria\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", numeri[i]);
    }
    printf("\n");

    free(numeri);       // la memoria allocata dalla funzione va liberata dal chiamante
    return 0;
}
```

In questo caso la responsabilità di liberare la memoria passa al **chiamante**: è bene indicarlo chiaramente nel commento che descrive la funzione. Le funzioni di libreria seguono la stessa regola: ad esempio la memoria di un file aperto con `fopen` viene liberata con `fclose`.

## 6. Struct allocate dinamicamente

Si può allocare dinamicamente qualsiasi tipo di dato, comprese le [struct](../struct/) e gli array di struct. Per accedere ai campi attraverso il puntatore si usa l'operatore freccia:

```c
typedef struct {
    char nome[30];
    int eta;
} Persona;

Persona *p = malloc(sizeof(Persona));
if (p != NULL) {
    strcpy(p->nome, "Anna");
    p->eta = 15;
    // ...
    free(p);
}

// array dinamico di n persone
Persona *elenco = malloc(n * sizeof(Persona));
if (elenco != NULL) {
    elenco[0].eta = 16;     // con l'indice si torna a usare il punto
    // ...
    free(elenco);
}
```

Notate la differenza: `p` è un puntatore a una struct, quindi si usa `p->eta`; `elenco[0]` invece è una struct (l'elemento di un array), quindi si usa `elenco[0].eta`.

## 7. Matrici dinamiche

Per creare una matrice di dimensioni decise durante l'esecuzione esistono due tecniche.

### Array di puntatori alle righe
Si alloca un array di puntatori, uno per ogni riga, e poi si alloca separatamente ogni riga. Il risultato si usa con la normale sintassi `mat[i][j]`:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int righe = 3, colonne = 4;

    // array di puntatori: uno per ogni riga
    int **mat = malloc(righe * sizeof(int *));
    if (mat == NULL) {
        return 1;
    }
    // ogni riga è un array dinamico di interi
    for (int i = 0; i < righe; i++) {
        mat[i] = malloc(colonne * sizeof(int));
        if (mat[i] == NULL) {
            return 1;       // (in un programma reale andrebbero liberate le righe già allocate)
        }
    }

    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            mat[i][j] = i * colonne + j;
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }

    // si libera prima ogni riga, poi l'array di puntatori
    for (int i = 0; i < righe; i++) {
        free(mat[i]);
    }
    free(mat);
    return 0;
}
```

```text
        mat
   +----------+      +----+----+----+----+
   | mat[0] --+----> |  0 |  1 |  2 |  3 |
   +----------+      +----+----+----+----+
   | mat[1] --+----> |  4 |  5 |  6 |  7 |
   +----------+      +----+----+----+----+
   | mat[2] --+----> |  8 |  9 | 10 | 11 |
   +----------+      +----+----+----+----+
```

`mat` è un **puntatore a puntatore** (`int **`): punta al primo elemento di un array i cui elementi sono a loro volta puntatori a `int`. Un vantaggio di questa tecnica è che le righe possono avere **lunghezze diverse**: ad esempio per memorizzare le righe di un file, ciascuna con un numero diverso di valori. L'ordine della `free` è importante: se si liberasse prima `mat`, si perderebbero gli indirizzi delle righe.

### Un unico blocco
In alternativa si può allocare un unico blocco di `righe * colonne` elementi e calcolare a mano la posizione di ogni elemento, esattamente come fa il compilatore con le matrici normali (vedi la [memorizzazione per righe](../matrici/#come-è-memorizzata-una-matrice)):

```c
int *mat = malloc(righe * colonne * sizeof(int));
// l'elemento di riga i e colonna j è mat[i * colonne + j]
mat[1 * colonne + 2] = 7;       // equivale a mat[1][2] = 7
free(mat);
```

È più efficiente (una sola allocazione, una sola `free`, elementi contigui in memoria) ma meno leggibile.

## 8. Errori comuni

| Errore | Conseguenza |
|---|---|
| `malloc(n)` invece di `malloc(n * sizeof(int))` | Memoria insufficiente: si scrive oltre la fine del blocco |
| Non controllare se `malloc`, `calloc` o `realloc` restituiscono `NULL` | Crash quando la memoria si esaurisce |
| `free` dimenticata | Memory leak |
| Uso del puntatore dopo la `free` | Comportamento imprevedibile |
| `free` chiamata due volte sullo stesso puntatore | Corruzione dello heap e crash |
| `v = realloc(v, ...)` senza puntatore temporaneo | Se `realloc` fallisce si perdono i dati e il blocco originale |
| Dopo `realloc` si continua a usare il vecchio puntatore | Il vecchio blocco potrebbe essere stato liberato |
| Matrice dinamica: `free(mat)` senza liberare prima le righe | Memory leak di tutte le righe |
| `free` di un array dichiarato normalmente (`int v[10]; free(v);`) | Crash |
| `sizeof(v)` con `v` puntatore a memoria dinamica | Restituisce la dimensione del puntatore, non del blocco allocato: la dimensione va memorizzata in una variabile |

## Esercizi

Gli esercizi relativi a questi argomenti si trovano nel capitolo **"Allocazione dinamica della memoria"** dell'eserciziario, linkato nella [pagina introduttiva](../programmazione-in-c/). Un ottimo allenamento è anche riprendere gli esercizi sui file gestendo i dati letti con array dinamici.
