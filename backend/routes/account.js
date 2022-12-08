var express = require('express');
var router = express.Router();
const account = require('../models/account_model');

router.get('/:accountNumber',
 function(request, response) {
  if (request.params.accountNumber) {
    account.getByAccountNumber(request.params.accountNumber, function(err, dbResult) {
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
  account.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});


router.delete('/:accountNumber', 
function(request, response) {
  account.delete(request.params.accountNumber, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:accountNumber', 
function(request, response) {
  account.update(request.params.accountNumber, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.get('/balance/:accountNumber/:useCredit',
 function(request, response) {
  const accountNumber = request.params.accountNumber;
  const useCredit = request.params.useCredit;
  if (accountNumber && useCredit) {
    account.getBalance(accountNumber, useCredit, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult[0]);
      }
    });
  }
});

router.put('/withdraw/:accountNumber', 
function(request, response) {
	const accountNumber = request.params.accountNumber;
	const useCredit = request.body.useCredit;
    account.withdraw(accountNumber, useCredit, request.body, function(err, dbResult) {
        if (err) {
            response.json(err);
        } else {
            response.json(dbResult);
        }
    });
});

module.exports = router;