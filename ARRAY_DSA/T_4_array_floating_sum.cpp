#include<iostream>

using namespace std;

double calculateAverage(double arr[],int n){

    double sum=0.0;

    for(int i=0;i<n;i++){
        sum+=arr[i];
    }

return sum/n;

}

int main(){

    int n;

    cout<<"Enter number of elements:";
    cin>>n;

    double arr[n];

    cout<<"enter"<<n<< " floating point number:";

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"average:" << calculateAverage(arr,n)<<endl;

    return 0;







}
