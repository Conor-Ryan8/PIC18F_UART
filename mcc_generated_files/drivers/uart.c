#include "uart.h"   

const uart_functions_t uart[] = {   
    {EUSART2_Read, EUSART2_Write, EUSART2_is_tx_ready, EUSART2_is_rx_ready, EUSART2_SetTxInterruptHandler, EUSART2_Receive_ISR, EUSART2_SetRxInterruptHandler, EUSART2_is_tx_done, EUSART2_Transmit_ISR, EUSART2_Initialize }
};
