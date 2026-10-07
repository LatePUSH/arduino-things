#include <Mouse.h>

void setup() {
  Mouse.begin();
  
  Serial.begin(9600);
  Serial.println("Mouse Jiggler activé !");
  Serial.println("Débranche l'Arduino ou ouvre le Moniteur Série et tape 'stop' pour l'arrêter.");
}

bool actif = true;

void loop() {

  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    if (input.indexOf("stop") >= 0) {
      actif = false;
      Serial.println("Jiggler désactivé.");
    }
  }

  if (actif) {
    Mouse.move(5, 0, 0);  
    delay(100);
    Mouse.move(-5, 0, 0); 
    delay(5000);         
  }
}