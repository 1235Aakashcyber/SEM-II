#include<stdio.h>
#define max 3
int top = -1;
void push(int *stack, int value);
void pop(int *stack);
void print_stack(int stack[]);
int stack[max];
int main(){
    char exit;
    int choice;
A:
    printf("Enter your choice (1 for push) and (2 for pop) : ");
    scanf("%d",&choice);
    if(choice==1){
        int value;
        printf("Enter the value you want to push : ");
        scanf("%d",&value);
        push(stack,value);
    }
    else if(choice==2){
        pop(stack);
    }
    else{
        printf("Gadhe ho kya be !");
    }
    printf("\nTo continue press 'c' to print the stack press 'p' else to exit press 'e'.....");
    scanf(" %c",&exit);
    if(exit=='c'){
        goto A;
    }
    else if(exit=='p' || exit == 'P'){
        printf("Your stack is : ");
        print_stack(stack);
    }
    else if(exit=='e'||exit=='E'){
        return 0;
    }

return 0;
}
void push(int *stack, int value){
    if(top==max-1){
        printf("Overflow !");
    }
    else{
        top++;
        stack[top] = value;
        printf("Your new stack is : ");
        print_stack(stack);
    }
}
void pop(int *stack){
    if(top==-1){
        printf("Underflow !");
    }
    else{
        printf("%d element is popped out !",stack[top]);
        top--;
    }
}
void print_stack(int stack[]){
    for(int i=0; i<=top; i++){
        printf("%d\t",stack[i]);
    }
}
