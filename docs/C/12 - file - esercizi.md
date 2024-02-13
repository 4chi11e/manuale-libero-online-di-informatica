---
layout: default
title: File - Esercizi
nav_order: 12
parent: Programmazione in C
has_children: False
---

# File - Esercizi
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

### Lettura e scrittura
{: .numerato_da_h3}

Scrivi un programma che scriva su un file un elenco di nomi, chiuda il file, lo riapra in lettura lo legga tutto e stampi ciò che ha letto.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



### Conteggio caratteri o lettere
{: .numerato_da_h3}

Scrivi e usa una funzione che conta il numero di caratteri contenuti in un file.

Variante: Conta le lettere, non i caratteri.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int contachar(char nomefile[]) {
    char carattere;
    int numchar = 0;
    FILE *fp = fopen(nomefile, "r");
    if (fp == NULL) {
        printf("File \"%s\" non trovato\n", nomefile);
        return 1;
    }

    while(!feof(fp)) {
        fscanf(fp, "%c ", &carattere);
        numchar++;
    }
    fclose(fp);
    return numchar;
}

int contalettere(nomefile) {
    char carattere;
    int numlettere = 0;
    FILE *fp = fopen(nomefile, "r");
    if (fp == NULL) {
        printf("File \"%s\" non trovato\n", nomefile);
        return 1;
    }

    while(!feof(fp)) {
        fscanf(fp, "%c ", &carattere);
        if ((carattere >= 'a' && carattere <= 'z') || (carattere >= 'A' && carattere <= 'Z')) {
            numlettere++;
        }
    }
    fclose(fp);
    return numlettere;
}

int main() {
    FILE *fp;
    char nomefileinput[] = "1-2.txt";
    int numchar;
    int numlettere;

    numchar = contachar(nomefileinput);
    numlettere = contalettere(nomefileinput);
    printf("Il numero di caratteri contenuti nel file: %d\n", numchar);
    printf("Il numero di lettere contenute nel file: %d\n", numlettere);
}
```

</details> 



### Numero di righe e numero di caratteri o lettere per riga
{: .numerato_da_h3}

Scrivi una funzione che conta e restituisce il numero di righe di un file.	 
Scrivi poi un'altra funzione che calcola per ogni riga il numero di caratteri contenuti nella riga. I valori vanno inseriti in un array o un vettore da restituire al main.

Variante complicata che prevede l’uso di strtok: invece dei caratteri conta il numero di parole per riga

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione senza variante
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>

#define N 200

int contaCaratteri(char riga[]) {
    return strlen(riga);
}

int contaLettere(char riga[]) {
    int ris = 0, i;
    for (i = 0; riga[i] != 0; i++) {
        if ((riga[i] >= 'a' && riga[i] <= 'z') || (riga[i] >= 'A' && riga[i] <= 'Z')) {
            ris++;
        }
    }
    return ris;
}

int main() {
    FILE *fp;
    char riga[N];
    int i;

    fp = fopen("6-1-3.txt", "r");
    if (fp == NULL) {
        printf("Errore nell'apertura del file.\n");
        return 1;
    }

    for (i = 0; !feof(fp); i++) {
        fgets(riga, N-1, fp);
        printf("La riga %d contiene %d lettere\n", i+1, contaLettere(riga));
    }

    fclose(fp);
}
```

</details> 



### Numero di parole
{: .numerato_da_h3}

Scrivi e usa una funzione che conta il numero di parole contenute in un file.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>

#define N 200

int contaParole(char nomefile[]) {
    FILE *fp;
    char parola[N];
    int ris;

    fp = fopen(nomefile, "r");
    if (fp == NULL) {
        printf("Errore nell'apertura del file.\n");
        return 1;
    }

    for (ris = 0; !feof(fp); ris++) {
        fscanf(fp, "%s", parola);
    }

    fclose(fp);

    return ris;
}

int main() {
    char nomefile[] = "6-1-3.txt";
    int nparole = contaParole(nomefile);
    printf("Nel file %s sono contenute %d parole", nomefile, nparole);
}
```

</details> 



### Modifica file e ordina parole
{: .numerato_da_h3}

Scrivi e usa una funzione che legga un file e scriva in un altro file tutte le parole del primo file in ordine alfabetico

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>

#define N 1000
#define M 50

void bsort(char parole[N][M], int nparole) {
    int i, j;
    char tmp[M];
    for (i = 0; i < nparole-1; i++) {
        for (j = 0; j < nparole-1-i; j++) {
            if (strcmp(parole[j], parole[j+1]) > 0) {
                strcpy(tmp, parole[j]);
                strcpy(parole[j], parole[j+1]);
                strcpy(parole[j+1], tmp);
            }
        }
    }
}

int main() {
    FILE *fp;
    char parole[N][M];
    int nparole, i;

    fp = fopen("6-1-5-in.txt", "r");
    if (fp == NULL) {
        printf("Errore nell'apertura nel file.\n");
        return 1;
    }

    for (nparole = 0; !feof(fp); nparole++) {
        fscanf(fp, "%s", parole[nparole]);
    }
    fclose(fp);

    bsort(parole, nparole);

    fp = fopen("6-1-5-out.txt", "w");
    if (fp == NULL) {
        printf("Errore nell'apertura nel file in scrittura.\n");
        return 1;
    }

    for (i = 0; i < nparole; i++) {
        fprintf(fp, "%s\n", parole[i]);
    }

}
```

</details> 




### Lettura e scrittura modificata
{: .numerato_da_h3}

Scrivi un programma che legga un file di testo e che scriva in un secondo file, lo stesso testo modificato in modo che tutte le lettere siano minuscole. Il file di testo iniziale generalo tu come vuoi.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

