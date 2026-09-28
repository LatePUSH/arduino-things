const int analogPin = A0;

// Coefficient de lissage (alpha). 
// Modifie cette valeur entre 0.01 (très filtré) et 0.9 (peu filtré) pour voir l'impact.
const float alpha = 0.05; 

// Variable globale pour stocker l'état précédent du filtre (y[n-1])
float filteredValue = 0.0;

void setup() {
  // Vitesse élevée indispensable pour tracer des courbes fluides
  Serial.begin(115200); 
  
  // Initialisation du filtre avec la première vraie valeur pour éviter 
  // que la courbe ne parte de 0 au démarrage
  filteredValue = analogRead(analogPin);
}

void loop() {
  // 1. Acquisition du signal brut (x[n])
  int rawValue = analogRead(analogPin);
  
  // 2. Application du filtre passe-bas numérique
  filteredValue = (alpha * rawValue) + ((1.0 - alpha) * filteredValue);
  
  // 3. Envoi des données formatées pour le Traceur Série
  // L'IDE Arduino trace deux courbes distinctes si les valeurs sont séparées par une virgule
  Serial.print("Brut:");
  Serial.print(rawValue);
  Serial.print(",");
  Serial.print("Filtre:");
  Serial.println(filteredValue);
  
  // Fixe grossièrement la fréquence d'échantillonnage (ici ~100 Hz)
  delay(10); 
}