/*Sort the elements of a queue without using any extra space.
Input: q[ ] = {20, 40, 10, 60, 50, 30}
Output: q[ ] = {10, 20, 30, 40, 50, 60}
*/

#include <stdio.h>
#include <limits.h>

#define MAX 100

typedef struct
{
    int arr[MAX];
    int front, rear, size;
} Queue;

void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void enqueue(Queue *q, int x)
{
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = x;
    q->size++;

    printf("Inserted: %d\n", x);
}

int dequeue(Queue *q)
{
    int x = q->arr[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return x;
}


void sortQueue(Queue *q)
{
    int n = q->size;

    for(int i = 0; i < n; i++)
    {
        int min = INT_MAX;


        for(int j = 0; j < q->size; j++)
        {
            int x = dequeue(q);

            if(j < n - i && x < min)
                min = x;

            enqueue(q, x);
        }

        int removed = 0;


        for(int j = 0; j < q->size; j++)
        {
            int x = dequeue(q);

            if(x == min && removed == 0)
                removed = 1;
            else
                enqueue(q, x);
        }


        enqueue(q, min);
    }
}

int main()
{
    Queue q;
    initQueue(&q);

    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter queue elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(&q, x);
    }

    sortQueue(&q);

    printf("\nSorted queue:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", dequeue(&q));
    }

    return 0;
}
