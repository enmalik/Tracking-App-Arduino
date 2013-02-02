int ledPin = 13;
//char server[] = "google.com";

void setup() {
 Serial.begin(9600); 
}

void loop() {
while (Serial.available() == 0);

int input = Serial.read();// - '0';

if (input == 49) {
 Serial.println("Legit");
 //digitalWrite(ledPin, HIGH);
 //delay(500);
 //digitalWrite(ledPin, LOW);
 //Serial.print("GET /meter.php HTTP/1.0\n");
} else {
  Serial.println("Flop");
}


}
