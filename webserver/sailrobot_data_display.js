const app = require("express")();
const http = require('http').Server(app);
const io = require('socket.io')(http);
const fs = require("fs");

const port = 8080
const dataFile = 'sailrobot_data.csv'

app.get('/', function (req, res) {
    res.sendfile('sailrobot_data_display.html');
})
 
 http.listen(port, function() {
    console.log('listening on *:' + port);
 });

 fs.watch(dataFile, (event, filename) => {
    if (filename) {
        readAndSendCSVFile();
    }
});

function readAndSendCSVFile() {
    fs.readFile(dataFile, function (err, data) {
        if (err) return console.error(err);
        console.log(data.toString());
        io.sockets.emit('boatData',{ description: data.toString()});

        var csvFile = data.toString();
        var csvList = csvFile.split(';');
        
        console.log(csvList[3]);
    });
}