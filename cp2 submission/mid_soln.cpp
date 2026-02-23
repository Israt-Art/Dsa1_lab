


#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};
typedef struct Node node;

void menu();
node* createNode(node* head);
void printList(node* head);
node* insert_head(node* head, node* nn);
node* insert_tail(node* head, node* nn);
node* insertAtNthPosition(node* head, node* nn, int n, int position);
node* delete_head(node *head);
int ListSize(node* head);
node* delete_tail(node *head);
node* delete_nth(node *head, int n, int position);
int isDuplicate(node* head, int value);
void partitionAtK(node* head, int k);
void bubbleSort(node* head);

int main()
{
    node* head = NULL, *nn;
    int choice;

    do {
        menu();
        scanf("%d", &choice);

        if (choice == 1) {
            printList(head);
        }
        else if (choice == 2) {
            nn = createNode(head);
            if (nn != NULL)
                head = insert_head(head, nn);
        }
        else if (choice == 3) {
            nn = createNode(head);
            if (nn != NULL)
                head = insert_tail(head, nn);
        }
        else if (choice == 4) {
            int len = ListSize(head);
            printf("List Size: %d\n\n", len);
        }
        else if (choice == 5) {
            nn = createNode(head);
            if (nn != NULL) {
                int n = ListSize(head);
                printf("Enter position: ");
                int position;
                scanf("%d", &position);
                if (position >= 1 && position <= n + 1)
                    head = insertAtNthPosition(head, nn, n, position);
                else
                    printf("Invalid Position!\n\n");
            }
        }
        else if (choice == 6) {
            head = delete_head(head);
        }
        else if (choice == 7) {
            head = delete_tail(head);
        }
        else if (choice == 8) {
            int n, position;
            n = ListSize(head);
            printf("Enter position: ");
            scanf("%d", &position);
            if (position >= 1 && position <= n)
                head = delete_nth(head, n, position);
            else
                printf("Invalid position\n\n");
        }
        else if (choice == 9) {
            int k;
            printf("Enter position k for partition: ");
            scanf("%d", &k);
            partitionAtK(head, k);
        }
        else if (choice == 10) {
            bubbleSort(head);
        }
        else if (choice == 0) {
            printf("\nYou pressed the Exit button!\nBye...\n");
        }
        else {
            printf("Invalid Choice!\n");
        }

    } while (choice != 0);

    return 0;
}

void menu()
{
    printf("1) Print List\n");
    printf("2) Insert Data at Head \n");
    printf("3) Insert Data at Tail \n");
    printf("4) Size of Linked List\n");
    printf("5) Insert Data at Nth Position \n");
    printf("6) Delete Head data\n");
    printf("7) Delete Tail data\n");
    printf("8) Delete Nth position data\n");
    printf("9) Partition at Kth Element\n");
    printf("10) Sort List using Bubble Sort\n");
    printf("0) Exit\n");
    printf("Enter your choice: ");
}

int isDuplicate(node* head, int value)
{
    node* temp = head;
    while (temp != NULL) {
        if (temp->data == value)
            return 1;
        temp = temp->next;
    }
    return 0;
}

node* createNode(node* head)
{
    int val;
    printf("Enter data: ");
    scanf("%d", &val);
    if (isDuplicate(head, val)) {
        printf("Duplicate data Exists!\n\n");
        return NULL;
    }
    node* nn = new node();
    nn->data = val;
    nn->next = NULL;
    return nn;
}

void printList(node* head)
{
    node* temp = head;
    printf("Data in Linked List:\n\n");
    if (temp == NULL)
        printf("No Data Found!\n");
    else {
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n\n");
}

node* insert_head(node* head, node* nn)
{
    nn->next = head;
    head = nn;
    printf("Node inserted at Head!\n\n");
    return head;
}

node* insert_tail(node* head, node* nn)
{
    if (head == NULL)
        return insert_head(head, nn);
    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = nn;
    printf("Node inserted at Tail!\n\n");
    return head;
}

node* insertAtNthPosition(node* head, node* nn, int n, int position)
{
    if (position == 1)
        return insert_head(head, nn);
    else if (position == n + 1)
        return insert_tail(head, nn);
    else {
        node* temp = head;
        for (int i = 1; i <= position - 2; i++)
            temp = temp->next;
        nn->next = temp->next;
        temp->next = nn;
    }
    printf("Data inserted at %d-th position!\n\n", position);
    return head;
}

node* delete_head(node* head)
{
    if (head == NULL) {
        printf("Nothing to delete\n\n");
        return head;
    }
    node* temp = head;
    head = head->next;
    delete(temp);
    printf("Head Node deleted!\n\n");
    return head;
}

int ListSize(node* head)
{
    int counter = 0;
    while (head != NULL) {
        counter++;
        head = head->next;
    }
    return counter;
}

node* delete_tail(node* head)
{
    int n = ListSize(head);
    if (n <= 1)
        return delete_head(head);
    node* temp = head;
    for (int i = 1; i <= n - 2; i++)
        temp = temp->next;
    delete(temp->next);
    temp->next = NULL;
    printf("Tail Node deleted!\n\n");
    return head;
}

node* delete_nth(node* head, int n, int position)
{
    if (position == 1)
        return delete_head(head);
    else if (position == n)
        return delete_tail(head);
    else {
        node* temp = head;
        for (int i = 1; i <= position - 2; i++)
            temp = temp->next;
        node* del = temp->next;
        temp->next = del->next;
        delete(del);
        printf("%d position Node deleted!\n\n", position);
        return head;
    }
}

void partitionAtK(node* head, int k)
{
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    int count = 1;
    node* temp = head;
    while (temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Invalid k position!\n");
        return;
    }
    node* secondHalf = temp->next;
    temp->next = NULL;

    printf("First Half: ");
    printList(head);
    printf("Last Half: ");
    printList(secondHalf);
}

void bubbleSort(node* head)
{
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    int swapped;
    node* ptr1;
    node* lptr = NULL;
    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    printf("Linked List sorted using Bubble Sort.\n\n");
}
