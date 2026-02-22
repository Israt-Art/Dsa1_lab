/*Find the Longest Consecutive Subsequence after sorting an array.
Input Output
a = [1, 9, 3, 10, 4, 20, 2] 4
a = [3,1] 1*/
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

    int maxLen = 1;
    int currLen = 1;

    for(int i = 1; i < n; i++)
    {
        if(a[i] == a[i - 1] + 1)
        {
            currLen++;
        }
        else if(a[i] == a[i - 1])
        {

            continue;
        }
        else
        {
            if(currLen > maxLen)
                maxLen = currLen;
            currLen = 1;
        }
    }

    if(currLen > maxLen)
        maxLen = currLen;

    printf("Length of longest consecutive subsequence: %d\n", maxLen);

    return 0;
}
