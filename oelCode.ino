#include <SPI.h> 
#include <Wire.h> 
#include <Adafruit_BMP085.h> 
 
int in1 = 8; 
int in2 = 9; 
int ConA = 10; 
 
Adafruit_BMP085 bmp; 
 
void setup() { 
  Serial.begin(9600); 
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT);  
  pinMode(7, OUTPUT); 
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT);  
  pinMode(10, OUTPUT); 
   
  if (!bmp.begin()) { 
    Serial.println("Could not find a valid BMP085 sensor, check wiring!"); 
    while (1) {} 
  } 
} 
 
void TurnMotor(int power) { 
  digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH); 
  analogWrite(ConA, power); 
} 
 
void loop() { 
    int temp = bmp.readTemperature(); 
    Serial.println(temp); 
 
    if (temp > 30) { 
      digitalWrite(5, HIGH); 
      digitalWrite(6, LOW); 
      digitalWrite(7, LOW); 
 
      int motorSpeed = map(temp, 30, 35, 250, 250); 
      // Adjust the upper temperature limit as needed 
       
      TurnMotor(motorSpeed); 
      Serial.println(motorSpeed); 
    } 
    else if (temp >= 25 && temp <= 30) { 
      digitalWrite(5, LOW); 
      digitalWrite(6, HIGH); 
      digitalWrite(7, LOW); 
 
      int motorSpeed = map(temp, 25, 30, 150, 200);  
      // Adjust the temperature range and speed values as needed 
       
      TurnMotor(motorSpeed); 
      Serial.println(motorSpeed); 
    } 
    else if (temp < 25) { 
      digitalWrite(5, LOW); 
      digitalWrite(6, LOW); 
      digitalWrite(7, HIGH); 
 
      int motorSpeed = map(temp, 20, 25, 100, 100);  
      // Adjust the lower temperature limit as needed 
       
      TurnMotor(motorSpeed); 
      Serial.println(motorSpeed); 
    } 
} 
