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

struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    struct Node* head = NULL, *tail = NULL;


    if (list1->data <= list2->data) {
        head = tail = list1;
        list1 = list1->next;
    } else {
        head = tail = list2;
        list2 = list2->next;
    }

    while (list1 && list2) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1) tail->next = list1;
    if (list2) tail->next = list2;

    return head;
}


void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    int n, m, value;
    struct Node *list1 = NULL, *list2 = NULL, *temp = NULL;

    
    printf("Enter number of nodes for first list: ");
    scanf("%d", &n);
    printf("Enter sorted values for first list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* new_node = newNode(value);
        if (!list1) {
            list1 = new_node;
        } else {
            temp->next = new_node;
        }
        temp = new_node;
    }

    
    printf("Enter number of nodes for second list: ");
    scanf("%d", &m);
    printf("Enter sorted values for second list:\n");
    temp = NULL; 
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        struct Node* new_node = newNode(value);
        if (!list2) {
            list2 = new_node;
        } else {
            temp->next = new_node;
        }
        temp = new_node;
    }

    printf("\nFirst Sorted Linked List:\n");
    printList(list1);

    printf("\nSecond Sorted Linked List:\n");
    printList(list2);

    struct Node* mergedList = mergeSortedLists(list1, list2);

    printf("\nMerged Sorted Linked List:\n");
    printList(mergedList);

    return 0;
}
