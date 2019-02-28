
#include <ESP8266WiFi.h>
#include "wpa2_enterprise.h"

#define SSID          "eduroam"
#define WPA2_USERNAME "s1234567@ed.ac.uk"
#define WPA2_IDENTITY WPA2_USERNAME
#define WPA2_PASSWORD "eduroamisannoyingtoconnect2"

int counter = 0;

void setup() {
  
  // Disconnect from wifi
    wifi_station_disconnect();

  // Initialise serial
    Serial.begin(115200);
    delay(10);
      
    Serial.print("Trying to connect to ");
    Serial.println(SSID);

  {
    // Set wpa2 wifi configuration to default settings
      char ssid[32] = SSID;
      char password[64] = WPA2_PASSWORD;
      struct station_config sta_conf;// = { 0 };

    // Set configuration settings to enable function
      os_memset(&sta_conf, 0, sizeof(sta_conf));
      os_memcpy(sta_conf.ssid, ssid, 32);
      os_memcpy(sta_conf.password, password, 64);
      wifi_station_set_config(&sta_conf);
  }

  {
    const char *identity = WPA2_IDENTITY;
    const char *username = WPA2_USERNAME;
    const char *password = WPA2_PASSWORD;

    // Set authentication of wpa2 enterprise to connect to AP
      wifi_station_set_wpa2_enterprise_auth(1);

    // Set wpa2 details
      wifi_station_set_enterprise_identity((u8*)(void*)identity, os_strlen(identity));
      wifi_station_set_enterprise_username((u8*)(void*)username, os_strlen(username));
      wifi_station_set_enterprise_password((u8*)(void*)password, os_strlen(password));
   }

  // Connect to wifi
    wifi_station_connect();
  
    while (wifi_station_get_connect_status() != WL_CONNECTED) {
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
