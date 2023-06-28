/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:46:32 by adpassar          #+#    #+#             */
/*   Updated: 2023/06/16 21:09:18 by adpassar         ###   ########.fr       */
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