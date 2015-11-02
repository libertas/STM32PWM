#include "pwm.h"

uint8_t PWMState;
uint32_t PWMHighTime;
uint32_t PWMLowTime;
uint32_t PWMTotal;

void PWM_Config()
{
	PWMState = 0;
	PWMTotal = 10000;
	PWMHighTime = 5000;
	PWMLowTime = 5000;
}

void setDuty(double duty)
{
	unsigned long freq;
	
}

void setFreq(unsigned long freq)
{
	double duty;
	duty = (double) PWMHighTime / PWMTotal;
	PWMTotal = PWM_FREQ / freq;
	PWMHighTime = PWMTotal * duty;
	PWMLowTime = PWMTotal - PWMHighTime;
}
