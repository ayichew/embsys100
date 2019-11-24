//#include "swap_pointer.c"
void swap_pointer (int* x, int*);
int main()
{
  int a = 3 ;
  int b = 7 ;
  int *aPtr = &a ;
  int *bPtr = &b ;
  swap_pointer(aPtr,bPtr);
  return 0;
}

void swap_pointer (int* x, int*y)
{
    // swapping the values
    int temp = *x;
    *x = *y;
    *y = temp;
    // swapping the pointers??
    //int* tempPtr = x;
    //x = y;
    //y = tempPtr;
}