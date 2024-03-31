/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:03:47 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/31 05:43:39 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	signal_hander(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("the message has been received\n");
}

int	parcing(char *av)
{
	int	i;

	i = 0;
	while (ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

void	send_signals(pid_t pid, char *str)
{
	unsigned char	bit;
	int				i;
	int				k;

	i = 0;
	k = 0;
	while (k < (int)ft_strlen(str) + 1)
	{
		i = 7;
		bit = str[k];
		while (i >= 0)
		{
			bit = str[k] >> i;
			if (bit % 2 == 0)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(400);
			i--;
		}
		k++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	signal(SIGUSR1, signal_hander);
	if (ac > 3 || ac == 1)
		return (ft_printf("incorrect  args\n"));
	if (!parcing(av[1]) && !av[2])
		return (ft_printf("illegal pid\nno message\n"));
	else if (!av[2] && parcing(av[1]))
		return (ft_printf("no message\n"));
	else if (av[2] && !parcing(av[1]))
		return (ft_printf("illegal pid\n"));
	if (ac == 3 && av[2])
	{
		pid = ft_atoi(av[1]);
		if (pid > 0)
			send_signals(pid, av[2]);
	}
	return (0);
}
