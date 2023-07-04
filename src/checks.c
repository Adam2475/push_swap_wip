/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:38:15 by adpassar          #+#    #+#             */
/*   Updated: 2023/07/04 15:07:51 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libftprintf/inc/libft.h"

// static void ft_putchar(char c)
// {
//     write(1, &c, 1);
// }

// static void ft_putstr(const char *str) {
//     while (*str != '\0') {
//         ft_putchar(*str);
//         str++;
//     }
// }

static void ft_puterr(char c)
{
    write(2,&c,1);
}

static void ft_errstr(const char *str) {
    while (*str != '\0') {
        ft_puterr(*str);
        str++;
    }
}

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
            break ;
        if (copy->value < copy->next->value)
            copy = copy->next;
        else
        {
            ft_free_list(&head);
            return (0);
        }
    }
    ft_free_list(&head);
    return (1);
}

// checks if the arguments exeeds the int value
int check_lim(char **av, int x)
{
    long int    num;
    
    //printf("%s\n", av[x]);
    //num = ft_atoi(av[x]);
    num = ft_atoi_long(av[x]);
    //num = atol(av[x]);
    //printf("%ld\n", num);
    if (num < INT_MIN || num > INT_MAX)
    {
        ft_errstr("Error\n");
    }
    else
    {
        return (0);
    }
    return(1);
}

// checks if all the caracters are eligible integers
int check_args(char **av)
{
    int x;
    int y;
    int limit;
    limit = 0;

    x = 0;
    while(av[++x])
    {
        y = 0;
        //printf("%s\n", av[x]);
        //printf("%s", av);
        // limit = check_lim(av, x);
        // if (limit == 1)
        //     return(1);
        if (check_lim(av,x) == 1)
            return (1);
        if (av[x][0] == '-' && av[x][1] != '\0')
            y++;
        while (av[x][y])
        {
            if((av[x][y] >= '0' && av[x][y] <= '9'))
                y++;
            else
            {
                ft_errstr("Error\n");
                return (1);
            }
        }
    }
    return(0);
}

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