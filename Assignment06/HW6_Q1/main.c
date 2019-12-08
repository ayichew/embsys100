/*
 HW6 Q1 ... by E. Ayichew
 Dec 2019
*/
// include CMSIS files
#include "stm32f401xe.h"
#include "system_stm32f4xx.h"

void delayByThis(unsigned);


void main(){
  // Enable the clock for GPIOA
  // around line 352 of stm32f401xe.h   :
  // RCC_TypeDef is a structure that defines the Reset and Clock Control (RCC)
      // #define RCC                 ((RCC_TypeDef *) RCC_BASE)
      // around line 358  __IO uint32_t AHB1RSTR;  is defined as member of the
  // RCC_TypeDef structure.
      // #define RCC_AHB1ENR_GPIOAEN_Msk            (0x1U << RCC_AHB1ENR_GPIOAEN_Pos)   /*!< 0x00000001 */
      // #define RCC_AHB1ENR_GPIOAEN                RCC_AHB1ENR_GPIOAEN_Msk             
  // The iar editor provided dropdown menu listing of RCC properties.
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
  
  // likewise ... Set GPIOA for output
  // Set bit[11:10] to 0x01  so --> 0x400 // To enable Port5 as output
      // #define GPIO_MODER_MODE5_0               (0x1U << GPIO_MODER_MODE5_Pos)        /*!< 0x00000400 */
  // 
  GPIOA->MODER |= GPIO_MODER_MODE5_0 ;
  
  // turn on GPIOA
  while(1){
    // LED on
    // from prior assignments LED On GPIOA_ODR = 0x20;
        // #define GPIO_ODR_OD5_Msk                 (0x1U << GPIO_ODR_OD5_Pos)            /*!< 0x00000020 */
        // #define GPIO_ODR_OD5                     GPIO_ODR_OD5_Msk      
    // set bit 5 to zero
    // GPIO is of GPIO_TypeDef structure type 
    GPIOA->ODR   |= GPIO_ODR_OD5 ;
    delayByThis(2000);
    // LED off
    GPIOA->ODR   = 0x00 ;
    delayByThis(2000);
  }
  
}
void delayByThis(unsigned n) {
  n = n*1000;
  unsigned counter = 0;
  while(counter < n)
  {
    counter++;
  }
 }