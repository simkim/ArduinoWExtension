#include <Wire.h>
#include <ArduinoWExtension.h>

#define BAUDRATE 19200

ArduinoWNunchuk Nunchuk = ArduinoWNunchuk();

void setup()
{
  Serial.begin(BAUDRATE);
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

