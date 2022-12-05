const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const card = require('../models/card_model');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');

router.post('/',
    function(request, response) {
        if (request.body.card_number && request.body.pin && request.body.is_active) {
            const card_number = request.body.card_number;
            const pin = request.body.pin;
            const is_active = request.body.is_active;
            card.checkPin(card_number, is_active, function(dbError, dbResult) {
                if (dbError) {
                    response.json(dbError.errno);
                } else {
                    if (dbResult.length > 0) {
                        console.log("is_active",request.body.is_active)
                        console.log("is_active",dbResult[0].is_active)
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