#include <WiFi.h>
#include "esp_wpa2.h"

#define SSID "eduroam"
#define WPA2_USERNAME "username@ed.ac.uk"
#define WPA2_IDENTITY WPA2_USERNAME
#define WPA2_PASSWORD "password"

int counter = 0;

void setup() {

  // Disconnect from wifi
    WiFi.disconnect(true);
    
  // Initialise wifi mode
    WiFi.mode(WIFI_STA);

  // Initialise serial
    Serial.begin(115200);
    delay(10);

    Serial.print("Trying to connect to ");
    Serial.println(SSID);

  // Set wpa2 details
    esp_wifi_sta_wpa2_ent_set_identity((uint8_t *)WPA2_IDENTITY, strlen(WPA2_IDENTITY)); 
    esp_wifi_sta_wpa2_ent_set_username((uint8_t *)WPA2_USERNAME, strlen(WPA2_USERNAME));
    esp_wifi_sta_wpa2_ent_set_password((uint8_t *)WPA2_PASSWORD, strlen(WPA2_PASSWORD));

  // Set wpa2 wifi configuration to default settings
    esp_wpa2_config_t config = WPA2_CONFIG_INIT_DEFAULT();

  // Set configuration settings to enable function
    esp_wifi_sta_wpa2_ent_enable(&config);

  // Connect to wifi
    WiFi.begin(SSID);

    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
      counter++;
      if(counter>=60){
        ESP.restart();
      }
    }
    
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address set: "); 
    Serial.println(WiFi.localIP()); 
    
}

void loop() {
  
}
  
  
  

  
