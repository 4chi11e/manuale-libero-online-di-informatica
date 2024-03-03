#include <stdio.h>
#include <string.h>

#define N 100
#define M 100

int main() {
    FILE *fp;
    int i, j, n, m;
    int mat[N][M];
    char riga[N*3];
    char *token;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("File non trovato\n");
        return 1;
    }

    for (i = 0; !feof(fp); i++) {
        fgets(riga, N*3, fp);
        token = strtok(riga, " ");
        for (j = 0; token != NULL; j++) {
            sscanf(token, "%d", &mat[i][j]);
            token = strtok(NULL, " ");

            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
    n = i;
    m = j;
}