#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9
#define SERVO_PIN 6
#define LED_PIN 4
#define GREEN_LED_PIN 8
#define BUZZER_PIN 7
#define IRSENSOR_PIN 2

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo lockServo;

const int distanceThreshold = 100;

void setup(){
  Serial.begin(9600);
  
  lcd.init();
  lcd.backlight();
  lcd.begin(16,2);
  lockServo.attach(SERVO_PIN);
  lcd.setCursor(5,0);
  lcd.print("WELCOME");
  lcd.setCursor(3,1);
  lcd.print("ADAMSONIAN");
  delay(2000);
  lcd.clear();
  
  SPI.begin();
  mfrc522.PCD_Init();

  pinMode(LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(IRSENSOR_PIN, INPUT);
}

void loop(){
  int sensorVal = digitalRead(IRSENSOR_PIN);

  if (sensorVal == LOW){
    lcd.clear();
    lcd.print("Please tap your");
    lcd.setCursor(3,1);
    lcd.print("ID");
    delay(1000);
    lcd.clear();
  

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
      lcd.clear();
      lcd.print("Access Granted!");
      lockServo.write(90);
      delay(1000);
      lockServo.write(0);
      lcd.clear();
      count();
      lockServo.write(0);
      lockServo.write(90);
      digitalWrite(LED_PIN, LOW);
          
    } else{
      digitalWrite(LED_PIN, LOW);
      digitalWrite(GREEN_LED_PIN, HIGH);
      digitalWrite(BUZZER_PIN, HIGH);
      lcd.print("Access Denied!");
      delay(1000);
      digitalWrite(BUZZER_PIN, LOW);
      digitalWrite(GREEN_LED_PIN, LOW);
      lcd.clear();
    }
    delay(1000);
  }}else{
    lcd.clear();
    lcd.print("COME CLOSER");
    lockServo.write(90);
  }
}

void count() {
  lcd.print("5");
  delay(1000);
  lcd.clear();
  lcd.print("4");
  delay(1000);
  lcd.clear();
  lcd.print("3");
  delay(1000);
  lcd.clear();
  lcd.print("2");
  delay(1000);
  lcd.clear();
  lcd.print("1");
  delay(1000);
  lcd.clear();
}
