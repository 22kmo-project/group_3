var express = require('express');
var router = express.Router();
const card = require('../models/card_model');

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