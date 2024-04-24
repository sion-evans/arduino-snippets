#include <DFRobot_SIM808.h>
#include <sim808.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);
DFRobot_SIM808 sim808(&Serial);

#define MESSAGE_LENGTH 160
int messageIndex = 0;
char message[MESSAGE_LENGTH];
char fromNumber[16];
char dateTime[24];

int errors = 0;
int maxWidth = 16;
int refresh = 1000;

void setup() {

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  displayText("Initialising..", 0);

  while ( ! sim808.init() ) {
    displayText("Error(s): " + String(++errors), 1);
    delay(refresh);
  }

  displayText("Initialised.", 0);
  displayText("", 1);
  delay(refresh);

}

void loop() {

  displayText("Standing by..", 0);
  displayText("", 1);
  delay(refresh);

  messageIndex = sim808.isSMSunread();

  if (messageIndex > 0) {

    displayText("Incoming..", 0);
    displayText("", 1);

    displayText("Message:", 0);

    sim808.readSMS(messageIndex, message, MESSAGE_LENGTH, fromNumber, dateTime);
    scrollText(String(message), 1, 500);

    displayText("Deleting..", 0);
    displayText("", 1);

    while ( ! sim808.deleteSMS(messageIndex) ) {
      displayText("Error(s): " + String(++errors), 1);
      delay(refresh);
    }

    displayText("Deleted.", 0);
    displayText("", 1);
    delay(refresh);

  }

}

void scrollText(String message, int axis, int interval) {

  for (int i = 0; i <= message.length(); i++) {

    lcd.setCursor(0, axis);

    String messageSegment = message.substring(i);

    if ( messageSegment.length() > maxWidth ) {

      lcd.print( messageSegment.substring(0, maxWidth) );

    } else {

      while (maxWidth > messageSegment.length()) {
        messageSegment = messageSegment + " ";
      }

      lcd.print( messageSegment );

    }

    delay(interval);

  }

}

void displayText(String data, int axis) {

    lcd.setCursor(0, axis);

    String output = data;

    while (maxWidth > output.length()) {
      output = output + " ";
    }

    if ( output.length() > maxWidth ) {
      lcd.print(output.substring(0, maxWidth));
    } else {
      lcd.print(output);
    }

    delay(refresh);

}
