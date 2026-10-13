---
title: Matrici
description: Array a due dimensioni in C, dichiarazione, memorizzazione, scorrimento per righe e per colonne, diagonali e celle adiacenti
---

Per capire cos'è una **matrice** la si può immaginare come una **tabella**: mentre un [array](../array/) è un elenco di valori che si sviluppa in una sola dimensione, una matrice si sviluppa in due dimensioni, **righe** e **colonne**. Le matrici sono ovunque: la griglia di una battaglia navale o di un campo minato, la classifica di un campionato, i pixel di un'immagine, l'orario settimanale delle lezioni.

In C una matrice non è altro che un **array di array**: un array i cui elementi sono a loro volta array. Valgono quindi tutte le regole già viste per gli array. In realtà le matrici possono avere un numero qualsiasi di dimensioni, e da questo punto di vista un array è semplicemente una matrice a una sola dimensione.

## 1. Dichiarare una matrice

Una matrice si dichiara come un array, indicando tra parentesi quadre **tutte** le dimensioni:

```c
#define N 4     // righe
#define M 6     // colonne

int main() {
    int mat[N][M];      // matrice di 4 righe e 6 colonne
    // ...
    return 0;
}
```

Il linguaggio C non impone che la prima dimensione indichi le righe e la seconda le colonne, ma è una **convenzione** universale in programmazione (come in matematica): si indicano sempre prima le righe, poi le colonne (e poi l'eventuale profondità...). Rispettare le convenzioni serve a rendere il codice comprensibile a voi e agli altri.

Ogni elemento si indica con **due indici**, il primo per la riga e il secondo per la colonna, entrambi a partire da 0:

```text
                   colonne (j)
             0    1    2    3    4    5
          +----+----+----+----+----+----+
        0 |    |    |    |    |    |    |
          +----+----+----+----+----+----+
        1 |    |    |    | X  |    |    |    X = mat[1][3]
righe     +----+----+----+----+----+----+    (riga 1, colonna 3)
 (i)    2 |    |    |    |    |    |    |
          +----+----+----+----+----+----+
        3 |    |    |    |    |    |    |
          +----+----+----+----+----+----+
```

```c
mat[0][0] = 5;              // primo elemento in alto a sinistra
mat[N-1][M-1] = 9;          // ultimo elemento in basso a destra
mat[1][3] = mat[0][0] * 2;
```

### Inizializzare una matrice
Come per gli array, si possono assegnare i valori già nella dichiarazione, scrivendo ogni riga tra graffe:

```c
int mat[3][2] = {
    {1, 2},
    {3, 4},
    {5, 6}
};

int zeri[N][M] = {0};      // tutti gli elementi valgono 0
```

È possibile omettere la **prima** dimensione (`int mat[][2] = {...}`), perché il compilatore può contare da solo le righe. Le altre dimensioni invece sono obbligatorie: per sistemare i valori in memoria il compilatore deve sapere quanto è lunga ogni riga. Il consiglio è di indicare sempre tutte le dimensioni: non costa nulla e si evitano problemi.

### Come è memorizzata una matrice
La memoria di un computer è una lunghissima sequenza di byte, a una sola dimensione. Per memorizzare una matrice il C mette le righe **una dopo l'altra**: prima tutti gli elementi della riga 0, poi quelli della riga 1, e così via (si dice che la matrice è memorizzata *per righe*).

```text
mat[3][2]:   riga 0      riga 1      riga 2
           +----+----+----+----+----+----+
memoria:   |  1 |  2 |  3 |  4 |  5 |  6 |
           +----+----+----+----+----+----+
```

Per trovare l'elemento `mat[i][j]` il computer parte dall'inizio della matrice e salta `i` righe intere più `j` elementi, cioè `i * M + j` posizioni, dove `M` è il numero di colonne. Ecco perché il compilatore ha bisogno di conoscere il numero di colonne: senza, non saprebbe calcolare dove inizia ogni riga. Questo dettaglio tornerà fuori quando passeremo le matrici alle [funzioni](../puntatori/#7-matrici-come-parametri).

## 2. Riempire e stampare una matrice

Quasi sempre le matrici sono troppo grandi per essere riempite a mano, oppure i loro valori non sono noti in anticipo. Si usano allora **due cicli `for` annidati**: il ciclo esterno scorre le righe, quello interno scorre le colonne della riga corrente.

```c
#include <stdio.h>

#define N 4
#define M 6

int main() {
    int mat[N][M];

    // riempimento: ogni cella contiene il prodotto di riga e colonna (tabelline)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            mat[i][j] = (i + 1) * (j + 1);
        }
    }

    // stampa
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%3d", mat[i][j]);
        }
        printf("\n");       // a capo alla fine di ogni riga
    }

    return 0;
}
```

```text
  1  2  3  4  5  6
  2  4  6  8 10 12
  3  6  9 12 15 18
  4  8 12 16 20 24
```

Alcune osservazioni:

*   Si usa **`i` per le righe e `j` per le colonne**. In questo esempio è facile, ma in quelli più complicati questa regola vi aiuterà moltissimo: quando leggete `mat[j][i]` dovrebbe suonare subito un campanello d'allarme.
*   Nelle tabelline si moltiplica `(i + 1) * (j + 1)` perché gli indici partono da 0, mentre le tabelline partono da 1.
*   Il `printf("\n")` va messo **dopo** la fine del ciclo sulle `j`, cioè alla fine di ogni riga.
*   Per avere le colonne **allineate** tutti i numeri devono occupare lo stesso spazio: `%3d` stampa ogni intero su almeno 3 caratteri, aggiungendo spazi a sinistra. La larghezza va scelta in base al numero più lungo da stampare (più uno spazio di separazione).

Per riempire la matrice con numeri casuali o da tastiera basta cambiare l'istruzione nel ciclo interno:

```c
mat[i][j] = rand() % (max - min + 1) + min;     // numeri casuali tra min e max

printf("Elemento [%d][%d]: ", i, j);            // da tastiera
scanf("%d", &mat[i][j]);
```

## 3. Lavorare su righe e colonne

### Una riga o una colonna specifica
Per lavorare su una sola **riga** si fissa l'indice `i` e si fa scorrere solo `j`:

```c
int i = 2;                      // riga da stampare
for (int j = 0; j < M; j++) {
    printf("%d ", mat[i][j]);
}
printf("\n");
```

Per lavorare su una sola **colonna**, invece, si fissa `j` e si fa scorrere `i`. In questo esempio la colonna viene stampata in verticale, andando a capo dopo ogni elemento:

```c
int j = 2;                      // colonna da stampare
for (int i = 0; i < N; i++) {
    printf("%d\n", mat[i][j]);
}
```

### Somma di ogni riga e di ogni colonna
Per calcolare la somma di ogni riga si usa un accumulatore che va **azzerato all'inizio di ogni riga**, cioè dentro il ciclo esterno:

```c
for (int i = 0; i < N; i++) {
    int somma = 0;
    for (int j = 0; j < M; j++) {
        somma += mat[i][j];
    }
    printf("Somma della riga %d: %d\n", i, somma);
}
```

Per le colonne si **scambiano i due cicli**: il ciclo esterno scorre le colonne e quello interno le righe. Gli indici però restano al loro posto: si scrive sempre `mat[i][j]`, con `i` per la riga e `j` per la colonna.

```c
for (int j = 0; j < M; j++) {
    int somma = 0;
    for (int i = 0; i < N; i++) {
        somma += mat[i][j];
    }
    printf("Somma della colonna %d: %d\n", j, somma);
}
```

Se le somme servono anche dopo (ad esempio per trovare la riga con la somma massima) si possono salvare in un array, `int sommeRighe[N]`, scrivendo `sommeRighe[i] = somma;` alla fine di ogni riga.

### Scambiare due righe
Per scambiare la riga `r1` con la riga `r2` si scambiano, una colonna alla volta, gli elementi corrispondenti:

```c
for (int j = 0; j < M; j++) {
    int tmp = mat[r1][j];
    mat[r1][j] = mat[r2][j];
    mat[r2][j] = tmp;
}
```

## 4. Matrici quadrate e diagonali

Una matrice con lo stesso numero di righe e colonne si dice **quadrata**. Nelle matrici quadrate si definiscono due diagonali:

*   la **diagonale principale**, dall'angolo in alto a sinistra a quello in basso a destra, è formata dagli elementi in cui **`i == j`**;
*   la **diagonale secondaria**, dall'angolo in alto a destra a quello in basso a sinistra, è formata dagli elementi in cui **`i + j == N - 1`**.

```text
       j: 0  1  2  3               j: 0  1  2  3
  i = 0   X  .  .  .          i = 0   .  .  .  X
  i = 1   .  X  .  .          i = 1   .  .  X  .
  i = 2   .  .  X  .          i = 2   .  X  .  .
  i = 3   .  .  .  X          i = 3   X  .  .  .
    principale: i == j       secondaria: i + j == N-1
```

Per scorrere una diagonale **basta un solo ciclo**: nella principale riga e colonna coincidono, nella secondaria la colonna si ricava dalla riga.

```c
for (int i = 0; i < N; i++) {
    printf("%d ", mat[i][i]);           // diagonale principale
}
printf("\n");
for (int i = 0; i < N; i++) {
    printf("%d ", mat[i][N - 1 - i]);   // diagonale secondaria
}
printf("\n");
```

Allo stesso modo, gli elementi **sopra** la diagonale principale sono quelli con `j > i`, quelli **sotto** hanno `j < i`.

### La matrice trasposta
La **trasposta** di una matrice si ottiene scambiando le righe con le colonne: l'elemento `[i][j]` va in posizione `[j][i]`. Per una matrice quadrata si può fare "sul posto", scambiando ogni elemento sopra la diagonale con il suo simmetrico:

```c
for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {    // solo gli elementi sopra la diagonale
        int tmp = mat[i][j];
        mat[i][j] = mat[j][i];
        mat[j][i] = tmp;
    }
}
```

Notate che `j` parte da `i + 1`: se scorresse tutta la matrice, ogni coppia verrebbe scambiata **due volte**, e la matrice tornerebbe com'era (è lo stesso problema dell'inversione di un array scorso tutto invece che fino a metà).

## 5. Le celle adiacenti

In molti problemi (giochi su griglia come il campo minato o il "gioco della vita", elaborazione di immagini...) bisogna esaminare le **celle vicine** a una cella data. Le celle adiacenti a `[i][j]`, comprese quelle in diagonale, sono 8 e si ottengono sommando a `i` e a `j` tutte le combinazioni di -1, 0, +1 (esclusa la combinazione 0, 0, che è la cella stessa):

```text
[i-1][j-1]  [i-1][j]  [i-1][j+1]
[i  ][j-1]  [i  ][j]  [i  ][j+1]
[i+1][j-1]  [i+1][j]  [i+1][j+1]
```

Invece di scrivere 8 `if` diversi, si possono usare due cicli che fanno variare gli scostamenti `di` e `dj` da -1 a +1. Ad esempio, per contare le mine attorno a una cella del campo minato (dove una mina è indicata con 1):

```c
int mine = 0;
for (int di = -1; di <= 1; di++) {
    for (int dj = -1; dj <= 1; dj++) {
        int ri = i + di, cj = j + dj;
        if ((di != 0 || dj != 0) &&             // esclude la cella stessa
            ri >= 0 && ri < N && cj >= 0 && cj < M &&   // resta dentro la matrice
            campo[ri][cj] == 1) {
            mine++;
        }
    }
}
```

:::caution[Attenzione ai bordi]
Le celle sul bordo della matrice hanno meno di 8 vicini: per la cella `[0][0]`, ad esempio, la cella `[-1][-1]` non esiste. Per questo, **prima** di accedere a una cella vicina bisogna controllare che i suoi indici siano dentro i limiti. L'ordine delle condizioni è importante: grazie alla [valutazione a corto circuito](../strutture-di-controllo/#valutazione-a-corto-circuito), se il controllo sui limiti fallisce l'accesso a `campo[ri][cj]` non viene eseguito.
:::

## 6. Matrici a più dimensioni

Si possono dichiarare matrici con un numero qualsiasi di dimensioni, aggiungendo altre parentesi quadre. Una matrice a tre dimensioni si può immaginare come una pila di tabelle, o come un cubo; per scorrerla servono tre cicli annidati.

```c
// temperature registrate ogni ora (24), per ogni giorno (31), per ogni mese (12)
double temperature[12][31][24];

temperature[11][24][8] = -2.5;    // il 25 dicembre alle ore 8
```

## 7. Errori comuni

| Errore | Conseguenza |
|---|---|
| Indici scambiati, `mat[j][i]` invece di `mat[i][j]` | Elementi sbagliati, o accessi fuori dalla matrice se non è quadrata |
| Nel ciclo interno si usa `N` (righe) invece di `M` (colonne) | Elementi saltati o accessi fuori dai limiti |
| `printf("\n")` dentro il ciclo interno o dimenticato | Un elemento per riga, oppure tutta la matrice su una sola riga |
| Accumulatore azzerato fuori dal ciclo esterno | Le somme delle righe si accumulano tra loro |
| Celle adiacenti senza controllo dei bordi | Accesso fuori dalla matrice: valori casuali o crash |
| Trasposta scorrendo tutta la matrice | Ogni coppia è scambiata due volte e la matrice non cambia |

## Esercizi

Gli esercizi relativi a questi argomenti si trovano nel capitolo **"Array, stringhe e matrici"** dell'eserciziario (sezione *Matrici di numeri*), linkato nella [pagina introduttiva](../programmazione-in-c/).
