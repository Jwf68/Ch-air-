/*
  SFM3200.cpp - Library for reading values from flowmeter Sensirion SFM3200
*/

#include "SFM3200.h"
#include <Wire.h>

SFM3200::SFM3200(int i2cAddress) {
	mI2cAddress = i2cAddress;
}

void SFM3200::initialize() {
	Wire.begin();
}

void SFM3200::startFlowMeasurement() {
	writeWord(START_FLOW_MEASUREMENT);
	delay(1000);
	getvalue();
}

float SFM3200::getOffset() {
	writeWord(READ_OFFSET);
	return getvalue();
}

float SFM3200::getScaleFactor() {
	writeWord(READ_SCALE_FACTOR);
	return getvalue();
}

void SFM3200::writeWord(uint16_t wordToWrite) {
	Wire.beginTransmission(byte(mI2cAddress));
	Wire.write(byte(highByte(wordToWrite)));
	Wire.write(byte(lowByte(wordToWrite)));
	Wire.endTransmission();
	delay(5);
}

float SFM3200::getvalue() {
	Wire.requestFrom(mI2cAddress, 3); // read 3 bytes
	uint16_t firstReceivedByte = Wire.read();
	uint8_t secondReceivedByte = Wire.read();
	uint8_t checksumReceivedByte = Wire.read();
	uint8_t receivedData[2];
	receivedData[0] = firstReceivedByte;
	receivedData[1] = secondReceivedByte;
	if (checkCrc(receivedData, sizeof(receivedData)/sizeof(receivedData[0]), checksumReceivedByte) > 0) {
		Serial.println("Error: wrong CRC");
	}
	uint16_t combinedTwoReceivedBytes = (firstReceivedByte << 8) | secondReceivedByte;
	return combinedTwoReceivedBytes;
}

uint8_t SFM3200::checkCrc(uint8_t data[], uint8_t nbrOfBytes, uint8_t checksum) {
	uint8_t crc = 0;
	uint8_t byteCtr;
	//calculates 8-Bit checksum with given polynomial
	for (byteCtr = 0; byteCtr < nbrOfBytes; ++byteCtr) {
		crc ^= (data[byteCtr]);
		for (uint8_t bit = 8; bit > 0; --bit)
		{
			if (crc & 0x80) crc = (crc << 1) ^ POLYNOMIAL;
			else crc = (crc << 1);
		}
	}
	if (crc != checksum) return CHECKSUM_ERROR;
	else return 0;
}