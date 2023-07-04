/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:19:23 by adpassar          #+#    #+#             */
/*   Updated: 2023/07/04 15:31:02 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <stdio.h>

int	get_min(t_stack **stack)
{
	t_stack *head;
  	int		min;

 	head = (*stack);
  	min = (*stack)->value;
	
  	while ((*stack)->next != NULL)
 	{
  		(*stack) = (*stack)->next;
  		if ((*stack)->value < min)
  			min = (*stack)->value;
  	}
 	(*stack) = head;
  	return (min);
}

long int	get_max(t_stack **stack)
{
 	t_stack *head;
  	long int	min;

 	head = (*stack);
  	min = (*stack)->value;
	
  	while ((*stack)->next != NULL)
 	{
  		(*stack) = (*stack)->next;
  		if ((*stack)->value > min)
  			min = (*stack)->value;
  	}
 	(*stack) = head;
  	return (min);
}

void	sort_3(t_stack **stack_a)
{
	t_stack *head;
	t_stack *tail;

	head = (*stack_a);
	tail = ft_lstlast(*stack_a);

	// printf("%d\n",head->value);
	// printf("%d\n",tail->value);
	
	while(check_sorting(stack_a) != 1)
	{
		if(head->value < tail->value && head->value > (*stack_a)->next->value)
				sa(stack_a);
		else if (head->value > (*stack_a)->next->value && head->value > tail->value && (*stack_a)->next->value > tail->value)
		{
			sa(stack_a);
			rra(stack_a);
		}
		else if (head->value > (*stack_a)->next->value && head->value > tail->value && (*stack_a)->next->value < tail->value)
			ra(stack_a);
		else if (head->value < tail->value && head->value < (*stack_a)->next->value)
		{
			sa(stack_a);
			ra(stack_a);
		}
		else if (head->value < (*stack_a)->next->value && head->value > tail->value)
		{
			rra(stack_a);
		}
	}
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{	
	t_stack *head;
	//t_stack *tail;
	int max;
	int min;
	min = get_min(stack_a);
	max = get_max(stack_a);

	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);

	head = (*stack_a);
	//tail = ft_lstlast(*stack_a);

	while(check_sorting(stack_a) != 1)
	{
		if(head->value == min)
			break;
		else if(head->value == max)
		{
			ra(stack_a);
			break;
		}
		else if (head->value > (*stack_a)->next->value && head->value < (*stack_a)->next->next->value)
		{
			sa(stack_a);
		}
		else if (head->value > (*stack_a)->next->value && head->value > (*stack_a)->next->next->value)
		{
			sa(stack_a);
			pb(stack_a, stack_b);
			sa(stack_a);
			pa(stack_a, stack_b);
		}
	}
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *head;
	t_stack *tail;
	int max;
	int min;
	min = get_min(stack_a);
	max = get_max(stack_a);
	
	head = (*stack_a);
	tail = ft_lstlast(*stack_a);

	while(check_sorting(stack_a) != 1)
	{
		if (ft_lstsize(*stack_a) == 3)
		{
			sort_3(stack_a);
			if ((*stack_b)->value == max)
			{
				pa(stack_a, stack_b);
				ra(stack_a);
				pa(stack_a, stack_b);
			}
			else if((*stack_b)->value == min)
			{
				pa(stack_a, stack_b);
				pa(stack_a, stack_b);
				ra(stack_a);
			}
		}
		else if (head->value == min || head->value == max)
		{
			pb(stack_a, stack_b);
			head = (*stack_a);
			if (check_sorting(stack_a) == 1 && ft_lstsize(*stack_a) == 3)
			{
				if ((*stack_b)->value == max)
				{
					pa(stack_a, stack_b);
					ra(stack_a);
					pa(stack_a, stack_b);
				}
				else if((*stack_b)->value == min)
				{
					pa(stack_a, stack_b);
					pa(stack_a, stack_b);
					ra(stack_a);
				}
			}
			else if (check_sorting(stack_a) == 1 && ft_lstsize(*stack_a) == 4)
			{
				if ((*stack_b)->value == max)
				{
					pa(stack_a, stack_b);
					ra(stack_a);
				}
				else if((*stack_b)->value == min)
				{
					pa(stack_a, stack_b);
				}
			}
		}
		else if(tail->value == min || tail->value == max)
		{
			rra(stack_a);
			pb(stack_a, stack_b);
			head = (*stack_a);
			tail = ft_lstlast(*stack_a);
			if (check_sorting(stack_a) == 1 && ft_lstsize(*stack_a) == 3)
			{
				if ((*stack_b)->value == max)
				{
					pa(stack_a, stack_b);
					ra(stack_a);
					pa(stack_a, stack_b);
				}
				else if((*stack_b)->value == min)
				{
					pa(stack_a, stack_b);
					pa(stack_a, stack_b);
					ra(stack_a);
				}
			}
			else if (check_sorting(stack_a) == 1 && ft_lstsize(*stack_a) == 4)
			{
				if ((*stack_b)->value == max)
				{
					pa(stack_a, stack_b);
					ra(stack_a);
				}
				else if((*stack_b)->value == min)
				{
					pa(stack_a, stack_b);
				}
			}
		}
		else if ((*stack_a)->next->value == min || (*stack_a)->next->value == max)
		{
			sa(stack_a);
			pb(stack_a, stack_b);
			head = (*stack_a);
			if (check_sorting(stack_a) == 1 && ft_lstsize(*stack_a) == 3)
			{
				if ((*stack_b)->value == max)
				{
					pa(stack_a, stack_b);
					ra(stack_a);
					pa(stack_a, stack_b);
				}
				else if((*stack_b)->value == min)
				{
					pa(stack_a, stack_b);
					pa(stack_a, stack_b);
					ra(stack_a);
				}
			}
			else if (check_sorting(stack_a) == 1 && ft_lstsize(*stack_a) == 4)
			{
				if ((*stack_b)->value == max)
				{
					pa(stack_a, stack_b);
					ra(stack_a);
				}
				else if((*stack_b)->value == min)
				{
					pa(stack_a, stack_b);
				}
			}
		}
		else if ((*stack_a)->next->next->value == min || (*stack_a)->next->next->value == max)
		{
			ra(stack_a);
			sa(stack_a);
			pb(stack_a, stack_b);
			head = (*stack_a);
			if (check_sorting(stack_a) == 1 && ft_lstsize(*stack_a) == 3)
			{
				if ((*stack_b)->value == max)
				{
					pa(stack_a, stack_b);
					ra(stack_a);
					pa(stack_a, stack_b);
				}
				else if((*stack_b)->value == min)
				{
					pa(stack_a, stack_b);
					pa(stack_a, stack_b);
					ra(stack_a);
				}
			}
		}
		else if ((*stack_a)->next->next->next->value == min || (*stack_a)->next->next->next->value == max)
		{
			rra(stack_a);
			rra(stack_a);
			pb(stack_a, stack_b);
			head = (*stack_a);
		}
	}
}

