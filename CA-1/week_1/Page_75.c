#include<stdio.h>
#define max 30
int top = -1;
void push(char *stack, char value);
void pop(char *stack);
void print_stack(char stack[]);
char stack[max];
int main(){
    char input[30];
    printf("Enter the sequence : ");
    scanf("%s",input);
    for(int i=0; input[i]!='\0'; i++){
        if(input[i]=='*'){
            pop(stack);
        }
        else{
            push(stack,input[i]);
        }
    }
print_stack(stack);
return 0;
}
void push(char *stack, char value){
    if(top==max-1){
        printf("Overflow !");
    }
    else{
        top++;
        stack[top] = value;
    }
}
void pop(char *stack){
    if(top==-1){
        printf("Underflow !");
    }
    else{
        top--;
    }
}
void print_stack(char stack[]){
    for(int i=0; i<=top; i++){
        printf("%c\t",stack[i]);
    }
}
