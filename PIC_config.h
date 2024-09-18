/*
 * File:   PIC_config.h
 * Author: Hager
 *
 * Created on September 2, 2024, 3:16 PM
 */



#ifndef PIC_CONFIG_H_
#define PIC_CONFIG_H_



/* you can use INPUT or OUPUT */

	
	
#define LA_Pin0_DIR     INPUT
#define LA_Pin1_DIR     OUTPUT
#define LA_Pin2_DIR     OUTPUT
#define LA_Pin3_DIR     INPUT
#define LA_Pin4_DIR     OUTPUT
#define LA_Pin5_DIR     INPUT
#define LA_Pin6_DIR     INPUT
#define LA_Pin7_DIR     OUTPUT
/*10010110*/ /*  => b7 b6 b5 b4 b3 b2 b1 b0*/

#define LB_Pin0_DIR     INPUT
#define LB_Pin1_DIR     OUTPUT
#define LB_Pin2_DIR     OUTPUT
#define LB_Pin3_DIR     INPUT
#define LB_Pin4_DIR     OUTPUT
#define LB_Pin5_DIR     INPUT
#define LB_Pin6_DIR     INPUT
#define LB_Pin7_DIR     OUTPUT

#define LC_Pin0_DIR     INPUT
#define LC_Pin1_DIR     OUTPUT
#define LC_Pin2_DIR     OUTPUT
#define LC_Pin3_DIR     INPUT
#define LC_Pin4_DIR     OUTPUT
#define LC_Pin5_DIR     INPUT
#define LC_Pin6_DIR     INPUT
#define LC_Pin7_DIR     OUTPUT

#define LD_Pin0_DIR     INPUT
#define LD_Pin1_DIR     OUTPUT
#define LD_Pin2_DIR     OUTPUT
#define LD_Pin3_DIR     INPUT
#define LD_Pin4_DIR     OUTPUT
#define LD_Pin5_DIR     INPUT
#define LD_Pin6_DIR     INPUT
#define LD_Pin7_DIR     OUTPUT






#define LA_Pin0_VAL     FLOAT
#define LA_Pin1_VAL     HIGH
#define LA_Pin2_VAL     LOW
#define LA_Pin3_VAL     PULL_UP
#define LA_Pin4_VAL     HIGH
#define LA_Pin5_VAL     FLOAT
#define LA_Pin6_VAL     PULL_UP
#define LA_Pin7_VAL     LOW
/*01011010*/



#define LB_Pin0_VAL     FLOAT
#define LB_Pin1_VAL     HIGH
#define LB_Pin2_VAL     LOW
#define LB_Pin3_VAL     PULL_UP
#define LB_Pin4_VAL     HIGH
#define LB_Pin5_VAL     FLOAT
#define LB_Pin6_VAL     PULL_UP
#define LB_Pin7_VAL     LOW


#define LC_Pin0_VAL     FLOAT
#define LC_Pin1_VAL     HIGH
#define LC_Pin2_VAL     LOW
#define LC_Pin3_VAL     PULL_UP
#define LC_Pin4_VAL     HIGH
#define LC_Pin5_VAL     FLOAT
#define LC_Pin6_VAL     PULL_UP
#define LC_Pin7_VAL     LOW


#define LD_Pin0_VAL     FLOAT
#define LD_Pin1_VAL     HIGH
#define LD_Pin2_VAL     LOW
#define LD_Pin3_VAL     PULL_UP
#define LD_Pin4_VAL     HIGH
#define LD_Pin5_VAL     FLOAT
#define LD_Pin6_VAL     PULL_UP
#define LD_Pin7_VAL     LOW







#endif /* DIO_CONFIG_H_ */
