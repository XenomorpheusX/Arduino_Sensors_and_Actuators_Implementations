/* 
 *  Photo_Resistor
 *  Dora Avun
 *  02/20/2021
 *  
 *  Inputs a photoresistor (prPin) and reads in the value as maxVal. Then 
 *  inputs a potentiometer (potpin) and reads in the value to potVal. The 
 *  potVal (0 - 1024) is mapped to (0 - maxVal/4) which ensures the extrema 
 *  are 0 and the value read by photoresistor divided by 4 (to not exceed 255).
 *  Prints out the ledVal - the value to be fed into the LED (for checking 
 *  purposes). Finally writes in the ledVal into the LED.
 *  
 */
int prPin=0;   // initialize analog pin 0, connected with photovaristor
int potpin=10; // initialize potenitometer at pin a10.
int ledpin=11; // initialize digital pin 11, output regulating the brightness of LED
int maxVal=0;  // initialize variable maxVal for the value received from the 
               // photoresistor. 
int potVal=0;  // initialize the potentiometer value.

void setup()
{
  pinMode(ledpin, OUTPUT);// set digital pin 11 as “output”
  Serial.begin(9600);     // set baud rate at “9600”
}

void loop()
{
  maxVal = analogRead(prPin);  // read the analog value of the photoresistor and assign it to maxVal
  potVal = analogRead(potpin); // read the analog value of potnetiometer and write it to potVal

  // In the following line, we will map the value of potentiometer (which is 0 - 1024) into 
  // 0 - maxVal/4. maxVal is the value produced by our photoresistor. We cannot exceed this value (255)
  // The mapped value will be initialized as an integer called ledVal.
  
  int ledVal = map(potVal, 0, 1024, 0, maxVal/4);
  
  Serial.println(ledVal);// display the value of ledVal (for checking purposes)
  
  analogWrite(ledpin, ledVal);// turn on the LED and set up brightness with our properly mapped ledVal.
  delay(10);// wait for 0.01
}
