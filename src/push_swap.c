/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:54:52 by adpassar          #+#    #+#             */
/*   Updated: 2023/04/20 16:54:10 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// void push_swap()
// {
//     int *stack_a;
//     int *stack_b;

//     stack_a = malloc(sizeof(int) * );
//     stack_b = malloc(sizeof(int) * ft_strlen(stack_a));
// }

int main(int ac, char **av)
{
    //inizializzo la variabile position e i 2 stack
    int pos;
    t_stack *stack_a;
    t_stack *stack_b;

    stack_b = NULL;
    //keeps track of position?
    pos = 1;

    //check args function?
    if (ac > 2 && cheack_args(av) == 0)
    {
        stack_a = ft_lstnewnum(ft_atoi(av[pos]));
        while (pos++ < ac -1)
            ft_lstadd_backnum(&stack_a,ft_lstnewnum(ft_atoi(av[pos])));
        if (check_list(stack_a) == 1)
        {
            ft_putstr()
        }
    }
}