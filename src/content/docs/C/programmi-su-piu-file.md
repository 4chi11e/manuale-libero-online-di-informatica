---
title: Programmi su più file
description: Dividere un programma C in più file, file header e file sorgente, include guard, compilazione separata e linking
---

Finché un programma è lungo qualche decina di righe, tenerlo tutto in un unico file `.c` non è un problema. Ma i programmi reali sono formati da migliaia, a volte milioni di righe: il kernel di Linux, scritto in C, ne conta più di trenta milioni! Tenere tutto in un solo file sarebbe impossibile da gestire. Per questo i programmi vengono divisi in **più file**, ognuno dei quali raccoglie le funzioni relative a un certo argomento: un file per la gestione dei file di dati, uno per l'interfaccia con l'utente, uno per i calcoli, e così via. Ognuno di questi gruppi di funzioni si chiama **modulo**.

Dividere un programma in moduli porta diversi vantaggi:

*   **Ordine**: è più facile orientarsi nel codice e trovare la funzione che si cerca.
*   **Riuso**: un modulo ben scritto (ad esempio quello per gestire un [vector](../strutture-dati-dinamiche/#1-il-vector-array-dinamico)) si può copiare e riutilizzare in altri programmi senza modifiche.
*   **Lavoro di gruppo**: più programmatori possono lavorare contemporaneamente su file diversi.
*   **Compilazione più veloce**: quando si modifica un file, basta ricompilare solo quello.

È esattamente quello che abbiamo sempre fatto usando le librerie standard: le funzioni come `printf` o `strlen` sono state scritte da qualcun altro, in altri file, e noi le usiamo semplicemente includendo `stdio.h` o `string.h`.

## 1. File header e file sorgente

Ogni modulo è formato da due file con lo stesso nome ed estensioni diverse:

*   il **file header** (o *file di intestazione*), con estensione **`.h`**, contiene l'**interfaccia** del modulo: tutto ciò che serve sapere per **usarlo**. Contiene i [prototipi](../funzioni/#4-dichiarazione-e-definizione-i-prototipi) delle funzioni, le definizioni dei tipi (`typedef struct`) e le costanti (`#define`);
*   il **file sorgente**, con estensione **`.c`**, contiene l'**implementazione**: il codice completo delle funzioni dichiarate nel file header.

Chi usa il modulo ha bisogno di conoscere solo il file header, come noi conosciamo il prototipo di `printf` senza sapere come è fatta all'interno.

### Un esempio
Creiamo un piccolo modulo per la geometria del piano. Il programma è formato da tre file, nella stessa cartella.

**`geometria.h`**: l'interfaccia del modulo.

```c
#ifndef GEOMETRIA_H
#define GEOMETRIA_H

typedef struct {
    double x, y;
} Punto;

// restituisce la distanza tra i punti a e b
double distanza(Punto a, Punto b);

// restituisce il punto medio del segmento ab
Punto puntoMedio(Punto a, Punto b);

// restituisce il perimetro del triangolo abc
double perimetroTriangolo(Punto a, Punto b, Punto c);

#endif
```

**`geometria.c`**: l'implementazione delle funzioni.

```c
#include <math.h>
#include "geometria.h"

double distanza(Punto a, Punto b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

Punto puntoMedio(Punto a, Punto b) {
    Punto m = {(a.x + b.x) / 2, (a.y + b.y) / 2};
    return m;
}

double perimetroTriangolo(Punto a, Punto b, Punto c) {
    return distanza(a, b) + distanza(b, c) + distanza(c, a);
}
```

**`main.c`**: il programma principale, che usa il modulo.

```c
#include <stdio.h>
#include "geometria.h"

int main() {
    Punto a = {0, 0}, b = {3, 0}, c = {0, 4};

    printf("Distanza AB: %g\n", distanza(a, b));
    Punto m = puntoMedio(b, c);
    printf("Punto medio di BC: (%g, %g)\n", m.x, m.y);
    printf("Perimetro di ABC: %g\n", perimetroTriangolo(a, b, c));
    return 0;
}
```

```text
Distanza AB: 3
Punto medio di BC: (1.5, 2)
Perimetro di ABC: 12
```

Notate che:

*   sia `main.c` sia `geometria.c` includono `geometria.h`: `main.c` perché deve conoscere il tipo `Punto` e i prototipi delle funzioni che usa, `geometria.c` perché deve conoscere il tipo `Punto` per poter definire le funzioni (e così il compilatore controlla anche che le definizioni corrispondano ai prototipi);
*   `math.h` è incluso solo in `geometria.c`, perché è l'unico file che usa `sqrt`. Ogni file include solo ciò di cui ha bisogno;
*   il `main` non sa, e non ha bisogno di sapere, come vengono calcolate distanze e perimetri: se un giorno si cambiasse l'implementazione di `distanza`, `main.c` non andrebbe toccato.

### `#include` con le virgolette o con le parentesi angolari?
*   `#include <stdio.h>`, con le **parentesi angolari**, si usa per le librerie di sistema: il file viene cercato nelle cartelle in cui è installato il compilatore.
*   `#include "geometria.h"`, con le **virgolette**, si usa per i file scritti da noi: il file viene cercato prima nella cartella del file che lo include, e solo dopo nelle cartelle di sistema.

Ricordate che `#include` è una direttiva per il preprocessore, che si limita a **copiare** il contenuto del file indicato al posto della riga `#include`. Per questo si includono sempre e solo i file `.h`, **mai i file `.c`**: includere un file `.c` funziona solo finché lo si include in un unico file, poi porta a errori di definizioni multiple.

## 2. Le include guard

Le prime due righe e l'ultima di `geometria.h` formano una **include guard** ("protezione dall'inclusione"):

```c
#ifndef GEOMETRIA_H     // se GEOMETRIA_H non è ancora stato definito...
#define GEOMETRIA_H     // ...lo definisce e prosegue

// ... contenuto del file header ...

#endif                  // fine del blocco
```

Servono a evitare che il contenuto del file header venga incluso **due volte** nello stesso file. Può succedere facilmente: se ad esempio un modulo `triangoli.h` include `geometria.h` (perché usa il tipo `Punto`) e `main.c` include sia `triangoli.h` sia `geometria.h`, senza protezione la definizione di `Punto` comparirebbe due volte in `main.c`, causando un errore di compilazione (*redefinition*).

Con la include guard, la prima volta che il file viene incluso la costante `GEOMETRIA_H` non esiste: il preprocessore la definisce e copia il contenuto. Le volte successive `GEOMETRIA_H` esiste già, e tutto il contenuto fino a `#endif` viene saltato. Il nome della costante è arbitrario, ma per convenzione si usa il nome del file in maiuscolo, con `_H` al posto di `.h`.

Ogni file header dovrebbe **sempre** avere la sua include guard. Molti compilatori supportano anche la direttiva `#pragma once`, da scrivere come prima riga del file header, che ha lo stesso effetto in modo più sintetico; non fa però parte dello standard C.

## 3. Compilare un programma su più file

Ricordiamo le fasi della [compilazione](../elementi-di-base/#dal-codice-sorgente-al-programma-la-compilazione): ogni file `.c` viene compilato **separatamente**, producendo un **file oggetto** (con estensione `.o`) che contiene il codice macchina delle sue funzioni. Il **linker** poi unisce tutti i file oggetto, insieme alle librerie, nell'eseguibile finale.

```text
geometria.h ----+--------------+
                |              |
                v              v
main.c ---> [compilatore]   geometria.c ---> [compilatore]
                |                                 |
                v                                 v
             main.o                          geometria.o
                |                                 |
                +------------> [linker] <---------+
                                   |
                                   v
                             programma.exe
```

Il modo più semplice per compilare è indicare a `gcc` tutti i file `.c` del programma (i file `.h` non vanno indicati, perché vengono inclusi dai `.c`):

```text
gcc main.c geometria.c -o programma.exe
```

Si possono anche eseguire le due fasi separatamente, compilando ogni file con l'opzione `-c` (*compile only*) e poi collegando i file oggetto:

```text
gcc -c main.c                                 (produce main.o)
gcc -c geometria.c                            (produce geometria.o)
gcc main.o geometria.o -o programma.exe       (linking)
```

Il vantaggio di questo secondo metodo è che, se si modifica solo `main.c`, basta ricompilare `main.c` e ripetere il linking: `geometria.c` non va ricompilato. In progetti con centinaia di file il risparmio di tempo è enorme, e questo processo viene automatizzato con strumenti come **`make`** o **CMake**, che ricompilano automaticamente solo i file modificati.

:::caution[E in VS Code?]
L'estensione *Code Runner* compila solo il file aperto nell'editor: premendo "play" su `main.c` si ottiene un errore del linker, perché il codice delle funzioni di `geometria.c` non viene compilato. Le soluzioni più semplici sono:

*   compilare dal **terminale** integrato di VS Code con il comando `gcc main.c geometria.c -o programma.exe`, ed eseguire il programma con `./programma.exe`;
*   usare l'estensione *C/C++ Runner*, che compila insieme tutti i file `.c` contenuti nella cartella aperta.
:::

## 4. Gli errori tipici: compilatore o linker?

Con i programmi su più file compare un nuovo tipo di errore, quello del **linker**. È importante saper distinguere da quale fase proviene un errore, perché le cause sono diverse.

*   **`implicit declaration of function 'distanza'`** è un warning (o un errore) del **compilatore**: nel file che si sta compilando la funzione viene usata ma non è stata dichiarata. Quasi sempre manca l'`#include` del file header che contiene il prototipo.
*   **`undefined reference to 'distanza'`** è un errore del **linker**: il compilatore conosceva il prototipo, quindi ha compilato tutto senza problemi, ma al momento di unire i file oggetto il linker non ha trovato il **codice** della funzione. Quasi sempre il file `.c` che la contiene non è stato compilato insieme agli altri (oppure il nome della funzione nella definizione è diverso da quello nel prototipo).
*   **`multiple definition of 'distanza'`** è un altro errore del **linker**: il codice della funzione compare in più file oggetto. Succede quando si scrive il corpo di una funzione in un file header incluso da più file `.c`, o quando si include un file `.c`.
*   **`redefinition of 'Punto'`** è un errore del **compilatore**: lo stesso tipo è definito due volte nello stesso file. Quasi sempre manca l'include guard in un file header.

## 5. Funzioni e variabili "private" del modulo

Non tutte le funzioni di un modulo devono essere usate dall'esterno: spesso ci sono funzioni di supporto che servono solo all'interno del modulo stesso. Queste funzioni non vanno dichiarate nel file header e, nel file `.c`, si dichiarano con la parola chiave **`static`**, che le rende visibili **solo nel file in cui sono definite**:

```c
// in geometria.c: funzione di supporto, non utilizzabile dagli altri file
static double quadrato(double x) {
    return x * x;
}
```

In questo modo il modulo espone solo la sua interfaccia, e due moduli diversi possono avere funzioni di supporto con lo stesso nome senza entrare in conflitto. È lo stesso principio di **incapsulamento** che, in forma molto più potente, sta alla base della programmazione a oggetti.

Allo stesso modo, una variabile globale dichiarata `static` in un file `.c` è visibile solo in quel file. Esiste anche la possibilità di condividere una variabile globale tra più file (si definisce in un file `.c` e si dichiara negli altri con la parola chiave `extern`), ma per gli stessi motivi per cui le [variabili globali](../funzioni/#6-visibilità-delle-variabili) sono sconsigliate in generale, è una pratica da evitare.

## 6. Errori comuni

| Errore | Conseguenza |
|---|---|
| File header senza include guard | Errore *redefinition* se il file viene incluso più volte |
| Corpo di una funzione scritto nel file header | Errore *multiple definition* del linker se il file è incluso da più `.c` |
| `#include "geometria.c"` invece di `"geometria.h"` | Errori di definizioni multiple non appena il programma cresce |
| Compilazione del solo `main.c` | Errore *undefined reference* del linker |
| `#include <geometria.h>` con le parentesi angolari | Il file non viene trovato, perché viene cercato tra le librerie di sistema |
| Prototipo nel file header diverso dalla definizione nel `.c` | Errore *conflicting types*, se il `.c` include il proprio header (per questo va sempre incluso) |
| Tipi o costanti usati nel `.h` definiti solo nel `.c` | Errori di compilazione nei file che includono l'header |

## Esercizi

Il capitolo **"Divisione programmi in progetti di più files"** dell'eserciziario, linkato nella [pagina introduttiva](../programmazione-in-c/), suggerisce di riprendere gli esercizi già svolti sulle funzioni e sulle struct, spostando dichiarazioni e implementazioni delle funzioni in file diversi da quello che contiene il `main`. Ottimi candidati sono i moduli per la gestione di array, matrici, vector e liste visti nelle pagine precedenti.
