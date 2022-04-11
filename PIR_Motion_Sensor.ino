/* 
 *  PIR_Motion_Sensor
 *  Dora Avun
 *  04/10/2021
 *  
 *  A Pyroelectric infrared motion sensor is connected to
 *  the circuit, which detects motion within a 100 degree
 *  angle and 7 ft distance (7.2 ft and around 120 degrees 
 *  were my experimental results). An output red LED is also
 *  in circuit which lights up when an object is detected.
 *  
 */
byte sensorPin = 3;  //sensor is initialized at pin 3.
byte indicator = 13; //this is to light up the integrated LED.
int redLED = 10;     //red LED is initialized at pin 10.
void setup()
{
  pinMode(redLED, OUTPUT);   // set digital pin 10 as “output”
  pinMode(sensorPin,INPUT);  // sensor set as input
  pinMode(indicator,OUTPUT); //indicator set as output.
  Serial.begin(9600);
}

void loop()
{
  byte state = digitalRead(sensorPin); //state is output from sensor
                                       //'0' or '1'.
  digitalWrite(indicator,state); //write the state to the led.
  if(state == 1)
  {
    Serial.println("Somebody is in this area!");
    digitalWrite (redLED, HIGH); //light up the red LED
  }
  else
  {
    Serial.println("No one!");
    digitalWrite (redLED, LOW); //Turn off the red LED   
  }
  delay(500); //wait for 500 ms.
}
