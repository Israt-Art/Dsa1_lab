#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
typedef struct Node node;

void menu();
node* insert_head(node* head, node* nn);
void printList(node* head);
node* createNode();

int main()
{
    node* head = NULL, *nn;
    int choice;
    menu();
    scanf("%d",&choice);

    while(choice!=0)
    {
        if(choice==1)
        {
            printList(head);
        }
        else if(choice==2)
        {
            nn= createNode();
            head = insert_head(head,nn);
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
    printf("Data in Linked List:\n\n");
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
    printf("Node inserted in Head!\n\n");
    return head;
}



void menu()
{
    printf("1) Print List\n");
    printf("2) Insert Data at Head\n");
    printf("0) Exit\n");
    printf("Enter your choice:");
}
