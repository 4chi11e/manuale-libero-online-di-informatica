<div align="center">
  <h1>Manuale Libero Online di Informatica</h1>
  <p><strong>per il Liceo Scientifico delle Scienze Applicate</strong></p>
  <p>A cura di <strong>Francesco Tormene</strong></p>
</div>

---

L'idea di creare questo sito nasce dalla necessità di porre rimedio all'inadeguatezza dei libri di testo esistenti per l'insegnamento dell'informatica nel liceo scientifico delle scienze applicate. I contenuti teorici di questi testi erano spesso imprecisi o incompleti, mentre gli esercizi erano numericamente insufficienti, erano spesso o troppo facili o troppo difficili, davano consegne ambigue e non coprivano tutti gli argomenti trattati.

Per questi motivi, ad inizio 2020, durante il mio secondo anno di insegnamento al Liceo Banfi di Vimercate, mi decido finalmente ad iniziare la creazione di questa dispensa che spero possa essere utile a tutti i miei studenti attuali e futuri, e chissà magari anche a qualche collega e ai suoi studenti.

Il materiale che troverete è di varia provenienza e non è soltanto farina del mio sacco: una parte non trascurabile è stata raccolta e riadattata da Wikipedia, altre parti sono state tratte e riadattate da pagine, documenti o eserciziari prodotti da diversi docenti o studenti universitari, alcuni contenuti sono stati infine raccolti da diversi libri di testo di informatica per le scuole superiori. Spero che nessuno si risentirà per aver utilizzato parte del materiale da loro scritto, anche considerando che questa dispensa è completamente gratuita e libera, infatti il codice è liberamente disponibile [qui](https://github.com/4chi11e/manuale-libero-online-di-informatica) su un repository pubblico su GitHub sotto licenza GNU GPL.

---

## 🛠️ Sviluppo Locale

Il manuale è realizzato con **Astro** e il tema **Starlight**. Per eseguirlo e modificarlo in locale, assicurati di avere installato [Node.js](https://nodejs.org/) (versione 18.17.1 o superiore).

### 1. Installare le dipendenze
Dalla cartella principale del progetto, esegui:
```bash
npm install
```

### 2. Avviare il server di sviluppo
Per avviare il server locale con live-reload:
```bash
npm run dev
```
Il sito sarà accessibile all'indirizzo [http://localhost:4321/manuale-libero-online-di-informatica](http://localhost:4321/manuale-libero-online-di-informatica).

### 3. Compilare il sito per la pubblicazione
Per generare i file HTML statici pronti per il deploy:
```bash
npm run build
```
L'output finale verrà generato all'interno della cartella `dist/`.

---

## 🚀 Deployment
Il sito viene compilato e pubblicato automaticamente su GitHub Pages ad ogni push sul branch principale tramite la pipeline di GitHub Actions configurata in `.github/workflows/deploy.yml`.
