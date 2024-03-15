/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorte-r <bcorte-r@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:55:59 by bcorte-r          #+#    #+#             */
/*   Updated: 2024/03/15 15:10:04 by bcorte-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

// Node structure for doubly linked list
typedef struct Node {
    int data;
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct
{
    Node* top;
    int size;
} Stack;

//Actions
Node* createNode(int data);
int pop(Node** top);
void print_stack(Node *top);
void print_stacks(Node *stackA, Node *stackB);
//sequences
void rotate(Node** top);
void ra(Node** top_a);
void rb(Node** top_b);
void rr(Node** top_a, Node** top_b);
void rotate_rev(Node **top);
void rra(Node** top_a);
void rrb(Node** top_b);
void rrr(Node** top_a, Node** top_b);
void push(Node** top_a, int data);
void pa(Node** top_a, Node **top_b);
void pb(Node** top_a, Node **top_b);
void swap(struct Node** top);
void sa(struct Node** top_a);
void sb(struct Node** top_b);
void ss(struct Node** top_a, struct Node** top_b);

#endif