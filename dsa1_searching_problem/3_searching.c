/*3: Linear Search with Condition
Problem: Find the first element in an array of integers that is greater than a given target. If
no such element exists, return -1.
Example:
Input: arr = [3, 5, 7, 2, 8, 10], target = 6
Output: 7*/
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


    int found = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i] > target) {
            found = arr[i];
            break;
        }
    }


    if(found != -1)
        printf("First element greater than %d is %d\n", target, found);
    else
        printf("No element greater than %d found in the array\n", target);

    return 0;
}
