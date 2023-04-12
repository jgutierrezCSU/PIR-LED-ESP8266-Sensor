# PIR-LED-ESP8266-Sensor


## Code Summary

The code is written in Arduino IDE and is designed to run on an ESP8266 microcontroller. The code uses a PIR motion sensor to detect motion and turn on an LED. The sensor is connected to the ESP8266's GPIO2 pin, and the LED is connected to the ESP8266's GPIO5 pin.

The code includes a function called `isNightTime()`, which returns true if the current time is between midnight and 6:00 AM. This function is used to control when the motion sensor is active.

The code also includes a function called `setup()`, which initializes the GPIO pins and sets up the Serial interface for debugging.

The main loop of the code checks to see if it's nighttime by calling `isNightTime()`. If it's nighttime, the code waits for motion to be detected by the sensor. If motion is detected, the LED is turned on for 5 seconds, and then turned off. If it's not nighttime, the code goes to sleep for 30 seconds to conserve power.

Finally, the code includes a function called `printDateTime()`, which is used for debugging. This function prints the current date and time to the Serial monitor.

Overall, the code provides a simple example of how to use a PIR motion sensor and an LED with an ESP8266 microcontroller, while also implementing some basic functionality for controlling the sensor based on the time of day.


PINOUT:

         +----------------+      +----------+      +----------------+
         | ESP8266 Module |      | Step-Up  |      | PIR Motion     |
         |                |      | Converter|      | Sensor         |
         |                |      |          |      |                |
         |   GPIO2 (D2) --+----->+  Vin  ---+---> 5V VIN         |
         |                |      |  GND  ---+---> GND            |
         |   GND        ---+----->+  Vout ---+---> 5V OUT         |
         |                |      |          |      |                |
         |   3.3V       ---+----->+          |      |                |
         |                |      |          |      |                |
         |                |      |          |      |                |
         |   GPIO5 (D1) --+----->+          |      | LED            |
         |                |      |          |      |                |
         |   GND        ---+----->+          |      |                |
         |                |      +----------+      |                |
         +----------------+                        +----------------+
