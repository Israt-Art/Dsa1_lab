/*Sort an Array of Strings according to length.
Input Output
a = ["apple", "bat", "carrot", "dog"] ["bat", "dog", "apple", "carrot"]*/
#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    printf("Enter number of strings: ");
    scanf("%d", &n);

    char a[n][100];

    printf("Enter the strings:\n");
    for(int i = 0; i < n; i++)
        scanf("%s", a[i]);


    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(strlen(a[i]) > strlen(a[j]))
            {
                char temp[100];
                strcpy(temp, a[i]);
                strcpy(a[i], a[j]);
                strcpy(a[j], temp);
            }
        }
    }

    printf("Strings after sorting by length:\n");
    for(int i = 0; i < n; i++)
        printf("%s ", a[i]);

    return 0;
}
