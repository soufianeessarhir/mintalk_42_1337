/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:26:36 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/31 05:37:21 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	signal_handler(int signal, siginfo_t *info, void *f)
{
	static unsigned char	byte;
	static int				i;
	static int				pid;

	if (info->si_pid != pid)
	{
		pid = info->si_pid;
		i = 0;
		byte = 0;
	}
	byte |= (signal == SIGUSR1);
	i++;
	if (i == 8)
	{
		if (byte == '\0')
			write(1, "\n", 1);
		else
			write(1, &byte, 1);
		i = 0;
		byte = 0;
	}
	else
		byte <<= 1;
	(void)f;
}

int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	sact;

	if (ac > 1)
		return (ft_printf("too many args\n"));
	(void)av;
	ft_memset(&sact, 0, sizeof(sact));
	sact.sa_sigaction = &signal_handler;
	pid = getpid();
	ft_printf("%d\n", pid);
	sigaction(SIGUSR1, &sact, NULL);
	sigaction(SIGUSR2, &sact, NULL);
	while (1)
		pause();
	return (0);
}
