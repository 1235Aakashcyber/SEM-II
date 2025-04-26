#include<stdio.h>
#include<conio.h>
#define max 4

int stack[max];
int top = -1;
void push();
void pop();
void print();
void peek();

int main(){
int choice;
clrscr();
while(1){
printf("\n\nEnter what would you like to do:\n");
printf("1. PUSH\n2. POP\n3. PRINT\n4. PEEK\n5. EXIT");
scanf("%d",&choice);
switch(choice){
case 1:
push();
break;
case 2:
pop();
break;
case 3:
print();
break;
case 4:
peek();
break;
case 5:
return 0;
default:
printf("Wrong Input\n");
}
}
}

void push(){
int value;
if(top == max-1){
printf("Stack is full !");
getch();
}
else{
printf("Enter the value to push : ");
scanf("%d",&value);
top++;
stack[top] = value;
}
}
void pop(){
if(top == -1){
printf("Stack is empty !");
return;
}
else{
printf("%d is poped out",stack[top]);
top--;
}
}
void print(){
int temp = 0;
if(top == -1){
printf("Stack is empty");
}
else{
while(temp != top+1){
printf("%d\t",stack[temp]);
temp++;
}
}
}
void peek(){
if(top == -1){
printf("Stack is empty !\n");
}
else{
printf("\n%d\n",stack[top]);
return;
}
}