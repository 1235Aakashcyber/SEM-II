#include<stdio.h>

  void TOH(int n,char a , char b , char c)
  {
  if (n==1){
  printf("shift ring %d from %c to %c",n,a,c);
  }
  else{

  TOH(n-1,a,c,b);

  printf("shif ring %d from %c to %c\n",n,a,c);

  TOH(n-1,b,a,c);
  }
  }
  void main(){
  int n=3;
  char a;
  char c;
  char b;
  TOH(n,a,b,c);
  }