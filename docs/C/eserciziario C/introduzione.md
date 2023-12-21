---
layout: default
title: Introduzione e Strutture di Controllo
nav_order: 1
parent: Eserciziario C
grand_parent: Programmazione in C
has_children: False
---

# Introduzione e Strutture di Controllo
{: .no_toc}
  
<details open markdown="block">
  <summary>
    Table of contents
  </summary>
  {: .text-delta }
1. TOC
{:toc .toc}
</details>



## Esempi base e spiegazioni
{: .azzera_numerazione_h3}

### Hello world
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
5. Per poter usare la funzione printf bisogna importare all'inizio del programma la libreria che la contiene. Una libreria è una raccolta di funzioni già fatte che possiamo inserire nei nostri programmi. La libreria che contiene le funzioni per l'input e l'output si chiama *stdio* (standard input output). Per importare la libreria si usa la direttiva per il compilatore *#include* seguita dal nome del file che contiene tutte le funzioni della libreria (in realtà i file con estensione .h contengono le intestazioni delle funzioni ma è un discorso troppo complesso per essere trattato ora).


### Variabili
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

### La selezione e gli operatori if - else
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



### Cicli while e for
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

## Esercizi
{: .azzera_numerazione_h3}

### Circonferenza 
{: .numerato_da_h3}

Data in input l’area del cerchio, stampare la circonferenza

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <math.h>
#include <stdio.h>

int main() {
    float cerchio, circonferenza, raggio;

    printf("Scrivi quanto misura l'area del cerchio: ");
    scanf("%f", &cerchio);

    raggio = sqrt(cerchio / 3.14);
    circonferenza = 2 * 3.14 * raggio;

    printf("Il cerchio con area %.2f ha un raggio che misura %.2f e una circonferenza che misura %.2f \n",
           cerchio, raggio, circonferenza);
}
```

</details> 



### Area del triangolo 
{: .numerato_da_h3}

Data la base e l’altezza di un triangolo, scrivere l’area 


<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    float base, altezza, area;

    printf("Scrivi la base: ");
    scanf("%f", &base);
    printf("Scrivi l'altezza: ");
    scanf("%f", &altezza);

    area = base * altezza / 2;

    printf("L'area misura %.2f", area);
}
```

</details> 



### Operazioni 
{: .numerato_da_h3}

Dati in input due numeri, scrivi il risultato di tutte le operazioni che è possibile fare con i due numeri (somma, sottrazione, moltiplicazione, divisione, resto della divisione)

### Approssimazioni 
{: .numerato_da_h3}

Dato un numero decimale, ottieni e stampa:

1. valore intero approssimato per difetto;
2. valore intero approssimato per eccesso;
3. valore intero approssimato in maniera intelligente;
4. approssimazione del numero al secondo decimale;
5. valore assoluto del numero.

### Input e output stringhe
{: .numerato_da_h3}

Leggi 3 parole e stampale tutte insieme in un'unica volta (solo un parallelogramma di scrittura).


### Divisione con condizione 
{: .numerato_da_h3}

Dati due numeri calcolare il loro quoziente se il divisore è != 0, ritornare “impossibile” se il divisore = 0

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    float a,b,c;
    printf("Scrivi il primo numero: ");
    scanf("%f", &a);
    printf("Scrivi il secondo numero: ");
    scanf("%f", &b);
    if (b != 0) {
        c = a / b;
        printf("%g", c);
    } else {
        printf("Non e' possibile dividere per 0\n");
    }
}
```

</details> 




### Sequenze crescenti e decrescenti
{: .numerato_da_h3}

Dato in input un numero:
1.	Stampa i numeri da 1 a quel numero
2.	Stampa i numeri da quel numero a 0 (conto alla rovescia)


<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int n, i;

    // input - versione col while
    printf("Scrivi un numero positivo: ");
    scanf("%d", &n);
    while (n <= 0) {
        printf("Il numero non è positivo, riscrivilo: ");
        scanf("%d", &n);
    }

    // input - versione col do-while
    do {
        printf("Scrivi un numero positivo: ");
        scanf("%d", &n);
    } while (n <= 0);

    // 1.   Stampa i numeri da 1 a quel numero
    for (i = 1; i <= n; i++) {
        printf("%d ", i);
    }

    printf("\n");
    
    // 2.   Stampa i numeri da quel numero a 0 (conto alla rovescia)
    for (i = n; i >= 0; i--) {
        printf("%d ", i);
    }
}
``` 

</details> 


### Sequenze pari
{: .numerato_da_h3}

Dato in input un numero positivo, stampa tutti i numeri pari minori di quel numero

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int n, i;

    printf("Scrivi un numero positivo: ");
    scanf("%d", &n);
    while (n <= 0) {
        printf("Il numero inserito e' negativo, scrivi un numero positivo: ");
        scanf("%d", &n);
    }

    // primo metodo
    for (i = 1; i < n; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }

    printf("\n");
    
    // secondo metodo
    for (i = 2; i < n; i+=2) {
        printf("%d ", i);
    }
}

```

</details> 

### Trova potenza di 2
{: .numerato_da_h3}

Dato in input un numero n, stampa la prima potenza di 2 maggiore o uguale a n

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int n, ris;

    printf("Scrivi un numero: ");
    scanf("%d", &n);

    ris = 1;
    while (ris < n) {
        ris *= 2;
    }

    printf("%d", ris);
}
```

</details> 

### Moltiplicazione con le somme
{: .numerato_da_h3}

Moltiplicazione di due numeri senza usare l’operatore *


<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int a, b, ris, i;

    a = 3;
    b = 5;

    ris = 0;

    for (i = 0; i < b; i++) {
        ris += a;
    }

    printf("%d * %d = %d", a, b, ris);
}
```

</details> 

### Divisione con le differenze
{: .numerato_da_h3}

Divisione di due numeri interi senza usare l’operatore di divisione

Variante: stampa anche il resto


<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int num, den, resto, risultato;

    do {
        printf("Scrivi il numeratore (positivo): ");
        scanf("%d", &num);
    } while (num < 0);

    do {
        printf("Scrivi il denominatore (positivo): ");
        scanf("%d", &den);
    } while (den <= 0);

    resto = num;
    for (risultato = 0; resto >= den; risultato += 1) {
        resto -= den;
    }

    printf("%d / %d = %d  con resto %d\n", num, den, risultato, resto);
}
```

</details> 

### Sequenze crescenti e decrescenti 2
{: .numerato_da_h3}

