const express = require('express');


const app = express();
app.use(express.json());
const PORT = process.env.PORT || 9000;

const data = {
    message: "¡Hola desde el servidor JavaScript!"
};
  
app.get('/', (req, res) => {
    res.json(data); // Envía los datos como JSON al cliente
});

//se me escucha?

app.post('/', (req, res) => {
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



app.listen(PORT, () => {
    console.log('Escuchando el puerto: ' + PORT);
});