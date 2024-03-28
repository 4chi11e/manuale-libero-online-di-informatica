#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 25
#define M 30

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
