// Version 4: Soil moisture monitor with percentage display
// Reads a capacitive soil moisture sensor, displays moisture percentage/status,
// and uses LEDs + buzzer alerts based on calibrated moisture readings

int sensorPin = A0;
int sensorValue = 0;
int greenLEDPin = 9;
int blueLEDPin = 10;
int redLEDPin = 8;
int buzzerPin = 13;

int moisturePercent = 0;

int dryValue = 620;   
int wetValue = 200;
/*Calibrated from testing:
  Wet soil: around 200-375
  Dry soil: around 590-620
  Air: around 640-680*/
     



#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);    // Serial output kept for debugging
  lcd.begin(16, 2);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  

}

void loop() {
  sensorValue = analogRead(sensorPin);      // Read sensor and calculate moisture percentage

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

  digitalWrite(blueLEDPin, LOW);    // Reset LED states before choosing current status
  digitalWrite(redLEDPin, LOW);
  digitalWrite(greenLEDPin, LOW);

  if (sensorValue < 400) {         // Determine soil status and trigger outputs
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