int main() {
    FILE *fpin, *fpout;
    char carattere;

    fpin = fopen("6-1-6-in.txt", "r");
    if (fpin == NULL) {
        printf("Errore nell'apertura nel file.\n");
        return 1;
    }

    fpout = fopen("6-1-6-out.txt", "w");
    if (fpout == NULL) {
        printf("Errore nell'apertura nel file in scrittura.\n");
        return 1;
    }

    while (!feof(fpin)) {
        fscanf(fpin, "%c", &carattere);
        if (carattere >= 'A' && carattere <= 'Z') {
            carattere += ('a'-'A');
        }
        printf("%c", carattere);
        fprintf(fpout, "%c", carattere);
    }

    fclose(fpin);
    fclose(fpout);
}
```

</details> 



### Lettura e aggiunta
{: .numerato_da_h3}

Scrivi un programma che legga un file di testo e che aggiunga alla fine di tale file, dopo un paio di righe vuote, lo stesso testo modificato in modo che tutte le lettere siano minuscole. Il file di testo iniziale generalo tu come vuoi. Attento a fare in modo che se il programma viene eseguito più volte, le righe da considerare sono solo quelle iniziali.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 


### Modifica file
{: .numerato_da_h3}

Scrivi una funzione parametrica in grado di modificare un file di testo di nome "miofile.txt" letto da disco in modo tale che, se l'ultimo elemento della linea è una virgola, la linea successiva venga eliminata

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



### Scrittura e ricerca
{: .numerato_da_h3}

Scrivi un programma che scriva su un file un elenco di nomi (o numeri se preferisci), chieda poi all'utente un nome da cercare nel file e stampi sullo schermo l'esito della ricerca (trovato o no). Le operazioni di scrittura su file devono essere eseguite da una funzione che riceve come parametro la stringa contenente il nome del file. Le operazioni di ricerca devono essere svolte da una funzione che riceve come parametro la stringa contenente il nome del file e la stringa da cercare.
1.	Continua l'esercizio aggiungendo una funzione che dato il nome del file e il numero di riga, cerca, se esiste, la riga e la restituisce.
2.	Aggiungi anche la possibilità di chiedere all'utente se vuole aggiungere dei nomi a quelli già presenti (aprendo poi il file in modalità append e aggiungendo i nomi dati dall'utente)

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

# define N 100

int scriviNomi(char nomefile[]) {
    FILE *fp;
    int i;
    fp = fopen("6-1-9-1.txt", "w");
    if (fp == NULL) {
        return 1;
    }
    for (i = 0; i < 20; i++) {
        fprintf(fp, "%d\n", rand() % 100);
    }
    fclose(fp);
    return 0;
}

int cercaNumero(char nomefile[], int numero) {
    FILE *fp;
    int numfile;
    fp = fopen("6-1-9-1.txt", "r");
    if (fp == NULL) {
        return -1;
    }
    while (!feof(fp)) {
        fscanf(fp, "%d", &numfile);
        if (numfile == numero) {
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int getRiga(char nomefile[], int numriga, char ris[]) {
    FILE *fp;
    int i;
    char riga[N];
    fp = fopen("6-1-9-1.txt", "r");
    if (fp == NULL) {
        return -1;
    }

    fgets(riga, N, fp);
    for (i = 1; !feof(fp); i++) {
        if (i == numriga) {
            strcpy(ris, riga);
            return 1;
        }
        fgets(riga, N, fp);
    }

    return 0;
}

int aggiungiRoba(char nomefile[], char roba[]) {
    FILE *fp;
    fp = fopen("6-1-9-1.txt", "a");
    if (fp == NULL) {
        return -1;
    }
    fprintf(fp, "\n%s", roba);
    fclose(fp);
}

int main() {
    int i, j, numero, ris, numriga;
    char nomefile[] = "6-1-9-1.txt";
    char riga[N];
    srand(time(NULL));
    if(scriviNomi(nomefile)) {
        printf("Errore nella scrittura del file. ");
        return 1;
    }
    
    printf("Che numero vuoi cercare? ");
    scanf("%d", &numero);

    ris = cercaNumero(nomefile, numero);
    if (ris == -1) {
        printf("Errore nell'apertura del file.\n");
    }
    if (ris == 1) {
        printf("Il numero e' stato trovato\n");
    } else {
        printf("Il numero non e' stato trovato\n");
    }

    // punto 1
    printf("\nChe riga vuoi? ");
    scanf("%d", &numriga);
    ris = getRiga(nomefile, numriga, riga);
    if (ris == -1) {
        printf("Errore nell'apertura del file.\n");
    }
    if (ris == 0) {
        printf("La riga non esiste\n");
    } else {
        printf("Riga %d: %s\n", numriga, riga);
    }

    // punto 2
    printf("\nVuoi aggiungere qualcosa al file? (0 no, altro sì)");
    scanf("%d", &ris);
    if (ris != 0) {
        printf("Scrivi che cosa vuoi aggiungere: ");
        scanf(" %99[^\n]", riga);
        aggiungiRoba(nomefile, riga);
    }

}
```

</details> 




### Esploratori 1
{: .numerato_da_h3}

Leggi i dati contenuti nel seguente file di testo. Dopo averli salvati in un’opportuna struttura dati, scrivi due funzioni:
1.	Funzione che riceve i dati e restituisce l’esploratore che ha vissuto più a lungo
2.	Funzione che ordina gli esploratori in ordine decrescente di età di morte.

```
Marco Polo 1254 1324
Cristoforo Colombo 1451 1506
Amerigo Vespucci 1454 1512
Francisco Pizarro 1475 1541
Ferdinando Magellano 1480 1521
Hernan Cortez 1485 1547
Walter Raleigh 1552 1618
Henry Hudson 1570 1611
James Cook 1728 1779
Charles Darwin 1809 1882
Kit Carson 1809 1866
David Livingstone 1813 1873
Charles Foucauld 1858 1916
Ronald Amundsen 1872 1928
Ernest Shakleton 1874 1922
```

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



### Voti studenti 1
{: .numerato_da_h3}

Scrivi un programma che legga i dati contenuti in un file di testo (testo riportato di seguito) e li inserisca in opportune strutture dati (richiesta la conoscenza delle struct o delle classi). Di questi dati il programma deve fare le seguenti cose:

1.	stamparli sullo schermo
2.	ordinarli in ordine decrescente di voto
3.	stamparli nuovamente in ordine
4.	scriverli in ordine in un secondo file che puoi nominare come vuoi

Dati da mettere nel file di testo:

```
Amici	7.00
Biella	9.00
Brescia	6.00
Carolla	8.00
Cunegatti	7.00
DeBella	4.00
DeVecchi	9.00
Fumagalli	7.00
Galimberti	9.00
Germanò	9.00
Gubellini	9.00
Lepore	5.00
Maconi	6.00
Mariani	8.00
Mattavelli	9.00
Oggiano	4.00
Passoni	5.00
Pastori	4.00
Pirovano	7.00
Rudi	10.00
Russell	6.00
Sogos	4.00
Tezza	6.00
Varisco	8.00
```

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



### Voti studenti 2
{: .numerato_da_h3}

Scrivi un programma che legga i dati contenuti in un file di testo (testo riportato di seguito) e li inserisca in opportune strutture dati che rappresentino il registro dei voti per una materia. Il programma deve poi calcolare la media dei voti per ogni singolo studente e aggiungerla alla struttura dati (che quindi conterrà anche una variabile media). Il programma deve mostrare tutti i dati raccolti e calcolati sullo schermo e salvarli in un secondo file di testo.

```
Amici 7.00 8.00 7.00
Biella 8.00 9.50 7.00
Brescia 5.00 7.50 9.00
Carolla 7.00 8.50 8.50
Cunegatti 7.00 7.00 5.50
DeBella 4.00 4.00 4.50
DeVecchi 8.00 10.00 6.00
Fumagalli 8.50 6.00 4.50
Galimberti 9.00 9.00 9.00
Germanò 8.50 9.00 7.50
Gubellini 8.00 10.00 7.00
Lepore 5.50 4.00 3.00
Maconi 7.50 5.00 7.50
Mariani 8.00 8.00 7.00
Mattavelli 9.00 9.50 8.50
Oggiano 5.00 3.00 3.00
Passoni 5.00 6.00 6.00
Pastori 3.50 5.00 7.00
Pirovano 6.50 7.50 7.50
Rudi 9.50 10.00 10.00
Russell 7.50 4.50 5.50
Sogos 4.00 3.50 3.50
Tezza 7.00 5.50 5.50
Varisco 8.00 9.00 8.50
```

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

#define N 50

typedef struct {
    char cognome[N];
    float voti[N];
    int nvoti;
} Studente;

