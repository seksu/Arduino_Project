#include <Wire.h>
#include <ACROBOTIC_SSD1306.h>
String output[8];
void setup()
{
  Serial.begin(115200);
  Wire.begin();	
  oled.init();                      // Initialze SSD1306 OLED display
  oled.clearDisplay();              // Clear screen
  oled.setTextXY(0,0);              
  oled.putString("line1");
    oled.setTextXY(1,0);              
  oled.putString("line2");
    oled.setTextXY(2,0);              
  oled.putString("line3");
    oled.setTextXY(3,0);              
  oled.putString("line4");
    oled.setTextXY(4,0);              
  oled.putString("line5");
    oled.setTextXY(5,0);              
  oled.putString("line6");
    oled.setTextXY(6,0);              
  oled.putString("line7");
    oled.setTextXY(7,0);              
  oled.putString("line8");

}

void loop()
{
  if(Serial.available()){
    String input = Serial.readStringUntil('\n');
    Serial.println(input.length());
    for(int i=0 ; i<30-input.length() ; i++){
      input += " ";
    }
    for(int i=7 ; i>0 ; i--){
      output[i] = output[i-1];
    }
    output[0] = input;
    printOled();
  }
}
void printOled(){
  for(int i=0 ; i<8 ; i++){
      oled.setTextXY(i,0);              
      oled.putString(output[i]);
  }
}

