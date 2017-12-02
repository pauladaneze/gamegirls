
// the setup function runs once when you press reset or power the board

int ledPin1 = 13; 
int ledPin2 = 11; 

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  Serial.begin(9600);

  
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledPin1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(ledPin1, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

 Serial.print(ledPin1);
 Serial.println(",");
}
