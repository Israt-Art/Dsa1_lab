/*Find the Insert Position
Problem: Given a sorted array, return the index where a target value should be inserted to
maintain the order. Use binary search.
Example:
Input: arr = [1, 3, 5, 6], target = 4
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
    int insertPos = n;

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] >= target) {
            insertPos = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("Insert position for %d is %d\n", target, insertPos);

    return 0;
}
