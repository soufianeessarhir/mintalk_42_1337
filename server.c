/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:26:36 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/21 18:06:00 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void signal_handler(int signal)
{
	static unsigned char byte;
	static int i;
	byte |= (signal == SIGUSR1);
	i++;
	if (i == 8)
	{
		if (byte == '\0')
			ft_printf("\n");
		else
			ft_printf("%c",byte);
		i = 0;
		byte = 0;
	}
	else
		byte <<=1;
}
int main (int ac , char **av)
{
	pid_t	pid;
	struct sigaction sact;

	ac = 0;
	(void)av;
	ft_memset(&sact,0,sizeof(sact));
	sact.sa_handler = signal_handler;
	pid = getpid();
	ft_printf("%d\n",pid);
	puts("hhh\n");
	while (1)
	pause();
	return 0;
}
