---
layout: default
title: Array Matrici e Stringhe - Esercizi
nav_order: 6
parent: Programmazione in C
has_children: False
---

# Array Matrici e Stringhe - Esercizi
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

### Array Numerici
{: .numerato_da_h3 .azzera_numerazione_h4}

#### Riempimento e stampe array
{: .numerato_da_h3}

Riempi un array di 6 elementi nel modo che preferisci, poi:
1. Stampa l’array
2. Stampa l’array al contrario

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int a[6] = {1,2,3,4,5,6};
    int i;

    // stampa
    for (i = 0; i < 6; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");

    // stampa al contrario
    for (i = 5; i >= 0; i--) {
        printf("%d ", a[i]);
    }
}
```

</details> 

<details markdown="block">
  <summary class="soluzione-toggler">
    Alternativa migliore perché parametrica
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 6

int main() {
    int a[N];
    int i;

    srand(time(NULL));

    // riempio l'array 1
    for (i = 0; i < N; i++) {
        a[i] = rand() % 100; // numeri da 0 a 99 - formula: rand() % (max-min+1) + min 
    }

    // stampa
    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");

    // stampa al contrario
    for (i = N-1; i >= 0; i--) {
        printf("%d ", a[i]);
    }
}
```

</details> 


#### Lettura valori array e calcolo media
{: .numerato_da_h3}

Leggi n voti, caricali in un array, calcolane la media, poi stampa tutti i numeri e la media.

Variante: calcola e stampa la media dei soli voti sufficienti.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

#define N 100 

int main() {
    int voti[N];
    int nvoti, i;
    float media;

    // lettura del numero di voti
    printf("Inserisci il numero di voti: ");
    scanf("%d", &nvoti);
    while (nvoti < 1) {
        printf("Ci deve essere almeno un voto.");
        printf("Inserisci il numero di voti: ");
        scanf("%d", &nvoti);
    }

    // lettura dei voti
    for (i = 0; i < nvoti; i++) {
        printf("Inserisci il %d voto: ", i+1);
        scanf("%d", &voti[i]);
        while (voti[i] < 1 || voti[i] > 10) {
            printf("Il voto non e' valido, deve essere compreso tra 1 e 10.");
            printf("Inserisci il %d voto: ", i+1);
            scanf("%d", &voti[i]);
        }
    }

    // calcolo la media (potevo farlo insieme alla lettura, così è più leggibile e modulare)
    media = 0;
    for (i = 0; i < nvoti; i++) {
        media += voti[i];
    }
    media /= nvoti;

    // stampe
    printf("\nElenco dei voti: ");
    for (i = 0; i < nvoti; i++) {
        printf("%d ", voti[i]);
    }
    printf("\nMedia: %.2f", media);
}
```

</details> 

#### Riempimento casuale e ricerca numero
{: .numerato_da_h3}

Carica un array di numeri casuali, chiedi poi all’utente un numero e digli se questo numero è presente nell’array.

Variante: stampa anche in che posizione si trova il numero trovato. Se il programma non trova il numero stampa una volta sola che il numero non è stato trovato.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione Base
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main() {
    int a[N];
    int num, i, trovato;

    srand(time(NULL));

    // riempimento
    for (i = 0; i < N; i++) {
        a[i] = rand() % 100;
    }

    // stampa
    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }

    printf("\n\nInserisci un numero da cercare: ");
    scanf("%d", &num);

    trovato = 0;
    for (i = 0; i < N; i++) {
        if (a[i] == num) {
            printf("Numero trovato in posizione %d\n", i);
            trovato = 1;
        }
    }
    if (!trovato) {
        printf("Numero non trovato \n");
    }
}
```

</details> 
<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione Variante
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10
#define MAX 3

int main() {
    int numeri[N], i, trovato, numero, posizioni[N], j, npos;

    srand(time(NULL));

    // riempimento casuale
    for (i = 0; i < N; i++) {
        numeri[i] = rand() % (MAX+1);
    }

    printf("Dammi un numero compreso tra 0 e %d: ", MAX);
    scanf("%d", &numero);

    // cerco il numero
    trovato = 0;
    j = 0;
    for (i = 0; i < N; i++) {
        if (numeri[i] == numero) {
            trovato = 1;
            posizioni[j] = i;
            j++;
        }
    }
    npos = j;

    // per controllare stampo l'array
    for (i = 0; i < N; i++) {
        printf("%d ", numeri[i]);
    }
    printf("\n");

    // printf("j: %d\n", j);

    // comunico il risultato
    if (trovato) {
        printf("Numero trovato nelle posizioni: ");
        for (i = 0; i < npos; i++) {
            printf("%d ", posizioni[i]);
        }
    } else {
        printf("Numero non trovato.\n");
    }
}
```

</details> 


#### Riempimento casuale, inversione e stampe varie
{: .numerato_da_h3}

Carica un array, di dimensione a piacere, di numeri casuali compresi in un range di numeri deciso dall’utente. Esegui poi le seguenti operazioni:
1.	inverti l’ordine dei numeri contenuti nell’array,
2.	Date due posizioni a e b dell’array (chiaramente controlla che a sia minore di b e che siano compresi tra 0 e N-1) stampa prima i numeri dell’array dalla posizione a alla posizione b poi i numeri dalla posizione b alla posizione a
3.	Dato un numero positivo x qualsiasi stampa tutti i numeri dell’array dalla posizione 0 alla posizione x. Se x > N-1, dopo aver stampato tutto l’array ricomincia a stampare dalla posizione 0 e continua fino ad aver stampato x+1 numeri.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 10

int main() {
    int arr[N];
    int i, tmp;
    int min = 5;
    int max = 22;

    // Carica un array, di dimensione a piacere, di numeri casuali compresi
    // in un range di numeri deciso dall’utente

    srand(time(NULL));

    // riempimento
    for (i = 0; i < N; i++) {
        arr[i] = rand() % (max-min+1) + min;
    }

    // stampa
    for (i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    

    // 1. inverti l’ordine dei numeri contenuti nell’array,
    for (i = 0; i < N/2; i++) {
        tmp = arr[i];
        arr[i] = arr[N-1-i];
        arr[N-1-i] = tmp;
    }

    // stampa
    for (i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 2. Date due posizioni a e b dell’array (chiaramente controlla che a sia
    // minore di b e che siano compresi tra 0 e N-1) stampa prima i numeri
    // dell’array dalla posizione a alla posizione b poi i numeri dalla posizione b
    // alla posizione a 

    int a = 2;
    int b = 7;

    for (i = a; i <= b; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (i = b; i >= a; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 3.   Dato un numero positivo x qualsiasi stampa tutti i
    // numeri dell’array dalla posizione 0 alla posizione x. Se x > N-1, dopo aver
    // stampato tutto l’array ricomincia a stampare dalla posizione 0 e continua
    // fino ad aver stampato x+1 numeri.
    int x = 22;
    for (i = 0; i <= x; i++) {
        printf("%d ", arr[i%N]);
    }
    printf("\n");
}
```

</details> 


#### Riempimento casuale e stampa massimo e minimo
{: .numerato_da_h3}

Dato un array di numeri interi casuali, calcola e stampa il valore massimo e il valore minimo contenuti nell’array

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

