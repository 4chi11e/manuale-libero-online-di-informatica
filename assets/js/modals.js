var modal_openers = document.querySelectorAll(".modal__opener");
var modal_closers = document.querySelectorAll(".modal__closer");
// console.log(modal_openers);
// console.log(modal_closers);

// Con i for normali
// for (let i = 0; i < modal_openers.length; i++) {
//     modal_openers[i].onclick = function() {
//         id = event.target.getAttribute("target")
//         var el = document.querySelector(id)
//         el.classList.toggle('modal--visibile')
//         console.log("Aperto "+id)
//     };
// }
// for (let i = 0; i < modal_closers.length; i++) {
//     modal_closers[i].onclick = function() {
//         id = event.target.getAttribute("target")
//         var el = document.querySelector(id)
//         el.classList.toggle('modal--visibile')
//         console.log("Chiuso "+id)
//     };
// }

// Alternativa col foreach
modal_openers.forEach((element) => {
  element.onclick = function () {
    id = event.target.getAttribute("aprire");
    var el = document.querySelector(id);
    el.classList.toggle("modal--visibile");
    // console.log("Aperto " + id);
  };
});
modal_closers.forEach((element) => {
  element.onclick = function () {
    id = event.target.getAttribute("chiudere");
    var el = document.querySelector(id);
    el.classList.toggle("modal--visibile");
    // console.log("Aperto " + id);
  };
});

// Aggiungo la possibilità di chiudere il modal cliccando sul modal fuori dal contenuto
window.onclick = function (event) {
  // console.log(event.target.classList[0] == "modal");
  if (event.target.classList[0] == "modal") {
    event.target.classList.toggle("modal--visibile");
  }
};
