---
layout: default
title: Introduzione
nav_order: 1
parent: Eserciziario C
grand_parent: Programmazione in C
has_children: False
---

# Introduzione e Strutture di Controllo
{: .no_toc}
  
* TOC
{:toc}

## Esempi di base

### Hello world
Di seguito è riportato il l'esempio che viene sempre proposto come primissimo programma in qualsiasi linguaggio di programmazione. Questo programma che consiste nello stampare sullo schermo una scritta di saluto è utile per capire i primi elementi di base della sintassi del linguaggio. 

```c
#include <stdio.h>

int main() {
    printf("Hello world!");
}
```

La prima cosa da dire è che un programma in C deve sempre avere una funzione principale che si chiama *main* e che contiene il codice da eseguire. In seguito si vedrà come inserire altre funzioni oltre a main.

La seconda cosa è che per stampare qualcosa sullo schermo, in questo caso sulla console, bisogna usare una funzione che si chiama *printf* (che sta per "print formatted") e che riceve come parametro la stringa da stampare. In seguito vedremo come stampare cose più elaborate.

Infine va detto che per poter usare la funzione printf bisogna importare all'inizio del programma la libreria che la contiene. Una libreria è una raccolta di funzioni già fatte che possiamo inserire nei nostri programmi. La libreria che contiene le funzioni per l'input e l'output si chiama *stdio* (standard input output). Per importare la libreria si usa la direttiva per il compilatore *#include* seguita dal nome del file che contiene le intestazioni (per ora accontentati di sapere che sono le indicazioni generali sul loro funzionamento) di tutte le funzioni della libreria.


### Variabili

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

    12 + 5 = 17 
    5 - 12 = -7 
    12 * 5 = 60 
    12 / 5 = 2 
    12 & 5 = 2 

    12 / 0.250000 = 48.000000 
    12 / 0.25 = 48.00 
    12 / 0.25 = 48 


Si possono fare le seguenti osservazioni:
1. le variabili si differenziano per tipo e all'inizio del programma bisogna dichiarare tipo e nome delle variabili che si vogliono utilizzare in modo che venga riservato loro l'opportuno spazio in memoria. Indicare il tipo serve poi al programma e ad altre funzioni, come ad esempio printf, per conoscere la loro codifica. Ogni tipo è codificato in modo diverso e se printf cerca di stampare un int pensando che sia un float lo stampa male (puoi provare a farlo). Le variabili fondamentali sono:
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
7. Esistono dei caratteri speciali, il primo che devi imparare a conoscere è **\n** che indica di andare a capo. Ne esistono altri meno importanti che forse ti capiterà di vedere. Unica cosa utile da sapere per ora è che siccome le stringhe iniziano e finiscono con le virgolette, se vuoi inserire delle virgolette in una stringa devi scrivere **\\"**.

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


