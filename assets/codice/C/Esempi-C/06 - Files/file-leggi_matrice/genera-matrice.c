#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 6
#define M 10

int main() {
    FILE *fp;
    int i, j;

    srand(time(NULL));

    fp = fopen("matrice.txt", "w");

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            fprintf(fp, "%3d", rand() % 100);
        }
        if (i < N-1) {
            fprintf(fp, "\n");
        }
    }

    fclose(fp);
}
