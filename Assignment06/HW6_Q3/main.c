#include <stdint.h>

#include "stm32f401xe.h"
#include "system_stm32f4xx.h"

#define LED_ON          1
#define LED_OFF         0
#define DELAY_DURATION  1000000

void delay(uint32_t iteration);
void control_user_led(uint8_t state, uint32_t duration);

void main(void)
{    
      // Enable the clock for GPIOA
  // around line 352 of stm32f401xe.h   :
  // RCC_TypeDef is a structure that defines the Reset and Clock Control (RCC)
      // #define RCC                 ((RCC_TypeDef *) RCC_BASE)
      // around line 358  __IO uint32_t AHB1RSTR;  is defined as member of the
  // RCC_TypeDef structure.
      // #define RCC_AHB1ENR_GPIOAEN_Msk            (0x1U << RCC_AHB1ENR_GPIOAEN_Pos)   /*!< 0x00000001 */
      // #define RCC_AHB1ENR_GPIOAEN                RCC_AHB1ENR_GPIOAEN_Msk             
  // The iar editor provided dropdown menu listing of RCC properties.
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN ;
  
  // likewise ... Set GPIOA for output
  // Set bit[11:10] to 0x01  so --> 0x400 // To enable Port5 as output
      // #define GPIO_MODER_MODE5_0               (0x1U << GPIO_MODER_MODE5_Pos)        /*!< 0x00000400 */
  // 
  GPIOA->MODER |= GPIO_MODER_MODE5_0  ;
     
  while(1)
  {
    //The below bunch lines are used to test delay assembly code by itself.
    //GPIOA_ODR = 0x20          ;
    //delay(DELAY_DURATION)     ;
    //GPIOA_ODR = 0x00          ;
    //delay(DELAY_DURATION)     ;
    
    control_user_led(LED_ON,  DELAY_DURATION) ;
    control_user_led(LED_OFF, DELAY_DURATION) ;
  }
}

// IAR default size 0x08000000