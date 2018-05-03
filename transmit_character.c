/*
 * File:   transmit_character.c
 * Author: philip
 *
 * Created on 02 January 2018, 19:39
 */




#include "config.h"
#include <xc.h>
#include "transmit_character.h"
#include <stdio.h>
void transmit_character (char *character)
{
  
  while(*character !='\0') 
  {
  while (TRMT == 0)    // TMRT bit = 0 until all characters are shifted out 
    {                  // of the TSR register
      ;                // wait here until TMRT = 1, ie all characters have been sent
    }
    
      TXREG = *character;
      if(*character !='\0')
      {
        character++;
      }     
  }   
}   
