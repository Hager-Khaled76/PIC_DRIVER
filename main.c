/*
 * File:   main.c
 * Author: Hager
 *
 * Created on September 2, 2024, 3:16 PM
 */


#define _XTAL_FREQ 4000000  // Define system frequency (for example, 4 MHz)
#include <xc.h>   // Include processor files

#include "PIC_int.h"

int main ()
{
    //unsigned long long var=400000;
	PIC_enumSetPortDirection(PIC_u8LATA,PIC_u8Pin0,OUTPUT);

	while(1)
	{
		
		PIC_enumSetportValue(PIC_u8LATA,PIC_u8Pin0, HIGH);
        
        __delay_ms(500);
        //or
		/*while(var--)
        {
            asm("NOP");
        }*/
        //var=400000;
		PIC_enumSetportValue(PIC_u8LATA,PIC_u8Pin0, LOW);

		/*  or 
        while(var--)
        {
            asm("NOP");
        }
*/

        __delay_ms(500);
	}
return 0;
}