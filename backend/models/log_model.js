const db = require('../database');
const log = {
  getById: function(id, callback) {
    return db.query('select * from log where id=?', [id], callback);
  },
 
  add: function(log, callback) {
    return db.query(
        'insert into log(account_number, card_number, event, amount, datetime) values(?,?,?,?,?)',
        [log.account_number, log.card_number, log.event, log.amount, log.datetime], // Määrittele lisättävät judut
        callback
        );
  },
  delete: function(id, callback) {
    return db.query('delete from log where id=?', [id], callback);
  },
  update: function(log, callback) {
    return db.query(
        'insert into log(account_number, card_number, event, amount, datetime) values(?,?,?,?,?)',
        [log.account_number, log.card_number, log.event, log.amount, log.datetime], // Määrittele lisättävät judut
        callback
        );
  }
};
module.exports = log;