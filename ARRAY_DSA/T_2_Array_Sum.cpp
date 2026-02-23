#include<iostream>

using namespace std;

int sumArray(int arr[],int n){

    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
return sum;
}

int main(){

    int n;

    cout<< " enter number of elements:";

    cin>>n;

    int arr[n];

    cout<<"enter"<< n<< "integers:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Sum:" << sumArray(arr,n)<<endl;

return 0;



}