int main() {
    FILE *fp;
    Studente elenco[N];
    int nstudenti = 0;

    fp = fopen("6-2-3.txt", "r");
    if (fp == NULL) {
        printf("errore");
        return 1;
    }

    for (nstudenti = 0; !feof(fp); nstudenti++) {
        fscanf(fp, "%s %f %f %f", elenco[nstudenti].cognome,
               &elenco[nstudenti].voti[0], &elenco[nstudenti].voti[1],
               &elenco[nstudenti].voti[2]);
    }
    fclose(fp);

    for (int i = 0; i < nstudenti; i++) {
        printf("%12s %4.1f %4.1f %4.1f\n", elenco[i].cognome,
               elenco[i].voti[0], elenco[i].voti[1],
               elenco[i].voti[2]);
    }
}
```

</details> 



### Voti studenti 3
{: .numerato_da_h3}

Scrivi un programma che legga i dati contenuti in un file di testo (testo riportato di seguito) e li inserisca in opportune strutture dati che rappresentino il registro dei voti per una materia. Il programma deve poi calcolare la media dei voti per ogni singolo studente e aggiungerla alla struttura dati (che quindi conterrà anche una variabile media). Il programma deve mostrare tutti i dati raccolti e calcolati sullo schermo e salvarli in un secondo file di testo. Questa versione del programma è più difficile della precedente perché si può notare che i cognomi possono essere formati da più parole e sono separati dai voti da un “:”, inoltre il numero di voti varia per ogni studente.

```
Amici: 7.00 8.00 7.00
Biella: 8.00 9.50 7.00
Brescia: 5.00 7.50 9.00
Carolla: 7.00 8.50 8.50
Cunegatti: 7.00 7.00
De Bella: 4.00 4.00 4.50 5.00
De Vecchi: 8.00 10.00 6.00
Fumagalli: 8.50 6.00 4.50
Galimberti: 9.00 9.00 9.00
Germanò: 8.50 9.00 7.50
Gubellini: 8.00 10.00 7.00
Lepore: 5.50 4.00 3.00 5.00
Maconi: 7.50 5.00
Mariani: 8.00 8.00 7.00
Mattavelli: 9.00 9.50 8.50
Oggiano: 5.00 3.00 3.00 2.00
Passoni: 5.00 6.00 6.00 7.50
Pastori: 3.50 5.00 7.00 2.00
Pirovano: 6.50 7.50 7.50
Rudi: 9.50 10.00 10.00
Russell: 7.50 4.50
Sogos: 4.00 3.50 3.50 2.00
Tezza: 7.00 5.50 5.50
Varisco: 8.00 9.00 8.50
Pirovano: 6.50 7.50 7.50
Rudi: 9.50 10.00 10.00
Russell: 7.50 4.50 5.50
Sogos: 4.00 3.50 3.50
Tezza: 7.00 5.50 5.50
Varisco: 8.00 9.00 8.50
```

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione con l'uso di sscanf
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>

#define N 50
#define M 200

typedef struct {
    char cognome[N];
    float voti[N];
    float media;
    int nvoti;
} Studente;

int main() {
    FILE *fp;
    Studente elenco[N];
    int nstudenti = 0;
    char riga[M], *token;
    int ntoken;
    int i, j;

    fp = fopen("6-2-4.txt", "r");
    if (fp == NULL) {
        printf("errore");
        return 1;
    }

    for (nstudenti = 0; !feof(fp); nstudenti++) {
        fgets(riga, M, fp);

        ntoken = sscanf(riga, "%[^:]: %f %f %f %f", elenco[nstudenti].cognome,
                       &elenco[nstudenti].voti[0], &elenco[nstudenti].voti[1],
                       &elenco[nstudenti].voti[2], &elenco[nstudenti].voti[3]);
        elenco[nstudenti].nvoti = ntoken-1;
    }
    fclose(fp);

    // calcolo della media
    for (i = 0; i < nstudenti; i++) {
        elenco[i].media = 0;
        for (j = 0; j < elenco[i].nvoti; j++) {
            elenco[i].media += elenco[i].voti[j];
        }
        elenco[i].media /= elenco[i].nvoti;
    }

    // stampo tutto con una funzione
    for (i = 0; i < nstudenti; i++) {
        printf("Studente: %12s - Media: %5.2f - Voti: ", elenco[i].cognome,
               elenco[i].media);
        for (j = 0; j < elenco[i].nvoti; j++) {
            printf("%3.1f ", elenco[i].voti[j]);
        }
        printf("\n");
    }

    // scrivo in un secondo file
    fp = fopen("6-2-4-out.txt", "w");
    if (fp == NULL) {
        printf("Apertura in scrittura del file fallita.\n");
        return 2;
    }
    for (i = 0; i < nstudenti; i++) {
        fprintf(fp, "%s: ", elenco[i].cognome);
        for (j = 0; j < elenco[i].nvoti; j++) {
            fprintf(fp, "%.2f ", elenco[i].voti[j]);
        }
        fprintf(fp, "- %.2f ", elenco[i].media);
        fprintf(fp, "\n");
    }
    fclose(fp);
}
```

</details> 

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione con l'uso di strtok
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>

#define N 50
#define M 200

typedef struct {
    char cognome[N];
    float voti[N];
    float media;
    int nvoti;
} Studente;

