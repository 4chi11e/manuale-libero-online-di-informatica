// in questo esempio leggo una matrice dando per scontato che ogni riga contiene
// la stessa quantità di numeri

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("File non trovato\n");
        return 1;
    }

    N = 2;
    M = 2;
    mat = malloc(N*sizeof(int*));
    n = 0;
    m = 0;
    for (i = 0; !feof(fp); i++) {
        if (i >= N) {
            N *= 2;
            mat = realloc(mat, N*sizeof(int*));
        }
        mat[i] = malloc(M*sizeof(int));
        fgets(riga, K, fp);
        token = strtok(riga, " ");
        for (j = 0; token != NULL; j++) {
            if (j >= M) {
                M *= 2;
                mat[i] = realloc(mat[i], M*sizeof(int));
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