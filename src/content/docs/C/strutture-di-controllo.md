---
title: Strutture di controllo
description: Selezione con if ed else, condizioni e operatori logici, cicli while, for e do-while, break e continue, schemi algoritmici ricorrenti in C
---

I programmi visti finora sono semplici **sequenze** di istruzioni, eseguite sempre tutte e sempre nello stesso ordine. I programmi veri però devono **prendere decisioni** (eseguire certe istruzioni solo se si verifica una condizione) e **ripetere** operazioni (ad esempio leggere cento numeri, o continuare a chiedere un dato finché l'utente non lo inserisce correttamente).

Le istruzioni che permettono di modificare il flusso di esecuzione si chiamano **strutture di controllo**. Un importante risultato dell'informatica teorica, il *teorema di Böhm-Jacopini*, afferma che qualsiasi algoritmo può essere scritto usando soltanto tre strutture:

*   la **sequenza**: istruzioni eseguite una dopo l'altra;
*   la **selezione**: si sceglie quali istruzioni eseguire in base a una condizione (`if`, `else`);
*   l'**iterazione**: un blocco di istruzioni viene ripetuto finché una condizione è vera (`while`, `for`, `do-while`).

## 1. La selezione: `if` ed `else`

L'istruzione `if` (in italiano "se") esegue un blocco di codice solo se una **condizione** è vera. Si può aggiungere un blocco `else` ("altrimenti") che viene eseguito quando la condizione è falsa.

```c
#include <stdio.h>

int main() {
    int num, den;

    printf("Inserisci numeratore e denominatore: ");
    scanf("%d %d", &num, &den);

    if (den != 0) {
        printf("%d / %d = %g\n", num, den, (double)num / den);
    } else {
        printf("Impossibile dividere per zero!\n");
    }

    return 0;
}
```

La sintassi è semplice:

*   la condizione va scritta **tra parentesi tonde** dopo `if`;
*   il codice da eseguire va racchiuso tra **parentesi graffe** e indentato;
*   l'`else` non ha condizione: si esegue in tutti i casi in cui la condizione dell'`if` è falsa.

L'`else` non è obbligatorio. Se manca e la condizione è falsa, semplicemente non succede nulla e il programma prosegue con l'istruzione successiva:

```c
if (voto >= 6) {
    printf("Promosso!\n");
}
printf("Fine dello scrutinio\n");   // eseguita in ogni caso
```

:::caution[Le graffe si possono omettere, ma è meglio di no]
Se il blocco contiene una sola istruzione, il C permette di omettere le graffe: `if (x > 0) printf("positivo");`. Così però è facile sbagliare quando in seguito si aggiunge una seconda istruzione, convinti che faccia parte dell'`if`:

```c
if (x > 0)
    printf("positivo\n");
    conta++;              // NON fa parte dell'if: viene eseguita sempre!
```

L'indentazione inganna l'occhio, ma il compilatore la ignora. Il consiglio è di mettere **sempre** le graffe. Se proprio non le si vuole mettere, almeno scrivete l'unica istruzione **sulla stessa riga** dell'`if`, invece di andare a capo:

```c
if (x > 0) conta++;
```

In questo modo è evidente che l'`if` controlla solo quell'istruzione, ed è molto più difficile aggiungerne per sbaglio una seconda pensando che faccia parte dell'`if`.
:::

### Scelte multiple: `else if`
Quando le alternative sono più di due si possono concatenare più condizioni con `else if`. Le condizioni vengono controllate **in ordine, dall'alto verso il basso**: appena una risulta vera viene eseguito il suo blocco e tutti gli altri vengono saltati.

```c
if (voto < 4) {
    printf("Gravemente insufficiente\n");
} else if (voto < 6) {
    printf("Insufficiente\n");
} else if (voto < 8) {
    printf("Discreto\n");
} else {
    printf("Ottimo\n");
}
```

Notate che nel secondo ramo non serve scrivere `voto >= 4 && voto < 6`: se il programma arriva a controllare la seconda condizione, la prima era sicuramente falsa, quindi `voto` è già sicuramente maggiore o uguale a 4.

### `if` annidati
All'interno di un blocco `if` o `else` si può scrivere qualsiasi istruzione, compresi altri `if`. In questo caso si dice che gli `if` sono **annidati**:

```c
if (a > 0) {
    if (a % 2 == 0) {
        printf("positivo e pari\n");
    } else {
        printf("positivo e dispari\n");
    }
} else {
    printf("non positivo\n");
}
```

## 2. Le condizioni

Una condizione è un'espressione a cui si può rispondere solo **vero** o **falso**. Le condizioni più semplici sono i confronti tra due valori, che si possono combinare tra loro con gli operatori logici.

### Operatori relazionali (di confronto)

| Operatore | Significato | Esempio vero |
|---|---|---|
| `==` | uguale a | `5 == 5` |
| `!=` | diverso da | `5 != 3` |
| `<` | minore di | `3 < 5` |
| `<=` | minore o uguale a | `5 <= 5` |
| `>` | maggiore di | `5 > 3` |
| `>=` | maggiore o uguale a | `5 >= 3` |

### Operatori logici

| Operatore | Nome | Significato |
|---|---|---|
| `&&` | AND (e) | vero se **entrambe** le condizioni sono vere |
| `\|\|` | OR (o) | vero se **almeno una** delle due condizioni è vera |
| `!` | NOT (non) | inverte la condizione: vero diventa falso e viceversa |

```c
// a è maggiore di 10 e dispari, oppure è multiplo di 3
if ((a > 10 && a % 2 != 0) || a % 3 == 0) {
    printf("%d rispetta le condizioni\n", a);
}
```

Il `&&` ha la precedenza sull'`||` (un po' come la moltiplicazione sulla somma), ma nelle condizioni complesse è sempre meglio usare le parentesi per rendere esplicito il significato.

