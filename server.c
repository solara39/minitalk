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

volatile sig_atomic_t	bits = 0;

void	signal_handler(int signum, siginfo_t *info, void *dummy)
{
	static int	i;
	char		c;

	bits = bits << 1;
	if (signum == SIGUSER1)
		bits |= 1;
	else if (signum == SIGUSER2)
		;
	i++;
	c = "0xff" & bits;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
	}
}

int	main()
{
	struct sigaction	sa1;
	struct sigaction	sa2;

	if (-1 == sigemptyset(&sa1.sa_mask)
		exit(1);
	if (-1 == sigemptyset(&sa2.sa_mask)
		exit(1);
	sa1.sa_handler = signal_handler;
	sa2.sa-handler = signal_handler;
	sa1.sa_flags = SA_SIGINFO;
	sa2.sa_flags = SA_SIGINFO;
	if (-1 == sigaction(SIGINT, &sa1, NULL)
		exit(1);
	if (-1 == sigaction(SIGINT, &sa2, NULL)
		exit(1);
	ft_printf("%d",getpid());
	return (0);
}
