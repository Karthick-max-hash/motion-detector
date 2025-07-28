# motion-detector
# 🔦 Smart Motion-Activated Light System using Arduino (PIR + LDR + Buzzer)

This project is a *motion-activated light system* using a *PIR sensor, **LDR (photoresistor), and **piezoelectric buzzer. It turns on an LED and buzzer **only when it's dark and motion is detected, simulating a basic **security or smart light system*.

Built and simulated using ->https://www.tinkercad.com/things/dQ6dT7golY1-motion-detector?sharecode=BT79gMCAp1rul8vFjrVC5nqKPmGQKv1ThQ2dorg0xtw

---

## 🚀 Features

- 🕵‍♂ Motion detection using *PIR sensor*
- 🌑 Light detection using *photoresistor (LDR)*
- 💡 Turns on *LED* only if motion is detected *and* it is *dark*
- 🔊 Activates *buzzer alarm* during detection
- ✅ Built on *Arduino Uno*

---

## 🧰 Components Used

| Component        | Quantity |
|------------------|----------|
| Arduino Uno      | 1        |
| PIR Sensor       | 1        |
| Photoresistor (LDR) | 1     |
| 10kΩ Resistor (for LDR) | 1 |
| LED              | 1        |
| 220Ω Resistor (for LED) | 1 |
| Piezoelectric Buzzer | 1    |
| Breadboard       | 1        |
| Jumper Wires     | As needed |

---

## 🔌 Circuit Connections

### PIR Sensor:
- *VCC* → 5V  
- *GND* → GND  
- *OUT* → Digital Pin 2

### LDR + 10kΩ Voltage Divider:
- One leg of *LDR* → 5V  
- Other leg of *LDR* → *A0* and to one leg of 10kΩ resistor  
- Other leg of *10kΩ resistor* → GND

### LED:
- *Anode (+)* → Digital Pin 8 via 220Ω resistor  
- *Cathode (–)* → GND

### Piezo Buzzer:
- *+ (Long leg)* → Digital Pin 9  
- *– (Short leg)* → GND

---

## 💻 Arduino Code

```cpp
int pirPin = 2;
int ledPin = 8;
int buzzerPin = 9;
int ldrPin = A0;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int motion = digitalRead(pirPin);
  int lightLevel = analogRead(ldrPin); // 0 (dark) to 1023 (bright)

  Serial.print("Motion: ");
  Serial.print(motion);
  Serial.print(" | Light: ");
  Serial.println(lightLevel);

  if (motion == HIGH && lightLevel < 500) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  delay(200);
}
