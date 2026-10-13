---
title: Struct
description: Definire nuovi tipi di dato con struct e typedef in C, accesso ai campi, struct annidate, struct e funzioni, operatore freccia, array di struct
---

Gli [array](../array/) permettono di raggruppare tanti valori **dello stesso tipo**. Molto spesso però i dati del mondo reale sono composti da informazioni di **tipo diverso** che "stanno insieme": uno studente ha un nome (una stringa), un'età (un intero) e una media dei voti (un `double`); un punto del piano ha due coordinate; un prodotto ha un codice, una descrizione, un prezzo e una quantità in magazzino.

Senza strumenti appositi, per memorizzare i dati di una classe di studenti dovremmo usare tanti array separati (`nomi[N][M]`, `eta[N]`, `medie[N]`), stando bene attenti che l'elemento `i` di ciascuno si riferisca sempre allo stesso studente. Basta un errore in un ordinamento, in cui si scambiano gli elementi di un array e non degli altri, per mescolare i dati di studenti diversi.

Le **strutture** (`struct`) risolvono il problema: permettono di definire un **nuovo tipo di dato** che raggruppa più variabili, anche di tipo diverso, sotto un unico nome.

## 1. Definire una struct

Il modo più comodo per definire una struttura in C è usare le parole chiave `typedef struct`:

```c
typedef struct {
    double x;
    double y;
} Punto;
```

In questo modo:

*   viene definita una struttura con due **campi** (o *membri*), `x` e `y`;
*   `Punto` diventa un **nuovo tipo di dato**, che si può usare come qualsiasi altro tipo (`int`, `double`...) per dichiarare variabili, parametri di funzioni, array...

La definizione di una struct va scritta **fuori dal `main`**, di solito in cima al file dopo gli `#include` e i `#define`, in modo che il nuovo tipo sia visibile in tutte le funzioni. Notate il **punto e virgola** obbligatorio dopo il nome del tipo. Per convenzione i nomi dei tipi definiti dal programmatore iniziano con una lettera **maiuscola**, per distinguerli dalle variabili.

Un esempio più ricco, in cui i campi hanno tipi diversi:

```c
#define LUN_NOME 30

typedef struct {
    char nome[LUN_NOME];
    char cognome[LUN_NOME];
    int eta;
    double media;
} Studente;
```

:::note[`struct` senza `typedef`]
La parola `typedef` serve a dare un nome al nuovo tipo. Si può definire una struttura anche senza `typedef`, dandole un'*etichetta* (in inglese *tag*):

```c
struct punto {
    double x;
    double y;
};

struct punto a;     // in C bisogna ripetere la parola struct ogni volta
```

In questo caso il tipo si chiama `struct punto`, e la parola `struct` va ripetuta in ogni dichiarazione. In C++ la si può omettere, e per questo in molti esempi online (scritti in C++) si trova `punto a;` anche senza `typedef`: in C quel codice dà errore. Con `typedef` il problema non si pone.
:::

## 2. Usare le variabili di tipo struct

Una volta definito il tipo, si possono dichiarare variabili di quel tipo. Per accedere ai singoli campi si usa l'**operatore punto** `.`, scrivendo `variabile.campo`. Ogni campo si usa esattamente come una normale variabile del suo tipo:

```c
#include <stdio.h>
#include <string.h>

#define LUN_NOME 30

typedef struct {
    char nome[LUN_NOME];
    int eta;
    double media;
} Studente;

int main() {
    Studente s;

    strcpy(s.nome, "Giulia");       // il campo nome è una stringa: si usa strcpy
    s.eta = 16;
    s.media = 7.85;

    printf("%s ha %d anni e la media del %.2f\n", s.nome, s.eta, s.media);

    printf("Nuova eta': ");
    scanf("%d", &s.eta);            // la & va davanti a tutta l'espressione s.eta
    s.media += 0.5;

    printf("%s ha %d anni e la media del %.2f\n", s.nome, s.eta, s.media);
    return 0;
}
```

### Inizializzazione
Come per gli array, si possono assegnare tutti i valori già nella dichiarazione, elencandoli tra graffe **nell'ordine dei campi**:

