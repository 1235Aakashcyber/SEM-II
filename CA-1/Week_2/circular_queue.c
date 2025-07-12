#include<stdio.h>
# define size 3
int front = -1;
int rear = -1;
int queue[size];
void enqueue(int *queue, int value);
int dequeue(int *queue);
void display(int *queue);
int main(){
    int operation;
    int value;
    char exit;
A:
    printf("Enter 1 to enqueue and 2 to dequeue : ");
    scanf("%d",&operation);
    switch(operation){
        case 1:
        printf("Enter the value to enqueue : ");
        scanf("%d",&value);
        enqueue(queue,value);     
        break;

        case 2:
        printf("%d is dequeued\n",dequeue(queue));
        break;

        default:
        printf("Wrong input\n");
    }
    printf("To continue press 'c' else press 'e' : ");
    scanf(" %c",&exit);
    if(exit=='c' || exit == 'C'){
        goto A;
    }
    else if(exit=='p'){
        display(queue);
    }
return 0;
}
void enqueue(int *queue, int value){
    if((rear == (front-1)) || (rear == size-1 && front == 0)){
        printf("The queue is full\n");
    }
    else if(front==-1 && rear == -1){
        front=rear=0;
        queue[rear] = value;
    }
    else if(front!=0 && rear==size-1){
        rear = 0;
        queue[rear] = value;
    }
    else {
        rear++;
        queue[rear] = value;
    }
}
int dequeue(int *queue){
    int deleted_value;
    if(front==rear==-1){
        printf("Queue is empty");
    }
    else if(front == rear){
        deleted_value = queue[front];
        front = rear = -1;
    }
    else if(front == size-1){
        deleted_value = queue[front]; 
        front=0;
    }
    else{
        deleted_value = queue[front];
        front++;
    }
    return deleted_value;
}
void display(int *queue){
    if(front==-1 && rear == -1){
        printf("Queue is empty\n");
    }
    else if(front>rear){
        for(int i=front; i<=size-1; i++){
            printf("%d\t",queue[i]);
        }
        for(int i=0; i<=rear; i++){
            printf("%d\t",queue[i]);
        }
    }
    else{
        for(int i=front; i<=rear; i++){
            printf("%d\t",queue[i]);
        }
    }
}