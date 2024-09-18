/*
 * File:   PIC_prog.c
 * Author: Hager
 *
 * Created on September 2, 2024, 3:15 PM
 */





#include "stdTypes.h"
#include "errorStates.h"

#include "PIC_priv.h"
#include "PIC_config.h"




//here implementation to func

ES_t PIC_enumInt(void)   //methode to write func
{
	ES_t Local_enumErrorstate = ES_NOK;

	TRISA = CONC( LA_Pin7_DIR ,  LA_Pin6_DIR, LA_Pin5_DIR,  LA_Pin4_DIR,  LA_Pin3_DIR, LA_Pin2_DIR , LA_Pin1_DIR,  LA_Pin0_DIR);
	TRISB = CONC( LB_Pin7_DIR ,  LB_Pin6_DIR, LB_Pin5_DIR,  LB_Pin4_DIR,  LB_Pin3_DIR, LB_Pin2_DIR , LB_Pin1_DIR,  LB_Pin0_DIR);
	TRISC = CONC( LC_Pin7_DIR ,  LC_Pin6_DIR, LC_Pin5_DIR,  LC_Pin4_DIR,  LC_Pin3_DIR, LC_Pin2_DIR , LC_Pin1_DIR,  LC_Pin0_DIR);
	TRISD = CONC( LD_Pin7_DIR ,  LD_Pin6_DIR, LD_Pin5_DIR,  LD_Pin4_DIR,  LD_Pin3_DIR, LD_Pin2_DIR , LD_Pin1_DIR,  LD_Pin0_DIR);
															
															
	LATA = CONC( LA_Pin7_VAL ,  LA_Pin6_VAL, LA_Pin5_VAL,  LA_Pin4_VAL,  LA_Pin3_VAL, LA_Pin2_VAL , LA_Pin1_VAL,  LA_Pin0_VAL);
	LATB = CONC( LB_Pin7_VAL ,  LB_Pin6_VAL, LB_Pin5_VAL,  LB_Pin4_VAL,  LB_Pin3_VAL, LB_Pin2_VAL , LB_Pin1_VAL,  LB_Pin0_VAL);
	LATC = CONC( LC_Pin7_VAL ,  LC_Pin6_VAL, LC_Pin5_VAL,  LC_Pin4_VAL,  LC_Pin3_VAL, LC_Pin2_VAL , LC_Pin1_VAL,  LC_Pin0_VAL);
	LATD = CONC( LD_Pin7_VAL,   LD_Pin6_VAL, LD_Pin5_VAL,  LD_Pin4_VAL,  LD_Pin3_VAL, LD_Pin2_VAL , LD_Pin1_VAL,  LD_Pin0_VAL);
																														 
	Local_enumErrorstate = ES_NOK;
	return Local_enumErrorstate;
}


ES_t PIC_enumSetLatDirection(u8 Copy_u8LatID , u8 Copy_u8Direction)
{
	ES_t Local_enumErrorstate = ES_NOK;     // worest case

	if(Copy_u8LatID <= PIC_LATD)  // <=3
	{
		switch(Copy_u8LatID)
		{
		case PIC_LATA:
			 TRISA= Copy_u8Direction;
			break;
		case PIC_LATB:
			 TRISB= Copy_u8Direction;
			break;
		case PIC_LATC:
			 TRISC= Copy_u8Direction;
			break;
		case PIC_LATD:
			 TRISD= Copy_u8Direction;
			break;
		}
		Local_enumErrorstate = ES_OK;
	}
	else
	{
		Local_enumErrorstate = ES_OUT_OF_RANGE;
	}

   return Local_enumErrorstate;
}


