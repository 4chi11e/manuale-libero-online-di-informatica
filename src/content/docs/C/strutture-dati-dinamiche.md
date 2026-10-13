---
title: Strutture dati dinamiche
description: Strutture dati la cui dimensione cambia durante l'esecuzione in C, il vector (array dinamico), le liste concatenate semplici e doppie, pile e code
---

Una **struttura dati dinamica** è una struttura la cui dimensione può **cambiare durante l'esecuzione** del programma. A differenza degli array normali (`int v[N]`), le strutture dinamiche:

*   possono crescere o ridursi, aggiungendo o togliendo elementi;
*   usano l'[allocazione dinamica della memoria](../allocazione-dinamica/);
*   sono gestite tramite [puntatori](../puntatori/).

Esempi di strutture dinamiche sono gli array dinamici (detti *vector*), le liste concatenate, le pile, le code, gli alberi e i grafi. Molti linguaggi di alto livello le mettono a disposizione già pronte: le liste di Python, ad esempio, sono array dinamici, e il C++ ha i tipi `vector`, `list`, `stack` e `queue`. Il C invece non è un linguaggio a oggetti e la sua libreria standard non contiene nessuna struttura dinamica: dobbiamo costruircele da soli, usando le funzioni per l'allocazione dinamica della memoria. È un ottimo esercizio per capire come funzionano "dietro le quinte" gli strumenti degli altri linguaggi.

In questa pagina vediamo le due strutture fondamentali, il **vector** e la **lista concatenata**, e come usarle per costruire **pile** e **code**.

## 1. Il vector (array dinamico)

Un **vector** è un array che cresce automaticamente quando si aggiungono elementi. Per realizzarlo servono un puntatore a un blocco di memoria allocato con `malloc` e due numeri:

*   la **dimensione** (*size*): il numero di elementi effettivamente contenuti;
*   la **capacità** (*capacity*): il numero di elementi per cui è stato allocato spazio.

Finché la dimensione è minore della capacità, aggiungere un elemento significa semplicemente scriverlo nella prima posizione libera. Quando il vector è pieno (dimensione uguale alla capacità), prima di aggiungere il nuovo elemento si alloca altra memoria con `realloc`. È lo stesso principio della [dimensione fisica e logica](../array/#dimensione-fisica-e-dimensione-logica) degli array, ma con una dimensione fisica che può crescere.

Conviene raggruppare il puntatore e i due numeri in una [struct](../struct/), e scrivere delle funzioni per le operazioni principali:

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dati;
    int size;
    int capacity;
} Vector;

// inizializza un vector vuoto; restituisce 1 se è andato tutto bene, 0 altrimenti
int vectorInit(Vector *v) {
    v->size = 0;
    v->capacity = 2;
    v->dati = malloc(v->capacity * sizeof(int));
    return v->dati != NULL;
}

// aggiunge un elemento in fondo; restituisce 1 se è andato tutto bene, 0 altrimenti
int vectorPushBack(Vector *v, int valore) {
    if (v->size == v->capacity) {
        int nuovaCapacity = v->capacity * 2;
        int *tmp = realloc(v->dati, nuovaCapacity * sizeof(int));
        if (tmp == NULL) {
            return 0;       // il vector resta com'era
        }
        v->dati = tmp;
        v->capacity = nuovaCapacity;
    }
    v->dati[v->size] = valore;
    v->size++;
    return 1;
}

// libera la memoria del vector
void vectorFree(Vector *v) {
    free(v->dati);
    v->dati = NULL;
    v->size = 0;
    v->capacity = 0;
}

