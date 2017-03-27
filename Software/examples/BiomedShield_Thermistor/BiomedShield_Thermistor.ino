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
  2017/03/26:2345>
      Release version for Hackster Arduino 101 Challenge


  DESCRIPTION
  Simple example for measuring ambient temperature sensor data
  using a photoresistor in a voltage divider circuit. The output
  of the ambient temperature sensor is on Analog In 1.
  
  
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

const int thermistor = A1; //analog input
const double AREF = 3.3; //ADC reference voltage
const double resolution = 1023; //ADC resolution of Arduino 101

void setup()
{
  Serial.begin(9600);
  while(!Serial);
}

void loop()
{
  int x = analogRead(thermistor);
  double volts = (x/resolution)*AREF;
  Serial.println(volts);
  delay(750);
}
