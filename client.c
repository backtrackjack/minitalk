/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsellars <jsellars@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:54:40 by jsellars          #+#    #+#             */
/*   Updated: 2022/02/03 17:07:17 by jsellars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<signal.h>
#include"libft/libft.h"

static void	send(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
		ft_putstr_fd("ac no 3\n", 1);
	send(ft_atoi(av[1]), av[2]);
	return (0);
}
