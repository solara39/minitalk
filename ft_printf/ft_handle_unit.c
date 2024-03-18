/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:09:21 by skondo            #+#    #+#             */
/*   Updated: 2023/10/16 18:11:19 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits(unsigned int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_change_toascii(unsigned int n)
{
	unsigned long	d;
	int				i;
	char			*p;

	d = 1;
	i = 0;
	p = malloc(sizeof(char) * (ft_count_digits(n) + 1));
	if (p == NULL)
		return (NULL);
	if (n == 0)
		p[i++] = '0';
	while (n / d > 0)
		d *= 10;
	d /= 10;
	while (d > 0)
	{
		p[i] = n / d + '0';
		n %= d;
		d /= 10;
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	ft_handle_unit(unsigned int n)
{
	char	*p;
	int		cnt;

	cnt = 0;
	p = ft_change_toascii(n);
	cnt = ft_count_output(p);
	free(p);
	return (cnt);
}
