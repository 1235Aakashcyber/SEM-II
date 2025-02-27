#include<stdio.h>
#include<stdlib.h>
struct node{
struct node *prev;
int data;
struct node *next;
};
void insertion_after_specific_node(struct node **head){
    int data;
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->prev = new_node->next = NULL;
    printf("Enter the data you want to insert : ");
    scanf("%d",&new_node->data);
    struct node *temp;
    printf("Enter the data before which you want to insert node : ");
    scanf("%d",&data);
    if(*head==NULL){
        *head = new_node;
    }
    else{
        temp = *head;
        while(temp->data != data){
            temp = temp->next;
        }
        new_node->next = temp;
        new_node->prev = temp->prev;
        temp->prev->next = new_node;
        temp->prev = new_node;
    }
}
int main()
{

}