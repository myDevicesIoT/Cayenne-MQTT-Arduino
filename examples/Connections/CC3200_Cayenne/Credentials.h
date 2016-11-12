///
/// @file		Credentials.h
/// @brief		Header
/// @details	Credentials for IoT
/// @n
/// @n @b		Project GetMacAddress
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		ReiVilo
/// @author		ReiVilo
///
/// @date		02/09/2015 12:32
/// @version	101
///
/// @copyright	(c) ReiVilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
///


// Core library for code-sense - IDE-based
#if defined(ENERGIA) // LaunchPad specific
#include "Energia.h"
#else // error
#   error Platform not defined
#endif // end IDE


#ifndef Credentials_h
#define Credentials_h

///
/// @brief	Network name = SSID
///
char ssidWiFi[] = "ssidWiFi";

///
/// @brief	Network password
///
char passwordWiFi[] = "passwordWiFi";

///
/// @brief	User name, given by Cayenne
///
char usernameCayenne[] = "usernameCayenne";

///
/// @brief	Password, given by Cayenne
///
char passwordCayenne[] = "passwordCayenne";

///
/// @brief	Client ID, given by Cayenne
///
char clientIDCayenne[] = "clientIDCayenne";


#endif // end Credentials_h
