#include <SPI.h>
#include <SD.h>

File root;

void printDirectory(File dir, int numTabs) {
  while (true) {
    File entry = dir.openNextFile();
    if (!entry) {
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print("\t");
    }
    Serial.println(entry.name());
    if (entry.isDirectory()) {
      // Serial.println("/");
      printDirectory(entry, numTabs + 1);
    } else {
      Serial.print("\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing SD card...");
  if (!SD.begin(10)) {
    Serial.println("Initialization failed!");
  }
  Serial.println("Initialization done.");

  root = SD.open("/");
  printDirectory(root, 0);
  Serial.println("Done.");
}

void loop() {

}
