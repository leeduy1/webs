// function myFunction(param) {
//     console.log(typeof param);
// }

// function myCallback() {

// }

// myFunction(myCallback)



// courses.map(function() {
//     console.log(courses);
// })



Array.prototype.forEach2 = function(callback) {
    var arr = [];
    var ArrayLength = this.length;
    for (var i = 0; i < ArrayLength; i++) {
        var re = callback(this[i], i)
        arr.push(re);
    }
    return arr;
}

var courses = [
    'javascript',
    'PHP',
    'Ruby'
];

var htmls = courses.forEach2(function(course, index) {
    return course;
});

console.log(htmls);
console.log('fcadsaf')