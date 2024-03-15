/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseRotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorte-r <bcorte-r@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:55:19 by bcorte-r          #+#    #+#             */
/*   Updated: 2024/03/15 12:56:05 by bcorte-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rotate_rev(Node **top)
{
    Node *tmp;
    Node *last;
    Node *first;
    
    if (!top || !(*top) || !((*top)->next))
        return;
    tmp = *top;
    first = *top;
    while ((tmp->next)->next)
        tmp = tmp->next;
    last = tmp->next;
    tmp->next = NULL;
    *top = last;
    last->next = first;    
}