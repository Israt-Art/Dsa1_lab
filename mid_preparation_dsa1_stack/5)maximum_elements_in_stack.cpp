#include <stdio.h>
#include <limits.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = value;
}


void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return;
    }
    top--;
}


void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Current stack elements:\n");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int getMax() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return INT_MIN;
    }
    int max = stack[0];
    for (int i = 1; i <= top; i++) {
        if (stack[i] > max) {
            max = stack[i];
        }
    }
    return max;
}

int main() {
    int n, value;

   
    printf("How many elements you want to push initially? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        push(value);
    }

    display();
    printf("Maximum element: %d\n\n", getMax());

    printf("After removing two elements:\n");
    pop();
    pop();
    display();
    printf("Maximum element: %d\n\n", getMax());

    
    printf("Enter one more element to push: ");
    scanf("%d", &value);
    push(value);

    printf("After adding one element:\n");
    display();
    printf("Maximum element: %d\n", getMax());

    return 0;
}
