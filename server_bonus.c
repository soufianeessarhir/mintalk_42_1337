/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:26:36 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/31 05:35:32 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

static unsigned char	g_byte;

int	byte_count(unsigned char c)
{
	int	i;

	i = 0;
	if (c < 0x80)
		i = 1;
	else if ((c & 0xe0) == 0xc0)
		i = 2;
	else if ((c & 0xf0) == 0xe0)
		i = 3;
	else if ((c & 0xf8) == 0xf0)
		i = 4;
	return (i);
}

void	helper(int *byte_num, int *i, int pid)
{
	if (g_byte == '\0')
	{
		kill(pid, SIGUSR1);
	}
	g_byte = 0;
	*byte_num -= 1;
	*i = 0;
}

void	helper_nd(int *pid, siginfo_t *info, int *i, int *index)
{
	*pid = info->si_pid;
	*i = 0;
	g_byte = 0;
	*index = 0;
}

void	signal_handler(int signal, siginfo_t *info, void *f)
{
	static unsigned char	utf_8_char[7];
	static int				i;
	static int				index;
	static int				byte_num;
	static int				pid;

	if (info->si_pid != pid)
		helper_nd(&pid, info, &i, &index);
	g_byte |= (signal == SIGUSR1);
	if (++i == 8)
	{
		if (index == 0)
			byte_num = byte_count(g_byte);
		utf_8_char[index++] = g_byte;
		helper(&byte_num, &i, pid);
		if (byte_num == 0)
		{
			utf_8_char[index] = '\0';
			ft_printf("%s", utf_8_char);
			index = 0;
		}
	}
	else
		g_byte <<= 1;
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
