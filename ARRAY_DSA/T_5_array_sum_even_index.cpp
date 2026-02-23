#include<iostream>

using namespace std;

int SumEvenIndexNumber(int arr[],int n){

int sum=0;

for(int i=0;i<n;i+=2){
    sum+=arr[i];
}

return sum;

}
int main(){
    int n;

    cout<<"enter the number of elements:";

    cin>>n;

    int arr[n];

    cout<<"enter"<<n << "integers:";

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Sum of even index:"<<SumEvenIndexNumber(arr,n)<<endl;

    return 0;




}
