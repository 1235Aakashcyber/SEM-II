#include<stdio.h>
#define max 20
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
        printf("\nNot a valid equation\n");
        return 0;
    }
    else if(stack[top]=='{' && (input[i] == ']' || input[i] == ')')){
        printf("\nNot a valid equation\n");
        return 0;
    }
    else if(stack[top]=='[' && (input[i] == '}' || input[i] == ')')){
        printf("\nNot a valid equation\n");
        return 0;
    }
    else if(input[i]==')' || input[i] == '}' || input[i] == ']'){
        int temp = pop();
        if(temp==2){
            printf("\nNot a valid equation\n");
            return 0;
        }
    }
}
if(top==-1){
    printf("\nValid Equation\n");
}
else{
    printf("\nNot a valid equation\n");
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