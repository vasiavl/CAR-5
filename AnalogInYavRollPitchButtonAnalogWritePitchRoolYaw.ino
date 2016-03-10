
const int analogInYawPin = A0;  // резистор джоя по Yaw
const int analogInRollPin = A2; // резистор джоя по Roll
const int analogInPitchPin = A4; // пин для резистора по Pitch
 #define Button_1      8
 #define Button_2      13
 #define Button_3      12
 #define forward_agoPinR      7// управляет реверсом правого двигателя
 #define forward_agoPinL      6// управляет реверсом левого двигателя
 #define LRPin               5// управляет реверсом мотора руля
 #define analogWritePRYPinR      11// ШИМ на правый ходовой мотор
 #define analogWritePRYPinL      10 // ШИМ на левый  ходовой мотор
#define analogWriteRPin        9  // ШИМ на рулевой мотор 
//const int analogOutPin = 9; // Analog output pin that the LED is attached to
int Yaw = 0;       
int outputYaw = 0;        
int Roll = 0;        
int outputRoll = 0; 
int Pitch = 0;        
int outputPitchR = 0;
int outputPitchL = 0;
int But1=0;
int But2=0;   //20
int But3=0;
int forward=0;
int timeY;
void setup() {
    pinMode(Button_1, INPUT_PULLUP);
    pinMode(Button_2, INPUT_PULLUP);
    pinMode(Button_3, INPUT_PULLUP);
     pinMode(forward_agoPinR, OUTPUT);
  Serial.begin(9600); 
}

