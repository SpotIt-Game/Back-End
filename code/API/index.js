const express = require('express');
const app = express();
const PORT = 8080;

app.use(express.json());

app.listen(
    PORT, 
    () => console.log(`It's alive on http://localhost:${PORT}`)
)

app.post('/spotit', (req, res) => {
    // Get the JSON document from the request body
    const jsonDocument = req.body;

    // Check if the request body contains JSON data
    if (!jsonDocument) {
        return res.status(400).json({ error: 'No JSON document provided' });
    }

    // Log the received JSON document (optional)
    // console.log('Received JSON document:', jsonDocument);

    // Return the received JSON document as response
    res.json(jsonDocument);
});
