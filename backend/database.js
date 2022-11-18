const mysql = require('mysql');
const connection = mysql.createPool({
  host: '127.0.0.1',
  user: 'group_3',
  password: 'netpass',
  database: 'group_3'
});
module.exports = connection;