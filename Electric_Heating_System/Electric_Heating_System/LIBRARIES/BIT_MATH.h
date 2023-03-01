#ifndef _COMMON_BIT_MATH_H_
#define _COMMON_BIT_MATH_H_

#define SET_BIT(REG, BIT) REG |= (1 << BIT)
#define CLR_BIT(REG, BIT) REG &= ~(1 << BIT)
#define TOG_BIT(REG, BIT) REG ^= (1 << BIT)
#define GET_BIT(REG, BIT) ((REG & (1u << BIT)) >> BIT)

#endif