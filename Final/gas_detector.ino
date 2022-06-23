//Name:Akshay Jayeshbhai Patel
//Date: 21 APRIL 2021 
//Description: gas detector alarm with lcd
//Recieve help from https://create.arduino.cc/projecthub/embeddedlab786/smoke-and-gas-leakage-detector-6a2f9a



#include<LiquidCrystal.h>
//initialise the serial LCD
LiquidCrystal lcd(12,11,5,4,3,2);//These pin numbers are hard coded in on the serial backpack board.
int GreenLed = 8;//The Green LED is connected to pin 8 of the Arduino.
int RedLed = 9;//The Red LED is connected to pin 9 of the Arduino.
int buzzer = 7;//The BuzzEr is connected to pin 7 of the Arduino.
int sensor = A5;//The sensor is connected to pin A5 of the Arduino.

void setup()
{
  	pinMode(GreenLed,OUTPUT);//Setup Green LED pin as an output pin.
  	pinMode(RedLed, OUTPUT);//Setup Red LED pin as an output pin.
	pinMode(buzzer,OUTPUT);//Setup buzzer pin as an output pin.
	pinMode(sensor,INPUT);//Setup sensor pin as an output pin.
	Serial.begin(9600);
	lcd.begin(16,2);// Initialize the LCD.
}
void loop()
{
  if(digitalRead(sensor)==HIGH)
  {
    //Turn on the Red LED
    digitalWrite(RedLed,HIGH);
    
    //Turn off the Green LED.
    digitalWrite(GreenLed,LOW);
    tone(buzzer,1000,500);
    
    //clearing the LCD screen
    lcd.clear();
    
    //goto first column and first line(0,0)
    lcd.setCursor(0,0);
    
    //Print at cursor Location
    lcd.print("ALERT");
    
    // Wait for 500 millisecond(s)
    delay(500);
    
    //clearing the LCD screen
    lcd.clear();
    
    //goto first column and second line(0,1)
    lcd.setCursor(0,1);
    
    //Print at cursor Location
    lcd.print("GAS DETECTED");
    
    // Wait for 500 millisecond(s)
    delay(500); 
    
  }
  else
  {
    //Turn on the Green LED.
    digitalWrite(GreenLed,HIGH);
    
    //Turn off the Red LED
    digitalWrite(RedLed,LOW);
    noTone(buzzer);
    
    //clearing the LCD screen
    lcd.clear();
    
    //goto first column and first line(0,0)
    lcd.setCursor(0,0);
    
    //Print at cursor Location
    lcd.print("SAFE");
    
    // Wait for 500 millisecond(s)
    delay(500);
    
    //clearing the LCD screen
    lcd.clear();
    
    //goto first column and second line(0,1)
    lcd.setCursor(0,1);
    
    //Print at cursor Location
    lcd.print("NO GAS DETECTED");
    
    // Wait for 500 millisecond(s)
    delay(500);
  }  
}