int main() {
    Vector v;
    if (!vectorInit(&v)) {
        printf("Errore di allocazione\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        if (!vectorPushBack(&v, i * 10)) {
            printf("Errore di allocazione\n");
            vectorFree(&v);
            return 1;
        }
        printf("Aggiunto: %2d, size: %2d, capacity: %2d\n", i * 10, v.size, v.capacity);
    }

    for (int i = 0; i < v.size; i++) {
        printf("%d ", v.dati[i]);
    }
    printf("\n");

    vectorFree(&v);
    return 0;
}
```

```text
Aggiunto:  0, size:  1, capacity:  2
Aggiunto: 10, size:  2, capacity:  2
Aggiunto: 20, size:  3, capacity:  4
Aggiunto: 30, size:  4, capacity:  4
Aggiunto: 40, size:  5, capacity:  8
Aggiunto: 50, size:  6, capacity:  8
Aggiunto: 60, size:  7, capacity:  8
Aggiunto: 70, size:  8, capacity:  8
Aggiunto: 80, size:  9, capacity: 16
Aggiunto: 90, size: 10, capacity: 16
0 10 20 30 40 50 60 70 80 90
```

Osservazioni:

*   tutte le funzioni ricevono un **puntatore** al vector (`Vector *v`), perché devono modificarne i campi, e usano l'operatore freccia;
*   le funzioni restituiscono un valore che indica se l'operazione è riuscita, così il `main` può decidere cosa fare in caso di errore. In alternativa, in caso di errore si potrebbe terminare il programma direttamente dalla funzione con `exit(1)` (della libreria `stdlib.h`), che a differenza di `return` non esce solo dalla funzione ma da tutto il programma;
*   gli elementi si leggono direttamente con `v.dati[i]`, come in un normale array: l'accesso a una posizione qualsiasi è immediato.

:::note[Perché raddoppiare la capacità?]
Si potrebbe pensare di aumentare la capacità di un solo elemento alla volta, per non sprecare memoria. Ma ogni `realloc` può richiedere di copiare tutti gli elementi in un nuovo blocco, un'operazione lenta: inserendo un milione di elementi uno alla volta, si farebbero un milione di copie sempre più lunghe. **Raddoppiando** la capacità, invece, le riallocazioni sono pochissime (20 per arrivare a un milione di elementi) e in media l'inserimento in fondo resta un'operazione velocissima. È la strategia usata da quasi tutte le implementazioni reali, comprese le liste di Python e i `vector` del C++. Il prezzo da pagare è che, nel caso peggiore, metà della memoria allocata resta inutilizzata.
:::

### I limiti del vector
Il vector è velocissimo per leggere o modificare un elemento in una posizione qualsiasi e per aggiungere elementi **in fondo**. È invece lento per inserire o eliminare elementi **all'inizio o in mezzo**, perché, come visto nella pagina sugli [array](../array/#inserire-ed-eliminare-un-elemento), bisogna spostare di una posizione tutti gli elementi successivi:

```text
Inserire 3 in posizione 2:
    1  2  4  5          vector iniziale
    1  2  4  4  5       gli elementi dalla posizione 2 in poi si spostano a destra
    1  2  3  4  5       si scrive 3 nella posizione 2
```

Con un vector di un milione di elementi, inserire un valore in testa richiede un milione di spostamenti. Se queste operazioni sono frequenti, serve una struttura diversa: la lista concatenata.

## 2. La lista concatenata

In una **lista concatenata** (*linked list*) gli elementi non sono memorizzati uno di seguito all'altro, ma ognuno in un blocco di memoria allocato separatamente, detto **nodo**. Ogni nodo contiene il **valore** e un **puntatore al nodo successivo**: è come una caccia al tesoro, in cui ogni tappa contiene l'indicazione per raggiungere la successiva. Basta conoscere l'indirizzo del primo nodo, detto **testa** (*head*); l'ultimo nodo ha come successivo `NULL`, che segna la fine della lista.

```text
  testa
    |
    v
+---+---+     +---+---+     +---+---+
| 7 | --+---> | 3 | --+---> | 9 | / |      / = NULL
+---+---+     +---+---+     +---+---+
 dato next     dato next     dato next
