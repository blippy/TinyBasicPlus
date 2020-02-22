#ifdef USE_SDCARD
#pragma message "sdcard.ino being processed"

#include "bas_config.h"

//#include <Arduino.h>
#include "FS.h"
#include "SD.h"
#include "SPI.h"

//using namespace fs;
//extern fs::SDFS SD;

void init_sdcard() {
      if(!SD.begin()){
        Serial.println("Card Mount Failed");
        return;
    }
}
void listDir(fs::FS &fs, const char * dirname, uint8_t levels){
//void listDir(const char * dirname, uint8_t levels){
    Serial.printf("Listing directory: %s\n", dirname);

//FS fs;
    File root = fs.open(dirname);
    if(!root){
        Serial.println("Failed to open directory");
        return;
    }
    if(!root.isDirectory()){
        Serial.println("Not a directory");
        return;
    }

    File file = root.openNextFile();
    while(file){
        if(file.isDirectory()){
            Serial.print("  DIR : ");
            Serial.println(file.name());
            if(levels){
                listDir(fs, file.name(), levels -1);
            }
        } else {
            Serial.print("  FILE: ");
            Serial.print(file.name());
            Serial.print("  SIZE: ");
            Serial.println(file.size());
        }
        file = root.openNextFile();
    }
}

void sdir() {
  listDir(SD, "/", 0);  
}
#endif // USE_SDCARD
