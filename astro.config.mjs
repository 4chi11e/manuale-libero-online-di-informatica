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
      social: {
        github: 'https://github.com/4chi11e/manuale-libero-online-di-informatica',
      },
      sidebar: [
        {
          label: 'Concetti di Base e Fondamenti',
          items: [
            { label: 'Reti per la classe prima', link: '/reti-prima/' },
            { label: 'Architettura dei calcolatori', link: '/architettura/' },
            { label: 'Sistemi Operativi', link: '/sistemi-operativi/' },
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
            { label: '1. Introduzione e Dati', link: '/machine-learning/introduzione-dati/' },
            { label: '2. Regressione e Classificazione', link: '/machine-learning/regressione-classificazione/' },
            { label: '3. Il Percettore e Reti Neurali', link: '/machine-learning/percettore-reti-neurali/' },
            { label: '4. Addestramento e Valutazione', link: '/machine-learning/addestramento-valutazione/' }
          ]
        }
      ],
      components: {
        Head: './src/components/Head.astro',
      },
      customCss: [
        './src/styles/custom.css',
      ],
    }),
  ],
});