dati dall'utente due numeri interi n1 e n2 il programma deve stampare:
1.	tutti i numeri dal più piccolo dei due al più grande dei due
2.	tutti i numeri dal più grande dei due al più piccolo dei due
3.	tutti i numeri da n1 a n2 (comunque siano n1 e n2 quindi potresti dover andare in ordine crescente o decrescente)
4.	tutti i numeri da n2 a n1 (comunque siano n1 e n2 quindi potresti dover andare in ordine crescente o decrescente)

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int n1, n2, min, max, i;

    n1 = 12;
    n2 = 5;

    // a.   tutti i numeri dal più piccolo dei due al più grande dei due

    if (n1 < n2) {
        min = n1;
        max = n2;
    } else {
        max = n1;
        min = n2;
    }

    for (i = min; i <= max; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // b.   tutti i numeri dal più grande dei due al più piccolo dei due
    for (i = max; i >= min; i--) {
        printf("%d ", i);
    }
    printf("\n");

    // c.   tutti i numeri da n1 a n2 (comunque siano n1 e n2 quindi potresti dover andare in ordine crescente o decrescente)
    if (n1 < n2) {
        for (i = n1; i <= n2; i++) {
            printf("%d ", i);
        }
    printf("\n");
    } else {
        for (i = n1; i >= n2; i--) {
            printf("%d ", i);
        }   
    }
    printf("\n");

    // d.   tutti i numeri da n2 a n1 (comunque siano n1 e n2 quindi potresti dover andare in ordine crescente o decrescente)
    if (n2 < n1) {
        for (i = n2; i <= n1; i++) {
            printf("%d ", i);
        }
    printf("\n");
    } else {
        for (i = n2; i >= n1; i--) {
            printf("%d ", i);
        }   
    }
    printf("\n");
}
```

</details> 

### Conta numeri inseriti diversi da 0
{: .numerato_da_h3}

Inserire n numeri != 0 (0 per finire), contare quanti sono i numeri inseriti

Variante avanzata: i numeri sono voti che devono essere validi e alla fine ne va calcolata la media.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione base
  </summary>
  {: .text-delta }

```c
int main() {
    int n, numero;

    // for (n = 0; numero != 0;) {
    //     printf("Scrivi il %d° numero: ");
    //     scanf("%d", numero);
    //     if (numero != 0) {
    //         n++;
    //     }
    // }

    // for (n = 0; numero != 0; n++) {
    //     printf("Scrivi il %d° numero: ");
    //     scanf("%d", numero);
    //     if (numero == 0) {
    //         break;
    //     }
    // }

    for (n = 0; 1; n++) {
        printf("Scrivi il %d numero: ", n+1);
        scanf("%d", &numero);
        if (numero == 0) {
            break;
        }
    }

    printf("Hai inserito %d numeri.\n\n", n);

}
```

</details> 

### Triangolo dati i lati
{: .numerato_da_h3}

Dati tre numeri reali dire che tipo di triangolo essi formano (classificazione dei triangoli in base ai lati).

### Somma dei pari e prodotto dei dispari
{: .numerato_da_h3}

Data una sequenza di n numeri interi (valore di n dato dall’utente), calcolare la somma dei pari ed il prodotto dei dispari 

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int n, somma, prodotto, i, numero;

    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &n);
    while (n <= 0) {
        printf("Il valore non puo' essere negativo.");
        printf("Quanti numeri vuoi inserire? ");
        scanf("%d", &n);
    }

    somma = 0;
    prodotto = 1;
    for (i = 0; i < n; i++) {
        printf("Scrivi un numero positivo: ");
        scanf("%d", &numero);
        while (numero < 0) {
            printf("Scrivi un numero positivo: ");
            scanf("%d", &numero);
        }

        if (numero % 2 == 0) {
            somma += numero;
        } else {
            prodotto *= numero;
        }
    }

    printf("Somma dei pari: %d\n", somma);
    printf("Prodotto dei dispari: %d\n", prodotto);
}
```

</details> 

### Confronto due numeri
{: .numerato_da_h3}

Dati due numeri, determinare il maggiore (verificare anche se sono uguali)

### Input sequenza non 0 e conteggio numeri inseriti
{: .numerato_da_h3}

Data una sequenza di numeri terminata da 0, dire quanti sono i numeri inseriti (diversi da 0)

### Input con controllo e conteggio numeri compresi
{: .numerato_da_h3}

Con un opportuno ciclo chiedere all’utente di inserire due numeri n1 e n2 compresi tra 1 e 100. Se i numeri non fossero corretti, rimanere nel ciclo e ripetere la richiesta. Stampare quanti sono i numeri pari compresi tra i due numeri

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int n1, n2, ris, i, tmp;

    do {
        printf("Scrivi due numeri compresi tra 1 e 100: ");
        scanf("%d %d", &n1, &n2);
    } while (n1 < 1 || n1 > 100 || n2 < 1 || n2 > 100);

    if (n1 > n2) {
        tmp = n1;
        n1 = n2;
        n2 = tmp;
    }

    // metodo 1
    ris = 0;
    for (i = n1; i <= n2; i++) {
        if (i%2==0) {
            ris++;
        }
    }
    printf("I numeri pari compresi tra %d e %d sono %d\n", n1, n2, ris);

    // metodo 2
    ris = 0;
    i = n1;
    if (i % 2 == 1) {
        i++;
    }
    for (;i <= n2; i += 2) {
        ris++;
    }
    printf("I numeri pari compresi tra %d e %d sono %d\n", n1, n2, ris);

    // metodo 3
    ris = (n2-n1) / 2;
    if (n1 % 2 == 0 || n2 % 2 == 0) {
        ris++;
    }

    printf("I numeri pari compresi tra %d e %d sono %d", n1, n2, ris);
}
```

</details> 


### Input sequenza non 0 e stampa massimo e minimo
{: .numerato_da_h3}

Data una sequenza di numeri terminata dal numero 0 (leggo numeri finchè non mi viene dato il numero 0), stampo il maggiore e il minore

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int num, max, min;

    printf("Scrivi un numero (0 per terminare): ");
    scanf("%d", &num);
    min = num;
    max = num;

    while (num != 0) {
        printf("Scrivi un numero (0 per terminare): ");
        scanf("%d", &num);
        if (num > max) {
            max = num;
        }
        if (num < min) {
            min = num;
        }
    }

    printf("I valori minimi e massimi inseriti sono: %d %d\n", min, max);
}
```

</details> 


### Fattoriale
{: .numerato_da_h3}

Letto un numero intero positivo n stampare il fattoriale: n! = 1 · 2 · 3 · . . . ·n

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int n, i;
    long long f;

    do {
        printf("Scrivi un numero positivo: ");
        scanf("%d", &n);
    } while (n < 0);

    f = 1;
    // for (i = 2; i <= n; i++) {
    for (i = n; i > 0; i--) {
        f *= i;
    }

    printf("%d! = %lld\n\n", n, f);
}
```

</details> 

Usando i double si riesce a rappresentare numeri molto grandi perché il double (come il float ma usa più byte) usa una notazione scietifica

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <float.h>

int main() {
    int i;
    double n;
    double f;

    do {
        printf("Scrivi un numero positivo: ");
        scanf("%lf", &n);
    } while (n < 0);

    f = 1;
    // for (i = 2; i <= n; i++) {
    for (i = n; i > 0; i--) {
        f *= i;
    }

    printf("%.0lf! = %e\n\n", n, f);
}
```

