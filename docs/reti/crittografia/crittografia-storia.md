---
layout: default
title: Storia della Crittografia
nav_order: 1
parent: Crittografia
grand_parent: Reti
---

# Storia della Crittografia
{: .no_toc}

* TOC
{:toc}

## Crittografia antica

### Scitala lacedemonica

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/reti/crittografia/crittografia-Skytale.png" class="modal__opener" aprire="#img-scitala">
  <p>Una ricostruzione di scitala.</p>
</div>
<!-- modal -->
<div id="img-scitala" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-scitala">&times;</span>
    <div class="modal__content__img-container"> 
      <img src="{{site.baseurl}}/assets/images/reti/crittografia/crittografia-Skytale.png">
    </div>
    <p>Una ricostruzione di scitala.</p>
  </div>
</div>

Rappresenta una delle più antiche forme di crittografia: era già presente negli scritti di Plutarco (400 a.C.).

Consisteva in un bastone in cui si avvolgeva ad elica un nastro di cuoio (algoritmo di cifratura).

La chiave consisteva nel diametro del cilindro e la scrittura avveniva per colonne parallele all’asse del bastone lettera per lettera.

### Disco di Enea (390-360 a.C.)

Tra il 390 e il 360 a.C. Enea il tattico, generale della lega arcadica, scrive il primo trattato di cifrari. Nel XXI capitolo, che tratta appunto di messaggi segreti, viene descritto un disco sulla zona esterna del quale erano contenuti 24 fori, contrassegnati dalle lettere disposte in ordine alfabetico. Un filo, partendo da un foro centrale, si avvolgeva passando per i fori delle successive lettere del testo. Il destinatario del messaggio svolgeva il filo del disco segnando le lettere da esso indicate. Il testo si doveva poi leggere a rovescio.

### Atbash

E’ un metodo di cifratura ideato dal popolo ebraico: consisteva nel capovolgere l’alfabeto, con la conseguenza che la prima lettera diventava l’ultima e l’ultima la prima e così per tutte le altre lettere dell’alfabeto.

L’alfabeto chiaro e quello cifrato erano quindi rappresentati nel seguente modo:

<table class="tbl-cifratura">
  <tr>
    <th>CHIARO</th><td>a</td><td>b</td><td>c</td><td>d</td><td>e</td><td>f</td><td>g</td><td>h</td><td>i</td><td>j</td><td>k</td><td>l</td><td>m</td><td>n</td><td>o</td><td>p</td><td>q</td><td>r</td><td>s</td><td>t</td><td>u</td><td>v</td><td>w</td><td>x</td><td>y</td><td>z</td>
  </tr>
  <tr>
    <th>CIFRATO</th><td>Z</td><td>Y</td><td>X</td><td>W</td><td>V</td><td>U</td><td>T</td><td>S</td><td>R</td><td>Q</td><td>P</td><td>O</td><td>N</td><td>M</td><td>L</td><td>K</td><td>J</td><td>I</td><td>H</td><td>G</td><td>F</td><td>E</td><td>D</td><td>C</td><td>B</td><td>A</td>
  </tr>
</table>

**Esempio**<br>
Frase da cifrare: Il sole brilla<br>
Frase cifrata: Ro hlov yirooz
{: .fs-4 .code-example }

<!--
| CHIARO|a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|
|CIFRATO|Z|Y|X|W|V|U|T|S|R|Q|P|O|N|M|L|K|J|I|H|G|F|E|D|C|B|A|
-->

### Albam

Richiede che l’alfabeto venga diviso in due parti e che ogni lettera venga sostituita con la corrispondente dell'altra metà.

<table class="tbl-cifratura">
  <tr>
    <td>CHIARO</td><td>a</td><td>b</td><td>c</td><td>d</td><td>e</td><td>f</td><td>g</td><td>h</td><td>i</td><td>j</td><td>k</td><td>l</td><td class="bordo-destra-spesso">m</td><td>n</td><td>o</td><td>p</td><td>q</td><td>r</td><td>s</td><td>t</td><td>u</td><td>v</td><td>w</td><td>x</td><td>y</td><td>z</td></tr>
  <tr>
    <td>CIFRATO</td><td>N</td><td>O</td><td>P</td><td>Q</td><td>R</td><td>S</td><td>T</td><td>U</td><td>V</td><td>W</td><td>X</td><td>Y</td><td class="bordo-destra-spesso">Z</td><td>A</td><td>B</td><td>C</td><td>D</td><td>E</td><td>F</td><td>G</td><td>H</td><td>I</td><td>J</td><td>K</td><td>L</td><td>M</td>
  </tr>
</table>

### Atbah

In questo caso la sostituzione soddisfa una relazione di tipo numerico: le prime nove lettere dell’alfabeto vengono sostituite in modo tale che la somma della lettera da sostituire e della lettera sostituente risulti uguale a dieci. Per le restanti 9 lettere dell’alfabeto vale una regola simile con somma pari a 28 in decimale. Infine, per le ultime 8 lettetere vale la stessa regola con somma pari a 45.

<table class="tbl-cifratura">
  <tr>
    <th>CHIARO</th><td>a</td><td>b</td><td>c</td><td>d</td><td>e</td><td>f</td><td>g</td><td>h</td><td>i</td><td>j</td><td>k</td><td>l</td><td>m</td><td>n</td><td>o</td><td>p</td><td>q</td><td>r</td><td>s</td><td>t</td><td>u</td><td>v</td><td>w</td><td>x</td><td>y</td><td>z</td>
  </tr>
  <tr>
    <th>Num</th><td>1</td><td>2</td><td>3</td><td>4</td><td>5</td><td>6</td><td>7</td><td>8</td><td>9</td><td>10</td><td>11</td><td>12</td><td>13</td><td>14</td><td>15</td><td>16</td><td>17</td><td>18</td><td>19</td><td>20</td><td>21</td><td>22</td><td>23</td><td>24</td><td>25</td><td>26</td>
  </tr>
  <tr>
    <td>&nbsp;</td><td>1<br>+<br>9</td><td>2<br>+<br>8</td><td>3<br>+<br>7</td><td>4<br>+<br>6</td><td>5<br>+<br>5</td><td>6<br>+<br>4</td><td>7<br>+<br>3</td><td>8<br>+<br>2</td><td>9<br>+<br>1</td><td>10<br>+<br>18</td><td>11<br>+<br>17</td><td>12<br>+<br>16</td><td>13<br>+<br>15</td><td>14<br>+<br>14</td><td>15<br>+<br>13</td><td>16<br>+<br>12</td><td>17<br>+<br>11</td><td>18<br>+<br>10</td><td>19<br>+<br>26</td><td>20<br>+<br>25</td><td>21<br>+<br>24</td><td>22<br>+<br>23</td><td>23<br>+<br>22</td><td>24<br>+<br>21</td><td>25<br>+<br>20</td><td>26<br>+<br>19</td>
  </tr>
  <tr>
    <th>CIFRATO</th><td>I</td><td>H</td><td>G</td><td>F</td><td>E</td><td>D</td><td>C</td><td>B</td><td>A</td><td>R</td><td>Q</td><td>P</td><td>O</td><td>N</td><td>M</td><td>L</td><td>K</td><td>J</td><td>Z</td><td>Y</td><td>X</td><td>W</td><td>V</td><td>U</td><td>T</td><td>S</td>
  </tr>
