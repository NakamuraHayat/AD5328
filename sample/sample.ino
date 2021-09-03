
#include "AD5328_1.h"

int cs1 = 10;
int cs2 = 9;
AD5328 ad5328_1(cs1);
AD5328 ad5328_2(cs2);

float pres_MPa = 0.0;
float pres_bar = 0.0;
float V_amplofier = 0.0;
float V_DAC = 0.0;
float V_DAC_bit = 0.0;

int port = 0;

void valve(float pes_MPa, int port);

void setup() {
  Serial.begin(9600);
  ad5328_1.begin();
  ad5328_2.begin();
}

void loop() {
  /*if (Serial.available()) {
    pres_MPa = float(Serial.read());
    port = int(Serial.read());
  }*/
  
  valve(pres_MPa, port);
}

void valve(float pes_MPa, int port) {
  float pres_bar = 0.0;
  float V_amplifier = 0.0;
  float V_DAC = 0.0;
  float V_DAC_bit = 0.0;

  pres_bar = pres_MPa * 10.0;
  V_amplifier = pres_bar / 8.0 * 10.0;
  V_DAC = V_amplifier / 2.0; // Gain = 1 + R1 / R2, R1 = R2 = 10kΩ
  V_DAC_bit = V_DAC * 4096.0 / 5.0; // V_DAC = V_ref * V_DAC_bit / 2^N , V_ref = 5V, N = 12bit(分解能)

  switch (port) {
    case 0:
      ad5328_1.write(DAC_A, V_DAC_bit);
      break;

    case 1:
      ad5328_1.write(DAC_B, V_DAC_bit);
      break;

    case 2:
      ad5328_1.write(DAC_C, V_DAC_bit);
      break;

    case 3:
      ad5328_1.write(DAC_D, V_DAC_bit);
      break;

    case 4:
      ad5328_1.write(DAC_E, V_DAC_bit);
      break;

    case 5:
      ad5328_1.write(DAC_F, V_DAC_bit);
      break;

    case 6:
      ad5328_1.write(DAC_G, V_DAC_bit);
      break;

    case 7:
      ad5328_1.write(DAC_H, V_DAC_bit);
      break;

    case 8:
      ad5328_2.write(DAC_A, V_DAC_bit);
      break;

    case 9:
      ad5328_2.write(DAC_B, V_DAC_bit);
      break;

    case 10:
      ad5328_2.write(DAC_C, V_DAC_bit);
      break;

    case 11:
      ad5328_2.write(DAC_D, V_DAC_bit);
      break;

    case 12:
      ad5328_2.write(DAC_E, V_DAC_bit);
      break;

    case 13:
      ad5328_2.write(DAC_F, V_DAC_bit);
      break;

    case 14:
      ad5328_2.write(DAC_G, V_DAC_bit);
      break;

    case 15:
      ad5328_2.write(DAC_H, V_DAC_bit);
      break;

  }
  Serial.print(port);
  Serial.print(" -> ");
  Serial.println(pres_MPa);

}
