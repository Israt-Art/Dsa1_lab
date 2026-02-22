/*Sort odd indexed elements of an array in descending order and
even indexed elements in ascending order.
Input Output
a = [16,17,4,18,1,20,5,12] [1,20,4,18,5,17,16,12]
a = [4,3,2,1] [2,3 ,4,1]*/
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

            if(i % 2 == 0 && j % 2 == 0)
            {
                if(a[i] > a[j])
                {
                    int t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
            }


            else if(i % 2 == 1 && j % 2 == 1)
            {
                if(a[i] < a[j])
                {
                    int t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
            }
        }
    }

    printf("Array after required sorting:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
