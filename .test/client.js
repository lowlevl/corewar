const net = require('net');
const xml = require('fast-xml-parser');

const SYNC_SOCKET = true;
const OPT_XML = {
	attributeNamePrefix: "",
	attrNodeName: false,
	textNodeName: "_content",
	ignoreAttributes: false,
	allowBooleanAttributes: true,
	trimValues: false,
};

const client = new net.Socket();

client.connect(8080, '127.0.0.1', () => {
	console.log('connected');
})

let nb = 0;

function intFromBytes(bytes) {
	val = 0;
	bytes.forEach((byte, i) => {
		val += byte;
		if (i < bytes.length - 1) {
			val = val << 8;
		}
	})
	return val;
}

function getLengthMessage(bytes) {
	return intFromBytes(bytes.slice(0, 4).reverse());
}

let buff = undefined;
let leftToRead = -1;

// read message from bytes buffer
function readMessage(data, len) {
	toRead = getLengthMessage(data);
	if (toRead > len) {
		buff = data;
		leftToRead = toRead - len;
	}
}

// complete missing part from last message
function completeMessage(data, len) {
	buff.concat
}

client.on('data', (data) => {
	SYNC_SOCKET && client.write('ok', (err) => {
		if (err) throw Error(err);
		console.log('msg send');
	})
	msgLen = data.length;
	if (leftToRead === -1) {
		readMessage(data, msgLen);
	} else {
		completeMessage(data, msgLen);
	}
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
