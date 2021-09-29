#ifndef AD5328_NH_H
#define AD5328_NH_H

#include "Arduino.h"
#include "SPI.h"

#define AD5328_DAC_A 0b0000 << 12
#define AD5328_DAC_B 0b0001 << 12
#define AD5328_DAC_C 0b0010 << 12
#define AD5328_DAC_D 0b0011 << 12
#define AD5328_DAC_E 0b0100 << 12
#define AD5328_DAC_F 0b0101 << 12
#define AD5328_DAC_G 0b0110 << 12
#define AD5328_DAC_H 0b0111 << 12

typedef enum
{
	DAC_A_ = AD5328_DAC_A,
	DAC_B_ = AD5328_DAC_B,
	DAC_C_ = AD5328_DAC_C,
	DAC_D_ = AD5328_DAC_D,
	DAC_E_ = AD5328_DAC_E,
	DAC_F_ = AD5328_DAC_F,
	DAC_G_ = AD5328_DAC_G,
	DAC_H_ = AD5328_DAC_H,
} DAC_t;

class AD5328
{
public:
	AD5328(int cs_pin);
	void begin();
	void write(DAC_t dac, int v_out_bit); // 動かすDAC(DAC_A～DAC_H)と出力(0～4096)を入力

private:
	int cs = SS;

	void set();
	void reset();
};

#endif
