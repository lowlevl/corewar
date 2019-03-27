const net = require('net');

const client = new net.Socket();

client.connect(8080, '127.0.0.1', () => {
	console.log('connected');
})

client.on('data', (data) => {
	console.log('DATA: ', );
	str = data.toString();
	arr = str.split('�');
	console.log('arr', arr.length);
	// for (let i = 0; i < str.length; i++) {
	// 	value = str.charCodeAt(i);
	// 	console.log(value, String.fromCharCode(value));
	// }
	console.log(arr);
})

client.on('close', () => {
	console.log('connexion close');
	client.destroy();
	process.exit(0);
})
