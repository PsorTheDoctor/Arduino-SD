#include <SPI.h>
#include <SD.h>

File file;
String filename = "test.txt";

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing SD card...");
  if (!SD.begin(10)) {
    Serial.println("Initialization failed!");
  }
  Serial.println("Initialization done.");

  file = SD.open(filename, FILE_WRITE);
  if (file) {
    Serial.println("Writing to " + filename);
    file.println("Hello World!");
    file.close();
    Serial.println("Done.");
  } else {
    Serial.println("Error opening " + filename);
  }
}

void loop() {
  
}
