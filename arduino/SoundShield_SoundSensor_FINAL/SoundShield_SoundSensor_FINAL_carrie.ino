#include <SPI.h>           // SPI library
#include <SdFat.h>         // SDFat Library
#include <SdFatUtil.h>     // SDFat Util Library
#include <SFEMP3Shield.h>  // Mp3 Shield Library

SdFat sd; // Create object to handle SD functions
SFEMP3Shield MP3player;

int led = 13; //LED test to SoundSensor//erase!!!
int threshold = 40; //Change This  SoundSensor
int volume; //SoundSendor
int tweets = 0;
int array[] = {"track001.mp3", "track002.mp3", "track003.mp3", "track004.mp3", "track005.mp3", "track006.mp3", "track007.mp3", "track008.mp3", "track009.mp3"};
long randNumber;

String inputString = "";
boolean stringComplete = false;
boolean soundIsPlaying = false;


void setup() {

  Serial.begin(9600); // Serial port begin
  randomSeed(0);
  pinMode(led, OUTPUT); //LED test to SoundSensor//erase!!!

  //start the shield
  sd.begin(SD_SEL, SPI_HALF_SPEED);
  MP3player.begin();

  inputString.reserve(200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  //  establishContact();  // send a byte to establish contact until receiver responds
}

  
void playSounds() {

  // say that sound is playing
  soundIsPlaying = true;

  // play all the sounds
  for (int j = 0; j < tweets ; j++) {
    randNumber = random(9);
    MP3player.playMP3(array[randNumber]); // play track by file name.
    delay(2000);
    MP3player.stopTrack();

  }

  // reset the tweets count
  tweets = 0;
  // say that sound is no longer playing
  soundIsPlaying = false;
}

void loop() {
  //
  volume = analogRead(A0); // Reads the value from the Analog PIN A0



  if (volume <= threshold) {
    digitalWrite(led, HIGH); //Turn ON Led //LED test to SoundSensor//erase!!!
    //tell meteor to give you the number of tweets
    
    if (!soundIsPlaying) {
      Serial.println("me too!");
      Serial.println(volume);
    }


  }

  else {
    digitalWrite(led, LOW); // Turn OFF Led //LED test to SoundSensor//erase!!!
  }

  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('|');
    tweets = data.toInt();
    
    Serial.print("tweets:");
    Serial.println(data);
    // when you have the number of tweets
    // and sound is not already playing, play the sounds


if (tweets > 0 && tweets != 31 && !soundIsPlaying) {
    Serial.print("nowplaying:");
    Serial.println(tweets);
  playSounds();
 }
 
  //  if (tweets > 0 && !soundIsPlaying) {
  //    playSounds();
  //  }
    
  




  Serial.println(volume); //to noise value
  delay(100);

}

}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.println("0,0,0");   // send an initial string
    delay(300);
  }
}
