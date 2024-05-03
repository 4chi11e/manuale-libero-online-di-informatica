// creo una struttura che consiste in un vettore di interi (in C non esistono
// gli oggetti)

typedef struct {
    int *vals;
    int cap, n;
} Vettore;

Vettore creaVettore() {
    Vettore v;
    v.n = 0;
    v.cap = 8;
    v.vals = malloc(v.cap * sizeof(int));
    return v;
}

void push_back(Vettore v, int numero) {
    if (v.n >= v.cap) {
        v.cap *= 2;
        v.vals = realloc(v.vals, v.cap * 2);
    }
    v.vals[v.n] = numero;
    v.n += 1;
}

void pop_back(Vettore v) {
    if (v.n > 0) {
        v.n -= 1;
    }
}

// da finire
