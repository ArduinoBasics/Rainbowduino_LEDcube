/*==========================================================================
 * Project: ArduinoBasics Drumming Precison Project - Arduino MASTER code
 * Author:  Scott C
 * Date created: 18 November 2018
 * Arduino IDE version: 1.8.5
 * Operating System: Windows 10 Pro
 * Tutorial Link: https//arduinobasics.blogspot.com/
 * 
 * Description: 
 * This code is for the Arduino UNO (wih the MIDI shield).
 * It is designed as an interface between the electronic Drum Kit and the Rainbowduino LED cube.
 * It receives MIDI messages from the drum kit and passes them through to the LED cube using I2C.
 * 
 * Acknowledgements:
 * 
 * -------------------------------------------------------------------------   
 * LIBRARIES:
 * Wire.h library is used for I2C communication between the Arduino and the Rainbowduino LED cube             
 ============================================================================ */
#include <Wire.h>



/* --------------------------------------------------------------------------
 *  GLOBAL VARIABLES:
 *  MIDI_Note:  Variable to hold the MIDI note that is sent by the drum kit.
 *  MIDI_recv:  The drum kit will send MIDI note #38 twice when the drum is hit.
 *              This variable helps to filter out one of the two notes
 *  MIDI_count: This variable is also used to filter out one of the notes.
 ----------------------------------------------------------------------------*/
unsigned char MIDI_Note;
boolean MIDI_recv = false;
int MIDI_count = 0;



/* --------------------------------------------------------------------------
 *  SETUP:
 *  Initialise I2C communication - set this Arduino as the MASTER with Wire.begin();
 *  Initiaise Serial communication to receive MIDI messages from the drum kit - baud rate=31250
 *  Set PIN13 with the built-in LED as an OUTPUT pin.
 *  Blink the built-in LED on Pin13 ten times - then proceed to the loop function.
 ----------------------------------------------------------------------------*/
void setup() {
  Wire.begin();                         //Used for I2C Communication
  Serial.begin(31250);                  //Used for MIDI communication
  pinMode(LED_BUILTIN, OUTPUT);
  for(int i=0; i<10; i++){
    digitalWrite(LED_BUILTIN,HIGH);
    delay(200);
    digitalWrite(LED_BUILTIN,LOW);
    delay(200);
  }
}



/* --------------------------------------------------------------------------
 *  LOOP:
 *  Listen for the drum kit to send a MIDI note #38 via Serial communication
 *  When MIDI note #38 is received:
 *   - Turn on the built-in LED
 *   - Send the note to the LED cube via I2C
 *  When MIDI note #38 is received the second time:
 *   - Turn OFF the built-in LED
 *   
 *   The MIDI_recv and MIDI_count variables help to limit the number of notes
 *   sent to the LED cube when the drum kit is hit.
 ----------------------------------------------------------------------------*/
void loop() {
  while(Serial.available()>0){
    MIDI_Note = Serial.read();
    if(MIDI_Note==38){
      MIDI_recv = true;
      MIDI_count++;
    }
    if(MIDI_recv){
      if(MIDI_count==1){
        digitalWrite(LED_BUILTIN, HIGH);
        Wire.beginTransmission(8);
        Wire.write(MIDI_Note);
        Wire.endTransmission(); 
      } else {
        MIDI_count=0;
        digitalWrite(LED_BUILTIN, LOW);
      }
      MIDI_recv = false;
    }
  }
}