```

Il grande vantaggio è che per inserire o eliminare un nodo **non bisogna spostare nulla**: basta modificare un paio di puntatori. Lo svantaggio è che per raggiungere l'elemento in posizione `i` bisogna partire dalla testa e seguire i puntatori uno alla volta: non c'è più l'accesso immediato `v[i]` degli array.

### Il nodo
Un nodo si definisce con una struct che contiene un puntatore a una struct **dello stesso tipo**:

```c
typedef struct Nodo {
    int dato;
    struct Nodo *next;
} Nodo;
```

Qui l'etichetta `struct Nodo` dopo `typedef struct` è indispensabile: all'interno della struct il nome `Nodo` definito dal `typedef` non esiste ancora (il compilatore lo incontra solo alla fine), quindi per dichiarare il puntatore `next` bisogna usare il nome `struct Nodo`. Una struct che contiene un puntatore al proprio tipo si dice **autoreferenziale**.

### Le operazioni fondamentali
Per comodità rappresentiamo la lista con una struct che contiene il puntatore alla testa e il numero di elementi:

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *next;
} Nodo;

typedef struct {
    Nodo *testa;
    int size;
} Lista;

// aggiunge un elemento all'inizio della lista; restituisce 0 in caso di errore
int pushFront(Lista *l, int valore) {
    Nodo *nuovo = malloc(sizeof(Nodo));
    if (nuovo == NULL) {
        return 0;
    }
    nuovo->dato = valore;
    nuovo->next = l->testa;     // il nuovo nodo punta alla vecchia testa...
    l->testa = nuovo;           // ...e diventa la nuova testa
    l->size++;
    return 1;
}

// aggiunge un elemento in fondo alla lista; restituisce 0 in caso di errore
int pushBack(Lista *l, int valore) {
    Nodo *nuovo = malloc(sizeof(Nodo));
    if (nuovo == NULL) {
        return 0;
    }
    nuovo->dato = valore;
    nuovo->next = NULL;         // sarà l'ultimo nodo

    if (l->testa == NULL) {     // lista vuota: il nuovo nodo è anche la testa
        l->testa = nuovo;
    } else {
        Nodo *p = l->testa;
        while (p->next != NULL) {   // cerca l'ultimo nodo
            p = p->next;
        }
        p->next = nuovo;
    }
    l->size++;
    return 1;
}

// stampa tutti gli elementi della lista
void stampa(const Lista *l) {
    for (Nodo *p = l->testa; p != NULL; p = p->next) {
        printf("%d ", p->dato);
    }
    printf("\n");
}

// elimina il primo nodo che contiene valore; restituisce 1 se l'ha trovato, 0 altrimenti
int rimuovi(Lista *l, int valore) {
    Nodo *prec = NULL;
    Nodo *p = l->testa;
    while (p != NULL && p->dato != valore) {
        prec = p;
        p = p->next;
    }
    if (p == NULL) {
        return 0;               // valore non trovato
    }
    if (prec == NULL) {
        l->testa = p->next;     // si elimina la testa
    } else {
        prec->next = p->next;   // il precedente "scavalca" il nodo da eliminare
    }
    free(p);
    l->size--;
    return 1;
}

// libera tutti i nodi della lista
void liberaLista(Lista *l) {
    Nodo *p = l->testa;
    while (p != NULL) {
        Nodo *daLiberare = p;
        p = p->next;            // ci si sposta PRIMA di liberare il nodo
        free(daLiberare);
    }
    l->testa = NULL;
    l->size = 0;
}

int main() {
    Lista l = {NULL, 0};        // lista vuota

    pushBack(&l, 3);
    pushBack(&l, 9);
    pushFront(&l, 7);
    stampa(&l);                 // 7 3 9

    rimuovi(&l, 3);
    stampa(&l);                 // 7 9

    printf("Elementi: %d\n", l.size);
    liberaLista(&l);
    return 0;
}
```

Analizziamo le operazioni principali:

*   **Scorrere la lista**: si usa un puntatore `p` che parte dalla testa e a ogni passo si sposta sul nodo successivo con `p = p->next`, finché non diventa `NULL`. È l'equivalente del `for` con l'indice per gli array, e si ritrova in quasi tutte le funzioni.
*   **Inserire in testa** (`pushFront`): si crea il nuovo nodo, lo si fa puntare alla testa attuale e lo si fa diventare la nuova testa. Sono due assegnamenti, qualunque sia la lunghezza della lista. L'ordine è importante: se si aggiornasse prima la testa, si perderebbe l'indirizzo del vecchio primo nodo.
*   **Inserire in fondo** (`pushBack`): bisogna prima scorrere tutta la lista per trovare l'ultimo nodo. Va trattato a parte il caso della lista vuota, in cui non esiste un ultimo nodo e il nuovo nodo diventa la testa.
*   **Eliminare un nodo** (`rimuovi`): mentre si cerca il nodo da eliminare, si tiene traccia anche del nodo **precedente**, perché è il suo puntatore `next` che va modificato per "scavalcare" il nodo eliminato. Anche qui va trattato a parte il caso in cui il nodo da eliminare è la testa. Infine il nodo eliminato va liberato con `free`.
*   **Liberare la lista**: ogni nodo è stato allocato con una `malloc`, quindi ogni nodo va liberato con una `free`. Bisogna salvare il puntatore al nodo successivo **prima** di liberare il nodo corrente: dopo la `free`, `p->next` non si può più leggere.

```text
Eliminazione del nodo che contiene 3:

prima:   testa --> [7] --> [3] --> [9] --> NULL
                   prec     p

dopo:    testa --> [7] -------------> [9] --> NULL      prec->next = p->next;
                            [3]                         free(p);
```