void loop() {                               
  // read the analog in value:
  Yaw = analogRead(analogInYawPin); 
  Roll = analogRead(analogInRollPin); 
  Pitch = analogRead(analogInPitchPin); 
  timeY = millis();
  outputYaw = map(Yaw, 0, 1023, 0, 255);  
   outputRoll = map(Roll, 0, 1023, 0, 255);
   
  if (Pitch > 560)
   {   
          if  (560>Roll>460)
           { 
                if ( Yaw>800)
                {       if (HIGH==digitalRead(forward_agoPinR)|| LOW==digitalRead(forward_agoPinL))
                         { digitalWrite(forward_agoPinL , HIGH);
                           digitalWrite(forward_agoPinR , LOW);
                           delay(500);
                         } 
//                     else
                 outputPitchR = map(Pitch, 560, 1023, 0, 255);
                 analogWrite(analogWritePRYPinR, outputPitchR);
                 outputPitchL = map(Pitch, 560, 1023, 0, 255);
                 analogWrite(analogWritePRYPinL, outputPitchL);
                 digitalWrite(forward_agoPinR , HIGH);
                 analogWrite(analogWriteRPin, 0);
                } 
               if ( 800>Yaw>560)
                        if (HIGH==digitalRead(forward_agoPinR)|| LOW==digitalRead(forward_agoPinL))
                         { digitalWrite(forward_agoPinL , HIGH);
                           digitalWrite(forward_agoPinR , LOW);
                           delay(500);
                         }
               {outputPitchR = map(Pitch, 560, 1023, 0, 255);
                analogWrite(analogWritePRYPinR, outputPitchR);
                outputPitchL = map(Pitch, 560, 1023, 0, 255);
                analogWrite(analogWritePRYPinL, outputPitchL);
                analogWrite(analogWriteRPin, 0);
               } 
              if ( 560>Yaw>460)
                        if (HIGH==digitalRead(forward_agoPinR)|| HIGH==digitalRead(forward_agoPinL))
                         { digitalWrite(forward_agoPinL , HIGH);
                           digitalWrite(forward_agoPinR , HIGH);
                           delay(500);
                         }
               {outputPitchR = map(Pitch, 560, 1023, 0, 255);
                analogWrite(analogWritePRYPinR, outputPitchR);
                outputPitchL = map(Pitch, 560, 1023, 0, 255);
                analogWrite(analogWritePRYPinL, outputPitchL);
                analogWrite(analogWriteRPin, 0);
               }
            } 
            if (800>Roll>560)
            {    
              if ( Yaw>800)
               {       if (HIGH==digitalRead(forward_agoPinR)|| HIGH==digitalRead(forward_agoPinL))
                         { digitalWrite(forward_agoPinL , LOW);
                           digitalWrite(forward_agoPinR , LOW);
                           delay(500);
                         } 
                         outputPitchR = map(Pitch, 560, 1023, 0, 155);
                         analogWrite(analogWritePRYPinR, outputPitchR);
                         outputPitchL = map(Pitch, 560, 1023, 0, 255);   //50
                          analogWrite(analogWritePRYPinL, outputPitchL);
                          digitalWrite(LRPin, 0);
                          analogWrite(analogWriteRPin, 255);
               
              if (  millis()-timeY>50)
                 analogWrite(analogWriteRPin, 0);
            }
            if (1023>Roll>800)
            {  outputPitchR = map(Pitch, 560, 1023, 0, 50);
               analogWrite(analogWritePRYPinR, outputPitchR);
               outputPitchL = map(Pitch, 560, 1023, 0, 255);
               analogWrite(analogWritePRYPinL, outputPitchL);
            }
            if  (260>Roll>0)
            { outputPitchR = map(Pitch, 560, 1023, 0, 255);
               analogWrite(analogWritePRYPinR, outputPitchR);
               outputPitchL = map(Pitch, 560, 1023, 0, 50);
               analogWrite(analogWritePRYPinL, outputPitchL);  
            }                                                      //60
            if (460>Roll>260)
            {  outputPitchR = map(Pitch, 560, 1023, 0, 255);
               analogWrite(analogWritePRYPinR, outputPitchR);
               outputPitchL = map(Pitch, 560, 1023, 0, 155);
               analogWrite(analogWritePRYPinL, outputPitchL);
            }
           else
           {  analogWrite(analogWritePRYPinR, 0);
             digitalWrite(forward_agoPinR , LOW);
              analogWrite(analogWritePRYPinL, 0);
              digitalWrite(forward_agoPinL , LOW);
                         delay(500); 
           }
      
  }      
 if (Pitch < 460)
  {   if ( HIGH==digitalRead(forward_agoPinR))
       {   if  (560>Roll>460)
            { outputPitchR = map(Pitch, 560, 1023, 0, 255);
               analogWrite(analogWritePRYPinR, outputPitchR);
               outputPitchL = map(Pitch, 560, 1023, 0, 255);
               analogWrite(analogWritePRYPinL, outputPitchL);
            } 
            if (800>Roll>560)
            {  outputPitchR = map(Pitch, 560, 1023, 0, 155);
               analogWrite(analogWritePRYPinR, outputPitchR);
               outputPitchL = map(Pitch, 560, 1023, 0, 255);   //50
               analogWrite(analogWritePRYPinL, outputPitchL);
            }
            if (1023>Roll>800)
            {  outputPitchR = map(Pitch, 560, 1023, 0, 50);
               analogWrite(analogWritePRYPinR, outputPitchR);
               outputPitchL = map(Pitch, 560, 1023, 0, 255);
               analogWrite(analogWritePRYPinL, outputPitchL);
            }
            if  (260>Roll>0)
            { outputPitchR = map(Pitch, 560, 1023, 0, 255);
               analogWrite(analogWritePRYPinR, outputPitchR);
               outputPitchL = map(Pitch, 560, 1023, 0, 50);
               analogWrite(analogWritePRYPinL, outputPitchL);  
            }                                                      //60
            if (460>Roll>260)
            {  outputPitchR = map(Pitch, 560, 1023, 0, 255);
               analogWrite(analogWritePRYPinR, outputPitchR);
               outputPitchL = map(Pitch, 560, 1023, 0, 155);
               analogWrite(analogWritePRYPinL, outputPitchL);
            }
         else
         { analogWrite(analogWritePRYPinR, 0);
           analogWrite(analogWritePRYPinL, 0);
         } 
       }   }
   But1=    digitalRead(Button_1);
    But2= digitalRead(Button_2);       
    But3=  digitalRead(Button_3);
//    forward=  digitalRead(forward_agoPin);
  /*
  Serial.print("Yaw = " );                       
  Serial.print(Yaw);      
  Serial.print("\t outputYaw = ");      
  Serial.println(outputYaw);  
 Serial.print("Roll = " );                       
  Serial.print(Roll);      
  Serial.print("\t outputRoll = ");      
  Serial.println(outputRoll); */
  Serial.print("Pitch = " );                       
  Serial.print(Pitch);      
  Serial.print("\t outputPitch = ");      
  Serial.println(outputPitchR); 
  Serial.print("\t forward_agoPin = " );                       
  Serial.print(forward); 
  delay(500);                     
}
