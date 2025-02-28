#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
void deletion_beginning(struct node **head){
    struct node *temp;
    if(*head == NULL){
        printf("Linked list is already empty!");
        return;
    }
    else{
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
int main()
{

}