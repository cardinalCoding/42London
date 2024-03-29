/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorte-r <bcorte-r@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:28:13 by bcorte-r          #+#    #+#             */
/*   Updated: 2024/03/15 11:33:37 by bcorte-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*
    Link the tmp node to the begining of stack_b
    update the begining of stack_b to tmp
*/
void push(Node** top_a, int data)
{
    Node* newNode = createNode(data);
    newNode->next = *top_a;
    *top_a = newNode;
}

void pa(Node** top_a, Node** top_b)
{
    if (*top_b == NULL)
        return;
    push(top_a, pop(top_b));
    printf("pa\n");
}

void pb(Node** top_a, Node** top_b)
{
    push(top_b, pop(top_a));
    printf("pb\n");
}