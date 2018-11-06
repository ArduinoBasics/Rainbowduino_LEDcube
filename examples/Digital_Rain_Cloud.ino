/*==========================================================================
 * Project: ArduinoBasics Digital Raincloud
 * Author:  Scott C
 * Date created: 06 November 2018
 * Arduino IDE version: 1.8.5
 * Operating System: Windows 10 Pro
 * 
 * Description: 
 * A simple program written for the Rainbowduino 4x4x4 RGB LED cube (by Seeedstudio), 
 * that creates a digital raincloud effect, lightning and all. Add a bit of cotton wool to the top of the
 * cube and the project really comes alive. 
 * 
 * 
 * Acknowledgements:
 * My son suggested putting cotton wool on the top. This simple suggestion made all the difference.
 * The Seeedstudio Rainbowduino WIKI page is a great place to get started with this cube.   
 * http://wiki.seeedstudio.com/Rainbowduino_v3.0/
 * 
 * -------------------------------------------------------------------------   
 * LIBRARIES:
 * The Rainowduino-v3 library by unwiredben was used in this project. 
 * The Rainbowduino-v3 library can be found here: https://github.com/unwiredben/Rainbowduino-v3
 * 
 * The FastLED library was used for the random8() function.
 * The FastLED library can be installed via the IDE:
 *      Sketch > Include Library > Manage Libraries : then search for FastLED
 *      Select the latest version, and then select INSTALL.
 *      I used version 3.2.0              
 ============================================================================ */
#include <FastLED.h>
#include <Rainbowduino.h>



/* --------------------------------------------------------------------------
 *  GLOBAL VARIABLES
 * xPos,yPos = allows us to select a specific LED position in a layer.
 * randomLED = is used to select the random LED from which rain falls
 * cRed, cGreen, cBlue = allows slight variations in colour of the raindrops.
 * topR, topG, topB = restores the colours of the top layer after the lightning effect
 * rainChance = affects the frequency/amount of rainfall
 * rainSpeed = the speed at which the rain falls. Recommend you set this between 2-5.
 * lightningChance = affect the frequency of lightning
 ----------------------------------------------------------------------------*/
unsigned char xPos[16] = {0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3};
unsigned char yPos[16] = {0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3};
int randomLED = 0;
int cRed[4][16];
int cGreen[4][16];
int cBlue[4][16];
int topR[16];
int topG[16];
int topB[16];
int rainChance;
int rainSpeed = 5;
int lightningChance;
 


/*--------------------------------------------------------------------------
 * SETUP:
 * Initialise the Rainbowduino 4x4x4 RGB LED cube and the colour arrays
 --------------------------------------------------------------------------*/
void setup() {
  Rb.init();
  for(int i=0; i<4; i++){
    for(int j=0; j<16; j++){
      cRed[i][j] = 0;
      cGreen[i][j] = 0;
      cBlue[i][j] = 0;
    }
  }
}




/*--------------------------------------------------------------------------
 * LOOP:
 * Randomise the chance of a lightning strike with every loop. Probability = 5%
 * Randomise the chance of a rain drop. Probability = 40%
 * Randomise the LED from which the rain drop falls from
 * Randomise the colour of the raindrop, with a bias towards blue colours
 * Record the colour of the raindrop into the topR, topG, and topB arrays.
 * Then update the display to start the raindrop animation.
 --------------------------------------------------------------------------*/
void loop() {
  lightningChance=random8(100);
  if(lightningChance>95){
    lightning();
  }

  rainChance = random8(100);
  if(rainChance>60){
    randomLED = random8(16);
    cRed[3][randomLED]=random8(10,100);
    cGreen[3][randomLED]=random8(10,100);
    cBlue[3][randomLED]=random8(80,250);
    topR[randomLED] = cRed[3][randomLED];
    topG[randomLED] = cGreen[3][randomLED];
    topB[randomLED] = cBlue[3][randomLED];
  }
  
  updateDisplay();
}




/*--------------------------------------------------------------------------
 * updateDisplay:
 * This function is responsible for the raindrop animation.
 * Illuminate the randomLED
 * Move the raindrop down to the next level with every cycle
 * Gradually fade the LEDs on every cycle, and prevent the values from dropping below zero
 * Update the LED brightness and rain drop animation sequence on the lower levels of the cube. 
 * The delay at the end, will determine the speed of the raindrop animation (larger values are slower)
 --------------------------------------------------------------------------*/
void updateDisplay(){
  for(int i=0; i<4; i++){
    for(int j=0; j<16; j++){
      
// Illuminate the randomLED on the top layer
      if(i>2){
        if(j==randomLED){
          Rb.setPixelZXY(3,xPos[j],yPos[j], topR[j],topG[j],topB[j]);
        }
      }
      
// Move the raindrop down to the next level
      if(i>0){
        cRed[i-1][j] = cRed[i][j];
        cGreen[i-1][j] = cGreen[i][j];
        cBlue[i-1][j] = cBlue[i][j];
      }

// Gradually fade the LEDs - Please note: the top layer is not affected
      cRed[i][j]=cRed[i][j]-50;
      cGreen[i][j]=cGreen[i][j]-40;
      cBlue[i][j]=cBlue[i][j]-40;
      if(cRed[i][j]<0){
        cRed[i][j] = 0;
      }
      if(cGreen[i][j]<0){
        cGreen[i][j] = 0;
      }
      if(cBlue[i][j]<0){
        cBlue[i][j] = 0;
      }

// Update the LED brightness and rain drop animation sequence on the lower levels. 
      if(i<3){
       Rb.setPixelZXY(i,xPos[j],yPos[j],cRed[i][j],cGreen[i][j],cBlue[i][j]);
      }
      
//Set the speed of the raindrop animation sequence
      delay(rainSpeed);
    }
  }
}




/*--------------------------------------------------------------------------
 * lightning:
 * The LEDs will be set to flash a random number of times (0 to 19 times)
 * But the flash may or may not always occur.
 * If the flash does occur, then there is a 50% chance that any particular LED will join in.
 * The LED will illuminate to full brightness WHITE (255,255,255)
 * They will stay illuminated for 20 to 70 milliseconds 
 * and then return back to their normal colour for 0 to 20 milliseconds until the next flash.
 * We do not want the rain animation to stop when the lightning is flashing, so we need to update
 * the raindrop sequence from time to time. I did this randomly to eliminate any PERCEIVED delay from the
 * lightning sequence.
 * The lightning sequence and pattern is very RANDOM, which makes it very realistic.
 --------------------------------------------------------------------------*/
void lightning(){
  int chance = random8(20);
  for(int k=0; k<chance; k++){
    lightningChance=random8(100);
    if(lightningChance>random8(50)){
      for(int j=0; j<16; j++){
        chance = random8(100);
        if(chance>50){
          Rb.setPixelZXY(3,xPos[j],yPos[j],255,255,255);
        }
      }
      delay(random8(20,70));
      for(int j=0; j<16; j++){
          Rb.setPixelZXY(3,xPos[j],yPos[j],topR[j],topG[j],topB[j]);
      }
      delay(random8(20));
    }
    chance = random8(100);
    if(chance>70){
      updateDisplay();
    }
  }
}
