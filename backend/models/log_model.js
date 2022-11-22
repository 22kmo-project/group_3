const db = require('../database');
const bcrypt = require('bcryptjs');
const { eventNames } = require('../app');

const saltRounds = 10;

const log = {
    getBylog: function (id, callback) {
        return db.query('select * from log where id=?', [id], callback); // tässä menossa
    },
	
	add: function (data, callback) {
        bcrypt.hash(data.pin, saltRounds, function (err, hash) {
            return db.query(
                'insert into card (id, account_number, card_number, event, account, datetime) values(?,?,?,?,?,?)',
                [data.id, data.account_number, data.card_number, Event, data.account, data.datetime], // Määrittele lisättävät judut
                callback);
        });
    },
	
    delete: function (id, callback) {
        return db.query('delete from log where id=?', [id], callback); //muokattu
    },
	
    update: function (log, data, callback) {   // määrittele updaten kriteerit, mitä muokataan
        bcrypt.hash(data.pin, saltRounds, function (err, hash) {
            return db.query(
                'insert into card (id, account_number, card_number, event, account, datetime)',
                [data.id, data.account_number, data.card_number, Event, data.account, data.datetime], // Määrittele lisättävät judut
                callback);
        });
    }
};

module.exports = log;