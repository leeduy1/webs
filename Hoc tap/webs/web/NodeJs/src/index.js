const path = require('path');
const express = require('express');
const morgan = require('morgan');
const handlebars = require('express-handlebars');
const app = express();
const port =3000;

app.use(express.static(path.join(__dirname, 'public')))

//HTTP logger
app.use(morgan('combined'));

//templates engine
app.engine('hbs', handlebars.engine({
  extname: '.hbs'
}));
app.set ('view engine','hbs');
app.set('views', path.join(__dirname, 'resources\\views'))
//app.set('views', 'resources/Views');


console.log('Path',path.join(__dirname, 'resources/Views'))
app.get('/', (req, res) => {
  res.render('home');
})

app.get('/new', (req, res) => {
  res.render('news');
})

app.listen(port, () => console.log(`Server run at http://localhost:${port}`));