#include <DHT.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>



// Set these to run example.
#define FIREBASE_HOST "arduino-data-e10ab.firebaseio.com"
#define FIREBASE_AUTH "8Ud3vZDKDlHnXK0sCWtg56Q520ude83ydcG1eByK"
#define WIFI_SSID "RewiKaze"
#define WIFI_PASSWORD "0821592331"
#define DHTPIN D2
#define DHTTYPE DHT22
#define stringupload "Data/"

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  WiFiConnection();
  Initialization(); 
  pinMode(D5,INPUT);
  dht.begin();
}
int person = 0;
void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  int a = digitalRead(D5);
  Serial.println(a);

  if (a == 1){
    person++;
    Firebase.setInt(stringupload+String(person),t);
    Firebase.setInt(stringupload+String("Total"),person);
    //Serial.println(stringupload+String(person));
  }
  if (isnan(h) || isnan(t) || isnan(f)) {
  Serial.println("Failed to read from DHT sensor!");
  return;
  }
  
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
}

void Initialization()
{
  Serial.begin(9600);
  
}
void WiFiConnection()
{
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}


  
  

  
