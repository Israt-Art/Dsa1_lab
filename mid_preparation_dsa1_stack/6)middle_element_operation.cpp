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
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}


int getMiddle() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return INT_MIN;
    }
    int midIndex = top / 2;
    return stack[midIndex];
}


void deleteMiddle() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    int midIndex = top / 2;
    for (int i = midIndex; i < top; i++) {
        stack[i] = stack[i + 1];
    }
    top--;
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
    printf("Middle element: %d\n\n", getMiddle());

    
    printf("Delete the middle element of the said stack:\n");
    deleteMiddle();
    display();
    printf("Middle element: %d\n\n", getMiddle());

    
    printf("Delete the middle element of the said stack:\n");
    deleteMiddle();
    display();
    printf("Middle element: %d\n", getMiddle());

    return 0;
}

