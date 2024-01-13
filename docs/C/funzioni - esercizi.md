---
layout: default
title: Funzioni - Esercizi
nav_order: 8
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

### Funzioni classiche
{: .numerato_da_h3 .azzera_numerazione_h4}

#### Somma di due numeri
{: .numerato_da_h3}

Scrivi e utilizza una funzione per calcolare e restituire la somma tra due numeri

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 




#### Calcolatrice
{: .numerato_da_h3}

Scrivi e utilizza 4 funzioni che effettuano le 4 operazioni e restituiscono il risultato.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 
 

#### Calcolatrice 2
{: .numerato_da_h3}

Scrivi e utilizza una funzione che dati due valori e un simbolo di una delle 4 operazioni effettua quella operazione e restituisce il risultato

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 


#### Raddoppia numero
{: .numerato_da_h3}

Scrivi e utilizza le seguenti funzioni:
1. raddoppia un numero passando parametri per valore,
2. raddoppia un numero passando parametri per indirizzo,
3. raddoppia due numeri contemporaneamente.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 


#### Prodotto di due numeri
{: .numerato_da_h3}

Scrivi e utilizza una funzione che restituisca il prodotto di due numeri e alla fine dell’esecuzione lasci modificati i due numeri in modo che valgano il doppio di prima.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 


#### Punto medio
{: .numerato_da_h3}

Funzione che date le coordinate di due punti nel piano, calcolino e restituiscano le coordinate del punto medio tra i due (senza approssimazioni).

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione con passaggio per indirizzo
  </summary>
  {: .text-delta }

```c

#include <stdio.h>

void puntoMedio(float ax, float ay, float bx, float by, float *mx, float *my) {
    *mx = (ax + bx) / 2;
    *my = (ay + by) / 2;
}

int main() {
    float ax, ay, bx, by, mx, my;
    ax = 1;
    ay = 1;
    bx = 3;
    by = 5;

    puntoMedio(ax,ay,bx,by, &mx, &my);
    printf("punto medio tra (%g, %g) e (%g, %g): (%g, %g)\n", ax, ay, bx, by, mx, my);
}
```

</details> 

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione con struct
  </summary>
  {: .text-delta }

```c

#include <stdio.h>

void puntoMedio(float ax, float ay, float bx, float by, float *mx, float *my) {
    *mx = (ax + bx) / 2;
    *my = (ay + by) / 2;
}

int main() {
    float ax, ay, bx, by, mx, my;
    ax = 1;
    ay = 1;
    bx = 3;
    by = 5;

    puntoMedio(ax,ay,bx,by, &mx, &my);
    printf("punto medio tra (%g, %g) e (%g, %g): (%g, %g)\n", ax, ay, bx, by, mx, my);
}
#include <stdio.h>

typedef struct {
    float x, y;
} Punto;

Punto puntoMedio(Punto A, Punto B) {
    Punto M;
    M.x = (A.x + B.x) / 2;
    M.y = (A.y + B.y) / 2;
    return M;
}

int main() {
    Punto A,B,M;
    A.x = 1;
    A.y = 1;
    B.x = 3;
    B.y = 5;

    M = puntoMedio(A, B);
    printf("punto medio tra (%g, %g) e (%g, %g): (%g, %g)\n", A.x, A.y, B.x, B.y, M.x, M.y);
}
```

</details> 



#### Caduta di un oggetto
{: .numerato_da_h3}

Funzione che dato il tempo di caduta di un oggetto, calcola l'altezza da cui è caduto l'oggetto e la velocità di impatto. Le formule che ti servono sono: h = 1/2 * g * t^2, con g=9,81 e v=g*t. Almeno uno dei due valori deve essere restituito normalmente

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

float calcolaCaduta(float t, float *v) {
    float g = 9.81;
    float h = 1.0 / 2.0 * g * t * t;
    *v = g * t;

    return h;
}

