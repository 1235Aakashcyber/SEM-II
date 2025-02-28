#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}node;
int main(){
struct node *head;
struct node *new_node;
new_node = (struct node*)malloc(sizeof(struct node));
head = new_node;
printf("Enter the value to be stored in the linked list: ");
scanf("%d", &new_node -> data);
printf("The value stored in the linked list is: %d\n", new_node -> data);
return 0;
}