---
layout: default
title: Struct - Esercizi
nav_order: 10
parent: Programmazione in C
has_children: False
---

# Struct - Esercizi
{: .no_toc}
  
<details open markdown="block">
  <summary>
    Table of contents
  </summary>
  {: .text-delta }
1. TOC
{:toc .toc}
</details>

## Esercizi
{: .azzera_numerazione_h3}

### Punti
{: .numerato_da_h3}

Scrivi un programma che definisca un punto e poi dati due punti scelti da te sia in grado, per mezzo di due apposite funzioni, di calcolare la distanza fra due punti e trovare il punto medio.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <math.h>
#include <stdio.h>

typedef struct {
    float x;
    float y;
} punto;

float distanza(punto a, punto b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

punto medio(punto a, punto b) {
    punto c;
    c.x = (a.x + b.x) / 2;
    c.y = (a.y + b.y) / 2;
    return c;
}

int main() {
    punto a, b, c;
    a.x = 1.1;
    a.y = 3.5;
    b.x = 0.5;
    b.y = 3;

    printf("La distanza tra (%g, %g) e (%g, %g) e' %g\n", a.x, a.y, b.x, b.y,
           distanza(a, b));
    c = medio(a, b);
    printf("il punto medio tra (%g, %g) e (%g, %g) e' (%g, %g)", a.x, a.y, b.x,
           b.y, c.x, c.y);
}
```

</details> 




### Punti 2
{: .numerato_da_h3}

Definisci una struct punto. Scrivi ed utilizza poi le funzioni:
1.	Funzione per stampare una rappresentazione del punto (es. A(1,2))
2.	Funzione per calcolare il punto medio
3.	Funzione per calcolare la retta passante tra due punti. Dovrai anche definire la struct retta che contiene le informazioni necessarie ad identificare una retta e definire una funzione per stamparla in modo standard (y=mx+c)
4.	Funzione che verifica se tre punti sono allineati.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



### Voti degli studenti 1
{: .numerato_da_h3}

Scrivi un programma per gestire un corso. Al corso sono iscritte delle persone, massimo 30. Per ogni persona dovete sapere nome e cognome e ad ognuno alla fine del corso viene assegnato un voto da 1 a 10. Alla fine stampa tutti i dati di ogni studente, compresi i voti.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 


### Esploratori
{: .numerato_da_h3}

Completa il seguente programma in cui è stato dichiarato un array di stringhe in cui sono scritti nomi, cognomi e date di nascita e morte di esploratori famosi. Devi definire le strutture dati adeguate a contenere queste informazioni: una struct esploratore e un array di esploratori. Usa la funzione sscanf per leggere i dati dalla stringa dati e riempi le strutture dati da te definite. scrivi poi una serie di funzioni che lavorino sulle tue strutture dati:
1.	una funzione che stampa l'array di esploratori.
2.	una funzione che ordina l'array in ordine alfabetico secondo il nome degli esploratori
3.	una funzione che ordina l'array in ordine crescente secondo le date di nascita degli esploratori
Consigli e indicazioni extra:
1.	La funzione sscanf l'abbiamo usata pochissimo in passato ma trovate facilmente online indicazioni su come si usa.
2.	Alcuni potrebbero trovare comodo definire una struttura dati contenente l'array degli esploratori insieme al numero di esploratori contenuti nell'array.
Di seguito i dati da utilizzare:

```c
int main(){
	char dati[15][50] = {
		"Marco Polo 1254 1324",
		"Cristoforo Colombo 1451 1506",
		"Amerigo Vespucci 1454 1512",
		"Francisco Pizarro 1475 1541",
		"Ferdinando Magellano 1480 1521",
		"Hernan Cortez 1485 1547",
		"Walter Raleigh 1552 1618",
		"Henry Hudson 1570 1611",
		"James Cook 1728 1779",
		"Charles Darwin 1809 1882",
		"Kit Carson 1809 1866",
		"David Livingstone 1813 1873",
		"Charles Foucauld 1858 1916",
		"Ronald Amundsen 1872 1928",
		"Ernest Shakleton 1874 1922",
	};
}
```

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>

#define N 100

typedef struct {
    char nome[N];
    char cognome[N];
    int nascita, morte;
} esploratore;

void stampa(esploratore lista[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("- %s %s %d %d\n", lista[i].nome, lista[i].cognome,
               lista[i].nascita, lista[i].morte);
    }
}

void ordinaPerNome(esploratore lista[], int n) {
    int i, j;
    esploratore tmp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (strcmp(lista[j].nome, lista[j + 1].nome) > 0 ||
                (strcmp(lista[j].nome, lista[j + 1].nome) == 0 &&
                 strcmp(lista[j].cognome, lista[j + 1].cognome) > 0)) {
                tmp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = tmp;
            }
        }
    }
}
void ordinaPerNascita(esploratore lista[], int n) {
    int i, j;
    esploratore tmp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (lista[j].nascita > lista[j+1].nascita) {
                tmp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = tmp;
            }
        }
    }
}

int main() {
    char dati[15][50] = {
        "Marco Polo 1254 1324",           "Cristoforo Colombo 1451 1506",
        "Amerigo Vespucci 1454 1512",     "Francisco Pizarro 1475 1541",
        "Ferdinando Magellano 1480 1521", "Hernan Cortez 1485 1547",
        "Walter Raleigh 1552 1618",       "Henry Hudson 1570 1611",
        "James Cook 1728 1779",           "Charles Darwin 1809 1882",
        "Kit Carson 1809 1866",           "David Livingstone 1813 1873",
        "Charles Foucauld 1858 1916",     "Ronald Amundsen 1872 1928",
        "Ernest Shakleton 1874 1922",
    };

    esploratore lista[N];
    int nesploratori = 0;

    for (nesploratori = 0; nesploratori < 15; nesploratori++) {
        sscanf(dati[nesploratori], "%s %s %d %d", lista[nesploratori].nome,
               lista[nesploratori].cognome, &lista[nesploratori].nascita,
               &lista[nesploratori].morte);
    }

    printf("Prima stampa:\n");
    stampa(lista, nesploratori);

    ordinaPerNome(lista, nesploratori);
    printf("\n\nOrdinati per nome:\n");
    stampa(lista, nesploratori);

    ordinaPerNascita(lista, nesploratori);
    printf("\n\nOrdinati per nascita:\n");
    stampa(lista, nesploratori);
}
```

</details> 

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione alternativa (con struttura esploratori)
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>

#define N 100

typedef struct {
    char nome[N];
    char cognome[N];
    int nascita, morte;
} esploratore;

typedef struct {
    esploratore elenco[N];
    int n;
} esploratori;

void aggiungiEsploratore(esploratori lista, esploratore e) {
    lista.elenco[lista.n] = e;
    lista.n++;
}

void stampa(esploratori lista) {
    int i;
    for (i = 0; i < lista.n; i++) {
        printf("- %s %s %d %d\n", lista.elenco[i].nome, lista.elenco[i].cognome,
               lista.elenco[i].nascita, lista.elenco[i].morte);
    }
}

void ordinaPerNome(esploratori lista) {
    int i, j;
    esploratore tmp;

    for (i = 0; i < lista.n - 1; i++) {
        for (j = 0; j < lista.n - 1 - i; j++) {
            if (strcmp(lista.elenco[j].nome, lista.elenco[j + 1].nome) > 0 ||
                (strcmp(lista.elenco[j].nome, lista.elenco[j + 1].nome) == 0 &&
                 strcmp(lista.elenco[j].cognome, lista.elenco[j + 1].cognome) > 0)) {
                tmp = lista.elenco[j];
                lista.elenco[j] = lista.elenco[j + 1];
                lista.elenco[j + 1] = tmp;
            }
        }
    }
}

void ordinaPerNascita(esploratori lista) {
    int i, j;
    esploratore tmp;

    for (i = 0; i < lista.n - 1; i++) {
        for (j = 0; j < lista.n - 1 - i; j++) {
            if (lista.elenco[j].nascita > lista.elenco[j+1].nascita) {
                tmp = lista.elenco[j];
                lista.elenco[j] = lista.elenco[j + 1];
                lista.elenco[j + 1] = tmp;
            }
        }
    }
}

int main() {
    char dati[15][50] = {
        "Marco Polo 1254 1324",           "Cristoforo Colombo 1451 1506",
        "Amerigo Vespucci 1454 1512",     "Francisco Pizarro 1475 1541",
        "Ferdinando Magellano 1480 1521", "Hernan Cortez 1485 1547",
        "Walter Raleigh 1552 1618",       "Henry Hudson 1570 1611",
        "James Cook 1728 1779",           "Charles Darwin 1809 1882",
        "Kit Carson 1809 1866",           "David Livingstone 1813 1873",
        "Charles Foucauld 1858 1916",     "Ronald Amundsen 1872 1928",
        "Ernest Shakleton 1874 1922",
    };

    esploratori lista;

    for (lista.n = 0; lista.n < 15; lista.n++) {
        sscanf(dati[lista.n], "%s %s %d %d", lista.elenco[lista.n].nome,
               lista.elenco[lista.n].cognome, &lista.elenco[lista.n].nascita,
               &lista.elenco[lista.n].morte);
    }

    printf("Prima stampa:\n");
    stampa(lista);

    ordinaPerNome(lista);
    printf("\n\nOrdinati per nome:\n");
    stampa(lista);

    ordinaPerNascita(lista);
    printf("\n\nOrdinati per nascita:\n");
    stampa(lista);
}
```

</details> 



### Frazioni
{: .numerato_da_h3}

Scrivi e utilizza un insieme di funzioni da utilizzare per fare calcoli con le frazioni. In pratica devono essere definite le funzioni per fare almeno le 4 operazioni (magari anche altre operazioni). Deve anche essere fatta una funzione per effettuare la semplificazione delle frazioni (puoi decidere se creare e usare anche un'altra funzione mcd o utilizzare un altro metodo). Scrivi tutte queste funzioni in un file separato e poi utilizza queste funzioni per fare dei calcoli con le frazioni in un programma.	
In una prima versione del programma considera numeratore e denominatore come due variabili intere separate. In una seconda versione definisci invece una struct frazione che contiene numeratore e denominatore. Le funzioni dovranno essere modificate di conseguenza.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num, den;
} frazione;

void semplifica(frazione* f) {
    int n;
    int segno;
    if (f->num * f->den >= 0 ){
        segno = 1;
    } else {
        segno = -1;
    }
    f->num = abs(f->num);
    f->den = abs(f->den);
    for (n = 2; n <= f->num && n <= f->den; n++) {
        while (f->num % n == 0 && f->den % n == 0) {
            f->num /= n;
            f->den /= n;
        }
    }
    f->num *= segno;
}

frazione somma(frazione a, frazione b) {
    frazione c;
    c.num = a.num * b.den + b.num * a.den;
    c.den = a.den * b.den;
    semplifica(&c);
    return c;
}

frazione sottrai(frazione a, frazione b) {
    frazione c;
    c.num = a.num * b.den - b.num * a.den;
    c.den = a.den * b.den;
    semplifica(&c);
    return c;
}

frazione moltiplica(frazione a, frazione b) {
    frazione c;
    c.num = a.num * b.num;
    c.den = a.den * b.den;
    semplifica(&c);
    return c;
}

frazione dividi(frazione a, frazione b) {
    frazione c;
    c.num = a.num * b.den;
    c.den = a.den * b.num;
    semplifica(&c);
    return c;
}

int main() {
    frazione a, b, c;
    a.num = 1;
    a.den = 2;
    b.num = 3;
    b.den = -2;
    c = somma(a, b);
    printf("%d/%d + %d/%d = %d/%d\n", a.num, a.den, b.num, b.den, c.num , c.den);
    c = sottrai(a, b);
    printf("%d/%d - %d/%d = %d/%d\n", a.num, a.den, b.num, b.den, c.num , c.den);
    c = moltiplica(a, b);
    printf("%d/%d x %d/%d = %d/%d\n", a.num, a.den, b.num, b.den, c.num , c.den);
    c = dividi(a, b);
    printf("%d/%d : %d/%d = %d/%d\n", a.num, a.den, b.num, b.den, c.num , c.den);
}
```

</details> 




### Voti degli Studenti 2
{: .numerato_da_h3}

Scrivi un programma in cui è definita una struttura studente. Dello studente ci interessano il nome, i vori presi e la media dei voti. Il programma deve istanziare uno o più studenti e aggiungere una serie di voti casuali (anche mezzi voti ma non tutti i decimali possibili). Voglio creare uno studente e poi usare delle funzioni per aggiungere voti e calcolare la media. Infine stampare lo studente con tutti i suoi dati con una funzione apposita.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define N 50

typedef struct {
    char nome[N];
    char cognome[N];
    float voti[N];
    int nvoti;
    float media;
} studente;

void calcolaMedia(studente* stud) {
    int i;
    stud->media = 0;
    for (i = 0; i < stud->nvoti; i++) {
        stud->media += stud->voti[i];
    }
    stud->media /= stud->nvoti;
}

void stampaStudenti(studente elenco[], int nstudenti) {
    int i, j;
    for (i = 0; i < nstudenti; i++) {
        printf("- %s %s: ", elenco[i].cognome, elenco[i].nome);
        for (j = 0; j < elenco[i].nvoti; j++) {
            printf("%g ", elenco[i].voti[j]);
        }
        printf(" - media: %g\n", elenco[i].media);
    }
}

int main() {
    int i;
    studente elenco[N];
    int nstudenti;

    srand(time(NULL));

    strcpy(elenco[0].nome, "Filippo"); 
    strcpy(elenco[0].cognome, "Brambilla");
    elenco[0].nvoti = 0;
    for (i = 0; i<3; i++) {
        elenco[0].voti[i] = (rand() % 19 + 2) / 2.0;
        elenco[0].nvoti ++;
    }
    calcolaMedia(&elenco[0]);

    strcpy(elenco[1].nome, "Andrea"); 
    strcpy(elenco[1].cognome, "Garofoli");
    elenco[1].nvoti = 0;
    for (i = 0; i<3; i++) {
        elenco[1].voti[i] = (rand() % 19 + 2) / 2.0;
        elenco[1].nvoti ++;
    }
    calcolaMedia(&elenco[1]);

    nstudenti = 2;

    stampaStudenti(elenco, nstudenti);
}
```

</details> 




### Liste con gli array
{: .numerato_da_h3}

Crea una struttura, che chiamerai Lista, che gestisca un array di interi e contenga come dati oltre all’array anche due interi che indicano la capienza massima dell’array e il numero di valori effettivamente contenuti nell’array. Scrivi e utilizza poi le seguenti funzioni:
1.	Funzione per aggiungere un numero in fondo all’array
2.	Funzione per aggiungere un numero all’inizio dell’array (gli altri scalano)
3.	Funzione per aggiungere un numero in una posizione a piacere dell’array (gli altri numeri scalano)
4.	Funzione per eliminare il numero presente in una determinata posizione dell’array (non deve rimanere il buco)
5.	Funzione per concatenare due liste

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

#define N 1000

// 5.1.6    Crea una struttura, che chiamerai Lista, che gestisca un array di
// interi e contenga come dati oltre all’array anche due interi che indicano la
// capienza massima dell’array e il numero di valori effettivamente contenuti
// nell’array. Scrivi e utilizza poi le seguenti funzioni:
typedef struct {
    int a[N];
    int capienza;
    int n;
} Lista;

// 1.   Funzione per aggiungere un numero in fondo all’array
int push_back(Lista *l, int num) {
    if (l->n == l->capienza) {
        return 0;
    }
    l->a[l->n] = num;
    l->n++;
    return 1;
}

// 2.   Funzione per aggiungere un numero all’inizio dell’array (gli altri scalano) 
int push_front(Lista* l, int num) {
    int i;
    if (l->n == l->capienza) {
        return 0;
    }
    l->n++;
    for (i = l->n-1; i > 0; i--) {
        l->a[i] = l->a[i-1];
    }
    l->a[0] = num;
    return 1;
}

// 3.   Funzione per aggiungere un numero in una posizione a piacere
// dell’array (gli altri numeri scalano)
int push(Lista* l, int num, int pos) {
    int i;
    if (l->n == l->capienza || pos < 0 || pos >= l->n) {
        return 0;
    }
    l->n++;
    for (i = l->n-1; i > pos; i--) {
        l->a[i] = l->a[i-1];
    }
    l->a[pos] = num;
    return 1;
}

// 4.   Funzione per eliminare il numero
// presente in una determinata posizione dell’array (non deve rimanere il buco)
int pop(Lista* l, int pos) {
    int i;
    if (pos < 0 || pos >= l->n) {
        return 0;
    }
    for (i = pos; i < l->n-1; i++) {
        l->a[i] = l->a[i+1];
    }
    l->n--;
    return 1;
}

// 5.   Funzione per concatenare due liste
Lista concatena(Lista l1, Lista l2) {
    Lista ris = l1;
    int i;
    
    for (i = 0; i < l2.n && ris.n < ris.capienza; i++, ris.n++) {
        ris.a[ris.n] = l2.a[i];
    }

    return ris;
}

void stampa(Lista l) {
    int i;
    for (i = 0; i < l.n; i++) {
        printf("%d ", l.a[i]);
    }
    printf("\n");
}

int main() {
    Lista lista;
    Lista l2;
    lista.capienza = N;
    lista.n = 0;
    lista.capienza = N;
    lista.n = 0;

    push_back(&lista, 2);
    push_back(&lista, 3);
    push_back(&lista, 5);
    push_back(&lista, 6);
    push_front(&lista, 1);
    push_front(&lista, 0);
    push(&lista, 4, 4);
    pop(&lista, 3);
    push(&lista, 3, 3);

    stampa(lista);

}
```

</details> 




### Voti degli studenti 3
{: .numerato_da_h3}

Completa un programma che legga i dati contenuti in un array (riportato di seguito) e li inserisca in opportune strutture dati. Di questi dati il programma deve fare le seguenti cose:

1.	stamparli sullo schermo (con una funzione)
2.	ordinarli in ordine decrescente di voto (con una funzione)
3.	stamparli nuovamente in ordine (usando la funzione del punto 1)

Il programma da completare:

```c
#include <stdio.h>

int main() {
    char dati[][50] = {
        "Amici 7.00",
        "Biella 9.00",
        "Brescia 6.00",
        "Carolla 8.00",
        "Cunegatti 7.00",
        "DeBella 4.00",
        "DeVecchi 9.00",
        "Fumagalli 7.00",
        "Galimberti 9.00",
        "Germano 9.00",
        "Gubellini 9.00",
        "Lepore 5.00",
        "Maconi 6.00",
        "Mariani 8.00",
        "Mattavelli 9.00",
        "Oggiano 4.00",
        "Passoni 5.00",
        "Pastori 4.00",
        "Pirovano 7.00",
        "Rudi 10.00",
        "Russell 6.00",
        "Sogos 4.00",
        "Tezza 6.00",
        "Varisco 8.00",
    };
    int n = 24, i;
    for (i = 0; i < n; i++) {
        printf("%s\n", dati[i]);
    }
}
```


<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



### Giocatori di basket
{: .numerato_da_h3}

Chiedi all’utente i dati riguardanti i giocatori di una squadra di basket. I dati sono: nome, cognome, ruolo, numero di maglia e altezza. Dopo aver letto i dati stampa il quintetto più alto possibile che contenga tutti i ruoli he sono: playmaker, guardia, ala piccola, ala grande, centro.

Variante: Scrivi e usa una funzione che dato l’elenco e un ruolo, restituisce il giocatore più alto che ha quel ruolo.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>

#define N 100
#define M 20

typedef struct {
    char nome[N];
    char ruolo[M];
    int numero;
    int altezza;
} Giocatore;

void stampaGiocatore(Giocatore g) {
    printf("%30s %20s %4d %5d\n", g.nome, g.ruolo,
               g.numero, g.altezza);
}

void stampaLista(Giocatore elenco[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%30s %20s %4d %5d\n", elenco[i].nome, elenco[i].ruolo,
               elenco[i].numero, elenco[i].altezza);
    }
}

