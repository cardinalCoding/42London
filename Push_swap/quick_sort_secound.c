/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_secound.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorte-r <bcorte-r@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:18:41 by bcorte-r          #+#    #+#             */
/*   Updated: 2024/03/13 18:57:47 by bcorte-r         ###   ########.fr       */
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
        }
    }
    i = (i == NULL) ? low : i->next;
    swap(i, high);
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

// Sequence of operations for sorting
void sa(struct Node** top) {
    if (*top == NULL || (*top)->next == NULL)
        return;
    int temp = (*top)->data;
    (*top)->data = (*top)->next->data;
    (*top)->next->data = temp;
}

void pa(struct Node** top_a, struct Node** top_b) {
    if (*top_b == NULL)
        return;
    push(top_a, (*top_b)->data);
    struct Node* temp = *top_b;
    *top_b = (*top_b)->next;
    free(temp);
}

void ra(struct Node** top) {
    if (*top == NULL || (*top)->next == NULL)
        return;
    struct Node* last = *top;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = *top;
    *top = (*top)->next;
    last->next->next = NULL;
}

void rra(struct Node** top) {
    if (*top == NULL || (*top)->next == NULL)
        return;
    struct Node* temp = *top;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    struct Node* last = temp;
    temp = *top;
    *top = (*top)->next;
    (*top)->prev = NULL;
    last->next = temp;
    temp->prev = last;
}

// Example usage
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <num1> <num2> ... <numN>\n", argv[0]);
        return 1;
    }

    struct Node* head = NULL;
    for (int i = 1; i < argc; i++) {
        push(&head, atoi(argv[i]));
    }

    printf("Unsorted linked list: \n");
    printList(head);

    // Find the last node of the linked list
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    quickSort(head, temp);

    printf("Sorted linked list: \n");
    printList(head);

    return 0;
}


