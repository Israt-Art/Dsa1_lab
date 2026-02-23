/*[Q1]
Download the week 2 code and execute it to verify its functionality. Your task is to modify the Binary Search operation as follows:
1.
If the given key value is found in the array: Delete the value from its current position and shift the remaining elements to fill the gap.
2.
If the given key value is not found: Insert the value into its correct position in the already sorted array, ensuring the array remains sorted after the insertion.
Ensure that your modifications maintain the integrity of the sorted array and handle edge cases appropriately. Test your updated code with various inputs to confirm its correctness.
[Q2]
Add another new menu option: "Find Square Root." On the same code.
•
The program should prompt the user to enter a number.
•
Implement the function float square_root(float val) to calculate the square root using the binary search method, with a tolerance of 0.005.
•
Ensure that your implementation correctly handles edge cases, such as:
→
When the input is 0
→
When the input is negative
→
When the input is a perfect square.
Hints:
If we need to find √10 we use binary search between 0 and 10. Let's say we find the square root of 10 an approximation, 3.1622, such that: 3.16222=10.0002443
The difference from 10 is: 0.000244
Since 0.000244 is ≤ 0.005, we stop and return 3.162 as the result.
Submission Guideline:
Submit a single code file. There is no need to zip the folder or include additional files.*/


#include <stdio.h>
#include <math.h>

void printData(int data[], int n);
void BubbleSort(int data[], int n);
void handleKeyOperation(int data[], int *n, int key);
float square_root(float val);


int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int data[n];
    for (int i = 0; i < n; i++) {
        printf("Enter data[%d]: ", i);
        scanf("%d", &data[i]);
    }

    printf("Data before sorting:\n");
    printData(data, n);

    BubbleSort(data, n);

    printf("Data after sorting:\n");
    printData(data, n);

    int choice;


    while (1) {
        printf("\nMenu:\n1) Binary Search with Deletion/Insertion\n2) Find Square Root\n");

        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {

            case 1: {

                int key;
                printf("Enter the key for binary search: ");
                scanf("%d", &key);
                handleKeyOperation(data, &n, key);
                printf("Data after binary search operation:\n");
                printData(data, n);
                break;
            }

            case 2: {

                float num;
                printf("Enter number to find square root: ");
                scanf("%f", &num);
                float result = square_root(num);
                if (result == -1.0) {
                    printf("Square root of negative numbers is not real.\n");
                } else {
                    printf("Square root of %.3f is %.3f\n", num, result);
                }
                break;
            }


            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

void printData(int data[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}


void BubbleSort(int data[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (data[j] > data[j + 1]) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void handleKeyOperation(int data[], int *n, int key) {
    int low = 0, high = *n - 1, mid;
    int found = 0;

    while (low <= high) {
        mid = (low + high) / 2;
        if (data[mid] == key) {
            found = 1;
            break;
        } else if (data[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (found) {

        printf("Key %d found at index %d. Deleting and shifting elements.\n", key, mid);
        for (int i = mid; i < *n - 1; i++) {
            data[i] = data[i + 1];
        }
        (*n)--;

    } else {

        printf("Key %d not found. Now inserting at the correct position.\n", key);
        for (int i = *n; i > low; i--) {
            data[i] = data[i - 1];
        }
        data[low] = key;
        (*n)++;
    }
}

float square_root(float val) {
    if (val < 0) {
        return -1.0;
    }

    if (val == 0) {
        return 0.0;
    }

    float low = 0, high = val, mid;
    float tolerance = 0.005;

    if (val < 1) {
        high = 1;
    }

    while (high - low > tolerance) {
        mid = (low + high) / 2;
        if (mid * mid > val) {
            high = mid;
        } else {
            low = mid;
        }
    }

    return (low + high) / 2;
}

