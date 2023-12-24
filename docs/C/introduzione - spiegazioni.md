---
layout: default
title: Introduzione e Strutture di Controllo - Spiegazioni
nav_order: 3
parent: Programmazione in C
has_children: False
---

# Introduzione e Strutture di Controllo - Spiegazioni ed Esempi
{: .no_toc}
  
<details open markdown="block">
  <summary>
    Table of contents
  </summary>
  {: .text-delta }
1. TOC
{:toc .toc}
</details>

## Hello world
{: .numerato_da_h3}

Di seguito è riportato il l'esempio che viene sempre proposto come primissimo programma in qualsiasi linguaggio di programmazione. Questo programma che consiste nello stampare sullo schermo una scritta di saluto è utile per capire i primi elementi di base della sintassi del linguaggio. 

```c
#include <stdio.h>

int main() {
    printf("Hello world!");
}
```

Ci sono diverse cose da spiegare di questo semplice codice:
1. Un programma in C deve sempre avere una funzione principale che si chiama *main* e che contiene il codice da eseguire. In seguito si vedrà come inserire altre funzioni oltre a main. Non entriamo qui nel dettaglio della spiegazione della sintassi legata all'uso delle funzioni in C, nota però che prima del nome della funzione è scritto int e subito dopo sono presenti due parentesi tonde che indicano la natura di funzione del main (all'interno delle parentesi vanno i parametri, come in matematica, ad es. f(x)). Tutto il codice della funzione main è racchiuso tra parentesi graffe. Racchiudere il codice tra parentesi graffe indica al computer che esso costituisce un unico blocco di codice che in questo caso appartiene a main.
2. Ogni comando all'interno del main termina con ; che indica che il comando è finito. Il fatto che andiamo a capo prima di scrivere un altro comando è solo una questione di ordine.
3. Ogni volta che si aprono delle parentesi e si va a capo è buona norma *indentare* il codice ovvero aggiungere una tabulazione che sposta il testo a destra di 4 spazi (non premere spazio 4 volte ma premi tab). Il codice deve sempre essere ben ordinato!
4. Per stampare qualcosa sullo schermo, in questo caso sulla console, bisogna usare una funzione che si chiama *printf* (che sta per "print formatted") e che riceve come parametro la stringa da stampare. In seguito vedremo come stampare cose più elaborate.
5. Per poter usare la funzione printf bisogna importare all'inizio del programma la libreria che la contiene. Una libreria è una raccolta di funzioni già fatte che possiamo inserire nei nostri programmi. La libreria che contiene le funzioni per l'input e l'output si chiama *stdio* (standard input output). Per importare la libreria si usa la direttiva per il compilatore *#include* seguita dal nome del file che contiene tutte le funzioni della libreria (in realtà i file con estensione .h contengono le intestazioni delle funzioni ma è un discorso troppo complesso per essere trattato ora). Tutte le direttive per il compilatore vanno scritte prima del resto del codice ed esse vengono eseguite in fase di compilazione, quindi prima che il programma possa essere eseguito.


## Variabili
{: .numerato_da_h3}

```c
#include <stdio.h>

int main() {
    int i1, i2;
    float f1, f2;
    char c1, c2;

    i1 = 12;
    i2 = 5;
    f1 = 5.5;
    f2 = 0.25;
    c1 = 'a';
    c2 = 'c';

    printf("%d + %d = %d \n", i1, i2, i1+i2);
    printf("%d - %d = %d \n", i2, i1, i2-i1);
    printf("%d * %d = %d \n", i1, i2, i1*i2);
    printf("%d / %d = %d \n", i1, i2, i1/i2);
    printf("%d & %d = %d \n", i1, i2, i1%i2);

    printf("\n");

    printf("%d / %f = %f \n", i1, f2, i1/f2);
    printf("%d / %.2f = %.2f \n", i1, f2, i1/f2);
    printf("%d / %g = %g \n", i1, f2, i1/f2);
}
```

