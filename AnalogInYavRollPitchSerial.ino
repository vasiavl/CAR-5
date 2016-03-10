
const int analogInYawPin = A0;  
const int analogInRollPin = A2; 
const int analogInPitchPin = A4; 
//const int analogOutPin = 9; // Analog output pin that the LED is attached to
int Yaw = 0;       // value read from the pot
int outputYaw = 0;        // value output to the PWM (analog out)
int Roll = 0;        
int outputRoll = 0; 
int Pitch = 0;        
int outputPitch = 0;
// #define LEFT_LED      13
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  // read the analog in value:
  Yaw = analogRead(analogInYawPin); 
  Roll = analogRead(analogInRollPin); 
  Pitch = analogRead(analogInPitchPin); 
  // map it to the range of the analog out:
  outputYaw = map(Yaw, 0, 1023, 0, 255);  
   outputRoll = map(Roll, 0, 1023, 0, 255);
   outputPitch = map(Pitch, 0, 1023, 0, 255);
  // change the analog out value:
  //analogWrite(analogOutPin, outputValue);           

  // print the results to the serial monitor:
  Serial.print("Yaw = " );                       
  Serial.print(Yaw);      
  Serial.print("\t outputYaw = ");      
  Serial.println(outputYaw);  
 Serial.print("Roll = " );                       
  Serial.print(Roll);      
  Serial.print("\t outputRoll = ");      
  Serial.println(outputRoll); 
  Serial.print("Pitch = " );                       
  Serial.print(Pitch);      
  Serial.print("\t outputPitch = ");      
  Serial.println(outputPitch); 
 
  delay(1000);                     
}
