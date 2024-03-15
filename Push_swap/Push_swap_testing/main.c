#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void push(Node** top, int data);
int pop(Node** top);
void printStack(Node* top);

// Stack operations
void sa(Node** top);
void pa(Node** dest, Node** src);
void ra(Node** top);
void rra(Node** top);

// Sorting algorithm using stack operations
void bubbleSort(Node** top, int* operationCount);

int main(int argc, char *argv[]) {
    Node *stack_a = NULL;
    int operationCount = 0; // Initialize operation count

    if (argc < 2)
    {
        printf("Usage: %s <numbers to push separated by space>\n", argv[0]);
        return 1;
    }

    // Push elements provided as command-line arguments
    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]); // Convert argument to integer
        push(&stack_a, num);
    }

    // Example usage of operations
    printf("Stack a before sorting: ");
    printStack(stack_a);
    printf("\n");

    // Sort the stack using bubble sort algorithm
    bubbleSort(&stack_a, &operationCount);

    // Display sorted stack
    printf("Stack a after sorting: ");
    printStack(stack_a);
    printf("\n");

    // Display operation count
    printf("Total operations performed: %d\n", operationCount);

    // Free allocated memory
    Node* temp;
    while (stack_a != NULL) {
        temp = stack_a;
        stack_a = stack_a->next;
        free(temp);
    }

    return 0;
}

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Push operation for a stack
void push(Node** top, int data) {
    Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Pop operation for a stack
int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = *top;
    int data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}

// Print the elements of a stack
void printStack(Node* top) {
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
}

// Swap operation for a stack
void sa(Node** top) {
    if (*top == NULL || (*top)->next == NULL)
        return;
    int temp = (*top)->data;
    (*top)->data = (*top)->next->data;
    (*top)->next->data = temp;
}

// Push from source stack to destination stack
void pa(Node** dest, Node** src) {
    if (*src == NULL)
        return;
    push(dest, pop(src));
}

// Rotate up operation for a stack
void ra(Node** top) {
    if (*top == NULL || (*top)->next == NULL)
        return;
    Node* last = *top;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = *top;
    *top = (*top)->next;
    last->next->next = NULL;
}

// Rotate down operation for a stack
void rra(Node** top) {
    if (*top == NULL || (*top)->next == NULL)
        return;
    Node* temp = *top;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    Node* last = temp->next;
    temp->next = NULL;
    last->next = *top;
    *top = last;
}

// Sorting algorithm using stack operations (Bubble Sort)
void bubbleSort(Node** top, int* operationCount) {
    int len = 0;
    Node* temp = *top;
    // Calculate the length of the stack
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }

    for (int i = 0; i < len - 1; i++) {
        Node* current = *top;
        Node* nextNode = current->next;
        for (int j = 0; j < len - i - 1; j++) {
            if (current->data > nextNode->data) {
                // Swap elements using stack operations
                sa(&current);
                (*operationCount)++;
                printf("Operation %d: sa\n", *operationCount);
            }
            current = current->next;
            nextNode = nextNode->next;
        }
        if (i < len - 1) {
            // Rotate down operation for a stack
            rra(top);
            (*operationCount)++;
            printf("Operation %d: rra\n", *operationCount);
        }
    }
}
