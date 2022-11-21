const db = require('../database');

const cardType = {
    getById: function (id, callback) {
        return db.query('select * from card_type where id=?', [id], callback);
    },
	
	add: function (data, callback) {
        return db.query('insert into card_type (type) values(?)', [data.type], callback);
    },
	
    delete: function (id, callback) {
        return db.query('delete from card_type where id=?', [id], callback);
    },
	
    update: function (id, data, callback) {
        return db.query('update card_type set type=? where id=?', [data.type, id], callback);
    }
};

module.exports = cardType;