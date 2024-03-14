/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorte-r <bcorte-r@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 00:37:31 by bcorte-r          #+#    #+#             */
/*   Updated: 2024/03/14 20:47:51 by bcorte-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void swap(struct Node** top)
{
    if (*top == NULL || (*top)->next == NULL)
        return;
    int temp = (*top)->data;
    (*top)->data = (*top)->next->data;
    (*top)->next->data = temp;
}
/*
    Sequence of operations for sorting
    this will be the sequence for the SA
    SB and the SA and SB at the same time
*/ 
void sa(struct Node** top_a) {
    swap(top_a);
    printf("sa");
}
/*
    this is the sequence for the sb
    it will swap the top 2 elements 
    of the stack.
*/
void sb(struct Node** top_b){
    sa(top_b);
    printf("Sb");
}
/*
    this operation is SS it doing 
    SA and SB at the same time. 
*/
void ss(struct Node** top_a, struct Node** top_b){
    sa(top_a);
    sb(top_b);
}


