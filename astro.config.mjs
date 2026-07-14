import { defineConfig } from 'astro/config';
import starlight from '@astrojs/starlight';

export default defineConfig({
  site: 'https://4chi11e.github.io',
  base: '/manuale-libero-online-di-informatica',
  integrations: [
    starlight({
      title: 'Manuale Libero di Informatica',
      description: 'Manuale Libero Online di Informatica per il Liceo Scientifico delle Scienze Applicate',
      social: {
        github: 'https://github.com/4chi11e/manuale-libero-online-di-informatica',
      },
      sidebar: [
        {
          label: 'Introduzione',
          items: [
            { label: 'Reti per la classe prima', link: '/reti-prima/' },
            { label: 'Architettura dei calcolatori', link: '/architettura/' },
            { label: 'Sistemi Operativi', link: '/sistemi-operativi/' },
            { label: 'Complessità computazionale', link: '/complessita/' },
          ]
        },
        {
          label: 'Programmazione in C',
          autogenerate: { directory: 'C' }
        },
        {
          label: 'Reti di Calcolatori',
          autogenerate: { directory: 'reti' }
        },
        {
          label: 'Informazioni',
          items: [
            { label: 'Copyright e Licenza', link: '/copyright/' }
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
