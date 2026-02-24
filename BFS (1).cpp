#include<stdio.h>
int data[100],frnt=0,rear=0,qsize,vcount=0;
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
void enqueue_data(int value);
int front_element();
int check_existence(int visited[],int now,int n);
void dequeue_data();


int main(){
    node* nn, *head=NULL;
    node *temp;
    int n;
    printf("n?");
    scanf("%d",&n);

    int graph[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph[i][j]=0;
        }
    }

    printf("Enter values:\n");
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            printf("%c-%c:",i+65,j+'A');
            scanf("%d",&graph[i][j]);
            graph[j][i] = graph[i][j];
        }
    }

    printf("Adjacency Matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("  %d",graph[i][j]);
        }
        printf("\n");
    }

    printf("Adjacency List:\n");

    node* head_arr[n];
    for(int i=0;i<n;i++){
        nn = createNode(i);
        //head = insert_head(head_arr[i],nn);
        head_arr[i]=nn;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]==1){
                nn = createNode(j); //col
                head_arr[i] = insert_tail(head_arr[i],nn);
            }
        }
    }

    for(int i=0;i<n;i++){
        printList(head_arr[i]);
        printf("\n");
    }

    int visited[n];
    qsize = 30;
    printf("Enter Start Node (Uppercase):");
    char ch;
    fflush(stdin); //getchar();
    scanf("%c",&ch); //A,B,C,D
    int start = ch-65;
    visited[0]=start;

    temp = head_arr[start]->next;
    while(temp!=NULL){
        enqueue_data(temp->data);
        temp=temp->next;
    }
    int i=1;
    while(vcount!=0){
        int now = front_element();
        int check = check_existence(visited,now,i);

        if(check==0){
            visited[i]=now;
            i++;
            dequeue_data();

            temp = head_arr[now]->next;
            while(temp!=NULL){
                enqueue_data(temp->data);
                temp = temp->next;
            }
        }else{
            dequeue_data();
        }
    }

    printf("BFS:\n");
    for(int i=0;i<n;i++){
        printf("%c ",visited[i]+65);
    }


return 0;
}

void dequeue_data(){
    if(vcount==0){
        printf("\nEMPTY!\n");
    }else{
        frnt = (frnt+1)%qsize;
        vcount--;
    }
}
int check_existence(int visited[],int now,int n){
    for(int i=0;i<n;i++){
        if(visited[i]==now){
            return 1; //visited
        }
    }
    return 0; //not visited
}

int front_element(){
    return data[frnt];
}

void enqueue_data(int value){
    if(vcount==qsize){
        printf("\nFULL!\n");
    }else{
        data[rear]=value;
        rear = (rear+1)%qsize;
        vcount++;
    }

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
