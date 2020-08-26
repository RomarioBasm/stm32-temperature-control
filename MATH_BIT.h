/******************************************************/
/* Author   : Romario Basem                           */
/* Date     : 25 AUG 2020                             */
/* Version  : V01                                     */
/******************************************************/
#ifndef MATH_BIT_H
#define MATH_BIT_H

#define SET_BIT(VAR,BIT)   VAR|=(1<<(BIT))
#define CLR_BIT(VAR,BIT)   VAR&=(1<<(BIT))
#define GET_BIT(VAR,BIT)   (VAR>>BIT)&1
#define TOR_BIT(VAR,BIT)   VAR^=(1<<(BIT))

#define SET_REG_PIN(REG,BIT,VAL)  (((REG)&(~(1<<BIT)))|((VAL)<<(BIT)))
#define READ_REG_PIN(REG,BIT)  (((REG)&(1<<BIT))>>(BIT))


#endif