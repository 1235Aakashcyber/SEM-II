#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}node;
void insert_at_beginning(struct node **head){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *temp;
    printf("Enter data you want to insert : ");
    scanf("%d",&new_node->data);
    if(*head==NULL){
        *head = new_node;
        new_node->next = new_node;
    }
    else{
        new_node->next = head;
        temp = *head;
        while(temp->next != *head){
            temp = temp->next;
        }
        temp->next = new_node;
        head = new_node;
        
    }
}
int main(){
//code
return 0;
}