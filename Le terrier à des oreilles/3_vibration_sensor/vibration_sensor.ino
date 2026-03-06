#include <FastLED.h>

#define PIN_LED 6       // Pin de la LED ring
#define NUM_LEDS 12     // 12 LEDs sur ta ring
#define PIN_VIBREUR 5   // Pin du vibreur
#define PIN_VIBRATION A0
#define SEUIL 50        // À ajuster selon tes besoins
#define NOMBRE_VIBRATIONS 3 // Nombre de fois que le vibreur doit vibrer

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812, PIN_LED, GRB>(leds, NUM_LEDS);
  FastLED.clear();
  FastLED.show();
  pinMode(PIN_VIBREUR, OUTPUT);
}

void loop() {
  int valeurVibration = analogRead(PIN_VIBRATION);
  Serial.print("Vibration: ");
  Serial.println(valeurVibration);

  if (valeurVibration > SEUIL) {
    Serial.println("Seuil dépassé ! Toutes les LEDs rouges et vibreur activé.");
    fill_solid(leds, NUM_LEDS, CRGB::Red);
    FastLED.show();
    for (int i = 0; i < NOMBRE_VIBRATIONS; i++) {
      digitalWrite(PIN_VIBREUR, HIGH);
      delay(200);
      digitalWrite(PIN_VIBREUR, LOW);
      delay(200);
    }
  } else {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    FastLED.show();
  }

  delay(100);
}
