// This program checks wether the given input mathematical equation is correct or not in terms of brackets only.
// It checks that if the brackets in the equation are placed at correct position or not, 
// or they are in equal number or not.

#include<stdio.h>
#define max 50
//Function declaration
void push(char value);
int pop();

//stack defnition
char stack[max];
int top = -1;

int main(){
char input[20];
printf("Enter the equation : ");
scanf("%s",input);
for(int i=0; input[i]!='\0'; i++){
    if(input[i]=='(' || input[i] == '{' || input[i] == '['){
        push(input[i]);
    }
    else if(stack[top]=='(' && (input[i] == '}' || input[i] == ']')){
        printf("Not a valid equation\n");
        return 0;
    }
    else if(stack[top]=='{' && (input[i] == ']' || input[i] == ')')){
        printf("Not a valid equation\n");
        return 0;
    }
    else if(stack[top]=='[' && (input[i] == '}' || input[i] == ')')){
        printf("Not a valid equation\n");
        return 0;
    }
    else if(input[i]==')' || input[i] == '}' || input[i] == ']'){
        int temp = pop();
        if(temp==2){
            printf("Not a valid equation\n");
            return 0;
        }
    }
}
if(top==-1){
    printf("Valid Equation\n");
}
else{
    printf("Not a valid equation\n");
}
return 0;
}

void push(char value){
    if(top==(max-1)){
        return;
    }
    else{
        top++;
        stack[top] = value;
    }
}
int pop(){
    if(top == -1){
        return 2;
    }
    else{
        top--;
        return 1;
    }
}