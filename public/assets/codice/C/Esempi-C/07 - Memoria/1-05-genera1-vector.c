// Dopo aver definito una struttura VettoreInt e le funzioni per usarla come vettore,
// dichiara e riempi un VettoreInt di numeri casuali minori di 100. Fermati quando estrai 0
// (non aggiungere lo 0)


#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "1-04-vettore.c"

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