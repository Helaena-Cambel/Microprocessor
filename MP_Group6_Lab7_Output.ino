#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);

#define LED_PIN 4
#define GREEN_LED_PIN 8
#define BUZZER_PIN 7

void setup(){
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  pinMode(LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop(){

  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()){

    Serial.print("Card UID: ");
    String tagID = "";
    for (byte i = 0; i < mfrc522.uid.size; i++){
      tagID += String(mfrc522.uid.uidByte[i]< 0x10 ? "0" : "");
      tagID += String(mfrc522.uid.uidByte[i], HEX);
      tagID.toUpperCase();
    }
    Serial.println(tagID);

    if (tagID == "A3E86CAD"){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(GREEN_LED_PIN, LOW);
      digitalWrite(BUZZER_PIN, LOW);
      delay(2000);
      digitalWrite(LED_PIN, LOW);
    } else{
      digitalWrite(LED_PIN, LOW);
      digitalWrite(GREEN_LED_PIN, HIGH);
      digitalWrite(BUZZER_PIN, HIGH);
      delay(1000);
      digitalWrite(BUZZER_PIN, LOW);
      digitalWrite(GREEN_LED_PIN, LOW);
    }
    delay(1000);
  }
}