---
layout: default
title: Malloc - Esercizi
nav_order: 14
parent: Programmazione in C
has_children: False
---

# Malloc - Esercizi
{: .no_toc}
  
<details open markdown="block">
  <summary>
    Table of contents
  </summary>
  {: .text-delta }
1. TOC
{:toc .toc}
</details>

## Esercizi
{: .azzera_numerazione_h3}

### Array e Matrici numerici
{: .numerato_da_h3 .azzera_numerazione_h4}

#### Memorizzazione sequenza numeri di lunghezza casuale 1
{: .numerato_da_h3}

Riempi un array di numeri casuali minori di 100, fermati quando estrai 0
(non aggiungere lo 0)

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, n, cap, numero;
    int *a; // invece di a[]

    srand(time(NULL));

    // qui alloco la memoria per a
    cap = 10;
    a = malloc(cap * sizeof(int));
    // questo mi serve per controllare se il computer riesce ad allocare
    // memoria, se non ci riesce blocco tutto
    if (a == NULL) {
        printf("Non riesco ad allocare abbastanza memoria!");
        return 1;
    }

    // conto quanti numeri estraggo e vado avanti per sempre (poi userò un break
    // quando estraggo 0)
    for (i = 0; 1; i++) {

        // estraggo un numero
        numero = rand() % 100;
        // printf("%d ", numero);

        // se è 0 esco
        if (numero == 0) {
            break;
        }

        // qui mi chiedo se ho già riempito tutto a e non ho più spazio,
        // in tal caso devo ingrandire a
        if (i >= cap) {
            a = realloc(a, cap * sizeof(int) * 2);
            if (a == NULL) {
                printf("Non riesco ad allocare abbastanza memoria!");
                return 1;
            }
            cap *= 2;
        }

        // finalmente posso aggungere numero ad a
        a[i] = numero;
    }
    // mi devo segnare quanti numeri ho estratto
    n = i;

    printf("\n");

    // ora stampo tutto a
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    free(a);
}
```

</details> 

#### Memorizzazione sequenza numeri di lunghezza casuale 2
{: .numerato_da_h3}

Genera e memorizza una sequenza di numeri casuali. La sequenza deve
terminare quando la media dei numeri è 50 +- 0.01

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>

int main() {
    int num, *a, cap, n;
    float media, somma;

    srand(time(NULL));

    cap = 2;
    n = 0;
    a = malloc(cap * sizeof(int));
    if (a == NULL) {
        printf("Non riesco ad allocare abbastanza memoria!");
        return 1;
    }

    somma = 0;
    while (1) {
        num = rand() % 99 + 1;
        if (n >= cap) {
            cap *= 2;
            a = realloc(a, cap * sizeof(int));
            if (a == NULL) {
                printf("Non riesco ad allocare abbastanza memoria!");
                return 1;
            }
        }
        a[n++] = num;

        somma += num;
        media = somma / n;
        printf("%2d - %5.2f\n", a[n-1], media);
        if (media >= 49.99 && media <= 50.01) {
            break;
        }
    }
}
```

</details> 


#### Input sequenza numeri in unica riga
{: .numerato_da_h3}

Chiedi all'utente di inserire in un'unica riga una serie di numeri interi. il
tuo programma deve leggere questi numeri e metterli in un array che sia
grande esattamente come il numero di numeri inseriti.
stampa poi l'array.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione 1
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main() {
    char riga[1000], *token;
    int *a, n, i;

    printf("Scrivi una sequenza di numeri interi in una sola riga separati da spazi:\n > ");
    scanf("%[^\n]", riga);

    token = strtok(riga, " ");
    for (n = 0; token != NULL; n++) {
        if (n == 0) {
            a = malloc(sizeof(int));
        }
        else {
            a = realloc(a, (n+1)*sizeof(int));
        }
        if (a == NULL) {
            printf("Non sono riuscito ad allocare abbastanza memoria!\n");
            return 1;
        }
        // printf("%s - ", token);
        sscanf(token, "%d", &a[n]);
        token = strtok(NULL, " ");
    }

    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}
```

</details> 

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione 2
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main() {
    char riga[1000], copia[1000], *token;
    int *a, n, i;

    printf("Scrivi una sequenza di numeri interi in una sola riga separati da spazi:\n > ");
    scanf("%[^\n]", riga);
    strcpy(copia, riga);

    token = strtok(copia, " ");
    for (n = 0; token != NULL; n++) {
        token = strtok(NULL, " ");
    }

    a = malloc(n*sizeof(int));
    if (a == NULL) {
        printf("Non sono riuscito ad allocare abbastanza memoria!\n");
        return 1;
    }

    token = strtok(riga, " ");
    for (i = 0; token != NULL && i < n; i++) {
        sscanf(token, "%d", &a[i]);
        token = strtok(NULL, " ");
    }

    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}
```

