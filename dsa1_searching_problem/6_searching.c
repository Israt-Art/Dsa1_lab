/*6: Binary Search for First and Last Occurrence
Problem: Given a sorted array, find the first and last positions of a target value. If the target
is not found, return (-1, -1).
Example:
Input: arr = [1, 2, 2, 2, 3, 4], target = 2
Output: (1, 3)*/
#include <stdio.h>


int firstOccurrence(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int result = -1;

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target) {
            result = mid;
            right = mid - 1;
        } else if(arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}


int lastOccurrence(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int result = -1;

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target) {
            result = mid;
            left = mid + 1;
        } else if(arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    int n, target;


    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];


    printf("Enter %d elements in sorted order:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    printf("Enter the target element: ");
    scanf("%d", &target);

    int first = firstOccurrence(arr, n, target);
    int last = lastOccurrence(arr, n, target);

    printf("First and Last Occurrence: (%d, %d)\n", first, last);

    return 0;
}
