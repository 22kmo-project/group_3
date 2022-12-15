var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const jwt = require('jsonwebtoken');
const helmet = require('helmet');
const cors = require('cors')

function authenticateToken(req, res, next) {
    const authHeader = req.headers['authorization']
    const token = authHeader && authHeader.split(' ')[1]
  
    console.log("token = "+token);
    if (token == null) return res.sendStatus(401)
  
    jwt.verify(token, process.env.MY_TOKEN, (err, user) => {
      console.log(err)
  
      if (err) return res.sendStatus(403)
  
      req.user = user
  
      next()
    })
  }

var indexRouter = require('./routes/index');
var cardRouter = require('./routes/card');
var accountRouter = require('./routes/account');
var cardTypeRouter = require('./routes/card_type');
var logRouter = require('./routes/log')
var customerRouter = require('./routes/customer');
var loginRouter = require('./routes/login');
var cardAccountRouter = require('./routes/card_account');
var cardLogRouter = require('./routes/card_log');
var customerAccountRouter = require('./routes/customer_account');


var app = express();

app.use(helmet());
app.use(cors());

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

//SUOJAAMATTOMAT ENDPOINTIT
app.use('/login', loginRouter);

app.use(authenticateToken);
//SUOJATUT ENDPOINTIT
app.use('/', indexRouter);
app.use('/card', cardRouter);
app.use('/account', accountRouter);
app.use('/card-type', cardTypeRouter);
app.use('/log', logRouter);
app.use('/customer', customerRouter);
app.use('/card-account', cardAccountRouter);
app.use('/card-log', cardLogRouter);
app.use('/customer-account', customerAccountRouter);


module.exports = app;
