#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#define M 20
#define K 200

typedef struct {
    char cognome[M];
    float voti[M];
    float media;
    int nvoti;
} Studente;

int main() {
    FILE *fp;
    Studente *elenco;
    char riga[K];
    int ntoken;
    int i, j, n, N = 4;

    fp = fopen("1-11-voti3.txt", "r");
    if (fp == NULL) {
        printf("errore nell'apertura del file.\n");
        return 1;
    }

    elenco = malloc(N * sizeof(Studente));
    if (elenco == NULL) {
        printf("Errore nell'allocazione della memoria.\n");
        return 1;
    }

    for (i = 0; !feof(fp); i++) {
        fgets(riga, K, fp);

        if (i >= N) {
            N *= 2;
            elenco = realloc(elenco, N * sizeof(Studente));
            if (elenco == NULL) {
                printf("Errore nell'allocazione della memoria.\n");
                return 1;
            }
        }
        ntoken = sscanf(riga, "%[^:]: %f %f %f %f", elenco[i].cognome,
                       &elenco[i].voti[0], &elenco[i].voti[1],
                       &elenco[i].voti[2], &elenco[i].voti[3]);
        elenco[i].nvoti = ntoken-1;
    }
    n = i;
    fclose(fp);

    // calcolo della media
    for (i = 0; i < n; i++) {
        elenco[i].media = 0;
        for (j = 0; j < elenco[i].nvoti; j++) {
            elenco[i].media += elenco[i].voti[j];
        }
        elenco[i].media /= elenco[i].nvoti;
    }

    // stampo tutto con una funzione
    for (i = 0; i < n; i++) {
        printf("Studente: %12s - Media: %5.2f - Voti: ", elenco[i].cognome,
               elenco[i].media);
        for (j = 0; j < elenco[i].nvoti; j++) {
            printf("%3.1f ", elenco[i].voti[j]);
        }
        printf("\n");
    }

    // scrivo in un secondo file
    fp = fopen("1-11-voti3-out.txt", "w");
    if (fp == NULL) {
        printf("Apertura in scrittura del file fallita.\n");
        return 2;
    }
    for (i = 0; i < n; i++) {
        fprintf(fp, "%s: ", elenco[i].cognome);
        for (j = 0; j < elenco[i].nvoti; j++) {
            fprintf(fp, "%.2f ", elenco[i].voti[j]);
        }
        fprintf(fp, "- %.2f ", elenco[i].media);
        fprintf(fp, "\n");
    }
    fclose(fp);
}