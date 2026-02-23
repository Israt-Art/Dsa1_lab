#include<iostream>

using namespace std;

void replaceDivisibleBy3(int A[],int n){

for(int i=0;i<n;i++){
    if(A[i]%3==0){
        A[i]=-1;
    }
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

replaceDivisibleBy3(A,n);

cout<<"Array A:";
for(int i=0;i<n;i++){
    cout<< A[i]<<" ";
}

return 0;


}
