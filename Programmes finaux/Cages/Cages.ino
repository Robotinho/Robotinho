#include <LiquidCrystal.h>
LiquidCrystal lcd(3,4,5,6,7,8);

const int Entry = 2;

int but = 0;
int b = 0;

void setup() {
  //Dimensions du LCD
  lcd.begin(16,2);
  
  Serial.begin(9600);
  
  pinMode(Entry, INPUT);
  attachInterrupt(digitalPinToInterrupt(Entry), Goal, RISING); //Lorsque l'entrée passe de LOW à HIGH, on exécute la fonction Goal()
}

void loop() {
  //On fait un compteur "b" pour que les écritures sur le LCD changent seulement quand le nombre de buts change, autrement le LCD réécrit en continu et c'est illisible
  if(b!=but){
    delay(100);
    lcd.clear(); //efface l'écran
    lcd.setCursor(3,0); //Déplace le curseur pour centrer les écritures
    lcd.print("Nombre de");
    lcd.setCursor(3,1); //Déplace le curseur pour centrer les écritures
    lcd.print("buts : ");
    lcd.print(but);
    b=but; //Incrémente le compteur 
    delay(100);
  }
}

//Fonction appelée en cas d'interruption (dans le setup), qui implémente le nombre de buts
void Goal(){
  but=but+1;
}
