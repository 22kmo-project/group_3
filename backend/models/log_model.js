const db = require('../database');
const log = {
  getById: function(id, callback) {
    return db.query('select * from log where id=?', [id], callback);
  },
 
  add: function(log, callback) {
    return db.query(
        'insert into log(id, account_number, card_number, event, account, datetime) values(?,?,?,?,?,?)',
        [log.id, log.account_number, log.card_number, Event, log.account, log.datetime], // Määrittele lisättävät judut
        callback
        );
  },
  delete: function(id, callback) {
    return db.query('delete from log where id=?', [id], callback);
  },
  update: function(log, callback) {
    return db.query(
        'insert into log(id, account_number, card_number, event, account, datetime) values(?,?,?,?,?,?)',
        [log.id, log.account_number, log.card_number, Event, log.account, log.datetime], // Määrittele lisättävät judut
        callback
        );
  }
};
module.exports = log;