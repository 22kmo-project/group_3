const db = require('../database');

const customer = {
  getById: function(id, callback) {
    return db.query('select * from customer where id=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from customer', callback);
  },
  add: function(customer, callback) {
    return db.query(
      'insert into customer (id,firstname,lastname,street,postcode,city,phone) values(?,?,?,?,?,?,?)',
      [, customer.firstname, customer.lastname, customer.street, customer.postcode,
         customer.city, customer.phone],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from customer where id=?', [id], callback);
  },
  update: function(id, customer, callback) {
    return db.query(
      'update customer set firstname=?,lastname=?, street=?, postcode=?, city=?, phone=? where id=?',
      [customer.firstname, customer.lastname, customer.street, customer.postcode,
        customer.city, customer.phone ,id],
      callback
    );
  }
};
module.exports = customer;