Giocatore scegli(Giocatore elenco[], int n, char ruolo[]) {
    int imax = -1;
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(elenco[i].ruolo, ruolo) == 0) {
            if (imax == -1 || elenco[i].altezza > elenco[imax].altezza) {
                imax = i;
            }
        }
    }
    if (imax == -1) {
        printf("Non ci sono giocatori con quel ruolo!!\n");
    }
    return elenco[imax];
}

void creaQuintetto(Giocatore elenco[], int n, Giocatore quintetto[]) {
    char ruoli[5][M] = {"playmaker", "guardia", "ala piccola", "ala grande", "centro"};
    int i;
    for (i = 0; i < 5; i++) {
        quintetto[i] = scegli(elenco, n, ruoli[i]); 
    }
}

int main() {
    Giocatore elenco[N], quintetto[5];
    int n = 0, i, risp;

    while (n < N) {
        printf("Vuoi inserire un giocatore? (1 si, 0 no)");
        scanf("%d", &risp);
        while (risp != 1 && risp != 0) {
            printf("Risposta non prevista\n");
            printf("Vuoi inserire un giocatore? (1 si, 0 no)");
            scanf("%d", &risp);
        }
        if (risp == 0) {
            break;
        } else {
            printf("Scrivi il nome (e cognome): ");
            scanf(" %99[^\n]", elenco[n].nome);
            printf("Scrivi il ruolo: ");
            scanf(" %19[^\n]", elenco[n].ruolo);
            printf("Scrivi il numero di maglia: ");
            scanf(" %d", &elenco[n].numero);
            printf("Scrivi l'altezza (in cm): ");
            scanf(" %d", &elenco[n].altezza);
            n++;
        }
    }
    i = 0;
    // printf("%30s, %20s, %2d, %3d\n", elenco[i].nome, elenco[i].ruolo,
    //            elenco[i].numero, elenco[i].altezza);
    printf("\nElenco dei giocatori inseriti:\n");
    stampaLista(elenco, n);

    printf("\n\n");
    stampaGiocatore(scegli(elenco, n, "ala piccola"));

    printf("\nStampa del quintetto piu' alto:\n");
    creaQuintetto(elenco, n, quintetto);
    stampaLista(quintetto, 5);
}
```

</details> 






<!-- per una nuova soluzione

#### 
{: .numerato_da_h3}



<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 

-->






<!-- 
<script src="{{site.baseurl}}/assets/js/esercizi-subnetting.js"></script> -->




