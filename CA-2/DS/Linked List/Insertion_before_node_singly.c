#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
void insert_before_node(struct node **head){
    int val;
    int data;
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *temp;
    struct node *p;
    printf("Enter the data you want to insert : ");
    scanf("%d",&data);
    new_node->data = data;
    printf("Enter the data before which you want to insert : ");
    scanf("%d",&val);
    if(*head==NULL){
        *head = new_node;
        new_node->next = NULL;
    }
    else{
        temp = *head;
        p = NULL;
        while(temp->data != val){
            p = temp;
            temp = temp->next;
        }
        new_node->next = temp;
        p->next = new_node;
    }
}
int main()
{

}