const int MAX_LEN = 30;
char sendMsg[MAX_LEN] = "Hello I'm Arduino-2\n";
char receiveMsg[MAX_LEN];
int switch_pin = 10;
void setup() {
 Serial.begin(9600);
 pinMode(switch_pin, INPUT);
}
void loop() {
 int switchState = digitalRead(switch_pin);
 if (switchState == HIGH) {
 if (Serial.available() > 0) {
 int len = Serial.parseInt();
 Serial.read();
 int n = Serial.readBytes(receiveMsg, len);
 receiveMsg[n] = '\0';
 Serial.print("Message = ");
 Serial.println(receiveMsg);
 }
 } 
 else {
 int len = strlen(sendMsg);
 Serial.write(sendMsg, len);
 delay(1000);
 }
}
