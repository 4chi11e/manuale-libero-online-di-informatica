import { defineConfig } from 'astro/config';
import starlight from '@astrojs/starlight';
import remarkMath from 'remark-math';
import rehypeKatex from 'rehype-katex';

export default defineConfig({
  site: 'https://4chi11e.github.io',
  base: '/manuale-libero-online-di-informatica',
  markdown: {
    remarkPlugins: [remarkMath],
    rehypePlugins: [rehypeKatex],
  },
  integrations: [
    starlight({
      title: 'Manuale Libero di Informatica',
      description: 'Manuale Libero Online di Informatica per il Liceo Scientifico delle Scienze Applicate',
      favicon: '/favicon.svg',
      defaultLocale: 'root',
      locales: {
        root: {
          label: 'Italiano',
          lang: 'it',
        },
      },
      social: {
        github: 'https://github.com/4chi11e/manuale-libero-online-di-informatica',
      },
      sidebar: [
        {
          label: 'Concetti di Base e Fondamenti',
          items: [
            {
              label: 'Conversioni numeriche',
              items: [
                { label: 'Spiegazione', link: '/conversioni-numeriche/' },
                { label: 'Esercizi sulle conversioni', link: '/conversioni-numeriche/esercizi/' },
              ]
            },
            {
              label: 'Rappresentazione dell\'Informazione',
              items: [
                { label: 'Rappresentazione dell\'Informazione', link: '/rappresentazione-informazione/rappresentazione-informazione/' },
                { label: 'Codifiche e caratteri', link: '/rappresentazione-informazione/codifiche/' },
                { label: 'Codifiche multimediali', link: '/rappresentazione-informazione/multimedia/' },
                { label: 'Esercizi', link: '/rappresentazione-informazione/esercizi/' },
              ]
            },
            { label: 'Architettura dei calcolatori', link: '/architettura/' },
            { label: 'Sistemi Operativi', link: '/sistemi-operativi/' },
            { label: 'Reti per la classe prima', link: '/reti-prima/' },
            { label: 'Copyright e licenze', link: '/copyright/' },
          ]
        },
        {
          label: 'Programmazione in C',
          link: '/c/programmazione-in-c/'
        },
        {
          label: 'Programmazione in Python',
          link: '/python/programmazione-in-python/'
        },
        {
          label: 'Complessità computazionale',
          link: '/complessita/'
        },
        {
          label: 'Reti di Calcolatori',
          items: [
            { label: 'Reti di calcolatori', link: '/reti/reti/' },
            {
              label: 'Modello ISO/OSI',
              items: [
                { label: 'ISO/OSI', link: '/reti/iso-osi/iso-osi/' },
                { label: 'Livello 1 - Fisico', link: '/reti/iso-osi/livello1/' },
                { label: 'Livello 2 - Collegamento', link: '/reti/iso-osi/livello2/' },
                {
                  label: 'Livello 3 - Rete',
                  items: [
                    { label: 'Spiegazione', link: '/reti/iso-osi/livello3/' },
                    { label: 'Esercizi Subnetting', link: '/reti/iso-osi/esercizi-subnetting/' }
                  ]
                },
                { label: 'Livello 4 - Trasporto', link: '/reti/iso-osi/livello4/' },
                { label: 'Livello 5 - Sessione', link: '/reti/iso-osi/livello5/' },
                { label: 'Livello 6 - Presentazione', link: '/reti/iso-osi/livello6/' },
                { label: 'Livello 7 - Applicazione', link: '/reti/iso-osi/livello7/' }
              ]
            },
            {
              label: 'Crittografia',
              items: [
                { label: 'Crittografia', link: '/reti/crittografia/crittografia/' },
                { label: 'Storia della Crittografia', link: '/reti/crittografia/crittografia-storia/' },
                { label: 'Crittografia Moderna', link: '/reti/crittografia/crittografia-moderna/' }
              ]
            }
          ]
        },
        {
          label: 'Machine Learning e Reti Neurali',
          items: [
            { label: 'Machine Learning e Reti Neurali', link: '/machine-learning/machine-learning/' },
            {
              label: 'Introduzione e Dati',
              items: [
                { label: 'Spiegazione', link: '/machine-learning/introduzione-dati/' },
                { label: 'Esercizi Teorici', link: '/machine-learning/esercizi-teorici-dati/' },
                { label: 'Laboratorio Python', link: '/machine-learning/laboratorio-dati/' }
              ]
            },
            {
              label: 'Regressione, Classificazione e Valutazione',
              items: [
                { label: 'Spiegazione', link: '/machine-learning/regressione-classificazione/' },
                { label: 'Esercizi Teorici', link: '/machine-learning/esercizi-teorici-regressione-classificazione/' },
                { label: 'Laboratorio Python', link: '/machine-learning/laboratorio-regressione-classificazione/' }
              ]
            },
            {
              label: 'Alberi di Decisione e Random Forest',
              items: [
                { label: 'Spiegazione', link: '/machine-learning/alberi-decisione/' },
                { label: 'Esercizi Teorici', link: '/machine-learning/esercizi-teorici-alberi-decisione/' },
                { label: 'Laboratorio Python', link: '/machine-learning/laboratorio-alberi-decisione/' }
              ]
            },
            {
              label: 'Il Percettore e Reti Neurali',
              items: [
                { label: 'Spiegazione', link: '/machine-learning/percettore-reti-neurali/' },
                { label: 'Esercizi Teorici', link: '/machine-learning/esercizi-teorici-percettore-reti-neurali/' },
                { label: 'Laboratorio Python', link: '/machine-learning/laboratorio-percettore-reti-neurali/' }
              ]
            }
          ]
        }
      ],
      components: {
        Head: './src/components/Head.astro',
        TableOfContents: './src/components/TableOfContents.astro',
        MobileTableOfContents: './src/components/MobileTableOfContents.astro',
      },
      customCss: [
        './src/styles/custom.css',
      ],
    }),
  ],
});
