/*
  FILENAME:   BMEShield_Thermistor.ino
  AUTHOR:     Orlando S. Hoilett
  CONTACT:    orlandohoilett@gmail.com
  VERSION:    0.0
  WEBSITE:    http://calveng.io/
  
  
  AFFILIATIONS:
  Calvary Engineering LLC, West Lafayette, IN USA
  "A group of makers who like to 'have a little fun and save the
  world while we're at it'" (C) Orlando Hoilett, 2017


  UPDATES:
  Version 0.0
  2017/03/26:2333>
      Release version for Hackster Arduino 101 Challenge.
      Slightly modified code to change a few variable names to
      fit my preferred naming conventions. Code source from
      wired746. "Re: Thermistor in Arduino Sidekick Basic Kit."


  DESCRIPTION
  Simple example for measuring ambient temperature data using
  a thermistor in a voltage divider circuit. The output of the
  ambient temperature sensor is on Analog In 1.
  
  
  The MIT License (MIT)
  Copyright (c) 2017 Orlando Hoilett
  
*/

#include <math.h>

const int thermistor = A1;
const double thermr = 10000; // thermistor nominal resistance
const double AREF = 3.3; //ADC reference voltage
const double resolution = 1023; //ADC resolution of Arduino 101
const double R2 = 10200; //10.2k resistor, the other resistor in
                         //the voltage divider

double getTemp(int RawADC)
{
  long Resistance;
  float Temp; // Dual-Purpose variable to save space.
  
  Resistance=((resolution * R2 / RawADC) - R2);
  Temp = log(Resistance); // Saving the Log(resistance) so not to calculate it 4 times later
  Temp = 1 / (0.001129148 + (0.000234125 * Temp) + (0.0000000876741 * Temp * Temp * Temp));
  Temp = Temp - 273.15; // Convert Kelvin to Celsius 
  //Temp = (Temp * 9.0)/ 5.0 + 32.0; // Convert to Fahrenheit comment out for Celsius
  return Temp; // Return the Temperature
}


void setup()
{
  Serial.begin(9600);
  while(!Serial);
}

void loop()
{
  float temp;
  temp=getTemp(analogRead(thermistor)); // read ADC and convert it
  Serial.print("Celsius: "); // comment and uncomment the desired reading
  //Serial.print("Fahrenheit: "); 
  Serial.print(temp,1); // display Temp
  Serial.println(""); 
  delay(1000); // Delay time to read 
}


/*Personal Annotations
Source:
wired746. "Re: Thermistor in Arduino Sidekick Basic Kit."
  SeeedstudioForum. phpBB, 3 Nov. 2012. Web. 16 May 2013.
  <http://www.seeedstudio.com/forum/viewtopic.php?f=4&t=2117&p=7695&hilit=sidekick+basic+kit#p7695>.
*/


/*
* Inputs ADC Value from Thermistor and outputs Temperature in Celsius
* requires: include <math.h>
* Utilizes the Steinhart-Hart Thermistor Equation:
* Temperature in Kelvin = 1 / {A + B[ln(R)] + C[ln(R)]3}
* where A = 0.001129148, B = 0.000234125 and C = 8.76741E-08
*
*
* Schematic:
* [Ground] -- [10k-pad-resistor] -- | -- [thermistor] --[Vcc (5 or 3.3v)]
************************************** |
* **********************************Analog Pin 0
*
*
* The resistance calculation uses the ratio of the two resistors, so the voltage
* specified above is really only required for the debugging that is commented out below
*
* Resistance = (1024 * PadResistance/ADC) - PadResistor 
*
*/


/*
  The MIT License (MIT)
  Copyright (c) 2016 Orlando Hoilett
  
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
