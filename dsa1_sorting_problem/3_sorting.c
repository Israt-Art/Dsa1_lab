/*Find the smallest difference of elements from an array.
Input Output
a = [15,7,2,12,13] 1
a = [2,13,11,19,5] 2 */

#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);


    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] > a[j])
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    int minDiff = a[1] - a[0];

    for(int i = 1; i < n - 1; i++)
    {
        int diff = a[i + 1] - a[i];
        if(diff < minDiff)
            minDiff = diff;
    }

    printf("Smallest difference is: %d\n", minDiff);

    return 0;
}
