---
layout: default
title: Livello 6 - Presentazione
nav_order: 6
parent: ISO/OSI
grand_parent: Reti
has_children: False
---

# Livello 6: presentazione (Presentation Layer)
{: .no_toc}

## Indice
{: .no_toc .text-delta }

- TOC
{:toc}

_Obiettivo: trasformare i dati forniti dalle applicazioni in un formato standardizzato e offrire servizi di comunicazione come la [crittografia](# "Crittografia"), la [compressione](https://it.wikipedia.org/wiki/Compressione_dati "Compressione dati") e la riformattazione dei dati._

In breve questo livello si occupa di tutto ciò che riguarda la forma che devono assumere i dati prodotti dalle applicazioni prima che vengano inoltrati ai livelli inferiori per essere trasmessi nella rete.

La compressione dei dati ha un ruolo molto importante nelle comunicazioni in rete perchè permette di ridurre anche considerevolmente il traffico dati. Per poter affrontare l'argomento sarebbe necessario un approfondito studio della teoria dell'informazione che è un argomento lungo e complesso. In questa sede ci concentreremo sullo studio dei protocolli finalizzati all'ottenimento di una comunicazione sicura tramite l'uso della crittografia (argomento ampiamente trattato in [questa sezione]({{site.baseurl}}/docs/reti/crittografia/crittografia/) del manuale).

Esistono diversi protocolli che utilizzano la crittografia per instaurare comunicazioni sicure nei più svariati contesti, come ad esempio PGP o SSH. Di seguito ci concentreremo su un protocollo particolarmente importante, il TLS.

## Transport Layer Security (TLS)

**Transport Layer Security (TLS)** e il suo predecessore **Secure Sockets Layer (SSL)** sono dei protocolli crittografici di presentazione che permettono una comunicazione sicura dalla sorgente al destinatario (end-to-end) su reti TCP/IP (come ad esempio Internet) fornendo autenticazione, integrità dei dati e confidenzialità operando al di sopra del livello di trasporto.

Diverse versioni del protocollo sono ampiamente utilizzate in applicazioni come i browser, l'e-mail, la messaggistica istantanea e il voice over IP. Un esempio di applicazione di SSL/TLS è nel protocollo HTTPS, che appunto significa HTTP over SSL.

### Storia
Lo stack protocollare TCP/IP di Internet, diversamente dal modello ISO/OSI, non prevede di per sé funzionalità di sicurezza per motivi storici legati all'uso principale della rete ai suoi primordi (semplice scambio di dati tra ricercatori nella comunità scientifica), e solo successivamente con l'apertura della Rete a fini pubblici le problematiche di sicurezza sono diventate via via sempre più importanti da cui la necessità di inserire degli strati aggiuntivi che si occupino appunto di sicurezza.

<div id="versioni-tls-ssl" markdown=1>
  
  **Protocolli SSL e TLS**
  {: .mb-0 .pb-0 .ta-c}

  |Protocollo | Pubblicato | Status
  |-|-|-|
  |**SSL 1.0** | Non pubblicato | Non pubblicato
  |**SSL 2.0** | 1995 | Deprecato nel 2011 (RFC 6176)
  |**SSL 3.0** | 1996 | Deprecato nel 2015 (RFC 7568)
  |**TLS 1.0** | 1999 | Deprecazione pianificata per il 2020
  |**TLS 1.1** | 2006 | Deprecazione pianificata per il 2020
  |**TLS 1.2** | 2008 | |
  |**TLS 1.3** | 2018 | |

</div>

Le prime implementazioni di SSL erano limitate a cifratura a chiave simmetrica di soli 40 bit a causa delle restrizioni imposte dal governo statunitense sull'esportazione di tecnologie crittografiche, per motivi di sicurezza nazionale. In altri termini, la limitazione della dimensione delle chiavi a 40 bit è stata esplicitamente imposta per rendere la cifratura abbastanza debole da potere essere forzata (tramite l'uso di tecniche di ricerca brute force) dalle autorità giudiziarie che volessero decifrare il traffico cifrato, ma sufficientemente resistente agli attacchi da parte di entità con minori disponibilità di risorse tecnologico-finanziarie. Dopo diversi anni di controversie pubbliche, cause e l'ammissione da parte del governo statunitense di disponibilità sul mercato di prodotti per la cifratura migliori (sia all'interno che al di fuori degli Stati Uniti), alcuni aspetti delle restrizioni sono stati modificati. Le implementazioni moderne utilizzano chiavi per la cifratura simmetrica a 128 (o più) bit.

