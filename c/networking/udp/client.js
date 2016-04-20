const dgram = require('dgram');
const message = new Buffer('Whats up man!');
const client = dgram.createSocket('udp4');

client.send(message, 3333, '127.0.0.1', (err) => {
  client.close();
});
