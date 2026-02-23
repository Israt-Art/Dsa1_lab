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

void printMiddle(struct Node* head){

    struct Node* slow=head;
    struct Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }



    printf("Middle node:%d",slow->data);

}

int main(){

struct Node* head=NULL;
struct Node* temp=NULL;

int n,value;

printf("enter number of nodes:");

scanf("%d",&n);

printf("Enter %d elements:",n);
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

printMiddle(head);

return 0;


}
