/* Play frets on fire with your guitar by usb */

#include <Wire.h>
#include <ArduinoWExtension.h>

ArduinoWGuitar Guitar = ArduinoWGuitar();

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

