// .. Define enable, moder and ODR registers using bit banding
// .... perpheral alias has a base of 0x42000000
#define PERIPH_BIT_BAND_BASE     (0x42000000)

//........ Byte offsets
// clock enable
// the RCC_AHB1_ENR bit is in this 0x40023830 address hinting the byte offset
#define BYT_OFFSET_RCC_AHB1_ENR  (0x23830)
// i/o config for in or output
// the GPIOA_MODER bit is in this 0x40020000 address hinting the byte offset
#define BYT_OFFSET_GPIOA_MODER   (0x2000)
// actual GPIO bit setting
// the GPIOA_ODR bit is in this 0x40020014 address hinting the byte offset
#define BYT_OFFSET_GPIOA_ODR     (0x20014)

// .... define bit numbers
#define BIT_NUMBER_RCC_AHB1_ENR  (0)
#define BIT_NUMBER_GPIOA_MODER10 (10) // 10th bit to set to set GPIOA to output
#define BIT_NUMBER_GPIOA_MODER11 (11)// 10th bit to set to set GPIOA to output
#define BIT_NUMBER_GPIOA_ODR     (5)

// BIT binding formula for latest ARM Cortex 
// bit_word_addr = bit_band_base + (byte_offset*32) + (bit_number 4)
// next line - using macro as function definition - adapted from ...
// https://atadiat.com/en/e-bit-banding-explained-a-feature-of-arm-cortex-m3/
#define BITBAND_PERI(byteOffset,biteNumber) (PERIPH_BIT_BAND_BASE + (byteOffset*32) + (biteNumber*4))

#define GPIOA_BITBAND_RCC_AHB1_ENR  (*(unsigned int*)BITBAND_PERI(BYT_OFFSET_RCC_AHB1_ENR,BIT_NUMBER_RCC_AHB1_ENR  ))
#define GPIOA_BITBAND_GPIOA_MODER10 (*(unsigned int*)BITBAND_PERI(BYT_OFFSET_GPIOA_MODER, BIT_NUMBER_GPIOA_MODER10 ))
#define GPIOA_BITBAND_GPIOA_MODER11 (*(unsigned int*)BITBAND_PERI(BYT_OFFSET_GPIOA_MODER, BIT_NUMBER_GPIOA_MODER11 ))
#define GPIOA_BITBAND_GPIOA_ODR     (*(unsigned int*)BITBAND_PERI(BYT_OFFSET_GPIOA_ODR,   BIT_NUMBER_GPIOA_ODR     ))


//*(unsigned int*) bitBinder(unsigned int*, unsigned int*, unsigned int*);