# ESP8266/32 eduroam connection in Arduino IDE
Successful connection to eduroam (at the University of Edinburgh), PEAP + MSCHAPv2, using both the ESP8266 and the ESP-32. 

## ESP8266
ESP's tested:
  * Seeds Wi-Fi Module ESP-01
  * Barebones AI-Thinker ESP8266 ESP-12S
  
Make sure you flash your ESP with Espressif's most recent SDK, https://www.espressif.com/en/support/download/sdks-demos, "ESP8266 NONOS SDK V3.0.0"
otherwise it may fail to connect. Both of the ESP's tested did not work out of the box and needed the SDK V3.0.0 reflash.

## ESP-32
ESP's tested:
  * HiLetgo ESP-WROOM-32 Development Board

A lot more people have had success connecting to eduroam, with the ESP-32's. https://github.com/espressif/arduino-esp32/tree/master/libraries/WiFi/examples/WiFiClientEnterprise


