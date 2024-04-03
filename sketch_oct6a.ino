#include <DHT.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

String apikey = "Isi dengan api kalian";
const char *ssid = "Isi nama ssid kalian";
const char *pass = "Isi nama pw kalian";
const char *server = "api.thingspeak.com";
WiFiClient client;
unsigned long myChannelNumber = 2271678;
const char *myWriteAPIKey = "Isi dengan api kalian";

#define DHTPIN D2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2); // Ganti alamat sesuai dengan LCD I2C Anda


void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin();  // Perubahan ini
  Wire.begin(D1,D4);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Suhu: ");
  lcd.setCursor(0, 1);
  lcd.print("Kelembapan: ");
  Serial.println("Connected");
  WiFi.begin(ssid, pass);
  ThingSpeak.begin(client);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Sensor Tidak Terdeteksi");
    lcd.setCursor(0, 0);
    lcd.print("Sensor Tidak Terdeteksi");
    lcd.setCursor(0, 1);
    lcd.print("                "); // Menghapus data sebelumnya
    delay(2000);
    return;
  } else {
    Serial.print("Suhu: ");
    Serial.print(temperature);
    Serial.print(" °C | Kelembapan: ");
    Serial.print(humidity);
    Serial.println(" %");

    lcd.setCursor(0, 0);
    lcd.print(temperature, 1); // Menampilkan suhu dengan satu angka di belakang koma
    lcd.print(" C");

    lcd.setCursor(0, 1);
    lcd.print(humidity, 1); // Menampilkan kelembapan dengan satu angka di belakang koma
    lcd.print(" %");
    delay(2000);
  }
  ThingSpeak.writeField(myChannelNumber, 1, temperature, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 2, humidity, myWriteAPIKey);
}
