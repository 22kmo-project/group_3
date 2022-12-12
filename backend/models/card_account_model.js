const db = require('../database');

const cardAccount = {
    getByCardNumber: function (cardNumber, callback) {
        return db.query('select * from card_account where card_number=?', [cardNumber], callback);
    },
	
	getByAccountNumber: function (accountNumber, callback) {
        return db.query('select * from card_account where account_number=?', [accountNumber], callback);
    },
	
	add: function (data, callback) {
        return db.query('insert into card_account (card_number, account_number) values(?, ?)', [data.card_number, data.account_number], callback);
    },
	
    deleteByCardNumber: function (cardNumber, callback) {
        return db.query('delete from card_account where card_number=?', [cardNumber], callback);
    },
	
	deleteByAccountNumber: function (accountNumber, callback) {
        return db.query('delete from card_account where account_number=?', [accountNumber], callback);
    },
	
    updateByCardNumber: function (cardNumber, data, callback) {
        return db.query('update card_account set card_number=?, account_number=? where card_number=?', [data.card_number, data.account_number, cardNumber], callback);
    },
	
	updateByAccountNumber: function (accountNumber, data, callback) {
        return db.query('update card_account set card_number=?, account_number=? where account_number=?', [data.card_number, data.account_number, accountNumber], callback);
    }
};

module.exports = cardAccount;