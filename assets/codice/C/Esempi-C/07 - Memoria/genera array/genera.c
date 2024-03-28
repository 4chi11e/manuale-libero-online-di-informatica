// riempio un array di numeri casuali minori di 100, mi fermo quando estraggo 0
// (lo 0 non lo agguingo)

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main() {
    int i, n, cap = N, numero;
    int *a;

    srand(time(NULL));

    a = malloc(N*sizeof(int));

    for (i = 0; 1; i++) {
        numero = rand() % 100;
        // printf("%d ", numero);
        if (numero == 0) {
            break;
        }
        if (i >= cap) {
            a = realloc(a, cap * sizeof(int) * 2);
            cap *= 2;
        }
        a[i] = numero;
    }
    n = i;

    printf("\n");

    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}