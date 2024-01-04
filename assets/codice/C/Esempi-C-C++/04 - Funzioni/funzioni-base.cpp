#include <stdio.h>

// funzione somma che riceve due interi a, b e restituisce un intero. questi
// interi a, b non sono gli stessi del main, la funzione ha uno spazio di
// memoria separato.
int somma(int a, int b) {  //
    int risultato = a + b;
    a = 6;  // nota che questa modifica non modifica la a del main perchè sono
            // due variabili diverse
    return risultato;
    // il comando return interrompe l'esecuzione della funzione e restituisce al
    // massimo un valore. Per restituire più di un valore è necessario ricorrere
    // a metodi più complessi
}

void stampaArray(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return;  // in una funzione void non è obbligatorio ma può essere usato per
             // terminare immediatamente l'esecuzione della funzione
    printf("Non verrò mai stampato\n");
}

void bubbleSort(int v[], int N) {
    int i, j, scambiato, tmp;

    scambiato = 1;
    for (i = 0; i < N - 1 && scambiato; i++) {
        scambiato = 0;
        for (j = 0; j < N - 1 - i; j++) {
            if (v[j] > v[j + 1]) {  // così ordina in ordine crescente, se si
                                    // cambia > con < si ottiene decrescente
                tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
                scambiato = 1;
            }
        }
    }
}

int main() {
    int a = 5, y = 6;
    printf("%d + %d = %d\n\n", a, y, somma(a, y));

    int n = 5, v[] = {5, 1, 3, 2, 4};

    stampaArray(v, n);
    printf("\n");
    bubbleSort(v, n);
    // gli array non sono variabili normali, in realtà sono puntatori al primo
    // elemento dell'array quindi la funzione bubbleSort è in grado di
    // modificare i valori contenuti in v
    stampaArray(v, n);
    printf("\n\n");
}