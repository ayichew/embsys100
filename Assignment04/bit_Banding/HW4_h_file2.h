// clock enable base register

#define RCC_BASE 0x40023800
// offset for GPIOA clock enable
#define RCC_AHB1ENR (*((unsigned int*)(RCC_BASE + 0x30)))

// GPIOA input vs output mode set base and offset
#define GPIOA_BASER 0x40020000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASER+0x00)))

// apply bit binding for the LED2 pin access
#define PERIPH_BIT_BAND_BASE (0x42000000)
// define bit banding relationship as a function
#define BITBAND_PERI(byteOffset,biteNumber) (PERIPH_BIT_BAND_BASE + (byteOffset*32) + (biteNumber*4))
#define BYT_OFFSET_GPIOA_ODR (0x23830)
#define BIT_NUMBER_GPIOA_ODR (0x20)
#define GPIOA_BITBAND_GPIOA_ODR (*(unsigned int*)BITBAND_PERI(BYT_OFFSET_GPIOA_ODR,BIT_NUMBER_GPIOA_ODR ))
