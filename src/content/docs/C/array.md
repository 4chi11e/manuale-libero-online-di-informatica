---
title: Array
description: Dichiarazione e uso degli array in C, indici, scorrimento con il for, algoritmi classici di ricerca e gli ordinamenti selection sort e bubble sort
---

Le variabili viste finora contengono un solo valore. In moltissimi casi però i programmi non lavorano su singoli valori ma su **sequenze** di valori: i voti di uno studente, le temperature di un mese, i punteggi di una partita. Sarebbe assurdo dichiarare cento variabili `voto1`, `voto2`, ..., `voto100`! Per questo tutti i linguaggi di programmazione prevedono una struttura dati apposita, che in C si chiama **array** (in italiano si usa a volte anche *vettore*).

Un **array** è una sequenza di valori **tutti dello stesso tipo**, memorizzati in memoria **uno di seguito all'altro**, a cui si accede tramite un unico nome e un **indice** che indica la posizione dell'elemento.

```text
indice:    0    1    2    3    4
         +----+----+----+----+----+
    v:   | 12 |  7 | 31 |  4 | 18 |
         +----+----+----+----+----+
```

## 1. Dichiarare un array

Un array si dichiara indicando il tipo degli elementi, il nome e, tra parentesi quadre, il **numero di elementi**:

```c
int voti[10];        // array di 10 interi
double temp[31];     // array di 31 double
```

