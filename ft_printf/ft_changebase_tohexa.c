/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_changebase_tohexa.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:05:02 by skondo            #+#    #+#             */
/*   Updated: 2023/10/16 18:28:31 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits(unsigned long long n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		cnt++;
	}
	return (cnt);
}

char	*ft_changebase_tohexa(unsigned long long n)
{
	char	*p;
	int		digits_cnt;
	int		j;

	digits_cnt = ft_count_digits(n);
	p = malloc(sizeof(char) * (digits_cnt + 1));
	if (p == NULL)
		return (NULL);
	j = digits_cnt - 1;
	if (n == 0)
		p[j] = '0';
	while (n > 0)
	{
		if (n % 16 < 10)
			p[j--] = n % 16 + '0';
		else
			p[j--] = n % 16 + 87;
		n /= 16;
	}
	p[digits_cnt] = '\0';
	return (p);
}
