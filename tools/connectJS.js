// For this to work, you must install node_modules to be able to include 'mysql'
const mysql = require('mysql'); // including 'mysql'

const connection = mysql.createConnection({
    host: '127.0.0.1',
    user: 'joshua',
    database: 'P1',
    password: 'Besamestazona11!',
    port: 3306 
});

connection.connect(function(err) {  // if it could not connect, it will give an error
    if (err) {
        console.error(err.stack)
        return;
    } 
})

const query = 'SELECT * FROM Mazo';       // make query

connection.query(query, (error, results, fields) => {
    if (error) {
        console.error(error);
        return;
    } console.log(results);
});

connection.end();
