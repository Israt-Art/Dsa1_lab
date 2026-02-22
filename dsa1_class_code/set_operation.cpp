#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
typedef struct Node node;

void menu();
node* createNode();
void printList(node* head);
node* insert_head(node* head, node* nn);
node* insert_tail(node* head, node* nn);
node* setUnion(node* set1, node* set2);
int contains(node* temp, int value);
node* setIntersection(node* temp1,node* temp2);
int checkDisjoints(node* temp1,node* temp2);

int main()
{
    node* set1=NULL, *set2=NULL, *result=NULL, *nn;
    int choice;
    menu();
    scanf("%d",&choice);

    while(choice!=0)
    {
        if(choice==1)
        {
            printf("Insert in SET A:\n");
            nn = createNode();
            set1 = insert_tail(set1, nn);
            printf("Node inserted in A\n\n");
        }
        else if(choice==2)
        {
            printf("Insert in SET B:\n");
            nn = createNode();
            set2 = insert_tail(set2, nn);
            printf("Node inserted in B\n\n");
        }
        else if(choice==3)
        {
            printf("SET A:\n");
            printList(set1);
        }
        else if(choice==4)
        {
            printf("SET B:\n");
            printList(set2);
        }else if(choice==5){
            printf("A UNION B:\n");
            result = setUnion(set1,set2);
            printList(result);
        }else if(choice==6){
            printf("A INTERSECTION B:\n");
            result = setIntersection(set1,set2);
            printList(result);
        }else if(choice==7){
            if(checkDisjoints(set1,set2)){
                printf("\n\nA,B ARE DISJOINTS!\n\n");
            }else{
                printf("\n\nA,B AREN'T DISJOINTS!\n\n");
            }
        }
        else
        {
            printf("Invalid Choice!\n");
        }
        menu();
        scanf("%d",&choice);
    }

    printf("\nYour pressed the Exit button!\nbye...\n");
}

int checkDisjoints(node* temp1,node* temp2){
    while(temp1!=NULL){
        if(contains(temp2,temp1->data)){
            return 0;
        }
        temp1 = temp1->next;
    }
    return 1;
}

node* setIntersection(node* temp1,node* temp2){
    node* result= NULL;

    while(temp1!=NULL){
        if(contains(temp2,temp1->data)){
            node* nn= new node();
            nn->data = temp1->data;
            nn->next = NULL;
            result = insert_tail(result,nn);
        }
        temp1 = temp1->next;
    }
    return result;
}

node* setUnion(node* set1, node* set2){
    node* result = NULL, *temp;
    temp = set1;
    while(temp!=NULL){
        node* nn = new node();
        nn->data = temp->data;
        nn->next = NULL;
        result = insert_tail(result,nn);

        temp = temp->next;
    }

    temp = set2;
    while(temp!=NULL){
        if(!contains(result, temp->data)){
            node* nn = new node();
            nn->data = temp->data;
            nn->next = NULL;
            result = insert_tail(result,nn);
        }
        temp = temp->next;
    }
    return result;
}

int contains(node* temp, int value){
    while(temp!=NULL){
        if(temp->data == value){
            return 1;
        }

        temp=temp->next;
    }
    return 0;
}

node* createNode()
{
    node* nn=new node();
    printf("Enter data:");
    scanf("%d",&nn->data);
    nn->next = NULL;
    return nn;
}

void printList(node* head)
{
    node* temp = head;
    printf("Data in SET:\n\n");
    if(temp==NULL)
    {
        printf("No Data Found!\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
    printf("\n\n");
}

node* insert_head(node* head, node* nn)
{
    node* temp = head;
    if(head!=NULL)
    {
        nn->next=head;
    }
    head=nn;
    return head;
}

node* insert_tail(node* head, node* nn)
{
    node* temp = head;
    if(temp==NULL)
    {
        head = insert_head(head,nn);
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
    return head;
}

int ListSize(node* head)
{
    node* temp= head;
    int counter=0;
    while(temp != NULL)
    {
        counter++;
        temp=temp->next;
    }
    return counter;
}

void menu()
{
    printf("1) Insert in SET A\n");
    printf("2) Insert in SET B\n");
    printf("3) Display SET A\n");
    printf("4) Display SET B\n");
    printf("5) Find A UNION B\n");
    printf("6) Find A INTERSECTION B\n");
    printf("7) Find DISJOINTS OF A,B\n");

    printf("0) Exit\n");
    printf("Enter your choice:");
}
