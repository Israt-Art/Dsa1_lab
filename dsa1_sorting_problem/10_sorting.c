/*You are given a list of tasks, where each task is represented as
(StartTime, FinishTime). The goal is to sort the tasks based on their
durations (calculated as FinishTime - StartTime) in ascending
order.
Input Output
[(2, 5), (1, 2), (4, 6)] [(1, 3), (4, 6), (2, 5)]*/
#include <stdio.h>

typedef struct {
    int start;
    int finish;
} Task;

int main()
{
    int n;
    printf("Enter number of tasks: ");
    scanf("%d", &n);

    Task tasks[n];

    printf("Enter start and finish times of tasks:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &tasks[i].start, &tasks[i].finish);
    }


    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int dur_i = tasks[i].finish - tasks[i].start;
            int dur_j = tasks[j].finish - tasks[j].start;
            if(dur_i > dur_j)
            {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    printf("Tasks after sorting by duration:\n");
    for(int i = 0; i < n; i++)
    {
        printf("(%d, %d) ", tasks[i].start, tasks[i].finish);
    }

    return 0;
}


