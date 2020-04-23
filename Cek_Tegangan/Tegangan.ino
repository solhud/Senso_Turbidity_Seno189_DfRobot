#include <Wire.h>  //library untuk memulai komunikasi I2C 
#include <LiquidCrystal_I2C.h> //library untuk LCD  
LiquidCrystal_I2C lcd(0x27, 16, 2); //mengatur alamat untuk LCD 16x2 

void setup() {
  lcd.init(); //memulai LCD 
  lcd.backlight(); //menyalakan atau mematikan lampu backlight pada LCD 
  Serial.begin(9600); //Baud rate: 9600
    
}
void loop() {
  int sensorValue = analogRead(A0);// read the input on analog pin 0:
  float voltage = sensorValue * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  Serial.println(voltage); // print out the value you read:
  lcd.print(voltage);
  delay(5000);
  
}