ES_t PIC_enumSetLatValue(u8 Copy_u8LatID , u8 Copy_u8Value)
{
	ES_t Local_enumErrorstate = ES_NOK;
	if(Copy_u8LatID <= PIC_LATD)  // <=3
	{
		switch(Copy_u8LatID)
		{
		case PIC_LATA:
			 LATA= Copy_u8Value;
			break;
		case PIC_LATB:
			 LATB= Copy_u8Value;
			break;
		case PIC_LATC:
			 LATC= Copy_u8Value;
			break;
		casePICPIC_LATD:
			 LATD= Copy_u8Value;
			break;
		}
		Local_enumErrorstate = ES_OK;
	}
	else
	{
		Local_enumErrorstate = ES_OUT_OF_RANGE;
	}

   return Local_enumErrorstate;
}


ES_t PIC_enumTogLatValue(u8 Copy_u8LatID )
{
	ES_t Local_enumErrorstate = ES_NOK;
	if(Copy_u8LatID <= PIC_LATD)  // <=3
	{
		switch(Copy_u8LatID)
		{
		case PIC_LATA:
			 LATA= ~LATA;
			break;
		case PIC_LATB:
			 LATB= ~LATB;
			break;
		case PIC_LATC:
			 LATC= ~LATC;
			break;
		case PIC_LATD:
			 LATD= ~LATD;
			break;
		}
		Local_enumErrorstate = ES_OK;
	}
	else
	{
		Local_enumErrorstate = ES_OUT_OF_RANGE;
	}


   return Local_enumErrorstate;
}


