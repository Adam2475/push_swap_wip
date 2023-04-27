/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:38:15 by adpassar          #+#    #+#             */
/*   Updated: 2023/04/27 17:50:06 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


// checks if the stack is already sorted
int check_sorting(t_stack **stack_a)
{
    t_stack *copy;
    t_stack *head;

    copy = ft_copy_list(*stack_a);
    head = copy;
    while (copy)
    {
        if (copy->next == NULL)
            break ;// why not return?
        // check if values are all ordered
        if (copy->value < copy->next->value)
            copy = copy->next;
        else
        {
            free_list(&head);
            return (0);
        }
    }
    free_list(&head);
    return (1);
}

// this function checks if no one of the arguments exeeds
// the viable size of an int
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

// this function cycles through the argumets vector and
// checks if all the caracters are eligible integers
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

// should check for duplicates
/* i declare this fuction in the main with the just assigned stack_a
    and i cycle thought it with the counter index*/

// int check_list(t_stack *stack)
// {
//     int counter;
//     t_stack *copy;
//     // nani ?!
//     t_stack *chead;

//     // copy list??
//     copy = ft_copy_list(stack);
//     chead = copy;
//     while (stack)
//     {
//         copy = chead;
//         counter = 0;
//         while (copy)
//         {
//             if (copy->value == stack->value)
//                 counter++;
//             if (counter > 1)
//             {
//                 free_list(&chead);
//                 return (1);
//             }
//             copy = copy->next;
//         }
//         stack = stack->next;
//     }
//     free_list(&chead);
//     return (0);
// }

int check_list(t_stack *stack)
{
    int duplicate;
    t_stack *tmp;
    t_stack *head;

    tmp = stack->next;
    head = stack;
    while (tmp)
    {
        duplicate = 0;
        stack = head;
        while (stack)
        {
            if(stack->value == tmp->value)
                duplicate++;
            if (duplicate > 1)
            {
                return(1);
            }
            stack = stack->next;
        }
        tmp = tmp->next;
    }
    return(0);
}