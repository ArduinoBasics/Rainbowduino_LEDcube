/*=============================================
* Project: LED Cube - Circle Motion 1
* Author: Scott C
* Web Page: https://arduinobasics.blogspot.com
* Date: 17 Nov 2018
===============================================*/

#include <Rainbowduino.h>
int mydelay = 80;

unsigned char Redx[18] = {0,1,2,3,3,3,3,3,3,3,2,1,0,0,0,0,0,0};
unsigned char Redy[18] = {0,0,0,0,1,2,3,3,3,3,3,3,3,2,1,0,0,0};
unsigned char Redz[18] = {0,0,0,0,0,0,0,1,2,3,3,3,3,3,3,3,2,1};
unsigned char Greenx[18] = {3,3,3,3,2,1,0,0,0,0,0,0,0,1,2,3,3,3};
unsigned char Greeny[18] = {3,3,3,3,3,3,3,2,1,0,0,0,0,0,0,0,1,2};
unsigned char Greenz[18] = {0,1,2,3,3,3,3,3,3,3,2,1,0,0,0,0,0,0};
unsigned char Bluex[18] = {0,0,0,0,0,0,0,1,2,3,3,3,3,3,3,3,2,1};
unsigned char Bluey[18] = {3,2,1,0,0,0,0,0,0,0,1,2,3,3,3,3,3,3};
unsigned char Bluez[18] = {3,3,3,3,2,1,0,0,0,0,0,0,0,1,2,3,3,3};


unsigned char Redxb[18] = {1,2,3,3,3,3,3,2,1,1,1,1};
unsigned char Redyb[18] = {0,0,0,1,2,2,2,2,2,1,0,0};
unsigned char Redzb[18] = {1,1,1,1,1,2,3,3,3,3,3,2};
unsigned char Greenxb[18] = {3,3,3,2,1,1,1,1,1,2,3,3};
unsigned char Greenyb[18] = {2,2,2,2,2,1,0,0,0,0,0,1};
unsigned char Greenzb[18] = {1,2,3,3,3,3,3,2,1,1,1,1};
unsigned char Bluexb[18] = {1,1,1,1,1,2,3,3,3,3,3,2};
unsigned char Blueyb[18] = {2,1,0,0,0,0,0,1,2,2,2,2};
unsigned char Bluezb[18] = {3,3,3,2,1,1,1,1,1,2,3,3};

unsigned char Redxc[18] = {2,3,3,3,2,2};
unsigned char Redyc[18] = {0,0,1,1,1,0};
unsigned char Redzc[18] = {2,2,2,3,3,3};
unsigned char Greenxc[18] = {3,3,2,2,2,3};
unsigned char Greenyc[18] = {1,1,1,0,0,0};
unsigned char Greenzc[18] = {2,3,3,3,2,2};
unsigned char Bluexc[18] = {2,2,2,3,3,3};
unsigned char Blueyc[18] = {1,0,0,0,1,1};
unsigned char Bluezc[18] = {3,3,2,2,2,3};




boolean c = true;

void setup() {
  Rb.init();
}

void loop() {
  for(int i=0;i<18;i++){
    Rb.setPixelZXY(Redz[i],Redx[i],Redy[i],0xFF,0x00,0x00);
    Rb.setPixelZXY(Greenz[i],Greenx[i],Greeny[i],0x00,0xFF,0x00);
    Rb.setPixelZXY(Bluez[i],Bluex[i],Bluey[i],0x00,0x00,0xFF);
    delay(mydelay);
    //Rb.blankDisplay();
  }
  Rb.blankDisplay();
  for(int i=0;i<12;i++){
    Rb.setPixelZXY(Redzb[i],Redxb[i],Redyb[i],0xFF,0x00,0x00);
    Rb.setPixelZXY(Greenzb[i],Greenxb[i],Greenyb[i],0x00,0xFF,0x00);
    Rb.setPixelZXY(Bluezb[i],Bluexb[i],Blueyb[i],0x00,0x00,0xFF);
    delay(mydelay*1.25);
    //Rb.blankDisplay();
  }
  Rb.blankDisplay();
    for(int i=0;i<6;i++){
    Rb.setPixelZXY(Redzc[i],Redxc[i],Redyc[i],0xFF,0x00,0x00);
    Rb.setPixelZXY(Greenzc[i],Greenxc[i],Greenyc[i],0x00,0xFF,0x00);
    Rb.setPixelZXY(Bluezc[i],Bluexc[i],Blueyc[i],0x00,0x00,0xFF);
    delay(mydelay*1.5);
    //Rb.blankDisplay();
  }
  Rb.blankDisplay();
}
