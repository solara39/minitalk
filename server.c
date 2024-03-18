/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:26:00 by skondo            #+#    #+#             */
/*   Updated: 2023/10/15 19:03:54 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

volatile sig_atomic_t	bits = 0;

void	signal_handler(int signum)
{
	static int	i;
	char		c;

	bits = bits << 1;
	if (signum == SIGUSR1)
		bits |= 1;
	else if (signum == SIGUSR2)
		;
	i++;
	c = 0xFF & bits;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		bits = 0;
	}
}

int	main()
{
	struct sigaction	sa1;
	struct sigaction	sa2;

	sigemptyset(&sa1.sa_mask);
	sigemptyset(&sa2.sa_mask);
	sa1.sa_handler = signal_handler;
	sa2.sa_handler = signal_handler;
	sa1.sa_flags = SA_SIGINFO;
	sa2.sa_flags = SA_SIGINFO;
	if (-1 == sigaction(SIGUSR1, &sa1, NULL))
		exit(1);
	if (-1 == sigaction(SIGUSR2, &sa2, NULL))
		exit(1);
	ft_printf("%d",getpid());
	while (1)
		pause();
	return (0);
}
