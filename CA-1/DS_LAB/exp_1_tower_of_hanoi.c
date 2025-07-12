#include<stdio.h>
#include<conio.h>
#include<math.h>
char e;
void toh(int n, char a, char b, char c);
int main(){
    int n;
    char a = 'A'; char b = 'B'; char c = 'C';       //Characters assigned for each tower.
A:
    printf("Enter the number of disks : ");
    scanf("%d",&n);
    int steps = (pow(2,n) - 1);                    //Calculates the total steps required.
    printf("Follow the below steps to solve the tower of hanoi...\n");
    toh(n,a,b,c);
    printf("\nTotal number of steps required : %d\n",steps);
    printf("To continue enter 'c' else enter 'e' to exit....");
    scanf(" %c",&e);
    if(e=='c' || e=='C'){
        goto A;
    }
    else{
        return 0;
    }
}
void toh(int n, char a, char b, char c){
    if(n==1){
        printf("Move disk %d from tower %c to tower %c\n",n,a,c);
    }
    else{
    toh(n-1, a, c, b);
    printf("Move disk %d from tower %c to tower %c\n",n,a,c);
    toh(n-1, b, a, c);
}
}




