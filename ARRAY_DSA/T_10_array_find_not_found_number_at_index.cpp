#include<iostream>

using namespace std;

void searchNumber(int arr[],int n,int target){

bool found=false;

cout<<"found at index position:";
for(int i=0;i<n;i++){
    if(arr[i]==target){
        cout<< i << " ";
        found =true;
    }
}

if(!found){
    cout<<"Not found";
}

cout<<endl;
}
int main(){

int n;
cout<<"Enter the number of elements:";
cin>>n;

cout<<" input:";

int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}


int target;
cout<< "wanna search:";
cin>>target;

searchNumber(arr,n,target);

return 0;
}
