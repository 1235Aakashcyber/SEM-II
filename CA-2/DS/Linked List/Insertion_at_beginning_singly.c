#include<stdio.h>
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
    }
    else{
    new_node->next = *head;
    *head = new_node;
    }
}