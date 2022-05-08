const express=require('express');
const app=express();
var cors = require('cors')

app.use(cors())


app.listen(3001,_=>{console.log('Server listening at http://localhost:3001')});

const Net = require('net');
const { stringify } = require('querystring');
const port =81;
const server = new Net.Server();
let myData=[];
server.listen(port, function() {
   
    console.log(`Server listening for connection requests on socket localhost:${port}`);
});
app.get('/data',(req,res)=>{
   res.send(myData);
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
     myData=[...myData,message];
     console.log(message);

}

