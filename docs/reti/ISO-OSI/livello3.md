---
layout: default
title: Livello 3 - Rete
nav_order: 3
parent: ISO/OSI
grand_parent: Reti
has_children: False
---

# Livello 3: Rete (Network Layer)
{: .no_toc}

_Obiettivo: rendere i livelli superiori indipendenti dai meccanismi e dalle tecnologie di trasmissione usate per la connessione e prendersi carico della consegna a destinazione dei pacchetti._

È responsabile di:

* [routing](https://it.wikipedia.org/wiki/Instradamento#Routing "Instradamento"): scelta ottimale del percorso di rete da utilizzare per garantire la consegna delle informazioni dal mittente al destinatario, scelta svolta dal [router](https://it.wikipedia.org/wiki/Router "Router") attraverso dei particolari [algoritmi di Routing](https://it.wikipedia.org/wiki/Protocolli_di_routing "Protocolli di routing") e [tabelle di routing](https://it.wikipedia.org/wiki/Routing_table "Routing table").
* conversione dei dati nel passaggio fra una rete ed un'altra con diverse caratteristiche, come il protocollo di rete utilizzato (_internet-working_). Deve, quindi:
  * tradurre gli indirizzi di rete;
  * valutare la necessità di frammentare i pacchetti dati se la nuova rete prevede una diversa dimensione dei pacchetti;
  * valutare la necessità di gestire diversi protocolli attraverso l'impiego di [gateway](https://it.wikipedia.org/wiki/Gateway_(informatica) "Gateway (informatica)").

La sua unità dati fondamentale è il _pacchetto_.

Il protocollo di rete più usato è il protocollo IP (Internet Protocol) usato in tutte le reti TCP/IP. Nella sezione dedicata al protocollo IP verranno analizzate nel dettaglio le operazioni effettuate nel livello di rete.

[Link](https://it.wikipedia.org/wiki/Livello_di_rete "Livello di rete") alla pagina wikipedia.

## Router

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/router.jfif" class="modal__opener" aprire="#img-router">
  <p>Router domestico dotato sia di porte fisiche che di antenne per il Wi-Fi</p>
</div>
<!-- modal -->
<div id="img-router" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-router">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/router.jfif">
    </div>
    <p>Router domestico dotato sia di porte fisiche che di antenne per il Wi-Fi</p>
  </div>
</div>

Un router è un dispositivo di rete di livello 3 usato per collegare sottoreti diverse e che si occupa di instradare i pacchetti fra le diverse sottoreti. Il router spesso opera anche come "gestore" di una determinata sottorete fornendo una serie di servizi agli host collegati a quella sottorete.

Mentre gli switch si occupano di collegare dispositivi all'interno di una stessa rete identificandoli per mezzo di indirizzi MAC, i router si occupano di collegare diverse reti utilizzando indirizzi di livello di rete che permettendo loro di effettuare il routing dei pacchetti tra reti differenti. Ogni protocollo di rete effettua queste operazioni in maniera differente. Nel capitolo riguardante il [protocollo IP](#) verrà trattato nel dettaglio questo argomento.

Spesso le reti sono organizzate gerarchicamente tra loro e i router sono quindi solitamente costruiti per rispettare tale ordine. Spesso quindi i router presentano una porta per la connessione alla rete "esterna" e una o più porte fisiche per i collegamenti verso la rete "interna". A volte possiedono anche antenne per fornire connessione Wi-Fi alla rete interna.

## Protocollo IP 
<!-- DA FARE -->



## Link e riferimenti esterni

- [ISO/OSI su Wikipedia](https://it.wikipedia.org/wiki/Modello_OSI)
- [Livello di rete su Wikipedia](https://it.wikipedia.org/wiki/Livello_di_rete)
- [Internet Protocol su Wikipedia](https://it.wikipedia.org/wiki/Internet_Protocol)
