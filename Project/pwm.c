#include <stdio.h>
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
	setFreq(56);
	setDuty(0.08);
}

void setDuty(double duty)
{
	if(duty >= 0 && duty <= 1)
	{
		PWMHighTime = PWMTotal * duty;
		PWMLowTime = PWMTotal - PWMHighTime;
	}
	else
	{
		printf("Wrong Duty!\n");
	}
}

void setFreq(unsigned long freq)
{
	double duty;
	duty = (double) PWMHighTime / PWMTotal;
	PWMTotal = PWM_FREQ / freq;
	PWMHighTime = PWMTotal * duty;
	PWMLowTime = PWMTotal - PWMHighTime;
}
