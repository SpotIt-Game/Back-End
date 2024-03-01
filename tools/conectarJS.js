//Para que funcione se debe instalar node_modules para poder incluir 'mysql'
const mysql=require('mysql'); //inclusión de 'mysql'

const connection = mysql.createConnection({
    host:'127.0.0.1',
    user:'joshua',
    database: 'P1',
    password: 'Besamestazona11!',
    port: 3306 //no es necesario al parecer
});

connection.connect(function(err){  //si no se pudo conectar, dará error
    if(err){
        console.error(err.stack)
        return;
    } 
})

const query = 'select* from Mazo';       //hacer consulta

connection.query(query,(error,results,fields) => {
    if(error){
        console.error(error);
        return;
    } console.log(results);
});

connection.end();
