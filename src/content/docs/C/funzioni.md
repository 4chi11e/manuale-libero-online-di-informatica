---
title: Funzioni
description: Definire e usare funzioni in C, parametri, valori di ritorno, prototipi, passaggio per valore, visibilità delle variabili e ricorsione
---

Quando si scrive un programma capita molto spesso di dover ripetere le stesse operazioni in punti diversi. Il C stesso ci mette a disposizione nelle sue librerie molte funzioni già pronte, come `printf`, `scanf`, `sqrt` o `strlen`, che usiamo continuamente per fare sempre la stessa cosa. Il linguaggio ci permette anche di **definire le nostre funzioni**.

Una **funzione** è un blocco di codice con un **nome** che:

*   può **ricevere dei dati** su cui lavorare (i *parametri*);
*   svolge un **compito preciso**;
*   può **restituire un risultato** a chi l'ha chiamata.

Usare le funzioni porta tre grandi vantaggi:

*   **Riuso**: il codice si scrive una volta sola e si usa ovunque serva. Se c'è un errore, si corregge in un solo punto.
*   **Leggibilità**: `if (primo(n))` è molto più chiaro di dieci righe di cicli e condizioni.
*   **Scomposizione dei problemi**: un problema complesso si spezza in tanti sotto-problemi più semplici, ciascuno risolto da una funzione (approccio *top-down*). Ogni funzione si può scrivere e verificare separatamente dalle altre.

## 1. Definire e chiamare una funzione

La forma generale di una funzione è:

```text
tipo_di_ritorno nome_funzione(tipo1 parametro1, tipo2 parametro2, ...) {
    // corpo della funzione
    return valore;      // solo se il tipo di ritorno non è void
}
```

Il **tipo di ritorno** indica che tipo di valore restituisce la funzione: `int`, `double`, `char`... oppure **`void`** ("vuoto") se la funzione non restituisce nulla, ma si limita a compiere un'azione.

### Funzioni `void`
```c
#include <stdio.h>

void saluta() {
    printf("Ciao!\n");
    printf("Benvenuto nel programma\n");
}

int main() {
    saluta();       // chiamata della funzione
    saluta();       // posso chiamarla quante volte voglio
    return 0;
}
```

La **definizione** della funzione (le righe da `void saluta()` alla graffa chiusa) non esegue nulla: dice solo al compilatore "esiste una funzione con questo nome, che fa queste cose". Il codice della funzione viene eseguito solo quando la funzione viene **chiamata**, scrivendone il nome seguito dalle parentesi tonde. Al termine della funzione, l'esecuzione riprende dal punto in cui era stata chiamata.

### Funzioni che restituiscono un valore
```c
#include <stdio.h>

int somma(int a, int b) {
    return a + b;
}

int main() {
    int s = somma(3, 5);
    printf("Somma = %d\n", s);                  // Somma = 8
    printf("Doppio = %d\n", somma(10, 2) * 2);  // Doppio = 24
    return 0;
}
```

L'istruzione `return` restituisce un valore alla funzione chiamante (in questo caso `main`). Il valore restituito "prende il posto" della chiamata, e può quindi essere salvato in una variabile, stampato o usato all'interno di un'espressione o di una condizione.

### Stampare o restituire?
È una delle confusioni più frequenti all'inizio: **stampare** un valore sullo schermo non significa **restituirlo**.

*   Se viene chiesto di **restituire** un valore, la funzione non deve stampare nulla: deve usare `return`.
*   Se viene chiesto di **stampare**, la funzione non deve restituire nulla: sarà di tipo `void`.

Pensate a una funzione che calcola la somma di due numeri: se si limitasse a stamparla, potrebbe essere usata solo per mostrare il risultato all'utente. Se invece la restituisce, può essere sfruttata in un programma che fa calcoli ben più complessi e usa quel risultato per fare altro. Allo stesso modo, è meglio che una funzione riceva i dati come **parametri** invece di chiederli con `scanf` al suo interno: sarà molto più facile da riutilizzare.

## 2. Parametri e argomenti

*   Le variabili dichiarate tra le parentesi nella definizione (`int a, int b`) si chiamano **parametri** (o parametri *formali*).
*   I valori passati nella chiamata (`3` e `5`) si chiamano **argomenti** (o parametri *attuali*).

