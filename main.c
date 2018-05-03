/*
 * File:   main.c
 * Author: philip
 *
 * Created on 24 April 2018, 16:57
 */

#include "config.h"
#include "send_spi_byte.h"
#include "write_command.h"
#include "init_ports.h"
#include "config_osc.h"
#include "config_oled.h"
#include "clear_oled.h"
#include "splash_screen.h"
#include "setup_vol_scrn.h"
#include "putch.h"
#include "set_usart.h"
#include "transmit_character.h"
#include "transmit_data.h"
#include "init_TMR1.h"
#include "ioc_enable.h"
#include "write_character.h"
#include "bar_graph.h"
#include "get_digit.h"
#include "split_digits.h"
#include "input.h"
#include"state_of_machine.h"
#include "interrupt isr.h"
#include<stdio.h>


void main(void) 
{
    init_ports();
    config_osc();
    config_oled();
    clear_oled();
    splash_screen();
    set_usart();
    __delay_ms(1000);
    clear_oled();
    setup_vol_scrn();
    init_TMR1();
    ioc_enable();
    int next_state = VOL;
    int current_state = VOL;
    printf("\n");
    printf(" hello Tonie xxx\n");
    char ton[] = " Finite state machine - mini box little head\n";
    transmit_character(&ton[0]);
    printf("\n");
    printf( "Current_state = %d\n", current_state);
    time_out = 0; 
    while(1)
    {
     state_of_machine(&current_state);
    
     if(next_state != current_state)
     {
       printf(" current_state = %d\n", current_state);
        next_state = current_state;
        printf("NEW time_out = %d\n", time_out);
        printf("\n");
     }              
    }
}

