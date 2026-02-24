/*Given a singly linked list, print “YES” if it is a palindrome otherwise print “NO”.

Input Output

1->2->2->1 YES
1->2->3->1 NO */


#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}


void insertEnd(struct Node** head, int data) {
    struct Node* temp = newNode(data);
    if (*head == NULL) {
        *head = temp;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = temp;
}

struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}


int isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return 1;

    struct Node *slow = head, *fast = head;

   
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

   
    struct Node* secondHalf = reverseList(slow);
    struct Node* firstHalf = head;
    struct Node* temp = secondHalf;

    
    while (temp != NULL) {
        if (firstHalf->data != temp->data)
            return 0;
        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    return 1;
}


void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        insertEnd(&head, data);
    }

    printf("Linked List: ");
    displayList(head);

    if (isPalindrome(head))
        printf("The linked list is a Palindrome.\n");
    else
        printf("The linked list is NOT a Palindrome.\n");

    return 0;
}