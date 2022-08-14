const cars = ['BMW', 'porsche','Mercedes']

const output = `
    <ul>
    ${cars.map(car =>'<li>${car}</li>')}
    </ul> 
    ` 
console.log(output);