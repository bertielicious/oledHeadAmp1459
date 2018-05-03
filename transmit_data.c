/*
 * File:   transmit_data.c
 * Author: philip
 *
 * Created on 02 January 2018, 16:17
 */
#include "config.h"
#include "transmit_data.h"
void transmit_data(char num)
{
        while (TRMT == 0)    // TMRT bit = 0 until all characters are shifted out 
            {                  // of the TSR register
                ;                // wait here until TMRT = 1, ie all characters have been sent
            }
            TXREG = num;               
} 
