
# CS 207 Project: ALARM CLOCK W/ SNOOZE BUTTON

This is an alarm clock system that is activated at a scheduled time. 
When activated, the LED lights up and the buzzer makes a sound.
The circuit uses Three buttons to control the clock.
The 3rd button is used to activate the snooze alarm by incrementing the time alarm time by 10 minutes.
The first and second buttons are pressed simultaneously to set up the time and the alarm. 
When an alarm is set, the screen displays the scheduled time of the alarm. 
The screen displays “Alarm Off” when no alarm is set.

2.	Installation instructions
# Materials:
-	x3 push buttons
-	x1 piezo speaker
-	x1 RTC DS1307
-	x1 LCD Display (16x2)
-	wire (generic)
-	x1 Arduino
-	x1 Breadboard
-	x2 10k ohms resistors
-	x1 560 ohms resitor

# Build Instructions
•	Connect push button 1 to pin 10 from ground.
•	Connect push button 2 to pin 11 from ground.
•	Connect push button 3 to pin 12 from ground.
•	Connect piezo speaker to pin 8 from ground.

•	The DS1307 RTC IC contains 8 pins:
o	Pin 1 and pin 2 are connected to the 32.768 KHz Crystal Oscillator
o	Pin 3 is connected to 3.3v
o	Pin 4 is connected to ground.
o	Pin 5 is connected to A4 with a 10k ohms resistor
o	Pint 6 is connected to A5 with a 10K ohms resistor
o	Pin 8 is connected to 5v.

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
o	Pin 2 is connected VEE on LCD display 
o	Pin 3 is connected to 5v


Bugs


# Credits:
https://simple-circuit.com/esp8266-esp-01-ds3231-ds1307-rtc/

