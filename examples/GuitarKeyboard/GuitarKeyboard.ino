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

/* Play frets on fire with your guitar by usb */

#include <Wire.h>
#include <ArduinoWExtension.h>

ArduinoWGuitar Guitar;

void setup()
{
  Wire.begin();
  Keyboard.begin();
  Guitar.begin();
}

void loop()
{
  Guitar.update();
  if (Guitar.joy.y > 15) Keyboard.press(KEY_UP_ARROW); else Keyboard.release(KEY_UP_ARROW);
  if (Guitar.joy.y < -15) Keyboard.press(KEY_DOWN_ARROW); else Keyboard.release(KEY_DOWN_ARROW);
  if (Guitar.button_l) Keyboard.press(KEY_ESC); else Keyboard.release(KEY_ESC);
  if (Guitar.button_g) Keyboard.press(KEY_F1); else Keyboard.release(KEY_F1);
  if (Guitar.button_r) Keyboard.press(KEY_F2); else Keyboard.release(KEY_F2);
  if (Guitar.button_y) Keyboard.press(KEY_F3); else Keyboard.release(KEY_F3);
  if (Guitar.button_b) Keyboard.press(KEY_F4); else Keyboard.release(KEY_F4);
  if (Guitar.button_o) Keyboard.press(KEY_F5); else Keyboard.release(KEY_F5);
  if (Guitar.button_sd || Guitar.button_su) Keyboard.press(KEY_RETURN); else Keyboard.release(KEY_RETURN);
}

