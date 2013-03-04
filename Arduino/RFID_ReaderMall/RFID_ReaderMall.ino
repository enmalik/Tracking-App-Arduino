  /* RFID ID12 */

char tagString[16];
int count = 0;
char val = 0;
  
void setup() {
Serial.begin(9600); // connect to the serial por
}

void loop () {

  if(Serial.available() > 0){
    val = Serial.read();
    tagString[count] = val;
    count++;
  }

  if (count == 13){
    for (int x = 1; x < count; x++){
      Serial.print(tagString[x]);
    } 
   Serial.print("_Mall_");
  }
  
  if (count == 16){
   count = 0;
 }
}