int main() {
    int arr[N];
    int max, min, i;

    srand(time(NULL));

    for (i = 0; i < N; i++) {
        arr[i] = rand() % 100;
    }
    min = arr[0];
    max = arr[0];
    for (i = 1; i < N; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Array: ");
    for (i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nMin: %d\n", min);
    printf("Max: %d\n", max);
}
```

</details> 


#### Riempimento casuale e stampa numeri superiori alla media
{: .numerato_da_h3}

Dato un array di numeri interi casuali, stampa tutti i numeri superiori alla media partendo dal fondo

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

int main() {
    int arr[N];
    int max, min, i;
    float media;

    srand(time(NULL));

    for (i = 0; i < N; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");

    media = 0;
    for (i = 0; i < N; i++) {
        media += arr[i];
    }
    media /= N;
    printf("%.2f\n", media);

    for (i = N-1; i >= 0; i--) {
        if (arr[i] > media) {
            printf("%d ", arr[i]);
        }
    }

}
```

</details> 


#### Lettura voti e calcolo media condizionale
{: .numerato_da_h3}

Scrivi un programma che esegua le seguenti operazioni:
1.	Chiedere con un ciclo all'utente di inserire i voti presi in matematica ed inserirli in un array, uscire dal ciclo quando l'utente inserisce un valore negativo;
2.	Calcola la media di tutti i voti escludendo il più basso e il più alto.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

#define N 100

int main() {
    float voti[N], media;
    int nvoti, imax, imin, i;

    nvoti = 0;
    while (1) {
        printf("Scrivi il %d voto: ", nvoti+1);
        scanf("%f", &voti[nvoti]);
        while (voti[nvoti] < 0 || voti[nvoti] > 10) {
            printf("Voto non valido, deve essere compreso tra 1 e 10.\n");
            printf("Scrivi il %d voto: ", nvoti+1);
            scanf("%f", &voti[nvoti]);
        }
        if (voti[nvoti] == 0) {
            break;
        } else {
            nvoti++;
        }
    }
    if (nvoti < 3) {
        printf("Non ha senso calcolare la media di 0 voti.");
    } else {
        imax = 0;
        imin = 0;
        for (i = 1; i < nvoti; i++) {
            if (voti[i] > voti[imax]) {
                imax = i;
            }
            if (voti[i] < voti[imin]) {
                imin = i;
            }
        }

        media = 0;
        for (i = 0; i < nvoti; i++) {
            if (i != imin && i != imax) {
                media += voti[i];
            }
        }
        media /= (nvoti-2);

        printf("La media vale %.2f\n", media);
    }
}
```

</details> 


#### Istogrammi
{: .numerato_da_h3}

Riempi un array di numeri casuali poi rappresenta l’array come un istogramma.
Ad es.

    1: x
    0: 
    4: xxxx
    6: xxxxxx
    3: xxx
    9: xxxxxxxxx

Alternative: stampa i numeri in orizzontale e le x in verticale sia coi numeri sotto che coi numeri sopra

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

int main() {
    int v[N], i, j, max;
    
    srand(time(NULL));

    // riempio l'array
    max = 0;
    for (i = 0; i < N; i++) {
        v[i] = rand() % 10;
        if (v[i] > max) {
            max = v[i];
        }
    }

    // stampa nel primo modo, array da su a giù, x da sinistra a destra
    for (i = 0; i < N; i++) {
        printf("%d: ", v[i]);
        for (j = 0; j < v[i]; j++) {
            printf("X");
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");

    // stampa nel secondo modo, array da sx a dx, x da su a giù
    for (i = 0; i < N; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    for (i = 0; i < N; i++) {
        printf("--");
    }
    printf("\n");

    for (i = 0; i < max; i++) {
        for (j = 0; j < N; j++) {
            if (i < v[j]) {
                printf("X ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    
    printf("\n");
    printf("\n");

    // stampa nel modo più bello, coi numeri sotto e le x che crescono verso l'alto
    for (i = 0; i < max; i++) {
        for (j = 0; j < N; j++) {
            if (i < max-v[j]) {
                printf("  ");
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
    for (i = 0; i < N; i++) {
        printf("--");
    }
    printf("\n");
    for (i = 0; i < N; i++) {
        printf("%d ", v[i]);
    }
}
```

</details> 


#### Selection Sort
{: .numerato_da_h3}

Scrivi un programma che ordini un array con l’algoritmo selection sort, prima in ordine crescente poi in ordine decrescente.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

#define N 6

void stampaArray(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void ordinaArrayCrescente(int a[], int n) {
    int i, j, jmin, tmp;
    for (i = 0; i < N-1; i++) {
        jmin = i;
        for (j = i+1; j < N; j++) {
            if (a[j] < a[jmin]) {
                jmin = j;
            }
        }
        tmp = a[i];
        a[i] = a[jmin];
        a[jmin] = tmp;
    }
}

void ordinaArrayDecrescente(int a[], int n) {
    int i, j, jmax, tmp;
    for (i = 0; i < N-1; i++) {
        jmax = i;
        for (j = i+1; j < N; j++) {
            if (a[j] > a[jmax]) {
                jmax = j;
            }
        }
        tmp = a[i];
        a[i] = a[jmax];
        a[jmax] = tmp;
    }
}

int main() {
    int arr[N] = {4,7,1,9,4,6};

    stampaArray(arr, N);
    printf("\n");

    // ordinamento (selection sort)
    ordinaArrayCrescente(arr, N);
    ordinaArrayDecrescente(arr, N);

    stampaArray(arr, N);
    printf("\n");
    
}
```

</details> 



#### Bubble Sort
{: .numerato_da_h3}

Scrivi un programma che ordini un array con l’algoritmo bubble sort, prima in ordine crescente poi in ordine decrescente.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

void stampaArray(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubbleSortCresente(int a[], int n) {
    int i, j, tmp;

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1; j++) {
            if (a[j] > a[j+1]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    
}

void bubbleSortDecresente(int a[], int n) {
    int i, j, tmp;

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1; j++) {
            if (a[j] < a[j+1]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

int main() {
    int arr[] = {1,7,3,9,5,6};
    int n = 6;

    bubbleSortCresente(arr,n);
    stampaArray(arr,n);
    bubbleSortDecresente(arr,n);
    stampaArray(arr,n);
}
```

</details> 


#### Ordinamento parte di array
{: .numerato_da_h3}

Scrivi un programma che dato un array di dimensione n e due valori x y tali che x<=y<=n, ordini l’array dalla posizione x alla posizione y comprese.


<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

void stampaArray(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void ordinaxy(int a[], int n, int x, int y) {
    int i, j, tmp;

    for (i = x; i < y; i++) {
        for (j = x; j < y; j++) {
            if (a[j] > a[j+1]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

int main() {
    int arr[] = {1,7,3,9,5,6,4,4,8};
    int n = 9;

    stampaArray(arr,n);
    ordinaxy(arr, n, 2, 6);
    stampaArray(arr,n);
    // bubbleSortDecresente(arr,n);
    // stampaArray(arr,n);
}
```

</details> 


#### Somma massima sottosequenze crescenti
{: .numerato_da_h3}

Riempi un array di numeri casuali tra 0 e 9 e calcola la somma massima fra le sottosequenze di cifre non decrescenti. Il valore deve essere calcolato da un’apposita funzione.

Esempio: *qui devo inserire l'immagine*
 
la prima riga rappresenta l'array e la seconda i vari valori calcolati (viene restituito 13 che è il più grande)

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

int main() {
    // int A[N] = {2,2,4,5,3,9,3,1,5,0};
    int A[N];
    int i, somma, sommamax;
    
    srand(time(NULL));

    for (i = 0; i < N; i++) {
        A[i] = rand() % 10;
        printf("%d ", A[i]);
    }
    printf("\n");

    somma = A[0];
    sommamax = A[0];
    for (i = 1; i < N; i++) {
        if (A[i] >= A[i-1]) {
            somma += A[i];
            if (somma > sommamax) {
                sommamax = somma;
            }
        } else {
            somma = A[i];
            if (somma > sommamax) {
                sommamax = somma;
            }
        }
    }
    
    printf("%d", sommamax);
}
```

</details> 


#### Riempimento casuale su e giu
{: .numerato_da_h3}

Scrivi un programma che riempia un array di numeri casuali di una cifra in modo tale che ogni numero sia sempre maggiore o minore di entrambi i numeri adiacenti (ad esempio 1 8 3 5 2 7 4 5 3). L’array generato deve essere stampato poi ordinato e infine ristampato. Per implementare le funzionalità descritte realizza due funzioni: una che riceve un array e lo riempie di numeri casuali come descritto, una che riceve un array e un indicazione che dica se ordinare l’array in ordine crescente o decrescente (ad esempio una variabile booleana).

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

int main() {
    int v[N], i, min, max, tmp, j, imin;

    srand(time(NULL));

    v[0] = rand() % 10;
    do {
        v[1] = rand() % 10;
    } while (v[1] == v[0]);

    for (i = 2; i < N; i++) {
        if (v[i-1] > v[i-2]) {
            min = 0;
            max = v[i-1] - 1;
        } else {
            min = v[i-1] + 1;
            max = 9;
        }
        v[i] = rand() % (max-min+1) + min;
    }

    // stampa
    for (i = 0; i < N; i++) {
        printf("%d ", v[i]);
    }

    // ordinamento

    // bubble sort
    for (i = 0; i < N-1; i++) {
        for (j = 0; j < N-1; j++) {
            if (v[j] < v[j+1]) {
                tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
        }
    }

    // selection sort
    for (i = 0; i < N; i++) {
        imin = i;
        for (j = i+1; j < N; j++) {
            if (v[j] > v[imin]) {
                imin = j;
            }
            tmp = v[i];
            v[i] = v[imin];
            v[imin] = tmp;
        }
    }

    // stampa
    printf("\n");
    for (i = 0; i < N; i++) {
        printf("%d ", v[i]);
    }

}
```

</details> 



#### Media e mediana
{: .numerato_da_h3}

Dato un array di numeri interi casuali, calcola e stampa media e mediana dell’array

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 


#### Stampa dal fondo dei numeri superiori alla media
{: .numerato_da_h3}

Dato un array di numeri interi casuali, stampa tutti i numeri superiori alla media partendo dal fondo

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 


#### Secondo array con soli numeri non primi
{: .numerato_da_h3}

Letta in input una sequenza di numeri interi positivi memorizzarla in un array. Costruire un secondo array contenente soltanto gli elementi del primo array che non siano numeri primi. Stampare il secondo array.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 


#### Fusione di due array ordinati in un terzo ordinato
{: .numerato_da_h3}

Dati due array di numeri ordinati (ottienili come vuoi), costruire un terzo array di numeri interi ordinato, ottenuto mediante la “fusione” dei prime due. Stampare il terzo array.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 
	

### Stringhe
{: .numerato_da_h3 .azzera_numerazione_h4}

#### Conteggio lettere
{: .numerato_da_h3}

Leggi una stringa da input e poi comunica all’utente di quante lettere è composta la stringa. Il conteggio deve essere fatto in due modi diversi, usando la funzione strlen e contando i caratteri uno alla volta.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>

#define N 100

int corrado(char stringa[]) {
    int i;
    for (i = 0; i < N && stringa[i] != 0 && stringa[i] != '\n'; i++) {
        // niente
    }
    return i;
}

int main() {
    char stringa[N];

    printf("Scrivi qualcosa: ");
    // fgets(stringa, N, stdin);
    scanf(" %29[^\n]", stringa);

    printf("La stringa e' formata da %d caratteri.\n", strlen(stringa));
    printf("La stringa e' formata da %d caratteri.\n", corrado(stringa));
    printf("%s", stringa);
    printf("ciao");
}
```

</details> 


#### Stampa normale e lettera per lettera
{: .numerato_da_h3}

Leggi una stringa da input e poi stampala in due modi diversi, la prima volta tutta insieme poi stampando una lettera per volta separando le lettere con uno spazio.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>

#define N 100

int main() {
    char stringa[N];
    int i;

    printf("Scrivi qualcosa: ");
    // fgets(stringa, N, stdin);
    scanf(" %29[^\n]", stringa);

    printf("%s\n", stringa);
    for (i = 0; stringa[i] != 0; i++) {
        printf("%c ", stringa[i]);
    }
    printf("\n");
}
```

</details> 

#### Stampa al contrario
{: .numerato_da_h3}

Leggi una stringa da input e poi stampala al contrario, cioè partendo dal fondo ma non modificandone il contenuto.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>

#define N 100

int main() {
    char stringa[N];
    int i;

    printf("Scrivi qualcosa: ");
    // fgets(stringa, N, stdin);
    scanf(" %29[^\n]", stringa);

    for (i = strlen(stringa)-1; i >= 0; i--) {
        printf("%c", stringa[i]);
    }
}
```

</details> 

#### Stringa inversa
{: .numerato_da_h3}

Leggi una stringa da input e poi modificala in modo da ottenere la stringa inversa (ad esempio “ciao” diventa “oaic”). Stampa infine la stringa.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>

#define N 100

int main() {
    char stringa[N];
    char tmp;
    int i, len;

    printf("Scrivi qualcosa: ");
    // fgets(stringa, N, stdin);
    scanf(" %29[^\n]", stringa);

    len = strlen(stringa);

    for (i = 0; i < len/2; i++) {
        tmp = stringa[i];
        stringa[i] = stringa[len-1-i];
        stringa[len-1-i] = tmp;
    }

    printf("%s", stringa);
}
```

</details> 

#### Scambio contenuto di due stringhe
{: .numerato_da_h3}

Dichiara e inizializza due stringhe con valori a piacere, stampale. Scambia il contenuto delle due stringhe in modo che la prima contenga il contenuto della seconda e viceversa, poi ristampale.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>

#define N 100

int main() {
    char stringa1[N];
    char stringa2[N];
    char tmp[N];
    int i, len;

    printf("Scrivi la prima stringa: ");
    fgets(stringa1, N, stdin);
    printf("Scrivi la seconda stringa: ");
    fgets(stringa2, N, stdin);

    printf("Inizio:\n");
    printf("%s", stringa1);
    printf("%s", stringa2);

    strcpy(tmp, stringa1);
    strcpy(stringa1, stringa2);
    strcpy(stringa2, tmp);

    printf("\n\nFine:\n");
    printf("%s", stringa1);
    printf("%s", stringa2);
}
```

</details> 

#### Confronto stringhe
{: .numerato_da_h3}

Leggi da input due stringhe, se le due stringhe sono uguali comunica che sono uguali altrimenti scrivi quella che viene prima in ordine alfabetico

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 	

#### Confronto stringhe 2
{: .numerato_da_h3}

Leggi usando un’unica funzione scanf tre parole. Indica poi qual è la parola più lunga, la parola che viene prima in ordine alfabetico e la parola che contiene più vocali.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione con tre variabili
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>

#define N 50

int contaVocali(char stringa[]) {
    int ris = 0;
    int i;
    for (i = 0; stringa[i] != 0; i++) {
        if (stringa[i] == 'a' || stringa[i] == 'e' || stringa[i] == 'i' ||
            stringa[i] == 'o' || stringa[i] == 'u' || stringa[i] == 'A' ||
            stringa[i] == 'E' || stringa[i] == 'I' || stringa[i] == 'O' ||
            stringa[i] == 'U') {
                ris++;
        }
    }
    return ris;
}

int main() {
    char p1[N], p2[N], p3[N];
    int nvp1, nvp2, nvp3;

    printf("Scrivi 3 parole: ");
    scanf("%s %s %s", p1, p2, p3);

    if (strlen(p1) >= strlen(p2) && strlen(p1) >= strlen(p3)) {
        printf("La parola piu' lunga e' %s\n", p1);
    } else if (strlen(p2) >= strlen(p1) && strlen(p2) >= strlen(p3)) {
        printf("La parola piu' lunga e' %s\n", p2);
    } else {
        printf("La parola piu' lunga e' %s\n", p3);
    }

    if (strcmp(p1, p2) <= 0 && strcmp(p1, p3) <= 0) {
        printf("La parola che viene prima e' %s\n", p1);
    } else if (strcmp(p2, p1) <= 0 && strcmp(p2, p3) <= 0) {
        printf("La parola che viene prima e' %s\n", p2);
    } else {
        printf("La parola che viene prima e' %s\n", p3);
    }

    nvp1 = contaVocali(p1);
    nvp2 = contaVocali(p2);
    nvp3 = contaVocali(p3);

    if (nvp1 > nvp2 && nvp1 > nvp3) {
        printf("La parola che ha piu' vocali e' %s\n", p1);
    } else if (nvp2 > nvp1 && nvp2 > nvp3) {
        printf("La parola che ha piu' vocali e' %s\n", p2);
    } else {
        printf("La parola che ha piu' vocali e' %s\n", p3);
    }
}
```

</details> 

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione con array di stringhe e bubble sort
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>

#define N 3
#define M 50

int contaVocali(char stringa[]) {
    int ris = 0;
    int i;
    for (i = 0; stringa[i] != 0; i++) {
        if (stringa[i] == 'a' || stringa[i] == 'e' || stringa[i] == 'i' ||
            stringa[i] == 'o' || stringa[i] == 'u' || stringa[i] == 'A' ||
            stringa[i] == 'E' || stringa[i] == 'I' || stringa[i] == 'O' ||
            stringa[i] == 'U') {
                ris++;
        }
    }
    return ris;
}

int main() {
    char parole[N][M], tmp[M];
    int i, j;

    printf("Scrivi 3 parole: ");
    scanf("%s %s %s", parole[0], parole[1], parole[2]);

    // ordino per lunghezza della stringa
    for (i = 0; i < N-1; i++) {
        for (j = 0; j < N-1; j++) {
            if (strlen(parole[j]) < strlen(parole[j+1])) {
                strcpy(tmp, parole[j]);
                strcpy(parole[j], parole[j+1]);
                strcpy(parole[j+1], tmp);
            }
        }
    }

    printf("La parola piu' lunga e' %s\n", parole[0]);

    // ordino alfabeticamente
    for (i = 0; i < N-1; i++) {
        for (j = 0; j < N-1; j++) {
            if (strcmp(parole[j], parole[j+1]) > 0) {
                strcpy(tmp, parole[j]);
                strcpy(parole[j], parole[j+1]);
                strcpy(parole[j+1], tmp);
            }
        }
    }
    printf("La parola che viene prima e' %s\n", parole[0]);
    
    // ordino per numero di vocali
    for (i = 0; i < N-1; i++) {
        for (j = 0; j < N-1; j++) {
            if (contaVocali(parole[j]) < contaVocali(parole[j+1])) {
                strcpy(tmp, parole[j]);
                strcpy(parole[j], parole[j+1]);
                strcpy(parole[j+1], tmp);
            }
        }
    }
    printf("La parola che ha piu' vocali e' %s\n", parole[0]);

}
```

</details> 


#### Stampa sottostringhe con separatore
{: .numerato_da_h3}

Scrivi e utilizza una funzione che riceve una stringa e un carattere e che stampi tutto il contenuto della stringa andando a capo ogni volta che trova il carattere dato (il carattere rappresenta un separatore della stringa in sottostringhe).

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



#### Stampa sottostringhe con separatore 2
{: .numerato_da_h3}

Scrivi un programma che contenga in un array la seguente stringa “Ciao a tutti, mi chiamo Francesco\nOggi vi voglio parlare delle stringhe, siete d’accordo?” e che la stampi in modo tale che quando trova una virgola va a capo(oltre a stampare la virgola) e quando trova un a capo, va a capo due volte.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



#### Cifrario di Cesare
{: .numerato_da_h3}

Scrivi due funzioni che implementino il cifrario di Cesare cioè un cifrario che per cifrare un testo trasforma ogni lettera nella lettera che si trova tre posizioni più avanti nell’alfabeto. Le due funzioni sono le funzioni “cifra” e “decifra”. Scrivi infine u programma che permetta di inserire un testo da cifrare o decifrare a scelta.
Variante: Fai in modo che il numero di posizioni sia un parametro da passare alle funzioni (consiste nella chiave di cifratura)

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

void cifra(char frase[], int chiave) {
    int i;
    int nlettere = 'z' - 'a' + 1;

    for (i = 0; frase[i] != 0; i++) {
        if (frase[i] >= 'a' && frase[i] <= 'z'){
            frase[i] = (((frase[i] - 'a') + chiave) % nlettere) + 'a';
        } else if (frase[i] >= 'A' && frase[i] <= 'Z') {
            frase[i] = (((frase[i] - 'A') + chiave) % nlettere) + 'A';
        }
    }
}

void decifra(char frase[], int chiave) {
    int i;
    int nlettere = 'z' - 'a' + 1;

    for (i = 0; frase[i] != 0; i++) {
        if (frase[i] >= 'a' && frase[i] <= 'z'){
            frase[i] = (((frase[i] - 'a') - chiave) % nlettere) + 'a';
        } else if (frase[i] >= 'A' && frase[i] <= 'Z') {
            frase[i] = (((frase[i] - 'A') - chiave) % nlettere) + 'A';
        }
    }
}

int main() {
    char frase[] = "Ciao, come va?";
    printf("%s\n", frase);
    cifra(frase, 3);
    printf("%s\n", frase);
    decifra(frase, 3);
    printf("%s\n", frase);
}
```

</details> 


#### Ricerca sottostringa
{: .numerato_da_h3}

Scrivi e utilizza una funzione che riceve due stringhe e sia in grado di dire se la stringa più piccola è una sottostringa di quella più grande. Nel tuo programma il main deve creare due stringhe di lunghezza a piacere contenenti lettere casuali (solo lettere maiuscole e minuscole senza altri simboli o cifre; la funzione non cambia)
Variante: invece di dire se la stringa è contenuta nell’altra stringa restituire la posizione di partenza della sottostringa trovata.
Ad esempio “mi c” è sottostringa di “Ciao a tutti mi chiamo Francesco”

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int contiene(char piccola[], char grande[]) {
    int len_piccola = strlen(piccola);
    int len_grande = strlen(grande);
    int i, j;
    int ris;

    for (i = 0; i <= len_grande - len_piccola; i++) {
        ris = 1;
        for (j = 0; j < len_piccola; j++) {
            if (piccola[j] != grande[i + j]) {
                ris = 0;
                break;
            }
        }
        if (ris) {
            // return 1; // rispondo true se l'ho trovata
            return i; // per la posizione
        }
    }
    // return 0; // non l'ho trovata
    return -1; // quando non la trovo do posizione -1 che non esiste (metodo
    // standard)
}

void stringaCasuale(char stringa[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        stringa[i] = rand() % ('z' - 'a' + 1) + 'a';
    }
    stringa[i] = 0;
}

int main() {
    printf("%d\n", contiene("ciao", "ciao"));
    printf("%d\n", contiene("ciao", "aciao"));
    printf("%d\n", contiene("ciao", "ciaoa"));
    printf("%d\n", contiene("ciao", "aciaoa"));
    printf("%d\n", contiene("ciao", "ocia"));

    // fin qui non ho creato stringhe casuali, ho solo testato la funzione con
    // stringhe create da me

    srand(time(NULL));
    char piccola[10];
    char grande[100];
    stringaCasuale(piccola, 2);
    stringaCasuale(grande, 99);
    printf("Grande:  %s\n", grande);
    printf("Piccola: %s\n", piccola);
    printf("%d\n", contiene(piccola, grande));

}
```

</details> 



#### Operazioni varie su stringhe
{: .numerato_da_h3}

Scrivi un programma che chieda all'utente nome e cognome e poi:
1.	Verifichi che il nome e il cognome siano stati scritti con le iniziali maiuscole (devi controllare se la prima lettera ha i valori corretti secondo la tabella ASCII, i caratteri sono come numeri)
2.	crei una stringa che contenga le generalità dell'utente (nome e cognome insieme)
3.	stampi le generalità al contrario.
4.	chieda nuovamente nome e cognome e verifichi se sono state riscritte le stesse cose di prima

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



#### MyStrlen
{: .numerato_da_h3}

Scrivi e usa la tua versione della funzione strlen.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int mystrlen(char stringa[]) {
    int i;

    for (i = 0; stringa[i] != 0; i++) {

    }

    return i;
}

int main() {
    char boh[] = "ciao belli!!";
    printf("%d", mystrlen(boh));
}
```

</details> 


#### MyStrcpy
{: .numerato_da_h3}

Scrivi e usa la tua versione della funzione strcpy.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

void mystrcpy(char a[], char da[]) {
    int i;
    for (i = 0; da[i] != 0; i++) {
        a[i] = da[i];
    }
    a[i] = 0;
}

int main() {
    char da[] = "ciao belli.";
    char a[50];

    mystrcpy(a, da);

    printf("%s", a);
}
```

</details> 



#### MyStrcmp
{: .numerato_da_h3}

Scrivi e usa la tua versione della funzione strcmp.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int mystrcmp(char a[], char b[]) {
    int i;
    for (i = 0; a[i] != 0 && b[i] != 0; i++) {
        if (a[i] < b[i]) {
            return -1;
        }
        if (a[i] > b[i]) {
            return 1;
        }
    }
    if (a[i] == 0 && b[i] == 0) return 0;
    else if (a[i] == 0) return -1;
    else return 1;
}

int main() {
    char a[] = "";
    char b[] = "ciao";

    printf("%d", mystrcmp(a, b));
}
```

</details> 


#### Copia particolare
{: .numerato_da_h3}

Scrivi e usa una funzione che riceve una stringa e ti genera una seconda stringa che sia uguale alla prima e che però abbia tutte le lettere in posizione pari maiuscole.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

#define N 100

void modificaStringa(char originale[], char modificata[]) {
    int i;
    int diff = 'A' - 'a';
    char lettera;
    for (i = 0; originale[i] != 0; i++) {
        lettera = originale[i];
        if (i % 2 == 0 && lettera >= 'a' && lettera <= 'z') {
            lettera += diff;
        }
        modificata[i] = lettera;
    }
    modificata[i] = 0;
}

int main() {
    char frase[N] = "Dovete decidere il nome della vostra squadra!";
    char modificata[N];
    modificaStringa(frase, modificata);
    printf("%s\n%s\n", frase, modificata);
}
```

</details> 










<!-- ---------------------------------------------------------------------------------------------------------- -->

### Matrici di numeri
{: .numerato_da_h3 .azzera_numerazione_h4}

#### Tabelline
{: .numerato_da_h3}

Creare una matrice che contiene le tabelline dei numeri dall' 1 al 10. Alla fine stamparla.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

#define N 10
#define M 10

int main() {
    int mat[N][M];
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            mat[i][j] = (i+1)*(j+1);
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
}
```

</details> 



#### Stampa riga o colonna
{: .numerato_da_h3}

Scrivi un programma che istanzia una matrice n x m di interi casuali (n e m scelti da te). Oltre a stampare l'intera matrice, chiedi all'utente quale riga o quale colonna stampare e stampala sullo schermo.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 4
#define M 6

void stampaMatrice(int m[N][M]) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m[N][M];
    int i, j;
    int rig, col;

    srand(time(NULL));

    // riempio la matrice
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            m[i][j] = rand() % 10;
        }
    }

    stampaMatrice(m);

    rig = 2;
    printf("\nRiga %d: ", rig);
    for (j = 0; j < M; j++) {
        printf("%d ", m[rig][j]);
    }

    col = 3;
    printf("\nColonna %d:\n", col);
    for (i = 0; i < N; i++) {
        printf("%d\n", m[i][col]);
    }
}
```

</details> 



#### Somma e prodotto matrici
{: .numerato_da_h3}

Scrivere un programma che riempia due matrici A e B di dimensione n x m e calcoli la matrice C = A + B e la matrice D = A x B (in realtà è un finto prodotto di matrici). Stampa le matrici ottenute. Per il calcolo della somma calcola normalmente C[i][j] = A[i][j] + B[i][j] mentre per la moltiplicazione hai due possibilità:
1.	Versione semplice se non riesci proprio a fare la versione corretta: C[i][j] = A[i][j] x B[i][j].
2.	Versione complicata: vai a guardare su internet come si calcola e scrivi l’algoritmo per farlo.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



#### Scambiare righe
{: .numerato_da_h3}

Scrivi un programma che data una matrice n x m di interi, scambia le righe pari con quelle dispari
variante: le dimensioni della matrice vengono scelte dall'utente tra i valori massimi 10 x 20.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 100
#define M 100

void riempiMatrice(int mat[N][M], int n, int m, int min, int max) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            mat[i][j] = rand() % (max-min+1) + min;
        }
    }
}

void stampaMatrice(int mat[N][M], int n, int m) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }
}

void scambiaRighe(int mat[N][M], int n, int m) {
    int i, j, tmp;
    for (i = 0; i < n-1; i+=2) {
        for (j = 0; j < m; j++) {
            tmp = mat[i][j];
            mat[i][j] = mat[i+1][j];
            mat[i+1][j] = tmp;
        }
    }
}

int main() {
    int mat[N][M];
    int n, m;

    srand(time(NULL));

    do {
        printf("Scrivi il numero di righe, min 1, max 10: ");
        scanf("%d", &n);
    } while (n < 1 || n > 10);
    do {
        printf("Scrivi il numero di colonne, min 1, max 20: ");
        scanf("%d", &m);
    } while (m < 1 || m > 10);

    riempiMatrice(mat, n, m, 0, 99);
    printf("\nMatrice iniziale:\n");
    stampaMatrice(mat, n, m);

    scambiaRighe(mat, n, m);
    printf("\nMatrice dopo gli scambi:\n");
    stampaMatrice(mat, n, m);
}
```

</details> 



#### Scambiare righe con colonne
{: .numerato_da_h3}

Scrivi un programma che data una matrice n x n di interi, con n scelto dall'utente, scambia le righe con le colonne

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione senza usare funzioni
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 4

int main() {
    int mat[N][N];
    int i, j, tmp;
    
    srand(time(NULL));

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            mat[i][j] = rand() % 100;
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }

    // inverto righe e colonne
    for (i = 0; i < N; i++) {
        for (j = i+1; j < N; j++) {
            tmp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = tmp;
        }
    }

    printf("\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }
}
```

</details> 

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione con uso di funzioni
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 100
#define M 100

void riempiMatrice(int mat[N][M], int n, int m, int min, int max) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            mat[i][j] = rand() % (max-min+1) + min;
        }
    }
}

void stampaMatrice(int mat[N][M], int n, int m) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }
}