int main() {
    FILE *fp;
    Studente elenco[N];
    int nstudenti = 0;
    char riga[M], *token;
    int nvoti;
    int i, j;

    fp = fopen("6-2-4.txt", "r");
    if (fp == NULL) {
        printf("errore");
        return 1;
    }

    for (nstudenti = 0; !feof(fp); nstudenti++) {
        fgets(riga, M, fp);
        token = strtok(riga, ":");
        strcpy(elenco[nstudenti].cognome, token);
        // printf("%s ", elenco[nstudenti].cognome);

        token = strtok(NULL, " ");
        
        for (elenco[nstudenti].nvoti = 0; token != NULL; elenco[nstudenti].nvoti += 1) {
            nvoti = elenco[nstudenti].nvoti;
            sscanf(token, "%f", &elenco[nstudenti].voti[nvoti]);
            // printf("%g ", elenco[nstudenti].voti[nvoti]);
            token = strtok(NULL, " ");
        }
        printf("\n");
    }
    fclose(fp);

    // calcolo della media
    for (i = 0; i < nstudenti; i++) {
        elenco[i].media = 0;
        for (j = 0; j < elenco[i].nvoti; j++) {
            elenco[i].media += elenco[i].voti[j];
        }
        elenco[i].media /= elenco[i].nvoti;
    }

    // stampo tutto con una funzione
    for (i = 0; i < nstudenti; i++) {
        printf("Studente: %12s - Media: %5.2f - Voti: ", elenco[i].cognome, elenco[i].media);
        for (j = 0; j < elenco[i].nvoti; j++) {
            printf("%3.1f ", elenco[i].voti[j]);
        }
        printf("\n");
    }

    // scrivo in un secondo file
    fp = fopen("6-2-4-out.txt", "w");
    if (fp == NULL) {
        printf("Apertura in scrittura del file fallita.\n");
        return 2;
    }
    for (i = 0; i < nstudenti; i++) {
        fprintf(fp, "%s: ", elenco[i].cognome);
        for (j = 0; j < elenco[i].nvoti; j++) {
            fprintf(fp, "%.2f ", elenco[i].voti[j]);
        }
        fprintf(fp, "- %.2f ", elenco[i].media);
        fprintf(fp, "\n");
    }
    fclose(fp);
}
```

</details> 



### Libri
{: .numerato_da_h3}

Leggi le informazioni riguardanti una serie di libri da un file (testo di seguito) e:
1.	carica i dati in un array di libri (definisci un'apposita struttura libro)
2.	ordina i libri per data di scrittura e riscrivili in un altro file nello stesso formato del file originale
3.	scrivi e usa una funzione che riceve i dati già caricati e che restituisce il libro più recente
4.	scrivi e usa una funzione che restituisca il secolo in cui sono stati scritti più libri

```
Divina Commedia;Dante Alighieri;1321
Promessi Sposi;Alessandro Manzoni;1840
Il Decamerone;Alessandro Boccaccio;1350
L'Orlando Furioso;Ludovico Ariosto;1516
Il fu Mattia Pascal;Luigi Pirandello;1904
Ultime lettere di Jacopo Ortis,Ugo Foscolo;1802
Se questo è un uomo;Primo Levi;1947
Il barone rampante;Italo Calvino;1957
I Malavoglia;Giovanni Verga;1881
Il Principe; Niccolò Macchiavelli;1532
La Gerusalemme Liberata;Torquato Tasso;1581
Cuore;Edmondo De Amicis;1886
Il deserto dei Tartari;Dino Buzzati;1940
La coscienza di Zeno;Italo Svevo;1923
Pinocchio;Carlo Collodi;1883
Il piacere;Gabriele D'Annunzio;1889
Myricae;Giovanni Pascoli;1891
Canti;Giacomo Leopardi;1831
Uno, nessuno e centomila;Luigi Pirandello;1926
Il nome della rosa;Umberto Eco;1980
La casa in collina;Cesare Pavese;1948
Il gattopardo;Giuseppe Tomasi di Lampedusa;1958
I Vicerè;Federico De Roberto;1894
Mastro don Gesualdo;Giovanni Verga;1889
```

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>

# define N 100

typedef struct {
    char titolo[N];
    char autore[N];
    int anno;
} libro;

void stampaElenco(libro elenco[], int nlibri) {
    int i;
    for (i = 0; i < nlibri; i++) {
        printf("%s;%s;%d\n", elenco[i].titolo, elenco[i].autore, elenco[i].anno);
    }
}

void ordina(libro elenco[], int nlibri) {
    int i, j;
    libro tmp;
    for (i = 0; i < nlibri-1; i++) {
        for (j = 0; j < nlibri - 1 - i; j++) {
            if (elenco[j].anno > elenco[j+1].anno) {
                tmp = elenco[j];
                elenco[j] = elenco[j+1];
                elenco[j+1] = tmp;
            }
        }
    }
}

void scriviSuFile(libro elenco[], int nlibri, char nomefile[]) {
    FILE *fp;
    int i;
    fp = fopen(nomefile, "w");
    if (fp == NULL) {
        printf("Errore scrittura");
        return;
    }

    for (i = 0; i < nlibri; i++) {
        fprintf(fp, "%s;%s;%d\n", elenco[i].titolo, elenco[i].autore, elenco[i].anno);
    }
    printf("Scrittura completata\n");
}

libro piuRecente(libro elenco[], int nlibri) {
    int i, imax;
    imax = 0;
    for (i = 1; i < nlibri; i++) {
        if (elenco[i].anno > elenco[imax].anno) {
            imax = i;
        }
    }
    return elenco[imax];
}

int secoloConPiuLibri(libro elenco[], int nlibri) {
    int secoli[21];
    int i, secolo, imax;

    for (i = 0; i < 21; i++) {
        secoli[i] = 0;
    }

    for (i = 0; i < nlibri; i++) {
        secolo = elenco[i].anno / 100;
        secoli[secolo]++;
    }

    imax = 0;
    for (i = 0; i < 21; i++) {
        if (secoli[i] > secoli[imax]) {
            imax = i;
        }
    }
    return imax*100; 
}

int main() {
    FILE *fp;
    char riga[200];
    libro elenco[N], recente;
    int nlibri;
    int i, j;

    fp = fopen("6-2-5.txt", "r");
    if (fp == NULL) {
        printf("Errore");
        return 1;
    }

    for (nlibri = 0; !feof(fp); nlibri++) {
        fgets(riga, 200, fp);
        sscanf(riga, "%[^;];%[^;];%d", elenco[nlibri].titolo, elenco[nlibri].autore, &elenco[nlibri].anno);
    }

    // stampa di controllo di tutti i dati
    printf("Elenco originale:\n");
    stampaElenco(elenco, nlibri);

    ordina(elenco, nlibri);
    printf("\n\nElenco ordinato:\n");
    stampaElenco(elenco, nlibri);

    scriviSuFile(elenco, nlibri, "6-2-5-out.txt");

    recente = piuRecente(elenco, nlibri);
    printf("\n\nIl libro piu' recente: %s;%s;%d\n", recente.titolo, recente.autore, recente.anno);

    printf("\n\nIl secolo con piu' libri e' il %d", secoloConPiuLibri(elenco, nlibri));
}
```

</details> 



### Punti e triangoli
{: .numerato_da_h3}

Scrivi un programma che sia in grado di leggere da file i dati riportati di seguito e salvarli in opportune strutture dati (punto e triangolo). Il programma deve poi stampare sia su schermo che in un altro file i dati riguardanti ogni triangolo e se esso è scaleno, isoscele o equilatero. Per decidere il tipo di triangolo devono essere usate tre diverse funzioni che controllano ognuna se il triangolo passato come parametro è di uno dei tre tipi richiesti.

Input
```
(1, 0) (3, 3) (-0.6, 3.23)
(1, 0) (1, 4) (-2.46, 2)
(2, 0) (5, 3) (2, 6)
(3, 0) (4.4, 3.3) (2.35, 4.8)
(2, 2) (4, 2) (4, 6)
```

Output
```
(1.000000, 0.000000) (3.000000, 3.000000) (-0.600000, 3.230000) - equilatero
(1.000000, 0.000000) (1.000000, 4.000000) (-2.460000, 2.000000) - equilatero
(2.000000, 0.000000) (5.000000, 3.000000) (2.000000, 6.000000) - isoscele
(3.000000, 0.000000) (4.400000, 3.300000) (2.350000, 4.800000) - scaleno
(2.000000, 2.000000) (4.000000, 2.000000) (4.000000, 6.000000) – scaleno
```

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



### Virologi
{: .numerato_da_h3}

Il seguente testo (che devi inserire in un file di testo) descrive i più celebri virologi Italiani nell'epoca covid

```
(Nome e Cognome - Ospedale - città - (O) Ottimista (P) Pessimista)
Roberto Burioni - San Raffaele - Milano (P)
Matteo Bassetti - San Martino - Genova (O)
Alberto Zangrillo - San Raffaele - Milano (O)
Massimo Galli - Luigi Sacco - Milano (P)
MariaRita Gismondo - Luigi Sacco - Milano (O)
Andrea Crisanti - Università di Padova - Padova (P)
Ilaria Capua - One Health - Florida (P)
Antonella Viola - Città della Speranza - Padova (P)
Fabrizio Pregliasco - Galeazzi - Milano (O)
Walter Ricciardi - Policlino Gemelli - Roma (P)
Franco Locatelli - Bambin Gesù - Roma (P)
```

1.	stampare nome e cognome dei virologi ordinati per cognome;
2.	stampare il numero di virologi ottimisti e di quelli pessimisti.

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
#define M 300

typedef struct {
    char nome[N];
    char cognome[N];
    char ospedale[N];
    char citta[N];
    char orientamento;
} virologo;

// funzione di confronto, cosa che non avete visto, da spiegare
int confrontaVirologi(const void *a, const void *b) {
    return strcmp(((virologo *)a)->cognome, ((virologo *)b)->cognome);
}

// ordinamento con bubble sort standard
void ordinaVirologi(virologo lista[], int n) {
    int i, j;
    virologo tmp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (strcmp(lista[j].cognome, lista[j + 1].cognome) > 0) {
                tmp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = tmp;
            }
        }
    }
}

int main() {
    FILE *fp;
    virologo lista[N];
    char riga[M];
    int nvirologi, i;

    fp = fopen("6-2-7.txt", "r");
    if (fp == NULL) {
        printf("Errore\n");
        return 1;
    }

    for (i = 0; !feof(fp); i++) {
        fgets(riga, M, fp);
        if (strlen(riga) > 0) {
            sscanf(riga, "%s %s - %[^-]- %s (%c)", lista[i].nome,
                   lista[i].cognome, lista[i].ospedale, lista[i].citta,
                   &lista[i].orientamento);
            // printf("%s %s - %s - %s (%c)\n", lista[i].nome, lista[i].cognome,
            //    lista[i].ospedale, lista[i].citta, lista[i].orientamento);
        }
    }
    nvirologi = i;

    // 1.   stampare nome e cognome dei virologi ordinati per cognome;
    qsort(lista, nvirologi, sizeof(virologo), confrontaVirologi);
    // ordinaVirologi(lista, nvirologi);
    for (i = 0; i < nvirologi; i++) {
        printf("%s %s - %s - %s (%c)\n", lista[i].nome, lista[i].cognome,
               lista[i].ospedale, lista[i].citta, lista[i].orientamento);
    }

    // 2.   stampare il numero di virologi ottimisti e di quelli pessimisti.
    int ottimisti = 0, pessimisti = 0;
    for (i = 0; i < nvirologi; i++) {
        if (lista[i].orientamento == 'O') {
            ottimisti++;
        } else if (lista[i].orientamento == 'P') {
            pessimisti++;
        }
    }
    printf("\nOttimisti: %d\nPessimisti: %d\n", ottimisti, pessimisti);
}

```

</details> 



### Esploratori 2
{: .numerato_da_h3}

Un file di testo contiene i seguenti dati:

```
Marco Polo 1254 1324
Cristoforo Colombo 1451 1506
Amerigo Vespucci 1454 1512
Francisco Pizarro 1475 1541
Ferdinando Magellano 1480 1521
Hernan Cortez 1485 1547
Walter Raleigh 1552 1618
Henry Hudson 1570 1611
James Cook 1728 1779
Charles Darwin 1809 1882
Kit Carson 1809 1866
David Livingstone 1813 1873
Charles Foucauld 1858 1916
Ronald Amundsen 1872 1928
Ernest Shakleton 1874 1922
```

Scrivi un programma che legga i dati contenuti nel file, li memorizzi opportunamente, e poi scrivi e utilizza le seguenti funzioni:
1.	una funzione che stampa tutti i dati.
2.	una funzione che ordina i dati in ordine alfabetico secondo il nome degli esploratori
3.	una funzione che ordina i dati in ordine crescente secondo le date di nascita degli esploratori
4.	una funzione che calcola la durata della vita di ogni esploratore e aggiunge questo dato agli altri
5.	una funzione che ordina gli esploratori in base alla durata della loro vita in ordine decrescente e in caso di parità in ordine crescente secondo la data di nascita
6.	una funzione che riscrive tutti i dati in un secondo file

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
#define M 300

typedef struct {
    char nome[N];
    char cognome[N];
    int nascita, morte, durata;
} esploratore;

// 4.     una
// funzione che calcola la durata della vita di ogni esploratore e aggiunge questo
// dato agli altri
void calcolaEta(esploratore elenco[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        elenco[i].durata = elenco[i].morte - elenco[i].nascita;
    }
}

// 1.     una
// funzione che stampa tutti i dati.
void stampaElenco(esploratore elenco[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%s %s %d %d %d\n", elenco[i].nome, elenco[i].cognome, elenco[i].nascita, elenco[i].morte, elenco[i].durata);
    }
}

// 2.     una
// funzione che ordina i dati in ordine alfabetico secondo il nome degli
// esploratori
int confAlfabetico(void *a, void *b) {
    return strcmp(((esploratore *)a)->nome, ((esploratore *)b)->nome);
}

// 3.     una
// funzione che ordina i dati in ordine crescente secondo le date di nascita degli
// esploratori
// 4.     una
// funzione che calcola la durata della vita di ogni esploratore e aggiunge questo
// dato agli altri
// 5.     una
// funzione che ordina gli esploratori in base alla durata della loro vita in
// ordine decrescente e in caso di parità in ordine crescente secondo la data di
// nascita
// 6.     una
// funzione che riscrive tutti i dati in un secondo file

int main() {
    FILE *fp;
    esploratore lista[N];
    char riga[M];
    int  i, nesploratori,letti;

    fp = fopen("6-2-8.txt", "r");
    if (fp == NULL) {
        printf("Errore\n");
        return 1;
    }
    
    for (i = 0; !feof(fp); i++) {
        fgets(riga, M, fp);
        // if (strlen(riga) > 0) {
        //     sscanf(riga, "%s %s %d %d", lista[i].nome, lista[i].cognome, &lista[i].nascita, &lista[i].morte);
        // }
        letti = sscanf(riga, "%s %s %d %d", lista[i].nome, lista[i].cognome, &lista[i].nascita, &lista[i].morte);
        if (letti != 4) {
            i--;
        }
    }
    nesploratori = i;

    calcolaEta(lista, nesploratori);
    stampaElenco(lista, nesploratori);
    qsort(lista, nesploratori, sizeof(esploratore), confAlfabetico);
    printf("----------------------\n");
    stampaElenco(lista, nesploratori);
}
```

</details> 




### Autostrade
{: .numerato_da_h3}

Dato il seguente file di dati in input:

```
A1: Milano - Napoli: Autostrade per l'Italia: 759
A2: Salerno - Reggio Calabria: Anas: 442
A3: Napoli - Salerno: Autostrade per l'Italia: 52
A4: Torino - Trieste: Autostrade per l'Italia: 524
A6: Torino - Savona: Gruppo Gavio: 124
A7: Milano - Genova: Enti Pubblici: 133
A8: Milano - Varese: Autostrade per l'Italia: 43
A10: Savona - Ventimiglia: Gruppo Gavio: 113
A11: Firenze - Pisa: Autostrade per l'Italia: 81
A12: Genova - Cecina: Gruppo Gavio: 210
A13: Bologna - Padova: Autostrade per l'Italia: 116
A14: Bologna - Taranto: Autostrade per l'Italia: 743
A15: Parma - La Spezia: Gruppo Gavio: 108
A16: Napoli - Canosa: Autostrade per l'Italia: 172
A19: Palermo - Catania: Anas: 191
A21: Torino - Piacenza - Brescia: Gruppo Gavio: 238
A22: Brennero - Modena: Enti Pubblici: 315
A23: Palmanova - Tarvisio: Enti Pubblici: 119
A24: Roma - Teramo: Gruppo Toto: 159
A25: Torano - Pescara: Gruppo Toto: 115
A26: Genova - Gravellona: Autostrade per l'Italia: 197
```

1.	Stampare il gestore dell'autostrada A8
2.	stampare il gestore dell'autostrada "Savona - Ventimiglia"
3.	stampare l'autostrada più lunga, con il suo percorso e il suo gestore
4.	Stampare quanti differenti gestori sono presenti nell’elenco
5.	Per ognuno dei gestori presenti stampare il numero di autostrade gestite, e il numero di km gestiti

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>

