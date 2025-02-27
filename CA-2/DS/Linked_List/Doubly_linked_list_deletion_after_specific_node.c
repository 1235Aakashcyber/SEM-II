#include<stdio.h>
#include<stdlib.h>
struct node{
struct node *prev;
int data;
struct node *next;
};
void deletion_after_specific_node(struct node **head){
    int value;
    struct node *temp;
    struct node *p;
    printf("Enter the data after which you want to delete : ");
    scanf("%d",&value);
    if(head==NULL){
        printf("Underflow!");
    }
    else{
        while(temp->data != value){
            temp = temp->next;
        }
        p = temp->next;
        p->next->prev = temp;
        temp->next = p->next;
        free(p);
    }
}
int main()
{

}