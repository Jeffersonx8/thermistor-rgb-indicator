unsigned long beginSerial = 0; 
unsigned long beginLED = 0;    //unused for RGB version
int interval = 1000;
int LED = LOW;                 //unused for RGB version
void setup()
{
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(A5, INPUT);
  Serial.begin(9600);
  
}
//Room temp units = 465.532 truncated to 465
void loop()
{
  unsigned long current = millis();
  float temp_Units = analogRead(A5);
  float temp_Volts = analogRead(A5)*.0049;
  float therm_resist = -(10000.00*temp_Volts / 5.00)/(temp_Volts/5.00 -1.00);
  float temp = (1.00/(log(therm_resist/10000.00)/3950.00 + (1.00/298.15))) - 273;
  
  String str = "Temp: ";
  if(current - beginSerial >=interval){
    Serial.println(therm_resist);
    Serial.println(temp_Volts);
    Serial.println(str + temp);
    beginSerial = beginSerial + interval;
  }
  //range is from 20C - 35C, room temp is somewhere in middle
  float red = 255 - (((temp_Units-402.08)/165.58)*255);
  float blue = ((temp_Units-402.08)/165.58)*255;
  if(blue>255){
    blue = 255;
  }
  else if (blue<0){
    blue = 0;
  }
  if(red>255){
    red = 255;
  }
  else if (red<0){
    red = 0;
  }
  analogWrite(3, red);
  analogWrite(5, blue);
}


//INITIAL RED LED BLINKING/STEADY CODE:
// if(temp_Units>=465){//465 units
//     if(current - beginLED >= interval){
// 		digitalWrite(7,LED);
//       beginLED = current;
//       if(LED == HIGH){
//       	LED = LOW;
//       }
//       else if(LED == LOW){
//     	LED = HIGH;
//       }
      
//     }
//   }
//   else if(temp_Units<465){
//     digitalWrite(7, HIGH);
//   }
