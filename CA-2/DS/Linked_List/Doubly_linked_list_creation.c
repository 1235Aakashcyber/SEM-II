#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
int main()
{
struct node *head;
struct node *new_node = (struct node*)malloc(sizeof(struct node));
new_node->next = NULL;
new_node->prev = NULL;
new_node->data = 10;
head = new_node;
}