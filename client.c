/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:25:54 by skondo            #+#    #+#             */
/*   Updated: 2023/10/14 18:07:01 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	send_chr(const pid_t pid, char c)
{
	int	bits;

	bits = 7;
	while (bits >= 0)
	{
		if (c & (1 << bits))
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		bits--;
		usleep(100);
	}
}

void	send_str(const pid_t pid, char *str)
{
	while (*str)
	{
		send_chr(pid, *str);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		exit(1);
	send_str(pid, argv[2]);
	return (0);
}
