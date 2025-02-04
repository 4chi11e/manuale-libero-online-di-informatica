# voglio far vedere quanto è più veloce usare un linguaggio di alto livello per fare queste cose

# Leggi l'elenco di nomi dal file di input e inseriscili in un array
# dinamico. Inserisci poi i nomi in una lista di liste di nomi in cui in ogni
# riga ci sono nomi che iniziano con la stessa lettera. Ordina poi ogni riga in
# ordine alfabetico.

with open("2-02-lista-nomi-to-matrice-ordinata.txt", encoding='utf-8') as f:
    nomi = [riga.strip() for riga in f]

mat = {}
for nome in nomi:
    if nome[0] in mat:
        mat[nome[0]].append(nome)
    else:
        mat[nome[0]] = [nome]

mat = [val for key,val in mat.items()]
mat.sort()
for nomi in mat:
    print(nomi)
