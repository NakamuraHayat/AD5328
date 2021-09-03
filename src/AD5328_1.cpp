#include "Arduino.h"
#include "SPI.h"
#include "AD5328_1.h"

AD5328::AD5328(int cs_pin) {
	cs = cs_pin;
}

void AD5328::begin()
{
	SPI.begin();
	pinMode(cs, OUTPUT);
	digitalWrite(cs, HIGH);
	reset();
	set();
}

void AD5328::set() {
	SPI.beginTransaction(SPISettings(30000000, MSBFIRST, SPI_MODE1));
	digitalWrite(cs, LOW);
	SPI.transfer16(0x8003); // Vddをリファレンスとして使用
	digitalWrite(cs, HIGH);
	SPI.endTransaction();
}

void AD5328::reset() {
	SPI.beginTransaction(SPISettings(30000000, MSBFIRST, SPI_MODE1));
	digitalWrite(cs, LOW);
	SPI.transfer16(0xF000); // データおよび制御リセット
	digitalWrite(cs, HIGH);
	SPI.endTransaction();
}

void AD5328::write(DAC_t DAC, int V_out_bit) {
	SPI.beginTransaction(SPISettings(30000000, MSBFIRST, SPI_MODE1));
	digitalWrite(cs, LOW);
	SPI.transfer16(DAC | V_out_bit); // 出力
	digitalWrite(cs, HIGH);
	SPI.endTransaction();
}
