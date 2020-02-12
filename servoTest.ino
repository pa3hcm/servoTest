/*
  Project:   servoTest
  Source:    http://github.com/pa3hcm/servoTest
  Author:    Ernest Neijenhuis
*/


/////////////////////////////////////////////////////////////////////////
// Constants

const char VERSION[6] = "v1.00";

// Pin labels
const int P_SERVO  =  3; // Connect to the PWM pin of the servo
const int P_POT    =  A0; // Connect to potmeter to set the degrees

// LCD settings
const int LCD_ROWS    = 2;    // Number of display rows
const int LCD_COLS    = 16;   // Number of display columns
const int LCD_I2CADDR = 0x27; // I2C address, in most cases this is 0x27


/////////////////////////////////////////////////////////////////////////
// Global variables

// none so far...


/////////////////////////////////////////////////////////////////////////
// Libraries

// LiquidCrystal_I2C source & info:
// https://github.com/johnrickman/LiquidCrystal_I2C
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(LCD_I2CADDR, LCD_COLS, LCD_ROWS);
// Note: If this library is not satisfying, maybe try this one instead:
// https://github.com/mathertel/LiquidCrystal_PCF8574

// Arduino default Servo library
#include <Servo.h>
Servo myservo;


/////////////////////////////////////////////////////////////////////////
// setup() routine

void setup() {
  pinMode(P_POT, INPUT);
  myservo.attach(P_SERVO);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("servoTest ");
  lcd.print(VERSION);
  lcd.setCursor(1, 1);
  lcd.print("(C)2020 PA3HCM");
  delay(1000);
  lcd.clear();
}


/////////////////////////////////////////////////////////////////////////
// Main loop()

void loop() {
  char angleStr[4];
  char pulseStr[5];

  int pot = analogRead(P_POT);
  //Serial.print("Pot: ");
  //Serial.println(pot);
  long angle = map(pot, 0, 683, 0, 190);
  long pulse = (angle * 1000 / 180) + 1000;
  
  dtostrf(angle, 3, 0, angleStr);
  dtostrf(pulse, 4, 0, pulseStr);

  myservo.write(angle);

  lcd.setCursor(0, 0);
  lcd.print("Angle:  ");
  lcd.print(angleStr);
  lcd.print((char)223);
  lcd.setCursor(0, 1);
  lcd.print("Pulse: ");
  lcd.print(pulseStr);
  lcd.print((char)228);
  lcd.print("s");
  
  //delay(100);
}
