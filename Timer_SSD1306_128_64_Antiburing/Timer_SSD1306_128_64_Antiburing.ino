#include "U8glib.h"
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);

void draw(void) {
  u8g.setFont(u8g_font_unifont);
  //u8g.setFont(u8g_font_osb21);
  u8g.drawStr( 0, 22, "Kanade");
  //u8g.drawBox(0,0,128,64);
}
void draw2(void) {
  u8g.drawBox(0,0,128,64);
}
int screenBurningBiasX = 0;
int screenBurningBiasY = 0;
void drawTime(unsigned int h, unsigned int m, unsigned int s){
  u8g.drawStr(0+screenBurningBiasX,10+screenBurningBiasY, "Kanade's Timer");
  String buff = String(h)+" : "+String(m)+" : "+String(s);
  char timer[32];
  buff.toCharArray(timer, 32);
  //char t[32];
  //char buff[16];
  //itoa(s,buff,10);
  
  u8g.drawStr(20+screenBurningBiasX,44+screenBurningBiasY, timer);
}

void setup(void) {
  // u8g.setRot180();
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }
}


void loop(void) {
  unsigned int hours = 0;
  unsigned int minutes = 0;
  unsigned int seconds = 0;
  u8g.setFont(u8g_font_unifont);
  while(1){
    u8g.firstPage();  
    do {
      drawTime(hours,minutes,seconds);
    } while( u8g.nextPage() );
    seconds++;
    if(seconds==60){
      seconds=0;
      minutes++;
      screenBurningBiasY++;
      if(screenBurningBiasY==5){
        screenBurningBiasY=0;
      }
      if(minutes==60){
        minutes=0;
        hours++;  
      } 
    }
    screenBurningBiasX++;
    if(screenBurningBiasX==5){
      screenBurningBiasX=0;
    }
    delay(1000);
 }
  delay(500);
}
