#include <Wire.h>
#include <sfm3200.h>

const int I2C_ADDRESS = 64;
SFM3200 massFlowMeter(I2C_ADDRESS);
const float SAMPEL_RATE_SEKUND = 0.1;
const float ADC_MAX = 1023.0;
const float MIN_RAW_PRESSURE_ADC = ADC_MAX * 0.1;
const float MAX_RAW_PRESSURE_ADC = ADC_MAX * 0.9;
const float MIN_PRESSURE_MM_H2O = -703.06957829636;
const float MAX_PRESSURE_MM_H2O = 703.06957829636;
float zeroCalibrationValueFlowMilliLiterPerSekund = 0.35;
float zeroCalibrationValuePressuremmH2O = 2.5;
float volumeInTheLung_ml = 0.0;
float offsetFlow; // 32768 offset flow for the Mass Flow Meter SFM3200 sensor
float scaleFactorFlow; // scale factor flow for 120.0 Air, N2 140.0, O2 142.8

void setup() {
  massFlowMeter.initialize();
  Serial.begin(9600);
  delay(500); // let serial console settle
  Serial.println("ml/s ml_in_lung mmH2O");
  offsetFlow = massFlowMeter.getOffset();
  scaleFactorFlow = massFlowMeter.getScaleFactor();
  massFlowMeter.startFlowMeasurement();
}

void loop() {
  float messuredFlowMilliLiterPerSekund = getFlowMilliLiterPerSekund();
  Serial.print(messuredFlowMilliLiterPerSekund);
  Serial.print(",");
  Serial.print(getVolumeInTheLung_ml(messuredFlowMilliLiterPerSekund));
  Serial.print(",");
  float messuredPressuremmH2O = getPressuremmH2O();
  Serial.println(messuredPressuremmH2O);
  //evaluateCommands(messuredFlowMilliLiterPerSekund, messuredPressuremmH2O);
  delay(SAMPEL_RATE_SEKUND * 1000);
}

/*
void evaluateCommands(float messuredFlowMilliLiterPerSekund, float messuredPressuremmH2O) {
  if (Serial.available() > 0) {
    byte aByte = Serial.read();
    //Serial.println(aByte);
    if (aByte == 99) { // c
      zeroCalibrationValueFlowMilliLiterPerSekund = zeroCalibrationValueFlowMilliLiterPerSekund + (messuredFlowMilliLiterPerSekund * -1.0);
      zeroCalibrationValuePressuremmH2O = zeroCalibrationValuePressuremmH2O + (messuredPressuremmH2O * - 1.0);
      aByte = -1;
    }
    if (aByte == 114) { // r
      volumeInTheLung_ml = 0.0;
      aByte = -1;
    }
  }
}
*/

float getVolumeInTheLung_ml(float messuredFlowMilliLiterPerSekund) {
  volumeInTheLung_ml = volumeInTheLung_ml + (SAMPEL_RATE_SEKUND * messuredFlowMilliLiterPerSekund);
  return volumeInTheLung_ml;
}

float scaleValue(float RawValue, float MinRaw, float MaxRaw, float MinEU, float MaxEU) {
  float EUValue = (RawValue - MinRaw) * ((MaxEU - MinEU) / (MaxRaw - MinRaw)) + MinEU;
  return EUValue;
}

float getFlowMilliLiterPerSekund() {
  float messuredValue = massFlowMeter.getvalue();
  float messuredFlowLiterPerMin = ((messuredValue - offsetFlow) / scaleFactorFlow);
  float messuredFlowMilliLiterPerSekund = (messuredFlowLiterPerMin * 1000 / 60) + zeroCalibrationValueFlowMilliLiterPerSekund;
  return messuredFlowMilliLiterPerSekund;
}

float getPressuremmH2O() {
  float RawValue = analogRead(0);
  float EUValue = scaleValue(RawValue, MIN_RAW_PRESSURE_ADC, MAX_RAW_PRESSURE_ADC, MIN_PRESSURE_MM_H2O, MAX_PRESSURE_MM_H2O);
  return EUValue + zeroCalibrationValuePressuremmH2O;
}
