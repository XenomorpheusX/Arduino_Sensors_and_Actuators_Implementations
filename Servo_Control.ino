/* 
 *  Servo_Control
 *  Dora Avun
 *  03/28/2021
 *  
 *  Move servo with determined potentiometer levels. Total
 *  potentiometer input is divided to 10 levels each incrementing
 *  the servo angle by 20, up to 180 degrees.
 */
int servopin=9; // select digital pin 9 for servomotor signal line
int myangle;    // initialize angle variable
int pulsewidth; // initialize width variable
int potpin=0;   // initialize analog pin 0 for potentiometer
int val = 0;    //value for inputting servo
int potVal = 0; //potentiometer at A0.
void servopulse(int servopin,int myangle)// define a servo pulse function
{
  pulsewidth=(myangle*11)+500;  // convert angle to 500-2480 pulse width
  digitalWrite(servopin,HIGH);  // set the level of servo pin as “high”
  delayMicroseconds(pulsewidth);// delay microsecond of pulse width
  digitalWrite(servopin,LOW);   // set the level of servo pin as “low”
  delay(20-pulsewidth/1000);
}
void setup()
{
  pinMode(servopin,OUTPUT);// set servo pin as “output”
  Serial.begin(9600);      // connect to serial port, set baud rate at “9600”
  Serial.println("servo=o_seral_simple ready" ) ;
}
void loop()// convert potVal into levels (0-9) which are converted into angles (0-180).
{
  potVal=analogRead(potpin);// read the analog value of analog pin 0, and assign it to val 
  //deternube levels of val from potVal.
  if (potVal <= 102)
    val = 0;
  else if (potVal <= 204)
    val = 1;
  else if (potVal <= 306)
    val = 2;
  else if (potVal <= 408)
    val = 3;
  else if (potVal <= 510)
    val = 4;
  else if (potVal <= 612)
    val = 5;
  else if (potVal <= 714)
    val = 6;
  else if (potVal <= 816)
    val = 7;
  else if (potVal <= 918)
    val = 8;
  else
    val = 9;
  //Create a compact string to print potentiometer values.
  char str0[30];
  sprintf(str0, "Potentiometer value: %d(%u)", potVal, val);
  Serial.println(str0);

  val=val*(180/9);// convert number to angle
  //Create a compact string to print angle values.
  char str1[30];
  sprintf(str1, "Moving to angle: %d", val);
  Serial.println(str1);

  for(int i=0;i<=50;i++) // giving the servo time to rotate to commanded position
    {
      servopulse(servopin,val);// use the pulse function
    }
}
