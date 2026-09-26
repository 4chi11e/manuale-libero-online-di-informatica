---
title: Progettazione Concettuale
description: Introduzione al Modello Entità-Relazione (Modello E/R)
---

La **Progettazione Concettuale** è la prima vera fase della creazione di un database. In questa fase si analizza il problema (la "realtà di interesse") e si individuano gli elementi fondamentali e i legami che esistono tra di essi. 

Il risultato di questa fase è uno schema astratto, indipendente dal software che si andrà ad utilizzare. Lo strumento standard in tutto il mondo per rappresentare questo schema è il **Modello Entità-Relazione** (o **Modello E/R**), ideato nel 1976 da Peter Chen. Il Modello E/R utilizza dei simboli grafici molto intuitivi per "disegnare" la struttura dei dati.

:::note[Una nota sui formalismi grafici]
Cercando online materiale sui database, ti imbatterai in moltissime varianti e formalismi diversi per disegnare un modello E/R (es. notazione "a zampa di gallina", UML, e stili diversi per attributi e cardinalità). Non spaventarti: per questo manuale e per gli esercizi abbiamo scelto una notazione grafica specifica che riteniamo essere la più pratica e chiara, ma le regole logiche di fondo rimangono sempre le stesse.
:::

Vediamo quali sono i "mattoni" fondamentali (i costrutti) di questo modello.

## 1. Le Entità

Un'**Entità** rappresenta una classe di oggetti (fisici o astratti) del mondo reale che hanno proprietà comuni e un'esistenza autonoma. In altre parole, è il "soggetto" di cui vogliamo memorizzare delle informazioni.

*   *Esempi di entità fisiche:* `Persona`, `Automobile`, `Prodotto`.
*   *Esempi di entità astratte:* `Corso`, `Fattura`, `Prenotazione`.

**Come si disegna:** Le entità si rappresentano graficamente con un **rettangolo** contenente il nome dell'entità al singolare.

*(Nota: L'entità è il concetto astratto generale, mentre il singolo oggetto specifico, come "L'automobile targata AB123CD", si chiama **istanza** dell'entità).*

## 2. Gli Attributi

Gli **Attributi** sono le proprietà, o le caratteristiche, che descrivono un'entità. Ogni istanza dell'entità avrà un valore specifico per quell'attributo.

Se prendiamo l'entità `Studente`, i suoi attributi potrebbero essere `Nome`, `Cognome`, `Data di Nascita` e `Codice Fiscale`.

A seconda della loro natura, gli attributi possono essere di vario tipo e si disegnano in modo diverso per essere immediatamente riconoscibili nello schema:

*   **Attributi semplici:** Hanno un valore singolo e indivisibile (es. `Nome`). Si rappresentano graficamente con un semplice **punto** collegato all'entità.
*   **Attributi composti:** Sono attributi formati dall'unione di un numero fisso e predefinito di attributi semplici. Possono essere quindi suddivisi in parti più piccole e indipendenti (es. l'attributo `Indirizzo` è tipicamente composto dal numero fisso di sotto-attributi `Via`, `CAP` e `Città`). Si rappresentano utilizzando un **quadrato**.
*   **Attributi multipli (o multivalore):** Possono assumere più di un valore per una singola istanza (es. una persona può avere più `Numeri di Telefono`). Si indicano disegnando una **freccia** che collega l'entità all'attributo.

Esistono inoltre due casistiche particolari di attributi legati al loro comportamento logico. Di solito, nello schema concettuale puro queste particolarità non hanno un simbolo grafico specifico, ma è fondamentale che il progettista ci ragioni sopra:

