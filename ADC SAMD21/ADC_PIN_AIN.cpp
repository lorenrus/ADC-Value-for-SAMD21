#include "ADC_PIN_AIN.h"




bool Attivazione_Mux_PA02;
bool Attivazione_Mux_PB08;
bool Attivazione_Mux_PB09;
bool Attivazione_Mux_PA04;
bool Attivazione_Mux_PA05;
bool Attivazione_Mux_PB02;
bool Attivazione_Mux_PA11;
bool Attivazione_Mux_PA10;
bool Attivazione_Mux_PA08;
bool Attivazione_Mux_PA09;
bool Attivazione_Mux_PA06;
bool Attivazione_Mux_PA07;
bool Attivazione_Mux_PA03;


uint8_t Posizione_Pin_AIN0;
uint8_t Posizione_Pin_AIN1;
uint8_t Posizione_Pin_AIN2;
uint8_t Posizione_Pin_AIN3;
uint8_t Posizione_Pin_AIN4;
uint8_t Posizione_Pin_AIN5;
uint8_t Posizione_Pin_AIN10;
uint8_t Posizione_Pin_AIN19;
uint8_t Posizione_Pin_AIN18;
uint8_t Posizione_Pin_AIN16;
uint8_t Posizione_Pin_AIN17;
uint8_t Posizione_Pin_AIN6;
uint8_t Posizione_Pin_AIN7;



float Valore_Fondo_Scala = 0;



void Impostazione_Pin_ADC (uint8_t Posizione_Mux_PA02, uint8_t Posizione_Mux_PB08, uint8_t Posizione_Mux_PB09, uint8_t Posizione_Mux_PA04, uint8_t Posizione_Mux_PA05,
                           uint8_t Posizione_Mux_PB02, uint8_t Posizione_Mux_PA11, uint8_t Posizione_Mux_PA10, uint8_t Posizione_Mux_PA08, uint8_t Posizione_Mux_PA09,
                           uint8_t Posizione_Mux_PA06, uint8_t Posizione_Mux_PA07, uint8_t Posizione_Mux_PA03) {




  if(Posizione_Mux_PA02 == 0) {

      Attivazione_Mux_PA02 = 0;
  }
  else if(Posizione_Mux_PA02 == 1) {
      
      Attivazione_Mux_PA02 = true;
      Posizione_Pin_AIN0 = 0;
  }

  if(Posizione_Mux_PA03 == NULL) {

      Attivazione_Mux_PA03 = 0;
  }
  else {

      Attivazione_Mux_PA03 = true;
      Posizione_Pin_AIN1 = 1;
  }

  if(Posizione_Mux_PB08 == NULL) {

      Attivazione_Mux_PB08 = 0;
  }
  else {

      Attivazione_Mux_PB08 = true;
      Posizione_Pin_AIN2  = 2;
  }

  if(Posizione_Mux_PB09 == NULL) {

      Attivazione_Mux_PB09 = 0;
  }
  else {

      Attivazione_Mux_PB09 = true;
      Posizione_Pin_AIN3  = 3;
  }

  if(Posizione_Mux_PA04 == NULL) {

      Attivazione_Mux_PA04 = 0;
  }
  else {

      Attivazione_Mux_PA04 = true;
      Posizione_Pin_AIN4  = 4;
  }

  if(Posizione_Mux_PA05 == NULL) {

      Attivazione_Mux_PA05 = 0;
  }
  else {

      Attivazione_Mux_PA05 = true;
      Posizione_Pin_AIN5 = 5;
  }

  if(Posizione_Mux_PB02 == NULL) {

      Attivazione_Mux_PB02 = 0;
  }
  else {

      Attivazione_Mux_PB02 = true;
      Posizione_Pin_AIN10  = 10;
  }

  if(Posizione_Mux_PA11 == NULL) {

      Attivazione_Mux_PA11 = 0;
  }
  else {

      Attivazione_Mux_PA11 = true;
      Posizione_Pin_AIN19  = 19;
  }

  if(Posizione_Mux_PA10 == NULL) {

      Attivazione_Mux_PA10 = 0;
  }
  else {

      Attivazione_Mux_PA10 = true;
      Posizione_Pin_AIN18  = 18;
  }

  if(Posizione_Mux_PA08 == NULL) {

      Attivazione_Mux_PA08 = 0;
  }
  else {

      Attivazione_Mux_PA08 = true;
      Posizione_Pin_AIN16 = 16;
  }

  if(Posizione_Mux_PA09 == NULL) {

      Attivazione_Mux_PA09 = 0;
  }
  else {

      Attivazione_Mux_PA09 = true;
      Posizione_Pin_AIN17 = 17;
  }

  if(Posizione_Mux_PA06 == NULL) {

      Attivazione_Mux_PA06 = 0;
  }
  else {

      Attivazione_Mux_PA06 = true;
      Posizione_Pin_AIN6 = 6;
  }

  if(Posizione_Mux_PA07 == NULL) {

      Attivazione_Mux_PA07 = 0;
  }
  else {

      Attivazione_Mux_PA07 = true;
      Posizione_Pin_AIN7 = 7;
  }
}