void scambiaRigheColonne1(int mat[N][N], int n) {
    int i, j;
    // uso una seconda matrice
    int m2[n][n];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            m2[j][i] = mat[i][j];
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            mat[i][j] = m2[i][j];
        }
    }
}

void scambiaRigheColonne2(int mat[N][N], int n) {
    int i, j, tmp;
    // lavoro sulla stessa matrice
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            tmp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = tmp;
        }
    }
}

int main() {
    int mat[N][N];
    int n;

    srand(time(NULL));

    do {
        printf("Scrivi il numero di righe, min 1, max 10: ");
        scanf("%d", &n);
    } while (n < 1 || n > 10);

    riempiMatrice(mat, n, n, 0, 99);
    printf("\nMatrice iniziale:\n");
    stampaMatrice(mat, n, n);

    scambiaRigheColonne1(mat, n);
    printf("\nMatrice dopo gli scambi 1:\n");
    stampaMatrice(mat, n, n);

    scambiaRigheColonne2(mat, n);
    printf("\nMatrice dopo gli scambi 2:\n");
    stampaMatrice(mat, n, n);
}
```

</details> 



#### Recerca numero più frequente
{: .numerato_da_h3}

Scrivi un programma che riempia una matrice n x m di numeri interi a caso, n e m sono scelti dall’utente e il range dei numeri è da 0 a x scelto anch’esso dall’utente. Determina poi il numero più frequente generato nella matrice. Il riempimento delle matrici e la ricerca del numero più frequente devono essere svolti da due apposite funzioni, mentre l’interazione con l’utente dev’essere lasciata al main.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 100
#define M 100
#define MAX 100

void riempiMatrice(int mat[N][M], int n, int m, int min, int max) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            mat[i][j] = rand() % (max-min+1) + min;
        }
    }
}

void stampaMatrice(int mat[N][M], int n, int m) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }
}

int piuFrequente(int mat[N][M], int n, int m) {
    int i, j;
    int occorrenze[MAX+1];
    int max;
    
    // azzero le occorrenze per ogni numero, la posizione indica il numero
    for (i = 0; i <= MAX; i++) {
        occorrenze[i] = 0;
    }

    // conto le occorrenze
    max = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            occorrenze[mat[i][j]] += 1;
            if (occorrenze[mat[i][j]] > occorrenze[max]) {
                max = mat[i][j];
            }
        }
    }
    return max;
}

int main() {
    int mat[N][M];
    int n, m, max, ris;

    srand(time(NULL));

    do {
        printf("Scrivi il numero di righe, min 1, max 10: ");
        scanf("%d", &n);
    } while (n < 1 || n > 10);
    do {
        printf("Scrivi il numero di colonne, min 1, max 20: ");
        scanf("%d", &m);
    } while (m < 1 || m > 20);

    do {
        printf("Scrivi il valore massimo da generare, min 0, max %d: ", MAX);
        scanf("%d", &max);
    } while (max < 1 || max > MAX);

    riempiMatrice(mat, n, m, 0, max);
    printf("\nMatrice iniziale:\n");
    stampaMatrice(mat, n, m);

    ris = piuFrequente(mat, n, m);
    printf("\nIl numero più frequente: %d\n", ris);
}
```

