// For this to work, you must install node_modules to be able to include 'mysql'
const mysql = require('mysql'); // including 'mysql'




const connection = mysql.createConnection({
    host: 'sql5.freesqldatabase.com',
    user: 'sql5688705',
    password: 'uACuvPiU8u',
    database: 'sql5688705',
    port: 3306
});

connection.connect(function(err) {  // if it could not connect, it will give an error
    if (err) {
        console.error(err.stack)
        return;
    } 
})

// const query = '';

// connection.query(query, (error, results, fields) => {
//     if (error) {
//         console.error(error);
//         return;
//     } console.log(results);
// });

connection.end();
