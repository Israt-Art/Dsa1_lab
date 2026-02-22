#include<stdio.h>
struct Node
{
    int data;
    struct Node* next;
};
typedef struct Node node;

node* createNode(int x);
void printList(node* head);
node* insert_head(node* head, node* nn);
node* insert_tail(node* head, node* nn);
int ListSize(node* head);


int main(){
    int n;
    printf("n?");
    scanf("%d",&n);

    int graph[n][n];

    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            graph[row][col] = 0;
        }
    }
    printf("Enter index values:\n");
    for(int row=0;row<n;row++){
        for(int col=row+1;col<n;col++){
            printf("%c-%c: ",row+'A',col+65);
            scanf("%d",&graph[row][col]);
            graph[col][row] = graph[row][col];
        }
    }

    printf("Adjacency Matrix:\n");
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            printf("%d  ",graph[row][col]);
        }
        printf("\n");
    }

    node *nn,*head=NULL;
    node* head_array[n];

    for(int i=0;i<n;i++){
       nn = createNode(i);
       //head_array[i] = insert_tail(head_array[i],nn);
        head_array[i]=nn;
    }

    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(graph[row][col]==1){
                nn = createNode(col);
                head_array[row] = insert_tail(head_array[row],nn);
            }
        }
    }
    for(int i=0;i<n;i++){
        printList(head_array[i]);
        printf("\n");
    }

return 0;
}

node* createNode(int x)
{
    node* nn=new node();
    nn->data = x;
    nn->next = NULL;
    return nn;
}

void printList(node* head)
{
    node* temp = head;
    //printf("Data in Linked List:\n\n");
    if(temp==NULL)
    {
        printf("No Data Found!\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%c ",temp->data+'A');
            temp=temp->next;
        }
    }
    //printf("\n\n");
}

node* insert_head(node* head, node* nn)
{
    node* temp = head;
    if(head!=NULL)
    {
        nn->next=head;
    }
    head=nn;
    //printf("Node inserted in Head!\n\n");
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
    //printf("Node inserted in Tail!\n\n");
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

