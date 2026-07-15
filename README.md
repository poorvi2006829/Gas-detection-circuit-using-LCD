# Gas Detection Circuit using LCD

A real-time gas-leakage monitoring system built with an **Arduino Uno**, an **MQ-series gas sensor**, and a **16x2 LCD display**. The circuit continuously samples the surrounding air and shows a live, human-readable status on the LCD — no computer, phone, or app required.

Designed and simulated in **Tinkercad**.

![Circuit Diagram](Gas_detection_circuit_using_LCD.png)

## Overview

- The gas sensor's analog output is continuously read on Arduino pin `A0`.
- The Arduino compares the reading against a threshold to determine air quality / gas presence.
- The result is displayed instantly on a 16x2 character LCD, driven in 4-bit mode.
- A potentiometer adjusts LCD contrast for readability in any lighting condition.

## How It Works

1. **Sense** — The MQ gas sensor's sensing element changes resistance as gas concentration in the air rises, producing a variable analog voltage.
2. **Read** — The Arduino Uno continuously samples that voltage on analog pin `A0` and converts it to a digital value (0–1023) via its ADC.
3. **Process** — The sketch compares the reading against a threshold to decide whether air quality is normal or a gas leak is likely.
4. **Display** — The result is written to the 16x2 LCD in real time, giving an immediate on-site readout.

## Bill of Materials

| Ref.   | Component               | Qty | Role in Circuit                                              |
|--------|--------------------------|-----|----------------------------------------------------------------|
| U1     | Arduino Uno R3           | 1   | Microcontroller — reads the sensor and drives the LCD          |
| GAS1   | MQ Gas Sensor            | 1   | Detects combustible / toxic gas concentration in air           |
| U2     | 16x2 LCD Display         | 1   | Shows live gas readings and status messages                    |
| RPOT2  | 250 kΩ Potentiometer     | 1   | Adjusts LCD contrast (connected to VO)                         |
| R1     | 1 kΩ Resistor            | 1   | Current-limiting resistor in the sensor/LED stage               |
| R2     | 330 Ω Resistor           | 1   | Current-limiting resistor for the sensor's heater/LED stage      |

## Signal Connections

| Arduino Uno            | Connects To                          | Purpose                                             |
|-------------------------|---------------------------------------|------------------------------------------------------|
| `A0` (Analog In)        | Gas Sensor (GAS1) Output              | Reads variable gas-concentration voltage             |
| `D2`–`D8` (Digital)     | LCD 16x2 (RS, E, D4–D7)               | Drives the LCD in 4-bit mode                          |
| `5V` / `GND`            | LCD VCC/GND, Sensor, Potentiometer    | Shared power and ground rails                         |
| Potentiometer Wiper     | LCD VO (Contrast Pin)                 | Sets LCD display contrast                             |
| R1 / R2                 | Gas Sensor Load Path                  | Limit current through the sensor stage                |

> **Note:** The LCD data lines are driven in 4-bit mode, so only 6 of the 8 data pins (D4–D7 plus RS and Enable) are wired to the Arduino.

## Circuit Diagrams

| Breadboard View | Schematic View |
|---|---|
| ![Breadboard](Gas_detection_circuit_using_LCD.png) | ![Schematic](schematic_cropped.jpg) |

## Applications

- **Home safety** — early warning for LPG or smoke leaks in kitchens and utility rooms
- **Industrial monitoring** — continuous air-quality checks near storage tanks and process lines
- **Laboratories** — localized alerts where solvent or gas fumes pose a health risk
- **Parking garages** — detects vehicle exhaust build-up in enclosed spaces
- **Agricultural storage** — monitors silos and grain stores for hazardous gas accumulation
- **Educational demos** — a compact, low-cost platform for teaching embedded sensing

## Future Enhancements

- Add a buzzer or relay output to trigger an audible alarm or automatically shut off a valve.
- Log readings over time with an SD card, or send them to the cloud (Wi-Fi / IoT module) for remote monitoring.
- Calibrate against multiple MQ sensor variants to detect specific gases (LPG, CO, smoke, methane).
- Add a mobile app or SMS alert path for notifications when no one is near the display.

## Repository Contents

| File | Description |
|---|---|
| `Gas_detection_circuit_using_LCD.png` | Breadboard circuit diagram (Tinkercad export) |
| `Gas_detection_circuit_using_LCD.pdf` | Schematic diagram (Tinkercad export) |
| `bom.csv` | Bill of materials |
| `Gas_Detection_Circuit_using_LCD.pptx` | Project presentation slides |

## Tools Used

- [Tinkercad](https://www.tinkercad.com/) — circuit design and simulation
- Arduino IDE — firmware development

## License

Feel free to use, modify, and build upon this project for personal or educational purposes.
