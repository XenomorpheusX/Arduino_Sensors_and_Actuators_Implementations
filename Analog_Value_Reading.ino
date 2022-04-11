/* 
 *  Analog_Value_Reading
 *  Dora Avun
 *  03/12/2021
 *  
 *  Inputs a potentiometer and reads in the values,and lights up
 *  3 separate LED's according to this value. (Red, Yellow and Blue).
 *  Red <= 340, 340 < Yellow <= 680, 680 < Blue.
 *  
 */
int potpin=0;     // initialize analog pin 0 for potentiometer
int redLED = 10;  // initialize digital pin 10 for red LED
int yellowLED = 9;// initialize digital pin 9 for yellow LED
int blueLED = 8;  // initialize digital pin 8 for blue LED
int val=0;        // define val, assign initial value 0

void setup()
{
  pinMode(redLED,OUTPUT);   // set digital pin 10 as “output”
  pinMode(yellowLED,OUTPUT);// set digital pin 9 as “output”
  pinMode(blueLED,OUTPUT);  // set digital pin 8 as “output”
  Serial.begin(9600);       // set baud rate at 9600
}

void loop()
{
  val=analogRead(potpin);// read the analog value of analog pin 0, and assign it to val 
  Serial.println(val);   // display val’s value

  if (val <= 340) //if value is less than or equal to 340, only red LED is on.
  {
    digitalWrite (redLED, HIGH);
    digitalWrite (yellowLED, LOW);
    digitalWrite (blueLED, LOW);
    
  }
  else if (val <= 680) //if value is between 340 - 680, only yellow LED is on.
  {
    digitalWrite (redLED, LOW);
    digitalWrite (yellowLED, HIGH);
    digitalWrite (blueLED, LOW);
  }
  else //if valuegreater than 680, only blue LED is on.
  {
    digitalWrite (redLED, LOW);
    digitalWrite (yellowLED, LOW);
    digitalWrite (blueLED, HIGH);
  }
}
