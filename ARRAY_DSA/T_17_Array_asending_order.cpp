#include<iostream>

using namespace std;

void bubbleSort(int A[],int n){

for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
        if(A[j]>A[j+1]){
            swap(A[j],A[j+1]);
        }
    }
}

}

int main(){

int n, A[100];

cout<<"enter the number of elements:";
cin>>n;

cout<<"enter input:";
for(int i=0;i<n;i++){
    cin>>A[i];
}

bubbleSort(A,n);
cout<<"Array A:";
for(int i=0;i<n;i++){
    cout<<A[i]<< " ";
}
return 0;
}