void Setting_Bit_ADC(float Bit) {
    
  ADC -> CTRLB.bit.RESSEL = Bit; // Bit ADC

  float Risoluzione = pow(2, Bit);

  //Serial.println(Risoluzione);
    
  // Con l'operazione successiva cambio i valori da 0 a 1023 in un intervallo che corrisponde alla Vcc
  Valore_Fondo_Scala = 3.3/Risoluzione;

  //Serial.println(Valore_Tensione_Analogica, 10);
}


int16_t ADC_Pin_PA02() {

  if(Attivazione_Mux_PA02) {

      int16_t Valore_Tensione_Pin_PA02 = 0;

      while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

      ADC->INPUTCTRL.bit.MUXPOS = Posizione_Pin_AIN0; // ADC input Positivo
      ADC->INPUTCTRL.bit.MUXNEG = 0x18; // A massa internamente

      while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

      ADC->CTRLA.bit.ENABLE = 0x01; // Abilito l'ADC
      ADC->CTRLB.bit.DIFFMODE = 0;  // Imposto la modalità Single-Ended

      while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

      ADC->SWTRIG.bit.START = 1; // Attivo la conversione

      ADC->INTFLAG.reg = ADC_INTFLAG_RESRDY; // Resetto il data ready flag

      while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

      ADC->SWTRIG.bit.START = 1; // Riattivo la conversione

      while(ADC->INTFLAG.bit.RESRDY == 0);   // Attendo che la conversione è terminata
      Valore_Tensione_Pin_PA02 = ADC->RESULT.reg; // Leggo il valore

      while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

      ADC->CTRLA.bit.ENABLE = 0x00; // Disabilito l'ADC

      while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

      return Valore_Tensione_Pin_PA02;
  }
  else {
  }
}


float Read_Voltage_PA02() {

  int16_t Valore_Tensione_Pin_PA02 = ADC_Pin_PA02();
  
  float Tensione_Pin_PA02 = Valore_Tensione_Pin_PA02 * Valore_Fondo_Scala;

  return Tensione_Pin_PA02;
}


uint16_t ADC_Pin_PB08() {

  if(Attivazione_Mux_PB08) {

    uint16_t Valore_Tensione_Pin_PB08 = 0;

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->INPUTCTRL.bit.MUXPOS = Posizione_Pin_AIN2; // ADC input Positivo
    ADC->INPUTCTRL.bit.MUXNEG = 0x18; // A massa internamente

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->CTRLA.bit.ENABLE = 0x01; // Abilito l'ADC
    ADC->CTRLB.bit.DIFFMODE = 0;  // Imposto la modalità Single-Ended

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->SWTRIG.bit.START = 1; // Attivo la conversione

    ADC->INTFLAG.reg = ADC_INTFLAG_RESRDY; // Resetto il data ready flag

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->SWTRIG.bit.START = 1; // Riattivo la conversione

    while(ADC->INTFLAG.bit.RESRDY == 0);   // Attendo che la conversione è terminata
    Valore_Tensione_Pin_PB08 = ADC->RESULT.reg; // Leggo il valore

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->CTRLA.bit.ENABLE = 0x00; // Disabilito l'ADC

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    return Valore_Tensione_Pin_PB08;
  }
  else {}
}


