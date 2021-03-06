servoTest
=========

This is a simple device to test and/or set small servo's, like the SG90
or the MG996R. I built it for a robotics project involving lots of
servo's that had to be aligned during assembly.

The device consists of an Arduino Uno, a 5V servo power supply, a 16x2
LCD display and a potentiometer. The potmeter allows you to set the
angle, which is shown in the display. The display also shows you the
pulse width of the PWM signal.

The Arduino is externally powered using a 9Vdc 1 amp power supply.


Circuit
=======

This amazing ASCII art shows the circuit of the Servo Tester:

```schema
.---------.
| Arduino |
|       D3|---------------------------------------.  .-.
|         |                  .------.             `--|o|
|      Vin|------------------| 7805 |----------------|o| Servo connector
|         |   |       |      `------'  |          .--|o|
|         |  +|1000uF |100nF    |      |100nF     |  `-'
|         |  ===     ===        |     ===         |
|         |   |       |         |      |          |
|      Gnd|---------------------------------------'
|         |
|      3V3|-----.
|         |     |
|         |    .-.
|         |    | |10k pot
|       A0|--->| |
|         |    `-'
|         |     |
|      Gnd|-----'
|         |               .-----------.  .---------.
|   A4/SDA|---------------| I2C       |==| LCD     |
|   A5/SCL|---------------| Piggyback |==| Display |
|       5V|---------------|           |==| 16x2    |
|      Gnd|---------------|           |==|         |
`---------'               `-----------'  `---------'
```
