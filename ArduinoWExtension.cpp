#include <Arduino.h>
#include <Wire.h>
#include "ArduinoWExtension.h"

void ArduinoWExtension::begin()
{      
  write(0x55, 0xF0);
  write(0x00, 0xFB); 
	update();
}
    
bool ArduinoWExtension::update()
{ 
  int count = 0;      
	wpacket_t packet;
  
  Wire.requestFrom (0x52, 6); 
  
	for (int i = 0; i < 6; i++) {
  	if (!Wire.available())
			return false;
    packet[i] = Wire.read();
  } 
	decode(packet);
  write(0x00, 0x00);
}
 
void ArduinoWExtension::write(uint8_t data, uint8_t location)
{  
  Wire.beginTransmission(0x52);
  Wire.write(location);
  Wire.write(data);  
  Wire.endTransmission();
  
  delay(10);
}

#define WPACKET_BIT(byte, bit) !((packet[byte] >> bit) & 1)

void ArduinoWNunchuk::decode(const wpacket_t packet) {
  joy.x = packet[0];
  joy.y = packet[1];      
  giro.x = packet[2] << 2 + WPACKET_BIT(5, 2) << 1 + WPACKET_BIT(5, 3);
  giro.x = packet[3] << 2 + WPACKET_BIT(5, 4) << 1 + WPACKET_BIT(5, 5);
  giro.x = packet[3] << 2 + WPACKET_BIT(5, 6) << 1 + WPACKET_BIT(5, 7);
  button_z = WPACKET_BIT(5, 0);
  button_c = WPACKET_BIT(5, 1);
}


void ArduinoWGuitar::decode(const wpacket_t packet) {
	button_p = WPACKET_BIT(4, 2);
	button_l = WPACKET_BIT(4, 4);
	button_g = WPACKET_BIT(5, 4);
	button_r = WPACKET_BIT(5, 6);
	button_y = WPACKET_BIT(5, 3);
	button_b = WPACKET_BIT(5, 5);
	button_o = WPACKET_BIT(5, 7);
	button_sd = WPACKET_BIT(4, 6);
	button_su = WPACKET_BIT(5, 0);
  joy.x = (packet[0]&63)-32;
  joy.y = (packet[1]&63)-32;      
	whammy_bar = (packet[3])&15;
}

void ArduinoWDebugger::decode(const wpacket_t packet) {
	for (uint8_t i = 0; i < 6; i++) {
		uint8_t j = packet[i];
		uint8_t k = 8;
		while (j) {
			j = j >> 1;
			k--;
		};
		if (k == 8) { k--; }
		while(k) { Serial.print("0"); k--; }
		Serial.print(packet[i], BIN);
		Serial.print(" ");
	}
	Serial.println("");
}
