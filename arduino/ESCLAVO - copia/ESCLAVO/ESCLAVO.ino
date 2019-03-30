#include <AFMotor.h>
#include<Servo.h>
Servo servo1;

AF_DCMotor motori(1);
AF_DCMotor motord(2);


int led = 13;  // usamos un pin de salida al LED
int DATO = 0;      // Variable lectrura serial
  
void setup() {
    pinMode(led, OUTPUT);
    
    Serial.begin(9700);

    servo1.attach(10);
    
}
  
void loop() {
if (Serial.available())
{ 
  DATO=Serial.read();
   if(DATO== '1'){
         servo1.write(115);
         motori.setSpeed(200);
         motord.setSpeed(200);
         motori.run(FORWARD);
         motord.run(FORWARD);
    }
  
   if(DATO== '2'){
         servo1.write(90);
         motori.setSpeed(200);
         motord.setSpeed(200);
         motori.run(FORWARD);
         motord.run(FORWARD);
         
    }
    if(DATO== '3'){
         servo1.write(65);
         motori.setSpeed(200);
         motord.setSpeed(200);
         motori.run(FORWARD);
         motord.run(FORWARD);
         
    }
    if(DATO== '4'){
         servo1.write(115);
         motori.setSpeed(200);
         motord.setSpeed(200);
         motori.run(RELEASE);
         motord.run(RELEASE);
         
    }
    if(DATO== '5'){
         servo1.write(90);
         motori.setSpeed(200);
         motord.setSpeed(200);
         motori.run(RELEASE);
         motord.run(RELEASE);
         
    }
    else if(DATO== '6'){
         servo1.write(65);
         motori.setSpeed(200);
         motord.setSpeed(200);
         motori.run(RELEASE);
         motord.run(RELEASE);
         
    }
    if(DATO== '7'){
         servo1.write(115);
         motori.setSpeed(200);
         motord.setSpeed(200);
         motori.run(BACKWARD);
         motord.run(BACKWARD);
         
    }
    else if(DATO== '8'){
         servo1.write(90);
         motori.setSpeed(200);
         motord.setSpeed(200);
         motori.run(BACKWARD);
         motord.run(BACKWARD);
         
    }
    if(DATO== '9'){
         servo1.write(65);
         motori.setSpeed(200);
         motord.setSpeed(200);
         motori.run(BACKWARD);
         motord.run(BACKWARD);
    }
  }
}
