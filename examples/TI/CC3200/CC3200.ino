///
/// @mainpage	CC3200
///
/// @details	Cayenne implementation for CC3200 LaunchPad and CC3100 BoosterPack for other LaunchPads
/// @n
/// @n
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
/// @date		nov. 11, 2016 19:49
/// @version	101
///
/// @copyright	(c) Rei Vilo, 2016
/// @copyright	GNU General Public Licence
///
/// @see		ReadMe.txt for references
/// *   http://www.cayenne-mydevices.com/docs/#bring-your-own-thing-api
/// *   http://energia.nu
///


///
/// @file		CC3200.ino
/// @brief		Main sketch
///
/// @details	Cayenne implementation for CC3200 LaunchPad and CC3100 BoosterPack for other LaunchPads
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
/// @date		nov. 11, 2016 19:49
/// @version	101
///
/// @copyright	(c) Rei Vilo, 2016
/// @copyright	GNU General Public Licence
///
/// @see		ReadMe.txt for references
/// *   http://www.cayenne-mydevices.com/docs/#bring-your-own-thing-api
/// *   http://energia.nu
///


// Core library for code-sense - IDE-based
#if defined(ENERGIA) // LaunchPad specific
#include "Energia.h"
#else // error
#error Platform not supported
#endif // end IDE

// Set parameters

//#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial

// Include application, user and local libraries
#include <CayenneMQTTWiFi.h>

// SPI not required for CC3200 LaunchPad
#ifndef __CC3200R1M1RGC__
#include <SPI.h>
#endif

// WiFi network info.
char ssid[] = "ssid";
char wifiPassword[] = "wifiPassword";

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "MQTT_USERNAME";
char password[] = "MQTT_PASSWORD";
char clientID[] = "CLIENT_ID";

// Edit period_ms
const uint32_t period_ms = 10000;
uint32_t chrono = 0;


// Add setup code
void setup()
{
    Serial.begin(9600);
    Cayenne.begin(username, password, clientID, ssid, wifiPassword);
}

// Add loop code
void loop()
{
    Cayenne.loop();

    // Publish data every (period_ms) ms
    if (millis() > chrono)
    {
        chrono = millis() + period_ms;

        // Write data to Cayenne here.
        Cayenne.virtualWrite(0, chrono);


        //Some examples of other functions you can use to send data.
        //Cayenne.celsiusWrite(1, 22.0);
        //Cayenne.luxWrite(2, 700);
        //Cayenne.virtualWrite(3, 50, TYPE_PROXIMITY, UNIT_CENTIMETER);
    }
}

//Default function for processing actuator commands from the Cayenne Dashboard.
//You can also use functions for specific channels, e.g CAYENNE_IN(1) for channel 1 commands.
CAYENNE_IN_DEFAULT()
{
    CAYENNE_LOG("CAYENNE_IN_DEFAULT(%u) - %s, %s", request.channel, getValue.getId(), getValue.asString());
    //Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
}