Che produce il seguente output:

    12 + 5 = 17 
    5 - 12 = -7 
    12 * 5 = 60 
    12 / 5 = 2 
    12 & 5 = 2 

    12 / 0.250000 = 48.000000 
    12 / 0.25 = 48.00 
    12 / 0.25 = 48 


Si possono fare le seguenti osservazioni:
1. le variabili si differenziano per tipo e all'inizio del programma bisogna dichiarare tipo e nome delle variabili che si vogliono utilizzare in modo che venga riservato loro l'opportuno spazio in memoria. Ricorda che in C la dichiarazione delle variabili è la prima cosa che deve essere fatta nel main (se usi un compilatore C++ esso ti permette di farlo anche dopo). Indicare il tipo serve poi al programma e ad altre funzioni, come ad esempio printf, per conoscere la loro codifica. Ogni tipo è codificato in modo diverso e se printf cerca di stampare un int pensando che sia un float lo stampa male (puoi provare a farlo). Le variabili fondamentali sono:
   1. int: numero intero
   2. float: numero con la virgola
   3. double: numero con la virgola più grande, cioè usa il doppio dei bit per essere rappresentato rispetto al float (da cui il nome)
   4. char: carattere
   5. per indicare le stringhe ovvero sequenze di caratteri si usano array di caratteri, strutture dati particolari che vedremo più avanti, per ora semplifichiamo dicendo che basta scrivere [] dopo il nome della variabile.
2. puoi assegnare un valore alla variabile mentre la dichiari (esempio di seguito), se non lo fai la variabile conterrà i bit precedentemente presenti nella zona di memoria ad essa assegnata, cioè robaccia per noi. In seguito possiamo assegnare un valore nuovo alla variabile quando vogliamo con l'operatore d'assegnamento **=** (da distinguere da == che confronta due variabili)
3. Per stampare il valore di una variabile devo indicare nella stringa passata come parametro a printf il tipo della variabile con l'opportuno simbolo (di seguito l'esempio completo):
   1. int: %d
   2. float: %f
   3. double: %lf
   4. char: %c
   5. stringhe: %s 
4. Si possono stampare le variabili formattandole in modi diversi, in particolare i numeri float per cui è possibile indicare il numero di decimali da stampare (ad esempio per due decimali scrivo %.2f) oppure lasciando al programma il compito di evitare di stampare decimali inutili uguali a 0 con %g
5. la divisione tra due interi produce un risultato intero troncato, per ottenere un float almeno uno dei due numeri coinvolti nella divisione deve essere un float
6. L'operatore % ci fornisce il resto della divisione, è molto utile quando devo verificare se un numero è pari, dispari, multiplo o divisore di quacun altro.
7. Esistono dei caratteri speciali, il primo che devi imparare a conoscere è **\n** che indica di andare a capo. Ne esistono altri meno importanti che forse ti capiterà di vedere. Unica cosa utile da sapere per ora è che siccome le stringhe iniziano e finiscono con le virgolette, se vuoi inserire delle virgolette in una stringa devi scrivere **\\"**. In generale se cerchi di stampare un carattere che per il C è un carattere speciale, come le virgolette che indicano l'inizio e la fine di una stringa, devi scriverlo preceduto da \ in modo che il compilatore capisca che non stai scrivendo un carattere speciale ma un comune carattere.

```c
#include <stdio.h>

int main() {
    int num_intero;
    float num_con_virgola;
    double num_grande_con_virgola = 2.75;
    char lettera = 'a';
    char frase[] = "Ciao a tutti";

    num_intero = 1;
    num_con_virgola = 1.5;

    printf("%d \n", num_intero);
    printf("%f \n", num_con_virgola);
    printf("%lf \n", num_grande_con_virgola);
    printf("%c \n", lettera);
    printf("%s \n", frase);
}
```

che produce il seguente output

    1 
    1.500000 
    2.750000 
    a 
    Ciao a tutti 


Nel seguente esempio invece è mostrato come funziona la funzione scanf (scan formatted) che serve a leggere dati dalla tastiera:

#include <stdio.h>

