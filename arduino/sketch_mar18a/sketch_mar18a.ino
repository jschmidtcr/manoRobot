// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo[5];  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
int cualDedo = 0;
 
void setup() 
{ 
  myservo[0].attach(5);  // attaches the servo on pin 9 to the servo object 
    myservo[1].attach(6);  // attaches the servo on pin 9 to the servo object 
      myservo[2].attach(9);  // attaches the servo on pin 9 to the servo object 
        myservo[3].attach(10);  // attaches the servo on pin 9 to the servo object 
          myservo[4].attach(11);  // attaches the servo on pin 9 to the servo object 
    // initialize serial:
  Serial.begin(9600);
} 
 
 
void loop() 
{
  if (Serial.available())
  {
   
   cualDedo = Serial.parseInt(); 
   if(cualDedo > -1 && cualDedo < 5){
     pos = Serial.parseInt();  
     Serial.print("dedo" );
     Serial.println(cualDedo);
     if (pos < 1) pos = 1;
     else if(pos > 90) pos = 90;
    
     Serial.println(pos);
     myservo[cualDedo].write(pos);
   }
   else
     Serial.println("dedo invalido");
  }
}


