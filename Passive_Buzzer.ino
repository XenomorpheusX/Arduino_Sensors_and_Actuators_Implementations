/* 
 *  Passive_Buzzer
 *  Dora Avun
 *  02/06/2021
 *  
 *  Inputs a potentiometer and reads in the values, which are then mapped 
 *  to frequencies 60Hz - 10KHz. The frequency values are printed and sent 
 *  to buzzer to produce corresponding frequencies.
 *  
 */
int buzzer=8;// select digital IO pin for the buzzer
int potpin = 0; // initialize potentiometer at pin A0
int val=0; // this will be our value received from potentiometer.
void setup() 
{ 
  pinMode(buzzer,OUTPUT);// set digital IO pin pattern, OUTPUT to be output 
  Serial.begin(9600);// setting the initial BAUD rate to 9600.
} 
void loop() 
{ 
  val = analogRead(potpin); //assigns potentiometer value to int val.

  // int frequency is our frequency value which is produced by mapping the 
  //  potentiometer value of range 0-1024 to 60Hz - 10000Hz. So, our extremes
  //  for frequency will be 60Hz and 10KHz.
  
  int frequency = map(val, 0, 1024, 60, 10000); 
 
  //printing out the frequency value to serial monitor.
  Serial.println(String("Frequency is ") + frequency + " Hz."); 
    
 // I used tone() function to generate frequency of sounds 
 // with my buzzer
  tone(buzzer, frequency); //tone function 
}