Al momento della chiamata il valore del primo argomento viene copiato nel primo parametro, il secondo nel secondo, e così via. Gli argomenti devono quindi essere **nello stesso numero e nello stesso ordine** dei parametri, e di tipo compatibile. Possono essere costanti, variabili o espressioni qualsiasi: `somma(x, y * 2)`.

Ogni parametro va dichiarato con il proprio tipo, anche se più parametri hanno lo stesso tipo: si scrive `int somma(int a, int b)`, non `int somma(int a, b)`. Una funzione senza parametri si può scrivere con le parentesi vuote, `saluta()`, oppure, in modo più preciso, `saluta(void)`.

## 3. L'istruzione `return`

Quando viene eseguito un `return` la funzione **termina immediatamente**, anche se ci sono altre istruzioni dopo. Questo permette di scrivere funzioni con più `return`, che spesso risultano più semplici:

```c
int massimo(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;       // si arriva qui solo se a > b era falso
}
```

Anche nelle funzioni `void` si può usare `return`, senza alcun valore, per uscire dalla funzione in anticipo:

```c
void stampaSePositivo(int x) {
    if (x <= 0) {
        return;     // esce dalla funzione senza fare nulla
    }
    printf("Il numero e' positivo: %d\n", x);
}
```

Se il valore restituito non è del tipo dichiarato, viene convertito automaticamente: una funzione di tipo `int` che esegue `return 3.7;` restituisce 3.

:::caution[Il `return` mancante]
In una funzione che non è `void` ogni percorso possibile deve terminare con un `return`. Il compilatore C purtroppo **non lo impone**: se si dimentica il `return`, il programma viene compilato lo stesso (con `-Wall` compare almeno il warning *control reaches end of non-void function*) e la funzione restituisce un valore casuale.

```c
int segno(int x) {
    if (x > 0) {
        return 1;
    } else if (x < 0) {
        return -1;
    }
    // manca il return per x == 0: valore casuale!
}
```
:::

### Si può restituire un solo valore
Una funzione può restituire **un solo valore** con `return`. Come fare allora se una funzione deve produrre più risultati, ad esempio quoziente e resto di una divisione, o le coordinate di un punto? Esistono due soluzioni, che vedremo nelle prossime pagine: il **passaggio per indirizzo** con i [puntatori](../puntatori/) e le [struct](../struct/).

## 4. Dichiarazione e definizione: i prototipi

Il compilatore legge il codice dall'alto verso il basso, e quando incontra la chiamata di una funzione deve già sapere che quella funzione esiste, quali parametri riceve e che tipo restituisce. Per questo negli esempi precedenti le funzioni sono sempre state scritte **prima** del `main`.

Quando le funzioni sono tante, però, è più comodo avere il `main` in alto, dove si legge subito cosa fa il programma. Si può fare scrivendo all'inizio del file solo i **prototipi** delle funzioni, cioè la loro intestazione seguita da un punto e virgola, e le **definizioni** complete dopo il `main`:

```c
#include <stdio.h>

// prototipi (dichiarazioni)
int quadrato(int x);
void stampaLinea(int lunghezza);

int main() {
    stampaLinea(20);
    printf("Il quadrato di 7 e' %d\n", quadrato(7));
    stampaLinea(20);
    return 0;
}

// definizioni
int quadrato(int x) {
    return x * x;
}

void stampaLinea(int lunghezza) {
    for (int i = 0; i < lunghezza; i++) {
        printf("-");
    }
    printf("\n");
}
```

Il prototipo contiene tutto ciò che serve al compilatore per controllare che le chiamate siano corrette (numero e tipo dei parametri, tipo di ritorno); il corpo della funzione può stare ovunque. Nei prototipi i nomi dei parametri si possono anche omettere (`int quadrato(int);`), ma è meglio scriverli perché documentano il significato di ogni parametro.

:::note
I prototipi sono proprio ciò che si trova nei file `.h` come `stdio.h`: includendo `stdio.h` diciamo al compilatore come sono fatte `printf`, `scanf` e tutte le altre, mentre il loro codice viene aggiunto al programma nella fase di *linking*. Vedremo come organizzare così anche i nostri programmi nella pagina sui [programmi su più file](../programmi-su-piu-file/).
:::

## 5. Il passaggio per valore