</details> 

### Ordinamento 3 numeri
{: .numerato_da_h3}

Dati in input 3 numeri, stamparli in ordine crescente

### Calcolatrice
{: .numerato_da_h3}

Realizzare un programma che, presi in input 2 operandi reali e un operatore (+, -, *, /), esegue l’operazione stampandone il risultato

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int a, b;
    char op;

    printf("Scrivi l'operazione da fare: ");
    scanf("%d %c %d", &a, &op, &b);

    if (op == '+') {
        printf("%d %c %d = %d", a, op, b, a+b);
    } else if (op == '-') {
        printf("%d %c %d = %d", a, op, b, a-b);
    } else if (op == '*') {
        printf("%d %c %d = %d", a, op, b, a*b);
    } else if (op == '/') {
        printf("%d %c %d = %d", a, op, b, a/b);
    } else {
        printf("Non riconosco l'operazione da fare.");
    }
}
```

</details> 


### Input sequenza non 0, prodotto positivi e somma negativi
{: .numerato_da_h3}

Progettare un algoritmo che legga da terminale una sequenza di interi positivi e negativi terminati dal valore 0 (uno su ogni linea) e stampi il prodotto degli interi positivi e la somma dei negativi.


### Input sequenza con domanda, prodotto positivi, somma negativi
{: .numerato_da_h3}

Progettare un algoritmo che legga da terminale una sequenza di interi positivi e negativi fintanto che l’utente dice di volerne inserire ancora, e stampi il prodotto degli interi positivi e la somma dei negativi.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int numero, risposta, somma, prodotto;

    somma = 0;
    prodotto = 1;
    while (1) {
        printf("Vuoi inserire un numero? (0 per no, altro numero per sì): ");
        scanf("%d", &risposta);
        if (risposta == 0) {
            break;
        }
        printf("Scrivi il numero: ");
        scanf("%d", &numero);
        if (numero >= 0) {
            prodotto *= numero;
        } else {
            somma += numero;
        }
    }

    printf("Prodotto dei positivi: %d\n", prodotto);
    printf("Somma dei negativi: %d\n", somma);
}
```

</details> 

Oppure

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int numero, risposta, somma, prodotto;

    somma = 0;
    prodotto = 1;

    printf("Vuoi inserire un numero? (0 per no, altro numero per sì): ");
    scanf("%d", &risposta);

    // while (risposta != 0) {
    while (risposta) {
        printf("Scrivi il numero: ");
        scanf("%d", &numero);
        if (numero >= 0) {
            prodotto *= numero;
        } else {
            somma += numero;
        }

        printf("Vuoi inserire un numero? (0 per no, altro numero per sì): ");
        scanf("%d", &risposta);
    }

    printf("Prodotto dei positivi: %d\n", prodotto);
    printf("Somma dei negativi: %d\n", somma);
}
```

</details> 


### Elevamento a potenza con le moltiplicazioni
{: .numerato_da_h3}

Dati due numeri in input b ed e, calcola e scrivi b^e senza usare la funzione pow.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int b, e, i;
    double ris;

    b = 2;
    e = 100;
    ris = 1;
    for (i = 0; i < e; i++) {
        ris *= b;
    }
    printf("%d^%d = %g", b, e, ris);
}
```

</details> 

### Input con controllo e confronto orari
{: .numerato_da_h3}

Dati in ingresso 4 numeri, che rappresentano gli orari in cui avvengono due diversi eventi della giornata, in modo che i primi 2 numeri siano ore e minuti del primo orario e gli altri 2 numeri siano ore e minuti del secondo orario, stabilire quale evento è avvenuto prima. Inserisci dei controlli durante l’input in modo che le ore possano andare da 0 a 23 e i minuti da 0 a 59.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int h1, m1, h2, m2;
    printf("Scrivi h1: ");
    scanf("%d", &h1);
    while (h1 < 0 || h1 > 23) {
        printf("Valore non valido, reinserisci: ");
        scanf("%d", &h1);
    }
    printf("Scrivi m1: ");
    scanf("%d", &m1);
    while (m1 < 0 || m1 > 59) {
        printf("Valore non valido, reinserisci: ");
        scanf("%d", &m1);
    }
    printf("Scrivi h2: ");
    scanf("%d", &h2);
    while (h2 < 0 || h2 > 23) {
        printf("Valore non valido, reinserisci: ");
        scanf("%d", &h2);
    }
    printf("Scrivi m1: ");
    scanf("%d", &m2);
    while (m2 < 0 || m2 > 59) {
        printf("Valore non valido, reinserisci: ");
        scanf("%d", &m2);
    }

    if (h1 > h2 || (h1 == h2 && m1 > m2)) {
        printf("%d:%d > %d:%d", h1,m1,h2,m2);
    } else if (h1 == h2 && m1 == m2) {
        printf("%d:%d = %d:%d", h1,m1,h2,m2);
    } else {
        printf("%d:%d < %d:%d", h1,m1,h2,m2);
    }
}
```

</details> 

### Input minuti, secondi e conto alla rovescia
{: .numerato_da_h3}

Dato un numero di minuti e un numero di secondi rappresentare il conto alla rovescia.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    int m, s;
    m = 1;
    s = 5;

    while (m > 0 || s > 0) {
        printf("%02d:%02d\n", m, s);
        s--;
        if (s < 0) {
            m--;
            s = 59;
        }
        sleep(1);
    }
}
```

</details> 

### Successione di Fibonacci
{: .numerato_da_h3}

Dato in input un numero intero n, stampa l’ennesimo numero della successione di fibonacci. La successione di fibonacci è quella successione di numeri in cui ogni numero è la somma dei due numeri precedenti. I primi due numeri sono 1 1. La successione inizia così: 1 1 2 3 5 8 13 21 …

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int prec1, prec2, ris, n, i;

    do {
        printf("Scrivi un numero >= 0: ");
        scanf("%d", &n);
    } while (n < 0);

    if (n == 0) {
        ris = 0; // Fib(0)
    } else {
        prec2 = 0;
        prec1 = 1;
        ris = 1; // che è sia Fib(1) che Fib(2)

        for (i = 2; i < n; i++) {
            prec2 = prec1;
            prec1 = ris;
            ris = prec1 + prec2;
        }
    }

    printf("Fib(%d) = %d", n, ris);
}
```

</details> 

### Conteggio cifre di un numero
{: .numerato_da_h3}

2.1.25	Dato in input un numero intero, conta da quante cifre è composto.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <math.h>

int main() {
    int n, cifre, tmp;
    n = -235;
    cifre = 1;
    tmp = abs(n);
    while (tmp >= 10) {
        tmp /= 10;
        cifre++;
    }
    printf("%d e' composto da %d cifre.\n", n, cifre);
}
```

