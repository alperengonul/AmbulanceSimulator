#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);
const int buttonPin1 = 2;  // 1. buton pin numarası
const int buttonPin2 = 3;  // 2. buton pin numarası
const int buttonPin3 = 4;  // 3. buton pin numarası
const int buttonPin4 = 5;  // 4. buton pin numarası

void setup() {
  radio.begin();
  Serial.begin(9600);
  radio.openWritingPipe(0xF0F0F0F0E1LL); // Alıcı adresi

  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(buttonPin1) == LOW) {
    sendText("yol1");
    delay(3000);
    sendText("yol1");
  } else if (digitalRead(buttonPin2) == LOW) {
    sendText("yol2");
    delay(3000);
    sendText("yol2");
  } else if (digitalRead(buttonPin3) == LOW) {
    sendText("yol3");
    delay(3000);
    sendText("yol3");
  } else if (digitalRead(buttonPin4) == LOW) {
    sendText("yol4");
    delay(3000);
    sendText("yol4");
  }
}

void sendText(const char* text) {
  radio.write(text, strlen(text) + 1);
  Serial.println(text);
  delay(1000);
}