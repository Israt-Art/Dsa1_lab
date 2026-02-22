/*8: Count Occurrences of Target with Binary Search
Problem: In a sorted array, count the occurrences of a target value using binary search.
Example:
Input: arr = [2, 4, 4, 4, 6, 7], target = 4
Output: 3*/
#include <stdio.h>


int firstOccurrence(int arr[], int n, int target) {
    int left = 0, right = n - 1, result = -1;
    while(left <= right) {
        int mid = left + (right - left)/2;
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
    int left = 0, right = n - 1, result = -1;
    while(left <= right) {
        int mid = left + (right - left)/2;
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

    if(first == -1) {
        printf("Target %d not found in the array\n", target);
    } else {
        int count = last - first + 1;
        printf("Target %d occurs %d times\n", target, count);
    }

    return 0;
}
