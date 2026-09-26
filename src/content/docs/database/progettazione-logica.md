---
title: Progettazione Logica
description: Il Modello Relazionale e la traduzione in Tabelle
---

La **Progettazione Logica** è la seconda fase della creazione di un database. Lo scopo di questa fase è "tradurre" lo schema astratto (il Modello E/R che abbiamo appena visto) in una struttura dati che un computer possa effettivamente comprendere e gestire.

Il modello logico oggi dominante e usato nel 99% dei database tradizionali è il **Modello Relazionale**, ideato da Edgar F. Codd nel 1970. L'idea di base è estremamente semplice e potente: tutti i dati vengono organizzati in **Tabelle**.

## 1. Il Modello Relazionale: Il Vocabolario
Prima di vedere come tradurre il nostro schema, dobbiamo allineare il vocabolario. Nel passaggio dal mondo concettuale (E/R) al mondo logico (Relazionale), i nomi degli elementi cambiano:

*   **Tabella (o Relazione):** È la struttura principale che conterrà i dati. Nel modello concettuale corrisponde all'**Entità**.
*   **Campo (o Attributo):** Sono le colonne della tabella. Definiscono le proprietà del dato. Nel modello concettuale corrispondono agli **Attributi**.
*   **Record (o Tupla):** È la singola riga della tabella. Contiene i dati effettivi di un singolo elemento. Nel modello concettuale corrisponde all'**Istanza** (e infatti, nella pratica, capita spessissimo di continuare a usare la parola "istanza" anche parlando di tabelle).

*(Nota: anche se nella teoria dei database il termine matematico formale sarebbe "Relazione", nel gergo comune e didattico si usa quasi esclusivamente la parola "Tabella". Il motivo è molto pratico: chiamarla "relazione" creerebbe una confusione terribile con le "relazioni" (associazioni) che intercorrono tra le entità! Allo stesso modo, si usano spessissimo i termini "Record" o "Istanza" al posto della parola "Tupla").*

## 2. Dallo Schema E/R alle Tabelle (Regole di Derivazione)
Come facciamo a convertire i nostri rettangoli e rombi in righe e colonne? Esistono delle precise regole matematiche, chiamate **regole di derivazione** (o mapping).

### Parte 1: La derivazione di Entità e Attributi
La primissima cosa da fare è tradurre i "rettangoli" (le Entità) e i loro attributi associati. 
Ogni **Entità** dello schema E/R diventa una **Tabella**. 
L'attributo che avevamo scelto come Chiave Primaria diventa la **Primary Key (PK)** della tabella (e continuiamo a sottolinearlo).
Per gli altri attributi, ci comportiamo diversamente in base alla loro natura:

1.  **Attributi semplici:** Diventano direttamente i **campi** (le colonne) della tabella.
2.  **Attributi composti:** Un database relazionale non accetta "campi dentro ai campi". Pertanto, l'attributo "padre" scompare e al suo posto vengono inseriti tutti i suoi sotto-attributi semplici come campi separati e indipendenti (es. l'attributo `Indirizzo` scompare e diventa tre colonne distinte: `Via`, `CAP`, `Città`).
3.  **Attributi multipli:** Sappiamo bene che una cella può contenere un solo valore. Se un attributo è multiplo (es. `Numeri_Telefono`), non possiamo infilarli tutti nella stessa colonna né creare un numero imprecisato di colonne. La regola d'oro è: **l'attributo multiplo genera una nuova tabella dedicata**. 
    *Come accade per le relazioni N:N, la Chiave Primaria di questa nuova tabella sarà composta*: sarà formata dal singolo valore dell'attributo unito alla Chiave Esterna che lo collega all'entità principale.

*Esempio di traduzione degli attributi:*
Un'entità `Studente` con attributi semplici (*Matricola*, Nome), un attributo composto (*Residenza*: Via, Città) e un attributo multiplo (*Telefono*), si tradurrà in due tabelle separate. Da notare come nella seconda tabella la chiave primaria sia composta da entrambi i campi (entrambi sottolineati, con l'asterisco per indicare la chiave esterna):

*   **STUDENTI** (<u>Matricola</u>, Nome, Via, Citta)
*   **TELEFONI_STUDENTI** (<u>Numero_Telefono</u>, <u>Matricola_Studente\*</u>)

---

### Parte 2: La derivazione delle Associazioni
Dopo aver sistemato le singole entità, passiamo a tradurre i "rombi" (le associazioni) in base alla loro cardinalità.

#### L'Associazione Uno a Molti (1:N)
Quando abbiamo un'associazione **1:N**, non creiamo una nuova tabella per l'associazione. Utilizziamo invece il meccanismo della **Chiave Esterna (Foreign Key - FK)**.
Avendo scelto (nella nostra notazione del Modello E/R) di posizionare l'1 vicino all'entità che partecipa 1 sola volta all'associazione e la N vicino all'entità che vi partecipa molte volte, la regola d'oro si inverte rispetto ad altri testi: **La chiave primaria dell'entità che sta dal lato "N" VIENE COPIATA e diventa una colonna aggiuntiva (chiave esterna) nella tabella che sta dal lato "1"** (restando ovviamente intatta nella sua tabella di origine).

