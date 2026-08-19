---
title: Rappresentazione dell'Informazione
description: Come il computer trasforma testi, immagini, suoni e video in sequenze di 0 e 1.
---

Nei capitoli precedenti abbiamo visto che i computer funzionano solo con **$0$ e $1$** (il sistema binario).

Ma pensaci un attimo: ogni giorno con il tuo smartphone o con il computer ascolti canzoni su Spotify, guardi video su TikTok o YouTube, mandi messaggi su WhatsApp e giochi online. **Come fa una macchina che conosce solo due cifre ($0$ e $1$) a memorizzare e gestire tutto questo?**

La risposta sta in una sola parola: **CODIFICA**.

```text
 ┌─────────────────────────┐
 │  Messaggi di testo      │
 │  Foto e immagini        │ ──[ Regola di Codifica ]──►  01001001 01101110 01100110...
 │  Canzoni e audio        │                              (solo bit 0 e 1 in memoria)
 │  Video e animazioni     │
 └─────────────────────────┘
```

Una **codifica** è semplicemente una regola concordata: associamo a ogni lettera, a ogni colore e a ogni suono un numero, e poi scriviamo quel numero in binario.

---

## Cosa imparerai in questo capitolo

1. **Codificare testi e inventare nuove codifiche:**  
   Come il codice **ASCII** e **Unicode** trasformano le lettere della tastiera (e le emoji!) in byte, e come calcolare esattamente quanti bit servono per rappresentare qualsiasi insieme di cose (dai giorni della settimana alle carte da gioco).

2. **Digitalizzare il mondo reale (Immagini, Audio e Video):**  
   Come si trasforma un'onda sonora continua o la luce di una fotocamera in numeri digitali tramite i convertitori **ADC** e **DAC**, cosa sono i **pixel**, come si campiona l'audio e come calcolare le **dimensioni reali dei file**.

3. **La compressione e le unità di misura:**  
   Perché un film non compresso peserebbe terabyte, come funzionano i formati compressi di tutti i giorni (MP3, JPEG, MP4) e come destreggiarsi tra **MB** e **MiB** senza farsi ingannare.

---

## Da dove iniziare?

Segui il percorso nell'ordine consigliato:

- 🔤 **[Codifiche e caratteri](/manuale-libero-online-di-informatica/rappresentazione-informazione/codifiche/):** parti dalle basi con l'alfabeto ASCII e la codifica del mazzo di carte.
- 🎨 **[Codifiche multimediali](/manuale-libero-online-di-informatica/rappresentazione-informazione/multimedia/):** scopri come digitalizzare musica, foto e video.
- ✏️ **[Esercizi](/manuale-libero-online-di-informatica/rappresentazione-informazione/esercizi/):** mettiti alla prova con tanti esercizi guidati con soluzioni a comparsa.