#define M 4
#define N 100
#define K 200

typedef struct {
    char nome[M];
    char tratta[N];
    char gestore[N];
    int km;
} Autostrada;

int main() {
    FILE *fp;
    Autostrada elenco[N];
    int i, nautostrade, imax;
    char riga[K];

    fp = fopen("6-2-9.txt", "r");
    if (fp == NULL) {
        printf("errore\n");
        return 1;
    }

    for (i = 0; !feof(fp); i++) {
        fgets(riga, K, fp);
        // A26: Genova - Gravellona: Autostrade per l'Italia: 197
        sscanf(riga, "%[^:]: %[^:]: %[^:]: %d", elenco[i].nome,
               elenco[i].tratta, elenco[i].gestore, &elenco[i].km);
    }
    nautostrade = i;

    // stampa di controllo
    for (i = 0; i < nautostrade; i++) {
        printf("%s: %s: %s: %d\n", elenco[i].nome,
               elenco[i].tratta, elenco[i].gestore, elenco[i].km);
    }

    // 1.   Stampare il gestore dell'autostrada A8
    for (i = 0; i < nautostrade; i++) {
        if (strcmp(elenco[i].nome, "A8") == 0) {
            printf("\n\nGestore dell'autostrada A8: %s\n", elenco[i].gestore);
        }
    }

    // 2.   stampare il gestore dell'autostrada "Savona - Ventimiglia"
    for (i = 0; i < nautostrade; i++) {
        if (strcmp(elenco[i].tratta, "Savona - Ventimiglia") == 0) {
            printf("\nGestore dell'autostrada Savona - Ventimiglia: %s\n", elenco[i].gestore);
        }
    }

    // 3.   stampare l'autostrada più lunga, con il suo percorso e il suo gestore (io stampo tutto)
    imax = 0;
    for (i = 0; i < nautostrade; i++) {
        if (elenco[i].km > elenco[imax].km) {
            imax = i;
        }
    }
    printf("L'autostrada piu' lunga:\n - %s: %s: %s: %d\n", elenco[imax].nome,
               elenco[imax].tratta, elenco[imax].gestore, elenco[imax].km);
    
    // 4 e 5 richiedono le mappe per essere fatti in modo semplice, se no sono lunghi e difficili
}
```

</details> 



### Squadre di calcio
{: .numerato_da_h3}

Dato il file contenente le seguenti informazioni:

```
Atalanta: Bergamo, Italia
Hellas: Verona, Italia
Sampdoria: Genova, Italia
Genoa: Genova, Italia
Liverpool: Liverpool, Regno Unito
Everton: Liverpool, Regno Unito
Espanol: Barcellona, Spagna
Barcellona: Barcellona, Spagna
Siviglia: Siviglia, Spagna
Betis: Siviglia, Spagna
Juventus: Torino, Italia
Young Boys: Berna, Svizzera
Chievo: Verona, Italia
Inter: Milano, Italia
Milan: Milano, Italia
Reggina: Reggio Calabria, Italia
```

1.	Leggi i dati e salvali in una struttura dati opportuna
2.	Trovare la città dell'Hellas, e stampare il nome dell'altra squadra della stessa città
3.	stampare in ordine alfabetico tutte le squadre italiane
4.	Stampare le sole squadre italiane, ordinate in base alla città, e a parità di città in ordine alfabetico

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 50
#define N 100
#define K 300

typedef struct {
    char nome[M];
    char citta[M];
    char nazione[M];
} Squadra;

// // 2.    Trovare la città dell'Hellas, e stampare il nome dell'altra squadra
// della stessa città int trovaCitta(Squadra elenco[], int nsquadre, char
// nome[], Squadra *ris) {
//     int i;
//     for (i = 0; i < nsquadre; i++) {
//         if (strcmp(elenco[i].nome, nome) == 0) {
//             *ris = elenco[i];
//             return 1;
//         }
//     }
//     return 0;
// }

int confrontoPerNome(void *a, void *b) {
    return strcmp(((Squadra *)a)->nome, ((Squadra *)b)->nome);
}
int confrontoPerCitta(void *a, void *b) {
    int confcitta;
    confcitta = strcmp(((Squadra *)a)->citta, ((Squadra *)b)->citta);
    if (confcitta == 0) {
        return strcmp(((Squadra *)a)->nome, ((Squadra *)b)->nome);
    } else {
        return confcitta;
    }
}

int main() {
    FILE *fp;
    Squadra elenco[N];
    int i, nsquadre;
    char riga[K];

    fp = fopen("6-2-10.txt", "r");
    if (fp == NULL) {
        printf("errore\n");
        return 1;
    }

    // 1.   Leggi i dati e salvali in una struttura dati opportuna
    for (i = 0; !feof(fp); i++) {
        fgets(riga, K, fp);
        if (strlen(riga) > 1) {
            sscanf(riga, "%[^:]: %[^,], %[^\n]", elenco[i].nome,
                   elenco[i].citta, elenco[i].nazione);
        } else {
            i--;
        }
    }
    nsquadre = i;

    for (i = 0; i < nsquadre; i++) {
        printf("%s: %s, %s\n", elenco[i].nome, elenco[i].citta,
               elenco[i].nazione);
    }
    // 2.   Trovare la città dell'Hellas, e stampare il nome dell'altra squadra
    // della stessa città
    for (i = 0; i < nsquadre; i++) {
        if (strcmp(elenco[i].nome, "Hellas") == 0) {
            printf("Citta' dell'Hellas: %s\n", elenco[i].citta);
            break;
        }
    }
    if (i >= nsquadre) {
        printf("Non ho trovato la citta dell'Hellas\n");
    }

    // 3.   stampare in ordine alfabetico tutte le squadre italiane
    qsort(elenco, nsquadre, sizeof(Squadra), confrontoPerNome);
    printf("\nSquadre ordinate per nome:\n");
    for (i = 0; i < nsquadre; i++) {
        if (strcmp(elenco[i].nazione, "Italia") == 0) {
            printf("%s: %s, %s\n", elenco[i].nome, elenco[i].citta,
                   elenco[i].nazione);
        }
    }

    // 4.   Stampare le sole squadre italiane, ordinate in base alla città, e a
    // parità di città in ordine alfabetico
    qsort(elenco, nsquadre, sizeof(Squadra), confrontoPerCitta);
    printf("\nSquadre ordinate per citta':\n");
    for (i = 0; i < nsquadre; i++) {
        if (strcmp(elenco[i].nazione, "Italia") == 0) {
            printf("%s: %s, %s\n", elenco[i].nome, elenco[i].citta,
                   elenco[i].nazione);
        }
    }

}
```



</details> 



### Codici studenti
{: .numerato_da_h3}

Devi assegnare ad ogni persona della classe un identificativo univoco formato dalle prime tre consonanti del nome seguite dalle prime tre consonanti del cognome seguito da una serie di 3 caratteri alfanumerici casuali. Se i nomi o i cognomi non contengono 3 consonanti aggiungi vocali a caso per arrivare alle 3 lettere richieste sia per il nome che per il cognome. Nel seguente file di testo è riportato l’elenco dei nomi. In un secondo file riscrivi i nomi seguiti dal codice identificativo.

