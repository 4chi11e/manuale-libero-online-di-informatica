// Genera una matrice di numeri casuali di massimo due cifre. Anche la
// dimensione della matrice deve essere casuale: il numero di righe e di colonne
// deve essere compreso tra 2 e 10.
// Ordina poi separatamente ogni riga in ordine crescente.

// Leggi i numeri contenuti nel file di input e inseriscili in una matrice dinamica.
// Dai per scontato che ogni riga contenga la stessa quantità di numeri.

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main() {
    int i, j;
    int N, M;
    int **mat;

    srand(time(NULL));

    N = rand() % (10-2+1) + 2;
    M = rand() % (10-2+1) + 2;
    mat = malloc(N * sizeof(int*));
    if (mat == NULL) {
        printf("Memoria insufficiente.");
        return 1;
    }
    for (i = 0; i < N; i++) {
        mat[i] = malloc(M * sizeof(int));
        if (mat[i] == NULL) {
            printf("Memoria insufficiente.");
            return 1;
        }
        for (j = 0; j < M; j++) {
            mat[i][j] = rand() % 100;
        }
    }

    // stampo separatamente (potevo farlo prima)
    for (i = 0; i < N; i++) {
        qsort(mat[i], M, sizeof(int), cmpfunc);
        for (j = 0; j < M; j++) {
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }


}