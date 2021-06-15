#include <OneWire.h>
#include <TFT_HX8357.h> // подключение библиотеки TFT
#include "Free_Fonts.h"// бібліотека шрифтів

TFT_HX8357 tft = TFT_HX8357();       // Invoke custom library
OneWire ds(2); // Объект OneWire

int temperature; // Глобальная переменная для хранения значение температуры с датчика DS18B20
void setup(){
  tft.init();
  tft.setRotation(3);               // ориентация дисплея 
  tft.fillScreen(TFT_BLACK);
}
void loop(){
  detectTemperature(); // Определяем температуру от датчика DS18b20
}
   int detectTemperature(){
   byte data[2]; //місце для значення температури
   ds.reset();  //скидуєм попередні значення
   ds.write(0xCC); //команда пропустити пошук по адресу
   ds.write(0x44,1); // команда зміряти температуру
  {
   ds.reset(); // готуємся для отримання данних
   ds.write(0xCC); //
   ds.write(0xBE); // передача даних регістрів зі значенням температури
   data[0] = ds.read(); // читаєм молодший байт температури
   data[1] = ds.read(); // читаєм старший байт температури
   temperature = (data[1] << 4) | (data[0] >> 4);
   tft.setTextColor(TFT_WHITE,TFT_BLACK);
   tft.setCursor(240,180);     
   tft.setFreeFont(FF32);
   tft.print(temperature); //температура накладається

   
  }
}
