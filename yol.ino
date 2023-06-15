#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define y1l1 A0
#define y1l2 A1
#define y1l3 2
#define y2l1 3
#define y2l2 4
#define y2l3 5
#define y3l1 6
#define y3l2 7
#define y3l3 8
#define y4l1 A2
#define y4l2 A3

String yolid ;
RF24 radio(9, 10);

LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD adresi ve boyutlarına göre değiştirilebilir

void setup() {
Serial.begin(9600);
 lcd.begin();  // LCD boyutlarına göre değiştirilebilir
  lcd.backlight();
  pinMode(y1l1, OUTPUT);
  pinMode(y1l2, OUTPUT);
  pinMode(y1l3, OUTPUT);
  pinMode(y2l1, OUTPUT);
  pinMode(y2l2, OUTPUT);
  pinMode(y2l3, OUTPUT);
  pinMode(y3l1, OUTPUT);
  pinMode(y3l2, OUTPUT);
  pinMode(y3l3, OUTPUT);
  pinMode(y4l1, OUTPUT);
  pinMode(y4l2, OUTPUT);

  digitalWrite(y1l1,LOW);
  digitalWrite(y1l2,LOW);
  digitalWrite(y1l3,LOW);
  digitalWrite(y2l1,LOW);
  digitalWrite(y2l2,LOW);
  digitalWrite(y2l3,LOW);
  digitalWrite(y3l1,LOW);
  digitalWrite(y3l2,LOW);
  digitalWrite(y3l3,LOW);
  digitalWrite(y4l1,LOW);
  digitalWrite(y4l2,LOW);
 
radio.begin();
radio.openReadingPipe(1, 0xF0F0F0F0E1LL); // Verici adresi
radio.startListening();
}

void loop() {
if (radio.available()) {
char text[32] = "";
radio.read(&text, sizeof(text));
yolid=text;
Serial.println(text);
if(yolid=="yol1"){
     lcd.clear(); // LCD ekranı temizle
  
  lcd.setCursor(0, 0); // İlk satıra git
  lcd.print("Ambulans geliyor!");
  
  delay(2000); // 2 saniye bekle

  lcd.clear(); // LCD ekranı temizle
  
  lcd.setCursor(0, 0); // İlk satıra git
  lcd.print("Fermuar yontemi");
  lcd.setCursor(0, 1); // İkinci satıra git
  lcd.print("uygulayin.");
  digitalWrite(y1l1,HIGH);
  digitalWrite(y1l2,LOW);
  digitalWrite(y1l3,LOW);

  digitalWrite(y2l1,HIGH);
  digitalWrite(y2l2,LOW);
  digitalWrite(y2l3,LOW);

  digitalWrite(y3l1,LOW);
  digitalWrite(y3l2,LOW);
  digitalWrite(y3l3,HIGH);

    digitalWrite(y4l1,HIGH);
  digitalWrite(y4l2,LOW);
}
if(yolid=="yol2"){
     lcd.clear(); // LCD ekranı temizle
  
  lcd.setCursor(0, 0); // İlk satıra git
  lcd.print("Ambulans geliyor!");
  
  delay(2000); // 2 saniye bekle

  lcd.clear(); // LCD ekranı temizle
  
  lcd.setCursor(0, 0); // İlk satıra git
  lcd.print("Fermuar yontemi");
  lcd.setCursor(0, 1); // İkinci satıra git
  lcd.print("uygulayin.");
  digitalWrite(y1l1,LOW);
  digitalWrite(y1l2,LOW);
  digitalWrite(y1l3,HIGH);

  digitalWrite(y2l1,LOW);
  digitalWrite(y2l2,LOW);
  digitalWrite(y2l3,HIGH);

  digitalWrite(y3l1,LOW);
  digitalWrite(y3l2,LOW);
  digitalWrite(y3l3,HIGH);

  digitalWrite(y4l1,HIGH);
  digitalWrite(y4l2,LOW);
}
if(yolid=="yol3"){
     lcd.clear(); // LCD ekranı temizle
  
  lcd.setCursor(0, 0); // İlk satıra git
  lcd.print("Ambulans geliyor!");
  
  delay(2000); // 2 saniye bekle

  lcd.clear(); // LCD ekranı temizle
  
  lcd.setCursor(0, 0); // İlk satıra git
  lcd.print("Fermuar yontemi");
  lcd.setCursor(0, 1); // İkinci satıra git
  lcd.print("uygulayin.");
  digitalWrite(y1l1,LOW);
  digitalWrite(y1l2,LOW);
  digitalWrite(y1l3,HIGH);

  digitalWrite(y2l1,HIGH);
  digitalWrite(y2l2,LOW);
  digitalWrite(y2l3,LOW);

  digitalWrite(y3l1,HIGH);
  digitalWrite(y3l2,LOW);
  digitalWrite(y3l3,LOW);

      digitalWrite(y4l1,HIGH);
  digitalWrite(y4l2,LOW);
}
if(yolid=="yol4"){
     lcd.clear(); // LCD ekranı temizle
  
  lcd.setCursor(0, 0); // İlk satıra git
  lcd.print("Ambulans geliyor!");
  
  delay(2000); // 2 saniye bekle

  lcd.clear(); // LCD ekranı temizle
  
  lcd.setCursor(0, 0); // İlk satıra git
  lcd.print("Fermuar yontemi");
  lcd.setCursor(0, 1); // İkinci satıra git
  lcd.print("uygulayin.");
  digitalWrite(y1l1,LOW);
  digitalWrite(y1l2,LOW);
  digitalWrite(y1l3,HIGH);

  digitalWrite(y2l1,HIGH);
  digitalWrite(y2l2,LOW);
  digitalWrite(y2l3,LOW);

  digitalWrite(y3l1,LOW);
  digitalWrite(y3l2,LOW);
  digitalWrite(y3l3,HIGH);
  
      digitalWrite(y4l1,LOW);
  digitalWrite(y4l2,HIGH);
}
}
}



