/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_sorting_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:11:57 by adpassar          #+#    #+#             */
/*   Updated: 2023/04/27 16:27:04 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    ft_sort_three(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *head;
    t_stack *last;

    while(check_sorting(*stack_a) != 1)
    {
        head = (*stack_a);
        last = lst_find_last(stack_a);
        if((*stack_a)->next < (*stack_a))
        {
            pa(stack_a,stack_b);
            
        }
    }
}