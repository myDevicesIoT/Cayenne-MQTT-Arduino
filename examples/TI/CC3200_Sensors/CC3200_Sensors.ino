///
/// @mainpage	CC3200_Sensors
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
/// @file		CC3200_Sensors.ino
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
#define USE_TMP007  0
#define USE_OPT3001 1
#define USE_BME280  1

//#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial

// Include application, user and local libraries
#include "Wire.h"
#include "Sensor_Units.h"
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


#if (USE_TMP007 == 1)
#include "Sensor_TMP007.h"
Sensor_TMP007 myTMP007;
float TMP007_internalTemperature, TMP007_externalTemperature;
#endif

#if (USE_OPT3001 == 1)
#include "Sensor_OPT3001.h"
Sensor_OPT3001 myOPT3001;
float OPT3001_light;
#endif

#if (USE_BME280 == 1)
#include "Sensor_BME280.h"
Sensor_BME280 myBME280;
float BME280_pressure, BME280_temperature, BME280_humidity;
#endif

// Edit period_ms
const uint32_t period_ms = 10000;
uint32_t chrono = 0;


// Add setup code
void setup()
{
    Serial.begin(9600);
    Cayenne.begin(username, password, clientID, ssid, wifiPassword);

    Wire.begin();

#if (USE_TMP007 == 1)
    myTMP007.begin(TMP007_FOUR_SAMPLES);
    myTMP007.get();
#endif

#if (USE_OPT3001 == 1)
    myOPT3001.begin();
    myOPT3001.get();
#endif

#if (USE_BME280 == 1)
    myBME280.begin();
    myBME280.get();
#endif
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

#if (USE_TMP007 == 1)
        myTMP007.get();
        TMP007_internalTemperature = conversion(myTMP007.internalTemperature(), KELVIN, CELSIUS);
        TMP007_externalTemperature = conversion(myTMP007.externalTemperature(), KELVIN, CELSIUS));
        Cayenne.celsiusWrite(5, TMP007_internalTemperature);
        Cayenne.celsiusWrite(6, TMP007_externalTemperature);
#endif

#if (USE_OPT3001 == 1)
        myOPT3001.get();
        OPT3001_light = myOPT3001.light();
        Cayenne.luxWrite(4, OPT3001_light);
#endif

#if (USE_BME280 == 1)
        myBME280.get();
        BME280_pressure = myBME280.pressure();
        BME280_temperature = conversion(myBME280.temperature(), KELVIN, CELSIUS);
        BME280_humidity = myBME280.humidity();

        Cayenne.celsiusWrite(1, BME280_temperature);
        Cayenne.hectoPascalWrite(2, BME280_pressure);
        Cayenne.virtualWrite(3, BME280_humidity);
#endif

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
