/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:04:58 by adpassar          #+#    #+#             */
/*   Updated: 2023/06/23 15:45:52 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void ft_putchar(char c)
{
    write(1,&c,1);
}

static void ft_putstr(const char *str) {
    while (*str != '\0') {
        ft_putchar(*str);
        str++;
    }
}

/* push:
*	Pushes the top element of src stack to the top of dest stack.
*/

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_b)
	{
		if (!(*stack_a))
		{
			ft_lstadd_backnum(stack_a, (*stack_b));
			(*stack_b) = (*stack_b)->next;
			(*stack_a)->next = NULL;
		}
		else
		{
			tmp = (*stack_b)->next;
			ft_lstadd_frontnum(stack_a, (*stack_b));
			(*stack_b) = tmp;
		}
		ft_putstr("pa\n");
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_a)
	{
		if (!(*stack_b))
		{
			ft_lstadd_backnum(stack_b, (*stack_a));
			(*stack_a) = (*stack_a)->next;
			(*stack_b)->next = NULL;
		}
		else
		{
			tmp = (*stack_a)->next;
			ft_lstadd_frontnum(stack_b, (*stack_a));
			(*stack_a) = tmp;
		}
		ft_putstr("pb\n");
	}
}