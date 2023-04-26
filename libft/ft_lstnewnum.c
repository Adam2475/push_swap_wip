/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:39:18 by adpassar          #+#    #+#             */
/*   Updated: 2023/04/20 16:56:16 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../inc/libft.h"
 #include "../inc/push_swap.h"

 t_stack *ft_lstnewnum(int num)
 {
    t_stack *new;

    new = malloc(sizeof(t_stack));
    if(!new)
        return(NULL);
    new->value = num;
    new->next = NULL;
    return(new);
 }