#define PULSE_TIMEOUT 250
#define COIN_PIN 2

unsigned long duration = 0;
unsigned int pulseCount = 0;

void setup() {
  Serial.begin(9600);
  Serial.write("0#");

  // added INPUT_PULLUP to configure the pullup resistor (20K or 50K)
  pinMode(COIN_PIN, INPUT_PULLUP);
  interrupts();
}


void coinRead(uint8_t pulses) {
  Serial.print(pulses);
  Serial.write('#');
}

void loop() {
  unsigned long duration;
  duration = pulseIn(COIN_PIN, HIGH, 250000);

  if (duration > 0)
  {
     pulseCount++;
  }
  else
  {
    if (pulseCount > 0)
    {
      Serial.print(pulseCount);
      Serial.print("#");
      pulseCount = 0;
    }
  }
}
