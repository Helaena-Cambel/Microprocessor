#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <Servo.h>

#define GREEN_LED_PIN 10
#define RED_LED_PIN 11
#define PASSCODE_LENGTH 4
#define SERVO_PIN 12
#define PASSCODE "1234"

const byte ROWS = 4;
const byte COLS = 4;
char keys [ROWS] [COLS] ={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3,2};
Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);
LiquidCrystal lcd(13, A4, A0, A1, A2, A3);
Servo lockServo;

String enteredPasscode = "";

void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  lockServo.attach(SERVO_PIN);
  lcd.setCursor(5,0);
  lcd.print("WELCOME");
  lcd.setCursor(3,1);
  lcd.print("ADAMSONIAN");
  delay(2000);
  lcd.clear();
  lcd.print("Enter Passcode:");
  pinMode (GREEN_LED_PIN, OUTPUT);
  pinMode (RED_LED_PIN, OUTPUT);
}

void loop(){
  access();
}

void access(){
  char key = keypad.getKey();
  if(key){
    if (key =='#'){
      if (enteredPasscode.length()==PASSCODE_LENGTH){
        if(enteredPasscode == PASSCODE){
          lcd.clear();
          lcd.print("Access Granted!");
          unlock();
          delay(2000);
          lcd.clear();
          lcd.setCursor(5,0);
          lcd.print("WELCOME");
          lcd.setCursor(3,1);
          lcd.print("ADAMSONIAN");
          delay(2000);
          lcd.clear();
          lcd.print("Enter Passcode:");
        } else{
          lcd.clear();
          lcd.print("Access Denied!");
          digitalWrite(RED_LED_PIN, HIGH);
          delay(2000);
          digitalWrite(RED_LED_PIN, LOW);
          lcd.clear();
          lcd.print("Enter Passcode:");
        }
        enteredPasscode = "";
      } else {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("MAXIMUM LIMIT!");
        lcd.setCursor(0,1);
        lcd.print("ENTER AGAIN");
        digitalWrite(RED_LED_PIN, HIGH);
        delay(5000);
        digitalWrite(RED_LED_PIN, LOW);
        delay(5000);
        setup();
      }
    } else{
      enteredPasscode += key;
      lcd.setCursor(0,1);
      lcd.print(enteredPasscode);
    }
  }
}

void unlock(){ 
  digitalWrite(GREEN_LED_PIN, HIGH);
  lockServo.write(90); 
  delay(2000);   
  lockServo.write(0);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please wait!");
  lcd.setCursor(0,1);
  lcd.print("20 secs");
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please wait!");
  lcd.setCursor(0,1);
  lcd.print("19 secs");
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please wait!");
  lcd.setCursor(0,1);
  lcd.print("18 secs");
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please wait!");
  lcd.setCursor(0,1);
  lcd.print("17 secs");
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please wait!");
  lcd.setCursor(0,1);
  lcd.print("16 secs");
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please wait!");
  lcd.setCursor(0,1);
  lcd.print("15 secs");
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please wait!");
  lcd.setCursor(0,1);
  lcd.print("14 secs");
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please wait!");
  lcd.setCursor(0,1);
  lcd.print("13 secs");
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please wait!");
  lcd.setCursor(0,1);
  lcd.print("12 secs");
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please wait!");
  lcd.setCursor(0,1);
  lcd.print("11 secs");
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please wait!");
  lcd.setCursor(0,1);
  lcd.print("10 secs");
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please wait!");
  lcd.setCursor(0,1);
  lcd.print("9 secs");
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please wait!");
  lcd.setCursor(0,1);
  lcd.print("8 secs");
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please wait!");
  lcd.setCursor(0,1);
  lcd.print("7 secs");
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please wait!");
  lcd.setCursor(0,1);
  lcd.print("6 secs");
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please wait!");
  lcd.setCursor(0,1);
  lcd.print("5 secs");
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please wait!");
  lcd.setCursor(0,1);
  lcd.print("4 secs");
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please wait!");
  lcd.setCursor(0,1);
  lcd.print("3 secs");
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please wait!");
  lcd.setCursor(0,1);
  lcd.print("2 secs");
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please wait!");
  lcd.setCursor(0,1);
  lcd.print("1 secs");
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please wait!");
  lcd.setCursor(0,1);
  lcd.print("0 secs");
  delay(1000);

  digitalWrite(GREEN_LED_PIN, LOW);
  lockServo.write(90);                                                                                                                
}