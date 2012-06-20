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

#ifndef ARDUINOWEXTENSION_H_
#define ARDUINOWEXTENSION_H_

#include <Arduino.h>

class ArduinoWJoystick {
	public:
		int x;
		int y;
};

class ArduinoWGiro {
	public:
		int x;
		int y;
		int z;
};

typedef uint8_t wpacket_t[6];

class ArduinoWExtension
{
  public:
    void begin();
    bool update();
  private:  
    virtual void decode(const wpacket_t packet) = 0;
    void write(uint8_t data, uint8_t location);
};

class ArduinoWNunchuk : public ArduinoWExtension
{  
  public:  
    ArduinoWJoystick	joy;
		ArduinoWGiro			giro;
    uint8_t 					button_z;
    uint8_t						button_c;
	private:
    virtual void decode(const wpacket_t packet);
};

class ArduinoWGuitar : public ArduinoWExtension
{
  public:
		ArduinoWJoystick	joy;
		uint8_t						button_p;
		uint8_t						button_l;
		uint8_t						button_g;
		uint8_t						button_r;
		uint8_t						button_y;
		uint8_t						button_b;
		uint8_t						button_o;
		uint8_t						button_sd;
		uint8_t						button_su;
		uint8_t						whammy_bar;
  private:
    virtual void decode(const wpacket_t packet);
};

class ArduinoWDebugger : public ArduinoWExtension
{ 
  private:
    virtual void decode(const wpacket_t packet);
};

#endif
