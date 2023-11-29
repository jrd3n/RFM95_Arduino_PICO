unsigned long now;

void setup() {

  Serial.begin(115200);

  pinMode(25, OUTPUT);
  SCREEN_setup();
  Lora_setup();

  button_setup();

}

void loop(){

  button_loop();
  
//  sendMessage("message");
//  PRINT_SCREEN("message\n");



  }
