#include<iostream>

using namespace std;

void reverseCopy(int A[],int B[],int n){

for(int i=0;i<n;i++){
    B[i]=A[n-i-1];
}
}

void printArray(string label, int arr[],int n){ 
    cout<<label<< " :";
    for(int i=0;i<n;i++){
        cout <<arr[i]<< " ";
cout<<endl;
    }
}

int main(){

int n;
cout<<"how namy numbers:";
cin>>n;

int A[n],B[n];

cout<<"input element for array A:";
for(int i=0;i<n;i++){
    cin>>A[i];
}

reverseCopy(A,B,n);

printArray("Array A",A,n);
printArray("Array B",B,n);

return 0;






}
