import { Meteor } from 'meteor/meteor';
import { HTTP } from 'meteor/http';
import { Asteroids } from '../imports/api/asteroids.js'
import SerialPort from 'serialport';

const Readline = SerialPort.parsers.Readline;
const parser = new Readline();

//serial port
var port = new SerialPort('/dev/cu.usbmodem1411', {
  baudRate: 9600
});
port.pipe(parser);

Meteor.publish('twitter', function asteroidsPublication() {
  return Asteroids.find();
});

//twitter api stuff 
var Twitter = require('twitter');

var client = new Twitter({
  consumer_key: 'QoPlW47zYbMPE27tuikPJb3OZ',
  consumer_secret: 'wHV7tF2aI75iv7FUxfnJ2adnf1O1qQr3MlwPot8gcTaWZOA5SP',
  access_token_key: '934795826467164160-YZuthwYTgl8FunMXJnTP1FzaTbuvt73',
  access_token_secret: 'oVPh5aBq9lSqf1e16WOscLoS98nMOGCLIJXfRuDxaBna3'
});

var stream = client.stream('statuses/filter', {track: '#metoo'});
var count = 0;
var messageHistory = [];

stream.on('data', function(event) {
 // console.log(event && event.text);
  count++;
  console.log(count);
});
 
stream.on('error', function(error) {
  throw error;
});

// parse the data from serial into meaningful objects
function onData(data) {
  console.log("meteor onData: " + data);
 let dataArr = data.split(",");
 console.log(dataArr);
}

if (data == 10) {
console.log('led');
//console.log(count);
}
else { console.log('test');
} 


// serial event
function writeSerialData(data) {
  var buffer = Buffer.from(data);

  port.write(data, function(err) {
    if (err) {
      return console.log('Error on write: ', err.message);
    }
    console.log('meteor wrote', count);
  });

}





Meteor.startup(() => {
  // code to run on server at startup
});