ES_t PIC_enumGetLatValue(u8 Copy_u8LatID , u8 * Copy_pointeru8Value)    // ???? ??????? ??????? ?? ??pin register , read value of pin reg and return in pointer
{
	ES_t Local_enumErrorstate = ES_NOK;
	if (Copy_pointeru8Value !=NULL)
	{
			if(Copy_u8LatID <= PIC_LATD)  // <=3
			{
				switch(Copy_u8LatID)
				{
				case PIC_LATA:
					*Copy_pointeru8Value = PORTA;
					break;
				case PIC_LATB:
					*Copy_pointeru8Value = PORTB;
					break;
				case PIC_LATC:
					 *Copy_pointeru8Value = PORTC;
					break;
				case PIC_LATD:
					 *Copy_pointeru8Value = PORTD;
					break;
				}
		}
		else
		{
			Local_enumErrorstate = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enumErrorstate = ES_NULL_POINTER;
	}


   return Local_enumErrorstate;
}





// work on pins level
// set,get will pass pin id ,port id

ES_t PIC_enumSetPortDirection(u8 Copy_u8LatID ,u8 Copy_u8PinID,  u8 Copy_u8Value)
{
	ES_t Local_enumErrorstate = ES_NOK;
	if(Copy_u8LatID <=PIC_LATD && Copy_u8PinID <=PIC_Pin7 && Copy_u8Value<= OUTPUT)
	{
		switch(Copy_u8PinID)     
		{
		case PIC_LATA:
			TRISA &=~ (1<<Copy_u8PinID);     // mask==clear
 			TRISA |= (Copy_u8Value <<Copy_u8PinID);
 			/*
 			 * TRIS->101-1-1001  => output means:  val =1 ,PORT =4
 		     mask => 101-0-1001  then or with value shift pin
 		     =====> 101-0-1001 | (1<<4)   ===1<<4=>000-1-0000
 		           101-0-1001  |  000-1-0000 = 101-1-1001
 			 * */

			break;
		case PIC_LATB:
			TRISB &=~ (1<<Copy_u8PinID);
 			TRISB |= (Copy_u8Value <<Copy_u8PinID);
			break;
		case PIC_LATC:
			TRISC &=~ (1<<Copy_u8PinID);
 			TRISC |= (Copy_u8Value <<Copy_u8PinID);
			break;
		case PIC_LATD:
			TRISD &=~ (1<<Copy_u8PinID);
 			TRISD |= (Copy_u8Value <<Copy_u8PinID);
			break;
	}
}
	else
	{
		Local_enumErrorstate = ES_OUT_OF_RANGE;
	}

   return Local_enumErrorstate;
}


ES_t PIC_enumSetportValue(u8 Copy_u8LatID ,u8 Copy_u8PinID, u8 Copy_u8Value)
{
	ES_t Local_enumErrorstate = ES_NOK;
	if(Copy_u8LatID <=PIC_LATD && Copy_u8PinID <=PIC_Pin7 && Copy_u8Value<= HIGH)
	{
		switch(Copy_u8LatID)     // will make mask(clear) and or with ddr then left shift eith numbit
		{
		case PIC_LATA:
			LATA &=~ (1<<Copy_u8PinID);
 			LATA |= (Copy_u8Value <<Copy_u8PinID);
 			/*
 			 * TRISA->101-1-1001  => output means:  val =1 ,Port =4
 		     mask => 101-0-1001  then or with value shift port
 		     =====> 101-0-1001 | (1<<4)   ===1<<4=>000-1-0000
 		           101-0-1001  |  000-1-0000 = 101-1-1001
 			 * */

			break;
		case PIC_LATB:
			LATB &=~ (1<<Copy_u8PinID);
 			LATB |= (Copy_u8Value <<Copy_u8PinID);
			break;
		casePIC_LATC:
			LATC &=~ (1<<Copy_u8PinID);
 			LATC |= (Copy_u8Value <<Copy_u8PinID);
			break;
		case PIC_LATD:
			LATD &=~ (1<<Copy_u8PinID);
 			LATD |= (Copy_u8Value <<Copy_u8PinID);
			break;
	}

	}
	else
	{
		Local_enumErrorstate = ES_OUT_OF_RANGE;
	}

   return Local_enumErrorstate;
}


ES_t PIC_enumTogPortValue(u8 Copy_u8LatID ,u8 Copy_u8PinID)
{
	ES_t Local_enumErrorstate = ES_NOK;
	if(Copy_u8LatID <=  PIC_LATD &&Copy_u8PinID<=PIC_Pin7)  // <=7
	{
		switch(Copy_u8LatID)
		{
		case PIC_LATA:
			 LATA^= (1<<Copy_u8PinID);
			break;
		case PIC_LATB:
			 LATB^=(1<< Copy_u8PinID);
			break;
		case PIC_LATC:
			 LATC^=(1<< Copy_u8PinID);
			break;
		case PIC_LATD:
			 LATD^=( 1<<Copy_u8PinID);
			break;
		}
		Local_enumErrorstate = ES_OK;
	}
	else
	{
		Local_enumErrorstate = ES_OUT_OF_RANGE;
	}

   return Local_enumErrorstate;
}


ES_t PIC_enumGetPortValue(u8 Copy_u8LatID ,u8 Copy_u8PinID, u8 * Copy_pointeru8Value)
{
	ES_t Local_enumErrorstate = ES_NOK;
	if (Copy_pointeru8Value !=NULL)
	{
			if(Copy_u8LatID <= PIC_LATD && Copy_u8PinID <=PIC_Pin7)
			{
				switch(Copy_u8LatID)
				{
				case PIC_LATA:
					*Copy_pointeru8Value = ((PORTA>>Copy_u8PinID)&1);  // to read(GET PIT) pin sepaarte   ??? ??? ???? ??pin ???
					break;
				case PIC_LATB:
					*Copy_pointeru8Value = ((PORTB>>Copy_u8PinID)&1);  // to read pin sepaarte   ??? ??? ???? ??pin
					break;
				case PIC_LATC:
					 *Copy_pointeru8Value = ((PORTC>>Copy_u8PinID)&1);   // to read pin sepaarte   ??? ??? ???? ??pin
					break;
				case PIC_LATD:
					 *Copy_pointeru8Value = ((PORTD>>Copy_u8PinID)&1);   // to read pin sepaarte   ??? ??? ???? ??pin
					break;
				}
		}
		else
		{
			Local_enumErrorstate = ES_OUT_OF_RANGE;
		}
	}
   return Local_enumErrorstate;
}

