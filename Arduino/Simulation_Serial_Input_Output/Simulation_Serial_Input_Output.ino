int ledPin = 13;

void setup() {
	Serial.begin(9600); 
}

void loop() {
	while (Serial.available() == 0);
	int input = Serial.read() - '0';
	if (input == 1) {
		Serial.println("123456781234_MallStoreA");
		digitalWrite(ledPin, HIGH);
		digitalWrite(ledPin, LOW);
	} else if (input == 2) {
		Serial.println("876543210987_MallExit");
		digitalWrite(ledPin, HIGH);
		digitalWrite(ledPin, LOW);
	} else if (input == 3) {
		Serial.println("098765431234_MallStoreA");
		digitalWrite(ledPin, HIGH);
		digitalWrite(ledPin, LOW);
	} else {
		Serial.println("Invalid");
	}
}
