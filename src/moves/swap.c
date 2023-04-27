/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:46:32 by adpassar          #+#    #+#             */
/*   Updated: 2023/04/27 18:55:21 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    sa(t_stack **stack)
{
    int swap;
    if(stack == NULL || (*stack)->next == NULL)
        return ;
    swap = (*stack)->value;
    (*stack)->value = (*stack)->next->value;
    (*stack)->next->value = swap;
    ft_putstr("sa\n");
}

void    sb(t_stack **stack)
{
    int swap;
    if(stack == NULL || (*stack)->next == NULL)
        return ;
    swap = (*stack)->value;
    (*stack)->value = (*stack)->next->value;
    (*stack)->next->value = swap;
    ft_putstr("sb\n");
}