/*
 * BIT_MATH.h
 *
 * Created: 9/25/2023 5:01:01 AM
 *  Author: lraya
 */ 

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define REG  NULL
#define BIT_NUM NULL

#define SET_BIT(REG,BIT_NUM)        REG|=(1<<BIT_NUM)
#define CLEAR_BIT(REG,BIT_NUM)      REG&=~(1<<BIT_NUM)
#define TOOGLE_BIT(REG,BIT_NUM)     REG^=(1<<BIT_NUM)
#define CHECK_BIT(REG,BIT_NUM)      ((REG>>BIT_NUM)&1)


#endif