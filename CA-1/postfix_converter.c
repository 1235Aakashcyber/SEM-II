#include<stdio.h>
#include<ctype.h>
#define max 20
int top=-1;
char stack[max];
void push(char value);
int pop();
int priority(char input);
int main(){
char input[50];
char out;
printf("Enter the equation : ");
fgets(input,50,stdin);
for(int i=0; input[i]!='\0'; i++){
    if(isalnum(input[i])){
        printf("%c",input[i]);
    }
    else if(input[i]=='('){
        push(input[i]);
    }
    else if(input[i]==')'){
        while((out = pop()) != '('){
            printf("%c",out);
        }
    }
    // else if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i]=='%'){
    //     push(input[i]);
    // }
    else if(priority(stack[top])>=priority(input[i]) || top==-1){
            printf("%c",pop());
            push(input[i]);
        
    }
}
while (top!=-1)
{
    printf("%c",pop());
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
char ret;
if(top == -1){
return 0;
}
else{
ret = stack[top];
top--;
return ret;
}
}

int priority(char input){
    // if(input=='('){
    //     return 0;
    // }
    if(input=='+' || input=='-'){
        return 1;
    }
    else if(input == '*' || input == '/' || input=='%'){
        return 2;
    }
}