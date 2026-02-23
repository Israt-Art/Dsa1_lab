#include <iostream>
using namespace std;


void SumArrays(int arr1[], int arr2[], int arr3[], int n) {
    for (int i = 0; i < n; i++) {
        arr3[i] = arr1[i] + arr2[i];
    }
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr1[n], arr2[n], arr3[n];

   
    cout << "Enter " << n << " integers for first array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];

    cout << "Enter " << n << " integers for second array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }


    SumArrays(arr1, arr2, arr3, n);

    
    cout << "Sum of corresponding elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;

    return 0;
}
