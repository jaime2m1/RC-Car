#include <SoftwareSerial.h>


// assign pin num
// duration for output

int time = 50;
// initial command
int command = 0;
SoftwareSerial mySerial(2, 3);
void setup() {
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  Serial.begin(115200);
  mySerial.begin(9600);
}

void loop() {
  digitalWrite(12,HIGH);
  digitalWrite(11,LOW);
  //receive command
  if (Serial.available() > 0){
    command = Serial.read();
  }
  else{
    reset();
  }
   send_command(command,time);
}

void right(int time){
  mySerial.write('6');
  delay(time);
}

void left(int time){
  mySerial.write('4');
  delay(time);
}

void forward(int time){
  mySerial.write('2');
  delay(time);
}

void reverse(int time){
  mySerial.write('8');
  delay(time);
}

void forward_right(int time){
  mySerial.write('3');
  delay(time);
}

void reverse_right(int time){
  mySerial.write('9');
  delay(time);
}

void forward_left(int time){
  mySerial.write('1');
  delay(time);
}

void reverse_left(int time){
  mySerial.write('7');
  delay(time);
}

void reset(){
  mySerial.write('5');
}

void send_command(int command, int time){
  switch (command){

     //reset command
     case 0: reset(); break;

     // single command
     case 1: forward(time); break;
     case 2: reverse(time); break;
     case 3: right(time); break;
     case 4: left(time); break;

     //combination command
     case 6: forward_right(time); break;
     case 7: forward_left(time); break;
     case 8: reverse_right(time); break;
     case 9: reverse_left(time); break;

     default: Serial.print("Inalid Command\n");
    }
}