</details> 


#### Definizione Vettore
{: .numerato_da_h3}

Definisci una struttura che chiamerai VettoreInt. Questa struttura deve contenere un'array dinamico di interi e i relativi valori di e capacità (quanti numeri può contenere) e dimensione (quanti elementi sono effettivamente contenuti). Implementa poi le seguenti funzioni:
- funzione inizializza per preparare il vettore all'utilizzo allocando la memoria e settando i valori iniziali di dimensione e capacità;
- funzione push_back per aggiungere un nuovo numero alla fine del vettore
- funzione pop per eliminare un numero da una determinata posizione del vettore

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <malloc.h>

typedef struct {
    int *data;
    int n, cap;
} VettoreInt;

int inizializza(VettoreInt *v) {
    v->n = 0; //(*v).
    v->cap = 0;
    v->data = malloc(sizeof(int) * 4);
    if(v->data == NULL){
        printf("Memoria esaurita\n");
        return 1;
    }
    v->cap = 4;
    return 0;
}

int push_back(VettoreInt *v, int dato) {
    if (v->n >= v->cap) {
        v->data = realloc(v->data, sizeof(int) * v->cap * 2);
        if(v->data == NULL){
            printf("Memoria esaurita\n");
            return 1;
        }
        v->cap *= 2;
    }
    v->data[v->n++] = dato;
    // che equivale a:
    // v->data[v->n] = dato;
    // n += 1;

    // printf("%d", v->n);
    return 0;
}

int pop(VettoreInt *v, int pos) {
    int i;
    if (pos < 0 || pos >= v->n) {
        printf("Posizione indicata per il pop non esistente\n");
        return 1;
    }
    for (i = pos; i < v->n-1; i++) {
        v->data[i] = v->data[i+1];
    }
    v->n--;
    return 0;
} 
```

</details> 


#### Memorizzazione sequenza numeri di lunghezza casuale 1 - col vettore
{: .numerato_da_h3}

Dopo aver definito una struttura VettoreInt e le funzioni per usarla come vettore,
dichiara e riempi un VettoreInt di numeri casuali minori di 100. Fermati quando estrai 0
(non aggiungere lo 0)

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "1-04-vettore.c" // vedi esercizio sulla definizione di VettoreInt

int main() {
    int i, numero;
    VettoreInt v;

    srand(time(NULL));

    inizializza(&v);

    numero = rand() % 100;
    while (numero != 0) {
        push_back(&v, numero);
        numero = rand() % 100;
    }

    // ora stampo tutto a
    for (i = 0; i < v.n; i++) {
        printf("%d ", v.data[i]);
    }
}
```

</details> 


#### Memorizzazione sequenza numeri di lunghezza casuale 2 - col vettore
{: .numerato_da_h3}

Dopo aver definito una struttura VettoreInt e le funzioni per usarla come vettore,
genera una sequenza di numeri casuali e salvali in memoria. La sequenza deve
terminare quando la media dei numeri è 50 +- 0.01

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
#include "1-04-vettore.c"

int main() {
    int num, i;
    float media, somma;
    VettoreInt v;

    srand(time(NULL));
    inizializza(&v);

    somma = 0;
    for (i = 0; 1; i++) {
        num = rand() % 99 + 1;
        push_back(&v, num);

        somma += num;
        media = somma / v.n;
        printf("%2d - %5.2f\n", v.data[i], media);
        if (media >= 49.99 && media <= 50.01) {
            break;
        }
    }
}
```

</details> 


#### Input sequenza numeri in unica riga - col vettore
{: .numerato_da_h3}

Dopo aver definito una struttura VettoreInt e le funzioni per usarla come vettore,
chiedi all'utente di inserire in un'unica riga una serie di numeri interi. il
tuo programma deve leggere questi numeri e metterli in un vettore.
Stampali infine al contrario.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "1-04-vettore.c"

int main() {
    char riga[1000], *token;
    VettoreInt v;
    int i, num;

    inizializza(&v);

    printf("Scrivi una sequenza di numeri interi in una sola riga separati da spazi:\n > ");
    scanf("%[^\n]", riga);

    token = strtok(riga, " ");
    for (i = 0; token != NULL; i++) {
        sscanf(token, "%d", &num);
        push_back(&v, num);
        token = strtok(NULL, " ");
    }

    for (i = v.n-1; i >= 0; i--) {
        printf("%d ", v.data[i]);
    }
}
```

