#include <ButtonDebounce.h>

ButtonDebounce button(18, 50);

void buttonChanged(int state){
  digitalWrite(25,!state);
//  Serial.println("Changed: " + String(state));
//  PRINT_SCREEN("button\t");
//  PRINT_SCREEN(String(state));
//  PRINT_SCREEN("\n");

  if (state == 0){
    
    PRINT_SCREEN("\fPING\n");
    sendMessage("PING");
    now = millis();
    
    }
}

void button_setup() {
  button.setCallback(buttonChanged);
}

void button_loop() {
  button.update();
}
