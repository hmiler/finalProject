

const Net = require('net');
const { stringify } = require('querystring');
const port =81;
const server = new Net.Server();
server.listen(port, function() {
   
    console.log(`Server listening for connection requests on socket localhost:${port}`);
});
server.on('connection', function(socket) {
    console.log('A new connection has been established.');
    socket.on('data', function(chunk) {
        parseBuffer(chunk);
    });
    socket.on('close', function() {
        console.log('Closing connection with the client');
    });
    socket.on('error', function(err) {
        console.log(`Error: ${err}`);
    });
});


const parseBuffer=(buffer)=> {
     let message = {}
     message.type = buffer[0];
     let ezerBuf = buffer.slice(2)
     if (message.type == 1) {
         message.status = Buffer.from(ezerBuf).readInt8(0)
     } 
     else {
         message.distance = Buffer.from(ezerBuf).readFloatLE(0);
         message.angle = Buffer.from(ezerBuf).readFloatLE(4);
         message.speed = Buffer.from(ezerBuf).readFloatLE(8);
     }
     console.log(message);
}
