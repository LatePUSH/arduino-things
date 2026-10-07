#include "WiFiS3.h"

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("Initialisation du module WiFi...");
  
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Erreur: Pas de module WiFi détecté !");
    while (true);
  }
}

void loop() {
  Serial.println("Scan des réseaux en cours...");
  int numSsid = WiFi.scanNetworks();

  if (numSsid == -1) {
    Serial.println("Aucun réseau trouvé.");
  } else {
    Serial.print(numSsid);
    Serial.println(" réseaux trouvés :");

    for (int i = 0; i < numSsid; i++) {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i)); // Network name
      Serial.print(" | Signal (RSSI): ");
      Serial.print(WiFi.RSSI(i)); // Signal
      Serial.println(" dBm");
    }
  }
  Serial.println("-----------------------");
  delay(10000); // Every 10 seconds
}