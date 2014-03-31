// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
    // initialize serial:
  Serial.begin(9600);
} 
 
 
void loop() 
{
  if (Serial.available())
  {
   pos = Serial.parseInt();  
   if (pos > 0 && pos < 180)
   {
     Serial.println(pos);
     myservo.write(pos);

   } 
  } 
}


