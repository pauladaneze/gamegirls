#include <SPI.h>
#include <SdFat.h>
#include <SdFatUtil.h> 
#include <SFEMP3Shield.h>

SdFat sd;
SFEMP3Shield MP3player;

void setup() {

  Serial.begin(9600);

  //start the shield
  sd.begin(SD_SEL, SPI_HALF_SPEED);
  MP3player.begin();


}

//do something else now
void loop() {
   //start playing track 1
    MP3player.playTrack(1); // play track 1 for 5 seconds
    delay(5000);
    MP3player.stopTrack();

    MP3player.playTrack(2); // play track 2 for 2 seconds
    delay(2000);
    MP3player.stopTrack();

    MP3player.playMP3("track003.mp3"); // play track by file name.
    delay(2000);
    MP3player.stopTrack();

  Serial.println("I'm bored!");
  delay(2000);

}
