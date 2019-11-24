/*******************************************************************************
File name       : swapCharsAsm.s
Description     : Assembly language function for swapping charactos
C Prototype     : void swapCharsAsm(void)
****************************************************************************** */  
// Exports symbols to other modules
// the below line must be indented, apparentlly
        PUBLIC swapCharsAsm
// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

        SECTION .text:CODE:REORDER:NOROOT(2)
        THUMB
        
swapCharsAsm 
    // swapping is done by shuffling the stack where the two chars are 
    // placed sequentially. We pass char pointers to force the caller
    // to push the addresses to the stack exposing them to the called ASM function
    // In this case none of the registers are preserved by the ASM, intentionally
    
    // load charactors from stack
    LDRB.W      R0, [SP, #0x0]
    LDRB.W      R1, [SP, #0x1]
    
    // x-x and store them back to stack
    STRB.W      R0, [SP, #0x1]
    STRB.W      R1, [SP, #0x0]
   
    // back to the caller
    BX LR
                                   
    END