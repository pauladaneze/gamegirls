//http://www.theorycircuit.com/add-sound-detector-arduino-project/
int led = 13; //test
int threshold = 450; //Change This
int volume = 0;

void setup() {                
  Serial.begin(9600); // Serial port begin
  pinMode(led, OUTPUT); //test
}

void loop() {
  
  volume = analogRead(A0); // Reads the value from the Analog PIN A0
    
    Serial.println(volume);
    delay(250);
    
   // sound combine to LED
  if(volume>=threshold){
    digitalWrite(led, HIGH); //Turn ON Led
  }  
  else{
    digitalWrite(led, LOW); // Turn OFF Led
  }

}
