/*Given a queue q[ ] and an integer K, remove the integer K from the queue. If
multiple same elements exist, remove the first one.
Input: q[ ] = {10, 20, 30, 40, 50, 60}, K = 30
Output: {10, 20, 40, 50, 60}
Input: q[] = {1, 2, 3, 3}, K = 3
Output: {1, 2, 3}
*/

#include <stdio.h>

#define MAX 100

void removeElement(int q[], int *size, int K) {
    int temp[MAX];
    int j = 0;
    int found = 0;

    for (int i = 0; i < *size; i++) {

        if (q[i] == K && !found) {
            found = 1;
            continue;
        }
        temp[j++] = q[i];
    }


    *size = j;
    for (int i = 0; i < j; i++) {
        q[i] = temp[i];
    }
}

int main() {
    int q[MAX], size, K;


    printf("Enter the number of elements in the queue: ");
    scanf("%d", &size);


    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &q[i]);
    }


    printf("Enter the integer K to remove: ");
    scanf("%d", &K);

    removeElement(q, &size, K);


    printf("Output Queue: {");
    for (int i = 0; i < size; i++) {
        printf("%d", q[i]);
        if (i < size - 1) printf(", ");
    }
    printf("}\n");

    return 0;
}