In C i parametri vengono passati **per valore**: la funzione riceve una **copia** del valore dell'argomento, non la variabile originale. Qualsiasi modifica fatta al parametro all'interno della funzione non ha alcun effetto sulla variabile del chiamante.

```c
#include <stdio.h>

void raddoppia(int a) {
    a = a * 2;
    printf("Dentro la funzione a = %d\n", a);   // 10
}

int main() {
    int a = 5;
    raddoppia(a);
    printf("Nel main a = %d\n", a);             // 5, non 10!
    return 0;
}
```

I nomi delle variabili di una funzione e quelli delle variabili del `main` **non hanno alcuna relazione**: ogni funzione vive una vita propria, separata dalle altre. In questo esempio il parametro della funzione si chiama `a` come la variabile del `main`, ma questa è solo una scelta del programmatore: si tratta di due variabili completamente diverse, che si trovano in zone diverse della memoria. Quando viene chiamata `raddoppia(a)`, il valore 5 viene copiato nel parametro `a` della funzione, che viene poi raddoppiato; la variabile `a` del `main` resta 5.

Per scrivere una funzione che modifichi davvero la variabile del chiamante bisogna passarle il suo **indirizzo**: è il *passaggio per indirizzo*, che vedremo nella pagina sui [puntatori](../puntatori/).

## 6. Visibilità delle variabili

Ogni variabile è visibile solo in una certa parte del programma, detta **ambito di visibilità** (in inglese *scope*).

*   Le variabili dichiarate dentro una funzione, compresi i parametri, sono **locali**: esistono solo durante l'esecuzione della funzione e non sono visibili dalle altre funzioni. Vengono create a ogni chiamata e distrutte quando la funzione termina, quindi non "ricordano" il valore che avevano nella chiamata precedente.
*   Più in generale, una variabile dichiarata dentro un **blocco** tra graffe (un `if`, un ciclo...) esiste solo all'interno di quel blocco. Per questo la variabile `i` dichiarata in `for (int i = 0; ...)` non esiste più dopo il ciclo.
*   Le variabili dichiarate **fuori** da tutte le funzioni sono **globali**: sono visibili e modificabili da tutte le funzioni del file.

```c
#include <stdio.h>

int contatore = 0;          // variabile globale

void incrementa() {
    int x = 10;             // variabile locale: esiste solo qui dentro
    contatore++;
    x++;
}

int main() {
    incrementa();
    incrementa();
    printf("%d\n", contatore);  // 2
    // printf("%d\n", x);       // ERRORE: x non esiste nel main
    return 0;
}
```

:::caution[Evitate le variabili globali]
Le variabili globali sembrano comode, perché permettono di non passare parametri, ma il loro uso è **fortemente sconsigliato**: rendono il programma difficile da capire e da correggere, perché qualsiasi funzione può modificarle e il comportamento di una funzione dipende da qualcosa che sta fuori di essa. Una funzione ben scritta riceve tutto ciò che le serve tramite i **parametri** e comunica i risultati tramite **`return`** (o i puntatori). Fanno eccezione le **costanti** definite con `#define`, che si mettono normalmente in cima al file.
:::

## 7. Un programma organizzato in funzioni

Ecco un esempio completo che mostra come un programma diventa più leggibile quando è scomposto in funzioni. Il `main` si legge quasi come una descrizione in italiano di cosa fa il programma, mentre i dettagli sono nascosti nelle singole funzioni.

```c
#include <stdio.h>

int leggiInteroInIntervallo(int min, int max);
int primo(int n);
int contaPrimi(int da, int a);

int main() {
    printf("Inizio dell'intervallo\n");
    int da = leggiInteroInIntervallo(1, 1000);
    printf("Fine dell'intervallo\n");
    int a = leggiInteroInIntervallo(da, 1000);

    printf("Tra %d e %d ci sono %d numeri primi\n", da, a, contaPrimi(da, a));
    return 0;
}

// chiede un intero finché non è compreso tra min e max, e lo restituisce
int leggiInteroInIntervallo(int min, int max) {
    int n;
    do {
        printf("Inserisci un numero tra %d e %d: ", min, max);
        scanf("%d", &n);
    } while (n < min || n > max);
    return n;
}

// restituisce 1 se n è primo, 0 altrimenti
int primo(int n) {
    if (n < 2) {
        return 0;
    }
    for (int d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            return 0;       // trovato un divisore: non serve continuare
        }
    }
    return 1;
}

// restituisce quanti numeri primi ci sono tra da e a (compresi)
int contaPrimi(int da, int a) {
    int conta = 0;
    for (int i = da; i <= a; i++) {
        if (primo(i)) {
            conta++;
        }
    }
    return conta;
}
```

