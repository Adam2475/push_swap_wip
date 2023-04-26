/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:38:15 by adpassar          #+#    #+#             */
/*   Updated: 2023/04/19 21:28:51 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//this function checks if no one of the arguments exeeds
//the viable size of an int
int check_limits(char **av, int x)
{
    long int    num;
    
    num = ft_atoi_long(av[x]);
    if (num >= INT_MIN && num <= INT_MAX)
        return (0);
    else
    {
        ft_putstr("Error\n");
        ft_putstr("Some arguments are not of an eligible int size");
    }
    return(1);
}

//this function cycles through the argumets vector and
//checks if all the caracters are eligible integers
int check_args(char **av)
{
    int x;
    int y;

    x = 0;
    while(av[++x])
    {
        y = 0;
        if (check_limits(av,x) == 1)
            return (1);
        if (av[x][0] == '-' && av[x][1] != '\0')
            y++;
        while (av[x][y])
        {
            if((av[x][y] >= '0' && av[x][y] <= '9'))
                y++;
            else
            {
                ft_putstr("Error!");
                ft_putstr("Some argument's aren't integers");
            }
        }
    }
    return(0);
}


//what the fuck it does?
//should check for duplicates
int check_list(t_stack *stack)
{
    int counter;
    t_stack *copy;
    t_stack *chead;
}