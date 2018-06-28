#include <U8glib.h>  // U8glib library
#include <dht.h>     // DHT library

#define dht_apin A5  // Analog pin to which the sensor is connected
dht DHT;
               /*Uncomment and comment*/
U8GLIB_SH1106_128X64 u8g(13, 11, 10, 9, 8);  // CLK=13, DIN=11, CS=10, DC=9, Reset=8
//U8GLIB_SSD1306_128X32 u8g(13, 11, 10, 9, 8); // CLK=13, DIN=11, CS=10, DC=9, Reset=8
//U8GLIB_SSD1306_128X64 u8g(13, 11, 10, 9, 8); // CLK=13, DIN=11, CS=10, DC=9, Reset=8

void draw(void) 
{
   u8g.setFont(u8g_font_fub11r);   // select font
   u8g.drawStr(0, 11, "Temp: ");   // put string of display at position X, Y
   u8g.drawStr(80, 11, "Humi: ");
   u8g.setFont(u8g_font_fub14r);
   u8g.setPrintPos(10, 45);        // set position
   u8g.print(DHT.temperature, 0);  // display temperature from DHT11 in Celsius
   u8g.println("F"); 
   u8g.setPrintPos(72, 45);        // set position
   u8g.print(DHT.humidity, 0);     // display humidity from DHT11
   u8g.println("%");
}
void setup(void) 
{

}

void loop(void)
{
   DHT.read11(dht_apin);  // Read apin on DHT11
   u8g.firstPage();  
   do 
{
   draw();
}  while( u8g.nextPage() );
   delay(2000);  // Delay of 2 sec before accessing DHT11 (min - 2sec)
}
                           /*END OF FILE*/
