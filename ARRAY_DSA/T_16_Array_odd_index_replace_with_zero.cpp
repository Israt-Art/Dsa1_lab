#include<iostream>

using namespace std;

void replaceOddIndex(int A[],int n){
for(int i=1;i<n;i+=2){
    A[i]=0;
}
}

int main(){

int n,A[100];

cout<<"enter the number of elements in A:";
cin>>n;

cout<<"enter input for A:";
for(int i=0;i<n;i++){
    cin>>A[i];
}

replaceOddIndex(A,n);

cout<<"Array A:";
for(int i=0;i<n;i++){
    cout<<A[i]<<" ";
}
return 0;
}
