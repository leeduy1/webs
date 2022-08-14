var arr_img = [
    "../img/slider_0.webp",
    "../img/slider_1.webp",
]

var index = 0;

function next() {
    index++;
    if (index >= arr_img.length) index = 0;
    var img = document.querySelector('.container-img img')
    img.src = arr_img[index]
}

function prev() {
    index--;
    if (index < 0) index = arr_img.length - 1;
    var img = document.querySelector('.container-img img')
    img.src = arr_img[index]
}

setInterval("next()", 3000)

var menuOpen = document.querySelector('.header-menu')
var menu = document.querySelector('.mobiel-menu')
var overLay = document.querySelector('.overlay')
var menuClose = document.querySelector('.mobile__top--icon')

menuOpen.onclick = function() {
    menu.style.display = 'block'
    overLay.style.display = 'block'
    menu.style.animation = 'mobileMenuSideIn 0.3s linear'
    overLay.style.animation = 'mobileMenuSideIn 0.3s linear'
}

overLay.onclick = function() {
    menu.style.display = 'none'
    overLay.style.display = 'none'
}

menuClose.onclick = function() {
    menu.style.display = 'none'
    overLay.style.display = 'none'
}