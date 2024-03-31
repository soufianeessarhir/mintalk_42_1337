/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:03:47 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/31 05:07:13 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

int parcing(char *av)
{
	int i;
	i = 0;
	while (ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}
void	send_signals(pid_t pid, char *str)
{
	unsigned char bit;
	int i;

	i = 0;

	while (*str)
	{
		i = 7;
		bit = *str;
		while (i >= 0)
		{
			bit = *str >> i;
			if (bit % 2 == 0)
				kill(pid,SIGUSR2);
			else
				kill(pid,SIGUSR1);
			usleep(400);
			i--;
		}
		str++;
	}
	
}
int main (int ac , char **av)
{
	pid_t pid;
	
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
			send_signals(pid,av[2]);
	}
	return 0;
}