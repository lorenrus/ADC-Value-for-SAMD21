#ifndef ADC_PIN_AIN
#define ADC_PIN_AIN


#include <Arduino.h>


void Impostazione_Pin_ADC (uint8_t Posizione_Mux_PA02, uint8_t Posizione_Mux_PB08, uint8_t Posizione_Mux_PB09, uint8_t Posizione_Mux_PA04, 
						   uint8_t Posizione_Mux_PA05, uint8_t Posizione_Mux_PB02, uint8_t Posizione_Mux_PA11, uint8_t Posizione_Mux_PA10, 
						   uint8_t Posizione_Mux_PA08, uint8_t Posizione_Mux_PA09, uint8_t Posizione_Mux_PA06, uint8_t Posizione_Mux_PA07, 
						   uint8_t Posizione_Mux_PA03);


void Setting_Bit_ADC(float Bit);


float Read_Voltage_PA02();

float Read_Voltage_PB08();

float Read_Voltage_PB09();

float Read_Voltage_PA04();

float Read_Voltage_PA05();

float Read_Voltage_PB02();

float Read_Voltage_PA11();

float Read_Voltage_PA10();

float Read_Voltage_PA08();

float Read_Voltage_PA09();

float Read_Voltage_PA06();

float Read_Voltage_PA07();

float Read_Voltage_PA03();


#endif
