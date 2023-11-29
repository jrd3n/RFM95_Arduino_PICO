
#define LED_PIN 25



void setup() {
  // put your setup code here, to run once:

  pinMode(LED_PIN, OUTPUT);

  Serial.begin(115200);

  Lora_setup();

  sendMessage("ONLINE");

}

void loop() {
  // put your main code here, to run repeatedly:
}
