void swap_pointer (int* x, int*y)
{
    // swapping the values
    int temp = *x;
    *x = *y;
    *y = temp;
    
    // swapping the pointers??
    int* tempPtr = x;
 
    y = tempPtr;
}