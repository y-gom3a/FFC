#include <Servo.h>   //SERVO LIBRARY

/*PINS CONFIGURATION*/

/*water pump pins*/
#define PUMP 7

/*Right motors*/

#define RIGHT_MOTORS_forward 4
#define RIGHT_MOTORS_backward 5

/*Left motors*/

#define LEFT_MOTORS_forward 8
#define LEFT_MOTORS_backward 9


/*SERVO MOTOR (~)*/
#define servo 3        

/*VARIABLES*/

char reading; //the reading from the controller to the blutooth module 

float pos = 0;  //the angle of the servo motor

Servo gun;      //creating an object for servo motor




/*
the function takes nothing and doesn't return anything
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

turning  the forward relays on -->HIGH: 
pins 4,8

turning all the forward relays off -->LOW: 
pin  5,9 

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

water pump off 

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
F:FORWARD
 
                      ^
(F)  O|     |O  (F)   |
      |     |         |
      |     |         |
(F)  O|     |O  (F)   | 

*/


void forward()
{
  digitalWrite(RIGHT_MOTORS_forward,HIGH);
  digitalWrite(LEFT_MOTORS_forward,HIGH);

  digitalWrite(RIGHT_MOTORS_backward,LOW);
  digitalWrite(LEFT_MOTORS_backward,LOW);

  digitalWrite(PUMP,LOW);
}


/*
the function takes nothing and doesn't return anything
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

turning  the forward relays off -->LOW: 
pins 4,8

turning all the forward relays on -->HIGH: 
pin  5,9 

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

water pump off

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
B:backward
                      
(B)  O|     |O  (B)      |
      |     |            |
      |     |            |
(B)  O|     |O  (B)      | 
                        \ /
*/


void backward()
{
  digitalWrite(RIGHT_MOTORS_forward,LOW);
  digitalWrite(LEFT_MOTORS_forward,LOW);

  digitalWrite(RIGHT_MOTORS_backward,HIGH);
  digitalWrite(LEFT_MOTORS_backward,HIGH);

  digitalWrite(PUMP,LOW);
}



/*
the function takes nothing and doesn't return anything
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

turning  the RIGHT relays off -->LOW: 
pins 4,5

turning all the LEFT relays on -->HIGH: (back)
pin  9 
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

water pump off

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
S:STOP

(B)  O|     |O  (S)      
      |     |            
      |     |            
(B)  O|     |O  (S)       
       \
        \ 
         \
          -->       
*/
void right_backward()
{
  digitalWrite(RIGHT_MOTORS_forward,LOW);
  digitalWrite(LEFT_MOTORS_forward,LOW);

  digitalWrite(RIGHT_MOTORS_backward,LOW);
  digitalWrite(LEFT_MOTORS_backward,HIGH);

  digitalWrite(PUMP,LOW);

}


/*
the function take nothing and doesn't return anything
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

turning  the RIGHT relays off -->LOW: 
pins 4,5

turning all the LEFT relays on -->HIGH: (forward)
pin  8 
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

water pump off

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
S:STOP

           --> 
          / 
         /
        /
       /                
(F)  O|     |O  (S)      
      |     |            
      |     |            
(F)  O|     |O  (S)                    
*/
void right_forward()
{
  digitalWrite(RIGHT_MOTORS_forward,LOW);
  digitalWrite(LEFT_MOTORS_forward,HIGH);

  digitalWrite(RIGHT_MOTORS_backward,LOW);
  digitalWrite(LEFT_MOTORS_backward,LOW);

  digitalWrite(PUMP,LOW);
}

/*
the function take nothing and doesn't return anything
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

turning  the RIGHT relays off -->LOW: 
pins 8,9

turning all the LEFT relays on -->HIGH: (backward)
pin   5
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

water pump off

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
S:STOP        
                       
(S)  O|     |O  (B)      
      |     |            
      |     |            
(S)  O|     |O  (B)
           / 
          /
         /
        /
    <--             
*/
void left_backward() 
{
  digitalWrite(RIGHT_MOTORS_forward,LOW);
  digitalWrite(LEFT_MOTORS_forward,LOW);

  digitalWrite(RIGHT_MOTORS_backward,HIGH);
  digitalWrite(LEFT_MOTORS_backward,LOW);

  digitalWrite(PUMP,LOW);
}

