# fruitlessss
!Image(https://drive.google.com/file/d/1Ui3VeCpNaVWcfy3_C20adyOFa_R6VNpk/view?usp=drivesdk)

# fruitlessss

arfan bt

theertha menon

ancy mariya shaju

An Arduino monk uses sensors to check air quality and distance, then moves a servo and lights LEDs to show if the air is good or bad, and if someone’s too close — in a funny, passive-aggressive way.
How to make a robot monk passively complain about bad air quality and annoying close talkers — because sometimes, you just want to say “stay away, the air stinks!” without being rude!It’s fun, quirky, and a lighthearted way to raise awareness about pollution and personal space


This project uses sensors to detect poor air quality and if someone is too close, then responds with LED lights and servo movements that mimic a monk’s reactions—calm when air is clean, warning when it’s bad, and dismissive if someone invades the space during bad air. It’s a creative way to remind people about pollution and respecting personal space without saying a word.


for software and hardware
,Languages:
C++ (Arduino programming language)
Frameworks/Libraries:
Servo.h (built-in Arduino library for controlling servo motors)
(Optional if OLED used) Adafruit_SSD1306 and Adafruit_GFX (for OLED display)



Tools:
Arduino IDE (for writing, compiling, and uploading code)
Arduino Uno board
MQ135 air quality sensor
HC-SR04 ultrasonic distance sensor
Servo motor
LEDs (red and green)
USB cable for connection
Hardware Setup:
Connect MQ135 sensor to analog pin A0 to measure air quality.
Connect HC-SR04 ultrasonic sensor to digital pins 2 (Trig) and 3 (Echo) for distance measurement.
Connect red and green LEDs to digital pins 5 and 6 through appropriate resistors.
Connect servo motor signal wire to pin 9; power and ground accordingly.
Connect Arduino Uno to PC via USB for programming and power.



Software Setup:
Write Arduino sketch using built-in Servo library and sensor readings.
Use analogRead() for MQ135 and pulseIn() for ultrasonic sensor to get distance.
Based on thresholds for air quality and proximity, control LEDs and servo movements to indicate different states.
Use Serial Monitor to display real-time sensor values and states.



