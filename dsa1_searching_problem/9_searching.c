/*9: Find Closest Element with Binary Search
Problem: Given a sorted array, find the element closest to a given target. If two elements are
equally close, return the smaller one.
Example:
Input: arr = [1, 3, 8, 10, 15], target = 12
Output: 10*/
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
    int closest = arr[0];

    while(left <= right) {
        int mid = left + (right - left)/2;


        if(abs(arr[mid] - target) < abs(closest - target) ||
           (abs(arr[mid] - target) == abs(closest - target) && arr[mid] < closest)) {
            closest = arr[mid];
        }

        if(arr[mid] == target) {
            closest = arr[mid];
            break;
        } else if(arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("Element closest to %d is %d\n", target, closest);

    return 0;
}
