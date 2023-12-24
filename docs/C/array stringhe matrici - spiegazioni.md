---
layout: default
title: Array, Stringhe e Matrici - Spiegazioni
nav_order: 5
parent: Programmazione in C
has_children: False
---

# Array Stringhe e Matrici - Spiegazioni ed Esempi
{: .no_toc}
  
<details open markdown="block">
  <summary>
    Table of contents
  </summary>
  {: .text-delta }
1. TOC
{:toc .toc}
</details>

In questa pagina vengono fatti molti esempi di utilizzo degli array, delle stringhe e delle matrici. Per tua comodità in fondo alla pagina sono presenti i link per scaricare i codici completi degli esempi spiegati(in questi file sono presenti anche alcuni esempi più complessi).

## Gli array

Le variabili possono essere immaginate come dei contenitori in grado di contenere un valore, il cui tipo dipende da come è stata dichiarata la variabile. In moltissimi casi i programmi non agiscono su singoli valori, ma su sequenze di valori (un elenco o una tabella di dati), per questo motivo tutti i linguaggi di programmazione prevedono una struttura dati apposita che nel linguaggio C viene detta array. Un array consiste in una sequenza di valori tutti dello stesso tipo allocati in memoria uno di seguito all'altro.

### Dichiarazione di un array

Esistono diversi modi per dichiarare e assegnare valori ad un array:

Dichiarazione di un array *a* che contiene dieci valori di tipo intero:
```c
int a[10];
```

Di solito non conviene dichiarare un array in questo modo perchè spesso, mentre si scrive codice, capita di dover modificare la dimensione dell'array, ed è molto meglio dover cambiare tale valore in un unico posto. Conviene quindi dichiarare l'array nel seguente modo:

```c
#define N 10

int main() {
    int a[N];
    // ...
}
```

La direttiva define, come include, è un comando per il compilatore con cui gli diciamo di creare una costante di nome N a cui assegnare il valore 10. In C non è possibile fare una cosa come:
```c
int main() {
    int n = 10;
    int a[n];
    // ...
}
```

perchè la dichiarazione delle variabili avviene sempre prima dell'assegnamento, perchè gli assegnamenti avvengono durante l'esecuzione del programma mentre l'allocazione della memoria per le variabili avviene prima. è necessario quindi usare le costanti definite dal compilatore se vogliamo indicare in modo parametrico quanta memoria allocare per gli array.

C'è un'importante considerazione da fare riguardo alla dichiarazione degli array: se si usano questi primi metodi in cui si dichiara solamente l'array senza assegnare alcun valore, nello spazio di memoria allocato per l'array rimangono i bit contenuti precedentemente in quella porzione di memoria, esattamente come succede quando si dichiara qualsiasi variabile in C.

Un array può essere dichiarato e contestualmente riempito di valori. Questo è l'unico caso in cui si possono assegnare più valori contemporaneamente all'array. Successivamente si potrà leggere e modificare solo un singolo elemento per volta. 
Un altra cosa da dire è che in questo caso il compilatore capisce da solo quanta memoria deve essere allocata per l'array. Risulta poi comodo segnare il numero di elementi dell'array in una variabile.
```c
int a[] = {1,7,4,6,3};
int n = 5;
```

è possibile indicare quanta memoria deve essere allocata per l'array. Nel caso indicato di seguito il compilatore alloca in memoria spazio per 10 interi, poi vengono assegnati i primi 5 elementi come indicato e i rimanenti vengono riempiti con zeri.
```c
int a[10] = {1,7,4,6,3};
int n = 5;
```

Per riempire un array di soli zeri si può quindi fare così:
```c
int a[N] = {0};
```

Per calcolare il numero di elementi di un array è possibile usare questo sistema:
```c
int a[] = {1,7,4,6,3};
int n = sizeof(a) / sizeof(int); 
```

dove sizeof(a) è una funzione che indica quanta memoria è stata allocata per l'elemento passato come parametro (in questi casi a e int). Il rapporto fra la dimensione di a e la dimensione di un int è proprio il numero di elementi di a. Chiaramente questo sistema funziona se si guarda la dimensione del giusto tipo di variabile, in questo caso int.

Questo sistema risulta comodo nel caso si voglia modifcare a mano il contenuto dell'array perchè si evita di dimenticarsi di modificare il valore di n (quando capita è poi difficile capire perchè il programma non funziona come vorremmo).

### Accedere agli elementi di un array

Dopo che si è dichiarato l'array è possibile accedere ad un solo elemento dell'array per volta. Per distinguere ogni elemento dell'array si indica la sua posizione ricordando che il primo elemento si trova in posizione 0. Questa cosa per chi inizia a programmare è poco intuitiva, sarebbe immediato pensare che il primo elemento si trova in posizione 1. Questa regola è comune a tutti i linguaggi di programmazione e ha una motivazione tecnica ben precisa, infatti bisogna pensare che la posizione di un elemento in un array è identificata dalla posizione in memoria del primo elemento + uno scostamento. Il primo elemento è quindi quello con scostamento 0, il secondo quello con scostamento 1 ... fino all'elemento con scostamento N-1. Normalmente però invece di parlare di scostamento si parla di posizione, considerando che la prima è la posizione 0.

