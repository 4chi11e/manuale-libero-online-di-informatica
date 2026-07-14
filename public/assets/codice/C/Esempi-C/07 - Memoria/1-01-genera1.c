// riempio un array di numeri casuali minori di 100, mi fermo quando estraggo 0
// (lo 0 non lo agguingo)

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, n, cap, numero;
    int *a; // invece di a[]

    srand(time(NULL));

    // qui alloco la memoria per a
    cap = 10;
    a = malloc(cap * sizeof(int));
    // questo mi serve per controllare se il computer riesce ad allocare
    // memoria, se non ci riesce blocco tutto
    if (a == NULL) {
        printf("Non riesco ad allocare abbastanza memoria!");
        return 1;
    }

    // conto quanti numeri estraggo e vado avanti per sempre (poi userò un break
    // quando estraggo 0)
    for (i = 0; 1; i++) {

        // estraggo un numero
        numero = rand() % 100;
        // printf("%d ", numero);

        // se è 0 esco
        if (numero == 0) {
            break;
        }

        // qui mi chiedo se ho già riempito tutto a e non ho più spazio,
        // in tal caso devo ingrandire a
        if (i >= cap) {
            a = realloc(a, cap * sizeof(int) * 2);
            if (a == NULL) {
                printf("Non riesco ad allocare abbastanza memoria!");
                return 1;
            }
            cap *= 2;
        }

        // finalmente posso aggungere numero ad a
        a[i] = numero;
    }
    // mi devo segnare quanti numeri ho estratto
    n = i;

    printf("\n");

    // ora stampo tutto a
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    free(a);
}