### Usare una costante per la dimensione
Di solito non conviene scrivere la dimensione direttamente come numero: mentre si scrive un programma capita spesso di doverla modificare, e la dimensione compare in molti punti del codice (nella dichiarazione, in tutti i cicli che scorrono l'array...). È molto meglio definirla **una volta sola** con una costante:

```c
#define N 10

int main() {
    int v[N];
    for (int i = 0; i < N; i++) {
        // ...
    }
    return 0;
}
```

Così per passare da 10 a 1000 elementi basta modificare una sola riga.

:::note[E se la dimensione la decide l'utente?]
Dallo standard C99 è possibile dichiarare un array la cui dimensione è contenuta in una variabile, ad esempio `int v[n];` dopo aver letto `n` da tastiera (si chiama *variable length array*, VLA). Questa possibilità però ha diversi limiti: un VLA non può essere inizializzato con le graffe, alcuni compilatori (ad esempio quello di Microsoft) non la supportano e, se `n` è molto grande, il programma va in crash senza alcun avviso. Per questi motivi in questo corso useremo sempre dimensioni costanti, dichiarando un array "abbastanza grande" e usandone solo una parte (vedi più sotto la [dimensione logica](#dimensione-fisica-e-dimensione-logica)). Il modo corretto di creare array di dimensione decisa durante l'esecuzione è l'[allocazione dinamica della memoria](../allocazione-dinamica/).
:::

### Inizializzare un array
Come per le variabili, un array appena dichiarato contiene valori casuali (la "robaccia" rimasta in memoria). Si possono però assegnare subito i valori elencandoli tra parentesi graffe:

```c
int a[5] = {1, 7, 4, 6, 3};    // array completamente inizializzato
int b[] = {1, 7, 4, 6, 3};     // la dimensione (5) viene calcolata dal compilatore
int c[10] = {1, 7, 4};         // i primi 3 elementi sono 1, 7, 4, gli altri 7 valgono 0
int d[N] = {0};                // tutti gli elementi valgono 0
```

L'ultimo caso è un trucco molto usato per **azzerare** un array: basta indicare esplicitamente il primo elemento, e tutti quelli non indicati vengono messi a 0.

:::caution[Le graffe valgono solo nella dichiarazione]
Assegnare più valori insieme con le graffe è possibile **solo** nel momento della dichiarazione. Dopo, gli elementi si possono leggere e modificare solo **uno alla volta**:

```c
int v[5];
v = {1, 2, 3, 4, 5};    // ERRORE di compilazione
```
:::

### Calcolare il numero di elementi con `sizeof`
Quando la dimensione viene calcolata dal compilatore (come per l'array `b` sopra), si può ricavare il numero di elementi con l'operatore `sizeof`, che restituisce il numero di byte occupati:

```c
int b[] = {1, 7, 4, 6, 3};
int n = sizeof(b) / sizeof(b[0]);   // byte totali / byte di un elemento = 5
```

Questo sistema è comodo quando si modifica a mano il contenuto dell'array: aggiungendo o togliendo valori tra le graffe, `n` si aggiorna da solo e non si rischia di dimenticarsene. Attenzione però: funziona solo nella funzione in cui l'array è dichiarato, non quando l'array viene passato a un'altra funzione (vedremo il motivo nella pagina sui [puntatori](../puntatori/#5-array-come-parametri)).

## 2. Accedere agli elementi

Ogni elemento si indica con il nome dell'array seguito dall'**indice** tra parentesi quadre. Un elemento di un array si usa esattamente come una normale variabile:

```c
int v[5];
v[0] = 12;              // il PRIMO elemento ha indice 0
v[1] = 7;
v[4] = 18;              // l'ULTIMO elemento ha indice 4, cioè N-1
v[2] = v[0] + v[1];     // v[2] vale 19
v[1]++;                 // v[1] vale 8
printf("%d\n", v[2]);
```

:::note[Perché si parte da 0?]
Per chi inizia a programmare sarebbe più naturale che il primo elemento fosse in posizione 1. Il motivo per cui si parte da 0 è tecnico: il computer trova un elemento partendo dall'indirizzo in memoria del primo elemento e spostandosi in avanti di un certo numero di posizioni. L'indice indica proprio di quante posizioni spostarsi (lo **scostamento** o *offset*): il primo elemento ha scostamento 0, il secondo 1, e così via fino all'ultimo, che ha scostamento **N-1**. Quasi tutti i linguaggi di programmazione seguono questa regola.
:::

L'indice può essere qualsiasi espressione intera: una costante, una variabile o un calcolo (`v[i]`, `v[i + 1]`, `v[N - 1 - i]`). È proprio questo che rende gli array così potenti, insieme ai cicli.

:::danger[Uscire dai limiti dell'array]
Il C **non controlla** che l'indice sia valido. Se si scrive `v[5]` o `v[-1]` in un array di 5 elementi, il programma accede alla zona di memoria vicina all'array, che appartiene ad altre variabili o addirittura ad altri programmi. Il risultato può essere un valore senza senso, la modifica silenziosa di un'altra variabile o il crash del programma (spesso con il messaggio *segmentation fault*).

L'errore più comune è il ciclo `for (i = 0; i <= N; i++)`, che all'ultima iterazione accede a `v[N]`, un elemento che non esiste. La condizione corretta è `i < N`.
:::

## 3. Scorrere un array con il `for`

Quando bisogna fare qualcosa su tutti gli elementi di un array (o su una parte di essi) si usa un ciclo `for`, facendo scorrere un indice dalla prima posizione (0) all'ultima (N-1):

```c
for (int i = 0; i < N; i++) {      // la prima posizione è 0, l'ultima N-1
    printf("%d ", v[i]);
}
printf("\n");
```

Per scorrere l'array al contrario, l'indice parte dall'ultima posizione e scende fino a 0:

```c
for (int i = N - 1; i >= 0; i--) {
    printf("%d ", v[i]);
}
```

Un metodo alternativo, utile per capire il meccanismo, è far scorrere l'indice normalmente e calcolare la posizione "speculare" con `N - 1 - i`: quando `i` vale 0 si stampa l'ultimo elemento, quando vale 1 il penultimo, e così via.

```c
for (int i = 0; i < N; i++) {
    printf("%d ", v[N - 1 - i]);
}
```

Per stampare solo una porzione dell'array, ad esempio dalla posizione `da` alla posizione `a` comprese:

```c
for (int i = da; i <= a; i++) {
    printf("%d ", v[i]);
}
```

### Una stampa più elegante
Spesso si vuole stampare l'array in un formato come `{12, 7, 31, 4, 18}`, con gli elementi separati da una virgola. Il problema è che dopo l'ultimo elemento la virgola non va messa: la soluzione più semplice (assumendo che l'array contenga almeno un elemento, cioè $n \ge 1$) è stampare tutti gli elementi tranne l'ultimo nel ciclo, e l'ultimo a parte.

```c
printf("{");
for (int i = 0; i < n - 1; i++) {
    printf("%d, ", v[i]);
}
printf("%d}\n", v[n - 1]);
```

## 4. Riempire un array

### Da tastiera
```c
for (int i = 0; i < N; i++) {
    printf("Inserisci il numero %d: ", i + 1);
    scanf("%d", &v[i]);
}
```

Notate due dettagli: in `scanf` la `&` va messa davanti all'elemento (`&v[i]`), e nel messaggio si stampa `i + 1` perché per l'utente il primo numero è il numero 1, non il numero 0.

### Con numeri casuali
Usando la formula vista negli [elementi di base](../elementi-di-base/#numeri-casuali-in-un-intervallo):

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main() {
    int v[N];
    int min = 1, max = 100;

    srand(time(NULL));              // una sola volta, all'inizio del main

    for (int i = 0; i < N; i++) {
        v[i] = rand() % (max - min + 1) + min;
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
```

### Dimensione fisica e dimensione logica
Spesso non si sa in anticipo quanti elementi serviranno: ad esempio si chiede all'utente quanti numeri vuole inserire. Visto che la dimensione dell'array deve essere costante, si dichiara un array **abbastanza grande** e se ne usa solo una parte. Bisogna allora distinguere tra:

*   la **dimensione fisica** `N`: il numero di elementi per cui è stata riservata memoria;
*   la **dimensione logica** `n`: il numero di elementi effettivamente usati, che deve essere sempre minore o uguale a `N`.

```c
#include <stdio.h>

#define N 100

int main() {
    int v[N];
    int n;

    do {
        printf("Quanti numeri vuoi inserire (max %d)? ", N);
        scanf("%d", &n);
    } while (n < 1 || n > N);       // controllo: n non deve superare N

    for (int i = 0; i < n; i++) {   // da qui in poi si usa n, non N
        printf("Numero %d: ", i + 1);
        scanf("%d", &v[i]);
    }
    // ...
    return 0;
}
```

Gli elementi da `v[n]` a `v[N-1]` esistono, ma non vanno considerati: contengono valori casuali.

## 5. Algoritmi classici con gli array

Ci sono alcune operazioni che si ripetono continuamente quando si lavora con gli array. Negli esempi che seguono `v` è un array di `n` interi.

### Copiare un array
Gli array **non si possono copiare** con l'operatore `=` (`copia = v;` dà errore di compilazione): bisogna copiare un elemento alla volta.

```c
for (int i = 0; i < n; i++) {
    copia[i] = v[i];
}
```

Naturalmente `copia` deve avere una dimensione sufficiente. In alternativa si può usare la funzione `memcpy` della libreria `string.h` (*memory copy*), che copia un certo numero di byte da una zona di memoria a un'altra:

```c
memcpy(copia, v, n * sizeof(int));   // copia n interi da v a copia
```

Per lo stesso motivo due array non si possono confrontare con `==`: bisogna confrontarli elemento per elemento.

### Somma e media
```c
int somma = 0;
for (int i = 0; i < n; i++) {
    somma += v[i];
}
double media = (double)somma / n;
printf("La media vale %.2f\n", media);
```

Ricordate che la media deve essere calcolata con una divisione **non intera**, altrimenti il risultato viene troncato.

### Massimo e minimo
Come visto nelle [strutture di controllo](../strutture-di-controllo/#massimo-e-minimo), si assume che il massimo sia il primo elemento e lo si confronta con tutti gli altri a partire dalla posizione 1. Con gli array è spesso utile ricordare anche la **posizione** del massimo:

```c
int max = v[0], posMax = 0;
for (int i = 1; i < n; i++) {
    if (v[i] > max) {
        max = v[i];
        posMax = i;
    }
}
printf("Il massimo e' %d e si trova in posizione %d\n", max, posMax);
```

In realtà basterebbe ricordare solo la posizione, perché il valore è sempre `v[posMax]`.

### Ricerca di un elemento
Per sapere se un valore è presente nell'array si usa una variabile flag. La condizione `&& !trovato` nel `for` interrompe la ricerca appena il valore viene trovato:

```c
int daCercare = 5;
int trovato = 0;
for (int i = 0; i < n && !trovato; i++) {
    if (v[i] == daCercare) {
        trovato = 1;
    }
}
if (trovato) {
    printf("%d e' presente\n", daCercare);
} else {
    printf("%d non e' presente\n", daCercare);
}
```

Se serve anche la **posizione** della prima occorrenza, la variabile flag si può sostituire con la posizione stessa, inizializzata a **-1**: visto che -1 non è un indice valido, significa "non ancora trovato". È un trucco usato in moltissimi contesti.

```c
int pos = -1;
for (int i = 0; i < n && pos == -1; i++) {
    if (v[i] == daCercare) {
        pos = i;
    }
}
if (pos != -1) {
    printf("%d si trova in posizione %d\n", daCercare, pos);
} else {
    printf("%d non e' presente\n", daCercare);
}
```

Senza la condizione `&& pos == -1` il ciclo proseguirebbe fino alla fine, e alla fine `pos` conterrebbe l'**ultima** occorrenza invece della prima.

Per contare **quante volte** un valore compare, invece, bisogna per forza scorrere tutto l'array con un contatore:

```c
int occorrenze = 0;
for (int i = 0; i < n; i++) {
    if (v[i] == daCercare) {
        occorrenze++;
    }
}
```

### Scambiare due elementi e invertire l'array
Per scambiare il contenuto di due variabili serve una **variabile di appoggio**: se si scrivesse direttamente `a = b; b = a;`, il valore originale di `a` andrebbe perso. È come scambiare il contenuto di due bicchieri: serve un terzo bicchiere vuoto.

```c
int tmp = v[i];
v[i] = v[j];
v[j] = tmp;
```

Per invertire un array si scambia il primo elemento con l'ultimo, il secondo con il penultimo e così via, **fermandosi a metà** (altrimenti la seconda metà degli scambi rimetterebbe tutto com'era):

```c
for (int i = 0; i < n / 2; i++) {
    int tmp = v[i];
    v[i] = v[n - 1 - i];
    v[n - 1 - i] = tmp;
}
```

### Inserire ed eliminare un elemento
Per eliminare l'elemento in posizione `pos` bisogna spostare di un posto verso sinistra tutti gli elementi successivi, e poi diminuire la dimensione logica:

```c
for (int i = pos; i < n - 1; i++) {
    v[i] = v[i + 1];
}
n--;
```

Per inserire un valore in posizione `pos`, al contrario, si spostano di un posto verso destra gli elementi da `pos` in poi, **partendo dal fondo** (altrimenti ogni elemento sovrascriverebbe il successivo prima che venga spostato), e si aumenta la dimensione logica. Bisogna naturalmente controllare che ci sia spazio, cioè che `n < N`.

```c
for (int i = n; i > pos; i--) {
    v[i] = v[i - 1];
}
v[pos] = valore;
n++;
```

### Cercare una sequenza dentro un array
Un esempio più complesso: cercare la prima posizione in cui l'array `vx` (di `nx` elementi) compare all'interno dell'array `vy` (di `ny` elementi). Per ogni possibile posizione di partenza `i` in `vy`, si confrontano gli elementi di `vx` uno alla volta finché sono uguali:

```c
int pos = -1;
for (int i = 0; i <= ny - nx && pos == -1; i++) {
    int j = 0;
    while (j < nx && vx[j] == vy[i + j]) {
        j++;
    }
    if (j == nx) {          // tutti gli elementi di vx coincidono
        pos = i;
    }
}
```

Il ciclo esterno si ferma a `ny - nx` perché oltre quella posizione `vx` non ci starebbe più per intero (e `vy[i + j]` uscirebbe dall'array). Se il ciclo interno arriva fino a `j == nx`, significa che tutti gli elementi coincidono. È l'esempio più complicato visto finora: simulatelo a mano su un caso semplice per capirlo bene.

## 6. Ordinare un array

Ordinare una sequenza di valori (in ordine crescente o decrescente) è uno dei problemi più studiati dell'informatica, perché su dati ordinati moltissime operazioni diventano molto più veloci (pensate a cercare una parola in un dizionario). Esistono decine di algoritmi di ordinamento; qui vediamo i due più semplici.

### Selection sort (ordinamento per selezione)
L'idea: si cerca il **minimo** di tutto l'array e lo si scambia con il primo elemento. Poi si cerca il minimo tra gli elementi dal secondo in poi e lo si scambia con il secondo, e così via. Ad ogni passo la parte iniziale dell'array è ordinata e cresce di un elemento.

```c
for (int i = 0; i < n - 1; i++) {
    int posMin = i;
    for (int j = i + 1; j < n; j++) {
        if (v[j] < v[posMin]) {      // con > si ottiene l'ordine decrescente
            posMin = j;
        }
    }
    int tmp = v[i];
    v[i] = v[posMin];
    v[posMin] = tmp;
}
```

```text
iniziale:  5 3 8 1 4
i = 0:     1 3 8 5 4    (il minimo 1 scambiato con il 5)
i = 1:     1 3 8 5 4    (il minimo dal secondo in poi è 3, già al suo posto)
i = 2:     1 3 4 5 8    (il minimo 4 scambiato con l'8)
i = 3:     1 3 4 5 8
```

### Bubble sort (ordinamento a bolle)
L'idea: si scorre l'array confrontando ogni elemento con il **successivo**, e se sono nell'ordine sbagliato si scambiano. Alla fine della prima passata l'elemento più grande è "salito" fino all'ultima posizione, come una bolla in un bicchiere. Si ripete il procedimento, ogni volta su una parte di array più corta di un elemento.

```c
int scambiato = 1;
for (int i = 0; i < n - 1 && scambiato; i++) {
    scambiato = 0;
    for (int j = 0; j < n - 1 - i; j++) {
        if (v[j] > v[j + 1]) {       // con < si ottiene l'ordine decrescente
            int tmp = v[j];
            v[j] = v[j + 1];
            v[j + 1] = tmp;
            scambiato = 1;
        }
    }
}
```

Due osservazioni:

*   il ciclo interno arriva a `n - 1 - i` perché dopo `i` passate gli ultimi `i` elementi sono già al loro posto definitivo; il `- 1` serve perché si confronta `v[j]` con `v[j + 1]`, che altrimenti uscirebbe dall'array;
*   la variabile `scambiato` è un'ottimizzazione: se durante una passata non avviene nessuno scambio, l'array è già ordinato ed è inutile continuare.

:::note[Quanto sono veloci?]
Entrambi gli algoritmi, nel caso peggiore, eseguono un numero di confronti proporzionale a n², cioè hanno complessità O(n²): raddoppiando il numero di elementi il tempo quadruplica. Per array di qualche migliaio di elementi vanno benissimo, ma per milioni di elementi esistono algoritmi molto più efficienti, come il *merge sort* e il *quick sort*, con complessità O(n log n). Approfondimenti nella pagina sulla [complessità computazionale](../../complessita/). La libreria standard del C mette a disposizione la funzione `qsort`, che vedremo nella pagina sui [puntatori](../puntatori/#8-ordinare-con-qsort).
:::

### Ricerca binaria (dicotomica)
Se l'array è **ordinato**, per cercare un valore non serve scorrerlo tutto: si guarda l'elemento centrale; se è quello cercato abbiamo finito, se è più grande il valore può trovarsi solo nella metà sinistra, altrimenti solo nella metà destra. Si ripete il procedimento sulla metà rimasta, dimezzando ogni volta lo spazio di ricerca (è lo stesso metodo che si usa per indovinare un numero tra 1 e 100 con le risposte "più alto" e "più basso").

```c
int sx = 0, dx = n - 1, pos = -1;
while (sx <= dx && pos == -1) {
    int centro = (sx + dx) / 2;
    if (v[centro] == daCercare) {
        pos = centro;
    } else if (v[centro] < daCercare) {
        sx = centro + 1;        // cerco nella metà destra
    } else {
        dx = centro - 1;        // cerco nella metà sinistra
    }
}
```

Con un milione di elementi la ricerca normale (detta *sequenziale*) può richiedere un milione di confronti, la ricerca binaria al massimo 20!

## 7. Errori comuni

| Errore | Conseguenza |
|---|---|
| `for (i = 0; i <= N; i++)` | Accesso a `v[N]`, che non esiste: valori casuali o crash |
| Array non inizializzato usato come accumulatore o contatore | Valori casuali |
| `copia = v;` oppure `if (a == b)` tra array | Errore di compilazione, o confronto tra indirizzi invece che tra contenuti |
| Massimo inizializzato a 0 invece che a `v[0]` | Risultato sbagliato se tutti i valori sono negativi |
| Scambio senza variabile di appoggio (`a = b; b = a;`) | Entrambe le variabili contengono lo stesso valore |
| Inversione con il ciclo fino a `n` invece che a `n / 2` | L'array torna com'era |
| Usare `N` invece di `n` quando l'array è riempito solo in parte | Si elaborano anche gli elementi non usati, che contengono valori casuali |

## Esercizi

Gli esercizi relativi a questi argomenti si trovano nel capitolo **"Array, stringhe e matrici"** dell'eserciziario (sezioni *Array numerici* e *Algoritmi di ordinamento*), linkato nella [pagina introduttiva](../programmazione-in-c/).
