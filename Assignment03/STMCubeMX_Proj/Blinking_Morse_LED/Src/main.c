// Embedded systems HW 3
// Efrem Ayichew
// 2019

// clock enable base register
#define RCC_BASE 0x40023800
// offset for GPIOA clock enable
#define RCC_AHB1ENR (*((unsigned int*)(RCC_BASE + 0x30)))

// GPIOA input vs output mode set base and offset
#define GPIOA_BASER 0x40020000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASER+0x00)))
#define GPIOA_ODR   (*((unsigned int*)(GPIOA_BASER+0x14)))

char formMorse(const char *);
void dotSignal();
void dashSignal();
void LED_on();
void LED_off();
void entryPause();
void pauseForDot();
void pauseForDash();
void pauseInBetween();
void delayByThis();

int main() {
  RCC_AHB1ENR = 0x01; // enable clock to GPIOA
  GPIOA_MODER = 0xA8000400; // set GPIOA as output
  
  char EFREM_MORSE_CODE[16] = ". ..-. .-. . --" ;
  //char EFREM_MORSE_CODE[16] = "- - - - . . . . "; 
  for (int i=0; i< 15; i++)   
  {
    if (EFREM_MORSE_CODE[i] == '.')             { dotSignal();      }
    else if (EFREM_MORSE_CODE[i] == '-')        { dashSignal();     }
    else                                        { pauseInBetween(); }
  }
  return 0;
}
void dotSignal() {
    entryPause();     LED_on();      pauseForDot();     LED_off();
}
void dashSignal() {
    entryPause();     LED_on();      pauseForDash();    LED_off();
}
void LED_on()        { GPIOA_ODR = 0x20; }
void LED_off()       { GPIOA_ODR = 0x00; }

void entryPause()    { delayByThis(2000)   ; }
void pauseForDot()   { delayByThis(1000)   ; }
void pauseForDash()  { delayByThis(4500)  ; }
void pauseInBetween(){ delayByThis(5000)  ; }

void delayByThis(unsigned n) {
  n = n*1000;
  unsigned counter = 0;
  while(counter < n)
  {
    counter++;
  }
 }