#include <Servo.h>
Servo myservo1;
Servo myservo2;
int pos1= 90; // initial position servo 1
int pos2= 90; //intial posioton servo 2
int sens1 = A0; // LRD 1 pin
int sens2 = A1; //LDR 2 pin
int sens3 = A2; //lLDR3 pin
int sens4 = A3; //ldr4 pin
int tolerance = 10;
void setup()
{
 myservo1.attach(9); // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);
   pinMode(sens1, INPUT);
    pinMode(sens2, INPUT);
     pinMode(sens3, INPUT);
      pinMode(sens4, INPUT);
       myservo1.write(pos1);
        myservo2.write(pos2);
         delay(2000); // a 2 seconds delay while we position the solar panel
         }
         void loop()
         {
          int val1 = analogRead(sens1); // read the value of sensor 1
           int val2 = analogRead(sens2); // read the value of sensor 2
            int val3 = analogRead(sens3); // read the value of sensor 3
             int val4 = analogRead(sens4); // read the value of sensor 4
             if((abs(val1 - val2) <= tolerance) || (abs(val2 - val1) <= tolerance))
              {
                }
                else {
                if(val1 > val2)
                 {
                  pos1 = --pos1;
                   }
                    if(val1 < val2)
                     {
                      pos1= ++pos1;
                       }
                        }
                         if(pos1 > 180)
                          { 
                           pos1 = 180;
                            } // reset to 180 if it goes higher
                             if(pos1 < 0) 
                              { 
                                pos1 = 0; 
                                  } // reset to 0 if it goes lower
                                  if((abs(val3 - val4) <= tolerance) || (abs(val4 - val3) <= tolerance))
                                   { 
                                    } 
                                      else {
                                       if(val3 > val4)
                                        {
                                         pos2 = --pos2;
                                          }
                                           if(val3 < val4)
                                            {
                                             pos2 = ++pos2;
                                              }
                                                }
                                                if(pos2 > 180) { pos2 = 180; } // reset to 180 if it goes higher
                                                 if(pos2 < 0) { pos2 = 0; } // reset to 0 if it goes lower
                                                  myservo1.write(pos1); // write the position1 to servo1
                                                  myservo2.write(pos2); //write the position2 to servo2
                                                    delay(30);
         }
                                                     
