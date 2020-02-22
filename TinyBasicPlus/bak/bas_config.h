#ifndef BAS_CONFIG_h
#define BAS_CONFIG_h


#ifdef ESP32
#pragma message "ESP32 defined inside bas_config"
#define USE_SDCARD
#endif

#if defined __has_include && __has_include ("SD.h")   /* not portable */
#pragma message "has_include works"
//#include "FS.h"
//#include "SD.h"
//#include "SPI.h"
#endif

#ifdef ESP32
#pragma message "config.h is using ESP32"
#endif // ESP32

#endif // BAS_CONFIG_h