```c
int main() {
    int a;
    char nome[50];

    printf("Come ti chiami? ");
    scanf("%s", &nome);
    printf("Piacere %s, quanti anni hai? ");
    scanf("%d", &a);
    printf("Davvero? anche io ho %d anni!", a);
}
```

che produce il seguente output (sono incluse anche le cose scritte con la tastiera)

    Come ti chiami? Francesco
    Piacere Francesco, quanti anni hai? 16
    Davvero? anche io ho 16 anni!

Il funzionamento di scanf è analogo a quello di printf, è però presente una differenza importante, le variabili da passare alla funzione perchè vengano modificate vanno scritte precedute dal simbolo **&**. Questo operatore che approfondirai più avanti è indispensabile per la funzione scanf che altrimenti non sarebbe in grado di modificare il valore della variabile. In realtà le stringhe fanno eccezione e possono essere passate anche senza usare la &. Il motivo verrà approfondito in seguito con lo studio delle stringhe e dei puntatori.

## La selezione e gli operatori if - else
{: .numerato_da_h3}

I programmi visti finora sono semplici sequenze di istruzioni che vengono eseguite sempre allo stesso modo. I programmi però devono spesso prendere delle decisioni e decidere se eseguire sequenze alternative di istruzioni. Questa operazione che possiamo chiamare selezione richiede l'istruzione condizionale *if-else*. Di seguito è riportato un esempio di utilizzo di tale istruzione.

```c
#include <stdio.h>

int main() {
    int num, den1, den2;

    num = 5;
    den1 = 2;
    den2 = 0;

    if (den1 != 0) {
        printf("%d / %d = %g \n", num, den1, (float)num/(float)den1);
    } else {
        printf("%d / %d = impossibile! \n", num, den1);
    }

    if (den2 != 0) {
        printf("%d / %d = %g \n", num, den2, (float)num/(float)den2);
    } else {
        printf("%d / %d = impossibile! \n", num, den2);
    }
}
```

La sintassi di questo operatore è piuttosto semplice: if è seguito da una espressione a cui è possibile solo rispondere sì o no (espressioni che restituiscono un valore booleano true o false). Queste domande possono contenere una domanda semplice come un confronto tra due valori (ad esempio *den == 0* che signignifica: den è uguale a 0?) o una espressione logica più complessa che può contenere uguaglianze, disuguaglianze, operatori logici come and, or, not... Di seguito è riportato un esempio con un espressione logica un po' più complessa.

```c
#include <stdio.h>

int main() {
    int a = 12;

    if ((a > 10 && a % 2 != 0) || a % 3 == 0) {
        printf("%d e' maggiore di 10 e dispari, oppure è multiplo di 3", a);
    } else {
        printf("%d non rispetta le condizioni date.");
    }
}
```

gli operatori possibili sono: 

<!-- | operatore | significato       |
|-----------| ------------------|
| <         | minore di         |
| <=        | minore o uguale a |
| \>        | maggiore di | -->

- <  : minore di
- <= : minore o uguale a
- \> : maggiore di
- \>= : maggiore o uguale a
- == : uguale a
- != : diverso da
- \|\| : or (in italiano o)
- && : and (in italiano e)
- !  : non, nega l'espressione successiva

Possono essere indicate direttamente delle variabili il cui valore significa vero o falso, come:
- 1    : indica vero
- 0    : indica falso
- NULL : indica falso

Tutti i valori interpretati come falso vengono detti falsy.

Possono anche essere indicate delle funzioni che restituiscono un certo valore che possa essere interpretato come vero o falso. Può anche essere inserito un assegnamento (=) che verrà eseguito e poi considerato falso se si assegna un valore falsy, vero altrimenti.

C'è un'ultima cosa importante da dire riguardo alle strutture di controllo if-else, cioè che la presenza del comando else non è obbligatoria, sono infatti lecite le seguenti righe di codice:

```c
if (a == 1) {
    printf("a == 1\n");
}
if (a == 2) {
    printf("a == 2\n");
}

if (a != 1) {

} else {
    printf("a == 1\n");
}

```

