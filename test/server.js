var net = require('net');

var server = net.createServer((socket) => {
	socket.write('Echo server\r\n');
	socket.pipe(socket);
});

server.listen(8080, '127.0.0.1', 5, () => {
	console.log('listen');
});

const connected = [];
let nbmsg = 0;
const MAX_MSG = 5;

function send_msg(socket) {
	nbmsg++;
	if (nbmsg > MAX_MSG) {
		console.log('done sending msg');
		setTimeout(closeServer, 50);
	}
	else {
		socket.write(`<p id="${nbmsg}" name="yolo">"         0"</p>`, () => send_msg(socket));
	}
}

server.on('connection', (socket) => {
	connected.push(socket);
	socket = socket.setNoDelay(true);
	send_msg(socket);
	// for (let i = 0; i < 500; i++) {
	// 	setTimeout(() => socket.write('hello\n', () => console.log(Date.now())), 10);
	// }
})


function closeServer() {
	console.log('server close')
	connected.forEach((socket) => socket.destroy())
	server.close();
}
