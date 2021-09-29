/* TODO: Serial.Read()で圧力とポートを変更できるようにする
*/

#include "AD5328_NH.h"

int cs1 = 10;
int cs2 = 9;
AD5328 ad5328_1(cs1);
AD5328 ad5328_2(cs2);

float pres_MPa = 0.0; // 0~0.8MPA
int valve_port = 0;   // 0~15

void valve(float pres_MPa, int valve_port);

void setup() {
  Serial.begin(9600);
  ad5328_1.begin();
  ad5328_2.begin();

  valve(pres_MPa, valve_port);

  Serial.print(valve_port);
  Serial.print(" -> ");
  Serial.println(pres_MPa);
}

void loop() {
  
}

void valve(float pres_MPa, int valve_port) {
  float pres_bar    = 0.0;
  float v_amplifier = 0.0;
  float v_dac       = 0.0;
  float v_dac_bit   = 0.0;

  pres_bar = pres_MPa * 10.0;
  v_amplifier = pres_bar / 8.0 * 10.0;
  v_dac = v_amplifier / 2.0;        // Gain = 1 + R1 / R2, R1 = R2 = 10kΩ
  v_dac_bit = v_dac * 4096.0 / 5.0; // V_DAC = V_ref * V_DAC_bit / 2^N , V_ref = 5V, N = 12bit(分解能)

  switch (valve_port) {
    case 0:
      ad5328_1.write(DAC_A_, v_dac_bit);
      break;
    case 1:
      ad5328_1.write(DAC_B_, v_dac_bit);
      break;
    case 2:
      ad5328_1.write(DAC_C_, v_dac_bit);
      break;
    case 3:
      ad5328_1.write(DAC_D_, v_dac_bit);
      break;
    case 4:
      ad5328_1.write(DAC_E_, v_dac_bit);
      break;
    case 5:
      ad5328_1.write(DAC_F_, v_dac_bit);
      break;
    case 6:
      ad5328_1.write(DAC_G_, v_dac_bit);
      break;
    case 7:
      ad5328_1.write(DAC_H_, v_dac_bit);
      break;
    case 8:
      ad5328_2.write(DAC_A_, v_dac_bit);
      break;
    case 9:
      ad5328_2.write(DAC_B_, v_dac_bit);
      break;
    case 10:
      ad5328_2.write(DAC_C_, v_dac_bit);
      break;

    case 11:
      ad5328_2.write(DAC_D_, v_dac_bit);
      break;

    case 12:
      ad5328_2.write(DAC_E_, v_dac_bit);
      break;

    case 13:
      ad5328_2.write(DAC_F_, v_dac_bit);
      break;

    case 14:
      ad5328_2.write(DAC_G_, v_dac_bit);
      break;

    case 15:
      ad5328_2.write(DAC_H_, v_dac_bit);
      break;
  }
}
