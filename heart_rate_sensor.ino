int led1 = 2;
int led2= 3;
int led3= 4;

int output_Pin = A0;
double alpha = 0.65;
int period = 200;

void setup() {
  // put your setup code here, to run once:
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int rawValue = analogRead (output_Pin);
double value = (alpha / rawValue) * 60.0 * 1000;         
// Serial.print (rawValue);   // printing the sensor initial  value
Serial.print ("BPM: ");                                                                                          
Serial.println (value);      // printing the heart beat value 
delay (period);

if(value > 90) {
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
 } else if(value >70 || value <90) {
  digitalWrite(led1,LOW);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,LOW);
 } 

 if(value<69) {
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,HIGH); 
 }
}
