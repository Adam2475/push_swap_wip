/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:19:23 by adpassar          #+#    #+#             */
/*   Updated: 2023/06/28 19:20:49 by adpassar         ###   ########.fr       */
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

static int	get_max(t_stack **stack)
{
 	t_stack *head;
  	int		min;

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
	
	if ((*stack_a)->value > (*stack_a)->next->value)
	{
		pa(stack_a, stack_b);
	}
	else
	{
		ra(stack_a);
	}
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *head;
	t_stack *tail;
	// t_stack *tmp;

	// tmp = (*stack_a);
	// tail = ft_lstlast(*stack_a);

	// int min;
	int max;
	int min;
	min = get_min(stack_a);
	max = get_max(stack_a);
	
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);

	sort_3(stack_a);

	pa(stack_a, stack_b);
	pa(stack_a, stack_b);

	head = (*stack_a);
	tail = ft_lstlast(*stack_a);
	//printf("%d\n",head->value);

	while(check_sorting(stack_a) != 1)
	{
		//printf("%d\n",check_sorting(stack_a));;
		if (head->value > (*stack_a)->next->value && (*stack_a)->next->value > tail->value)
		{
			sa(stack_a);
			ra(stack_a);
			ra(stack_a);
		}
		else if (head->value < tail->value && head->value < (*stack_a)->next->value && head->value < (*stack_a)->next->next->value)
		{
			if (head->value == min && (*stack_a)->next->value == max)
			{
				//pb(stack_a, stack_b);
				sa(stack_a);
				ra(stack_a);
				//pa(stack_a, stack_b);
				break;
			}
			if (head->value == min && tail->value == max)
			{
				pb(stack_a, stack_b);
				sa(stack_a);
				pa(stack_a, stack_b);
				break;
			}
			pb(stack_a, stack_b);
			sa(stack_a);
			if ((*stack_a)->value == min && tail->value == max)
			{
				pa(stack_a, stack_b);
				sa(stack_a);
				break;
			}
			pb(stack_a, stack_b);
			sa(stack_a);
			pa(stack_a, stack_b);
			pa(stack_a, stack_b);
			break;
		}
		else if (head->value < tail->value && head->value < (*stack_a)->next->value && head->value > (*stack_a)->next->value)
		{
			sa(stack_a);
			ra(stack_a);
			sa(stack_a);
		}
		else if (head->value > (*stack_a)->next->value && (*stack_a)->next->value < tail->value && head->value < tail->value)
		{
			if ((*stack_a)->next->next->value == min)
			{
				rra(stack_a);
				pb(stack_a,stack_b);
				sa(stack_a);
				ra(stack_a);
				ra(stack_a);
				pa(stack_a,stack_b);
				ra(stack_a);
				break;
			}
			else if ((*stack_a)->next->value == min)
			{
				rra(stack_a);
				sa(stack_a);
				ra(stack_a);
				ra(stack_a);
				break;
			}
			sa(stack_a);
			if ((*stack_a)->next->value < (*stack_a)->next->next->value && head->value < (*stack_a)->next->next->value)
				break;
			pb(stack_a, stack_b);
			sa(stack_a);
			pa(stack_a, stack_b);
			sa(stack_a);
			break;
		}
		else if (head->value > (*stack_a)->next->value && (*stack_a)->next->value < tail->value && (*stack_a)->next->value > (*stack_a)->next->next->value)
		{
			ra(stack_a);
			//pb(stack_a, stack_b);
			if ((*stack_a)->value > (*stack_a)->next->next->value)
			{
				sa(stack_a);
				pb(stack_a, stack_b);
				sa(stack_a);
				pa(stack_a, stack_b);
				break;
			}
			sa(stack_a);
			//pa(stack_a, stack_b);
			//sa(stack_a);
			break;
		}
		else if (head->value > (*stack_a)->next->value && (*stack_a)->next->value < tail->value)
		{
			ra(stack_a);
			if (head->value > (*stack_a)->next->value && head->value != max && (*stack_a)->value < (*stack_a)->next->next->value)
			{
				sa(stack_a);
				printf("%d", head->value);
			}
			else if ((*stack_a)->value > (*stack_a)->next->next->value)
			{
				sa(stack_a);
				pb(stack_a, stack_b);
				sa(stack_a);
				pa(stack_a, stack_b);
			}
		}
		else if (head->value < tail->value && head->value < (*stack_a)->next->value && head->value > (*stack_a)->next->next->next->value)
		{
			if ((*stack_a)->next->value == max)
			{
				sa(stack_a);
				ra(stack_a);
				sa(stack_a);
				pb(stack_a, stack_b);
				sa(stack_a);
				pa(stack_a, stack_b);
				break;
			}
			rra(stack_a);
			pb(stack_a, stack_b);
			ra(stack_a);
			ra(stack_a);
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else if (head->value < tail->value && head->value < (*stack_a)->next->value && head->value > (*stack_a)->next->next->value && head->value != min)
		{
			if (head->value == min)
			{
				pb(stack_a, stack_b);
				sa(stack_a);
				pb(stack_a, stack_b);
				//sa(stack_a);
				pa(stack_a, stack_b);
				pa(stack_a, stack_b);
				sa(stack_a);
				break;
			}
			if ((*stack_a)->next->value > (*stack_a)->next->next->next->value)
			{
				pb(stack_a, stack_b);
				sa(stack_a);
				pb(stack_a, stack_b);
				sa(stack_a);
				pa(stack_a, stack_b);
				pa(stack_a, stack_b);
				sa(stack_a);
				break;
			}
			pb(stack_a, stack_b);
			sa(stack_a);
			pa(stack_a, stack_b);
			sa(stack_a);
			break;
		}
		else if (head->value < (*stack_a)->next->value && (*stack_a)->next->value == max)
		{
			ra(stack_a);
			ra(stack_a);
		}
	}
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (check_sorting(stack_a) || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	//printf("%d\n",size);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}

