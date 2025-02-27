#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
void Deletion_at_end(struct node **head){
    struct node *temp;
    struct node *p;
    if(*head==NULL){
        printf("Linked list is already empty!");
        return;
    }
    else{
        temp = *head;
        p = NULL;
        while(temp->next != NULL){
            p = temp;
            temp = temp->next;
        }
        p->next = NULL;
        free(temp);
    }
}
int main()
{

}