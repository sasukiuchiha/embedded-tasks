#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(REG,BIT_NUM)    REG|=(1<<(BIT_NUM))
#define CLR_BIT(REG,BIT_NUM)    REG&=(~(1<<(BIT_NUM)))
#define TOGGLE_BIT(REG,BIT_NUM) REG^=(1<<(BIT_NUM))
#define GET_BIT(REG,BIT_NUM)    REG&(1<<BIT_NUM)



#endif
