function bordiColonna(id,n){
   $("#"+id+" tr:first-child td:nth-child("+n+")").css("border-top","2px solid black");
   $("#"+id+" td:nth-child("+n+")").css({"border-left": "2px solid black", "border-right": "2px solid black"/*, "background-color": "gray"*/});
   $("#"+id+" tr:last-child td:nth-child("+n+")").css("border-bottom","2px solid black");
}

function evidenziaRiga(id,n){
   $("#"+id+" tr:nth-child("+n+") td").css({"background-color": "#eee"});
}

function evidenziaBordoOrizzontale(id,n,px){
   if(n==0){
      $("#"+id+" tr:first-child td").css("border-top", px+"px solid black");
   }
   else{
      $("#"+id+" tr:nth-child("+n+") td").css("border-bottom", px+"px solid black");
   }
}

function evidenziaBordoVerticale(id,n,px){
   if(n==0){
      $("#"+id+" td:first-child").css("border-left", px+"px solid black");
   }
   else{
      $("#"+id+" td:nth-child("+n+")").css("border-right", px+"px solid black");
   }
}
