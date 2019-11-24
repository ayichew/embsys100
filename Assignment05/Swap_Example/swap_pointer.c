void swap_pointer (char* x, char*y)
{
    // swapping the values
    int temp = *x;
    *x = *y;
    *y = temp;
    
    // swapping the pointers??
    char* tempPtr = x;
 
    y = tempPtr;
}