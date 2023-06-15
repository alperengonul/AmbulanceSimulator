#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
String yolid ;
String yolid1 ;
RF24 radio(9, 10);
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD adresi ve boyutlarına göre değiştirilebilir
const int buttonPin1 = 2;  // 1. buton pin numarası
const int buttonPin2 = 3;  // 2. buton pin numarası
const int buttonPin3 = 4;  // 3. buton pin numarası
const int buttonPin4 = 5;  // 4. buton pin numarası

void setup() {
Serial.begin(9600);
 lcd.begin();  // LCD boyutlarına göre değiştirilebilir
  lcd.backlight();
    pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
 
radio.begin();
radio.openReadingPipe(1, 0xF0F0F0F0E1LL); // Verici adresi
radio.startListening();
}

void loop() {
  if (digitalRead(buttonPin1) == LOW) {
    yolid1="yol1";
    Serial.println("yolunuz:" + yolid1);
  } else if (digitalRead(buttonPin2) == LOW) {
    yolid1="yol2";
    Serial.println("yolunuz:" + yolid1);
  } else if (digitalRead(buttonPin3) == LOW) {
    yolid1="yol3";
    Serial.println("yolunuz:" + yolid1);
  } else if (digitalRead(buttonPin4) == LOW) {
    yolid1="yol4";
    Serial.println("yolunuz:" + yolid1);
  }

if (radio.available()) {
char text[32] = "";
radio.read(&text, sizeof(text));
yolid=text;
Serial.println(text);
if(yolid==yolid1){
     lcd.clear(); // LCD ekranı temizle
  
  lcd.setCursor(0, 0); // İlk satıra git
  lcd.print("Ambulans geliyor!");
  
  delay(2000); // 2 saniye bekle

  lcd.clear(); // LCD ekranı temizle
  
  lcd.setCursor(0, 0); // İlk satıra git
  lcd.print("Fermuar yontemi");
  lcd.setCursor(0, 1); // İkinci satıra git
  lcd.print("uygulayin.");

  delay(2000); // 2 saniye bekle
}else lcd.clear(); // LCD ekranı temizle
}
}