### La lista doppiamente concatenata
Nella lista vista finora ogni nodo conosce solo il successivo: si può scorrere solo in avanti, e per inserire in fondo bisogna attraversarla tutta. Nella **lista doppiamente concatenata** (*double linked list*) ogni nodo ha **due** puntatori, uno al successivo e uno al **precedente**, e la lista memorizza sia il primo nodo (la testa) sia l'ultimo (la **coda**, in inglese *tail*):

```text
  head                                    tail
    |                                       |
    v                                       v
+---+---+---+     +---+---+---+     +---+---+---+
| / | 7 | --+---> |   | 3 | --+---> |   | 9 | / |
|   |   |   | <---+-- |   |   | <---+-- |   |   |
+---+---+---+     +---+---+---+     +---+---+---+
 prev dato next
```

```c
typedef struct Nodo2 {
    int dato;
    struct Nodo2 *next;
    struct Nodo2 *prev;
} Nodo2;

typedef struct {
    Nodo2 *head;
    Nodo2 *tail;
    int size;
} ListaDoppia;
```

In questo modo:

*   si può inserire o eliminare **sia in testa sia in coda** con pochi assegnamenti, senza scorrere la lista;
*   la lista si può scorrere **in entrambe le direzioni**;
*   dato un nodo, lo si può eliminare senza dover cercare il precedente, perché lo si conosce già tramite `prev`.

Il prezzo da pagare è un puntatore in più per ogni nodo e funzioni un po' più complicate, perché a ogni modifica bisogna aggiornare correttamente entrambi i puntatori dei nodi vicini e, quando serve, `head` e `tail`. Ecco ad esempio l'inserimento in coda e l'eliminazione di un nodo:

```c
// aggiunge un elemento in coda; restituisce 0 in caso di errore
int pushBack2(ListaDoppia *l, int valore) {
    Nodo2 *nuovo = malloc(sizeof(Nodo2));
    if (nuovo == NULL) {
        return 0;
    }
    nuovo->dato = valore;
    nuovo->next = NULL;
    nuovo->prev = l->tail;

    if (l->tail != NULL) {
        l->tail->next = nuovo;  // il vecchio ultimo nodo punta al nuovo
    } else {
        l->head = nuovo;        // lista vuota: il nuovo nodo è anche il primo
    }
    l->tail = nuovo;
    l->size++;
    return 1;
}

// elimina dalla lista il nodo indicato
void eliminaNodo(ListaDoppia *l, Nodo2 *nodo) {
    if (nodo->prev != NULL) {
        nodo->prev->next = nodo->next;
    } else {
        l->head = nodo->next;   // era il primo nodo
    }
    if (nodo->next != NULL) {
        nodo->next->prev = nodo->prev;
    } else {
        l->tail = nodo->prev;   // era l'ultimo nodo
    }
    free(nodo);                 // fondamentale: altrimenti la memoria del nodo va persa
    l->size--;
}
```

Un'implementazione completa, con inserimento in una posizione qualsiasi, è disponibile nel capitolo sull'allocazione dinamica dell'eserciziario.

:::caution[La `free` dei nodi eliminati]
Con le strutture dinamiche dimenticare la `free` è particolarmente pericoloso. Un programma che aggiunge e rimuove continuamente elementi da una lista (pensate a un server che gestisce le richieste in arrivo) senza liberare i nodi eliminati continua ad accumulare memoria inutilizzata e prima o poi la esaurisce. Qui non basta "aspettare la fine del programma": la memoria va liberata appena un nodo non serve più. Potete provarlo voi stessi: commentate la `free` in `eliminaNodo` e fate inserire ed eliminare qualche milione di nodi in un ciclo, osservando la memoria occupata dal programma nel Task Manager.
:::

## 3. Vector o lista?

Nessuna delle due strutture è migliore in assoluto: la scelta dipende dalle operazioni che il programma deve fare più spesso. Nella tabella, O(1) indica un'operazione che richiede un tempo costante, indipendente dal numero n di elementi, mentre O(n) indica un tempo proporzionale al numero di elementi (vedi la pagina sulla [complessità computazionale](../../complessita/)).

