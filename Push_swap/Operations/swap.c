/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorte-r <bcorte-r@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 00:37:31 by bcorte-r          #+#    #+#             */
/*   Updated: 2024/03/14 00:47:33 by bcorte-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Sequence of operations for sorting
void sa(struct Node** top) {
    if (*top == NULL || (*top)->next == NULL)
        return;
    int temp = (*top)->data;
    (*top)->data = (*top)->next->data;
    (*top)->next->data = temp;
}