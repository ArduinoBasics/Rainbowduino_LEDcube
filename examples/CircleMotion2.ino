#include <Rainbowduino.h>
int mydelay = 75;

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

unsigned long timeRed;
unsigned long timeGreen;
unsigned long timeBlue;
unsigned long startClockRed, startClockGreen, startClockBlue;
unsigned long currentTime;

boolean c = true;

void setup() {
  Rb.init();
  startClockRed = millis();
  startClockGreen = millis();
  startClockBlue = millis();
}

void loop() {
  int i=0;
  int j=0;
  int k=0;
  while(true){
    currentTime = millis();
    timeRed = currentTime;
    timeGreen = currentTime;
    timeBlue = currentTime;
    if(timeRed-startClockRed>99){
      startClockRed=millis();
          Rb.setPixelZXY(Redz[i],Redx[i],Redy[i],0xFF,0x00,0x00);
          Rb.setPixelZXY(Greenz[i],Greenx[i],Greeny[i],0x00,0xFF,0x00);
          Rb.setPixelZXY(Bluez[i],Bluex[i],Bluey[i],0x00,0x00,0xFF);
          i++;
    }
    if(timeGreen-startClockGreen>149){
      startClockGreen=millis();
      Rb.setPixelZXY(Redzb[j],Redxb[j],Redyb[j],0xFF,0x00,0x00);
      Rb.setPixelZXY(Greenzb[j],Greenxb[j],Greenyb[j],0x00,0xFF,0x00);
      Rb.setPixelZXY(Bluezb[j],Bluexb[j],Blueyb[j],0x00,0x00,0xFF);
      j++;
    }
    if(timeBlue-startClockBlue>299){
      startClockBlue=millis();
      Rb.setPixelZXY(Redzc[k],Redxc[k],Redyc[k],0xFF,0x00,0x00);
      Rb.setPixelZXY(Greenzc[k],Greenxc[k],Greenyc[k],0x00,0xFF,0x00);
      Rb.setPixelZXY(Bluezc[k],Bluexc[k],Blueyc[k],0x00,0x00,0xFF);
      k++;
    }
    if(i>17){
      i=0;
    }
    if(j>11){
      j=0;
    }
    if(k>5){
      k=0;
    }

  }
}
