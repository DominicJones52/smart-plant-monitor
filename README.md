# Smart Plant Monitor

This project is an Arduino-based Smart Plant Monitor that uses a capacitive soil moisture sensor to measure soil moisture levels and help determine when a plant needs water.

The monitor reads analog moisture values from the sensor, converts the raw reading into a moisture percentage, displays the result on an LCD screen, and uses LED indicators plus a buzzer alert to show the current soil condition.

## Features

- Capacitive soil moisture sensor input
- Raw analog sensor reading using `analogRead()`
- Moisture percentage display
- Wet, Good, and Dry soil classification
- LCD1602 display output
- Blue LED indicator for Wet soil
- Green LED indicator for Good soil
- Red LED indicator for Dry soil
- Buzzer alert when soil is Dry
- Calibrated sensor thresholds based on real testing
- Serial Monitor output available for debugging

## Hardware Used

- Arduino Uno
- Capacitive soil moisture sensor
- LCD1602 display
- Potentiometer for LCD contrast
- Blue LED
- Green LED
- Red LED
- Buzzer
- Breadboard
- Jumper wires
- LED resistors
- USB power source or computer connection

## Wiring Setup

### Full Wiring Setup

![Full Wiring Setup](images/plant-wiring-setup-1.jpeg)

### Additional Wiring Angle 1

![Additional Wiring Angle](images/plant-wiring-setup-2.jpeg)

### Additional Wiring Angle 2

![Sensor, LED, and LCD Wiring](images/plant-wiring-setup-3.jpeg)

### Final Setup With Plant

![Final Setup With Plant](images/plant-wiring-setup-with-plant.jpeg)

## Pin Connections

| Component | Arduino Pin / Connection |
|---|---|
| Capacitive soil moisture sensor AO | A0 |
| Capacitive soil moisture sensor VCC | 5V |
| Capacitive soil moisture sensor GND | GND |
| Blue LED | Digital pin 10 |
| Green LED | Digital pin 9 |
| Red LED | Digital pin 8 |
| Buzzer | Digital pin 13 and GND |
| LCD RS | Digital pin 12 |
| LCD E | Digital pin 11 |
| LCD D4 | Digital pin 5 |
| LCD D5 | Digital pin 4 |
| LCD D6 | Digital pin 3 |
| LCD D7 | Digital pin 2 |
| LCD VSS | GND |
| LCD VDD | 5V |
| LCD VO | Middle pin of potentiometer |
| LCD RW | GND |
| LCD A | 5V through resistor if needed |
| LCD K | GND |
| Potentiometer outside pins | 5V and GND |

## Calibration

The capacitive soil moisture sensor was tested in air, wet soil, and dry soil to determine useful thresholds.

Approximate calibration readings:

| Condition | Raw Sensor Reading |
|---|---|
| Wet soil | 200–375 |
| Good/moist soil | 400–574 |
| Dry soil | 590–620 |
| Air | 640–680 |

Lower readings indicate wetter soil, while higher readings indicate drier soil.

The project converts the raw analog value into a moisture percentage using calibrated wet and dry values. The percentage is constrained between 0% and 100% so unusual readings do not display unrealistic values.

## How It Works

The capacitive soil moisture sensor sends an analog signal to the Arduino based on the moisture level in the soil. The Arduino reads this signal through analog pin A0 using `analogRead()`.

The raw sensor value is then converted into a moisture percentage. Since this sensor gives lower values when the soil is wetter and higher values when the soil is drier, the percentage conversion maps the dry reading to 0% and the wet reading to 100%.

The LCD displays the current moisture percentage on the first row and the soil status on the second row.

The monitor classifies the soil into three categories:

- **Wet:** soil has plenty of moisture
- **Good:** soil moisture is in a healthy range
- **Dry:** soil likely needs water

The LEDs provide quick visual feedback:

- Blue LED = Wet
- Green LED = Good
- Red LED = Dry

When the soil is Dry, the buzzer also sounds as an alert.

## Skills Practiced

- Arduino C++ programming
- Analog sensor input with `analogRead()`
- Sensor calibration
- Mapping raw sensor values to percentages
- LCD1602 display wiring and programming
- Potentiometer contrast control
- Digital output with LEDs
- Buzzer output with `tone()`
- Conditional logic with calibrated thresholds
- Breadboard wiring
- GitHub project documentation

## Versions

- Version 1: Read raw soil moisture values and tested Wet, Good, and Dry classifications
- Version 2: Added LCD output for raw moisture value and soil status
- Version 3: Added blue, green, and red LED indicators plus a dry-soil buzzer alert
- Version 4: Added moisture percentage display using calibrated sensor values

## Future Improvements

- Build a custom enclosure for the monitor
- Improve wiring layout for a cleaner final build
- Add an on/off switch for alerts
- Use long-term testing to refine moisture thresholds for different plants
- Test the monitor with different soil types and plant watering needs
