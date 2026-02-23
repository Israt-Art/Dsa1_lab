#include<iostream>

using namespace std;

void findMaxMin(int arr[],int n){

int maxVal=arr[0];
int minVal=arr[0];

 int maxIndex=0;
  int minIndex=0;

for(int i=0;i<n;i++){
    if(arr[i]>maxVal){
        maxVal=arr[i];
        maxIndex=i;
    }

    if(arr[i]<minVal){
        minVal=arr[i];
        minIndex=i;
    }
}

cout<<"Max:"<<maxVal<< " , maxIndex:"<<maxIndex<<endl;
cout<<"Min:"<<minVal<< " ,minIndex:"<<minIndex<<endl;

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
findMaxMin(arr,n);

return 0;
}
