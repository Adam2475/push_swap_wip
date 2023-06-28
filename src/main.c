/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:54:52 by adpassar          #+#    #+#             */
/*   Updated: 2023/06/16 21:06:18 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libftprintf/inc/libft.h"

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

void    start_sorting(t_stack **stack_a, t_stack **stack_b)
{
    if(ft_lstsize(*stack_a) <= 5)
        simple_sort(stack_a, stack_b);
    else
        radix_sort(stack_a, stack_b);
}

int main(int ac, char **av)
{
    // initializing the 2 stacks
    int i;
    t_stack *stack_a;
    t_stack *stack_b;

    stack_b = NULL;
    // keeps track of position?
    i = 1;
    
    /* check if there is more than 2 arguments and that they're
        all eligible integers */ 
    if (ac > 2 && check_args(av) == 0)
    {
        /* i manually assign the first number at the beginning of
            the stack */
        stack_a = ft_lstnewnum(ft_atoi(av[i]));
        /* i start assigning into the back of stack_a the arguments 
            one by one through the pos index */

        while (i++ < ac -1) // put -1 cause the ac[1] is the name
        {
            ft_lstadd_backnum(&stack_a,ft_lstnewnum(ft_atoi(av[i])));
        }
            
        // check duplicates? probably inefficient...
        if (check_list(stack_a) == 1)
        {
            ft_putstr("there are some duplicate arguments!");
            // need to control the ft_free
            ft_free_list(&stack_a);
            return (1);
        }
        /* i execute the function that consist in a list of
            conditions depending on the numbers of arguments */
        start_sorting(&stack_a, &stack_b /*ac -1*/);
        // free the stacks and take home
        ft_free_list(&stack_a);
        ft_free_list(&stack_b);
    }
   
    // else means there is only 1 argument or there are invalid args
    else
        return (0);
}