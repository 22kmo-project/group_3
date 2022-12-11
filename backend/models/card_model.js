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
    },
	
    checkPin: function (card_number, is_active, callback) {
		return db.query('select pin from card where card_number=? and is_active=?', [card_number, 1], callback);
	},
	
    getType: function (card_number, callback) {
        return db.query('select ct.type from card_type ct join card c on ct.id = c.card_type_id where c.card_number=?', [card_number], callback);
    },
	
    getCardAccountNumber: function (card_number, is_debit, callback) {
        if (is_debit == 1) {
		    return db.query(
                `select a.account_number from card c
                join card_account ca on c.card_number = ca.card_number
                join account a on ca.account_number = a.account_number
                where c.card_number = ? and a.credit_limit = 0`,
				[card_number],
				callback);
        } else {
		    return db.query(
	            `select a.account_number from card c
                join card_account ca on c.card_number = ca.card_number
                join account a on ca.account_number = a.account_number
                where c.card_number = ? and a.credit_limit > 0`,
				[card_number],
				callback);
		}
	    
    }
};

module.exports = card;