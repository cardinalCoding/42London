#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to swap two nodes in the linked list
void swapNodes(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to perform selection sort on the linked list
void selectionSort(struct Node* head) {
    struct Node *i, *j, *min;
    for (i = head; i != NULL; i = i->next) {
        min = i;
        for (j = i->next; j != NULL; j = j->next) {
            if (j->data < min->data)
                min = j;
        }
        swapNodes(i, min);
    }
}

// Main function to test the above functions
int main() {
    struct Node* head = NULL;
    insertNode(&head, 64);
    insertNode(&head, 25);
    insertNode(&head, 12);
    insertNode(&head, 22);
    insertNode(&head, 11);

    printf("Original list: ");
    printList(head);

    selectionSort(head);

    printf("Sorted list: ");
    printList(head);

    return 0;
}
