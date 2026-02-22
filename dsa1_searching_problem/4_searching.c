/*4: Binary Search in a Sorted Array
Problem: Implement binary search in a sorted array to locate a target value. Return the
index of the target if found; otherwise, return -1.
Example:
Input: arr = [1, 3, 5, 7, 9], target = 5
Output: 2*/
#include <stdio.h>

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


    int left = 0, right = n - 1;
    int index = -1;

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target) {
            index = mid;
            break;
        } else if(arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }


    if(index != -1)
        printf("Target %d found at index %d\n", target, index);
    else
        printf("Target %d not found in the array\n", target);

    return 0;
}
