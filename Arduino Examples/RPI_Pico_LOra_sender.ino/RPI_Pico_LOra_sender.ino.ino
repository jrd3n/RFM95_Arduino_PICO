unsigned long now;

void setup() {

  Serial.begin(115200);

  pinMode(25, OUTPUT);
  SCREEN_setup();
  Lora_setup();

  button_setup();

  PRINT_SCREEN("Online\n");

}

void loop(){

  button_loop();
  
//  sendMessage("message");




  }
