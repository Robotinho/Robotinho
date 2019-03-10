#include<SoftwareSerial.h> 
#define TX 11 
#define RX 3 
SoftwareSerial BlueT(RX,TX);

#include <Servo.h>
Servo servo1;
//Servo servo2;

int PWM;
char Data;

//-- MOTEUR A -
int ENA=5; 
int IN1=7; 
int IN2=4; 

//-- MOTEUR B -
int ENB=6;  
int IN3=2; 
int IN4=8; 

void setup() {
  
  Serial.begin(9600); 
  BlueT.begin(9600); 

  servo1.attach(12,500,2650);
  //servo2.attach(13,500,2650);
   
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN1,OUTPUT); 
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

void loop() {

   //Pour récupérer les données de communication Bluetooth
   if (BlueT.available()){
      Data=BlueT.read();
      Serial.print("Data =  ");
      Serial.println(Data);

   //PWM pour régler la puissance du moteur, ainsi la vitesse du robot
   if (Data=='S'){
     Serial.println("boucleS");
     PWM=BlueT.parseInt();
     Serial.println(PWM);
     analogWrite(ENA,PWM);
     analogWrite(ENB,PWM);
     }

  //1,2,3,4 pour régler la direction du robot
  //Avant 
   if (Data=='1') {
    Serial.println("boucle1");
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN4,LOW); 
    digitalWrite(IN3,HIGH);
    analogWrite(ENA,PWM);
    analogWrite(ENB,PWM); }

  //Gauche
  if (Data=='4') {
    Serial.println("boucle4");
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH); 
    digitalWrite(IN4,LOW);
    analogWrite(ENA,PWM);
    analogWrite(ENB,PWM); }

  //Arrière
  if (Data=='3') {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW); 
    digitalWrite(IN4,HIGH);
    analogWrite(ENA,PWM);
    analogWrite(ENB,PWM);
    Serial.println("boucle3");
    }

  //Droite
  if (Data=='2') {
    Serial.println("boucle2");
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW); 
    digitalWrite(IN4,HIGH);
    analogWrite(ENA,PWM);
    analogWrite(ENB,PWM);
    }

  //Système de tir
  if (Data=='T') {
      servo1.writeMicroseconds(1500);
      delay(1000);
      servo1.writeMicroseconds(0);  
  }

  //Pour ouvrir la trappe
  //if (Data=='O') {
      //servo2.writeMicroseconds(3000);
  //}

  //Pour fermer la trappe
  //if (Data=='C') {
      //servo2.writeMicroseconds(0);
  //}
}
  

}
