#include<iostream>

using namespace std;

void deleteElement(int arr[],int n,int pos){

if(pos<0 || pos>=n){
    cout <<"invalid position"<<endl;
    return;
}

for(int i=pos;i<n-1;i++){
    arr[i]=arr[i+1];
}
n--;
}

int main(){

int n;
cout<<"enter the number of elements:";
cin>>n;

int arr[n];
cout<<"input:";
for(int i=0;i<n;i++){
    cin>>arr[i];
}

int pos;
cout<<"enter position to delete:";
cin>>pos;

deleteElement(arr,n,pos);

cout<< " updated array:";
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
return 0;




}
