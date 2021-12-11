#include <Adafruit_NeoPixel.h>

#define pin A4
#define NUMPIXELS 1

Adafruit_NeoPixel pixels = Adafruit_NeoPixel( NUMPIXELS,pin,NEO_GRB+NEO_KHZ800);
int ldr = A5;

int light = 3;
int ldr_value;
void setup()
{
 pinMode(ldr,INPUT);
  pinMode(light,OUTPUT);
  pixels.begin();
  
}
void loop()
{
  ldr_value = analogRead(ldr);
  if(ldr_value > 500)
  {
   digitalWrite(light,LOW);
    for(int i =0;i < NUMPIXELS;i++)
    {
      pixels.setPixelColor(i,255,0,0);
      pixels.show();
      delay(100);
    //  pixels.setPixelColor(i,255,146,146);
     
    }
  }
  else
  {
   digitalWrite(light,HIGH); 
    for(int i =0;i < NUMPIXELS;i++)
    {
      pixels.setPixelColor(i,0,255,0);
      pixels.show();
      delay(50);
    }
  }
  
}