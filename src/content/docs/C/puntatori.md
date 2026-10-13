---
title: Puntatori
description: Indirizzi di memoria e puntatori in C, passaggio per indirizzo, relazione tra puntatori e array, passaggio di array, stringhe e matrici alle funzioni, qsort
---

I **puntatori** sono probabilmente l'argomento più caratteristico del linguaggio C, e quello che spaventa di più chi inizia. In realtà l'idea di base è semplice, e capirla bene permette finalmente di spiegare molte cose che finora abbiamo dovuto accettare "sulla fiducia": perché in `scanf` serve la `&`, perché con le stringhe invece no, perché gli array non si possono copiare con `=`.

I puntatori servono soprattutto a due cose:

*   permettere a una funzione di **modificare le variabili del chiamante** (il *passaggio per indirizzo*);
*   lavorare con zone di memoria la cui dimensione non è nota in anticipo, come vedremo nella pagina sull'[allocazione dinamica](../allocazione-dinamica/).

## 1. Gli indirizzi di memoria

La memoria RAM di un computer si può immaginare come una lunghissima fila di celle, ognuna grande un byte e identificata da un numero progressivo: il suo **indirizzo**. Ogni variabile occupa una o più celle consecutive (un `int` tipicamente 4), e il suo indirizzo è quello della prima cella.

```text
indirizzo:   ...   1000   1001   1002   1003   1004   ...
                 +------+------+------+------+------+
memoria:     ... |        a = 5 (int)        |      | ...
                 +------+------+------+------+------+
```

L'operatore **`&`** restituisce l'indirizzo di una variabile. Per stamparlo si usa lo specificatore `%p` (*pointer*), che lo mostra in esadecimale:

```c
int a = 5;
printf("Valore di a:    %d\n", a);
printf("Indirizzo di a: %p\n", (void *)&a);
```

```text
Valore di a:    5
Indirizzo di a: 000000000061FE1C
```

Il valore preciso dell'indirizzo dipende dal computer e cambia da un'esecuzione all'altra: a noi non interessa il numero in sé, ma il fatto di poterlo usare per raggiungere la variabile. (Il `(void *)` è una conversione richiesta formalmente da `%p`; per ora ignoratela.)

## 2. I puntatori

Un **puntatore** è una variabile che contiene l'**indirizzo** di un'altra variabile. Si dice che il puntatore "punta" a quella variabile.

Un puntatore si dichiara indicando il tipo della variabile puntata seguito da un asterisco:

```c
int *p;         // p è un puntatore a int: può contenere l'indirizzo di un int
double *q;      // q è un puntatore a double
char *c;        // c è un puntatore a char
```

Per accedere alla variabile puntata si usa l'operatore **`*`** davanti al puntatore (si chiama operatore di *dereferenziazione* o *indirezione*): se `p` contiene l'indirizzo di `a`, allora `*p` **è** `a`, e si può usare esattamente come `a`, sia per leggerne il valore sia per modificarlo.

```c
#include <stdio.h>

int main() {
    int a = 5;
    int *p;

    p = &a;                     // p contiene l'indirizzo di a: "p punta ad a"

    printf("a  = %d\n", a);     // 5
    printf("*p = %d\n", *p);    // 5: il valore della variabile puntata

    *p = 10;                    // modifica la variabile puntata, cioè a
    printf("a  = %d\n", a);     // 10

    printf("&a = %p\n", (void *)&a);
    printf("p  = %p\n", (void *)p);     // lo stesso indirizzo
    return 0;
}
```

```text
        p                    a
   +----------+         +--------+
   |   1000   | ------> |   10   |    indirizzo 1000
   +----------+         +--------+
```

