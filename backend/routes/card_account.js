var express = require('express');
var router = express.Router();
const card = require('../models/card_model');
const cardAccount = require('../models/card_account_model');

router.get('/card/:cardNumber',
 function(request, response) {
  if (request.params.cardNumber) {
    cardAccount.getByCardNumber(request.params.cardNumber, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult[0]);
      }
    });
  }
});

router.get('/account/:accountNumber',
 function(request, response) {
  if (request.params.accountNumber) {
    cardAccount.getByAccountNumber(request.params.accountNumber, function(err, dbResult) {
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
  cardType.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});


router.delete('/card/:id', 
function(request, response) {
  cardType.deleteByCardNumber(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.delete('/account/:id', 
function(request, response) {
  cardType.deleteByAccountNumber(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/card/:id', 
function(request, response) {
  cardType.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.put('/account/:id', 
function(request, response) {
  cardType.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.get('/:card_number/:is_debit', function(request, response){
    const card_number = request.params.card_number;
	const is_debit = request.params.is_debit;
    card.getCardAccountNumber(card_number, is_debit, function(err, dbResult){
        if(err) {
            response.json(err);
        } else {
            response.json(dbResult[0]);
        }
    })
});

module.exports = router;