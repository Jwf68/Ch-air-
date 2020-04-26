/*
  SFM3200.cpp - Library for reading values from flowmeter Sensirion SFM3200
*/

#ifndef SFM3200_h
#define SFM3200_h
 
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif

// constants
#define READ_OFFSET 0x30DF
#define READ_SCALE_FACTOR 0x30DE
#define START_FLOW_MEASUREMENT 0x1000
#define POLYNOMIAL 0x131
#define CHECKSUM_ERROR 0X04

class SFM3200 {
  public:
	SFM3200::SFM3200(int i2cAddress);
	void SFM3200::initialize();
	float SFM3200::getOffset();
	float SFM3200::getScaleFactor();
	void SFM3200::startFlowMeasurement();
    float SFM3200::getvalue();

private:
	void SFM3200::writeWord();
	int mI2cAddress;
	void SFM3200::writeWord(uint16_t wordToWrite);
	uint8_t SFM3200::checkCrc(uint8_t data[], uint8_t nbrOfBytes, uint8_t checksum);
};
 
#endif
