// genera una sequenza di numeri casuali e salvali in memoria. La sequenza deve
// terminare quando la media dei numeri è 50 +- 0.01

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>

int main() {
    int num, *a, cap, n;
    float media, somma;

    srand(time(NULL));

    cap = 2;
    n = 0;
    a = malloc(cap * sizeof(int));
    if (a == NULL) {
        printf("Non riesco ad allocare abbastanza memoria!");
        return 1;
    }

    somma = 0;
    while (1) {
        num = rand() % 99 + 1;
        if (n >= cap) {
            cap *= 2;
            a = realloc(a, cap * sizeof(int));
            if (a == NULL) {
                printf("Non riesco ad allocare abbastanza memoria!");
                return 1;
            }
        }
        a[n++] = num;

        somma += num;
        media = somma / n;
        printf("%2d - %5.2f\n", a[n-1], media);
        if (media >= 49.99 && media <= 50.01) {
            break;
        }
    }
}