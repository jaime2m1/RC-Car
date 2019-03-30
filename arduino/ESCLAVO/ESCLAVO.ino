#include <AFMotor.h>

AF_DCMotor motori(1);
AF_DCMotor motord(2);


int led = 13;  // usamos un pin de salida al LED
int DATO = 0;      // Variable lectrura serial
  
void setup() {
    pinMode(led, OUTPUT);
    
    Serial.begin(9600);
    
}
  
void loop() {
if (Serial.available())
{ 
  DATO=Serial.read();
   if(DATO== '1'){
         motori.setSpeed(200);
         motord.setSpeed(200);
         motori.run(RELEASE);
         motord.run(FORWARD);
    }
  
   if(DATO== '2'){
         motori.setSpeed(200);
         motord.setSpeed(200);
         motori.run(FORWARD);
         motord.run(FORWARD);
         
    }
    if(DATO== '3'){
         motori.setSpeed(200);
         motord.setSpeed(200);
         motori.run(FORWARD);
         motord.run(RELEASE);
         
    }
    if(DATO== '4'){
         motori.setSpeed(200);
         motord.setSpeed(200);
         motori.run(BACKWARD);
         motord.run(FORWARD);
         
    }
    if(DATO== '5'){
         motori.setSpeed(200);
         motord.setSpeed(200);
         motori.run(RELEASE);
         motord.run(RELEASE);
         
    }
    else if(DATO== '6'){
         motori.setSpeed(200);
         motord.setSpeed(200);
         motori.run(FORWARD);
         motord.run(BACKWARD);
         
    }
    if(DATO== '7'){
         motori.setSpeed(200);
         motord.setSpeed(200);
         motori.run(RELEASE);
         motord.run(BACKWARD);
         
    }
    else if(DATO== '8'){
         motori.setSpeed(200);
         motord.setSpeed(200);
         motori.run(BACKWARD);
         motord.run(BACKWARD);
         
    }
    if(DATO== '9'){
         motori.setSpeed(200);
         motord.setSpeed(200);
         motori.run(BACKWARD);
         motord.run(RELEASE);
    }
  }
}
