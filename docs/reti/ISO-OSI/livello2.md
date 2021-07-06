---
layout: default
title: Livello 2 - Collegamento
nav_order: 2
parent: ISO/OSI
grand_parent: Reti
has_children: False
---

# Livello 2: Collegamento dati (Datalink layer)

_Obiettivo: permettere il trasferimento_ affidabile _di dati tra due nodi contigui nella rete attraverso il livello fisico. Invia frame di dati con la necessaria sincronizzazione ed effettua un [controllo degli errori](https://it.wikipedia.org/wiki/Rilevazione_e_correzione_d%27errore "Rilevazione e correzione d'errore") e delle perdite di segnale. Tutto ciò consente di far apparire, al livello superiore, il mezzo fisico come una linea di trasmissione esente da errori di trasmissione._

Questo livello si occupa in primis di formare i dati da inviare attraverso il livello fisico, [incapsulando](#incapsulamento) il pacchetto proveniente dallo strato superiore in un nuovo pacchetto provvisto di un nuovo _[header](https://it.wikipedia.org/wiki/Header "Header")_ (intestazione) e _tail_ (coda), usati anche per sequenze di controllo. Questa frammentazione dei dati in specifici pacchetti è detta _framing_ e i singoli pacchetti sono i _frame_. 

Le intestazioni contengono una serie di informazioni riguardanti il frame (detti _metadati_ ossia informazioni sui dati) che servono ai protocolli di livello 2 per gestire la trasmissione o effettuare il controllo degli errori. Due informazioni particolarmente importanti contenute negli header sono gli indirizzi di identificazione del mittente e del destinatario del frame detti _indirizzi MAC_. 

Come [controllo di errore](https://it.wikipedia.org/wiki/Controllo_di_errore "Controllo di errore"), per ogni pacchetto ricevuto, il destinatario invia al mittente un pacchetto **ACK** (_acknowledgement_, conferma) che ne conferma la corretta ricezione: il mittente deve ripetere l'invio dei pacchetti mal trasmessi e di quelli che non hanno ricevuto riscontro/risposta.

Questo livello si occupa anche di controllare il flusso di dati controllo di flusso: in caso di sbilanciamento della velocità di trasmissione tra mittente e destinatario, si occupa di rallentare l'operazione della macchina più veloce, accordandola all'altra e minimizzando così le perdite dovute a sovraccarico sul destinatario.

I protocolli più famosi che operano a questo livello sono:

- Ethernet (opera anche a livello 1)
- Wi-Fi (opera anche a livello 1)
- Point-to-Point Protocol (PPP)

[Link](https://it.wikipedia.org/wiki/Livello_di_collegamento_dati "Livello di collegamento dati") alla pagina wikipedia.

## Switch

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/switch-rack.jpg" class="modal__opener" aprire="#img-switch-rack">
  <p>Porzione di armadio rack contenente diversi switch a 24 porte</p>
</div>
<!-- modal -->
<div id="img-switch-rack" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-switch-rack">&times;</span>
    <div class="modal__content__img-container">   
      <img src="{{site.baseurl}}/assets/images/reti/ISO-OSI/switch-rack.jpg">
    </div>
    <p>Porzione di armadio rack contenente diversi switch a 24 porte</p>
  </div>
</div>

Uno switch è un dispositivo di rete di livello 2, usato per collegare computer appartenenti ad una stessa rete solitamente all'interno di una stanza o di un piano di un edificio. A differenza degli hub precedentemente descritti, gli switch operano sul livello di collegamento dati (livello 2) e sono in grado di leggere nell'intestazione di ogni frame l'indirizzo MAC di destinazione e scegliere la porta corretta su cui ritrasmettere il frame. In questo modo viene creato un dominio di collisione separato per ciascuna porta dello switch cioè ogni dispositivo collegato a una porta dello switch può trasferire dati in qualsiasi momento senza che le trasmissioni interferiscano con quelle di un altro dispositivo risolvendo il cosiddetto _problema delle collisioni_. Gli switch possono quindi gestire diverse decine di collegamenti contemporaneamente (si trovano facilmente switch da 24 o 48 porte).

Essendo un dispositivo di livello 2, lo switch opera sia sul livello 1 che sul livello 2.

Spesso si trovano in commercio dispositivi che vengono definiti switch ma che in realtà offrono funzionalità di livello più alto tipiche dei router.


## Link e riferimenti esterni

- [ISO/OSI su Wikipedia](https://it.wikipedia.org/wiki/Modello_OSI)
- [Livello di collegamento dati su Wikipedia](https://it.wikipedia.org/wiki/Livello_di_collegamento_dati)
