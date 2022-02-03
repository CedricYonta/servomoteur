#include <Arduino.h>
#include <Servo.h>

/*
  # Description:
  # When you push the digital button, the Led 13 on the board will turn off. Otherwise,the led turns on.
*/






Servo myservo;
int ledPin = 10;
int inputPin = 7;              
int inputPin2 = 6;
int pos = 90;;


void setup() {
  myservo.attach(9);
  

  pinMode(inputPin, INPUT);    




 
}

void loop(){
  
  int valRed = digitalRead(inputPin);  // read input value
  int valWhite = digitalRead(inputPin2); 
    
  if(valRed == HIGH ) {            // check if the input is HIGH
            pos += 1;
            myservo.write(pos);
            delay(15);
            pos += 1;

          int servoAngle = myservo.read();
            Serial.println(servoAngle);
          if (valRed == HIGH &&  servoAngle == 180){
                tone(8, 300,500);


                delay(100);

                noTone(8);

        }
    }         
        
    
    
  
  
  if (valWhite == HIGH ) {            // check if the input is HIGH
         pos -= 1;
        myservo.write(pos);
        delay(15);
         
      int servoAngle = myservo.read();
       Serial.println(servoAngle);
      if (valWhite == HIGH &&  servoAngle == 0){
        tone(8, 300,500);


              delay(100);

          noTone(8);

       }
          
  }
  
 
  
  
  
  
}