float Read_Voltage_PB08() {

  int16_t Valore_Tensione_Pin_PB08 = ADC_Pin_PB08();
  
  float Tensione_Pin_PB08 = Valore_Tensione_Pin_PB08 * Valore_Fondo_Scala;

  return Tensione_Pin_PB08;
}


uint16_t ADC_Pin_PB09() {

  if(Attivazione_Mux_PB09) {

    uint16_t Valore_Tensione_Pin_PB09 = 0;

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->INPUTCTRL.bit.MUXPOS = Posizione_Pin_AIN3; // ADC input Positivo
    ADC->INPUTCTRL.bit.MUXNEG = 0x18; // A massa internamente

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->CTRLA.bit.ENABLE = 0x01; // Abilito l'ADC
    ADC->CTRLB.bit.DIFFMODE = 0;  // Imposto la modalità Single-Ended

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->SWTRIG.bit.START = 1; // Attivo la conversione

    ADC->INTFLAG.reg = ADC_INTFLAG_RESRDY; // Resetto il data ready flag

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->SWTRIG.bit.START = 1; // Riattivo la conversione

    while(ADC->INTFLAG.bit.RESRDY == 0);   // Attendo che la conversione è terminata
    Valore_Tensione_Pin_PB09 = ADC->RESULT.reg; // Leggo il valore

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->CTRLA.bit.ENABLE = 0x00; // Disabilito l'ADC

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    return Valore_Tensione_Pin_PB09;
  }
  else {}
}


float Read_Voltage_PB09() {

  int16_t Valore_Tensione_Pin_PB09 = ADC_Pin_PB09();
  
  float Tensione_Pin_PB09 = Valore_Tensione_Pin_PB09 * Valore_Fondo_Scala;

  return Tensione_Pin_PB09;
}


uint16_t ADC_Pin_PA04() {

  if(Attivazione_Mux_PA04) {

    uint16_t Valore_Tensione_Pin_PA04 = 0;

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->INPUTCTRL.bit.MUXPOS = Posizione_Pin_AIN4; // ADC input Positivo
    ADC->INPUTCTRL.bit.MUXNEG = 0x18; // A massa internamente

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->CTRLA.bit.ENABLE = 0x01; // Abilito l'ADC
    ADC->CTRLB.bit.DIFFMODE = 0;  // Imposto la modalità Single-Ended

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->SWTRIG.bit.START = 1; // Attivo la conversione

    ADC->INTFLAG.reg = ADC_INTFLAG_RESRDY; // Resetto il data ready flag

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->SWTRIG.bit.START = 1; // Riattivo la conversione

    while(ADC->INTFLAG.bit.RESRDY == 0);   // Attendo che la conversione è terminata
    Valore_Tensione_Pin_PA04 = ADC->RESULT.reg; // Leggo il valore

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->CTRLA.bit.ENABLE = 0x00; // Disabilito l'ADC

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    return Valore_Tensione_Pin_PA04;
  }
  else {}
}


float Read_Voltage_PA04() {

  int16_t Valore_Tensione_Pin_PA04 = ADC_Pin_PA04();
  
  float Tensione_Pin_PA04 = Valore_Tensione_Pin_PA04 * Valore_Fondo_Scala;

  return Tensione_Pin_PA04;
}


uint16_t ADC_Pin_PA05() {

  if(Attivazione_Mux_PA05) {

    uint16_t Valore_Tensione_Pin_PA05 = 0;

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->INPUTCTRL.bit.MUXPOS = Posizione_Pin_AIN5; // ADC input Positivo
    ADC->INPUTCTRL.bit.MUXNEG = 0x18; // A massa internamente

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->CTRLA.bit.ENABLE = 0x01; // Abilito l'ADC
    ADC->CTRLB.bit.DIFFMODE = 0;  // Imposto la modalità Single-Ended

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->SWTRIG.bit.START = 1; // Attivo la conversione

    ADC->INTFLAG.reg = ADC_INTFLAG_RESRDY; // Resetto il data ready flag

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->SWTRIG.bit.START = 1; // Riattivo la conversione

    while(ADC->INTFLAG.bit.RESRDY == 0);   // Attendo che la conversione è terminata
    Valore_Tensione_Pin_PA05 = ADC->RESULT.reg; // Leggo il valore

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->CTRLA.bit.ENABLE = 0x00; // Disabilito l'ADC

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    return Valore_Tensione_Pin_PA05;
  }
  else {}
}


