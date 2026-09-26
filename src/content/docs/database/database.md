---
title: Introduzione ai Database
description: Dati, informazioni e i concetti fondamentali dei sistemi informativi e dei database.
---

## Dati, Informazioni e Sistemi

Prima di addentrarci nel mondo dei Database, è fondamentale fare chiarezza su due concetti che nel linguaggio comune vengono spesso (erroneamente) usati come sinonimi: il **dato** e l'**informazione**.

*   **Dato:** È la materia prima grezza, la descrizione elementare e non interpretata di un fatto o un evento. Da solo, un dato non ha un significato utile (Esempio: il numero `23`, oppure la parola `Mario`).
*   **Informazione (o Conoscenza):** È il dato inserito in un contesto, a cui è stata applicata una *chiave di interpretazione*. L'informazione produce un effettivo incremento di conoscenza. (Esempio: "Oggi ci sono `23` °C", oppure "`Mario` è il nome di un cliente").

L'obiettivo di qualsiasi organizzazione (che sia una scuola, un'azienda o un ente pubblico) è gestire queste informazioni nel modo più efficiente possibile per poter operare e prendere decisioni. Per farlo, l'organizzazione si avvale di un **Sistema Informativo**: un insieme organizzato di strumenti, procedure, norme e persone volto alla raccolta, archiviazione ed elaborazione delle informazioni. 
*Nota bene: un sistema informativo esiste a prescindere dall'uso dei computer (anche un vecchio archivio cartaceo con i faldoni fa parte del sistema informativo!).*

Quando il sistema informativo viene automatizzato, in tutto o in parte, tramite l'uso di computer e software, parliamo di **Sistema Informatico**. Oggi, il cuore pulsante di quasi ogni sistema informatico è proprio il **Database**.

## Perché usare un Database? I limiti dei vecchi sistemi

Nei primi decenni dell'informatica, i dati venivano salvati su semplici file separati (il cosiddetto file system tradizionale). Ogni reparto di un'azienda (es. amministrazione, vendite, magazzino) aveva i propri file. Questo approccio, all'aumentare dei dati, generava enormi problemi:

1.  **Ridondanza:** Lo stesso dato veniva duplicato e memorizzato in più file diversi. Ad esempio, l'indirizzo del cliente "Mario Rossi" era salvato sia nel file delle fatture che nel file delle spedizioni. Oltre all'evidente spreco di spazio di archiviazione, la ridondanza innesca a catena altri due gravi problemi.
2.  **Incongruenza:** Se Mario Rossi cambia casa e l'indirizzo viene aggiornato solo nel file delle fatture ma non in quello delle spedizioni, le informazioni non sono più allo stesso livello di aggiornamento. Il sistema restituisce versioni diverse dello stesso dato.
3.  **Inconsistenza:** È la diretta conseguenza dell'incongruenza. Avendo nel sistema dati discordanti e non aggiornati allo stesso modo, non è più possibile stabilire quale sia l'informazione "vera". L'intera base di informazioni diventa inaffidabile.
4.  **Concorrenza:** Cosa succede se due impiegati aprono lo stesso file contemporaneamente per modificarlo? Spesso, il salvataggio dell'uno sovrascriveva e annullava il lavoro dell'altro, causando la perdita di aggiornamenti.

Per risolvere in modo definitivo questi problemi, sono nati i **Database**.

## Cos'è un Database e cos'è un DBMS