int main() {
    float t, h, v;
    t = 1;

    h = calcolaCaduta(t, &v);

    printf("Con una caduta di %g secondi, l'altezza e' %g m, e la velocita' di "
           "impatto e' %g m/s",
           t, h, v);
}
```

</details> 



#### Caduta di un oggetto 2
{: .numerato_da_h3}

Funzione che prevede se un oggetto si rompe cadendo da una certa altezza. Quello che ti serve sapere è quindi l’altezza da cui cade l’oggetto e la velocità massima di impatto che l’oggetto può sopportare. Le formule che ti servono sono: h = 1/2 * g * t^2, con g=9,81 e v=g*t. 

Variante: Modifica l’esercizio facendo in modo che la funzione restituisca anche la velocità di impatto.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



#### Aumenta numeri
{: .numerato_da_h3}

Scrivi ed utilizza una funzione che dati due numeri li aumenta entrambi di un certo valore passato come parametro.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



#### Massimo e minimo di un array
{: .numerato_da_h3}

Scrivi e utilizza una funzione che dato un array di numeri, trova e restituisce il massimo e il minimo numero presenti.
Soluzione

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

void maxmin(int a[], int n, int *max, int *min) {
    int i, imax, imin;

    for (i = 1, imax = 0, imin = 0; i < n; i++) {
        if (a[i] > a[imax]) imax = i;
        if (a[i] < a[imin]) imin = i;
    }
    *max = a[imax];
    *min = a[imin];
}

int main() {
    int a[] = {3,7,12,8,1,1,27};
    int n = 7;
    int max, min;
    maxmin(a,n,&max,&min);
    printf("%d - %d", min, max);
}
```

</details> 




#### Controllo iniziale maiuscola
{: .numerato_da_h3}

