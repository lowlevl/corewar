import { Socket } from 'net';
import { optionXmlParser, socketSync, port, host } from './client.config.json';
import { parse, X2jOptionsOptional } from 'fast-xml-parser';

const client = new Socket();

client.connect(port, host, () => {
    console.log('connected');
})

let nbMessage = 0;
let nbReply = 0;
let leftToRead = -1;
let saveBuff: Buffer;
let clientSync = socketSync;
function getLengthFromMessage(data: Buffer): number {
    return data.readInt32LE(0);
}

function logMessage(buffer: Buffer) {
    try {
        clientSync && client.write('ok', () => {
            nbReply++;
        });
    } catch (error) {
        console.error(error);
    }

    nbMessage++;
    let len = getLengthFromMessage(buffer);
    let str = buffer.toString(undefined, 4);
    console.log('raw :', buffer);
    console.log('len :', len);
    console.log('str :', str);
    console.log('xml :', parse(str, optionXmlParser as X2jOptionsOptional))
    console.log('');
}

function readMessage(data: Buffer) {
    let toRead = getLengthFromMessage(data);
    if (toRead > data.length) {
        leftToRead = toRead - data.length;
        saveBuff = data;
        return ;
    }
    let buff = data.slice(0, toRead);
    let left = data.slice(toRead, data.length);
    logMessage(buff);
    if (left.length > 0)
        readMessage(left);
}

function completeMessage(data: Buffer) {
    if (leftToRead > data.length) {
        leftToRead -= data.length;
        saveBuff = Buffer.concat([ saveBuff, data ]);
    } else {
        let buff = data.slice(0, leftToRead);
        let left = data.slice(leftToRead, data.length);
        saveBuff = Buffer.concat([ saveBuff, buff ]);
        leftToRead = -1;
        readMessage(saveBuff);
        if (left.length > 0)
            readMessage(left);

        }
}

client.on('data', (data: Buffer) => {
    if (leftToRead === -1) {
        readMessage(data);
    } else {
        completeMessage(data);
    }
})

client.on('end', () => {
    console.log('socket end');
})

client.on('error', (err) => {
    console.error(err);
})

client.on('close', () => {
    console.log('server closed');
    console.log(`print ${nbMessage} message(s)`);
    console.log('left :', leftToRead);
    console.log('buff :', saveBuff);
    console.log('reply :', nbReply);
})
