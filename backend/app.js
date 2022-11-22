var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

const helmet = require('helmet');
const cors = require('cors')

var indexRouter = require('./routes/index');
var cardRouter = require('./routes/card');
var cardTypeRouter = require('./routes/card_type');
var logRouter = require('./routes/log')
var customerRouter = require('./routes/customer');

var app = express();

app.use(helmet());
app.use(cors());

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);

app.use('/card', cardRouter);
app.use('/card-type', cardTypeRouter);
app.use('/log', logRouter);
app.use('/customer', customerRouter);

module.exports = app;
