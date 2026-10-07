#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;


const uint32_t heart[] = {
  0x3184a444,
  0x42081100,
  0xa0040000
};

void setup() {
  Serial.begin(115200);
  matrix.begin();
}

void loop() {
  matrix.loadFrame(heart); 
  delay(500);
  matrix.clear();         
  delay(500);
}