float Read_Voltage_PA05() {

  int16_t Valore_Tensione_Pin_PA05 = ADC_Pin_PA05();
  
  float Tensione_Pin_PA05 = Valore_Tensione_Pin_PA05 * Valore_Fondo_Scala;

  return Tensione_Pin_PA05;
}


uint16_t ADC_Pin_PB02() {

  if(Attivazione_Mux_PB02) {

    uint16_t Valore_Tensione_Pin_PB02 = 0;

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->INPUTCTRL.bit.MUXPOS = Posizione_Pin_AIN10; // ADC input Positivo
    ADC->INPUTCTRL.bit.MUXNEG = 0x18; // A massa internamente

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->CTRLA.bit.ENABLE = 0x01; // Abilito l'ADC
    ADC->CTRLB.bit.DIFFMODE = 0;  // Imposto la modalità Single-Ended

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->SWTRIG.bit.START = 1; // Attivo la conversione

    ADC->INTFLAG.reg = ADC_INTFLAG_RESRDY; // Resetto il data ready flag

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->SWTRIG.bit.START = 1; // Riattivo la conversione

    while(ADC->INTFLAG.bit.RESRDY == 0);   // Attendo che la conversione è terminata
    Valore_Tensione_Pin_PB02 = ADC->RESULT.reg; // Leggo il valore

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->CTRLA.bit.ENABLE = 0x00; // Disabilito l'ADC

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    return Valore_Tensione_Pin_PB02;
  }
  else {}
}


float Read_Voltage_PB02() {

  int16_t Valore_Tensione_Pin_PB02 = ADC_Pin_PB02();
  
  float Tensione_Pin_PB02 = Valore_Tensione_Pin_PB02 * Valore_Fondo_Scala;

  return Tensione_Pin_PB02;
}


uint16_t ADC_Pin_PA11() {

  if(Attivazione_Mux_PA11) {

    uint16_t Valore_Tensione_Pin_PA11 = 0;

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->INPUTCTRL.bit.MUXPOS = Posizione_Pin_AIN19; // ADC input Positivo
    ADC->INPUTCTRL.bit.MUXNEG = 0x18; // A massa internamente

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->CTRLA.bit.ENABLE = 0x01; // Abilito l'ADC
    ADC->CTRLB.bit.DIFFMODE = 0;  // Imposto la modalità Single-Ended

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->SWTRIG.bit.START = 1; // Attivo la conversione

    ADC->INTFLAG.reg = ADC_INTFLAG_RESRDY; // Resetto il data ready flag

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->SWTRIG.bit.START = 1; // Riattivo la conversione

    while(ADC->INTFLAG.bit.RESRDY == 0);   // Attendo che la conversione è terminata
    Valore_Tensione_Pin_PA11 = ADC->RESULT.reg; // Leggo il valore

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->CTRLA.bit.ENABLE = 0x00; // Disabilito l'ADC

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    return Valore_Tensione_Pin_PA11;
  }
  else {}
}


float Read_Voltage_PA11() {

  int16_t Valore_Tensione_Pin_PA11 = ADC_Pin_PA11();
  
  float Tensione_Pin_PA11 = Valore_Tensione_Pin_PA11 * Valore_Fondo_Scala;

  return Tensione_Pin_PA11;
}


uint16_t ADC_Pin_PA10() {

  if(Attivazione_Mux_PA10) {

    uint16_t Valore_Tensione_Pin_PA10 = 0;

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->INPUTCTRL.bit.MUXPOS = Posizione_Pin_AIN18; // ADC input Positivo
    ADC->INPUTCTRL.bit.MUXNEG = 0x18; // A massa internamente

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->CTRLA.bit.ENABLE = 0x01; // Abilito l'ADC
    ADC->CTRLB.bit.DIFFMODE = 0;  // Imposto la modalità Single-Ended

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->SWTRIG.bit.START = 1; // Attivo la conversione

    ADC->INTFLAG.reg = ADC_INTFLAG_RESRDY; // Resetto il data ready flag

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->SWTRIG.bit.START = 1; // Riattivo la conversione

    while(ADC->INTFLAG.bit.RESRDY == 0);   // Attendo che la conversione è terminata
    Valore_Tensione_Pin_PA10 = ADC->RESULT.reg; // Leggo il valore

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->CTRLA.bit.ENABLE = 0x00; // Disabilito l'ADC

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    return Valore_Tensione_Pin_PA10;
  }
  else {}
}