Scrivi e utilizza una funzione che, data una stringa, restituisce true se la stringa inizia con una lettera maiuscola.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int iniziaMaiuscola(char frase[]) {
    if (frase[0] >= 'A' && frase[0] <= 'Z') {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char frase1[] = "Ciao belli!";
    char frase2[] = "come stai oggi?";

    if (iniziaMaiuscola(frase1)) {
        printf("\"%s\" inizia con una lettera maiuscola.\n", frase1);
    } else {
        printf("\"%s\" inizia con una lettera minuscola.\n", frase1);
    }

    if (iniziaMaiuscola(frase2)) {
        printf("\"%s\" inizia con una lettera maiuscola.\n", frase2);
    } else {
        printf("\"%s\" inizia con una lettera minuscola.\n", frase2);
    }
}
```

</details> 



#### Stampa stringa spaziata
{: .numerato_da_h3}

Funzione che data una stringa, la stampa separando ogni carattere della stringa con uno spazio.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



#### Concatenazione stringhe
{: .numerato_da_h3}

Scrivi e utilizza una funzione che riceve come parametri due stringhe e restituisce una stringa che è la concatenazione delle altre due.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

void concatena(char ris[], char a[], char b[]) {
    int i, j, n;
    for (i = 0; a[i] != 0; i++) {
        ris[i] = a[i];
    }
    // for (j = 0; a[j] != 0; j++, i++) {
    //     ris[i] = b[j];
    // }
    // ris[i] = 0;
    n = i;
    for (i = 0; b[i] != 0; i++) {
        ris[n+i] = b[i];
    }
    ris[n+i] = 0;
}

int main() {
    char frase1[] = "Ciao belli";
    char frase2[] = "come state?";
    char frase3[100];
    concatena(frase3, frase1, ", ");
    concatena(frase3, frase3, frase2);
    printf("%s", frase3);
}
```

</details> 



#### Massimo minimo e media condizionale
{: .numerato_da_h3}

Scrivi un programma che, dati n voti in un array, li passi ad una funzione che restituisca la media dei voti escludendo il voto più alto e il voto più basso.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 

#### Stampa stringa
{: .numerato_da_h3}

Scrivi e utilizza una funzione che stampa una stringa ricevuta come parametro.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



#### Numero più frequente
{: .numerato_da_h3}

Scrivi un programma che utilizzi una funzione che, ricevuto un array di numeri interi, restituisce il numero che compare con più frequenza (in caso di parità restituisce il primo numero trovato con la frequenza maggiore).

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 


#### Scambio valori
{: .numerato_da_h3}

Scrivi una funzione che scambia il contenuto di due variabili intere (i valori devono rimanere scambiati per chi chiama la funzione).

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 
 

#### Ordinamento array composto
{: .numerato_da_h3}

Scrivi un programma che sappia riordinare un array. Per farlo dividi le seguenti funzionalità in diverse funzioni:
1. funzione che scambia il valore di due variabili
2. funzione che riceve un array e lo riempie di numeri casuali
3. funzione che stampa un array
4. funzione che riceve un array e lo ordina. Lo scambio del valore delle variabili deve essere fatto usando la funzione descritta sopra
5. main che dichiara un array e poi usando le funzioni descritte sopra lo riempie di numeri casuali, lo stampa, lo ordina e poi lo ristampa.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 


#### Quoziente e resto
{: .numerato_da_h3}

Scrivi e utilizza una funzione che calcola il quoziente tra due numeri interi e restituisce, oltre al quoziente anche il resto della divisione.


<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

void quozienteI(int num, int den, int *q, int *r) {
    *r = num;
    for (*q = 0; *r >= den; (*q)++) {
        *r -= den;
    }
}

int quozienteR(int num, int den, int *r) {
    if (num < den) {
        *r = num;
        return 0;
    } else {
        return 1 + quozienteR(num-den, den, r);
    }
}

int main() {
    int num = 14;
    int den = 3;
    int q, r;
    q = quozienteR(num, den, &r);
    printf("%d/%d = %d resto %d\n", num, den, q, r);
}
```

</details> 





#### Modifica lettere stringa
{: .numerato_da_h3}

Scrivi e utilizza una funzione che data una stringa, fa in modo che la prima lettera sia maiuscola e tutte le altre minuscole. i caratteri che non sono lettere non devono essere modificati.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 


#### Massimo comun divisore e semplificazione frazione
{: .numerato_da_h3}

Scrivi una funzione che calcola il massimo comune divisore tra due numeri.
Scrivi ed utilizza poi una funzione che dati due valori numeratore e denominatore, semplifica la frazione, usando la funzione mcd appena definita.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

typedef struct {
    int num, den;
} Frazione;

int mcd(int a, int b) {
    int max, min, i;
    if (a > b) {
        max = a;
        min = b;
    } else {
        max = b;
        min = a;
    }
    for (i = min; i > 0; i--) {
        if (max % i == 0 && min % i == 0) {
            return i;
        }
    }
}

Frazione semplificaV(Frazione a) {
    int div = mcd(a.num, a.den);
    a.num /= div;
    a.den /= div;
    return a;
}

void semplificaI(Frazione *a) {
    int div = mcd(a->num, a->den);
    a->num /= div;
    a->den /= div;
}

int main() {
    Frazione a, b;
    a.num = 36;
    a.den = 60;
    b = semplificaV(a);
    semplificaI(&a);
    printf("a: %d/%d\n", a.num, a.den);
    printf("b: %d/%d\n", b.num, b.den);
}
```

</details> 




#### Tipo di triangolo
{: .numerato_da_h3}

Scrivi ed utilizza una funzione che riceva come parametri tre numeri e che restituisca true se questi numeri possono essere le misure di un triangolo. In questo caso la funzione deve anche restituire una stringa in cui c'è scritto il tipo di triangolo (equilatero, isoscele, scaleno).

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>

int triangolo(float a, float b, float c, char tipo[]) {
    if (a >= b + c || b >= a + c || c >= a + b || a <= 0 || b <= 0 || c <= 0) {
        return 0; 
    } else {
        if (a == b && b == c) {
            strcpy(tipo, "equilatero");
        } 
        else if (a == b || a == c || b == c) {
            strcpy(tipo, "isoscele");
        } else {
            strcpy(tipo, "scaleno");
        }
        return 1;
    }
}

int main() {
    char tipo[20];
    float a, b, c;

    a = 10;
    b = 2;
    c = 3;
    if (triangolo(a,b,c,tipo)) {
        printf("%g, %g, %g formano un triangolo %s\n", a, b, c, tipo);
    } else {
        printf("%g, %g, %g  non formano un triangolo \n", a, b, c);
    }

    a = 10;
    b = 20;
    c = 15;
    if (triangolo(a,b,c,tipo)) {
        printf("%g, %g, %g formano un triangolo %s\n", a, b, c, tipo);
    } else {
        printf("%g, %g, %g  non formano un triangolo \n", a, b, c);
    }

    a = 10;
    b = 10;
    c = 10;
    if (triangolo(a,b,c,tipo)) {
        printf("%g, %g, %g formano un triangolo %s\n", a, b, c, tipo);
    } else {
        printf("%g, %g, %g  non formano un triangolo \n", a, b, c);
    }

    a = 10;
    b = 10;
    c = 12;
    if (triangolo(a,b,c,tipo)) {
        printf("%g, %g, %g formano un triangolo %s\n", a, b, c, tipo);
    } else {
        printf("%g, %g, %g  non formano un triangolo \n", a, b, c);
    }
}
```

</details> 



#### Media e mediana di un array
{: .numerato_da_h3}

Scrivi e utilizza una funzione che restituisce media e mediana di una serie di numeri contenuti in un array

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void mediaMediana(int v[], int n, float *media, float *mediana) {
    int a[n], i, j, tmp;

    // media
    *media = 0;
    for (i = 0; i < n; i++) {
        *media += v[i];
    }
    *media /= n;

    // mediana
    for (i = 0; i < n; i++) {
        a[i] = v[i];
    }
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1; j++) {
            if (a[j] > a[j+1]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    if (n % 2 == 0) {
        *mediana = (a[n/2-1] + a[n/2]) / 2.0;
    } else {
        *mediana = a[n/2];
    }
} 

int main() {
    int v[10];
    int n = 10;
    int i;
    float media, mediana;

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        v[i] = rand() % 20;
        printf("%d ", v[i]);
    }
    printf("\n");

    mediaMediana(v, n, &media, &mediana);
    printf("Media: %g\n", media);
    printf("Mediana: %g\n", mediana);

}
```

</details> 

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione con struct
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
    float a, b;
} CoppiaFloat;

