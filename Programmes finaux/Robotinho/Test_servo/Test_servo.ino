#include<SoftwareSerial.h> 
#define TX 11 
#define RX 3 
SoftwareSerial BlueT(RX,TX);

#include <Servo.h>
Servo servo1;
//Servo servo2;

char Data;

void setup() {
  Serial.begin(9600); 
  BlueT.begin(9600); 

  servo1.attach(12,500,2650);
  //servo2.attach(13,500,2650);

}

void loop() {
  if (BlueT.available()){
      Data=BlueT.read();
      Serial.print("Data =  ");
      Serial.println(Data);
  
  if (Data=='T') {
      servo1.writeMicroseconds(1500);
      delay(1000);
      servo1.writeMicroseconds(0);  
  }

  //if (Data=='O') {
      //servo2.writeMicroseconds(3000);
  //}

  //if (Data=='C') {
      //servo2.writeMicroseconds(0);
  //}
  
 }    

}
