#include <Servo.h>

Servo servo;
int angle = 10;
int incomingByte = 0; // for incoming serial data

void setup() {
  servo.attach(8);
  servo.write(angle);
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  // New Command
  Serial.println("'+' => angle+ ; '-' => angle- ; '0' => angle = 0° ; '5' => angle = 90° ; '8' => angle = 180° ");
}


void loop() 
{ 
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    if (incomingByte == '+'){
      angle = angle + 10 ; 
      if (angle >= 180){angle = 179;}
    }
    else if(incomingByte == '-'){
      angle = angle - 10 ; 
      if (angle <= 10){angle = 10;}
    }
    else if(incomingByte == '0'){
      angle = 0 ; 
    }
    else if(incomingByte == '5'){
      angle = 90 ; 
    }
    else if(incomingByte == '8'){
      angle = 180 ; 
    }
    
    // Output new Command:
    servo.write(angle);
    Serial.print("angle: ");
    Serial.println(angle, DEC);

    // New Command
    Serial.println("'+' => angle+ ; '-' => angle- ; '0' => angle = 0° ; '5' => angle = 90° ; '8' => angle = 180° ");
    
  }
  delay(15); 

} 
