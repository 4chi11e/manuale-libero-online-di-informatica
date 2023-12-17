---
layout: default
title: Installazione ambiente
nav_order: 1
parent: Programmazione in C
has_children: False
---

# Installazione ambiente di lavoro
{: .no_toc}

Per poter scrivere un programma in C è necessario installare sul proprio computer due programmi:
  
* TOC
{:toc}

## il compilatore (MinGW)
Il linguaggio C, come molti altri linguaggi, è un linguaggio che per poter essere eseguito deve prima essere compilato. La CPU dei computer è in grado di eseguire solo il proprio set di istruzioni (instruction set del processore) che costituisce il cosiddetto "linguaggio macchina", e non conosce altri linguaggi. Per questo motivo è necessario che sul computer sia installato un programma detto "compilatore" che trasformi il codice scritto in linguaggio C in un codice scritto in linguaggio macchina.

Il C è uno dei linguaggi più diffusi che esista e sono presenti compilatori per un vastissimo numero di sistemi come ad esempio Windows, MacOS, Linux in tutte le loro versioni. Di seguito verrà spiegato come installare un compilatore per il sistema operativo Windows.

Il compilatore scelto è MinGW, un compilatore molto usato in ambiente Windows. L'installazione di questo compilatore non è particolarmente complessa ma può risultare ostica per uno studente alle prime armi. Di seguito sono quindi riportate nel dettaglio le operazioni da fare.

