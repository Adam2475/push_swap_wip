/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:06:43 by adpassar          #+#    #+#             */
/*   Updated: 2023/04/27 18:46:44 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    ra(t_stack **stack_a)
{

}

void    rb(t_stack **stack_b)
{

}

void rra(t_stack **stack_a)
{
    t_stack *head;
    t_stack *last;
    
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

void rra(t_stack **stack_b)
{
    t_stack *head;
    t_stack *last;
    
    if(*stack_b && (*stack_b)->next != NULL)
    {
        head = (*stack_b);
        last = lst_lastnum(*stack_b);
        while((*stack_b)->next != NULL)
            (*stack_b) = (*stack_b)->next;
        (*stack_b)->next = NULL;
        last->next = head;
        (*stack_b) = last;
        ft_putstr("rrb");
    }
}