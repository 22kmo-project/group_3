const db = require('../database');

const cardAccount = {
    getById: function (id, callback) {
        return db.query('select * from customer_account where customer_id=?', [id], callback);
    },

	add: function (data, callback) {
        return db.query('insert into customer_account (customer_id, account_number, owner) values(?, ?, ?)', [data.customer_id, data.account_number, data.owner], callback);
    },
	
    delete: function (id, callback) {
        return db.query('delete from customer_account where customer_id=?', [id], callback);
    },
	
    update(id, data, callback) {
        return db.query('update customer_account set customer_id=?, account_number=?, owner=? where customer_id=? and account_number=?', [data.customer_id, data.account_number, data.owner, id, data.account_number], callback);
    }
};

module.exports = cardAccount;