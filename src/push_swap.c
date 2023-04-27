/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:54:52 by adpassar          #+#    #+#             */
/*   Updated: 2023/04/26 17:00:21 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    start_sorting(t_stack **stack_a, t_stack **stack_b, int ac)
{
    if(check_sorting(stack_a) == 1)
    {
        return ;
    }
    if (ac == 2)
    {
        if ((*stack_a)->value > (*stack_a)->next->value)
            sa(stack_a);
    }
    else if (ac == 3)
        execute_sorting_three(stack_a);
    else if (ac == 4)
        execute_sorting_four(stack_a, stack_b);
    else if (ac == 5)
        execute_sorting_five(stack_a, stack_b);
    else
        execute_sorting(stack_a, stack_b);
}

int main(int ac, char **av)
{
    // initializing the pos variable and 2 stacks
    int pos;
    t_stack *stack_a;
    t_stack *stack_b;

    stack_b = NULL;
    // keeps track of position?
    pos = 1;

    /* check if there is more than 2 arguments and that they're
        all eligible integers */ 
    if (ac > 2 && cheack_args(av) == 0)
    {
        // i assign the 
        stack_a = ft_lstnewnum(ft_atoi(av[pos]));
        /* i start assigning into the back of stack_a the arguments 
            one by one through the pos index */
        while (pos++ < ac -1)
            ft_lstadd_backnum(&stack_a,ft_lstnewnum(ft_atoi(av[pos])));
            
        // check duplicates?
        if (check_list(stack_a) == 1)
        {
            ft_putstr("there are some duplicate arguments!");
            free_list(&stack_a);
            return (1);
        }
        start_sorting(&stack_a, &stack_b, ac -1);
        free_list(*stack_a);
        free_list(*stack_b);
    }
    else
        return (0);
}