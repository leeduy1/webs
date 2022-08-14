// var myString = '  Hoc JS tai  JS F8  ';

// 2. Find index
// console.log(myString.indexOf('JS'));
// console.log(myString.lastIndexOf('JS'));
// console.log(myString.search('JS'));

// 3. Cut String
// console.log(myString.slice(4, 6));
// console.log(myString.slice(-3, -1));

// 4.replace
// console.log(myString.replace('JS', 'Javascrip'))
// console.log(myString.replace(/JS/g, 'Javascrip'))

// 5. convert to upper case
// console.log(myString.toUpperCase());
// 6. convert to lower case
// console.log(myString.toLowerCase());

// 7. Trim
// console.log(myString.trim());

// 8. Split cắt chuỗi dâu , là điểm chung để cắt
// var languages = 'Javascript, PHP, Ruby';

// console.log(languages.split(','));

// 9. get a character by index
// const myString2 = 'Son Dang';

// console.log(myString2.charAt(0));

// console.log(Math.random())

// function getRandomItem(array) {
//     console.log(array.length);
//     console.log(Math.random());
//     var random = Math.floor(Math.random() * array.length);
//     return array[random];
// }

// console.log(getRandomItem(['-100',
//     '10',
//     '7',
//     '8',
//     '9',
//     '22',
//     '50',
//     '71'
// ]));

var courses = [{
        id: 0,
        name: "html",
        coin: 200
    },
    {
        id: 1,
        name: "php",
        coin: 0
    },
    {
        id: 2,
        name: "Ruby",
        coin: 300
    },
    {
        id: 3,
        name: "html",
        coin: 400
    },
    {
        id: 5,
        name: "css",
        coin: 500
    },
    {
        id: 6,
        name: "Ruby",
        coin: 10,
    }

]

// courses.forEach(function(courses, index) {
//     console.log(index, courses)
// });

// var isFree = courses.every(function(courses, index) {
//     return courses.coin === 0;
// });

// console.log(isFree);


// var isFree1 = courses.some(function(courses, index) {
//     return courses.coin === 0;
// });

// console.log(isFree1);

// var course = courses.find(function(courses, index) {
//     return courses.name === 'Ruby';
// });

// console.log(course);

// var listcourse = courses.filter(function(courses, index) {
//     return courses.name === 'Ruby';
// });

// console.log(listcourse);


// function courseHandler(course, index, originArray) {
//     return {
//         id: course.id,
//         name: `Khoa hoc: ${course.name}`,
//         coin: course.coin,
//         index: index,
//         originArray: courses,

//     };
// }

// var newCourese = courses.map(courseHandler);
// console.log(newCourese)

var totalCoin = 0;
for (var course of courses) {
    totalCoin += course.coin;
}

console.log(totalCoin);


var i = 0;

function coinHandler(accunulator, currentValue, currentIndex, originArray) {
    i++;
    console.table({
        'Lượt chạy:': i,
        'Biến tích trữ:': accunulator,
    })
    console.log(currentValue)
    var total = accunulator + currentValue.coin;
    return total;
}
var totalCoin1 = courses.reduce(coinHandler, 0);

var totalCoin2 = courses.reduce(function(total, courese) {
    return total + courese.coin;
}, 0); // giá trị khởi tạo(ko bắt buộc)

console.log(totalCoin2)


var numbers = [100, 200, 220, 200, 480];

var totalCoin3 = numbers.reduce(function(toltal, number) {
    return toltal + numbers;
}, 0);

console.log(totalCoin3);


//Flat - "Làm phẳng" mảng từ Depth array - "Mảng sâu"
var depthArray = [1, 2, [3, 4], 5, 6, [7, 8, 9]];

var flatArray = depthArray.reduce(function(flatOutput, depthItem) {
    return flatOutput.concat(depthItem);
}, []);

console.log(flatArray);

// Lấy ra các khóa học đưa vào 1 mảng mới

var topics = [{
        topic: "Front-end",
        courses: [{
                id: 1,
                title: "HTML, CSS"
            },
            {
                id: 2,
                title: "Javascript"
            }
        ]
    },
    {
        topic: "Back-end",
        courses: [{
                id: 1,
                title: "PHP"
            },
            {
                id: 2,
                title: "NodeJS"
            }
        ]
    },
];

var newCourese = topics.reduce(function(coureses, topic) {
    return coureses.concat(topic.courses);
}, []);

console.log(newCourese)


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