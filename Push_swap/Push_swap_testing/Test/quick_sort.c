/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorte-r <bcorte-r@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:18:41 by bcorte-r          #+#    #+#             */
/*   Updated: 2024/03/14 20:04:04 by bcorte-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Global variable to count sorting operations
int sorting_counter = 0;

// Function to insert a new node at the beginning of the linked list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = *head_ref;

    if (*head_ref != NULL)
        (*head_ref)->prev = new_node;

    *head_ref = new_node;
}

// Function to swap two nodes in the linked list
void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to partition the linked list and return the pivot node
struct Node* partition(struct Node* low, struct Node* high) {
    int pivot = high->data; // Choosing the last element as the pivot
    struct Node* i = low->prev;

    for (struct Node* j = low; j != high; j = j->next) {
        if (j->data <= pivot) {
            i = (i == NULL) ? low : i->next;
            swap(i, j);
            sorting_counter++;
        }
    }
    i = (i == NULL) ? low : i->next;
    swap(i, high);
    sorting_counter++;
    return i;
}

// Function to implement Quick Sort on linked list
void quickSort(struct Node* low, struct Node* high) {
    if (high != NULL && low != high && low != high->next) {
        struct Node* pi = partition(low, high);
        quickSort(low, pi->prev);
        quickSort(pi->next, high);
    }
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Swap operation for stack a (sa)
void swap_a(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return;

    swap(head, head->next);
}

// Swap operation for stack b (sb)
void swap_b(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return;

    swap(head, head->next);
}

// Swap operation for both stacks (ss)
void swap_both(struct Node* head_a, struct Node* head_b) {
    swap_a(head_a);
    swap_b(head_b);
}

// Push operation for stack a (pa)
void push_a(struct Node** head_a, struct Node** head_b) {
    if (*head_b == NULL)
        return;

    struct Node* temp = *head_b;
    *head_b = (*head_b)->next;

    temp->next = *head_a;
    temp->prev = NULL;
    if (*head_a != NULL)
        (*head_a)->prev = temp;
    *head_a = temp;
}

// Push operation for stack b (pb)
void push_b(struct Node** head_a, struct Node** head_b) {
    if (*head_a == NULL)
        return;

    struct Node* temp = *head_a;
    *head_a = (*head_a)->next;

    temp->next = *head_b;
    temp->prev = NULL;
    if (*head_b != NULL)
        (*head_b)->prev = temp;
    *head_b = temp;
}

// Rotate operation for stack a (ra)
void rotate_a(struct Node** head_a) {
    if (*head_a == NULL || (*head_a)->next == NULL)
        return;

    struct Node* last = *head_a;
    while (last->next != NULL)
        last = last->next;

    last->next = *head_a;
    (*head_a)->prev = last;
    *head_a = (*head_a)->next;
    last->next->next = NULL;
    last->next->prev = NULL;
}

// Rotate operation for stack b (rb)
void rotate_b(struct Node** head_b) {
    if (*head_b == NULL || (*head_b)->next == NULL)
        return;

    struct Node* last = *head_b;
    while (last->next != NULL)
        last = last->next;

    last->next = *head_b;
    (*head_b)->prev = last;
    *head_b = (*head_b)->next;
    last->next->next = NULL;
    last->next->prev = NULL;
}

// Rotate operation for both stacks (rr)
void rotate_both(struct Node** head_a, struct Node** head_b) {
    rotate_a(head_a);
    rotate_b(head_b);
}

// Reverse rotate operation for stack a (rra)
void reverse_rotate_a(struct Node** head_a) {
    if (*head_a == NULL || (*head_a)->next == NULL)
        return;

    struct Node* temp = *head_a;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = *head_a;
    (*head_a)->prev = temp;
    *head_a = temp->next->next;
    (*head_a)->prev = NULL;
    temp->next->next = NULL;
}

// Reverse rotate operation for stack b (rrb)
void reverse_rotate_b(struct Node** head_b) {
    if (*head_b == NULL || (*head_b)->next == NULL)
        return;

    struct Node* temp = *head_b;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = *head_b;
    (*head_b)->prev = temp;
    *head_b = temp->next->next;
    (*head_b)->prev = NULL;
    temp->next->next = NULL;
}

// Reverse rotate operation for both stacks (rrr)
void reverse_rotate_both(struct Node** head_a, struct Node** head_b) {
    reverse_rotate_a(head_a);
    reverse_rotate_b(head_b);
}

// Example usage
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <element1> <element2> ... <elementN>\n", argv[0]);
        return 1;
    }

    struct Node* head_a = NULL; // Stack a

    // Parse command-line arguments and push them onto stack a
    for (int i = 1; i < argc; i++) {
        push(&head_a, atoi(argv[i]));
    }

    printf("Unsorted stack a: ");
    printList(head_a);

    // Sort the stack a using Quick Sort
    struct Node* temp = head_a;
    while (temp->next != NULL)
        temp = temp->next;
    quickSort(head_a, temp);

    printf("Sorted stack a: ");
    printList(head_a);

    printf("Number of sorting operations performed: %d\n", sorting_counter);

    return 0;
}
