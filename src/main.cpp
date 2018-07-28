#include <Arduino.h>

#include <EEPROM.h>

//#include <SPI.h>
//#include <RH_RF95.h>

#include <Wire.h>
#include <DS1307.h>

#include <Base64.hpp>

DS1307 rtc;

void setup() {

    Serial.begin(115200);
    delay(2000);

    // RTC initialization
    //Serial.println("===== Setup =====");
    // check if we already have an ID or not
    // for testing, we will always let user input id for now
    if ( EEPROM.read(0) == 0 || EEPROM.read(1) == 0 ) {

        Serial.println("NO_ID");

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
    } else {
        Serial.println("YES_ID");
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

    digitalWrite(8, LOW);

    rtc.set(
		startSec,
		startMinute,
		startHour,
		startDay,
		startMonth,
		startYear
	); //08:00:00 24.12.2014 //sec, min, hour, day, month, year

	rtc.start();

    uint8_t sec, min, hour, day, month;
  	uint16_t year;
	rtc.get(&sec, &min, &hour, &day, &month, &year);

    Serial.print("Set time: ");
    Serial.print(hour, DEC);
    Serial.print(":");
    Serial.print(min, DEC);
    Serial.print(":");
    Serial.print(sec, DEC);

	Serial.print(" ");

	Serial.print(day, DEC);
	Serial.print(".");
	Serial.print(month, DEC);
	Serial.print(".");
	Serial.println(year, DEC);
}

void loop() {
    // put your main code here, to run repeatedly:
}