</details> 


### Stampa cifre di un numero (numero noto di cifre)
{: .numerato_da_h3}

Dato in input un numero intero n di 3 cifre (in questo caso sarebbe utile mettere un controllo sull’input, cioè continuare a richiedere il numero fintanto che il numero dato non è di 3 cifre), stampa separatamente le sue cifre. Consiglio: usa divisioni per 10 e resti della divisione per 10. Puoi provare anche a generalizzare il programma in modo che funzioni anche con numeri di dimensione diversa da 3 cifre. 

### Stampa cifre di un numero
{: .numerato_da_h3}

Dato in input un numero intero qualsiasi, stampa separatamente le sue cifre.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int cifra, ncifre, tmp, potenza;
    int n = -234, i;
    ncifre = 1;
    tmp = abs(n);
    while (tmp >= 10) {
        tmp /= 10;
        ncifre++;
    }
    // printf("%d", ncifre);
    tmp = abs(n);
    while (ncifre > 0) {
        potenza = 1;
        for (i = 0; i < ncifre-1; i++) {
            potenza *= 10;
        }
        // printf("potenza %d\n", potenza);
        cifra = tmp / potenza;
        printf("%d ", cifra);
        tmp = tmp % potenza;
        ncifre--;
    }
}
```

</details> 


### Controllo primalità di un numero
{: .numerato_da_h3}

Dato in input un numero intero n, stabilisci se è primo

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int n = 23, i, primo;

    primo = 1;
    for (i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            primo = 0;
        }
    }

    if (primo) {
        printf("%d e' primo.", n);
    } else {
        printf("%d non e' primo.", n);
    }  
}
```

</details> 

### Scomposizione in fattori primi
{: .numerato_da_h3}

Dato in input un numero intero n, stampa la sua scomposizione in fattori primi

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int n, val, div;

    do {
        printf("Inserisci un numero positivo: ");
        scanf("%d", &n);
    } while (n <= 0);

    val = n;
    div = 2;
    while (val >= div) {
        while (val % div == 0) {
            printf("%d ", div);
            val /= div;
        }
        div++;
    }
}
```

</details> 

### Input sequenza lunga n, stampa massimo, minimo, media
{: .numerato_da_h3}

Data una sequenza di n numeri (n dato dall’utente) stabilire qual è il numero più grande, qual è il più piccolo e calcolare la media.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int n, i;
    float media, numero, min, max;

    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &n);
    while (n < 1) {
        printf("Devi inserirne almeno 1, reinserisci:  ");
        scanf("%d", &n);   
    }

    printf("Inserisci un numero: ");
    scanf("%f", &numero);
    min = numero;
    max = numero;
    media = numero;

    for (i = 1; i < n; i++) {
        printf("Inserisci un numero: ");
        scanf("%f", &numero);
        if (numero < min) min = numero;
        if (numero > max) max = numero;
        media += numero;
    }
    media /= n;

    printf("Minimo: %.2f\n", min);
    printf("Massimo: %.2f\n", max);
    printf("Media: %.2f\n", media);
}
```

</details> 

### Input sequenza lunga n, stampa secondo più grande e secondo più piccolo
{: .numerato_da_h3}

Data una sequenza di n numeri (n dato dall’utente) stabilire qual è il secondo numero più grande, qual è il secondo più piccolo.

### Input sequenza non 0, stampa maggior differenza numeri consecutivi
{: .numerato_da_h3}

Data una sequenza di numeri positivi (fai il controllo sull’input) terminati da 0, scrivi qual è la maggior differenza tra due numeri dati consecutivamente

### Input sequenza non 0, somma multipli di 3
{: .numerato_da_h3}

Data una sequenza di numeri positivi (fai il controllo sull’input) terminati da 0, scrivi la somma dei numeri divisibili per 3

### somma e prodotto sequenza
{: .numerato_da_h3}

Dato un numero n scrivi somma e prodotto di tutti i numeri minori o uguali a n.

### Conteggio divisibilità per 2
{: .numerato_da_h3}

Dato un numero n stabilire quante volte è possibile dividerlo per 2. (esempio 20 è divisibile per 2, 2 volte)

### Calcolo spesa con sconti
{: .numerato_da_h3}

Data una sequenza di prezzi di prodotti, calcolare la spesa totale sapendo che se un prodotto costa meno di 100€ lo devo scontare del 10% altrimenti del 5%. Decidi tu il metodo per capire quando terminare la lettura della sequenza di prezzi.

### Promosso, rimandato o bocciato
{: .numerato_da_h3}

Data una sequenza di 5 numeri che rappresentano i voti presi nelle diverse materie, stabilire se lo studente sarà promosso, bocciato o rimandato a settembre. Lo studente è promosso se non ha insufficienze, è bocciato se ha almeno 3 insufficienze, altrimenti è rimandato. Ricordati di controllare i valori dei voti in input che devono essere voti validi.

### Stampa sequenze e multipli
{: .numerato_da_h3}

Dato un numero n positivo stampa tutti i numeri da 1 a n, i primi n multipli di 2 (2 compreso che consideri il primo multiplo) e i primi n multipli di 3

### Terna pitagorica
{: .numerato_da_h3}

Dati tre numeri positivi verificare che questi tre numeri siano una terna pitagorica ( una terna pitagorica è un insieme di 3 numeri per cui la somma del quadrato di due numeri sia uguale al quadrato del terzo numero, in altre parole sono le lunghezze dei lati di un triangolo rettangolo)

### Calcolo spesa con sconti 2
{: .numerato_da_h3}

Scrivere l’algoritmo per il pagamento della spesa che consiste nel chiedere inizialmente se si è in possesso della carta fedeltà, poi chiedere tutti i prezzi dei prodotti acquistati terminando la sequenza con un prezzo uguale a zero. Il programma deve sommare i prezzi, e se si è in possesso della carta, scontare del 10% i prezzi minori di 50 e del 5% i prezzi maggiori di 50

### Restituzione in biblioteca
{: .numerato_da_h3}

Un libro deve essere restituito in biblioteca dopo 15 giorni di prestito altrimenti si è multati di 0,80€ al giorno di ritardo. Ricevuto in ingresso il numero di giorni di un prestito, visualizza se il socio deve essere multato per il ritardo e a quanto ammonta la multa da pagare.

### Calcolo bolletta
{: .numerato_da_h3}

Calcolare il costo della bolletta telefonica sapendo che i primi 30 scatti costano 20 centesimi l’uno, gli scatti dal 31 al 100 costano 15 centesimi l’uno, mentre gli ulteriori scatti costano 10 centesimi l’uno. Aggiungere infine una tassa fissa di 2,50€ per le spese telefoniche. In input al programma è dato il numero di scatti effettuati.

