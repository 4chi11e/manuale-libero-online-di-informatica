#include "vettore.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

int main() {
    VettoreInt v;
    int i;
    int nnumeri = 135;

    srand(time(NULL));

    inizializza(&v);
    for (i = 0; i < nnumeri; i++) {
        push(&v, rand() % 100);
        // printf("Aggiunto %d\n", v.data[i]);
    }

    printf("Stampa del vettore v con capacita' %d e che contiene %d numeri\n",
           v.cap, v.n);
    for (i = 0; i < v.n; i++) {
        printf("%2d", v.data[i]);
        if (i > 0 && i % 10 == 9) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
    // fflush(stdout);
}