CoppiaFloat mediaMediana(int v[], int n) {
    int a[n], i, j, tmp;
    CoppiaFloat ris;

    // media
    ris.a = 0;
    for (i = 0; i < n; i++) {
        ris.a += v[i];
    }
    ris.a /= n;

    // mediana
    for (i = 0; i < n; i++) {
        a[i] = v[i];
    }
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1; j++) {
            if (a[j] > a[j+1]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    if (n % 2 == 0) {
        ris.b = (a[n/2-1] + a[n/2]) / 2.0;
    } else {
        ris.b = a[n/2];
    }

    return ris;
} 

int main() {
    int v[10];
    int n = 10;
    int i;
    CoppiaFloat ris;

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        v[i] = rand() % 20;
        printf("%d ", v[i]);
    }
    printf("\n");

    ris = mediaMediana(v, n);
    printf("Media: %g\n", ris.a);
    printf("Mediana: %g\n", ris.b);
}
```

</details> 

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione con array
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void mediaMediana(int v[], int n, float ris[]) {
    int a[n], i, j, tmp;

    // media
    ris[0] = 0;
    for (i = 0; i < n; i++) {
        ris[0] += v[i];
    }
    ris[0] /= n;

    // mediana
    for (i = 0; i < n; i++) {
        a[i] = v[i];
    }
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1; j++) {
            if (a[j] > a[j+1]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    if (n % 2 == 0) {
        ris[1] = (a[n/2-1] + a[n/2]) / 2.0;
    } else {
        ris[1] = a[n/2];
    }
} 

int main() {
    int v[10];
    int n = 10;
    int i;
    float ris[2];

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        v[i] = rand() % 20;
        printf("%d ", v[i]);
    }
    printf("\n");

    mediaMediana(v, n, ris);
    printf("Media: %g\n", ris[0]);
    printf("Mediana: %g\n", ris[1]);
}
```

</details> 



#### Area e perimetro del triangolo dati 3 punti
{: .numerato_da_h3}

Dati tre punti nel piano calcola l’area e il perimetro del triangolo da essi formato

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 




### Funzioni ricorsive
{: .numerato_da_h3 .azzera_numerazione_h4}

#### Fattoriale iterativo
{: .numerato_da_h3}

Scrivi ed utilizza una funzione iterativa che calcola il fattoriale di un numero

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

