#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
void insert_at_end(int value, struct node **head, struct node *temp){
    struct node *new_node;
    new_node =  (struct node*)malloc(sizeof(struct node));
        new_node->data=value;
        new_node->next = NULL;
    if(*head == NULL){
        *head = new_node;
    }
    else{
        temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}
}
int main()
{

}