</details> 



#### Riga o colonna con massima somma
{: .numerato_da_h3}

Scrivi un programma che riempia una matrice n x m di numeri interi a caso, n e m sono scelti dall’utente e il range dei numeri è da 0 a x scelto anch’esso dall’utente. Determina poi il la riga o la colonna con la somma dei numeri più grande. Il riempimento delle matrici e la ricerca della riga o della colonna devono essere svolti da apposite funzioni, mentre l’interazione con l’utente dev’essere lasciata al main.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 

#### Riga o colonna con massima somma 2 (da fondere con l'1)
{: .numerato_da_h3}

data una matrice n x m di numeri casuali (n e m scelti da te), stampa l'indice della riga con la massima somma dei numeri contenuti. Stampa anche l'indice della colonna con la massima somma dei numeri.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3
#define M 4

int main() {
    int mat[N][M];
    int i, j;
    int somma, sommamax, imax, jmax;

    srand(time(NULL));

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            mat[i][j] = rand() % 10;
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }

    // trovo la riga massima
    imax = 0;
    sommamax = 0;
    for (i = 0; i < N; i++) {
        somma = 0;
        for (j = 0; j < M; j++) {
            somma += mat[i][j];
        }
        if (somma > sommamax) {
            sommamax = somma;
            imax = i;
        }
    }
    printf("Riga con somma massima: %d\n", imax);

    // trovo la colonna massima
    jmax = 0;
    sommamax = 0;
    for (j = 0; j < M; j++) {
        somma = 0;
        for (i = 0; i < N; i++) {
            somma += mat[i][j];
        }
        if (somma > sommamax) {
            sommamax = somma;
            jmax = j;
        }
    }
    printf("Colonna con somma massima: %d\n", jmax);
}
```

</details> 

	

#### Ricerca presenza e coordinate numero
{: .numerato_da_h3}

Scrivi un programma che:

1.	crei e riempia di valori casuali una matrice di dimensioni a tua scelta, 
2.	ne stampi il contenuto sullo schermo, 
3.	chieda all'utente un numero e cerchi se il numero è presente nella matrice
4.	se il numero è presente si stampino le coordinate della posizione nella matrice

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 	







#### Conteggio per riga e per colonna
{: .numerato_da_h3}

Scrivi un programma che per mezzo di un’apposita funzione riempia una matrice di numeri casuali. Stampa poi il numero di numeri pari contenuti in ogni riga della matrice (riga per riga separatamente) e il numero di numeri dispari contenuti in ogni colonna della matrice. Anche in questo caso definisci una o due funzioni per farlo (a scelta).

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



#### Stampa parte di matrice
{: .numerato_da_h3}

Riempi una matrice di numeri casuali (dimensione a scelta), poi scegli di stampare solo una parte della matrice: a partire da una riga ad un'altra e a partire da una colonna ad un'altra.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define M 10

int main() {
    int mat[N][M];
    int i, j;
    int ri, rf, ci, cf;

    srand(time(NULL));

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            mat[i][j] = rand() % 100;
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }

    ri = 2;
    rf = 5;
    ci = 1;
    cf = 3;

    printf("\n");
    for (i = ri; i <= rf; i++) {
        for (j = ci; j <= cf; j++) {
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }

}
```