Notare inoltre che l'ultimo if-else è lecito ed equivale al primo if anche se è dacisamente da preferirsi il primo if.



## Cicli while e for
{: .numerato_da_h3}

Spesso nei programmi capita di dover ripetere le stesse operazioni tante volte, in questo caso si dice che si è in presenza di un ciclo o iterazione (ripetizione). Le istruzioni necessaei a creare i cicli sono il **while** e il **for**. Queste istruzioni permettono di ripetere l'esecuzione di uno stesso blocco di codice fintanto che continua ad essere vera una certa condizione. Di seguito è riportato un esempio:

```c
#include <stdio.h>

int main() {
    int i;
    int n = 10;

    printf("Esempio col while:\n");
    i = 0;
    while (i < n) {
        printf("%d ", i);
        i += 1;
    }

    printf("\n");

    printf("\n\nEsempio equivalente col for:\n");
    for (i = 0; i < n; i += 1) {
        printf("%d ", i);
    }
}
```

Che produce il seguente output:


```
Esempio col while:
0 1 2 3 4 5 6 7 8 9 

Esempio equivalente col for:
0 1 2 3 4 5 6 7 8 9 
```


in questo esempio sono stati utilizzati il while e il for per fare la stessa cosa cioè stampare tutti i numeri da 0 a 9. Dopo aver assegnato alla variabile *i* il valore 0 si sono ripetute le operazioni di stampare *i* e incrementare di 1 il valore di *i*. La condizione che deve essere soddisfatta per entrare nel ciclo è che *i* sia minore di *n* (a cui è stato assegnato il valore 10).

While e for sono del tutto equivalenti ma il for è molto comodo nelle situazioni come questa in cui deve essere fatto un assegnamento iniziale (solitamente un contatore o un indice che ci permette di scorrere un elenco di dati), e un incremento (o decremento) alla fine di ogni ciclo. La sintassi del for ci permette di mettere in un unico posto, assegnamento iniziale, condizione e incremento, cosa molto comoda in molti contesti.

Il while rimane comunque utilizzato in tutti gli altri generici contesti in cui si ha un ciclo, solitamente quando la condizione non dipende dallo scorrere di un contatore o indice.

Il C prevede anche un altro tipo di ciclo: il *do-while* che permette di eseguire le operazioni del ciclo prima del controllo. Questa istruzione però non è così utile tanto che molti linguaggi non la implementano. Per non confondervi troppo all'inizio del vostro percorso di studio della programmazione, lo saltiamo.

In alcuni casi può essere comodo modificare il flusso di esecuzione dei cicli while e for con due nuovi operatori: **break** e **continue**

```c
#include <stdio.h>

int main() {
    int i;

    printf("Esempio col while:\n");
    i = 0;
    while (1) {
        if (i >= 10) {
            break;
        } else {
            printf("%d ", i);
        }
        i++;

        continue;
        printf("Questo non viene eseguito\n");
    }

    printf("\n\nEsempio equivalente col for:\n");
    for (i = 0; 1; i++) {
        if (i >= 10) {
            break;
        } else {
            printf("%d ", i);
        }
    }
}
```

Questo codice produce esattamente lo stesso output di quello precedente ma è scritto con una logica differente. la condizione del while e del for contengono un valore sempre vero per cui si entrerebbe e si rimarrebbe per sempre all'interno del ciclo. All'interno del ciclo però viene inserito il comando *break* che fa in modo che non appena viene eseguito, il programma esce dal ciclo.

Un altro comando un po meno usato è il comando continue che permette di terminare l'esecuzione del ciclo corrente e di passare al successivo (motivo per cui nel codice di esempio il printf della riga seguente al continue non viene mai eseguito).

Sebbene l'esistenza di questi due comandi non sia strettamente necessaria piochè si possono fare le stesse cose con un corretto uso delle strutture di controllo while, for e if-else, in alcuni contesti questi comandi sono molto comodi (specialmente in un contesto ad eventi, ad esempio un gioco in cui succede sempre la stessa cosa finchè non viene premuto qualcosa).