### Indovina il numero segreto
{: .numerato_da_h3}

Costruire uno schema di flusso che rappresenti l’algoritmo per il seguente gioco: il computer genera un numero segreto (usa la funzione random(100) che genera un numero casuale tra 0 e 99) e il giocatore deve individuarlo seguendo le indicazioni fornite dal computer (ti dice se il numero da trovare è più grande o più piccolo di quello che hai provato); una volta trovato il numero segreto, il numero di tentativi effettuati è visualizzato a video.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int segreto, tentativo;

    srand(time(NULL));

    segreto = rand() % 100;

    while (1) {
        printf("Indovina il numero (da 0 a 99): ");
        scanf("%d", &tentativo);

        if (tentativo < segreto) {
            printf("Il numero da trovare e' piu' grande.\n");
        } else if (tentativo > segreto){
            printf("Il numero da trovare e' piu' piccolo.\n");
        } else {
            printf("Hai indovinato!\n");
            break;
        }
    }
}
```

</details> 

### Quoziente e resto con le differenze
{: .numerato_da_h3}

Calcolare il quoziente e il resto della divisione intera di due numeri interi positivi forniti in ingresso chiamati dividendo e divisore, applicando il metodo delle sottrazioni successive. Per esempio, se dividendo=13 e divisore=5, il programma dovrà restituire Quoziente=2 e Resto=3, calcolati sottraendo successivamente il valore di divisore dal valore di dividendo

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int num, den, quoz, resto;

    num = 13;
    den = 3;

    for (resto = num, quoz = 0; resto >= den; quoz++) {
        resto -= den;
    }

    resto = num;
    quoz = 0;
    while (resto >= den) {
        resto -= den;
        quoz += 1;
    }

    printf("%d : %d = %d resto %d\n", num, den, quoz, resto);
}
```

</details> 

### Successione di Fibonacci 2
{: .numerato_da_h3}

Visualizza i termini della successione di Fibonacci compresi nell’intervallo tra due interi positivi N1 e N2, entrambi forniti in ingresso, con N2>N1 (controlla bene gli input) 

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int n1, n2, i, prec1, prec2, fib;

    do {
        printf("Inserisci un numero positivo: ");
        scanf("%d", &n1);
    } while (n1 < 1);
    do {
        printf("Inserisci un numero positivo maggiore di %d: ", n1);
        scanf("%d", &n2);
    } while (n2 <= n1);

    prec2 = 1;
    prec1 = 1;
    fib = 2;

    if (n1 == 1) {
        printf("1 1 ");
    }

    for (i = n1; fib <= n2; i++) {
        if (fib >= n1 && fib <= n2) {
            printf("%d ", fib);
        } 
        
        fib = prec1 + prec2;
        prec2 = prec1;
        prec1 = fib; 
    }
}
```

</details> 

### Calcolo probabilità dado
{: .numerato_da_h3}

Simula il lancio di un dado per N volte (con N intero e positivo in ingresso e usando la funzione random(7) per il lancio) e verifica che effettivamente la probabilità che esca 6 è 1/6. Per farlo fai tanti tiri e vedi se esce 6 un sesto delle volte (più tiri fai più dovresti avere un risultato positivo).

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
int main() {
    int n, dado, i;
    float prob;

    srand(time(NULL));

    n = 100000;
    prob = 0;
    for (i = 0; i < n; i++) {
        dado = rand() % 6 + 1;
        if (dado == 6) {
            prob += 1;
        }
    }

    prob /= n;

    printf("La probabilita' che esca 6 e' %.3f%%.\n", prob*100);
    printf("1/6=%.5f", 1.0/6.0);
}
```

</details> 

### Calcolo probabilità dadi
{: .numerato_da_h3}

Simula il lancio di due dadi e verifica le probabilità che escano: una coppia di 6, un valore totale uguale a 7 (due diverse probabilità) 

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int nlanci, dado1, dado2, i;
    float prob1, prob2;

    srand(time(NULL));

    prob1 = 0;
    prob2 = 0;
    nlanci = 100000;

    for (i = 0; i < nlanci; i++) {
        dado1 = rand() % 6 + 1;
        dado2 = rand() % 6 + 1;

        if (dado1 == 6 && dado2 == 6) {
            prob1 += 1;
        }
        if (dado1 + dado2 == 7) {
            prob2 += 1;
        }
    }

    prob1 /= nlanci;
    prob2 /= nlanci;

    printf("Probabilita che esca coppia di 6: %.2f%%\n", prob1*100);
    printf("Probabilita che esca somma 7: %.2f%%\n", prob2*100);
}
```

</details> 

### Sequenza numeri con condizioni
{: .numerato_da_h3}

Dati in ingresso due numeri positivi x e y, visualizza in ordine decrescente la sequenza di numeri interi compresi tra x e y che sono divisibili per il minore tra x e y. Ad esempio, se x = 7 e y = 35, la sequenza è 35 28 21 14 7.


<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int x, y, i, min, max;
    
    do {
        printf("Inserisci il primo numero, deve essere positivo: ");
        scanf("%d", &x);
    } while (x <= 0);
    do {
        printf("Inserisci il secondo numero, deve essere positivo: ");
        scanf("%d", &y);
    } while (y <= 0);

    if (x < y) {
        min = x;
        max = y;
    } else {
        min = y;
        max = x;
    }

    for (i = max; i >= min; i--) {
        if (i % min == 0) {
            printf("%d ", i);
        }
    }
}
```

</details> 


### Calcolo probabilità dado 2
{: .numerato_da_h3}

Simula una serie di lanci di un dado a 6 facce (d6) e un dado da 20 facce (d20). Calcola il valore medio che si ottiene lanciando il d6 e quello ottenuto lanciando il d20.

### Calcolo probabilità dadi 2
{: .numerato_da_h3}

Valuta se è più probabile ottenere 7 oppure ottenere 8 lanciando 2 dadi da 6 e sommando i 2 valori ottenuti.

### Calcolo probabilità dadi 3
{: .numerato_da_h3}

