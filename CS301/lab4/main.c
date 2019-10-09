#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "key.h"
#include "string.h"

int main(void)
{
	u8 keys;
	u16 times = 0;

	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	uart_init(9600);
	LED_Init();
	KEY_Init();
	LED0 = 1;
	LED1 = 1;

	while (1)
	{
		// Read from COM and make response
		if (USART_RX_STA & 0x8000)
		{
			USART_RX_BUF[USART_RX_STA & 0x3fff] = '\0';
			if (strcmp(USART_RX_BUF, "led0 on") == 0)
				LED0 = 0;
			else if (strcmp(USART_RX_BUF, "led0 off") == 0)
				LED0 = 1;
			else if (strcmp(USART_RX_BUF, "led1 on") == 0)
				LED1 = 0;
			else if (strcmp(USART_RX_BUF, "led1 off") == 0)
				LED1 = 1;
			else
				printf("\r\n Hello %s \r\n", USART_RX_BUF);
			USART_RX_STA = 0;
		}
		// Watch for key events
		keys = KEY_Scan(0);
		if (keys == KEY0_PRES)
			printf("KEY0 pressed\r\n");
		if (keys == KEY1_PRES)
			printf("KEY1 pressed\r\n");
		if (keys == WKUP_PRES)
			printf("WKUP pressed\r\n");
	}
}
