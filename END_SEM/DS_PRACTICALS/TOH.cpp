//Tower of hanoi solver

#include<stdio.h>
#include<conio.h>
void toh(int n, char from_rod, char to_rod, char aux_rod){
if(n==1){
printf("Move the disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
return;
}
toh(n-1, from_rod, aux_rod, to_rod);
printf("Move the disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
toh(n-1, aux_rod, to_rod, from_rod);
}
int main(){
int n;
clrscr();
printf("Enter the number of disks : ");
scanf("%d",&n);

printf("Follow the below steps to solve tower of hanoi problem :\n");
toh(n,'A', 'C', 'B');
getch();
return 0;
}
