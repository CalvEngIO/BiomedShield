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
    
    
    int getPulse();  // How long does it read for? Make this an option to improve accuracy?
    int getRespiration(); // ^^
    int getEXG();  // ^^
    
    calcHR();
    
    double getHumidity();
	double getBodyTemp();
	
	// Bioimpedance Functions??
	// Chemical Sensing Functions??
	// Can't find MAX-30 chip
	
	
	// I'm assuming we don't include ardino101 functions in this header file:
	/*		accelerometer
			gyro
			
			contact sensor
			
			touch sensor
			
			capacitive touch
			
			BLE
	*/
	
	//----------------------------------
	// ADPS-9200
	//----------------------------------
	
	long getLight();
	long getUV();
	void standby();
	
	long getLightUnfiltered();
	long getUVUnfiltered();
	
	bool setInterruptPersistence(int numgetings);
	
	// Threshold Interrupt
	void setLightInterrupt(int upper, int lower);
	void setLightInterruptUpper(int upper);
	void setLightInterruptLower(int lower);
	void enableLightInterrupt();
	void disableLightInterrupt();
	
	void setUVInterrupt(int upper, int lower);
	void setUVInterruptUpper(int upper);
	void setUVInterruptLower(int lower);
	void enableUVInterrupt();
	void disableUVInterrupt();
	
	// Variance Interrupt
	void setLightInterruptVar(int var);
	void enableLightInterruptVar();
	void disableLightInterruptVar();
	
	void setUVInterruptVar(int var);
	void enableUVInterruptVar();
	void disableUVInterruptVar();
	
	// Higher Level Functions
	int getUVIndex();
	
	
	//-----------------------------------
	// BMP-280
	//-----------------------------------
	
	Adafruit_BMP280();
    Adafruit_BMP280(int8_t cspin);
    Adafruit_BMP280(int8_t cspin, int8_t mosipin, int8_t misopin, int8_t sckpin);

    bool  begin(uint8_t addr = BMP280_ADDRESS, uint8_t chipid = BMP280_CHIPID);
    float getTemp(void);
    float getPressure(void);
    float getAltitude(float seaLevelhPa = 1013.25);
    
    
    
    /*
     
     pseudocode
     
     
     **(ambient) temperature sensor - BMP280
     **humidity sensor - SHT30-ARP-B - $2.50
     **human body temperature - $2 - MAX30 ?????????
     **barometric pressure - BMP280 - $2.50
     
     **ambient light sensor
     **UV sensor --
     
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
