// Leggi i numeri contenuti nel file di input e inseriscili in una matrice dinamica.
// Dai per scontato che ogni riga contenga la stessa quantità di numeri.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define K 1000

int main() {
    FILE *fp;
    int i, j;
    // le maiuscole indicano la capacità della matrice, le minuscole  la
    // quantità di valori effettivamente contenuti
    int N, M, n, m;
    int **mat;
    char riga[K];
    char *token;

    fp = fopen("1-09-leggi-matrice-input.txt", "r");
    if (fp == NULL) {
        printf("File non trovato\n");
        return 1;
    }

    N = 2;
    M = 2;
    // qui alloco un array dinamico di puntatori, ognuno a sua volta è un
    // array dinamico. Per ora ogni puntatore non punta a nulla.
    mat = malloc(N * sizeof(int *));
    n = 0;
    m = 0;
    for (i = 0; !feof(fp); i++) {
        if (i >= N) {
            N *= 2;
            // aggiungo puntatori cioè nuove righe
            mat = realloc(mat, N * sizeof(int *));
        }
        // è qui che alloco memoria per la riga i-esima (puntata dal puntatore
        // i-esimo)
        mat[i] = malloc(M * sizeof(int));
        fgets(riga, K, fp);
        token = strtok(riga, " ");
        for (j = 0; token != NULL; j++) {
            if (j >= M) {
                M *= 2;
                mat[i] = realloc(mat[i], M * sizeof(int));
                // qui va considerato che le righe devo essere tutte lunghe
                // uguali se no bisognerebbe fare una cosa più complicata.
                // Qui la realloc viene fatta solo riempiendo la prima riga.
            }
            sscanf(token, "%d", &mat[i][j]);
            token = strtok(NULL, " ");

            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
    n = i;
    m = j;
}