long long f(int n) {
    long long ris = 1;

    if (n < 0) {
        return -1;
    }

    // while (n > 0) {
    //     ris *= n;
    //     n--;
    // }
    // return ris;

    int i;
    for (i = 1; i <= n; i++) {
        ris *= i;
    }
    
    return ris;
}

int main() {
    int n;
    for (n = -1; n <= 60; n++) {
        printf("%2d! = %lld\n", n, f(n));
    }
}
```

</details> 



#### Fattoriale ricorsivo
{: .numerato_da_h3}

Scrivi ed utilizza una funzione ricorsiva che calcola il fattoriale di un numero

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

long long f(int n) {
    if (n < 0) return -1;
    if (n == 0) return 1;
    return n * f(n-1);
}

int main() {
    int n;
    for (n = -1; n <= 60; n++) {
        printf("%2d! = %lld\n", n, f(n));
    }
}
```

</details> 



#### Fibonacci iterativo
{: .numerato_da_h3}

Scrivi una funzione iterativa che calcola l'ennesimo numero della successione di Fibonacci.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

long long fibonacci(int n) {
    long long i, fib = 1, fib1 = 1, fib2 = 0;

    if (n < 0) return -1;

    if (n == 0) {
        return 0;
    }

    for (i = 2; i <= n; i++) {
        fib = fib2+fib1;
        fib2 = fib1;
        fib1= fib;
    }
    return fib;
}

int main() {
    int i;
    for (i = -1; i < 60; i++) {
        printf("f(%d) = %lld\n", i, fibonacci(i));
    }
}
```

</details> 





#### Fibonacci ricorsivo
{: .numerato_da_h3}

Scrivi una funzione ricorsiva che calcola l'ennesimo numero della successione di Fibonacci.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int fibonacci(int n) {
    // quando uscire
    if (n < 0) return -1;
    if (n == 0) return 0;
    if (n == 1) return 1;

    // ricorsione
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int i;
    for (i = 0; i < 60; i++) {
        printf("f(%d) = %d\n", i, fibonacci(i));
    }
}
```

</details> 

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione con memoria
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

#define N 1000

long long ris[N], calcolato[N] = {0};

long long fibonacci(int n) {
    long long fib;
    // quando uscire
    if (n < 0) return -1;
    if (n == 0) return 0;
    if (n == 1) return 1;

    if (calcolato[n]) {
        return ris[n];
    } else {
        fib = fibonacci(n-1) + fibonacci(n-2);
        ris[n] = fib;
        calcolato[n] = 1;
    }
}

int main() {
    int i;
    for (i = 0; i < 100; i++) {
        printf("f(%d) = %lld\n", i, fibonacci(i));
    }
}
```

</details>


#### Moltiplicazione ricorsiva
{: .numerato_da_h3}

Scrivi una funzione ricorsiva che effettui la moltiplicazione tra due numeri

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int moltiplicazione(int a, int b){
    if (a == 0 || b == 0){
        return 0;
    }
    
    return a + moltiplicazione (a, b - 1);
}

int main() {
   int a = 7, b = 3; 
   printf ("%d", moltiplicazione(a, b));
  
}
```

</details> 



#### Quoziente ricorsivo
{: .numerato_da_h3}

Scrivi una funzione che calcola ricorsivamente il quoziente tra due numeri utilizzando le sottrazioni.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
// 12 / 4 = 1 + 8 / 4

#include <stdio.h>

int quozienteR(int a, int b) {
    if (b == 0) {
        return -1;
    }
    if (a < b) {
        return 0;
    }
    return 1 + quozienteR(a-b, b);
}

int main() {
    int a = 14;
    int b = 4;
    int resto, ris;

    ris = quozienteR(a, b);
    printf("%d / %d = %d   resto %d\n", a, b, ris);
}
```

</details> 
<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione col resto
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int quozienteR(int a, int b, int *resto) {
    if (b == 0) {
        return -1;
    }
    if (a < b) {
        *resto = a;
        return 0;
    }
    return 1 + quozienteR(a-b, b, resto);
}

int main() {
    int a = 14;
    int b = 4;
    int resto, ris;

    ris = quozienteR(a, b, &resto);
    printf("%d / %d = %d   resto %d\n", a, b, ris, resto);
}
```

