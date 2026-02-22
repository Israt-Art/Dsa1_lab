/*Sort an array based on the frequency of its elements. If two
elements have the same frequency, sort them in ascending order.
Input Output
a = [4, 3, 1, 6, 1, 3, 4, 4] [4, 4, 4, 1, 1, 3, 3, 6]*/
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

    int freq[n];
    for(int i = 0; i < n; i++)
    {
        freq[i] = 1;
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] == a[j])
            {
                freq[i]++;
            }
        }
    }


    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(freq[i] < freq[j] || (freq[i] == freq[j] && a[i] > a[j]))
            {

                int t = a[i];
                a[i] = a[j];
                 a[j] = t;

                t = freq[i];
                freq[i] = freq[j];
                freq[j] = t;
            }
        }
    }

    printf("Array after sorting by frequency:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
