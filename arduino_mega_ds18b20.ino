#include <OneWire.h>  //библиотека для соединения DS18B20 с помощью 2 проводов
#include <TFT_HX8357.h> // подключение библиотеки TFT
#include "Free_Fonts.h"// бібліотека шрифтов

TFT_HX8357 tft = TFT_HX8357();       // Invoke custom library
OneWire ds(2); // Объект OneWire    

int temperature; // Глобальная переменная для хранения значение температуры с датчика DS18B20
void setup(){
  tft.init();
  tft.setRotation(3);               // ориентация дисплея 
  tft.fillScreen(TFT_BLACK);        // заливка чдисплея черным цветом
}
void loop(){
  detectTemperature(); // Определяем температуру от датчика DS18b20
}
   int detectTemperature(){
   byte data[2]; // место для значения температуры
   ds.reset();  // сброс предыдущих значений 
   ds.write(0xCC); //команда пропустить поиск по адресу
   ds.write(0x44,1); // команда измерить температуру
  {
   ds.reset(); // 
   ds.write(0xCC); //
   ds.write(0xBE); // передача данных регистров с данными температруы
   data[0] = ds.read(); // читаем младший байт температуры
   data[1] = ds.read(); // читаем старший байт температуры
   temperature = (data[1] << 4) | (data[0] >> 4); // складываем полученные значения
   tft.setTextColor(TFT_WHITE,TFT_BLACK);         // установка цвета для шрифта и экрана
   tft.setCursor(240,180);                        // курсов в положение X-240, y-180
   tft.setFreeFont(FF32);                         // задаем шрифт из библиотеки для дисплея
   tft.print(temperature);                        // вывод температры на экран

   
  }
}
