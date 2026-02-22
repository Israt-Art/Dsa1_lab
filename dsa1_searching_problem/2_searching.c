/*2: Linear Search with Multiple Occurrences
Problem: Given an array, find all the indices where a target integer appears. Return an array
of indices. If the target does not appear, return an empty array.
Example:
Input: arr = [4, 2, 3, 2, 4, 2], target = 2
Output: [1, 3, 5] */
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


    int found = 0;
    printf("Target %d found at indices: ", target);
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            printf("%d ", i);
            found = 1;
        }
    }

    if(!found)
        printf("None");

    printf("\n");
    return 0;
}
