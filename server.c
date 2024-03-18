/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:26:36 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/18 01:30:17 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)(b);
	while (i < len)
	{
		str[i] = (char )(c);
		i++; 
	}
	return (b);
}
int main (int ac , char **av)
{
	pid_t	pid;
	struct sigaction sa;

	ft_memset(&sa,0,sizeof(sigaction));
	pid = getpid();
	
	printf("%d\n",pid);

	while (1)
	{
	
	}
	

	
	
	return 0;
}
