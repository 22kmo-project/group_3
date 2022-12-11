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
  },
  
    getWithdrawEvents: function (card_number, account_number, callback) {
        return db.query(
        'select event, amount, datetime from log where card_number=? AND account_number=? AND amount IS NOT ? ORDER BY datetime DESC',
        [card_number, account_number, null],
        callback);
    },
};
module.exports = log;