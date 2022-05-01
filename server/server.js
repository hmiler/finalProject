
const Net = require('net');
const port = 80;
function parseBuffer(buffer){
    let message={};
    message.type=buffer[1];
    if(message.type==1)
    {
        message.status=buffer[2];
    
    }
    else{
        message.distance=buffer[2] 
        message.angle=buffer[6]   
        message.speed=buffer[10]   
    }
    console.log(message)
}
const server = new Net.Server();
server.listen(port, function() {
    console.log(`Server listening for connection requests on socket localhost:${port}`)
});

server.on('connection', function(socket) {
    console.log('A new connection has been established.');
    socket.write('Hello, client.');
    socket.on('data', function(buffer) {
        console.log(`Data received from client: ${buffer.toString()}`);
    });
    socket.on('end', function() {
        console.log('Closing connection with the client');
    });
    socket.on('error', function(err) {
        console.log(`Error: ${err}`);
    });
});
