/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorte-r <bcorte-r@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:18:41 by bcorte-r          #+#    #+#             */
/*   Updated: 2024/03/13 18:44:42 by bcorte-r         ###   ########.fr       */
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

// Example usage
int main() {
    struct Node* head = NULL;
    push(&head, 10);
    push(&head, 7);
    push(&head, 8);
    push(&head, 9);
    push(&head, 1);
    push(&head, 5);
    push(&head, 20);
    push(&head, 17);
    push(&head, 18);
    push(&head, 19);
    push(&head, 11);
    push(&head, 15);
    push(&head, 30);
    push(&head, 27);
    push(&head, 28);
    push(&head, 29);
    push(&head, 21);
    push(&head, 25);
    push(&head, -10);
    push(&head, -7);
    push(&head, -8);
    push(&head, -9);
    push(&head, 31);
    push(&head, 35);
    push(&head, 120);
    push(&head, 77);
    push(&head, 58);
    push(&head, 69);
    push(&head, 41);
    push(&head, 45);

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
