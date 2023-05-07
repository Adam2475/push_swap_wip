/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_sorting_five.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:42:59 by adpassar          #+#    #+#             */
/*   Updated: 2023/05/06 13:18:00 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *head_a;
    t_stack *last_a;

    t_stack *head_b;

    head_a = (*stack_a);
    last_a = lst_find_last(stack_a);

    while(check_sorting == 1)
    {
        if ((*stack_a)->next = NULL)
        {
            if(head_b < (*stack_b)->next)
            {
                push_a(**stack_a, **stack_b);
                rotate_a(**stack_a);
                push_a(**stack_a, **stack_b);
                rotate_a(**stack_a);
            }
            else
            {
                rotate_b(**stack_b);
                push_a(**stack_a, **stack_b);
                rotate_a(**stack_a);
                push_a(**stack_a, **stack_b);
                rotate_a(**stack_a);
            }
        }


        if (&head_a > (*stack_a)->next->value)
            push_b(**stack_a, **stack_b);
        else
            rotate_a(**stack_a);
    }
}