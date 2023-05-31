#include "interrupt_manager.h"
#include "mcc.h"

void  INTERRUPT_Initialize (void)
{
    // Disable Interrupt Priority Vectors (16CXXX Compatibility Mode)
    INTCONbits.IPEN = 0;
}

void __interrupt() INTERRUPT_InterruptManager (void)
{
    // interrupt handler
    if(INTCONbits.PEIE == 1)
    {
        if(PIE3bits.TX2IE == 1 && PIR3bits.TX2IF == 1)
        {
            EUSART2_TxDefaultInterruptHandler();
        } 
        else if(PIE3bits.RC2IE == 1 && PIR3bits.RC2IF == 1)
        {
            EUSART2_RxDefaultInterruptHandler();
        } 
        else
        {
            //Unhandled Interrupt
        }
    }      
    else
    {
        //Unhandled Interrupt
    }
}