</table>

Ad esempio la c = 3 viene sostituita con la g = 7 in modo che la somma sia 10

### Sperimenta la cifratura antica

Utilizza il seguente programma per verificare le tue soluzioni.  
Inoltre puoi fare tutti gli esperimenti che desideri e preparare i tuoi esercizi.

**Come funziona, per decifrare:**

- scrivi il messaggio da decifrare nel riquadro "Messaggio cifrato" (puoi anche utilizzare il copia e incolla per testi molto lunghi)
- scegli uno dei tre cifrari, selezionando il corrispondente bottone rotondo (radio button)
- clicca sul pulsante "Decifrare"

**Come funziona, per cifrare:**

- scrivi il messaggio da cifrare nel riquadro "Messaggio chiaro" (puoi anche utilizzare il copia e incolla per testi molto lunghi)
- scegli uno dei tre cifrari, selezionando il corrispondente bottone rotondo (radio button)
- clicca sul pulsante "Cifrare"

**Attenzione**: il programma converte i testi in lettere maiuscole e cifra/decifra soltanto i caratteri alfabetici. Tutti gli altri caratteri, come gli spazi, le virgole, i numeri etc. solo lasciati invariati.

<script language="JavaScript" src="{{site.baseurl}}/assets/js/crittografia-antica.js"></script>
<form name="controle">
  <table cellpadding="3" cellspacing="0">
    <tbody>
    <tr>
      <td bgcolor="#E3DAB7" colspan="6">
        <p align="center"><font size="2"><b>Messaggio chiaro<br>
        </b></font><textarea name="clair" rows="10" wrap="virtual" cols="60">UCCELLO IN GABBIA NON CANTA PER AMORE, CANTA PER RABBIA</textarea></p>
      </td>
    </tr>
    <tr>
      <td align="right" width="10"><input type="radio" checked="" value="1" name="layout"></td>
      <td align="left">Atbash</td>
      <td align="right" width="10"><input type="radio" value="2" name="layout"></td>
      <td align="left">Albam</td>
      <td align="right" width="10"><input type="radio" value="3" name="layout"></td>
      <td align="left">Atbah</td>
    </tr>
    <tr>
      <td colspan="6">
        <p align="center"><input onclick="chiffrer(clair, chiffre, true)" type="button" value="Cifrare">
          <input onclick="chiffrer(clair, chiffre, false)" type="button" value="Decifrare">
          <input onclick="clair.value=&#39;&#39;; chiffre.value=&#39;&#39;" type="button" value="Cancellare"></p>
      </td>
    </tr>
    <tr>
      <td bgcolor="#E3DAB7" colspan="6">
        <p align="center"><font size="2"><b>Messaggio cifrato</b></font><br>
          <textarea name="chiffre" rows="10" wrap="virtual" cols="60"></textarea></p>
      </td>
    </tr>
    </tbody>
  </table>
</form>

### Polibio (200 ca. -118 a.C.)

