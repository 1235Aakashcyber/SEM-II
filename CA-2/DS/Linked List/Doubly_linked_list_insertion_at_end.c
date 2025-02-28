#include<stdio.h>
#include<stdlib.h>
struct node{
struct node *prev;
int data;
struct node *next;
};
void insert_at_end(struct node **head){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->prev = new_node->next = NULL;
    struct node *temp;
    printf("Enter the data you want to insert : ");
    scanf("%d",&new_node->data);
    if(*head==NULL){
        *head = new_node;
    }
    else{
        temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}
int main()
{

}