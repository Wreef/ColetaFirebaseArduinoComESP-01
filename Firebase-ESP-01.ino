#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "SEU FIREBASE-HOST"
#define FIREBASE_AUTH "SEU FIREBASE-AUTH"

#define WIFI_SSID "SUA REDE WI-FI"
#define WIFI_PASSWORD "SENHA  DA SUA REDE WI-FI"


void setup() {
  
  Serial.begin(9600);
  delay(500);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Conectando");
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(".");
    delay(500);
  }

  Serial.println("Conectado:");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  delay(500);
}

void loop() {

  String vsData = String(Firebase.getInt("/Banco/Var"));
  
  if (vsData.length() > 0)
  {
    Serial.println("O" + vsData + "K");
  }
  
  delay(15000);
}
