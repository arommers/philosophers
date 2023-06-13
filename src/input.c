/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: adri <adri@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 17:41:19 by adri          #+#    #+#                 */
/*   Updated: 2023/06/13 10:05:02 by adri          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return (TRUE);
    return (FALSE);
}

int size_check(int argc, char **argv)
{
    int i;
    
    i = 0;
    while (++i < argc)
    {
        if (ft_atolong(argv[i]) < 0 || ft_atolong(argv[i]) > INT_MAX)
            return (FALSE);
    }
    return (TRUE);
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
            if (ft_isdigit(argv[i][j]) != TRUE)
                return (FALSE);
            j++;
        }
    }
    return (TRUE);
}

void solo_philo(t_data *data, t_philo *philo)
{
	pthread_t   thread;
	pthread_t   monitor;

    data->start = get_time();
    if (pthread_create(&thread, NULL, &run_sim, &philo[0]) != SUCCESS)
        print_error("Creating threads failed", philo);
    run_monitor(philo, &monitor);
    exact_sleep(data->time_to_die + 10);
    pthread_detach(monitor);
    pthread_detach(thread);
    ft_clean(philo);
}

int input_check(int argc, char **argv)
{
    if (argc < 5 || argc > 6)
        return (FALSE);
    if (ft_atolong(argv[1]) > 250)
        return (FALSE);
    if (size_check(argc, argv) != TRUE)
        return (FALSE);
    if (digit_check(argc, argv) != TRUE)
        return (FALSE);
    return (SUCCESS);
}