</details> 



#### Stampa dei soli numeri pari
{: .numerato_da_h3}

Riempi una matrice di numeri casuali, poi stampa la matrice in modo che siano visibili solo i numeri pari

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



#### Stampa diagonali
{: .numerato_da_h3}

Riempi una matrice quadrata di numeri casuali, poi stampa le diagonali in entrambe le direzioni. La stampa delle diagonali avviene in orizzontale.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



#### Stampa diagonali 2
{: .numerato_da_h3}

Riempi una matrice di numeri casuali, poi stampa la matrice in modo che siano visibili solo le diagonali (La struttura della matrice deve rimanere, si deve vedere una sorta di X)

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



#### Stampa diagonali 3
{: .numerato_da_h3}

Complicato!

Scrivi un programma che riempia una matrice di numeri casuali e che stampi i numeri contenuti in ogni diagonale, prima delle diagonali che vanno da in basso a sinistra a in alto a destra, poi da in alto a sinistra a in basso a destra.

Variante: invece che stampare solamente i numeri, crea una matrice che contenga per ogni riga i valori contenuti in una diagonale. Devono essere create due matrici, una per ogni diversa direzione delle diagonali. Attento che avrai bisogno di memorizzare il numero di elementi di ogni diagonale (e quindi riga della matrice)

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3
#define M 5

