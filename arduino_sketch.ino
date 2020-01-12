/*
 * Loadcell messures - .9 lcd output - esptouch
 * 
 */

//#include <ESP8266WiFi.h> // No wifi yet? webapi for current weight?
//#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h"
#include <HX711.h>

// Initialize the OLED display using Wire library
SSD1306Wire  display(0x3c, 21, 22);                         //  OLED wired to 21 and 22
HX711 scale;
volatile bool tare_me = false;

//  touch
const int touch_threeshold = 30;                            //  30 worked well with my screws, adjust here if needed
volatile unsigned long sinceLastTouch = 0;

//  smoothing of weight, less jumpy
float alpha = .6;
float smooth_weight = 0;

//  offsets                                                 //  ofsets set by screw touches
volatile float offset = 0;
const float offset_1 = 234;                                 //  esun ABS+ spools
const float offset_2 = 420;                                 //  my custom 3kg spools

////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////

int digits(int in_) {

  String in_to_str = String(in_);
  int out_ = 5 - in_to_str.length();
  
  return out_;
}

void gotTouch1(){
  if (millis() - sinceLastTouch < 500) return;
  sinceLastTouch = millis();
  
  Serial.println("Button_1 pressed");
  delay(100);
  offset = 0;
  tare_me = true;
}

void gotTouch2(){
  if (millis() - sinceLastTouch < 500) return;
  sinceLastTouch = millis();
  
  Serial.println("Button_2 pressed");
  delay(100);
  offset = offset_1;
}

void gotTouch3(){
  if (millis() - sinceLastTouch < 500) return;
  sinceLastTouch = millis();
  
  Serial.println("Button_3 pressed");
  delay(100);
  offset = offset_2;
}

//
void setup() {

  Serial.begin(115200);

  display.init();
  display.flipScreenVertically();

  touchAttachInterrupt(T0, gotTouch1, touch_threeshold);
  touchAttachInterrupt(T3, gotTouch2, touch_threeshold);
  touchAttachInterrupt(T5, gotTouch3, touch_threeshold);
  
  scale.begin(19, 23);
  delay(250);
  scale.set_scale(132.f); // this value is obtained by calibrating the scale with known weights; see the README for details
  delay(250);
  scale.tare();
}

void loop() {

  if(tare_me){
    display.clear();
    display.display();
    tare_me = false;
    scale.tare();
  }

  smooth_weight = alpha * scale.get_units(4) + (1-alpha) * smooth_weight; 
  disp_out(smooth_weight-offset);

}

void disp_out(int weight) {
  display.clear();

  //  tare? esun? bigspools?
  display.setFont(ArialMT_Plain_16);
  if( offset == offset_1 ){
    display.drawString(40, 0, "Offset 1");
  } else if ( offset == offset_2 ) {
    display.drawString(75, 0, "Offset 2");
  } else {
    display.drawString(0, 0, "Tara"); 
  }

  //  weight display
  int d_ = digits(weight);
  display.setFont(DSEG14_Classic_Bold_36);
  display.drawString(d_*12, 22, (String)weight);
  
  display.display();
}
