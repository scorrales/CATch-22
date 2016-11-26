# CATch-22

CATch 22 is a project designed to shoo away obnoxious animals from a designated area. Work in progress.

## Author

Sergio Corrales Zamora.

## Main Hardware
 * Adafruit Pro Trinket microcontroller
 * HC-SR04 ultrasonic sensor
 * Solenoid valve 3/4" actuator
 * Adafruit ESP8266 Breakout WiFi module

## Main Software
 * The microcontroller runs on *.ino* code. Here the measurements take place, and alarms are relayed to the WiFi module through serial.
 * The WiFi module sends the alarms to a server. It can also feed intructions to the microcontroller. Runs on *.ino* code.
 * The server runs an interface from which the system can be controlled remotely. It also keeps a history of alarm events.

## How to install

## Dependencies

## Changelog

### 1.0.0
 * Initial Release (still pending)

## Design & Capabilities

## TO-DO

## Related Works

## License