</details> 



#### Stampa array
{: .numerato_da_h3}

Scrivi e utilizza tre diverse versioni di una funzione che stampa un array elemento per elemento. Le tre versioni sono:
1. Versione iterativa, cioè che usa un ciclo for
2. Versione ricorsiva che riceve come parametri solo l’array e il numero di elementi contenuti nell’array
3. Versione ricorsiva che riceve come parametri l’array e le posizioni di inizio e fine dell’array che vanno considerate.

Variante: Stampa l’array al contrario

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

void stampa1(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}
void stampa2(int a[], int n) {
    if (n < 1) return;
    stampa2(a, n-1);
    printf("%d ", a[n-1]);
}
void stampa3(int a[], int inizio, int fine) {
    if (inizio > fine) return;
    printf("%d ", a[inizio]);
    stampa3(a, inizio+1, fine);
}

void stampaContrario1(int a[], int n) {
    int i;
    for (i = n-1; i >= 0; i--) {
        printf("%d ", a[i]);
    }
}
void stampaContrario2(int a[], int n) {
    if (n < 1) return;
    printf("%d ", a[n-1]);
    stampaContrario2(a, n-1);
}
void stampaContrario3(int a[], int inizio, int fine) {
    if (inizio > fine) return;
    printf("%d ", a[fine]);
    stampaContrario3(a, inizio, fine-1);
}

int main() {
    int a[] = {1,2,3,4,5,6};
    int n  = 6;

    stampa1(a, n);
    printf("\n");
    stampa2(a, n);
    printf("\n");
    stampa3(a, 0, n-1);
    printf("\n");
    stampaContrario1(a, n);
    printf("\n");
    stampaContrario2(a, n);
    printf("\n");
    stampaContrario3(a, 0, n-1);
    printf("\n");
}
```

</details> 



#### Iversione array
{: .numerato_da_h3}

Scrivi e utilizza le versioni iterativa e ricorsiva di una funzione che riceve un array e inverte l'ordine dei numeri in esso contenuti.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

void invertiI(int a[], int n) {
    int i, tmp;
    for (i = 0; i < n/2; i++) {
        tmp = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = tmp;
    }
}

void invertiR(int a[], int inizio, int fine) {
    int tmp;
    if (inizio >= fine) {
        return;
    }

    tmp = a[inizio];
    a[inizio] = a[fine];
    a[fine] = tmp;

    invertiR(a, inizio+1, fine-1);
}

void stampa(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {4,7,4,8,6,7};
    int n = sizeof(a)/sizeof(a[0]);
    stampa(a, n);
    invertiI(a, n);
    stampa(a, n);
    invertiR(a, 0, n-1);
    stampa(a, n);
}
```

</details> 




#### Massimo e minimo ricorsivo
{: .numerato_da_h3}

Funzione ricorsiva per trovare i valori massimi e minimi di un vettore. Si possono creare diverse funzioni:
1. Due funzioni, una che restituisce il minimo e una che restituisce il massimo
2. Una funzione che restituisce una struct che contiene minimo e massimo
3. Una funzione che modifica due variabili passate per indirizzo

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

typedef struct {
    int min;
    int max;
} coppia;

int maxr(int a[], int n) {
    int resto;
    if (n <= 0) {
        printf("Hai passato un array vuoto!\n");
        return -1;
    }
    if (n == 1) {
        return a[0];
    }
    resto = maxr(a, n-1);
    if (resto > a[n-1]) {
        return resto;
    } else {
        return a[n-1];
    }
}

int minr(int a[], int n) {
    int resto;
    if (n <= 0) {
        printf("Hai passato un array vuoto!\n");
        return -1;
    }
    if (n == 1) {
        return a[0];
    }
    resto = minr(a, n-1);
    if (resto < a[n-1]) {
        return resto;
    } else {
        return a[n-1];
    }
}

