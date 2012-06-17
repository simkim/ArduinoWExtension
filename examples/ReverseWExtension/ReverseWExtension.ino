#include <Wire.h>
#include <ArduinoWExtension.h>

#define BAUDRATE 19200

ArduinoWDebugger wdebugger = ArduinoWDebugger();

void setup()
{
  Serial.begin(BAUDRATE);
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