*   **Attributi opzionali:** Non tutte le istanze sono obbligate ad avere un valore per questo attributo. Se il dato non è noto o non esiste, in futuro il campo potrà essere lasciato vuoto (tecnicamente assumerà il valore "NULL", es. `Numero di Telefono Secondario`). Nella fase concettuale, solitamente, questa opzionalità non si indica graficamente.
*   **Attributi calcolati (o derivati):** Qui il discorso si fa molto interessante per il progettista, che deve prendere una decisione. Il valore di un attributo calcolato (es. l'`Età` ricavata dalla `Data di nascita`, o il `Totale` di una fattura) si ottiene matematicamente partendo da altri dati. Se decidessimo di inserire questo attributo nello schema per poi salvarlo fisicamente, introdurremmo volontariamente una **ridondanza** (che, come abbiamo visto, vogliamo assolutamente evitare). Pertanto, la regola d'oro è che solitamente *non ha senso inserire attributi calcolati nel database*, poiché in futuro quei dati verranno generati dinamicamente al volo tramite interrogazioni (query) o viste.

### La Chiave Primaria (Primary Key)
Tra tutti gli attributi di un'entità, ne deve esistere *almeno uno* (o un gruppo di essi) capace di identificare in modo univoco una singola istanza. Questo attributo prende il nome di **Chiave Primaria (PK)** o Identificatore Univoco. 

Ad esempio, per l'entità `Persona`, nome e cognome non vanno bene (possono esserci omonimi), ma il `Codice Fiscale` è un'ottima chiave primaria. Se non esiste un attributo naturale univoco, se ne crea uno artificiale inventato dal sistema (es. `Matricola` o `ID_Cliente`).

*Un consiglio pratico:* Nei database reali si tende spesso ad aggiungere un "ID" artificiale di servizio per quasi tutte le tabelle, per comodità e per evitare di gestire chiavi primarie composte da troppi attributi. Tuttavia, in questa fase di **progettazione concettuale**, è molto utile sforzarsi di identificare sempre una *chiave reale* (se esiste), perché ci costringe a ragionare a fondo e a comprendere meglio la vera natura dell'entità che stiamo trattando.

**Come si disegna:** L'attributo chiave, per distinguerlo visivamente dagli attributi normali, si rappresenta semplicemente **sottolineando il suo nome**. 

#### Entità Deboli
In alcuni casi, un'entità non possiede attributi sufficienti per formare una chiave primaria autonoma e univoca, ma ha bisogno di "appoggiarsi" alla chiave di un'altra entità a cui è strettamente collegata. Queste entità vengono definite **Entità Deboli**. 

L'esempio classico è l'entità `Poltrona` di un cinema: i suoi attributi `Fila` e `Numero` non bastano a identificarla univocamente (perché esiste una poltrona "A-1" in ogni singola sala del cinema). La sua vera chiave primaria è quindi composta dai suoi attributi `Fila` e `Numero` uniti alla *chiave della Sala*. La `Poltrona` è un'entità debole perché la sua identificazione (e la sua stessa esistenza) dipende dall'entità forte `Sala`.

**Come si disegna:** L'identificazione "in prestito" si indica disegnando un **trattino con un pallino** perpendicolare alla linea che collega l'entità debole alla sua associazione con l'entità forte.

## 3. Le Associazioni (o Relazioni)

Le entità quasi mai "vivono da sole" isolate nel database. Un'**Associazione** (spesso chiamata anche *Relazione*) rappresenta un legame logico che intercorre tra due o più entità.

*   *Esempio:* Tra l'entità `Studente` e l'entità `Classe` esiste un legame logico: lo studente *appartiene* a una classe. L'associazione si chiamerà "Appartiene".

**Attributi delle associazioni:** Proprio come le entità, anche le associazioni possono avere dei propri attributi! Questo accade quando un'informazione non appartiene a nessuna delle entità singolarmente, ma "nasce" solo dal loro incontro. Ad esempio, se uno `Studente` si iscrive a un `Corso`, la `Data_Iscrizione` non è una proprietà dello studente in generale, né del corso, ma è un'informazione che esiste solo nella specifica associazione tra i due. Infatti, uno studente può iscriversi a tanti corsi in date diverse, e a un corso possono iscriversi tanti studenti in date diverse: di conseguenza, queste date fanno parte della relazione stessa e non delle singole entità.

**Come si disegna:** Le associazioni si rappresentano con un **rombo** collegato tramite segmenti alle entità coinvolte, con all'interno un verbo (di solito all'attivo) che descrive chiaramente il legame. Gli eventuali attributi dell'associazione si collegano al rombo esattamente come si fa con le entità (con un segmento e un punto).

## 4. La Cardinalità delle Associazioni

Non basta dire che due entità sono collegate. Dobbiamo specificare *quante* istanze di un'entità possono partecipare al legame con l'altra entità. Questo concetto cruciale si esprime tramite le **Cardinalità**.

In base a "quanti con quanti" si legano, le associazioni si classificano in tre grandi famiglie fondamentali:

1.  **Associazione Uno a Uno (1:1):** 
    Un'istanza della prima entità si associa al massimo a *una* della seconda, e viceversa. 
    *(Es. `Studente` e `Badge`. Uno studente riceve un solo badge identificativo, e quello specifico badge è assegnato a un solo studente).*
2.  **Associazione Uno a Molti (1:N):**
    Un'istanza della prima entità può associarsi a *molte* istanze della seconda, ma un'istanza della seconda si associa al massimo a *una* della prima.
    *(Es. `Classe` e `Studente`. In una classe ci sono molti studenti, ma un singolo studente appartiene a una sola classe).*
3.  **Associazione Molti a Molti (N:N):**
    Un'istanza della prima entità può associarsi a *molte* della seconda, e viceversa.
    *(Es. `Studente` e `Corso`. Uno studente frequenta molti corsi, e un corso è frequentato da molti studenti contemporaneamente).*

**Dove si posizionano graficamente 1 e N nello schema?**
Nei testi scolastici si trovano spesso due formalismi opposti. Per questo manuale abbiamo scelto la notazione in cui **il numero si scrive vicino all'entità stessa**, indicando quante volte una singola istanza di *quella* entità partecipa all'associazione. Anche se inizialmente può sembrare controintuitiva rispetto al "leggere la frase", questa notazione è l'unica che ci permette di gestire facilmente e senza ambiguità anche associazioni complesse in cui **partecipano tre o più entità contemporaneamente** (associazioni multiple).

Con questi semplici "mattoni" (Entità, Attributi, Chiavi e Associazioni con Cardinalità) è possibile modellare e disegnare in modo astratto la struttura di praticamente qualsiasi scenario del mondo reale.
