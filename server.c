/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsellars <jsellars@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:54:29 by jsellars          #+#    #+#             */
/*   Updated: 2022/02/02 17:37:55 by jsellars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

static int	current_bit = 0;
static int	current_byte = 0;
static char	byte = 0;
static char	str[100];

void	handler(int sig)
{
	if (sig == SIGUSR2)
		byte &= ~(128 >> current_bit);
	if (sig == SIGUSR1)
		byte |= ~(128 >> current_bit);
	current_bit++;
	if (current_bit > 7)
	{
		current_bit = 0;
		str[current_byte] = byte;
		byte = 0;
		if (current_byte < 99)
			current_byte++;		
	}
}

int	main(void)
{
	int	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);

	kill(SIGUSR1, pid);
	kill(SIGUSR2, pid);
	kill(SIGUSR1, pid);
	kill(SIGUSR2, pid);
	kill(SIGUSR1, pid);
	kill(SIGUSR1, pid);
	kill(SIGUSR1, pid);
	kill(SIGUSR1, pid);
	
	ft_putchar_fd(str[0], 1);
	/*
	 *while (1)
	 *        pause();
	 *return (0);
	 */
}
