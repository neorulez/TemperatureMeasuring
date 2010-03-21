// Module..: AC.C
// Version.: 1.0
// Compiler: CodeVisionAVR
// Chip....: ATmega88
// Date....: May 2008
// Author..: Udo Juerss
//-----------------------------------------------------------------------------

#include "ac.h"
//-----------------------------------------------------------------------------

volatile BOOL ac_ready;
volatile U16 ac_t1_overflows;
volatile U16 ac_t1_ic_time;
//-----------------------------------------------------------------------------

void ac_init(void)
{
#ifndef USE_ACO
  #error *** Module "Analog Comparator" not enabled!
#endif

  // Setup Analog Comparator
  ACSR = ACBG | // Select internal bandgap reference (1.1V)
         ACIC; // Select Timer1 input capture trigger

  // Disable digital input buffer for PD7 AIN1
  DIDR1 = AIN1D;

  // Set Test pin as output and clear
  AC_INIT_TEST_PIN();
  AC_CLR_TEST_PIN();

  // Setup Timer1
  PORTB &= ~PB0; // Set PB0_ICP1 to input
  PORTB |= PB0; // Enable pullup for PB0_ICP1

  TIMSK1 = ICIE1 | TOIE1; // Enable input capture and overflow interrupts
  TCCR1A = 0;
  TCCR1B = ICNC1 | CS10; // Clock timer with F_CPU, enable noise canceler
  AC_T1_IC_CLR_FLAG(); // Clear Timer1 input capture interrupt flag

  AC_T1_STOP();
  AC_T1_CLEAR();
  ac_t1_overflows = 0;

  AC_SET_OUTPUT(); // Set AIN1 as output
  PORTD &= ~PD7; // Set output AIN1 low
}
//-----------------------------------------------------------------------------

interrupt[TIM1_CAPT] void timer1_capt_isr(void)
{
  ac_t1_ic_time = ICR1L + ICR1H * 256; // Get input capture time

  AC_T1_IC_DISABLE(); // Disable more Input Capture interrupts
  AC_T1_STOP(); // Stop Timer1
  ac_ready = TRUE;
}
//-----------------------------------------------------------------------------

interrupt[TIM1_OVF] void timer1_ovf_isr(void)
{
  ac_t1_overflows++;
}
