// Version 2: Soil moisture monitor with LCD output
// Displays raw analog moisture values and Wet, Good, or Dry status on the LCD

int sensorPin = A0;
int sensorValue = 0;

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

}

void loop() {
  sensorValue = analogRead(sensorPin);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Moisture #: ");
  lcd.print(sensorValue);
  lcd.setCursor(0,1);

  Serial.print("Soil moisture: ");
  Serial.println(sensorValue);

  if (sensorValue < 400) {
    lcd.print("Status: Wet");
    Serial.println("Soil Status: Wet");

  } else if (sensorValue > 574) {
    lcd.print("Status: Dry");
    Serial.println("Soil Status: Dry");

  } else {
    lcd.print("Status: Good");
    Serial.println("Soil Status: Good");
  }

  Serial.println();
  

  delay(500);
}