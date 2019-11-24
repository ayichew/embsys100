
// Assembly Call
extern  int swapCharsAsm(char*, char*);
void swap_pointer();

int main()
{
  char FN = 'E';
  char LN = 'A';
  (void) swapCharsAsm(&FN,&LN);
  
  return 0;
  // note that first name and last name initials are swapped in the locals 
  // viewer
}