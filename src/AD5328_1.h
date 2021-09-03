#ifndef INCLUDED_AD5328_1_H
#define INCLUDED_AD5328_1_H

#define AD5328_DAC_A 0b0000 << 12
#define AD5328_DAC_B 0b0001 << 12
#define AD5328_DAC_C 0b0010 << 12
#define AD5328_DAC_D 0b0011 << 12
#define AD5328_DAC_E 0b0100 << 12
#define AD5328_DAC_F 0b0101 << 12
#define AD5328_DAC_G 0b0110 << 12
#define AD5328_DAC_H 0b0111 << 12

//#define FREQUENCY 30000000 // (30MHz)これ以上大きくはできない

typedef enum
{
	DAC_A = AD5328_DAC_A,
	DAC_B = AD5328_DAC_B,
	DAC_C = AD5328_DAC_C,
	DAC_D = AD5328_DAC_D,
	DAC_E = AD5328_DAC_E,
	DAC_F = AD5328_DAC_F,
	DAC_G = AD5328_DAC_G,
	DAC_H = AD5328_DAC_H,
} DAC_t;

class AD5328
{
public:
	AD5328(int pin);
	void begin();
	void write(DAC_t DAC, int V_out_bit); // 動かすDAC(DAC_A～DAC_H)と出力(0～4096)を入力

private:
	//int frequency = FREQUENCY;
	int cs = SS;

	void set();
	void reset();
};

#endif