```
Banani, Fahd
Brambilla, Carlo
Brambilla, Federico
Carrera, Aurora
Crespi, Ryan
Germanò, Riccardo
Grassi, Arianna
Hoxha, Visar
Kuka, Blerina
La Rosa, Abraham
Livieri, Lorenzo
Meterangelo, Chiara
Miele, Serena
Puertas Moreno, Alessandra
Pulvirenti, Giorgia
Roncoroni, Luca Davide
Rossetti, Gabriele
Sambo, Luigi
Sfondrini, Diego
Tarboush, Andrea
Tieni, Ilaria
Tornaghi, Francesca
```

Ad esempio Tieni Ilaria è associata a lrotnaf5u, lr sono scelti dal nome, o è a caso, tn presi dal cognome, a a caso, f5u a caso.


<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 100

int main() {
    FILE *fpin, *fpout;
    char riga[N], nome[N], cognome[N], codice[10];
    char vocali[] = "aeiou";
    char alfanum[] = "abcdefghijklmnopqrstuvwxyz0123456789";
    int i, j;

    srand(time(NULL));

    fpin = fopen("6-2-11.txt", "r");
    if (fpin == NULL) {
        printf("errore lettura\n");
        return 1;
    }

    fpout = fopen("6-2-11-out.txt", "w");
    if (fpout == NULL) {
        printf("errore scruttura\n");
        return 2;
    }

    while (!feof(fpin)) {
        fgets(riga, N, fpin);
        if (strlen(riga) > 1) { // controllo se la riga non è vuota
            sscanf(riga, "%[^,], %[^\n]", cognome, nome);

            // prime tre consonanti del nome
            j = 0;
            for (i = 0; i < strlen(nome) && j < 3; i++) {
                nome[i] = tolower(nome[i]);
                if ((nome[i] >= 'a' && nome[i] <= 'z') && nome[i] != 'a' &&
                    nome[i] != 'e' && nome[i] != 'i' && nome[i] != 'o' &&
                    nome[i] != 'u') {
                    codice[j] == nome[i];
                    j++;
                }
            }
            while (j < 3) {
                codice[j] = vocali[rand()%5];
                j++;
            }

            for (i = 0; i < strlen(cognome) && j < 6; i++) {
                cognome[i] = tolower(cognome[i]);
                if ((cognome[i] >= 'a' && cognome[i] <= 'z') && cognome[i] != 'a' &&
                    cognome[i] != 'e' && cognome[i] != 'i' && cognome[i] != 'o' &&
                    cognome[i] != 'u') {
                    codice[j] == cognome[i];
                    j++;
                }
            }
            while (j < 6) {
                codice[j] = vocali[rand()%5];
                j++;
            }

            while (j < 9) {
                codice[j] = alfanum[rand()%strlen(alfanum)];
                j++;
            }

            // da finire
        }
    }

    fclose(fpin);
    fclose(fpout);
}
```


</details> 




### Brobabilità dei dadi
{: .numerato_da_h3}

Sei un giocatore di giochi di ruolo e ti serve avere delle tabelle che ti indichino le probabilità di ottenere i vari punteggi con dei tiri di diversi dadi. Non conosci molto la matematica e il calcolo combinatorio (e oltretutto calcolare tutto a mano è lungo) ma sai programmare bene, pensi quindi di stimare le probabilità con un programma e di scrivere dei file ognuno che idica le diverse probabilità ottenibili con un diverso dado. I dadi che usi sono: d4 (dado a quattro facce), d6, d8, d10, d12, d20. Per ogni dado vuoi sapere le probabilità di ottenere ogni diverso risultato possibile tirando il dado una volta, o 2, o 3… fino a 10 volte.
Alla fine devi generare 6 file (uno per dado) e ogni file deve avere una prima riga che indica il dado (ad esempio “d6”) e poi diverse righe, ognuna inizia indicando il numero di dadi tirati (da 1 a 10 quindi 10 righe) seguito da un “:”  e poi un dizionario che associa ad ogni valore ottenibile la probabilità associata. 

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
    int dadi[] = {4,6,8,10,12,20};
    int ndadi = 6;
    int i, j, k, l, ris;
    FILE *fp;
    char nomefile[30];
    float prob[201];
    int nlanci = 10000;

    srand(time(NULL));

    for (i = 0; i < ndadi; i++) {
        sprintf(nomefile, "d%d.txt", dadi[i]);
        fp = fopen(nomefile, "w");
        if (fp == NULL) {
            printf("errore");
            return 1;
        }

        for (j = 1; j <= 10; j++) {
            fprintf(fp, "%2d. ", j); // qui stampo quanti dadi tiro
            printf("%d\n", j);
            for (k = 0; k < 201; k++){
                prob[k] = 0;
            }
            for (k = 0; k < nlanci; k++){
                ris = 0;
                for (l = 0; l < j; l++) {
                    ris += rand() % dadi[i] + 1;
                }
                prob[ris] += 1;
            }
            for (k = 0; k < 201; k++){
                prob[k] /= nlanci;
                // k mi rappresenta il numero venuto lanciando j dadi insieme
                if (prob[k] > 0) {
                    fprintf(fp, "%d: %.2f  ", k, prob[k]*100); // qui stampo la singola prob
                }
            }
            fprintf(fp, "\n");
        }
        fclose(fp);
    }
}
```

</details> 




### Agenda
{: .numerato_da_h3}

Crea un programma di gestione di una agenda. L’agenda deve permettere di visualizzare e inserire i dati riguardanti i propri contatti. Per ogni persona devono essere memorizzati nome cognome e numero di telefono. La visualizzazione dei dati deve avvenire in ordine alfabetico per nome o cognome (scegli tu). Tutti i dati devono essere salvati in un file in modo da poterli caricare ogni volta che si apre il programma.
Rendi il programma più modulare possibile dividendo le funzionalità in funzioni separate. Scrivi anche una funzione che ti permetta di cercare un contatto in base a nome o cognome o entrambi.
Variante: L’agenda è ordinata per cognome e la funzione di ricerca cerca il contatto a partire dal cognome con una ricerca dicotomica. Se hai fatto le funzioni ricorsive la funzione deve essere fatta sia nella versione iterativa che ricorsiva 

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c

