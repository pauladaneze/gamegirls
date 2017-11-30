import { Meteor } from 'meteor/meteor';
import { HTTP } from 'meteor/http';
import { Asteroids } from '../imports/api/asteroids.js'



Meteor.publish('twitter', function asteroidsPublication() {
  return Asteroids.find();
});

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
  console.log(event && event.text);
  count++;
  console.log(count);

});
 
stream.on('error', function(error) {
  throw error;
});
 
// You can also get the stream in a callback if you prefer. 
/*client.stream('statuses/filter', {track: 'javascript'}, function(stream) {
  stream.on('data', function(event) {
    console.log(event && event.text);
  });
 
  stream.on('error', function(error) {
    throw error;
  });
});

/*client.get('favorites/list', function(error, tweets, response) {
  if(error) throw error;
  console.log(tweets);  // The favorites. 
  console.log(response);  // Raw response object. 
});


client.post('statuses/update', {status: 'hello'})
  .then(function (tweet) {
    console.log(tweet);
  })
  .catch(function (error) {
    throw error;
  })


*/


//Meteor.methods({
  //loadAsteroids: function() {
   // console.log("loadAsteroids");

    //HTTP.call('GET', 'https://twitter.com/search?q=%23MeToo&src=tyah', {
    //  params: { api_key: "QoPlW47zYbMPE27tuikPJb3OZ", start_date:"2017-10-17", end_date:"2017-10-24" }
    //}, (error, result) => {
     // if (!error) {

       // var data = result.data;
       // console.log(data["near_earth_objects"])


        //for (var obj in data["near_earth_objects"]) {
          
          //console.log(obj)
          //for (var i = 0; i < data["near_earth_objects"][obj].length; i++) {
          //  console.log(data["near_earth_objects"][obj][i].name);
          //  Asteroids.insert({text:data["near_earth_objects"][obj][i].name, date:new Date()})
         // }
       // }

        // for (var i=0; i < result.content.length; i++) {
        //   console.log(result.content[i].name);
        // }
      //}
    //});
 // }
//})


Meteor.startup(() => {
  // code to run on server at startup


});
