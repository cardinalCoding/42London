/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorte-r <bcorte-r@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:46:01 by bcorte-r          #+#    #+#             */
/*   Updated: 2024/03/15 15:33:54 by bcorte-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/* is_sorted:
*	Checks if a stack is sorted.
*	Returns 0 if the stack is not sorted, 1 if it is sorted.
*/
int	is_sorted(Node *stack)
{

}

static void	push_swap(Node **stack_a, Node **stack_b) 
{

}

int main(int argc, char *argv[]) {
    Node *stack_a = NULL;
    Node *stack_b = NULL;

    if (argc < 2)
    {
        printf("Usage: %s <numbers to push separated by space>\n", argv[0]);
        return 1;
    }
    
    // Populate stack_a with command line arguments
    for (int i = 1; i < argc; i++) {
        int value = atoi(argv[i]);
        push(&stack_a, value); 
    }
    
    // Display stacks after operations
    printf("Stack A: ");
    print_stack(stack_a);
    printf("Stack B: ");
    print_stack(stack_b);

    push_swap(&stack_a, &stack_b);

    // Free allocated memory
    Node* temp;
    while (stack_a != NULL) {
        temp = stack_a;
        stack_a = stack_a->next;
        free(temp);
    }
    while (stack_b != NULL) {
        temp = stack_b;
        stack_b = stack_b->next;
        free(temp);
    }
    
    return 0;
}
