---
layout: default
title: Crittografia
nav_order: 2
parent: Reti
has_children: true
# has_toc: false
has_toc: true
---

<!-- JQuery -->
<script src="https://code.jquery.com/jquery-3.5.1.min.js" integrity="sha256-9/aliU8dGd2tb6OSsuzixeV4y/faTqgFtohetphbbj0=" crossorigin="anonymous"></script>
<!-- Miei script -->
<script src="{{site.baseurl}}/assets/js/bordi-tabelle.js"></script>
<script src="{{site.baseurl}}/assets/js/crittografia-antica.js"></script>

<!-- MathJax -->
<script src="https://polyfill.io/v3/polyfill.min.js?features=es6"></script>
<script id="MathJax-script" async src="https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-mml-chtml.js"></script>

# Crittografia
{: .no_toc}

* TOC
{:toc}

## Introduzione

La crittografia (dal greco kryptòs=nascosto e graphè=scrittura) sta ad indicare un insieme di procedure ideate allo scopo di nascondere il significato di un messaggio riservato ad altri che non ne fossero il mittente o il destinatario. Non è da confondere quindi con la crittologia che ha come scopo invece quello di nascondere l'esistenza stessa del messaggio.

Si hanno notizie dell’utilizzo della crittografia fin dal V sec. a.C., nello scambio di messaggi legati a questioni particolarmente delicate, in genere alla vigilia o durante conflitti militari; a partire dal 750 d.C. si sviluppa la crittoanalisi, lo studio dei sistemi in grado di svelare il contenuto di un messaggio segreto senza conoscere a priori la procedura utilizzata per cifrarlo. Da allora la storia delle informazioni riservate si snoda attraverso studi, successi e fallimenti di crittografi e crittoanalisti: i primi nel tentativo di creare una riservatezza inviolabile, gli altri in quello di trovarne i punti deboli.

Nella Società dell’informazione l’utilizzo della crittografia è legato al problema della sicurezza delle transazioni, particolarmente quelle economiche, attraverso la rete e più in generale della comunicazione. Azioni che svolgiamo ogni giorno come chiamare con il cellulare, aprire l’auto
con il telecomando o fare bancomat, fanno si che noi trasmettiamo informazioni
che potrebbero essere captate e sfruttate a nostro svantaggio. 

Gli studi dei crittografi e dei crittoanalisti sono strettamente connessi all’informatica: la scienza che si occupa della rappresentazione e della elaborazione dell’informazione e del suo trattamento automatico mediante elaboratori elettronici deve il primo elaboratore elettronico (il Colossus) ai tentativi degli studiosi di Bletchey Park di decifrare le comunicazioni cifrate con il sistema Lorenz e scambiate tra Hitler e i suoi capi di stato maggiore durante il secondo conflitto mondiale. Nel corso degli anni che separano il 1943 dall’epoca attuale, la crittografia ha raggiunto notevoli livelli di sicurezza, passando attraverso scoperte rilevanti e attirando l’attenzione di molti studiosi, che concentrarono le loro abilità nella risoluzione dei problemi di fondo che rendevano i sistemi crittografici di utilizzo esclusivo di una ristretta cerchia di persone “fidate” e li esponevano gravemente a intercettazione e decifrazione.

## Obiettivi della crittografia

Una comunicazione per poter essere considerata sicura, deve soddisfare 4 condizioni
- riservatezza dei dati: solo mittente e destinatario (o destinatari) devono essere in grado di comprendere il contenuto del messaggio;
- autenticazione dell'utente: chi riceve il messaggio deve essere sicuro dell'identità del mittente, in altri termini nessuno deve poter mandare un messaggio spacciandosi per qualcun altro;
- integrità dei dati: il destinatario deve essere sicuro che il messaggio ricevuto sia esattamente quello mandato dal mittente, senza errori o manipolazioni;
- non ripudio: chi spedisce un messaggio non può disconoscerne la paternità, negare cioè di essere stato lui a spedire il messaggio così come è stato ricevuto.

Se si guarda alla [storia della crittografia](#) si può notare che la maggior parte dei sistemi crittografici non garantivano pienamente tutte le condizioni. Anche molte tecniche moderne sono studiate per soddisfare solamente una parte di queste condizioni e per questo motivo i protocolli di comunicazione sicura moderni (ad esempio [TLS](#)) possono utilizzare diverse tecniche per raggiungere tutti e quattro gli obiettivi, oltre a risolvere altri problemi come quello dello scambio della chiave.


## Il problema dello scambio delle chiavi

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/crittografia/crittografia-cifratura-decifratura.jpg" class="modal__opener" aprire="#img-cifratura-decifratura">
  <p>Il principio della Crittografia.</p></div>
<!-- modal -->
<div id="img-cifratura-decifratura" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-cifratura-decifratura">&times;</span>
    <div class="modal__content__img-container"> 
      <img src="{{site.baseurl}}/assets/images/crittografia/crittografia-cifratura-decifratura.jpg">
    </div>
    <p>Il principio della Crittografia.</p>
  </div>
</div>

Uno dei problemi più complessi nell’evoluzione della crittografia, era costituito dal cosiddetto “scambio delle chiavi”: due parti che volessero scambiarsi messaggi cifrati, avevano ovviamente la necessità di conoscere entrambe la chiave di cifratura, che al mittente serviva per rendere il messaggio incomprensibile a terzi, e al destinatario serviva per riportare il messaggio cifrato in chiaro. 

Questo problema riguarda tutti i sistemi di cifratura simmetrici, quelli cioè in cui si usa la stessa chiave sia per cifrare che per decifrare, ed è stato risolto soltanto negli anni 1970 con l'invenzione della crittografia asimmetrica.

## Il principio di Kerckhoffs

Risulterà strano, ma uno dei principi fondamentali della crittografia, utilizzato ancora nei moderni sistemi crittografici è stato individuato nel lontano 1883 dal linguista francoolandese August Kerckhoffs nel suo celebre articolo “La cryptographie militaire” apparso nel Journal des sciences militaires.

“La sicurezza di un sistema crittografico è basata esclusivamente sulla segretezza della chiave, in pratica si presuppone noto a priori l’algoritmo di cifratura e decifrazione”
{: .fs-5 .importante}

Nella crittografia antica la sicurezza della comunicazione era affidata principalmente alla segretezza del sistema adottato, e per questo motivo tali sistemi non erano davvero sicuri. Spesso questi sistemi erano utilizzati in contesti bellici in cui bastava scoprire il sistema utilizzato dal nemico per poter decifrare per sempre tutti i suoi messaggi. Creare un nuovo sistema di crittografia valido è molto complesso e non può essere fatto continuamente. Per questo motivo è molto più conveniente avere un sistema per cui non importa se il nemico conosce la tecnica di crittografia adottata perchè mi basta sostituire frequentemente la chiave utilizzata per mantenere segrete le mie comunicazioni. Inventare nuove chiavi non richiede nessun impegno, ma nel caso della crittografia simmetrica rimane il problema di dover condividere continuamente le nuove chiavi.
