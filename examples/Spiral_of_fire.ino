/*=============================================
* Author: Scott C
* Web Page: https://arduinobasics.blogspot.com
* Date: 17 Nov 2018
===============================================*/

#include <Rainbowduino.h>
#include <FastLED.h>

unsigned char x[8] = {1,2,3,3,2,1,0,0};
unsigned char z[8] = {0,0,1,2,3,3,2,1};
int bR[8] = {0,0,0,0,0,0,0,0};
int bG[8] = {0,0,0,0,0,0,0,0};
int bB[8] = {0,0,0,0,0,0,0,0};
int cube[4][4][4];

void setup() {
  // put your setup code here, to run once:
   Rb.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int k=0; k<4; k++){
    for(int i=0; i<8; i++){
      bR[i] = 255;
      cube[z[i]][x[i]][k] = 255;
      Rb.setPixelZXY(z[i],x[i],k,255,random8(20,100),0);
      delay(150);
      fadeToBlack();
    }
  }
}

void fadeToBlack(){
  for(int zVal=0; zVal<4; zVal++){
    for(int xVal=0; xVal<4; xVal++){
      for(int yVal=0; yVal<4; yVal++){
          cube[zVal][xVal][yVal] = cube[zVal][xVal][yVal] - random8(100);
          if(cube[zVal][xVal][yVal]<0){
            cube[zVal][xVal][yVal] = 0;
          }
          Rb.setPixelZXY(zVal,xVal,yVal,cube[zVal][xVal][yVal],random8(10,15),random8(5));
      }
    }
  }
}