/*
the function take nothing and doesn't return anything
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

turning  the RIGHT relays off -->LOW: 
pins 8,9

turning all the LEFT relays on -->HIGH: (forward)
pin   4
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

water pump off

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

     <--
        \
         \
          \
           \         
(S)  O|     |O  (F)      
      |     |            
      |     |            
(S)  O|     |O  (F)             

*/
void left_forward()
{
  digitalWrite(RIGHT_MOTORS_forward,HIGH);
  digitalWrite(LEFT_MOTORS_forward,LOW);

  digitalWrite(RIGHT_MOTORS_backward,LOW);
  digitalWrite(LEFT_MOTORS_backward,LOW);

  digitalWrite(PUMP,LOW);
}

/*
the function take nothing and doesn't return anything
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
turning  the RIGHT relays on -->LOW: (forward)
pins 4,9

turning all the LEFT relays on -->HIGH: (backward)
pin  5,8
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

water pump off

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  
                           ^ 
 |   (B)  O|     |O  (F)   |      
 |         |     |         |    
 |         |     |         |    
 |   (B)  O|     |O  (F)   |           
\ /  

*/

void rotation_360()
{
  digitalWrite(RIGHT_MOTORS_forward,HIGH);
  digitalWrite(LEFT_MOTORS_forward,LOW);

  digitalWrite(RIGHT_MOTORS_backward,LOW);
  digitalWrite(LEFT_MOTORS_backward,HIGH);

  digitalWrite(PUMP,LOW);
}

/*
the function take nothing and doesn't return anything
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
STOP ALL THE RELAYS
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

water pump off

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>     
                          
    (S)  O|     |O  (S)         
          |     |             
          |     |             
    (S)  O|     |O  (S)              

*/

void stop()
{
  digitalWrite(RIGHT_MOTORS_forward,LOW);
  digitalWrite(LEFT_MOTORS_forward,LOW);

  digitalWrite(RIGHT_MOTORS_backward,LOW);
  digitalWrite(LEFT_MOTORS_backward,LOW);

  digitalWrite(PUMP,LOW);
}
/*
the function take nothing and doesn't return anything
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
trun onn the water pump

*/
void pump()
{
  digitalWrite(RIGHT_MOTORS_forward,LOW);
  digitalWrite(LEFT_MOTORS_forward,LOW);

  digitalWrite(RIGHT_MOTORS_backward,LOW);
  digitalWrite(LEFT_MOTORS_backward,LOW);

  digitalWrite(PUMP,HIGH);
}

void setup()
 {

  Serial.begin(9600);
  gun.attach(servo);
 
 // for loop to define all the pins as an output
  for (int counter=2 ; counter<=12 ; counter++)
  {
    if(counter==4)
    {continue;}
    
    pinMode(counter,OUTPUT);
  }
}

void loop() {

 //to make sure that the arduino received the data

if(Serial.available()>0)
{
  reading = Serial.read();
  /*
  we made a case for each function,
  and to enhance the code response
  we made an while loop in each case
  to make sure that as long as the 
  letter received by arduino it will
  stack in the same function   
  */

switch(reading)
{
  //forward case
  case 'F':
  while(reading=='F')
  {
    reading = Serial.read(); 
   forward();
  }
   break; 
  


  //backward case
  case 'B':
  while(reading=='B')
  {
    reading = Serial.read(); 
   backward();
  }
   break;


  //right_forward case
  case 'R':
  while(reading=='R')
  {
    reading = Serial.read(); 
   right_forward();
  }
   break;
  

  //left forward case
  case 'L':
  while(reading=='L')
  {
   reading = Serial.read(); 
   left_forward();
  }
   break;
  

  //right_backwad case
  case 'r': 
  while(reading=='r')
  {
   reading = Serial.read(); 
   right_backward();
  }
   break;
  

  //left_backward case
   case 'l':
  while(reading=='l')
  {
    reading = Serial.read(); 
   left_backward();
  }
   break;
  

  //pump_on case
  case 'P':
  while(reading=='P')
  {
   reading = Serial.read(); 
   pump();
  }
   break;
  

  //right_direction for the water gun
  case 'D':
  while(reading=='D')
  {
    reading = Serial.read(); 
    pos-=2;
    if (pos<=32.5) {gun.write(147.5);pos=147.5;}
    gun.write(pos); 
    delay(30); 
  }
  

  //left_direction for the water gun
  case 'A':
  while(reading=='A')
  {
    reading = Serial.read(); 
    pos+=2;
    if (pos<=237.5) {gun.write(147.5);pos=147.5;}
    gun.write(pos); 
    delay(30); 
  }
   
  case 'S':
   stop();
   break;
}

}  
}
