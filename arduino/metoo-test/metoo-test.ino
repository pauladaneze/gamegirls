
// the setup function runs once when you press reset or power the board

int ledPin1 = 13;
int ledPin2 = 11;
String inputString = "";
boolean stringComplete = false;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  Serial.begin(9600);
  inputString.reserve(200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
//  establishContact();  // send a byte to establish contact until receiver responds
}



// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledPin1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(ledPin1, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  Serial.println(ledPin1);

  unsigned int t = 100;   // t: delay time
  
  if (Serial.available() > 0) {
    String s = Serial.readStringUntil('|');
    //Serial.print('revcd ');
    Serial.println(s);
    String hexValue = s;

    digitalWrite(ledPin2, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(ledPin2, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);                       // wait for a second

  }
}

//Serial.flush();


void establishContact() {
  while (Serial.available() <= 0) {
    Serial.println("0,0,0");   // send an initial string
    delay(300);
  }
}


