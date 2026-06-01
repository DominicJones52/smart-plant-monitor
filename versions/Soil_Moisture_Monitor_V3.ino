// Version 4: Soil moisture monitor with percentage display
// Converts raw analog sensor readings into a moisture percentage and displays status on the LCD

int sensorPin = A0;
int sensorValue = 0;
int greenLEDPin = 9;
int blueLEDPin = 10;
int redLEDPin = 8;
int buzzerPin = 13;

int moisturePercent = 0;

int dryValue = 620;
int wetValue = 200;



#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  

}

void loop() {
  sensorValue = analogRead(sensorPin);

  moisturePercent = map(sensorValue, dryValue, wetValue, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100);
  


  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Moisture: ");
  lcd.print(moisturePercent);
  lcd.print("%");
  lcd.setCursor(0,1);

  //Serial.print("Soil moisture: ");
  //Serial.println(sensorValue);

  digitalWrite(blueLEDPin, LOW);
  digitalWrite(redLEDPin, LOW);
  digitalWrite(greenLEDPin, LOW);

  if (sensorValue < 400) {
    lcd.print("Status: Wet");
    //Serial.println("Soil Status: Wet");
    digitalWrite(blueLEDPin, HIGH);

  } else if (sensorValue > 574) {
    lcd.print("Status: Dry");
    //Serial.println("Soil Status: Dry");
    digitalWrite(redLEDPin, HIGH);
    tone(buzzerPin, 800, 500);

  } else {
    lcd.print("Status: Good");
    //Serial.println("Soil Status: Good");
    digitalWrite(greenLEDPin, HIGH);
  }

  //Serial.println();
  

  delay(3000);
}