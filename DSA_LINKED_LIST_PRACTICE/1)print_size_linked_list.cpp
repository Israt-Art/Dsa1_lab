/*Print the size of a linked list.
Input Output
34->12->55->42->11 5*/

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

int getSize(struct Node* head){

int count=0;
struct Node* temp=head;

while(temp!=NULL){
    count++;
    temp=temp->next;
}

return count;

}

int main(){

struct Node* head=NULL;
struct Node* temp=NULL;



int n,value;

printf("enter number of nodes:");
scanf("%d",&n);

printf("Enter %d element:",n);
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

printf("Size of linked list:%d\n",getSize(head));


return 0;

}