float Read_Voltage_PA10() {

  int16_t Valore_Tensione_Pin_PA10 = ADC_Pin_PA10();
  
  float Tensione_Pin_PA10 = Valore_Tensione_Pin_PA10 * Valore_Fondo_Scala;

  return Tensione_Pin_PA10;
}


uint16_t ADC_Pin_PA08() {

  if(Attivazione_Mux_PA08) {

    uint16_t Valore_Tensione_Pin_PA08 = 0;

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->INPUTCTRL.bit.MUXPOS = Posizione_Pin_AIN16; // ADC input Positivo
    ADC->INPUTCTRL.bit.MUXNEG = 0x18; // A massa internamente

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->CTRLA.bit.ENABLE = 0x01; // Abilito l'ADC
    ADC->CTRLB.bit.DIFFMODE = 0;  // Imposto la modalità Single-Ended

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->SWTRIG.bit.START = 1; // Attivo la conversione

    ADC->INTFLAG.reg = ADC_INTFLAG_RESRDY; // Resetto il data ready flag

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->SWTRIG.bit.START = 1; // Riattivo la conversione

    while(ADC->INTFLAG.bit.RESRDY == 0);   // Attendo che la conversione è terminata
    Valore_Tensione_Pin_PA08 = ADC->RESULT.reg; // Leggo il valore

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->CTRLA.bit.ENABLE = 0x00; // Disabilito l'ADC

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    return Valore_Tensione_Pin_PA08;
  }
  else {}
}


float Read_Voltage_PA08() {

  int16_t Valore_Tensione_Pin_PA08 = ADC_Pin_PA08();
  
  float Tensione_Pin_PA08 = Valore_Tensione_Pin_PA08 * Valore_Fondo_Scala;

  return Tensione_Pin_PA08;
}


uint16_t ADC_Pin_PA09() {

  if(Attivazione_Mux_PA09) {

    uint16_t Valore_Tensione_Pin_PA09 = 0;

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->INPUTCTRL.bit.MUXPOS = Posizione_Pin_AIN17; // ADC input Positivo
    ADC->INPUTCTRL.bit.MUXNEG = 0x18; // A massa internamente

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->CTRLA.bit.ENABLE = 0x01; // Abilito l'ADC
    ADC->CTRLB.bit.DIFFMODE = 0;  // Imposto la modalità Single-Ended

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->SWTRIG.bit.START = 1; // Attivo la conversione

    ADC->INTFLAG.reg = ADC_INTFLAG_RESRDY; // Resetto il data ready flag

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->SWTRIG.bit.START = 1; // Riattivo la conversione

    while(ADC->INTFLAG.bit.RESRDY == 0);   // Attendo che la conversione è terminata
    Valore_Tensione_Pin_PA09 = ADC->RESULT.reg; // Leggo il valore

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->CTRLA.bit.ENABLE = 0x00; // Disabilito l'ADC

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    return Valore_Tensione_Pin_PA09;
  }
  else {}
}


float Read_Voltage_PA09() {

  int16_t Valore_Tensione_Pin_PA09 = ADC_Pin_PA09();
  
  float Tensione_Pin_PA09 = Valore_Tensione_Pin_PA09 * Valore_Fondo_Scala;

  return Tensione_Pin_PA09;
}