**Perché si copia in questa direzione e non al contrario?**
Il motivo è puramente logico: se provassimo a fare il contrario (copiando la chiave dello Studente dentro la tabella Classe), la Classe si ritroverebbe a dover inserire *tante* matricole diverse nella stessa riga (una per ogni studente). Questo è vietato, perché ogni "cella" di un database relazionale può contenere un solo dato! Invece, poiché ogni Studente appartiene a *una sola* Classe, la riga dello Studente può ospitare tranquillamente il singolo `ID_Classe` in una colonna dedicata.

La chiave esterna si indica mettendo un **asterisco (*)** alla fine del nome del campo.

:::caution[Attenzione alla sottolineatura!]
La chiave esterna appena copiata **NON va sottolineata** nella nuova tabella. Non essendo la chiave primaria di questa entità, serve unicamente come "ponte" per rappresentare la relazione. Si indica solamente con l'asterisco. 

*L'unica eccezione a questa regola si ha con le **Entità Deboli** (es. Sala e Poltrona che abbiamo visto prima): in quel caso, la chiave esterna importata fa parte della chiave primaria composta dell'entità debole, e quindi sarà sia sottolineata che seguita dall'asterisco.*
:::

*Esempio (Classe N --- Appartiene --- 1 Studente):*

La chiave primaria della Classe (lato N) viene copiata per fare da chiave esterna negli Studenti (lato 1).

*   **CLASSI** (<u>ID_Classe</u>, Sezione, Anno)
*   **STUDENTI** (<u>Matricola</u>, Nome, Cognome, ID_Classe\*)

#### L'Associazione Molti a Molti (N:N)
I database relazionali non sanno gestire direttamente un'associazione Molti a Molti. 

**Perché non possiamo usare la chiave esterna come nella 1:N?**
Nella 1:N potevamo cavarcela copiando la chiave perché, ad esempio, uno Studente ha *una sola* Classe: basta aggiungere un'unica colonna che conterrà un singolo valore. Se tentassimo di fare lo stesso in una N:N (es. uno Studente frequenta *molti* Corsi), lo studente dovrebbe inserire tanti valori diversi nel campo `ID_Corso`, cosa che le tabelle dei database non permettono di fare (ogni "cella" può contenere un solo dato).

Per risolvere il problema, la regola d'oro è: **L'associazione scompare e al suo posto nasce una NUOVA TABELLA (detta tabella associativa o tabella ponte)**.
Questa nuova tabella avrà come chiavi esterne le chiavi primarie delle due entità originali. La combinazione di queste due chiavi esterne formerà la chiave primaria composta della nuova tabella ponte.

*Esempio (Studente N : N Corso):*

*   **STUDENTI** (<u>Matricola</u>, Nome, Cognome)
*   **CORSI** (<u>Codice_Corso</u>, Titolo, Ore)
*   **ISCRIZIONI** (<u>Matricola\*</u>, <u>Codice_Corso\*</u>, Data_Iscrizione)

*(Nota: come si vede nell'esempio, eventuali attributi propri dell'associazione N:N, come la data in cui lo studente si è iscritto, diventano banalmente campi della nuova tabella ponte).*

#### L'Associazione Uno a Uno (1:1)
Le associazioni 1:1 sono più rare. Di base ci sono due modi logici per risolverle, ma uno è di gran lunga preferibile all'altro:
1.  **Copia della chiave (Consigliata):** Si tengono separate le due tabelle. A differenza della 1:N, qui la scelta della direzione è tecnicamente libera, ma **bisogna scegliere una e una sola direzione**, non entrambe! Si copia la chiave primaria di una tabella inserendola come chiave esterna nell'altra. Di solito si segue un "criterio di importanza", inserendo la chiave copiata nell'entità che risulta gerarchicamente più rilevante e "pesante" all'interno del database.
2.  **Fusione delle tabelle (Da valutare con attenzione):** In teoria si potrebbero "collassare" le due entità fondendole in un'unica grande tabella che contiene gli attributi di entrambe. Questa strada è accettabile solo se le due entità "vivono e muoiono" sempre insieme (partecipazione obbligatoria per entrambe). Tuttavia, è **fortemente sconsigliata** se una delle due parti è *opzionale*. Ad esempio, se l'entità `Impiegato` ha un'associazione 1:1 opzionale con `Auto_Aziendale` (non tutti ce l'hanno), fondere le tabelle costringerebbe il database a creare tantissime celle vuote (valori `NULL` per targa, modello, ecc.) in corrispondenza di tutti gli impiegati senza auto, sporcando i dati. Inoltre, tenere tabelle separate è spesso preferibile per motivi di sicurezza (es. separare un profilo pubblico dalle password) o di semplice pulizia concettuale.

*Esempio (Studente 1 : 1 Badge):*

*   **STUDENTI** (<u>Matricola</u>, Nome, Cognome)
*   **BADGE** (<u>ID_Badge</u>, Codice_RFID, Matricola_Studente\*)

---

Applicando rigorosamente queste regole, il tuo schema E/R astratto si trasformerà in un set di tabelle ineccepibile, pronto per essere sottoposto alla fase di verifica: la **Normalizzazione**.
