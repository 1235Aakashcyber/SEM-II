#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
void deletion_at_beginnng(struct node **head){
    if(head==NULL){
        printf("Linked list is empty!\n");
    }
    else{
        struct node *temp;
        struct node *p;

        p = *head;
        while (p->next != *head)
        {
            p = p->next;
        }
        temp = *head;
        p->next = temp->next;
        *head = temp->next;
        free(temp);
        
    }

}
int main()
{

}