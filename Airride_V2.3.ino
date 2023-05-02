/*
 * Airride HeSpi V2.4
 * 
 * Added long press feature
 * Added double press feature
 */
 
#include "OneButton.h"                              
#include "Arduino.h"

// Define relay outputs for valve block
 
int front_U = 4; // Front up relay
int front_D = 5; // Front down relay
int rear_U = 6; // Rear up relay
int rear_D = 7; // Rear down relay

// Using UTP CAT6 as interface cable between OEM buttons and Arduino

const int buttonPin8 = 8;  // Inlet rear / ORANGE
const int buttonPin9 = 9;  // Inlet front / BLUE
const int buttonPin10 = 10;  // Exhaust reat / GREEN
const int buttonPin12 = 12;  // Exhaust front / BROWN
int buttonState = 0;  // variable for reading the pushbutton status

// Define pushbuttons

#define BUTTON_PIN 8

OneButton button8 = OneButton(
  BUTTON_PIN,  // Input pin for the button
  true,        // Button is active LOW
  true         // Enable internal pull-up resistor
);

#define BUTTON_PIN 9

OneButton button9 = OneButton(
  BUTTON_PIN,  // Input pin for the button
  true,        // Button is active LOW
  true         // Enable internal pull-up resistor
);

#define BUTTON_PIN 10

OneButton button10 = OneButton(
  BUTTON_PIN,  // Input pin for the button
  true,        // Button is active LOW
  true         // Enable internal pull-up resistor
);

#define BUTTON_PIN 12

OneButton button12 = OneButton(
  BUTTON_PIN,  // Input pin for the button
  true,        // Button is active LOW
  true         // Enable internal pull-up resistor
);


void setup() {

  Serial.begin(115200);                             // enable serial monitor for debugging purposes
 
  pinMode(front_U, OUTPUT);                              // sets the digital pin as output
  pinMode(front_D, OUTPUT);                              // sets the digital pin as output
  pinMode(rear_U, OUTPUT);                              // sets the digital pin as output
  pinMode(rear_D, OUTPUT);                              // sets the digital pin as output

  button12.attachDoubleClick(doubleclick);            // link the function to be called on a doubleclick event.
  button9.attachDoubleClick(doubleclick2);            // link the function to be called on a doubleclick2 event.
  button8.attachDuringLongPress(longpress8);            // link the function to be called on a longpress8 event.
  button9.attachDuringLongPress(longpress9);            // link the function to be called on a longpress9 event.
  button10.attachDuringLongPress(longpress10);            // link the function to be called on a longpress10 event.
  button12.attachDuringLongPress(longpress12);            // link the function to be called on a longpress12 event.
} 

void loop() {
  
  button8.tick();                                   // check the status of the button
  button9.tick();                                   // check the status of the button
  button10.tick();                                  // check the status of the button
  button12.tick();                                  // check the status of the button
 
  delay(10);                                        // a short wait between checking the button

} // loop
 

void doubleclick() {                                // SLAM mode
 digitalWrite(6,HIGH);                             // Open ALL outlet valves
 digitalWrite(7,HIGH);
 Serial.println("SLAM mode activated!");
 delay(10000);                                       // wait 10 seconds
 digitalWrite(6,LOW);                              // close ALL outlet valves
 digitalWrite(7,LOW);
 Serial.println("SLAM mode deactived, system empty");
} 

void doubleclick2() {                                // RIDE mode
 digitalWrite(4,HIGH);                             // Open ALL outlet valves
 digitalWrite(5,HIGH);
 Serial.println("RIDE mode activated!");
 delay(2500);                                       // wait 2.5 second
 digitalWrite(4,LOW);                              // close ALL outlet valves
 digitalWrite(5,LOW);
 Serial.println("RIDE mode active");
} 
 
void longpress8(){                                  // Adjust rear UP
  digitalWrite(4,HIGH);                            // Open REAR inlet valve
   Serial.println("Adjusting rear UP");
 delay(1000);                                       // wait one second
 digitalWrite(4,LOW);                              // Close REAR inlet valve
 Serial.println("Done, rear UP adjusted");
}

void longpress9(){                                   // Adjust front UP
  digitalWrite(5,HIGH);                            // Open the FRONT inlet valve
   Serial.println("Adjusting front UP");
 delay(1000);                                       // wait one second
 digitalWrite(5,LOW);                              // Close FRONT inlet valve
 Serial.println("Done, front UP adjusted");
}

void longpress10(){                                   // Adjust rear DOWN
  digitalWrite(6,HIGH);                            // Open the REAR down valve
   Serial.println("Adjusting, rear DOWN");
 delay(1000);                                       // wait one second
 digitalWrite(6,LOW);                              // Close the REAR down valve
 Serial.println("Done, rear DOWN adjusted");
}

void longpress12(){                                   // Adjust front DOWN
  digitalWrite(7,HIGH);                            // Open the FRONT outlet valve
   Serial.println("Adjusting front DOWN");
 delay(1000);                                       // wait one second
 digitalWrite(7,LOW);                              // Close the FRONT outlet valve
 Serial.println("Done, front DOWN adjusted");
}
