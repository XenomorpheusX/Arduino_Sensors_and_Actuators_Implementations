/* 
 *  Simple_Switch
 *  Dora Avun
 *  02/01/2021
 *  
 *  If button is pressed, light up the RED LED, otherwise,
 *  light up the Green LED.
 *  
 */
int ledpin=11;// initialize pin 11
int greenpin=3;// initialize pin 3 for green LED
int inpin=7;// initialize pin 7
int val;// define val
int wait = 1000; //how many milliseconds to wait before stopping led's
bool enableRelease = false; // initial boolean condition to stop green LED from running when button is not pressed.
int delayMultiplier = 1; //each run, delayMultiplier is multiplied with wait to increase delay time. Incremented each loop.
void setup()
{
pinMode(ledpin,OUTPUT);// set LED pin as “output”
pinMode(greenpin,OUTPUT); // set green LED pin as output
pinMode(inpin,INPUT);// set button pin as “input”

}
void loop()
{
val=digitalRead(inpin);// read the level value of pin 7 and assign if to val

if(val==HIGH && delayMultiplier <= 5) //if button is pressed and delayMultiplier doesn't exceed 5...
  {
    digitalWrite(ledpin, HIGH); //turn on red LED
    delay (wait * delayMultiplier); //wait for 1 seconds * delayMultiplier
    digitalWrite(ledpin, LOW); //turn off red LED
    enableRelease = true; //Release is now enabled and when button is pressed, green LED can be activated.
  }
  else //if button is not pressed
  {
    if (enableRelease == true) //if enableRelease condition is true
    {
      digitalWrite(greenpin, HIGH); //turn on green LED
      delay (wait * delayMultiplier); //
      digitalWrite(greenpin, LOW); //wait for 1 seconds * delayMultiplier
      enableRelease = false; //enableRelease is now false to keep green LED from running infinitely. Can be reset to true if button is repressed.
      delayMultiplier ++; //the delay times will now be multiplied by an increment of delayMultiplier.
    }
  }
  
 }
