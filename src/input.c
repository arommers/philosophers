/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: adri <adri@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 17:41:19 by adri          #+#    #+#                 */
/*   Updated: 2023/06/08 22:16:12 by adri          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int nega_check (int argc, char **argv)
{
    int i;
    int j;
    
    i = 0;
    while (++i < argc)
    {
        if (ft_atolong(argv[i]) < 0)
            return (1);
    }
    return (0);
}

int digit_check(int argc, char **argv)
{
    int i;
    int j;
    
    i = 0;
    while (++i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            if (ft_isdigit(argv[i][j++]) != 1)
                return (1);
            i++;
        }
    }
    return (0);
}

int solo_philo(int argc, char **argv)
{
    
}

int input_check(int argc, char **argv)
{
    if (argc < 5 || argc > 6)
        return (1);
    if (nega_check(argc, argv) != 0)
        return (1);
    if (digit_check(argc, argv) != 0)
        return (1);
}