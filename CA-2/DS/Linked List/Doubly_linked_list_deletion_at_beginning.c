#include<stdio.h>
#include<stdlib.h>
struct node{
struct node *prev;
int data;
struct node *next;
};
void deletion_at_beginning(struct node **head){
    struct node *temp;
    if(head==NULL){
        printf("Underflow!");
    }
    else{
        temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
}
int main()
{

}