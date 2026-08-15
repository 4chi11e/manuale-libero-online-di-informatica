import fs from 'node:fs/promises';
import path from 'node:path';
import JSZip from 'jszip';

const CACHE_FILE = path.join(process.cwd(), '.stats-cache.json');

const todayFormatted = new Intl.DateTimeFormat('it-IT', {
    day: 'numeric',
    month: 'long',
    year: 'numeric'
}).format(new Date());

const DEFAULT_STATS = {
    site: { words: 52413, chars: 322845, lines: 11230, images: 45, pages: 196, updatedAt: todayFormatted },
    c: { words: 70762, chars: 340779, images: 12, pages: 303, updatedAt: todayFormatted },
    python: { words: 60074, chars: 303396, images: 22, pages: 180, updatedAt: todayFormatted },
    lastUpdated: todayFormatted
};

async function getCachedStats() {
    try {
        const raw = await fs.readFile(CACHE_FILE, 'utf-8');
        return JSON.parse(raw);
    } catch {
        return DEFAULT_STATS;
    }
}

async function saveCachedStats(stats) {
    try {
        await fs.writeFile(CACHE_FILE, JSON.stringify(stats, null, 2), 'utf-8');
    } catch (err) {
        console.warn('Impossibile salvare stats-cache.json:', err);
    }
}

async function countSiteMarkdown(dir) {
    let words = 0;
    let chars = 0;
    let lines = 0;
    let images = 0;

    async function scan(currentDir) {
        const entries = await fs.readdir(currentDir, { withFileTypes: true });
        for (const entry of entries) {
            const fullPath = path.join(currentDir, entry.name);
            if (entry.isDirectory()) {
                const lower = entry.name.toLowerCase();
                if (lower === 'c' || lower === 'python') continue;
                await scan(fullPath);
            } else if (entry.name.endsWith('.md') || entry.name.endsWith('.mdx')) {
                const content = await fs.readFile(fullPath, 'utf-8');
                chars += content.length;
                lines += content.split('\n').length;

                const tokenWords = content.trim().split(/\s+/);
                if (tokenWords.length > 0 && tokenWords[0] !== '') {
                    words += tokenWords.length;
                }

                const imagesMd = content.match(/!\[.*?\]\(.*?\)/g);
                if (imagesMd) images += imagesMd.length;
                const imagesHtml = content.match(/<img[^>]+>/g);
                if (imagesHtml) images += imagesHtml.length;
            }
        }
    }

    await scan(dir);

    // Calcolo pagine A4 effettive calcolato sulla resa di stampa reale del browser con blocchi espansi
    const pages = Math.round(words / 267.4);

    return { words, chars, lines, images, pages, updatedAt: todayFormatted };
}

async function fetchDocxStats(fileId, fallback) {
    try {
        const url = `https://drive.google.com/uc?export=download&id=${fileId}`;
        const controller = new AbortController();
        const timeout = setTimeout(() => controller.abort(), 12000);

        const response = await fetch(url, {
            headers: { 'User-Agent': 'Mozilla/5.0' },
            signal: controller.signal
        });
        clearTimeout(timeout);

        if (!response.ok) throw new Error(`HTTP ${response.status}`);
        const arrayBuffer = await response.arrayBuffer();
        const zip = await JSZip.loadAsync(arrayBuffer);

        // Count images inside word/media/
        const imageFiles = Object.keys(zip.files).filter(k => k.startsWith('word/media/'));
        const images = imageFiles.length;

        // Read word/document.xml
        const docXmlFile = zip.file('word/document.xml');
        if (!docXmlFile) throw new Error('word/document.xml non trovato');
        const docXml = await docXmlFile.async('string');

        const cleanText = docXml.replace(/<[^>]+>/g, ' ');
        const wordsMatch = cleanText.match(/[\p{L}\p{N}]+/gu);
        const words = wordsMatch ? wordsMatch.length : 0;
        const chars = cleanText.replace(/\s+/g, '').length;

        // Read pages from docProps/app.xml if available
        let pages = fallback.pages || Math.round(words / 250);
        const appXmlFile = zip.file('docProps/app.xml');
        if (appXmlFile) {
            const appXml = await appXmlFile.async('string');
            const pageMatch = appXml.match(/<Pages>(\d+)<\/Pages>/);
            if (pageMatch && parseInt(pageMatch[1], 10) > 1) {
                pages = parseInt(pageMatch[1], 10);
            }
        }

        return { words, chars, images, pages, updatedAt: todayFormatted };
    } catch (err) {
        console.warn(`[Stats] Impossibile scaricare DOCX (${fileId}), uso fallback in cache. Motivo:`, err.message);
        return { ...fallback, updatedAt: fallback.updatedAt || todayFormatted };
    }
}

let cachedResults = null;

export async function getAllStats() {
    if (cachedResults) return cachedResults;

    const cache = await getCachedStats();
    let site = cache.site;

    try {
        const docsDir = path.join(process.cwd(), 'src', 'content', 'docs');
        site = await countSiteMarkdown(docsDir);
    } catch (e) {
        console.warn('Errore scansione markdown:', e);
    }

    const cStats = await fetchDocxStats('16uNuwwTZimF5VL0Mq-jymDLsTfTziG_q', cache.c);
    const pythonStats = await fetchDocxStats('1nhYKZMu_DmVJPh4SHuVg-AZPkNtWAQki', cache.python);

    const result = {
        site,
        c: cStats,
        python: pythonStats,
        lastUpdated: todayFormatted
    };

    await saveCachedStats(result);
    cachedResults = result;
    return result;
}
