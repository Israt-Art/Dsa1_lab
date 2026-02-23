#include <stdio.h>
#define MAX 100

int main() {
    int queue[MAX];
    int front = 0, rear = -1;
    int n, i, j, temp;

    // Take number of elements
    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);

    // Input queue elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &queue[++rear]);
    }

    // In-place Sorting (using simple selection sort)
    for(i = front; i <= rear-1; i++) {
        for(j = i+1; j <= rear; j++) {
            if(queue[i] > queue[j]) {
                // Swap elements
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    // Print sorted queue
    printf("Sorted Queue: ");
    for(i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}

