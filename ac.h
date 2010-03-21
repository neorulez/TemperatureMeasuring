#ifndef __AC_H
#define __AC_H
//------------------------------------------------------------------------------

#include "typedefs.h"
#include "application.h"
//------------------------------------------------------------------------------

#define AC_BUFFER_ITEMS 8

#define AC_T1_CLEAR() {TCNT1H = 0; TCNT1L = 0;} // Reset Timer1
#define AC_T1_START() (TCCR1B |= CS10) // Enable Timer1 clock
#define AC_T1_STOP() (TCCR1B &= ~CS10) // Disable Timer1 clock
#define AC_T1_IC_CLR_FLAG() (TIFR1 |= ICF1) // Clear input capture interrupt flag
#define AC_T1_IC_ENABLE() (TIMSK1 |= ICIE1) // Enable input capture interrupt
#define AC_T1_IC_DISABLE() (TIMSK1 &= ~ICIE1) // Disable input capture interrupt

#define AC_INIT_TEST_PIN() (AC_TEST_PIN_DDR |= AC_TEST_PIN_BIT)
#define AC_SET_TEST_PIN() (AC_TEST_PIN_PRT |= AC_TEST_PIN_BIT)
#define AC_CLR_TEST_PIN() (AC_TEST_PIN_PRT &= ~AC_TEST_PIN_BIT)

#define AC_SET_INPUT() (DDRD &= ~PD7) // Set AIN1 as input
#define AC_SET_OUTPUT() (DDRD |= PD7) // Set AIN1 as output
//------------------------------------------------------------------------------

extern volatile BOOL ac_ready;
extern volatile U16 ac_t1_ic_time;
extern volatile U16 ac_t1_overflows;
//------------------------------------------------------------------------------

void ac_init(void);
//------------------------------------------------------------------------------

#endif
