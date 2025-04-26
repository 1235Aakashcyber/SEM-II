#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};

void insert_specific(int value, struct node **head);
void delete_specific(struct node **head);
void display(struct node **head);

int main(){
struct node *head = NULL;
int choice;
int value;
clrscr();
while(1){
printf("\n-------------------------------------------\n");
printf("What would you like to do ?\n");
printf("1. Insert after specific node\n2. Delete a specific node\n3. Display\n4. Exit\n");
scanf("%d",&choice);
switch(choice){
	case 1:
	printf("Enter the value to insert : ");
	scanf("%d",&value);
	insert_specific(value,&head);
	break;

	case 2:
	delete_specific(&head);
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

void insert_specific(int value, struct node **head){
struct node *new_node = (struct node*)malloc(sizeof(struct node));
new_node -> data = value;
struct node *temp = *head;
int val;
if(*head == NULL){
*head = new_node;
new_node -> next = NULL;
}
else{
printf("Enter after which value you want to insert the new node : ");
scanf("%d",&val);
while(temp -> data != val){
temp = temp -> next;
}
new_node -> next = temp -> next;
temp -> next = new_node;
}
printf("Insertion Successful !\n");
}

void delete_specific(struct node **head){
struct node *temp = *head;
struct node *p;
int val;
printf("Which value do you want to delete : ");
scanf("%d",&val);
if(*head == NULL){
printf("Linked list is empty !\n");
return;
}
else{
while(temp -> data != val){
p = temp;
temp = temp -> next;
}
if(temp == *head){
*head = temp -> next;
}
else{
p -> next = temp -> next;
}

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