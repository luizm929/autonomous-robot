//LED NEO Pixel
/*LATEST WORKING ROBOT !!!!!!!!!!!! as of August 16 2013
 PROBLEMS TO SOLVE
 
 **Optimize navigation. 
 **Maybe slowing down the clock in order to use less power.
 **Make code shorter ( there are a lot of variables not in use.
 **Optimize stepper.
 
 
 
 PROBLEMS ALREADY SOLVED
 **Integrate the stepper motor to move the ultrasonic sensor in order to check 
 distance in different directions
 **RED LED deos not turn on to let me know it encountered an obstacle
 Only BLUE and GREEN turn on
 **Ultrasonic would take too long to measure obstacle distance,
 the culprit was the for loop inside one of the funtcions of 
 the NEO_PIXEL example
 
 */
/* We create a new object called strip eventhough we have only one LED per sensor.*/
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, 10, NEO_GRB + NEO_KHZ800);// Temp sensor
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(60, 8, NEO_GRB + NEO_KHZ800);// Distance
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(60, 12, NEO_GRB + NEO_KHZ800);
/**********************************************************************************/
/*Ultrasonic trig and pin to measure distance*/
#define trigPin 4
#define echoPin 3
/****************************/

int tempSensor = 0;  // Temp sensor at pin 0
#define aref_voltage 3.3 //We use aref for more accuracy and also becasue oterwise it will conflict with dcmotors
#include <AFMotor.h>  //we include the motor library
AF_DCMotor motor1(4); //create motor1 at channel 4
AF_DCMotor motor2(3); //create motor2 at channel 3
AF_Stepper stepper(200, 1);// connect step motor with 48 steps per rev on mottor shield channel 1
#include <Wire.h> //Include the wire library to communicate with the LCD
#include <Adafruit_MCP23017.h>     //include the adafruit library for the LCD
#include <Adafruit_RGBLCDShield.h>  //Inlcude another library to communicate with LCD
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();   //We create an object called lcd (OUR LCD).
// These #defines make it easy to set the backlight color
#define LCD_RED 0x1  //Backlight RED
//#define YELLOW 0x3
#define LCD_GREEN 0x2 //Backlight GREEN
//#define TEAL 0x6
#define LCD_BLUE 0x4 // Backlight BLUE
//#define VIOLET 0x5
#define LCD_WHITE 0x7  //Backlight WHITE

void setup() {
  Serial.begin (9600);  //We start the serial console 
  /*We need this for temp sensor connected to AREF pin*/
  analogReference(EXTERNAL);  //This must be declared in order for the TEmperature sensor to work correctly
  /*Definitions for Ultrasonic pins*/
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  motor1.setSpeed(190);// wheel motors speed
  motor2.setSpeed(190);// wheel motors speed
  stepper.setSpeed(150); //stepper which moves the ultrasonic sensor initial speed.
  motor1.run(RELEASE); //This is neede in order for the motors to work (we also needed to stop the motors).
  motor2.run(RELEASE);
  strip.begin(); //Initialize the LED
  strip.show(); // Initialize all pixels to 'off'
  strip2.begin();
  strip2.show();
  strip3.begin();
  strip3.show(); 
  lcd.begin(16, 2);//Initialize LCD
}




void loop() {

  int distance = chkDistance();//We store the distance in a variabel to use in loop()
  Serial.println(chkDistance());
  lcdMod(); //we call the LCD function.
  if (distance > 30) {  // If you become too close to an obstacle
    Fwd();
    DistanceColorSwitch(strip2.Color(0, 20, 0), 7); //Green

  }
  else {
    /*This is how we fill LED with color*/
    DistanceColorSwitch(strip2.Color(20, 0, 0), 7); //Red
    Halt();
    delay(1000);
    int distOnRight, distOnLeft;

    stepper.step(40, FORWARD, MICROSTEP); 
    distOnLeft = chkDistance();
    delay(1000);
    Serial.print("Distance on Left");
    Serial.println(distOnLeft);
    stepper.step(40, BACKWARD, MICROSTEP); 
    delay(1000);
    stepper.step(40, BACKWARD, MICROSTEP); 
    delay(1000);
    stepper.step(40, FORWARD, MICROSTEP); 
    distOnRight = chkDistance();
    delay(1000);
    Serial.print("Distance on Right");
    Serial.println(distOnRight);
    
   
    if(distOnRight > distOnLeft){
      TurnRight();
      delay(700);  
      Fwd();
    }
    else {
      TurnLeft();
      delay(700);
      Fwd();
    } 
      

  }
  //if (distance >= 200 || distance <= 0){
  // Serial.println("Out of range");
  //}
  //else {
  Serial.print(distance);
  Serial.println(" cm");
  //}
  float Temp = chkTemp();
  if(Temp > 82.99)
  {
    //Temp Color switch
    TempColorSwitch(strip.Color(20, 0, 0), 7);//Red
    // Serial.print("Too hot(F): ");//*************
    //Serial.println(Temp);        //**********
    delay(50);
  }
  else 
    if(Temp <= 82.99)
  {
    TempColorSwitch(strip.Color(0, 0, 20), 7); // Blue

    // Serial.print("Nice Temp(F): ");//************
    //Serial.println(Temp);          //************
    delay(50);
  }

  // delay(50);
}