:::caution[Gli intervalli non si scrivono come in matematica]
Per controllare che `x` sia compreso tra 0 e 10, in matematica si scrive 0 < x < 10. In C **non** funziona:

```c
if (0 < x < 10)            // SBAGLIATO, ma compila!
if (x > 0 && x < 10)       // CORRETTO
```

Il compilatore calcola prima `0 < x`, che vale 0 o 1, e poi confronta quel risultato con 10: la condizione è quindi **sempre vera**. Allo stesso modo, per controllare se `c` vale `'a'` oppure `'b'` non si scrive `c == 'a' || 'b'` ma `c == 'a' || c == 'b'`.
:::

### Valutazione a corto circuito
Gli operatori `&&` e `||` valutano le condizioni **da sinistra a destra** e si fermano appena il risultato è certo: se la prima condizione di un `&&` è falsa, il risultato è sicuramente falso e la seconda non viene nemmeno calcolata (lo stesso vale per un `||` la cui prima condizione è vera). Questo comportamento si può sfruttare per evitare errori:

```c
if (den != 0 && num / den > 2) {   // se den vale 0 la divisione non viene eseguita
    printf("Il rapporto supera 2\n");
}
```

### Il vero e il falso in C
In C le condizioni sono in realtà dei **numeri interi**: un confronto vero vale `1`, un confronto falso vale `0`. Più in generale, nelle condizioni:

*   **`0` è considerato falso**;
*   **qualsiasi valore diverso da 0 è considerato vero**.

Per questo al posto di una condizione si può scrivere direttamente una variabile o il risultato di una funzione:

```c
int trovato = 0;
// ...
if (trovato) {          // equivale a: if (trovato != 0)
    printf("Trovato!\n");
}
if (!trovato) {         // equivale a: if (trovato == 0)
    printf("Non trovato\n");
}
```

Variabili come `trovato`, usate per ricordare se qualcosa è vero o falso, si chiamano **flag** (bandierine). Dallo standard C99 si può usare la libreria `stdbool.h`, che definisce il tipo `bool` e le costanti `true` e `false`. Rendono il codice più leggibile, ma dietro le quinte sono ancora gli interi 1 e 0:

```c
#include <stdbool.h>

bool trovato = false;
// ...
if (trovato) {
    printf("Trovato!\n");
}
```

:::danger[`=` al posto di `==`]
È l'errore più classico in assoluto:

```c
if (x = 5) {       // SBAGLIATO: assegna 5 a x, poi controlla se 5 è vero (lo è sempre!)
if (x == 5) {      // CORRETTO: confronta x con 5
```

Il primo `if` è sintatticamente corretto, quindi il compilatore lo accetta (con `-Wall` dà almeno un warning): `x` viene sovrascritta e la condizione è sempre vera.

