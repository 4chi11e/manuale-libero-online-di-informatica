// Leggi l'elenco di nomi dal file di input e inseriscili in un array
// dinamico. Ordina poi l'elenco in ordine alfabetico.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 20

int main() {
    FILE *fp;
    int i, j, N, n;
    char (*nomi)[M]; // così definisco prima quanto sono grandi le singole stringhe

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