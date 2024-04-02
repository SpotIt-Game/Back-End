const express = require('express');
const axios = require('axios');


const app = express();
app.use(express.json());
const PORT = process.env.PORT || 9000;



// const data = {  

//     move: 1,
//     game_mode: 1,
//     players : [0, 1, 2, 3, 4, 5]

// };



const data = {  

    move: 2,
    player: 1,
    urls : [
        "hola",
        "adios",        
        "hola",    
    ]

};


  
// app.get('/move3', (req, res) => {

//     res.json(data); // Envía los datos como JSON al cliente
// });



app.get('/move2', (req, res) => {

    res.json(data); // Envía los datos como JSON al cliente
});


// app.get('/move1',(req, res) => {

//     res.json(data); // Envía los datos como JSON al cliente
// });



app.post('/move2', (req, res) => {     //Recordar que esto de ejecutará si sucede en http://localhost:9000/move2/
    const { booleano } = req.body;

    console.log("Valor booleano recibido:", booleano);

    if (booleano === true) {
        console.log("true!");
        res.send('<h1>¡Verdadero!</h1>');
    } else {
        console.log('False!');
        res.send('<h1>Falso</h1>');
    }
});


app.post('/move3', (req, res) => {

    const { Winners } = req.body; 
    
    if (Winners && Array.isArray(Winners)) {
        console.log("Winners:");
        Winners.forEach((id) => {
            console.log(id);
        });
        res.status(200).send("Winners printed successfully.");
    }

});



app.listen(PORT, () => {
    console.log('Escuchando el puerto: ' + PORT);
});