Un altro errore subdolo è il **punto e virgola dopo la condizione**: `if (x > 0);` è un `if` con un blocco vuoto, e il blocco tra graffe che segue viene eseguito sempre.
:::

## 3. Il ciclo `while`

Spesso un programma deve ripetere le stesse operazioni tante volte: si dice che si è in presenza di un **ciclo** o **iterazione**. Il ciclo più semplice è il `while` ("finché"): ripete il blocco di codice **finché la condizione è vera**.

```c
int i = 0;
while (i < 10) {
    printf("%d ", i);
    i++;
}
printf("\n");
```

```text
0 1 2 3 4 5 6 7 8 9
```

Il funzionamento è questo:

1.  si controlla la condizione;
2.  se è **falsa** il ciclo termina e si prosegue con l'istruzione dopo la graffa chiusa;
3.  se è **vera** si esegue il blocco e poi si torna al punto 1.

Ogni ripetizione del blocco si chiama **iterazione**. Se la condizione è falsa fin dall'inizio, il blocco non viene eseguito neanche una volta.

Il `while` è il ciclo adatto quando **non si sa in anticipo** quante volte bisognerà ripetere le operazioni. Ad esempio, leggere numeri finché l'utente non inserisce 0:

```c
#include <stdio.h>

int main() {
    int n, somma = 0;

    printf("Inserisci un numero (0 per terminare): ");
    scanf("%d", &n);
    while (n != 0) {
        somma += n;
        printf("Inserisci un numero (0 per terminare): ");
        scanf("%d", &n);
    }
    printf("La somma vale %d\n", somma);

    return 0;
}
```

Notate che la lettura compare due volte: una prima del ciclo (per avere un primo valore da controllare) e una alla fine del blocco (per leggere il valore successivo prima di ricontrollare la condizione).

:::danger[Il ciclo infinito]
Se all'interno del ciclo nulla modifica le variabili della condizione, la condizione resta vera per sempre e il programma non termina più:

```c
int i = 0;
while (i < 10) {
    printf("%d ", i);
    // manca i++: stampa 0 all'infinito
}
```

Se vi capita, interrompete il programma premendo `Ctrl + C` nel terminale.
:::

## 4. Il ciclo `for`

Moltissimi cicli hanno la stessa struttura: una variabile (il **contatore** o **indice**) viene inizializzata, si controlla una condizione e alla fine di ogni iterazione la variabile viene incrementata. Il `for` permette di scrivere queste tre parti tutte insieme, in un'unica riga:

```c
for (int i = 0; i < 10; i++) {
    printf("%d ", i);
}
```

Questo `for` è del tutto equivalente al `while` del paragrafo precedente. Tra le parentesi ci sono tre parti separate da `;`:

| Parte | Esempio | Quando viene eseguita |
|---|---|---|
| inizializzazione | `int i = 0` | una sola volta, prima di iniziare il ciclo |
| condizione | `i < 10` | prima di ogni iterazione: se è falsa il ciclo termina |
| aggiornamento | `i++` | alla fine di ogni iterazione |