coppia minmaxr(int a[], int n) {
    coppia ris;
    if (n <= 0) {
        printf("Hai passato un array vuoto!\n");
        ris.min = -1;
        ris.max = -1;
        return ris;
    }
    if (n == 1) {
        ris.min = a[0];
        ris.max = a[0];
        return ris;
    }
    ris = minmaxr(a, n-1);
    if (a[n-1] < ris.min) {
        ris.min = a[n-1];
    }
    if (a[n-1] > ris.max) {
        ris.max = a[n-1];
    }
    return ris;
}

void minmaxr2(int a[], int n, int *min, int *max) {
    coppia ris;
    if (n <= 0) {
        printf("Hai passato un array vuoto!\n");
        *min = -1;
        *max = -1;
        return;
    }
    if (n == 1) {
        *min = a[0];
        *max = a[0];
        return;
    }
    minmaxr2(a, n-1, min, max);
    if (a[n-1] < *min) {
        *min = a[n-1];
    }
    if (a[n-1] > *max) {
        *max = a[n-1];
    }
}

int main() {
    int a[] = {5,7,2,6,8,4};
    int n = sizeof(a)/sizeof(int);
    coppia minmax = minmaxr(a, n);
    int min, max;
    printf("max: %d\n", minmax.max);
    printf("min: %d\n", minmax.min);
    
    minmaxr2(a, n, &min, &max);
    printf("max: %d\n", max);
    printf("min: %d\n", min);
}
```

</details> 



#### Ricerca ricorsiva
{: .numerato_da_h3}

Funzione ricorsiva per cercare un valore all’interno di un vettore non ordinato (ricerca lineare). Risultato: –1 se non lo trova, altrimenti l’indice della posizione dove è stato trovato.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int trova(int a[], int n, int val) {
    if (n <= 0) {
        return -1;
    }
    if (a[n-1] == val) {
        return n-1;
    } else {
        trova(a,n-1,val);
    }
}

int main() {
    int a[] = {5, 7, 2, 6, 8, 4};
    int n = sizeof(a) / sizeof(int);
    int val = 4;
    printf("La posizione di %d: %d\n", val, trova(a,n,val));
}
```

</details> 



#### Ricerca ricorsiva 2
{: .numerato_da_h3}

Scrivere una funzione ricorsiva per cercare un valore all’interno di un vettore ordinato (ricerca dicotomica). Risultato: – 1 o l’indice. 

Indicazioni: se il vettore è ordinato, iniziate a controllare il numero a metà del vettore, se il numero controllato è più piccolo di quello da trovare, cercherò nella parte del vettore a sinistra (richiamo la funzione indicando come intervallo in cui cercare solo la parte a sinistra), se è più piccolo dovrò cercare a destra, se è uguale l'ho trovato.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int cerca(int a[], int num, int i, int f){
    int medio;
    if(i>f){
        return -1;
    }
    medio = (i+f)/2;
    if (a[medio] == num) {
        return medio;
    }
    if (num < a[medio]) {
        return cerca(a, num, i, medio-1);
    } else {
        return cerca(a, num, medio+1, f);
    }
}

int main() {
    int a[] = {2,5,7,11,19,25,27,37,50,68,99};
    int n = sizeof(a)/sizeof(int);

    printf("%d", cerca(a, 50, 0, n-1));
}
```

</details> 



#### Verifica array ricorsiva
{: .numerato_da_h3}

Scrivere una funzione ricorsiva che riceve un array di interi e restituisce true se gli elementi sono tutti dispari e false se non lo sono.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int tuttoDispari(int a[], int n) {
    if (n <= 0) {
        return 0;
    }
    else if (n == 1) {
        return (a[n-1] % 2 == 1);
    }
    else {
       return (a[n-1] % 2 == 1) && tuttoDispari(a, n-1);
    }
}

int main() {
    int a[] = {4,3,7,8,4,2,6};
    int b[] = {1,7,3,5,9};
    int c[] = {};
    printf("%d\n", tuttoDispari(a, 7));
    printf("%d\n", tuttoDispari(b, 5));
    printf("%d", tuttoDispari(c, 0));
}
```

</details> 



#### Prodotto valori array ricorsivo
{: .numerato_da_h3}

