---
layout: default
title: Livello 5 - Sessione
nav_order: 5
parent: ISO/OSI
grand_parent: Reti
has_children: False
---

# Livello 5: sessione (Session Layer)
{: .no_toc}

_Obiettivo: controllare la comunicazione tra applicazioni. Instaurare, mantenere ed abbattere connessioni (sessioni) tra applicazioni cooperanti. Si occupa anche della sincronia di invio/ricezione messaggi. In pratica si occupa di gestire intere sessioni di comunicazione tra host._

Il livello di sessione è un livello normalmente poco studiato poichè è un livello che non offre di suo particolari servizi ma serve soprattutto a gestire i servizi offerti dal livello sottostante in modo da permettere alle applicazione di sfruttarli nella maniera desiderata. Il livello di sessione si occupa quindi di gestire le sessioni di comunicazione tra applicazioni su host diversi aprendo e chiudendo canali di comunicazione (servizio del livello 4) scegliendo opportunamente il protocollo da utilizzare (ad es. TCP o UDP) anche dinamicamente sulla base del controllo del traffico in corso.

I protocolli di livello di sessione sono tutti poco conosciuti anche perchè le funzionalità che il modello OSI colloca a questo livello sono solitamente incorporate nei protocolli di livello 7 seguendo essenzialmente il modello TCP/IP. Di seguito è comunque fornito un esempio di protocollo di livello di sessione.

L'RTP (Real-time Transfer Protocol) è un protocollo di livello di sessione utilizzato per servizi di comunicazione in tempo reale su internet. Internet offre un servizio *best-effort* e non sarebbe quindi adatto ad applicazioni real-time. Questo protocollo ottimizza i tempi di comunicazione monitorando costantemente il traffico dati e scegliendo di aprire connessioni TCP o UDP in base alle necessità. In questo modo si cerca di attenersi il più possibile ai vincoli richiesti da un'applicazione real time.

Per approfondire l'argomento è possibile consultare la [pagina wikipedia](https://it.wikipedia.org/wiki/Livello_di_sessione) dedicata al livello di sessione.


## Link e riferimenti esterni

- [ISO/OSI su Wikipedia](https://it.wikipedia.org/wiki/Modello_OSI)
- [Livello di sessione su Wikipedia](https://it.wikipedia.org/wiki/Livello_di_sessione)
