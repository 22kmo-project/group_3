var express = require('express');
var router = express.Router();
const card = require('../models/card_model');

router.get('/:cardNumber',
 function(request, response) {
  if (request.params.cardNumber) {
    card.getByCardNumber(request.params.cardNumber, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult[0]);
      }
    });
  }
});

router.get('/type/:cardNumber',
 function(request, response) {
  if (request.params.cardNumber) {
    card.getType(request.params.cardNumber, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult[0]);
      }
    });
  }
});

router.post('/', 
function(request, response) {
  console.log(request.body);
  card.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});


router.delete('/:cardNumber', 
function(request, response) {
  card.delete(request.params.cardNumber, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:cardNumber', 
function(request, response) {
  card.update(request.params.cardNumber, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;