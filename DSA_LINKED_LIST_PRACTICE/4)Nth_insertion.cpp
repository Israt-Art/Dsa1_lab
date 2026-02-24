/*Given a sorted linked list, insert a number so that after insertion, it remains
sorted.
Input Output
1->4->6->7->9->11, num = 3 1->3->4->6->7->9->11*/


#include<stdio.h>
#include<stdlib.h>

struct Node{

int data;
struct Node* next;
};

struct Node* createNode(int data){

struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));

newNode->data=data;

newNode->next=NULL;

return newNode;

};

struct Node* insertSorted(struct Node* head, int num){

struct Node* newNode=createNode(num);

if(head==NULL||num< head->data){
    newNode->next=head;

    head=newNode;

    return head;
}

struct Node* temp=head;

while(temp->next!=NULL && temp->next->data<num){
    temp=temp->next;
}

newNode->next=temp->next;
temp->next=newNode;

return head;

};

void display(struct Node* head){

struct Node* temp=head;

while(temp!=NULL){
    printf("%d",temp->data);

    if(temp->next!=NULL)
        printf("->");
    temp=temp->next;
}
printf("\n");

}


int main(){


struct Node* head=NULL;
struct Node* temp=NULL;

int n,value,num;

printf("enter the number of nodes:");
scanf("%d",&n);

printf("enter %d sorted elements:",n);
for(int i=0;i<n;i++){
    scanf("%d",&value);

    struct Node* newNode=createNode(value);

    if(head==NULL){
        head=newNode;
        temp=head;
    }

    else{
        temp->next=newNode;
        temp=temp->next;
    }
}

printf("ENTER NUMBER TO INSERT:");
scanf("%d",&num);

head=insertSorted(head,num);

printf("after insertion:");

display(head);

return 0;

}
