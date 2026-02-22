/*Sort an array by absolute value in ascending order.
Input Output
a = [-10, 5, -3, 7, -2] [-2, -3, 5, 7, -10]*/

#include <stdio.h>

int absVal(int x)
{
    if(x < 0)
        return -x;
    return x;
}

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
            if(absVal(a[i]) > absVal(a[j]))
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    printf("Array after sorting by absolute value:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
