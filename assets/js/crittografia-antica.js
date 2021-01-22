function atbash(clair, chiffre, chiffrer){
   alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
   clair.value = clair.value.toUpperCase();
   chiffre.value = "";
   k=clair.value.length;
   n=0;
   for(var count = 0; count < k; count++){
      alpha = clair.value.charAt(count);
      idx = alphabet.indexOf(alpha);
      if (idx > -1)     // ne (dé)chiffre que les 26 lettres majuscules
      {
         //if ((n%5==0) && (n>0) && chiffrer) {chiffre.value+=" "};
         n++;
         chiffre.value += alphabet.charAt(25-idx);
      }
      if (idx <= -1)
      {
         chiffre.value+=alpha;
         n++;
      }
   }
}

function albam(clair, chiffre, chiffrer){
   alphabet1 = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
   alphabet2 = 'NOPQRSTUVWXYZABCDEFGHIJKLM';
   clair.value = clair.value.toUpperCase();
   chiffre.value = "";
   k=clair.value.length;
   n=0;
   for(var count = 0; count < k; count++){
      alpha = clair.value.charAt(count);
      idx = alphabet1.indexOf(alpha);
      if (idx > -1)     // ne (dé)chiffre que les 26 lettres majuscules
      {
         //if ((n%5==0) && (n>0) && chiffrer) {chiffre.value+=" "};
         n++;
         chiffre.value += alphabet2.charAt(idx);
      }
      if (idx <= -1)
      {
         chiffre.value+=alpha;
         n++;
      }
   }
}

function atbah(clair, chiffre, chiffrer){
   alphabet1 = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
   alphabet2 = 'IHGFNDCBARQPOEMLKJZYXWVUTS';
   clair.value = clair.value.toUpperCase();
   chiffre.value = "";
   k=clair.value.length;
   n=0;
   for(var count = 0; count < k; count++){
      alpha = clair.value.charAt(count);
      idx = alphabet1.indexOf(alpha);
      if (idx > -1)     // ne (dé)chiffre que les 26 lettres majuscules
      {
         //if ((n%5==0) && (n>0) && chiffrer) {chiffre.value+=" "};
         n++;
         chiffre.value += alphabet2.charAt(idx);
      }
      if (idx <= -1)
      {
         chiffre.value+=alpha;
         n++;
      }
   }
}

function chiffrer(clair, chiffre, chiffrer){
   if (document.controle.elements[1].checked){
      if (chiffrer) {atbash(clair, chiffre, chiffrer)} else {atbash(chiffre, clair, chiffrer)}}
   else if (document.controle.elements[2].checked){
      if (chiffrer) {albam(clair, chiffre, chiffrer)} else {albam(chiffre, clair, chiffrer)}}
   else if (document.controle.elements[3].checked){
      if (chiffrer) {atbah(clair, chiffre, chiffrer)} else {atbah(chiffre, clair, chiffrer)}}
}