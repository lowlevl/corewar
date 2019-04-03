const net = require('net');
const xml = require('fast-xml-parser');

const SYNC_SOCKET = false;
const OPT_XML = {
	attributeNamePrefix : "",
	attrNodeName: false,
	textNodeName: "_content",
	ignoreAttributes: false,
	allowBooleanAttributes : true,
	trimValues: false,
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
	str = data.toString();
	if (str.length > 6000) {
		console.log('str :', str.slice(0, 50), 'len :', str.length);
	} else {
		console.log('str :', str);
	}
	console.log('xml :', xml.parse(str, OPT_XML))
	nb++;
})

client.on('end', () => {
	console.log('socket end');
})

client.on('close', () => {
	console.log('connexion close');
	// console.log('recv', nb, 'msg')
	// client.destroy();
	// process.exit(0);
})
