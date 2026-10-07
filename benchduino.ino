void setup() {
  Serial.begin(115200);
  while (!Serial); 
  
  Serial.println("Début du calcul des nombres premiers jusqu'à 10000...");
  
  unsigned long start = millis();
  int count = 0;
  
  for (int i = 2; i < 10000; i++) {
    bool isPrime = true;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) count++;
  }
  
  unsigned long duration = millis() - start;
  
  Serial.print("Nombres premiers trouves : ");
  Serial.println(count);
  Serial.print("Temps d'execution : ");
  Serial.print(duration);
  Serial.println(" millisecondes.");
}

void loop() {
  // On ne fait le test qu'une seule fois au démarrage
}