1. Scarica l’installer da [https://sourceforge.net/projects/mingw/](https://sourceforge.net/projects/mingw/), cliccando sul pulsantone verde “download”;

    <!-- thumbnail -->
    <div class="thumbnail--w100 mt-4 mb-4">
        <img src="{{site.baseurl}}/assets/images/eserciziario_C/installazione/download_mingw.png" class="modal__opener" aprire="#img-download_mingw">
    </div>
    <!-- modal -->
    <div id="img-download_mingw" class="modal">
    <div class="modal__content">
        <span class="modal__closer modal__closer--topright" chiudere="#img-download_mingw">&times;</span>
        <div class="modal__content__img-container">   
            <img src="{{site.baseurl}}/assets/images/eserciziario_C/installazione/download_mingw.png">
        </div>
    </div>
    </div>

2. Apri l’installer che hai scaricato e alle prime due schermate premi i pulsanti “Install” e “Continue” senza cambiare nulla. L’installer ci metterà un po’ di tempo a scaricare tutto, poi  dopo aver premuto di nuovo “Contunue” comparirà una schermata da cui scegliere i componenti che si vogliono installare.

    <!-- thumbnail -->
    <div class="thumbnail--w100 mt-4 mb-4">
        <img src="{{site.baseurl}}/assets/images/eserciziario_C/installazione/installer_mingw.png" class="modal__opener" aprire="#img-installer_mingw">
    </div>
    <!-- modal -->
    <div id="img-installer_mingw" class="modal">
    <div class="modal__content">
        <span class="modal__closer modal__closer--topright" chiudere="#img-installer_mingw">&times;</span>
        <div class="modal__content__img-container">   
            <img src="{{site.baseurl}}/assets/images/eserciziario_C/installazione/installer_mingw.png">
        </div>
    </div>
    </div>


3. Cliccare a sinistra su “Basic Setup” e poi a destra sui quadratini a fianco di “mingw32-base” e mingw32-gcc-g++” e scegliere “Mark for Installation”. Infine scegliere dal menu in alto a sinistra “Installation” la voce “Apply changes”. Quando si apre la finestra premere su “Apply”. Alla fine dell’installazione premere “Close”. 

4. Cerca nel pannello di controllo di windows “modifica le variabili di ambiente relative al sistema” e aprilo (puoi cercarlo velocemente dal menu start con la parola chiave “path”). Sulla finestra che si apre clicca il bottone in basso a destra “Variabili d’ambiente…”.	
Nella finestra che si apre ci sono due elenchi, vai nel secondo dedicato alle variabili di sistema (non dell’utente corrente) e fai doppio click sulla varibile “Path”.	
Nella nuova finestra clicca su nuovo e scrivi il percorso “C:\MinGW\bin” (posizione di default, se hai installato mingw in un'altra cartella dovrai inserire quel percorso).

    <!-- thumbnail -->
    <div class="thumbnail--w100 mt-4 mb-4">
        <img src="{{site.baseurl}}/assets/images/eserciziario_C/installazione/variabili_di_sistema.png" class="modal__opener" aprire="#img-variabili_di_sistema">
    </div>
    <!-- modal -->
    <div id="img-variabili_di_sistema" class="modal">
    <div class="modal__content">
        <span class="modal__closer modal__closer--topright" chiudere="#img-variabili_di_sistema">&times;</span>
        <div class="modal__content__img-container">   
            <img src="{{site.baseurl}}/assets/images/eserciziario_C/installazione/variabili_di_sistema.png">
        </div>
    </div>
    </div>

    <!-- thumbnail -->
    <div class="thumbnail--w100 mt-4 mb-4">
        <img src="{{site.baseurl}}/assets/images/eserciziario_C/installazione/variabili_di_sistema_2.png" class="modal__opener wauto" aprire="#img-variabili_di_sistema_2">
    </div>
    <!-- modal -->
    <div id="img-variabili_di_sistema_2" class="modal">
    <div class="modal__content">
        <span class="modal__closer modal__closer--topright" chiudere="#img-variabili_di_sistema_2">&times;</span>
        <div class="modal__content__img-container">   
            <img src="{{site.baseurl}}/assets/images/eserciziario_C/installazione/variabili_di_sistema_2.png">
        </div>
    </div>
    </div>

A questo punto il compilatore dovrebbe essere correttamente installato e le altre applicazioni come l'IDE che installeremo saranno in grado di utilizzarlo per compilare i nostri programmi. Se hai già aperto VSCode (l'IDE) prima di installare il MinGW dovrai chiuderlo e riaprirlo perché VSCode carica le variabili di sistema all suo avvio. 

## L'IDE (Visual Studio Code)

Esistono moltissimi IDE (integrated development environment o ambiente di sviluppo integrato) per sviluppare programmi in C, dai più semplici ai più complessi. è Possibile scrivere programmi in C con un semplice editor di testo e compilarli da riga di comando ma sarebbe inutilmente scomodo. Con un buon IDE è possibile avere a disposizione una serie di strumenti che rendono il nostro lavoro più veloce e comodo.

L'IDE che utilizzeremo è Visual Studio Code, un software relativamente recente ma molto diffuso anche in ambito professionale per via della sua versatilità e espandibilità. VSCode è utilizzato per programmare in moltissimi linguaggi e per esso sono state sviluppate moltissime estensioni.

Di seguito sono riportate le operazioni da effettuare per installare e configurare VSCode sul tuo PC.

1. A meno di esigenze particolari scarica il system installer da 64bit che puoi trovare sul sito https://code.visualstudio.com/download.
2. Esegui l'installer che hai scaricato e durante le prime fasi **ricordati flaggare le voci corrette** come riportato nell'immagine di seguito:
    <!-- thumbnail -->
    <div class="thumbnail--w100 mt-4 mb-4">
        <img src="{{site.baseurl}}/assets/images/eserciziario_C/installazione/spunte_installazione_vscode.png" class="modal__opener" aprire="#img-spunte_installazione_vscode">
    </div>
    <!-- modal -->
    <div id="img-spunte_installazione_vscode" class="modal">
    <div class="modal__content">
        <span class="modal__closer modal__closer--topright" chiudere="#img-spunte_installazione_vscode">&times;</span>
        <div class="modal__content__img-container">   
            <img src="{{site.baseurl}}/assets/images/eserciziario_C/installazione/spunte_installazione_vscode.png">
        </div>
    </div>
    </div>
3. Una volta installato il programma aprilo e vai nella sezione dedicata alle estensioni cliccando sull'icona corretta a sinistra (vedi immagine sotto). Le estensioni da installare sono:
   1. C/C++, estensione che permette a VSCode di gestire correttamente i linguaggi C e C++ nell editor del codice (durante la scrittura del codice in C, VSCode ti propone di installare questa estensione se non l'hai ancora fatto)
   2. Code Runner, estensione che aggiunge un pulsante "play" in alto a destra per compilare ed eseguire in automatico il codice che hai scritto.
        <!-- thumbnail -->
        <div class="thumbnail--w100 mt-4 mb-4">
            <img src="{{site.baseurl}}/assets/images/eserciziario_C/installazione/estensioni_vscode.png" class="modal__opener" aprire="#img-estensioni_vscode">
        </div>
        <!-- modal -->
        <div id="img-estensioni_vscode" class="modal">
        <div class="modal__content">
            <span class="modal__closer modal__closer--topright" chiudere="#img-estensioni_vscode">&times;</span>
            <div class="modal__content__img-container">   
                <img src="{{site.baseurl}}/assets/images/eserciziario_C/installazione/estensioni_vscode.png">
            </div>
        </div>
        </div>
   3. C/C++ Compile Run, estensione alternativa a Code Runner che offre maggiori funzionalità (ad es. eseguire su una console esterna, inserire file di output in una sottocartella) ma può dare problemi se non la si sa utilizzare.
4. Una volta installate le estensioni vanno modificate alcune impostazioni. Il menù impostazioni è velocemente accessibile dal tasto in basso a sinistra;
    <!-- thumbnail -->
    <div class="thumbnail--w100 mt-4 mb-4">
        <img src="{{site.baseurl}}/assets/images/eserciziario_C/installazione/impostazioni_vscode.png" class="modal__opener wauto" aprire="#img-impostazioni_vscode">
    </div>
    <!-- modal -->
    <div id="img-impostazioni_vscode" class="modal">
    <div class="modal__content">
        <span class="modal__closer modal__closer--topright" chiudere="#img-impostazioni_vscode">&times;</span>
        <div class="modal__content__img-container">   
            <img src="{{site.baseurl}}/assets/images/eserciziario_C/installazione/impostazioni_vscode.png">
        </div>
    </div>
    </div>

   Le impostazioni da modificare sono:
   1. “run in terminal” da spuntare nelle impostazioni e trovabile velocemente inserendo la voce nella barra di ricerca e cliccando sull’estensione interessata come nella seguente immagine:  
        <!-- thumbnail -->
        <div class="thumbnail--w100 mt-4 mb-4">
            <img src="{{site.baseurl}}/assets/images/eserciziario_C/installazione/run_in_terminal.png" class="modal__opener" aprire="#img-run_in_terminal">
        </div>
        <!-- modal -->
        <div id="img-run_in_terminal" class="modal">
        <div class="modal__content">
            <span class="modal__closer modal__closer--topright" chiudere="#img-run_in_terminal">&times;</span>
            <div class="modal__content__img-container">   
                <img src="{{site.baseurl}}/assets/images/eserciziario_C/installazione/run_in_terminal.png">
            </div>
        </div>
        </div>
   2. “Mouse Wheel Zoom” da spuntare come fatto per l’impostazione precedente
        <!-- thumbnail -->
        <div class="thumbnail--w100 mt-4 mb-4">
            <img src="{{site.baseurl}}/assets/images/eserciziario_C/installazione/wheel_zoom.png" class="modal__opener" aprire="#img-wheel_zoom">
        </div>
        <!-- modal -->
        <div id="img-wheel_zoom" class="modal">
        <div class="modal__content">
            <span class="modal__closer modal__closer--topright" chiudere="#img-wheel_zoom">&times;</span>
            <div class="modal__content__img-container">   
                <img src="{{site.baseurl}}/assets/images/eserciziario_C/installazione/wheel_zoom.png">
            </div>
        </div>
        </div>
5. È possibile modificare a piacere altre impostazioni come:
   1. Save file before run
   2. Save all files before run
   3. Color Theme
   4. Clear Previous Output


