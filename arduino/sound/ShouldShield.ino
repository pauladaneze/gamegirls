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
  MP3player.playTrack(1);

  Serial.println("I'm bored!");
  delay(2000);

}
