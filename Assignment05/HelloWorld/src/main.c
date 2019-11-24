/*******************************************************************************
FILE NAME   : main.c
DESCRIPTION : Where all the magic begins.
	      

Copyright   : David Allegre
            : 2015
	    : All Rights Reserved
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "nucleoboard.h"
#include "hw_init.h"
#include "print.h"

// Assembly Call
extern int sqrAsm(int);
extern int div2Asm(int);

char  messageEA[30] = "\n Square in assembly :\n";
char * myCstr = &messageEA[0];

char divMessageEA[30] = "\n Div by 2 in assembly :\n";
char * myDivCstr      = &divMessageEA[0];

char clr_scrn[] = { 27, 91, 50, 74, 0 };              // esc[2J
/* Public variables ----------------------------------------------------------*/
__IO uint32_t timer;
PRINT_DEFINEBUFFER();           /* required for lightweight sprintf */
/* Private prototype ---------------------------------------------------------*/
void delay(uint32_t time);

/* ******************************************************************************
Function Name   : main
Description     : 
Parameters      :
Return value    :               */
void main() {
  int foo;

  foo = 10;
  Hw_init();

  PrintString(clr_scrn); /* Clear entire screen */
  // Change [My name] to your name      //
  // PrintString("Efrem's Nucleo STM32F401 is ... alive!!! and ... \n");
  // PrintString("\n\n Assembly Code Start ... :  \n\n");
  
  int sqr = sqrAsm(foo);
  char sqrChar = (char) sqr;
  PrintString((char*) &(sqrChar));

  //PrintString("\n\n Divide a number by 2 Assembly Code Result ... :  \n\n");
  int div2 = div2Asm(foo);
  char div2Char = (char) div2;
  PrintString((char*) &(div2Char));
  
  // PrintString("\n\n ....Assembly code end\n");
  
/*
  RETAILMSG(1, ("Programming Assignment #6: Built %s %s.\r\n\r\n",
              __DATE__,
              __TIME__));  
  while (foo) {
    GPIO_ToggleBits(GPIO_PORT_LD2, GPIO_PIN_LD2);
    PrintString("EMBSYS CP100A: University of Washington - UART Test Application \n");
    
    delay(1000);
    GPIO_ToggleBits(GPIO_PORT_LD2, GPIO_PIN_LD2);
    
    delay(1000);
    foo--;
  }
  while (1) {
    // loop forever
    asm("nop");
  }
*/
}

void delay(uint32_t time) {
  
  timer = time;
  while(timer) {}
}
void SystemInit(void) {
  // System init is called from the assembly .s file
  // We will configure the clocks in hw_init
  asm("nop");
}
  