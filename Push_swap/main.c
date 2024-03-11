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
void sa(Node** top);
void sb(Node** top);
void ss(Node** top_a, Node** top_b);
void pa(Node** top_a, Node** top_b);
void pb(Node** top_a, Node** top_b);
void ra(Node** top);
void rb(Node** top);
void rr(Node** top_a, Node** top_b);
void rra(Node** top);
void rrb(Node** top);
void rrr(Node** top_a, Node** top_b);

int main(int argc, char *argv[]) {
    Node* stack_a = NULL;
    Node* stack_b = NULL;
    
    if (argc < 2) {
        printf("Usage: %s <numbers to push separated by space>\n", argv[0]);
        return 1;
    }
     // Push elements provided as command-line arguments
    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]); // Convert argument to integer
        push(&stack_a, num);
    }

    // Push random elements to stack a
    //push(&stack_a, 8);
    //push(&stack_a, 5);
    //push(&stack_a, 6);
    //push(&stack_a, 3);
    //push(&stack_a, 1);
    //push(&stack_a, 2);

    // Example usage of operations
    printf("Stack a before sorting: ");
    printStack(stack_a);
    printf("\n");

    printf("Stack b before sorting: ");
    printStack(stack_b);
    printf("\n");

    // Example operations
    sa(&stack_a); // Swap a
    pb(&stack_a, &stack_b);
    pb(&stack_a, &stack_b); 
    pb(&stack_a, &stack_b);  // Push b
    rr(&stack_a, &stack_b);
    //rrr(&stack_a, &stack_b);
    //sa(&stack_a);
    //pa(&stack_a, &stack_b);
    //pa(&stack_a, &stack_b); 
    //pa(&stack_a, &stack_b); 

    printf("Stack a after sorting: ");
    printStack(stack_a);
    printf("\n");

    printf("Stack b after sorting: ");
    printStack(stack_b);
    printf("\n");

    // Free allocated memory
    Node* temp;
    while (stack_a != NULL) {
        temp = stack_a;
        stack_a = stack_a->next;
        free(temp);
    }
    while (stack_b != NULL) {
        temp = stack_b;
        stack_b = stack_b->next;
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

// Swap the first 2 elements at the top of stack a
void sa(Node** top) {
    if (*top == NULL || (*top)->next == NULL)
        return;
    int temp = (*top)->data;
    (*top)->data = (*top)->next->data;
    (*top)->next->data = temp;
}

// Swap the first 2 elements at the top of stack b
void sb(Node** top) {
    sa(top);
}

// sa and sb at the same time
void ss(Node** top_a, Node** top_b) {
    sa(top_a);
    sa(top_b);
}

// Take the first element at the top of b and put it at the top of a
void pa(Node** top_a, Node** top_b) {
    if (*top_b == NULL)
        return;
    push(top_a, pop(top_b));
}

// Take the first element at the top of a and put it at the top of b
void pb(Node** top_a, Node** top_b) {
    pa(top_b, top_a);
}

// Shift up all elements of stack a by 1
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

// Shift up all elements of stack b by 1
void rb(Node** top) {
    ra(top);
}

// ra and rb at the same time
void rr(Node** top_a, Node** top_b) {
    ra(top_a);
    ra(top_b);
}

// Shift down all elements of stack a by 1
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

// Shift down all elements of stack b by 1
void rrb(Node** top) {
    rra(top);
}

// rra and rrb at the same time
void rrr(Node** top_a, Node** top_b) {
    rra(top_a);
    rrb(top_b);
}
