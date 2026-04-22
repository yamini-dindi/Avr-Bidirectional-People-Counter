# Avr-Bidirectional-People-Counter

A real-time people counting system using AVR microcontroller, dual PIR sensors, and 16x2 LCD display.

## Features

- Detects entry and exit using two PIR sensors
- Updates occupancy count in real time
- Displays count on 16x2 LCD
- Bare metal programming using AVR registers

## Technologies Used

- Embedded C
- AVR Microcontroller (ATmega328P)
- GPIO Programming
- LCD 4-bit Interfacing

## Working Principle

- Sensor 1 then Sensor 2 → Person Entered
- Sensor 2 then Sensor 1 → Person Exited
- LCD displays current count

## Files

- `main.c` – project source code

## Future Improvements

- Interrupt-based sensing
- EEPROM memory backup
- Wi-Fi logging using ESP32

  ## Demo video

[Watch Project Demo](https://www.linkedin.com/posts/activity-7452318894070890496-1vfz?utm_source=social_share_send&utm_medium=member_desktop_web&rcm=ACoAAEhoTdEBaiwlRRQ-JYEoohnzfeSjPpGZ578)
