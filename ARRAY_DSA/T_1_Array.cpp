#include<iostream>

using namespace std;

void PrintReverse(int arr[], int n){

cout <<"After reversing:";

for(int i=n-1;i>=0;i--){
    cout<< arr[i]<< " ";
}

cout<<endl;
}
int main(){

int n;

cout<<"enter number of elements:";

cin>>n;

int arr[n];

cout<<"enter" <<n<<" integers: ";

for(int i=0;i<n;i++){
    cin>>arr[i];
}

PrintReverse(arr,n);

return 0;


}
