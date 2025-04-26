#include<stdio.h>
#include<conio.h>
#define max 4
int queue[max];
int front = -1;
int rear = -1;

void enqueue();
void dequeue();
void display();

void main(){
int choice;
clrscr();
while(1){
printf("\n---------------------------------------------------\n");
printf("What would you like to do ?\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
printf("\nEnter your choice : ");
scanf("%d",&choice);
switch (choice){
	case 1: enqueue(); break;
	case 2: dequeue(); break;
	case 3: display(); break;
	case 4: printf("Exiting..."); getch(); return;
       default: printf("Wrong input");
}
}
}

void enqueue(){
int value;
if(rear == max-1 && front == 0){
printf("Queue is full !\n");
return;
}
else if(front == -1 && rear == -1){
front = rear = 0;
}
else if(front != 0 && rear == max-1){
rear = 0;
}
else{
rear++;
}
printf("\nEnter the value to be inserted : ");
scanf("%d",&value);
queue[rear] = value;
printf("Insertion successful !\n");
}


void dequeue(){
if(front == -1 && rear == -1){
printf("Queue is empty !\n");
return;
}
else if(front == max -1){
front = 0;
}
else if(front == rear){
front = rear = -1;
}
else{
front++;
}
printf("Deletion successful !\n");
}

void display(){
int i;
if(front == -1 && rear == -1){
printf("Queue is empty !\n");
return;
}
else{
printf("Queue elements are : ");

if(front > rear){
for(i=front; i<=(max-1); i++){
printf("%d\t",queue[i]);
}
for(i=0; i<=rear; i++){
printf("%d\t",queue[i]);
}
}

else{
for(i=front; i<= rear; i++){
printf("%d\t",queue[i]);
}
}
}
}