/*5: Binary Search in Descending Order Array
Problem: Perform binary search on a descending order sorted array to find a target value.
Example:
Input: arr = [9, 7, 5, 3, 1], target = 7
Output: 1*/
#include <stdio.h>

int main() {
    int n, target;


    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];


    printf("Enter %d elements in descending order:\n", n);
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

            right = mid - 1;
        } else {

            left = mid + 1;
        }
    }


    if(index != -1)
        printf("Target %d found at index %d\n", target, index);
    else
        printf("Target %d not found in the array\n", target);

    return 0;
}
