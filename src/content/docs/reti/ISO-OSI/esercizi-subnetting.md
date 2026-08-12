---
title: Esercizi Subnetting
---

<div id="esercizi-subnetting">
<h1>Esercizi sul Subnetting</h1>

<h2>Esercizio 1</h2>

<p>Dato l'indirizzo IP 200.110.12.0, specificare quante sottoreti e quanti
host per sottorete si possono ottenere con la maschera di sottorete 255.255.255.224.
</p>

<div class="soluzione-container">
<p class="soluzione-toggler" totoggle="#es01-semplice">Visualizza la soluzione</p>
<div class="soluzione soluzione-semplice" id="es01-semplice">
<p>[ 8 subnet | 30 host ciascuna ]</p>
</div>
</div>

<div class="soluzione-container">
<p class="soluzione-toggler" totoggle="#es01-completa">Visualizza la soluzione completa di procedimenti</p>

<div class="soluzione soluzione-completa" id="es01-completa">
<p>
L'indirizzo inizia con un numero maggiore di 192, si tratta di una classe C.<br>
La suddivisione fra subnet e host viene fatta sul 4° ottetto.
</p>
<p>Osservando la subnet mask abbiamo</p>
<p>255.255.255.224 = 11111111.11111111.11111111.11100000</p>
<p>Quindi gli host appartenenti alla rete avranno indirizzi del tipo</p>
<p>200.110.12.ssshhhhh</p>
<p>
ci saranno 3 bit dedicati alle subnet e 5 riservati agli host per un totale di:<br>
2<sup>3</sup> = 8 subnet da<br>
2<sup>5</sup> - 2 = 30 host ciascuna
</p>

</div>
</div>



<h2>Esercizio 2</h2>

<p>Dato l'indirizzo IP 200.110.12.0 partizionare la rete da esso individuata in 12 sottoreti specificando il numero di
host
che appartengono a ciascuna sottorete e indicare l'indirizzo ip del terzo host appartenente alla settima sottorete,
</p>

<div class="soluzione-container">
<p class="soluzione-toggler" totoggle="#es02-semplice">Visualizza la soluzione</p>
<div class="soluzione soluzione-semplice" id="es02-semplice">
<p>[ 200.110.12.99 ]</p>
</div>
</div>

<div class="soluzione-container">
<p class="soluzione-toggler" totoggle="#es02-completa">Visualizza la soluzione completa di procedimenti</p>