Notate alcune cose:

*   ogni funzione è preceduta da un breve commento che spiega **cosa fa**, cosa riceve e cosa restituisce;
*   una funzione può chiamare altre funzioni: `contaPrimi` usa `primo`;
*   nella funzione `primo` i `return` multipli rendono inutile la variabile flag che avevamo usato nelle [strutture di controllo](../strutture-di-controllo/#flag-cercare-se-esiste-almeno-un-elemento): appena si trova un divisore, si restituisce 0 e la funzione termina;
*   `leggiInteroInIntervallo` è un esempio di funzione che chiede dati all'utente: in questo caso va bene, perché leggere un dato è proprio il suo compito. I limiti `min` e `max` però sono parametri, così la stessa funzione si può riutilizzare ovunque.

## 8. La ricorsione

Una funzione può chiamare qualsiasi altra funzione, **anche sé stessa**. Una funzione che chiama sé stessa si dice **ricorsiva**.

L'idea della ricorsione è risolvere un problema riconducendolo allo **stesso problema, ma più piccolo**, finché non diventa così piccolo da avere una soluzione immediata. L'esempio classico è il fattoriale:

$$n! = n \cdot (n-1)! \qquad \text{e} \qquad 0! = 1$$

Cioè: per calcolare il fattoriale di 5 basta saper calcolare il fattoriale di 4 e moltiplicarlo per 5, e così via fino a 0, il cui fattoriale vale 1 per definizione.

```c
#include <stdio.h>

long long fattoriale(int n) {
    if (n == 0) {                       // caso base
        return 1;
    }
    return n * fattoriale(n - 1);       // passo ricorsivo
}

int main() {
    printf("5! = %lld\n", fattoriale(5));   // 5! = 120
    return 0;
}
```

(Il tipo `long long`, che si stampa con `%lld`, permette di calcolare fattoriali più grandi di quelli che stanno in un `int`: con un `int` si arriva solo a 12!.)

Ogni funzione ricorsiva deve avere due elementi:

1.  **Il caso base**: una situazione in cui la risposta è nota direttamente, senza ulteriori chiamate ricorsive.
2.  **Il passo ricorsivo**: la funzione chiama sé stessa su un problema **più piccolo**, che si avvicina al caso base.

Ecco cosa succede quando si calcola `fattoriale(3)`:

```text
fattoriale(3) = 3 * fattoriale(2)
                    fattoriale(2) = 2 * fattoriale(1)
                                        fattoriale(1) = 1 * fattoriale(0)
                                                            fattoriale(0) = 1
                                        fattoriale(1) = 1 * 1 = 1
                    fattoriale(2) = 2 * 1 = 2
fattoriale(3) = 3 * 2 = 6
```

Ogni chiamata resta "in sospeso" in attesa del risultato della chiamata successiva. Ogni chiamata ha le **sue** variabili locali e i **suoi** parametri: in questo momento esistono contemporaneamente quattro diverse variabili `n`, con valori 3, 2, 1 e 0. Le chiamate in sospeso, con le loro variabili, vengono memorizzate in un'area di memoria chiamata **stack** (pila): ogni nuova chiamata viene "impilata" sopra le precedenti, e quando termina viene tolta dalla pila e si riprende la chiamata sottostante.

:::danger[Ricorsione infinita]
Se manca il caso base, o se il passo ricorsivo non si avvicina mai al caso base (ad esempio `fattoriale(-1)` con la funzione sopra), la funzione continua a chiamare sé stessa senza fine. Lo stack però ha una dimensione limitata: dopo qualche decina o centinaia di migliaia di chiamate si esaurisce e il programma va in crash (si parla di **stack overflow**). A differenza di altri linguaggi, il C non dà nessun messaggio chiaro: il programma semplicemente si interrompe.
:::

### Prima o dopo la chiamata ricorsiva?
Il punto in cui si mettono le istruzioni rispetto alla chiamata ricorsiva cambia molto il risultato. Queste due funzioni stampano le cifre di un numero, una per riga:

```c
// stampa le cifre dall'ultima alla prima
void cifreAlContrario(int n) {
    printf("%d\n", n % 10);         // prima stampa l'ultima cifra...
    if (n >= 10) {
        cifreAlContrario(n / 10);   // ...poi si occupa delle altre
    }
}

// stampa le cifre dalla prima all'ultima
void cifre(int n) {
    if (n >= 10) {
        cifre(n / 10);              // prima si occupa delle altre...
    }
    printf("%d\n", n % 10);         // ...poi stampa l'ultima cifra
}
```

Con `n = 472`, la prima funzione stampa 2, 7, 4 e la seconda 4, 7, 2. Nella seconda, la stampa avviene "al ritorno" dalle chiamate ricorsive: la prima `printf` eseguita è quella della chiamata più profonda, `cifre(4)`. Ottenere lo stesso risultato con un ciclo sarebbe più complicato!

### Altri esempi classici

**Potenza**: a<sup>n</sup> = a · a<sup>n-1</sup>, con a<sup>0</sup> = 1.

```c
double potenza(double a, int n) {
    if (n == 0) {
        return 1;
    }
    return a * potenza(a, n - 1);
}
```

**Massimo comune divisore** con l'algoritmo di Euclide: il MCD tra `a` e `b` è uguale al MCD tra `b` e il resto della divisione `a % b`. Ad ogni passo i numeri diventano più piccoli, finché il secondo diventa 0: a quel punto il MCD è il primo, perché MCD(a, 0) = a.

```c
int mcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return mcd(b, a % b);
}
```

**Successione di Fibonacci**: ogni numero è la somma dei due precedenti (0, 1, 1, 2, 3, 5, 8, 13, ...). In questo caso il passo ricorsivo contiene **due** chiamate ricorsive, e i casi base sono due:

```c
int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

### Ricorsione o iterazione?
Tutto ciò che si può fare con la ricorsione si può fare anche con i cicli, e viceversa. La versione iterativa di solito è **più efficiente**, perché ogni chiamata di funzione ha un costo in tempo e in memoria (lo stack).

La funzione `fibonacci` qui sopra ne è un esempio lampante: per calcolare `fibonacci(5)` calcola `fibonacci(4)` e `fibonacci(3)`, ma `fibonacci(4)` calcola di nuovo `fibonacci(3)`, e così via. Gli stessi valori vengono ricalcolati moltissime volte e il numero di chiamate cresce in modo esponenziale: già `fibonacci(45)` richiede alcuni secondi, mentre un semplice ciclo che tiene in memoria gli ultimi due valori dà il risultato istantaneamente.

D'altra parte ci sono problemi in cui la soluzione ricorsiva è molto più naturale e semplice da scrivere di quella iterativa: l'esplorazione di strutture ad albero (come le cartelle di un disco), alcuni algoritmi di ordinamento molto efficienti (come il *merge sort* e il *quick sort*), il gioco della Torre di Hanoi, la ricerca di un percorso in un labirinto. In questi casi la ricorsione è lo strumento giusto.

## 9. Errori comuni

| Errore | Conseguenza |
|---|---|
| Funzione chiamata prima di essere definita, senza prototipo | Warning o errore *implicit declaration of function* |
| Prototipo e definizione con parametri diversi | Errore di compilazione (*conflicting types*) |
| `return` dimenticato in una funzione non `void` | Il programma compila, ma restituisce un valore casuale |
| La funzione stampa il risultato invece di restituirlo | Il risultato non può essere riutilizzato dal chiamante |
| Valore di ritorno ignorato: `quadrato(5);` invece di `q = quadrato(5);` | Il risultato viene calcolato e poi perso |
| Aspettarsi che la funzione modifichi un parametro del chiamante | Nessun effetto: i parametri sono copie |
| Usare una variabile locale di un'altra funzione | Errore di compilazione: la variabile non è visibile |
| Funzione ricorsiva senza caso base, o che non si avvicina al caso base | Ricorsione infinita e crash per stack overflow |
| `;` dopo l'intestazione nella definizione: `int f(int x); { ... }` | Errore di compilazione |

## Esercizi

Gli esercizi relativi a questi argomenti si trovano nei capitoli **"Funzioni e struct"** e **"Funzioni ricorsive"** dell'eserciziario, linkato nella [pagina introduttiva](../programmazione-in-c/).
