/* GENERAL NOTES ON ADPS-9200 (sorry, I know this is really messy right now)
 * 
 * Address = 0x52  (7 bit addresss protocol)
 * 
 * The UV light sensor has to be operated independently from Ambient Light Sensor. To enable the reading of UV sensor, UVS_MODE
 * and LS_EN bit has to be correctly set in the MAIN_CTRL register. Setting the UVS_MODE bit will stop a running ALS measurement
 * and start a new UV sensor reading.
 * 
 * 3.3V Supply
 * 
 * 18 bit range
 * 
 * Standby is default after powerup
 * 
 * ALS measurements can be activated by setting the LS_EN bit
 * to 1 and the UVS_Mode bit to 0 in the MAIN_CTRL register.
 * 
 * UV measurements can be activated by setting the LS_EN bit to
 * 1 and the UVS_Mode bit to 1 in the MAIN_CTRL register
 * 
 * The LS interrupt is enabled by LS_INT_EN = 1. It can function as
 * either threshold triggered (LS_VAR_MODE = 0) or variance
 * trigged (LS_VAR_MODE = 1)
 * 
 * You have to use block read proocols
 *     This assures you don't read values from different conversions
 *
 */
 
 /*
 * FILENAME:	ADPS9200.h
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
 * This header file provides function declarations for controlling the ADPS-9200
 * chip which acts as a UV and ambient light sensor.
 * This is a very basic code that allows the user to declare a Light Sensor object
 * and programmatically read UV and ambient light readings along with adjusting 
 * settings of the chip. This library utilizes high level Arduino functions.
 *
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
 
 #ifndef ADPS9200_H
 #define ADPS9200_H
 
 // These were copied from somewhere else and slightly altered.  Not sure if needed.
 #if (ARDUINO >= 100)
	#include "Arduino.h"
 #endif
 
 #ifdef Wire.h  //FIXME I know this is wrong but not sure how to reference it.
	#include <Wire.h>
 #endif
 
 /*=========================================================================
    I2C ADDRESS/BITS/SETTINGS
    -----------------------------------------------------------------------*/
    #define ADPS9200_ADDRESS                (0x52)

/*=========================================================================
    REGISTERS
    -----------------------------------------------------------------------*/
    enum
    {
	  ADPS9200_REGISTER_MAIN_CTRL			= 0x00,	//(RW)
	  ADPS9200_REGISTER_LS_MEAS_RATE		= 0x04,	//(RW)
	  ADPS9200_REGISTER_LS_GAIN				= 0x05,	//(RW)
	  ADPS9200_REGISTER_PART_ID				= 0x06,	//(R )
	  ADPS9200_REGISTER_MAIN_STATUS			= 0x07,	//(R )
	  ADPS9200_REGISTER_ALS_DATA_0			= 0x0D,	//(R )
	  ADPS9200_REGISTER_ALS_DATA_1			= 0x0E,	//(R )
	  ADPS9200_REGISTER_ALS_DATA_2			= 0x0F,	//(R )
	  ADPS9200_REGISTER_UVS_DATA_0			= 0x10,	//(R )
	  ADPS9200_REGISTER_UVS_DATA_1			= 0x11,	//(R )
	  ADPS9200_REGISTER_UVS_DATA_2			= 0x12,	//(R )
	  ADPS9200_REGISTER_UVS_COMP_DATA_0		= 0x13,	//(R )
	  ADPS9200_REGISTER_UVS_COMP_DATA_1		= 0x14,	//(R )
	  ADPS9200_REGISTER_UVS_COMP_DATA_2		= 0x15,	//(R )
	  ADPS9200_REGISTER_COMP_DATA_0			= 0x16,	//(R )
	  ADPS9200_REGISTER_COMP_DATA_1			= 0x17,	//(R )
	  ADPS9200_REGISTER_COMP_DATA_2			= 0x18,	//(R )
	  ADPS9200_REGISTER_INT_CFG				= 0x19,	//(RW)
	  ADPS9200_REGISTER_INT_PERSISTNECE		= 0x1A,	//(RW)
	  ADPS9200_REGISTER_LS_THRES_UP_0		= 0x21,	//(RW)
	  ADPS9200_REGISTER_LS_THRES_UP_1		= 0x22,	//(RW)
	  ADPS9200_REGISTER_LS_THRES_UP_2		= 0x23,	//(RW)
	  ADPS9200_REGISTER_LS_THRES_LOW_0		= 0x24,	//(RW)
	  ADPS9200_REGISTER_LS_THRES_LOW_1		= 0x25,	//(RW)
	  ADPS9200_REGISTER_LS_THRES_LOW_2		= 0x26,	//(RW)
	  ADPS9200_REGISTER_LS_THRES_VAR		= 0x27,	//(RW)
    };

/*=========================================================================*/
 
 class LIGHT
 {
	 private:
	 
		int interruptPin;
	 
		int read3bit();
	 
	 public:
	 
		Light();
		Light(int intrpPin);
		
		// I currently just manually set the mode each time a reading
		// is requested.  Not necessarily the most efficient way, but
		// I thought it would be the most straightforward way for the
		// user.  You could have the user manually switch the UV or
		// Ambient light modes as well, depends on what you want.
		
		// Afterthought, we could have different read functions for
		// both of the above methods and let the user choose.  This
		// would allow them to take multple RAPID readings over a 
		// period of time.  I currently cannot think of a way to have
		// a function take an input number of readings all in a row.
		// (not sure how to return that data in a clean format)
		
		int readLight();
		int readUV();
		
		int readLightUnfiltered();
		int readUVUnfiltered();
		
		// Threshold Interrupt
		void setUVInterrupt();
		void enableUVInterrupt();
		void disableUVInterrupt();
		
		void setLightInterrupt();
		void enableLightInterrupt();
		void disableLightInterrupt();
		
		// Variance Interrupt
		void setUVInterruptVar();
		void enableUVInterruptVar();
		void disableUVInterruptVar();
		
		void setLightInterruptVar();
		void enableLightInterruptVar();
		void disableLightInterruptVar();
		
		// Higher Level Functions
		int getUVIndex();
 };
 
 #endif