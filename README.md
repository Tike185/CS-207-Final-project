
# CS 207 Project: ALARM CLOCK

This is an alarm clock system that is activated at a scheduled time.
It uses an LCD to display the time and alarm and a rtc chip to keep track of the time.
The circuit uses 2 buttons to control the time on the display.
The first button is used to select the hour and minute of time and Alarm while the second buttons edits the time and alarm on the clock.
When an alarm is set, the screen displays the scheduled time of the alarm. 
An LED also blinks every second to replicate the "tik-toking" of a clock.
When the alarm is activated,the screen displays “Wake Up” and the buzzer makes a sound for a minute.

# Installation instructions
Materials:
-	x3 push buttons
-	x1 piezo speaker
-	x1 red LED
-	x1 RTC DS1307
-	x1 LCD Display (16x2)
-	wire (generic)
-	x1 Arduino
-	x1 Breadboard
-	x2 10k ohms resistors
-	x2 560 ohms resitor

- Wiring diagrams:
- [sketch 1.pdf](https://github.com/Tike185/CS-207-Final-project/files/6314934/sketch.1.pdf)
- [LCD sketch.pdf](https://github.com/Tike185/CS-207-Final-project/files/6315358/LCD.sketch.pdf)
- [DS1307 sketch.pdf](https://github.com/Tike185/CS-207-Final-project/files/6315356/DS1307.sketch.pdf)

# Build Instructions
•	Connect push button 1 to pin 10 from ground.
•	Connect push button 2 to pin 11 from ground.
•	Connect piezo speaker to pin 8 from ground.

•	The DS1307 RTC IC contains 8 pins: 
o	Pin 1(x1) and pin 2(x2+) are connected to the 32.768 KHz Crystal Oscillator
o	Pin 3(VBATT) is connected to 3.3v
o	Pin 4(GND) is connected to ground.
o	Pin 5(SDA) is connected to A4 with a 10k ohms resistor
o	Pint 6(SCL) is connected to A5 with a 10K ohms resistor
o	Pin 8(VCC) is connected to 5v.


•	The 16x2 LCD Display contains 16 pins:
o	Pin 1(VSS) is connected to ground
o	Pin 2(VDD) is connected to 5v.
o	Pin 3(VEE) is connected to potential meter
o	Pin 4(RS) is connected to pin 2
o	Pin 5(RW) is connected to ground
o	Pin 6(E) is connected to pin 3
o	Pin 11(D4) is connected to pin 4
o	Pin 12(D5) is connected to pin 5
o	Pin 13(D6) is connected to pin 6
o	Pin 14(D7) is connected to pin 7
o	Pin 15(A) is connected to 5v
o	Pin 16(K) is connected to ground
o D0, D1, D2, and D3 are not in use

•	The potential meter has 3 pins:
o	Pin 1 is connected to ground
o	Pin 2 is the middle pin that is connected VEE on LCD display 
o	Pin 3 is connected to 5v

- Things to note:
-  The VEE pin controls the constrast of the screen
- 


# Planned features: 
I want to add a third button thatwould function as a snooze button by adding an extra 10 minutes to the Alarm time.

# Bugs:

I was not aware that i had ordered the Wrong LCD display screen and DS1307 rtc so i had to choose a different project as a template to create the alarm clock.
The DS1307 chip requires a 3v coin cell battery to provide bakc-up power but can still function without one. Instead, connect the VBATT pin of the DS1307 to the 3.3v pin on the arduino.
The program sets up the time and alarm with the same buttons. This would be an issue if you wanted to reset the time for the alarm because it pauses the time when resetting the alarm clock, which alters the original time. 


# Licence:

- credits: https://simple-circuit.com/esp8266-esp-01-ds3231-ds1307-rtc/
- Disclaimer: None of the libraries were created by me.

# Thanks: 

- a special thanks to my brother for buying the extra compents needed to complete the circuit.
