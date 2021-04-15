// Real time clock and calendar with set buttons using DS1307 and Arduino
// include LCD library code
#include <LiquidCrystal.h>
// include Wire library code (needed for I2C protocol devices)
#include <Wire.h>
#include <MusicBuzzer.h>


// LCD module connections (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define LED 9
#define buzzer 8
#define SelectButton 10
#define EditButton 11

void setup() {
  
  pinMode(SelectButton, INPUT_PULLUP);                    // button1 is connected to pin 10
  pinMode(EditButton, INPUT_PULLUP);                      // button2 is connected to pin 11
  pinMode(LED, OUTPUT);                                   // Set LED as an output
  pinMode(buzzer, OUTPUT);                                // Set buzzer as an output
  music.init(buzzer);                                     // initialize Alarm sound for buzzer
  
  // set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  Wire.begin();                                           // Join i2c bus
}
 
char Time[]   = "TIME:  :  :  ";
char Alarm[]  = "ALRM:  :  ";
byte i, second, minute, hour, minuteA, hourA;

void DS1307_display(){
  // Convert BCD to decimal
  second = (second >> 4) * 10 + (second & 0x0F);
  minute = (minute >> 4) * 10 + (minute & 0x0F);
  hour   = (hour >> 4)   * 10 + (hour & 0x0F);

  minuteA  = (minuteA >> 4)  * 10 + (minuteA & 0x0F);
  hourA    = (hourA >> 4)    * 10 + (hourA & 0x0F);
    // End conversion
    
  Time[12]     = second  % 10 + 48;
  Time[11]     = second  / 10 + 48;
  Time[9]      = minute  % 10 + 48;
  Time[8]      = minute  / 10 + 48;
  Time[6]      = hour    % 10 + 48;
  Time[5]      = hour    / 10 + 48;
  Alarm[9]     = minuteA % 10 + 48;
  Alarm[8]     = minuteA / 10 + 48;
  Alarm[6]     = hourA   % 10 + 48;
  Alarm[5]     = hourA   / 10 + 48;
  lcd.setCursor(0, 0);
  lcd.print(Time);                             // Display time
  lcd.setCursor(0, 1);
  lcd.print(Alarm);                            // Display Alarm
}
void blink_parameter(){
  byte j = 0;
  while(j <  10 && digitalRead(SelectButton) && digitalRead(EditButton)){
    j++;
    delay(25);
  }
}
byte edit(byte x, byte y, byte parameter){
  char text[3];
  while(!digitalRead(SelectButton));             // Wait until button (pin #10) released
  while(true){
    while(!digitalRead(EditButton)){             // If button (pin #11) is pressed
      parameter++;
      if(i == 0 && parameter > 23)               // If hours > 23 ==> hours = 0
        parameter = 0;
      if(i == 1 && parameter > 59)               // If minutes > 59 ==> minutes = 0
        parameter = 0;
      if(i == 2 && parameter > 23)               // If hours for alarm > 23 ==> hours = 0
        parameter = 0;
      if(i == 3 && parameter > 59)               // If minutes for alarm > 59 ==> minutes = 0
        parameter = 0;
        
        sprintf(text,"%02u", parameter);
        lcd.setCursor(x, y);
        lcd.print(text);
        delay(200);                                // Wait 200ms
        }
        lcd.setCursor(x, y);
        lcd.print("  ");                           // Display two spaces
        blink_parameter();
        sprintf(text,"%02u", parameter);
        lcd.setCursor(x, y);
        lcd.print(text);
        blink_parameter();
        
        if(!digitalRead(SelectButton)){              // If button (pin #12) is pressed
          i++;                                       // Increament 'i' for the next parameter
          return parameter;                          // Return parameter value and exit
          }
  }
}

 void loop() {
  if(!digitalRead(SelectButton)){                           // If button (pin #10) is pressed edit the time and alarm
      i = 0;
      hour   = edit(5, 0, hour);
      minute = edit(8, 0, minute);
      hourA   = edit(5, 1, hourA);
      minuteA  = edit(8, 1, minuteA);
    
      
      // Convert decimal to BCD
      minute = ((minute / 10) << 4) + (minute % 10);
      hour =   ((hour / 10) << 4) + (hour % 10);
   
      minuteA = ((minuteA / 10) << 4) + (minuteA % 10);
      hourA =   ((hourA / 10) << 4) + (hourA % 10);
      // End conversion
      
      // Write data to DS1307 RTC
      Wire.beginTransmission(0x68);               // Start I2C protocol with DS1307 address
      Wire.write(0);                              // Send register address
      Wire.write(0);                              // Reset sesonds and start oscillator
      Wire.write(minute);                         // Write minute for time
      Wire.write(hour);                           // Write hour for time
      Wire.write(1);                              // Write day (not used)
      Wire.write(minuteA);                        // Write minute for alarm
      Wire.write(hourA);                          // Write hour for alarm
      Wire.endTransmission();                     // Stop transmission and release the I2C bus
      delay(200);                                 // Wait 200ms
    }
    Wire.beginTransmission(0x68);                 // Start I2C protocol with DS1307 address
    Wire.write(0);                                // Send register address
    Wire.endTransmission(false);                  // I2C restart
    Wire.requestFrom(0x68, 7);                    // Request 7 bytes from DS1307 and release I2C bus at end of reading
    second = Wire.read();                         // Read seconds from register 0
    minute = Wire.read();                         // Read minuts from register 1
    hour   = Wire.read();                         // Read hour from register 2
    Wire.read();                                  // Read day from register 3 (not used)
                 
    minuteA  = Wire.read();                       // Read minute for alarm from register 5
    hourA   = Wire.read();                        // Read Hour for alarm from register 6
    Wire.read();  
    DS1307_display();                             // Diaplay Time & Alarm
    delay(50);  // Wait 50ms

   soundAlarm();                                  //turns on speaker when alarm is activated
   blinkLED();                                    //Blink LED every second
}

// activates piezo speaker when the Alarm matches the Time
 void soundAlarm(){

  if(hourA == hour && minuteA == minute){  
    lcd.setCursor(5,1);
    lcd.print("Wake Up");
     music.pinkpanther();
     delay(2000);
     lcd.print("        ");
     lcd.clear();
  }
  else{
    digitalWrite(buzzer, LOW);
  }
}

void blinkLED() {  
digitalWrite(LED, HIGH); 
delay(500); 
digitalWrite(LED, LOW); 
delay(500); 
}
