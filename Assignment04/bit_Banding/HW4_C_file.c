void delayByThis(unsigned);
void delayByThis(unsigned n) 
{
  n = n*1000;
  unsigned counter = 0;
  while(counter < n)   {     counter++;   }
 }