Per assegnare dei valori ai vari elementi dell'array possiamo quindi scrivere:

```c
int a[0] = 1;
int a[1] = 7;
// ...
int a[N-1] = 3;
```

e per stamparli invece:

```c
printf("%d ", a[0]);
printf("%d ", a[1]);
// ...
printf("%d ", a[N-1]);
```

è evidente che quando si vuole eseguire qualcosa per tutti gli elementi di un array (o una parte di essi) è molto comodo usare un ciclo for. Ad esempio per stampare tutti gli elementi di un array si può scrivere:

```c
for(i = 0; i < N; i++){         // la prima posizione è 0, l'ultima N-1
    printf("%d ", a[i]);
}
printf("\n");
```

In questo caso si stampano tutti gli elementi dell'array facendo scorrere un indice dalla posizione 0 alla posizione N-1.

Se si vuole stampare l'array al contrario invece si può scrivere:

```c
for(i = N-1; i >= 0; i--){      // l'indice parte dall'ultima posizione che è N-1
    printf("%d ", a[i]);
}
printf("\n");
```

Un metodo alternativo utile per comprendere il meccanismo in questione può essere:

```c
for(i = 0; i < N; i++){      
    printf("%d ", a[N-1-i]); 
}
printf("\n");
```

In questo caso il ciclo for fa scorrere l'indice normalmente in ordine crescente ma poi lo si usa facendo una differenza: *ultima posizione - indice* cioè *N-1 - i*.

Se si volesse stampare solo una porzione dell'array si scrive:

```c
int a = 2, b = 5;
for(i = a; i <= b; i++){
    printf("%d ", a[i]);
}
printf("\n\n");
```

O al contrario:
```c
for(i = b; i >= a; i--){
    printf("%d ", a[i]);
}
printf("\n");

// metodo alternativo complicato ma istruttivo
for(i = 0; i <= b-a; i++){
    printf("%d ", a[b-i]);
}
printf("\n\n");
```

## Algoritmi classici con gli array

Ci sono alcune operazioni che vengono svolte frequentemente con gli array. Di seguito sono riportate alcune di esse.

### Stampa di un array

In questo esempio l'array è stampato all'interno di parentesi graffe con gli elementi separati tra loro da una virgola e uno spazio.

```c
printf("{");
for(int i = 0; i < n - 1; i++){
    printf("%d, ", v[i]);
}
printf("%d}", v[n-1]);
```

### Riempire un array di numeri casuali

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int i, j, v[N], min, max;
    srand(time(NULL));

    min = 0;
    max = 9;
    for(int i = 0; i < n - 1; i++){
        v[i] = rand() % (max-min+1) + min;
    }
}
```

Questo codice richiede diverse spiegazioni. Per prima cosa bisogna spiegare che un computer è in grado di generare sequenze di numeri pseudocasuali ciè sequenze di numeri che non sono davvero casuali ma che lo sembrano (la distribuzione statistica dei numeri è analoga a quella di una sequenza casuale). La sequenza di numeri è generata da un algoritmo che necessita di un punto di partenza detto *seed* (seme in inglese) a partire dal quale genera sempre gli stessi numeri in modo deterministico. Se vogliamo che il seme cambi ogni volta e con esso la sequenza generata è necessario utilizzare la funzione srand che serve appunto a modificare il valore del seed. Il parametro che passiamo alla funzione srand è il valore attuale del clock del processore (ottenuto con la funzione *time(NULL)*) che è sempre diverso ad ogni esecuzione del programma. La funzione srand va sempre messa nella funzione main prima di usare la funzione rand. L'idea migliore è quella di metterla subito dopo la dichiarazione delle variabili.

La funzione rand genera un numero intero pseudocasuale compreso tra 0 e il massimo valore rappresentabile da un int (questo valore può variare in base al processore del computer). Se vogliamo ottenere un valore casuale compreso tra due estremi *min* e *max* è necessario usare l'espressione `rand() % (max-min+1) + min`. Per capire questa espressione analizziamo un esempio pratico in cui *min = 3* e *max = 5*. I seguenti tre passaggi mi permettono di ricostruire la formula

1. `rand() % 5` genererebbe un numero tra 0 e 4 perchè se prendo un numero e calcolo il resto della divisione per 5 ottengo per forza un numero tra 0 e 4.
2. I numeri da estrarre tra 3 e 5 sono solo 3,4,5 cioè 3 numeri ossia la differenza tra 5 e 3 più 1 (5-3 = 2, perdo un estremo dell'intervallo)
3. per generare i numeri 3,4,5 estraggo i numeri 0,1,2 e poi aggiungo 3 (*min*)

Mettendo insieme le tre considerazioni ottengo `rand() % (5-3+1) + 3` ossia `rand() % (max-min+1) + min`

### Copiare un array

Se voglio copiare un array le operazioni da fare sono molto semplici.

```c
for(i = 0; i < N; i++){
    vCopia[i] = v[i];
}
```

Chiaramente vCopia e v devono avere la stessa dimensione N

Se si volesse usare una funzione già fatta presente nella libreria standard:

```c
// funzione C
memcpy(vCopia, v, sizeof(v));     // la funzione fa parte della libreria string.h

