var soluzioni_togglers = document.querySelectorAll(".soluzione-toggler");
console.log(soluzioni_togglers);

// Alternativa col foreach
soluzioni_togglers.forEach((element) => {
  element.onclick = function () {
    id = event.target.getAttribute("totoggle");
    var el = document.querySelector(id);
    if(el.classList.contains("soluzione-semplice")){
      el.classList.toggle("soluzione-semplice__visibile");
    }
    if(el.classList.contains("soluzione-completa")){
      el.classList.toggle("soluzione-completa__visibile");
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