</details> 


#### Genera matrice dinamica random
{: .numerato_da_h3}

Genera una matrice di numeri casuali di massimo due cifre. Anche la
dimensione della matrice deve essere casuale: il numero di righe e di colonne
deve essere compreso tra 2 e 10. 
Ordina poi separatamente ogni riga in ordine crescente.

Leggi i numeri contenuti nel file di input e inseriscili in una matrice dinamica.
Dai per scontato che ogni riga contenga la stessa quantità di numeri.


<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main() {
    int i, j;
    int N, M;
    int **mat;

    srand(time(NULL));

    N = rand() % (10-2+1) + 2;
    M = rand() % (10-2+1) + 2;
    mat = malloc(N * sizeof(int*));
    if (mat == NULL) {
        printf("Memoria insufficiente.");
        return 1;
    }
    for (i = 0; i < N; i++) {
        mat[i] = malloc(M * sizeof(int));
        if (mat[i] == NULL) {
            printf("Memoria insufficiente.");
            return 1;
        }
        for (j = 0; j < M; j++) {
            mat[i][j] = rand() % 100;
        }
    }

    // stampo separatamente (potevo farlo prima)
    for (i = 0; i < N; i++) {
        qsort(mat[i], M, sizeof(int), cmpfunc);
        for (j = 0; j < M; j++) {
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }
}
```

</details> 


#### Lettura matrice da file
{: .numerato_da_h3}

Leggi i numeri contenuti nel file di input e inseriscili in una matrice dinamica.
Dai per scontato che ogni riga contenga la stessa quantità di numeri.

<details markdown="block">
  <summary class="soluzione-toggler">
    File di input
  </summary>
  {: .text-delta }

```
 53 15 43 42 24 22 10 82 22  6 68 46 90 60 70  2 14 36 39 53  9 44 38 36 38 45 75 42 98 67
 41 50 86 79 88 64 17 51 68 25  3 84 93 65 99 67 36 70 43 58 42  7 69 68  0 94 83 63 23 74
 63  1 40 15 84 73 19 91 45 67 91 49 91 11 33 20 13 22 34 50 83 82 42 37 38 31  3 22 35  9
  9 49 34 92 44 80 94 21 94 35 90 47 45 95 30 82 28 89 25  7 49 42 69  4 51 77 13 73 85 68
 74 67  7 82  2 64 31  5 69 88 39 15 92 30 36 87 35 70 15 17 85 25 83 62  7 97 42 97 77 31
 96 68 88 34 52 55  9 74 94 65  0 53 45 85 16 12 62 69 98 61 96 56  1 48 89 81  9 76 21 34
 43 32  6 10 35 17 79 18 59 37 78 58 56 72 67 67 50 58 30 40 84 18 72 26  4 41 68 88 32 38
 93 95 74  4 98 33 22 68 90 60 81 65 73 34 12 82 27 22  5 87 63 49 33 82 11 82 83 59 66 27
 36 89 98 94 63 64 72 66 55 52 52 73 23 31 21 29 17 57 80 46 50 19 39 36 24  7 14 86 17 90
 53 62 56 15  5 45 58 62 39 89 18 12 97 17 96 34  8  1 58 92 10 39 80 63 77 89 42 24 11 32
 11 83 40  8 37 12 16 65 62 41  1 70 68 64 89 92 29 38 44 25  0 88  5 69 44 93 17 88 50 41
  0 53 25 13 22  3 94 54 33 42  8  2  1 61 37 76 60 29 13 32 80 64 47 91 13 43 18 80 79 92
 49 79 11 85 10 52 81 33 84 27 90 32 11 47 35 69 96 25 70  1 61 35 19 99 42 28 86 34 33 17
 31 55 15 37  6 67 75 33  8 43 74 63 85 30 52 35 47 55 90 98 83 80 76 59 15 34 38  0 72 58
 77 30 61 11 63 59 79 41 51 14 83 61  1 36 85 34 30 55 98 31 74 60 59 78 55 80 35 57 26 89
 19 27 31 38  1 17 82 65 24 17 31 54 62 35 45  0 85 42 38 21 26 97 73 21 23  7 82 35 95 43
  7 89  8 60 31 53 36 49 39 24  0 12 58 66 21 68 25 54 83 59 91 83 92 37 23  7  1 50 32 19
 27 22 20 36 49 79 40 88 96  2 35 12 63 10 41 64 48 13 69 43  6 89 94  9  0 58 63 82 51 92
 38 61 79 72 14 80 56 74  7 10 94 58 85 19 73 99 71 55 51 46 79 18 82 75 47 69 43 86 78 56
 27 26 91 12 15 30 76 47  3 74 43 84 31 87  6 79 50  2 69 39 18 27 28 47 39 31  1 25 87 31
 23 23 87 41 40 88 48 16  3 77 68 75 13  4 49 10 25 39 82 80 79 45 17 72 67 42 33 71 37  1
 54 94 94 83 17 68 88 65  4 37 63 52 57 13  9 92 78 67 43 87 25 66  0 32 69 13 86 24 56 16
 54 15 14 22 97 14 71 38 64 84 96 55 99  2 80 55 42 64 92 21 68 60 63 90 89 17 76  5 13 28
 65 86 81 81 17 25 42 42 99 86 55 76 49 16 96 99  8 10 85 62 53 54 15 37 49 56 61 82 19 21
 21 99 82 73 34 75 98 89 13  2 23 17 71  1 37 21 45 93 80 54 33 60  0 32  5 43 65  6 57  1
```

</details> 

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define K 1000

int main() {
    FILE *fp;
    int i, j;
    // le maiuscole indicano la capacità della matrice, le minuscole  la
    // quantità di valori effettivamente contenuti
    int N, M, n, m;
    int **mat;
    char riga[K];
    char *token;

    fp = fopen("1-09-leggi-matrice-input.txt", "r");
    if (fp == NULL) {
        printf("File non trovato\n");
        return 1;
    }

    N = 2;
    M = 2;
    // qui alloco un array dinamico di puntatori, ognuno a sua volta è un
    // array dinamico. Per ora ogni puntatore non punta a nulla.
    mat = malloc(N * sizeof(int *));
    n = 0;
    m = 0;
    for (i = 0; !feof(fp); i++) {
        if (i >= N) {
            N *= 2;
            // aggiungo puntatori cioè nuove righe
            mat = realloc(mat, N * sizeof(int *));
        }
        // è qui che alloco memoria per la riga i-esima (puntata dal puntatore
        // i-esimo)
        mat[i] = malloc(M * sizeof(int));
        fgets(riga, K, fp);
        token = strtok(riga, " ");
        for (j = 0; token != NULL; j++) {
            if (j >= M) {
                M *= 2;
                mat[i] = realloc(mat[i], M * sizeof(int));
                // qui va considerato che le righe devo essere tutte lunghe
                // uguali se no bisognerebbe fare una cosa più complicata.
                // Qui la realloc viene fatta solo riempiendo la prima riga.
            }
            sscanf(token, "%d", &mat[i][j]);
            token = strtok(NULL, " ");

            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
    n = i;
    m = j;
}
```

</details> 



#### Lettura matrice da file e ordinamenti 
{: .numerato_da_h3}

Leggi i numeri contenuti nel file di input e inseriscili in una matrice dinamica.
Dai per scontato che ogni riga contenga la stessa quantità di numeri.
Dopo aver letto la matrice ordina ogni riga in ordine crescente. Ordina poi tra loro
le righe in modo che siano ordnate in ordine crescente secondo il primo numero della
riga.

<details markdown="block">
  <summary class="soluzione-toggler">
    File di input
  </summary>
  {: .text-delta }

```
 53 15 43 42 24 22 10 82 22  6 68 46 90 60 70  2 14 36 39 53  9 44 38 36 38 45 75 42 98 67
 41 50 86 79 88 64 17 51 68 25  3 84 93 65 99 67 36 70 43 58 42  7 69 68  0 94 83 63 23 74
 63  1 40 15 84 73 19 91 45 67 91 49 91 11 33 20 13 22 34 50 83 82 42 37 38 31  3 22 35  9
  9 49 34 92 44 80 94 21 94 35 90 47 45 95 30 82 28 89 25  7 49 42 69  4 51 77 13 73 85 68
 74 67  7 82  2 64 31  5 69 88 39 15 92 30 36 87 35 70 15 17 85 25 83 62  7 97 42 97 77 31
 96 68 88 34 52 55  9 74 94 65  0 53 45 85 16 12 62 69 98 61 96 56  1 48 89 81  9 76 21 34
 43 32  6 10 35 17 79 18 59 37 78 58 56 72 67 67 50 58 30 40 84 18 72 26  4 41 68 88 32 38
 93 95 74  4 98 33 22 68 90 60 81 65 73 34 12 82 27 22  5 87 63 49 33 82 11 82 83 59 66 27
 36 89 98 94 63 64 72 66 55 52 52 73 23 31 21 29 17 57 80 46 50 19 39 36 24  7 14 86 17 90
 53 62 56 15  5 45 58 62 39 89 18 12 97 17 96 34  8  1 58 92 10 39 80 63 77 89 42 24 11 32
 11 83 40  8 37 12 16 65 62 41  1 70 68 64 89 92 29 38 44 25  0 88  5 69 44 93 17 88 50 41
  0 53 25 13 22  3 94 54 33 42  8  2  1 61 37 76 60 29 13 32 80 64 47 91 13 43 18 80 79 92
 49 79 11 85 10 52 81 33 84 27 90 32 11 47 35 69 96 25 70  1 61 35 19 99 42 28 86 34 33 17
 31 55 15 37  6 67 75 33  8 43 74 63 85 30 52 35 47 55 90 98 83 80 76 59 15 34 38  0 72 58
 77 30 61 11 63 59 79 41 51 14 83 61  1 36 85 34 30 55 98 31 74 60 59 78 55 80 35 57 26 89
 19 27 31 38  1 17 82 65 24 17 31 54 62 35 45  0 85 42 38 21 26 97 73 21 23  7 82 35 95 43
  7 89  8 60 31 53 36 49 39 24  0 12 58 66 21 68 25 54 83 59 91 83 92 37 23  7  1 50 32 19
 27 22 20 36 49 79 40 88 96  2 35 12 63 10 41 64 48 13 69 43  6 89 94  9  0 58 63 82 51 92
 38 61 79 72 14 80 56 74  7 10 94 58 85 19 73 99 71 55 51 46 79 18 82 75 47 69 43 86 78 56
 27 26 91 12 15 30 76 47  3 74 43 84 31 87  6 79 50  2 69 39 18 27 28 47 39 31  1 25 87 31
 23 23 87 41 40 88 48 16  3 77 68 75 13  4 49 10 25 39 82 80 79 45 17 72 67 42 33 71 37  1
 54 94 94 83 17 68 88 65  4 37 63 52 57 13  9 92 78 67 43 87 25 66  0 32 69 13 86 24 56 16
 54 15 14 22 97 14 71 38 64 84 96 55 99  2 80 55 42 64 92 21 68 60 63 90 89 17 76  5 13 28
 65 86 81 81 17 25 42 42 99 86 55 76 49 16 96 99  8 10 85 62 53 54 15 37 49 56 61 82 19 21
 21 99 82 73 34 75 98 89 13  2 23 17 71  1 37 21 45 93 80 54 33 60  0 32  5 43 65  6 57  1
```

</details> 


<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define K 1000

int confrontoint(const void *arg1, const void *arg2) {
    int* a = (int*)arg1;
    int* b = arg2;
    return *a - *b;
}

int confrontorighe(const void *arg1, const void *arg2) {
    int* a = *(int**)arg1;
    int* b = *(int**)arg2;
    return a[0] - b[0];
}

int main() {
    FILE *fp;
    int i, j;
    // le maiuscole indicano la capacità della matrice, le minuscole  la
    // quantità di valori effettivamente contenuti
    int N, M, n, m;
    int **mat;
    char riga[K];
    char *token;

    fp = fopen("1-10-leggi-matrice-ordinamenti-input.txt", "r");
    if (fp == NULL) {
        printf("File non trovato\n");
        return 1;
    }

    N = 2;
    M = 2;
    // qui alloco un array dinamico di puntatori, ognuno a sua volta è un
    // array dinamico. Per ora ogni puntatore non punta a nulla.
    mat = malloc(N * sizeof(int*));
    n = 0;
    m = 0;
    for (i = 0; !feof(fp); i++) {
        if (i >= N) {
            N *= 2;
            // aggiungo puntatori cioè nuove righe
            mat = realloc(mat, N * sizeof(int *));
        }
        // è qui che alloco memoria per la riga i-esima (puntata dal puntatore
        // i-esimo)
        mat[i] = malloc(M * sizeof(int));
        fgets(riga, K, fp);
        token = strtok(riga, " ");
        for (j = 0; token != NULL; j++) {
            if (j >= M) {
                M *= 2;
                mat[i] = realloc(mat[i], M * sizeof(int));
                // qui va considerato che le righe devo essere tutte lunghe
                // uguali se no bisognerebbe fare una cosa più complicata.
                // Qui la realloc viene fatta solo riempiendo la prima riga.
            }
            sscanf(token, "%d", &mat[i][j]);
            token = strtok(NULL, " ");
        }
        
    }
    n = i;
    m = j;

    // stampa della matrice normale
    printf("Stampa della matrice letta:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }


    printf("\n\nStampa della matrice ordinata riga per riga:\n");
    for (i = 0; i < n; i++) {
        qsort(mat[i], m, sizeof(int), confrontoint);
        for (j = 0; j < m; j++) {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }


    printf("\n\nStampa della matrice ordinata anche per righe:\n");
    qsort(mat, n, sizeof(int*), confrontorighe);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
}
```

</details> 


#### Voti studenti
{: .numerato_da_h3}

Scrivi un programma che legga i dati contenuti in un file di testo (testo
riportato di seguito) e li inserisca in opportune strutture dati che
rappresentino il registro dei voti per una materia. Il programma deve poi
calcolare la media dei voti per ogni singolo studente e aggiungerla alla
struttura dati (che quindi conterrà anche una variabile media). Il programma
deve mostrare tutti i dati raccolti e calcolati sullo schermo e salvarli in
un secondo file di testo. Nota che i cognomi possono essere formati da più
parole e sono separati dai voti da un “:”, inoltre il numero di voti varia
per ogni studente.
L'array contenente i dati di ogni studente deve essere dinamico in modo
che il programma funzioni per un qualsiasi numero di studenti.

<details markdown="block">
  <summary class="soluzione-toggler">
    File di input
  </summary>
  {: .text-delta }

```
Amici: 7.00 8.00 7.00
Biella: 8.00 9.50 7.00
Brescia: 5.00 7.50 9.00
Carolla: 7.00 8.50 8.50
Cunegatti: 7.00 7.00
De Bella: 4.00 4.00 4.50 5.00
De Vecchi: 8.00 10.00 6.00
Fumagalli: 8.50 6.00 4.50
Galimberti: 9.00 9.00 9.00
Germanò: 8.50 9.00 7.50
Gubellini: 8.00 10.00 7.00
Lepore: 5.50 4.00 3.00 5.00
Maconi: 7.50 5.00
Mariani: 8.00 8.00 7.00
Mattavelli: 9.00 9.50 8.50
Oggiano: 5.00 3.00 3.00 2.00
Passoni: 5.00 6.00 6.00 7.50
Pastori: 3.50 5.00 7.00 2.00
Pirovano: 6.50 7.50 7.50
Rudi: 9.50 10.00 10.00
Russell: 7.50 4.50
Sogos: 4.00 3.50 3.50 2.00
Tezza: 7.00 5.50 5.50
Varisco: 8.00 9.00 8.50
```

</details> 

<details markdown="block">
  <summary class="soluzione-toggler">
    Output della soluzione
  </summary>
  {: .text-delta }

```
Amici: 7.00 8.00 7.00 - 7.33 
Biella: 8.00 9.50 7.00 - 8.17 
Brescia: 5.00 7.50 9.00 - 7.17 
Carolla: 7.00 8.50 8.50 - 8.00 
Cunegatti: 7.00 7.00 - 7.00 
De Bella: 4.00 4.00 4.50 5.00 - 4.38 
De Vecchi: 8.00 10.00 6.00 - 8.00 
Fumagalli: 8.50 6.00 4.50 - 6.33 
Galimberti: 9.00 9.00 9.00 - 9.00 
Germanò: 8.50 9.00 7.50 - 8.33 
Gubellini: 8.00 10.00 7.00 - 8.33 
Lepore: 5.50 4.00 3.00 5.00 - 4.38 
Maconi: 7.50 5.00 - 6.25 
Mariani: 8.00 8.00 7.00 - 7.67 
Mattavelli: 9.00 9.50 8.50 - 9.00 
Oggiano: 5.00 3.00 3.00 2.00 - 3.25 
Passoni: 5.00 6.00 6.00 7.50 - 6.13 
Pastori: 3.50 5.00 7.00 2.00 - 4.38 
Pirovano: 6.50 7.50 7.50 - 7.17 
Rudi: 9.50 10.00 10.00 - 9.83 
Russell: 7.50 4.50 - 6.00 
Sogos: 4.00 3.50 3.50 2.00 - 3.25 
Tezza: 7.00 5.50 5.50 - 6.00 
Varisco: 8.00 9.00 8.50 - 8.50 
```

</details> 

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 20
#define K 200

typedef struct {
    char cognome[M];
    float voti[M];
    float media;
    int nvoti;
} Studente;

int main() {
    FILE *fp;
    Studente *elenco;
    char riga[K];
    int ntoken;
    int i, j, n, N = 4;

    fp = fopen("1-11-voti3.txt", "r");
    if (fp == NULL) {
        printf("errore nell'apertura del file.\n");
        return 1;
    }

    elenco = malloc(N * sizeof(Studente));
    if (elenco == NULL) {
        printf("Errore nell'allocazione della memoria.\n");
        return 1;
    }

    for (i = 0; !feof(fp); i++) {
        fgets(riga, K, fp);

        if (i >= N) {
            N *= 2;
            elenco = realloc(elenco, N * sizeof(Studente));
            if (elenco == NULL) {
                printf("Errore nell'allocazione della memoria.\n");
                return 1;
            }
        }
        ntoken = sscanf(riga, "%[^:]: %f %f %f %f", elenco[i].cognome,
                        &elenco[i].voti[0], &elenco[i].voti[1],
                        &elenco[i].voti[2], &elenco[i].voti[3]);
        elenco[i].nvoti = ntoken - 1;
    }
    n = i;
    fclose(fp);

    // calcolo della media
    for (i = 0; i < n; i++) {
        elenco[i].media = 0;
        for (j = 0; j < elenco[i].nvoti; j++) {
            elenco[i].media += elenco[i].voti[j];
        }
        elenco[i].media /= elenco[i].nvoti;
    }

    // stampo tutto con una funzione
    for (i = 0; i < n; i++) {
        printf("Studente: %12s - Media: %5.2f - Voti: ", elenco[i].cognome,
               elenco[i].media);
        for (j = 0; j < elenco[i].nvoti; j++) {
            printf("%3.1f ", elenco[i].voti[j]);
        }
        printf("\n");
    }

    // scrivo in un secondo file
    fp = fopen("1-11-voti3-out.txt", "w");
    if (fp == NULL) {
        printf("Apertura in scrittura del file fallita.\n");
        return 2;
    }
    for (i = 0; i < n; i++) {
        fprintf(fp, "%s: ", elenco[i].cognome);
        for (j = 0; j < elenco[i].nvoti; j++) {
            fprintf(fp, "%.2f ", elenco[i].voti[j]);
        }
        fprintf(fp, "- %.2f ", elenco[i].media);
        fprintf(fp, "\n");
    }
    fclose(fp);
}
```

</details> 


### Array e Matrici di Stringhe
{: .numerato_da_h3 .azzera_numerazione_h4}

La gestione delle stringhe in maniera del tutto dinamica è piuttosto complessa ed è utile solo in casi particolari. Per questo motivo almeno le stringhe continueremo a gestirle in maniera classica.

#### Lettura lista stringhe da file e ordinamento
{: .numerato_da_h3}

Leggi l'elenco di nomi dal file di input e inseriscili in un array
dinamico. Ordina poi l'elenco in ordine alfabetico.


<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 20

int main() {
    FILE *fp;
    int i, j, N, n;
    char (*nomi)[M];

    fp = fopen("2-01-lista-nomi.txt", "r");
    if (fp == NULL) {
        printf("File non trovato\n");
        return 1;
    }

    N = 4;
    nomi = malloc(N * sizeof(char) * M);
    if (nomi == NULL) {
        printf("Non riesco ad allocare abbastanza memoria!");
        return 1;
    }

    for (i = 0; !feof(fp); i++) {
        if (i >= N) {
            nomi = realloc(nomi, N * sizeof(char) * M * 2);
            if (nomi == NULL) {
                printf("Non riesco ad allocare abbastanza memoria!");
                return 1;
            }
            N *= 2;
        }
        fscanf(fp, "%s", nomi[i]);
    }
    n = i;

    printf("Nomi non ordinati:\n");
    for (i = 0; i < n; i++) {
        printf("- %s\n", nomi[i]);
    }

    qsort(nomi, n, sizeof(char) * M, strcmp);
    // si lamenta un po' (warnings) perchè strcmp non ha esattamente il formato
    // che vorrebbe ma funziona

    printf("Nomi ordinati:\n");
    for (i = 0; i < n; i++) {
        printf("- %s\n", nomi[i]);
    }
}
```

</details> 


#### Matrice di stringhe e ordinamenti
{: .numerato_da_h3}

Leggi l'elenco di nomi dal file di input e inseriscili in un array
dinamico. Inserisci poi i nomi in una lista di liste di nomi in cui in ogni
riga ci sono nomi che iniziano con la stessa lettera. Ordina poi ogni riga in
ordine alfabetico.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 20

int main() {
    FILE *fp;
    int i, j, N, n, p, matcap, matsize;
    char (*nomi)[M];
    char (**mat)[M];
    int *sizes, *caps;

    fp = fopen("2-02-lista-nomi-to-matrice-ordinata.txt", "r");
    if (fp == NULL) {
        printf("File non trovato\n");
        return 1;
    }

    N = 4;
    nomi = malloc(N * sizeof(char) * M);

    for (i = 0; !feof(fp); i++) {
        if (i >= N) {
            nomi = realloc(nomi, N * sizeof(char) * M * 2);
            if (nomi == NULL) {
                printf("Non riesco ad allocare abbastanza memoria!");
                return 1;
            }
            N *= 2;
        }
        fscanf(fp, "%s", nomi[i]);
    }
    n = i;

    printf("Nomi letti:\n");
    for (i = 0; i < n; i++) {
        printf("- %s\n", nomi[i]);
    }

    // qsort(nomi, n, sizeof(char) * M, strcmp);
    // si lamenta un po (warnings) perchè strcmp non ha esattamente il formato
    // che vorrebbe ma funziona

    mat = malloc(1 * sizeof(char**));
    if (mat == NULL) {
        printf("Non riesco ad allocare abbastanza memoria!");
        return 1;
    }
    matcap = 1;
    matsize = 1;

    sizes = malloc(matcap * sizeof(int));
    caps = malloc(matcap * sizeof(int));
    for (i = 0; i < matcap; i++) {
        sizes[i] = 0;
        caps[i] = 0;
    }

    for (p = 0; p < n; p++) {
        i = 0;
        // printf("%d %s %s - ", sizes[i], nomi[p], mat[i][0]);
        while (sizes[i] != 0 && nomi[p][0] != mat[i][0][0]) {
            i++;
            if (i >= matcap) {
                mat = realloc(mat, matcap * 2 * sizeof(char**));
                if (mat == NULL) {
                    printf("Non riesco ad allocare abbastanza memoria!");
                    return 1;
                }
                matcap *= 2;
                sizes = realloc(sizes, matcap * sizeof(int));
                caps = realloc(caps, matcap * sizeof(int));
                for (j = matsize; j < matcap; j++) {
                    sizes[j] = 0;
                    caps[j] = 0;
                }
            }
            if (i >= matsize) {
                matsize++;
            }
        }
        // printf("matcap:%d matsize:%d - ", matcap, matsize);
        if (caps[i] == 0) {
            mat[i] = malloc(4 * sizeof(char) * M);
            if (mat[i] == NULL) {
                printf("Non riesco ad allocare abbastanza memoria!");
                return 1;
            }
            caps[i] = 4;
        }
        if (sizes[i] >= caps[i]) {
            mat[i] = realloc(mat[i], caps[i] * 2 * sizeof(char) * M);
            if (mat[i] == NULL) {
                printf("Non riesco ad allocare abbastanza memoria!");
                return 1;
            }
            caps[i] *= 2;
        }
        // printf("Scrivo %s in mat[%d][%d]\n", nomi[p], i, sizes[i]);
        strcpy(mat[i][sizes[i]], nomi[p]);
        sizes[i] += 1;
    }

    printf("\n\nStampa matrice:\n");
    for (i = 0; i < matsize; i++) {
        printf(" %c: ", mat[i][0][0]);
        for (j = 0; j < sizes[i]; j++) {
            printf("%s ", mat[i][j]);
        }
        printf("\n");
    }

    printf("\n\nRistampa matrice ordinata riga per riga:\n");
    for (i = 0; i < matsize; i++) {
        qsort(mat[i], sizes[i], sizeof(char)*M, strcmp);
        printf(" %c: ", mat[i][0][0]);
        for (j = 0; j < sizes[i]; j++) {
            printf("%s ", mat[i][j]);
        }
        printf("\n");
    }

    // per ordinare le righe fra loro il qsort non va bene perchè dovrei ordinare anche l'array sizes
    // per usarlo dovevo fare una struttura per ogni riga contenente sia l'array che la dimensione
}
```

</details> 

Per curiosità riporto la soluzione di questo esercizio in Python, un linguaggio di alto livello che nasconde la gestione della memoria e delle strutture dati dinamiche.
Come è evidente questo rende la scrittura e la comprensione del codice molto più semplice. Di contro si perde il controllo delle operazioni di basso livello e la possibiiltà di ottimizzare tali operazioni per compiti specifici.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione in Python
  </summary>
  {: .text-delta }

```c
with open("2-02-lista-nomi-to-matrice-ordinata.txt", encoding='utf-8') as f:
    nomi = [riga.strip() for riga in f]

mat = {}
for nome in nomi:
    if nome[0] in mat:
        mat[nome[0]].append(nome)
    else:
        mat[nome[0]] = [nome]

mat = [val for key,val in mat.items()]
mat.sort()
for nomi in mat:
    print(nomi)
```

</details> 

<!-- per una nuova soluzione

#### 
{: .numerato_da_h3}



<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 

-->






<!-- 
<script src="{{site.baseurl}}/assets/js/esercizi-subnetting.js"></script> -->




