#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};

void insert_end(int value, struct node **head);
void delete_beginning(struct node **head);
void display(struct node **head);

int main(){
struct node *head = NULL;
int choice;
int value;
clrscr();
while(1){
printf("\n-------------------------------------------\n");
printf("What would you like to do ?\n");
printf("1. Insert at end\n2. Delete from beginning\n3. Display\n4. Exit\n");
scanf("%d",&choice);
switch(choice){
	case 1:
	printf("Enter the value to insert : ");
	scanf("%d",&value);
	insert_end(value,&head);
	break;

	case 2:
	delete_beginning(&head);
	break;

	case 3:
	display(&head);
	break;

	case 4:
	printf("Exiting...");
	getch();
	return 0;

	default:
	printf("Wrong Input !");
}
}
}

void insert_end(int value, struct node **head){
struct node *new_node = (struct node*)malloc(sizeof(struct node));
struct node *temp = *head;
new_node -> data = value;
new_node -> next = NULL;
if(*head == NULL){
*head = new_node;
}
else{
while(temp -> next != NULL){
temp = temp -> next;
}
temp -> next = new_node;
}
printf("Insertion Successful !\n");
}

void delete_beginning(struct node **head){
struct node *temp;
if(*head == NULL){
printf("Linked list is empty !\n");
return;
}
else{
temp = *head;
*head = temp -> next;
temp -> next = NULL;
free(temp);
printf("Deletion Successful !\n");
}
}

void display(struct node **head){
struct node *temp=*head;
if(*head == NULL){
printf("Linked list is empty !\n");
return;
}
else{
printf("Linked list contains : ");
while(temp -> next != NULL){
printf("%d -> ",temp -> data);
temp = temp -> next;
}
printf("%d -> ",temp -> data);
printf("NULL\n");
}
}
