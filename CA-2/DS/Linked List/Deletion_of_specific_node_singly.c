#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
void Deletion_of_specific_node(struct node **head){
    int data;
    struct node *temp;
    struct node *p;
    if(*head==NULL){
        printf("Linked list is already empty!");
        return;
    }
    else{
        printf("Enter the data you want to delete : ");
        scanf("%d",&data);
        temp = *head;
        p = NULL;
        while(temp->data != data){
            p = temp;
            temp = temp->next;
        }
        p->next = temp->next;
        free(temp);

    }
}
int main()
{

}