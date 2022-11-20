const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds = 10;

const card = {
    getByCardNumber: function (card_number, callback) {
        return db.query('select * from card where card_number=?', [card_number], callback);
    },
	
	add: function (data, callback) {
        bcrypt.hash(data.pin, saltRounds, function (err, hash) {
            return db.query(
                'insert into card (card_number, card_type_id, customer_id, pin, is_active) values(?,?,?,?,?)',
                [data.card_number, data.card_type_id, data.customer_id, hash, data.is_active],
                callback);
        });
    },
	
    delete: function (cardNumber, callback) {
        return db.query('delete from card where card_number=?', [cardNumber], callback);
    },
	
    update: function (cardNumber, data, callback) {
        bcrypt.hash(data.pin, saltRounds, function (err, hash) {
            return db.query(
                'update card set pin=?, is_active=? where card_number=?',
                [hash, data.is_active, cardNumber],
                callback);
        });
    }
};

module.exports = card;