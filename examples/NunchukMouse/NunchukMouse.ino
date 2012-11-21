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

ArduinoWNunchuk Nunchuk;

void setup()
{
  Serial.begin(19200);
	while (!Serial) {}; // Leonardo
	Wire.begin();
  Mouse.begin();
  Nunchuk.begin();
}

void loop()
{
  Nunchuk.update();

  if (Nunchuk.button_z && !Mouse.isPressed(MOUSE_LEFT))
    Mouse.press(MOUSE_LEFT);
  if (Nunchuk.button_c && !Mouse.isPressed(MOUSE_RIGHT))
    Mouse.press(MOUSE_RIGHT);
  if (!Nunchuk.button_z && Mouse.isPressed(MOUSE_LEFT))
    Mouse.release(MOUSE_LEFT);
  if (!Nunchuk.button_c && Mouse.isPressed(MOUSE_RIGHT))
    Mouse.release(MOUSE_RIGHT);
  int x = map(Nunchuk.joy.x, 27,  225, -10, 10);
  int y = map(Nunchuk.joy.y, 32,  224, -10, 10);
  if (x < 2 && x > -2)
    x = 0;
  if (y < 1 && y > -1)
    y = 0;
  Mouse.move(x, -y);
  delay(50);
}

