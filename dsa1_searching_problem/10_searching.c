/*10: Find Peak Element with Binary Search
Problem: Given an array where elements increase and then decrease (a ”mountain” array),
find the index of the peak element using binary search.
Example:
Input: arr = [1, 3, 8, 12, 4, 2]
Output: 3 (peak element 12 is at index 3)
3*/
#include <stdio.h>

int main() {
    int n;


    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];


    printf("Enter %d elements (mountain array):\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    int left = 0, right = n - 1;
    int peakIndex = 0;

    while(left <= right) {
        int mid = left + (right - left)/2;


        if((mid == 0 || arr[mid] > arr[mid - 1]) &&
           (mid == n - 1 || arr[mid] > arr[mid + 1])) {
            peakIndex = mid;
            break;
        }

        else if(mid > 0 && arr[mid - 1] > arr[mid]) {
            right = mid - 1;
        }

        else {
            left = mid + 1;
        }
    }

    printf("Peak element is %d at index %d\n", arr[peakIndex], peakIndex);

    return 0;
}