uint16_t ADC_Pin_PA06() {

  if(Attivazione_Mux_PA06) {

    uint16_t Valore_Tensione_Pin_PA06 = 0;

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->INPUTCTRL.bit.MUXPOS = Posizione_Pin_AIN6; // ADC input Positivo
    ADC->INPUTCTRL.bit.MUXNEG = 0x18; // A massa internamente

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->CTRLA.bit.ENABLE = 0x01; // Abilito l'ADC
    ADC->CTRLB.bit.DIFFMODE = 0;  // Imposto la modalità Single-Ended

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->SWTRIG.bit.START = 1; // Attivo la conversione

    ADC->INTFLAG.reg = ADC_INTFLAG_RESRDY; // Resetto il data ready flag

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->SWTRIG.bit.START = 1; // Riattivo la conversione

    while(ADC->INTFLAG.bit.RESRDY == 0);   // Attendo che la conversione è terminata
    Valore_Tensione_Pin_PA06 = ADC->RESULT.reg; // Leggo il valore

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->CTRLA.bit.ENABLE = 0x00; // Disabilito l'ADC

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    return Valore_Tensione_Pin_PA06;
  }
  else {}
}


float Read_Voltage_PA06() {

  int16_t Valore_Tensione_Pin_PA06 = ADC_Pin_PA06();
  
  float Tensione_Pin_PA06 = Valore_Tensione_Pin_PA06 * Valore_Fondo_Scala;

  return Tensione_Pin_PA06;
}


uint16_t ADC_Pin_PA07() {

  if(Attivazione_Mux_PA07) {

    uint16_t Valore_Tensione_Pin_PA07 = 0;

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->INPUTCTRL.bit.MUXPOS = Posizione_Pin_AIN7; // ADC input Positivo
    ADC->INPUTCTRL.bit.MUXNEG = 0x18; // A massa internamente

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->CTRLA.bit.ENABLE = 0x01; // Abilito l'ADC
    ADC->CTRLB.bit.DIFFMODE = 0;  // Imposto la modalità Single-Ended

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->SWTRIG.bit.START = 1; // Attivo la conversione

    ADC->INTFLAG.reg = ADC_INTFLAG_RESRDY; // Resetto il data ready flag

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->SWTRIG.bit.START = 1; // Riattivo la conversione

    while(ADC->INTFLAG.bit.RESRDY == 0);   // Attendo che la conversione è terminata
    Valore_Tensione_Pin_PA07 = ADC->RESULT.reg; // Leggo il valore

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->CTRLA.bit.ENABLE = 0x00; // Disabilito l'ADC

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    return Valore_Tensione_Pin_PA07;
  }
  else {}
}


float Read_Voltage_PA07() {

  int16_t Valore_Tensione_Pin_PA07 = ADC_Pin_PA07();
  
  float Tensione_Pin_PA07 = Valore_Tensione_Pin_PA07 * Valore_Fondo_Scala;

  return Tensione_Pin_PA07;
}


uint16_t ADC_Pin_PA03() {

  if(Attivazione_Mux_PA03) {

    uint16_t Valore_Tensione_Pin_PA03 = 0;

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->INPUTCTRL.bit.MUXPOS = Posizione_Pin_AIN1; // ADC input Positivo
    ADC->INPUTCTRL.bit.MUXNEG = 0x18; // A massa internamente

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->CTRLA.bit.ENABLE = 0x01; // Abilito l'ADC
    ADC->CTRLB.bit.DIFFMODE = 0;  // Imposto la modalità Single-Ended

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->SWTRIG.bit.START = 1; // Attivo la conversione

    ADC->INTFLAG.reg = ADC_INTFLAG_RESRDY; // Resetto il data ready flag

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->SWTRIG.bit.START = 1; // Riattivo la conversione

    while(ADC->INTFLAG.bit.RESRDY == 0);   // Attendo che la conversione è terminata
    Valore_Tensione_Pin_PA03 = ADC->RESULT.reg; // Leggo il valore

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    ADC->CTRLA.bit.ENABLE = 0x00; // Disabilito l'ADC

    while (ADC->STATUS.bit.SYNCBUSY == 1); // Attendo la sincronizzazione

    return Valore_Tensione_Pin_PA03;
  }
  else {}
}


float Read_Voltage_PA03() {

  int16_t Valore_Tensione_Pin_PA03 = ADC_Pin_PA03();
  
  float Tensione_Pin_PA03 = Valore_Tensione_Pin_PA03 * Valore_Fondo_Scala;

  return Tensione_Pin_PA03;
}