:::caution[I due significati dell'asterisco]
L'asterisco ha due significati diversi a seconda del contesto, e all'inizio è facile confondersi:

*   in una **dichiarazione** (`int *p;`) indica che la variabile è un puntatore;
*   **usato su un puntatore** in un'espressione (`*p = 10;`, `x = *p + 1;`) indica la variabile puntata.

Riassumendo: `&` va dalla variabile all'indirizzo, `*` va dall'indirizzo alla variabile. Sono uno l'operazione inversa dell'altra: `*&a` è `a`.
:::

Il tipo del puntatore deve corrispondere al tipo della variabile puntata: un `int *` deve puntare a un `int`, non a un `double`. Il tipo serve al compilatore per sapere come interpretare i byte che si trovano a quell'indirizzo, e quanti byte leggere.

### Il puntatore `NULL`
Esiste un valore speciale, **`NULL`**, che indica un puntatore che **non punta a nulla**. Molte funzioni di libreria restituiscono `NULL` per segnalare un errore (ad esempio `fopen` quando non riesce ad aprire un [file](../file/)). `NULL` vale 0, quindi in una condizione è considerato falso: `if (p != NULL)` e `if (p)` sono equivalenti.

:::danger[Il puntatore non inizializzato]
Come tutte le variabili, un puntatore appena dichiarato contiene un valore casuale, cioè punta a una zona di memoria casuale. Scrivere attraverso un puntatore non inizializzato è un errore gravissimo:

```c
int *p;
*p = 10;        // scrive 10 in un punto CASUALE della memoria!
```

Il risultato è il crash del programma (*segmentation fault*) oppure, peggio, la modifica silenziosa di qualche altro dato. Un puntatore va sempre inizializzato con l'indirizzo di una variabile, oppure con `NULL` se non sa ancora dove puntare.
:::

## 3. Il passaggio per indirizzo

Nella pagina sulle [funzioni](../funzioni/#5-il-passaggio-per-valore) abbiamo visto che i parametri vengono passati **per valore**: la funzione riceve una copia, e non può modificare la variabile originale. Con i puntatori possiamo aggirare il problema: invece di passare il **valore** della variabile, passiamo il suo **indirizzo**.

```c
#include <stdio.h>

void raddoppia(int *p) {
    *p = *p * 2;        // modifica la variabile puntata
}

int main() {
    int x = 5;
    raddoppia(&x);      // passa l'indirizzo di x
    printf("x = %d\n", x);      // x = 10
    return 0;
}
```

In questo esempio:

*   nella chiamata, `&x` passa alla funzione l'**indirizzo** della variabile `x`;
*   il parametro `p` è un **puntatore a `int`**, che riceve quell'indirizzo;
*   dentro la funzione, `*p` è la variabile `x` del `main`: modificando `*p` si modifica direttamente `x`.

In realtà anche in questo caso la funzione riceve una **copia**, ma è la copia di un indirizzo: attraverso quell'indirizzo la funzione può raggiungere e modificare la variabile originale. È come dare a qualcuno una fotocopia dell'indirizzo di casa vostra: la fotocopia è un foglio diverso dall'originale, ma porta comunque a casa vostra.

Ora è chiaro anche perché in **`scanf`** bisogna scrivere `&`: `scanf` deve modificare le nostre variabili, scrivendoci dentro i valori letti, quindi ha bisogno dei loro indirizzi.

### L'esempio classico: lo scambio
Una funzione che scambia il contenuto di due variabili non può funzionare con il passaggio per valore (scambierebbe solo le copie), ma funziona perfettamente con il passaggio per indirizzo:

```c
#include <stdio.h>

void scambia(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int x = 3, y = 7;
    scambia(&x, &y);
    printf("x = %d, y = %d\n", x, y);   // x = 7, y = 3
    return 0;
}
```

### Restituire più risultati
Una funzione può restituire un solo valore con `return`, ma con il passaggio per indirizzo può **modificare più variabili** del chiamante. Si passano gli indirizzi delle variabili che dovranno contenere i risultati:

```c
#include <stdio.h>

void puntoMedio(double ax, double ay, double bx, double by, double *mx, double *my) {
    *mx = (ax + bx) / 2;
    *my = (ay + by) / 2;
}

int main() {
    double mx, my;
    puntoMedio(1, 1, 3, 5, &mx, &my);
    printf("Il punto medio e' (%g, %g)\n", mx, my);     // (2, 3)
    return 0;
}
```

Spesso si combinano le due tecniche: il `return` restituisce un valore che indica se l'operazione è riuscita, e i risultati veri e propri vengono scritti attraverso i puntatori. È esattamente quello che fa `scanf`, che restituisce il numero di valori letti e scrive i valori nelle variabili.

```c
// calcola quoziente e resto; restituisce 0 se la divisione è impossibile, 1 altrimenti
int dividi(int a, int b, int *quoziente, int *resto) {
    if (b == 0) {
        return 0;
    }
    *quoziente = a / b;
    *resto = a % b;
    return 1;
}
```

:::caution[Errori classici nel passaggio per indirizzo]
```c
raddoppia(x);       // SBAGLIATO: passa il valore di x, non il suo indirizzo
raddoppia(&x);      // CORRETTO

p = p * 2;          // SBAGLIATO: lavora sull'indirizzo, non sul valore
*p = *p * 2;        // CORRETTO: modifica il valore puntato
```

Il primo errore produce in genere un warning del compilatore (*makes pointer from integer without a cast*): non ignoratelo, perché il programma andrà quasi certamente in crash.
:::

## 4. Puntatori e array

Puntatori e array in C sono strettamente legati. Un array **non** è un puntatore: è un blocco di elementi consecutivi in memoria. Però, in quasi tutte le espressioni, **il nome di un array viene convertito automaticamente nell'indirizzo del suo primo elemento**: scrivere `v` equivale a scrivere `&v[0]`.

Ecco perché gli array non si possono assegnare con `=` né confrontare con `==`: in `a == b` si stanno confrontando gli indirizzi dei due array, non il loro contenuto. Ed ecco perché in `scanf("%s", nome)` non serve la `&`: `nome` è già un indirizzo.

### L'aritmetica dei puntatori
A un puntatore si può sommare un numero intero: se `p` punta a un elemento di un array, `p + 1` punta all'elemento **successivo**, `p + 2` a quello dopo ancora, e così via. Il compilatore tiene conto automaticamente della dimensione degli elementi: se `p` è un `int *` e gli `int` occupano 4 byte, `p + 1` è l'indirizzo 4 byte più avanti.

Di conseguenza, l'accesso a un elemento di un array con le parentesi quadre non è altro che un modo più comodo di scrivere un'operazione sui puntatori:

$$v[i] \quad \Longleftrightarrow \quad *(v + i)$$

cioè "parti dall'indirizzo del primo elemento, spostati in avanti di `i` elementi e prendi il valore che trovi lì". Questa è anche la vera ragione per cui gli indici partono da 0: `v[0]` è `*(v + 0)`, il primo elemento.

```c
#include <stdio.h>

int main() {
    int v[5] = {10, 20, 30, 40, 50};

    printf("%d %d\n", v[0], *v);            // 10 10
    printf("%d %d\n", v[2], *(v + 2));      // 30 30

    // scorrere l'array con un puntatore
    for (int *p = v; p < v + 5; p++) {
        printf("%d ", *p);
    }
    printf("\n");
    return 0;
}
```

Nell'ultimo ciclo il puntatore `p` parte dal primo elemento e viene spostato in avanti di un elemento alla volta con `p++`, finché non supera l'ultimo. Questo stile è molto comune nel codice C professionale, in particolare con le stringhe, dove si scorre finché non si trova il terminatore:

```c
// conta i caratteri di una stringa, come strlen
int lunghezza(char *s) {
    char *p = s;
    while (*p != '\0') {
        p++;
    }
    return p - s;       // la differenza tra due puntatori è il numero di elementi tra loro
}
```

### `char s[]` e `char *s`: una differenza importante
```c
char s1[] = "Ciao";     // array di 5 char, inizializzato con una copia di "Ciao": modificabile
char *s2 = "Ciao";      // puntatore a una stringa letterale: NON modificabile
```

Le stringhe letterali scritte tra virgolette vengono memorizzate in una zona di memoria **di sola lettura**. Nel primo caso il contenuto viene copiato in un array, che si può modificare liberamente; nel secondo caso `s2` punta direttamente alla stringa letterale, e un'istruzione come `s2[0] = 'M';` fa andare in crash il programma. Quando una stringa deve essere modificata, dichiaratela sempre come array; per i puntatori a stringhe letterali è buona norma scrivere `const char *s2 = "Ciao";`, così il compilatore segnala come errore qualsiasi tentativo di modifica.

## 5. Array come parametri

Per passare un array a una funzione, nell'intestazione si scrive il parametro come un array, e nella chiamata si indica **solo il nome** dell'array, senza parentesi quadre:

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

void riempiCasuale(int v[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % (max - min + 1) + min;
    }
}

void stampa(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

double media(int v[], int n) {
    int somma = 0;
    for (int i = 0; i < n; i++) {
        somma += v[i];
    }
    return (double)somma / n;
}

int main() {
    int v[N];
    int n = 10;

    srand(time(NULL));
    riempiCasuale(v, n, 1, 10);
    stampa(v, n);
    printf("Media: %.2f\n", media(v, n));
    return 0;
}
```

Eseguendo il programma si vede che `riempiCasuale` modifica davvero l'array del `main`: gli array si comportano **come se fossero passati per indirizzo**. Il motivo è quello visto sopra: nella chiamata `riempiCasuale(v, ...)` il nome `v` viene convertito nell'indirizzo del primo elemento, ed è questo indirizzo che la funzione riceve. L'array non viene copiato (sarebbe molto costoso per array grandi): la funzione lavora direttamente sull'array originale.

Di conseguenza:

*   nell'intestazione, `int v[]` e `int *v` sono **del tutto equivalenti**: in entrambi i casi il parametro è un puntatore. Si può scrivere anche `int v[N]`, ma il numero tra parentesi viene ignorato, perché nessun nuovo array viene creato;
*   la funzione **non può sapere quanti elementi ha l'array**: riceve solo l'indirizzo del primo. Per questo bisogna sempre passare anche la dimensione come parametro aggiuntivo (`int n`). Passare la dimensione logica `n`, invece della costante `N`, rende la funzione utilizzabile anche con array riempiti solo in parte;
*   dentro la funzione, `sizeof(v)` restituisce la dimensione di un puntatore (4 o 8 byte), non quella dell'array: il trucco `sizeof(v) / sizeof(v[0])` funziona solo dove l'array è dichiarato.

Se una funzione deve solo leggere l'array senza modificarlo, si può dichiarare il parametro come `const int v[]`: il compilatore segnalerà come errore qualsiasi tentativo di modifica. È un modo per documentare le intenzioni della funzione e prevenire errori.

:::danger[Non restituite l'indirizzo di una variabile locale]
Una funzione non può restituire un array creato al suo interno:

```c
int *creaArray() {
    int v[10];      // array locale
    // ...
    return v;       // SBAGLIATO: v smette di esistere quando la funzione termina
}
```

Le variabili locali vengono distrutte al termine della funzione, quindi il puntatore restituito punta a una zona di memoria non più valida, che verrà presto riutilizzata per altro. Il modo corretto è far ricevere alla funzione l'array da riempire come parametro (come `riempiCasuale`), oppure usare l'[allocazione dinamica](../allocazione-dinamica/).
:::

## 6. Stringhe come parametri

Le stringhe sono array, e vengono passate allo stesso modo. Con le stringhe però di solito non serve passare la lunghezza, perché la fine è indicata dal terminatore `'\0'`:

```c
#include <stdio.h>

int contaLettere(char str[]) {
    int conta = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            conta++;
        }
    }
    return conta;
}

int main() {
    char frase[] = "Ciao, Mondo! 123";
    printf("Lettere: %d\n", contaLettere(frase));   // Lettere: 9
    return 0;
}
```

Con le stringhe è molto comune scrivere il parametro come puntatore (`char *str`) e scorrerle con un puntatore invece che con un indice. La stessa funzione si può scrivere così:

```c
int contaLettere(char *str) {
    int conta = 0;
    for (char *p = str; *p != '\0'; p++) {
        if ((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')) {
            conta++;
        }
    }
    return conta;
}
```

Chi è abituato alla sintassi degli array tende a evitare questo secondo stile, ma è bene saperlo leggere perché è molto diffuso nel codice C professionale e nelle librerie standard. Tutte le funzioni di `string.h`, ad esempio, hanno parametri di tipo `char *` o `const char *`.

## 7. Matrici come parametri

Anche le [matrici](../matrici/) vengono passate per indirizzo: la funzione lavora sulla matrice originale. C'è però una differenza importante rispetto agli array: **il numero di colonne deve essere indicato nell'intestazione**.

```c
#include <stdio.h>

#define N 100
#define M 100

void stampaMatrice(int mat[][M], int righe, int colonne) {
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat[N][M] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    stampaMatrice(mat, 2, 3);
    return 0;
}
```

Perché le colonne sono obbligatorie? Come visto nella pagina sulle matrici, gli elementi sono memorizzati [riga per riga](../matrici/#come-è-memorizzata-una-matrice), e per trovare `mat[i][j]` il compilatore deve calcolare la posizione `i * colonne + j`. Senza conoscere il numero di colonne (cioè la lunghezza di ogni riga), questo calcolo sarebbe impossibile. Il numero di righe invece non serve, e si può omettere: `int mat[][M]` e `int mat[N][M]` sono equivalenti.

Come per gli array, conviene passare il numero di righe e colonne effettivamente usate: così la stessa funzione si può usare con matrici di dimensioni diverse, purché dichiarate con lo stesso numero di colonne `M`.

:::note
Potreste trovare intestazioni scritte come `void f(int (*mat)[M])`: è la stessa cosa scritta con la sintassi dei puntatori ("puntatore a un array di M interi"), corretta ma molto meno leggibile. Noi useremo sempre la forma `int mat[][M]`.
:::

## 8. Ordinare con `qsort`

La libreria `stdlib.h` contiene la funzione `qsort`, che ordina un array di qualsiasi tipo usando un algoritmo molto efficiente (di solito una variante del *quick sort*). Per poter ordinare qualsiasi tipo di dato, però, `qsort` ha bisogno che le si dica **come confrontare due elementi**: le si passa una **funzione di confronto** scritta da noi.

```c
#include <stdio.h>
#include <stdlib.h>

// restituisce un numero negativo se a viene prima di b, 0 se sono uguali, positivo se a viene dopo b
int confrontaInteri(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int v[] = {42, 7, 19, 3, 25, 11};
    int n = sizeof(v) / sizeof(v[0]);

    qsort(v, n, sizeof(int), confrontaInteri);

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);        // 3 7 11 19 25 42
    }
    printf("\n");
    return 0;
}
```

I parametri di `qsort` sono, in ordine: l'array da ordinare, il numero di elementi, la dimensione di un elemento e il **nome della funzione di confronto** (senza parentesi: non la stiamo chiamando, la stiamo passando a `qsort`, che la chiamerà ogni volta che deve confrontare due elementi).

La funzione di confronto segue le stesse regole di `strcmp` e riceve gli indirizzi dei due elementi come `const void *`, un "puntatore generico" che può puntare a qualsiasi tipo: per questo, prima di usarli, vanno convertiti nel tipo corretto con un cast. Per ordinare in ordine **decrescente** basta invertire i valori restituiti; per ordinare array di [struct](../struct/) basta confrontare il campo desiderato.

## 9. Errori comuni

| Errore | Conseguenza |
|---|---|
| Puntatore usato senza essere inizializzato | Scrittura in memoria casuale: crash o dati corrotti |
| `&` dimenticata nella chiamata (`raddoppia(x)`) | La funzione usa un valore come se fosse un indirizzo: crash |
| `*` dimenticato nella funzione (`p = p * 2`) | Si modifica l'indirizzo invece del valore |
| Indirizzo stampato con `%d` invece di `%p` | Valore troncato o sbagliato su sistemi a 64 bit |
| `sizeof(v)` su un array ricevuto come parametro | Dimensione del puntatore, non dell'array |
| Array passato senza la sua dimensione | La funzione non sa quanti elementi elaborare |
| Matrice passata senza indicare le colonne nell'intestazione | Errore di compilazione |
| Modifica di una stringa letterale tramite `char *` | Crash del programma |
| Funzione che restituisce l'indirizzo di una variabile locale | Puntatore a memoria non più valida |
| Dereferenziare un puntatore `NULL` | Crash del programma |

## Esercizi

Gli esercizi relativi a questi argomenti si trovano nel capitolo **"Funzioni e struct"** dell'eserciziario, linkato nella [pagina introduttiva](../programmazione-in-c/).