<div class="tbl-fr" markdown="1">
  | |1|2|3|4|5|
  |1|A|B|C|D|E|
  |2|F|G|H|I|J|
  |3|KQ|L|M|N|O|
  |4|P|R|S|T|U|
  |5|V|W|X|Y|Z|
  {: #polibio1 .ta-c .tab--p-3}

  <script>
    evidenziaBordoVerticale("polibio1",1,1);
    evidenziaBordoOrizzontale("polibio1",1,1);
  </script>
</div>

  <!-- <table id="polibio1" class="float-right ml-4 mr-4 ta-c">
    <tr><td></td><td>1</td><td>2</td><td>3</td><td>4</td><td>5</td></tr>
    <tr><td>1</td><td>A</td><td>B</td><td>C</td><td>D</td><td>E</td></tr>
    <tr><td>2</td><td>F</td><td>G</td><td>H</td><td>I</td><td>J</td></tr>
    <tr><td>3</td><td>KQ</td><td>L</td><td>M</td><td>N</td><td>O</td></tr>
    <tr><td>4</td><td>P</td><td>R</td><td>S</td><td>T</td><td>U</td></tr>
    <tr><td>5</td><td>V</td><td>W</td><td>X</td> <td>Y</td><td>Z</td></tr>
  </table> -->


Nelle sue Storie (Libro X) Polibio descrive un importante metodo di cifratura. L'idea è quella di cifrare una lettera con una coppia di numeri compresi tra 1 e 5, in base ad una matrice 5x5, contenente le lettere dell'alfabeto.

Ogni lettera viene rappresentata da due numeri, guardando la riga e la colonna in cui essa si trova. Per esempio, a=11 e r=42.

La sua importanza nella storia della crittografia sta nell’essere alla base di altri codici di cifratura come il <a href="">playfair cipher</a> o il <a href="">cifrario campale germanico</a> usato nella prima guerra mondiale.

**Esempio:**  
Attenzione agli scogli  
11444415345524353415 11223224 431335223224
{: .code-example .clear-right}

### Cifratura di Cesare (II secolo d.C.)

Questo antico sistema crittografico, in uso fino al rinascimento, è il più semplice codice simmetrico possibile. Consideriamo l’alfabeto latino di 26 caratteri e numeriamoli da 0 a 25.

Fissiamo un numero da 0 a 25 che sar`a la chiave segreta K. L’operazione di cifratura tramite il Codice di Cesare consiste nel sommare K ad ogni carattere del messaggio in chiaro: il crittogramma, cioè, si ottiene spostando “in avanti” di K posti ogni carattere del messaggio in chiaro. Grazie alla testimonianza di Svetonio sappiamo che Cesare utilizzava come chiave di cifratura K=3.

<table class="tbl-cifratura">
  <tr>
    <th>CHIARO</th><td>a</td><td>b</td><td>c</td><td>d</td><td>e</td><td>f</td><td>g</td><td>h</td><td>i</td><td>j</td><td>k</td><td>l</td><td>m</td><td>n</td><td>o</td><td>p</td><td>q</td><td>r</td><td>s</td><td>t</td><td>u</td><td>v</td><td>w</td><td>x</td><td>y</td><td>z</td>
  </tr>
  <tr>
    <th>CIFRATO</th><td>D</td><td>E</td><td>F</td><td>G</td><td>H</td><td>I</td><td>J</td><td>K</td><td>L</td><td>M</td><td>N</td><td>O</td><td>P</td><td>Q</td><td>R</td><td>S</td><td>T</td><td>U</td><td>V</td><td>W</td><td>X</td><td>Y</td><td>Z</td><td>A</td><td>B</td><td>C</td>
  </tr>
</table>

**Esempio:**<br>
Testo chiaro: JULIUS CAESAR<br>
Testo cifrato: MXOLXVFDHVDU
{: .code-example }

Questa stringa costituiva quindi il messaggio affidato al corriere e, teoricamente, anche se fosse caduto in mano nemica, la riservatezza restava garantita dal fatto che il nemico non conosceva la chiave K. Solo il legittimo destinatario, che conosceva la chiave, poteva recuperare il messaggio originale dal crittogramma eseguendo l’operazione inversa, cioè spostando ogni lettera del crittogramma “indietro” di K posti.

Per la cifratura secondo il Codice di Cesare, si deve immaginare l’alfabeto scritto su di una corona circolare (...XYZABC...) senza soluzione di continuità. Matematicamente, la cifratura di Cesare è una operazione di somma modulo 26 e la decifrazione è un’operazione di differenza modulo 26. Per ulteriori dettagli vedi il capitolo dedicato al [cifrario di Cesare generalizzato con l'aritmetica modulo n]({{site.baseurl}}/docs/reti/crittografia/crittografia/#il-cifrario-di-cesare-generalizzato-con-laritmetica-modulo-n).

Se l’avversario riesce a impadronirsi del crittogramma e sospetta trattarsi di un Codice di Cesare, può tentare un attacco di tipo“forza bruta”(ricerca esaustiva nello spazio delle chiavi), provando a decifrare il messaggio con tutte le possibili chiavi da K=1 (per K=0 si ha una cifratura banale che lascia inalterato il messaggio)
a K=25, sperando di imbattersi in un messaggio di senso compiuto. Questo elementare tipo di attacco è reso possibile dal numero estremamente esiguo di chiavi; il Codice di Cesare garantisce ora, perci`o, una sicurezza assai scarsa, invece al tempo di Cesare questo tipo di sistema crittografico era abbastanza sicuro, considerando che spesso i nemici non erano neanche in grado di leggere un testo in chiaro, men che mai uno cifrato e inoltre non esistevano metodi di crittanalisi in grado di rompere tale codice, per quanto banale.

## Crittografia Rinascimentale

Nel caso dei cifrari monoalfabetici, come quelli precedentemente illustrati, ad ogni lettera se ne sostituisce un'altra secondo opportune regole.

Un tale sistema è molto facile da attaccare e da violare: basta conoscere le proprietà statistiche del linguaggio con cui il testo è stato scritto, in altre parole conoscere le frequenze con le quali le lettere dell’alfabeto compaiono in un generico testo scritto nella stessa lingua del messaggio, per arrivare a trovare la corrispondenza tra le lettere del testo cifrato e quelle dell’alfabeto in chiaro.

Nel rinascimento si passò dalla sostituzione monoalfabetica a alla sostituzione polialfabetica: una cifratura per sostituzione polialfabetica si differenzia da quelle fino ad ora considerate per il fatto di utilizzare più alfabeti cifranti; con questo accorgimento il metodo dell'analisi delle frequenze perde di utilità poiché la stessa lettera nel messaggio in chiaro può essere tradotta con lettere diverse nel messaggio cifrato.

### Il Disco di Leon Battista Alberti

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/reti/crittografia/crittografia-disco_leonbattista_alberti.gif" class="modal__opener" aprire="#img-disco-leonbattista-alberti">
  <p>Disco di Leon Battista Alberti</p>
</div>
<!-- modal -->
<div id="img-disco-leonbattista-alberti" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-disco-leonbattista-alberti">&times;</span>
    <div class="modal__content__img-container"> 
      <img src="{{site.baseurl}}/assets/images/reti/crittografia/crittografia-disco_leonbattista_alberti.gif">
    </div>
    <p>Disco di Leon Battista Alberti</p>
  </div>
</div>

Nel suo Trattato De Cifris (circa nel 1400), Leon Battista Alberti introdusse il **primo codice polialfabetico**. Per tre secoli tale codice costituì il basamento dei sistemi crittografici. Inoltre, tale sistema introduce il concetto su cui si basa la macchina cifrante [Enigma](#enigma). E’ un disco composto di due cerchi concentrici di rame, uno esterno fisso di diametro maggiore sul quale sono riportate le lettere dell’alfabeto in chiaro (composto di 24 caselle contenenti 20 lettere maiuscole in ordine lessicografico, escluse H, J, K, W, Y, al posto delle quali ci sono i numeri 1, 2, 3, 4) e uno interno mobile per le lettere dell’alfabeto cifrante. Il disco interno riporta le 24 lettere minuscole in maniera disordinata (la e e la t sono collassate) ed un simbolo speciale et. Per utilizzare questo sistema, mittente e destinatario devono avere entrambi la stessa macchinetta e aver precedentemente concordato una lettera da utilizzare come chiave di partenza. Per cifrare il messaggio, il mittente inizia ruotando il disco interno in maniera casuale; scrive quindi il testo cifrato, riportando per prima cosa la lettera sul disco piccolo in corrispondenza della chiave concordata sul disco grande. Passa quindi ad eseguire la sostituzione del testo prelevando i caratteri sul disco più piccolo in corrispondenza dei caratteri da cifrare sul disco più grande. Terminata la prima parola, ruota di nuovo in maniera casuale il disco interno e itera la procedura di sostituzione. In questo modo, ogni parola utilizzava un proprio alfabeto di sostituzione e con tale dispositivo ne sono a disposizione 24 (ecco perché questo sistema è classificato tra i polialfabetici). Le lettere che di volta in volta corrispondono ai numeri 1,2,3,4 non vengono usate. Con questo tipo di sistema, la sicurezza è affidata ad una chiave di cifratura di un solo carattere: sarebbe semplicissimo decifrare il messaggio anche senza sapere che la prima lettera di ogni parola è la chiave di cifratura, basterebbe provare per ogni parola le 24 posizioni del disco. Con questo sistema Leon Battista riusciva ad **impedire l’analisi statistica basata sulla frequenza delle lettere** (da lui stesso studiata).

Tutti i metodi crittografici fin qui analizzati erano sicuri finchè l’algoritmo stesso che li generava rimaneva segreto: la crittografia moderna si basa invece sul presupposto che il messaggio possa rimanere segreto anche se il metodo utilizzato per generarlo viene scoperto.
{: .importante}

### Tavola di Vigenère

Blaise de Vigenère propose, in un trattato di cifrari pubblicato nel 1586, un codice che ebbe molta fortuna e che è ricordato con il suo nome. La sua fama è dovuta alla semplicità del semplice **codice polialfabetico**. Il principale punto di forza di questo metodo è l’utilizzo non di uno ma di ben 26 alfabeti cifranti per cifrare un solo messaggio. Il metodo si può considerare una generalizzazione e evoluzione dei codici di Cesare e del disco di Leon Battista Alberti. Invece di spostare sempre dello stesso numero di posti la lettera da cifrare, questa viene spostata di un numero di posti variabile, determinato dalle lettere della **parola chiave**, da concordarsi tra mittente e destinatario. La parola è detta chiave o verme, per il motivo che, essendo in genere molto più corta del messaggio, deve essere ripetuta molte volte.

Risulta evidente dall’esempio seguente che la stessa lettera nel testo in chiaro può essere cifrata con lettere diverse: ad esempio la “a” è stata cifrata con le lettere “s” “e” “l” “o”: è dunque impossibile utilizzare un metodo di analisi delle frequenze per decrittare il messaggio (i crittoanalisti svilupparono però altre tecniche e riuscirono ad aver ragione anche della cifratura di Vigenère).

<div class="code-example" markdown="1">
  **Esempio:**
  {: .mb-0}

|Testo in chiaro: |Attacco all'alba |
|Testo cifrato: |sheeuqzedzlpto |
{: .no-wrapper .invisible}

|a|t|t|a|c|c|o|a|l|l|a|l|b|a|
|S|O|L|E|S|O|L|E|S|O|L|E|S|O|
|s|h|e|e|u|q|z|e|d|z|l|p|t|o|
{: .tbl-cifratura}

</div>

| | | | |E| | | | | | |L| | |O| | | |S| | | | | | | |
|a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|
|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|a|
|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|a|b|
|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|a|b|c|
|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|a|b|c|d|
|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|a|b|c|d|e|
|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|a|b|c|d|e|f|
|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|a|b|c|d|e|f|g|
|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|a|b|c|d|e|f|g|h|
|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|a|b|c|d|e|f|g|h|i|
|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|a|b|c|d|e|f|g|h|i|j|
|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|a|b|c|d|e|f|g|h|i|j|k|
|m|n|o|p|q|r|s|t|u|v|w|x|y|z|a|b|c|d|e|f|g|h|i|j|k|l|
|n|o|p|q|r|s|t|u|v|w|x|y|z|a|b|c|d|e|f|g|h|i|j|k|l|m|
|o|p|q|r|s|t|u|v|w|x|y|z|a|b|c|d|e|f|g|h|i|j|k|l|m|n|
|p|q|r|s|t|u|v|w|x|y|z|a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|
|q|r|s|t|u|v|w|x|y|z|a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|
|r|s|t|u|v|w|x|y|z|a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|
|s|t|u|v|w|x|y|z|a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|
|t|u|v|w|x|y|z|a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|
|u|v|w|x|y|z|a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|
|v|w|x|y|z|a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|
|w|x|y|z|a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|
|x|y|z|a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|
|y|z|a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|
|z|a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|
{: #vigenere-table .tbl-cifratura}

<script>
  bordiColonna("vigenere-table",5);
  bordiColonna("vigenere-table",12);
  bordiColonna("vigenere-table",15);
  bordiColonna("vigenere-table",19);

  evidenziaRiga("vigenere-table",2);
  evidenziaRiga("vigenere-table",21);
</script>

## La crittografia dal XIX secolo alla Grande Guerra

Fino alla prima metà del XIX secolo la corrispondenza era esclusivamente cartacea ed era recapitata dai servizi postali. Tra la seconda metà del XIX secolo e il XX secolo, l’invenzione del telegrafo, del telefono e della radio hanno cambiato radicalmente il modo di comunicare, rendendo possibile la trasmissione di messaggi pressoché istantanea anche da luoghi molto distanti. Questi nuovi mezzi di comunicazione, la radio in particolare, rendevano però ancora più facili e frequenti le intercettazioni da parte di nemici; il ricorso alla crittografia diventa, quindi, inevitabile, come la necessità di cifrari sempre più sofisticati.

Nel 1863 il colonnello prussiano Friedrich Kasiski pubblica il primo metodo di decrittazione del cifrario di Vigenère basandosi sulla seguente osservazione: porzioni ripetute di messaggio cifrate con la stessa porzione di chiave risultano segmenti di testo cifrato identici. In questo periodo si sviluppano anche le prime macchine cifranti che permettono di ridurre notevolmente i tempi di cifratura e decifratura trasformando automaticamente le lettere del testo chiaro in quelle del testo cifrato e viceversa. Si può considerare come primissima e rudimentale macchina cifrante il disco di Leon Battista Alberti, ma è nella prima metà del Novecento che le macchine cifranti hanno il loro massimo sviluppo.

Di seguito verranno presentati prima i due cifrari più famosi e usati dell'epoca: [Playfair cipher](#playfair-cipher) e [cifra campale germanica](#cifra-campale-germanica-o-adfgvx), di seguito si parlerà di un famoso sistema di attacco ai sistemi crittografici dell'epoca: il [metodo Kasiski](#il-metodo-kasiski), e di come questo abbia portato a introdurre un sistema di cifratura matematicamente perfetto: il [cifrario di Vernam](#cifrario-di-vernam).

### Playfair cipher

Divulgato da Lyon Playfair doveva essere utilizzato durante la guerra di Crimea ma il sistema fu effettivamente utilizzato dall’esercito britannico solamente a partire dalla guerra Boera.

Rappresenta il primo metodo di cifratura a digrammi (in altre parole, ogni lettera del testo viene crittata con gruppi di due lettere). Si usa una matrice 5x5 di 25 lettere che viene riempita nelle prime caselle con la parola chiave, abolendo le eventuali lettere ripetute, ed è completata con le rimanenti lettere nel loro ordine alfabetico.

Vediamo con una applicazione come veniva utilizzato il Playfair cipher.

<div class="float-left mr-4" markdown="1">
  |S|E|G|R|T|
  |I/J|A|B|C|D|
  |F|H|K|L|M|
  |N|O|P|Q|U|
  |V|W|X|Y|Z|
  {: .tbl-cifratura}

</div>

Costruzione della matrice di 25 elementi:

|Chiave: |SEGRETI|
|||
|Messaggio: |Domani nella battaglia pensa a me|
| |DO MA NI NE LX LA BA TX TA GL IA PE NS AM EX|
{: .no-wrapper .invisible .mb-4}

Le lettere doppie sono separate per mezzo dell’inserimento di una X; inoltre, se l’ultima lettera rimane spaiata, viene a sua volta affiancata da una X.

E’ possibile a questo punto che si presenti uno dei seguenti casi: lettere su righe e colonne diverse, lettere sulla stessa riga o lettere sulla stessa colonna.

Caso 1: lettere su righe e colonne diverse

<div class="float-left mr-4 mb-4" markdown="1">
  |.|.|.|.|.|
  |.|A|.|.|D|
  |.|.|.|.|.|
  |.|O|.|.|U|
  |.|.|.|.|.|
  {: .tbl-cifratura}

</div>

Le lettere sono sostituite da quelle corrispondenti ai vertici opposti del rettangolo formato dall’incrocio di righe e colonne delle lettere del testo in chiaro.

Caso 2: lettere sulla stessa riga
{: .clear-both}

<div class="float-left mr-4 mb-4" markdown="1">
  |.|.|.|.|.|
  |I/J|A|B|C|D|
  |.|.|.|.|.|
  |.|.|.|.|.|
  |.|.|.|.|.|
  {: .tbl-cifratura}

</div>

Le lettere sono sostituite da quelle contenute nelle celle adiacenti, alla destra delle celle contenenti le lettere del testo chiaro.

Caso 3: lettere sulla stessa colonna
{: .clear-both}

<div class="float-left mr-4 mb-4" markdown="1">
  |S|.|.|.|.|
  |I/J|.|.|.|.|
  |F|.|.|.|.|
  |N|.|.|.|.|
  |V|.|.|.|.|
  {: .tbl-cifratura}

</div>

Le lettere sono sostituite da quelle contenute nelle celle adiacenti, sotto le celle contenenti le lettere del testo chiaro.

Il nostro messaggio viene dunque crittato come:  
DO MA NI NE LX LA BA TX TA GL IA PE NS AM EX AU HD VF OS KY HC CB GZ ED RK AB OG VI BW DH GW

E poi raggruppato in gruppi di cinque lettere:  
AUHDV FOSKY HCCBG ZEDRK ABOGV IBWDH GW

### Cifra campale germanica o ADFGVX

La cifra campale germanica è un metodo di crittografia usato dall’esercito tedesco nella Grande Guerra, a partire dagli inizi del 1918, anche chiamato metodo ADFGVX (lettere scelte per la facilità con cui vengono trasmesse nel codice morse). Il metodo utilizza una scacchiera 6x6 simile a quella usata nel Playfair Cipher, e nel cifrario bifido di Delastelle; si sostituiscono le lettere con gruppi di due o più lettere, le quali vengono poi sottoposte a una trasposizione per la trasmissione. Si tratta quindi di un cifrario poligrafico in cui si fa uso sia di un quadrato sia di una colonna per la trasposizione, e che necessita quindi di due chiavi per la cifratura: nel seguito chiameremo tali chiavi “chiave quadrato” e “chiave colonna”.

Vediamo come sia possibile utilizzare la cifra campale germanica con un esempio concreto.

Scegliamo una chiave per il quadrato:  
Chiave quadrato: DEUTSCHLAND

Si eliminano le lettere doppie dalla chiave, ottenendo: DEUTSCHLAN

Si aggiungono le rimanenti lettere dell’alfabeto in fondo alla stringa (una stringa è una serie di lettere ed eventualmente numeri, per cui si parla in generale di stringhe alfanumeriche) che si è ottenuta:

DEUTSCHLANBFGIJKMOPQRVWXYZ

Si inseriscono i numeri da 0 a 9 dopo le lettere della chiave con la seguente corrispondenza:

|A|B|C|D|E|F|G|H|I|J|
|1|2|3|4|5|6|7|8|9|0|
{: .tbl-cifratura}

D4E5UT SC3H8L A1NB2F 6G7I9J 0KMOPQ RVWXYZ

<div class="tbl-fl" markdown="1">
  | |A|D|F|G|V|X|
  |A|D|4|E|5|U|T|
  |D|S|C|3|H|8|L|
  |F|A|1|N|B|2|F|
  |G|6|G|7|I|9|J|
  |V|0|K|M|O|P|Q|
  |X|R|V|W|X|Y|Z|
  {: #campale1 .tbl-cifratura}

  <script>
    evidenziaBordoVerticale("campale1",1,1);
    evidenziaBordoOrizzontale("campale1",1,1);
  </script>
</div>

Si inserisce la stringa alfanumerica ottenuta in un quadrato di 6x6 celle:

Scegliamo un messaggio da trasmettere:  
Messaggio: Questo è un segreto

Ogni lettera del messaggio è sostituita dalle lettere corrispondenti rispettivamente alla riga e alla colonna della lettera del testo chiaro:

<div class="clear-both mb-4" markdown="1">
  |q|u|e|s|t|o|e|u|n|s|e|g|r|e|t|o|
  |VX|AV|AF|DA|AX|VG|AF|AV|FF|DA|AF|GD|XA|AF|AX|VG|

</div>

<div class="tbl-fl" markdown="1">
  |P|A|N|Z|E|R|
  |4|1|3|6|2|5|
  |V|X|A|V|A|F|
  |D|A|A|X|V|G|
  |A|F|A|V|F|F|
  |D|A|A|F|G|D|
  |X|A|A|F|A|X|  
  |V|G| | | | |
  {: #campale2 .tbl-cifratura}

  <script>
    evidenziaBordoOrizzontale("campale2",2,1);
  </script>
</div>

Scegliamo una chiave colonna per la trasposizione:  
Chiave colonna: PANZER

A ogni lettera della chiave colonna viene assegnato un numero in base all’ordine con cui compare nell’alfabeto (se la lettera compare più volte nella chiave si prosegue la numerazione cominciando da sinistra; es.: APOLLO = 164235). La stringa alfanumerica ottenuta dal procedimento sul quadrato è riscritta in una tabella sotto la chiave colonna.

Si leggono le colonne nell’ordine dato dalla chiave e si riscrivono in gruppi di cinque, ottenendo il messaggio crittato:  
XAFAA GAVFG AAAAA AVDAD XVFGF DXVXV FF


### Il metodo Kasiski

L’[attacco alla Kasiski](https://it.wikipedia.org/wiki/Metodo_Kasiski) si basa sull’osservazione che in un [crittogramma alla Vigenère](#tavola-di-vigenère) si trovano spesso sequenze identiche di caratteri a una certa distanza l’una dell’altra; infatti una stessa lettera del testo in chiaro viene, generalmente, cifrata con caratteri diversi nelle sue varie occorrenze, ma se due lettere identiche si trovano a una distanza pari a quella della chiave, o a un suo multiplo, vengono cifrate allo stesso modo. Per individuare la lunghezza della chiave sarà quindi sufficiente calcolare il massimo comun divisore tra le distanze tra sequenze ripetute. Una volta trovata la lunghezza della chiave, disponendo di un numero significativo di crittogrammi, si può applicare l’[analisi delle frequenze](https://it.wikipedia.org/wiki/Analisi_delle_frequenze) a sottoinsiemi di caratteri che occupano la medesima posizione all’interno di un blocco.

Questa tecnica viene anche chiamata metodo Babbage-Kasiski in quanto, già nel 1854, l’eccentrico matematico e inventore Charles Babbage aveva individuato un criterio di decifrazione del tutto analogo a quello successivamente elaborato dal Kasiski, ma mai pubblicato.

### Cifrario di Vernam

Ideato da Frank Miller nel 1882, perfezionato e brevettato nel 1919, negli USA, da Gilbert Vernam, il cifrario di Vernam è un sistema crittografico basato sul [cifrario di Vigenère](#tavola-di-vigen%c3%a8re), al quale aggiunge il requisito che la chiave di cifratura sia lunga quanto l'intero testo da cifrare e che non sia riutilizzabile (per questo viene spesso chiamato OTP, acronimo per l'inglese One Time Pad (OTP), letteralmente "taccuino monouso").

Il cifrario di Vernam è l'unico sistema crittografico la cui **sicurezza** sia **comprovata da una dimostrazione matematica** e per questo si è guadagnato il titolo di **"cifrario perfetto"**. La prima dimostrazione della sua inviolabilità fu pubblicata nel 1949 da [Claude Shannon](https://it.wikipedia.org/wiki/Claude_Shannon) nell'articolo La teoria della comunicazione nei sistemi crittografici.

Si può facilmente capire quanto sia scomodo distribuire in modo sicuro chiavi di tali dimensioni. Ciò nonostante il cifrario di Vernam è stato utilizzato per le comunicazioni con le spie, che venivano equipaggiate di taccuini (pad in inglese) contenenti una lunga chiave per ogni pagina, da poter strappare e gettare una volta utilizzata (one time, ovvero "un solo uso").

La sua forma più classica è quella in cui la chiave ha la stessa forma del testo (a ogni lettera viene associato il numero corrispondente A=0 B=1 C=2) e che sfrutta l’aritmetica modulare per operare sulle lettere (quella per cui dopo la lettera Z c'è di nuovo la lettera A, quindi:  
A+C = 0+2 = 2 = C,  
B+C = 1+2 = 3 = D,  
Z+C = 25+2 = 27→1 = B,  
Z+Z = 25+25 = 50→24 = Y).

```
Testo in chiaro: C I A O = 2  8  0 14
Chiave:          A J R Z = 0  9 17 25
-------------------------------------
                                   39
Testo cifrato:   C R R N = 2 17 17 13
```
{: .fs-4}

È tuttavia molto diffusa, specialmente nell'ambiente informatico, la forma che fa utilizzo dell'operazione logica XOR (disgiunzione esclusiva), che del resto non è altro che l'addizione circolare dei singoli bit che compongono la codifica in binario del testo.

Questo sistema di cifratura venne perfezionato e ampiamente utilizzato durante la guerra fredda, soprattutto dalle spie sovietiche. In circa 20 anni di ricerche, solamente una minima parte dei messaggi cifrati con questo metodo furono decifrate dagli americani e solamente perchè i mittenti utilizzarono per più di una volta le sequenze di numeri casuali, o perché sequenze delle stesse furono sequestrate a spie arrestate.

È **importante** ribadire che questo tipo di **chiave deve essere lunga quanto il messaggio che cifra e può essere utilizzata una sola volta**, pena la perdita della validità delle ipotesi iniziali e la riduzione da sistema "inattaccabile" a sistema "facilmente attaccabile" dal [metodo Kasiski](#il-metodo-kasiski), una specializzazione del metodo crittanalitico di [analisi delle frequenze](https://it.wikipedia.org/wiki/Analisi_delle_frequenze).

## Crittografia nella II Guerra Mondiale

La ricerca di nuovi sistemi crittografici diede un grande impulso alla crittografia durante il periodo antecedente la Seconda Guerra Mondiale. Già dall’inizio del XX sec, infatti, stava nascendo l’esigenza di poter usufruire di una crittografia sicura e, soprattutto, veloce e facilmente utilizzabile: per questo nacquero le prime macchine cifranti.

La prima macchina cifrante fu inventata dal comandante francese Etienne Bazières già nel 1891. Da questa prima macchina furono sviluppate molte altre che permettevano metodi di cifratura sempre più rapidi e sicuri; la più famosa di queste macchine è sicuramente Enigma.

### Enigma

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/reti/crittografia/crittografia-Enigma-Museo_scienza_e_tecnologia_Milano.jpg" class="modal__opener" aprire="#img-enigma-museo-milano">
  <p>Macchina Enigma. Esposta presso il <a href="https://it.wikipedia.org/wiki/Museo_nazionale_della_scienza_e_della_tecnologia_Leonardo_da_Vinci">Museo nazionale della scienza e della tecnologia "L. Da Vinci" di Milano</a>.</p>
</div>
<!-- modal -->
<div id="img-enigma-museo-milano" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-enigma-museo-milano">&times;</span>
    <div class="modal__content__img-container"> 
      <img src="{{site.baseurl}}/assets/images/reti/crittografia/crittografia-Enigma-Museo_scienza_e_tecnologia_Milano.jpg">
    </div>
    <p>Macchina Enigma. Esposta presso il <a href="https://it.wikipedia.org/wiki/Museo_nazionale_della_scienza_e_della_tecnologia_Leonardo_da_Vinci">Museo nazionale della scienza e della tecnologia "L. Da Vinci" di Milano</a>.</p>
  </div>
</div>

Enigma fu un dispositivo elettromeccanico per cifrare e decifrare messaggi sviluppata dalla società Scherbius&Ritter di Arthur Scherbius e Richard Ritter. Fu ampiamente utilizzata dal servizio delle forze armate tedesche durante il periodo nazista e della seconda guerra mondiale. La facilità d'uso e la presunta indecifrabilità furono le maggiori ragioni del suo ampio utilizzo.

Nonostante fosse stata modificata e potenziata nell'arco del suo periodo di utilizzo, un nutrito gruppo di esperti riuscì a violarla dopo essersi impegnato a lungo con questo intento. I primi a decifrarla nel 1932 furono un gruppo di matematici polacchi: Marian Rejewski, Jerzy Różycki e Henryk Zygalski. Il loro lavoro ha permesso di ottenere ulteriori informazioni sulla sempre più aggiornata macchina dei tedeschi "Enigma", prima in Polonia e, dopo lo scoppio della guerra, anche in Francia e Gran Bretagna. La decrittazione dei messaggi cifrati con Enigma fornì per quasi tutta la seconda guerra mondiale importantissime informazioni alle forze alleate.

#### Principio

In linea di principio, Enigma può essere considerata come un'estensione del metodo del [cifrario di Vigenère](#tavola-di-vigen%c3%a8re) munita di [disco di Leon Battista Alberti](#il-disco-di-leon-battista-alberti). La differenza principale sta nel fatto che i dischi cifranti sono più di uno, posti fra loro "in cascata", e che qui manca una chiave vera e propria, detta anche verme, che invece era elemento essenziale nella cifratura di Vigenère. La chiave, come nel disco di Leon Battista Alberti, è sostituita dalla configurazione iniziale della macchina.

#### Struttura

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/reti/crittografia/crittografia-schema_enigma.jpg" class="modal__opener" aprire="#img-schema-enigma">
  <p>Schema del funzionamento della macchina Enigma</p>
</div>
<!-- modal -->
<div id="img-schema-enigma" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-schema-enigma">&times;</span>
    <div class="modal__content__img-container"> 
      <img src="{{site.baseurl}}/assets/images/reti/crittografia/crittografia-schema_enigma.jpg">
    </div>
    <p>Schema del funzionamento della macchina Enigma</p>
  </div>
</div>

La macchina Enigma aveva l'aspetto di una macchina per scrivere con due tastiere: la prima, inferiore, e la seconda nella quale i tasti erano sostituiti da lettere luminose che si accendevano ogni qualvolta venisse premuto un tasto sulla tastiera effettiva; la sequenza delle lettere che si illuminavano dava il messaggio cifrato (o quello in chiaro, se si batteva il testo cifrato). Tra la tastiera e il visore si trovavano i componenti che permettevano la cifratura e decifratura dei messaggi.

#### Lo scambiatore

<!-- thumbnail -->
<div class="thumbnail float-right">
  <img src="{{site.baseurl}}/assets/images/reti/crittografia/crittografia-rotore.jpg" class="modal__opener" aprire="#img-rotore-enigma">
  <p>Rotore di una macchina Enigma</p>
</div>
<!-- modal -->
<div id="img-rotore-enigma" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-rotore-enigma">&times;</span>
    <div class="modal__content__img-container"> 
      <img src="{{site.baseurl}}/assets/images/reti/crittografia/crittografia-rotore.jpg">
    </div>
    <p>Rotore di una macchina Enigma</p>
  </div>
</div>

Lo scambiatore rappresenta la parte più importante della macchina: consiste in uno spesso disco di gomma attraversato da una fitta rete di fili provenienti dalla tastiera. Questi fili entrano nello scambiatore e dopo un percorso formato da vari gomiti emergono dalla parte opposta. Lo schema interno dello scambiatore determina in pratica un alfabeto cifrante utilizzabile per una semplice cifratura a sostituzione monoalfabetica.

Il passo successivo dell’idea di Scherbius prevedeva di far ruotare il disco dello scambiatore di un ventiseiesimo di giro dopo la cifratura di ogni lettera, facendo sì che l’alfabeto cifrante cambiasse dopo ogni lettera trasformando la cifratura da monoalfabetica a polialfabetica.

Così com’è il meccanismo presenta ancora il problema della ripetizione che è comunemente sinonimo di cifratura debole. Per superarlo vennero introdotti un secondo e un terzo scambiatore. Il secondo compiva una rotazione parziale soltanto dopo che il primo aveva compiuto un intero giro e allo stesso modo faceva il terzo basandosi sul secondo. In questo modo la macchina di Scherbius poteva disporre di 26 × 26 × 26 = 17576 procedure di sostituzione diverse.

#### Il Riflessore

Un altro degli elementi del dispositivo considerato importante dallo stesso inventore era il riflessore. Esso consisteva di un disco con circuiti interni simile agli scambiatori ma che non ruotava e i fili che vi entravano riemergevano dallo stesso lato (si veda la Figura 6). Con tale elemento installato un segnale in ingresso alla macchina attraversava i tre scambiatori, poi passava al riflessore e veniva rimandato indietro passando nuovamente negli scambiatori, ma usando un percorso diverso. In Figura 6 si vede come digitando la lettera “b” sulla tastiera, il percorso è tale da illuminare la lettera “c”.

Per aumentare ulteriormente il numero di chiavi, i rotori disponibili vennero portati da 3 a 5.

#### Pannello a prese multiple

Venne inoltre introdotto un pannello a prese multiple (Stecker) posto tra la tastiera e il primo rotore (si vedano la Figura 6 e la Figura 8). Tale dispositivo permetteva di inserire alcuni cavi muniti di spinotti, che avevano l’effetto di scambiare due lettere prima della loro immissione nel rotore. L’operatore di Enigma aveva a disposizione sei cavi per sei coppie di lettere, mentre le altre quattordici restavano non scambiate.

Combinando insieme tutti gli elementi fin qui osservati si può calcolare il numero di chiavi che Enigma poteva impiegare.

#### Calcolo del numero di chiavi possibili

- gli **scambiatori** (o **rotori**) potevano orientarsi oguno in 26 modi nel piano perpendicolare all’asse di rotazione, quindi tutti e tre generavano combinazioni; 26 x 26 x 26 = 17576
- all’interno dell’**unità cifratrice** i tre scambiatori potevano essere inseriti in diverse posizioni reciproche, così riassumibili: 123, 132, 213, 231, 312, 321. Erano quindi ammesse 3! = 6 diverse posizioni reciproche dei rotori;
- con il **pannello a prese multiple** i possibili abbinamenti di 12 (6x2) lettere su 26 sono moltissimi, per l’esattezza 100.391.791.500, che si ottiene dalla formula seguente dove p rappresenta il numero di chiavi ed è pari a 6:

$$ \binom{26}{2p} \cdot (2p-1) \cdot (2p-3) \cdot (2p-5) \cdot ... \cdot 1 = \frac{26!}{(26-2p)! \cdot p! \cdot 2^p} $$

- il numero totale di chiavi si ottiene moltiplicando tra loro le suddette possibilità:

17.576 · 6 · 100.391.791.500 = 105.869.167.644.240.000
{: .ta-c}

circa 10 milioni di miliardi.
{: .ml-5}

#### Utilizzo

Vediamo come veniva usata nella pratica una macchina Enigma.  
Innanzitutto bisogna specificare che gli scambiatori dovevano essere posizionati con un certo assetto prima di iniziare la cifratura di un messaggio e la loro posizione costituiva una vera e propria chiave. L’insieme di tali chiavi giornaliere era contenuta in un cifrario (Figura 9) che doveva essere distribuito mensilmente a tutti gli operatori e che doveva essere, ovviamente, molto ben custodito (torna, anche in questo caso, il **problema della distribuzione delle chiavi**). Gli assetti giornalieri del cifrario venivano usati per tutti i messaggi di una giornata. Per cifrare un messaggio un operatore Enigma posizionava gli scambiatori secondo la chiave giornaliera, digitava il messaggio sulla tastiera della macchina e spediva via radio il risultato al destinatario. Quest’ultimo digitava il messaggio cifrato sulla tastiera della sua macchina Enigma, sulla quale gli scambiatori erano sistemati secondo la stessa chiave giornaliera usata da chi aveva crittato il messaggio, e otteneva il messaggio in chiaro. La semplicità con cui questa operazione era realizzata era dovuta proprio all’introduzione del riflessore.

<!-- thumbnail -->
<div class="thumbnail--centrato mt-4 mb-4">
  <img src="{{site.baseurl}}/assets/images/reti/crittografia/esempio-chiavi-enigma.jpg" class="modal__opener" aprire="#img-esempio-chiavi-enigma">
  <p>Parte di un cifrario tedesco per macchine Enigma.</p>
</div>
<!-- modal -->
<div id="img-esempio-chiavi-enigma" class="modal">
  <div class="modal__content">
    <span class="modal__closer modal__closer--topright" chiudere="#img-esempio-chiavi-enigma">&times;</span>
    <div class="modal__content__img-container"> 
      <img src="{{site.baseurl}}/assets/images/reti/crittografia/esempio-chiavi-enigma.jpg">
    </div>
    <p>Parte di un cifrario tedesco per macchine Enigma.</p>
  </div>
</div>

I passaggi per l’utilizzo di Enigma si possono riassumere con i seguenti punti:

1. Walzenlage: quali rotori usare e in che ordine [II I III, III V II, ecc.];
2. Ringstellung: assetto degli anelli [F T R, Y V P, ecc.];
3. Steckerverbindungen: assetto del pannello a prese multiple [es., HR AT IW SN UY DF GV LJ DO MX];
4. Grundstellung: le 3 lettere che mostravano la posizione dei rotori da usare per cifrare il messaggio [v y j].

Oltre alle chiavi contenute nei cifrari, veniva anche utilizzata una chiave di messaggio usata per regolare il nuovo assetto: tale chiave era trasmessa due volte di seguito all’inizio di ogni messaggio, con l’assetto della chiave giornaliera (fu proprio questa ripetizione della chiave di messaggio all’inizio di ogni testo trasmesso il punto di partenza che permise al matematico Marian Rejewski di far breccia nel codice Enigma).

<div class="esempio" markdown="1">
  
**Esempio**
{: .mt-0 .fs-5}

**Cifratura**
{: .mb-0}

- Chiave giornaliera: QCW
- Chiave di messaggio: PGH
- Il mittente posiziona i rotori secondo la chiave giornaliera
- Digita PGH PGH sulla tastiera, ottenendo KIV BJE
- Posiziona gli scambiatori secondo la chiave di messaggio
- Scrive il messaggio

**Decifratura**
{: .mb-0}

- Il destinatario posiziona i rotori sulla chiave giornaliera QCW
- Digita le prime sei lettere del messaggio ricevuto, ottenendo PGH PGH
- Posiziona gli scambiatori secondo la chiave di messaggio
- Digita il resto del testo cifrato sulla tastiera ottenendo il testo in chiaro
{: .mb-0}

</div>

#### Approfondimenti e strumenti vari

- [Qui](http://users.telenet.be/d.rijmenants/en/enigmasim.htm) è possibile scaricare un software che riproduce il funzionamento di una macchina Enigma a tre rotori in dotazione alla Wehrmacht e il modello M4 a quattro rotori in dotazione alla Kriegmarine, entrambe utilizzate durante la Seconda Guerra Mondiale dal 1939 al 1945.
- [Qui](http://www.codesandciphers.org.uk/enigmafilm/emachines/enigma1.htm) è possibile utilizzare un simulatore che riproduce il funzionamento di una macchina Enigma a tre rotori in dotazione all’esercito e all’aviazione tedesca durante la seconda guerra mondiale, direttamente sul Web.
- [Qui](http://math.arizona.edu/~dsl/ephotos.htm) sono disponibili una serie di foto della macchina Enigma, anche con particolari dei componenti interni.


## Materiale, Link e riferimenti esterni

- [Crittografia su Wikipedia](https://it.wikipedia.org/wiki/Crittografia)
- Ing. Emanuele Salvador. *Appunti di Crittografia, una introduzione all'algebra moderna*. [Link locale]({{site.baseurl}}/assets/documenti/Crittografia.pdf)
- Ghilberti Chiara. (2011). *La storia della crittografia: appunti e riflessioni* [Tesi di laurea, Università di Bologna]. [Link locale]({{site.baseurl}}/assets/documenti/crittografia-alternativo.pdf), [link esterno](https://amslaurea.unibo.it/2571/1/giberti_chiara_tesi.pdf)
- Testi Simon Singh, “Codici e Segreti – La storia affascinante dei messaggi cifrati dall’antico Egitto a Internet”. BUR Saggi, Aprile 2005. 
- Frederick W. Winterbotham, “Ultra Secret – La macchina che decifrava i messaggi segreti dell’Asse”. Mursia, 1976. 
- Alessandro Languasco, Alessandro Zaccagnini, “Introduzione alla Crittografia”. HOEPLI Informatica, Milano, 2004. 
- [www.turing.org.uk/turing](http://www.turing.org.uk/turing) 
- [www.math.arizona.edu/~dsl/enigma.htm](http://www.math.arizona.edu/~dsl/enigma.htm) 
- [www.riksoft.com/indexok.asp?Goto=critlogia.htm](http://www.riksoft.com/indexok.asp?Goto=critlogia.htm) 
- [www.codesandciphers.org.uk](http://www.codesandciphers.org.uk) 
- [Pagina originale (in locale) dell'applet per sperimentare gli algoritmi di cifratura antichi]({{site.baseurl}}/assets/documenti/crittografia-cifrari_antichi.html)
- [Pagina originale (esterna) dell'applet per sperimentare gli algoritmi di cifratura antichi](http://utenti.quipo.it/base5/combinatoria/crittografia2.htm)


