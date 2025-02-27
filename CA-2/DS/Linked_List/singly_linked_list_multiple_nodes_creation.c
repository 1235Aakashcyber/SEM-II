#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main(){
    struct node *head = NULL;
    struct node *new_node;
    struct node *temp;
    int value;
    do{
        printf("Enter the value to be stored in the linked list: ");
        new_node = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &new_node -> data);
        new_node -> next = NULL;
        if (head == NULL) {
            head = new_node;
            temp = new_node;
        }
        else{
            temp -> next = new_node;
            temp = new_node;
        }
    printf("The value stored in the linked list is: %d\n", new_node -> data);
    printf("Do you want to continue : ");
    scanf("%d", &value);
    }while(value);

    //Display
    printf("The values stored in the linked list are: ");
    temp = head;
    while(temp != NULL){
        printf("%d\t", temp -> data);
        temp = temp -> next;
    }
}
