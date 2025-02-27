#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
void insert_after_node(struct node **head){
    int val;
    int data;
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *temp;
    printf("Enter the data you want to insert : ");
    scanf("%d",&data);
    new_node->data = data;
    printf("Enter the data after which you want to insert : ");
    scanf("%d",&val);
    if(*head==NULL){
        *head = new_node;
        new_node->next = NULL;
    }
    else{
        temp = *head;
        while(temp->data != val){
            temp = temp->next;
        }
        new_node->next=temp->next;
        temp->next = new_node;
    }
}
int main()
{

}