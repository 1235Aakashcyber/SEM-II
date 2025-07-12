#include<stdio.h>
# define max 3
int top = -1;
void push(int *stack, int value);
int main(){
int value;
int stack[max];
push(stack,10);
push(stack,20);
push(stack,30);
push(stack,40);
for(int i = 0; i<3; i++){
printf("%d\n",stack[i]);
}
return 0;
}
void push(int *stack, int value){
    if(top==(max-1)){
        printf("Overflow\n");
    }
    else{
        top += 1;
        stack[top] = value;
    }
}