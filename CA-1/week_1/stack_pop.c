#include<stdio.h>
# define max 3
int top = -1;
void pop(int *stack, int value);
int main(){
int value;
int stack[max] = {1,2,3};
pop(stack,1);
pop(stack,2);
pop(stack,3);
// pop(stack,4);
for(int i = 0; i<3; i++){
printf("%d\n",stack[i]);
}
return 0;
}
void pop(int *stack, int value){
    if(top<0){
        printf("\nUnderflow\n");
    }
    else{
        printf("\n%d is the element which is popped out\n",stack[top]);
        top--;
    }
}