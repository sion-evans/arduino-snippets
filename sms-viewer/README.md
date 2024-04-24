## SMS Viewer (with an Arduino Uno, SIM808, and I2C 16x2 LCD Display)

This project demonstrates how to use an Arduino Uno along with a DFRobot SIM808 module and an I2C 16x2 LCD Display to receive SMS messages and display them on the LCD screen.

### Components Used
- [Arduino Uno](https://thepihut.com/products/arduino-uno-rev-3)
- [SIM808 GSM/GPRS/GPS module](https://www.dfrobot.com/product-1469.html)
- [I2C 16x2 LCD Display](https://www.dfrobot.com/product-135.html)

### Functionality
The Arduino Uno is programmed to interface with the SIM808 module to receive SMS messages using the [DFRobot SIM808 Library](https://github.com/DFRobot/DFRobot_SIM808). Upon receiving a new SMS, the Arduino extracts the message content and displays it on the 16x2 LCD screen. If the message exceeds 16 characters in length, the text will automatically scroll horizontally on the display.

### Additional Notes
- Ensure the Arduino has adequate power using a 9V power supply or similar (USB power alone is insufficient).
- Ensure the function switch on the SIM808 module is set to 1 while programming and 3 when in use.
- If the blue 'Net' LED on the SIM808 module is not blinking (approximately every 3 seconds), press and hold the 'boot' switch for a second or two.
