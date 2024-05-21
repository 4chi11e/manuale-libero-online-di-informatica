#include <stdio.h>
#include <malloc.h>

typedef struct {
    int *data;
    int n, cap;
} VettoreInt;

int inizializza(VettoreInt *v) {
    v->n = 0; //(*v).
    v->cap = 0;
    v->data = malloc(sizeof(int) * 4);
    if(v->data == NULL){
        printf("Memoria esaurita\n");
        return 1;
    }
    v->cap = 4;
    return 0;
}

int push_back(VettoreInt *v, int dato) {
    if (v->n >= v->cap) {
        v->data = realloc(v->data, sizeof(int) * v->cap * 2);
        if(v->data == NULL){
            printf("Memoria esaurita\n");
            return 1;
        }
        v->cap *= 2;
    }
    v->data[v->n++] = dato;
    // che equivale a:
    // v->data[v->n] = dato;
    // n += 1;

    // printf("%d", v->n);
    return 0;
}

int pop(VettoreInt *v, int pos) {
    int i;
    if (pos < 0 || pos >= v->n) {
        printf("Posizione indicata per il pop non esistente\n");
        return 1;
    }
    for (i = pos; i < v->n-1; i++) {
        v->data[i] = v->data[i+1];
    }
    v->n--;
    return 0;
} 

int pop_back(VettoreInt *v) {
    if (v->n <= 0) {
        printf("Il vettore è vuoto!\n");
        return 1;
    }
    v->n--;
    return 0;
}

void libera(VettoreInt *v) {
    free(v->data);
}

void svuota(VettoreInt *v) {
    v->n = 0;
}