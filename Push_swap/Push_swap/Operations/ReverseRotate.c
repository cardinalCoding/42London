/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseRotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorte-r <bcorte-r@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:55:19 by bcorte-r          #+#    #+#             */
/*   Updated: 2024/03/15 14:40:39 by bcorte-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rotate_rev(Node **top)
{
    if (*top == NULL || (*top)->next == NULL)
        return;
    Node* temp = *top;
    while (temp->next->next != NULL)
        temp = temp->next;
    Node* last = temp->next;
    temp->next = NULL;
    last->next = *top;
    *top = last;
}

void rra(Node** top_a)
{
    rotate_rev(top_a);
    printf("rra\n");
}

void rrb(Node** top_b)
{
    rotate_rev(top_b);
    printf("rrb\n");
}

void rrr(Node** top_a, Node** top_b)
{
    rotate_rev(top_a);
    rotate_rev(top_b);
    printf("rrr\n");
}

