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

### Memorizzazione sequenza numeri di lunghezza casuale 1
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

### Memorizzazione sequenza numeri di lunghezza casuale 2
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


### Input sequenza numeri in unica riga
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

### Definizione Vettore
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


### Memorizzazione sequenza numeri di lunghezza casuale 1 - col vettore
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


### Memorizzazione sequenza numeri di lunghezza casuale 2 - col vettore
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


### Input sequenza numeri in unica riga - col vettore
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

<!-- per una nuova soluzione

### 
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




