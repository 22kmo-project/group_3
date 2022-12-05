const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const card = require('../models/card_model');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');

router.post('/',
    function(request, response) {
        if (request.body.card_number && request.body.pin) {
            const card_number = request.body.card_number;
            const pin = request.body.pin;
            card.checkPin(card_number, request.body,function(dbError, dbResult) {
                if (dbError) {
                    response.json(dbError.errno);
                } else {
                    if (dbResult.length > 0) {
                        bcrypt.compare(pin, dbResult[0].pin, function(err, compareResult) {
                            if (compareResult) {
								console.log("success");
                                const token = generateAccessToken({ username: card_number });
                                response.send(token);
                            } else {
                                console.log("wrong password");
                                response.send(false);
                            }
                        });
                    } else {
                        console.log("card does not exists");
                        response.send(false);
                    }
                }
            });
        } else {
            console.log("card_number or pin missing");
            response.send(false);
        }
        
    });

    
function generateAccessToken(username) {
    dotenv.config();
    return jwt.sign(username, process.env.MY_TOKEN, { expiresIn: '1800s' });

}

module.exports = router;