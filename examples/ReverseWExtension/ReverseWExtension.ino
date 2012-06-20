/*  
    Copyright (C) 2012 Gauthier Monserand

    This file is part of ArduinoWExtension.

    ArduinoWExtension is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    ArduinoWExtension is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ArduinoWExtension.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <Wire.h>
#include <ArduinoWExtension.h>

ArduinoWDebugger wdebugger = ArduinoWDebugger();

void setup()
{
  Serial.begin(19200);
	while (!Serial) {}; // Leonardo
	Wire.begin();
	Serial.println("Press any key to dump data packet");
  wdebugger.begin();

}

void loop()
{
	if (!Serial.available()) {
		return;
	}
	while(Serial.available()) {
		Serial.read();
	}
  wdebugger.update();
}

