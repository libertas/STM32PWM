#include "utils.h"

int fputc(int ch, FILE *f)
{
    while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);

    USART_SendData(USART1, (uint8_t) ch);

    return ch;
}

int fgetc(FILE *fp)
{
	int ch = 0;
  while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);

  ch = (int)USART3->DR & 0xFF;
	
	return ch;
}

#define CMD_BUFFER_LEN 100

void USART_Printf(USART_TypeDef* USARTx, char *fmt, ...)
{

	char buffer[CMD_BUFFER_LEN+1];
	u8 i = 0;
	
	va_list arg_ptr;
	va_start(arg_ptr, fmt);  
	vsnprintf(buffer, CMD_BUFFER_LEN+1, fmt, arg_ptr);
	USART_ClearFlag(USARTx,USART_FLAG_TXE);
	while ((i < CMD_BUFFER_LEN) && buffer[i])
	{
	    USART_SendData(USARTx, (u8) buffer[i++]);
		while (USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET); 
	}
	va_end(arg_ptr);
}
