#include <iostream>
using namespace std;


void removeDuplicates(int arr[], int &n) {
    int uniqueIndex = 0;

  
    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;

       
        for (int j = 0; j < uniqueIndex; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }


        if (!isDuplicate) {
            arr[uniqueIndex] = arr[i];
            uniqueIndex++;
        }
    }

 
    n = uniqueIndex;
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;

    
    cin >> n;

    int arr[n];

    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    
    removeDuplicates(arr, n);

  
    displayArray(arr, n);

    return 0;
}
