# Avr-Bidirectional-People-Counter

A real-time people counting system using AVR microcontroller, dual IR sensors, and 16x2 LCD display.

Features
Detects entry and exit using two IR sensors
Updates occupancy count in real time
Displays count on 16x2 LCD
Bare metal programming using AVR registers
Technologies Used
Embedded C
AVR Microcontroller (ATmega328P)
GPIO Programming
LCD 4-bit Interfacing
Working Principle
Sensor 1 then Sensor 2 → Person entered
Sensor 2 then Sensor 1 → Person exited
LCD displays current count
Files
main.c – project source code
Future Improvements
Interrupt-based sensing
EEPROM memory backup
Wi-Fi logging using ESP32
🔥 Important Note About
