"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var net_1 = require("net");
var client_config_json_1 = require("./client.config.json");
var client = new net_1.Socket();
client.connect(client_config_json_1.port, client_config_json_1.host, function () {
    console.log('connected');
});
var nbMessage = 0;
var nbReply = 0;
var leftToRead = -1;
var saveBuff;
var clientSync = client_config_json_1.socketSync;
function getLengthFromMessage(data) {
    return data.readInt32LE(0);
}
function logMessage(buffer) {
    try {
        clientSync && client.write('ok', function () {
            nbReply++;
        });
    }
    catch (error) {
        console.error(error);
    }
    nbMessage++;
    var len = getLengthFromMessage(buffer);
    var str = buffer.toString(undefined, 4);
    console.log('raw :', buffer);
    console.log('len :', len);
    console.log('str :', str);
    console.log('');
}
function readMessage(data) {
    var toRead = getLengthFromMessage(data);
    if (toRead > data.length) {
        leftToRead = toRead - data.length;
        saveBuff = data;
        return;
    }
    var buff = data.slice(0, toRead);
    var left = data.slice(toRead, data.length);
    logMessage(buff);
    if (left.length > 0)
        readMessage(left);
}
function completeMessage(data) {
    if (leftToRead > data.length) {
        leftToRead -= data.length;
        saveBuff = Buffer.concat([saveBuff, data]);
    }
    else {
        var buff = data.slice(0, leftToRead);
        var left = data.slice(leftToRead, data.length);
        saveBuff = Buffer.concat([saveBuff, buff]);
        leftToRead = -1;
        readMessage(saveBuff);
        if (left.length > 0)
            readMessage(left);
    }
}
client.on('data', function (data) {
    if (leftToRead === -1) {
        readMessage(data);
    }
    else {
        completeMessage(data);
    }
});
client.on('end', function () {
    console.log('socket end');
});
client.on('error', function (err) {
    console.error(err);
});
client.on('close', function () {
    console.log('server closed');
    console.log("print " + nbMessage + " message(s)");
    console.log('left :', leftToRead);
    console.log('buff :', saveBuff);
    console.log('reply :', nbReply);
});
