#include "misc.h"
#include "stdio.h"
#include "stdarg.h"
#include "stm32f10x_usart.h"

int fputc(int ch, FILE *f);
int fgetc(FILE *fp);
void USART_Printf(USART_TypeDef* USARTx, char *fmt, ...);
