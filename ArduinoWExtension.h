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
