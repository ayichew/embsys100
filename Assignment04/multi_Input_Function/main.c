/* 
 Observe stack and registrs under multiple function inputs\
 Assignment 4  UW
 Efrem E. Ayichew
*/

int callMe1(int, int, int, int, int, int, int );
int callMe2(int);

int main()
{
 int a1 = 1;
 int a2 = 2;
 int a3 = 3;
 int a4 = 4;
 int a5 = 5;
 int a6 = 6;
 int a7 = 7;
 
 int summed1, summed2 ;
 summed1 = callMe1(a1, a2, a3, a4, a5, a6,a7);
 summed2 = callMe2(a1);

 return summed2;
}

int callMe1(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
 int returnMe = 0;
 returnMe = a1+a2+a3+a4+a5+a6+a7;
 return returnMe;
}
int callMe2(int a1)
{
 int returnMe = 0;
 return returnMe;
}

/*
int callMe(int a[100] );

int main()
{
  int a[100];
  for (int i=0; i<100; i++)
  {
    a[i]= i+1;
  }
  int summed ;
    
  //summed = callMe(a1, a2, a3, a1, a2, a3);
  summed = callMe(a);
  
  return summed;
}

//int callMe(int a1, int a2, int a3, int a4, int a5, int a6)
int callMe(int a[100] )
{
 int returnMe = 0;
 for (int j=0;j<100;j++)
 {
   returnMe +=a[j];
 }
 return returnMe;
}
*/