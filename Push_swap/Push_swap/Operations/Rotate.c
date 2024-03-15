/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorte-r <bcorte-r@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:43:53 by bcorte-r          #+#    #+#             */
/*   Updated: 2024/03/15 12:56:29 by bcorte-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rotate(Node **top)
{
    if (!top || !(*top) || !((*top)->next))
        return;
    Node* last = *top;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = *top;
    *top = (*top)->next;
    last->next->next = NULL;
}

void ra(Node** top_a)
{
    if (!top_a || !(*top_a) || !((*top_a)->next))
        return;
    rotate(top_a);
    printf("ra\n");
}

void rb(Node** top_b)
{
    if (!top_b || !(*top_b) || !((*top_b)->next))
        return;
    rotate(top_b);
    printf("rb\n");
}

void rr(Node** top_a, Node** top_b)
{
    rotate(top_a);
    rotate(top_b);
    printf("rr\n");
}