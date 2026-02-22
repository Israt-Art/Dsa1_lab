/*1: Linear Search
Problem: Given an array of integers, find the first occurrence of a target integer. If the target
is not in the array, return -1.
Example:
Input: arr = [5, 3, 8, 1, 9], target = 8
Output: 2
*/
#include <stdio.h>

int main() {
    int n, target;


    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];


    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    printf("Enter the target element: ");
    scanf("%d", &target);

    int index = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            index = i;
            break;
        }
    }


    if(index != -1)
        printf("Target %d found at index %d\n", target, index);
    else
        printf("Target %d not found in the array\n", target);

    return 0;
}
