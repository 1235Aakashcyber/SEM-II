#include<stdio.h>
#include<stdlib.h>
struct node{
struct node *prev;
int data;
struct node *next;
};
void insert_at_beginning(struct node **head){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->next = new_node->prev = NULL;
    printf("Enter the value you want to insert : ");
    scanf("%d",&new_node->data);
    if(*head==NULL){
        *head = new_node;
    }
    else{
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
    }

}
int main()
{

}