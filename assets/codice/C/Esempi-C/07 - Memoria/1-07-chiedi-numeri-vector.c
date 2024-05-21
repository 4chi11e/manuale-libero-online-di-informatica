// Dopo aver definito una struttura VettoreInt e le funzioni per usarla come vettore,
// chiedi all'utente di inserire in un'unica riga una serie di numeri interi. il
// tuo programma deve leggere questi numeri e metterli in un vettore.
// Stampali infine al contrario.

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