const mysql = require('mysql');
const fs = require('fs');
const path = require('path');






const connection = mysql.createConnection({
  host: 'sql5.freesqldatabase.com',
  user: 'sql5688705',
  password: 'uACuvPiU8u',
  database: 'sql5688705',
  port: 3306
});






connection.connect(err => {
  if (err) {
    return console.error('error connecting: ' + err.stack);
  }
  console.log('Connected to the database with ID ' + connection.threadId);

  // Path to the folder containing SVG files
  const folderPath = '/home/danilo/SpotIT/code/Images/ComputerScience';

  // Read all files in the folder
  fs.readdir(folderPath, (err, files) => {
    if (err) throw err;

    // Counter to track the number of SVG files processed
    let filesProcessed = 0;

    // Iterate through each file in the folder
    files.forEach(file => {
      const svgPath = path.join(folderPath, file);

      // Read the content of the SVG file as a Buffer
      fs.readFile(svgPath, (err, data) => {
        if (err) throw err;

        // Insert the SVG into the database
        insertSVGIntoDatabase(data);

        // Increment the counter
        filesProcessed++;

        // Check if all files have been processed
        if (filesProcessed === files.length) {
          // Close the database connection after inserting all SVGs
          connection.end(err => {
            if (err) return console.log('error:' + err.message);
            console.log('Database connection closed.');
          });
        }
      });
    });
  });
});




// Function to insert the SVG into the database
function insertSVGIntoDatabase(svgBuffer) {
  const query = 'INSERT INTO image (data) VALUES (?)';
  const values = [svgBuffer];

  connection.query(query, values, (error, results, fields) => {
    if (error) throw error;

    console.log('SVG inserted successfully, ID:', results.insertId);
  });
}
