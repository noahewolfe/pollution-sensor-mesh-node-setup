#include <Arduino.h>

#include <EEPROM.h>

//#include <SPI.h>
//#include <RH_RF95.h>

#include <Wire.h>

#include <Base64.hpp>

#include <LiquidCrystal.h>
#define LCD_LIGHT_PIN A3

LiquidCrystal lcd(14, 15, 9, 10, 5, 16);

void setup() {

    Serial.begin(115200);
    lcd.begin(16, 2);
    lcd.setCursor(0,0);
    lcd.clear();
    delay(2000);

    // RTC initialization
    //Serial.println("===== Setup =====");
    // check if we already have an ID or not
    // for testing, we will always let user input id for now
    lcd.print(EEPROM.read(0));
    lcd.setCursor(1,0);
    lcd.print(EEPROM.read(1));
    lcd.setCursor(0,1);
    if ( EEPROM.read(0) == 0 || EEPROM.read(1) == 0 ) {

        Serial.println("NO_ID");
        lcd.print("NO_ID");

    } else {
        Serial.println("YES_ID");
        lcd.print("YES_ID");
    }

    bool expectId = NULL;
    while(expectId == NULL) {
        if (Serial.available() > 0) {
            int code = Serial.parseInt();
            if (code == 1) {
                expectId = true;
            } else if (code == 0) {
                expectId = false;
            }
        }
    }

    lcd.clear();

    lcd.print("Expect ID:");
    lcd.setCursor(10,0);
    lcd.print(expectId);

    if (expectId == true) {
        int id = -1;
        while(id == -1) {
            if (Serial.available() > 0) {
                id = Serial.parseInt();
            }
        }
        char base64Id[2];
        convertNumber(base64Id, id, 0, 2);
        //Serial.print(base64Id[0]);
        //    Serial.println(base64Id[1]);
        EEPROM.write(0, base64Id[0]);
        EEPROM.write(1, base64Id[1]);
    }

    Serial.print("ID (base 64): ");
    Serial.print((char)EEPROM.read(0));
    Serial.println((char)EEPROM.read(1));

    //Serial.println("Initializing RTC...");
    //Serial.println("===== Enter an initialization time ===== ");

    int startYear = -1;
    //Serial.print("Year:");
    while(startYear == -1) {
        if (Serial.available() > 0) {
            startYear = Serial.parseInt();
            Serial.println(startYear);
        }
    }


    int startMonth = -1;
    //Serial.print("Month:");
    while(startMonth == -1) {
        if (Serial.available() > 0) {
            startMonth = Serial.parseInt();
            Serial.println(startMonth);
        }
    }


    int startDay = -1;
    //Serial.print("Day:");
    while(startDay == -1) {
        if (Serial.available() > 0) {
            startDay = Serial.parseInt();
            Serial.println(startDay);

        }
    }


    int startHour = -1;
    //Serial.print("Hour:");
    while(startHour == -1) {
        if (Serial.available() > 0) {
            startHour = Serial.parseInt();
            Serial.println(startHour);
        }
    }


    int startMinute = -1;
    //Serial.print("Minute:");
    while(startMinute == -1) {
        if (Serial.available() > 0) {
            startMinute = Serial.parseInt();
            Serial.println(startMinute);
        }
    }


    int startSec = -1;
    //Serial.print("Second:");
    while(startSec == -1) {
        if (Serial.available() > 0) {
            startSec = Serial.parseInt();
            Serial.println(startSec);
        }
    }

    digitalWrite(8, LOW); // why?
}

void loop() {
    // put your main code here, to run repeatedly:
}
