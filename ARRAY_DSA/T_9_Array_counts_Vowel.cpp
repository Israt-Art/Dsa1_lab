#include<iostream>

using namespace std;

int countVowels(char arr[],int n){

int count=0;
for(int i=0;i<n;i++){
    char ch=tolower(arr[i]);
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
        count++;
    }
}
return count;
}

int main(){

int n;
cout<<"enter the number of elements:";
cin>>n;

cout<<"Input:";
char arr[n];

for(int i=0;i<n;i++){
    cin>>arr[i];
}

cout<<"Count:"<<countVowels(arr,n)<<endl;
return 0;
}
