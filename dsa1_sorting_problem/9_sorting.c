/*You are given two arrays a and b. Merge a and b into a single array
sorted in non-decreasing order.
Input Output
a = [1,16,13,14,4]
b = [15,12,5,3,7]
[1,3,4,5,7,12,13,14,15,16] */
#include <stdio.h>

int main()
{
    int n1, n2;
    printf("Enter size of first array: ");
    scanf("%d", &n1);
    int a[n1];
    printf("Enter elements of first array:\n");
    for(int i = 0; i < n1; i++)
        scanf("%d", &a[i]);

    printf("Enter size of second array: ");
    scanf("%d", &n2);
    int b[n2];
    printf("Enter elements of second array:\n");
    for(int i = 0; i < n2; i++)
        scanf("%d", &b[i]);

    int merged[n1 + n2];


    for(int i = 0; i < n1; i++)
        merged[i] = a[i];


    for(int i = 0; i < n2; i++)
        merged[n1 + i] = b[i];


    int total = n1 + n2;
    for(int i = 0; i < total - 1; i++)
    {
        for(int j = i + 1; j < total; j++)
        {
            if(merged[i] > merged[j])
            {
                int t = merged[i];
                merged[i] = merged[j];
                merged[j] = t;
            }
        }
    }

    printf("Merged and sorted array:\n");
    for(int i = 0; i < total; i++)
        printf("%d ", merged[i]);

    return 0;
}
