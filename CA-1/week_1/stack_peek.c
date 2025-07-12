#include<stdio.h>
# define max 3
int top = max-1;
void peek(int *stack);
int main(){
int value;
int stack[max] = {10,20,30};
peek(stack);
peek(stack);
peek(stack);
return 0;
}
void peek(int *stack){
    if(top<0){
        printf("Underflow\n");
    }
    else{
        printf("\n%d\n",stack[top]);
    }
}