// funzione C++
std::copy(v, v+N, vCopia);        // la funzione fa parte della libreria algorithm
```

la funzione memcpy (abbreviazione di memory copy) copia in vCopia l'array v. è necessario indicare quanti byte copiare con la funzione sizeof(v).

Per comodità ho riportato anche la funzione C++ che in molti casi si può tranquillamente usare poichè in alcuni casi (il nostro) si usano compilatori C++ per compilare il C.

### Ricerca di un elemento nell'array

Per verificare se un numero è presente nell'array scrivo:

```c
int daCercare = 5;
int trovato = 0;
for(i = 0; i < N && !trovato; i++){    
    if(v[i] == daCercare){
        trovato = 1;
    }
}
if(trovato) {
    printf("%d e' contenuto nell'array", daCercare);
} else {
    printf("%d non e' contenuto nell'array", daCercare);
}
printf("\n");
```

In questo caso uso una variabile per ricordare se ho trovato il numero oppure no. In C non esistono le variabili booleane, quelle variabili che possono contenere solo i valori *vero* o *falso* quindi si usano numeri interi a cui si assegnano i valori 1 per vero e 0 per falso. In realtà nelle versioni più recenti del linguaggio sono state aggiunte le variabili booleane ma solitamente i compilatori attualmente in circolazione non implementano ancora questa funzionalità.


Per cercare la posizione della prima occorrenza di un numero in un array:

```c
daCercare = 5;
int pos = -1;
for(i = 0; i < N && pos < 0; i++){   // se non metto "&& pos" mi stampa l'ultima posizione di 5 nell'array 
    if(v[i] == daCercare){
        pos = i;
    }
}
if(pos >= 0) {
    printf("%d e' contenuto nell'array in posizione %d", daCercare, pos);
} else {
    printf("%d non e' contenuto nell'array", daCercare);
}
printf("\n");

```

In questo caso uso la variabile pos per indicare la posizione ed essa sostituisce la variabile booleana. Uso il valore -1 per indicare che non è ancora stata trovata nessuna posizione. Questo è un trucco usato in molti contesti.

Per contare quante volte è presente un numero nell'array:

```c
daCercare = 5;
int occorrenze = 0;
for(i = 0; i < N; i++){
    if(v[i] == daCercare){
        occorrenze += 1;
    }
}
if(occorrenze) {
    printf("%d e' contenuto nell'array %d volte", daCercare, occorrenze);
} else {
    printf("%d non e' contenuto nell'array", daCercare);
}
```




### Ricerca dei valori massimi e minimi dell'array

Per cercare i valori massimi e minimi contenuti in un array:

```c
int min = v[0];
int max = v[0];
for (i = 1; i < N; i++){
    if(v[i] > max){
        max = v[i];
    }
    else if (v[i] < min){
        min = v[i];
    }
}
printf("min: %d\nmax: %d\n\n", min, max);
```

Ogni volta che si cerca il valore massimo o il valore minimo in un array, il modo migliore di procedere è:
1. segnare che il valore massimo è il primo elemento dell'array
2. scorrere tutto l'array a partire dalla seconda posizione (la posizione 1)
   1. se il valore in posizione i è maggiore di quello trovato finora esso diventa il nuovo max. 


### Calcolo della media

```c
float media = 0;
for (i = 1; i < N; i++){
    media += v[i];
}
media /= N;
printf("La media vale: %.2f\n\n", media);
```

Ricorda che media deve essere un valore float (o double) anche se gli elementi dell'array sono interi, altrimenti viene calcolato un valore troncato.

### Ricerca di una sequenza di numeri in una sequenza più grande

Per cercare la prima posizione di una sequenza di numeri v_x in un array più grande v_y

```c
int posvx = -1;
for(i = 0; i < dimvy; i++){
    for(j = 0; j < dimvx && vx[j] == vy[i+j]; j++){
        // niente
    }
    if(j == dimvx){
        posvx = i;
        break;          // posso in alternativa mettere come condizione del ciclo sulle i: i < dimvy && posvx != -1
                        // oppure se non metto niente mi trova l'ultima posizione di vx in vy
    }
}

if(posvx == -1){
    printf("L'array da cercare non e' contenuto nell'array in cui cercare\n\n");
}else{
    printf("L'array da cercare e' stato trovato nella posizione %d\n\n", posvx);
}
    
```

Dove:
1. posvx indica la posizione in cui trovo v_x
2. dimvx e dimvy sono le dimensioni di v_x e di v_y

Questo è sicuramente l'esempio più complicato visto finora e richiede di aver acquisito una certa padronanza con i cicli for applicati agli array.




## Archivio codici di esempio

Qui puoi scaricare l'archivio completo degli esempi che ho scritto.

- [Archivio esempi C]({{site.baseurl}}/assets/codice/C/Esempi-C.zip)






