var express = require('express');
var router = express.Router();
const card = require('../models/card_model');
const bcrypt = require('bcryptjs');
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
  card.checkPin(request.params.cardNumber, function(dbError, dbResult) {
    if (dbError) {
      console.log("cpl")
        response.json(dbError.errno);
    } else {
        if (dbResult.length > 0) {
          console.log("parametripin",request.body.pin)
          console.log("tietokantapin",dbResult[0].pin)
            bcrypt.compare(request.body.pin, dbResult[0].pin, function(err, compareResult) {
                if (!compareResult) {
                    console.log("ei täsmää");
                    response.send(false);
                } else {
                  card.update(request.params.cardNumber, request.body, function(err, dbResult) {
                    if (err) {
                      response.json(err);
                    } else {
                      response.json(dbResult);
                    }
                  });
                }
            });
        } else {
            console.log("card does not exists");
            response.send(false);
        }
    }
});

});

module.exports = router;