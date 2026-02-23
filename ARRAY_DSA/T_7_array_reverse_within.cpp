#include<iostream>

using namespace std;

void reverseArray(int arr[],int n){

int start=0,end=n-1;
while(start<end){ 
    swap(arr[start],arr[end]);
    start++;
    end--;

    }
}

void PrintArray(int arr[],int n){

for(int i=0;i<n;i++){
    cout<<arr[i]<< " ";
}
cout<<endl;
}

int main(){

int n;
cin>>n;

int arr[n];

for(int i=0;i<n;i++){
    cin>>arr[i];
}
reverseArray(arr,n);
PrintArray(arr,n);

return 0;

}
