// difficile ma interessante

// Leggi l'elenco di nomi dal file di input e inseriscili in un array
// dinamico. Inserisci poi i nomi in una lista di liste di nomi in cui in ogni
// riga ci sono nomi che iniziano con la stessa lettera. Ordina poi ogni riga in
// ordine alfabetico.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 20

int main() {
    FILE *fp;
    int i, j, N, n, p, matcap, matsize;
    char (*nomi)[M];
    char (**mat)[M];
    int *sizes, *caps;

    fp = fopen("2-02-lista-nomi-to-matrice-ordinata.txt", "r");
    if (fp == NULL) {
        printf("File non trovato\n");
        return 1;
    }

    N = 4;
    nomi = malloc(N * sizeof(char) * M);

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

    printf("Nomi letti:\n");
    for (i = 0; i < n; i++) {
        printf("- %s\n", nomi[i]);
    }

    // qsort(nomi, n, sizeof(char) * M, strcmp);
    // si lamenta un po (warnings) perchè strcmp non ha esattamente il formato
    // che vorrebbe ma funziona

    mat = malloc(1 * sizeof(char**));
    if (mat == NULL) {
        printf("Non riesco ad allocare abbastanza memoria!");
        return 1;
    }
    matcap = 1;
    matsize = 1;

    sizes = malloc(matcap * sizeof(int));
    caps = malloc(matcap * sizeof(int));
    for (i = 0; i < matcap; i++) {
        sizes[i] = 0;
        caps[i] = 0;
    }

    for (p = 0; p < n; p++) {
        i = 0;
        // printf("%d %s %s - ", sizes[i], nomi[p], mat[i][0]);
        while (sizes[i] != 0 && nomi[p][0] != mat[i][0][0]) {
            i++;
            if (i >= matcap) {
                mat = realloc(mat, matcap * 2 * sizeof(char**));
                if (mat == NULL) {
                    printf("Non riesco ad allocare abbastanza memoria!");
                    return 1;
                }
                matcap *= 2;
                sizes = realloc(sizes, matcap * sizeof(int));
                caps = realloc(caps, matcap * sizeof(int));
                for (j = matsize; j < matcap; j++) {
                    sizes[j] = 0;
                    caps[j] = 0;
                }
            }
            if (i >= matsize) {
                matsize++;
            }
        }
        // printf("matcap:%d matsize:%d - ", matcap, matsize);
        if (caps[i] == 0) {
            mat[i] = malloc(4 * sizeof(char) * M);
            if (mat[i] == NULL) {
                printf("Non riesco ad allocare abbastanza memoria!");
                return 1;
            }
            caps[i] = 4;
        }
        if (sizes[i] >= caps[i]) {
            mat[i] = realloc(mat[i], caps[i] * 2 * sizeof(char) * M);
            if (mat[i] == NULL) {
                printf("Non riesco ad allocare abbastanza memoria!");
                return 1;
            }
            caps[i] *= 2;
        }
        // printf("Scrivo %s in mat[%d][%d]\n", nomi[p], i, sizes[i]);
        strcpy(mat[i][sizes[i]], nomi[p]);
        sizes[i] += 1;
    }

    printf("\n\nStampa matrice:\n");
    for (i = 0; i < matsize; i++) {
        printf(" %c: ", mat[i][0][0]);
        for (j = 0; j < sizes[i]; j++) {
            printf("%s ", mat[i][j]);
        }
        printf("\n");
    }

    printf("\n\nRistampa matrice ordinata riga per riga:\n");
    for (i = 0; i < matsize; i++) {
        qsort(mat[i], sizes[i], sizeof(char)*M, strcmp);
        printf(" %c: ", mat[i][0][0]);
        for (j = 0; j < sizes[i]; j++) {
            printf("%s ", mat[i][j]);
        }
        printf("\n");
    }

    // per ordinare le righe fra loro il qsort non va bene perchè dovrei ordinare anche l'array sizes
    // per usarlo dovevo fare una struttura per ogni riga contenente sia l'array che la dimensione

}