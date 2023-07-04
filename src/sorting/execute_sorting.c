/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:18:49 by adpassar          #+#    #+#             */
/*   Updated: 2023/07/04 12:44:00 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static	void	printList(t_stack *head)
{
 	t_stack	*tmp;

 	tmp = head;
 	while (tmp != NULL)
 	{
 		ft_putnbr_fd(tmp->value, 1);
 		ft_putendl_fd("", 1);
 		tmp = tmp->next;
 	}
}

int	get_max_bits(t_stack **stack)
{
	t_stack	*head;
	int		max;
	int		max_bits;

	head = (*stack);
	max = get_max(stack);
	max_bits = 0;
	while (head)
	{
 	 	if (head->value > max)
 	 		max = head->value;
 	 	head = head->next;
 	}
 	while ((max >> max_bits) != 0)
 		max_bits++;
 	return (max_bits);
}

static t_stack *normalizer(t_stack **stack_a)
{
	t_stack	*head;
	long int min;
	//int char_min;
	long int tmp;
	long int loco;
 	min = get_min(stack_a);
	tmp = min * (-1);
 	head = (*stack_a);
 	//char_min = ((const char *) min);
 	if (min < 0)
 	{
		//min *= (-1);
 		//printf("%d", min);
 		while((*stack_a) != NULL)
 		{
			loco = (*stack_a)->value + tmp + 1;
			(*stack_a)->value = loco;
 			(*stack_a) = (*stack_a)->next;
 		}
 		(*stack_a) = head;
 		return (*stack_a);
 	}
 	else
 	{
 		return (*stack_a);
 	}
	printList(*stack_a);
	//exit(0);
 }

static t_stack	*flattener(t_stack **stack_a)
{
	t_stack **tmp;
	t_stack *holder;
	int i;
	int j;
	t_stack *head;
	long int min;
	int size;
	long long int max;
	tmp = stack_a;
	head = (*tmp);
	j = 0;
	i = 0;
	long int prev;
	prev = 0;
	size = ft_lstsize(*stack_a);
	max = get_max(stack_a);
	//long int v = get_max(stack_a);

	//printList(*stack_a);
	//printList(*tmp);
	//exit(0);
	//printf("--------\n");

	while (j < size)
	{
		min = max;
		//min = v;
		//head = (*stack_a);
		//(*tmp) = head;
		while (i < size)
		{
			//printf("%d\n",(*tmp)->value);
			if ((*tmp)->value == max && min == max)
			{
				min = (*tmp)->value;
				holder = (*tmp);
			}
			if ((*tmp)->value < min && (*tmp)->value > prev)
			{
				min = (*tmp)->value;
				holder = (*tmp);
			}
			//printf("%d\n", min);
			(*tmp) = (*tmp)->next;
			i++;
		}
		//printf("--------\n");
		//printf("%d", prev);
		i = 0;
		(*tmp) = holder;
		//printf("%d", j);
		prev = holder->value;
		(*tmp)->value = j;
		//prev = (*tmp)->value;
		(*tmp) = head;
		//i = 0;
		j++;
		//min = head->value;
		// (*stack_a) = (*stack_a)->next;
	}

	(*tmp) = head;
	//printf("--------\n");
	//printList(*tmp);
	//printf("--------\n");
	//printList(*stack_a);
	//exit(0);
	return(*tmp);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
 	t_stack	*head_a;
 	int		i;
 	int		j;
 	int		size;
 	int		max_bits;
	int		normalized;
	int		min;

	normalized = 0;
 	
	if (normalized != 1)
	{
		*stack_a = normalizer(stack_a);
		*stack_a = flattener(stack_a);
		normalized = 1;
	}

	max_bits = get_max_bits(stack_a);
	min = get_min(stack_a);
	i = 0;
 	head_a = *stack_a;
 	size = ft_lstsize(head_a);

	//printf("%d", min);
	
 	//while (i < max_bits)
	while (i < max_bits)
 	{
		//printf("%d",max_bits);
		//break;
 		j = 0;
 		while (j++ < size)
		{
 			head_a = *stack_a;
 			if (((head_a->value >> i) & 1) == 1)
 				ra(stack_a);
 			else
 				pb(stack_a, stack_b);
 		}
		while ((*stack_b) != NULL)
 			pa(stack_a, stack_b);
 		i++;
 	}
}