<div class="soluzione soluzione-completa" id="es02-completa">
<p><strong>Procedimento dettagliato:</strong></p>
<ol>
    <li><strong>Identificazione della Classe:</strong> L'indirizzo IP <code>200.110.12.0</code> appartiene alla <strong>Classe C</strong> (il primo ottetto è compreso tra 192 e 223). La subnet mask di default è quindi <code>255.255.255.0</code> (prefisso <code>/24</code>).</li>
    <li><strong>Calcolo dei bit di sottorete:</strong> Dobbiamo creare almeno 12 sottoreti. Cerchiamo la più piccola potenza di 2 maggiore o uguale a 12:
        $$2^n \ge 12 \implies n = 4 \text{ bit}$$
        Dobbiamo quindi dedicare 4 bit della parte host alle sottoreti (bit "rubati").
    </li>
    <li><strong>Nuova Subnet Mask:</strong> Aggiungendo 4 bit al prefisso di default (/24), otteniamo un prefisso di <code>/28</code> (ossia $24 + 4 = 28$ bit a 1).
        <ul>
            <li>In binario l'ultimo ottetto è: <code>11110000</code>.</li>
            <li>In decimale la maschera è: <code>255.255.255.240</code>.</li>
        </ul>
    </li>
    <li><strong>Numero di host utilizzabili per sottorete:</strong> Per gli host rimangono $8 - 4 = 4$ bit. Il numero di indirizzi utilizzabili per ciascuna sottorete è:
        $$2^4 - 2 = 16 - 2 = 14 \text{ host}$$
        (Si sottraggono 2 indirizzi riservati: uno per l'indirizzo di rete e uno per il broadcast).
    </li>
    <li><strong>Calcolo della 7ª sottorete:</strong> Ogni sottorete ha una dimensione totale di 16 indirizzi IP.
        <ul>
            <li>La 7ª sottorete ha indice 6 (poiché si parte da 0).</li>
            <li>Indirizzo di rete della 7ª sottorete: $200.110.12.(6 \times 16) = 200.110.12.96$.</li>
            <li>Intervallo host utilizzabili: da <code>200.110.12.97</code> a <code>200.110.12.110</code>.</li>
            <li>Indirizzo di broadcast: <code>200.110.12.111</code>.</li>
            <li>Il <strong>3° host utilizzabile</strong> è quindi: <strong><code>200.110.12.99</code></strong>.</li>
        </ul>
    </li>
</ol>
<p><em>Procedimento grafico originale (immagine):</em></p>
<p>
<img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/esercizi-subnetting/2.png">
</p>
</div>
</div>



<h2>Esercizio 3</h2>

<p>Determinare l'indirizzo di rete, la lunghezza del suo prefisso e la maschera di sottorete, necessari per individuare
la subnet che contiene il seguente intervallo di indirizzi IP 200.110.12.32 - 200.110.12.63.
</p>

<div class="soluzione-container">
<p class="soluzione-toggler" totoggle="#es03-semplice">Visualizza la soluzione</p>
<div class="soluzione soluzione-semplice" id="es03-semplice">
<p>[ 200.110.12.32/27 ]</p>
</div>
</div>

<div class="soluzione-container">
<p class="soluzione-toggler" totoggle="#es03-completa">Visualizza la soluzione completa di procedimenti</p>

<div class="soluzione soluzione-completa" id="es03-completa">
<p><strong>Nota bene:</strong> La soluzione grafica originale contiene un errore di calcolo (ipotizza l'aggiunta di soli 2 bit anziché 3). Di seguito viene riportata la spiegazione corretta passo dopo passo.</p>
<p><strong>Procedimento dettagliato:</strong></p>
<ol>
    <li><strong>Analisi dell'intervallo degli IP:</strong> Dobbiamo individuare una sottorete che contenga l'intervallo <code>200.110.12.32</code> - <code>200.110.12.63</code>.
        La variazione avviene solo nel 4° ottetto (da 32 a 63). Questo intervallo comprende esattamente 32 indirizzi IP totali ($63 - 32 + 1 = 32$).
    </li>
    <li><strong>Calcolo dei bit di host:</strong> Per contenere 32 indirizzi IP totali, abbiamo bisogno di:
        $$2^h = 32 \implies h = 5 \text{ bit per la parte host}$$
    </li>
    <li><strong>Calcolo della Subnet Mask:</strong> In un indirizzo IPv4 di 32 bit, se 5 bit sono dedicati agli host, i restanti bit sono dedicati alla rete:
        $$\text{Bit di rete} = 32 - 5 = 27 \text{ bit} \implies \text{prefisso } /27$$
        <ul>
            <li>In binario l'ultimo ottetto è: <code>11100000</code> (3 bit di rete e 5 di host).</li>
            <li>In decimale la subnet mask è: <code>255.255.255.224</code>.</li>
        </ul>
    </li>
    <li><strong>Determinazione dell'indirizzo di rete:</strong> Convertiamo in binario l'ultimo ottetto degli IP di partenza (32 e 63):
        <ul>
            <li>$32 \implies \mathbf{010}00000_2$</li>
            <li>$63 \implies \mathbf{010}11111_2$</li>
        </ul>
        I primi 3 bit del quarto ottetto (corrispondenti ai 3 bit aggiuntivi di rete del prefisso /27) sono identici per entrambi gli indirizzi (<code>010</code>). Azzerando i restanti 5 bit di host, otteniamo l'indirizzo di rete:
        $$\mathbf{010}00000_2 \implies 32 \text{ in decimale}$$
        L'indirizzo della sottorete è quindi <strong><code>200.110.12.32/27</code></strong>.
    </li>
</ol>
<p><em>Procedimento grafico originale (immagine con errore a fine calcolo):</em></p>
<p>
<img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/esercizi-subnetting/3.png">
</p>
</div>
</div>



<h2>Esercizio 4</h2>

<p>Determinare l'indirizzo di rete, la maschera di sottorete e l'indirizzo di broadcast del seguente blocco di indirizzi
IP
130.1.10.32/20.
</p>

<div class="soluzione-container">
<p class="soluzione-toggler" totoggle="#es04-semplice">Visualizza la soluzione</p>
<div class="soluzione soluzione-semplice" id="es04-semplice">
<p>[ 130.1.0.0 | 255.255.240.0 | 130.1.15.255 ]</p>
</div>
</div>

<div class="soluzione-container">
<p class="soluzione-toggler" totoggle="#es04-completa">Visualizza la soluzione completa di procedimenti</p>

<div class="soluzione soluzione-completa" id="es04-completa">
<p><strong>Procedimento dettagliato:</strong></p>
<ol>
    <li><strong>Analisi della maschera (/20):</strong> Un prefisso <code>/20</code> indica che i primi 20 bit dell'indirizzo appartengono alla rete, mentre i restanti 12 bit ($32 - 20 = 12$) appartengono agli host.
        <ul>
            <li>In binario: <code>11111111.11111111.11110000.00000000</code>.</li>
            <li>In decimale la maschera è: <code>255.255.240.0</code>.</li>
        </ul>
    </li>
    <li><strong>Calcolo dell'Indirizzo di Rete:</strong> Si ottiene azzerando tutti i 12 bit meno significativi della parte host dell'IP di partenza <code>130.1.10.32</code>.
        La variazione riguarda il terzo ottetto (che contiene gli ultimi 4 bit di rete e i primi 4 bit di host) e il quarto ottetto (tutti bit di host).
        <ul>
            <li>Il terzo ottetto 10 in binario è: $10 \implies 0000\mathbf{1010}_2$.</li>
            <li>Applicando la maschera (teniamo i primi 4 bit, azzeriamo gli ultimi 4): $0000\mathbf{0000}_2 \implies 0$.</li>
            <li>Il quarto ottetto (32) viene interamente azzerato $\implies 0$.</li>
            <li>L'indirizzo di rete risultante è: <strong><code>130.1.0.0</code></strong>.</li>
        </ul>
    </li>
    <li><strong>Calcolo dell'Indirizzo di Broadcast:</strong> Si ottiene impostando a 1 tutti i 12 bit di host.
        <ul>
            <li>Nel terzo ottetto, impostiamo a 1 gli ultimi 4 bit: $0000\mathbf{1111}_2 \implies 15$.</li>
            <li>Nel quarto ottetto, tutti gli 8 bit vengono impostati a 1: $11111111_2 \implies 255$.</li>
            <li>L'indirizzo di broadcast risultante è: <strong><code>130.1.15.255</code></strong>.</li>
        </ul>
    </li>
</ol>
<p><em>Procedimento grafico originale (immagine):</em></p>
<p>
<img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/esercizi-subnetting/4.png">
</p>
</div>
</div>



<h2>Esercizio 5</h2>

<p>192.168.23.87/26 e 192.168.23.67/26 appartengono alla stessa rete?
</p>

<div class="soluzione-container">
<p class="soluzione-toggler" totoggle="#es05-semplice">Visualizza la soluzione</p>
<div class="soluzione soluzione-semplice" id="es05-semplice">
<p>Sì, 192.168.23.64/26</p>
</div>
</div>

<div class="soluzione-container">
<p class="soluzione-toggler" totoggle="#es05-completa">Visualizza la soluzione completa di procedimenti</p>

<div class="soluzione soluzione-completa" id="es05-completa">
<p><strong>Procedimento dettagliato:</strong></p>
<ol>
    <li><strong>Analisi del prefisso (/26):</strong> Un prefisso <code>/26</code> dedica 26 bit alla parte di rete e $32 - 26 = 6$ bit alla parte host.
        La dimensione totale di ogni sottorete in termini di indirizzi IP è:
        $$2^6 = 64 \text{ indirizzi IP}$$
    </li>
    <li><strong>Determinazione degli intervalli delle sottoreti:</strong> Gli indirizzi cambiano solo nel 4° ottetto, a blocchi di 64:
        <ul>
            <li><strong>Sottorete 0:</strong> da <code>.0</code> a <code>.63</code> (Rete: <code>.0</code>, Broadcast: <code>.63</code>)</li>
            <li><strong>Sottorete 1:</strong> da <code>.64</code> a <code>.127</code> (Rete: <code>.64</code>, Broadcast: <code>.127</code>)</li>
            <li><strong>Sottorete 2:</strong> da <code>.128</code> a <code>.191</code> (Rete: <code>.128</code>, Broadcast: <code>.191</code>)</li>
            <li><strong>Sottorete 3:</strong> da <code>.192</code> a <code>.255</code> (Rete: <code>.192</code>, Broadcast: <code>.255</code>)</li>
        </ul>
    </li>
    <li><strong>Posizionamento degli indirizzi IP:</strong>
        <ul>
            <li>L'indirizzo <code>192.168.23.87</code> ha come quarto ottetto 87. Poiché $64 \le 87 \le 127$, appartiene alla <strong>Sottorete 1</strong> (rete <code>192.168.23.64/26</code>).</li>
            <li>L'indirizzo <code>192.168.23.67</code> ha come quarto ottetto 67. Poiché $64 \le 67 \le 127$, anch'esso appartiene alla <strong>Sottorete 1</strong> (rete <code>192.168.23.64/26</code>).</li>
        </ul>
    </li>
    <li><strong>Conclusione:</strong> I due indirizzi appartengono alla stessa rete, ovvero <strong><code>192.168.23.64/26</code></strong>.</li>
</ol>
<p><em>Procedimento grafico originale (immagine):</em></p>
<p>
<img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/esercizi-subnetting/5.png">
</p>
</div>
</div>



<h2>Esercizio 6</h2>

<p>Dopo aver verificato che i due indirizzi 130.37.23.100 e 130.37.22.150 subnet mask 255.255.254.0, sono sulla stessa
subnet; determina gli host con indirizzo di valore maggiore e quello con valore minore della subnet e l'indirizzo di
broadcast della stessa.
</p>

<div class="soluzione-container">
<p class="soluzione-toggler" totoggle="#es06-semplice">Visualizza la soluzione</p>
<div class="soluzione soluzione-semplice" id="es06-semplice">
<p>[ 130.37.23.254 | 130.37.22.1 | 130.37.23.255 ]</p>
</div>
</div>

<div class="soluzione-container">
<p class="soluzione-toggler" totoggle="#es06-completa">Visualizza la soluzione completa di procedimenti</p>

<div class="soluzione soluzione-completa" id="es06-completa">
<p><strong>Procedimento dettagliato:</strong></p>
<ol>
    <li><strong>Analisi della maschera:</strong> La subnet mask <code>255.255.254.0</code> in binario ha i primi 23 bit impostati a 1:
        <code>11111111.11111111.11111110.00000000</code> $\implies$ prefisso <code>/23</code>.
        <ul>
            <li>I bit dedicati agli host sono $32 - 23 = 9$ bit (1 bit nel terzo ottetto e 8 bit nel quarto).</li>
            <li>La dimensione totale di ogni sottorete è: $2^9 = 512$ indirizzi IP totali.</li>
            <li>I blocchi del terzo ottetto variano di $2^1 = 2$ alla volta ($512 / 256 = 2$). Gli indirizzi di rete avranno quindi sempre un terzo ottetto <strong>pari</strong>.</li>
        </ul>
    </li>
    <li><strong>Verifica dell'appartenenza alla stessa sottorete:</strong>
        Definiamo la sottorete contenente il terzo ottetto 22 e 23.
        Poiché 22 è pari, la sottorete inizia a <code>130.37.22.0</code>.
        La sottorete successiva inizierebbe a <code>130.37.24.0</code>.
        L'intervallo di questa sottorete va da <code>130.37.22.0</code> a <code>130.37.23.255</code>.
        <ul>
            <li><code>130.37.23.100</code> ricade in questo intervallo.</li>
            <li><code>130.37.22.150</code> ricade in questo intervallo.</li>
            <li>I due host appartengono alla stessa sottorete.</li>
        </ul>
    </li>
    <li><strong>Determinazione dei valori richiesti:</strong>
        <ul>
            <li><strong>Indirizzo di Rete:</strong> <strong><code>130.37.22.0</code></strong></li>
            <li><strong>Indirizzo di Broadcast:</strong> Si impostano a 1 tutti i 9 bit di host. Il terzo ottetto (22 in binario è <code>00010110</code>) con l'ultimo bit a 1 diventa <code>00010111</code> = 23. Il quarto ottetto a 1 diventa 255. L'indirizzo di broadcast è quindi <strong><code>130.37.23.255</code></strong>.</li>
            <li><strong>Host con IP minore (primo host utilizzabile):</strong> Indirizzo di rete + 1 $\implies$ <strong><code>130.37.22.1</code></strong>.</li>
            <li><strong>Host con IP maggiore (ultimo host utilizzabile):</strong> Indirizzo di broadcast - 1 $\implies$ <strong><code>130.37.23.254</code></strong>.</li>
        </ul>
    </li>
</ol>
<p><em>Procedimento grafico originale (immagine):</em></p>
<p>
<img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/esercizi-subnetting/6.png">
</p>
</div>
</div>



<h2>Esercizio 7</h2>

<p>Dato l'indirizzo IP 131.175.21.1/22 ; determina l'indirizzo di rete, la maschera di sottorete , l'indirizzo di
broadcast, il numero di subnet ed il numero di host per ciascuna subnet.
</p>

<div class="soluzione-container">
<p class="soluzione-toggler" totoggle="#es07-semplice">Visualizza la soluzione</p>
<div class="soluzione soluzione-semplice" id="es07-semplice">
<p>[ 131.175.20.0 | 255.255.252.0 | 131.175.23.255 ]</p>
</div>
</div>

<div class="soluzione-container">
<p class="soluzione-toggler" totoggle="#es07-completa">Visualizza la soluzione completa di procedimenti</p>

<div class="soluzione soluzione-completa" id="es07-completa">
<p><strong>Procedimento dettagliato:</strong></p>
<ol>
    <li><strong>Analisi del prefisso (/22):</strong>
        <ul>
            <li>La subnet mask in binario ha i primi 22 bit a 1 e i restanti 10 a 0:
                <code>11111111.11111111.11111100.00000000</code>.
            </li>
            <li>In decimale la subnet mask è: <strong><code>255.255.252.0</code></strong>.</li>
        </ul>
    </li>
    <li><strong>Calcolo del numero di sottoreti e host (Classe B):</strong>
        L'indirizzo <code>131.175.21.1</code> appartiene alla Classe B (primo ottetto tra 128 e 191). La default mask è `/16`.
        <ul>
            <li>Bit dedicati alle sottoreti: $22 - 16 = 6$ bit.</li>
            <li>Numero di subnet totali: $2^6 =$ <strong><code>64 sottoreti</code></strong>.</li>
            <li>Bit dedicati agli host: $32 - 22 = 10$ bit.</li>
            <li>Numero di host per sottorete: $2^{10} - 2 = 1024 - 2 =$ <strong><code>1022 host</code></strong>.</li>
        </ul>
    </li>
    <li><strong>Calcolo dell'Indirizzo di Rete:</strong>
        Convertiamo il terzo ottetto (21) in binario per azzerare i bit di host.
        <ul>
            <li>$21 \implies 000101\mathbf{01}_2$</li>
            <li>Azzerando gli ultimi 2 bit del terzo ottetto (che appartengono alla parte host): $000101\mathbf{00}_2 \implies 20$.</li>
            <li>Il quarto ottetto viene interamente azzerato $\implies 0$.</li>
            <li>L'indirizzo di rete è: <strong><code>131.175.20.0</code></strong>.</li>
        </ul>
    </li>
    <li><strong>Calcolo dell'Indirizzo di Broadcast:</strong>
        Si impostano a 1 tutti i 10 bit di host.
        <ul>
            <li>Nel terzo ottetto, impostiamo a 1 gli ultimi 2 bit: $000101\mathbf{11}_2 \implies 23$.</li>
            <li>Nel quarto ottetto, tutti gli 8 bit vanno a 1 $\implies 255$.</li>
            <li>L'indirizzo di broadcast è: <strong><code>131.175.23.255</code></strong>.</li>
        </ul>
    </li>
</ol>
<p><em>Procedimento grafico originale (immagine):</em></p>
<p>
<img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/esercizi-subnetting/7.png">
</p>
</div>
</div>



<h2>Esercizio 8</h2>

<p>Indicare l'indirizzo del primo e dell'ultimo host della 30a sottorete dell'indirizzo
150.12.0.0/22 calcola anche l'indirizzo del primo e dell'ultimo host della 50a subnet.
</p>

<div class="soluzione-container">
<p class="soluzione-toggler" totoggle="#es08-semplice">Visualizza la soluzione</p>
<div class="soluzione soluzione-semplice" id="es08-semplice">
<p>[ 1° host della 30ª sub = 150.12.116.1 | ultimo host della 30ª sub = 150.12.119.254 <br>
1° host della 50ª sub = 150.12.196.1 | ultimo host della 50ª sub = 150.12.199.254 ]</p>
</div>
</div>

<div class="soluzione-container">
<p class="soluzione-toggler" totoggle="#es08-completa">Visualizza la soluzione completa di procedimenti</p>

<div class="soluzione soluzione-completa" id="es08-completa">
<p><strong>Nota bene:</strong> L'immagine originale contiene un errore di conteggio per la 50ª sottorete (calcola i valori per l'indice 50, che corrisponde in realtà alla 51ª sottorete, invece dell'indice 49). Di seguito viene riportata la spiegazione corretta per entrambe le sottoreti.</p>
<p><strong>Procedimento dettagliato:</strong></p>
<ol>
    <li><strong>Analisi della maschera (/22):</strong>
        L'indirizzo <code>150.12.0.0/22</code> appartiene alla Classe B (default mask `/16`).
        <ul>
            <li>Bit dedicati alle sottoreti: $22 - 16 = 6$ bit.</li>
            <li>Bit dedicati agli host: $32 - 22 = 10$ bit.</li>
            <li>Ogni sottorete contiene $2^{10} = 1024$ indirizzi IP totali (pari a 4 classi C intere, poiché $1024 / 256 = 4$).</li>
            <li>La dimensione del blocco per il terzo ottetto è quindi <strong>4</strong>. Gli indirizzi IP di rete avranno il terzo ottetto multiplo di 4.</li>
        </ul>
    </li>
    <li><strong>Calcolo per la 30ª sottorete:</strong>
        <ul>
            <li>Poiché il conteggio delle sottoreti inizia da 0 (0-indexed), la 30ª sottorete ha indice <strong>29</strong>.</li>
            <li>Il terzo ottetto dell'indirizzo di rete si ottiene moltiplicando l'indice per la dimensione del blocco:
                $$\text{Terzo ottetto} = 29 \times 4 = 116$$
            </li>
            <li>Indirizzo di rete della 30ª subnet: <strong><code>150.12.116.0</code></strong>.</li>
            <li><strong>Primo host utilizzabile:</strong> Indirizzo di rete + 1 $\implies$ <strong><code>150.12.116.1</code></strong>.</li>
            <li>Indirizzo di broadcast: Si ottiene sommando 3 al terzo ottetto (poiché il blocco è di 4, da 116 a 119) e impostando a 255 il quarto ottetto $\implies$ <strong><code>150.12.119.255</code></strong>.</li>
            <li><strong>Ultimo host utilizzabile:</strong> Indirizzo di broadcast - 1 $\implies$ <strong><code>150.12.119.254</code></strong>.</li>
        </ul>
    </li>
    <li><strong>Calcolo per la 50ª sottorete (corretto):</strong>
        <ul>
            <li>La 50ª sottorete ha indice <strong>49</strong> (0-indexed).</li>
            <li>Il terzo ottetto dell'indirizzo di rete è:
                $$\text{Terzo ottetto} = 49 \times 4 = 196$$
            </li>
            <li>Indirizzo di rete della 50ª subnet: <strong><code>150.12.196.0</code></strong>.</li>
            <li><strong>Primo host utilizzabile:</strong> Indirizzo di rete + 1 $\implies$ <strong><code>150.12.196.1</code></strong>.</li>
            <li>Indirizzo di broadcast: Il terzo ottetto sale a $196 + 3 = 199$ e il quarto a 255 $\implies$ <strong><code>150.12.199.255</code></strong>.</li>
            <li><strong>Ultimo host utilizzabile:</strong> Indirizzo di broadcast - 1 $\implies$ <strong><code>150.12.199.254</code></strong>.</li>
            <li><em>(Nota: Nella soluzione grafica originale, l'autore ha calcolato per errore la 51ª subnet con indice 50, ottenendo la rete <code>150.12.200.0</code> e l'ultimo host <code>150.12.203.254</code>).</em></li>
        </ul>
    </li>
</ol>
<p><em>Procedimento grafico originale (immagine con errore di indice sull'esercizio della 50ª subnet):</em></p>
<p>
<img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/esercizi-subnetting/8.png">
</p>
</div>
</div>



<h2>Esercizio 9</h2>

<p>Indicare l'indirizzo del 20° host della 10a subnet relativa all'indirizzo di rete 180.180.0.0 con subnet mask
255.255.240.0.
</p>

<div class="soluzione-container">
<p class="soluzione-toggler" totoggle="#es09-semplice">Visualizza la soluzione</p>
<div class="soluzione soluzione-semplice" id="es09-semplice">
<p>[ 180.180.144.20 ]</p>
</div>
</div>

<div class="soluzione-container">
<p class="soluzione-toggler" totoggle="#es09-completa">Visualizza la soluzione completa di procedimenti</p>

<div class="soluzione soluzione-completa" id="es09-completa">
<p><strong>Procedimento dettagliato:</strong></p>
<ol>
    <li><strong>Analisi della maschera:</strong> La subnet mask <code>255.255.240.0</code> in binario ha i primi 20 bit impostati a 1:
        <code>11111111.11111111.11110000.00000000</code> $\implies$ prefisso <code>/20</code>.
        <ul>
            <li>Essendo una rete di Classe B (default mask `/16`), i bit dedicati alle subnet sono $20 - 16 = 4$ bit.</li>
            <li>I bit dedicati agli host sono $32 - 20 = 12$ bit.</li>
            <li>La dimensione totale di ciascuna sottorete è: $2^{12} = 4096$ indirizzi IP totali (pari a 16 classi C intere, poiché $4096 / 256 = 16$).</li>
            <li>La variazione nel terzo ottetto per ciascuna sottorete è quindi di <strong>16</strong>. Gli indirizzi di rete avranno il terzo ottetto multiplo di 16.</li>
        </ul>
    </li>
    <li><strong>Calcolo per la 10ª sottorete:</strong>
        <ul>
            <li>La 10ª sottorete ha indice <strong>9</strong> (0-indexed).</li>
            <li>Il terzo ottetto dell'indirizzo di rete si ottiene moltiplicando l'indice per la dimensione del blocco (16):
                $$\text{Terzo ottetto} = 9 \times 16 = 144$$
            </li>
            <li>L'indirizzo di rete della 10ª sottorete è quindi: <strong><code>180.180.144.0</code></strong>.</li>
        </ul>
    </li>
    <li><strong>Calcolo del 20° host:</strong>
        <ul>
            <li>I primi 8 bit della parte host corrispondono al quarto ottetto dell'indirizzo.</li>
            <li>Il 20° host si ottiene semplicemente sommando 20 all'indirizzo di rete:
                $$\text{IP 20° host} = 180.180.144.0 + 20 = \mathbf{180.180.144.20}$$
            </li>
        </ul>
    </li>
</ol>
<p><em>Procedimento grafico originale (immagine):</em></p>
<p>
<img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/esercizi-subnetting/9.png">
</p>
</div>
</div>



<h2>Esercizio 10</h2>

<p>Viene assegnato un indirizzo IP 199.10.10.0 (classe C), per eseguire il cablaggio di una rete collocata in un
edificio
scolastico come indicato in figura.
</p>
<p class="ta-c">
<img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/esercizi-subnetting/10-img-testo.png">
</p>
<p>Volendo realizzare una sottorete per ogni aula elenca l'indirizzo IP per ogni host della rete rappresentata. Si nota
che è necessario avere almeno 8 host per ogni sottorete.
</p>

<div class="soluzione-container">
<p class="soluzione-toggler" totoggle="#es10-completa">Visualizza la soluzione completa di procedimenti</p>

<div class="soluzione soluzione-completa" id="es10-completa">
<p><strong>Procedimento dettagliato:</strong></p>
<ol>
    <li><strong>Calcolo dei bit per host:</strong> L'IP di partenza è <code>199.10.10.0</code> (Classe C). Ci viene richiesto di cablare 5 sottoreti (una per ogni aula) in modo che ciascuna possa ospitare <strong>almeno 8 host</strong> utilizzabili.
        Cerchiamo il numero $X$ di bit host necessari:
        $$2^X - 2 \ge 8 \implies 2^X \ge 10 \implies X = 4 \text{ bit host}$$
        Con 4 bit host avremo $2^4 - 2 = 14$ host utilizzabili per sottorete, soddisfacendo il requisito.
    </li>
    <li><strong>Calcolo dei bit di rete e nuova maschera:</strong>
        Essendo una Classe C, l'ultimo ottetto (8 bit) viene suddiviso in subnet e host.
        <ul>
            <li>Bit dedicati alle subnet: $8 - 4 = 4$ bit.</li>
            <li>Nuovo prefisso di rete: $24 + 4 = 28$ bit $\implies$ prefisso <strong><code>/28</code></strong>.</li>
            <li>La subnet mask in decimale è: <strong><code>255.255.255.240</code></strong> (l'ultimo ottetto binario è <code>11110000</code>).</li>
            <li>La dimensione totale di ogni blocco di sottorete è: $2^4 = 16$ indirizzi IP.</li>
        </ul>
    </li>
    <li><strong>Assegnazione degli indirizzi IP per le 5 sottoreti (Multipli di 16):</strong>
    <div style="overflow-x: auto; width: 100%; margin: 15px 0;">
        <table class="tbl-nowrapper" style="width: 100%; border-collapse: collapse; min-width: 600px;">
            <thead>
                <tr style="background-color: var(--sl-color-gray-6); border-bottom: 2px solid var(--sl-color-gray-5);">
                    <th style="padding: 8px; text-align: left; white-space: nowrap;">Sottorete / Destinazione</th>
                    <th style="padding: 8px; text-align: left; white-space: nowrap;">Indirizzo Rete</th>
                    <th style="padding: 8px; text-align: left; white-space: nowrap;">IP Primo Host</th>
                    <th style="padding: 8px; text-align: left; white-space: nowrap;">IP Ultimo Host</th>
                    <th style="padding: 8px; text-align: left; white-space: nowrap;">IP Broadcast</th>
                </tr>
            </thead>
            <tbody>
                <tr style="border-bottom: 1px solid var(--sl-color-gray-5);">
                    <td style="padding: 8px; white-space: nowrap;"><strong>Subnet 0</strong> (Aula 1)</td>
                    <td style="padding: 8px; white-space: nowrap;"><code>199.10.10.0/28</code></td>
                    <td style="padding: 8px; white-space: nowrap;"><code>199.10.10.1</code></td>
                    <td style="padding: 8px; white-space: nowrap;"><code>199.10.10.14</code></td>
                    <td style="padding: 8px; white-space: nowrap;"><code>199.10.10.15</code></td>
                </tr>
                <tr style="border-bottom: 1px solid var(--sl-color-gray-5); background-color: rgba(255,255,255,0.02);">
                    <td style="padding: 8px; white-space: nowrap;"><strong>Subnet 1</strong> (Aula 2)</td>
                    <td style="padding: 8px; white-space: nowrap;"><code>199.10.10.16/28</code></td>
                    <td style="padding: 8px; white-space: nowrap;"><code>199.10.10.17</code></td>
                    <td style="padding: 8px; white-space: nowrap;"><code>199.10.10.30</code></td>
                    <td style="padding: 8px; white-space: nowrap;"><code>199.10.10.31</code></td>
                </tr>
                <tr style="border-bottom: 1px solid var(--sl-color-gray-5);">
                    <td style="padding: 8px; white-space: nowrap;"><strong>Subnet 2</strong> (Laboratorio 1)</td>
                    <td style="padding: 8px; white-space: nowrap;"><code>199.10.10.32/28</code></td>
                    <td style="padding: 8px; white-space: nowrap;"><code>199.10.10.33</code></td>
                    <td style="padding: 8px; white-space: nowrap;"><code>199.10.10.46</code></td>
                    <td style="padding: 8px; white-space: nowrap;"><code>199.10.10.47</code></td>
                </tr>
                <tr style="border-bottom: 1px solid var(--sl-color-gray-5); background-color: rgba(255,255,255,0.02);">
                    <td style="padding: 8px; white-space: nowrap;"><strong>Subnet 3</strong> (Laboratorio 2)</td>
                    <td style="padding: 8px; white-space: nowrap;"><code>199.10.10.48/28</code></td>
                    <td style="padding: 8px; white-space: nowrap;"><code>199.10.10.49</code></td>
                    <td style="padding: 8px; white-space: nowrap;"><code>199.10.10.62</code></td>
                    <td style="padding: 8px; white-space: nowrap;"><code>199.10.10.63</code></td>
                </tr>
                <tr style="border-bottom: 1px solid var(--sl-color-gray-5);">
                    <td style="padding: 8px; white-space: nowrap;"><strong>Subnet 4</strong> (Uffici)</td>
                    <td style="padding: 8px; white-space: nowrap;"><code>199.10.10.64/28</code></td>
                    <td style="padding: 8px; white-space: nowrap;"><code>199.10.10.65</code></td>
                    <td style="padding: 8px; white-space: nowrap;"><code>199.10.10.78</code></td>
                    <td style="padding: 8px; white-space: nowrap;"><code>199.10.10.79</code></td>
                </tr>
            </tbody>
        </table>
    </div>
    </li>
</ol>
<p><em>Procedimento grafico originale (immagine):</em></p>
<p>
<img src="/manuale-libero-online-di-informatica/assets/images/reti/ISO-OSI/esercizi-subnetting/10.png">
</p>
</div>
</div>
</div>





