/*
 * File:   PIC_int.h
 * Author: Hager
 *
 * Created on September 2, 2024, 3:15 PM
 */


#include <xc.h>

#include "errorStates.h"
#include "stdTypes.h"

#ifndef PIC_INT_H_
#define PIC_INT_H_

/*  PORT   */
#define PIC_u8LATA        0
#define PIC_u8LATB        1
#define PIC_u8LATC        2
#define PIC_u8LATD        3

/*  PIN   */
#define PIC_u8Pin0    0
#define PIC_u8Pin1    1
#define PIC_u8Pin2    2
#define PIC_u8Pin3    3
#define PIC_u8Pin4    4
#define PIC_u8Pin5    5
#define PIC_u8Pin6    6
#define PIC_u8Pin7    7

/* input in pic =>1  , output in pic =>0  */
#define INPUT  1
#define OUTPUT 0


#define LOW      0
#define HIGH     1
#define FLOAT    0
#define PULL_UP  1

//here prototype
ES_t PIC_enumInt(void);   //methode to write func
//pin
ES_t PIC_enumSetportValue(u8 Copy_u8LatID ,u8 Copy_u8PinID, u8 Copy_u8Value);
	 
ES_t PIC_enumSetLatDirection(u8 Copy_u8LatID , u8 Copy_u8Value);
				
ES_t PIC_enumSetLatValue(u8 Copy_u8LatID , u8 Copy_u8Value);
				
ES_t PIC_enumTogLatValue(u8 Copy_u8LatID );
				
ES_t PIC_enumGetLatValue(u8 Copy_u8LatID , u8 * Copy_pointeru8Value);      // ???? ??????? ??????? ?? ??pin register


/* work on [pins] level  */

/* set,get will pass lat==port id ,pin==port id  */


ES_t PIC_enumSetPortDirection(u8 Copy_u8LatID ,u8 Copy_u8PinID,  u8 Copy_u8Value);
				
ES_t PIC_enumSetPortValue(u8 Copy_u8LatID ,u8 Copy_u8PinID, u8 Copy_u8Value);
				
ES_t PIC_enumTogPortValue(u8 Copy_u8LatID ,u8 Copy_u8PinID );
				
ES_t PIC_enumGetPortValue(u8 Copy_u8LatID ,u8 Copy_u8PinID, u8 * Copy_pointeru8Value);




#endif /* PIC_INT_H_ */