`while` e `for` sono del tutto equivalenti (tutto ciò che si fa con uno si può fare con l'altro), ma per convenzione:

*   si usa il **`for`** quando si conosce il numero di ripetizioni, o quando c'è un indice che scorre un insieme di valori (come gli elementi di un [array](../array/));
*   si usa il **`while`** in tutti gli altri casi, quando la condizione non dipende dallo scorrere di un contatore.

Alcuni esempi di `for`:

```c
for (int i = 1; i <= 10; i++)      // da 1 a 10
for (int i = 10; i > 0; i--)       // da 10 a 1, al contrario
for (int i = 0; i <= 100; i += 5)  // 0, 5, 10, ..., 100
for (int i = 1; i <= 1000; i *= 2) // 1, 2, 4, 8, ..., 512
```

:::note[Dove dichiarare l'indice]
Dichiarando la variabile dentro il `for` (`for (int i = 0; ...)`), questa esiste solo all'interno del ciclo. Se il valore dell'indice serve anche dopo la fine del ciclo, bisogna dichiararla prima: `int i; for (i = 0; ...)`. Nei programmi più vecchi, e nei compilatori che seguono lo standard C89, si trova solo questa seconda forma.
:::

## 5. Il ciclo `do-while`

Il `do-while` è una variante del `while` in cui la condizione viene controllata **alla fine** di ogni iterazione invece che all'inizio. Di conseguenza il blocco viene eseguito **sempre almeno una volta**.

```c
int voto;
do {
    printf("Inserisci un voto tra 1 e 10: ");
    scanf("%d", &voto);
} while (voto < 1 || voto > 10);
```

È la struttura perfetta per l'**input con controllo**: il dato va chiesto almeno una volta, e va richiesto finché non è valido. Con un `while` normale avremmo dovuto scrivere la lettura due volte, come nell'esempio della somma. Notate il **punto e virgola** obbligatorio dopo la condizione finale.

Il `do-while` è meno usato degli altri cicli e alcuni linguaggi (come Python) non lo prevedono nemmeno, ma in casi come questo rende il codice più semplice.

## 6. `break` e `continue`

Due istruzioni permettono di modificare il normale flusso di un ciclo:

*   **`break`** esce immediatamente dal ciclo, qualunque sia la condizione;
*   **`continue`** salta il resto dell'iterazione corrente e passa direttamente alla successiva (nel `for`, eseguendo comunque l'aggiornamento).

```c
// stampa i numeri da 1 a 20 saltando i multipli di 3, e si ferma al primo multiplo di 7
for (int i = 1; i <= 20; i++) {
    if (i % 3 == 0) {
        continue;       // salta la stampa e passa al prossimo i
    }
    if (i % 7 == 0) {
        break;          // esce dal ciclo
    }
    printf("%d ", i);
}
```

```text
1 2 4 5
```

Un uso tipico di `break` è il ciclo con condizione sempre vera, `while (1)`, da cui si esce solo quando succede qualcosa (molto comune nei programmi a eventi, come un gioco che continua finché l'utente non preme un certo tasto):

```c
while (1) {
    printf("Inserisci un numero positivo (0 per uscire): ");
    scanf("%d", &n);
    if (n == 0) {
        break;
    }
    // ... elaborazione di n ...
}
```

`break` e `continue` non sono indispensabili (si può sempre ottenere lo stesso risultato con condizioni scritte bene) e un loro uso eccessivo rende i programmi difficili da seguire. In alcuni contesti però semplificano molto il codice.

## 7. Cicli annidati

Un ciclo può contenere al suo interno un altro ciclo. Per ogni iterazione del ciclo **esterno**, il ciclo **interno** viene eseguito per intero.

```c
// stampa un rettangolo di asterischi di 3 righe e 5 colonne
for (int i = 0; i < 3; i++) {          // per ogni riga...
    for (int j = 0; j < 5; j++) {      // ...stampa 5 asterischi
        printf("* ");
    }
    printf("\n");                      // a fine riga va a capo
}
```

```text
* * * * *
* * * * *
* * * * *
```

Anche la tavola pitagorica si costruisce con due cicli annidati. Notate la larghezza `%4d` per incolonnare i numeri:

```c
for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
        printf("%4d", i * j);
    }
    printf("\n");
}
```

Per convenzione si usa `i` come indice del ciclo esterno (le **righe**) e `j` per quello interno (le **colonne**). Abituatevi fin da subito a rispettare questa regola: con le [matrici](../matrici/) vi eviterà moltissimi errori.

## 8. Schemi algoritmici ricorrenti

Molti problemi, anche diversissimi tra loro, si risolvono con gli stessi "schemi" di base. Conviene impararli bene perché si ritrovano continuamente.

### Contatore
Una variabile che parte da 0 e viene incrementata ogni volta che si verifica un evento.

```c
int pari = 0;
for (int i = 0; i < 10; i++) {
    scanf("%d", &n);
    if (n % 2 == 0) {
        pari++;
    }
}
printf("Hai inserito %d numeri pari\n", pari);
```

### Accumulatore
Una variabile in cui si "accumula" un risultato: per le **somme** si parte da 0, per i **prodotti** da 1 (partire da 0 renderebbe nullo l'intero prodotto). Per la media si divide la somma per il numero di elementi, ricordandosi della [divisione tra interi](../elementi-di-base/#4-gli-operatori-aritmetici).

```c
int somma = 0;
long long fattoriale = 1;
for (int i = 1; i <= n; i++) {
    somma += i;
    fattoriale *= i;
}
double media = (double)somma / n;
```

### Massimo e minimo
Si assume che il primo valore sia il massimo (e il minimo) e lo si confronta con tutti gli altri, aggiornandolo quando si trova un valore più grande (o più piccolo).

```c
printf("Numero 1: ");
scanf("%d", &n);
int max = n, min = n;        // il primo valore è sia il massimo sia il minimo
for (int i = 2; i <= 10; i++) {
    printf("Numero %d: ", i);
    scanf("%d", &n);
    if (n > max) {
        max = n;
    }
    if (n < min) {
        min = n;
    }
}
```

:::caution
Non inizializzate il massimo a 0: se l'utente inserisce solo numeri negativi, il massimo risulterebbe 0, un valore che non è mai stato inserito. Partite sempre dal **primo valore** effettivo.
:::

### Flag: cercare se esiste almeno un elemento
Per sapere se **almeno un** valore soddisfa una condizione (o se **tutti** la soddisfano), si usa una variabile flag. L'esempio classico è il controllo di primalità: un numero è primo se **non esiste** nessun divisore tra 2 e n-1.

```c
#include <stdio.h>

int main() {
    int n, primo;

    printf("Inserisci un numero: ");
    scanf("%d", &n);

    primo = (n >= 2);                       // 0 e 1 non sono primi
    for (int d = 2; d * d <= n && primo; d++) {
        if (n % d == 0) {
            primo = 0;                      // trovato un divisore: non è primo
        }
    }

    if (primo) {
        printf("%d e' primo\n", n);
    } else {
        printf("%d non e' primo\n", n);
    }

    return 0;
}
```

Due osservazioni:

*   la condizione `&& primo` nel `for` fa terminare il ciclo appena si trova un divisore: è inutile continuare a cercare;
*   basta cercare i divisori fino alla radice quadrata di `n` (cioè finché `d * d <= n`): se `n` avesse un divisore più grande della radice, avrebbe anche un "compagno" più piccolo, che avremmo già trovato.

### Scomporre un numero nelle sue cifre
Con `% 10` si ottiene l'ultima cifra, con `/ 10` la si elimina. Ripetendo finché il numero non diventa 0 si analizzano tutte le cifre, dall'ultima alla prima:

```c
int n = 4721, cifre = 0, somma = 0;
while (n > 0) {
    somma += n % 10;    // ultima cifra
    n /= 10;            // la elimina
    cifre++;
}
printf("%d cifre, somma delle cifre: %d\n", cifre, somma);   // 4 cifre, somma 14
```

## 9. Errori comuni

| Errore | Conseguenza |
|---|---|
| `if (x = 5)` invece di `if (x == 5)` | La condizione è sempre vera e `x` viene sovrascritta |
| `;` subito dopo `if (...)`, `while (...)` o `for (...)` | Il blocco tra graffe viene eseguito sempre (con `if`) o una volta sola dopo un ciclo vuoto (con `for`), o il programma si blocca (con `while`) |
| `0 < x < 10` | Condizione sempre vera: si scrive `x > 0 && x < 10` |
| Graffe omesse e seconda istruzione aggiunta | La seconda istruzione è fuori dall'`if` o dal ciclo |
| Contatore o accumulatore non inizializzato | Risultato casuale |
| Variabile della condizione mai modificata nel ciclo | Ciclo infinito |
| `<=` al posto di `<` (o viceversa) nella condizione del `for` | Un'iterazione in più o in meno (errore detto *off by one*) |

:::tip[Simulare il programma a mano]
Quando un ciclo non fa quello che vi aspettate, prendete carta e penna e simulatene l'esecuzione: scrivete una tabella con una colonna per ogni variabile e una riga per ogni iterazione, aggiornando i valori passo dopo passo. In alternativa aggiungete temporaneamente delle `printf` dentro il ciclo per vedere come cambiano le variabili. Quasi sempre l'errore salta subito all'occhio.
:::

## Esercizi

Gli esercizi relativi a questi argomenti si trovano nel capitolo **"Introduzione e strutture di controllo"** dell'eserciziario (sezione *Algoritmi e strutture di controllo*), linkato nella [pagina introduttiva](../programmazione-in-c/).
