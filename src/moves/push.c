/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:04:58 by adpassar          #+#    #+#             */
/*   Updated: 2023/04/27 18:27:09 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* push:
*	Pushes the top element of src stack to the top of dest stack.
*/

void    pa(t_stack **stack_a, t_stack **stack_b)
{
    int n;
    n =(*stack_a)->value;
    ft_add_frontnum(stack_b, n);
    ft_lstdelfirst(stack_a);
    ft_putstr("pa\n");
}

void    pb(t_stack **stack_a, t_stack **stack_b)
{
    int n;
    n =(*stack_b)->value;
    ft_add_frontnum(stack_a, n);
    ft_lstdelfirst(stack_b);
    ft_putstr("pb\n");
}