| Operazione | Vector | Lista doppiamente concatenata |
|---|---|---|
| Accesso all'elemento in posizione `i` | O(1) | O(n): bisogna scorrere la lista |
| Inserimento / eliminazione in fondo | O(1) in media | O(1) |
| Inserimento / eliminazione in testa | O(n): bisogna spostare tutto | O(1) |
| Inserimento / eliminazione in mezzo (avendo già il nodo) | O(n) | O(1) |
| Ricerca di un valore | O(n), O(log n) se ordinato con la [ricerca binaria](../array/#ricerca-binaria-dicotomica) | O(n) |
| Memoria occupata | solo i dati (più lo spazio libero in fondo) | i dati più due puntatori per ogni nodo |

In pratica il vector è la scelta più comune, perché l'accesso diretto agli elementi è utilissimo e, avendo gli elementi contigui in memoria, è anche molto veloce da scorrere. La lista è preferibile quando gli inserimenti e le eliminazioni in testa o in mezzo sono molto frequenti.

## 4. Pile e code

Le **pile** e le **code** sono strutture dati che non permettono di accedere a qualsiasi elemento, ma solo di inserire ed estrarre elementi secondo una regola precisa. Si possono realizzare facilmente sia con un vector sia con una lista.

### La pila (stack)
In una **pila** l'ultimo elemento inserito è il primo a essere estratto: si dice che è una struttura **LIFO** (*Last In, First Out*). È proprio come una pila di piatti: si appoggia un piatto in cima e si prende sempre il piatto in cima. Le operazioni fondamentali sono:

*   **push**: inserisce un elemento in cima alla pila;
*   **pop**: estrae l'elemento in cima alla pila.

Con una lista concatenata, la cima della pila è la testa: `push` è il `pushFront` visto sopra, e `pop` restituisce il valore della testa e la elimina. Con un vector, la cima è l'ultimo elemento: si inserisce e si estrae in fondo.

Le pile sono ovunque in informatica: la funzione "annulla" (*undo*) degli editor tiene le ultime modifiche in una pila, i browser fanno lo stesso con le pagine visitate per il tasto "indietro", e lo stesso [stack](../allocazione-dinamica/#1-stack-e-heap) che contiene le chiamate di funzione è una pila (ed ecco perché l'ultima funzione chiamata è la prima a terminare, come si vede bene nella [ricorsione](../funzioni/#8-la-ricorsione)).

### La coda (queue)
In una **coda** il primo elemento inserito è il primo a essere estratto: è una struttura **FIFO** (*First In, First Out*), come la fila alla cassa del supermercato. Le operazioni fondamentali sono:

*   **enqueue**: inserisce un elemento in fondo alla coda;
*   **dequeue**: estrae l'elemento all'inizio della coda.

Con una lista doppiamente concatenata (o con una lista semplice che memorizza anche l'ultimo nodo) entrambe le operazioni sono immediate: si inserisce in coda e si estrae dalla testa. Le code si usano ogni volta che delle richieste devono essere servite nell'ordine di arrivo: i documenti inviati a una stampante, i processi in attesa della CPU in un [sistema operativo](../../sistemi-operativi/), i pacchetti in attesa di essere trasmessi in una rete.

## 5. Errori comuni

| Errore | Conseguenza |
|---|---|
| Nodo definito con `typedef struct { ...; Nodo *next; } Nodo;` | Errore di compilazione: dentro la struct serve `struct Nodo *next` con l'etichetta |
| Lista non inizializzata (testa con valore casuale invece di `NULL`) | Crash al primo scorrimento |
| Inserimento in testa aggiornando prima la testa e poi `next` | Si perde il resto della lista |
| Caso della lista vuota non gestito in `pushBack` o nell'eliminazione | Dereferenziazione di `NULL` e crash |
| Eliminazione della testa non gestita a parte | La testa punta a un nodo liberato |
| `free(p)` e poi `p = p->next` nel ciclo che libera la lista | Uso di memoria già liberata |
| Nodi eliminati senza `free` | Memory leak |
| Lista doppia: aggiornato `next` ma non `prev` (o viceversa), o dimenticati `head` e `tail` | Lista incoerente: lo scorrimento in un verso funziona e nell'altro no |
| Vector: `realloc` senza puntatore temporaneo | Perdita dei dati se la riallocazione fallisce |
| Vector: capacità aumentata di uno alla volta | Programma molto lento con tanti elementi |

## Esercizi

Gli esercizi relativi a questi argomenti si trovano nel capitolo **"Allocazione dinamica della memoria"** dell'eserciziario, linkato nella [pagina introduttiva](../programmazione-in-c/). Un buon esercizio è anche riscrivere gli esercizi sui file memorizzando i dati letti in un vector o in una lista.
