#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 10

int hash[size];

void initialize_table();
int hash_fun(int key);
void insert(int key);
int search(int key);
void display();

void main(){
int choice;
int key;
int result;
clrscr();
initialize_table();
while(1){
printf("\n---------------------------------\n");
printf("Enter what you want to do\n");
printf("1. Insert\n2. Search\n3. Display\n4. Exit\n");
scanf("%d",&choice);

switch(choice){
	case 1:
	printf("Enter the key you want to insert : ");
	scanf("%d",&key);
	insert(key);
	break;

	case 2:
	printf("Enter the key you want to search : ");
	scanf("%d",&key);
	result = search(key);
	if(result == -1){
	printf("Key not found !\n");
	}
	else{
	printf("Key %d found at index %d\n",key,result);
	}
	break;

	case 3:
	display();
	break;

	case 4:
	printf("Exiting...");
	getch();
	return;

	default:
	printf("Wrong Input !\n");
}
}
}

void initialize_table(){
int i;
for(i=0; i<size; i++){
hash[i] = -1;
}
}

int hash_fun(int key){
return key%size;
}

void insert(int key){
int index = hash_fun(key);
int org_idx = index; //original index

while(hash[index] != -1){
index = (index + 1) % size;
if(index == org_idx){
printf("Hash table is full\n");
return;
}
}
hash[index] = key;
printf("Inserted %d at index %d\n",key,index);
}

int search(int key){
int index = hash_fun(key);
int org_idx = index;

while(hash[index] != -1){
if(hash[index] == key){
return index;
}
index = (index + 1) % size;
if(index == org_idx){
break;
}
}
return -1;
}

void display(){
int i;
for(i=0; i<size; i++){
printf("\nINDEX %d = %d\n",i,hash[i]);
}
return;
}