int main() {
    int mat[N][M];
    int i, j;

    srand(time(NULL));

    printf("Matrice intera:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            mat[i][j] = rand() % 100;
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // sola stampa diagonali su-sx a giu-dx \.
    printf("Diagonali \\:\n");
    for (j = -N + 1; j < M; j++) {
        for (i = 0; i < N; i++) {
            if (j + i >= 0 && j + i < M) {
                printf("%2d ", mat[i][j + i]);
            }
        }
        printf("\n");
    }
    printf("\n");

    // sola stampa diagonali /.
    printf("Diagonali /:\n");
    for (j = -N + 1; j < M; j++) {
        for (i = N - 1; i >= 0; i--) {
            if (j + (N - 1 - i) >= 0 && j + (N - 1 - i) < M) {
                printf("%2d ", mat[i][j + (N - 1 - i)]);
            }
        }
        printf("\n");
    }
    printf("\n");

    // sola stampa diagonali /. usando le i in maniera diversa (forse più
    // comprensibile)
    printf("Diagonali / alternativo:\n");
    for (j = -N + 1; j < M; j++) {
        for (i = 0; i < N; i++) {
            if (j + i >= 0 && j + i < M) {
                printf("%2d ", mat[N - 1 - i][j + i]);
            }
        }
        printf("\n");
    }
    printf("\n");
}
```

</details> 








<!-- ------------------------------------------------------------------------------------- -->

### Array di stringhe o matrici di caratteri
{: .numerato_da_h3 .azzera_numerazione_h4}


#### Lettura nomi e modifica iniziale maiuscola
{: .numerato_da_h3}

Scrivi un programma che chieda all'utente una serie di nomi che devono essere tutti memorizzati in un array di stringhe (e sarà quindi una matrice, ad esempio `char nomi[n][m]` con n numero dei nomi e m numero massimo di caratteri per stringa). Il numero di nomi da inserire deve essere chiesto all'utente. Quando viene inserito un nome bisogna controllare che inizi con una lettera e se questa è minuscola deve essere fatta diventare maiuscola. Alla fine stampa tutte le stringhe.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <ctype.h>

#define N 100
#define M 100

int main() {
    int n, i;
    char nomi[N][M];

    n = 3;
    for (i = 0; i < n; i++) {
        printf("Scrivi il %d nome: ", i+1);
        fgets(nomi[i], M, stdin);
        // if (nomi[i][0] >= 'a' && nomi[i][0] <= 'z') {
        //     nomi[i][0] += 'A' - 'a';
        // }
        nomi[i][0] = toupper(nomi[i][0]);
    }

    for (i = 0; i < n; i++) {
        printf("%s", nomi[i]);
    }
}
```

</details> 



#### Ricerche condizionali stringhe
{: .numerato_da_h3}

Continua l’esercizio precedente aggiungendo le seguenti funzionalità:

1.	Cerca e stampa il nome più lungo
2.	Cerca e stampa il nome che in ordine alfabetico è il primo
3.	Chiedi all'utente un nome e digli se il nome è presente nell'elenco dei nomi (usa strcmp).

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define N 100
#define M 100

int main() {
    int n, i;
    char nomi[N][M];
    char lungo[M];
    char primo[M];
    char cercare[M];

    n = 3;
    for (i = 0; i < n; i++) {
        printf("Scrivi il %d nome: ", i+1);
        scanf(" %99[^\n]", nomi[i]);
        // if (nomi[i][0] >= 'a' && nomi[i][0] <= 'z') {
        //     nomi[i][0] += 'A' - 'a';
        // }
        nomi[i][0] = toupper(nomi[i][0]);
    }

    for (i = 0; i < n; i++) {
        printf("%s\n", nomi[i]);
    }

    // printf("-----");

    // cerco il più lungo
    strcpy(lungo, nomi[0]);
    for (i = 1; i < n; i++) {
        if (strlen(nomi[i]) > strlen(lungo)) {
            strcpy(lungo, nomi[0]);
        }
    }
    //alternativa
    int ilungo = 0;
    for (i = 1; i < n; i++) {
        if (strlen(nomi[i]) > strlen(nomi[ilungo])) {
            ilungo = i;
        }
    }
    printf("Il nome piu' lungo e': %s\n", nomi[ilungo]);

    // 2.  Cerca e stampa il nome che in ordine alfabetico è il primo
    int iprimo = 0;
    for (i = 1; i < n; i++) {
        if (strcmp(nomi[i], nomi[iprimo]) < 0) {
            iprimo = i;
        }
    }
    printf("Il primo nome in ordine alfabetico e': %s\n", nomi[iprimo]);

    // 3.  Chiedi all'utente un nome e digli se il nome è presente
    // nell'elenco dei nomi (usa strcmp).
    printf("Scrivi un nome da cercare: ");
    // fgets(cercare, M, stdin);
    scanf(" %99[^\n]", cercare);
    for (i = 0; i < n; i++) {
        if (strcmp(nomi[i], cercare) == 0) {
            printf("Il nome e' presente nell'elenco.\n");
            break;
        }
    }
    if (i == n) {
        printf("Il nome non e' presente nell'elenco.\n");
    }

}
```

</details> 



#### Stringhe più lunga, più corta e lunghezza media
{: .numerato_da_h3}

Dato un array di stringhe (quindi una matrice), riempito come preferisci, stampa la stringa più lunga, la più corta e la lunghezza media delle stringhe. I tre risultati devono essere ottenuti per mezzo di apposite funzioni.

Variante: voglio contare non tutti i caratteri ma solo le lettere (no punteggiatura e spazi o altro)

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>

#define N 100
#define M 100

int main() {
    char mat[N][M];
    int n;
    int i;

    strcpy(mat[0], "Ciao");
    strcpy(mat[1], "belli");
    strcpy(mat[2], "evviva!");
    n = 3;

    // la più lunga
    int ilunga = 0;
    for (i = 1; i < n; i++) {
        if (strlen(mat[i]) > strlen(mat[ilunga])) {
            ilunga = i;
        }
    }
    printf("La parola piu' lunga e': %s\n", mat[ilunga]);

    // la più corta
    int icorta = 0;
    for (i = 1; i < n; i++) {
        if (strlen(mat[i]) < strlen(mat[icorta])) {
            icorta = i;
        }
    }
    printf("La parola piu' corta e': %s\n", mat[icorta]);

    // lunghezza media delle stringhe
    float media = 0;
    for (i = 0; i < n; i++) {
        media += strlen(mat[i]);
    }
    media /= n;
    printf("La lunghezza media delle parole e': %.2f\n", media);

}
```

</details> 

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione Variante
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>

#define N 100

#define TRUE 1
#define FALSE 0

int isLettera(char lettera) {
    if ((lettera > 'a' && lettera < 'z') || (lettera > 'A' && lettera < 'Z')) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int numLettere(char stringa[]) {
    int i, ris;
    ris = 0;
    for (i = 0; stringa[i] != 0; i++) {
        if (isLettera(stringa[i])) {
            ris++;
        }
    }
    return ris;
}

int main() {
    char elenco[N][N];
    int i, n, imax, imin;
    float media;

    strcpy(elenco[0], "Michele sta imparando le stringhe");
    strcpy(elenco[1], "Molteni non si sa che cosa sa già fare");
    strcpy(elenco[2], "Enrico pensa di saper fare tutto");
    strcpy(elenco[3], "Anche Davide");
    n = 4;

    imin = 0;
    imax = 0;
    media = 0;
    for (i = 1; i < n; i++) {
        // versione base
        // if (strlen(elenco[i]) > strlen(elenco[imax])) {
        //     imax = i;
        // }
        // if (strlen(elenco[i]) < strlen(elenco[imin])) {
        //     imin = i;
        // }
        // media += strlen(elenco[i]);

        // versione variante
        if (numLettere(elenco[i]) > numLettere(elenco[imax])) {
            imax = i;
        }
        if (numLettere(elenco[i]) < numLettere(elenco[imin])) {
            imin = i;
        }
        media += numLettere(elenco[i]);
    }
    media /= n;

    printf("La stringa piu' lunga e': \"%s\"\n", elenco[imax]);
    printf("La stringa piu' corta e': \"%s\"\n", elenco[imin]);
    printf("La lunghezza media delle stringhe e': \"%g\"\n", media);
}
```

</details> 



#### Conteggio parole palindrome
{: .numerato_da_h3}

Scrivi e usa una funzione che dato un array di stringhe (quindi una matrice), restituisca il numero di parole palindrome contenute nell’array. Riempi l’array come preferisci.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>

#define N 100
#define M 100

int palindrome(char elenco[][M], int n) {
    int i, j, ris = 0, palindroma, m;
    for (i = 0; i < n; i++) {
        palindroma = 1;
        m = strlen(elenco[i]);
        for (j = 0; j < m / 2; j++) {
            if (elenco[i][j] != elenco[i][m-1-j]) {
                palindroma = 0;
                break;
            }
        }
        if (palindroma) {
            ris++;
        }
    }
    return ris;
}

int main() {
    char elenco[N][M];
    int n;

    strcpy(elenco[0], "casa");
    strcpy(elenco[1], "anna");
    strcpy(elenco[2], "osso");
    strcpy(elenco[3], "cammello");
    strcpy(elenco[4], "onorarono");
    strcpy(elenco[5], "fragnelli");
    strcpy(elenco[6], "corrado");
    strcpy(elenco[7], "chiara");
    n = 8;

    // int x = palindrome(elenco, n);

    printf("Le parole palindrome sono %d\n", palindrome(elenco, n));
}
```

</details> 



#### Campo Minato
{: .numerato_da_h3}

Scrivi un programma che permetta di rappresentare il campo di gioco di “Campo minato”. Il campo deve essere formato da una superficie suddivisa in caselle quadrate, quindi avrai una grande tabella (ad esempio di dimensioni 8x12 ma puoi scegliere diversamente). Sul campo devono essere disposte a caso una serie di mine (suggerisco 16 ma puoi cambiare). Fai poi in modo che ogni casella che non sia una mina abbia un numero che rappresenti il numero di mine adiacenti (anche in diagonale quindi un numero da 1 a 8) lasciando vuote le celle che non hanno mine adiacenti (non scrivere 0) 

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>

#define N 100
#define M 100

int palindrome(char elenco[][M], int n) {
    int i, j, ris = 0, palindroma, m;
    for (i = 0; i < n; i++) {
        palindroma = 1;
        m = strlen(elenco[i]);
        for (j = 0; j < m / 2; j++) {
            if (elenco[i][j] != elenco[i][m-1-j]) {
                palindroma = 0;
                break;
            }
        }
        if (palindroma) {
            ris++;
        }
    }
    return ris;
}

int main() {
    char elenco[N][M];
    int n;

    strcpy(elenco[0], "casa");
    strcpy(elenco[1], "anna");
    strcpy(elenco[2], "osso");
    strcpy(elenco[3], "cammello");
    strcpy(elenco[4], "onorarono");
    strcpy(elenco[5], "fragnelli");
    strcpy(elenco[6], "corrado");
    strcpy(elenco[7], "chiara");
    n = 8;

    // int x = palindrome(elenco, n);

    printf("Le parole palindrome sono %d\n", palindrome(elenco, n));
}
```

</details> 



#### Agenda
{: .numerato_da_h3}

Crea un programma di gestione di una agenda. L’agenda deve permettere di visualizzare e inserire i dati riguardanti i propri contatti. Per ogni persona devono essere memorizzati nome cognome e numero di telefono. La visualizzazione dei dati deve avvenire in ordine alfabetico per nome o cognome (scegli tu). Aggiungi poi una funzione per cancellare un contatto in una specifica posizione dell’agenda. (Non avendo ancora fatto la gestione dei files ogni volta l’agenda partirà da uno stato predefinito che puoi decidere tu). Aggiungi anche un’interfaccia utilizzabile.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 
	


#### Lettura frase
{: .numerato_da_h3}

Scrivi un programma che chieda all’utente di scrivere una frase. Le parole della frase devono poi essere stampate una per volta andando sempre a capo tra una parola e l’altra. La lettura può avvenire usando opportunamente scanf, gets o fgets.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



#### Concatenamento stringhe
{: .numerato_da_h3}

Scrivi un programma che chieda all’utente di scrivere una serie di parole lette una ad una. Queste parole devono essere unite a formare un’unica stringa che deve essere infine stampata.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>

#define N 5
#define M 100

int main() {
    char parole[N][M];
    int i, j, k;
    char frase[N*M];

    printf("Scrivere 5 parole.\n");
    for (i = 0; i < N; i++) {
        printf("La numero %d: ", i+1);
        scanf("%s", parole[i]);
    }

    // // opzione 1 veloce
    // strcpy(frase, parole[0]);
    // for (i = 1; i < N; i++) {
    //     strcat(frase, " ");
    //     strcat(frase, parole[i]);
    // }

    // opzione 2 lenta
    k = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; parole[i][j] != 0; j++) { // 0 == '\0' come ' ' == 32
            frase[k] = parole[i][j];
            k++;
        }
        frase[k] = ' ';
        k++;
    }
    frase[k] = 0;

    printf("\n%s\n", frase);
}
```

</details> 



#### Ordinamento alfabetico
{: .numerato_da_h3}

Scrivi un programma che chieda all’utente di scrivere una frase. Le parole della frase devono poi essere ordinate e stampate in ordine alfabetico. (consiglio: prendi le parole dalla stringa, mettile in un array e ordina l’array).

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 





<!-- -------------------------------------------------------------------------------- -->

### Algoritmi di ordinamento
{: .numerato_da_h3 .azzera_numerazione_h4}


#### Selection Sort 2
{: .numerato_da_h3}

Carica un array di numeri casuali e utilizza il selection sort per ordinarlo. Deve essere fatta una stampa dell’array prima e dopo l’ordinamento

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



#### Bubble Sort 2
{: .numerato_da_h3}

Carica un array di numeri casuali e utilizza il bubble sort per ordinarlo. Deve essere fatta una stampa dell’array prima e dopo l’ordinamento

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



#### Sort libreria standard
{: .numerato_da_h3}

Carica un array di numeri casuali e utilizza la funzione sort della libreria standard per ordinarlo. Deve essere fatta una stampa dell’array prima e dopo l’ordinamento

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



#### 
{: .numerato_da_h3}

Scrivi un programma che dato un array di numeri interi, sia in grado di:

1.	controllare se l'array è palindromo,
2.	invertire l'ordine dei numeri dell'array,
3.	ordinare in ordine decrescente l'array.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



#### Ordinamento stringhe
{: .numerato_da_h3}

Dato un array di stringhe (quindi una matrice di caratteri), che puoi riempire come preferisci, ordina l’array in ordine alfabetico prima crescente e poi decrescente. Devono essere inserite le stampe dell’intero array prima e dopo ogni ordinamento.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



#### Agenda 2
{: .numerato_da_h3}

Crea un programma di gestione di una agenda. L’agenda deve permettere di visualizzare e inserire i dati riguardanti i propri contatti. Per ogni persona devono essere memorizzati nome cognome e numero di telefono. La visualizzazione dei dati deve avvenire in ordine alfabetico per nome o cognome (scegli tu). (Non avendo ancora fatto la gestione dei files ogni volta l’agenda partirà da uno stato predefinito che puoi decidere tu).

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>

#define N 100
#define M 100

char nomi[N][M];
char cognomi[N][M];
char numeri[N][M];
int n;

void ordinaAgenda() {
    int i, j;
    char tmp[M];
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1-i; j++) {
            if (strcmp(nomi[j], nomi[j+1]) > 0) {
                strcpy(tmp, nomi[j]);
                strcpy(nomi[j], nomi[j+1]);
                strcpy(nomi[j+1], tmp);

                strcpy(tmp, cognomi[j]);
                strcpy(cognomi[j], cognomi[j+1]);
                strcpy(cognomi[j+1], tmp);

                strcpy(tmp, numeri[j]);
                strcpy(numeri[j], numeri[j+1]);
                strcpy(numeri[j+1], tmp);
            }
        }
    }
}