Voglio valutare la probabilità che tirando due dadi da 6 esca il valore 2. Il valore calcolato deve essere abbastanza preciso e decido di calcolarlo misurando la media di tanti tiri di dado e fermandomi solo quando vedo che facendo uscire un nuovo 2 valore calcolato non varia di più di 0,01%

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tiro, ntiri = 0, ndue = 0;
    float prob = 0, prec = 0, diff;
    float soglia = 0.0000001;

    srand(time(NULL));

    while (1) {
        tiro = rand() % 6 + 1 + rand() % 6 + 1; // rand() % (max-min+1) + min
        ntiri++;

        prec = prob;
        if (tiro == 2) {
            ndue++;
            prob = (float)ndue/(float)ntiri;

            diff = prob-prec;
            // if (diff < 0) diff * -1;
            // printf("%f - %f = %f\n", prob, prec, diff);
            if (diff < soglia && diff > -soglia) {
                break;
            }
        }
        printf("%d - %2d: %f\n", ntiri, tiro, prob);
    }

    printf("%f", prob);
}
```

</details> 


### Input sequenza lunga n, calcolo media condizionale
{: .numerato_da_h3}

Vengono dati in input i valori delle altezze di n persone (n chiesto all'utente). Per ogni persona oltre all'altezza viene indicato anche il sesso. Deve essere stampato il valore medio di altezza separatamente per i maschi e per le femmine. L’utente può decidere di non indicare né maschio né femmina, in quel caso non contare quella persona.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int n, i, altezza, numm, numf;
    float mediam, mediaf;
    char sesso;

    printf("Quanti valori vuoi inserire? ");
    scanf("%d", &n);

    mediam = 0;
    mediaf = 0;
    numm = 0;
    numf = 0;
    for (i = 0; i < n; i++) {
        printf("Scrivi l'altezza della persona n %d: ", i+1);
        scanf("%d", &altezza);
        printf("Scrivi se e' maschio o femmina (m maschio, f femmina altrimenti non considero il sesso)");
        scanf(" %c", &sesso);

        if (sesso == 'm') {
            mediam += altezza;
            numm += 1;
        } else {
            mediaf += altezza;
            numf += 1;
        }
    }

    mediam /= numm;
    mediaf /= numf;

    printf("L'altezza media dei maschi e' %.1f.\n", mediam);
    printf("L'altezza media delle femmine e' %.1f.\n", mediaf);
}
```

</details> 


### Gioco coi dadi
{: .numerato_da_h3}

Scrivi il codice di un gioco per 2 persone basato sul lancio di dadi. All’inizio del gioco si decide che tipo di dado usare, si possono scegliere i dadi da 4, 6, 8 o 20 facce. Il gioco consiste nel tirare uno per volta il dado e sommando ogni volta i numeri usciti finchè uno dei due giocatori non supera un valore limite che è 4 volte il valore massimo rappresentato sul dado scelto (ad esempio se si sceglie il dado da 6 il limite è 24). Per rendere il gioco equo si può fare in modo che i due giocatori debbano tirare per forza lo stesso numero di tiri e che entrambi i giocatori possano superare il limite facendo finire il gioco in parità
Variante: Scrivi una variante del gioco in cui l’obiettivo è avvicinarsi il più possibile al valore limite senza superarlo. Chi si avvicina di più vince. In ogni momento un giocatore può decidere di accontentarsi del valore ottenuto e smettere di tirare.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int valdado, limite, g1, g2, lancio;

    srand(time(NULL));

    do {
        printf("Che dado vuoi usare? (4, 6, 8, 20):  ");
        scanf("%d", &valdado);
    } while (valdado != 4 && valdado != 6 && valdado != 8 && valdado != 20);

    limite = 4*valdado;

    g1 = 0;
    g2 = 0;
    while (g1 <= limite && g2 <= limite) {
        lancio = rand() % valdado + 1;
        g1 += lancio;
        printf("Il giocatore 1 lancia %d e arriva a %d.\n", lancio, g1);
        system("pause");

        lancio = rand() % valdado + 1;
        g2 += lancio;
        printf("Il giocatore 2 lancia %d e arriva a %d.\n", lancio, g2);
        system("pause");
    }

    if (g1 > limite && g2 > limite) {
        printf("Pareggio.\n");
    } else if (g1 > limite) {
        printf("Vince il giocatore 2.\n");
    } else {
        printf("Vince il giocatore 1.\n");
    }
}
```

</details> 


### If con espressione logica
{: .numerato_da_h3}

Leggi un numero positivo e controlla se esso è divisibile per 2 o divide 3 e non è compreso tra 10 e 20

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int n;

    do {
        printf("Scrivi un numero positivo: ");
        scanf("%d", &n);
    } while (n <= 0);

    if ((n % 2 == 0 || 30 % n == 0) && !(n >= 10 && n <= 20)) {
        printf("Si");
    } else {
        printf("No");
    }
}
```

</details> 


### If con espressione logica 2
{: .numerato_da_h3}

Leggi un numero positivo e controlla se esso è divisibile per 2 o è un multiplo di 3 ed è compreso tra 10 e 20

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int n;
    do {
        printf("Scrivi un numero positivo: ");
        scanf("%d", &n);
    } while (n <= 0);

    if ((n % 2 == 0 || n % 3 == 0) && (n >= 10 && n <= 20)) {
        printf("Si");
    } else {
        printf("No");
    }
}
```

</details> 


### Sequenza e if con espressione logica
{: .numerato_da_h3}

dato un numero n stampa tutti i numeri da 1 a n che sono divisibili da 2 o 3 o 5 ma non sono divisibili per 4

### Figure geometriche
{: .numerato_da_h3}


Dato un numero positivo n disegna le figure geometriche riportate di seguito:

    per n = 5
    xxxxx
    xxxx
    xxx
    xx
    x

    xxxxx
    xxxxx
    xxxxx
    xxxxx
    xxxxx	

    x
    xx
    xxx
    xxxx
    xxxxx

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int n = 5, i, j;

    printf("Triangolo 1\n");
    // xxxxx
    // xxxx
    // xxx
    // xx
    // x
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            printf("x");
        }
        printf("\n");
    }

    printf("\nQuadrato\n");
    // xxxxx
    // xxxxx
    // xxxxx
    // xxxxx
    // xxxxx    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("x");
        }
        printf("\n");
    }

    printf("\nTriangolo 2\n");
    // x
    // xx
    // xxx
    // xxxx
    // xxxxx
    for (i = 0; i < n; i++) {
        for (j = 0; j < i + 1; j++) {
            printf("x");
        }
        printf("\n");
    }
}
```

</details> 


### Figure geometriche 2
{: .numerato_da_h3}

