/*
 * BitMath.h
 *
 * Created: 17-Feb-21 10:48:01 AM
 *  Author: dell
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

/* Set bit in register */
#define SET_BIT(REG,BIT) (REG |= (1<<BIT))

/* Clear bit in register */
#define CLR_BIT(REG,BIT) (REG &=~ (1<<BIT))


/* Toggle bit in register */
#define TGL_BIT(REG,BIT) (REG ^= (1<<BIT))


/* Get bit in register */
#define GET_BIT(REG,BIT) ((REG >> BIT) &1)




#endif /* BITMATH_H_ */