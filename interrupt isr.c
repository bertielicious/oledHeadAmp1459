/*
 * File:   interrupt isr.c
 * Author: philip
 *
 * Created on 30 March 2018, 20:08
 */
#include <xc.h>
#include "config.h"
#include <stdio.h>
#include "interrupt isr.h"

void interrupt isr(void) 
{
    uchar clear_port_a = 0;
    
    if(PIR1bits.TMR1IF == 1)
    {
        RB5 = ~RB5;       //diagnostic led  pin 12
        TMR1H = 0x00;                       // 85ms interrupt
        TMR1L = 0x00;
        time_out++;                         // at least 85ms has expired
        printf(" time_out = %d\n", time_out);
    }
    PIR1bits.TMR1IF = 0;
    /************************************************************************/
    //if(INTCONbits.INTF == 1)
    if(INTCONbits.IOCIF == 1)
    {
        if(CLK == HI)       // clockwise movement of the knob
        { 
            up_down = HI;
            count++;
        }
        else if (CLK == LO) // anti-clockwise movement of the knob
        {
            up_down = LO;
            count--;
        }
     
    if (count >= COUNT_MAX)
    {
        count = COUNT_MAX;
    }
    if(count <= COUNT_MIN)
    {
        count = COUNT_MIN;
    }
        if((previous_count != count) && (count != COUNT_MAX) && (count != COUNT_MIN))
        {
            printf("volume position = %d\n", count);  // display latest value of count via serial monitor
        }
        
        previous_count = count;  
        printf("volume position = %d\n", count);  // display latest value of count via serial monitor
    }
    clear_port_a = PORTA;
    //INTCONbits.INTF = 0;
    IOCAFbits.IOCAF1 = 0;
    IOCAFbits.IOCAF4 = 0;
    INTCONbits.IOCIF == 0;
    
   
}