Scrivere una funzione ricorsiva che riceve un array di interi e restituisce il prodotto degli elementi negativi.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int prodottoNegativi(int a[], int n) {
    if (n <= 0) {
        return 1;
    }
    if (a[n-1] < 0) {
        return a[n-1] * prodottoNegativi(a, n-1);
    } else {
        return prodottoNegativi(a, n-1);
    }
}

int main() {
    int a[] = {-3,-4};
    int b[] = {1,7,3,5,9};
    int c[] = {};
    printf("%d\n", prodottoNegativi(a, 2));
    printf("%d\n", prodottoNegativi(b, 5));
    printf("%d\n", prodottoNegativi(c, 0));
}
```

</details> 



#### Bubble sort ricorsivo
{: .numerato_da_h3}

Scrivi una funzione di ordinamento ricorsiva che utilizzi il principio del bubble sort e che contenga al massimo un solo ciclo for.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione (migliorabile)
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

void ordinaArray(int a[], int n) {
    int i, tmp;
    if (n <= 1) {
        return;
    }
    for (i = 0; i < n-1; i++) {
        if (a[i] > a[i+1]){
            tmp = a[i];
            a[i] = a[i+1];
            a[i+1] = tmp;
        }
    }
    ordinaArray(a, n-1);
}

void stampaArray(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {1,6,3,8,5,7,7,3,2};
    int n = sizeof(a) / sizeof(int);

    stampaArray(a, n);
    ordinaArray(a, n);
    stampaArray(a, n);
}
```

</details> 



#### Massima differenza tra numeri consecutivi
{: .numerato_da_h3}

Scrivi e utilizza le versioni iterativa e ricorsiva di una funzione che dato un array di interi, calcola e restituisce la massima differenza tra due numeri consecutivi.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <stdlib.h>

int maxDiffR(int a[], int n) {
    int diff1, diff2;
    if (n <= 1) {
        return 0;
    }
    else if (n == 2) {
        return abs(a[1] - a[0]);
    }
    else {
        diff1 = abs(a[n-1] - a[n-2]);
        diff2 = maxDiffR(a, n-1);
        if (diff1 > diff2) {
            return diff1;
        } else {
            return diff2;
        }
    }
}

void stampaArray(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {1,6,3,8,5,7,7,3,2};
    int n = sizeof(a) / sizeof(int);

    stampaArray(a, n);
    printf("Massima differenza tra due numeri consecutivi: %d", maxDiffR(a, n));
}
```

</details> 



#### Ricerca condizionale
{: .numerato_da_h3}

Scrivi una funzione ricorsiva che riceva un array di punti (definisci la struct punto) e che restituisca il punto più vicino all’origine (definisci e usa la funzione distanza tra punti)

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
    float x, y;
} Punto;

float distanza(Punto a, Punto b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

Punto piuVicino(Punto v[], int n) {
    Punto ris, corrente, altri, origine = {0,0};
    float distcorrente, distaltri;

    if (n <= 0) {
        ris.x = 0;
        ris.y = 0;
        return ris;
    }

    if (n == 1) {
        return v[0];
    }

    corrente = v[n-1];
    distcorrente = distanza(corrente, origine);
    altri = piuVicino(v, n-1);
    distaltri = distanza(altri, origine);
    if (distcorrente < distaltri) {
        return corrente;
    } else {
        return altri;
    }
}

int main() {
    {% raw %}// Punto v[] = {{1,2}, {2.2, 5.8}, {0, 1}, {3,0}};{% endraw %}
    Punto v[5], vicino;
    int n = 5, i;
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        v[i].x = ((float)rand()/((float)RAND_MAX/20) ) - 10;
        v[i].y = ((float)rand()/((float)RAND_MAX/20) ) - 10;
        printf("(%.2f, %.2f) ", v[i].x, v[i].y);
    }

    vicino = piuVicino(v, n);
    printf("\n(%.2f, %.2f)\n", vicino.x, vicino.y);
}
```

</details> 

#### Stringa minuscola
{: .numerato_da_h3}

Scrivi una funzione ricorsiva che sia in grado di rendere minuscole tutte le lettere di una stringa

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



#### Stringa con vocali
{: .numerato_da_h3}

Scrivi una funzione ricorsiva che sia in grado di dire se una stringa contiene tutte le vocali

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

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




