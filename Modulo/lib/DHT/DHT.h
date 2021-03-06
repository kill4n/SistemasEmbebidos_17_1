#ifndef DHT_H
#define DHT_H
 #include "Arduino.h"
#include "Energia.h"

#define ERR 0

/* DHT library 

MIT license
written by Adafruit Industries
*/

// how many timing transitions we need to keep track of. 2 * number bits + extra
#define MAXTIMINGS 85

#define DHT11 11
#define DHT22 22
#define DHT21 21
#define AM2301 21

class DHT {
 private:
  uint8_t data[6];
  uint8_t _pin, _type;
  boolean read(void);
  unsigned long _lastreadtime;
  boolean firstreading;

 public:
  DHT(uint8_t pin, uint8_t type);
  void begin(void);
  float readTemperature(void);
  float convertCtoF(float);
  float readHumidity(void);

};
#endif