```c
Punto a = {0.5, 5};
Studente s = {"Giulia", 16, 7.85};
```

Dallo standard C99 si possono anche indicare esplicitamente i nomi dei campi (si chiamano *inizializzatori designati*): in questo modo l'ordine non conta e il codice è più leggibile. I campi non indicati vengono messi a zero.

```c
Punto b = {.y = 2.5, .x = 1};
Studente t = {.nome = "Marco", .media = 6.5};     // eta vale 0
```

Le graffe, però, si possono usare in questo modo **solo nella dichiarazione**: dopo, `b = {1, 2.5};` dà errore di compilazione. Per assegnare tutti i campi insieme a una variabile già dichiarata bisogna indicare il tipo tra parentesi davanti alle graffe (si chiama *letterale composto*, anch'esso introdotto dal C99): `b = (Punto){1, 2.5};`. Altrimenti si assegnano i campi uno alla volta.

### Copia e confronto
Due variabili dello stesso tipo struct si possono **copiare con l'operatore `=`**, esattamente come si farebbe con due `int`: tutti i campi vengono copiati, compresi gli array e le stringhe contenuti nella struct!

```c
Studente a = {"Giulia", 16, 7.85};
Studente b;
b = a;          // copia tutti i campi, compresa la stringa nome
```

Non è invece possibile **confrontare** due struct con `==`, `<` o `>`: il linguaggio non sa come confrontare automaticamente strutture definite dal programmatore (cosa vuol dire che uno studente è "minore" di un altro? Più giovane? Viene prima in ordine alfabetico?). Per confrontare due struct bisogna confrontare manualmente i singoli campi, decidendo noi il criterio:

```c
if (a.x == b.x && a.y == b.y) {
    printf("I due punti coincidono\n");
}
```

## 3. Struct annidate

Un campo di una struct può essere a sua volta una struct. Ad esempio, una persona può avere una data di nascita e una posizione:

```c
typedef struct {
    int giorno, mese, anno;
} Data;

typedef struct {
    double x, y;
} Punto;

typedef struct {
    char nome[30];
    Data nascita;
    Punto posizione;
} Persona;
```

Per accedere ai campi interni si usano più operatori punto in sequenza, procedendo "dall'esterno verso l'interno":

```c
Persona p = {"Anna", {12, 3, 2009}, {1.5, -2}};

printf("%s e' nata il %d/%d/%d\n", p.nome, p.nascita.giorno, p.nascita.mese, p.nascita.anno);
p.posizione.x += 1;
```

Naturalmente `Data` e `Punto` vanno definite **prima** di `Persona`, perché il compilatore deve già conoscerle quando le incontra.

## 4. Struct e funzioni

Le struct si possono passare alle funzioni e restituire dalle funzioni, come qualsiasi altro tipo. Questo ci dà una soluzione elegante al problema delle funzioni che devono restituire [più di un valore](../funzioni/#si-può-restituire-un-solo-valore): basta raggrupparli in una struct.

```c
#include <stdio.h>

typedef struct {
    double x, y;
} Punto;

Punto puntoMedio(Punto a, Punto b) {
    Punto m;
    m.x = (a.x + b.x) / 2;
    m.y = (a.y + b.y) / 2;
    return m;
}

int main() {
    Punto a = {0.5, 5};
    Punto b = {1, 2.5};

    Punto m = puntoMedio(a, b);

    printf("Il punto medio tra (%g, %g) e (%g, %g) e' (%g, %g)\n",
           a.x, a.y, b.x, b.y, m.x, m.y);
    return 0;
}
```

Confrontate questa versione con quella vista nella pagina sui [puntatori](../puntatori/#restituire-più-risultati), che usava due `double` per ogni punto e due puntatori per i risultati: qui ogni punto è una sola variabile, la funzione riceve due punti e restituisce un punto. Il codice è molto più compatto e si legge quasi come una formula matematica.

Le struct passate come parametri seguono le stesse regole delle variabili normali: vengono passate **per valore**, cioè la funzione riceve una **copia** di tutta la struct (a differenza degli array, che non vengono mai copiati).

### Puntatori a struct e l'operatore freccia
Se una funzione deve **modificare** una struct del chiamante, bisogna passarle il suo indirizzo, come per qualsiasi altra variabile:

```c
#include <stdio.h>

typedef struct {
    double x, y;
} Punto;

void trasla(Punto *p, double dx, double dy) {
    p->x += dx;
    p->y += dy;
}

int main() {
    Punto a = {0.5, 5};
    trasla(&a, 2, -3);
    printf("Punto traslato: (%g, %g)\n", a.x, a.y);    // (2.5, 2)
    return 0;
}
```

Per accedere ai campi di una struct tramite un puntatore si usa l'operatore **freccia** `->`. Senza di esso dovremmo scrivere:

```c
(*p).x += dx;
(*p).y += dy;
```

cioè prima ottenere la struct puntata con `*p`, poi accedere al campo con il punto. Le parentesi sono obbligatorie, perché il punto ha la precedenza sull'asterisco: `*p.x` verrebbe interpretato come `*(p.x)`, che non ha senso. Questa sintassi è scomoda e poco leggibile, per questo il C mette a disposizione l'operatore `->`: **`p->x` è esattamente equivalente a `(*p).x`**, ma più chiaro e compatto.

Riassumendo: si usa il **punto** quando si ha una variabile struct, la **freccia** quando si ha un puntatore a una struct.

:::tip[Passare le struct grandi per indirizzo]
Passare una struct per valore significa copiarla tutta. Per una struct piccola come `Punto` non è un problema, ma per una struct con molti campi o con array al suo interno la copia può diventare costosa. Per questo spesso le struct grandi si passano per indirizzo anche quando la funzione non deve modificarle, indicandolo con `const`:

```c
void stampaStudente(const Studente *s) {
    printf("%-15s %3d %6.2f\n", s->nome, s->eta, s->media);
}
```

Il `const` garantisce che la funzione non modifichi la struct: se ci provasse, il compilatore darebbe errore.
:::

### Puntatori o struct per restituire più valori?
Quando una funzione deve produrre più risultati, conviene usare il passaggio per indirizzo di più variabili o una struct che le contenga tutte? Entrambe le soluzioni funzionano e sono molto usate; in generale:

*   se i valori sono per loro natura **raggruppabili** in un'unica entità (le coordinate di un punto, i campi di una data), conviene usare una **struct**;
*   se i valori **non appartengono** naturalmente alla stessa entità (ad esempio il massimo e il numero di volte che compare in un array), conviene il **passaggio per indirizzo**;
*   se i valori da restituire sono **molti e dello stesso tipo**, conviene usare un **array**, passato come parametro.

## 5. Array di struct

Le struct danno il meglio di sé insieme agli array: un **array di struct** è il modo naturale di rappresentare una tabella di dati, come l'elenco degli studenti di una classe, la rubrica dei contatti o il catalogo di un negozio. Ogni elemento dell'array è una "riga" della tabella e ogni campo è una "colonna".

```c
#include <stdio.h>
#include <string.h>

#define N 30
#define LUN_NOME 30

typedef struct {
    char nome[LUN_NOME];
    int eta;
    double media;
} Studente;

void stampaClasse(Studente classe[], int n) {
    printf("%-15s %4s %6s\n", "Nome", "Eta'", "Media");
    for (int i = 0; i < n; i++) {
        printf("%-15s %4d %6.2f\n", classe[i].nome, classe[i].eta, classe[i].media);
    }
}

// restituisce la posizione dello studente con la media più alta
int posMigliore(Studente classe[], int n) {
    int pos = 0;
    for (int i = 1; i < n; i++) {
        if (classe[i].media > classe[pos].media) {
            pos = i;
        }
    }
    return pos;
}

// ordina gli studenti in ordine alfabetico (bubble sort)
void ordinaPerNome(Studente classe[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(classe[j].nome, classe[j + 1].nome) > 0) {
                Studente tmp = classe[j];       // le struct si scambiano con =
                classe[j] = classe[j + 1];
                classe[j + 1] = tmp;
            }
        }
    }
}

int main() {
    Studente classe[N] = {
        {"Marco", 16, 6.75},
        {"Anna", 15, 8.20},
        {"Luca", 16, 7.10},
        {"Giulia", 15, 9.05}
    };
    int n = 4;

    stampaClasse(classe, n);

    int p = posMigliore(classe, n);
    printf("\nMedia migliore: %s (%.2f)\n\n", classe[p].nome, classe[p].media);

    ordinaPerNome(classe, n);
    stampaClasse(classe, n);
    return 0;
}
```

```text
Nome            Eta'  Media
Marco             16   6.75
Anna              15   8.20
Luca              16   7.10
Giulia            15   9.05

Media migliore: Giulia (9.05)

Nome            Eta'  Media
Anna              15   8.20
Giulia            15   9.05
Luca              16   7.10
Marco             16   6.75
```

Osservazioni:

*   `classe[i]` è l'`i`-esimo studente (una variabile di tipo `Studente`), e `classe[i].nome` è il nome dell'`i`-esimo studente. Attenzione all'ordine: l'indice va dopo il nome dell'**array**, il punto prima del nome del **campo**;
*   la funzione `posMigliore` restituisce la **posizione** dello studente, non lo studente stesso: in questo modo chi la chiama può accedere a tutti i suoi dati, e anche modificarli;
*   nell'ordinamento il confronto avviene su un campo (il nome), ma lo scambio riguarda **l'intera struct**: tutti i dati di uno studente si spostano insieme, ed è impossibile mescolarli. Grazie all'assegnamento tra struct, lo scambio è identico a quello tra due interi;
*   per ordinare secondo un altro criterio (ad esempio per media decrescente) basta cambiare la condizione dell'`if`: `classe[j].media < classe[j + 1].media`.

Per ordinare un array di struct si può usare anche [`qsort`](../puntatori/#8-ordinare-con-qsort), con una funzione di confronto che confronta il campo desiderato:

```c
int confrontaPerMedia(const void *a, const void *b) {
    const Studente *s1 = a;
    const Studente *s2 = b;
    if (s1->media < s2->media) return 1;    // ordine decrescente
    if (s1->media > s2->media) return -1;
    return 0;
}

// nel main:
qsort(classe, n, sizeof(Studente), confrontaPerMedia);
```

Gli array di struct sono la base di quasi tutti i programmi gestionali: nella pagina sui [file di testo](../file/) vedremo come leggerne il contenuto da un file e come salvarlo, in modo che i dati non vadano persi alla chiusura del programma.

## 6. Errori comuni

| Errore | Conseguenza |
|---|---|
| Punto e virgola dimenticato dopo la definizione della struct | Errore di compilazione, spesso segnalato in un punto lontano |
| Struct definita dentro il `main` | Il tipo non è visibile nelle altre funzioni |
| `s.nome = "Giulia";` | Errore: le stringhe si copiano con `strcpy`, anche dentro le struct |
| `b = {1, 2};` dopo la dichiarazione | Errore di compilazione: si assegnano i campi uno alla volta o si usa `(Punto){1, 2}` |
| `if (a == b)` tra due struct | Errore di compilazione: si confrontano i singoli campi |
| `p.x` con `p` puntatore, oppure `s->x` con `s` variabile struct | Errore di compilazione: punto per le variabili, freccia per i puntatori |
| `*p.x` invece di `(*p).x` | Errore di compilazione per la precedenza degli operatori |
| `classe.nome[i]` invece di `classe[i].nome` | Errore di compilazione, o accesso a un singolo carattere |
| Funzione che riceve la struct per valore e la modifica | La modifica non ha effetto sulla variabile del chiamante |
| Nell'ordinamento si scambia un solo campo invece dell'intera struct | I dati di elementi diversi si mescolano |

## Esercizi

Gli esercizi relativi a questi argomenti si trovano nel capitolo **"Funzioni e struct"** (sezione *Struct*) e nel capitolo **"Struct"** dell'eserciziario, linkato nella [pagina introduttiva](../programmazione-in-c/).
