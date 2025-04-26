#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void insert_beginning(int value, struct node **head){
    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    if(*head==NULL){
	*head=new_node;
	new_node->next=NULL;
	printf("Insertion successful !\n");
    }
    else{
	new_node->next = *head;
	*head = new_node;
	printf("Insertion successful !\n");
    }
}
void Deletion_at_end(struct node **head){
    struct node *temp;
    struct node *p;
    if(*head==NULL){
	printf("Linked list is already empty!\n");
	return;
    }
    else{
	temp = *head;
	p = NULL;
	while(temp->next != NULL){
	    p = temp;
	    temp = temp->next;
	}
	p->next = NULL;
	free(temp);
	printf("Deletion successful !\n");
    }
}
void display(struct node **head){
    struct node *temp;
    if(*head==NULL){
	printf("Linked list is empty !\n");
	return;
    }
    else{
	temp = *head;
	while(temp != NULL){
	    printf("%d -> ",temp->data);
	    temp = temp->next;
	}
	printf("NULL\n");
    }
}
int main(){
    struct node *head=NULL;
    int value;
    int choice;
    clrscr();
    while(1){
    printf("--------------------------------------------------\n");
    printf("What you want to do ?\n1. Insert at beginning\n2. Delete node at end\n3. Display\n4. Exit\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
	printf("Enter the data to insert :");
	scanf("%d",&value);
	insert_beginning(value,&head);
	break;
    case 2:
	Deletion_at_end(&head);
	break;
    case 3:
	display(&head);
	break;
    case 4:
	printf("Exiting...\n");
	getch();
	return 0;
    default:
	break;
    }
}
}