Un **Database** (o Base di Dati) è una vasta collezione di dati logicamente correlati tra loro, organizzata per modellare una specifica realtà (es. l'anagrafica di una scuola, il catalogo di un e-commerce o il sistema di prenotazioni di un treno). I dati sono centralizzati, non più sparsi in archivi a compartimenti stagni.

Per gestire, interrogare e proteggere questa collezione di dati serve un complesso software specializzato, chiamato **DBMS** (*Data Base Management System* - Sistema di Gestione di Basi di Dati). Esempi famosi di DBMS sono MySQL, PostgreSQL, Oracle o SQL Server. Il DBMS fa da intermediario esclusivo tra gli utenti (o le applicazioni software) e i dati fisici salvati sul disco.

Grazie all'uso congiunto di Database e DBMS, si garantiscono alcune **caratteristiche fondamentali**:

*   **Sicurezza:** L'accesso ai dati è consentito solo a utenti o programmi autorizzati tramite meccanismi di autenticazione e privilegi (chi può solo leggere, chi può modificare).
*   **Integrità:** Il DBMS assicura che i dati inseriti siano sempre validi e rispettino le regole della realtà che rappresentano (ad esempio, impedendo l'inserimento di un'età negativa o di una data inesistente).
*   **Consistenza:** Avendo eliminato le ridondanze, l'aggiornamento di un dato avviene in un solo punto, garantendo che le informazioni lette siano sempre affidabili e prive di contraddizioni.
*   **Condivisione (e gestione della Concorrenza):** Più utenti e applicazioni possono leggere e modificare gli stessi dati contemporaneamente. Il DBMS regola gli accessi incrociati come un vigile urbano, garantendo che le modifiche non si sovrascrivano a vicenda.
*   **Persistenza:** I dati hanno una vita propria: sopravvivono al riavvio del computer e all'esecuzione dei programmi che li utilizzano, rimanendo memorizzati nel tempo in modo permanente.
*   **Scalabilità:** Il sistema è progettato per mantenere buone prestazioni (in termini di tempi di risposta) anche quando la mole di dati cresce in modo considerevole nel tempo.

## Schema, Istanza e Modelli di Dati

Per comprendere come un database organizza le informazioni, è essenziale distinguere tra la struttura dei dati e i dati veri e propri:

*   **Schema (o Intensione):** È la struttura, l'ossatura del database. Descrive *quali* categorie di dati vogliamo memorizzare e come sono collegate tra loro. Lo schema viene definito a tavolino durante la progettazione iniziale e successivamente si cerca di cambiarlo il meno possibile, poiché alterare la struttura in corso d'opera (con i dati già inseriti) risulta quasi sempre un'operazione complessa e problematica (Esempio: lo schema stabilisce che per ogni Studente vogliamo memorizzare Nome, Cognome e Matricola).
*   **Istanza (o Estensione):** È l'insieme dei valori effettivi presenti nel database in un preciso istante. L'istanza cambia continuamente a ogni inserimento, modifica o cancellazione (Esempio: l'istanza attuale contiene "Mario, Rossi, 12345" e "Giulia, Bianchi, 67890").

Questa distinzione è resa possibile dall'utilizzo di specifici **Modelli di Dati**, ovvero insiemi di concetti e regole usati per descrivere la struttura del database. Come vedremo, i modelli possono essere molto astratti (modelli concettuali) o più vicini alla vera struttura informatica (modelli logici).

## L'Architettura di un DBMS e i Linguaggi

Un DBMS è un software complesso progettato per separare le applicazioni dalla gestione fisica dei dati sul disco (un principio cardine chiamato **indipendenza dei dati**). Per fare ciò, struttura il database su tre livelli di astrazione:

1.  **Livello Fisico (o Interno):** Riguarda come i dati sono *realmente* salvati sul disco fisso (file, bit, settori). Questo livello è gestito in automatico dal DBMS ed è del tutto trasparente per l'utente e per il progettista.
2.  **Livello Logico:** Riguarda l'intera struttura del database vista nella sua interezza (lo *schema logico*). Descrive tutti i dati e le relazioni tra essi, ma nasconde i dettagli fisici di memorizzazione.
3.  **Livello Esterno (o delle Viste):** Riguarda le *viste* personalizzate per i diversi utenti. Ogni utente (o applicazione) vede solo la porzione di database di sua competenza (Es. il magazziniere vede le giacenze, l'HR vede gli stipendi, pur accedendo tutti allo stesso database centrale).

Per operare su questi livelli, il DBMS mette a disposizione dei linguaggi specifici (il più famoso standard in assoluto è il linguaggio **SQL**, che vedremo nella pratica):

*   **DDL (Data Definition Language):** Usato per creare, modificare ed eliminare lo *schema* logico del database (es. creare nuove tabelle o definire le caratteristiche di un dato).
*   **DML (Data Manipulation Language):** Usato per operare sulle *istanze*. Permette di interrogare il database per cercare informazioni (spesso questa parte specifica è chiamata *DQL - Data Query Language*), oltre che inserire, aggiornare e cancellare i dati.
*   **DCL (Data Control Language):** Usato per gestire la sicurezza, assegnando o revocando permessi e autorizzazioni ai vari utenti.

## Il Ciclo di Vita: le Fasi della Progettazione

Un database non si crea scrivendo codice a caso. Richiede un rigoroso processo di progettazione, suddiviso in tre fasi sequenziali. La differenza tra queste fasi (e in particolare tra modello concettuale e logico) può creare confusione, ma è facile capirla se la paragoniamo alla costruzione di una casa:

1.  **Progettazione Concettuale (Il disegno dell'architetto):** Lo scopo di questa fase è organizzare le informazioni in modo puramente astratto. Ci si concentra esclusivamente sull'identificazione delle **entità** (i "soggetti" della realtà di interesse), delle loro **caratteristiche** e delle **relazioni** che intercorrono tra di loro, senza specificare in alcun modo come queste dovranno essere effettivamente rappresentate nel computer. Serve per definire *cosa* rappresentare. Il risultato è uno schema concettuale (es. il **Modello Entità-Relazione** o E/R).
2.  **Progettazione Logica (La piantina dell'ingegnere):** Lo schema concettuale è bello per gli umani, ma non può essere "dato in pasto" a un computer. Questa fase definisce l'organizzazione effettiva dei dati per il computer, traducendo i concetti astratti in una precisa struttura dati che un software possa gestire. Oggi il modello logico dominante è il **Modello Relazionale** (che trasforma le entità concettuali in tabelle informatiche).
3.  **Progettazione Fisica (I lavori in cantiere):** Si prendono le tabelle logiche e si implementano materialmente sul disco fisso (scegliendo l'allocazione della memoria, la formattazione dei byte, ecc.). Nei DBMS moderni, questo lavoro di basso livello è gestito in gran parte in automatico dal software stesso.

Al termine di questo processo costruttivo, entra in gioco un'operazione di verifica fondamentale:

*   **La Normalizzazione:** È un processo matematico e formale che si esegue sul modello logico per verificare se il database è stato progettato correttamente. Se vengono individuate delle ridondanze o delle anomalie strutturali, la normalizzazione permette di correggerle scomponendo le tabelle problematiche secondo regole precise (chiamate *forme normali*).

---

## Il Percorso di questa Sezione

Ora che abbiamo chiarito il "vocabolario" e i concetti fondamentali dei database, nelle prossime pagine affronteremo l'intero percorso costruttivo, partendo dall'analisi di un problema fino ad arrivare al database funzionante:

1.  **[Progettazione Concettuale](/database/progettazione-concettuale/)**: Impareremo a modellare la realtà in modo astratto usando il Modello Entità-Relazione (Modello E/R).
2.  **[Progettazione Logica](/database/progettazione-logica/)**: Scopriremo come convertire lo schema E/R nelle vere e proprie tabelle del Modello Relazionale.
3.  **[Normalizzazione](/database/normalizzazione/)**: Vedremo le regole (fino alla Terza Forma Normale) per analizzare e ottimizzare un database finito.
4.  **[Creazione e Utilizzo con MySQL](/database/mysql/)**: Infine, metteremo le mani in pasta usando XAMPP e il linguaggio SQL per creare il database, inserire i dati e interrogarlo.
