/*
 * File:   ioc_enable.c
 * Author: philip
 *
 * Created on 16 April 2018, 19:43
 */


#include <xc.h>

void ioc_enable(void) 
{
    INTCONbits.GIE = 1;         // enable global interrupts
    //INTCONbits.INTE = 1;       // enable external interrupt on PORTAbits.RA1 pin 18
    INTCONbits.IOCIE = 1;
    IOCANbits.IOCAN1 = 1;
    //IOCANbits.IOCAN4 = 1;
    OPTION_REGbits.INTEDG = 0;  //interrupt of falling edge of DT
    INTCONbits.INTF = 0;       // clear external interrupt flag to allow future interrupts 
    //IOCAFbits.IOCAF1 = 0;
    //IOCAFbits.IOCAF4= 0;
    INTCONbits.IOCIF = 0;
    
}
