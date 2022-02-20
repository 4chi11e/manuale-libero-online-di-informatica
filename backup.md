### Componenti comuni alle varie implementazioni

Tra i vari algoritmi di crittazione possiamo trovare alcune operazioni comuni, poiché aggiungono generalmente maggior sicurezza nel testo cifrato e sono operazioni rapide per la macchina.

Spesso una stessa operazione viene ciclata più volte, riferendosi a questi passaggi come **cicli** o **round**. Ad esempio in AES la stessa routine viene ripetuta 10 volte. In DES il testo in chiaro subisce 16 volte la crittazione insieme alla chiave prima di terminare. Una volta disegnato l'algoritmo viene molto facile ripeterlo, rendendo più complesso un lavoro di decrittazione forzata tramite brute force. Se l'algoritmo di decrittazione è ben disegnato e non si riescono ad avere informazioni sulla chiave, questo è l'unico metodo attraverso cui è possibile la decrittazione del messaggio cifrato.

Tra i vari algoritmi simmetrici possiamo riconoscere alcuni parametri standard come la **lunghezza della chiave** e la **dimensione del blocco**.

La lunghezza della chiave è misurata in bit e ha valori che oscillano tra 32 bit e 512 bit. Generalmente la lunghezza della chiave è un valore fisso nonostante esistano alcuni algoritmi come AES che impiegano lunghezze variabili.

Ogni algoritmo generalmente cerca di crittare una stringa di bit attraverso una chiave in un'altra stringa di bit della medesima lunghezza. La lunghezza di questa stringa è pari alla dimensione del blocco. Algoritmi ormai datati ma che hanno costituito uno standard per molti anni come il DES, avevano questo valore pari a 64bit in media. Oggi si preferisce adottare dimensioni di almeno 128 bit, numero che cresce nel tempo con l'aumentare della potenza dei computer. Per un alto livello di sicurezza oggi si consigliano 256 bit.

Un problema che affligge la dimensione del blocco è il [paradosso del compleanno](https://it.wikipedia.org/wiki/Paradosso_del_compleanno) che rilascia informazioni sulla chiave ogni volta che avviene una collisione (quando due blocchi vengono cifrati allo stesso modo). Possiamo ritenere sicura solo la radice quadrata di tutte le combinazioni possibili. Per esempio con una dimensione di 64 bit, che genererebbe 2<sup>64</sup> possibili combinazioni, potremo impiegarne solo 2<sup>32</sup> prima di cominciare a rivelare informazioni sulla chiave.






### Metodi di crittazione a blocchi di cifre

Generalmente la dimensione del blocco scelta è della medesima lunghezza della chiave perché risulta semplice per l'implementazione di un algoritmo. Tuttavia è bene fare attenzione ad alcuni metodi che possono compromettere la sicurezza dell'algoritmo. Nei seguenti algoritmi individuiamo: