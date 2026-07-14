// Dopo aver definito una struttura VettoreInt e le funzioni per usarla come vettore,
// genera una sequenza di numeri casuali e salvali in memoria. La sequenza deve
// terminare quando la media dei numeri è 50 +- 0.01

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
#include "1-04-vettore.c"

int main() {
    int num, i;
    float media, somma;
    float obiettivo = 50, scarto = 0.001;
    VettoreInt v;

    srand(time(NULL));
    inizializza(&v);

    somma = 0;
    for (i = 0; 1; i++) {
        num = rand() % 99 + 1;
        push_back(&v, num);

        somma += num;
        media = somma / v.n;
        printf("%2d - %6.3f\n", v.data[i], media);
        if (media >= obiettivo-scarto && media <= obiettivo+scarto) {
            break;
        }
    }
}