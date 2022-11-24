const db = require('../database');

const account = {
    getByAccountNumber: function (account_number, callback) {
        return db.query('select * from account where account_number=?', [account_number], callback);
    },

	add: function (account, callback) {
        return db.query('insert into account (account_number, balance, credit_limit) values(?,?,?)', 
        [account.account_number, account.balance, account.credit_limit], callback);
    },
	
    delete: function (accountNumber, callback) {
        return db.query('delete from account where account_number=?', [accountNumber], callback);
    },
	
    update: function (accountNumber, data, callback) {
        return db.query('update account set account_number=?, balance=?, credit_limit=? where account_number=?', [data.account_number, data.balance, data.credit_limit, accountNumber], callback);
    }
};

module.exports = account;