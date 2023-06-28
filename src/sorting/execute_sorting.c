/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:18:49 by adpassar          #+#    #+#             */
/*   Updated: 2023/06/22 16:43:46 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// int	get_max_bits(t_stack **stack)
// {
// 	t_stack	*head;
// 	int		max;
// 	int		max_bits;

// 	head = *stack;
// 	max = head->index;
// 	max_bits = 0;
// 	while (head)
// 	{
// 		if (head->index > max)
// 			max = head->index;
// 		head = head->next;
// 	}
// 	while ((max >> max_bits) != 0)
// 		max_bits++;
// 	return (max_bits);
// }

// void	radix_sort(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	*head_a;
// 	int		i;
// 	int		j;
// 	int		size;
// 	int		max_bits;

// 	i = 0;
// 	head_a = *stack_a;
// 	size = ft_lstsize(head_a);
// 	max_bits = get_max_bits(stack_a);
// 	while (i < max_bits)
// 	{
// 		j = 0;
// 		while (j++ < size)
// 		{
// 			head_a = *stack_a;
// 			if (((head_a->index >> i) & 1) == 1)
// 				ra(stack_a);
// 			else
// 				pb(stack_a, stack_b);
// 		}
// 		while (ft_lstsize(*stack_b) != 0)
// 			pa(stack_a, stack_b);
// 		i++;
// 	}
// }

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	if((*stack_a)->value > (*stack_a)->next->value)
	{
		pa(stack_a, stack_b);
	}
	else
	{
		ra(stack_a);
	}
}