### Funzionamento
I servizi offerti da TLS sono tre:
1. cifratura dei dati,
2. autenticazione dei partecipanti alla comunicazione,
3. controllo dell'integrità dei dati.

per poter offrire questi servizi il protocollo TLS divide la comunicazione tra host in tre fasi:

1. **Negoziazione fra le parti dell'algoritmo da utilizzare**.  
In questa fase i due host devono concordare quali algoritmi verranno utilizzati nelle fasi successive.
2. **Scambio delle chiavi e autenticazione**.  
Questa fase è quindi a sua volta divisa in due:  
> 1. utilizzo di un agoritmo di cifratura asimmetrico per effettuare uno scambio sicuro della chiave che verrà usata per il trasferimento dei dati che avverà con cifratura simmetrica che è più veloce e sicura.  
> 2. utilizzo di un algoritmo per l'autenticazione degli host. Molto spesso l'autenticazione TLS è unilaterale: è il solo server ad autenticarsi presso il client (il client, cioè, conosce l'identità del server, ma non viceversa cioè il client rimane anonimo e non autenticato sul server). Il browser valida il certificato del server controllando che la firma digitale dei certificati del server sia valida e riconosciuta da una certificate authority conosciuta utilizzando una cifratura a chiave pubblica. Nel caso di una connessione effettuata da un browser per mezzo del protocollo HTTPS, dopo questa autenticazione il browser indica una connessione sicura mostrando una specifica icona, di solito un lucchetto, di fianco all'URL. Questa fase è molto importante, basti pensare al caso in cui ci si voglia connettere al proprio servizio di home banking: è importante che il client sia sicuro di essersi connesso al giusto server e non ad un server fittizio creato per truffare i cilienti della banca.
3. **Cifratura simmetrica e autenticazione dei messaggi**.  
Questa fase consiste nella trasmissione dei dati veri e propri e ciò avviene per mezzo di un algoritmo di cifratura simmetrico che è molto più veloce e sicuro rispetto ad uno asimmetrico. In questa fase si utilizza anche una funzione crittografica di hash allo scopo di verificare che i dati ricevuti siano identici ai dati trasmessi evitando sia errori di trasmissione che eventuali manomissioni.

### Algoritmi utilizzati
All'interno di una sessione tipicamente vengono utilizzati i seguenti protocolli:
- Per lo scambio di chiavi: [RSA]({{site.baseurl}}/docs/reti/crittografia/crittografia-moderna/#rsa), [Diffie-Hellman]({{site.baseurl}}/docs/reti/crittografia/crittografia-moderna/#lo-scambio-di-chiavi-secondo-diffie-hellman-e-merkle), ECDH, SRP, PSK (pre-shared key o chiave precondivisa)
- Per l'autenticazione: [RSA]({{site.baseurl}}/docs/reti/crittografia/crittografia-moderna/#rsa), DSA, ECDSA
- Per la cifratura simmetrica: [RC4]({{site.baseurl}}/docs/reti/crittografia/crittografia-moderna/#rc4), [DES]({{site.baseurl}}/docs/reti/crittografia/crittografia-moderna/#des-data-encryption-standard), [Triple DES]({{site.baseurl}}/docs/reti/crittografia/crittografia-moderna/#3des-triple-des), [AES]({{site.baseurl}}/docs/reti/crittografia/crittografia-moderna/#aes-advanced-encryption-standard) (Attualmente questo è il più utilizzato e consigliato), IDEA o Camellia.
- Per le funzioni crittografiche d'integrità si usano usualmente funzioni di hash: in TLS sono utilizzati [HMAC-MD5](https://it.wikipedia.org/wiki/HMAC) o [HMAC-SHA](https://it.wikipedia.org/wiki/HMAC) (sistema che utilizza gli algoritmi di hash visti [qui]({{site.baseurl}}/docs/reti/crittografia/crittografia-moderna/#algoritmi-di-hash-crittografico) aggiungendo funzionalità e sicurezza aggiuntive)

Puoi approfondire l'argomento alla [pagina](https://en.wikipedia.org/wiki/Transport_Layer_Security) di wikipedia dedicata a TLS.


## Link e riferimenti esterni

- [ISO/OSI su Wikipedia](https://it.wikipedia.org/wiki/Modello_OSI)
- [Livello di presentazione su Wikipedia](https://it.wikipedia.org/wiki/Livello_di_presentazione)
- [TLS su Wikipedia](https://en.wikipedia.org/wiki/Transport_Layer_Security)


