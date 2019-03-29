const net = require('net');
const xml = require('fast-xml-parser');

const SYNC_SOCKET = false;
const OPT_XML = {
	attributeNamePrefix : "",
	attrNodeName: false,
	textNodeName: "_content",
	ignoreAttributes: false,
	allowBooleanAttributes : true,
};

const client = new net.Socket();

client.connect(8080, '127.0.0.1', () => {
	console.log('connected');
})

let nb = 0;

client.on('data', (data) => {
	SYNC_SOCKET && client.write('ok', (err) => {
		if (err) throw Error(err);
		console.log('msg send');
	})
	console.log('DATA')
	console.log('raw :', data)
	console.log('str :', data.toString());
	console.log('xml :', xml.parse(data.toString(), OPT_XML))
	nb++;
})

client.on('close', () => {
	console.log('connexion close');
	console.log('recv', nb, 'msg')
	client.destroy();
	process.exit(0);
})