Esegui un programma che abbia il seguente output (chiaramente usando dei cicli):

    1 2 3 4 5 6
    2 3 4 5 6 +
    3 4 5 6 + +
    4 5 6 + + +
    5 6 + + + +
    6 + + + + +

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int i, j, n = 6, val;

    printf("Modo 1\n");
    for (i = 0; i < n; i++) {
        for (j = 1 + i; j < 1 + i + n; j++) {
            if (j <= n) {
                printf("%d ", j);
            } else {
                printf("+ ");
            }
        }
        printf("\n");
    }

    printf("\nModo 2\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            val = 1 + i + j;
            if (val <= n) {
                printf("%d ", val);
            } else {
                printf("+ ");
            }
        }
        printf("\n");
    }
}
```

</details> 


### Gioco coi dadi 2
{: .numerato_da_h3}

Simula l’esecuzione di un gioco di dadi in cui due persone si scontrano lanciando ognuno un dado. Il gioco è diviso in round. Al primo round i due giocatori lanciano ognuno un dado da venti facce e vince chi fa il numero più alto, in caso di pareggio ritirano i dadi finchè uno dei due non vince. Chi perde il round deve affrontare i round successivi con un dado con una faccia in meno. Perde la partita chi arriva ad avere un dado con 0 facce. Mostra ad ogni round quante facce hanno i dadi dei due giocatori e mostra il risultato di ogni lancio dei dadi. Dichiara infine il vincitore.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int dado1, dado2, tiro1, tiro2;

    srand(time(NULL));

    dado1 = 20;
    dado2 = 20;
    while (dado1 > 0 && dado2 > 0) {
        tiro1 = rand() % dado1 + 1;
        tiro2 = rand() % dado2 + 1;

        printf("giocatore 1: %2d,  giocatore 2: %2d - ", tiro1, tiro2);
        if (tiro1 > tiro2) {
            dado2--;
            printf("vince giocatore 1\n");
        } else if (tiro1 < tiro2) {
            dado1--;
            printf("vice giocatore 2\n");
        } else {
            printf("pareggio\n");
        }
    }
    if (dado1 == 0) {
        printf("\nVince il giocatore 2!\n");
    } else {
        printf("\nVince il giocatore 1!\n");
    }
}
```

</details> 



### Figure geometriche 3
{: .numerato_da_h3}

Scrivi un programma che dato un numero n stampi una piramide come nel seguente esempio:

    Con n = 3
      1  
     121 
    12321

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int n, i, j, val;

    n = 10;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            val = -n+i+j+2;
            if (val > 0) {
                printf("%2d ", val);
            } else {
                printf("   ");
            }
        }
        for (j = n-2; j >= 0; j--) {
            val = -n+i+j+2;
            if (val > 0) {
                printf("%2d ", val);
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}
```

</details> 



### Figure geometriche 4
{: .numerato_da_h3}

Scrivere un programma che legga due interi n e m con valori compresi tra 1 e 9, i cui prodotto sia inferiore a 35, e stampi m piramidi di altezza n. L’esempio si riferisce al caso n=3 e m=4.

      1    1    1    1
     121  121  121  121
    12321123211232112321

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int n, i, j, k, m, val;

    n = 3;
    m = 4;
    for (i = 0; i < n; i++) {
        for (k = 0; k < m; k++) {
            for (j = 0; j < n; j++) {
                val = -n + i + j + 2;
                if (val > 0) {
                    printf("%2d ", val);
                } else {
                    printf("   ");
                }
            }
            for (j = n - 2; j >= 0; j--) {
                val = -n + i + j + 2;
                if (val > 0) {
                    printf("%2d ", val);
                } else {
                    printf("   ");
                }
            }
        }
        printf("\n");
    }
}
```

</details> 


### Input e condizione
{: .numerato_da_h3}

Scrivi un programma che permetta di controllare i dati di input immessi dall’utente:
se l’utente inserisce un intero N compreso tra 1 e 10, il programma deve stampare a video il valore N^N,
se l’intero N e’ compreso tra 11 e 20, il programma deve stampare a video la somma 1 + 2 + 3 +… + N
altrimenti deve dare un segnale di errore.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    long long int n, i, ris;

    printf("Scrivi un numero: ");
    scanf("%lld", &n);

    if (n >= 1 && n <= 10) {
        for (i = 0, ris = 1; i < n; i++) {
            ris *= n;
        }
        printf("%lld^%lld=%lld", n, n, ris);
    } 
    else if (n >= 11 && n <= 20) {
        for (i = 1, ris = 0; i <= n; i++) {
            ris += i;
        }
        printf("sommatoria da 1 a %lld = %lld", n, ris);
    } else {
        printf("Valore non valido.");
    }
}
```

</details> 


### Calcolo sommatoria matematica
{: .numerato_da_h3}

Si realizzi un programma che legga un intero N da tastiera, e stampi a video il risultato della seguente sommatoria:

$$ \sum_{i=0}^N \left[(-1)^i {4 \over 2i + 1}\right] $$

Una volta calcolato e stampato il valore a video, il programma deve chiedere un nuovo numero all’utente e ripetere il calcolo. Il programma deve terminare solo qualora l’utente inserisca un valore negativo.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int i, n;
    float ris, x;

    do {
        printf("Scrivi n (negativo per terminare): ");
        scanf("%d", &n);

        ris = 0;
        for (i = 0; i <= n; i++) {
            x = 4.0 / (2 * i + 1);
            if (i % 2 != 0) {
                x *= -1;
            }
            ris += x;
        }

        printf("%f\n", ris);
    } while (n >= 0);
}
```

</details> 


### Calcolo interesse cumulato
{: .numerato_da_h3}

Si progetti in C un programma che legge un float, rappresentante un ammontare di euro; di seguito il programma deve leggere un tasso d’interesse (in percentuale), ed un numero di anni. Il programma deve stampare, in uscita, per ogni anno, come l’ammontare cresce con gli interessi. Si ricordi che l’interesse si calcola con la seguente formula:

$$ C_{fin} = C_{in} \left( 1 + (r/100) \right)N $$

dove $C_{fin}$ è il capitale finale, $C_{in}$ è quello iniziale, $r$ è l’interesse, e $N$ rappresenta il numero di anni in cui si applicano gli interessi.

Ad esempio supponiamo che il capitale iniziale sia di 1000.0 €, con un tasso del 3%, per un periodo di 3 anni. L’output stampato deve avere all’incirca questo aspetto: 

    Capitale iniziale: 1000.00€ 
    Dopo 1 anno: 1030.00 € 
    Dopo 2 anni: 1060.90 € 
    Dopo 3 anni: 1092.73 €

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <math.h>

int main() {
    float c, r, cf;
    int n, i;
    c = 1000.0;
    r = 3;
    n = 10;

    printf("Capitale iniziale : %.2f e\n", c);
    cf = c;
    for (i = 1; i <= n; i++) {
        cf =  cf * ( 1 + (r/100));
        printf("Dopo %d anni: %.2f e\n", i, cf);
    }

    printf("\n\nCapitale iniziale : %.2f e\n", c);
    for (i = 1; i <= n; i++) {
        cf =  c * pow(1 + (r/100), i);
        printf("Dopo %d anni: %.2f e\n", i, cf);
    }
}
```

</details> 


### Input sequenza non 0, ASCII code
{: .numerato_da_h3}

Realizzare un programma che legga da input un carattere dell’alfabeto e stampi a video il carattere stesso ed il suo valore ASCII. Il programma deve controllare che il carattere inserito sia compreso tra ‘a’ e ‘z’ o tra ‘A’ e ‘Z’ (in caso contrario si stampi un messaggio di errore). Dopo la stampa, il programma deve continuare a chiedere nuovi caratteri, finché l’utente non inserisce il carattere corrispondente al numero zero ( ‘0’ ): in tal caso il programma termina.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    char c;
    

    do {
        printf("Scrivi un carattere: ");
        scanf(" %c", &c);

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            printf("%d\n\n", c);
        } else {
            printf("'%c' non e' una lettera.\n\n", c);
        }
    } while (c != '0');
}
```

