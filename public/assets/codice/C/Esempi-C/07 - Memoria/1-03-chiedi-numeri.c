// chiedi all'utente di inserire in un'unica riga una serie di numeri interi. il
// tuo programma deve leggere questi numeri e metterli in un array che sia
// grande esattamente come il numero di numeri inseriti.
// stampa poi l'array.

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