```

</details> 



### Tabella di lavoro
{: .numerato_da_h3}

Il seguenti dati, che dovrai inserire in un file di testo, descrivono quante ore hanno lavorato in una settimana, una serie di dipendenti: ad esempio Mr White ha lavorato 8 ore il lunedì, 9 ore il martedì, 8 ore il mercoledì, 9 ore il giovedì e 4 ore il venerdì

```
Mr White: 8, 9, 8, 9, 4
Mr Brown: 0, 8, 7, 10, 8
Mr Blonde: 8, 8, 8, 9, 9
Mr Black: 6, 9, 9, 8, 8
Mr Red: 8, 7, 8, 8, 8
Mr Green: 4, 8, 8, 8, 4
```

1.	Stampare la classifica dei lavoratori, in base al numero di ore lavorate
2.	Stampare il giorno con più ore lavorate, e quante ore sono state lavorate in quel giorno

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 20
#define M 100

typedef struct {
    char nome[N];
    int ore[5];
    int somma;
} Lavoratore;

int confronto(void *a, void *b) {
    return ((Lavoratore *)a)->somma < ((Lavoratore *)b)->somma;
}

int main() {
    FILE *fp;
    int n, i, j, maxj, max, somma;
    char riga[M];
    Lavoratore elenco[N];
    char giorni[][20] = {"Lunedi'", "Martedi'", "Mercoledi'", "Giovedi'", "Venerdi'"};

    fp = fopen("6-2-14.txt", "r");
    if (fp == NULL) {
        printf("errore lettura\n");
        return 1;
    }

    for (n = 0; !feof(fp); n++) {
        fgets(riga, M, fp);
        // printf("%s\n", riga);

        sscanf(riga, "%[^:]: %d, %d, %d, %d, %d", elenco[n].nome,
               &elenco[n].ore[0], &elenco[n].ore[1], &elenco[n].ore[2],
               &elenco[n].ore[3], &elenco[n].ore[4]);

        elenco[n].somma = elenco[n].ore[0] + elenco[n].ore[1] +
                          elenco[n].ore[2] + elenco[n].ore[3] +
                          elenco[n].ore[4];
        
        // printf("%10s: %2d %2d %2d %2d %2d - %2d\n", elenco[n].nome,
        //        elenco[n].ore[0], elenco[n].ore[1], elenco[n].ore[2],
        //        elenco[n].ore[3], elenco[n].ore[4], elenco[n].somma);
    }
    fclose(fp);
    // 1.     Stampare
    // la classifica dei lavoratori, in base al numero di ore lavorate
    qsort(elenco, n, sizeof(Lavoratore), confronto);
    for (i = 0; i < n; i++) {
        printf("%10s: %2d %2d %2d %2d %2d - %2d\n", elenco[i].nome,
               elenco[i].ore[0], elenco[i].ore[1], elenco[i].ore[2],
               elenco[i].ore[3], elenco[i].ore[4], elenco[i].somma);
    }

    // 2.     Stampare
    // il giorno con più ore lavorate, e quante ore sono state lavorate in quel
    // giorno
    maxj = 0;
    max = 0;
    for (i = 0; i < n; i++) {
        max += elenco[i].ore[0];
    }
    for (j = 1; j < 5; j++) {
        somma = 0;
        for (i = 0; i < n; i++) {
            somma += elenco[i].ore[j];
        }
        if (somma > max) {
            max = somma;
            maxj = j;
        }
    }
    printf("Il giorno in cui si e' lavorato di piu' e' %s\n", giorni[maxj]);
}
```

</details> 



### Regioni e province
{: .numerato_da_h3}

Il seguente file di testo contiene le informazioni riguardanti le provincie d’Italia raggruppate per regione:

```
Valle d'Aosta: Aosta
Piemonte: Torino, Alessandria, Asti, Biella, Cuneo, Novara, Verbano-Cusio-Ossola, Vercelli
Liguria: Genova, Imperia, La Spezia, Savona
Lombardia: Milano, Bergamo, Brescia, Como, Cremona, Lecco, Lodi, Mantova, Monza e Brianza, Pavia, Sondrio, Varese
Trentino-Alto Adige: Trento, Bolzano
Veneto: Venezia: Belluno, Padova, Rovigo, Treviso, Verona, Vicenza
Friuli-Venezia Giulia: Trieste Gorizia, Pordenone, Udine
Emilia-Romagna: Bologna, Ferrara, Forlì-Cesena, Modena, Parma, Piacenza, Ravenna, Reggio Emilia, Rimini
Toscana: Firenze, Arezzo, Grosseto, Livorno, Lucca, Massa Carrara, Pisa, Pistoia, Prato, Siena
Umbria: Perugia, Terni
Marche: Ancona, Ascoli Piceno, Fermo, Macerata, Pesaro-Urbino
Lazio: Roma, Frosinone, Latina, Rieti, Viterbo
Abruzzo: L'Aquila, Chieti, Pescara, Teramo
Molise: Campobasso, Isernia
Campania: Napoli, Avellino, Benevento, Caserta, Salerno
Puglia: Bari, Andria, Barletta, Brindisi, Foggia, Lecce, Taranto, Trani
Basilicata: Potenza, Matera
Calabria: Catanzaro, Cosenza, Crotone, Reggio Calabria, Vibo Valentia
Sicilia: Palermo, Agrigento, Caltanissetta, Catania, Enna, Messina, Ragusa, Siracusa, Trapani
Sardegna: Cagliari, Nuoro, Oristano, Sassari, Sud Sardegna
```

La prima provincia indicata per ogni regione è il capoluogo di regione.
Scrivi un programma che memorizzi opportunamente tutti i dati, poi:
1.	Scrivi e usa una funzione che calcola quante provincie sono presenti mediamente in ogni regione
2.	Ordina le regioni per numero di provincie
3.	Scrivi i nomi delle regioni con più provincie e con meno provincie

<details markdown="block">
  <summary class="soluzione-toggler">
    Soluzione
  </summary>
  {: .text-delta }

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 50
#define M 200

typedef struct {
    char nome[N];
    char province[N][N];
    int nprovince;
} Regione;

void stampaRegioni(Regione elenco[], int nregioni) {
    int i, j;
    for (i = 0; i < nregioni; i++) {
        printf("%s: ", elenco[i].nome);
        for (j = 0; j < elenco[i].nprovince; j++) {
            printf("%s, ", elenco[i].province[j]);
        }
        printf("%d\n", elenco[i].nprovince);
    }
}

float mediaprovince(Regione elenco[], int nregioni) {
    float ris = 0;
    int i;
    for (i = 0; i < nregioni; i++) {
        ris += elenco[i].nprovince;
    }
    ris /= nregioni;
    return ris;
}

int confrontaRegioniPerNprovince(void *a, void *b) {
    return ((Regione *)a)->nprovince > ((Regione *)b)->nprovince;
}

int main() {
    FILE *fp;
    int i, ntoken, j;
    char riga[M], *token;
    Regione elenco[N];
    int nregioni;

    fp = fopen("6-2-15.txt", "r");
    if (fp == NULL) {
        printf("errore lettura\n");
        return 1;
    }

    for (i = 0; !feof(fp); i++) {
        fgets(riga, M, fp);
        if (riga[strlen(riga) - 1] == '\n') {
            riga[strlen(riga) - 1] = 0;
        }

        // if (strlen(riga) > 1) {
        //     ntoken = sscanf(riga,
        //                     "%[^:]: %[^,], %[^,], %[^,], %[^,], %[^,], %[^,], "
        //                     "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,]",
        //                     elenco[i].nome, elenco[i].province[0],
        //                     elenco[i].province[0], elenco[i].province[1],
        //                     elenco[i].province[2], elenco[i].province[3],
        //                     elenco[i].province[4], elenco[i].province[5],
        //                     elenco[i].province[6], elenco[i].province[7],
        //                     elenco[i].province[8], elenco[i].province[9],
        //                     elenco[i].province[10], elenco[i].province[11],
        //                     elenco[i].province[12]);
        //     elenco[i].nprovince = ntoken - 1;
        // }

        if (strlen(riga) > 1) {
            token = strtok(riga, ": ");
            strcpy(elenco[i].nome, token);

            token = strtok(NULL, ", ");
            for (j = 0; token != NULL; j++) {
                strcpy(elenco[i].province[j], token);
                token = strtok(NULL, ", ");
            }
            elenco[i].nprovince = j;
        }

    }
    nregioni = i;

    stampaRegioni(elenco, nregioni);

    printf("Media province per regione: %g\n\n",
           mediaprovince(elenco, nregioni));

    qsort(elenco, nregioni, sizeof(Regione), confrontaRegioniPerNprovince);
    printf("Regione con piu' province: %s\n", elenco[nregioni-1].nome);
    printf("Regione con meno province: %s\n", elenco[0].nome);

    // stampaRegioni(elenco, nregioni);
}
```

</details> 






<!-- per una nuova soluzione

### 
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




