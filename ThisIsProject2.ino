// Toff Nguyen Project 2
//  RGB LED connected to pins 12, 27, 33

 #include <analogWrite.h>
 
// the numbers of the LED pins
const int RedLED = 12;  
const int GreenLED = 27;  
const int BlueLED = 33;  

const int LDR = A0;  
const int POT = A1;  

int LDRval = 0;
int POTval= 0;

int delaytime = 5;
int redBrightness = 0;
int greenBrightness = 0;
int blueBrightness = 0;
 
void setup(){
  Serial.begin(9600);

  pinMode(POT, INPUT);
  pinMode(LDR, INPUT);
    
  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(BlueLED, OUTPUT);
}
 
void loop(){

    LDRval = analogRead(LDR);
    Serial.print("LDRval: ");
    Serial.print(LDRval);
    
    POTval = analogRead(POT);   
    Serial.print("\t POTval: ");
    Serial.println(POTval);

      redBrightness = map(POTval, 0, 4095, 0, 255);
      analogWrite(RedLED, redBrightness);
    
      greenBrightness = 255-redBrightness;
      analogWrite(GreenLED, greenBrightness);


    if (LDRval < 700 && greenBrightness > redBrightness )
    {
        analogWrite(GreenLED, LOW);
        analogWrite(RedLED, 255);
        if (LDRval <500)
        {
          analogWrite(RedLED, 5);
          analogWrite(RedLED, 255);
        }
    }
    else if (LDRval < 700 && greenBrightness < redBrightness )
    {
        analogWrite(RedLED, LOW);
        analogWrite(GreenLED, 255);
        if (LDRval <500)
        {
          analogWrite(GreenLED, 5);
          analogWrite(GreenLED, 255);
        }
    }

}
