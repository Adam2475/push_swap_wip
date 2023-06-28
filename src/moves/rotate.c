/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:06:43 by adpassar          #+#    #+#             */
/*   Updated: 2023/06/23 14:33:14 by adpassar         ###   ########.fr       */
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

void	ra(t_stack **stack_a)
{
	t_stack	*tmp;

	if (*stack_a && (*stack_a)->next != NULL)
	{
		tmp = (*stack_a)->next;
		ft_lstadd_backnum(stack_a, (*stack_a));
		(*stack_a) = tmp;
		ft_putstr("ra\n");
	}
}

void	rb(t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_b && (*stack_b)->next != NULL)
	{
		tmp = (*stack_b)->next;
		ft_lstadd_backnum(stack_b, (*stack_b));
		(*stack_b) = tmp;
		ft_putstr("rb\n");
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_putstr("rr\b");
	ra(stack_a);
	rb(stack_b);
	ft_putstr("OFF");
}

// void	rra(t_stack **stack_a)
// {
// 	t_stack	*head;
// 	t_stack	*last;

// 	if (*stack_a && (*stack_a)->next != NULL)
// 	{
// 		head = (*stack_a);
// 		last = ft_lstlastnum((*stack_a));
// 		while ((*stack_a)->next != last)
// 			(*stack_a) = (*stack_a)->next;
// 		(*stack_a)->next = NULL;
// 		last->next = head;
// 		(*stack_a) = last;
// 		ft_putstr("rra");
// 	}
// }

void	rra(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*last;

	if (*stack_a && (*stack_a)->next != NULL)
	{
		head = (*stack_a);
		last = ft_lstlastnum((*stack_a));
		while ((*stack_a)->next != last)
			(*stack_a) = (*stack_a)->next;
		(*stack_a)->next = NULL;
		last->next = head;
		(*stack_a) = last;
		ft_putstr("rra\n");
	}
}

void	rrb(t_stack **stack_b)
{
	t_stack	*head;
	t_stack	*last;

	if (*stack_b && (*stack_b)->next != NULL)
	{
		head = (*stack_b);
		last = ft_lstlastnum((*stack_b));
		while ((*stack_b)->next != last)
			(*stack_b) = (*stack_b)->next;
		(*stack_b)->next = NULL;
		last->next = head;
		(*stack_b) = last;
		ft_putstr("rrb\n");
	}
}