# Microprocessor-Embedded-System
It is a open ended lab performance I had done along with my groupmates named 'Temperature Dependent Motor Control'. The main purpose of this experiment is to adjust the speed of a motor according to the temperature. If the temperature is high, motor speed will increase and if temperature is low, motor speed will decrease.
# Apparatus
Arduino UNO, LED Indicators (3 pieces - Red, Yellow, and Green), Temperature Sensor, Breadboard, DC Motor, H-bridge Motor Driver, 1 KΩ Resistors (3 pieces), Connecting Wires 
# Experimental Set-up
![image](https://github.com/Srabone/Microprocessor-Embedded-System/assets/95047190/01942437-f9a7-44cd-8855-b9d424de3a01)
![image](https://github.com/Srabone/Microprocessor-Embedded-System/assets/95047190/5ecce2aa-d4c8-4b13-925c-fce1d40aa479)
# Simulation
![image](https://github.com/Srabone/Microprocessor-Embedded-System/assets/95047190/846b2b22-fc88-4f39-b135-c43366d0bc25)
![image](https://github.com/Srabone/Microprocessor-Embedded-System/assets/95047190/329d4e53-449d-4e46-ac62-8d6e4a089a46)
![image](https://github.com/Srabone/Microprocessor-Embedded-System/assets/95047190/39472765-bec8-4b34-8a07-e556f891e184)
# Code of the Program
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

# Data and analysis
![image](https://github.com/Srabone/Microprocessor-Embedded-System/assets/95047190/f4ae1692-130a-4412-b629-fce1781369df)
