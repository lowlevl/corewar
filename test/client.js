const net = require('net');

const client = new net.Socket();

client.connect(8080, '127.0.0.1', () => {
	console.log('connected');
})

let nb = 0;

client.on('data', (data) => {
	client.write('ok', (err) => {
		if (err) throw Error(err);
		console.log('msg send');
	})
	console.log('DATA: ', data);
	str = data.toString();
	if (str.indexOf('\u0000') > 0)
		str = str.slice(0, str.indexOf('\u0000'));
	console.log(str, str.length);
	console.log(JSON.parse(str, 'utf8'));
	nb++;
})

client.on('close', () => {
	console.log('connexion close');
	console.log('recv', nb, 'msg')
	client.destroy();
	process.exit(0);
})
