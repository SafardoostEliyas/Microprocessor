volatile bool led_state = LOW;

/* Setup is run once at the start (Power-On or Reset) of sketch */
void setup()
{
  pinMode(13, OUTPUT); /* Pin 13 is defined as Output */
  pinMode(2, INPUT_PULLUP); /* Interrupt pin */
  /* Connect pin 2 to ground using a tactile switch between the pin and ground */
  attachInterrupt(digitalPinToInterrupt(2), blink, FALLING); /* Call ISR blink whenever a falling edge event is detected on pin 2 */
  /* Press switch to cause falling edge event on the pin */
}

/* Loop runs over and over after the startup function */
void loop()
{
  digitalWrite(13, led_state); /* Write state value to pin 13 which has on-board LED */
}

/* ISR */
void blink() {
  led_state = !led_state; /* Toggle state value of LED */
}