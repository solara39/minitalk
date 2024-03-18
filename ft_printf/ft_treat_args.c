/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:13:31 by skondo            #+#    #+#             */
/*   Updated: 2023/10/16 18:53:33 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_treat_args(const char *format, va_list args)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] != '\0')
				cnt += ft_treat_specifier(format[i], args);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			cnt++;
		}
		i++;
		if (!format[i])
			return (cnt);
	}
	return (cnt);
}
