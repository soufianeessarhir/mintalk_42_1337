/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:26:36 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/19 17:38:53 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

int main (int ac , char **av)
{
	pid_t	pid;
	struct sigaction sa;

	ac = 0;
	(void)av;
	ft_memset(&sa,0,sizeof(sigaction));
	pid = getpid();
	
	ft_printf("%d\n",pid);
	
	while (1)
	{
	
	}
	

	
	return 0;
}
