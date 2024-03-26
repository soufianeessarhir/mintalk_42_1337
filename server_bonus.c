/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:26:36 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/26 03:12:37 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

int byte_count(unsigned char c)
{
	int i;
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
void signal_handler(int signal)
{
	
	static unsigned char byte;
	static unsigned char utf_8_char[5];
	static int i;
	static int index;
	static int byte_num;
	byte |= (signal == SIGUSR1);
	i++;
	if (i == 8)
	{
		if (index == 0)
			byte_num = byte_count(byte);
			utf_8_char[index++] = byte;
		i = 0;
		byte = 0;
		byte_num--;
		if (byte_num == 0)
		{
			utf_8_char[index] = '\0';
			ft_printf("%s",utf_8_char);
			index = 0;
		}
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
	sact.sa_handler = &signal_handler;
	pid = getpid();
	ft_printf("%d\n",pid);
	sigaction(SIGUSR1,&sact,NULL);
	sigaction(SIGUSR2,&sact,NULL);
	while (1)
	pause();
	return 0;
}
