/*
The MIT License(MIT)

Cayenne Arduino Client Library
Copyright � 2016 myDevices

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files(the "Software"), to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense, and / or sell copies of the Software,
and to permit persons to whom the Software is furnished to do so, subject to the following conditions :
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef _CAYENNEMQTTYUNCLIENT_h
#define _CAYENNEMQTTYUNCLIENT_h

#include <BridgeClient.h>
#include "CayenneArduinoMQTTClient.h"

class CayenneMQTTYunClient : public CayenneArduinoMQTTClient
{
public:
	/**
	* Begins Cayenne session
	* @param username Cayenne username
	* @param password Cayenne password
	* @param clientID Cayennne client ID
	*/
	void begin(const char* username, const char* password, const char* clientID)
	{
		Bridge.begin();
		CayenneArduinoMQTTClient::begin(_bridgeClient, username, password, clientID);
	}

private:
	BridgeClient _bridgeClient;
};

CayenneMQTTYunClient Cayenne;

#endif