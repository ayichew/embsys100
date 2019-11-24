Emb. Sys 101. UW.
By Efrem Ayichew
Nov 2019

============================
1. (folder name: swapExample)
1.a. 
I declared the variables as local and the main() funciton stored them onto the stack before it calls swap_pointer(). It also did other house keeping with {R5-R7, LR} - also pushing those onto the stack.

1.b. 
R0 and R1 have the address in the stack of where thier respective local variables are stored. Inspecting those (stack) memory locations reveal in fact the initialed locals are preserved in the stack.

1.c.
saved as swap_workspace_snip file in the folder. 
Note - I used values 3 and 7 for initial values for the main() locals.

---------------------
(folder name: HelloWorld)
2.
3.
Both part 2 and 3 are done under the HelloWorld project

snapshot saved as Asm4MathSnip

Note:   I was not able to capture the return value of both the square and div by 2 and write it into Tera Term.
        But the basic string display was able to work.

---------------
(folder name: swapWithAsm)
4. note: I did not do the bonus parts