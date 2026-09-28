void setup() {
  // Configure la broche de la LED intégrée comme une sortie (OUTPUT)
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Allume la LED en appliquant 5V (HIGH)
  digitalWrite(LED_BUILTIN, HIGH);
  
  // Si on veut la faire clignoter :
  // delay(1000); 
  // digitalWrite(LED_BUILTIN, LOW);
  // delay(1000);
}