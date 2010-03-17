#ifndef CONFIG_H
#define CONFIG_H

#ifndef F_CPU
#define F_CPU    4800000UL
#endif

#include "variablen.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <avr/pgmspace.h>

#define 	ADC1	0x01
#define		ADC2	0x02
#define		ADC3	0x03

uint16 adc(uint8);

#endif
