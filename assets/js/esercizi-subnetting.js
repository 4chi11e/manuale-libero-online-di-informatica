var soluzioni_togglers = document.querySelectorAll(".soluzione-toggler");
console.log(soluzioni_togglers);

// Alternativa col foreach
soluzioni_togglers.forEach((element) => {
  element.onclick = function () {
    id = event.target.getAttribute("totoggle");
    var el = document.querySelector(id);
    el.classList.toggle("soluzione__visibile");
    if(el.classList.contains("soluzione-semplice")){
      if(element.innerHTML == "Visualizza la soluzione"){
        element.innerHTML = "Nascondi la soluzione"
      }
      else {
        element.innerHTML = "Visualizza la soluzione"
      }
    }
    if(el.classList.contains("soluzione-completa")){
      if(element.innerHTML == "Visualizza la soluzione completa di procedimenti"){
        element.innerHTML = "Nascondi la soluzione completa di procedimenti"
      }
      else {
        element.innerHTML = "Visualizza la soluzione completa di procedimenti"
      }
    }
    console.log("Toggled " + id);
  };
});
// modal_closers.forEach((element) => {
//   element.onclick = function () {
//     id = event.target.getAttribute("chiudere");
//     var el = document.querySelector(id);
//     el.classList.toggle("modal--visibile");
//     // console.log("Aperto " + id);
//   };
// });

