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
if(rear == max-1){
printf("Queue is full !\n");
return;
}
else{
printf("\nEnter the value to be inserted : ");
scanf("%d",&value);
if(front == -1){
front = 0;
}
rear++;
queue[rear] = value;
printf("Insertion successful !\n");
}
}

void dequeue(){
if(front == -1 || front > rear){
printf("Queue is empty !\n");
return;
}
else{
printf("Deletion successful !\n%d is Dequeued\n",queue[front]);
front++;
}
}

void display(){
int i;
if(front == -1 || front > rear){
printf("Queue is empty !\n");
return;
}
else{
printf("Queue elements are :");
for(i=front; i<= rear; i++){
printf("%d\t",queue[i]);
}
}
}