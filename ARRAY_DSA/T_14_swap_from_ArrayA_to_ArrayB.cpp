#include <iostream>
using namespace std;

void swapArrays(int A[], int B[], int &n, int &m) {
    int tempSize = n;
    n = m;
    m = tempSize;

    int temp[100]; // Assuming max size 100 for simplicity
    for (int i = 0; i < n; i++) temp[i] = A[i];
    for (int i = 0; i < m; i++) A[i] = B[i];
    for (int i = 0; i < tempSize; i++) B[i] = temp[i];
}

int main() {
    int n, m, A[100], B[100];

    cout << "Enter number of elements in A: ";
    cin >> n;
    cout << "Enter " << n << " elements of A: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Enter number of elements in B: ";
    cin >> m;
    cout << "Enter " << m << " elements of B: ";
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    swapArrays(A, B, n, m);

    cout << "Array A: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "Array B: ";
    for (int i = 0; i < m; i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    return 0;
}
