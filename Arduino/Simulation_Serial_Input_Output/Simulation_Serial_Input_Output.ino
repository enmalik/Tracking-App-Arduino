int ledPin = 13;

void setup() {
	Serial.begin(9600); 
}

void loop() {
	/*Serial.print("GET /meter.php HTTP/1.0\n");
	delay(1000);*/
	
	while (Serial.available() == 0);
	int input = Serial.read() - '0';
	
	if (input == 1) {
		Serial.println("12345678_MallStoreA");
		digitalWrite(ledPin, HIGH);
		digitalWrite(ledPin, LOW);
	} else if (input == 2) {
		Serial.println("87654321_MallExit");
		digitalWrite(ledPin, HIGH);
		digitalWrite(ledPin, LOW);
	} else if (input == 3) {
		Serial.println("09876543_MallStoreA");
		digitalWrite(ledPin, HIGH);
		digitalWrite(ledPin, LOW);
	} else {
		Serial.println("Invalid");
	}

}
