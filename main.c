#include <string.h>
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/drivers/uart.h"

void uartTransmit(char msg[])
{
    for(uint8_t i = 0; i < strlen(msg); i++)
    {
        uart[UART0].Write(msg[i]);
    }
}
void main(void)
{
    SYSTEM_Initialize();
    
    while (1)
    {
        LATEbits.LATE0 = 0;
        uartTransmit("LED on\n\r");
        __delay_ms(2500);
        
        LATEbits.LATE0 = 1;
        uartTransmit("LED off\n\r");
        __delay_ms(2500);
    }
}