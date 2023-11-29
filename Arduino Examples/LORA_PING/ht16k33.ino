//
//    FILE: test_float_decimals.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: test decimal point for floats.
//     URL: http://www.adafruit.com/products/1002
//     URL: https://github.com/RobTillaart/HT16K33


#include "HT16K33.h"

HT16K33 seg(0x70);

#include <Wire.h>

const byte PICO_I2C_ADDRESS = 0x55;
const byte PICO_I2C_SDA = 20;
const byte PICO_I2C_SCL = 21;
const byte PICO_LED = 25;

void HT16k33_setup()
{

  Serial.println(__FILE__);

  Wire.setSDA(PICO_I2C_SDA);
  Wire.setSCL(PICO_I2C_SCL);

  if (! seg.begin())
  {
    Serial.println("not connected");
  }
  Wire.setClock(100000);
  seg.displayOn();

  wait_screen();

}

void wait_screen(){
  
      seg.displayHex(0xEEEE);

  
  }



void print_value(float value){
  seg.displayFloat(value, 0);
  
  
  }


// -- END OF FILE --
