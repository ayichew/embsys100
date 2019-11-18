/*
 Homework #4 
 Efrem E. Ayichew Nov. 2019 UW Embedded Programming I
*/
/*
 Redo blinking LED using BIT banding method
*/

#include "HW4_Header.h"
//#include "HW4_h_file2.h"
#include "HW4_C_file.c"

int main(void)
{
  GPIOA_BITBAND_RCC_AHB1_ENR   =0x1 ;
  GPIOA_BITBAND_GPIOA_MODER10  =0x1 ;
  GPIOA_BITBAND_GPIOA_MODER11  =0x1 ;

  //RCC_AHB1ENR = 0x01;       // enable clock to GPIOA
  //GPIOA_MODER = 0xA8000400; // set GPIOA as output
  
  volatile int blinks  = 0  ;
  
  while(blinks < 10000) 
  {
   GPIOA_BITBAND_GPIOA_ODR   =1  ;
   delayByThis(200)                ;
   GPIOA_BITBAND_GPIOA_ODR   =0  ;
   delayByThis(200)                ;
   
   blinks ++;
  }
  return 0;
}
