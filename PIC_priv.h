/*
 * File:   PIC_priv.h
 * Author: Hager
 *
 * Created on September 2, 2024, 3:16 PM
 */


#include <xc.h>

#ifndef PIC_PRIV_H_
#define PIC_PRIV_H_


#define PIC_LATA    0
#define PIC_LATB    1
#define PIC_LATC    2
#define PIC_LATD    3

//PIN
#define PIC_Pin0    0
#define PIC_Pin1    1
#define PIC_Pin2    2
#define PIC_Pin3    3
#define PIC_Pin4    4
#define PIC_Pin5    5
#define PIC_Pin6    6
#define PIC_Pin7    7


#define PIC_PORTA    0
#define PIC_PORTB    1
#define PIC_PORTC    2
#define PIC_PORTD    3




#define INPUT  1
#define OUTPUT 0


#define LOW      0
#define HIGH     1
#define FLOAT    0
#define PULL_UP  1




#define TRISA      *((u8*)0xF92)
#define LATA      *((u8*)0xF89)
#define PORTA      *((volatile u8*)0xF80)

#define TRISB      *((u8*)0xF93)
#define LATB     *((u8*)0xF8A)
#define PORTB      *((volatile u8*)0xF81)

#define TRISC      *((u8*)0xF94)
#define LATC     *((u8*)0xF8B)
#define PORTC      *((volatile u8*)0xF82)

#define TRISD      *((u8*)0xF95)
#define LATD      *((u8*)0xF8C)
#define PORTD      *((volatile u8*)0xF83)

#define  CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)      0b##b7##b6##b5##b4##b3##b2##b1##b0
#define  CONC(b7,b6,b5,b4,b3,b2,b1,b0)           CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)



#endif /* PIC_PRIV_H_ */
