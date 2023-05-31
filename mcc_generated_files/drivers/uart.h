#ifndef _UART_H

#define _UART_H

#include <stdint.h>
#include <stddef.h>
#include "../eusart2.h"

typedef enum
{ 
    UART0
}
uart_configurations_t;

typedef struct { uint8_t (*Read)(void); void (*Write)(uint8_t txdata); bool (*TransmitReady)(void); bool (*DataReady)(void); void (*SetTxISR)(void (* interruptHandler)(void)); void (*RxDefaultISR)(void); void (*SetRxISR)(void (* interruptHandler)(void)); bool (*TransmitDone)(void); void (*TxDefaultISR)(void); void (*Initialize)(void);  } uart_functions_t;

extern const uart_functions_t uart[];

#endif	// _UART_H