/*
Cayenne SendDataOnRequest Example

This example sketch shows how a value can be sent from Arduino to the Cayenne Dashboard in response to a Virtual Pin request.

The CayenneMQTT Library is required to run this sketch. If you have not already done so you can install it from the Arduino IDE Library Manager.

Steps:
1. Set the Cayenne authentication info to match the authentication info from the Dashboard.
2. Compile and upload the sketch.
3. A temporary widget will be automatically generated in the Cayenne Dashboard. To make the widget permanent click the plus sign on the widget.
*/

#define CAYENNE_PRINT Serial
#include <CayenneMQTTEthernet.h>   // Change this to use a different communication device. See Communications examples.

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "MQTT_USERNAME";
char password[] = "MQTT_PASSWORD";
char clientID[] = "CLIENT_ID";

// Use Virtual Pin 5 for uptime display.
#define VIRTUAL_PIN 5

void setup()
{
	Serial.begin(9600);
	Cayenne.begin(username, password, clientID);
}

void loop()
{
	Cayenne.loop();
}

// This function is called when a Cayenne widget requests data for Virtual Pin 5.
CAYENNE_OUT(VIRTUAL_PIN)
{
	CAYENNE_LOG("Data requested for Virtual Pin %d", VIRTUAL_PIN);
	// This command writes Arduino's uptime in seconds to the Virtual Pin.
	Cayenne.virtualWrite(VIRTUAL_PIN, millis() / 1000);
}
