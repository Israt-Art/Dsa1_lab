/*Find the median from an array.
Input Output
a = [5,2,1,4,7] 4
a = [11,9,17,15] 13 */
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
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

    if(n % 2 == 1)
        printf("%d", a[n / 2]);
    else
        printf("%d", (a[n/2 - 1] + a[n/2]) / 2);

    return 0;
}
