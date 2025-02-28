#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
void deletion_at_end(struct node **head){
    if(head==NULL){
        printf("Linked list is empty!\n");
    }
    else{
        struct node *temp;
        struct node *p;

        temp = *head;
        p = NULL;
        while (temp->next != *head)
        {
            p = temp;
            temp = temp->next;
        }
        p->next = *head;
        free(temp);
        
    }

}
int main()
{

}