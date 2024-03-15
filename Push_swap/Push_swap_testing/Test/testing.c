#include <stdio.h>
#include <stdlib.h>

#define SA "sa\n"
#define SB "sb\n"
#define SS "ss\n"
#define PA "pa\n"
#define PB "pb\n"
#define RA "ra\n"
#define RB "rb\n"
#define RR "rr\n"
#define RRA "rra\n"
#define RRB "rrb\n"
#define RRR "rrr\n"

// Define stack structure
typedef struct Stack {
    int *array;
    int top;
    int capacity;
} Stack;

// Function prototypes
Stack *createStack(int capacity);
void push(Stack *stack, int item);
int pop(Stack *stack);
void swap(Stack *stack);
void pushAtoB(Stack *stackA, Stack *stackB);
void rotate(Stack *stack);
void reverseRotate(Stack *stack);
void sort(Stack *stackA, Stack *stackB);
int isSorted(Stack *stack);

int main(int argc, char *argv[]) {
    // Check if there are enough arguments
    if (argc < 2) {
        printf("Usage: %s <integer1> <integer2> ... <integerN>\n", argv[0]);
        return 1;
    }

    // Create stack A and push integers onto it
    Stack *stackA = createStack(argc - 1);
    for (int i = 1; i < argc; i++) {
        push(stackA, atoi(argv[i]));
    }

    // Create an empty stack B
    Stack *stackB = createStack(argc - 1);

    // Sort the stack A
    sort(stackA, stackB);

    // Free allocated memory
    free(stackA->array);
    free(stackA);
    free(stackB->array);
    free(stackB);

    return 0;
}

// Create a stack with given capacity
Stack *createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Push an item onto the stack
void push(Stack *stack, int item) {
    stack->array[++stack->top] = item;
}

// Pop an item from the stack
int pop(Stack *stack) {
    return stack->array[stack->top--];
}

// Swap the top two elements of the stack
void swap(Stack *stack) {
    if (stack->top < 1) return;
    int temp = stack->array[stack->top];
    stack->array[stack->top] = stack->array[stack->top - 1];
    stack->array[stack->top - 1] = temp;
}

// Push the top element from stack B to stack A
void pushAtoB(Stack *stackA, Stack *stackB) {
    if (stackA->top >= 0) { // Check if stack A is not empty
        push(stackB, pop(stackA)); // Corrected order of push
    } else {
        printf("pushAtoB: Stack A is empty\n");
    }
}

// Rotate the stack (shift up all elements by one)
void rotate(Stack *stack) {
    if (stack->top < 1) return;
    int temp = stack->array[0];
    for (int i = 0; i < stack->top - 1; i++) {
        stack->array[i] = stack->array[i + 1];
    }
    stack->array[stack->top - 1] = temp;
}

// Reverse rotate the stack (shift down all elements by one)
void reverseRotate(Stack *stack) {
    if (stack->top < 1) return;
    int temp = stack->array[stack->top];
    for (int i = stack->top; i > 0; i--) {
        stack->array[i] = stack->array[i - 1];
    }
    stack->array[0] = temp;
}

// Sort the stack using push_swap algorithm
void sort(Stack *stackA, Stack *stackB) {
    int lastOp = -1; // To store the last operation performed: 0 for swap, 1 for rotate
    while (!isSorted(stackA)) {
        if (stackA->array[stackA->top] > stackA->array[stackA->top - 1]) {
            if (lastOp != 0) {
                swap(stackA);
                printf("%s", SA);
                lastOp = 0;
            } else {
                rotate(stackA);
                printf("%s", RA);
                lastOp = 1;
            }
        } else if (stackA->top > 0 && stackA->array[stackA->top] < stackA->array[stackA->top - 1]) {
            pushAtoB(stackA, stackB);
            printf("%s", PB);
            lastOp = -1;
        } else {
            rotate(stackA);
            printf("%s", RA);
            lastOp = 1;
        }
        printf("Stack A: ");
        for (int i = 0; i <= stackA->top; i++) {
            printf("%d ", stackA->array[i]);
        }
        printf("\n");
        printf("Stack B: ");
        for (int i = 0; i <= stackB->top; i++) {
            printf("%d ", stackB->array[i]);
        }
        printf("\n");
    }
    while (stackB->top >= 0) {
        pushAtoB(stackA, stackB);
        printf("%s", PB);
        printf("Stack A: ");
        for (int i = 0; i <= stackA->top; i++) {
            printf("%d ", stackA->array[i]);
        }
        printf("\n");
        printf("Stack B: ");
        for (int i = 0; i <= stackB->top; i++) {
            printf("%d ", stackB->array[i]);
        }
        printf("\n");
    }
}


// Check if the stack is sorted
int isSorted(Stack *stack) {
    for (int i = 0; i < stack->top; i++) {
        if (stack->array[i] > stack->array[i + 1]) return 0;
    }
    return 1;
}
