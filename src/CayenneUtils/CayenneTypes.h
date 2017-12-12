/*
The MIT License(MIT)

Cayenne MQTT Client Library
Copyright (c) 2016 myDevices

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

#ifndef _CAYENNETYPES_h
#define _CAYENNETYPES_h

// Data types
#define TYPE_ACCELERATION "accel" // Acceleration, units: UNIT_G
#define TYPE_ANALOG_ACTUATOR "analog_actuator" // Analog Actuator, units: UNIT_ANALOG
#define TYPE_ANALOG_SENSOR "analog_sensor" // Analog Sensor, units: UNIT_ANALOG
#define TYPE_BAROMETRIC_PRESSURE "bp" // Barometric pressure, units: UNIT_PASCAL, UNIT_HECTOPASCAL
#define TYPE_BATTERY "batt" // Battery, units: UNIT_PERCENT, UNIT_RATIO, UNIT_VOLTS
#define TYPE_CO2 "co2" // Carbon Dioxide, units: UNIT_PPM
#define TYPE_COUNTER "counter" // Counter, units: UNIT_ANALOG
#define TYPE_CURRENT "current" // Current, units: UNIT_AMP, UNIT_MAMP
#define TYPE_DIGITAL_ACTUATOR "digital_actuator" // Digital Actuator, units: UNIT_DIGITAL
#define TYPE_DIGITAL_SENSOR "digital_sensor" // Digital Sensor, units: UNIT_DIGITAL
#define TYPE_ENERGY "energy" // Energy, units: UNIT_KWH
#define TYPE_EXT_WATERLEAK "ext_wleak" // External Waterleak, units: UNIT_ANALOG
#define TYPE_FREQUENCY "freq" // Frequency, units: UNIT_HERTZ
#define TYPE_GPS "gps" // GPS, units: UNIT_GPS
#define TYPE_GYROSCOPE "gyro" // Gyroscope, units: UNIT_ROTATION_PER_MINUTE, UNIT_DEGREE_PER_SEC
#define TYPE_LUMINOSITY "lum" // Luminosity, units: UNIT_LUX, UNIT_VOLTS, UNIT_PERCENT, UNIT_RATIO
#define TYPE_MOTION "motion" // Motion, units: UNIT_DIGITAL
#define TYPE_POWER "pow" // Power, units: UNIT_WATT, UNIT_KILOWATT
#define TYPE_PROXIMITY "prox" // Proximity, units: UNIT_CENTIMETER, UNIT_METER, UNIT_DIGITAL
#define TYPE_RAIN_LEVEL "rain_level" // Rain Level, units: UNIT_CENTIMETER, UNIT_MILLIMETER
#define TYPE_RELATIVE_HUMIDITY "rel_hum" // Relative Humidity, units: UNIT_PERCENT, UNIT_RATIO
#define TYPE_RESISTANCE "res" // Resistance, units: UNIT_OHM
#define TYPE_RSSI "rssi" // Received signal strength indicator, units: UNIT_DBM
#define TYPE_SNR "snr" // Signal Noise Ratio, units: UNIT_DB
#define TYPE_SOIL_MOISTURE "soil_moist" // Soil Moisture, units: UNIT_PERCENT
#define TYPE_SOIL_PH "soil_ph" // Soil pH, units: UNIT_ANALOG
#define TYPE_SOIL_WATER_TENSION "soil_w_ten" // Soil Water Tension, units: UNIT_KILOPASCAL, UNIT_PASCAL
#define TYPE_TANK_LEVEL "tl" // Tank Level, units: UNIT_ANALOG
#define TYPE_TEMPERATURE "temp" // Temperature, units: UNIT_FAHRENHEIT, UNIT_CELSIUS, UNIT_KELVIN
#define TYPE_VOLTAGE "voltage" // Voltage, units: UNIT_VOLTS, UNIT_MILLIVOLTS
#define TYPE_WIND_SPEED "wind_speed" // Wind Speed, units: UNIT_KM_PER_H

#define MAX_TYPE_LENGTH 16

// Unit types
#define UNIT_UNDEFINED "null" // Undefined unit type
#define UNIT_AMP "a" // Ampere
#define UNIT_ANALOG "null" // Analog
#define UNIT_CELSIUS "c" // Celsius
#define UNIT_CENTIMETER "cm" // Centimeter
#define UNIT_DB "db" // Decibels
#define UNIT_DBM "dbm" // dBm
#define UNIT_DEGREE_PER_SEC "dps" // Degree per second
#define UNIT_DIGITAL "d" // Digital (0/1)
#define UNIT_FAHRENHEIT "f" // Fahrenheit
#define UNIT_G "g" // Acceleration
#define UNIT_GPS "m" // GPS
#define UNIT_HECTOPASCAL "hpa" // Hectopascal
#define UNIT_HERTZ "hz" // Hertz
#define UNIT_KELVIN "k" // Kelvin
#define UNIT_KILOPASCAL "kpa" // Kilopascal
#define UNIT_KILOWATT "kw" // Kilowatts
#define UNIT_KM_PER_H "kmh" // Kilometer per hour
#define UNIT_KWH "kwh" // Killowatt Hour
#define UNIT_LUX "lux" // Lux
#define UNIT_MAMP "ma" // Milliampere
#define UNIT_METER "m" // Meter
#define UNIT_MILLIMETER "mm" // Millimeter
#define UNIT_MILLIVOLTS "mv" // Millivolts
#define UNIT_OHM "ohm" // Ohm
#define UNIT_PASCAL "pa" // Pascal
#define UNIT_PERCENT "p" // Percent (%)
#define UNIT_PPM "ppm" // Parts per million
#define UNIT_RATIO "r" // Ratio
#define UNIT_ROTATION_PER_MINUTE "rpm" // Rotation per minute
#define UNIT_VOLTS "v" // Volts
#define UNIT_WATT "w" // Watts

#define MAX_UNIT_LENGTH 4

#endif
