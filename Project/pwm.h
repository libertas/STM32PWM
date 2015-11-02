#include <stdint.h>

/*
	It makes pwm freq is available
	from 10 Hz to 15 kHz.
*/
#define PWM_PRESCALE 71

#define PWM_FREQ 1000000UL

void PWM_Config(void);
void setDuty(double duty);
void setFreq(unsigned long freq);
