#include<stdio.h>

void printData(int data[],int n);
void SelectionSort(int data[],int n);
void BubbleSort(int data[],int n);
void InsertionSort(int data[], int n);
int BinarySearch(int data[], int n, int key);

int main(){
    int n;
    printf("n?");
    scanf("%d",&n);

    int data[n];
    for(int i=0;i<n;i++){
        printf("data[%d]:",i);
        scanf("%d",&data[i]);
    }
    printf("\ndata before sorting:\n");
    printData(data,n);

    printf("\n1) Selection Sort\n2) Bubble Sort\n3) Insertion Sort\n4)Binary Search\n");
    int choice;
    printf("\nchoice?");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            SelectionSort(data,n);
            break;
        case 2:
            BubbleSort(data,n);
            break;
        case 3:
            InsertionSort(data,n);
            break;
        case 4:
            int key;
            printf("key?");
            scanf("%d",&key);
            int res = BinarySearch(data,n,key);
            if(res!=0){
                printf("Found at index %d\n",res);
            }else{
                printf("Not Found!\n");
            }
            break;
    }


    printf("\ndata after sorting:\n");
    printData(data,n);

}

void printData(int data[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",data[i]);
    }
}

void SelectionSort(int data[],int n){
    int i,j,temp, minIndx;
    for(i=0;i<n-1;i++){
        minIndx = i;
        for(j=i+1;j<n;j++){
            if(data[minIndx]>data[j]){
                minIndx = j;
            }
        }
        temp = data[i];
        data[i] = data[minIndx];
        data[minIndx] = temp;
    }
}

void BubbleSort(int data[],int n){
    int i,j,temp;

    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(data[j] > data[j+1]){
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}

void InsertionSort(int data[], int n){
    int key,i,j;
    for(i=1;i<n;i++){
        key = data[i];
        j = i-1;
        while(j>=0 && data[j]>key){
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = key;
    }
}

int BinarySearch(int data[], int n, int key){
    BubbleSort(data,n);
    int low=0, high = n-1, mid;

    while(low<high){
        mid = (low+high)/2;
        if(data[mid]==key){
            return mid;
        }else if(data[mid]>key){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return 0;
}

