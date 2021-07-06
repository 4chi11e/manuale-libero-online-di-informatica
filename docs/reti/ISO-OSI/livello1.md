---
layout: default
title: Livello 1 - Fisico
nav_order: 1
parent: ISO/OSI
grand_parent: Reti
has_children: False
---

# Livello 1: Fisico (Physical Layer)

_Obiettivo: trasmettere un flusso di dati non strutturati attraverso un collegamento fisico, occupandosi della forma e dei livelli di tensione del segnale. Ha a che fare con le procedure meccaniche ed elettroniche necessarie a stabilire, mantenere e disattivare un collegamento fisico._

Semplicemente: si occupa di controllare la rete, gli [hardware](https://it.wikipedia.org/wiki/Hardware "Hardware") che la compongono e i dispositivi che permettono la connessione.

In questo livello si decidono:

* Il numero di bit in un collegamento (PROB)
* Le tensioni scelte per rappresentare i valori logici dei bit trasmessi;
* La durata in microsecondi del segnale che identifica un bit;
* La [modulazione](https://it.wikipedia.org/wiki/Modulazione "Modulazione") e la [codifica](https://it.wikipedia.org/wiki/Codifica "Codifica") utilizzata;
* L'eventuale trasmissione simultanea in due direzioni Half-Duplex o Full-Duplex;
* La forma e la meccanica dei connettori usati per collegare l'hardware al mezzo trasmissivo.

I protocolli più famosi che operano a questo livello sono:
- Bluetooth
- DSL (Digital Subscriber Line)
- Ethernet (opera anche a livello 2)
- Wi-Fi (opera anche a livello 2)
- Wi-Max (opera anche a livello 2)

## Hub
<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/hub.jpg" class="modal__opener" aprire="#img-hub">
  <p>Un hub Ethernet da 4 porte.</p>
</div>
<!-- modal -->
<div id="img-hub" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-hub">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/hub.jpg">
    </div>
    <p>Un hub Ethernet da 4 porte.</p>
  </div>
</div>
L'hub è un disposivo di rete di livello fisico che funge da nodo di smistamento dati di una rete di comunicazione dati organizzata con una topologia logica a bus e di topologia fisica a stella. 

Questo dispositivo, operando a livello 1, non ha nessuna logica interna e si occupa solamente di ritrasmettere i segnali ricevuti da una porta su tutte le altre in broadcast. Per questo motivo una rete che utilizzi un hub, nonostante abbia una topologia fisica a stella con l'hub al cento, è di fatto una rete con topologia logica a bus ereditando i difetti di entrambe le topologie. Viste queste limitazioni un hub normalmente non ha un alto numero di porte.

Attualmente la tecnologia degli hub è considerata obsoleta, poiché largamente soppiantata dall'uso degli switch che, operando a livello 2, è in grado di decidere su quale porta ritrasmettere i segnali risolvendo il problema della collisioni.


## Link e riferimenti esterni

- [ISO/OSI su Wikipedia](https://it.wikipedia.org/wiki/Modello_OSI)
- [Livello fisico su Wikipedia](https://it.wikipedia.org/wiki/Livello_fisico)
