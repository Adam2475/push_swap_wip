/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:06:43 by adpassar          #+#    #+#             */
/*   Updated: 2023/04/26 14:41:25 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include "../../inc/push_swap.h"

void rra(t_stack **stack_a)
{
    t_stack **head;
    t_stack **last;
    if(*stack_a && (*stack_a)->next != NULL)
    {
        head = (*stack_a);
        last = lst_lastnum(*stack_a);
        while((*stack_a)->next != NULL)
            (*stack_a) = (*stack_a)->next;
        (*stack_a)->next = NULL;
        last->next = head;
        (*stack_a) = last;
        ft_putstr("rra");
    }
}