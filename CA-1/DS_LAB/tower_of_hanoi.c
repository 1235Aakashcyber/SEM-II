#include<stdio.h>
char e;
void toh(int n, char a, char b, char c);
int main(){
    int n;
    char a = 'A'; char b = 'B'; char c = 'C';
A:
    printf("Enter the number of disks : ");
    scanf("%d",&n);
    printf("Follow the below steps to solve the tower of hanoi...\n");
    toh(n,a,b,c);
    printf("To continue enter 'y' else enter 'e' to exit....");
    scanf(" %c",&e);
    if(e=='y' || e=='Y'){
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