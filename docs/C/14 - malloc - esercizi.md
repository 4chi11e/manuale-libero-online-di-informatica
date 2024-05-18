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

##### Memorizzazione sequenza numeri di lunghezza casuale 1
{: .numerato_da_h3}

Riempi un array di numeri casuali minori di 100, fermati quando estrai 0
// (non aggiungere lo 0)

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
    Soluzione
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
#include "vettore.c" // vedi esercizio sulla definizione di VettoreInt

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
#include "vettore.c"

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
#include "vettore.c"

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

    fp = fopen("09-lista-nomi.txt", "r");
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

    fp = fopen("09-lista-nomi.txt", "r");
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
with open("09-lista-nomi.txt", encoding='utf-8') as f:
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




