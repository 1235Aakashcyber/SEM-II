#include<stdio.h>
#include<stdlib.h>
struct node{
struct node *prev;
int data;
struct node *next;
};
void deletion_at_end(struct node **head){
    struct node *temp;
    if(head==NULL){
        printf("Underflow!");
    }
    else{
        temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
}
int main()
{

}