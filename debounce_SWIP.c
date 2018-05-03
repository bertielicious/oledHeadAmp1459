/*
 * File:   debounce_SWIP.c
 * Author: philip
 *
 * Created on 28 February 2018, 18:54
 */
/*INPUT = SWIP && previous_state && current_state 
  OUTPUT = LED_OFF or LED_ON*/

#include <xc.h>
#include "config.h"
#include <stdbool.h>
#include "debounce_SWIP.h"

bool debounce_SWIP(void) 
{
    static uchar switch_state = LO;
    
    if(SWIP == NOT_PUSHED && switch_state == OFF) //a
    {
        switch_state = OFF; 
        return LED_OFF;
    }
    
    if(SWIP == PUSHED && switch_state == OFF)  //b
    {
        switch_state = BOUNCING_ON;
        return  LED_OFF;
    }
    
    if(SWIP == NOT_PUSHED  && switch_state == BOUNCING_ON) //c
    {
        switch_state = HI;
        return LED_OFF;
    }
    
    if(SWIP == PUSHED && switch_state == BOUNCING_ON) //d
    {
        switch_state = ON;
        return LED_ON;
    }
    
    if(SWIP == PUSHED && switch_state == ON) //x
    {
        switch_state = ON;
        return LED_ON;
    }
    
    if(SWIP == NOT_PUSHED  && switch_state == ON) //e
    {
        switch_state = BOUNCING_OFF;
        return LED_OFF;
    }
    
    if(SWIP == PUSHED && switch_state == BOUNCING_OFF)       // f
    {
        switch_state = ON;
        return LED_OFF;
    }
    
    if(SWIP == NOT_PUSHED  && switch_state == BOUNCING_OFF) //g
    {
        switch_state = OFF;
        return LED_OFF;
    }
}
