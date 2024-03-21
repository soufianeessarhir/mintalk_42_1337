/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:03:47 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/21 16:37:44 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	send_signals(pid_t pid, char *str)
{
	unsigned char bit;
	int i;

	bit = 0;
	i = 0;

	while (*str)
	{
		i = 8;
		while (i > 0)
		{
			bit = *str >> i;
			if (bit % 2 == 0)
				kill(pid,SIGUSR2);
			else
				kill(pid,SIGUSR1);
			i--;
			usleep(40);
		}
		str++;
	}
	
}
int main (int ac , char **av)
{
	pid_t pid;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid > 0)
			send_signals(pid,av[2]);
	}
	return 0;
}