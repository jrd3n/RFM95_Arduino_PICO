# RFM95 Arduino and RPI PICO

This is a place to store some code for the RPI PICO, running on arduino IDE and interacting with the RFM95 LoRa module.

## Contents

1. Arduino Code
2. Some KiCad components for building a PCB to interact with the RFM95 module.
# Arduino Code

This is for use with the RPI Pico using the earlephilhower board manager https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json .

Using the https://github.com/sandeepmistry/arduino-LoRa library. More information can be found here https://github.com/sandeepmistry/arduino-LoRa/blob/master/API.md.

The following lines go in the setup, the purpose of this is to specify the pins on the RPI PICO:

```c++
SPI.setRX(MISO_PIN);
SPI.setCS(CS_PIN);
SPI.setSCK(SCK_PIN);
SPI.setTX(MOSI_PIN);

SPI.begin(true);

LoRa.setSPI(SPI);

LoRa.setPins(CS_PIN, reset_PIN, INT_PIN);
```

**Notes on choosing pins on the RPI Pico**

* The pin numbers are the GPIO numbers.
* Look at the Pin chart for the RPI pico to see which pins are capable for SPI comms on bus 0.

# KiCad


