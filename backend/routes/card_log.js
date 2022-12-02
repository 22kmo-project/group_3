var express = require('express');
var router = express.Router();
const card = require('../models/card_model.js');

router.get('/:card_number/:account_number', function(request, response){
    const card_number = request.params.card_number;
	const account_number = request.params.account_number;
    card.getWithdrawEvents(card_number, account_number, function(err, dbResult){
        if(err) {
            response.json(err);
        } else {
            response.json(dbResult);
        }
    })
});

module.exports = router;