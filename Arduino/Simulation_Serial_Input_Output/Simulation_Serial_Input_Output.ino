int ledPin = 13;
char server[] = "google.com";

void setup() {
 Serial.begin(9600); 
}

void loop() {
/*Serial.print("GET /meter.php HTTP/1.0\n");
delay(1000);*/

while (Serial.available() == 0);
int input = Serial.read() - '0';
 if (input == 1) {
 Serial.println("Legit");
 digitalWrite(ledPin, HIGH);
 //delay(250);
 digitalWrite(ledPin, LOW);
} else {
  Serial.println("Flop");
}

}
