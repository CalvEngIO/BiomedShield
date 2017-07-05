/*
 * FILENAME:	ADPS9200.cpp
 * AUTHOR:	Trevor D. Meyer
 * EMAIL:	mail2trevorm@gmail.com
 * VERSION:	0.0
 *
 *
 * AFFILIATIONS
 * Calvary Engineering Family Group, USA
 *	A group of electronics and science enthusiasts who enjoy building things
 *
 *
 * DESCRIPTION
 * This source file provides function definitions for controlling the ADPS-9200.
 * This is a very basic code that allows the user to declare a Light Sensor object
 * and programmatically read UV and ambient light readings along with adjusting 
 * settings of the chip. This library utilizes high level Arduino functions.
 *
 * UPDATES
 * Version 0.0
 * 2017/07/04:2000>
 *			Started writing the code. 
 *
 *
 * DISCLAIMER
 * This code is in the public domain. Please feel free to use, modify, distribute,
 * etc. as needed, but please give reference to original author as a courtesy to
 * open source developing/-ers.
 *
 * If you find any bugs in the code, or have any questions, please feel free to
 * contact me.
 */
 
 // OVERALL QUESTIONS
 // Not sure how to handle Adjustable Measurement Rate
 // Not sure how to handle Adjustable Gain
 // Still need to find a way to convert raw data to wavelength?
 //   (or is that what the sensor gives me?)
 
 #include "ADPS9200.h"
 #include "Arduino.h"
 #include <Wire.h>
 
 
 //Constructors
 //*****************************************************************************
 
 
 //Default Constructor
 Light::Light
 {
 }
 
 //Light(int intrpPin)
 //This method is a constructor that allows the user to set the pin
 //that will be connected to the chip interrupt functionality
 Light::Light(int intrpPin)
 {
	 interruptPin = intrpPin;
 }
 
 
 //Public Functions
 //*****************************************************************************
 
 
 //int readLight()
 //Reads a single ambint light measurement raw value (filtered by chip logic)
 int Light::readLight();
 {
	// Enable and set chip to read Ambient Light
	 Wire.beginTransmission(ADPS9200_ADDRESS);
	 
	 Wire.write(0x02);  //Sets value 00000010
	 
	 Wire.endTransmission();
	 
	 
	// FIXME Do I need a wait time????
	// Note: Default measurement rate is 100 ms, goes up to 2000 ms
	
	// Reads light value
	 Wire.requestFrom(ADPS9200_REGISTER_ALS_DATA_0, 3);
	 
	 if ( Wire.available() )
		 int light = read3bit();
	 
	 else
		 return 0;
	 
	 
	// Put chip in standby
	 Wire.beginTransmission(ADPS9200_ADDRESS);
	 
	 Wire.write(0x00);  //Sets value 00000000
	 
	 Wire.endTransmission();
	 
	 
	 return light;
 }
 
 
 //int readLight()
 //Reads a single UV light measurement raw value (filtered by chip logic)
 int Light::readUV();
 {
	// Enable and set chip to read UV Light
	 Wire.beginTransmission(ADPS9200_ADDRESS);
	 
	 Wire.write(0x0A);  //Sets value 00001010
	 
	 Wire.endTransmission();
	 
	 
	// FIXME Do I need a wait time????
	// Note: Default measurement rate is 100 ms, goes up to 2000 ms
	
	// Reads UV Light value
	 Wire.requestFrom(ADPS9200_REGISTER_UVS_DATA_0, 3);
	 
	 if ( Wire.available() )
		 int light = read3bit();
	 
	 else
		 return 0;
	 
	 
	// Put chip in standby
	 Wire.beginTransmission(ADPS9200_ADDRESS);
	 
	 Wire.write(0x08);  //Sets value 00001000
	 
	 Wire.endTransmission();
	 
	 
	 return light;
 }
 
 
 //int readLightUnfiltered()
 //Reads a single ambint light measurement unfiltered raw value
 //The filtered value and offset are red, then the offset is added
 //back into the read value.
 int Light::readLightUnfiltered();
 {
	// Enable and set chip to read Ambient Light
	 Wire.beginTransmission(ADPS9200_ADDRESS);
	 
	 Wire.write(0x02);  //Sets value 00000010
	 
	 Wire.endTransmission();
	 
	 
	// FIXME Do I need a wait time????
	// Note: Default measurement rate is 100 ms, goes up to 2000 ms
	
	// Reads Light Value
	 Wire.requestFrom(ADPS9200_REGISTER_ALS_DATA_0, 3);
	 
	 if ( Wire.available() )
		 int filtered_data = read3bit();
	 
	 else
		 return 0;
	 
	// Reads offset value
	 Wire.requestFrom(ADPS9200_REGISTER_COMP_DATA_0, 3);
	 
	 if ( Wire.available() )
		 int comp = read3bit();
	 
	 else
		 return 0;
	 
	
	// Put chip in standby
	 Wire.beginTransmission(ADPS9200_ADDRESS);
	 
	 Wire.write(0x00);  //Sets value 00000000
	 
	 Wire.endTransmission();
	 
	 
	 return filtered_data + comp;
 }
 
 
 //int readUVUnfiltered()
 //Reads a single UV light measurement unfiltered raw value
 //The filtered value and offset are red, then the offset is added
 //back into the read value.
 int Light::readUVUnfiltered();
 {
	// Enable and set chip to read UV Light
	 Wire.beginTransmission(ADPS9200_ADDRESS);
	 
	 Wire.write(0x0A);  //Sets value 00001010
	 
	 Wire.endTransmission();
	 
	 
	// FIXME Do I need a wait time????
	// Note: Default measurement rate is 100 ms, goes up to 2000 ms
	
	// Reads UV Light Value
	 Wire.requestFrom(ADPS9200_REGISTER_UVS_DATA_0, 3);
	 
	 if ( Wire.available() )
		 int filtered_data = read3bit();
	 
	 else
		 return 0;
	 
	// Reads offset value
	 Wire.requestFrom(ADPS9200_REGISTER_UVS_COMP_DATA_0, 3);
	 
	 if ( Wire.available() )
		 int comp = read3bit();
	 
	 else
		 return 0;
	 
	 
	// Put chip in standby
	 Wire.beginTransmission(ADPS9200_ADDRESS);
	 
	 Wire.write(0x08);  //Sets value 00001000
	 
	 Wire.endTransmission();
	 
	 
	 return filtered_data + comp;
 }
 
 
 //----------------------------------------------
 // Functions Dealing with Interrupt
 //----------------------------------------------
 
 void Light::setLightInterrupt();
 {
	 
 }
 
 
 void Light::enableLightInterrupt();
 {
	 
 }
 
 
 void Light::disableLightInterrupt();
 {
	 
 }

 
 void Light::setUVInterrupt();
 {
	 
 }
 
 
 void Light::enableUVInterrupt();
 {
	 
 }
 
 
 void Light::disableUVInterrupt();
 {
	 
 }
 
 
 void Light::setUVInterruptVar();
 {
	 
 }
 
 
 void Light::enableUVInterruptVar();
 {
	 
 }
 
 
 void Light::disableUVInterruptVar();
 {
	 
 }
 
 
 void Light::setLightInterruptVar();
 {
	 
 }
 
 
 void Light::enableLightInterruptVar();
 {
	 
 }
 
 
 void Light::disableLightInterruptVar();
 {
	 
 }
 
 
 //----------------------------------------------
 // Higher Level Functions
 //----------------------------------------------
 
 void Light::getUVIndex();
 {
	 // Is there a way to do this? Not sure how to define the object calling it
	 // from inside the class itself.  I found this syntax online but I'm not
	 // sure if it's completely right.
	 
	 int UV = this->readUV();
	 
	 // FIXME still need to find conversion for the index relationship
 }
 
 
 // Private Functions
 //*****************************************************************************
 
 int Light::read3bit()
 {
    int x = Wire.read();
    int y = Wire.read() << 4;
    int z = Wire.read() << 8;
    
    return ( x | y | z );    
 }