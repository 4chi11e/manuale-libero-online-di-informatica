---
title: La Normalizzazione
description: Verificare e ottimizzare il database per evitare anomalie
---

La **Normalizzazione** è un processo formale che si esegue sul Modello Logico (le tabelle) per verificare se il database è stato progettato correttamente. 
Se la progettazione concettuale (il modello E/R) e la traduzione in tabelle sono state fatte a regola d'arte, la normalizzazione si limiterà a confermare che tutto è a posto. Se invece abbiamo commesso degli errori o "preso delle scorciatoie", fondendo dati che dovevano stare separati, la normalizzazione ci obbligherà a correggerli.

## Perché normalizziamo? Il problema delle Anomalie e delle Incongruenze

L'obiettivo principale della normalizzazione è eliminare le **ridondanze**. Nei database, avere dati ridondanti (cioè ripetuti in più punti) non è solo uno spreco di spazio, ma è l'origine di gravissimi errori chiamati **anomalie**.

Per capire il problema, prendiamo un esempio classico: un database di film. Se, per pigrizia, invece di creare due tabelle separate decidessimo di inserire il Genere cinematografico direttamente come attributo normale dentro la tabella dei Film, cosa succederebbe?

*   **Anomalia di Inserimento e Incongruenze:** Avendo tanti film di genere "Fantascienza", saremmo costretti a digitare la parola "Fantascienza" decine di volte. Se un utente la scrivesse in modi diversi ("Fantascenza" senza la *i*, o "Sci-Fi"), il database inizierebbe ad avere delle gravi **incongruenze**. Non riusciremmo più a raggruppare o filtrare correttamente i film per genere, perché il sistema li vedrebbe come generi diversi.
*   **La soluzione:** Avendo invece una tabella `GENERI` separata (dove le caratteristiche di quel genere sono scritte *una volta sola*), possiamo collegare i film tramite una chiave esterna (`ID_Genere`). Questo non solo elimina alla radice il problema di scrivere lo stesso genere in modi diversi, ma ci regala il superpotere dell'**Integrità Referenziale**: il database controllerà che ogni relazione sia valida, impedendo fisicamente di inserire in un film un `ID_Genere` che non esiste nella tabella dei generi!

Per assicurarci che le nostre tabelle siano separate correttamente e non nascondano questi problemi, applichiamo le **Forme Normali**. Un database relazionale si considera ben progettato quando rispetta almeno le prime tre.

## Il concetto chiave: La Dipendenza Funzionale
Prima di vedere le forme normali, dobbiamo capire il concetto logico di **Dipendenza Funzionale**.
In parole semplici, diciamo che un attributo B dipende funzionalmente da un attributo A se, *conoscendo il valore di A, posso determinare un solo e unico valore per B*.
*Esempio:* Conoscendo il `Codice Fiscale` (A), posso determinare in modo univoco il `Nome` (B). Quindi il Nome dipende funzionalmente dal Codice Fiscale.

L'obiettivo di una buona tabella è che **tutti i suoi campi dipendano esclusivamente dalla Chiave Primaria**.

---

## 1. Prima Forma Normale (1FN)
Una tabella è in Prima Forma Normale se rispetta queste due regole fondamentali:
1.  **Atomicità:** Ogni cella della tabella deve contenere un **singolo valore indivisibile** (atomico). Non posso avere un campo `Telefoni` in cui inserisco "333123456, 333987654". I dati multipli richiedono una tabella a parte.
2.  **Nessun gruppo ripetuto:** Non posso aggirare la regola precedente creando infinite colonne chiamate `Telefono_1`, `Telefono_2`, `Telefono_3`. Se il numero di attributi dello stesso tipo può variare, serve una tabella collegata con un'associazione 1:N.

**Una buona notizia!**
Se hai applicato correttamente le regole di derivazione del capitolo precedente (in particolare sciogliendo gli **attributi composti** e trasformando gli **attributi multipli** in nuove tabelle separate), ti accorgerai che **le tue tabelle sono già automaticamente in Prima Forma Normale!** Questo dimostra quanto sia potente e "preventivo" fare una buona progettazione concettuale a monte.

## 2. Seconda Forma Normale (2FN)
Una tabella è in Seconda Forma Normale se:
1.  È già in 1FN.
2.  **Tutti i campi non chiave dipendono dall'INTERA chiave primaria, e non solo da una parte di essa.**

Questa regola entra in gioco **solo se la tabella ha una Chiave Primaria Composta** (formata da due o più campi). Questo errore, tipicamente, si verifica quando abbiamo progettato male un'associazione **Molti a Molti (N:N)**, "mischiando" gli attributi delle entità originali dentro la tabella ponte.

Se, ad esempio, in una tabella ponte degli esami `ESAMI (Matricola*, Codice_Corso*, Voto, Nome_Studente)` inseriamo per errore il campo `Nome_Studente`, commettiamo una violazione: il nome dello studente dipende *solo* dalla `Matricola` (una parte della chiave), non dal `Codice_Corso`. Quel campo va tolto e riposizionato nella sua vera tabella originaria (`STUDENTI`)!

## 3. Terza Forma Normale (3FN)
Una tabella è in Terza Forma Normale se:
1.  È già in 2FN.
2.  **Nessun campo non chiave dipende da un altro campo non chiave (nessuna dipendenza transitiva).**

In parole povere: tutti gli attributi devono dipendere *direttamente* dalla chiave primaria principale, e non da un attributo secondario. 
Così come la 2FN blocca gli errori di progettazione sulle N:N, questo errore si verifica tipicamente quando abbiamo progettato male un'associazione **Uno a Molti (1:N)**, decidendo erroneamente di fondere le due entità in un'unica gigantesca tabella (ad esempio, mettendo tutti i dati della `Classe` dentro la tabella degli `Studenti`).

*Esempio:* Se nella tabella degli studenti scrivessimo `STUDENTI (Matricola, Nome, ID_Classe, Anno_Classe, Sezione_Classe)`, commetteremmo una gravissima violazione: l'`Anno` e la `Sezione` non dipendono dallo studente, ma dipendono dall'`ID_Classe` (che a sua volta dipende dallo studente). Questa è la famosa dipendenza transitiva! 
Questo genera ridondanza, costringendoci a riscrivere i dati della classe per ogni singolo studente che la frequenta, rischiando pericolose incongruenze. La soluzione è spezzare la tabella: mantenere solo l'`ID_Classe` negli Studenti come chiave esterna, e ricollocare `Anno` e `Sezione` nella loro vera tabella originaria `CLASSI`.
