HW#6 Writeup by E. Ayichew

================================================
3. 
a) and b) the size of the code from Q2. is :
    
    Module            ro code  rw data
    ------            -------  -------

    Grand Total:          292    8'192

ROM ......................^^^
RAM .............................^^^^^


c) d) 
The ROM is used to store the text/code while the RAM is used to capture variables

------------------------
4. Ways to reduce program size:
The most effective way I found is to downsize the stack as demonstrated in class. 
Below is the code size after:
-> adapting CMSIS library under libraty configuration
-> Using assembly code for delay routine from Q2
-> Reducing the stack/heap sizes as demonstrated in class
-> applying maximum code optimization option
-> selecting the " inline small routines " option
-> selecting "merge duplicate sections " option

    Module            ro code  rw data
    ------            -------  -------

    Linker created                 512
--------------------------------------
    Grand Total:          252      512

ROM ......................^^^
RAM .............................^^^^^

The project with these choices is part of the submission.

