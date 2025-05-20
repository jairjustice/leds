#include <Arduino.h>
#include <FastLED.h>

// Configuración de LEDs
#define NUM_LEDS 8       // Número de NeoPixels
#define LED_PIN 2        // Pin de datos (GPIO2/D2)
CRGB leds[NUM_LEDS];     
void setup() {
  // Inicializar FastLED
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(100);  // Brillo al 100%
  Serial.begin(115200);
  Serial.println("Efecto arcoiris iniciado");
}

void loop() {
  static uint8_t hue = 0;  
  fill_rainbow(leds, NUM_LEDS, hue, 7);  
  FastLED.show();
  
  hue++; 
  delay(20);  
}