</details> 


### Input sequenza, calcolo più lunga sottosequenza
{: .numerato_da_h3}

Realizzare un programma che prende in input una sequenza di caratteri ‘0’ e ‘1’ e conta la lunghezza della più lunga sotto-sequenza di ‘0’ di fila. L’inserimento della sequenza termina quando si inserisce un carattere diverso da ‘0’ e ‘1’ A quel punto, si stampa a video il valore trovato.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    char car;
    int lung, max;

    lung = 0;
    max = 0;
    do {
        scanf(" %c", &car);
        if (car == '0'){
            lung++;
        } else {
            if (lung > max) {
                max = lung;
            }
            lung = 0;
        }
    } while (car == '0' || car == '1');

    printf("\n\n%d", max);
}
```

</details> 



### Input sequenza, calcolo più lunga sottosequenza 2
{: .numerato_da_h3}

Realizzare un programma che prenda in input una sequenza di cifre (tra 1 e 9) e calcoli la somma massima fra le sottosequenze di cifre non decrescenti Il programma termina quando viene inserito lo 0
Esempio: 
 
<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int n, prec, somma, sommamax;

    prec = 10;
    sommamax = 0;
    somma = 0;
    do {
        printf("Scrivi un numero tra 1 e 9: ");
        scanf("%d", &n);
        while (n < 0 || n > 9) {
            printf("Errore! Scrivi un numero tra 1 e 9: ");
            scanf("%d", &n);
        }

        if (prec <= n) {
            somma += n;
        } else {
            somma = n;
        }
        if (somma > sommamax) {
            sommamax = somma;
        }
        prec = n;
    } while (n != 0);

    printf("%d", sommamax);
}
```

</details> 


### Input sequenza lunga n, quadrati perfetti
{: .numerato_da_h3}

Data in input una sequenza di n numeri (n dato dall’utente), stampare per ognuno il numero di quadrati perfetti minori di quel numero.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int n, numero, i, j, nquadrati;

    do {
        printf("Quanti numeri vuoi inserire: ");
        scanf("%d", &n);
    } while (n < 1);

    for (i = 0; i < n; i++) {
        printf("inserisci il %d numero: ", i+1);
        scanf("%d", &numero);
        nquadrati = 0;
        for (j = 1; j*j <= numero; j++) {
            nquadrati++;
        }
        printf("esistono %d quadrati perfetti minori o ugali a %d.\n", nquadrati, numero);
    }
}
```

</details> 


### Lancio moneta
{: .numerato_da_h3}

Conta quanti tiri di moneta devi fare prima di vedere uscire testa per 10 volte di fila.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int ntiri, tiro, cont;

    srand(time(NULL));

    for(ntiri = 0, cont = 0; cont < 10; ntiri++) {
        tiro = rand() % 2;
        if (tiro == 1) {
            cont += 1;
        } else {
            cont = 0;
        }
    }

    printf("%d", ntiri);
}
```

</details> 


### Calcolo probabilità Dado 3
{: .numerato_da_h3}

Conta quanti tiri di un dado da 6 devi fare prima di vedere uscire lo stesso numero 5 volte di fila.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int ntiri, tiro, cont, prec;

    srand(time(NULL));

    prec = 0;
    for(ntiri = 0, cont = 0; cont < 5; ntiri++) {
        tiro = rand() % 6 + 1;
        if (tiro == prec) {
            cont += 1;
        } else {
            cont = 0;
        }
        prec = tiro;
    }

    printf("%d", ntiri);
}
```

</details> 


### Indovina il numero
{: .numerato_da_h3}

Scrivi un programma che deve indovinare un numero scelto dall’utente (che se lo tiene per sé e non lo dice al computer). Il computer continua a proporre numeri e l’utente deve rispondere se il numero segreto è maggiore o minore di quello proposto.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, risp;
    int min = 0, max = 1000;
    int ntentativi;

    printf("Pensa ad un numero tra %d e %d, ora cercherò di indovinarlo.\n", min, max);

    for (ntentativi = 0; 1; ntentativi++) {
        n = (max+min) / 2;
        printf("Il numero e' %d? (0 no, 1 si): ", n);
        scanf("%d", &risp);
        if (risp) {
            printf("Ho indovinato in %d mosse.\n", ntentativi);
            break;
        } else {
            printf("Il numero che hai pensato e' maggiore o minore di %d? (0 minore, 1 maggiore): ", n);
            scanf("%d", &risp);
            if (risp) {
                min = n+1;
            } else {
                max = n-1;
            }
        }
    }
}
```

</details> 


### Sequenza casuale, calcolo media
{: .numerato_da_h3}

Genera una sequenza di 10 numeri interi casuali e calcolane la media.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 10, numero, i, min, max;
    float media;

    srand(time(NULL));

    min = 8;
    max = 12;
    media = 0;
    for (i = 0; i < n; i++) {
        numero = rand() % (max-min+1) + min;
        printf("%d ", numero);
        media += numero;
    }
    media /= n;
    printf("\n\n%.2f", media);
}
```

</details> 


### Calcolo probabilità dadi 4
{: .numerato_da_h3}

Tira due dadi da 12 fino a che non escono due numeri uguali. Calcola la media dei tiri fatti (sommi sempre i due dadi)

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int d1, d2, c, min, max;
    float media;

    srand(time(NULL));

    media = 0;
    c = 0;
    while (1) {
        d1 = rand() % 12 + 1;
        d2 = rand() % 12 + 1;
        printf("%d %d = %d\n", d1, d2, d1+d2);
        if (d1 == d2) {
            break;
        }
        media += (d1+d2);
        c++;
    }
    media /= c;
    printf("\n\n%.2f", media);
}
```

</details> 


### If con espressione logica 3
{: .numerato_da_h3}

Leggi due numeri e poi comunica se questi numeri hanno lo stesso segno o se la loro somma è negativa e contemporaneamente sono entrambi minori di 10.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    int a, b;

    printf("Scrivi due numeri interi qualsiasi: ");
    scanf("%d %d", &a, &b);

    if (a*b > 0 || (a+b < 0 && a < 10 && b < 10)){
        printf("Si");
    } else {
        printf("No");
    }
}
```

</details> 






<!-- per una nuova soluzione

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
```

</details> 

-->







<script src="{{site.baseurl}}/assets/js/esercizi-subnetting.js"></script>