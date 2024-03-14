/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_lower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorte-r <bcorte-r@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:45:49 by bcorte-r          #+#    #+#             */
/*   Updated: 2024/03/14 21:20:08 by bcorte-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sort_3_numbers(Node** head) {
    if (*head == NULL || (*head)->next == NULL || (*head)->next->next == NULL)
        return;

    if ((*head)->data > (*head)->next->data && (*head)->next->data < (*head)->next->next->data && (*head)->data < (*head)->next->next->data)
        swap(head);
    if ((*head)->data > (*head)->next->data && (*head)->next->data > (*head)->next->next->data && (*head)->data > (*head)->next->next->data) {
        swap(head);
        reverse_rotate(head);
    }
    if ((*head)->data > (*head)->next->data && (*head)->next->data < (*head)->next->next->data && (*head)->data > (*head)->next->next->data)
        rotate(head);
    if ((*head)->data < (*head)->next->data && (*head)->next->data > (*head)->next->next->data && (*head)->data < (*head)->next->next->data) {
        swap(head);
        rotate(head);
    }
    if ((*head)->data < (*head)->next->data && (*head)->next->data > (*head)->next->next->data && (*head)->data > (*head)->next->next->data)
        reverse_rotate(head);
}