/*
 FILENAME:	BiomedShield.h
 AUTHOR:	Orlando S. Hoilett
 EMAIL:


 Please see .cpp file for extended descriptions, instructions, and version updates
 
 
 DISCLAIMER

 The MIT License (MIT)

 (C) Copyright 6/20/17 by authors

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.


*/



#ifndef BiomedShield_h
#define BiomedShield_h


#include “Arduino.h”
#include "BME280.h"


class BiomedShield
{
private:


public:

	//Default Constructor
	BiomedShield();
    
    
    int getPulse();
    int getRespiration();
    int getEXG();
    
    calcHR();
    
    double getHumidity();

    
    
    
    /*
     
     pseudocode
     
     
     **(ambient) temperature sensor
     **humidity sensor - SHT30-ARP-B - $2.50
     **human body temperature - $2 - MAX30
     **barometric pressure - BMP280 - $2.50
     
     **ambient light sensor
     **UV sensor --
     
	 Arduino-capable: https://www.digikey.com/product-detail/en/vishay-semiconductor-opto-division/VEML6070/VEML6070CT-ND/5171286 - $2.77
	        (UV sensor but no light sensor)
	 UV and Light Sensor: http://www.mouser.com/ProductDetail/Silicon-Labs/SI1132-A10-GMR/?qs=sGAEpiMZZMsB9HsreUc%252bifOGjEN2inPtTn4xL1ddrZ8%3d - $2.14
	 UV and Light sensor: http://www.mouser.com/ProductDetail/Broadcom-Limited/APDS-9200/?qs=%2fha2pyFaduhqU9Kf5MdtHTZHc8m6Q4v1JYaTc%252bdOVH2H4RPVKOftMA%3d%3d - $ 1.90
	 
	 If you get the arduino-capable sensor, there are a million light sensor chips for $1 or less
	 
     pulse sensor  - Arduino pulse sensor circuit - $2.00 (copy and paste from pulseFit BOM)
     respiration sensor - arduino pulse sensor circuit - $1
     
     EXG circuit - super simple EXG circuit - $3
     
     **bioimpedance circuit - DAC, OTA, Super Simple EXG circuit, analog switch - $2
     
     **chemical sensing - $3
     
     These should be Arduino 101 functions
     accelerometer
     gyro
     
     contact sensor
     
     touch sensor
     
     capacitive touch
     
     BLE
     
     
     powering
     coin cell for bioimpedance circuit
     
     
     cost analysis
     cost (BOM-extended)
     already arduino library
     simplicity of the library
     analog output voltage that doenst need to be conditioned over digital output
     
     
     
     */
    
    
    

};



#endif /* BiomedShield_h */