int inserisciContatto(char nome[M], char cognome[M], char numero[M]) {
    if (n < N-1) {
        strcpy(nomi[n], nome);
        strcpy(cognomi[n], cognome);
        strcpy(numeri[n], numero);
        n++;
        ordinaAgenda();
        return 0;
    }
    return 1;
}

void stampaContatti() {
    int i;
    for (i = 0; i < n; i++) {
        printf("%s %s - %s\n", nomi[i], cognomi[i], numeri[i]);
    }
}

int main() {
    int scelta = -1;
    char nome[M];
    char cognome[M];
    char numero[M];

    do {
        printf("   AGENDA   \n\n");
        printf("1. Visualizza contatti\n");
        printf("2. Inserisci contatto\n");
        printf("3. esci\n");

        printf("\nChe cosa vuoi fare? ");
        scanf("%d", &scelta);
        while (scelta < 1 || scelta > 3) {
            printf("Scelta non prevista, riprova: ");
            scanf("%d", &scelta);
        }

        if (scelta == 1) {
            printf("\n\nElenco dei contatti:\n\n");
            stampaContatti();
        } else if (scelta == 2) {
            printf("Scrivi il nome: ");
            scanf("%s", nome);
            printf("Scrivi il cognome: ");
            scanf("%s", cognome);
            printf("Scrivi il numero: ");
            scanf("%s", numero);

            if (inserisciContatto(nome, cognome, numero)) {
                printf("L'agenda e' piena.\n");
            } else {
                printf("Contatto inserito.\n");
            }
        }
    } while (scelta != 3);
    
}
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







<script src="{{site.baseurl}}/assets/js/esercizi-subnetting.js"></script>




