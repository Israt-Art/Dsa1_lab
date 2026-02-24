#include<stdio.h>
void menu();

int main(){
    int data[100],front=0,rear=0,choice,qsize,vcount=0;

    printf("size?");
    scanf("%d",&qsize);
    menu();
    scanf("%d",&choice);

    while(choice!=0){
        if(choice==1){
            if(qsize==vcount){
                printf("\nFULL QUEUE!\n");
            }else{
                printf("data?");
                scanf("%d",&data[rear]);
                //rear++;
                rear = (rear+1)%qsize;
                vcount++;
            }
        }else if(choice==2){
            if(vcount==0){
                printf("\nEmpty Queue!\n");
            }else{
                printf("%d dequeued!",data[front]);
                //front++;
                front = (front+1)%qsize;
                vcount--;
            }
        }else if(choice==3){
            if(vcount==0){
                printf("\nNo data found!\n");
            }else{
                printf("front element: %d",data[front]);
            }

        }else if(choice==4){
            printf("Current Size: %d",vcount);

        }else{
            printf("\nINVALID CHOICE!\n");
        }

        menu();
        scanf("%d",&choice);
    }
    return 0;
}

void menu(){
    printf("\n1)Enqueue\n");
    printf("2)Dequeue\n");
    printf("3)Front Element\n");
    printf("4)Current Queue Size!\n");
    printf("0)Exit!\n");
    printf("Enter your choice:");
}

